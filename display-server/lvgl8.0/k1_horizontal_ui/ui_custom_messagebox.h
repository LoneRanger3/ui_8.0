/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-08 10:54:20
 * @LastEditTime: 2022-12-12 19:55:51
 */
#ifndef _UI_CUSTOM_MESSAGEBOX_H
#define _UI_CUSTOM_MESSAGEBOX_H


#ifdef __cplusplus
extern "C" {
#endif


#include "lvgl/lvgl.h"



// create_custom_messagebox max btns count is 3, message is NULL or content is enpty will not show message
void create_custom_messagebox(char *title, char *message, char *btns[3], void(*btns_callback_array[3])(void), int btn_count, bool arrangement_method_hor, bool show_close_btn);
//void set_custom_messagebox_style(lv_style_t *style); // style must be static pointer or global pointer, can not be Temporary variables. 
void set_custom_messagebox_bg_color(lv_color_t bk_color, uint8_t arp);  
void set_custom_messagebox_label_text_color(lv_color_t color);  
void set_custom_messagebox_label_bg_color(lv_color_t color);  
void set_custom_messagebox_btn_bg_color(int btn_index, lv_color_t color);  //btn_index start at 0, max is 2 ; style must be static pointer or global pointer, can not be Temporary variables. 
void set_custom_messagebox_btn_text_color(int btn_index, lv_color_t color);
void clear_custom_messagebox_bg_color();
void messagebox_close();
#ifdef __cplusplus
}
#endif

#endif