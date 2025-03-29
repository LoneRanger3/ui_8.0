/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2023-02-18 15:39:00
 * @LastEditTime: 2023-11-02 21:01:32
 */
#include "page_switch.h"
#include "ui.h"
#include "ui_Screen_Widgets.h"
#include "mult_language.h"

lv_obj_t * ui_Msgbox;
lv_obj_t * ui_Msgboxbg;
lv_obj_t * ui_MsgboxTitle;
lv_obj_t * ui_Msgboximg;
lv_timer_t * ui_Msgbox_timeout;

ErrorMsg_t * error_msg;
//等待动画弹窗
lv_obj_t * ui_waitAnimotion;
lv_obj_t * ui_waitimg;
lv_obj_t * ui_waittimer;

lv_obj_t * ui_WifiWaitAnimotion;
lv_obj_t * ui_Wifiwaitimg;

//上传日志弹窗
lv_obj_t * Msgbox2Bg;
lv_obj_t * Msgbox2;
lv_obj_t * Msgbox2label1;
lv_obj_t * Msgbox2label2;
lv_obj_t * Msgbox2label3;
lv_obj_t * Msgbox2label4;
lv_obj_t * Msgbox2label5;
lv_obj_t * Msgbox2img1;
lv_obj_t * Msgbox2Btnlabel1;
lv_obj_t * Msgbox2Btn1;


lv_obj_t * ErrorMsgboxlabel1;
lv_obj_t * ErrorMsgboxlabel2;

//打印完成弹窗
lv_obj_t * Msgbox3Bg;
lv_obj_t * Msgbox3;
lv_obj_t * Msgbox3label1;
lv_obj_t * Msgbox3label2;
lv_obj_t * Msgbox3img1;
lv_obj_t * Msgbox3img2;
lv_obj_t * Msgbox3Btnlabel1;
lv_obj_t * Msgbox3Btn1;

//弹窗
lv_obj_t * ui_SelftestMsgboxBg;
lv_obj_t * ui_SelftestMsgbox;
lv_obj_t * ui_Msgboxlabel1;
lv_obj_t * ui_Msgboxlabel2;
lv_obj_t * ui_MsgboxButton1;
lv_obj_t * ui_MsgboxBtnlabel1;
lv_obj_t * ui_MsgboxButton2;
lv_obj_t * ui_MsgboxBtnlabel2;

static bool waitAnimotionFlag = false;

static void (*messagebox_btn_callback[2])(void) = {NULL, NULL, NULL};
void messagebox_btnclick_event_handler(lv_event_t * e);

void ui_event_msgbtn1(lv_event_t * e);
void ui_event_msgbtn2(lv_event_t * e);
void ui_event_pageload(lv_event_t * e);
void ui_event_Msgbox2Btn1(lv_event_t * e);
void ErrorMsgboxAddObjsToGroup(void);
void SelftestMsgboxAddObjsToGroup(void);


void timeout_handle(lv_timer_t * timer)
{
    cancle_msgbox();
    lv_timer_pause(ui_Msgbox_timeout);
    //lv_group_focus_freeze(encoder_group, false);
    CrLogI("cancle the msgbox.");
}
void init_msgbox()
{
    // ErrorPopout.popout_focus_obj1 = NULL;
    // ErrorPopout.popout_focus_obj2 = NULL;
    // ErrorPopout.obj1_flag = false;
    // ErrorPopout.obj2_flag = false;
    // ErrorPopout.change_group_objs = ErrorMsgboxAddObjsToGroup;

    ui_Msgbox = lv_obj_create(lv_layer_top());
    lv_obj_set_width(ui_Msgbox, 640);
    lv_obj_set_height(ui_Msgbox, 480);
    lv_obj_clear_flag(ui_Msgbox, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Msgbox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Msgbox, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Msgbox, 220, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Msgbox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_Msgbox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_Msgbox, LV_OBJ_FLAG_HIDDEN);      /// Flags

    ui_Msgboxbg = lv_obj_create(ui_Msgbox);
    lv_obj_set_width(ui_Msgboxbg, 480);
    lv_obj_set_height(ui_Msgboxbg, 70);
    lv_obj_clear_flag(ui_Msgboxbg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_align(ui_Msgboxbg, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_radius(ui_Msgboxbg, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Msgboxbg, lv_color_hex(0x36383C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Msgboxbg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Msgboxbg, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Msgboxbg, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_Msgboxbg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_Msgboxbg, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Msgboxbg, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_row(ui_Msgboxbg, 5,  LV_PART_MAIN | LV_STATE_DEFAULT);

    
    ui_Msgboximg = lv_img_create(ui_Msgboxbg);
    lv_obj_set_width(ui_Msgboximg, 30);
    lv_obj_set_height(ui_Msgboximg, 30);
    lv_obj_align(ui_Msgboximg, LV_ALIGN_LEFT_MID, -5, 8);
    lv_obj_add_flag(ui_Msgboximg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags

    ui_MsgboxTitle = lv_label_create(ui_Msgboxbg);
    lv_obj_set_width(ui_MsgboxTitle, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_MsgboxTitle, 40);
   // lv_obj_align(ui_MsgboxTitle, LV_ALIGN_CENTER, 0, 0);
    lv_obj_align(ui_MsgboxTitle, LV_ALIGN_LEFT_MID, 60, 0);
    lv_label_set_long_mode(ui_MsgboxTitle, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_MsgboxTitle, "");
    lv_obj_set_style_text_color(ui_MsgboxTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_MsgboxTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_MsgboxTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Msgbox_timeout = lv_timer_create(timeout_handle, 1000, NULL);
    lv_timer_pause(ui_Msgbox_timeout);
}

void MsgboxAddObjsToGroup(void)
{
    lv_group_focus_freeze(encoder_group, false); //用于解决导航按钮加冻结后解冻前，错误弹框无法聚焦的情况
    lv_group_remove_all_objs(encoder_group);

    lv_group_add_obj(encoder_group, ui_Msgbox);
}

void create_msgbox(char * title, char * imgsrc, uint32_t continue_length, lv_obj_t * parent)
{
    //创建前记录之前的聚焦对象，如果前面有弹框，那么就不用记录
    // if (!IsThereAnyPopout())
    // {
    //     RecordObjBeforePopup();
    // }
    CrLogI("create_msgbox");
    if (ScreenOffFlag) //息屏状态下，不在显示消息框，并且关闭消息框，解决与息屏冲突，造成BackPrepage出错问题
    {
        cancle_msgbox();
        lv_timer_pause(ui_Msgbox_timeout);
        return;
    }

    //lv_group_focus_freeze(encoder_group, true);
    lv_indev_enable(enc_indev, false);
    lv_obj_set_parent(ui_Msgbox, lv_scr_act());
    if(lv_obj_has_flag(ui_Msgbox, LV_OBJ_FLAG_HIDDEN))
        lv_obj_clear_flag(ui_Msgbox, LV_OBJ_FLAG_HIDDEN);      /// Flags

    if(title != NULL) 
    {
        lv_label_set_text(ui_MsgboxTitle, title);
        redefine_label_size(ui_MsgboxTitle, lv_font25.font, 0, 0, 360, 0);

        lv_obj_update_layout(ui_Msgboxbg);
        redefine_widgets_size(ui_Msgboxbg, ui_MsgboxTitle, 5, 10, 384, 70);
    }

    if(imgsrc != NULL)
    {
        lv_img_set_src(ui_Msgboximg, imgsrc);
        lv_obj_clear_flag(ui_Msgboximg, LV_OBJ_FLAG_HIDDEN);     /// Flags
    }
    else
    {
        lv_obj_add_flag(ui_Msgboximg, LV_OBJ_FLAG_HIDDEN);     /// Flags
    }

    if(continue_length > 0)
    {
        CrLogI("reload the timer");
        lv_timer_pause(ui_Msgbox_timeout);
        lv_timer_set_period(ui_Msgbox_timeout, continue_length);
        lv_timer_reset(ui_Msgbox_timeout);
        lv_timer_resume(ui_Msgbox_timeout);
        // lv_timer_set_repeat_count(ui_Msgbox_timeout, 1);            
    }
    else
    {
        CrLogI("pause the timer");
        lv_timer_pause(ui_Msgbox_timeout);
        //lv_group_focus_freeze(encoder_group, false);
        //lv_indev_enable(enc_indev, true);
    }
    // InitPopoutManager(&MsgPopout, ui_Msgbox, MsgboxAddObjsToGroup);
    // MsgPopout.obj1_flag = true;
    // MsgPopout.popout_focus_obj1 = ui_Msgbox;

    // //弹框聚焦对象处理
    // ManagePopoutFocus();
}

void cancle_msgbox()
{
    // lv_obj_del(ui_Msgbox);
    // ui_Msgbox = NULL;
    // ui_Msgbox  = NULL;
    // ui_Msgboxbg = NULL;
    // ui_MsgboxTitle = NULL;
    // ui_Msgboximg = NULL;
    // ui_Msgbox_timeout = NULL;
    CrLogI("cancle_msgbox");
    //lv_group_focus_freeze(encoder_group, false);
    // if (!waitAnimotionFlag)
    // {
        lv_indev_enable(enc_indev, true);
   // }
    
    //DeinitPopoutManager(&MsgPopout);
    lv_obj_add_flag(ui_Msgboximg, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_add_flag(ui_Msgbox, LV_OBJ_FLAG_HIDDEN);      /// Flags
    // if (IsThereAnyPopout())
    // {
    //     ManagePopoutFocus();
    // }
    // else
    // {
    //     CrLogI("cancle_msgbox BackPrepage");
    //     printf("cancle_msgbox BackPrepage\n");
    //     BackPrepage(true);
    // }
}

void Error_message_delete(ErrorMsg_t * msg)
{
    CrLogI("Error message start delete.");
    // if(current_error) current_error = false;
    // if(current_tips) current_tips = true;
    DeinitPopoutManager(&ErrorPopout);
    lv_obj_add_flag(msg->ErrorMsgbox, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    lv_obj_del(msg->ErrorMsgbox);
    lv_mem_free(msg);
    error_msg = NULL;
    msg = NULL;
    
    if (IsThereAnyPopout())
    {
        ManagePopoutFocus();
    }
    // else
    // {
    //     CrLogI("Error_message_delete BackPrepage");
    //     BackPrepage(true);
    // }
}

//错误弹窗提示
ErrorMsg_t * Error_message_create(char * title, char * content, char * btn1, char *btn2, int errorcode, char * error_content)
{
    if (!IsThereAnyPopout())
    {
        RecordObjBeforePopup();
    }
    ErrorMsg_t * msg = (ErrorMsg_t *)lv_mem_alloc(sizeof(ErrorMsg_t));
    if ( !msg )
    {
        CrLogE("Errormsgbox can't create.");
        return NULL;
    }

    CrLogI("Errormsgbox create success.");
    lv_obj_t *ErrorMsgbox = lv_obj_create(lv_layer_top());
    lv_obj_set_width(ErrorMsgbox, 640);
    lv_obj_set_height(ErrorMsgbox, 480);
    lv_obj_clear_flag(ErrorMsgbox, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ErrorMsgbox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ErrorMsgbox, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ErrorMsgbox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ErrorMsgbox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ErrorMsgbox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // lv_obj_t *ErrorMsgboxImage1 = lv_img_create(ErrorMsgbox);
    // lv_img_set_src(ErrorMsgboxImage1, &ui_img_pagehome_png);
    // lv_obj_set_width(ErrorMsgboxImage1, 80);
    // lv_obj_set_height(ErrorMsgboxImage1, 96);
    // lv_obj_add_flag(ErrorMsgboxImage1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    // lv_obj_clear_flag(ErrorMsgboxImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ErrorMsgboxImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // lv_obj_t *ErrorMsgboxImage2 = lv_img_create(ErrorMsgbox);
    // lv_img_set_src(ErrorMsgboxImage2, &ui_img_pagemove_png);
    // lv_obj_set_width(ErrorMsgboxImage2, 80);
    // lv_obj_set_height(ErrorMsgboxImage2, 96);
    // lv_obj_set_x(ErrorMsgboxImage2, 0);
    // lv_obj_set_y(ErrorMsgboxImage2, 96);
    // lv_obj_add_flag(ErrorMsgboxImage2, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    // lv_obj_clear_flag(ErrorMsgboxImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ErrorMsgboxImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ErrorMsgboxImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // lv_obj_t *ErrorMsgboxImage3 = lv_img_create(ErrorMsgbox);
    // lv_img_set_src(ErrorMsgboxImage3, &ui_img_pagefilemanage_png);
    // lv_obj_set_width(ErrorMsgboxImage3, 80);
    // lv_obj_set_height(ErrorMsgboxImage3, 96);
    // lv_obj_set_x(ErrorMsgboxImage3, 0);
    // lv_obj_set_y(ErrorMsgboxImage3, 192);
    // lv_obj_add_flag(ErrorMsgboxImage3, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    // lv_obj_clear_flag(ErrorMsgboxImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ErrorMsgboxImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ErrorMsgboxImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // lv_obj_t *ErrorMsgboxImage4 = lv_img_create(ErrorMsgbox);
    // lv_img_set_src(ErrorMsgboxImage4, &ui_img_pagesettingselected_png);
    // lv_obj_set_width(ErrorMsgboxImage4, 80);
    // lv_obj_set_height(ErrorMsgboxImage4, 96);
    // lv_obj_set_x(ErrorMsgboxImage4, 0);
    // lv_obj_set_y(ErrorMsgboxImage4, 288);
    // lv_obj_add_flag(ErrorMsgboxImage4, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    // lv_obj_clear_flag(ErrorMsgboxImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ErrorMsgboxImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ErrorMsgboxImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // lv_obj_t * ErrorMsgboxImage5 = lv_img_create(ErrorMsgbox);
    // lv_img_set_src(ErrorMsgboxImage5, &ui_img_pagereserve_png);
    // lv_obj_set_width(ErrorMsgboxImage5, 80);
    // lv_obj_set_height(ErrorMsgboxImage5, 96);
    // lv_obj_set_x(ErrorMsgboxImage5, 0);
    // lv_obj_set_y(ErrorMsgboxImage5, 384);
    // lv_obj_add_flag(ErrorMsgboxImage5, LV_OBJ_FLAG_CLICKABLE );     /// Flags
    // lv_obj_clear_flag(ErrorMsgboxImage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ErrorMsgboxImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ErrorMsgboxImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // lv_obj_set_style_img_opa(ErrorMsgboxImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_img_opa(ErrorMsgboxImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_img_opa(ErrorMsgboxImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_img_opa(ErrorMsgboxImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_img_opa(ErrorMsgboxImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // lv_obj_add_event_cb(ErrorMsgboxImage1,ui_event_pageload,LV_EVENT_CLICKED, msg);
    // lv_obj_add_event_cb(ErrorMsgboxImage2,ui_event_pageload,LV_EVENT_CLICKED, msg);
    // lv_obj_add_event_cb(ErrorMsgboxImage3,ui_event_pageload,LV_EVENT_CLICKED, msg);
    // lv_obj_add_event_cb(ErrorMsgboxImage4,ui_event_pageload,LV_EVENT_CLICKED, msg);
    // lv_obj_add_event_cb(ErrorMsgboxImage5,ui_event_pageload,LV_EVENT_CLICKED, msg);

    lv_obj_t * ErrorMsgboxbg = lv_obj_create(ErrorMsgbox);
    lv_obj_set_width(ErrorMsgboxbg, 527);
    lv_obj_set_height(ErrorMsgboxbg, 165);
    lv_obj_clear_flag(ErrorMsgboxbg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_align(ErrorMsgboxbg, LV_ALIGN_TOP_LEFT, 85, 65); //5
    lv_obj_set_style_radius(ErrorMsgboxbg, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ErrorMsgboxbg, lv_color_hex(0x333435), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ErrorMsgboxbg, 220, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ErrorMsgboxbg, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ErrorMsgboxbg, lv_color_hex(0x3B3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ErrorMsgboxbg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * MsgboxTitle = lv_label_create(ErrorMsgboxbg);
    lv_obj_set_width(MsgboxTitle, LV_SIZE_CONTENT);
    lv_obj_set_height(MsgboxTitle, LV_SIZE_CONTENT);
    lv_obj_align(MsgboxTitle, LV_ALIGN_TOP_LEFT, 29, 11);
    lv_label_set_text(MsgboxTitle, title);
    lv_obj_set_style_text_color(MsgboxTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(MsgboxTitle, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * MsgboxContent = lv_label_create(ErrorMsgboxbg);
    lv_obj_set_width(MsgboxContent, 470);//630
    lv_obj_set_height(MsgboxContent, LV_SIZE_CONTENT); //60
    lv_obj_align(MsgboxContent, LV_ALIGN_TOP_LEFT, 29, 58);
    lv_label_set_long_mode(MsgboxContent, LV_LABEL_LONG_WRAP);
    lv_label_set_text(MsgboxContent, content);
    lv_obj_set_style_text_color(MsgboxContent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(MsgboxContent, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_update_layout(ErrorMsgboxbg); 
    lv_coord_t height = lv_obj_get_height(MsgboxContent);
    if (height > 60) //高度比原来高则扩展
    {    
        height -= 60;
        lv_obj_set_height(ErrorMsgboxbg, 165 + height + 10); //根据错误内容动态改变背景面板高度
    }
    
    ErrorMsgboxlabel1 = lv_label_create(ErrorMsgboxbg);
    lv_obj_set_width(ErrorMsgboxlabel1, LV_SIZE_CONTENT);
    lv_obj_set_height(ErrorMsgboxlabel1, LV_SIZE_CONTENT);
    lv_obj_align(ErrorMsgboxlabel1,  LV_ALIGN_BOTTOM_RIGHT, -20, -16);
    lv_label_set_long_mode(ErrorMsgboxlabel1, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ErrorMsgboxlabel1, btn1);
    lv_obj_set_style_text_color(ErrorMsgboxlabel1, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ErrorMsgboxlabel1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ErrorMsgboxlabel1, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ErrorMsgboxlabel1, LV_OBJ_FLAG_SCROLLABLE);   
    lv_obj_set_ext_click_area(ErrorMsgboxlabel1, 20);
    lv_obj_add_event_cb(ErrorMsgboxlabel1, ui_event_msgbtn1, LV_EVENT_ALL, msg);
    
    lv_obj_set_style_border_color(ErrorMsgboxlabel1, lv_color_hex(0x333435), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ErrorMsgboxlabel1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ErrorMsgboxlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ErrorMsgboxlabel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ErrorMsgboxlabel1, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ErrorMsgboxlabel1, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ErrorMsgboxlabel1, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_pad_all(ErrorMsgboxlabel1, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    ErrorMsgboxlabel2 = lv_label_create(ErrorMsgboxbg);
    lv_obj_set_width(ErrorMsgboxlabel2, LV_SIZE_CONTENT);
    lv_obj_set_height(ErrorMsgboxlabel2, LV_SIZE_CONTENT);
    lv_obj_set_style_border_color(ErrorMsgboxlabel2, lv_color_hex(0x333435), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ErrorMsgboxlabel2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ErrorMsgboxlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ErrorMsgboxlabel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ErrorMsgboxlabel2, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ErrorMsgboxlabel2, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ErrorMsgboxlabel2, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_pad_all(ErrorMsgboxlabel2, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    lv_obj_set_style_text_align(ErrorMsgboxlabel2, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ErrorMsgboxlabel2, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ErrorMsgboxlabel2, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_text(ErrorMsgboxlabel2, btn2);
    lv_obj_add_flag(ErrorMsgboxlabel2, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ErrorMsgboxlabel2, LV_OBJ_FLAG_SCROLLABLE);    
    // lv_obj_set_ext_click_area(ErrorMsgboxlabel2, 20);
    lv_obj_add_event_cb(ErrorMsgboxlabel2, ui_event_msgbtn2, LV_EVENT_ALL, msg);
    lv_obj_align_to(ErrorMsgboxlabel2, ErrorMsgboxlabel1, LV_ALIGN_OUT_LEFT_MID, -30, 0);


    msg->ErrorMsgbox = ErrorMsgbox;
    // msg->ErrorMsgboxImage1 = ErrorMsgboxImage1;
    // msg->ErrorMsgboxImage2 = ErrorMsgboxImage2;
    // msg->ErrorMsgboxImage3 = ErrorMsgboxImage3;
    // msg->ErrorMsgboxImage4 = ErrorMsgboxImage4;
    // msg->ErrorMsgboxImage5 = ErrorMsgboxImage5;
    msg->ErrorMsgboxbg = ErrorMsgboxbg;
    msg->MsgboxTitle = MsgboxTitle;
    msg->MsgboxContent = MsgboxContent;
    msg->ErrorMsgboxlabel1 = ErrorMsgboxlabel1;
    msg->ErrorMsgboxlabel2 = ErrorMsgboxlabel2;
    msg->errorcode = errorcode;
    // msg->error_content = error_content;
    snprintf(msg->error_content, sizeof(msg->error_content), "%s", content);

    if(current_error)
    {
        lv_obj_set_style_text_color(msg->MsgboxTitle, lv_color_hex(0xFF4949), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(msg->MsgboxContent, lv_color_hex(0xFF4949), LV_PART_MAIN | LV_STATE_DEFAULT);
        if(errorcode == 101 || errorcode == 103 || errorcode == 104 )
        {
            lv_obj_set_style_text_color(msg->MsgboxTitle, lv_color_hex(0xFFAB49), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(msg->MsgboxContent, lv_color_hex(0xFFAB49), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    if(current_tips)
    {
        lv_obj_set_style_text_color(msg->MsgboxTitle, lv_color_hex(0xFFAB49), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(msg->MsgboxContent, lv_color_hex(0xFFAB49), LV_PART_MAIN | LV_STATE_DEFAULT);
        if(errorcode == 508)
        {
            lv_obj_set_style_text_color(msg->MsgboxTitle, lv_color_hex(0xFF4949), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(msg->MsgboxContent, lv_color_hex(0xFF4949), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ErrorMsgbox, LV_OBJ_FLAG_HIDDEN);

    InitPopoutManager(&ErrorPopout, msg->ErrorMsgboxbg, ErrorMsgboxAddObjsToGroup);
    if (btn1 != NULL)
    {
        if (strlen(btn1) > 0)
        {
            ErrorPopout.obj1_flag = true;
            ErrorPopout.popout_focus_obj1 = msg->ErrorMsgboxlabel1;
        } 
        else
        {
            lv_obj_set_style_border_width(ErrorMsgboxlabel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    if (btn2 != NULL)
    {
        if (strlen(btn2) > 0)
        {
            ErrorPopout.obj2_flag = true;
            ErrorPopout.popout_focus_obj2 = msg->ErrorMsgboxlabel2;
        } 
        else
        {
            lv_obj_set_style_border_width(ErrorMsgboxlabel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    ManagePopoutFocus();
    // ErrorPopout.change_group_objs = ErrorMsgboxAddObjsToGroup;

    // ErrorMsgboxAddObjsToGroup();
    return msg;
}

void wait_response_timer_handler(lv_timer_t * timer)
{
    CrLogI("refresh the error page restart button");
    if(!selftestflag)
    LoadHomeNormalPageAndObjs(false);
        //LoadHomeNormalScreen();
    lv_obj_set_style_bg_opa(ui_MsgboxButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_MsgboxButton2,LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(ui_MsgboxButton1,LV_OBJ_FLAG_CLICKABLE);
    selftest_messagebox_close();
}

void error_btn1()
{
    CrLogI("don't upload and restart");
    set_printer_data(0x19,1,"2");
    set_printer_data(0x19,1,"1");
    set_printer_data(CONTROL_ERROR_MSG, 2, "0");//重置错误码状态
    //创建定时器，一定时间内不允许重复点击
    static lv_timer_cb_t wait_response_timer;
    wait_response_timer = lv_timer_create(wait_response_timer_handler, 1000 * 20, NULL);
    lv_timer_set_repeat_count(wait_response_timer,1);

    lv_obj_set_style_bg_opa(ui_MsgboxButton1, 150, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_MsgboxButton1,LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(ui_MsgboxButton2,LV_OBJ_FLAG_CLICKABLE);
}

void error_btn2()
{
    selftest_messagebox_close();
    set_printer_data(CONTROL_ERROR_MSG, 2, "0");//重置错误码状态
    if(system_state.CxyUserInfoState == 1)//有绑定信息
    {
        if (wifi_state == '1' || wire_net_state == '1')    //网络已连接
        {
            CrLogI("start upload log");
            start_selftest_upload = true;
            set_printer_data(CONTROL_MACHINE_LOG, 2, "2");
        }
        else
        {
            CrLogI("don't have network");
            create_msgbox(DontNetwork[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
        }
    }
    else
    {
        CrLogI("don't have cxyuserinfo");
        create_msgbox(DontCXYUserInfo[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
    }
}

void ui_event_msgbtn1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    ErrorMsg_t * user_data = lv_event_get_user_data(e);
    lv_obj_t * target = lv_event_get_target(e);
    void (*btns_callback[2])(void) = {&error_btn1, &error_btn2};
    if(event_code == LV_EVENT_CLICKED) {
        CrLogI("ui_event_msgbtn1");
        CrLogI("%d",user_data->errorcode);
        CrLogI("%s",user_data->error_content);
        if(current_error)   //当前是错误类型弹窗
        {
            if(user_data->errorcode == 101 || user_data->errorcode == 103 ||
               user_data->errorcode == 104 )//当前是错误类型弹窗并且是AI错误码
            {
                Error_message_delete(user_data);
                BackPrepage(true);
                set_printer_data(0x0f, 2, "3");
                set_printer_data(CONTROL_ERROR_MSG, 2, "0");//重置错误码状态
                return;
            }
            char temp[60] = {0};
            char content[200];
            uint8_t index = get_cur_language_index();
            int code = user_data->errorcode;
            // snprintf(content, 200, "key:%d\n%s", code,user_data->error_content);
            snprintf(content, 200, "%s", user_data->error_content);
            void (*btns_callback[2])(void) = {&error_btn1, &error_btn2};
            create_selftest_messagebox(Warning[index], content, Restart[index], UploadErrorTips1[index], btns_callback);
            Error_message_delete(user_data);
            //BackPrepage(true);
        }
        if(current_tips)   //当前是提示类型弹窗
        {
            if(user_data->errorcode == 508 )//当前是提示类型弹窗并且是内存告警错误码
            {
                //ui_change(PAGE_FILEMANAGE);
                LoadFileManageScreenAndObjs(false);
            }
            else
            {
                CrLogI("ui_event_msgbtn1 BackPrepage(true)");
                BackPrepage(true);
            }
            if(user_data->errorcode >= 2520 && user_data->errorcode <= 2535 && print_state != 1)//当前是应力片错误码且处于打印状态
            {
                Error_message_delete(user_data);
                BackPrepage(true);
                user_data = NULL;
                set_printer_data(0x0f, 2, "3");
                set_printer_data(CONTROL_ERROR_MSG, 2, "0");//重置错误码状态
                return;
            }
            Error_message_delete(user_data);
          
            set_printer_data(CONTROL_ERROR_MSG, 2, "0");//重置错误码状态
            user_data = NULL;
        }

    }
}

void ui_event_msgbtn2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    ErrorMsg_t * user_data = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(current_error)
        {
            if(user_data->errorcode == 101 || user_data->errorcode == 103 ||
               user_data->errorcode == 104)//当前是错误类型弹窗并且是AI错误码
            {
                set_printer_data(0x0f, 2, "1");
                Error_message_delete(user_data);
                BackPrepage(true);
                set_printer_data(CONTROL_ERROR_MSG, 2, "0");//重置错误码状态
                return;
            }
        }
        if(user_data->errorcode >= 2520 && user_data->errorcode <= 2535)//当前是应力片错误码
        {
            Error_message_delete(user_data);
            BackPrepage(true);
            user_data = NULL;
            set_printer_data(0x0f, 2, "1");
            set_printer_data(CONTROL_ERROR_MSG, 2, "0");//重置错误码状态
            return;
        }
        Error_message_delete(user_data);
        set_printer_data(CONTROL_ERROR_MSG, 2, "0");//重置错误码状态
        CrLogI("ui_event_msgbtn2 BackPrepage(true)");
        BackPrepage(true);
    }
}

// void ui_event_pageload(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     ErrorMsg_t * user_data = lv_event_get_user_data(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         CrLogI("change screen");
//         if(current_error)return ;
//         if(selftestflag)return;    //开机引导不允许页面跳转
//         if(target == user_data->ErrorMsgboxImage1)
//             if ( home_printing_is_printing_finished() )
//                 LoadHomeNormalScreen();
//             else
//                 LoadHomePrintingScreen();
//         if(target == user_data->ErrorMsgboxImage2)
//             LoadAxisMoveScreen();
//         if(target == user_data->ErrorMsgboxImage3)
//             LoadFileManageScreen();
//         if(target == user_data->ErrorMsgboxImage4)
//             LoadSettingsScreen();
//         if(target == user_data->ErrorMsgboxImage5)
//             LoadCustomerServiceScreen();
//         Error_message_delete(user_data);//后期可换成按钮发送事件
//     }
// }



void set_error_msg(int errorcode, int k1_errorcode, char * error_content)
{
    CrLogI("enter the errormsgbox.error code :%d,%d",errorcode, k1_errorcode);
    uint8_t index = get_cur_language_index();
    char title[50] = {0};
    char content[200] = {0};
    char btn1label[32] = {0};
    char btn2label[32] = {0};  
    
    //RecordObjBeforePopup();

    if(current_error && k1_errorcode != 0)   //  已有错误存在且新的错误码不是0直接忽略
    {
        CrLogI("exist error,exit");
        return;
    }

    if( k1_errorcode <= 200 && k1_errorcode > 0 )
    {
        current_error = true;
        current_tips = false;

    }
    else if( k1_errorcode > 200 && k1_errorcode <= 500 )
    {
        current_error = false;
        current_tips = true;
    }
    else
    {
        current_error = false;
        current_tips = true;
    }
    
    char tempbuff[20] = {0};
    snprintf(tempbuff, 20, "key:%d,",errorcode);
    strcat(content, tempbuff);
    switch (errorcode)
    {
        //未知错误
        case 0:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key000Content[index]);
            strcat(btn1label,ErrorBtnInfo[index]);
            strcat(btn2label,"");
            break;
        }
        case 1:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key000Content[index]);
            strcat(btn1label,ErrorBtnInfo[index]);
            strcat(btn2label,"");
            break;
        }

        //电机驱动异常
        case 2505:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Error001Content[index]);
            strcat(btn1label,ErrorBtnInfo[index]);
            strcat(btn2label,"");
            break;
        }

        //内部错误
        case 2060:
        case 2090:
        case 2091:
        case 2092:
        case 2093:
        case 2094:
        case 2295:
        case 2298:
        case 2299:
        case 2300:
        case 2301:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Error002Content[index]);
            strcat(btn1label,ErrorBtnInfo[index]);
            strcat(btn2label,"");
            break;
        }

        //通讯异常
        case 2506:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Error003Content[index]);
            strcat(btn1label,ErrorBtnInfo[index]);
            strcat(btn2label,"");
            break;
        }

        //与主MCU通讯异常
        case 2560:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2560Content[index]);
            strcat(btn1label,ErrorBtnInfo[index]);
            strcat(btn2label,"");
            break;
        }

        //与喷头MCU通讯异常
        case 2561:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2561Content[index]);
            strcat(btn1label,ErrorBtnInfo[index]);
            strcat(btn2label,"");
            break;
        }

        //与热床MCU通讯异常
        case 2562:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2562Content[index]);
            strcat(btn1label,ErrorBtnInfo[index]);
            strcat(btn2label,"");
            break;
        }

        //与rpi MCU通讯异常
        case 2563:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2563Content[index]);
            strcat(btn1label,ErrorBtnInfo[index]);
            strcat(btn2label,"");
            break;
        }

        //未按预期加热
        case 2507:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Error004Content[index]);
            strcat(btn1label,ErrorBtnInfo[index]);
            strcat(btn2label,"");
            break;
        }

        //喷头未按预期加热
        case 2564:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2564Content[index]);
            strcat(btn1label,ErrorBtnInfo[index]);
            strcat(btn2label,"");
            break;
        }

        //热床未按预期加热
        case 2565:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2565Content[index]);
            strcat(btn1label,ErrorBtnInfo[index]);
            strcat(btn2label,"");
            break;
        }

        //打印文件坐标异常
        case 2243:{
            if(errorcode == 2243 && print_state != 3)//不在打印状态
            {
                create_msgbox(Error800_2242_Content[index], NULL, 1000, lv_scr_act());
                set_printer_data(CONTROL_ERROR_MSG, 2, "0");
                return;
            }
            strcat(title,ErrorTitile1[index]);
            strcat(content,Error007Content[index]);
            strcat(btn1label,ErrorBtnInfo[index]);
            strcat(btn2label,"");
            break;
        }

        //振纹优化异常
        case 2056:
        case 2119:
        case 2312:
        case 2313:
        case 2314:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Error009Content[index]);
            strcat(btn1label,ErrorBtnInfo[index]);
            strcat(btn2label,"");
            break;
        }

        //风扇反馈异常
        case 109:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key109Content[index]);
            strcat(btn1label,ErrorBtnInfo[index]);
            strcat(btn2label,"");
            break;
        }

        //应力片调平故障
        case 2520:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2520Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }
        case 2521:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2521Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }
        case 2522:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2522Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }
        case 2523:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2523Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }
        case 2524:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2524Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }
        case 2525:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2525Content[index]);
            strcat(btn1label,ErrorBtnInfo[index]);
            strcat(btn2label,"");
            break;
        }
        case 2526:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2526Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }
        case 2527:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2527Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }
        case 2528:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2528Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }
        case 2529:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2529Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }
        case 2530:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2530Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }
        case 2531:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2531Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }
        case 2532:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2532Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }
        case 2533:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2533Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }
        case 2534:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2534Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }
        case 2535:{
            strcat(title,ErrorTitile1[index]);
            strcat(content,Key2535Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }

        //AI检测错误
        case 101:{
            strcat(title,ErrorTitile3[index]);
            strcat(content,Key101Content[index]);
            strcat(btn1label,ErrorBtnContinuePrint[index]);
            strcat(btn2label,ErrorBtnStopPrint[index]);
            break;
        }
        case 103:{
            strcat(title,ErrorTitile3[index]);
            strcat(content,Key103Content[index]);
            strcat(btn1label,ErrorBtnContinuePrint[index]);
            strcat(btn2label,ErrorBtnStopPrint[index]);
            break;
        }
        case 104:{
            strcat(title,ErrorTitile3[index]);
            strcat(content,Key104Content[index]);
            strcat(btn1label,ErrorBtnContinuePrint[index]);
            strcat(btn2label,ErrorBtnStopPrint[index]);
            break;
        }

        //传感器温度异常
        case 2509:
        case 2510:
        case 2511:
        case 2512:{
            strcat(title,ErrorTitile2[index]);
            strcat(content,Error201Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }

        //喉管风扇异常
        case 501:{
            strcat(title,ErrorTitile2[index]);
            strcat(content,Key501Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }

        //主板风扇异常
        case 502:{
            strcat(title,ErrorTitile2[index]);
            strcat(content,Key502Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }

        //AI检测异常（意面）
        case 500:{
            strcat(title,ErrorTitile3[index]);
            strcat(content,Key500Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }

        //AI检测异常（首层检测）
        case 503:{
            strcat(title,ErrorTitile3[index]);
            strcat(content,Key503Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }

        //当前文件不支持流量检测
        case 504:{
            strcat(title,ErrorTitile3[index]);
            strcat(content,Key504Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }

        ///z-Touch异常
        case 2502:
        case 2503:{
            strcat(title,ErrorTitile2[index]);
            strcat(content,Error207Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }

        //文件异常
        case 100:
        case 102:{
            strcat(title,ErrorTitile2[index]);
            strcat(content,Error208Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }

        //雷达连接异常
        case 505:{
            strcat(title,ErrorTitile3[index]);
            strcat(content,Key505Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }

        //雷达标定失败
        case 506:{
            strcat(title,ErrorTitile3[index]);
            strcat(content,Key506Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }

        //雷达偏移校准失败
        case 507:{
            strcat(title,ErrorTitile3[index]);
            strcat(content,Key507Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }

        //内存告警
        case 508:{
            strcat(title,ErrorTitile4[index]);
            char tempbuff[256] = {0};
            snprintf(tempbuff, 256, Key508Content[index], error_content);
            strcat(content,tempbuff);
            strcat(btn1label,ErrorBtnFileManagement[index]);
            strcat(btn2label,ErrorBtnFileIgnore[index]);
            break;
        }

        //轻提示错误
        case 2095:{
            create_msgbox(Error800Content[index], NULL, 1000, lv_scr_act());
            set_printer_data(CONTROL_ERROR_MSG, 2, "0");
            return;
        }
        case 2242:{
            create_msgbox(Error800_2242_Content[index], NULL, 1000, lv_scr_act());
            set_printer_data(CONTROL_ERROR_MSG, 2, "0");
            return;
        }
        case 2211:{
            create_msgbox(Error800_2211_Content[index], NULL, 1000, lv_scr_act());
            set_printer_data(CONTROL_ERROR_MSG, 2, "0");
            return;
        }

        case 2003:{
            // create_msgbox(Error801Content[index], NULL, 0, lv_scr_act());
            // machine_start_flag = true;
            CrLogI("error code is 2003");
            set_printer_data(CONTROL_ERROR_MSG, 2, "0");
            return;
        }

        default:{
            strcat(title,ErrorTitile2[index]);
            strcat(content,Error500Content[index]);
            strcat(btn1label,ErrorBtnConfirm[index]);
            strcat(btn2label,"");
            break;
        }

    }
    
    if(k1_errorcode <= 500 && k1_errorcode > 0)
    {
        //标题去掉E码
        // char tempbuff[20] = {0};
        // snprintf(tempbuff, 20, ":E%03d",k1_errorcode);
        // strcat(title, tempbuff);

        if(errorcode >= 2520 && errorcode <= 2535)//应力片错误代码需要特殊处理
        {
            if(print_state != 1)//不处于停止状态
            {
                memset(btn1label, 0, 32);
                memset(btn2label, 0, 32);
                strcat(btn1label,ErrorBtnContinuePrint[index]);
                strcat(btn2label,ErrorBtnStopPrint[index]);
            }
        }
        if(error_msg == NULL)
        {
            error_msg = Error_message_create(title, content, btn1label, btn2label, errorcode, error_content);
        }
        else
        {
            //先删除之前的提示栏再创建新的错误弹窗
            Error_message_delete(error_msg);
            error_msg = NULL;
            error_msg = Error_message_create(title, content, btn1label, btn2label, errorcode, error_content);
        }
    }
    if(k1_errorcode == 0)
    {
        if(error_msg != NULL)
        {
            CrLogI("2");
            CrLogI("set_error_msg BackPrepage(true)");
            BackPrepage(true);
            Error_message_delete(error_msg);
        }
    }
}

void wait_timerout_handle(lv_timer_t * timer)
{
    CrLogI("endstop wait animotion by timeout");
    lv_obj_add_flag(ui_waitAnimotion,LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(lv_layer_top(),LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_waitimg, LV_OBJ_FLAG_HIDDEN);
    
    waitAnimotionFlag = false;
    lv_indev_enable(enc_indev, true);
   
    ui_waittimer = NULL;
}

void wait_animmotion(bool flag)
{
    if (ui_waitAnimotion == NULL)
    {
        ui_waitAnimotion = lv_obj_create(lv_layer_top());
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        
        lv_obj_set_size(ui_waitAnimotion, 640, 480);
        lv_obj_add_style(ui_waitAnimotion, &style_cont_msgbox, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_waitAnimotion, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_waitAnimotion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

        //Write codes wait_spinner_1
        ui_waitimg = lv_gif_create(ui_waitAnimotion);
        lv_obj_set_width(ui_waitimg, LV_SIZE_CONTENT);
        lv_obj_set_height(ui_waitimg, LV_SIZE_CONTENT);
        lv_obj_align(ui_waitimg, LV_ALIGN_CENTER, 28, 0);
        
        lv_gif_set_src(ui_waitimg, &ui_img_wait_gif);
    }
    else
    {
        lv_obj_clear_flag(ui_waitAnimotion,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_waitimg, LV_OBJ_FLAG_HIDDEN);
    }
    
    lv_timer_t * ui_waittimer1  = NULL;
    if(flag)
    {
        CrLogI("start wait animotion");
        waitAnimotionFlag = true;
        lv_indev_enable(enc_indev, false);
        lv_obj_clear_flag(ui_waitAnimotion,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_waitimg, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
        ui_waittimer1 = lv_timer_create(wait_timerout_handle, 1000 * 10, NULL);
        lv_timer_set_repeat_count(ui_waittimer1, 1);

    }
    else
    {
        CrLogI("endstop wait animotion");
        // if(ui_waittimer1 != NULL)
        // {
        //     lv_timer_del(ui_waittimer1);
        //     CrLogI("delate a timer");
        // }
        lv_obj_add_flag(ui_waitAnimotion,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_waitimg, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(lv_layer_top(),LV_OBJ_FLAG_CLICKABLE);
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
        lv_indev_enable(enc_indev, true);
        CrLogI("endstop wait animotion22222");
    }
}

void wifi_wait_timerout_handle(lv_timer_t * timer)
{
    CrLogI("endstop wifi wait animotion by timeout");
    
    lv_obj_add_flag(ui_WifiWaitAnimotion,LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Wifiwaitimg, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(lv_layer_top(),LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
    lv_indev_enable(enc_indev, true);
    CrLogI("delate a timer");
}

void wifi_wait_animmotion(uint16_t time_s)
{
    if (ui_WifiWaitAnimotion == NULL)
    {
        ui_WifiWaitAnimotion = lv_obj_create(lv_layer_top());
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_size(ui_WifiWaitAnimotion, 640, 480);
        lv_obj_add_style(ui_WifiWaitAnimotion, &style_cont_msgbox, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_WifiWaitAnimotion, lv_color_hex(0xFFFFFF), LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_WifiWaitAnimotion, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

        ui_Wifiwaitimg = lv_gif_create(ui_WifiWaitAnimotion);
        lv_obj_set_width(ui_Wifiwaitimg, LV_SIZE_CONTENT);
        lv_obj_set_height(ui_Wifiwaitimg, LV_SIZE_CONTENT);

        lv_obj_align(ui_Wifiwaitimg, LV_ALIGN_CENTER, 28, 0);
        lv_gif_set_src(ui_Wifiwaitimg, &ui_img_wait_gif);
    }

    if (lv_obj_has_flag(ui_Wifiwaitimg, LV_OBJ_FLAG_HIDDEN))
    {
        lv_obj_clear_flag(ui_WifiWaitAnimotion,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_Wifiwaitimg, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
    }
    lv_timer_t * ui_waittimer2  = NULL;
    CrLogI("start wifi wait animotion");
    ui_waittimer2 = lv_timer_create(wifi_wait_timerout_handle, 1000 * time_s, NULL);
    lv_timer_set_repeat_count(ui_waittimer2, 1);
    CrLogI("create a timer");
    lv_indev_enable(enc_indev, false);
}

void redefine_label_size(lv_obj_t * widgets, lv_font_t * font, lv_coord_t letter_space, lv_coord_t line_space, lv_coord_t max_width, lv_text_flag_t flag)
{
    lv_point_t label_size;
    lv_txt_get_size(&label_size, lv_label_get_text(widgets), font, letter_space, line_space, max_width, flag);
    CrLogI("redefine the label size,width:%d, height:%d, content:%s",label_size.x, label_size.y, lv_label_get_text(widgets));
    lv_obj_set_width(widgets, label_size.x);
    lv_obj_set_height(widgets, label_size.y);
}

void redefine_widgets_size(lv_obj_t * widgets, lv_obj_t *new_widgets, lv_coord_t width_offset, lv_coord_t height_offset, lv_coord_t min_width, lv_coord_t min_height)
{
    lv_obj_update_layout(new_widgets);
    lv_coord_t width  = lv_obj_get_width(new_widgets);
    lv_coord_t height = lv_obj_get_height(new_widgets);

    if(width > min_width || (min_width - width) < 5)
    {
        width = width + width_offset * 2; //超过左右都需要一点空间
    }
    else
    {
        width = min_width;
    }
    
    if(height > min_height)//高度比原来高则扩展
    {
        height = height + height_offset * 2; //上下都需要一点空间
    }
    else
    {
        height = min_height;
    }

    CrLogI("redefine the widgets size,width:%d, height:%d",width, height);
    lv_obj_set_width(widgets, width);
    lv_obj_set_height(widgets, height);
}


void init_uploadlog_msg(void)
{
    //创建工单流水号弹窗
    Msgbox2Bg = lv_obj_create(lv_layer_top());
    lv_obj_set_width(Msgbox2Bg, 800);
    lv_obj_set_height(Msgbox2Bg, 480);
    lv_obj_set_x(Msgbox2Bg, 0);
    lv_obj_set_y(Msgbox2Bg, 0);
    lv_obj_set_style_radius(Msgbox2Bg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(Msgbox2Bg, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(Msgbox2Bg, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(Msgbox2Bg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(Msgbox2Bg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    Msgbox2 = lv_obj_create(Msgbox2Bg);
    lv_obj_set_width(Msgbox2, 456);
    lv_obj_set_height(Msgbox2, 435);
    lv_obj_set_x(Msgbox2, 172);
    lv_obj_set_y(Msgbox2, 20);
    lv_obj_clear_flag(Msgbox2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(Msgbox2, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(Msgbox2, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(Msgbox2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(Msgbox2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(Msgbox2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(Msgbox2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(Msgbox2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(Msgbox2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    Msgbox2label1 = lv_label_create(Msgbox2);
    lv_obj_set_width(Msgbox2label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(Msgbox2label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(Msgbox2label1, 0);
    lv_obj_set_y(Msgbox2label1, 22);
    lv_obj_set_align(Msgbox2label1, LV_ALIGN_TOP_MID);
    lv_label_set_text(Msgbox2label1, UploadErrorresult[get_cur_language_index()]);    

    lv_obj_set_style_text_color(Msgbox2label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(Msgbox2label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(Msgbox2label1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(Msgbox2label1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    Msgbox2label2 = lv_label_create(Msgbox2);
    lv_obj_set_width(Msgbox2label2, LV_SIZE_CONTENT);
    lv_obj_set_height(Msgbox2label2, LV_SIZE_CONTENT);
    lv_obj_set_x(Msgbox2label2, 0);
    lv_obj_set_y(Msgbox2label2, 62);
    lv_obj_set_align(Msgbox2label2, LV_ALIGN_TOP_MID);
    lv_label_set_text(Msgbox2label2, "请拍照留存");
    lv_obj_set_style_text_color(Msgbox2label2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(Msgbox2label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(Msgbox2label2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(Msgbox2label2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    Msgbox2label3 = lv_label_create(Msgbox2);
    lv_obj_set_width(Msgbox2label3, LV_SIZE_CONTENT);
    lv_obj_set_height(Msgbox2label3, LV_SIZE_CONTENT);
    lv_obj_set_x(Msgbox2label3, 0);
    lv_obj_set_y(Msgbox2label3, 106);
    lv_obj_set_align(Msgbox2label3, LV_ALIGN_TOP_MID);
    lv_label_set_text(Msgbox2label3, "工单号:xxxxxx");
    lv_obj_set_style_text_color(Msgbox2label3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(Msgbox2label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(Msgbox2label3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(Msgbox2label3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    Msgbox2label4 = lv_label_create(Msgbox2);
    lv_obj_set_width(Msgbox2label4, LV_SIZE_CONTENT);
    lv_obj_set_height(Msgbox2label4, LV_SIZE_CONTENT);
    lv_obj_set_x(Msgbox2label4, 0);
    lv_obj_set_y(Msgbox2label4, 141);
    lv_obj_set_align(Msgbox2label4, LV_ALIGN_TOP_MID);
    lv_label_set_text(Msgbox2label4, "客服邮箱:cs@creality.com");
    lv_obj_set_style_text_color(Msgbox2label4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(Msgbox2label4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(Msgbox2label4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(Msgbox2label4, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
   
    Msgbox2img1 = lv_qrcode_create(Msgbox2, 124, lv_color_hex(0xFFFFFF), lv_color_hex(0x000000));
    lv_obj_set_width(Msgbox2img1, 124);
    lv_obj_set_height(Msgbox2img1, 124);
    lv_obj_set_x(Msgbox2img1, 0);
    lv_obj_set_y(Msgbox2img1, 180);
    lv_obj_set_align(Msgbox2img1, LV_ALIGN_TOP_MID);

    Msgbox2label5 = lv_label_create(Msgbox2);
    lv_obj_set_width(Msgbox2label5, LV_SIZE_CONTENT);
    lv_obj_set_height(Msgbox2label5, LV_SIZE_CONTENT);
    lv_obj_set_x(Msgbox2label5, 0);
    lv_obj_set_y(Msgbox2label5, 306);
    lv_obj_set_align(Msgbox2label5, LV_ALIGN_TOP_MID);
    lv_label_set_text(Msgbox2label5, UploadErrorTips[get_cur_language_index()]);
    lv_obj_set_style_text_color(Msgbox2label5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(Msgbox2label5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(Msgbox2label5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(Msgbox2label5, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    Msgbox2Btn1 = lv_btn_create(Msgbox2);
    lv_obj_set_width(Msgbox2Btn1, 146);
    lv_obj_set_height(Msgbox2Btn1, 60);
    lv_obj_set_x(Msgbox2Btn1, 155);
    lv_obj_set_y(Msgbox2Btn1, 355);
    lv_obj_add_flag(Msgbox2Btn1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(Msgbox2Btn1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(Msgbox2Btn1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(Msgbox2Btn1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(Msgbox2Btn1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(Msgbox2Btn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(Msgbox2Btn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    Msgbox2Btnlabel1 = lv_label_create(Msgbox2Btn1);
    lv_obj_set_width(Msgbox2Btnlabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(Msgbox2Btnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(Msgbox2Btnlabel1, LV_ALIGN_CENTER);
    lv_label_set_text(Msgbox2Btnlabel1, Confirm[get_cur_language_index()]);
    lv_obj_set_style_text_color(Msgbox2Btnlabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(Msgbox2Btnlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(Msgbox2Btnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(Msgbox2Btn1, ui_event_Msgbox2Btn1, LV_EVENT_ALL, NULL);
    lv_obj_add_flag(Msgbox2Bg,LV_OBJ_FLAG_HIDDEN);     /// Flags
}

void create_uploadlog_msg()
{
    uint8_t language_index = get_cur_language_index();
    lv_label_set_text(Msgbox2label1, UploadErrorresult[language_index]);
    lv_label_set_text(Msgbox2label2, UploadErrorTips3[language_index]);
    lv_label_set_text(Msgbox2label3, UploadErrorTips4[language_index]);
    lv_label_set_text(Msgbox2label4, UploadErrorTips5[language_index]);
    lv_label_set_text(Msgbox2label5, UploadErrorTips[language_index]);
    lv_label_set_text(Msgbox2Btnlabel1, Confirm[language_index]);

    lv_obj_clear_flag(Msgbox2Bg,LV_OBJ_FLAG_HIDDEN);     /// Flags
}

int delete_uploadlog_msg()
{
    lv_obj_add_flag(Msgbox2Bg,LV_OBJ_FLAG_HIDDEN);     /// Flags
}

void ui_event_Msgbox2Btn1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    ErrorMsg_t * user_data = lv_event_get_user_data(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        CrLogI("change screen");
        if(selftestflag)    //开机引导过程中
        {
            _ui_screen_change(ui_SelftestTips, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        }
        lv_obj_add_flag(Msgbox2Bg, LV_OBJ_FLAG_HIDDEN);
    }
}

void selftest_refresh_upload_process(int state, int process, char * SN)
{
    if(!start_selftest_upload)return;
    CrLogI("refresh the upload log ,state is %d.",process);
    switch (state)
    {
        case 0:
        {
            if(process > 0)
            {
                char tempbuff[256] = {0};
                snprintf(tempbuff, 256, "%s : %d%%", LogUploadingMsg[get_cur_language_index()], process);
                create_msgbox(tempbuff, NULL, 0, lv_scr_act());
            }
            else
            {
                create_msgbox(LogUploadingMsg[get_cur_language_index()], NULL, 0, lv_scr_act());
            }
            break;
        }
        case 1:
        {
            start_selftest_upload = false;
            create_msgbox(LogUploadSuccessMsg[get_cur_language_index()], NULL, 1000, lv_scr_act());
            // create_uploadlog_msg();
            char msgbuff[100] = {0};
            snprintf(msgbuff, 100, "%s%s",UploadErrorTips4[get_cur_language_index()], SN);
            lv_label_set_text(Msgbox2label3, msgbuff);
             char tempbuff[256] = {0};
            if(init_uiconfiginfo.ServerOption == 1)//国内
                snprintf(tempbuff, 256, "%s","https://work.weixin.qq.com/u/vc6f86a40c32ec25e2?v=4.1.0.20669");
            else//国外
                snprintf(tempbuff, 256, "%s","https://www.facebook.com/crealitycustomerservice");
            lv_qrcode_update(Msgbox2img1, tempbuff, strlen(tempbuff));
            break;
        }
        case 2:
        {
            start_selftest_upload = false;
            create_msgbox(LogUploadFailedMsg[get_cur_language_index()], NULL, 2000, lv_scr_act());
            break;
        }
    }
}

char * get_errorcode_info(int errorcode)
{
    int index = get_cur_language_index();
    switch(errorcode)
    {
        //未知错误
        case 0:return Key000Content[index];
        case 1:return Key000Content[index];

        //电机驱动异常
        case 2505:return Error001Content[index];

        //内部错误
        case 2060:
        case 2090:
        case 2091:
        case 2092:
        case 2093:
        case 2094:
        case 2295:
        case 2298:
        case 2299:
        case 2300:
        case 2301:return Error002Content[index];

        //通讯异常
        case 2506:return Error003Content[index];

        //与主MCU通讯异常
        case 2560:return Key2560Content[index];

        //与喷头MCU通讯异常
        case 2561:return Key2561Content[index];

        //与热床MCU通讯异常
        case 2562:return Key2562Content[index];

        //与rpi MCU通讯异常
        case 2563:return Key2563Content[index];

        //喷头未按预期加热
        case 2564:return Key2564Content[index];

        //热床未按预期加热
        case 2565:return Key2565Content[index];

        //未按预期加热
        case 2507:return Error004Content[index];

        //打印文件坐标异常
        case 2243:return Error007Content[index];

        //振纹优化异常
        case 2056:
        case 2119:
        case 2312:
        case 2313:
        case 2314:return Error009Content[index];

        //风扇反馈异常
        case 109:return Key109Content[index];

        //应力片调平故障
        case 2520:return Key2520Content[index];
        case 2521:return Key2521Content[index];
        case 2522:return Key2522Content[index];
        case 2523:return Key2523Content[index];
        case 2524:return Key2524Content[index];
        case 2525:return Key2525Content[index];
        case 2526:return Key2526Content[index];
        case 2527:return Key2527Content[index];
        case 2528:return Key2528Content[index];
        case 2529:return Key2529Content[index];
        case 2530:return Key2530Content[index];
        case 2531:return Key2531Content[index];
        case 2532:return Key2532Content[index];
        case 2533:return Key2533Content[index];
        case 2534:return Key2534Content[index];
        case 2535:return Key2535Content[index];

        //AI检测错误
        case 101:return Key101Content[index];
        case 103:return Key103Content[index];
        case 104:return Key104Content[index];

        //传感器温度异常
        case 2509:
        case 2510:
        case 2511:
        case 2512:return Error201Content[index];

        //喉管风扇异常
        case 501:return Key501Content[index];

        //主板风扇异常
        case 502:return Key502Content[index];


        //AI检测异常（意面）
        case 500:return Key500Content[index];

        //AI检测异常（首层检测）
        case 503:return Key503Content[index];


        //当前文件不支持流量检测
        case 504:return Key504Content[index];


        ///z-Touch异常
        case 2502:
        case 2503:return Error207Content[index];

        //文件异常
        case 100:
        case 102:return Error208Content[index];

        //雷达连接异常
        case 505:return Key505Content[index];

        //雷达标定失败
        case 506:return Key506Content[index];

        //雷达偏移校准失败
        case 507:return Key507Content[index];

        //轻提示错误
        case 2095:return Error800Content[index];
        case 2242:return Error800_2242_Content[index];
        case 2211:return Error800_2211_Content[index];
        case 2003:return Error801Content[index];

        default:return Error500Content[index];
    }
}

/***********wifi网络连接页面及接口**************/
extern const char * * kb_map[4];
void create_wificonect_page(lv_obj_t * screen_page, const char * wifiname, bool isHiddenNetwork)
{
    CrLogI("load the network connect page");
    lv_obj_set_parent(ui_NetworkSettingPanel, screen_page);
    lv_textarea_set_text(ui_NetworkName_TextArea, wifiname);
    lv_btnmatrix_set_map(ui_NetworkSetting_Keyboard, kb_map[KEYBOARD_MODE_TEXT_LOWER]); //键盘默认小写
    keyboard_spec_flag = false;
    if(isHiddenNetwork)
    {
         lv_obj_clear_state(ui_NetworkPassw_TextArea, LV_STATE_FOCUSED); //清除密码输入区域光标闪烁
        //lv_obj_clear_state(ui_NetworkName_TextArea, LV_STATE_DISABLED);
       // lv_obj_add_flag(ui_NetworkName_TextArea, LV_OBJ_FLAG_CLICKABLE);
        if(!lv_obj_has_state(ui_NetworkName_TextArea, LV_STATE_FOCUSED))
            lv_obj_add_state(ui_NetworkName_TextArea, LV_STATE_FOCUSED);
    }
    else
    {
       // lv_obj_add_state(ui_NetworkName_TextArea, LV_STATE_DISABLED);
        //lv_obj_clear_flag(ui_NetworkName_TextArea, LV_OBJ_FLAG_CLICKABLE);
        if(!lv_obj_has_state(ui_NetworkPassw_TextArea, LV_STATE_FOCUSED))
            lv_obj_add_state(ui_NetworkPassw_TextArea, LV_STATE_FOCUSED);
        
    }
    lv_textarea_set_text(ui_NetworkPassw_TextArea,"");
    lv_obj_clear_flag(ui_NetworkSettingPanel, LV_OBJ_FLAG_HIDDEN);
}
/***********wifi网络连接页面及接口**************/

/***********打印完成弹窗*************/
void init_printcompleted_msg()
{
    //创建打印完成弹窗
    Msgbox3Bg = lv_obj_create(lv_layer_top());
    lv_obj_set_width(Msgbox3Bg, 800);
    lv_obj_set_height(Msgbox3Bg, 480);
    lv_obj_set_x(Msgbox3Bg, 0);
    lv_obj_set_y(Msgbox3Bg, 0);
    lv_obj_set_style_radius(Msgbox3Bg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(Msgbox3Bg, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(Msgbox3Bg, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(Msgbox3Bg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(Msgbox3Bg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    Msgbox3 = lv_obj_create(Msgbox3Bg);
    lv_obj_set_width(Msgbox3, 418);
    lv_obj_set_height(Msgbox3, 300);
    lv_obj_align(Msgbox3, LV_ALIGN_TOP_MID, 0, 80);
    lv_obj_clear_flag(Msgbox3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(Msgbox3, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(Msgbox3, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(Msgbox3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(Msgbox3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(Msgbox3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(Msgbox3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(Msgbox3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(Msgbox3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    Msgbox3img1 = lv_img_create(Msgbox3);
    lv_obj_set_width(Msgbox3img1, LV_SIZE_CONTENT);
    lv_obj_set_height(Msgbox3img1, LV_SIZE_CONTENT);
    lv_obj_align(Msgbox3img1, LV_ALIGN_TOP_MID, 0, 26);
    char tempbuff[256] = {0};
    snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "print_success.png");
    lv_img_set_src(Msgbox3img1, tempbuff);

    Msgbox3label1 = lv_label_create(Msgbox3);
    lv_obj_set_width(Msgbox3label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(Msgbox3label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_align(Msgbox3label1, LV_ALIGN_TOP_MID, 0, 126);
    lv_label_set_text(Msgbox3label1, UploadErrorresult[get_cur_language_index()]);    

    lv_obj_set_style_text_color(Msgbox3label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(Msgbox3label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(Msgbox3label1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(Msgbox3label1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    Msgbox3img2 = lv_img_create(Msgbox3);
    lv_obj_set_width(Msgbox3img2, LV_SIZE_CONTENT);
    lv_obj_set_height(Msgbox3img2, LV_SIZE_CONTENT);
    lv_obj_align(Msgbox3img2, LV_ALIGN_TOP_LEFT, 154, 168);
    lv_img_set_src(Msgbox3img2, &ui_img_home_used_png);

    Msgbox3label2 = lv_label_create(Msgbox3);
    lv_obj_set_width(Msgbox3label2, LV_SIZE_CONTENT);
    lv_obj_set_height(Msgbox3label2, LV_SIZE_CONTENT);
    lv_obj_align_to(Msgbox3label2, Msgbox3img2, LV_ALIGN_OUT_RIGHT_TOP, 6, -3);
    lv_label_set_text(Msgbox3label2, "05h05m");
    lv_obj_set_style_text_color(Msgbox3label2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(Msgbox3label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
     lv_obj_set_style_text_align(Msgbox3label2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(Msgbox3label2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    Msgbox3Btn1 = lv_btn_create(Msgbox3);
    lv_obj_set_width(Msgbox3Btn1, 146);
    lv_obj_set_height(Msgbox3Btn1, 60);
    lv_obj_align(Msgbox3Btn1, LV_ALIGN_TOP_MID, 0, 220);
    lv_obj_add_flag(Msgbox3Btn1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(Msgbox3Btn1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(Msgbox3Btn1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(Msgbox3Btn1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(Msgbox3Btn1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(Msgbox3Btn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(Msgbox3Btn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    Msgbox3Btnlabel1 = lv_label_create(Msgbox3Btn1);
    lv_obj_set_width(Msgbox3Btnlabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(Msgbox3Btnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(Msgbox3Btnlabel1, LV_ALIGN_CENTER);
    lv_label_set_text(Msgbox3Btnlabel1, Confirm[get_cur_language_index()]);
    lv_obj_set_style_text_color(Msgbox3Btnlabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(Msgbox3Btnlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(Msgbox3Btnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_flag(Msgbox3Bg,LV_OBJ_FLAG_HIDDEN);     /// Flags
}

void create_printcompleted_msg(int print_state, char * print_time, lv_event_cb_t event_cb)
{
    CrLogI("enter the printcompleted msg");
    lv_label_set_text(Msgbox3Btnlabel1, Confirm[get_cur_language_index()]);
    switch (print_state)//1:打印完成 2：打印终止 3：打印失败
    {
        case 1:lv_label_set_text(Msgbox3label1, PrintCompleted[get_cur_language_index()]);    
               lv_label_set_text(Msgbox3label2, print_time);
               lv_obj_add_event_cb(Msgbox3Btn1, event_cb, LV_EVENT_CLICKED, NULL);
               break;
        // case 2:break;
        // case 3:break;
        default:lv_label_set_text(Msgbox3label1, PrintCompleted[get_cur_language_index()]);    
                lv_label_set_text(Msgbox3label2, print_time);
                lv_obj_add_event_cb(Msgbox3Btn1, event_cb, LV_EVENT_CLICKED, NULL);
                break;
    }
    lv_obj_clear_flag(Msgbox3Bg,LV_OBJ_FLAG_HIDDEN);     /// Flags
}

void close_printcompleted_msg()
{
    lv_obj_remove_event_cb(Msgbox3Btn1, NULL);         //删除引用的事件
    lv_obj_add_flag(Msgbox3Bg,LV_OBJ_FLAG_HIDDEN);     /// Flags
}
/***********打印完成弹窗*************/

/***********隐私协议弹窗*************/
static lv_obj_t * the_last_page = NULL;

void PrivacyMsgbox_event_handler(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        int count = lv_obj_get_child_cnt(userdata);
        lv_obj_t * child = lv_obj_get_child(userdata, count - 1);
        if(target == lv_obj_get_child(child, 1))//label2
        {   
            close_PrivacyMessagebox();
            //EnterPrivacyPage();
        }
        if(target == lv_obj_get_child(child, 2))//btn1
        {
            close_PrivacyMessagebox();
        }
        if(target == lv_obj_get_child(child, 3))//btn2
        {
            //set_printer_data(0x06, 3, "q1");
            close_PrivacyMessagebox();
        }
    }
}

lv_obj_t * PrivacyMessagebox = NULL;
lv_obj_t * PrivacyMsgboxButton1 = NULL;
lv_obj_t * PrivacyMsgboxButton2 = NULL;
void close_PrivacyMessagebox()
{
    lv_obj_del(PrivacyMessagebox);
    DeinitPopoutManager(&BtnDialogPopout);
    PrivacyMessagebox = NULL;
    PrivacyMsgboxButton1 = NULL;
    PrivacyMsgboxButton2 = NULL;

    if (IsThereAnyPopout())
    {
        ManagePopoutFocus();
    }
    else
    {
        BackPrepage(true);
    }
}

void PrivacyMessageboxAddObjsToGroup(void)
{
    lv_group_focus_freeze(encoder_group, false); //用于解决导航按钮加冻结后解冻前，错误弹框无法聚焦的情况
    lv_group_remove_all_objs(encoder_group);

    if (BtnDialogPopout.obj1_flag)
        lv_group_add_obj(encoder_group, BtnDialogPopout.popout_focus_obj1);
    if (BtnDialogPopout.obj2_flag)
        lv_group_add_obj(encoder_group, BtnDialogPopout.popout_focus_obj2);
}

void create_PrivacyMessagebox(char *message, char *btn1label, char *btn2label, lv_event_cb_t btn1_event, lv_event_cb_t btn2_event)
{
    if (PrivacyMessagebox && !lv_obj_has_flag(PrivacyMessagebox, LV_OBJ_FLAG_HIDDEN))
    {
        return;
    }
    if (!IsThereAnyPopout())
    {
        RecordObjBeforePopup();
    }

    uint8_t language_index = get_cur_language_index();
    PrivacyMessagebox = lv_obj_create(lv_layer_top());
    lv_obj_set_width(PrivacyMessagebox, 640);
    lv_obj_set_height(PrivacyMessagebox, 480);
    lv_obj_clear_flag(PrivacyMessagebox, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(PrivacyMessagebox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(PrivacyMessagebox, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(PrivacyMessagebox, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(PrivacyMessagebox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(PrivacyMessagebox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * PrivacyMessagecontent = lv_obj_create(PrivacyMessagebox);
    lv_obj_set_width(PrivacyMessagecontent, 371);
    lv_obj_set_height(PrivacyMessagecontent, 285);
    // lv_obj_set_x(PrivacyMessagecontent, 133);
    // lv_obj_set_y(PrivacyMessagecontent, 36);
    lv_obj_set_align(PrivacyMessagecontent, LV_ALIGN_CENTER);
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
    lv_obj_align(PrivacyMsgboxlabel1, LV_ALIGN_TOP_MID, 0, 8);
    lv_label_set_long_mode(PrivacyMsgboxlabel1, LV_LABEL_LONG_SCROLL);
    lv_label_set_text(PrivacyMsgboxlabel1, KindTips[language_index]);
    lv_obj_set_style_text_color(PrivacyMsgboxlabel1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(PrivacyMsgboxlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(PrivacyMsgboxlabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(PrivacyMsgboxlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * PrivacyMsgboxlabel2 = lv_label_create(PrivacyMessagecontent);
    lv_obj_set_width(PrivacyMsgboxlabel2, 327);
    lv_obj_set_height(PrivacyMsgboxlabel2, LV_SIZE_CONTENT);
    lv_obj_align(PrivacyMsgboxlabel2, LV_ALIGN_TOP_MID, 0, 90);
    lv_label_set_long_mode(PrivacyMsgboxlabel2, LV_LABEL_LONG_DOT);
    lv_label_set_recolor(PrivacyMsgboxlabel2, true);
    lv_label_set_text(PrivacyMsgboxlabel2, message);
    lv_obj_add_flag(PrivacyMsgboxlabel2, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_set_style_text_color(PrivacyMsgboxlabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(PrivacyMsgboxlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(PrivacyMsgboxlabel2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(PrivacyMsgboxlabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    PrivacyMsgboxButton1 = lv_btn_create(PrivacyMessagecontent);
    lv_obj_set_width(PrivacyMsgboxButton1, 144);
    lv_obj_set_height(PrivacyMsgboxButton1, 56);
    lv_obj_set_x(PrivacyMsgboxButton1, 26);
    lv_obj_set_y(PrivacyMsgboxButton1, 221);
    lv_obj_add_flag(PrivacyMsgboxButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(PrivacyMsgboxButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(PrivacyMsgboxButton1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(PrivacyMsgboxButton1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(PrivacyMsgboxButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(PrivacyMsgboxButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(PrivacyMsgboxButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(PrivacyMsgboxButton1, lv_color_hex(0xFFFFFF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(PrivacyMsgboxButton1, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(PrivacyMsgboxButton1, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(PrivacyMsgboxButton1, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(PrivacyMsgboxButton1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    lv_obj_t * PrivacyMsgboxBtnlabel1 = lv_label_create(PrivacyMsgboxButton1);
    lv_obj_set_width(PrivacyMsgboxBtnlabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(PrivacyMsgboxBtnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(PrivacyMsgboxBtnlabel1, LV_ALIGN_CENTER);
    lv_label_set_text(PrivacyMsgboxBtnlabel1, btn1label);
    lv_obj_set_style_text_color(PrivacyMsgboxBtnlabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(PrivacyMsgboxBtnlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(PrivacyMsgboxBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    PrivacyMsgboxButton2 = lv_btn_create(PrivacyMessagecontent);
    lv_obj_set_width(PrivacyMsgboxButton2, 144);
    lv_obj_set_height(PrivacyMsgboxButton2, 56);
    lv_obj_set_x(PrivacyMsgboxButton2, 204);
    lv_obj_set_y(PrivacyMsgboxButton2, 221);
    lv_obj_add_flag(PrivacyMsgboxButton2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(PrivacyMsgboxButton2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(PrivacyMsgboxButton2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(PrivacyMsgboxButton2, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(PrivacyMsgboxButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(PrivacyMsgboxButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(PrivacyMsgboxButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(PrivacyMsgboxButton2, lv_color_hex(0xFFFFFF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(PrivacyMsgboxButton2, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(PrivacyMsgboxButton2, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(PrivacyMsgboxButton2, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(PrivacyMsgboxButton2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    lv_obj_t * PrivacyMsgboxBtnlabel2 = lv_label_create(PrivacyMsgboxButton2);
    lv_obj_set_width(PrivacyMsgboxBtnlabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(PrivacyMsgboxBtnlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(PrivacyMsgboxBtnlabel2, LV_ALIGN_CENTER);
    lv_label_set_text(PrivacyMsgboxBtnlabel2, btn2label);
    lv_obj_set_style_text_color(PrivacyMsgboxBtnlabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(PrivacyMsgboxBtnlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(PrivacyMsgboxBtnlabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    if( btn1_event != NULL )lv_obj_add_event_cb(PrivacyMsgboxButton1, btn1_event, LV_EVENT_ALL, PrivacyMsgboxButton1);
    if( btn2_event != NULL )lv_obj_add_event_cb(PrivacyMsgboxButton2, btn2_event, LV_EVENT_ALL, PrivacyMsgboxButton1);
    lv_obj_add_event_cb(PrivacyMsgboxButton1, PrivacyMsgbox_event_handler, LV_EVENT_ALL, PrivacyMessagebox);
    lv_obj_add_event_cb(PrivacyMsgboxButton2, PrivacyMsgbox_event_handler, LV_EVENT_ALL, PrivacyMessagebox);
    //lv_obj_add_event_cb(PrivacyMsgboxlabel2,  PrivacyMsgbox_event_handler, LV_EVENT_ALL, PrivacyMessagebox);

    InitPopoutManager(&BtnDialogPopout, PrivacyMessagebox, PrivacyMessageboxAddObjsToGroup);

    BtnDialogPopout.obj1_flag = true;
    BtnDialogPopout.popout_focus_obj1 = PrivacyMsgboxButton1;

    BtnDialogPopout.obj2_flag = true;
    BtnDialogPopout.popout_focus_obj2 = PrivacyMsgboxButton2;

    ManagePopoutFocus();
    
    CrLogI("Privacypage msgbox create success");
}

void EnterPrivacyPage()
{
    CrLogI("enter the Privacypage");
    the_last_page = lv_scr_act();
    _ui_screen_change(ui_SelftestPrivacyPolicy, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}

void QuitPrivacyPage()
{
    CrLogI("Quit the Privacypage");
    if(the_last_page)
    {
        _ui_screen_change(the_last_page, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        int index = get_cur_language_index();
        create_PrivacyMessagebox(PrivacyPolicyTips[index], NotAgree[index], Agree[index], NULL, NULL);
    }
    else
        LoadHomeNormalScreen();
    the_last_page = NULL;
}
/***********隐私协议弹窗*************/

/***********强制调平弹窗*************/
void msg_close()
{
    send_buzzer(0x01);
    selftest_messagebox_close();
}

void gotolevel()
{
    send_buzzer(0x01);
    selftest_messagebox_close();
    //_ui_screen_change(ui_Manualtest, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    LoadPage(ui_Manualtest, 1);
   // RemindUserToAgreePrivacyPolicy();
}


void RemindUserToAutolevel()
{
    CrLogI("tips user go to level");
    int language_index = get_cur_language_index();
    void (*btns_callback[2])(void) = {msg_close, &gotolevel};
    create_selftest_messagebox(KindTips[language_index], UpdataTips[language_index],Cancel[language_index], Confirm[language_index], btns_callback);
}
/***********强制调平弹窗*************/

/***********提醒用户查看隐私协议*************/

// void printing_recovery_file_print_again_callback(void)
// {
//     poweloss_flag = false;
//     send_set_start_print_recovery_file();
// }

// void printing_recovery_file_stop_print_callback(void)
// {
//     poweloss_flag = false;
//     send_set_stop_print_recovery_file();
// }

void RemindUserToAgreePrivacyPolicy()
{
    CrLogI("tips user go to the privacypolicy");
    int index = get_cur_language_index();
    if(init_uiconfiginfo.AgreePrivacyPolicy)
    {
        // char *btns[2] = {0};
        // char buff[20] = {0};
        // sprintf(buff, "%s%s", Resume[cur_language], Print[cur_language]);
        // btns[0] = Back[cur_language];
        // btns[1] = "查看";
        // void (*btns_callback[2])(void) = {&printing_recovery_file_print_again_callback, &printing_recovery_file_stop_print_callback};
        // create_custom_messagebox(KindTips[cur_language], PrivacyPolicyTips[index], btns, btns_callback, 2, true, false);
        create_PrivacyMessagebox(PrivacyPolicyTips[index], NotAgree[index], Agree[index], NULL, NULL);
    }
    else
        CrLogI("state:%d,user agree the privacypolicy, exit",init_uiconfiginfo.AgreePrivacyPolicy);
}
/***********提醒用户查看隐私协议*************/

void ErrorMsgboxAddObjsToGroup(void)
{
    lv_group_focus_freeze(encoder_group, false); //用于解决导航按钮加冻结后解冻前，错误弹框无法聚焦的情况
    lv_group_remove_all_objs(encoder_group);

    if (ErrorPopout.obj1_flag)
        lv_group_add_obj(encoder_group, ErrorMsgboxlabel1);
    if (ErrorPopout.obj2_flag)
        lv_group_add_obj(encoder_group, ErrorMsgboxlabel2);
}

// 消息弹框事件窗口
void create_selftest_messagebox(char *title, char *message, char *btn1label, char *btn2label, void(*btns_callback_array[2])(void))
{
    //创建前记录之前的聚焦对象，如果前面有弹框，那么就不用记录
    if (!IsThereAnyPopout())
    {
        RecordObjBeforePopup();
    }

    if(ui_SelftestMsgboxBg == NULL)
    {
        uint8_t language_index = get_cur_language_index();
        ui_SelftestMsgboxBg = lv_obj_create(lv_layer_top());
        lv_obj_set_width(ui_SelftestMsgboxBg, 640);
        lv_obj_set_height(ui_SelftestMsgboxBg, 480);
        lv_obj_clear_flag(ui_SelftestMsgboxBg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_SelftestMsgboxBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_SelftestMsgboxBg, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_SelftestMsgboxBg, 205, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(ui_SelftestMsgboxBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_SelftestMsgboxBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);

        ui_SelftestMsgbox = lv_obj_create(ui_SelftestMsgboxBg);
        lv_obj_set_width(ui_SelftestMsgbox, 371);
        lv_obj_set_height(ui_SelftestMsgbox, 285);
        // lv_obj_set_x(ui_SelftestMsgbox, 191);
        // lv_obj_set_y(ui_SelftestMsgbox, 79);
        lv_obj_set_align(ui_SelftestMsgbox, LV_ALIGN_CENTER);
        lv_obj_clear_flag(ui_SelftestMsgbox, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_SelftestMsgbox, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_SelftestMsgbox, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_SelftestMsgbox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(ui_SelftestMsgbox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_left(ui_SelftestMsgbox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_right(ui_SelftestMsgbox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_top(ui_SelftestMsgbox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_bottom(ui_SelftestMsgbox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_Msgboxlabel1 = lv_label_create(ui_SelftestMsgbox);
        lv_obj_set_width(ui_Msgboxlabel1, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_Msgboxlabel1, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_x(ui_Msgboxlabel1, 0);
        lv_obj_set_y(ui_Msgboxlabel1, 2);
        lv_obj_set_align(ui_Msgboxlabel1, LV_ALIGN_TOP_MID);
        lv_label_set_long_mode(ui_Msgboxlabel1, LV_LABEL_LONG_SCROLL);
        lv_label_set_text(ui_Msgboxlabel1, KindTips[language_index]);
        lv_obj_set_style_text_color(ui_Msgboxlabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_Msgboxlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_Msgboxlabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_Msgboxlabel1, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_Msgboxlabel2 = lv_label_create(ui_SelftestMsgbox);
        lv_obj_set_width(ui_Msgboxlabel2, 327);
        lv_obj_set_height(ui_Msgboxlabel2, 78);
        lv_obj_set_x(ui_Msgboxlabel2, 22);
        lv_obj_set_y(ui_Msgboxlabel2, 100);
        lv_label_set_long_mode(ui_Msgboxlabel2, LV_LABEL_LONG_DOT);
        lv_label_set_text(ui_Msgboxlabel2, "");
        lv_obj_set_style_text_color(ui_Msgboxlabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_Msgboxlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_Msgboxlabel2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_Msgboxlabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_MsgboxButton1 = lv_btn_create(ui_SelftestMsgbox);
        lv_obj_set_width(ui_MsgboxButton1, 140);
        lv_obj_set_height(ui_MsgboxButton1, 52);
        lv_obj_set_x(ui_MsgboxButton1, 30);
        lv_obj_set_y(ui_MsgboxButton1, 221);
        lv_obj_add_flag(ui_MsgboxButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_MsgboxButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_MsgboxButton1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_MsgboxButton1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_MsgboxButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_MsgboxButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_MsgboxButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(ui_MsgboxButton1, lv_color_hex(0xB0F1FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_border_opa(ui_MsgboxButton1, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_border_width(ui_MsgboxButton1, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_outline_pad(ui_MsgboxButton1, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_outline_color(ui_MsgboxButton1, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

        ui_MsgboxBtnlabel1 = lv_label_create(ui_MsgboxButton1);
        lv_obj_set_width(ui_MsgboxBtnlabel1, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_MsgboxBtnlabel1, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_align(ui_MsgboxBtnlabel1, LV_ALIGN_CENTER);
        lv_label_set_text(ui_MsgboxBtnlabel1, Cancel[language_index]);
        lv_obj_set_style_text_color(ui_MsgboxBtnlabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_MsgboxBtnlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_MsgboxBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_MsgboxButton2 = lv_btn_create(ui_SelftestMsgbox);
        lv_obj_set_width(ui_MsgboxButton2, 140);
        lv_obj_set_height(ui_MsgboxButton2, 52);
        lv_obj_set_x(ui_MsgboxButton2, 202);
        lv_obj_set_y(ui_MsgboxButton2, 221);
        lv_obj_add_flag(ui_MsgboxButton2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_MsgboxButton2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_MsgboxButton2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_MsgboxButton2, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_MsgboxButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_MsgboxButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_MsgboxButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(ui_MsgboxButton2, lv_color_hex(0xB0F1FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_border_opa(ui_MsgboxButton2, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_border_width(ui_MsgboxButton2, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_outline_pad(ui_MsgboxButton2, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_outline_color(ui_MsgboxButton2, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

        ui_MsgboxBtnlabel2 = lv_label_create(ui_MsgboxButton2);
        lv_obj_set_width(ui_MsgboxBtnlabel2, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_MsgboxBtnlabel2, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_align(ui_MsgboxBtnlabel2, LV_ALIGN_CENTER);
        lv_label_set_text(ui_MsgboxBtnlabel2, SaveArray[language_index]);
        lv_obj_set_style_text_color(ui_MsgboxBtnlabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_MsgboxBtnlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_MsgboxBtnlabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        
        lv_obj_add_event_cb(ui_MsgboxButton1, messagebox_btnclick_event_handler, LV_EVENT_ALL, "1");
        lv_obj_add_event_cb(ui_MsgboxButton2, messagebox_btnclick_event_handler, LV_EVENT_ALL, "2");
        CrLogI("Lower msgbox priority1");
    }
    else
    {
        if(lv_obj_has_flag(ui_SelftestMsgboxBg,LV_OBJ_FLAG_HIDDEN))
        {
            lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
            lv_obj_clear_flag(ui_SelftestMsgboxBg, LV_OBJ_FLAG_HIDDEN);     /// Flags  
            CrLogI("cancle the msgbox hidden!");
        }
        else
        {
            CrLogI("msgbox exists,quit!");
            return;
        }

    }
    lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
    // lv_obj_move_to_index(ui_ScreenoffPanel1, -1);
    if ( ui_Msgboxlabel1 )
    {
        if ( title && strlen(title) )
            lv_label_set_text(ui_Msgboxlabel1, title);
        else
            lv_label_set_text(ui_Msgboxlabel1, "");
    }

    if ( ui_Msgboxlabel2 )
    {
        if ( message && strlen(message) )
        {
            lv_obj_clear_flag(ui_Msgboxlabel2, LV_OBJ_FLAG_HIDDEN);     /// Flags
            lv_label_set_text(ui_Msgboxlabel2, message);  
        }
        else 
            lv_obj_add_flag(ui_Msgboxlabel2, LV_OBJ_FLAG_HIDDEN);     /// Flags
    }
    if(btn2label == NULL || btn1label == NULL)
    {
        lv_obj_add_flag(ui_MsgboxButton1, LV_OBJ_FLAG_HIDDEN);     /// Flags
        lv_obj_align(ui_MsgboxButton2,LV_ALIGN_TOP_MID,0,220);
    }
    else
    {
        lv_obj_align(ui_MsgboxButton1,LV_ALIGN_TOP_LEFT,30,221);
        lv_obj_align(ui_MsgboxButton2,LV_ALIGN_TOP_LEFT,202,221);
    }
    if ( ui_MsgboxBtnlabel1 )
    {
        if ( btn1label && strlen(btn1label) )
        {

            lv_obj_clear_flag(ui_MsgboxButton1, LV_OBJ_FLAG_HIDDEN);     /// Flags
            lv_label_set_text(ui_MsgboxBtnlabel1, btn1label);  
            redefine_label_size(ui_MsgboxBtnlabel1, lv_font24.font, 0, 0, 140, 0);
            lv_obj_update_layout(ui_MsgboxButton1);

            redefine_widgets_size(ui_MsgboxButton1, ui_MsgboxBtnlabel1, 2, 0, 140, 52);
        }
        else 
        {
            lv_obj_add_flag(ui_MsgboxButton1, LV_OBJ_FLAG_HIDDEN);     /// Flags
            lv_obj_align(ui_MsgboxButton2,LV_ALIGN_TOP_MID,0,220);
        }
    }
    if ( ui_MsgboxBtnlabel2 )
    {
        if ( btn2label && strlen(btn2label) )
        {
            
            lv_obj_clear_flag(ui_MsgboxButton2, LV_OBJ_FLAG_HIDDEN);     /// Flags
            lv_label_set_text(ui_MsgboxBtnlabel2, btn2label); 
            redefine_label_size(ui_MsgboxBtnlabel2, lv_font24.font, 0, 0, 140, 0);
            lv_obj_update_layout(ui_MsgboxButton2);

            redefine_widgets_size(ui_MsgboxButton2, ui_MsgboxBtnlabel2, 2, 0, 140, 52);
        }
        else
        {
            lv_obj_add_flag(ui_MsgboxButton2, LV_OBJ_FLAG_HIDDEN);     /// Flags
            lv_obj_align(ui_MsgboxButton1,LV_ALIGN_TOP_MID,0,220);
        }
    }
    //SelftestMsgboxAddObjsToGroup(btn1label, btn2label);
    for(int i = 0; i < 2; i++)
    {
        if ( btns_callback_array && btns_callback_array[i] )
            messagebox_btn_callback[i] = btns_callback_array[i];
        else
            messagebox_btn_callback[i] = NULL;
    }

    InitPopoutManager(&BtnDialogPopout, ui_SelftestMsgboxBg, SelftestMsgboxAddObjsToGroup);

    if (btn1label && strlen(btn1label))
    {
        BtnDialogPopout.obj1_flag = true;
        BtnDialogPopout.popout_focus_obj1 = ui_MsgboxButton1;
    }
    if (btn2label && strlen(btn2label))
    {
        BtnDialogPopout.obj2_flag = true;
        BtnDialogPopout.popout_focus_obj2 = ui_MsgboxButton2;
    }

    //弹框聚焦对象处理
    ManagePopoutFocus();
}

void messagebox_btnclick_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            char * userdata = lv_event_get_user_data(e);
            CrLogI("messagebox_btnclick_event_handler BackPrepage(true)");
            BackPrepage(true);
            switch (userdata[0])
            {
            case '1':
                if ( messagebox_btn_callback[0] )
                    messagebox_btn_callback[0]();
                break;
            case '2':
                if ( messagebox_btn_callback[1] )
                    messagebox_btn_callback[1]();
                break;
            default:
                break;
            }
        }
        break;
        default:
		break;
	}
}

void selftest_messagebox_close()
{
    DeinitPopoutManager(&BtnDialogPopout);
    lv_obj_add_flag(ui_SelftestMsgboxBg, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);

    if (IsThereAnyPopout())
    {
        ManagePopoutFocus();
    }
}

void SelftestMsgboxAddObjsToGroup()
{
    lv_group_remove_all_objs(encoder_group);
    // lv_indev_set_group(enc_indev, NULL); 
    // lv_indev_set_group(enc_indev, encoder_group); //关联组
    if (!lv_obj_has_flag(ui_MsgboxButton1, LV_OBJ_FLAG_HIDDEN))
    {
        lv_group_add_obj(encoder_group, ui_MsgboxButton1);
    }
    if (!lv_obj_has_flag(ui_MsgboxButton2, LV_OBJ_FLAG_HIDDEN))
    {
        lv_group_add_obj(encoder_group, ui_MsgboxButton2);
    }
    
}