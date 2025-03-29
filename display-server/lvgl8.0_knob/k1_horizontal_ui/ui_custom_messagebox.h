/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-08 10:54:20
 * @LastEditTime: 2023-08-18 04:14:39
 */
#ifndef _UI_CUSTOM_MESSAGEBOX_H
#define _UI_CUSTOM_MESSAGEBOX_H


#ifdef __cplusplus
extern "C" {
#endif


#include "lvgl/lvgl.h"


typedef struct Msgboxbtn
{
    lv_obj_t *btn;
    lv_obj_t *label;
    void (*SetLabelText)(lv_obj_t *label, uint8_t label_index, uint8_t language_index);
    lv_event_cb_t btnsCallbackArray;
} Msgboxbtn_t;

typedef struct SubPanlAttr
{
    uint8_t x;
    uint8_t y;
    uint16_t h;
    uint16_t w;
}SubPanlAttr_t;

typedef struct DialogMsgbox
{
    const char **title;
    char *message;
    lv_obj_t *panel;
    lv_obj_t *subPanel;
    lv_obj_t *titleLabel;
    lv_obj_t *contentLabel;
    uint8_t btnNumber;
    bool hasSubPanel;
    Msgboxbtn_t *btn;
    lv_style_t *customStyle;
    lv_style_t *customFocusStyle;
    SubPanlAttr_t subPanelAttr;
}DialogMsgbox_t; 

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

void InitDialogMessagebox(DialogMsgbox_t *dialog);
void ShowDialogMessagebox(DialogMsgbox_t *dialog, void (*change_group_objs_cb)(void));
void HiddenDialogMessagebox(DialogMsgbox_t *dialog);
#ifdef __cplusplus
}
#endif

#endif