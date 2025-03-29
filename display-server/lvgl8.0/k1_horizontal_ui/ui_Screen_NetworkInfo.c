#include "ui.h"
#include "mult_language.h"

lv_obj_t * ui_NetworkInfo;
lv_obj_t * ui_NetworkInfoPanel1;
lv_obj_t * ui_NetworkInfoImage1;
lv_obj_t * ui_NetworkInfoImage2;
lv_obj_t * ui_NetworkInfoImage3;
lv_obj_t * ui_NetworkInfoImage4;
lv_obj_t * ui_NetworkInfoImage5;
lv_obj_t * ui_NetworkInfoPanel2;
lv_obj_t * ui_NetworkInfoPanel3;
lv_obj_t * ui_NetworkInfotitle1;
lv_obj_t * ui_NetworkInfoLabel1;
lv_obj_t * ui_NetworkInfoButton1;
lv_obj_t * ui_NetworkInfoBtnlabel1;
lv_obj_t * ui_NetworkInfoLabel2;
lv_obj_t * ui_NetworkInfoLabel3;
lv_obj_t * ui_NetworkInfoLabel4;
lv_obj_t * ui_NetworkInfoLabel5;

void ui_event_NetworkInfoButton1(lv_event_t * e);
void ui_event_NetworkInfo(lv_event_t * e);

void ui_NetworkInfo_screen_init(void)
{
    ui_NetworkInfo = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_NetworkInfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    uint8_t language_index = get_cur_language_index();
    ui_NetworkInfoPanel1 = lv_obj_create(ui_NetworkInfo);
    lv_obj_set_width(ui_NetworkInfoPanel1, 80);
    lv_obj_set_height(ui_NetworkInfoPanel1, 480);
    lv_obj_clear_flag(ui_NetworkInfoPanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkInfoPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkInfoPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkInfoPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkInfoPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_NetworkInfoPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkInfoPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_NetworkInfoPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_NetworkInfoPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_NetworkInfoPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_NetworkInfoPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoImage1 = lv_img_create(ui_NetworkInfoPanel1);
    lv_img_set_src(ui_NetworkInfoImage1, &ui_img_pagehome_png);
    lv_obj_set_width(ui_NetworkInfoImage1, 80);
    lv_obj_set_height(ui_NetworkInfoImage1, 96);
    lv_obj_add_flag(ui_NetworkInfoImage1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_NetworkInfoImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkInfoImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoImage2 = lv_img_create(ui_NetworkInfoPanel1);
    lv_img_set_src(ui_NetworkInfoImage2, &ui_img_pagemove_png);
    lv_obj_set_width(ui_NetworkInfoImage2, 80);
    lv_obj_set_height(ui_NetworkInfoImage2, 96);
    lv_obj_set_x(ui_NetworkInfoImage2, 0);
    lv_obj_set_y(ui_NetworkInfoImage2, 96);
    lv_obj_add_flag(ui_NetworkInfoImage2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_NetworkInfoImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkInfoImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkInfoImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoImage3 = lv_img_create(ui_NetworkInfoPanel1);
    lv_img_set_src(ui_NetworkInfoImage3, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_NetworkInfoImage3, 80);
    lv_obj_set_height(ui_NetworkInfoImage3, 96);
    lv_obj_set_x(ui_NetworkInfoImage3, 0);
    lv_obj_set_y(ui_NetworkInfoImage3, 192);
    lv_obj_add_flag(ui_NetworkInfoImage3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_NetworkInfoImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkInfoImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkInfoImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoImage4 = lv_img_create(ui_NetworkInfoPanel1);
    lv_img_set_src(ui_NetworkInfoImage4, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_NetworkInfoImage4, 80);
    lv_obj_set_height(ui_NetworkInfoImage4, 96);
    lv_obj_set_x(ui_NetworkInfoImage4, 0);
    lv_obj_set_y(ui_NetworkInfoImage4, 288);
    lv_obj_add_flag(ui_NetworkInfoImage4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_NetworkInfoImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkInfoImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkInfoImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoImage5 = lv_img_create(ui_NetworkInfoPanel1);
    lv_img_set_src(ui_NetworkInfoImage5, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_NetworkInfoImage5, 80);
    lv_obj_set_height(ui_NetworkInfoImage5, 96);
    lv_obj_set_x(ui_NetworkInfoImage5, 0);
    lv_obj_set_y(ui_NetworkInfoImage5, 384);
    lv_obj_add_flag(ui_NetworkInfoImage5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_NetworkInfoImage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkInfoImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkInfoImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoPanel2 = lv_obj_create(ui_NetworkInfo);
    lv_obj_set_width(ui_NetworkInfoPanel2, 720);
    lv_obj_set_height(ui_NetworkInfoPanel2, 480);
    lv_obj_set_x(ui_NetworkInfoPanel2, 80);
    lv_obj_set_y(ui_NetworkInfoPanel2, 0);
    lv_obj_clear_flag(ui_NetworkInfoPanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkInfoPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkInfoPanel2, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkInfoPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkInfoPanel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_NetworkInfoPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkInfoPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_NetworkInfoPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_NetworkInfoPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_NetworkInfoPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_NetworkInfoPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoPanel3 = lv_obj_create(ui_NetworkInfoPanel2);
    lv_obj_set_width(ui_NetworkInfoPanel3, 696);
    lv_obj_set_height(ui_NetworkInfoPanel3, 456);
    lv_obj_set_x(ui_NetworkInfoPanel3, -1);
    lv_obj_set_y(ui_NetworkInfoPanel3, 0);
    lv_obj_set_align(ui_NetworkInfoPanel3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_NetworkInfoPanel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkInfoPanel3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkInfoPanel3, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkInfoPanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkInfoPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_NetworkInfoPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_NetworkInfoPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_NetworkInfoPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_NetworkInfoPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfotitle1 = lv_obj_create(ui_NetworkInfoPanel3);
    lv_obj_set_width(ui_NetworkInfotitle1, 665);
    lv_obj_set_height(ui_NetworkInfotitle1, 65);
    lv_obj_set_x(ui_NetworkInfotitle1, 10);
    lv_obj_set_y(ui_NetworkInfotitle1, 0);
    lv_obj_clear_flag(ui_NetworkInfotitle1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkInfotitle1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkInfotitle1, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkInfotitle1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkInfotitle1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_NetworkInfotitle1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkInfotitle1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_NetworkInfotitle1, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_NetworkInfotitle1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_NetworkInfotitle1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_NetworkInfotitle1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_NetworkInfotitle1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoLabel1 = lv_label_create(ui_NetworkInfotitle1);
    lv_obj_set_width(ui_NetworkInfoLabel1, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_NetworkInfoLabel1, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_NetworkInfoLabel1, 15);
    lv_obj_set_y(ui_NetworkInfoLabel1, 0);
    lv_obj_set_align(ui_NetworkInfoLabel1, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_NetworkInfoLabel1, NetworkInfoArray[language_index]);
    lv_obj_set_style_text_color(ui_NetworkInfoLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworkInfoLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkInfoLabel1, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoButton1 = lv_btn_create(ui_NetworkInfoPanel3);
    lv_obj_set_width(ui_NetworkInfoButton1, 116);
    lv_obj_set_height(ui_NetworkInfoButton1, 60);
    lv_obj_set_x(ui_NetworkInfoButton1, 560);
    lv_obj_set_y(ui_NetworkInfoButton1, 381);
    lv_obj_add_flag(ui_NetworkInfoButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_NetworkInfoButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkInfoButton1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkInfoButton1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkInfoButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_NetworkInfoButton1, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_NetworkInfoButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_NetworkInfoButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_NetworkInfoButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_NetworkInfoButton1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworkInfoButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkInfoButton1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoBtnlabel1 = lv_label_create(ui_NetworkInfoButton1);
    lv_obj_set_width(ui_NetworkInfoBtnlabel1, lv_pct(100));
    lv_obj_set_height(ui_NetworkInfoBtnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_NetworkInfoBtnlabel1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_NetworkInfoBtnlabel1, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_NetworkInfoBtnlabel1, Back[language_index]);
    lv_obj_set_style_text_align(ui_NetworkInfoBtnlabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkInfoBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoLabel2 = lv_label_create(ui_NetworkInfoPanel3);
    lv_obj_set_width(ui_NetworkInfoLabel2, LV_SIZE_CONTENT);   /// 300
    lv_obj_set_height(ui_NetworkInfoLabel2, LV_SIZE_CONTENT);    /// 28
    lv_obj_set_x(ui_NetworkInfoLabel2, 26);
    lv_obj_set_y(ui_NetworkInfoLabel2, 90);
    lv_label_set_long_mode(ui_NetworkInfoLabel2, LV_LABEL_LONG_SCROLL_CIRCULAR);
    char buff[30] = {0};
    sprintf(buff, "%s:", IPAddrArray[language_index]);
    lv_label_set_text(ui_NetworkInfoLabel2, buff);
    lv_obj_set_style_text_color(ui_NetworkInfoLabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworkInfoLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkInfoLabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoLabel3 = lv_label_create(ui_NetworkInfoPanel3);
    lv_obj_set_width(ui_NetworkInfoLabel3, LV_SIZE_CONTENT);   /// 300
    lv_obj_set_height(ui_NetworkInfoLabel3, LV_SIZE_CONTENT);    /// 28
    lv_obj_set_x(ui_NetworkInfoLabel3, 26);
    lv_obj_set_y(ui_NetworkInfoLabel3, 149);
    lv_label_set_long_mode(ui_NetworkInfoLabel3, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", GatewayArray[language_index]);
    lv_label_set_text(ui_NetworkInfoLabel3, buff);
    lv_obj_set_style_text_color(ui_NetworkInfoLabel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworkInfoLabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkInfoLabel3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoLabel4 = lv_label_create(ui_NetworkInfoPanel3);
    lv_obj_set_width(ui_NetworkInfoLabel4, LV_SIZE_CONTENT);   /// 300
    lv_obj_set_height(ui_NetworkInfoLabel4, LV_SIZE_CONTENT);    /// 28
    lv_obj_set_x(ui_NetworkInfoLabel4, 26);
    lv_obj_set_y(ui_NetworkInfoLabel4, 208);
    lv_label_set_long_mode(ui_NetworkInfoLabel4, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", SubNetMaskArray[language_index]);
    lv_label_set_text(ui_NetworkInfoLabel4, buff);
    lv_obj_set_style_text_color(ui_NetworkInfoLabel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworkInfoLabel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkInfoLabel4, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoLabel5 = lv_label_create(ui_NetworkInfoPanel3);
    lv_obj_set_width(ui_NetworkInfoLabel5, LV_SIZE_CONTENT);   /// 300
    lv_obj_set_height(ui_NetworkInfoLabel5, LV_SIZE_CONTENT);    /// 28
    lv_obj_set_x(ui_NetworkInfoLabel5, 26);
    lv_obj_set_y(ui_NetworkInfoLabel5, 268);
    lv_label_set_long_mode(ui_NetworkInfoLabel5, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", DNSServerArray[language_index]);
    lv_label_set_text(ui_NetworkInfoLabel5, buff);
    lv_obj_set_style_text_color(ui_NetworkInfoLabel5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworkInfoLabel5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkInfoLabel5, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_NetworkInfoButton1, ui_event_NetworkInfoButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_NetworkInfo, ui_event_NetworkInfo, LV_EVENT_ALL, NULL);
}

void ui_event_NetworkInfoButton1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_Settings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_NetworkInfo(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load NetworkInfo page.");
        get_printer_data(0x7,1,"1");   
    }
}

void refresh_networkinfo_page()
{
    CrLogI("refresh the networkinfo page.");
    // if(wire_net_state == '1')
    // {
        char temp[60] = {0};
        snprintf(temp,60,"%s:%s", IPAddrArray[get_cur_language_index()], wire_net_ip);
        lv_label_set_text(ui_NetworkInfoLabel2, temp);

        memset(temp, 0, 60);
        snprintf(temp,60,"%s:%s", GatewayArray[get_cur_language_index()], wire_gateway);
        lv_label_set_text(ui_NetworkInfoLabel3, temp);
    
        memset(temp, 0, 60);
        snprintf(temp,60,"%s:%s", SubNetMaskArray[get_cur_language_index()], wire_subnet_mask);
        lv_label_set_text(ui_NetworkInfoLabel4, temp);

        memset(temp, 0, 60);
        snprintf(temp,60,"%s:%s", DNSServerArray[get_cur_language_index()], wire_dns);
        lv_label_set_text(ui_NetworkInfoLabel5, temp);
    // }
}

void network_info_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();

    if ( ui_NetworkInfoLabel1 )
        lv_label_set_text(ui_NetworkInfoLabel1, NetworkInfoArray[language_index]);

    if ( ui_NetworkInfoBtnlabel1 )
        lv_label_set_text(ui_NetworkInfoBtnlabel1, Back[language_index]);

    char buff[80] = {0};
    if ( ui_NetworkInfoLabel2 )
    {
        char *ip = lv_label_get_text(ui_NetworkInfoLabel2);
        char *ch = NULL;
        if ( ip )
        {
            ch = strchr(ip, ':');
        }

        if ( ch )
            sprintf(buff, "%s%s", IPAddrArray[language_index], ch);
        else
            sprintf(buff, "%s:", IPAddrArray[language_index]);

        lv_label_set_text(ui_NetworkInfoLabel2, buff);
    }

    if ( ui_NetworkInfoLabel3 )
    {
        char *gateway = lv_label_get_text(ui_NetworkInfoLabel3);
        char *ch1 = NULL;
        if ( gateway )
        {
            ch1 = strchr(gateway, ':');
        }

        memset(buff, 0, sizeof(buff));
        if ( ch1 )
            sprintf(buff, "%s%s", GatewayArray[language_index], ch1);
        else
            sprintf(buff, "%s:", GatewayArray[language_index]);

        lv_label_set_text(ui_NetworkInfoLabel3, buff);
    }

    if ( ui_NetworkInfoLabel4 )
    {
        char *mask = lv_label_get_text(ui_NetworkInfoLabel4);
        char *ch2 = NULL;
        if ( mask )
        {
            ch2 = strchr(mask, ':');
        }

        memset(buff, 0, sizeof(buff));
        if ( ch2 )
            sprintf(buff, "%s%s", SubNetMaskArray[language_index], ch2);
        else
            sprintf(buff, "%s:", SubNetMaskArray[language_index]);

        lv_label_set_text(ui_NetworkInfoLabel4, buff);
    }

    if ( ui_NetworkInfoLabel5 )
    {
        char *server = lv_label_get_text(ui_NetworkInfoLabel5);
        char *ch3 = NULL;
        if ( server )
        {
            ch3 = strchr(server, ':');
        }

        memset(buff, 0, sizeof(buff));
        if ( ch3 )
            sprintf(buff, "%s%s", DNSServerArray[language_index], ch3);
        else
            sprintf(buff, "%s:", DNSServerArray[language_index]);

        lv_label_set_text(ui_NetworkInfoLabel5, buff);
    }
}