/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-14 20:20:32
 * @LastEditTime: 2023-09-16 08:52:26
 */
#ifndef _UI_SCREEN_WIDGETS_H
#define _UI_SCREEN_WIDGETS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"

extern lv_obj_t * ui_Msgbox;

typedef struct ErrorMsg
{
    lv_obj_t * ErrorMsgbox;
    // lv_obj_t * ErrorMsgboxImage1;
    // lv_obj_t * ErrorMsgboxImage2;
    // lv_obj_t * ErrorMsgboxImage3;
    // lv_obj_t * ErrorMsgboxImage4;
    // lv_obj_t * ErrorMsgboxImage5;
    lv_obj_t * ErrorMsgboxbg;
    lv_obj_t * MsgboxTitle;
    lv_obj_t * MsgboxContent;
    lv_obj_t * ErrorMsgboxlabel1;
    lv_obj_t * ErrorMsgboxlabel2;
    int errorcode;
    char error_content[200];
}ErrorMsg_t;


void cancle_msgbox();
void init_msgbox();
void create_msgbox(char * title, char * imgsrc, uint32_t continue_length, lv_obj_t * parent);
ErrorMsg_t * Error_message_create(char * title, char * content, char * btn1, char *btn2, int errorcode, char * error_content);
void Error_message_delete(ErrorMsg_t * msg);
void set_error_msg(int errorcode, int k1_errorcode, char * error_msg);
void wait_animmotion(bool flag);
void wifi_wait_animmotion(uint16_t time_s);
void redefine_label_size(lv_obj_t * widgets, lv_font_t * font, lv_coord_t letter_space, lv_coord_t line_space, lv_coord_t max_width, lv_text_flag_t flag);
void redefine_widgets_size(lv_obj_t * widgets, lv_obj_t *new_widgets, lv_coord_t width_offset, lv_coord_t height_offset, lv_coord_t max_width, lv_coord_t max_height);
void ErrorMsgboxAddObjsToGroup(void);
char * get_errorcode_info(int errorcode);
void init_uploadlog_msg(void);
void create_wificonect_page(lv_obj_t * screen_page, const char * wifiname, bool isHiddenNetwork);
void selftest_refresh_upload_process(int state, int process, char * SN);
void close_PrivacyMessagebox();
void create_PrivacyMessagebox(char *message, char *btn1label, char *btn2label, lv_event_cb_t btn1_event, lv_event_cb_t btn2_event);
void create_selftest_messagebox(char *title, char *message, char *btn1label, char *btn2label, void(*btns_callback_array[2])(void));
void selftest_messagebox_close(void);
void RemindUserToAutolevel();
#ifdef __cplusplus
}
#endif

#endif