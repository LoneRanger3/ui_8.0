/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-02-02 15:51:30
 * @LastEditTime: 2023-10-23 02:01:45
 */
#include "ui_screen_DetectionAI.h"
#include "k1_horizontal_ui/mult_language.h"
#include "k1_horizontal_ui/ui_Screen_Settings.h"
#include "page_switch.h"
#include "src/core/lv_event.h"
#include "src/core/lv_obj_pos.h"
#include <stdbool.h>
#include <stdio.h>
#include "ui_custom_messagebox.h"
//#include "ui_custom_radio_box.h"


/******************variable***********************/

lv_obj_t * ui_ScreenAI;
/**************left panel*******************/
static lv_obj_t * ui_PanelPageScreenAI;

static lv_obj_t * ui_ButtonHomeScreenAI;
static lv_obj_t * ui_ButtonMoveScreenAI;
static lv_obj_t * ui_ButtonFileManageScreenAI;
static lv_obj_t * ui_ImageSettingPage;
static lv_obj_t * ui_ButtonReserveScreenAI;

/****************right panel**************/
static lv_obj_t * ui_PanelAIScreenAI;
static lv_obj_t * ui_PanelCenterScreenAI;
static lv_obj_t * ui_LabelTitleScreenAI;
static lv_obj_t * ui_SwitchFunctionScreenAI;
static lv_obj_t * ui_PanelLineScreenAI;
static lv_obj_t * ui_PanelAIdetection;
static lv_obj_t * ui_LabelFunctionScreenAI;
static lv_obj_t * ui_LabelExplanationScreenAI;
static lv_obj_t * ui_CheckboxFaultDetectionScreenAI;  //改写的checkbox
static lv_obj_t * ui_LabelFaultDetectionScreenAI;  //改写的checkbox
static lv_obj_t * ui_CheckboxFaultPauseScreenAI; //改写的checkbox
static lv_obj_t * ui_LabelFaultPauseScreenAI;  //改写的checkbox
static lv_obj_t * ui_PanelFlowCalibration;
static lv_obj_t * ui_LabelFlowCalibration;
static lv_obj_t * ui_LabelFlowCalibrationTips;
static lv_obj_t * ui_SwitchFlowCalibration;
static lv_obj_t * ui_ButtonBackScreenAI;
//static lv_obj_t * ui_LabelBackScreenAI;
static lv_obj_t * ui_PanelFirstLayerDetection;
static lv_obj_t * ui_LabelFirstDetectionAI;
static lv_obj_t * ui_SwitchFirstDetectionAI;
static lv_obj_t * ui_CheckboxScreenAI;
static lv_obj_t * ui_SensitivityOfAI;
static lv_obj_t * ui_SensitivityLbale;
static lv_obj_t * ui_SensitivityImage;
static lv_obj_t * ui_SensitivityMode;

/******************funs***********************/
static void ui_event_ButtonBackScreenAI(lv_event_t * e);
static void ui_event_RadioBox(lv_event_t * e);
static void ui_event_SwitchDetectionAI(lv_event_t * e);
static void ui_event_SwitchFirstLayerDetection(lv_event_t * e);
static void ui_event_SwitchFlowCalibration(lv_event_t * e);
static void ui_event_CheckboxScreenAIDetection(lv_event_t * e);
static void ui_event_loadAiScreen(lv_event_t * e);

static void AiPageBackBtnClicked(lv_event_t * e);
static void DetectionAIPageChangeObjs(uint8_t index);
static void SensitivityMessageAddFocusObjs(void);

/******************custom variable***********************/
static DialogMsgbox_t SensitivitySetMessage; //灵敏度设置选择对话框
static lv_obj_t *cur_radio_box;

static uint8_t ai_mode = 0;

/******************custom funs***********************/
static void show_ai_detection_actions(bool show);


/******************event***********************/
void ui_event_ButtonBackScreenAI(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
       // AiPageBackBtnClicked(e);
        BackPrepage(false);
       // LoadPage(ui_ScreenSettings, uint8_t curgroup_level)
    }
}

void ui_event_RadioBox(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        lv_obj_t *obj = (lv_obj_t *)lv_event_get_user_data(e);
        //暂时未确定两个选项是否互斥
        /*
        if ( cur_radio_box )
        {
            lv_obj_clear_state(cur_radio_box, LV_STATE_CHECKED);
        }

        if ( obj)
            lv_obj_add_state(obj, LV_STATE_CHECKED);
        
        cur_radio_box = obj;

        if ( cur_radio_box == ui_CheckboxFaultDetectionScreenAI )
        {
            send_set_fault_action_cmd(true);
        }
        else if ( cur_radio_box == ui_CheckboxFaultPauseScreenAI )
        {
            send_set_fault_action_cmd(false);
        }
        */
        
        // if (obj == ui_CheckboxFaultDetectionScreenAI)
        // {
        //     if(lv_obj_has_state(obj, LV_STATE_CHECKED))
        //     {
        //         lv_obj_clear_state(obj, LV_STATE_CHECKED);
        //         set_printer_data(0x1f, 3, "20");
        //     }
        //     else
        //     {
        //         lv_obj_add_state(obj, LV_STATE_CHECKED);
        //         set_printer_data(0x1f, 3, "21");
        //     }
        // }
        // if (obj == ui_CheckboxFaultPauseScreenAI)
        // {
        //     if(lv_obj_has_state(obj, LV_STATE_CHECKED))
        //     {
        //         lv_obj_clear_state(obj, LV_STATE_CHECKED);
        //         set_printer_data(0x1f, 3, "30");
        //     }
        //     else
        //     {
        //         lv_obj_add_state(obj, LV_STATE_CHECKED);
        //         set_printer_data(0x1f, 3, "31");
        //     }
        // }
    }
}

void ui_event_SwitchDetectionAI(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(system_state.Camera_model_state == 0)
        {
            create_msgbox(Nocamera[get_cur_language_index()], NULL, 1000 * 1, lv_scr_act());
            if(lv_obj_has_state(ui_SwitchFunctionScreenAI, LV_STATE_CHECKED))
            {
                lv_obj_clear_state(ui_SwitchFunctionScreenAI, LV_STATE_CHECKED);
            }
            send_set_ai_detection_switch_cmd(false);
            return;
        }
        // bool checked = lv_obj_has_state(ui_SwitchFunctionScreenAI, LV_STATE_CHECKED);
        // send_set_ai_detection_switch_cmd(checked);
        // CrLogI("---------ai detection flag %d",checked);
        if(!lv_obj_has_state(ui_SwitchFunctionScreenAI, LV_STATE_CHECKED))
        {
            lv_obj_add_state(ui_SwitchFunctionScreenAI, LV_STATE_CHECKED);
            send_set_ai_detection_switch_cmd(true);
        }
        else
        {
            lv_obj_clear_state(ui_SwitchFunctionScreenAI, LV_STATE_CHECKED);
            send_set_ai_detection_switch_cmd(false);
        }
    }
}

void ui_event_SwitchFirstLayerDetection(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(system_state.Laser_state == 0)
        {
            create_msgbox(NoLaser[get_cur_language_index()], NULL, 1000 * 1, lv_scr_act());
            if(lv_obj_has_state(ui_SwitchFirstDetectionAI, LV_STATE_CHECKED))
            {
                lv_obj_clear_state(ui_SwitchFirstDetectionAI, LV_STATE_CHECKED);
            }
            send_set_first_layer_detection_cmd(false);
            return;
        }
        // bool checked = lv_obj_has_state(ui_SwitchFirstDetectionAI, LV_STATE_CHECKED);
        // send_set_first_layer_detection_cmd(checked);
        // CrLogI("---------first layer detection flag %d",checked);
        if(!lv_obj_has_state(ui_SwitchFirstDetectionAI, LV_STATE_CHECKED))
        {
            lv_obj_add_state(ui_SwitchFirstDetectionAI, LV_STATE_CHECKED);
            send_set_first_layer_detection_cmd(true);
        }
        else
        {
            lv_obj_clear_state(ui_SwitchFirstDetectionAI, LV_STATE_CHECKED);
            send_set_first_layer_detection_cmd(false);
        }
    }
}

void ui_event_SwitchFlowCalibration(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(system_state.Laser_state == 0)
        {
            create_msgbox(NoLaser[get_cur_language_index()], NULL, 1000 * 1, lv_scr_act());
            if(lv_obj_has_state(ui_SwitchFlowCalibration, LV_STATE_CHECKED))
            {
                lv_obj_clear_state(ui_SwitchFlowCalibration, LV_STATE_CHECKED);
            }
            send_set_ai_flowcalibration_switch_cmd(false);
            return;
        }
        // bool checked = lv_obj_has_state(ui_SwitchFirstDetectionAI, LV_STATE_CHECKED);
        // send_set_ai_flowcalibration_switch_cmd(checked);
        // CrLogI("---------flowcalibration detection flag %d",checked);
        if(!lv_obj_has_state(ui_SwitchFlowCalibration, LV_STATE_CHECKED))
        {
            lv_obj_add_state(ui_SwitchFlowCalibration, LV_STATE_CHECKED);
            send_set_ai_flowcalibration_switch_cmd(true);
        }
        else
        {
            lv_obj_clear_state(ui_SwitchFlowCalibration, LV_STATE_CHECKED);
            send_set_ai_flowcalibration_switch_cmd(false);
        }
    }
    if (event_code == LV_EVENT_FOCUSED)
    {
        lv_obj_scroll_to_y(ui_PanelCenterScreenAI, 100 , true);
    }
}

void ui_event_CheckboxScreenAIDetection(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(system_state.Camera_model_state == 0)
        {
            create_msgbox(Nocamera[get_cur_language_index()], NULL, 1000 * 1, lv_scr_act());
            if(lv_obj_has_state(ui_CheckboxScreenAI, LV_STATE_CHECKED))
            {
                lv_obj_clear_state(ui_CheckboxScreenAI, LV_STATE_CHECKED);
            }
            send_set_fault_action_cmd(false);
            return;
        }

        if(lv_obj_has_state(ui_CheckboxScreenAI, LV_STATE_CHECKED))
        {
            CrLogI("AI pause print mode open");
            send_set_fault_action_cmd(true);
        }
        else
        {
            CrLogI("AI pause print mode close");
            send_set_fault_action_cmd(false);
        }
    }
}

void ui_event_SensitivityOfAISetting(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(system_state.Camera_model_state == 0)
        {
            create_msgbox(Nocamera[get_cur_language_index()], NULL, 1000 * 1, lv_scr_act());
        }
        else
        {
            ShowDialogMessagebox(&SensitivitySetMessage, SensitivityMessageAddFocusObjs);
        }
    }
}

void ui_event_loadAiScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load the AI page");
        get_printer_data(CONTROL_MACHINE_STATE, 2, "5");    //获取摄像头状态
        get_printer_data(CONTROL_MACHINE_STATE, 2, "a");    //获取轮廓仪状态
        get_printer_data(CONTROL_AI_OPTIONS, 2, "1");       //获取AI功能状态
        switch (UIType)
        {
            case CR_K1: //默认不接轮廓仪的机型 
                //首层检测
                lv_obj_add_flag(ui_PanelFirstLayerDetection, LV_OBJ_FLAG_HIDDEN); 
                lv_obj_add_flag(ui_LabelFirstDetectionAI, LV_OBJ_FLAG_HIDDEN); 
                lv_obj_add_flag(ui_SwitchFirstDetectionAI, LV_OBJ_FLAG_HIDDEN);

                //故障暂停打印
                lv_obj_add_flag(ui_CheckboxScreenAI, LV_OBJ_FLAG_HIDDEN);

                //流量检测
                lv_obj_add_flag(ui_PanelFlowCalibration, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_LabelFlowCalibration, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_LabelFlowCalibrationTips, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_SwitchFlowCalibration, LV_OBJ_FLAG_HIDDEN);
        
                break;
            default:
                break;
       }
    }
}

void ui_event_detectionai_changepage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(target == ui_ButtonHomeScreenAI)
        {
            if ( home_printing_is_printing_finished() )
                LoadHomeNormalScreen();
            else
                LoadHomePrintingScreen();
        }
        if(target == ui_ButtonMoveScreenAI)LoadAxisMoveScreen();
        if(target == ui_ButtonFileManageScreenAI)LoadFileManageScreen();
        if(target == ui_ImageSettingPage)LoadSettingsScreen();
        if(target == ui_ButtonReserveScreenAI)LoadCustomerServiceScreen();
    }
}

/**
 * @description: 灵敏度对话框设置
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_SensitivitySetting(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    int dat = lv_event_get_user_data(e);
    uint8_t language_index = get_cur_language_index();
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        switch(dat) 
        {
            case 0: 
                set_printer_data(CONTROL_AI_OPTIONS, 3, "61");
                break;
            case 1: 
                set_printer_data(CONTROL_AI_OPTIONS, 3, "62");
                break; 
            default:break;
        }
  
        HiddenDialogMessagebox(&SensitivitySetMessage);
        BackPrepage(true);
    }
}

static void SensitivityTextSet(lv_obj_t *label, uint8_t label_index, uint8_t language_index)
{
    switch (label_index) {
    case 0:
        lv_label_set_text(label, AINormalMode[language_index]);
        break;
    case 1:
        lv_label_set_text(label, AIProMode[language_index]);
        break;
    default:break;
    }    
}

/******************ui***********************/
void ui_ScreenAI_screen_init(void)
{
    ui_ScreenAI = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenAI, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenAI, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ScreenAI, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    init_pages(ui_ScreenAI, DetectionAIPageChangeObjs, LoadAiDetectionScreen);

    /****************left panel**************/
    ui_PanelPageScreenAI= lv_obj_create(ui_ScreenAI);
    lv_obj_set_width(ui_PanelPageScreenAI, 68);
    lv_obj_set_height(ui_PanelPageScreenAI, 360);
    lv_obj_set_pos(ui_PanelPageScreenAI, 0, 60);
    lv_obj_clear_flag(ui_PanelPageScreenAI, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_PanelPageScreenAI, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelPageScreenAI, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
   // lv_obj_set_style_pad_all(ui_PanelPageScreenAI, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonHomeScreenAI = lv_btn_create(ui_PanelPageScreenAI);
    lv_obj_set_width(ui_ButtonHomeScreenAI, 68);
    lv_obj_set_height(ui_ButtonHomeScreenAI, 72);
    lv_obj_set_x(ui_ButtonHomeScreenAI, -18);
    lv_obj_set_y(ui_ButtonHomeScreenAI, -18);
    lv_obj_add_flag(ui_ButtonHomeScreenAI, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonHomeScreenAI, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonHomeScreenAI, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonHomeScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonHomeScreenAI, &ui_img_pagehome_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ButtonHomeScreenAI, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonHomeScreenAI, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonHomeScreenAI, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonHomeScreenAI, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonHomeScreenAI, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonMoveScreenAI = lv_btn_create(ui_PanelPageScreenAI);
    lv_obj_set_width(ui_ButtonMoveScreenAI, 68);
    lv_obj_set_height(ui_ButtonMoveScreenAI, 72);
    lv_obj_set_x(ui_ButtonMoveScreenAI, -18);
    lv_obj_set_y(ui_ButtonMoveScreenAI, 54);  
    lv_obj_add_flag(ui_ButtonMoveScreenAI, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonMoveScreenAI, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonMoveScreenAI, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonMoveScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonMoveScreenAI, &ui_img_pagemove_png,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonMoveScreenAI, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonMoveScreenAI, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonMoveScreenAI, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonMoveScreenAI, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);


    ui_ButtonFileManageScreenAI= lv_btn_create(ui_PanelPageScreenAI);
    lv_obj_set_width(ui_ButtonFileManageScreenAI, 68);
    lv_obj_set_height(ui_ButtonFileManageScreenAI, 72);
    lv_obj_set_x(ui_ButtonFileManageScreenAI, -18);
    lv_obj_set_y(ui_ButtonFileManageScreenAI, 126);
    lv_obj_add_flag(ui_ButtonFileManageScreenAI, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonFileManageScreenAI, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonFileManageScreenAI, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonFileManageScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonFileManageScreenAI, &ui_img_pagefilemanage_png,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ButtonFileManageScreenAI, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonFileManageScreenAI, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonFileManageScreenAI, 255,
                                LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonFileManageScreenAI, 2,
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonFileManageScreenAI, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);


    ui_ImageSettingPage = lv_img_create(ui_PanelPageScreenAI);
    lv_img_set_src(ui_ImageSettingPage, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_ImageSettingPage, 68);
    lv_obj_set_height(ui_ImageSettingPage, LV_SIZE_CONTENT);    /// 92
    lv_obj_set_x(ui_ImageSettingPage, -18);
    lv_obj_set_y(ui_ImageSettingPage, 198);    //74变成266
    lv_obj_add_flag(ui_ImageSettingPage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageSettingPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonReserveScreenAI = lv_btn_create(ui_PanelPageScreenAI);
    lv_obj_set_width(ui_ButtonReserveScreenAI, 68);
    lv_obj_set_height(ui_ButtonReserveScreenAI, 72);
    lv_obj_set_x(ui_ButtonReserveScreenAI, -18);
    lv_obj_set_y(ui_ButtonReserveScreenAI, 270);  
    lv_obj_add_flag(ui_ButtonReserveScreenAI, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonReserveScreenAI, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonReserveScreenAI, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonReserveScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonReserveScreenAI, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonReserveScreenAI, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonReserveScreenAI, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonReserveScreenAI, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonReserveScreenAI, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);


    /****************right panel**************/
    ui_PanelAIScreenAI = lv_obj_create(ui_ScreenAI);
    lv_obj_set_pos(ui_PanelAIScreenAI, 73, 68);
    lv_obj_set_size(ui_PanelAIScreenAI, 556, 344); 
    lv_obj_clear_flag(ui_PanelAIScreenAI, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelAIScreenAI, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelAIScreenAI, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelAIScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelAIScreenAI, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelAIScreenAI, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelCenterScreenAI = lv_obj_create(ui_PanelAIScreenAI);
    lv_obj_set_pos(ui_PanelCenterScreenAI, -1, 60);
    lv_obj_set_size(ui_PanelCenterScreenAI, 556, 283); 
    lv_obj_add_flag(ui_PanelCenterScreenAI, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelCenterScreenAI, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelCenterScreenAI, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCenterScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelCenterScreenAI, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelCenterScreenAI, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTitleScreenAI = lv_label_create(ui_PanelAIScreenAI);
    lv_obj_set_size(ui_LabelTitleScreenAI, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_pos(ui_LabelTitleScreenAI, 16, 0);
    lv_label_set_text(ui_LabelTitleScreenAI, AIFunction[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelTitleScreenAI, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTitleScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTitleScreenAI, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelLineScreenAI = lv_obj_create(ui_PanelAIScreenAI);
    lv_obj_set_size(ui_PanelLineScreenAI, 543, 1);
    lv_obj_set_pos(ui_PanelLineScreenAI, 7, 49);
    lv_obj_clear_flag(ui_PanelLineScreenAI, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelLineScreenAI, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelLineScreenAI, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelLineScreenAI, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelLineScreenAI, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //AI 检测
    ui_PanelAIdetection = lv_obj_create(ui_PanelCenterScreenAI);
    lv_obj_set_size(ui_PanelAIdetection, 528, 56);
    lv_obj_set_pos(ui_PanelAIdetection, 12, 0);
    lv_obj_add_flag(ui_PanelAIdetection, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_PanelAIdetection, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_set_style_bg_color(ui_PanelAIdetection, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelAIdetection, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelAIdetection, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_PanelAIdetection, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelAIdetection, 4, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_pad_all(ui_PanelAIdetection, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //选中后样式设置
    lv_obj_set_style_bg_color(ui_PanelAIdetection, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_PanelAIdetection, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_PanelAIdetection, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_PanelAIdetection, 4, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_LabelFunctionScreenAI = lv_label_create(ui_PanelAIdetection);
    lv_obj_set_size(ui_LabelFunctionScreenAI, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_LabelFunctionScreenAI, LV_ALIGN_LEFT_MID, 11, 1);
    lv_label_set_recolor(ui_LabelFunctionScreenAI, true);
    lv_label_set_text(ui_LabelFunctionScreenAI, AIdetection[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelFunctionScreenAI, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFunctionScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFunctionScreenAI, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_LabelExplanationScreenAI = lv_label_create(ui_PanelCenterScreenAI);
    lv_obj_set_width(ui_LabelExplanationScreenAI, 525);
    lv_obj_set_height(ui_LabelExplanationScreenAI, 50);
    lv_obj_set_x(ui_LabelExplanationScreenAI, 24);
    lv_obj_set_y(ui_LabelExplanationScreenAI, 60);
    lv_label_set_text(ui_LabelExplanationScreenAI, "打印过程中可以通过AI检测打印中的异常情况.");
    lv_obj_set_style_text_color(ui_LabelExplanationScreenAI, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelExplanationScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelExplanationScreenAI, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
 
    ui_SwitchFunctionScreenAI = lv_switch_create(ui_PanelAIdetection);
    lv_obj_set_width(ui_SwitchFunctionScreenAI, 54);
    lv_obj_set_height(ui_SwitchFunctionScreenAI, 26);
    lv_obj_align(ui_SwitchFunctionScreenAI, LV_ALIGN_RIGHT_MID, -12, 0);
    lv_obj_add_flag(ui_SwitchFunctionScreenAI, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_radius(ui_SwitchFunctionScreenAI, 90, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFunctionScreenAI, lv_color_hex(0x6D6D6D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SwitchFunctionScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_SwitchFunctionScreenAI, lv_color_hex(0x252525), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SwitchFunctionScreenAI, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_SwitchFunctionScreenAI, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_SwitchFunctionScreenAI, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_set_style_radius(ui_SwitchFunctionScreenAI, 30, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFunctionScreenAI, lv_color_hex(0x9D9D9D), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SwitchFunctionScreenAI, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFunctionScreenAI, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SwitchFunctionScreenAI, 255, LV_PART_KNOB | LV_STATE_CHECKED);

    //灵敏度设置
    ui_SensitivityOfAI = lv_obj_create(ui_PanelCenterScreenAI);
    lv_obj_set_size(ui_SensitivityOfAI, 528, 56);
    lv_obj_set_pos(ui_SensitivityOfAI, 12, 104);
    //lv_obj_align_to(ui_SensitivityOfAI, ui_PanelAIdetection, LV_ALIGN_OUT_BOTTOM_MID, 0, 50);
    lv_obj_add_flag(ui_SensitivityOfAI, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_SensitivityOfAI, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_set_style_bg_color(ui_SensitivityOfAI, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SensitivityOfAI, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SensitivityOfAI, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_SensitivityOfAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_SensitivityOfAI, 4, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_pad_all(ui_SensitivityOfAI, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SensitivityOfAI, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_SensitivityOfAI, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_SensitivityOfAI, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_SensitivityOfAI, 4, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_SensitivityLbale = lv_label_create(ui_SensitivityOfAI);
    lv_obj_set_width(ui_SensitivityLbale, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SensitivityLbale, LV_SIZE_CONTENT);
    // lv_obj_set_x(ui_SensitivityLbale, 26);
    // lv_obj_set_y(ui_SensitivityLbale, 202);
    lv_obj_align(ui_SensitivityLbale, LV_ALIGN_LEFT_MID, 11, 1);
    lv_label_set_text(ui_SensitivityLbale, AISensitivity[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_SensitivityLbale, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SensitivityLbale, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SensitivityLbale, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_SensitivityImage = lv_img_create(ui_SensitivityOfAI);
    lv_img_set_src(ui_SensitivityImage, &ui_img_rightarrow_png);
    lv_obj_set_width(ui_SensitivityImage, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_SensitivityImage, LV_SIZE_CONTENT);
    lv_obj_align(ui_SensitivityImage, LV_ALIGN_RIGHT_MID, -16, 0);
    lv_obj_add_flag(ui_SensitivityImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SensitivityImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_SensitivityMode = lv_label_create(ui_SensitivityOfAI);
    lv_obj_set_width(ui_SensitivityMode, 200);
    lv_obj_set_height(ui_SensitivityMode, 24);
    lv_obj_align(ui_SensitivityMode, LV_ALIGN_RIGHT_MID, -36, -2);
    lv_label_set_text(ui_SensitivityMode, AINormalMode[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_SensitivityMode, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SensitivityMode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SensitivityMode, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_SensitivityMode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SensitivityMode, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //灵敏度设置弹窗
    static Msgboxbtn_t SensitivityOfAIbtn[2];
    for (size_t i = 0; i < 2; i++)
    {
        SensitivityOfAIbtn[i].btnsCallbackArray = ui_event_SensitivitySetting;
        SensitivityOfAIbtn[i].SetLabelText = SensitivityTextSet;
    }
    SensitivitySetMessage.hasSubPanel = true;
    SensitivitySetMessage.title = AISensitivity;
    SensitivitySetMessage.btn = SensitivityOfAIbtn;
    SensitivitySetMessage.customStyle = &StyleDialogBtn;
    SensitivitySetMessage.customFocusStyle = &StyleDialogFocusBtn;

    SensitivitySetMessage.btnNumber = sizeof(SensitivityOfAIbtn)/sizeof(Msgboxbtn_t);
    SensitivitySetMessage.subPanelAttr.w = 371;
    SensitivitySetMessage.subPanelAttr.h = 285;

    InitDialogMessagebox(&SensitivitySetMessage);

    lv_obj_align(SensitivitySetMessage.titleLabel, LV_ALIGN_TOP_MID, 0, 15);
    
    uint8_t btnBasePos_y = 88;
    for (size_t i = 0; i < SensitivitySetMessage.btnNumber; i++)
    {
        lv_obj_align(SensitivitySetMessage.btn[i].label, LV_ALIGN_LEFT_MID, 0, 1);
        lv_obj_set_size(SensitivitySetMessage.btn[i].btn, 312, 52);
        lv_obj_set_pos(SensitivitySetMessage.btn[i].btn, 30, btnBasePos_y);
        btnBasePos_y += 77;
    }

    //首层检测
    ui_PanelFirstLayerDetection = lv_obj_create(ui_PanelCenterScreenAI);
    lv_obj_set_size(ui_PanelFirstLayerDetection, 528, 56);
    lv_obj_set_pos(ui_PanelFirstLayerDetection, 12, 177);
    lv_obj_align_to(ui_PanelFirstLayerDetection, ui_SensitivityOfAI, LV_ALIGN_OUT_BOTTOM_MID, 0, 12);
    lv_obj_add_flag(ui_PanelFirstLayerDetection, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_PanelFirstLayerDetection, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_set_style_bg_color(ui_PanelFirstLayerDetection, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelFirstLayerDetection, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelFirstLayerDetection, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_PanelFirstLayerDetection, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelFirstLayerDetection, 4, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_pad_all(ui_PanelFirstLayerDetection, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelFirstLayerDetection, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_PanelFirstLayerDetection, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_PanelFirstLayerDetection, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_PanelFirstLayerDetection, 4, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_LabelFirstDetectionAI = lv_label_create(ui_PanelFirstLayerDetection);
    lv_obj_set_width(ui_LabelFirstDetectionAI, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelFirstDetectionAI, LV_SIZE_CONTENT);
    // lv_obj_set_x(ui_LabelFirstDetectionAI, 26);
    // lv_obj_set_y(ui_LabelFirstDetectionAI, 202);
    lv_obj_align(ui_LabelFirstDetectionAI, LV_ALIGN_LEFT_MID, 11, 1);
    lv_label_set_text(ui_LabelFirstDetectionAI, FirstLayerDetection[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelFirstDetectionAI, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFirstDetectionAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFirstDetectionAI, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SwitchFirstDetectionAI = lv_switch_create(ui_PanelFirstLayerDetection);
    lv_obj_set_width(ui_SwitchFirstDetectionAI, 54);
    lv_obj_set_height(ui_SwitchFirstDetectionAI, 26);
    // lv_obj_set_x(ui_SwitchFirstDetectionAI, 586);
    // lv_obj_set_y(ui_SwitchFirstDetectionAI, 204);
    lv_obj_align(ui_SwitchFirstDetectionAI, LV_ALIGN_RIGHT_MID, -12, 0);
    lv_obj_add_flag(ui_SwitchFirstDetectionAI, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_radius(ui_SwitchFirstDetectionAI, 90, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFirstDetectionAI, lv_color_hex(0x6D6D6D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SwitchFirstDetectionAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
   
    lv_obj_set_style_bg_color(ui_SwitchFirstDetectionAI, lv_color_hex(0x252525), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SwitchFirstDetectionAI, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_SwitchFirstDetectionAI, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_SwitchFirstDetectionAI, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_set_style_radius(ui_SwitchFirstDetectionAI, 30, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFirstDetectionAI, lv_color_hex(0x9D9D9D), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SwitchFirstDetectionAI, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFirstDetectionAI, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SwitchFirstDetectionAI, 255, LV_PART_KNOB | LV_STATE_CHECKED);
    
    //流量校准
    ui_PanelFlowCalibration = lv_obj_create(ui_PanelCenterScreenAI);
    lv_obj_set_size(ui_PanelFlowCalibration, 528, 52);
   // lv_obj_set_pos(ui_PanelFlowCalibration, 12, 218);
    lv_obj_align_to(ui_PanelFlowCalibration, ui_PanelFirstLayerDetection, LV_ALIGN_OUT_BOTTOM_MID, 0, 49);
    lv_obj_add_flag(ui_PanelFlowCalibration, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_PanelFlowCalibration, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_set_style_bg_color(ui_PanelFlowCalibration, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelFlowCalibration, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelFlowCalibration, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_PanelFlowCalibration, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelFlowCalibration, 4, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_pad_all(ui_PanelFlowCalibration, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelFlowCalibration, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_PanelFlowCalibration, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_PanelFlowCalibration, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_PanelFlowCalibration, 4, LV_PART_MAIN | LV_STATE_FOCUSED);

    ui_LabelFlowCalibration = lv_label_create(ui_PanelFlowCalibration);
    lv_obj_set_width(ui_LabelFlowCalibration, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelFlowCalibration, LV_SIZE_CONTENT);
    // lv_obj_set_x(ui_LabelFlowCalibration, 26);
    // lv_obj_set_y(ui_LabelFlowCalibration, 300);
    lv_obj_align(ui_LabelFlowCalibration, LV_ALIGN_LEFT_MID, 11, 1);
    lv_label_set_text(ui_LabelFlowCalibration, FlowCalibration[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelFlowCalibration, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFlowCalibration, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFlowCalibration, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFlowCalibrationTips = lv_label_create(ui_PanelCenterScreenAI);
    lv_obj_set_width(ui_LabelFlowCalibrationTips, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelFlowCalibrationTips, LV_SIZE_CONTENT);
    // lv_obj_set_x(ui_LabelFlowCalibrationTips, 26);
    // lv_obj_set_y(ui_LabelFlowCalibrationTips, 278);
    lv_obj_align_to(ui_LabelFlowCalibrationTips, ui_PanelFirstLayerDetection, LV_ALIGN_OUT_BOTTOM_LEFT, 14, 109);
    lv_label_set_text(ui_LabelFlowCalibrationTips, FlowCalibrationTips[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelFlowCalibrationTips, lv_color_hex(0xFFD158), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFlowCalibrationTips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFlowCalibrationTips, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SwitchFlowCalibration = lv_switch_create(ui_PanelFlowCalibration); 
    lv_obj_set_width(ui_SwitchFlowCalibration, 54);
    lv_obj_set_height(ui_SwitchFlowCalibration, 26);
     // lv_obj_set_x(ui_SwitchFlowCalibration, 586);
    // lv_obj_set_y(ui_SwitchFlowCalibration, 302);
    lv_obj_align(ui_SwitchFlowCalibration, LV_ALIGN_RIGHT_MID, -12, 0);
    lv_obj_add_flag(ui_SwitchFlowCalibration, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_radius(ui_SwitchFlowCalibration, 90, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFlowCalibration, lv_color_hex(0x6D6D6D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SwitchFlowCalibration, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_SwitchFlowCalibration, lv_color_hex(0x252525), LV_PART_MAIN | LV_STATE_CHECKED);
    // lv_obj_set_style_bg_opa(ui_SwitchFlowCalibration, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_set_style_bg_color(ui_SwitchFlowCalibration, lv_color_hex(0x252525), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SwitchFlowCalibration, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_SwitchFlowCalibration, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_SwitchFlowCalibration, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_set_style_radius(ui_SwitchFlowCalibration, 30, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFlowCalibration, lv_color_hex(0x9D9D9D), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SwitchFlowCalibration, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFlowCalibration, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SwitchFlowCalibration, 255, LV_PART_KNOB | LV_STATE_CHECKED);

    ui_ButtonBackScreenAI = lv_btn_create(ui_PanelAIScreenAI);
    lv_obj_set_size(ui_ButtonBackScreenAI, 68, 38);
    lv_obj_set_pos(ui_ButtonBackScreenAI, 474, 6);
    lv_obj_add_flag(ui_ButtonBackScreenAI, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonBackScreenAI, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonBackScreenAI, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonBackScreenAI, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonBackScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonBackScreenAI, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonBackScreenAI, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonBackScreenAI, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonBackScreenAI, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonBackScreenAI, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonBackScreenAI, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonBackScreenAI, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonBackScreenAI, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonBackScreenAI, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_ButtonBackScreenAI, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonBackScreenAI, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    // ui_LabelBackScreenAI = lv_label_create(ui_ButtonBackScreenAI);
    // lv_obj_set_width(ui_LabelBackScreenAI, 116);
    // lv_obj_set_height(ui_LabelBackScreenAI, 30);
    // lv_obj_set_align(ui_LabelBackScreenAI, LV_ALIGN_CENTER);
    // lv_label_set_text(ui_LabelBackScreenAI, Back[get_cur_language_index()]);
    // lv_obj_set_style_text_align(ui_LabelBackScreenAI, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_LabelBackScreenAI, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CheckboxScreenAI = lv_checkbox_create(ui_PanelCenterScreenAI);
    lv_checkbox_set_text(ui_CheckboxScreenAI, AIPausePrint[get_cur_language_index()]);
    lv_obj_set_width(ui_CheckboxScreenAI, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_CheckboxScreenAI, LV_SIZE_CONTENT);
    // lv_obj_set_x(ui_CheckboxScreenAI, 29);
    // lv_obj_set_y(ui_CheckboxScreenAI, 172);
    lv_obj_align_to(ui_CheckboxScreenAI, ui_PanelFirstLayerDetection, LV_ALIGN_OUT_BOTTOM_LEFT, 12, 7);
    lv_obj_add_flag(ui_CheckboxScreenAI, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_CheckboxScreenAI, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_set_style_text_color(ui_CheckboxScreenAI, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CheckboxScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CheckboxScreenAI, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(ui_CheckboxScreenAI, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_CheckboxScreenAI, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_CheckboxScreenAI, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CheckboxScreenAI, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CheckboxScreenAI, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CheckboxScreenAI, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CheckboxScreenAI, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_CheckboxScreenAI, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_ext_click_area(ui_CheckboxScreenAI, 20);
     //选中后样式
    lv_obj_set_style_border_color(ui_CheckboxScreenAI, lv_color_hex(0xCDF6FF),
                                    LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_CheckboxScreenAI, 255, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_CheckboxScreenAI, 4, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_CheckboxScreenAI, 0, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_CheckboxScreenAI, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_CheckboxScreenAI, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
  //  lv_obj_set_style_outline_color(ui_CheckboxScreenAI, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_opa(ui_CheckboxScreenAI, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_pad_all(ui_CheckboxScreenAI, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_CheckboxScreenAI, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);

    /*******************************************/
    // cur_radio_box = ui_CheckboxFaultDetectionScreenAI;
    // if ( cur_radio_box )
    //     lv_obj_add_state(cur_radio_box, LV_STATE_CHECKED);

    lv_obj_add_event_cb(ui_ButtonBackScreenAI, ui_event_ButtonBackScreenAI, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelAIdetection, ui_event_SwitchDetectionAI, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelFirstLayerDetection, ui_event_SwitchFirstLayerDetection, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelFlowCalibration, ui_event_SwitchFlowCalibration, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CheckboxScreenAI, ui_event_CheckboxScreenAIDetection, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SensitivityOfAI, ui_event_SensitivityOfAISetting, LV_EVENT_ALL, NULL);
    
    lv_obj_add_event_cb(ui_ScreenAI, ui_event_loadAiScreen, LV_EVENT_ALL, NULL);

    lv_obj_add_event_cb(ui_ButtonHomeScreenAI, ui_event_detectionai_changepage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonMoveScreenAI, ui_event_detectionai_changepage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonFileManageScreenAI, ui_event_detectionai_changepage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ImageSettingPage, ui_event_detectionai_changepage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonReserveScreenAI, ui_event_detectionai_changepage, LV_EVENT_ALL, NULL);
}

void LoadAiDetectionScreen(void)
{
    lv_disp_load_scr(ui_ScreenAI);
}

void AiPageBackBtnClicked(lv_event_t * e)
{
    LoadSettingsScreen();
}

void ai_set_detection_state(AIConfigState_t aistate)
{
    if(system_state.Camera_model_state == 0)    //如果摄像头未配置则不更新状态
    {
        CrLogW("don't exist camera");
        return ;
    }
    if ( aistate.AI_state )
    {
        if(!lv_obj_has_state(ui_SwitchFunctionScreenAI, LV_STATE_CHECKED))
        {
            lv_obj_add_state(ui_SwitchFunctionScreenAI, LV_STATE_CHECKED);
        }
        // show_ai_detection_actions(true);
    }
    else
    {
        if(lv_obj_has_state(ui_SwitchFunctionScreenAI, LV_STATE_CHECKED))
        {
            lv_obj_clear_state(ui_SwitchFunctionScreenAI, LV_STATE_CHECKED);
        }
        // show_ai_detection_actions(false);
    }
    
    if ( aistate.FlowCalibrationState )
    {
        if(!lv_obj_has_state(ui_SwitchFlowCalibration, LV_STATE_CHECKED))
        {
            lv_obj_add_state(ui_SwitchFlowCalibration, LV_STATE_CHECKED);
        }
    }
    else
    {
        if(lv_obj_has_state(ui_SwitchFlowCalibration, LV_STATE_CHECKED))
        {
            lv_obj_clear_state(ui_SwitchFlowCalibration, LV_STATE_CHECKED);
        }
    }

    if ( aistate.FaultToPause_state )
    {
        if(!lv_obj_has_state(ui_CheckboxScreenAI, LV_STATE_CHECKED))
        {
            lv_obj_add_state(ui_CheckboxScreenAI, LV_STATE_CHECKED);
        }
    }
    else
    {
        if(lv_obj_has_state(ui_CheckboxScreenAI, LV_STATE_CHECKED))
        {
            lv_obj_clear_state(ui_CheckboxScreenAI, LV_STATE_CHECKED);
        }
    }

    if ( aistate.FirstLayerDetection_state )
        ai_set_first_layer_detection(true);
    else
        ai_set_first_layer_detection(false);
    
    if( aistate.AiMode == AI_MODE_TYPE_ROUTINE )
    {
        ai_mode = AI_MODE_TYPE_ROUTINE;
        lv_label_set_text(ui_SensitivityMode, AINormalMode[get_cur_language_index()]);
    }
    else
    {
        ai_mode = AI_MODE_TYPE_MAJOR;
        lv_label_set_text(ui_SensitivityMode, AIProMode[get_cur_language_index()]);
    }
    
}

void ai_set_first_layer_detection(bool opened)
{
    if ( opened )
    {
        if(!lv_obj_has_state(ui_SwitchFirstDetectionAI, LV_STATE_CHECKED))
        {
            lv_obj_add_state(ui_SwitchFirstDetectionAI, LV_STATE_CHECKED);
        }
    }
    else
    {
        if(lv_obj_has_state(ui_SwitchFirstDetectionAI, LV_STATE_CHECKED))
        {
            lv_obj_clear_state(ui_SwitchFirstDetectionAI, LV_STATE_CHECKED);
        }
    }
}

void ai_set_fault_action(bool is_detection_in_printing)
{
    // if ( cur_radio_box )
    //     lv_obj_clear_state(cur_radio_box, LV_STATE_CHECKED);

    // if ( is_detection_in_printing )
    //     cur_radio_box = ui_CheckboxFaultDetectionScreenAI;
    // else
    //     cur_radio_box = ui_CheckboxFaultPauseScreenAI;

    // if ( cur_radio_box )
    //     lv_obj_add_state(cur_radio_box, LV_STATE_CHECKED);
}

void show_ai_detection_actions(bool show)
{
    if ( show )
    {
        // lv_obj_clear_flag(ui_CheckboxFaultDetectionScreenAI, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_clear_flag(ui_LabelFaultDetectionScreenAI, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_clear_flag(ui_CheckboxFaultPauseScreenAI, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_clear_flag(ui_LabelFaultPauseScreenAI, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_clear_flag(ui_LabelFirstLayerScreenAI, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_clear_flag(ui_SwitchFirstLayerScreenAI, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        // lv_obj_add_flag(ui_CheckboxFaultDetectionScreenAI, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_add_flag(ui_LabelFaultDetectionScreenAI, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_add_flag(ui_CheckboxFaultPauseScreenAI, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_add_flag(ui_LabelFaultPauseScreenAI, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_add_flag(ui_LabelFirstLayerScreenAI, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_add_flag(ui_SwitchFirstLayerScreenAI, LV_OBJ_FLAG_HIDDEN);
    }
}

void DetectionAI_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if(ui_LabelTitleScreenAI)
        lv_label_set_text(ui_LabelTitleScreenAI, AIFunction[language_index]);
    if(ui_LabelFunctionScreenAI)
        lv_label_set_text(ui_LabelFunctionScreenAI, AIdetection[language_index]);
    if(ui_LabelExplanationScreenAI)
        lv_label_set_text(ui_LabelExplanationScreenAI, AIDetectionTips[language_index]);
    if(ui_LabelFirstDetectionAI)
        lv_label_set_text(ui_LabelFirstDetectionAI, FirstLayerDetection[language_index]);
    // if(ui_LabelBackScreenAI)
    //     lv_label_set_text(ui_LabelBackScreenAI, Back[language_index]);
    if(ui_CheckboxScreenAI)
        lv_checkbox_set_text(ui_CheckboxScreenAI, AIPausePrint[language_index]);
    if(ui_LabelFlowCalibration)
        lv_label_set_text(ui_LabelFlowCalibration, FlowCalibration[language_index]);
    if(ui_LabelFlowCalibrationTips)
        lv_label_set_text(ui_LabelFlowCalibrationTips, FlowCalibrationTips[language_index]);
    if(ui_SensitivityLbale)
        lv_label_set_text(ui_SensitivityLbale, AISensitivity[language_index]);
    
    if( ai_mode == AI_MODE_TYPE_ROUTINE )
    {
        lv_label_set_text(ui_SensitivityMode, AINormalMode[get_cur_language_index()]);
    }
    else
    {
        lv_label_set_text(ui_SensitivityMode, AIProMode[get_cur_language_index()]);
    }

    if(language_index)
    {
        lv_obj_set_pos(ui_SensitivityOfAI, 12, 125);
        lv_obj_align_to(ui_PanelFirstLayerDetection, ui_SensitivityOfAI, LV_ALIGN_OUT_BOTTOM_MID, 0, 12);
        lv_obj_align_to(ui_CheckboxScreenAI, ui_PanelFirstLayerDetection, LV_ALIGN_OUT_BOTTOM_LEFT, 12, 7);
        lv_obj_align_to(ui_PanelFlowCalibration, ui_PanelFirstLayerDetection, LV_ALIGN_OUT_BOTTOM_MID, 0, 49);
        lv_obj_align_to(ui_LabelFlowCalibrationTips, ui_PanelFirstLayerDetection, LV_ALIGN_OUT_BOTTOM_LEFT, 14, 109);
    }
    else
    {
        lv_obj_set_pos(ui_SensitivityOfAI, 12, 104);
        lv_obj_align_to(ui_PanelFirstLayerDetection, ui_SensitivityOfAI, LV_ALIGN_OUT_BOTTOM_MID, 0, 12);
        lv_obj_align_to(ui_CheckboxScreenAI, ui_PanelFirstLayerDetection, LV_ALIGN_OUT_BOTTOM_LEFT, 12, 7);
        lv_obj_align_to(ui_PanelFlowCalibration, ui_PanelFirstLayerDetection, LV_ALIGN_OUT_BOTTOM_MID, 0, 49);
        lv_obj_align_to(ui_LabelFlowCalibrationTips, ui_PanelFirstLayerDetection, LV_ALIGN_OUT_BOTTOM_LEFT, 14, 109);
    }
}

void refresh_camera_detecte_state(int camera_state)
{
    if (!camera_state)
    {
        lv_obj_clear_state(ui_SwitchFunctionScreenAI, LV_STATE_CHECKED);
        send_set_ai_detection_switch_cmd(false);
    }
}

void refresh_laser_detecte_state(int laser_state)
{
    if (!laser_state)
    {
        lv_obj_clear_state(ui_SwitchFlowCalibration, LV_STATE_CHECKED);
        send_set_ai_flowcalibration_switch_cmd(false);
        lv_obj_clear_state(ui_CheckboxScreenAI, LV_STATE_CHECKED);
        send_set_fault_action_cmd(false);
        lv_obj_clear_state(ui_SwitchFirstDetectionAI, LV_STATE_CHECKED);
        send_set_first_layer_detection_cmd(false);
    }
}

/**
 * @description: 灵敏度弹框对象事件添加
 * @return {*}
 */
static void SensitivityMessageAddFocusObjs(void)
{
    lv_group_remove_all_objs(encoder_group);
    for (int i = 0; i < 2; i++)
    {
        lv_group_add_obj(encoder_group, SensitivitySetMessage.btn[i].btn);
    } 
}

static void DetectionAIPageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    PageNode *DetectionAI_node = find_page(ui_ScreenAI);
    DetectionAI_node->nav_level = index;

    // switch (index)
    // {
    // case 1:
        lv_group_add_obj(encoder_group, ui_ButtonBackScreenAI);
        lv_group_add_obj(encoder_group, ui_PanelAIdetection);
        lv_group_add_obj(encoder_group, ui_SensitivityOfAI);
        lv_group_add_obj(encoder_group, ui_PanelFirstLayerDetection);
        lv_group_add_obj(encoder_group, ui_CheckboxScreenAI);
        lv_group_add_obj(encoder_group, ui_PanelFlowCalibration);
    //     break;
    // default:
    //     break;
   // }
 
}