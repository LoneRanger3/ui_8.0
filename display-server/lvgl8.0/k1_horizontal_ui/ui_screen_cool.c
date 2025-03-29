// /*
//  * @Description : 
//  * @Author      : Yufeng Zhang
//  * @Date: 2023-01-29 11:17:35
//  * @LastEditTime: 2023-03-17 18:38:33
//  */
// #include "ui_screen_cool.h"
// #include <stdio.h>
// #include "mult_language.h"
// #include "ui_screen_HomeNormal.h"
// #include "ui_screen_FileManage.h"
// #include "../custom/lvgl_cmd.h"
// #include "ui_Screen_Settings.h"
// #include "ui_Screen_CustomerService.h"
// #include "ui_screen_AxisMove.h"
// #include "ui_screen_Adjustment.h"
// #include "ui_Screen_CustomerService.h"
// #include "ui_screen_filament_Infor.h"


// /*********************variable***********************/
// static lv_obj_t * ui_ScreenCool;
// static lv_obj_t * ui_PanelPageScreenCool;

// static lv_obj_t * ui_ButtonHomeScreenCool;
// static lv_obj_t * ui_ImageCoolPage;
// static lv_obj_t * ui_ButtonFileManageScreenCool;
// static lv_obj_t * ui_ButtonSettingsScreenCool;
// static lv_obj_t * ui_ButtonReserveScreenCool;

// static lv_obj_t * ui_PanelTitleScreenCool;

// static lv_obj_t * ui_PanelMoveScreenCool;
// static lv_obj_t * ui_LabelMoveScreenCool;
// static lv_obj_t * ui_PanelFilamentScreenCool;
// static lv_obj_t * ui_LabelFilamentScreenCool;
// static lv_obj_t * ui_PanelCoolScreenCool;
// static lv_obj_t * ui_LabelCoolScreenCool;
// static lv_obj_t * ui_PanelAdjustmentScreenCool;
// static lv_obj_t * ui_LabelAdjustmentScreenCool;

// static lv_obj_t * ui_ScreenCoolPanelCenter;
// static lv_obj_t * ui_ScreenCoolPanelFans;
// static lv_obj_t * ui_ScreenCoolImageModelFan;
// static lv_obj_t * ui_ScreenCoolLabelModelFan;
// static lv_obj_t * ui_ScreenCoolSliderModelFan;
// static lv_obj_t * ui_ScreenCoolLabelModelPercent;
// static lv_obj_t * ui_ScreenCoolImageAuxiliaryFan;
// static lv_obj_t * ui_ScreenCoolLabelAuxiliaryFan;
// static lv_obj_t * ui_ScreenCoolSliderAuxiliaryFan;
// static lv_obj_t * ui_ScreenCoolLabelAuxiliaryPercent;
// static lv_obj_t * ui_ScreenCoolImageChassisFan;
// static lv_obj_t * ui_ScreenCoolLabelChassisFan;
// static lv_obj_t * ui_ScreenCoolSliderChassisFan;
// static lv_obj_t * ui_ScreenCoolLabelChassisPercent;

// /***********************funs*************************/
// static void ui_event_ButtonHomeScreenCool(lv_event_t * e);
// static void ui_event_ButtonFileManageScreenCool(lv_event_t * e);
// static void ui_event_ButtonSettingsScreenCool(lv_event_t * e);
// static void ui_event_ButtonReserveScreenCool(lv_event_t * e);

// static void ui_event_SliderModelFans(lv_event_t * e);
// static void ui_event_SliderCoolFans(lv_event_t * e);
// static void ui_event_SliderChassisFans(lv_event_t * e);
// static void ui_event_ButtonMoveScreenCool(lv_event_t * e);
// static void ui_event_ButtonFilamentScreenCool(lv_event_t * e);
// static void ui_event_ButtonAdjustScreenCool(lv_event_t * e);

// /**************************************************/


// static void CoolPageHomeBtnClicked(lv_event_t * e);
// static void CoolPageFileManageBtnClicked(lv_event_t * e);
// static void CoolPageSettingBtnClicked(lv_event_t * e);
// static void CoolPageReserveBtnClicked(lv_event_t * e);

// static void CoolPageMoveBtnClicked(lv_event_t * e);
// static void CoolPageFilamentBtnClicked(lv_event_t * e);
// static void CoolPageAdjustBtnClicked(lv_event_t * e);
// static void ModelFanValueChanged(lv_event_t * e);
// static void CoolFanValueChanged(lv_event_t * e);
// static void ChassisFanValueChanged(lv_event_t * e);


// /***********************custom variable****************************/
// static uint8_t last_model_fan_percent = 0;
// static uint8_t last_cool_fan_percent = 0;
// static uint8_t last_chassis_fan_percent = 0;

// /***********************custom funs****************************/



// /**********************************************/
// void ui_event_ButtonHomeScreenCool(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         CoolPageHomeBtnClicked(e);
//     }
// }
// void ui_event_ButtonFileManageScreenCool(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         CoolPageFileManageBtnClicked(e);
//     }
// }
// void ui_event_ButtonSettingsScreenCool(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         CoolPageSettingBtnClicked(e);
//     }
// }
// void ui_event_ButtonReserveScreenCool(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         CoolPageReserveBtnClicked(e);
//     }
// }

// void ui_event_ButtonMoveScreenCool(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         CoolPageMoveBtnClicked(e);
//     }
// }
// void ui_event_ButtonFilamentScreenCool(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         CoolPageFilamentBtnClicked(e);
//     }
// }
// void ui_event_ButtonAdjustScreenCool(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         CoolPageAdjustBtnClicked(e);
//     }
// }

// void ui_event_SliderModelFans(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if ( event_code == LV_EVENT_RELEASED ) {
//         ModelFanValueChanged(e);
//     }
// }

// void ui_event_SliderCoolFans(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if ( event_code == LV_EVENT_RELEASED ) {
//         CoolFanValueChanged(e);
//     }
// }

// void ui_event_SliderChassisFans(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if ( event_code == LV_EVENT_RELEASED ) {
//         ChassisFanValueChanged(e);
//     }
// }

// /*************************/
// void CoolPageHomeBtnClicked(lv_event_t * e)
// {
// 	// Your code here
//     if ( home_printing_is_printing_finished() )
//         LoadHomeNormalScreen();
//     else
//         LoadHomePrintingScreen();
// }

// void CoolPageFileManageBtnClicked(lv_event_t * e)
// {
// 	// Your code here
//     LoadFileManageScreen();
// }

// void CoolPageSettingBtnClicked(lv_event_t * e)
// {
// 	// Your code here
//     LoadSettingsScreen();
// }

// void CoolPageReserveBtnClicked(lv_event_t * e)
// {
// 	// Your code here
//     LoadCustomerServiceScreen();
// }

// void CoolPageMoveBtnClicked(lv_event_t * e)
// {
// 	// Your code here
//     LoadAxisMoveScreen();
// }

// void CoolPageFilamentBtnClicked(lv_event_t * e)
// {
// 	// Your code here
//     LoadFilamentScreen();
// }

// void CoolPageAdjustBtnClicked(lv_event_t * e)
// {
// 	// Your code here
//     LoadAdjustmentScreen();

// }

// void ModelFanValueChanged(lv_event_t * e)
// {
//     // Your code here
//     uint8_t percent = lv_slider_get_value(ui_ScreenCoolSliderModelFan);
//     CrLogI("modelfan value:%d, last value:%d", percent, last_model_fan_percent);
//     // if ( percent != last_model_fan_percent )
//     // {
//         send_set_model_fan_opt_cmd(percent);
//     // }
    
//     last_model_fan_percent = percent;
    
// }

// void CoolFanValueChanged(lv_event_t * e)
// {
//     // Your code here
//     uint8_t percent = lv_slider_get_value(ui_ScreenCoolSliderAuxiliaryFan);
//     CrLogI("coolfan value:%d, last value:%d", percent, last_cool_fan_percent);
//     // if ( percent != last_cool_fan_percent )
//     // {
//         send_set_auxiliary_fan_opt_cmd(percent);
//     // }
//     last_cool_fan_percent = percent;
// }

// void ChassisFanValueChanged(lv_event_t * e)
// {
//     // Your code here
//     uint8_t percent = lv_slider_get_value(ui_ScreenCoolSliderChassisFan);
//     CrLogI("Chassisfan value:%d, last value:%d", percent, last_chassis_fan_percent);
//     // if ( percent != last_chassis_fan_percent )
//         send_set_chassis_fan_opt_cmd(percent);
    
//     last_chassis_fan_percent = percent;
// }

// void ui_ScreenCool_screen_init(void)
// {
//     uint8_t language_index = get_cur_language_index();
//     ui_ScreenCool = lv_obj_create(NULL);
//     lv_obj_clear_flag(ui_ScreenCool, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_clear_flag(ui_ScreenCool, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_bg_color(ui_ScreenCool, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_ScreenCool, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_blend_mode(ui_ScreenCool, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_PanelPageScreenCool= lv_obj_create(ui_ScreenCool);
//     lv_obj_set_width(ui_PanelPageScreenCool, 80);
//     lv_obj_set_height(ui_PanelPageScreenCool, 480);
//     lv_obj_clear_flag(ui_PanelPageScreenCool, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_border_side(ui_PanelPageScreenCool, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_ButtonHomeScreenCool = lv_btn_create(ui_PanelPageScreenCool);
//     lv_obj_set_width(ui_ButtonHomeScreenCool, 80);
//     lv_obj_set_height(ui_ButtonHomeScreenCool, 96);
//     lv_obj_set_x(ui_ButtonHomeScreenCool, -22);
//     lv_obj_set_y(ui_ButtonHomeScreenCool, -22);
//     lv_obj_add_flag(ui_ButtonHomeScreenCool, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     lv_obj_clear_flag(ui_ButtonHomeScreenCool, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     // lv_obj_set_style_bg_color(ui_ButtonHomeScreenCool, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     // lv_obj_set_style_bg_opa(ui_ButtonHomeScreenCool, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_img_src(ui_ButtonHomeScreenCool, &ui_img_pagehome_png, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_ButtonHomeScreenCool, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_color(ui_ButtonHomeScreenCool, lv_color_hex(0x42BDD8),
//                                   LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_opa(ui_ButtonHomeScreenCool, 255, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_width(ui_ButtonHomeScreenCool, 2, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_side(ui_ButtonHomeScreenCool, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

//     ui_ImageCoolPage = lv_img_create(ui_PanelPageScreenCool);
//     lv_img_set_src(ui_ImageCoolPage, &ui_img_pagemoveselected_png);
//     lv_obj_set_width(ui_ImageCoolPage, 80);
//     lv_obj_set_height(ui_ImageCoolPage, LV_SIZE_CONTENT);    /// 92
//     lv_obj_set_x(ui_ImageCoolPage, -22);
//     lv_obj_set_y(ui_ImageCoolPage, 74);
//     lv_obj_add_flag(ui_ImageCoolPage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
//     lv_obj_clear_flag(ui_ImageCoolPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

//     ui_ButtonFileManageScreenCool= lv_btn_create(ui_PanelPageScreenCool);
//     lv_obj_set_width(ui_ButtonFileManageScreenCool, 80);
//     lv_obj_set_height(ui_ButtonFileManageScreenCool, 96);
//     lv_obj_set_x(ui_ButtonFileManageScreenCool, -22);
//     lv_obj_set_y(ui_ButtonFileManageScreenCool, 170);
//     lv_obj_add_flag(ui_ButtonFileManageScreenCool, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     lv_obj_clear_flag(ui_ButtonFileManageScreenCool, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     // lv_obj_set_style_bg_color(ui_ButtonFileManageScreenCool, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     // lv_obj_set_style_bg_opa(ui_ButtonFileManageScreenCool, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_img_src(ui_ButtonFileManageScreenCool, &ui_img_pagefilemanage_png,
//                                 LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_ButtonFileManageScreenCool, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_color(ui_ButtonFileManageScreenCool, lv_color_hex(0x42BDD8),
//                                   LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_opa(ui_ButtonFileManageScreenCool, 255,
//                                 LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_width(ui_ButtonFileManageScreenCool, 2,
//                                   LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_side(ui_ButtonFileManageScreenCool, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

//     ui_ButtonSettingsScreenCool = lv_btn_create(ui_PanelPageScreenCool);
//     lv_obj_set_width(ui_ButtonSettingsScreenCool, 80);
//     lv_obj_set_height(ui_ButtonSettingsScreenCool, 96);
//     lv_obj_set_x(ui_ButtonSettingsScreenCool, -22);
//     lv_obj_set_y(ui_ButtonSettingsScreenCool, 266);
//     lv_obj_add_flag(ui_ButtonSettingsScreenCool, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     lv_obj_clear_flag(ui_ButtonSettingsScreenCool, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     // lv_obj_set_style_bg_color(ui_ButtonSettingsScreenCool, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     // lv_obj_set_style_bg_opa(ui_ButtonSettingsScreenCool, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_img_src(ui_ButtonSettingsScreenCool, &ui_img_pagesetting_png,
//                                 LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_color(ui_ButtonSettingsScreenCool, lv_color_hex(0x42BDD8),
//                                   LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_opa(ui_ButtonSettingsScreenCool, 255, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_width(ui_ButtonSettingsScreenCool, 2, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_side(ui_ButtonSettingsScreenCool, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

//     ui_ButtonReserveScreenCool = lv_btn_create(ui_PanelPageScreenCool);
//     lv_obj_set_width(ui_ButtonReserveScreenCool, 80);
//     lv_obj_set_height(ui_ButtonReserveScreenCool, 96);
//     lv_obj_set_x(ui_ButtonReserveScreenCool, -22);
//     lv_obj_set_y(ui_ButtonReserveScreenCool, 362);
//     lv_obj_add_flag(ui_ButtonReserveScreenCool, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     lv_obj_clear_flag(ui_ButtonReserveScreenCool, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     // lv_obj_set_style_bg_color(ui_ButtonReserveScreenCool, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     // lv_obj_set_style_bg_opa(ui_ButtonReserveScreenCool, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_img_src(ui_ButtonReserveScreenCool, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_color(ui_ButtonReserveScreenCool, lv_color_hex(0x42BDD8),
//                                   LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_opa(ui_ButtonReserveScreenCool, 255, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_width(ui_ButtonReserveScreenCool, 2, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_side(ui_ButtonReserveScreenCool, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

//     ui_PanelTitleScreenCool = lv_obj_create(ui_ScreenCool);
//     lv_obj_set_width(ui_PanelTitleScreenCool, 720);
//     lv_obj_set_height(ui_PanelTitleScreenCool, 50);
//     lv_obj_set_x(ui_PanelTitleScreenCool, 80);
//     lv_obj_set_y(ui_PanelTitleScreenCool, 0);
//     lv_obj_clear_flag(ui_PanelTitleScreenCool, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelTitleScreenCool, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelTitleScreenCool, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelTitleScreenCool, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelTitleScreenCool, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_all(ui_PanelTitleScreenCool, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_flex_flow(ui_PanelTitleScreenCool, LV_FLEX_FLOW_ROW);
//     lv_obj_set_flex_align(ui_PanelTitleScreenCool, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_END);

//     ui_PanelMoveScreenCool = lv_obj_create(ui_PanelTitleScreenCool);
//     lv_obj_set_width(ui_PanelMoveScreenCool, 240);
//     lv_obj_set_height(ui_PanelMoveScreenCool, 46);
//     lv_obj_clear_flag(ui_PanelMoveScreenCool, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_border_side(ui_PanelMoveScreenCool, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_radius(ui_PanelMoveScreenCool, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelMoveScreenCool, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelMoveScreenCool, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_add_flag(ui_PanelMoveScreenCool, LV_OBJ_FLAG_CLICKABLE);      /// Flags
//     lv_obj_set_style_border_side(ui_PanelMoveScreenCool, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelMoveScreenCool, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_color(ui_PanelMoveScreenCool, lv_color_hex(0x42BDD8),
//                                   LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_opa(ui_PanelMoveScreenCool, 255, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_width(ui_PanelMoveScreenCool, 2, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_shadow_width(ui_PanelMoveScreenCool, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_spread(ui_PanelMoveScreenCool, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_LabelMoveScreenCool = lv_label_create(ui_PanelMoveScreenCool);
//     lv_obj_set_width(ui_LabelMoveScreenCool, 240);
//     lv_obj_set_height(ui_LabelMoveScreenCool, LV_SIZE_CONTENT);
//     lv_obj_set_align(ui_LabelMoveScreenCool, LV_ALIGN_CENTER);
//     //lv_label_set_long_mode(ui_LabelMoveAndTemperTitle, LV_LABEL_LONG_SCROLL_CIRCULAR);
//     lv_label_set_text(ui_LabelMoveScreenCool, MovePageTitle[get_cur_language_index()]);
//     //lv_label_set_recolor(ui_LabelMoveAndTemperTitle, "true");
//     lv_obj_set_style_text_color(ui_LabelMoveScreenCool, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelMoveScreenCool, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_align(ui_LabelMoveScreenCool, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelMoveScreenCool, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_PanelFilamentScreenCool = lv_obj_create(ui_PanelTitleScreenCool);
//     lv_obj_set_width(ui_PanelFilamentScreenCool, 200);
//     lv_obj_set_height(ui_PanelFilamentScreenCool, 46);
//     lv_obj_clear_flag(ui_PanelFilamentScreenCool, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_add_flag(ui_PanelFilamentScreenCool, LV_OBJ_FLAG_CLICKABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelFilamentScreenCool, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelFilamentScreenCool, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelFilamentScreenCool, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelFilamentScreenCool, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelFilamentScreenCool, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_color(ui_PanelFilamentScreenCool, lv_color_hex(0x42BDD8),
//                                   LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_opa(ui_PanelFilamentScreenCool, 255, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_width(ui_PanelFilamentScreenCool, 2, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_shadow_width(ui_PanelFilamentScreenCool, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_spread(ui_PanelFilamentScreenCool, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    

//     ui_LabelFilamentScreenCool  = lv_label_create(ui_PanelFilamentScreenCool);
//     lv_obj_set_width(ui_LabelFilamentScreenCool, 200);
//     lv_obj_set_height(ui_LabelFilamentScreenCool, LV_SIZE_CONTENT);
//     lv_obj_set_align(ui_LabelFilamentScreenCool, LV_ALIGN_CENTER);
//     lv_label_set_long_mode(ui_LabelFilamentScreenCool, LV_LABEL_LONG_SCROLL_CIRCULAR);
//     lv_label_set_text(ui_LabelFilamentScreenCool, Extrude_Retract[get_cur_language_index()]);   //进退料
//     //lv_label_set_recolor(ui_LabelFilament, "true");
//     lv_obj_set_style_text_color(ui_LabelFilamentScreenCool, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelFilamentScreenCool, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_align(ui_LabelFilamentScreenCool, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelFilamentScreenCool, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
//     ui_PanelCoolScreenCool = lv_obj_create(ui_PanelTitleScreenCool);
//     lv_obj_set_width(ui_PanelCoolScreenCool, 100);
//     lv_obj_set_height(ui_PanelCoolScreenCool, 46);
//     lv_obj_clear_flag(ui_PanelCoolScreenCool, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelCoolScreenCool, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelCoolScreenCool, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelCoolScreenCool, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelCoolScreenCool, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_LabelCoolScreenCool= lv_label_create(ui_PanelCoolScreenCool);
//     lv_obj_set_width(ui_LabelCoolScreenCool, 100);
//     lv_obj_set_height(ui_LabelCoolScreenCool, LV_SIZE_CONTENT);
//     lv_obj_set_align(ui_LabelCoolScreenCool, LV_ALIGN_CENTER);
//     lv_label_set_long_mode(ui_LabelCoolScreenCool, LV_LABEL_LONG_SCROLL_CIRCULAR);
//     lv_label_set_text(ui_LabelCoolScreenCool, Cooling[get_cur_language_index()]);     //冷却
//     //lv_label_set_recolor(ui_LabelCool, "true");
//     lv_obj_set_style_text_color(ui_LabelCoolScreenCool, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelCoolScreenCool, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_align(ui_LabelCoolScreenCool, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelCoolScreenCool, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
//     ui_PanelAdjustmentScreenCool = lv_obj_create(ui_PanelTitleScreenCool);
//     lv_obj_set_width(ui_PanelAdjustmentScreenCool, 152);
//     lv_obj_set_height(ui_PanelAdjustmentScreenCool, 46);
//     lv_obj_set_x(ui_PanelAdjustmentScreenCool, 546);
//     lv_obj_set_y(ui_PanelAdjustmentScreenCool, -18);
//     lv_obj_clear_flag(ui_PanelAdjustmentScreenCool, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_add_flag(ui_PanelAdjustmentScreenCool, LV_OBJ_FLAG_CLICKABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelAdjustmentScreenCool, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelAdjustmentScreenCool, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelAdjustmentScreenCool, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelAdjustmentScreenCool, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelAdjustmentScreenCool, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_color(ui_PanelAdjustmentScreenCool, lv_color_hex(0x42BDD8),
//                                   LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_opa(ui_PanelAdjustmentScreenCool, 255, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_width(ui_PanelAdjustmentScreenCool, 2, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_shadow_width(ui_PanelAdjustmentScreenCool, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_spread(ui_PanelAdjustmentScreenCool, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_add_flag(ui_PanelAdjustmentScreenCool, LV_OBJ_FLAG_HIDDEN);      /// Flags

//     ui_LabelAdjustmentScreenCool = lv_label_create(ui_PanelAdjustmentScreenCool);
//     lv_obj_set_width(ui_LabelAdjustmentScreenCool, 152);
//     lv_obj_set_height(ui_LabelAdjustmentScreenCool, LV_SIZE_CONTENT);
//     lv_obj_set_align(ui_LabelAdjustmentScreenCool, LV_ALIGN_CENTER);
//     lv_label_set_long_mode(ui_LabelAdjustmentScreenCool, LV_LABEL_LONG_SCROLL_CIRCULAR);
//     lv_label_set_text(ui_LabelAdjustmentScreenCool, Adjustment[get_cur_language_index()]);  //调整
//     //lv_label_set_recolor(ui_LabelAdjustment, "true");
//     lv_obj_set_style_text_color(ui_LabelAdjustmentScreenCool, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelAdjustmentScreenCool, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_align(ui_LabelAdjustmentScreenCool, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelAdjustmentScreenCool, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_ScreenCoolPanelCenter = lv_obj_create(ui_ScreenCool);
//     lv_obj_set_width(ui_ScreenCoolPanelCenter, 720);
//     lv_obj_set_height(ui_ScreenCoolPanelCenter, 430);
//     lv_obj_set_x(ui_ScreenCoolPanelCenter, 80);
//     lv_obj_set_y(ui_ScreenCoolPanelCenter, 50);
//     lv_obj_clear_flag(ui_ScreenCoolPanelCenter, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_ScreenCoolPanelCenter, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_ScreenCoolPanelCenter, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_ScreenCoolPanelCenter, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_ScreenCoolPanelCenter, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_ScreenCoolPanelFans = lv_obj_create(ui_ScreenCoolPanelCenter);
//     lv_obj_set_width(ui_ScreenCoolPanelFans, 696);
//     lv_obj_set_height(ui_ScreenCoolPanelFans, 406);
//     lv_obj_set_x(ui_ScreenCoolPanelFans, -10);
//     lv_obj_set_y(ui_ScreenCoolPanelFans, -10);
//     lv_obj_clear_flag(ui_ScreenCoolPanelFans, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_bg_color(ui_ScreenCoolPanelFans, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_ScreenCoolPanelFans, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_ScreenCoolPanelFans, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_ScreenCoolImageModelFan = lv_img_create(ui_ScreenCoolPanelFans);
//     lv_img_set_src(ui_ScreenCoolImageModelFan, &ui_img_cool_stop_fan_png);
//     lv_obj_set_width(ui_ScreenCoolImageModelFan, 39);
//     lv_obj_set_height(ui_ScreenCoolImageModelFan, 39);
//     lv_obj_set_x(ui_ScreenCoolImageModelFan, 13);
//     lv_obj_set_y(ui_ScreenCoolImageModelFan, 64);
//     lv_obj_add_flag(ui_ScreenCoolImageModelFan, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
//     lv_obj_clear_flag(ui_ScreenCoolImageModelFan, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

//     ui_ScreenCoolLabelModelFan = lv_label_create(ui_ScreenCoolPanelFans);
//     lv_obj_set_width(ui_ScreenCoolLabelModelFan, LV_SIZE_CONTENT);
//     lv_obj_set_height(ui_ScreenCoolLabelModelFan, LV_SIZE_CONTENT);
//     lv_obj_set_x(ui_ScreenCoolLabelModelFan, 62);
//     lv_obj_set_y(ui_ScreenCoolLabelModelFan, 30);   //从40改成30
//     lv_label_set_text(ui_ScreenCoolLabelModelFan, "模型风扇");
//     lv_obj_set_style_text_color(ui_ScreenCoolLabelModelFan, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_ScreenCoolLabelModelFan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_ScreenCoolLabelModelFan, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_ScreenCoolSliderModelFan = lv_slider_create(ui_ScreenCoolPanelFans);
//     lv_slider_set_value(ui_ScreenCoolSliderModelFan, 20, LV_ANIM_OFF);
//     if(lv_slider_get_mode(ui_ScreenCoolSliderModelFan) == LV_SLIDER_MODE_RANGE) 
//         lv_slider_set_left_value(ui_ScreenCoolSliderModelFan, 0, LV_ANIM_OFF);
//     lv_obj_set_width(ui_ScreenCoolSliderModelFan, 492);
//     lv_obj_set_height(ui_ScreenCoolSliderModelFan, 16);
//     lv_obj_set_x(ui_ScreenCoolSliderModelFan, 62);
//     lv_obj_set_y(ui_ScreenCoolSliderModelFan, 74);
//     lv_obj_set_style_radius(ui_ScreenCoolSliderModelFan, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_ScreenCoolSliderModelFan, lv_color_hex(0x616367), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_ScreenCoolSliderModelFan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_set_style_radius(ui_ScreenCoolSliderModelFan, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_ScreenCoolSliderModelFan, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_ScreenCoolSliderModelFan, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

//     lv_obj_set_style_radius(ui_ScreenCoolSliderModelFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_ScreenCoolSliderModelFan, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_ScreenCoolSliderModelFan, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_left(ui_ScreenCoolSliderModelFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_right(ui_ScreenCoolSliderModelFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_top(ui_ScreenCoolSliderModelFan, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_bottom(ui_ScreenCoolSliderModelFan, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_ScreenCoolSliderModelFan, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_ScreenCoolSliderModelFan, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_ext_click_area(ui_ScreenCoolSliderModelFan, 50);

//     ui_ScreenCoolLabelModelPercent = lv_label_create(ui_ScreenCoolPanelFans);
//     lv_obj_set_width(ui_ScreenCoolLabelModelPercent, 70);
//     lv_obj_set_height(ui_ScreenCoolLabelModelPercent, 30);
//     lv_obj_set_x(ui_ScreenCoolLabelModelPercent, 572);
//     lv_obj_set_y(ui_ScreenCoolLabelModelPercent, 66);
//     lv_label_set_text(ui_ScreenCoolLabelModelPercent, "");
//     lv_obj_set_style_text_color(ui_ScreenCoolLabelModelPercent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_ScreenCoolLabelModelPercent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_ScreenCoolLabelModelPercent, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_ScreenCoolImageAuxiliaryFan = lv_img_create(ui_ScreenCoolPanelFans);
//     lv_img_set_src(ui_ScreenCoolImageAuxiliaryFan, &ui_img_cool_stop_fan_png);
//     lv_obj_set_width(ui_ScreenCoolImageAuxiliaryFan, 39);
//     lv_obj_set_height(ui_ScreenCoolImageAuxiliaryFan, 39);
//     lv_obj_set_x(ui_ScreenCoolImageAuxiliaryFan, 13);
//     lv_obj_set_y(ui_ScreenCoolImageAuxiliaryFan, 169);
//     lv_obj_add_flag(ui_ScreenCoolImageAuxiliaryFan, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
//     lv_obj_clear_flag(ui_ScreenCoolImageAuxiliaryFan, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

//     ui_ScreenCoolLabelAuxiliaryFan = lv_label_create(ui_ScreenCoolPanelFans);
//     lv_obj_set_width(ui_ScreenCoolLabelAuxiliaryFan, LV_SIZE_CONTENT);
//     lv_obj_set_height(ui_ScreenCoolLabelAuxiliaryFan, LV_SIZE_CONTENT);
//     lv_obj_set_x(ui_ScreenCoolLabelAuxiliaryFan, 62);
//     lv_obj_set_y(ui_ScreenCoolLabelAuxiliaryFan, 135);  //从145改成135
//     lv_label_set_text(ui_ScreenCoolLabelAuxiliaryFan, "辅助风扇");
//     lv_obj_set_style_text_color(ui_ScreenCoolLabelAuxiliaryFan, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_ScreenCoolLabelAuxiliaryFan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_ScreenCoolLabelAuxiliaryFan, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_ScreenCoolSliderAuxiliaryFan = lv_slider_create(ui_ScreenCoolPanelFans);
//     //lv_slider_set_value(ui_ScreenCoolSliderAuxiliaryFan, 20, LV_ANIM_OFF);
//     if(lv_slider_get_mode(ui_ScreenCoolSliderAuxiliaryFan) == LV_SLIDER_MODE_RANGE) 
//         lv_slider_set_left_value(ui_ScreenCoolSliderAuxiliaryFan, 0, LV_ANIM_OFF);
//     lv_obj_set_width(ui_ScreenCoolSliderAuxiliaryFan, 492);
//     lv_obj_set_height(ui_ScreenCoolSliderAuxiliaryFan, 16);
//     lv_obj_set_x(ui_ScreenCoolSliderAuxiliaryFan, 62);
//     lv_obj_set_y(ui_ScreenCoolSliderAuxiliaryFan, 179);
//     lv_obj_set_style_radius(ui_ScreenCoolSliderAuxiliaryFan, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_ScreenCoolSliderAuxiliaryFan, lv_color_hex(0x616367), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_ScreenCoolSliderAuxiliaryFan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_set_style_radius(ui_ScreenCoolSliderAuxiliaryFan, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_ScreenCoolSliderAuxiliaryFan, lv_color_hex(0x42BDD8),
//                               LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_ScreenCoolSliderAuxiliaryFan, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

//     lv_obj_set_style_radius(ui_ScreenCoolSliderAuxiliaryFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_ScreenCoolSliderAuxiliaryFan, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_ScreenCoolSliderAuxiliaryFan, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_left(ui_ScreenCoolSliderAuxiliaryFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_right(ui_ScreenCoolSliderAuxiliaryFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_top(ui_ScreenCoolSliderAuxiliaryFan, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_bottom(ui_ScreenCoolSliderAuxiliaryFan, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_ScreenCoolSliderAuxiliaryFan, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_ScreenCoolSliderAuxiliaryFan, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_ext_click_area(ui_ScreenCoolSliderAuxiliaryFan, 50);

//     ui_ScreenCoolLabelAuxiliaryPercent = lv_label_create(ui_ScreenCoolPanelFans);
//     lv_obj_set_width(ui_ScreenCoolLabelAuxiliaryPercent, 70);
//     lv_obj_set_height(ui_ScreenCoolLabelAuxiliaryPercent, 30);
//     lv_obj_set_x(ui_ScreenCoolLabelAuxiliaryPercent, 572);
//     lv_obj_set_y(ui_ScreenCoolLabelAuxiliaryPercent, 171);
//     lv_label_set_text(ui_ScreenCoolLabelAuxiliaryPercent, "");
//     lv_obj_set_style_text_color(ui_ScreenCoolLabelAuxiliaryPercent, lv_color_hex(0xFFFFFF),
//                                 LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_ScreenCoolLabelAuxiliaryPercent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_ScreenCoolLabelAuxiliaryPercent, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_ScreenCoolImageChassisFan = lv_img_create(ui_ScreenCoolPanelFans);
//     lv_img_set_src(ui_ScreenCoolImageChassisFan, &ui_img_cool_stop_fan_png);
//     lv_obj_set_width(ui_ScreenCoolImageChassisFan, 39);
//     lv_obj_set_height(ui_ScreenCoolImageChassisFan, 39);
//     lv_obj_set_x(ui_ScreenCoolImageChassisFan, 13);
//     lv_obj_set_y(ui_ScreenCoolImageChassisFan, 271);
//     lv_obj_add_flag(ui_ScreenCoolImageChassisFan, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
//     lv_obj_clear_flag(ui_ScreenCoolImageChassisFan, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

//     ui_ScreenCoolLabelChassisFan = lv_label_create(ui_ScreenCoolPanelFans);
//     lv_obj_set_width(ui_ScreenCoolLabelChassisFan, LV_SIZE_CONTENT);
//     lv_obj_set_height(ui_ScreenCoolLabelChassisFan, LV_SIZE_CONTENT);
//     lv_obj_set_x(ui_ScreenCoolLabelChassisFan, 62);
//     lv_obj_set_y(ui_ScreenCoolLabelChassisFan, 237);  //从247改成237
//     lv_label_set_text(ui_ScreenCoolLabelChassisFan, "机箱风扇");
//     lv_obj_set_style_text_color(ui_ScreenCoolLabelChassisFan, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_ScreenCoolLabelChassisFan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_ScreenCoolLabelChassisFan, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_ScreenCoolSliderChassisFan = lv_slider_create(ui_ScreenCoolPanelFans);
//     lv_slider_set_value(ui_ScreenCoolSliderChassisFan, 20, LV_ANIM_OFF);
//     if(lv_slider_get_mode(ui_ScreenCoolSliderChassisFan) == LV_SLIDER_MODE_RANGE) 
//         lv_slider_set_left_value(ui_ScreenCoolSliderChassisFan, 0, LV_ANIM_OFF);
//     lv_obj_set_width(ui_ScreenCoolSliderChassisFan, 492);
//     lv_obj_set_height(ui_ScreenCoolSliderChassisFan, 16);
//     lv_obj_set_x(ui_ScreenCoolSliderChassisFan, 62);
//     lv_obj_set_y(ui_ScreenCoolSliderChassisFan, 281);
//     lv_obj_set_style_radius(ui_ScreenCoolSliderChassisFan, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_ScreenCoolSliderChassisFan, lv_color_hex(0x616367), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_ScreenCoolSliderChassisFan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

//     lv_obj_set_style_radius(ui_ScreenCoolSliderChassisFan, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_ScreenCoolSliderChassisFan, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_ScreenCoolSliderChassisFan, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

//     lv_obj_set_style_radius(ui_ScreenCoolSliderChassisFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_ScreenCoolSliderChassisFan, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_ScreenCoolSliderChassisFan, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_left(ui_ScreenCoolSliderChassisFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_right(ui_ScreenCoolSliderChassisFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_top(ui_ScreenCoolSliderChassisFan, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_bottom(ui_ScreenCoolSliderChassisFan, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_row(ui_ScreenCoolSliderChassisFan, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_column(ui_ScreenCoolSliderChassisFan, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_ext_click_area(ui_ScreenCoolSliderChassisFan, 50);

//     ui_ScreenCoolLabelChassisPercent = lv_label_create(ui_ScreenCoolPanelFans);
//     lv_obj_set_width(ui_ScreenCoolLabelChassisPercent, 70);
//     lv_obj_set_height(ui_ScreenCoolLabelChassisPercent, 30);
//     lv_obj_set_x(ui_ScreenCoolLabelChassisPercent, 572);
//     lv_obj_set_y(ui_ScreenCoolLabelChassisPercent, 273);
//     lv_label_set_text(ui_ScreenCoolLabelChassisPercent, "");
//     lv_obj_set_style_text_color(ui_ScreenCoolLabelChassisPercent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_ScreenCoolLabelChassisPercent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_ScreenCoolLabelChassisPercent, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    

//     lv_obj_add_event_cb(ui_ButtonHomeScreenCool, ui_event_ButtonHomeScreenCool, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_ButtonFileManageScreenCool, ui_event_ButtonFileManageScreenCool, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_ButtonSettingsScreenCool, ui_event_ButtonSettingsScreenCool, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_ButtonReserveScreenCool, ui_event_ButtonReserveScreenCool, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_PanelMoveScreenCool, ui_event_ButtonMoveScreenCool, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_PanelFilamentScreenCool, ui_event_ButtonFilamentScreenCool, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_PanelAdjustmentScreenCool, ui_event_ButtonAdjustScreenCool, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_ScreenCoolSliderModelFan, ui_event_SliderModelFans, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_ScreenCoolSliderAuxiliaryFan, ui_event_SliderCoolFans, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_ScreenCoolSliderChassisFan, ui_event_SliderChassisFans, LV_EVENT_ALL, NULL);

//     /*************************************/
//     lv_slider_set_range(ui_ScreenCoolSliderModelFan, 0, 100);
//     lv_slider_set_range(ui_ScreenCoolSliderAuxiliaryFan, 0, 100);
//     lv_slider_set_range(ui_ScreenCoolSliderChassisFan, 0, 100);
// }

// void LoadCoolScreen(void)
// {
//     lv_disp_load_scr(ui_ScreenCool);

//     send_get_fans_status_cmd();    
// }

// void cool_set_model_fan_duty_percent(uint8_t percent)
// {
//     if ( percent > 100 )
//         percent = 100;

//     char buff[5] = {0};
//     sprintf(buff, "%d%%", percent); 
//     lv_label_set_text(ui_ScreenCoolLabelModelPercent, buff);
//     lv_slider_set_value(ui_ScreenCoolSliderModelFan, percent, LV_ANIM_OFF);
// }

// void cool_set_cool_fan_duty_percent(uint8_t percent)
// {
//     if ( percent > 100 )
//         percent = 100;
//     CrLogI("COOL FAN value get :%d",percent);
//     // percent = percent * 65 / 255 + 0; //风扇生效范围在190-255区间内
//     // CrLogI("COOL FAN value get after:%d",percent);
//     char buff[5] = {0};
//     sprintf(buff, "%d%%", percent); 
//     lv_label_set_text(ui_ScreenCoolLabelAuxiliaryPercent, buff);
//     lv_slider_set_value(ui_ScreenCoolSliderAuxiliaryFan, percent, LV_ANIM_OFF);
// }

// void cool_set_Chassis_fan_duty_percent(uint8_t percent)
// {
//     if ( percent > 100 )
//         percent = 100;

//     char buff[5] = {0};
//     sprintf(buff, "%d%%", percent); 
//     lv_label_set_text(ui_ScreenCoolLabelChassisPercent, buff);
//     lv_slider_set_value(ui_ScreenCoolSliderChassisFan, percent, LV_ANIM_OFF);
// }

// void cool_change_language_text()
// {
//     if ( ui_LabelMoveScreenCool )
//     {
//         lv_label_set_text(ui_LabelMoveScreenCool, MovePageTitle[get_cur_language_index()]);
//         redefine_label_size(ui_LabelMoveScreenCool, lv_font25.font,  0, 0, 240, 0);
        
//         lv_obj_update_layout(ui_PanelMoveScreenCool);
//         redefine_widgets_size(ui_PanelMoveScreenCool, ui_LabelMoveScreenCool, 5, 0, 240, 46);
//     }
//     if ( ui_LabelAdjustmentScreenCool )
//     {
//         lv_label_set_text(ui_LabelAdjustmentScreenCool, Adjustment[get_cur_language_index()]);
//         redefine_label_size(ui_LabelAdjustmentScreenCool, lv_font25.font, 0, 0, 150, 0);

//         lv_obj_update_layout(ui_PanelAdjustmentScreenCool);
//         redefine_widgets_size(ui_PanelAdjustmentScreenCool, ui_LabelAdjustmentScreenCool, 5, 0, 100, 46);

//     }
//     if ( ui_LabelCoolScreenCool )
//     {
//         lv_label_set_text(ui_LabelCoolScreenCool, Cooling[get_cur_language_index()]);     //冷却
//         redefine_label_size(ui_LabelCoolScreenCool, lv_font25.font, 0, 0, 240, 0);
        
//         lv_obj_update_layout(ui_PanelCoolScreenCool);
//         redefine_widgets_size(ui_PanelCoolScreenCool, ui_LabelCoolScreenCool, 5, 0, 240, 46);
//     }
//     if ( ui_LabelFilamentScreenCool )
//     {
//         lv_label_set_text(ui_LabelFilamentScreenCool, Extrude_Retract[get_cur_language_index()]);
//         redefine_label_size(ui_LabelFilamentScreenCool, lv_font25.font, 0, 0, 240, 0);
        
//         lv_obj_update_layout(ui_PanelFilamentScreenCool);
//         redefine_widgets_size(ui_PanelFilamentScreenCool, ui_LabelFilamentScreenCool, 5, 0, 200, 46);
//     }
//     if ( ui_ScreenCoolLabelModelFan )
//         lv_label_set_text(ui_ScreenCoolLabelModelFan, ModelFan[get_cur_language_index()]);
//     if ( ui_ScreenCoolLabelAuxiliaryFan )
//         lv_label_set_text(ui_ScreenCoolLabelAuxiliaryFan, CoolFan[get_cur_language_index()]);
//     if ( ui_ScreenCoolLabelChassisFan )
//         lv_label_set_text(ui_ScreenCoolLabelChassisFan, BackFan[get_cur_language_index()]);

        
// }