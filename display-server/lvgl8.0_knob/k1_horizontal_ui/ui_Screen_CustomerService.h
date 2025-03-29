/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-22 17:39:34
 * @LastEditTime: 2023-10-24 22:01:03
 */
#ifndef _UI_SCREEN_CUSTOMERSERVICE_H
#define _UI_SCREEN_CUSTOMERSERVICE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

typedef struct MenuItem
{
    lv_obj_t *parent;
    lv_obj_t *part_panel;
    lv_obj_t *label_item_name; 
    lv_obj_t *label_content_name; 
    lv_obj_t *img_arrow_png;
    uint8_t index;
}MenuItem_t;

typedef struct ErrorMenuItemInfo
{
    int64_t time;
    int32_t code;
    int32_t error;
    char msg[256];
    char value[64];
    // uint8_t index;
}ErrorMenuItemInfo_t;

typedef struct ErrorMenuItemObj
{
    lv_obj_t *parent;
    lv_obj_t *part_panel;
    lv_obj_t *label_error_code;
    lv_obj_t *label_error_time; 
    lv_obj_t *label_error_detail;
    ErrorMenuItemInfo_t error_info;
    uint8_t index;
}ErrorMenuItemObj_t;

typedef enum {
    MAIN_MENU_PAGE = 0,
    FAQ_PAGE,
    ONLINE_MANUAL_PAGE,
    PRINT_HISTORY_PAGE,
    ERROR_HISTORY_PAGE,
    EXPORT_LOG_PAGE,
    EXPORT_UDISK_PAGE,
}SubPageType_t;

typedef struct print_history_part
{
    lv_obj_t *parent;
    lv_obj_t *history_panel;
    lv_obj_t *img_thumbnail;
    lv_obj_t *label_file_name;
    lv_obj_t *label_start_time;
    lv_obj_t *label_real_totle_time;
    lv_obj_t *img_state;
    // lv_obj_t *btn_print_again;
    // lv_obj_t *lable_print_again;
    int32_t history_record_index;
}print_history_part_t;


void LoadServiceScreenAndObjs(bool IsEntered);
void ui_ScreenCustomerService_screen_init(void);
void LoadCustomerServiceScreen(void);

void service_set_feedback_QRcode_png(char *QRcode_png_name);
void service_change_language_text(void);
void refresh_uploadlog_process(int state, int process, char * SN);
void ChangeServiceScreenFosObjs(bool IsEntered);
void service_page_refresh_laserstate(int laser_state);
void service_page_refresh_camerastate(int camera_state);
void service_page_set_wifi_status(int intensity);
void CreateInsertUdiskTipDialog(uint32_t continue_length);
void refresh_compressed_process(int process);
void CustomerServicePageCloseSubPage(void);

#ifdef __cplusplus
}
#endif

#endif