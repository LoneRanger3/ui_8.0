// /*
//  * @Description : 
//  * @Author      : Yufeng Zhang
//  * @Date: 2023-01-30 11:13:28
//  * @LastEditTime: 2023-03-18 14:00:38
//  */
// #include "ui_screen_filament_Infor.h"
// #include <stdio.h>
// #include "mult_language.h"
// #include "ui_screen_HomeNormal.h"
// #include "ui_screen_HomePrinting.h"
// #include "ui_screen_FileManage.h"
// #include "../custom/lvgl_cmd.h"
// #include "ui_Screen_Settings.h"
// #include "ui_Screen_CustomerService.h"
// #include "ui_screen_AxisMove.h"
// #include "ui_screen_Adjustment.h"
// #include "ui_Screen_CustomerService.h"
// #include "lvgl/src/misc/lv_timer.h"
// #include "ui_custom_messagebox.h"
// #include "ui_custom_reminderbox.h"

// /**********************/
// enum SHOW_TEMPER_PANEL{
//     SHOW_TEMPER_EDIT_PANEL,
//     SHOW_HEATING_PANEL,
//     SHOW_NORMAL_PANEL,
// };

// enum STEP_DIR_STATE{
//     STEP_NOT_START,
//     STEP_PROCCESSING,
//     STEP_FINISHED,
// };

// enum IN_FILA_PROCCESS{
//     IN_FILAMENT_FIRST_STEP,
//     IN_FILAMENT_SECOND_STEP,
//     IN_FILAMENT_THIRD_STEP,
// };

// enum OUT_FILA_PROCCESS{
//     OUT_FILAMENT_FIRST_STEP,
//     OUT_FILAMENT_SECOND_STEP,
//     OUT_FILAMENT_THIRD_STEP,
//     OUT_FILAMENT_FOURTH_STEP,
// };

// #define FILAMENT_ACTION_INCREASE_TEMPER 10
// #define FILAMENT_COOL_EXTRUDE_TEMPER 180
// //#define HOTEND_MAX_TEMPER 300

// /********************screen variable***************************/
// static lv_obj_t * ui_ScreenFilament;
// static lv_obj_t * ui_PanelPageScreenFila;

// static lv_obj_t * ui_ButtonHomeScreenFila;
// static lv_obj_t * ui_ImageFilaPage;
// static lv_obj_t * ui_ButtonFileManageScreenFila;
// static lv_obj_t * ui_ButtonSettingsScreenFila;
// static lv_obj_t * ui_ButtonReserveScreenFila;

// static lv_obj_t * ui_PanelTitleScreenFila;

// static lv_obj_t * ui_PanelMoveScreenFila;
// static lv_obj_t * ui_LabelMoveScreenFila;
// static lv_obj_t * ui_PanelFilamentScreenFila;
// static lv_obj_t * ui_LabelFilamentScreenFila;
// static lv_obj_t * ui_PanelCoolScreenFila;
// static lv_obj_t * ui_LabelCoolScreenFila;
// static lv_obj_t * ui_PanelAdjustmentScreenFila;
// static lv_obj_t * ui_LabelAdjustmentScreenFila;

// /********************right center panel***************************/
// static lv_obj_t * ui_PanelCenterScreenFila;

// /********************action panel***************************/
// static lv_obj_t * ui_PanelActionScreenFila;


// /********************hotend temper edit panel***************************/
// static lv_obj_t * ui_PanelTempScreenFilament;
// static lv_obj_t * ui_LabelTitleScreenFilament;
// static lv_obj_t * ui_ButtonSubTemperScreenFilament;
// static lv_obj_t * ui_ButtonAddTemperScreenFilament;
// static lv_obj_t * ui_PanelTemperValueScreenFilament;
// static lv_obj_t * ui_LabelTemperScreenFilament;
// static lv_obj_t * ui_LabelTemperUnitScreenFilament;

// /********************hotend heating panel***************************/
// static lv_obj_t * ui_PanelhotendHeatScreenFilament;
// static lv_obj_t * ui_ImageHotendHeating;
// static lv_obj_t * ui_LabelRealTemper;
// static lv_obj_t * ui_LabelTargetTemper;
// static lv_obj_t * ui_ImageTemperTo;

// /********************hotend normal panel***************************/
// static lv_obj_t * ui_PanelhotendNormalScreenFila;
// static lv_obj_t * ui_ImageHotendNormal;
// static lv_obj_t * ui_LabelNormalRealTemper;

// /********************filament action panel***************************/
// static lv_obj_t * ui_PanelInAndOutAction;
// static lv_obj_t * ui_ButtonInFilaScreenFilament;
// static lv_obj_t * ui_LabelInFilaScreenFilament;
// static lv_obj_t * ui_ButtonOutFilaScreenFilament;
// static lv_obj_t * ui_LabelOutFilaScreenFilament;

// /**************Prompt panel****************/
// static lv_obj_t * ui_PanelPromptScreenFila;
// static lv_obj_t * ui_Panel6ScreenFilament;

// /**************tips infor****************/
// static lv_obj_t * ui_LabelTitleTips;
// static lv_obj_t * ui_LabelTipsContentScreenFila;

// /**************filament step****************/
// static lv_obj_t * ui_LabelTitleFilament;
// static lv_obj_t * ui_PanelFilamentProccess;
// static lv_obj_t * ui_BtnFirstStepScreenFila;
// static lv_obj_t * ui_LabelFirstStepScreenFila;
// static lv_obj_t * ui_LabelFilamentFirstStep;
// static lv_obj_t * ui_PanelFirstStepScreenFila;
// static lv_obj_t * ui_BtnSecondStepScreenFila;
// static lv_obj_t * ui_LabelSecondStepScreenFila;
// static lv_obj_t * ui_LabelFilamentSecondStep;
// static lv_obj_t * ui_PanelSecondStepScreenFila;
// static lv_obj_t * ui_BtnThirdStepScreenFila;
// static lv_obj_t * ui_LabelThirdStepScreenFila;
// static lv_obj_t * ui_LabelFilamentThirdStep;
// static lv_obj_t * ui_PanelThirdStepScreenFila;
// static lv_obj_t * ui_BtnFourthStepScreenFila;
// static lv_obj_t * ui_LabelFourthStepScreenFila;
// static lv_obj_t * ui_LabelFilamentFourthStep;

// int targettemp = 0;
// /********************funs **************************/
// /*****************事件函数声明*******************/
// static void ui_event_ButtonHomeScreenFila(lv_event_t * e);
// static void ui_event_ButtonFileManageScreenFila(lv_event_t * e);
// static void ui_event_ButtonSettingsScreenFila(lv_event_t * e);
// static void ui_event_ButtonReserveScreenFila(lv_event_t * e);

// static void ui_event_ButtonMoveScreenFila(lv_event_t * e);
// static void ui_event_ButtonCoolScreenFila(lv_event_t * e);
// static void ui_event_ButtonAdjustScreenFila(lv_event_t * e);

// static void ui_event_BtnInFilament(lv_event_t * e);
// static void ui_event_BtnOutFilament(lv_event_t * e);
// static void ui_event_BtnAddTargetTemper(lv_event_t * e);
// static void ui_event_BtnSubTargetTemper(lv_event_t * e);
// static void ui_event_PanelTargetTemper(lv_event_t * e);

// /*****************事件响应函数声明*******************/
// static void FilaPageHomeBtnClicked(lv_event_t * e);
// static void FilaPageFileManageBtnClicked(lv_event_t * e);
// static void FilaPageSettingBtnClicked(lv_event_t * e);
// static void FilaPageReserveBtnClicked(lv_event_t * e);

// static void FilaPageMoveBtnClicked(lv_event_t * e);
// static void FilaPageCoolBtnClicked(lv_event_t * e);
// static void FilaPageAdjustBtnClicked(lv_event_t * e);

// static void FilaPageInFilamentBtnClicked(lv_event_t * e);
// static void FilaPageOutFilamentBtnClicked(lv_event_t * e);
// static void FilaPageAddTemperBtnClicked(lv_event_t * e);
// static void FilaPageSubTemperBtnClicked(lv_event_t * e);
// static void FilaPageTemperPanelClicked(lv_event_t * e);

// /*********************custom variable**********************/
// static lv_timer_t *timer_proccess = NULL;
// static uint16_t edit_target_temper = 240;
// static enum FILA_ACTION_TYPE filament_action = FILA_ACTION_NONE;
// static uint8_t filament_action_step_order = 0;


// /********************custom funs**********************/
// static void show_temper_panel(enum SHOW_TEMPER_PANEL panel);
// static void show_proccess_panel(bool show_proccess);
// static void show_in_filament_proccess(enum IN_FILA_PROCCESS in_step);
// static void show_out_filament_proccess(enum OUT_FILA_PROCCESS out_step);
// static void show_step_btn_state(lv_obj_t *step_btn, bool is_start);
// static void show_step_label_state(lv_obj_t *step_label, bool is_start);
// static void show_step_dir_panel_state(lv_obj_t *step_dir, enum STEP_DIR_STATE state);
// static void show_filament_proccess_steps(bool in_fila);
// static void fila_hotend_edit_target_temper_callback(void *param);


// void proccess_callback(struct _lv_timer_t *timer)
// {
//     static uint32_t count = 0;
//     uint8_t times = count++ % 8;
//     if ( times == 0 )
//     {
//         show_temper_panel(SHOW_TEMPER_EDIT_PANEL);
//         show_proccess_panel(false);
//     }
//     else if ( (times > 0) && (times < 4) )
//     {
//         show_proccess_panel(true);
//         show_in_filament_proccess((enum IN_FILA_PROCCESS)(times - 1));
//     }
//     else
//     {
//         show_proccess_panel(true);
//         show_out_filament_proccess((enum OUT_FILA_PROCCESS)(times - 4));
//     }
// }

// /**********************事件函数实现**********************/
// void ui_event_ButtonHomeScreenFila(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         FilaPageHomeBtnClicked(e);
//     }
// }
// void ui_event_ButtonFileManageScreenFila(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         FilaPageFileManageBtnClicked(e);
//     }
// }
// void ui_event_ButtonSettingsScreenFila(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         FilaPageSettingBtnClicked(e);
//     }
// }
// void ui_event_ButtonReserveScreenFila(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         FilaPageReserveBtnClicked(e);
//     }
// }

// void ui_event_ButtonMoveScreenFila(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         FilaPageMoveBtnClicked(e);
//     }
// }
// void ui_event_ButtonCoolScreenFila(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         FilaPageCoolBtnClicked(e);
//     }
// }
// void ui_event_ButtonAdjustScreenFila(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         FilaPageAdjustBtnClicked(e);
//     }
// }

// void ui_event_BtnInFilament(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         FilaPageInFilamentBtnClicked(e);
//     }
// }

// void ui_event_BtnOutFilament(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         FilaPageOutFilamentBtnClicked(e);
//     }
// }

// void ui_event_BtnAddTargetTemper(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         FilaPageAddTemperBtnClicked(e);
//     }
// }

// void ui_event_BtnSubTargetTemper(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         FilaPageSubTemperBtnClicked(e);
//     }
// }

// void ui_event_PanelTargetTemper(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         FilaPageTemperPanelClicked(e);
//     }
// }

// void ui_event_PageLoad(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_SCREEN_LOADED) {
//         CrLogI("load the filamentinfo page");
//     }
// }

// /**********************事件响应函数实现**********************/
// void FilaPageHomeBtnClicked(lv_event_t * e)
// {
// 	// Your code here
//     if ( home_printing_is_printing_finished() )
//         LoadHomeNormalScreen();
//     else
//         LoadHomePrintingScreen();
// }

// void FilaPageFileManageBtnClicked(lv_event_t * e)
// {
// 	// Your code here
//     LoadFileManageScreen();
// }

// void FilaPageSettingBtnClicked(lv_event_t * e)
// {
// 	// Your code here
//     LoadSettingsScreen();
// }

// void FilaPageReserveBtnClicked(lv_event_t * e)
// {
// 	// Your code here
//     LoadCustomerServiceScreen();
// }

// void FilaPageMoveBtnClicked(lv_event_t * e)
// {
// 	// Your code here
//     LoadAxisMoveScreen();
// }

// void FilaPageCoolBtnClicked(lv_event_t * e)
// {
// 	// Your code here
//     LoadCoolScreen();
// }

// void FilaPageAdjustBtnClicked(lv_event_t * e)
// {
// 	// Your code here
//     LoadAdjustmentScreen();

// }

// void time_too_close(struct _lv_timer_t *timer)
// {
//     CrLogI("out of time,stop the filament option.");
//     filament_actions_status(false);
// }

// void FilaPageInFilamentBtnClicked(lv_event_t * e)
// {
//     show_proccess_panel(true);
//     if ( edit_target_temper < FILAMENT_COOL_EXTRUDE_TEMPER )
//         edit_target_temper = FILAMENT_COOL_EXTRUDE_TEMPER;
    
//     filament_action = FILA_ACTION_IN;
//     filament_action_step_order = 0;
//     // send_set_target_temper_cmd(edit_target_temper, true);
//     // show_in_filament_proccess(IN_FILAMENT_FIRST_STEP);
//     targettemp = atoi(hotend_max_temp);
//     CrLogI("extrude filament,the last targettemp is:%d",targettemp);
//     char buff[30] = {0};
//     snprintf(buff, 30, "1%d", edit_target_temper);
//     set_printer_data(0x08, strlen(buff), buff);
//     filament_actions_status(true);

//     timer_proccess = lv_timer_create(time_too_close, 1000 * 3, NULL);
//     lv_timer_set_repeat_count(timer_proccess, 1);
// }

// void FilaPageOutFilamentBtnClicked(lv_event_t * e)
// {
//     show_proccess_panel(true);
//     if ( edit_target_temper < FILAMENT_COOL_EXTRUDE_TEMPER )
//         edit_target_temper = FILAMENT_COOL_EXTRUDE_TEMPER;
    
//     filament_action = FILA_ACTION_OUT;
//     filament_action_step_order = 0;
//     // send_set_target_temper_cmd(edit_target_temper, true);
//     // show_out_filament_proccess(OUT_FILAMENT_FIRST_STEP);
//     targettemp = atoi(hotend_max_temp);
//     CrLogI("retract filament,the last targettemp is:%d",targettemp);
//     char buff[30] = {0};
//     snprintf(buff, 30, "2%d", edit_target_temper);
//     set_printer_data(0x08, strlen(buff), buff);
//     filament_actions_status(true);

//     timer_proccess = lv_timer_create(time_too_close, 1000 * 3, NULL);
//     lv_timer_set_repeat_count(timer_proccess, 1);
// }

// void FilaPageAddTemperBtnClicked(lv_event_t * e)
// {
//     if ( edit_target_temper >= HOTEND_MAX_EDIT_TEMPER )
//     {
//         create_msgbox(FilamentTempTips1[get_cur_language_index()], NULL, 2000, lv_scr_act());
//         return ;
//     }

//     edit_target_temper += FILAMENT_ACTION_INCREASE_TEMPER;
//     char buf[10] = {0};
//     sprintf(buf, "%d", edit_target_temper);
//     lv_label_set_text(ui_LabelTemperScreenFilament, buf);
// }

// void FilaPageSubTemperBtnClicked(lv_event_t * e)
// {
//     if ( edit_target_temper <= FILAMENT_COOL_EXTRUDE_TEMPER )
//     {
//         create_msgbox(FilamentTempTips2[get_cur_language_index()], NULL, 2000, lv_scr_act());

//         return ;
//     }

//     edit_target_temper -= FILAMENT_ACTION_INCREASE_TEMPER;
//     char buf[10] = {0};
//     sprintf(buf, "%d", edit_target_temper);
//     lv_label_set_text(ui_LabelTemperScreenFilament, buf);
// }

// void FilaPageTemperPanelClicked(lv_event_t * e)
// {
//     char buff[300] = {0};
//     sprintf(buff, "%s #42BDD8 %d-%d#", HotendInputRangle[get_cur_language_index()], FILAMENT_COOL_EXTRUDE_TEMPER, HOTEND_MAX_EDIT_TEMPER);
//     numberskeyboardinput(buff, HOTEND_MAX_EDIT_TEMPER, FILAMENT_COOL_EXTRUDE_TEMPER,
//                     fila_hotend_edit_target_temper_callback, key_reminder_callback, 320, 0);
// }

// void fila_hotend_edit_target_temper_callback(void *param)
// {
//     char *number_buff = (char*)param;
//     if ( number_buff )
//     {
//         char *ch = strchr(number_buff, '.');
//         if ( ch )
//             *ch = '\0';

//         edit_target_temper = atoi(number_buff);
//         lv_label_set_text(ui_LabelTemperScreenFilament, number_buff);
//     }
// }

// /*********************ui init*****************************/

// void ui_ScreenFilament_screen_init(void)
// {
//     ui_ScreenFilament = lv_obj_create(NULL);
//     lv_obj_clear_flag(ui_ScreenFilament, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

//     /*********************************/
//     ui_PanelPageScreenFila= lv_obj_create(ui_ScreenFilament);
//     lv_obj_set_width(ui_PanelPageScreenFila, 80);
//     lv_obj_set_height(ui_PanelPageScreenFila, 480);
//     lv_obj_clear_flag(ui_PanelPageScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_border_side(ui_PanelPageScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_ButtonHomeScreenFila = lv_btn_create(ui_PanelPageScreenFila);
//     lv_obj_set_width(ui_ButtonHomeScreenFila, 80);
//     lv_obj_set_height(ui_ButtonHomeScreenFila, 96);
//     lv_obj_set_x(ui_ButtonHomeScreenFila, -22);
//     lv_obj_set_y(ui_ButtonHomeScreenFila, -22);
//     lv_obj_add_flag(ui_ButtonHomeScreenFila, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     lv_obj_clear_flag(ui_ButtonHomeScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_bg_img_src(ui_ButtonHomeScreenFila, &ui_img_pagehome_png, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_ButtonHomeScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_color(ui_ButtonHomeScreenFila, lv_color_hex(0x42BDD8),
//                                   LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_opa(ui_ButtonHomeScreenFila, 255, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_width(ui_ButtonHomeScreenFila, 2, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_side(ui_ButtonHomeScreenFila, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

//     ui_ImageFilaPage = lv_img_create(ui_PanelPageScreenFila);
//     lv_img_set_src(ui_ImageFilaPage, &ui_img_pagemoveselected_png);
//     lv_obj_set_width(ui_ImageFilaPage, 80);
//     lv_obj_set_height(ui_ImageFilaPage, LV_SIZE_CONTENT);    /// 92
//     lv_obj_set_x(ui_ImageFilaPage, -22);
//     lv_obj_set_y(ui_ImageFilaPage, 74);
//     lv_obj_add_flag(ui_ImageFilaPage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
//     lv_obj_clear_flag(ui_ImageFilaPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

//     ui_ButtonFileManageScreenFila= lv_btn_create(ui_PanelPageScreenFila);
//     lv_obj_set_width(ui_ButtonFileManageScreenFila, 80);
//     lv_obj_set_height(ui_ButtonFileManageScreenFila, 96);
//     lv_obj_set_x(ui_ButtonFileManageScreenFila, -22);
//     lv_obj_set_y(ui_ButtonFileManageScreenFila, 170);
//     lv_obj_add_flag(ui_ButtonFileManageScreenFila, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     lv_obj_clear_flag(ui_ButtonFileManageScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_bg_img_src(ui_ButtonFileManageScreenFila, &ui_img_pagefilemanage_png,
//                                 LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_ButtonFileManageScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_color(ui_ButtonFileManageScreenFila, lv_color_hex(0x42BDD8),
//                                   LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_opa(ui_ButtonFileManageScreenFila, 255,
//                                 LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_width(ui_ButtonFileManageScreenFila, 2,
//                                   LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_side(ui_ButtonFileManageScreenFila, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

//     ui_ButtonSettingsScreenFila = lv_btn_create(ui_PanelPageScreenFila);
//     lv_obj_set_width(ui_ButtonSettingsScreenFila, 80);
//     lv_obj_set_height(ui_ButtonSettingsScreenFila, 96);
//     lv_obj_set_x(ui_ButtonSettingsScreenFila, -22);
//     lv_obj_set_y(ui_ButtonSettingsScreenFila, 266);
//     lv_obj_add_flag(ui_ButtonSettingsScreenFila, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     lv_obj_clear_flag(ui_ButtonSettingsScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_bg_img_src(ui_ButtonSettingsScreenFila, &ui_img_pagesetting_png,
//                                 LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_color(ui_ButtonSettingsScreenFila, lv_color_hex(0x42BDD8),
//                                   LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_opa(ui_ButtonSettingsScreenFila, 255, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_width(ui_ButtonSettingsScreenFila, 2, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_side(ui_ButtonSettingsScreenFila, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

//     ui_ButtonReserveScreenFila = lv_btn_create(ui_PanelPageScreenFila);
//     lv_obj_set_width(ui_ButtonReserveScreenFila, 80);
//     lv_obj_set_height(ui_ButtonReserveScreenFila, 96);
//     lv_obj_set_x(ui_ButtonReserveScreenFila, -22);
//     lv_obj_set_y(ui_ButtonReserveScreenFila, 362);
//     lv_obj_add_flag(ui_ButtonReserveScreenFila, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     lv_obj_clear_flag(ui_ButtonReserveScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_bg_img_src(ui_ButtonReserveScreenFila, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_color(ui_ButtonReserveScreenFila, lv_color_hex(0x42BDD8),
//                                   LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_opa(ui_ButtonReserveScreenFila, 255, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_width(ui_ButtonReserveScreenFila, 2, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_side(ui_ButtonReserveScreenFila, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

//     ui_PanelTitleScreenFila = lv_obj_create(ui_ScreenFilament);
//     lv_obj_set_width(ui_PanelTitleScreenFila, 720);
//     lv_obj_set_height(ui_PanelTitleScreenFila, 50);
//     lv_obj_set_x(ui_PanelTitleScreenFila, 80);
//     lv_obj_set_y(ui_PanelTitleScreenFila, 0);
//     lv_obj_clear_flag(ui_PanelTitleScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelTitleScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelTitleScreenFila, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelTitleScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelTitleScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_all(ui_PanelTitleScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_flex_flow(ui_PanelTitleScreenFila, LV_FLEX_FLOW_ROW);
//     lv_obj_set_flex_align(ui_PanelTitleScreenFila, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_END);

//     ui_PanelMoveScreenFila = lv_obj_create(ui_PanelTitleScreenFila);
//     lv_obj_set_width(ui_PanelMoveScreenFila, 240);
//     lv_obj_set_height(ui_PanelMoveScreenFila, 46);
//     lv_obj_clear_flag(ui_PanelMoveScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_border_side(ui_PanelMoveScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_radius(ui_PanelMoveScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelMoveScreenFila, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelMoveScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_add_flag(ui_PanelMoveScreenFila, LV_OBJ_FLAG_CLICKABLE);      /// Flags
//     lv_obj_set_style_border_side(ui_PanelMoveScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelMoveScreenFila, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_color(ui_PanelMoveScreenFila, lv_color_hex(0x42BDD8),
//                                   LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_opa(ui_PanelMoveScreenFila, 255, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_width(ui_PanelMoveScreenFila, 2, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_shadow_width(ui_PanelMoveScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_spread(ui_PanelMoveScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_LabelMoveScreenFila = lv_label_create(ui_PanelMoveScreenFila);
//     lv_obj_set_width(ui_LabelMoveScreenFila, 240);
//     lv_obj_set_height(ui_LabelMoveScreenFila, LV_SIZE_CONTENT);
//     lv_obj_set_align(ui_LabelMoveScreenFila, LV_ALIGN_CENTER);
//     //lv_label_set_long_mode(ui_LabelMoveAndTemperTitle, LV_LABEL_LONG_SCROLL_CIRCULAR);
//     lv_label_set_text(ui_LabelMoveScreenFila, MovePageTitle[get_cur_language_index()]);
//     //lv_label_set_recolor(ui_LabelMoveAndTemperTitle, "true");
//     lv_obj_set_style_text_color(ui_LabelMoveScreenFila, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelMoveScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_align(ui_LabelMoveScreenFila, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelMoveScreenFila, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_PanelFilamentScreenFila = lv_obj_create(ui_PanelTitleScreenFila);
//     lv_obj_set_width(ui_PanelFilamentScreenFila, 200);
//     lv_obj_set_height(ui_PanelFilamentScreenFila, 46);
//     lv_obj_clear_flag(ui_PanelFilamentScreenFila, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelFilamentScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelFilamentScreenFila, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelFilamentScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelFilamentScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_LabelFilamentScreenFila  = lv_label_create(ui_PanelFilamentScreenFila);
//     lv_obj_set_width(ui_LabelFilamentScreenFila, 200);
//     lv_obj_set_height(ui_LabelFilamentScreenFila, LV_SIZE_CONTENT);
//     lv_obj_set_align(ui_LabelFilamentScreenFila, LV_ALIGN_CENTER);
//     lv_label_set_long_mode(ui_LabelFilamentScreenFila, LV_LABEL_LONG_SCROLL_CIRCULAR);
//     lv_label_set_text(ui_LabelFilamentScreenFila, Extrude_Retract[get_cur_language_index()]);   //进退料
//     //lv_label_set_recolor(ui_LabelFilament, "true");
//     //lv_obj_set_style_text_color(ui_LabelFilamentScreenFila, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_color(ui_LabelFilamentScreenFila, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelFilamentScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_align(ui_LabelFilamentScreenFila, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelFilamentScreenFila, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
//     ui_PanelCoolScreenFila = lv_obj_create(ui_PanelTitleScreenFila);
//     lv_obj_set_width(ui_PanelCoolScreenFila, 100);
//     lv_obj_set_height(ui_PanelCoolScreenFila, 46);
//     lv_obj_clear_flag(ui_PanelCoolScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_add_flag(ui_PanelCoolScreenFila, LV_OBJ_FLAG_CLICKABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelCoolScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelCoolScreenFila, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelCoolScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelCoolScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelCoolScreenFila, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_color(ui_PanelCoolScreenFila, lv_color_hex(0x42BDD8),
//                                   LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_opa(ui_PanelCoolScreenFila, 255, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_width(ui_PanelCoolScreenFila, 2, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_shadow_width(ui_PanelCoolScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_spread(ui_PanelCoolScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_LabelCoolScreenFila= lv_label_create(ui_PanelCoolScreenFila);
//     lv_obj_set_width(ui_LabelCoolScreenFila, 100);
//     lv_obj_set_height(ui_LabelCoolScreenFila, LV_SIZE_CONTENT);
//     lv_obj_set_align(ui_LabelCoolScreenFila, LV_ALIGN_CENTER);
//     lv_label_set_long_mode(ui_LabelCoolScreenFila, LV_LABEL_LONG_SCROLL_CIRCULAR);
//     lv_label_set_text(ui_LabelCoolScreenFila, Cooling[get_cur_language_index()]);     //冷却
//     lv_obj_set_style_text_color(ui_LabelCoolScreenFila, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelCoolScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_align(ui_LabelCoolScreenFila, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelCoolScreenFila, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
//     ui_PanelAdjustmentScreenFila = lv_obj_create(ui_PanelTitleScreenFila);
//     lv_obj_set_width(ui_PanelAdjustmentScreenFila, 152);
//     lv_obj_set_height(ui_PanelAdjustmentScreenFila, 46);
//     lv_obj_set_x(ui_PanelAdjustmentScreenFila, 546);
//     lv_obj_set_y(ui_PanelAdjustmentScreenFila, -18);
//     lv_obj_clear_flag(ui_PanelAdjustmentScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_add_flag(ui_PanelAdjustmentScreenFila, LV_OBJ_FLAG_CLICKABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelAdjustmentScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelAdjustmentScreenFila, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelAdjustmentScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelAdjustmentScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelAdjustmentScreenFila, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_color(ui_PanelAdjustmentScreenFila, lv_color_hex(0x42BDD8),
//                                   LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_opa(ui_PanelAdjustmentScreenFila, 255, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_border_width(ui_PanelAdjustmentScreenFila, 2, LV_PART_MAIN | LV_STATE_PRESSED);
//     lv_obj_set_style_shadow_width(ui_PanelAdjustmentScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_spread(ui_PanelAdjustmentScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_add_flag(ui_PanelAdjustmentScreenFila, LV_OBJ_FLAG_HIDDEN);      /// Flags

//     ui_LabelAdjustmentScreenFila = lv_label_create(ui_PanelAdjustmentScreenFila);
//     lv_obj_set_width(ui_LabelAdjustmentScreenFila, 152);
//     lv_obj_set_height(ui_LabelAdjustmentScreenFila, LV_SIZE_CONTENT);
//     lv_obj_set_align(ui_LabelAdjustmentScreenFila, LV_ALIGN_CENTER);
//     lv_label_set_long_mode(ui_LabelAdjustmentScreenFila, LV_LABEL_LONG_SCROLL_CIRCULAR);
//     lv_label_set_text(ui_LabelAdjustmentScreenFila, Adjustment[get_cur_language_index()]);  //调整
//     //lv_label_set_recolor(ui_LabelAdjustment, "true");
//     lv_obj_set_style_text_color(ui_LabelAdjustmentScreenFila, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelAdjustmentScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_align(ui_LabelAdjustmentScreenFila, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelAdjustmentScreenFila, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    
//     /*****************filament center*************************/
//     ui_PanelCenterScreenFila = lv_obj_create(ui_ScreenFilament);
//     lv_obj_set_width(ui_PanelCenterScreenFila, 720);
//     lv_obj_set_height(ui_PanelCenterScreenFila, 430);
//     lv_obj_set_x(ui_PanelCenterScreenFila, 80);
//     lv_obj_set_y(ui_PanelCenterScreenFila, 50);
//     lv_obj_clear_flag(ui_PanelCenterScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelCenterScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelCenterScreenFila, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelCenterScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelCenterScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

//     /**--------------------------------action pan------------------------***/
//     ui_PanelActionScreenFila = lv_obj_create(ui_PanelCenterScreenFila);
//     lv_obj_set_width(ui_PanelActionScreenFila, 424);
//     lv_obj_set_height(ui_PanelActionScreenFila, 406);
//     lv_obj_set_x(ui_PanelActionScreenFila, -9);
//     lv_obj_set_y(ui_PanelActionScreenFila, -12);
//     lv_obj_clear_flag(ui_PanelActionScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelActionScreenFila, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelActionScreenFila, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelActionScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelActionScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);


//     /************************hotend temper edit panel******************************/
//     ui_PanelTempScreenFilament = lv_obj_create(ui_PanelActionScreenFila);
//     lv_obj_set_width(ui_PanelTempScreenFilament, 424);
//     lv_obj_set_height(ui_PanelTempScreenFilament, 110);
//     lv_obj_set_x(ui_PanelTempScreenFilament, -22);
//     lv_obj_set_y(ui_PanelTempScreenFilament, 54);
//     lv_obj_clear_flag(ui_PanelTempScreenFilament, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelTempScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelTempScreenFilament, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelTempScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelTempScreenFilament, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_LabelTitleScreenFilament = lv_label_create(ui_PanelTempScreenFilament);
//     lv_obj_set_width(ui_LabelTitleScreenFilament, LV_SIZE_CONTENT);
//     lv_obj_set_height(ui_LabelTitleScreenFilament, 30);
//     lv_obj_align(ui_LabelTitleScreenFilament, LV_ALIGN_TOP_MID, 0, -5);
//     lv_label_set_text(ui_LabelTitleScreenFilament, HotendTemp[get_cur_language_index()]);
//     lv_obj_set_style_text_color(ui_LabelTitleScreenFilament, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelTitleScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_align(ui_LabelTitleScreenFilament, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelTitleScreenFilament, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_ButtonSubTemperScreenFilament = lv_btn_create(ui_PanelTempScreenFilament);
//     lv_obj_set_width(ui_ButtonSubTemperScreenFilament, 52);
//     lv_obj_set_height(ui_ButtonSubTemperScreenFilament, 52);
//     lv_obj_set_x(ui_ButtonSubTemperScreenFilament, 38);
//     lv_obj_set_y(ui_ButtonSubTemperScreenFilament, 33);
//     lv_obj_add_flag(ui_ButtonSubTemperScreenFilament, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     lv_obj_clear_flag(ui_ButtonSubTemperScreenFilament, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_ButtonSubTemperScreenFilament, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_img_src(ui_ButtonSubTemperScreenFilament, &ui_img_sub_png, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_width(ui_ButtonSubTemperScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_spread(ui_ButtonSubTemperScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_ButtonAddTemperScreenFilament = lv_btn_create(ui_PanelTempScreenFilament);
//     lv_obj_set_width(ui_ButtonAddTemperScreenFilament, 52);
//     lv_obj_set_height(ui_ButtonAddTemperScreenFilament, 52);
//     lv_obj_set_x(ui_ButtonAddTemperScreenFilament, 290);
//     lv_obj_set_y(ui_ButtonAddTemperScreenFilament, 33);
//     lv_obj_add_flag(ui_ButtonAddTemperScreenFilament, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     lv_obj_clear_flag(ui_ButtonAddTemperScreenFilament, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_ButtonAddTemperScreenFilament, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_img_src(ui_ButtonAddTemperScreenFilament, &ui_img_add_png, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_width(ui_ButtonAddTemperScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_spread(ui_ButtonAddTemperScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_PanelTemperValueScreenFilament = lv_obj_create(ui_PanelTempScreenFilament);
//     lv_obj_set_width(ui_PanelTemperValueScreenFilament, 146);
//     lv_obj_set_height(ui_PanelTemperValueScreenFilament, 54);
//     lv_obj_set_x(ui_PanelTemperValueScreenFilament, 117);
//     lv_obj_set_y(ui_PanelTemperValueScreenFilament, 32);
//     lv_obj_clear_flag(ui_PanelTemperValueScreenFilament, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelTemperValueScreenFilament, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelTemperValueScreenFilament, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelTemperValueScreenFilament, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_color(ui_PanelTemperValueScreenFilament, lv_color_hex(0x5E6166),
//                                   LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_opa(ui_PanelTemperValueScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_width(ui_PanelTemperValueScreenFilament, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_LabelTemperScreenFilament = lv_label_create(ui_PanelTemperValueScreenFilament);
//     lv_obj_set_width(ui_LabelTemperScreenFilament, 62);
//     lv_obj_set_height(ui_LabelTemperScreenFilament, 30);
//     lv_obj_set_x(ui_LabelTemperScreenFilament, 12);
//     lv_obj_set_y(ui_LabelTemperScreenFilament, -9);
//     char buf[10] = {0};
//     sprintf(buf, "%d", edit_target_temper);
//     lv_label_set_text(ui_LabelTemperScreenFilament, buf);
//     lv_obj_set_style_text_color(ui_LabelTemperScreenFilament, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelTemperScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_align(ui_LabelTemperScreenFilament, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelTemperScreenFilament, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_LabelTemperUnitScreenFilament = lv_label_create(ui_PanelTemperValueScreenFilament);
//     lv_obj_set_width(ui_LabelTemperUnitScreenFilament, 26);
//     lv_obj_set_height(ui_LabelTemperUnitScreenFilament, 22);
//     lv_obj_set_x(ui_LabelTemperUnitScreenFilament, 76);
//     lv_obj_set_y(ui_LabelTemperUnitScreenFilament, -3);
//     lv_label_set_text(ui_LabelTemperUnitScreenFilament, "°C");
//     lv_obj_set_style_text_color(ui_LabelTemperUnitScreenFilament, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelTemperUnitScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelTemperUnitScreenFilament, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);


//     /**********************hotend heating panel************************************/
//     ui_PanelhotendHeatScreenFilament = lv_obj_create(ui_PanelActionScreenFila);
//     lv_obj_set_width(ui_PanelhotendHeatScreenFilament, 424);
//     lv_obj_set_height(ui_PanelhotendHeatScreenFilament, 115);
//     lv_obj_set_x(ui_PanelhotendHeatScreenFilament, -22);
//     lv_obj_set_y(ui_PanelhotendHeatScreenFilament, 72);
//     lv_obj_clear_flag(ui_PanelhotendHeatScreenFilament, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelhotendHeatScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelhotendHeatScreenFilament, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelhotendHeatScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelhotendHeatScreenFilament, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_ImageHotendHeating = lv_img_create(ui_PanelhotendHeatScreenFilament);
//     lv_img_set_src(ui_ImageHotendHeating, &ui_img_filament_hotend_heat_png);
//     lv_obj_set_width(ui_ImageHotendHeating, 74);
//     lv_obj_set_height(ui_ImageHotendHeating, 75);
//     lv_obj_set_x(ui_ImageHotendHeating, 153);
//     lv_obj_set_y(ui_ImageHotendHeating, -22);
//     lv_obj_add_flag(ui_ImageHotendHeating, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
//     lv_obj_clear_flag(ui_ImageHotendHeating, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

//     ui_LabelRealTemper = lv_label_create(ui_PanelhotendHeatScreenFilament);
//     lv_obj_set_width(ui_LabelRealTemper, 80);
//     lv_obj_set_height(ui_LabelRealTemper, 30);
//     lv_obj_set_x(ui_LabelRealTemper, 91);
//     lv_obj_set_y(ui_LabelRealTemper, 59);
//     lv_label_set_text(ui_LabelRealTemper, "240°C");
//     lv_obj_set_style_text_color(ui_LabelRealTemper, lv_color_hex(0xFA6D31), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelRealTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_align(ui_LabelRealTemper, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelRealTemper, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_LabelTargetTemper = lv_label_create(ui_PanelhotendHeatScreenFilament);
//     lv_obj_set_width(ui_LabelTargetTemper, 80);
//     lv_obj_set_height(ui_LabelTargetTemper, 30);
//     lv_obj_set_x(ui_LabelTargetTemper, 210);
//     lv_obj_set_y(ui_LabelTargetTemper, 59);
//     lv_label_set_text(ui_LabelTargetTemper, "240°C");
//     lv_obj_set_style_text_color(ui_LabelTargetTemper, lv_color_hex(0xFA6D31), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelTargetTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_align(ui_LabelTargetTemper, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelTargetTemper, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_ImageTemperTo = lv_img_create(ui_PanelhotendHeatScreenFilament);
//     lv_img_set_src(ui_ImageTemperTo, &ui_img_filament_to_png);
//     lv_obj_set_width(ui_ImageTemperTo, LV_SIZE_CONTENT);   /// 1
//     lv_obj_set_height(ui_ImageTemperTo, LV_SIZE_CONTENT);    /// 1
//     lv_obj_set_x(ui_ImageTemperTo, 0);
//     lv_obj_set_y(ui_ImageTemperTo, 38);
//     lv_obj_set_align(ui_ImageTemperTo, LV_ALIGN_CENTER);
//     lv_obj_add_flag(ui_ImageTemperTo, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
//     lv_obj_clear_flag(ui_ImageTemperTo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

//     /*****************hotend normal panel*************************/
//     ui_PanelhotendNormalScreenFila = lv_obj_create(ui_PanelActionScreenFila);
//     lv_obj_set_width(ui_PanelhotendNormalScreenFila, 424);
//     lv_obj_set_height(ui_PanelhotendNormalScreenFila, 115);
//     lv_obj_set_x(ui_PanelhotendNormalScreenFila, -22);
//     lv_obj_set_y(ui_PanelhotendNormalScreenFila, 72);
//     lv_obj_clear_flag(ui_PanelhotendNormalScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelhotendNormalScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelhotendNormalScreenFila, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelhotendNormalScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelhotendNormalScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_ImageHotendNormal = lv_img_create(ui_PanelhotendNormalScreenFila);
//     lv_img_set_src(ui_ImageHotendNormal, &ui_img_filament_hotend_normal_png);
//     lv_obj_set_width(ui_ImageHotendNormal, 74);
//     lv_obj_set_height(ui_ImageHotendNormal, 75);
//     lv_obj_set_x(ui_ImageHotendNormal, 153);
//     lv_obj_set_y(ui_ImageHotendNormal, -22);
//     lv_obj_add_flag(ui_ImageHotendNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
//     lv_obj_clear_flag(ui_ImageHotendNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

//     ui_LabelNormalRealTemper = lv_label_create(ui_PanelhotendNormalScreenFila);
//     lv_obj_set_width(ui_LabelNormalRealTemper, 80);
//     lv_obj_set_height(ui_LabelNormalRealTemper, 30);
//     lv_obj_set_x(ui_LabelNormalRealTemper, 150);
//     lv_obj_set_y(ui_LabelNormalRealTemper, 60);
//     lv_label_set_text(ui_LabelNormalRealTemper, "240°C");
//     lv_obj_set_style_text_color(ui_LabelNormalRealTemper, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelNormalRealTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_align(ui_LabelNormalRealTemper, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelNormalRealTemper, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     /***************************filament action panel******************************/
//     ui_PanelInAndOutAction = lv_obj_create(ui_PanelActionScreenFila);
//     lv_obj_set_width(ui_PanelInAndOutAction, 424);
//     lv_obj_set_height(ui_PanelInAndOutAction, 64);
//     lv_obj_set_x(ui_PanelInAndOutAction, -22);
//     lv_obj_set_y(ui_PanelInAndOutAction, 299);
//     lv_obj_clear_flag(ui_PanelInAndOutAction, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelInAndOutAction, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelInAndOutAction, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelInAndOutAction, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelInAndOutAction, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_ButtonInFilaScreenFilament = lv_btn_create(ui_PanelInAndOutAction);
//     lv_obj_set_width(ui_ButtonInFilaScreenFilament, 116);
//     lv_obj_set_height(ui_ButtonInFilaScreenFilament, 60);
//     lv_obj_set_x(ui_ButtonInFilaScreenFilament, 38);
//     lv_obj_set_y(ui_ButtonInFilaScreenFilament, -20);
//     lv_obj_add_flag(ui_ButtonInFilaScreenFilament, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     lv_obj_clear_flag(ui_ButtonInFilaScreenFilament, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_ButtonInFilaScreenFilament, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_ButtonInFilaScreenFilament, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_ButtonInFilaScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_width(ui_ButtonInFilaScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_spread(ui_ButtonInFilaScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     //lv_obj_set_style_bg_color(ui_ButtonInFilaScreenFilament, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DISABLED);
//     lv_obj_set_style_bg_opa(ui_ButtonInFilaScreenFilament, 178, LV_STATE_DISABLED);

//     ui_LabelInFilaScreenFilament = lv_label_create(ui_ButtonInFilaScreenFilament);
//     lv_obj_set_width(ui_LabelInFilaScreenFilament, 116);
//     lv_obj_set_height(ui_LabelInFilaScreenFilament, 30);
//     lv_obj_set_align(ui_LabelInFilaScreenFilament, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_LabelInFilaScreenFilament, "进料");
//     lv_obj_set_style_text_align(ui_LabelInFilaScreenFilament, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelInFilaScreenFilament, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_color(ui_LabelInFilaScreenFilament, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelInFilaScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelInFilaScreenFilament, 178, LV_PART_MAIN | LV_STATE_DISABLED);

//     ui_ButtonOutFilaScreenFilament = lv_btn_create(ui_PanelInAndOutAction);
//     lv_obj_set_width(ui_ButtonOutFilaScreenFilament, 116);
//     lv_obj_set_height(ui_ButtonOutFilaScreenFilament, 60);
//     lv_obj_set_x(ui_ButtonOutFilaScreenFilament, 226);
//     lv_obj_set_y(ui_ButtonOutFilaScreenFilament, -20);
//     lv_obj_add_flag(ui_ButtonOutFilaScreenFilament, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     lv_obj_clear_flag(ui_ButtonOutFilaScreenFilament, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_ButtonOutFilaScreenFilament, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_ButtonOutFilaScreenFilament, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_ButtonOutFilaScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_width(ui_ButtonOutFilaScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_spread(ui_ButtonOutFilaScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_ButtonOutFilaScreenFilament, 178, LV_PART_MAIN | LV_STATE_DISABLED);

//     ui_LabelOutFilaScreenFilament = lv_label_create(ui_ButtonOutFilaScreenFilament);
//     lv_obj_set_width(ui_LabelOutFilaScreenFilament, 116);
//     lv_obj_set_height(ui_LabelOutFilaScreenFilament, 30);
//     lv_obj_set_align(ui_LabelOutFilaScreenFilament, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_LabelOutFilaScreenFilament, "退料");
//     lv_obj_set_style_text_align(ui_LabelOutFilaScreenFilament, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelOutFilaScreenFilament, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelOutFilaScreenFilament, 178, LV_PART_MAIN | LV_STATE_DISABLED);

//     /**--------------------------------action pan------------------------***/


//     /***++++++++++++++++++++++++++++Prompt panel+++++++++++++++++++++++++++++*****/
//     ui_PanelPromptScreenFila = lv_obj_create(ui_PanelCenterScreenFila);
//     lv_obj_set_width(ui_PanelPromptScreenFila, 266);
//     lv_obj_set_height(ui_PanelPromptScreenFila, 406);
//     lv_obj_set_x(ui_PanelPromptScreenFila, 424);
//     lv_obj_set_y(ui_PanelPromptScreenFila, -12);
//     lv_obj_clear_flag(ui_PanelPromptScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelPromptScreenFila, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelPromptScreenFila, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelPromptScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelPromptScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_pad_all(ui_PanelPromptScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_Panel6ScreenFilament = lv_obj_create(ui_PanelPromptScreenFila);
//     lv_obj_set_width(ui_Panel6ScreenFilament, 256);
//     lv_obj_set_height(ui_Panel6ScreenFilament, 1);
//     lv_obj_align(ui_Panel6ScreenFilament, LV_ALIGN_TOP_MID, 0, 60);
//     lv_obj_clear_flag(ui_Panel6ScreenFilament, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_Panel6ScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_Panel6ScreenFilament, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_Panel6ScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_color(ui_Panel6ScreenFilament, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_opa(ui_Panel6ScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_width(ui_Panel6ScreenFilament, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

//     /*****************************tips infor********************************************/
//     ui_LabelTitleTips = lv_label_create(ui_PanelPromptScreenFila);
//     lv_obj_set_width(ui_LabelTitleTips, 240);
//     lv_obj_set_height(ui_LabelTitleTips, 30);
//     lv_obj_align(ui_LabelTitleTips, LV_ALIGN_TOP_MID, 0, 12);
//     lv_label_set_text(ui_LabelTitleTips, "提示");
//     lv_obj_set_style_text_color(ui_LabelTitleTips, lv_color_hex(0x40BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelTitleTips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_align(ui_LabelTitleTips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelTitleTips, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_LabelTipsContentScreenFila = lv_label_create(ui_PanelPromptScreenFila);
//     lv_obj_set_width(ui_LabelTipsContentScreenFila, 229);
//     lv_obj_set_height(ui_LabelTipsContentScreenFila, 300);
//     lv_obj_align(ui_LabelTipsContentScreenFila, LV_ALIGN_TOP_MID, 0, 79);
//     lv_label_set_text(ui_LabelTipsContentScreenFila, "进退料前温度将自动加热");
//     lv_obj_set_style_text_color(ui_LabelTipsContentScreenFila, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelTipsContentScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelTipsContentScreenFila, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);


//     /**************************in and out filament proccess*********************************/
//     ui_LabelTitleFilament = lv_label_create(ui_PanelPromptScreenFila);
//     lv_obj_set_width(ui_LabelTitleFilament, 240);
//     lv_obj_set_height(ui_LabelTitleFilament, 30);
//     lv_obj_align(ui_LabelTitleFilament, LV_ALIGN_TOP_MID, 0, 12);
//     lv_label_set_text(ui_LabelTitleFilament, "");
//     lv_obj_set_style_text_color(ui_LabelTitleFilament, lv_color_hex(0x40BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelTitleFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_align(ui_LabelTitleFilament, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelTitleFilament, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_PanelFilamentProccess = lv_obj_create(ui_PanelPromptScreenFila);
//     lv_obj_set_width(ui_PanelFilamentProccess, 266);
//     lv_obj_set_height(ui_PanelFilamentProccess, 330);
//     lv_obj_align(ui_PanelFilamentProccess, LV_ALIGN_TOP_MID, 0, 62);
//     lv_obj_clear_flag(ui_PanelFilamentProccess, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelFilamentProccess, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelFilamentProccess, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelFilamentProccess, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelFilamentProccess, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_BtnFirstStepScreenFila = lv_btn_create(ui_PanelFilamentProccess);
//     lv_obj_set_width(ui_BtnFirstStepScreenFila, 30);
//     lv_obj_set_height(ui_BtnFirstStepScreenFila, 30);
//     lv_obj_set_x(ui_BtnFirstStepScreenFila, -4);
//     lv_obj_set_y(ui_BtnFirstStepScreenFila, -1);
//     lv_obj_add_flag(ui_BtnFirstStepScreenFila, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     lv_obj_clear_flag(ui_BtnFirstStepScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_BtnFirstStepScreenFila, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_BtnFirstStepScreenFila, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_BtnFirstStepScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_width(ui_BtnFirstStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_spread(ui_BtnFirstStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_LabelFirstStepScreenFila = lv_label_create(ui_BtnFirstStepScreenFila);
//     lv_obj_set_width(ui_LabelFirstStepScreenFila, LV_SIZE_CONTENT);   /// 1
//     lv_obj_set_height(ui_LabelFirstStepScreenFila, LV_SIZE_CONTENT);    /// 1
//     lv_obj_set_align(ui_LabelFirstStepScreenFila, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_LabelFirstStepScreenFila, "1");
//     lv_obj_set_style_text_font(ui_LabelFirstStepScreenFila, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_LabelFilamentFirstStep = lv_label_create(ui_PanelFilamentProccess);
//     lv_obj_set_width(ui_LabelFilamentFirstStep, 200);
//     lv_obj_set_height(ui_LabelFilamentFirstStep, 50);
//     lv_obj_set_x(ui_LabelFilamentFirstStep, 34);
//     lv_obj_set_y(ui_LabelFilamentFirstStep, -1);
//     lv_label_set_text(ui_LabelFilamentFirstStep, "");
//     lv_obj_set_style_text_color(ui_LabelFilamentFirstStep, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelFilamentFirstStep, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelFilamentFirstStep, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_PanelFirstStepScreenFila = lv_obj_create(ui_PanelFilamentProccess);
//     lv_obj_set_width(ui_PanelFirstStepScreenFila, 3);
//     lv_obj_set_height(ui_PanelFirstStepScreenFila, 59);
//     lv_obj_set_x(ui_PanelFirstStepScreenFila, 10);
//     lv_obj_set_y(ui_PanelFirstStepScreenFila, 29);
//     lv_obj_clear_flag(ui_PanelFirstStepScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelFirstStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelFirstStepScreenFila, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelFirstStepScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_grad_color(ui_PanelFirstStepScreenFila, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_grad_dir(ui_PanelFirstStepScreenFila, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_width(ui_PanelFirstStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelFirstStepScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_BtnSecondStepScreenFila = lv_btn_create(ui_PanelFilamentProccess);
//     lv_obj_set_width(ui_BtnSecondStepScreenFila, 30);
//     lv_obj_set_height(ui_BtnSecondStepScreenFila, 30);
//     lv_obj_set_x(ui_BtnSecondStepScreenFila, -4);
//     lv_obj_set_y(ui_BtnSecondStepScreenFila, 88);
//     lv_obj_add_flag(ui_BtnSecondStepScreenFila, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     lv_obj_clear_flag(ui_BtnSecondStepScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_BtnSecondStepScreenFila, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_BtnSecondStepScreenFila, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_BtnSecondStepScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_width(ui_BtnSecondStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_spread(ui_BtnSecondStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_LabelSecondStepScreenFila = lv_label_create(ui_BtnSecondStepScreenFila);
//     lv_obj_set_width(ui_LabelSecondStepScreenFila, LV_SIZE_CONTENT);   /// 1
//     lv_obj_set_height(ui_LabelSecondStepScreenFila, LV_SIZE_CONTENT);    /// 1
//     lv_obj_set_align(ui_LabelSecondStepScreenFila, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_LabelSecondStepScreenFila, "2");
//     lv_obj_set_style_text_font(ui_LabelSecondStepScreenFila, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_LabelFilamentSecondStep = lv_label_create(ui_PanelFilamentProccess);
//     lv_obj_set_width(ui_LabelFilamentSecondStep, 200);
//     lv_obj_set_height(ui_LabelFilamentSecondStep, 30);
//     lv_obj_set_x(ui_LabelFilamentSecondStep, 34);
//     lv_obj_set_y(ui_LabelFilamentSecondStep, 88);
//     lv_label_set_text(ui_LabelFilamentSecondStep, "");
//     lv_obj_set_style_text_color(ui_LabelFilamentSecondStep, lv_color_hex(0x9A9DA0), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelFilamentSecondStep, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelFilamentSecondStep, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_PanelSecondStepScreenFila = lv_obj_create(ui_PanelFilamentProccess);
//     lv_obj_set_width(ui_PanelSecondStepScreenFila, 3);
//     lv_obj_set_height(ui_PanelSecondStepScreenFila, 59);
//     lv_obj_set_x(ui_PanelSecondStepScreenFila, 10);
//     lv_obj_set_y(ui_PanelSecondStepScreenFila, 118);
//     lv_obj_clear_flag(ui_PanelSecondStepScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelSecondStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelSecondStepScreenFila, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelSecondStepScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_grad_color(ui_PanelSecondStepScreenFila, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_grad_dir(ui_PanelSecondStepScreenFila, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_width(ui_PanelSecondStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelSecondStepScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_BtnThirdStepScreenFila = lv_btn_create(ui_PanelFilamentProccess);
//     lv_obj_set_width(ui_BtnThirdStepScreenFila, 30);
//     lv_obj_set_height(ui_BtnThirdStepScreenFila, 30);
//     lv_obj_set_x(ui_BtnThirdStepScreenFila, -4);
//     lv_obj_set_y(ui_BtnThirdStepScreenFila, 177);
//     lv_obj_add_flag(ui_BtnThirdStepScreenFila, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     lv_obj_clear_flag(ui_BtnThirdStepScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_BtnThirdStepScreenFila, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_BtnThirdStepScreenFila, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_BtnThirdStepScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_width(ui_BtnThirdStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_spread(ui_BtnThirdStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_LabelThirdStepScreenFila = lv_label_create(ui_BtnThirdStepScreenFila);
//     lv_obj_set_width(ui_LabelThirdStepScreenFila, LV_SIZE_CONTENT);   /// 1
//     lv_obj_set_height(ui_LabelThirdStepScreenFila, LV_SIZE_CONTENT);    /// 1
//     lv_obj_set_align(ui_LabelThirdStepScreenFila, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_LabelThirdStepScreenFila, "3");
//     lv_obj_set_style_text_font(ui_LabelThirdStepScreenFila, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_LabelFilamentThirdStep = lv_label_create(ui_PanelFilamentProccess);
//     lv_obj_set_width(ui_LabelFilamentThirdStep, 200);
//     lv_obj_set_height(ui_LabelFilamentThirdStep, 30);
//     lv_obj_set_x(ui_LabelFilamentThirdStep, 34);
//     lv_obj_set_y(ui_LabelFilamentThirdStep, 177);
//     lv_label_set_text(ui_LabelFilamentThirdStep, "");
//     lv_obj_set_style_text_color(ui_LabelFilamentThirdStep, lv_color_hex(0x9A9DA0), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelFilamentThirdStep, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelFilamentThirdStep, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_PanelThirdStepScreenFila = lv_obj_create(ui_PanelFilamentProccess);
//     lv_obj_set_width(ui_PanelThirdStepScreenFila, 3);
//     lv_obj_set_height(ui_PanelThirdStepScreenFila, 59);
//     lv_obj_set_x(ui_PanelThirdStepScreenFila, 10);
//     lv_obj_set_y(ui_PanelThirdStepScreenFila, 207);
//     lv_obj_clear_flag(ui_PanelThirdStepScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_PanelThirdStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_PanelThirdStepScreenFila, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_PanelThirdStepScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_grad_color(ui_PanelThirdStepScreenFila, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_grad_dir(ui_PanelThirdStepScreenFila, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_width(ui_PanelThirdStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_side(ui_PanelThirdStepScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_BtnFourthStepScreenFila = lv_btn_create(ui_PanelFilamentProccess);
//     lv_obj_set_width(ui_BtnFourthStepScreenFila, 30);
//     lv_obj_set_height(ui_BtnFourthStepScreenFila, 30);
//     lv_obj_set_x(ui_BtnFourthStepScreenFila, -4);
//     lv_obj_set_y(ui_BtnFourthStepScreenFila, 266);
//     lv_obj_add_flag(ui_BtnFourthStepScreenFila, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//     lv_obj_clear_flag(ui_BtnFourthStepScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//     lv_obj_set_style_radius(ui_BtnFourthStepScreenFila, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(ui_BtnFourthStepScreenFila, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(ui_BtnFourthStepScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_width(ui_BtnFourthStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_shadow_spread(ui_BtnFourthStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_LabelFourthStepScreenFila = lv_label_create(ui_BtnFourthStepScreenFila);
//     lv_obj_set_width(ui_LabelFourthStepScreenFila, LV_SIZE_CONTENT);   /// 1
//     lv_obj_set_height(ui_LabelFourthStepScreenFila, LV_SIZE_CONTENT);    /// 1
//     lv_obj_set_x(ui_LabelFourthStepScreenFila, -2);
//     lv_obj_set_y(ui_LabelFourthStepScreenFila, -1);
//     lv_obj_set_align(ui_LabelFourthStepScreenFila, LV_ALIGN_CENTER);
//     lv_label_set_text(ui_LabelFourthStepScreenFila, "4");
//     lv_obj_set_style_text_font(ui_LabelFourthStepScreenFila, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     ui_LabelFilamentFourthStep = lv_label_create(ui_PanelFilamentProccess);
//     lv_obj_set_width(ui_LabelFilamentFourthStep, 230);
//     lv_obj_set_height(ui_LabelFilamentFourthStep, 60);
//     lv_obj_set_x(ui_LabelFilamentFourthStep, 34);
//     lv_obj_set_y(ui_LabelFilamentFourthStep, 266);
//     lv_obj_set_style_text_letter_space(ui_LabelFilamentFourthStep, -2, LV_PART_MAIN | LV_STATE_DEFAULT);  //设置行间距
//     lv_label_set_text(ui_LabelFilamentFourthStep, "");
//     lv_obj_set_style_text_color(ui_LabelFilamentFourthStep, lv_color_hex(0x9A9DA0), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_opa(ui_LabelFilamentFourthStep, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_text_font(ui_LabelFilamentFourthStep, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

//     /***++++++++++++++++++++++++++++Prompt panel+++++++++++++++++++++++++++++*****/

//     lv_obj_add_event_cb(ui_ButtonHomeScreenFila, ui_event_ButtonHomeScreenFila, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_ButtonFileManageScreenFila, ui_event_ButtonFileManageScreenFila, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_ButtonSettingsScreenFila, ui_event_ButtonSettingsScreenFila, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_ButtonReserveScreenFila, ui_event_ButtonReserveScreenFila, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_PanelMoveScreenFila, ui_event_ButtonMoveScreenFila, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_PanelCoolScreenFila, ui_event_ButtonCoolScreenFila, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_PanelAdjustmentScreenFila, ui_event_ButtonAdjustScreenFila, LV_EVENT_ALL, NULL);

//     lv_obj_add_event_cb(ui_ButtonInFilaScreenFilament, ui_event_BtnInFilament, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_ButtonOutFilaScreenFilament, ui_event_BtnOutFilament, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_ButtonAddTemperScreenFilament, ui_event_BtnAddTargetTemper, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_ButtonSubTemperScreenFilament, ui_event_BtnSubTargetTemper, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_PanelTemperValueScreenFilament, ui_event_PanelTargetTemper, LV_EVENT_ALL, NULL);
//     lv_obj_add_event_cb(ui_ScreenFilament, ui_event_PageLoad, LV_EVENT_ALL, NULL);
//     /*****************init action*********************/
//     show_temper_panel(SHOW_TEMPER_EDIT_PANEL);
//     show_proccess_panel(false);
//     // lv_obj_add_state(ui_BtnFirstStepScreenFila, LV_STATE_DISABLED);       /// States
//     // lv_obj_add_state(ui_BtnSecondStepScreenFila, LV_STATE_DISABLED);       /// States
//     // lv_obj_add_state(ui_BtnThirdStepScreenFila, LV_STATE_DISABLED);       /// States
//     // lv_obj_add_state(ui_BtnFourthStepScreenFila, LV_STATE_DISABLED);       /// States

//     //timer_proccess = lv_timer_create(proccess_callback, 5 * 1000, NULL);
// }

// void LoadFilamentScreen(void)
// {
//     lv_disp_load_scr(ui_ScreenFilament);
//     // show_proccess_panel(false);
// }

// void show_temper_panel(enum SHOW_TEMPER_PANEL panel)
// {
//     lv_obj_add_flag(ui_PanelhotendHeatScreenFilament, LV_OBJ_FLAG_HIDDEN);
//     lv_obj_add_flag(ui_PanelhotendNormalScreenFila, LV_OBJ_FLAG_HIDDEN);
//     lv_obj_add_flag(ui_PanelTempScreenFilament, LV_OBJ_FLAG_HIDDEN);
    
//     switch (panel)
//     {
//     case SHOW_NORMAL_PANEL:
//         {
//             lv_obj_clear_flag(ui_PanelhotendNormalScreenFila, LV_OBJ_FLAG_HIDDEN);
//         }
//         break;
//     case SHOW_HEATING_PANEL:
//         {
//             lv_obj_clear_flag(ui_PanelhotendHeatScreenFilament, LV_OBJ_FLAG_HIDDEN);
//         }
//         break;  
//     default:
//         {
//             lv_obj_clear_flag(ui_PanelTempScreenFilament, LV_OBJ_FLAG_HIDDEN);
//         }
//         break;
//     }
// }

// void show_proccess_panel(bool show_proccess)
// {
//     lv_obj_add_flag(ui_LabelTitleTips, LV_OBJ_FLAG_HIDDEN);
//     lv_obj_add_flag(ui_LabelTipsContentScreenFila, LV_OBJ_FLAG_HIDDEN);
//     lv_obj_add_flag(ui_LabelTitleFilament, LV_OBJ_FLAG_HIDDEN);
//     lv_obj_add_flag(ui_PanelFilamentProccess, LV_OBJ_FLAG_HIDDEN);

//     if ( show_proccess )
//     {
//         lv_obj_clear_flag(ui_LabelTitleFilament, LV_OBJ_FLAG_HIDDEN);
//         lv_obj_clear_flag(ui_PanelFilamentProccess, LV_OBJ_FLAG_HIDDEN);
//     }
//     else
//     {
//         lv_obj_clear_flag(ui_LabelTitleTips, LV_OBJ_FLAG_HIDDEN);
//         lv_obj_clear_flag(ui_LabelTipsContentScreenFila, LV_OBJ_FLAG_HIDDEN);
//     }
// }

// void show_in_filament_proccess(enum IN_FILA_PROCCESS in_step)
// {
//     show_proccess_panel(true);
//     show_filament_proccess_steps(true);
//     switch (in_step)
//     {
//     case IN_FILAMENT_FIRST_STEP:
//         {
//             show_step_btn_state(ui_BtnFirstStepScreenFila, true);
//             show_step_btn_state(ui_BtnSecondStepScreenFila, false);
//             show_step_btn_state(ui_BtnThirdStepScreenFila, false);
//             show_step_label_state(ui_LabelFilamentFirstStep, true);
//             show_step_label_state(ui_LabelFilamentSecondStep, false);
//             show_step_label_state(ui_LabelFilamentThirdStep, false);
//             show_step_dir_panel_state(ui_PanelFirstStepScreenFila, STEP_PROCCESSING);
//             show_step_dir_panel_state(ui_PanelSecondStepScreenFila, STEP_NOT_START);
//             show_temper_panel(SHOW_HEATING_PANEL);
//             filament_actions_status(true);
//         }
//         break;
//     case IN_FILAMENT_SECOND_STEP:
//         {
//             show_step_btn_state(ui_BtnFirstStepScreenFila, true);
//             show_step_btn_state(ui_BtnSecondStepScreenFila, true);
//             show_step_btn_state(ui_BtnThirdStepScreenFila, false);
//             show_step_label_state(ui_LabelFilamentFirstStep, true);
//             show_step_label_state(ui_LabelFilamentSecondStep, true);
//             show_step_label_state(ui_LabelFilamentThirdStep, false);
//             show_step_dir_panel_state(ui_PanelFirstStepScreenFila, STEP_FINISHED);
//             show_step_dir_panel_state(ui_PanelSecondStepScreenFila, STEP_PROCCESSING);
//             show_temper_panel(SHOW_NORMAL_PANEL);
//             filament_actions_status(true);
//         }
//         break;
//     case IN_FILAMENT_THIRD_STEP:
//         {
//             show_step_btn_state(ui_BtnFirstStepScreenFila, true);
//             show_step_btn_state(ui_BtnSecondStepScreenFila, true);
//             show_step_btn_state(ui_BtnThirdStepScreenFila, true);
//             show_step_label_state(ui_LabelFilamentFirstStep, true);
//             show_step_label_state(ui_LabelFilamentSecondStep, true);
//             show_step_label_state(ui_LabelFilamentThirdStep, true);
//             show_step_dir_panel_state(ui_PanelFirstStepScreenFila, STEP_FINISHED);
//             show_step_dir_panel_state(ui_PanelSecondStepScreenFila, STEP_FINISHED);
//             show_temper_panel(SHOW_TEMPER_EDIT_PANEL);
//             if ( !home_printing_is_printing() ) //只有非打印进行中状态时才能进行消除不能使用状态
//                 filament_actions_status(false);
                
//             filament_action = FILA_ACTION_NONE;
//             filament_action_step_order = 0;
//             send_set_target_temper_cmd(targettemp, true);
//         }
//         break;

//     default:
//         break;
//     }

// }

// void show_out_filament_proccess(enum OUT_FILA_PROCCESS out_step)
// {
//     show_proccess_panel(true);
//     show_filament_proccess_steps(false);

//     switch (out_step)
//     {
//     case OUT_FILAMENT_FIRST_STEP:
//         {
//             show_step_btn_state(ui_BtnFirstStepScreenFila, true);
//             show_step_btn_state(ui_BtnSecondStepScreenFila, false);
//             show_step_btn_state(ui_BtnThirdStepScreenFila, false);
//             show_step_btn_state(ui_BtnFourthStepScreenFila, false);
//             show_step_label_state(ui_LabelFilamentFirstStep, true);
//             show_step_label_state(ui_LabelFilamentSecondStep, false);
//             show_step_label_state(ui_LabelFilamentThirdStep, false);
//             show_step_label_state(ui_LabelFilamentFourthStep, false);
//             show_step_dir_panel_state(ui_PanelFirstStepScreenFila, STEP_PROCCESSING);
//             show_step_dir_panel_state(ui_PanelSecondStepScreenFila, STEP_NOT_START);
//             show_step_dir_panel_state(ui_PanelThirdStepScreenFila, STEP_NOT_START);
//             show_temper_panel(SHOW_HEATING_PANEL);
//             filament_actions_status(true);
//         }
//         break;
//     case OUT_FILAMENT_SECOND_STEP:
//         {
//             show_step_btn_state(ui_BtnFirstStepScreenFila, true);
//             show_step_btn_state(ui_BtnSecondStepScreenFila, true);
//             show_step_btn_state(ui_BtnThirdStepScreenFila, false);
//             show_step_btn_state(ui_BtnFourthStepScreenFila, false);
//             show_step_label_state(ui_LabelFilamentFirstStep, true);
//             show_step_label_state(ui_LabelFilamentSecondStep, true);
//             show_step_label_state(ui_LabelFilamentThirdStep, false);
//             show_step_label_state(ui_LabelFilamentFourthStep, false);
//             show_step_dir_panel_state(ui_PanelFirstStepScreenFila, STEP_FINISHED);
//             show_step_dir_panel_state(ui_PanelSecondStepScreenFila, STEP_PROCCESSING);
//             show_step_dir_panel_state(ui_PanelThirdStepScreenFila, STEP_NOT_START);
//             show_temper_panel(SHOW_NORMAL_PANEL);
//             filament_actions_status(true);
//         }
//         break;
//     case OUT_FILAMENT_THIRD_STEP:
//         {
//             show_step_btn_state(ui_BtnFirstStepScreenFila, true);
//             show_step_btn_state(ui_BtnSecondStepScreenFila, true);
//             show_step_btn_state(ui_BtnThirdStepScreenFila, true);
//             show_step_btn_state(ui_BtnFourthStepScreenFila, false);
//             show_step_label_state(ui_LabelFilamentFirstStep, true);
//             show_step_label_state(ui_LabelFilamentSecondStep, true);
//             show_step_label_state(ui_LabelFilamentThirdStep, true);
//             show_step_label_state(ui_LabelFilamentFourthStep, false);
//             show_step_dir_panel_state(ui_PanelFirstStepScreenFila, STEP_FINISHED);
//             show_step_dir_panel_state(ui_PanelSecondStepScreenFila, STEP_FINISHED);
//             show_step_dir_panel_state(ui_PanelThirdStepScreenFila, STEP_PROCCESSING);
//             show_temper_panel(SHOW_NORMAL_PANEL);
//             filament_actions_status(true);
//         }
//         break;
//     case OUT_FILAMENT_FOURTH_STEP:
//         {
//             show_step_btn_state(ui_BtnFirstStepScreenFila, true);
//             show_step_btn_state(ui_BtnSecondStepScreenFila, true);
//             show_step_btn_state(ui_BtnThirdStepScreenFila, true);
//             show_step_btn_state(ui_BtnFourthStepScreenFila, true);
//             show_step_label_state(ui_LabelFilamentFirstStep, true);
//             show_step_label_state(ui_LabelFilamentSecondStep, true);
//             show_step_label_state(ui_LabelFilamentThirdStep, true);
//             show_step_label_state(ui_LabelFilamentFourthStep, true);
//             show_step_dir_panel_state(ui_PanelFirstStepScreenFila, STEP_FINISHED);
//             show_step_dir_panel_state(ui_PanelSecondStepScreenFila, STEP_FINISHED);
//             show_step_dir_panel_state(ui_PanelThirdStepScreenFila, STEP_FINISHED);
//             show_temper_panel(SHOW_TEMPER_EDIT_PANEL);
//             if ( !home_printing_is_printing() ) //只有非打印进行中状态时才能进行消除不能使用状态
//                 filament_actions_status(false);

//             filament_action = FILA_ACTION_NONE;
//             filament_action_step_order = 0;
//             send_set_target_temper_cmd(targettemp, true);
//         }
//         break;

//     default:
//         break;
//     }

// }

// void show_step_btn_state(lv_obj_t *step_btn, bool is_start)
// {
//     if ( step_btn )
//     {
//         if ( is_start )
//             lv_obj_set_style_bg_color(step_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
//         else
//             lv_obj_set_style_bg_color(step_btn, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
//     }
// }

// void show_step_label_state(lv_obj_t *step_label, bool is_start)
// {
//     if ( step_label )
//     {
//         if ( is_start )
//             lv_obj_set_style_text_color(step_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//         else
//             lv_obj_set_style_text_color(step_label, lv_color_hex(0x9A9DA0), LV_PART_MAIN | LV_STATE_DEFAULT);
//     }
// }

// void show_step_dir_panel_state(lv_obj_t *step_dir, enum STEP_DIR_STATE state)
// {
//     if ( !step_dir )
//         return;
    
//     switch (state)
//     {
//     case STEP_NOT_START:
//         {
//             lv_obj_set_style_bg_color(step_dir, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
//             lv_obj_set_style_bg_grad_dir(step_dir, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
//         }
//         break;
//     case STEP_PROCCESSING:
//         {
//             lv_obj_set_style_bg_color(step_dir, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
//             lv_obj_set_style_bg_grad_dir(step_dir, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
//         }
//         break;
//     case STEP_FINISHED:
//         {
//             lv_obj_set_style_bg_color(step_dir, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
//             lv_obj_set_style_bg_grad_dir(step_dir, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//         }
//         break;

//     default:
//         break;
//     }

// }

// void show_filament_proccess_steps(bool in_fila)
// {
//     if ( in_fila )
//     {
//         lv_obj_add_flag(ui_BtnFourthStepScreenFila, LV_OBJ_FLAG_HIDDEN);
//         lv_obj_add_flag(ui_LabelFilamentFourthStep, LV_OBJ_FLAG_HIDDEN);
//         lv_obj_add_flag(ui_PanelThirdStepScreenFila, LV_OBJ_FLAG_HIDDEN);
//         lv_label_set_text(ui_LabelFilamentFirstStep, HotendHeating[get_cur_language_index()]);
//         lv_label_set_text(ui_LabelTitleFilament, FilamentIn[get_cur_language_index()]);
//         lv_label_set_text(ui_LabelFilamentSecondStep, FilamentIning[get_cur_language_index()]);
//         lv_label_set_text(ui_LabelFilamentThirdStep, FilamentEnd[get_cur_language_index()]);
//     }
//     else
//     {
//         lv_obj_clear_flag(ui_BtnFourthStepScreenFila, LV_OBJ_FLAG_HIDDEN);
//         lv_obj_clear_flag(ui_LabelFilamentFourthStep, LV_OBJ_FLAG_HIDDEN);
//         lv_obj_clear_flag(ui_PanelThirdStepScreenFila, LV_OBJ_FLAG_HIDDEN);
//         lv_label_set_text(ui_LabelFilamentFirstStep, HotendHeating[get_cur_language_index()]);
//         lv_label_set_text(ui_LabelTitleFilament, FilamentOut[get_cur_language_index()]);
//         lv_label_set_text(ui_LabelFilamentSecondStep, FilamentOutPrep[get_cur_language_index()]);
//         lv_label_set_text(ui_LabelFilamentThirdStep, FilamentOuting[get_cur_language_index()]);
//         lv_label_set_text(ui_LabelFilamentFourthStep, FilamentOutEnd[get_cur_language_index()]);
//     }
// }

// void filament_actions_status(bool disable)
// {
//     CrLogI("refresh the filament state:%d.",disable);
//     if ( disable )
//     {
//         lv_obj_add_state(ui_ButtonInFilaScreenFilament, LV_STATE_DISABLED);       /// States
//         lv_obj_add_state(ui_ButtonOutFilaScreenFilament, LV_STATE_DISABLED);       /// States  
//         lv_obj_add_state(ui_LabelInFilaScreenFilament, LV_STATE_DISABLED);       /// States
//         lv_obj_add_state(ui_LabelOutFilaScreenFilament, LV_STATE_DISABLED);       /// States  
          
//     }
//     else
//     {
//         lv_obj_clear_state(ui_ButtonInFilaScreenFilament, LV_STATE_DISABLED);       /// States
//         lv_obj_clear_state(ui_ButtonOutFilaScreenFilament, LV_STATE_DISABLED);       /// States
//         lv_obj_clear_state(ui_LabelInFilaScreenFilament, LV_STATE_DISABLED);       /// States
//         lv_obj_clear_state(ui_LabelOutFilaScreenFilament, LV_STATE_DISABLED);       /// States
//     }
    
// }

// void filament_set_hotend_temper(uint16_t cur_temper, uint16_t target_temper)
// {
//     if ( target_temper <= 0 || ((filament_action != FILA_ACTION_IN) && (filament_action != FILA_ACTION_OUT)) )
//         return;
    
//     if ( cur_temper >=  target_temper )
//     {
//         if ( filament_action_step_order > 0 )
//             return;

//         filament_action_step_order = 1;
//         if ( filament_action == FILA_ACTION_IN )
//         {
//             show_in_filament_proccess(IN_FILAMENT_SECOND_STEP);
//             send_set_axis_move_opt_cmd(AXIS_E, true, 100, 300);
//         }
//         else if ( filament_action == FILA_ACTION_OUT )
//         {
//             show_out_filament_proccess(OUT_FILAMENT_SECOND_STEP);
//             // 发送退料准备的命令内容
//             send_set_axis_move_opt_cmd(AXIS_E, true, 10, 300);  // 5mm/s改成2.5mm/s(待测试后再改)
//         }
//     }
// }

// //进退料的动作过程，只有开始和结束，不包含加热温度
// void filament_set_filament_action_state(enum FILAMENT_ACTION_STATE state)
// {
//     if ( filament_action == FILA_ACTION_IN )
//     {
//         if ( state ==  FILAMENT_ACTION_SUCCESS )
//         {
//             if ( filament_action_step_order >= 1 )
//                 show_in_filament_proccess(IN_FILAMENT_THIRD_STEP);
//         }
//         else if ( state ==  FILAMENT_ACTION_FAILED )
//         {
//             show_in_filament_proccess(IN_FILAMENT_THIRD_STEP);
//             //是否有进料失败的提示

//         }
        

//     }
//     else if ( filament_action == FILA_ACTION_OUT )
//     {
//         if ( state ==  FILAMENT_ACTION_SUCCESS )
//         {
//             if ( filament_action_step_order == 1 )
//             {
//                 show_out_filament_proccess(OUT_FILAMENT_THIRD_STEP);

//                 //发送退料的命令
//                 send_set_axis_move_opt_cmd(AXIS_E, false, 110, 300);

//                 filament_action_step_order = 2;
//             }
//             else if ( filament_action_step_order > 1 )
//             {
//                 show_out_filament_proccess(OUT_FILAMENT_FOURTH_STEP);
//             }
//         }
//         else if ( state ==  FILAMENT_ACTION_FAILED )
//         {
//             show_out_filament_proccess(OUT_FILAMENT_FOURTH_STEP);
//         }
//     }
// }

// void filament_set_print_status(int8_t print_status)  // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
// {
//     // 0: finished, 1:stoped, 2:paused, 3:printing,6:温度升温中  依赖于协议
//     if ( (print_status == 3) || (print_status == 6) )  
//     {
//         filament_actions_status(true);    
//     }
//     else if ( (print_status == 2) || (print_status == 0) || (print_status == 1) )
//     {
//         if ( (filament_action == FILA_ACTION_NONE) && (filament_action_step_order == 0) )
//             filament_actions_status(false);
//         if(system_state.PreStartprint_state)
//             filament_actions_status(true);
//     }

// }

// void set_hotend_temper_filament(char * curtemp, char * tartemp)
// {
//     if( lv_scr_act() != ui_ScreenFilament)return;
//     char buff[30] = {0};
//     snprintf(buff, 30, "%s°C", curtemp);
//     if(ui_LabelRealTemper && curtemp[0] != '\0')
//     {
//         char buff[30] = {0};
//         snprintf(buff, 30, "%s°C", curtemp);
//         lv_label_set_text(ui_LabelRealTemper, buff);
//     }
//     if(ui_LabelTargetTemper && tartemp[0] != '\0')
//     {
//         char buff[30] = {0};
//         snprintf(buff, 30, "%s°C", tartemp);
//         lv_label_set_text(ui_LabelTargetTemper, buff);
//         lv_label_set_text(ui_LabelNormalRealTemper, buff);
//     }
// }

// void refresh_filament_process(int flag, int process)
// {
//     if(flag == 1)
//     {
//         switch (process)
//         {
//             case 2: lv_timer_set_repeat_count(timer_proccess, 0);
//                     show_in_filament_proccess(IN_FILAMENT_FIRST_STEP);break;
//             case 4:show_in_filament_proccess(IN_FILAMENT_SECOND_STEP);break;
//             case 100:show_in_filament_proccess(IN_FILAMENT_THIRD_STEP);break;
//             default:
//                 break;
//         }
//     }
//     if(flag == 2)
//     {
//         switch (process)
//         {
//             case 2:lv_timer_set_repeat_count(timer_proccess, 0);
//                    show_out_filament_proccess(OUT_FILAMENT_FIRST_STEP);break;
//             case 4:show_out_filament_proccess(OUT_FILAMENT_SECOND_STEP);break;
//             case 5:show_out_filament_proccess(OUT_FILAMENT_THIRD_STEP);break;
//             case 100:show_out_filament_proccess(OUT_FILAMENT_FOURTH_STEP);break;
//             default:
//                 break;
//         }
//     }
// }

// void filament_infor_change_language_text()
// {
//     if ( ui_LabelMoveScreenFila )
//     {
//         lv_label_set_text(ui_LabelMoveScreenFila, MovePageTitle[get_cur_language_index()]);
//         redefine_label_size(ui_LabelMoveScreenFila, lv_font25.font, 0, 0, 240, 0);
        
//         lv_obj_update_layout(ui_PanelMoveScreenFila);
//         redefine_widgets_size(ui_PanelMoveScreenFila, ui_LabelMoveScreenFila, 5, 0, 240, 46);
//     }
//     if ( ui_LabelAdjustmentScreenFila )
//     {
//         lv_label_set_text(ui_LabelAdjustmentScreenFila, Adjustment[get_cur_language_index()]);
//         redefine_label_size(ui_LabelAdjustmentScreenFila, lv_font25.font, 0, 0, 150, 0);

//         lv_obj_update_layout(ui_PanelAdjustmentScreenFila);
//         redefine_widgets_size(ui_PanelAdjustmentScreenFila, ui_LabelAdjustmentScreenFila, 5, 0, 100, 46);
//     }
//     if ( ui_LabelCoolScreenFila )
//     {
//         lv_label_set_text(ui_LabelCoolScreenFila, Cooling[get_cur_language_index()]);     //冷却
//         redefine_label_size(ui_LabelCoolScreenFila, lv_font25.font, 0, 0, 240, 0);
        
//         lv_obj_update_layout(ui_PanelCoolScreenFila);
//         redefine_widgets_size(ui_PanelCoolScreenFila, ui_LabelCoolScreenFila, 5, 0, 100, 46);
//     }
//     if ( ui_LabelFilamentScreenFila )
//     {
//         lv_label_set_text(ui_LabelFilamentScreenFila, Extrude_Retract[get_cur_language_index()]);
//         redefine_label_size(ui_LabelFilamentScreenFila, lv_font25.font, 0, 0, 240, 0);
        
//         lv_obj_update_layout(ui_PanelFilamentScreenFila);
//         redefine_widgets_size(ui_PanelFilamentScreenFila, ui_LabelFilamentScreenFila, 5, 0, 200, 46);
//     }
//     if ( ui_LabelTipsContentScreenFila )
//         lv_label_set_text(ui_LabelTipsContentScreenFila, HotTips[get_cur_language_index()]);
//     if ( ui_LabelTitleTips )
//         lv_label_set_text(ui_LabelTitleTips, FilamentTips[get_cur_language_index()]);
//     if ( ui_LabelInFilaScreenFilament )
//     {
//         lv_label_set_text(ui_LabelInFilaScreenFilament, FilamentIn[get_cur_language_index()]);
//         redefine_label_size(ui_LabelInFilaScreenFilament, lv_font25.font, 0, 0, 220, 0);
        
//         lv_obj_update_layout(ui_ButtonInFilaScreenFilament);
//         redefine_widgets_size(ui_ButtonInFilaScreenFilament, ui_LabelInFilaScreenFilament, 10, 0, 116, 60);
//     }
//     if ( ui_LabelOutFilaScreenFilament )
//     {
//         lv_label_set_text(ui_LabelOutFilaScreenFilament, FilamentOut[get_cur_language_index()]);
//         redefine_label_size(ui_LabelOutFilaScreenFilament, lv_font25.font, 0, 0, 220, 0);
        
//         lv_obj_update_layout(ui_ButtonOutFilaScreenFilament);
//         redefine_widgets_size(ui_ButtonOutFilaScreenFilament, ui_LabelOutFilaScreenFilament, 10, 0, 116, 60);
//     }
//     if ( ui_LabelTitleScreenFilament )
//         lv_label_set_text(ui_LabelTitleScreenFilament, HotendTemp[get_cur_language_index()]); 
//     if ( ui_LabelFilamentFirstStep )
//         lv_label_set_text(ui_LabelFilamentFirstStep, HotendHeating[get_cur_language_index()]);

//     if(ui_LabelTitleFilament)
//     {
//         for(int i = 0; i < MAX_LANGUAGE; i++)
//         {
//             if(strcmp(lv_label_get_text(ui_LabelTitleFilament),FilamentIn[i])== 0)
//             {
//                 lv_label_set_text(ui_LabelTitleFilament, FilamentIn[get_cur_language_index()]);
//                 break;
//             }
//             else if(strcmp(lv_label_get_text(ui_LabelTitleFilament),FilamentOut[i])== 0)
//             {
//                 lv_label_set_text(ui_LabelTitleFilament, FilamentOut[get_cur_language_index()]);
//                 break;
//             }
//         }
//     }

//     if(ui_LabelFilamentSecondStep)
//     {
//         for(int i = 0; i < MAX_LANGUAGE; i++)
//         {
//             if(strcmp(lv_label_get_text(ui_LabelFilamentSecondStep),FilamentIning[i])== 0)
//             {
//                 lv_label_set_text(ui_LabelFilamentSecondStep, FilamentIning[get_cur_language_index()]);
//                 break;
//             }
//             else if(strcmp(lv_label_get_text(ui_LabelFilamentSecondStep),FilamentOutPrep[i])== 0)
//             {
//                 lv_label_set_text(ui_LabelFilamentSecondStep, FilamentOutPrep[get_cur_language_index()]);
//                 break;
//             }
//         }
//     }

//     if(ui_LabelFilamentThirdStep)
//     {
//         for(int i = 0; i < MAX_LANGUAGE; i++)
//         {
//             if(strcmp(lv_label_get_text(ui_LabelFilamentThirdStep),FilamentEnd[i])== 0)
//             {
//                 lv_label_set_text(ui_LabelFilamentThirdStep, FilamentEnd[get_cur_language_index()]);
//                 break;
//             }
//             else if(strcmp(lv_label_get_text(ui_LabelFilamentThirdStep),FilamentOuting[i])== 0)
//             {
//                 lv_label_set_text(ui_LabelFilamentThirdStep, FilamentOuting[get_cur_language_index()]);
//                 break;
//             }
//         }
//     }
    
//     if(ui_LabelFilamentThirdStep)
//         lv_label_set_text(ui_LabelFilamentFourthStep, FilamentOutEnd[get_cur_language_index()]);

// }

// int get_fila_action_type(void)
// {
//     return filament_action;
// }