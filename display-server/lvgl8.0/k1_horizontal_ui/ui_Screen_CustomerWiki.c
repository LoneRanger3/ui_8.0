#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "mult_language.h"

lv_obj_t * ui_CustomerWiki;
lv_obj_t * ui_CustomerWikiPanel1;
lv_obj_t * ui_CustomerWikiImage1;
lv_obj_t * ui_CustomerWikiImage2;
lv_obj_t * ui_CustomerWikiImage3;
lv_obj_t * ui_CustomerWikiImage4;
lv_obj_t * ui_CustomerWikiImage5;
lv_obj_t * ui_CustomerWikiPanel2;
lv_obj_t * ui_CustomerWikiPanel3;
lv_obj_t * ui_CustomerWikiTitle;
lv_obj_t * ui_CustomerWikiLabel1;
lv_obj_t * ui_CustomerWikiButton1;
lv_obj_t * ui_CustomerWikiBtnlabel1;
lv_obj_t * ui_CustomerWikiLabel2;
lv_obj_t * ui_CustomerWikiImage6;

void ui_event_CustomerWiki(lv_event_t * e);
void ui_event_CustomerWikiButton1(lv_event_t * e);
void ui_event_CustomerWikiImage(lv_event_t * e);

void ui_CustomerWiki_screen_init(void)
{
    ui_CustomerWiki = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_CustomerWiki, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    uint8_t language_index = get_cur_language_index();
    ui_CustomerWikiPanel1 = lv_obj_create(ui_CustomerWiki);
    lv_obj_set_width(ui_CustomerWikiPanel1, 80);
    lv_obj_set_height(ui_CustomerWikiPanel1, 480);
    lv_obj_clear_flag(ui_CustomerWikiPanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerWikiPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CustomerWikiPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CustomerWikiPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CustomerWikiPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CustomerWikiPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomerWikiPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_CustomerWikiPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_CustomerWikiPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_CustomerWikiPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_CustomerWikiPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerWikiImage1 = lv_img_create(ui_CustomerWikiPanel1);
    lv_img_set_src(ui_CustomerWikiImage1, &ui_img_pagehome_png);
    lv_obj_set_width(ui_CustomerWikiImage1, 80);
    lv_obj_set_height(ui_CustomerWikiImage1, 96);
    lv_obj_add_flag(ui_CustomerWikiImage1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CustomerWikiImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerWikiImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerWikiImage2 = lv_img_create(ui_CustomerWikiPanel1);
    lv_img_set_src(ui_CustomerWikiImage2, &ui_img_pagemove_png);
    lv_obj_set_width(ui_CustomerWikiImage2, 80);
    lv_obj_set_height(ui_CustomerWikiImage2, 96);
    lv_obj_set_x(ui_CustomerWikiImage2, 0);
    lv_obj_set_y(ui_CustomerWikiImage2, 96);
    lv_obj_add_flag(ui_CustomerWikiImage2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CustomerWikiImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerWikiImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomerWikiImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerWikiImage3 = lv_img_create(ui_CustomerWikiPanel1);
    lv_img_set_src(ui_CustomerWikiImage3, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_CustomerWikiImage3, 80);
    lv_obj_set_height(ui_CustomerWikiImage3, 96);
    lv_obj_set_x(ui_CustomerWikiImage3, 0);
    lv_obj_set_y(ui_CustomerWikiImage3, 192);
    lv_obj_add_flag(ui_CustomerWikiImage3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CustomerWikiImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerWikiImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomerWikiImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerWikiImage4 = lv_img_create(ui_CustomerWikiPanel1);
    lv_img_set_src(ui_CustomerWikiImage4, &ui_img_pagesetting_png);
    lv_obj_set_width(ui_CustomerWikiImage4, 80);
    lv_obj_set_height(ui_CustomerWikiImage4, 96);
    lv_obj_set_x(ui_CustomerWikiImage4, 0);
    lv_obj_set_y(ui_CustomerWikiImage4, 288);
    lv_obj_add_flag(ui_CustomerWikiImage4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CustomerWikiImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerWikiImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomerWikiImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerWikiImage5 = lv_img_create(ui_CustomerWikiPanel1);
    lv_img_set_src(ui_CustomerWikiImage5, &ui_img_pagereserveselected_png);
    lv_obj_set_width(ui_CustomerWikiImage5, 80);
    lv_obj_set_height(ui_CustomerWikiImage5, 96);
    lv_obj_set_x(ui_CustomerWikiImage5, 0);
    lv_obj_set_y(ui_CustomerWikiImage5, 384);
    lv_obj_add_flag(ui_CustomerWikiImage5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CustomerWikiImage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerWikiImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomerWikiImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_CustomerWikiImage1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_CustomerWikiImage2, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_CustomerWikiImage3, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_CustomerWikiImage4, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_CustomerWikiImage5, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_CustomerWikiPanel2 = lv_obj_create(ui_CustomerWiki);
    lv_obj_set_width(ui_CustomerWikiPanel2, 720);
    lv_obj_set_height(ui_CustomerWikiPanel2, 480);
    lv_obj_set_x(ui_CustomerWikiPanel2, 80);
    lv_obj_set_y(ui_CustomerWikiPanel2, 0);
    lv_obj_clear_flag(ui_CustomerWikiPanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerWikiPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CustomerWikiPanel2, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CustomerWikiPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CustomerWikiPanel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CustomerWikiPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomerWikiPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_CustomerWikiPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_CustomerWikiPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_CustomerWikiPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_CustomerWikiPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerWikiPanel3 = lv_obj_create(ui_CustomerWikiPanel2);
    lv_obj_set_width(ui_CustomerWikiPanel3, 696);
    lv_obj_set_height(ui_CustomerWikiPanel3, 456);
    lv_obj_set_align(ui_CustomerWikiPanel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_CustomerWikiPanel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerWikiPanel3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CustomerWikiPanel3, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CustomerWikiPanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomerWikiPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_CustomerWikiPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_CustomerWikiPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_CustomerWikiPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_CustomerWikiPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerWikiTitle = lv_obj_create(ui_CustomerWikiPanel3);
    lv_obj_set_width(ui_CustomerWikiTitle, 665);
    lv_obj_set_height(ui_CustomerWikiTitle, 65);
    lv_obj_set_x(ui_CustomerWikiTitle, 10);
    lv_obj_set_y(ui_CustomerWikiTitle, 0);
    lv_obj_clear_flag(ui_CustomerWikiTitle, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerWikiTitle, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CustomerWikiTitle, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CustomerWikiTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CustomerWikiTitle, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CustomerWikiTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomerWikiTitle, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_CustomerWikiTitle, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_CustomerWikiTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_CustomerWikiTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_CustomerWikiTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_CustomerWikiTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerWikiLabel1 = lv_label_create(ui_CustomerWikiTitle);
    lv_obj_set_width(ui_CustomerWikiLabel1, 600);
    lv_obj_set_height(ui_CustomerWikiLabel1, 28);
    lv_obj_set_x(ui_CustomerWikiLabel1, 15);
    lv_obj_set_y(ui_CustomerWikiLabel1, 0);
    lv_obj_set_align(ui_CustomerWikiLabel1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_CustomerWikiLabel1, "在线说明书");
    lv_obj_set_style_text_color(ui_CustomerWikiLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CustomerWikiLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CustomerWikiLabel1, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerWikiButton1 = lv_btn_create(ui_CustomerWikiPanel3);
    lv_obj_set_width(ui_CustomerWikiButton1, 116);
    lv_obj_set_height(ui_CustomerWikiButton1, 60);
    lv_obj_set_x(ui_CustomerWikiButton1, 560);
    lv_obj_set_y(ui_CustomerWikiButton1, 381);
    lv_obj_add_flag(ui_CustomerWikiButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_CustomerWikiButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerWikiButton1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CustomerWikiButton1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CustomerWikiButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_CustomerWikiButton1, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_CustomerWikiButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_CustomerWikiButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_CustomerWikiButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_CustomerWikiButton1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CustomerWikiButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CustomerWikiButton1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerWikiBtnlabel1 = lv_label_create(ui_CustomerWikiButton1);
    lv_obj_set_width(ui_CustomerWikiBtnlabel1, lv_pct(100));
    lv_obj_set_height(ui_CustomerWikiBtnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_CustomerWikiBtnlabel1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_CustomerWikiBtnlabel1, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_CustomerWikiBtnlabel1, Back[language_index]);
    lv_obj_set_style_text_align(ui_CustomerWikiBtnlabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CustomerWikiBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerWikiLabel2 = lv_label_create(ui_CustomerWikiPanel3);
    lv_obj_set_width(ui_CustomerWikiLabel2, 600);
    lv_obj_set_height(ui_CustomerWikiLabel2, 60);
    lv_obj_set_x(ui_CustomerWikiLabel2, 25);
    lv_obj_set_y(ui_CustomerWikiLabel2, 87);
    lv_label_set_long_mode(ui_CustomerWikiLabel2, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_CustomerWikiLabel2, "请用手机扫码查看在线说明书");
    lv_obj_set_style_text_color(ui_CustomerWikiLabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CustomerWikiLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CustomerWikiLabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerWikiImage6 = lv_qrcode_create(ui_CustomerWikiPanel3, 160, lv_color_hex(0xFFFFFF), lv_color_hex(0x000000));
    lv_obj_set_width(ui_CustomerWikiImage6, 160);
    lv_obj_set_height(ui_CustomerWikiImage6, 160);
    lv_obj_set_x(ui_CustomerWikiImage6, 0);
    lv_obj_set_y(ui_CustomerWikiImage6, 40);
    lv_obj_set_align(ui_CustomerWikiImage6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_CustomerWikiImage6, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CustomerWikiImage6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_CustomerWikiButton1, ui_event_CustomerWikiButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CustomerWiki, ui_event_CustomerWiki, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CustomerWikiImage1, ui_event_CustomerWikiImage, LV_EVENT_ALL, ui_CustomerWikiImage1);
    lv_obj_add_event_cb(ui_CustomerWikiImage2, ui_event_CustomerWikiImage, LV_EVENT_ALL, ui_CustomerWikiImage2);
    lv_obj_add_event_cb(ui_CustomerWikiImage3, ui_event_CustomerWikiImage, LV_EVENT_ALL, ui_CustomerWikiImage3);
    lv_obj_add_event_cb(ui_CustomerWikiImage4, ui_event_CustomerWikiImage, LV_EVENT_ALL, ui_CustomerWikiImage4);
    lv_obj_add_event_cb(ui_CustomerWikiImage5, ui_event_CustomerWikiImage, LV_EVENT_ALL, ui_CustomerWikiImage5);

}

void ui_event_CustomerWikiButton1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadCustomerServiceScreen();
        // _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_CustomerWiki(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        //请求二维码图片
        // CrLogI("Request a QR code image.");
        // //get_printer_data(0x15,1,"\0");
        // send_get_creality_cloud_qrcode_cmd();
        char temp[256] = {0};
        switch(UIType)
        {
            case CR_K1:{
                if(get_cur_language_index() == 0)//中文
                {
                    snprintf(temp, 256, "https://www.crealitycloud.cn/product/details/644a32275abbb0be0651c9ed");
                }
                else//国外
                {
                    snprintf(temp, 256, "https://www.crealitycloud.com/product/details/644a3313b508e0e6e4f5d884");
                }
                break;
            }
            case CR_K1_Max:{
                snprintf(temp, 256, "https://www.crealitycloud.com/product");
                break;
            }
        }
        
        lv_qrcode_update(ui_CustomerWikiImage6, temp, strlen(temp));
        // lv_obj_center(ui_CustomerWikiImage6);
    }
}

void ui_event_CustomerWikiImage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        if(target == ui_CustomerWikiImage1)
            if ( home_printing_is_printing_finished() )
                LoadHomeNormalScreen();
            else
                LoadHomePrintingScreen();
        if(target == ui_CustomerWikiImage2)LoadAxisMoveScreen();
        if(target == ui_CustomerWikiImage3)LoadFileManageScreen();
        if(target == ui_CustomerWikiImage4)LoadSettingsScreen();
    }
}

void refresh_CustomerWiki_page(char *src)
{
    if(src != NULL)
    {
        char buff[258] = {0};
        buff[0] = PNG_DRV_LETTER;
        strncpy(buff + 1, src, sizeof(buff) - 2);
        lv_img_set_src(ui_CustomerWikiImage6, buff);
    }
}

void Customerwiki_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_CustomerWikiLabel1 )
        lv_label_set_text(ui_CustomerWikiLabel1, OnlineManual[language_index]);
    if ( ui_CustomerWikiLabel2 )
        lv_label_set_text(ui_CustomerWikiLabel2, WikiTips[language_index]);
    if ( ui_CustomerWikiBtnlabel1 )
        lv_label_set_text(ui_CustomerWikiBtnlabel1, Back[language_index]);
}