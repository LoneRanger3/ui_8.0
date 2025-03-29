/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2023-02-02 15:51:30
 * @LastEditTime: 2023-02-24 14:36:32
 */
#include "ui_screen_DetectionAI.h"
#include <stdio.h>
//#include "ui_custom_radio_box.h"


/******************variable***********************/

static lv_obj_t * ui_ScreenAI;
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
static lv_obj_t * ui_LabelFunctionScreenAI;
static lv_obj_t * ui_LabelExplanationScreenAI;
static lv_obj_t * ui_LabelExplanation;
static lv_obj_t * ui_CheckboxFaultDetectionScreenAI;  //改写的checkbox
static lv_obj_t * ui_LabelFaultDetectionScreenAI;  //改写的checkbox
static lv_obj_t * ui_CheckboxFaultPauseScreenAI; //改写的checkbox
static lv_obj_t * ui_LabelFaultPauseScreenAI;  //改写的checkbox
static lv_obj_t * ui_LabelFlowCalibration;
static lv_obj_t * ui_LabelFlowCalibrationTips;
static lv_obj_t * ui_SwitchFlowCalibration;
static lv_obj_t * ui_ButtonBackScreenAI;
static lv_obj_t * ui_LabelBackScreenAI;
static lv_obj_t * ui_LabelFirstDetectionAI;
static lv_obj_t * ui_SwitchFirstDetectionAI;
static lv_obj_t * ui_CheckboxScreenAI;
static lv_obj_t * ui_SensitivityOfAI;
static lv_obj_t * ui_SensitivityLbale;
static lv_obj_t * ui_SensitivityImage;
static lv_obj_t * ui_SensitivityMode;

/******************funs***********************/
static void ui_event_ButtonBackScreenAI(lv_event_t * e);
static void ui_event_SwitchDetectionAI(lv_event_t * e);
static void ui_event_SwitchFirstLayerDetection(lv_event_t * e);
static void ui_event_SwitchFlowCalibration(lv_event_t * e);
static void ui_event_CheckboxScreenAIDetection(lv_event_t * e);
static void ui_event_loadAiScreen(lv_event_t * e);

static void AiPageBackBtnClicked(lv_event_t * e);
void Msgbox_event_handler(lv_event_t * e);
void EnterMsgboxTips(lv_obj_t * parent, char *message, char *btn1label);
void create_AImode_msg(AiModeType mode);

/******************custom variable***********************/
static lv_obj_t *cur_radio_box;



/******************custom funs***********************/
static void show_ai_detection_actions(bool show);




/******************event***********************/
void ui_event_ButtonBackScreenAI(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        AiPageBackBtnClicked(e);
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
        bool checked = lv_obj_has_state(ui_SwitchFunctionScreenAI, LV_STATE_CHECKED);
        send_set_ai_detection_switch_cmd(checked);
        if(checked)
        {
            EnterMsgboxTips(ui_ScreenAI, AIShareCheckboxContent[get_cur_language_index()], Confirm[get_cur_language_index()]);
        }
        CrLogI("---------ai detection flag %d",checked);
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
        bool checked = lv_obj_has_state(ui_SwitchFirstDetectionAI, LV_STATE_CHECKED);
        send_set_first_layer_detection_cmd(checked);
        CrLogI("---------first layer detection flag %d",checked);
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
        bool checked = lv_obj_has_state(ui_SwitchFlowCalibration, LV_STATE_CHECKED);
        send_set_ai_flowcalibration_switch_cmd(checked);
        CrLogI("---------flowcalibration detection flag %d",checked);
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

void ui_event_loadAiScreen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load the AI page");
        get_printer_data(CONTROL_PARAMETERS, 2, "s");       //获取用户分享状态
        get_printer_data(CONTROL_MACHINE_STATE, 2, "5");    //获取摄像头状态
        get_printer_data(CONTROL_MACHINE_STATE, 2, "a");    //获取轮廓仪状态
        get_printer_data(CONTROL_AI_OPTIONS, 2, "1");       //获取AI功能状态
        switch (UIType)
        {
            case CR_K1_Max: //K1maxse默认不接轮廓仪
            {
                if(IsK1MaxSe)
                {
                    //首层检测
                    lv_obj_add_flag(ui_LabelFirstDetectionAI, LV_OBJ_FLAG_HIDDEN); 
                    lv_obj_add_flag(ui_SwitchFirstDetectionAI, LV_OBJ_FLAG_HIDDEN);

                    //故障暂停打印
                    lv_obj_add_flag(ui_CheckboxScreenAI, LV_OBJ_FLAG_HIDDEN);

                    //流量检测
                    lv_obj_add_flag(ui_LabelFlowCalibration, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_LabelFlowCalibrationTips, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_SwitchFlowCalibration, LV_OBJ_FLAG_HIDDEN);
                }
                break;
            }
            default:
                break;
        }
        refreshSharePictrueState(system_state.IsAgreeSharePicture);
    }
}

void ui_event_SensitivityOfAI(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED) {
        CrLogI("AI mode change");
        create_AImode_msg(ai_state.AiMode);
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

/******************ui***********************/
void ui_ScreenAI_screen_init(void)
{
    ui_ScreenAI = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenAI, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    /****************left panel**************/
    ui_PanelPageScreenAI= lv_obj_create(ui_ScreenAI);
    lv_obj_set_width(ui_PanelPageScreenAI, 80);
    lv_obj_set_height(ui_PanelPageScreenAI, 480);
    lv_obj_clear_flag(ui_PanelPageScreenAI, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_PanelPageScreenAI, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonHomeScreenAI = lv_btn_create(ui_PanelPageScreenAI);
    lv_obj_set_width(ui_ButtonHomeScreenAI, 80);
    lv_obj_set_height(ui_ButtonHomeScreenAI, 96);
    lv_obj_set_x(ui_ButtonHomeScreenAI, -22);
    lv_obj_set_y(ui_ButtonHomeScreenAI, -22);
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
    lv_obj_set_width(ui_ButtonMoveScreenAI, 80);
    lv_obj_set_height(ui_ButtonMoveScreenAI, 96);
    lv_obj_set_x(ui_ButtonMoveScreenAI, -22);
    lv_obj_set_y(ui_ButtonMoveScreenAI, 74);   //266变成74
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
    lv_obj_set_width(ui_ButtonFileManageScreenAI, 80);
    lv_obj_set_height(ui_ButtonFileManageScreenAI, 96);
    lv_obj_set_x(ui_ButtonFileManageScreenAI, -22);
    lv_obj_set_y(ui_ButtonFileManageScreenAI, 170);
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
    lv_obj_set_width(ui_ImageSettingPage, 80);
    lv_obj_set_height(ui_ImageSettingPage, LV_SIZE_CONTENT);    /// 92
    lv_obj_set_x(ui_ImageSettingPage, -22);
    lv_obj_set_y(ui_ImageSettingPage, 266);    //74变成266
    lv_obj_add_flag(ui_ImageSettingPage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageSettingPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonReserveScreenAI = lv_btn_create(ui_PanelPageScreenAI);
    lv_obj_set_width(ui_ButtonReserveScreenAI, 80);
    lv_obj_set_height(ui_ButtonReserveScreenAI, 96);
    lv_obj_set_x(ui_ButtonReserveScreenAI, -22);
    lv_obj_set_y(ui_ButtonReserveScreenAI, 362);  
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
    lv_obj_set_width(ui_PanelAIScreenAI, 720);
    lv_obj_set_height(ui_PanelAIScreenAI, 480);
    lv_obj_set_x(ui_PanelAIScreenAI, 80);
    lv_obj_set_y(ui_PanelAIScreenAI, 0);
    lv_obj_clear_flag(ui_PanelAIScreenAI, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelAIScreenAI, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelAIScreenAI, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelAIScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelAIScreenAI, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelCenterScreenAI = lv_obj_create(ui_PanelAIScreenAI);
    lv_obj_set_width(ui_PanelCenterScreenAI, 696);
    lv_obj_set_height(ui_PanelCenterScreenAI, 456);
    lv_obj_set_x(ui_PanelCenterScreenAI, -10);
    lv_obj_set_y(ui_PanelCenterScreenAI, -10);
    lv_obj_clear_flag(ui_PanelCenterScreenAI, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelCenterScreenAI, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelCenterScreenAI, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCenterScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelCenterScreenAI, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelCenterScreenAI, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTitleScreenAI = lv_label_create(ui_PanelCenterScreenAI);
    lv_obj_set_width(ui_LabelTitleScreenAI, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTitleScreenAI, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_LabelTitleScreenAI, 25);
    lv_obj_set_y(ui_LabelTitleScreenAI, 25);
    lv_label_set_text(ui_LabelTitleScreenAI, AIFunction[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelTitleScreenAI, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTitleScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTitleScreenAI, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelLineScreenAI = lv_obj_create(ui_PanelCenterScreenAI);
    lv_obj_set_width(ui_PanelLineScreenAI, 665);
    lv_obj_set_height(ui_PanelLineScreenAI, 1);
    lv_obj_set_x(ui_PanelLineScreenAI, 15);
    lv_obj_set_y(ui_PanelLineScreenAI, 67);
    lv_obj_clear_flag(ui_PanelLineScreenAI, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelLineScreenAI, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelLineScreenAI, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelLineScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelLineScreenAI, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFunctionScreenAI = lv_label_create(ui_PanelCenterScreenAI);
    lv_obj_set_width(ui_LabelFunctionScreenAI, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelFunctionScreenAI, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_LabelFunctionScreenAI, 25);
    lv_obj_set_y(ui_LabelFunctionScreenAI, 90);
    lv_label_set_recolor(ui_LabelFunctionScreenAI, true);
    lv_label_set_text(ui_LabelFunctionScreenAI, AIdetection[get_cur_language_index()]);
    // lv_obj_set_style_text_color(ui_LabelFunctionScreenAI, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFunctionScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFunctionScreenAI, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelExplanationScreenAI = lv_label_create(ui_PanelCenterScreenAI);
    lv_obj_set_width(ui_LabelExplanationScreenAI, 654);
    lv_obj_set_height(ui_LabelExplanationScreenAI, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_LabelExplanationScreenAI, 26);
    lv_obj_set_y(ui_LabelExplanationScreenAI, 133);
    lv_label_set_text(ui_LabelExplanationScreenAI, "打印过程中可以通过AI检测打印中的异常情况.");
    lv_obj_set_style_text_color(ui_LabelExplanationScreenAI, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelExplanationScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelExplanationScreenAI, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelExplanation = lv_label_create(ui_PanelCenterScreenAI);
    lv_obj_set_width(ui_LabelExplanation, 654);
    lv_obj_set_height(ui_LabelExplanation, LV_SIZE_CONTENT);
    lv_obj_align_to(ui_LabelExplanation, ui_LabelExplanationScreenAI, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
    lv_label_set_text(ui_LabelExplanation, AIShareTips[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelExplanation, lv_color_hex(0xCAA850), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelExplanation, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelExplanation, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SwitchFunctionScreenAI = lv_switch_create(ui_PanelCenterScreenAI);
    lv_obj_set_width(ui_SwitchFunctionScreenAI, 74);
    lv_obj_set_height(ui_SwitchFunctionScreenAI, 36);
    lv_obj_set_x(ui_SwitchFunctionScreenAI, 586);
    lv_obj_set_y(ui_SwitchFunctionScreenAI, 89);
    lv_obj_add_flag(ui_SwitchFunctionScreenAI, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_radius(ui_SwitchFunctionScreenAI, 90, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFunctionScreenAI, lv_color_hex(0x43454A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SwitchFunctionScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_SwitchFunctionScreenAI, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SwitchFunctionScreenAI, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_set_style_radius(ui_SwitchFunctionScreenAI, 30, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFunctionScreenAI, lv_color_hex(0x5F646C), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SwitchFunctionScreenAI, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFunctionScreenAI, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SwitchFunctionScreenAI, 255, LV_PART_KNOB | LV_STATE_CHECKED);

    ui_SensitivityOfAI = lv_obj_create(ui_PanelCenterScreenAI);
    lv_obj_set_width(ui_SensitivityOfAI, 696);
    lv_obj_set_height(ui_SensitivityOfAI, 39);
    lv_obj_align_to(ui_SensitivityOfAI, ui_LabelExplanation, LV_ALIGN_OUT_BOTTOM_LEFT, -26, 5);
    lv_obj_clear_flag(ui_SensitivityOfAI, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_SensitivityOfAI, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SensitivityOfAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SensitivityOfAI, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_SensitivityOfAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_SensitivityOfAI, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_SensitivityOfAI, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    ui_SensitivityLbale = lv_label_create(ui_SensitivityOfAI);
    lv_obj_set_width(ui_SensitivityLbale, 500);
    lv_obj_set_height(ui_SensitivityLbale, 24);
    lv_obj_set_x(ui_SensitivityLbale, 24);
    lv_obj_set_y(ui_SensitivityLbale, 0);
    lv_obj_set_align(ui_SensitivityLbale, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_SensitivityLbale, AISensitivity[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_SensitivityLbale, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SensitivityLbale, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SensitivityLbale, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_SensitivityLbale, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SensitivityImage = lv_img_create(ui_SensitivityOfAI);
    lv_img_set_src(ui_SensitivityImage, &ui_img_vector_24_png);
    lv_obj_set_width(ui_SensitivityImage, 14);
    lv_obj_set_height(ui_SensitivityImage, 28);
    lv_obj_set_x(ui_SensitivityImage, -20);
    lv_obj_set_y(ui_SensitivityImage, 0);
    lv_obj_set_align(ui_SensitivityImage, LV_ALIGN_RIGHT_MID);
    lv_obj_add_flag(ui_SensitivityImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SensitivityImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_SensitivityImage, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_SensitivityMode = lv_label_create(ui_SensitivityOfAI);
    lv_obj_set_width(ui_SensitivityMode, 500);
    lv_obj_set_height(ui_SensitivityMode, 24);
    lv_obj_align_to(ui_SensitivityMode, ui_SensitivityImage, LV_ALIGN_OUT_LEFT_MID, -10, -3);
    lv_label_set_text(ui_SensitivityMode, AINormalMode[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_SensitivityMode, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SensitivityMode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SensitivityMode, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_SensitivityMode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SensitivityMode, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFirstDetectionAI = lv_label_create(ui_PanelCenterScreenAI);
    lv_obj_set_width(ui_LabelFirstDetectionAI, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelFirstDetectionAI, LV_SIZE_CONTENT);
    lv_obj_align_to(ui_LabelFirstDetectionAI, ui_SensitivityOfAI, LV_ALIGN_OUT_BOTTOM_LEFT, 26, 20);
    lv_label_set_text(ui_LabelFirstDetectionAI, FirstLayerDetection[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelFirstDetectionAI, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFirstDetectionAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFirstDetectionAI, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SwitchFirstDetectionAI = lv_switch_create(ui_PanelCenterScreenAI);
    lv_obj_set_width(ui_SwitchFirstDetectionAI, 74);
    lv_obj_set_height(ui_SwitchFirstDetectionAI, 36);
    lv_obj_align_to(ui_SwitchFirstDetectionAI, ui_SensitivityOfAI, LV_ALIGN_OUT_BOTTOM_RIGHT, -37, 20);
    lv_obj_add_flag(ui_SwitchFirstDetectionAI, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_radius(ui_SwitchFirstDetectionAI, 90, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFirstDetectionAI, lv_color_hex(0x43454A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SwitchFirstDetectionAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_SwitchFirstDetectionAI, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SwitchFirstDetectionAI, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_set_style_radius(ui_SwitchFirstDetectionAI, 30, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFirstDetectionAI, lv_color_hex(0x5F646C), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SwitchFirstDetectionAI, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFirstDetectionAI, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SwitchFirstDetectionAI, 255, LV_PART_KNOB | LV_STATE_CHECKED);

    ui_CheckboxScreenAI = lv_checkbox_create(ui_PanelCenterScreenAI);
    lv_checkbox_set_text(ui_CheckboxScreenAI, AIPausePrint[get_cur_language_index()]);
    lv_obj_set_width(ui_CheckboxScreenAI, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_CheckboxScreenAI, LV_SIZE_CONTENT);
    lv_obj_align_to(ui_CheckboxScreenAI, ui_LabelFirstDetectionAI, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
    lv_obj_add_flag(ui_CheckboxScreenAI, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_CheckboxScreenAI, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CheckboxScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CheckboxScreenAI, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CheckboxScreenAI, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_CheckboxScreenAI, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_CheckboxScreenAI, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui_CheckboxScreenAI, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_CheckboxScreenAI, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_CheckboxScreenAI, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CheckboxScreenAI, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CheckboxScreenAI, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CheckboxScreenAI, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CheckboxScreenAI, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_CheckboxScreenAI, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_ext_click_area(ui_CheckboxScreenAI, 20);

    ui_LabelFlowCalibration = lv_label_create(ui_PanelCenterScreenAI);
    lv_obj_set_width(ui_LabelFlowCalibration, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelFlowCalibration, LV_SIZE_CONTENT);
    lv_obj_align_to(ui_LabelFlowCalibration, ui_CheckboxScreenAI, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 18);
    lv_label_set_text(ui_LabelFlowCalibration, FlowCalibration[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelFlowCalibration, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFlowCalibration, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFlowCalibration, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFlowCalibrationTips = lv_label_create(ui_PanelCenterScreenAI);
    lv_obj_set_width(ui_LabelFlowCalibrationTips, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelFlowCalibrationTips, LV_SIZE_CONTENT);
    lv_obj_align_to(ui_LabelFlowCalibrationTips, ui_LabelFlowCalibration, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 3);
    lv_label_set_text(ui_LabelFlowCalibrationTips, FlowCalibrationTips[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelFlowCalibrationTips, lv_color_hex(0xFFD158), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFlowCalibrationTips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFlowCalibrationTips, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SwitchFlowCalibration = lv_switch_create(ui_PanelCenterScreenAI);
    lv_obj_set_width(ui_SwitchFlowCalibration, 76);
    lv_obj_set_height(ui_SwitchFlowCalibration, 36);
    lv_obj_align(ui_SwitchFlowCalibration, LV_ALIGN_TOP_LEFT, 586, 322);
    lv_obj_add_flag(ui_SwitchFlowCalibration, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_radius(ui_SwitchFlowCalibration, 90, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFlowCalibration, lv_color_hex(0x43454A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SwitchFlowCalibration, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFlowCalibration, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SwitchFlowCalibration, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    lv_obj_set_style_bg_color(ui_SwitchFlowCalibration, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SwitchFlowCalibration, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_set_style_radius(ui_SwitchFlowCalibration, 30, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFlowCalibration, lv_color_hex(0x5F646C), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SwitchFlowCalibration, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SwitchFlowCalibration, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SwitchFlowCalibration, 255, LV_PART_KNOB | LV_STATE_CHECKED);

    ui_ButtonBackScreenAI = lv_btn_create(ui_PanelCenterScreenAI);
    lv_obj_set_width(ui_ButtonBackScreenAI, 116);
    lv_obj_set_height(ui_ButtonBackScreenAI, 60);
    lv_obj_set_x(ui_ButtonBackScreenAI, 560);
    lv_obj_set_y(ui_ButtonBackScreenAI, 381);
    lv_obj_add_flag(ui_ButtonBackScreenAI, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonBackScreenAI, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonBackScreenAI, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonBackScreenAI, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonBackScreenAI, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonBackScreenAI, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonBackScreenAI, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelBackScreenAI = lv_label_create(ui_ButtonBackScreenAI);
    lv_obj_set_width(ui_LabelBackScreenAI, 116);
    lv_obj_set_height(ui_LabelBackScreenAI, 30);
    lv_obj_set_align(ui_LabelBackScreenAI, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelBackScreenAI, Back[get_cur_language_index()]);
    lv_obj_set_style_text_align(ui_LabelBackScreenAI, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBackScreenAI, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    /*******************************************/
    // cur_radio_box = ui_CheckboxFaultDetectionScreenAI;
    // if ( cur_radio_box )
    //     lv_obj_add_state(cur_radio_box, LV_STATE_CHECKED);

    lv_obj_add_event_cb(ui_ButtonBackScreenAI, ui_event_ButtonBackScreenAI, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SwitchFunctionScreenAI, ui_event_SwitchDetectionAI, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SwitchFirstDetectionAI, ui_event_SwitchFirstLayerDetection, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SwitchFlowCalibration, ui_event_SwitchFlowCalibration, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CheckboxScreenAI, ui_event_CheckboxScreenAIDetection, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ScreenAI, ui_event_loadAiScreen, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SensitivityOfAI, ui_event_SensitivityOfAI, LV_EVENT_ALL, NULL);

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
    if(system_state.Camera_model_state == 0)
    {
        CrLogW("don't exist camera");
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
        lv_label_set_text(ui_SensitivityMode, AINormalMode[get_cur_language_index()]);
    }
    else
    {
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
    {
        lv_label_set_text(ui_LabelExplanationScreenAI, AIDetectionTips[language_index]);
        lv_obj_update_layout(ui_LabelExplanationScreenAI);
        
        lv_obj_align_to(ui_LabelExplanation, ui_LabelExplanationScreenAI, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
        lv_obj_align_to(ui_SensitivityOfAI, ui_LabelExplanation, LV_ALIGN_OUT_BOTTOM_LEFT, -26, 5);
    }
    if(ui_LabelExplanation)
    {
        lv_label_set_text(ui_LabelExplanation, AIShareTips[language_index]);
    }
    if(ui_LabelFirstDetectionAI)
        lv_label_set_text(ui_LabelFirstDetectionAI, FirstLayerDetection[language_index]);
    if(ui_LabelBackScreenAI)
        lv_label_set_text(ui_LabelBackScreenAI, Back[language_index]);
    if(ui_CheckboxScreenAI)
        lv_checkbox_set_text(ui_CheckboxScreenAI, AIPausePrint[language_index]);
    if(ui_LabelFlowCalibration)
        lv_label_set_text(ui_LabelFlowCalibration, FlowCalibration[language_index]);
    if(ui_LabelFlowCalibrationTips)
        lv_label_set_text(ui_LabelFlowCalibrationTips, FlowCalibrationTips[language_index]);
    if(ui_SensitivityLbale)
        lv_label_set_text(ui_SensitivityLbale, AISensitivity[language_index]);
}

void aiModeChangeHandle(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        lv_obj_t * parent = lv_obj_get_parent(target);
        if(strcmp(userdata, "1") == 0)//btn1
        {
            lv_obj_set_style_border_color(target, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(lv_obj_get_child(parent, 3), lv_color_hex(0x646768), LV_PART_MAIN | LV_STATE_DEFAULT);
            set_printer_data(CONTROL_AI_OPTIONS, 3, "61");
        }
        else if(strcmp(userdata, "2") == 0)
        {
            lv_obj_set_style_border_color(target, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(lv_obj_get_child(parent, 1), lv_color_hex(0x646768), LV_PART_MAIN | LV_STATE_DEFAULT);
            set_printer_data(CONTROL_AI_OPTIONS, 3, "62");
        }
        else
        {
            //目标控件为弹窗背景，直接删除
            lv_obj_del(target);
            return;
        }
        lv_obj_del(lv_obj_get_parent(parent));
    }
}

void create_AImode_msg(AiModeType mode)
{
    uint8_t language_index = get_cur_language_index();
    lv_obj_t * aiModeBg = lv_obj_create(lv_scr_act());
    lv_obj_set_width(aiModeBg, 800);
    lv_obj_set_height(aiModeBg, 480);
    lv_obj_clear_flag(aiModeBg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(aiModeBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(aiModeBg, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(aiModeBg, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(aiModeBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(aiModeBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(aiModeBg, LV_OBJ_FLAG_CLICKABLE);      /// Flags

    lv_obj_t * aiModeinfo = lv_obj_create(aiModeBg);
    lv_obj_set_width(aiModeinfo, 418);
    lv_obj_set_height(aiModeinfo, 420);
    lv_obj_align(aiModeinfo, LV_ALIGN_TOP_MID, 0, 20);
    lv_obj_clear_flag(aiModeinfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(aiModeinfo, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(aiModeinfo, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(aiModeinfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(aiModeinfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(aiModeinfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(aiModeinfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(aiModeinfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(aiModeinfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * aimodeTitle = lv_label_create(aiModeinfo);
    lv_obj_set_width(aimodeTitle, LV_SIZE_CONTENT);
    lv_obj_set_height(aimodeTitle, 38);
    lv_obj_align(aimodeTitle, LV_ALIGN_TOP_MID, 0, 11);
    lv_label_set_long_mode(aimodeTitle, LV_LABEL_LONG_SCROLL);
    lv_label_set_text(aimodeTitle, AISensitivity[language_index]);
    lv_obj_set_style_text_color(aimodeTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(aimodeTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(aimodeTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(aimodeTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * btn1 = lv_btn_create(aiModeinfo);
    lv_obj_set_width(btn1, 340);
    lv_obj_set_height(btn1, 67);
    lv_obj_align(btn1, LV_ALIGN_TOP_MID, 0, 67);
    lv_obj_add_flag(btn1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(btn1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(btn1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(btn1, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(btn1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(btn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(btn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(btn1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(btn1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * btn1label = lv_label_create(btn1);
    lv_obj_set_width(btn1label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(btn1label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(btn1label, LV_ALIGN_CENTER);
    lv_label_set_text(btn1label, AINormalMode[language_index]);
    lv_obj_set_style_text_color(btn1label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(btn1label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(btn1label, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * NormalModeTips = lv_label_create(aiModeinfo);
    lv_obj_align(NormalModeTips, LV_ALIGN_TOP_MID, 0, 143);
    lv_obj_set_width(NormalModeTips, 344);
    lv_obj_set_height(NormalModeTips, LV_SIZE_CONTENT);
    char tempbuff[256] = {0};
    snprintf(tempbuff, 256, AINormalModeTips[language_index], ai_state.AiCheckTime);
    lv_label_set_text(NormalModeTips, tempbuff);
    lv_obj_set_style_text_color(NormalModeTips, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(NormalModeTips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(NormalModeTips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(NormalModeTips, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * btn2 = lv_btn_create(aiModeinfo);
    lv_obj_set_width(btn2, 340);
    lv_obj_set_height(btn2, 67);
    lv_obj_align(btn2, LV_ALIGN_TOP_MID, 0, 240);
    lv_obj_add_flag(btn2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(btn2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(btn2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(btn2, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(btn2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(btn2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(btn2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(btn2, lv_color_hex(0x646768), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(btn2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * btn2label = lv_label_create(btn2);
    lv_obj_set_width(btn2label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(btn2label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(btn2label, LV_ALIGN_CENTER);
    lv_label_set_text(btn2label, AIProMode[language_index]);
    lv_obj_set_style_text_color(btn2label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(btn2label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(btn2label, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * ProModeTips = lv_label_create(aiModeinfo);
    lv_obj_align(ProModeTips, LV_ALIGN_TOP_MID, 0, 319);
    lv_obj_set_width(ProModeTips, 400);
    lv_obj_set_height(ProModeTips, LV_SIZE_CONTENT);
    lv_label_set_text(ProModeTips, AIProModeTips[language_index]);
    lv_obj_set_style_text_color(ProModeTips, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ProModeTips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ProModeTips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ProModeTips, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(btn1, aiModeChangeHandle, LV_EVENT_ALL, "1");
    lv_obj_add_event_cb(btn2, aiModeChangeHandle, LV_EVENT_ALL, "2");
    lv_obj_add_event_cb(aiModeBg, aiModeChangeHandle, LV_EVENT_ALL, "3");

    //初始化模式
    if(mode == AI_MODE_TYPE_ROUTINE)
    {
        lv_obj_set_style_border_color(btn1, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(btn2, lv_color_hex(0x646768), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    else if(mode == AI_MODE_TYPE_MAJOR)
    {
        lv_obj_set_style_border_color(btn1, lv_color_hex(0x646768), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(btn2, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    CrLogI("create AImode change msgbox success");
}

void EnterMsgboxTips(lv_obj_t * parent, char *message, char *btn1label)
{
    uint8_t language_index = get_cur_language_index();
    lv_obj_t * PrivacyMessagebox = lv_obj_create(parent);
    lv_obj_set_width(PrivacyMessagebox, 800);
    lv_obj_set_height(PrivacyMessagebox, 480);
    lv_obj_clear_flag(PrivacyMessagebox, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(PrivacyMessagebox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(PrivacyMessagebox, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(PrivacyMessagebox, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(PrivacyMessagebox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(PrivacyMessagebox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * PrivacyMessagecontent = lv_obj_create(PrivacyMessagebox);
    lv_obj_set_width(PrivacyMessagecontent, 418);
    lv_obj_set_height(PrivacyMessagecontent, 300);
    lv_obj_set_x(PrivacyMessagecontent, 191);
    lv_obj_set_y(PrivacyMessagecontent, 79);
    lv_obj_clear_flag(PrivacyMessagecontent, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(PrivacyMessagecontent, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(PrivacyMessagecontent, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(PrivacyMessagecontent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(PrivacyMessagecontent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(PrivacyMessagecontent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(PrivacyMessagecontent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(PrivacyMessagecontent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(PrivacyMessagecontent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * PrivacyMsgboxlabel1 = lv_label_create(PrivacyMessagecontent);
    lv_obj_set_width(PrivacyMsgboxlabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(PrivacyMsgboxlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(PrivacyMsgboxlabel1, 0);
    lv_obj_set_y(PrivacyMsgboxlabel1, 20);
    lv_obj_set_align(PrivacyMsgboxlabel1, LV_ALIGN_TOP_MID);
    lv_label_set_long_mode(PrivacyMsgboxlabel1, LV_LABEL_LONG_SCROLL);
    lv_label_set_text(PrivacyMsgboxlabel1, KindTips[language_index]);
    lv_obj_set_style_text_color(PrivacyMsgboxlabel1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(PrivacyMsgboxlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(PrivacyMsgboxlabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(PrivacyMsgboxlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * PrivacyMsgboxlabel2 = lv_checkbox_create(PrivacyMessagecontent);
    lv_obj_set_width(PrivacyMsgboxlabel2, LV_SIZE_CONTENT);
    lv_obj_set_height(PrivacyMsgboxlabel2, LV_SIZE_CONTENT);
    lv_obj_align(PrivacyMsgboxlabel2, LV_ALIGN_TOP_LEFT, 47, 99);
    lv_checkbox_set_text(PrivacyMsgboxlabel2, "");
    lv_obj_add_flag(PrivacyMsgboxlabel2, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_set_style_text_color(PrivacyMsgboxlabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(PrivacyMsgboxlabel2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(PrivacyMsgboxlabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(PrivacyMsgboxlabel2, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(PrivacyMsgboxlabel2, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(PrivacyMsgboxlabel2, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(PrivacyMsgboxlabel2, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_radius(PrivacyMsgboxlabel2, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(PrivacyMsgboxlabel2, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(PrivacyMsgboxlabel2, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    lv_obj_t * Msgboxlabel2 = lv_label_create(PrivacyMessagecontent);
    lv_label_set_recolor(Msgboxlabel2, true);
    lv_obj_set_width(Msgboxlabel2, 287);   /// 1
    lv_obj_set_height(Msgboxlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_align_to(Msgboxlabel2, PrivacyMsgboxlabel2, LV_ALIGN_OUT_RIGHT_TOP, 0, 0);
    lv_label_set_long_mode(Msgboxlabel2, LV_LABEL_LONG_WRAP);
    lv_obj_add_flag(Msgboxlabel2, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_label_set_text(Msgboxlabel2, message);
    lv_obj_set_style_text_color(Msgboxlabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(Msgboxlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(Msgboxlabel2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(Msgboxlabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * PrivacyMsgboxButton1 = lv_btn_create(PrivacyMessagecontent);
    lv_obj_set_width(PrivacyMsgboxButton1, 146);
    lv_obj_set_height(PrivacyMsgboxButton1, 60);
    lv_obj_set_x(PrivacyMsgboxButton1, 136);
    lv_obj_set_y(PrivacyMsgboxButton1, 220);
    lv_obj_add_flag(PrivacyMsgboxButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(PrivacyMsgboxButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(PrivacyMsgboxButton1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(PrivacyMsgboxButton1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(PrivacyMsgboxButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(PrivacyMsgboxButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(PrivacyMsgboxButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * PrivacyMsgboxBtnlabel1 = lv_label_create(PrivacyMsgboxButton1);
    lv_obj_set_width(PrivacyMsgboxBtnlabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(PrivacyMsgboxBtnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(PrivacyMsgboxBtnlabel1, LV_ALIGN_CENTER);
    lv_label_set_text(PrivacyMsgboxBtnlabel1, btn1label);
    lv_obj_set_style_text_color(PrivacyMsgboxBtnlabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(PrivacyMsgboxBtnlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(PrivacyMsgboxBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(PrivacyMsgboxButton1, Msgbox_event_handler, LV_EVENT_ALL, PrivacyMessagebox);
    lv_obj_add_event_cb(PrivacyMsgboxlabel2, Msgbox_event_handler, LV_EVENT_ALL, PrivacyMessagebox);
    lv_obj_add_event_cb(Msgboxlabel2, Msgbox_event_handler, LV_EVENT_ALL, PrivacyMessagebox);

    CrLogI("msgbox create success");
}

void Msgbox_event_handler(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        int count = lv_obj_get_child_cnt(userdata);
        lv_obj_t * child = lv_obj_get_child(userdata, count - 1);
        if(target == lv_obj_get_child(child, 2))//label2
        {   
            CrLogI("enter the share content page");
            CreateSharePicturePage();
            // lv_obj_del(userdata);
        }
        else if(target == lv_obj_get_child(child, 3))//btn1
        {
            //发送确认分享的命令
            if(lv_obj_has_state(lv_obj_get_child(child, 1), LV_STATE_CHECKED))
                set_printer_data(CONTROL_PARAMETERS, 3, "s1");
            else
                set_printer_data(CONTROL_PARAMETERS, 3, "s0");
            CrLogI("close the msgbox,the state:%d",lv_obj_has_state(lv_obj_get_child(child, 1), LV_STATE_CHECKED));
            lv_obj_del(userdata);
        }
    }
}

void SharePageEventHandle(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    char * userdata = lv_event_get_user_data(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(strcmp(userdata, "1") == 0) //btn1
        {
            lv_obj_del(lv_obj_get_parent(target));
        }
    }
}

//创建分享政策页面
void CreateSharePicturePage()
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
    lv_obj_align(policyButton1, LV_ALIGN_TOP_MID, 0, 400);
    lv_obj_add_flag(policyButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(policyButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(policyButton1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(policyButton1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(policyButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(policyButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(policyButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * policyBtnlabel1 = lv_label_create(policyButton1);
    lv_obj_set_width(policyBtnlabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(policyBtnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(policyBtnlabel1, LV_ALIGN_CENTER);
    lv_label_set_text(policyBtnlabel1, Confirm[language_index]);
    lv_obj_set_style_text_color(policyBtnlabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(policyBtnlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(policyBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

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

    lv_obj_add_event_cb(policyButton1, SharePageEventHandle, LV_EVENT_ALL, "1");
}

void refreshSharePictrueState(bool state)
{
    if(state)
    {
        lv_obj_clear_flag(ui_LabelExplanation, LV_OBJ_FLAG_HIDDEN);
        lv_obj_align_to(ui_LabelExplanation, ui_LabelExplanationScreenAI, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
        lv_obj_align_to(ui_SensitivityOfAI, ui_LabelExplanation, LV_ALIGN_OUT_BOTTOM_LEFT, -26, 5);
    }
    else
    {
        lv_obj_add_flag(ui_LabelExplanation, LV_OBJ_FLAG_HIDDEN);
        lv_obj_align_to(ui_SensitivityOfAI, ui_LabelExplanationScreenAI, LV_ALIGN_OUT_BOTTOM_LEFT, -26, 5);
    }
}

