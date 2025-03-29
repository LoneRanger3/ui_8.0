// /*
//  * @Description : 
//  * @Author      : Yufeng Zhang
//  * @Date: 2023-01-30 11:13:24
//  * @LastEditTime: 2023-03-17 17:50:13
//  */
// #ifndef _UI_SCREEN_FILAMENT_INFOR_H
// #define _UI_SCREEN_FILAMENT_INFOR_H

// #ifdef __cplusplus
// extern "C" {
// #endif

// #include "ui.h"
// #include "ui_helpers.h"

// /*****挤出料的过程，不包含加热温度*******/
// enum IN_FILAMENT_STATE
// {
//     IN_FILAMENT_NONE,
//     IN_FILAMENT_IN,
//     IN_FILAMENT_FINISHED,
// };

// /*****退出料的过程，不包含加热温度*******/
// enum OUT_FILAMENT_STATE
// {
//     OUT_FILAMENT_NONE,
//     OUT_FILAMENT_READY,
//     OUT_FILAMENT_OUT,
//     OUT_FILAMENT_FINISHED,
// };

// /***********料操作动作状态******************/
// enum FILAMENT_ACTION_STATE
// {
//     FILAMENT_ACTION_PROCCESSING,
//     FILAMENT_ACTION_FAILED,
//     FILAMENT_ACTION_SUCCESS,
// };

// enum FILA_ACTION_TYPE{
//     FILA_ACTION_NONE,
//     FILA_ACTION_IN,
//     FILA_ACTION_OUT,
// };

// int get_fila_action_type(void);
// void ui_ScreenFilament_screen_init(void);
// void LoadFilamentScreen(void);

// void filament_set_hotend_temper(uint16_t cur_temper, uint16_t target_temper);
// void filament_set_filament_action_state(enum FILAMENT_ACTION_STATE state);  //进退料的动作过程，只有开始和结束，不包含加热温度
// void filament_set_print_status(int8_t print_status);  // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
// void refresh_filament_process(int flag, int process);
// void set_hotend_temper_filament(char * curtemp, char * tartemp);
// void filament_infor_change_language_text();
// void filament_actions_status(bool disable);
// #ifdef __cplusplus
// }
// #endif

// #endif