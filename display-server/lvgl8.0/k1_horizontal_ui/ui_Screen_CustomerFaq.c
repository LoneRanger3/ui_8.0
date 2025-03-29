#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "mult_language.h"

lv_obj_t * ui_CustomerFaq;
lv_obj_t * ui_CustomerFaqPanel1;
lv_obj_t * ui_CustomerFaqImage1;
lv_obj_t * ui_CustomerFaqImage2;
lv_obj_t * ui_CustomerFaqImage3;
lv_obj_t * ui_CustomerFaqImage4;
lv_obj_t * ui_CustomerFaqImage5;
lv_obj_t * ui_CustomerFaqPanel2;
lv_obj_t * ui_CustomerFaqPanel3;
lv_obj_t * ui_CustomerFaqTitle;
lv_obj_t * ui_CustomerFaqLabel1;
lv_obj_t * ui_CustomerFaqButton1;
lv_obj_t * ui_CustomerFaqBtnlabel1;
lv_obj_t * ui_CustomerFaqLabel2;
lv_obj_t * ui_CustomerFaqImage6;

void ui_event_CustomerFaq(lv_event_t * e);
void ui_event_CustomerFaqButton1(lv_event_t * e);
void ui_event_CustomerFaqImage(lv_event_t * e);

void ui_CustomerFaq_screen_init(void)
{
    ui_CustomerFaq = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_CustomerFaq, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    uint8_t language_index = get_cur_language_index();
    ui_CustomerFaqPanel1 = lv_obj_create(ui_CustomerFaq);
    lv_obj_set_width(ui_CustomerFaqPanel1, 80);
    lv_obj_set_height(ui_CustomerFaqPanel1, 480);
    lv_obj_clear_flag(ui_CustomerFaqPanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerFaqPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CustomerFaqPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CustomerFaqPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CustomerFaqPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CustomerFaqPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomerFaqPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_CustomerFaqPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_CustomerFaqPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_CustomerFaqPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_CustomerFaqPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerFaqImage1 = lv_img_create(ui_CustomerFaqPanel1);
    lv_img_set_src(ui_CustomerFaqImage1, &ui_img_pagehome_png);
    lv_obj_set_width(ui_CustomerFaqImage1, 80);
    lv_obj_set_height(ui_CustomerFaqImage1, 96);
    lv_obj_add_flag(ui_CustomerFaqImage1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CustomerFaqImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerFaqImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerFaqImage2 = lv_img_create(ui_CustomerFaqPanel1);
    lv_img_set_src(ui_CustomerFaqImage2, &ui_img_pagemove_png);
    lv_obj_set_width(ui_CustomerFaqImage2, 80);
    lv_obj_set_height(ui_CustomerFaqImage2, 96);
    lv_obj_set_x(ui_CustomerFaqImage2, 0);
    lv_obj_set_y(ui_CustomerFaqImage2, 96);
    lv_obj_add_flag(ui_CustomerFaqImage2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CustomerFaqImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerFaqImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomerFaqImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerFaqImage3 = lv_img_create(ui_CustomerFaqPanel1);
    lv_img_set_src(ui_CustomerFaqImage3, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_CustomerFaqImage3, 80);
    lv_obj_set_height(ui_CustomerFaqImage3, 96);
    lv_obj_set_x(ui_CustomerFaqImage3, 0);
    lv_obj_set_y(ui_CustomerFaqImage3, 192);
    lv_obj_add_flag(ui_CustomerFaqImage3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CustomerFaqImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerFaqImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomerFaqImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerFaqImage4 = lv_img_create(ui_CustomerFaqPanel1);
    lv_img_set_src(ui_CustomerFaqImage4, &ui_img_pagesetting_png);
    lv_obj_set_width(ui_CustomerFaqImage4, 80);
    lv_obj_set_height(ui_CustomerFaqImage4, 96);
    lv_obj_set_x(ui_CustomerFaqImage4, 0);
    lv_obj_set_y(ui_CustomerFaqImage4, 288);
    lv_obj_add_flag(ui_CustomerFaqImage4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CustomerFaqImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerFaqImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomerFaqImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerFaqImage5 = lv_img_create(ui_CustomerFaqPanel1);
    lv_img_set_src(ui_CustomerFaqImage5, &ui_img_pagereserveselected_png);
    lv_obj_set_width(ui_CustomerFaqImage5, 80);
    lv_obj_set_height(ui_CustomerFaqImage5, 96);
    lv_obj_set_x(ui_CustomerFaqImage5, 0);
    lv_obj_set_y(ui_CustomerFaqImage5, 384);
    lv_obj_add_flag(ui_CustomerFaqImage5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CustomerFaqImage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerFaqImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomerFaqImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_CustomerFaqImage1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_CustomerFaqImage2, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_CustomerFaqImage3, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_CustomerFaqImage4, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_add_flag(ui_CustomerFaqImage5, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_CustomerFaqPanel2 = lv_obj_create(ui_CustomerFaq);
    lv_obj_set_width(ui_CustomerFaqPanel2, 720);
    lv_obj_set_height(ui_CustomerFaqPanel2, 480);
    lv_obj_set_x(ui_CustomerFaqPanel2, 80);
    lv_obj_set_y(ui_CustomerFaqPanel2, 0);
    lv_obj_clear_flag(ui_CustomerFaqPanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerFaqPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CustomerFaqPanel2, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CustomerFaqPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CustomerFaqPanel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CustomerFaqPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomerFaqPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_CustomerFaqPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_CustomerFaqPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_CustomerFaqPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_CustomerFaqPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerFaqPanel3 = lv_obj_create(ui_CustomerFaqPanel2);
    lv_obj_set_width(ui_CustomerFaqPanel3, 696);
    lv_obj_set_height(ui_CustomerFaqPanel3, 456);
    lv_obj_set_align(ui_CustomerFaqPanel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_CustomerFaqPanel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerFaqPanel3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CustomerFaqPanel3, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CustomerFaqPanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomerFaqPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_CustomerFaqPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_CustomerFaqPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_CustomerFaqPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_CustomerFaqPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerFaqTitle = lv_obj_create(ui_CustomerFaqPanel3);
    lv_obj_set_width(ui_CustomerFaqTitle, 665);
    lv_obj_set_height(ui_CustomerFaqTitle, 65);
    lv_obj_set_x(ui_CustomerFaqTitle, 10);
    lv_obj_set_y(ui_CustomerFaqTitle, 0);
    lv_obj_clear_flag(ui_CustomerFaqTitle, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerFaqTitle, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CustomerFaqTitle, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CustomerFaqTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CustomerFaqTitle, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CustomerFaqTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CustomerFaqTitle, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_CustomerFaqTitle, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_CustomerFaqTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_CustomerFaqTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_CustomerFaqTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_CustomerFaqTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerFaqLabel1 = lv_label_create(ui_CustomerFaqTitle);
    lv_obj_set_width(ui_CustomerFaqLabel1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_CustomerFaqLabel1, 28);
    lv_obj_set_x(ui_CustomerFaqLabel1, 15);
    lv_obj_set_y(ui_CustomerFaqLabel1, 0);
    lv_obj_set_align(ui_CustomerFaqLabel1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_CustomerFaqLabel1, "常见问题解答");
    lv_obj_set_style_text_color(ui_CustomerFaqLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CustomerFaqLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CustomerFaqLabel1, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerFaqButton1 = lv_btn_create(ui_CustomerFaqPanel3);
    lv_obj_set_width(ui_CustomerFaqButton1, 116);
    lv_obj_set_height(ui_CustomerFaqButton1, 60);
    lv_obj_set_x(ui_CustomerFaqButton1, 560);
    lv_obj_set_y(ui_CustomerFaqButton1, 381);
    lv_obj_add_flag(ui_CustomerFaqButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_CustomerFaqButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CustomerFaqButton1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CustomerFaqButton1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CustomerFaqButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_CustomerFaqButton1, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_CustomerFaqButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_CustomerFaqButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_CustomerFaqButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_CustomerFaqButton1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CustomerFaqButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CustomerFaqButton1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerFaqBtnlabel1 = lv_label_create(ui_CustomerFaqButton1);
    lv_obj_set_width(ui_CustomerFaqBtnlabel1, lv_pct(100));
    lv_obj_set_height(ui_CustomerFaqBtnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_CustomerFaqBtnlabel1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_CustomerFaqBtnlabel1, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_CustomerFaqBtnlabel1, Back[language_index]);
    lv_obj_set_style_text_align(ui_CustomerFaqBtnlabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CustomerFaqBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerFaqLabel2 = lv_label_create(ui_CustomerFaqPanel3);
    lv_obj_set_width(ui_CustomerFaqLabel2, 600);
    lv_obj_set_height(ui_CustomerFaqLabel2, 60);
    lv_obj_set_x(ui_CustomerFaqLabel2, 25);
    lv_obj_set_y(ui_CustomerFaqLabel2, 87);
    lv_label_set_long_mode(ui_CustomerFaqLabel2, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_CustomerFaqLabel2, "请用手机扫码查询常见问题解答");
    lv_obj_set_style_text_color(ui_CustomerFaqLabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CustomerFaqLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CustomerFaqLabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_CustomerFaqImage6 = lv_qrcode_create(ui_CustomerFaqPanel3, 160, lv_color_hex(0xFFFFFF), lv_color_hex(0x000000));

    lv_obj_set_width(ui_CustomerFaqImage6, 160);
    lv_obj_set_height(ui_CustomerFaqImage6, 160);
    lv_obj_set_x(ui_CustomerFaqImage6, 0);
    lv_obj_set_y(ui_CustomerFaqImage6, 40);
    lv_obj_set_align(ui_CustomerFaqImage6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_CustomerFaqImage6, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_CustomerFaqImage6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_CustomerFaqButton1, ui_event_CustomerFaqButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CustomerFaq, ui_event_CustomerFaq, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CustomerFaqImage1, ui_event_CustomerFaqImage, LV_EVENT_ALL, ui_CustomerFaqImage1);
    lv_obj_add_event_cb(ui_CustomerFaqImage2, ui_event_CustomerFaqImage, LV_EVENT_ALL, ui_CustomerFaqImage2);
    lv_obj_add_event_cb(ui_CustomerFaqImage3, ui_event_CustomerFaqImage, LV_EVENT_ALL, ui_CustomerFaqImage3);
    lv_obj_add_event_cb(ui_CustomerFaqImage4, ui_event_CustomerFaqImage, LV_EVENT_ALL, ui_CustomerFaqImage4);
    lv_obj_add_event_cb(ui_CustomerFaqImage5, ui_event_CustomerFaqImage, LV_EVENT_ALL, ui_CustomerFaqImage5);

}

void ui_event_CustomerFaqButton1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        LoadCustomerServiceScreen();
    }
}

void ui_event_CustomerFaq(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        //请求二维码图片
        // CrLogI("Request a QR code image.");
        // //get_printer_data(0x15,1,"\0");
        // send_get_creality_cloud_qrcode_cmd();

        char temp[64] = {0};
        snprintf(temp, 64, "https://www.crealitycloud.com/product");
        
        lv_qrcode_update(ui_CustomerFaqImage6, temp, strlen(temp));
        // lv_obj_center(ui_CustomerFaqImage6);
    }
}

void ui_event_CustomerFaqImage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        if(target == ui_CustomerFaqImage1)
            if ( home_printing_is_printing_finished() )
                LoadHomeNormalScreen();
            else
                LoadHomePrintingScreen();
        if(target == ui_CustomerFaqImage2)LoadAxisMoveScreen();
        if(target == ui_CustomerFaqImage3)LoadFileManageScreen();
        if(target == ui_CustomerFaqImage4)LoadSettingsScreen();
    }
}

void refresh_CustomerFaq_page(char *src)
{
    if(src != NULL)
    {
        char buff[258] = {0};
        buff[0] = PNG_DRV_LETTER;
        strncpy(buff + 1, src, sizeof(buff) - 2);
        lv_img_set_src(ui_CustomerFaqImage6, buff);
    }
}

void CustomerFaq_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_CustomerFaqLabel1 )
        lv_label_set_text(ui_CustomerFaqLabel1, FAQ[language_index]);
    if ( ui_CustomerFaqBtnlabel1 )
        lv_label_set_text(ui_CustomerFaqBtnlabel1, Back[language_index]);
    if ( ui_CustomerFaqLabel2 )
        lv_label_set_text(ui_CustomerFaqLabel2, FaqTips[language_index]);
}