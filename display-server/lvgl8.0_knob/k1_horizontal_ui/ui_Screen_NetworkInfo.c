#include "page_switch.h"
#include "ui.h"
#include "mult_language.h"

lv_obj_t * ui_NetworkInfo;
lv_obj_t * ui_NetworkInfoScreenPanel;
lv_obj_t * ui_NetworkInfoImage1;
lv_obj_t * ui_NetworkInfoImage2;
lv_obj_t * ui_NetworkInfoImage3;
lv_obj_t * ui_NetworkInfoImage4;
lv_obj_t * ui_NetworkInfoImage5;

lv_obj_t * ui_NetworkInfoPanel;
lv_obj_t * ui_NetworkInfotitle;
lv_obj_t * ui_NetworkInfoPanelLine;
lv_obj_t * ui_NetworkInfoButtonBack;

lv_obj_t * ui_NetworkIPAddrLabel;
lv_obj_t * ui_NetworkGatewayLabel;
lv_obj_t * ui_NetworkSubNetMaskLabel;
lv_obj_t * ui_NetworkDNSServerLabel;

void ui_event_NetworkInfoButton1(lv_event_t * e);
void ui_event_NetworkInfo(lv_event_t * e);
static void LoadNetworkInfoPage(void);
static void NetworkInfoPageChangeObjs(uint8_t index);

void ui_NetworkInfo_screen_init(void)
{
    ui_NetworkInfo = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_NetworkInfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_NetworkInfo, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_NetworkInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    init_pages(ui_NetworkInfo, NetworkInfoPageChangeObjs, LoadNetworkInfoPage);

    uint8_t language_index = get_cur_language_index();
    ui_NetworkInfoScreenPanel = lv_obj_create(ui_NetworkInfo);
    lv_obj_set_width(ui_NetworkInfoScreenPanel, 68);
    lv_obj_set_height(ui_NetworkInfoScreenPanel, 360);
       lv_obj_set_pos(ui_NetworkInfoScreenPanel, 0, 60);
    lv_obj_clear_flag(ui_NetworkInfoScreenPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkInfoScreenPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkInfoScreenPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkInfoScreenPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkInfoScreenPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_NetworkInfoScreenPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkInfoScreenPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_NetworkInfoScreenPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_NetworkInfoScreenPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_NetworkInfoScreenPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_NetworkInfoScreenPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoImage1 = lv_img_create(ui_NetworkInfoScreenPanel);
    lv_img_set_src(ui_NetworkInfoImage1, &ui_img_pagehome_png);
    lv_obj_set_width(ui_NetworkInfoImage1, 68);
    lv_obj_set_height(ui_NetworkInfoImage1, 72);
    lv_obj_set_pos(ui_NetworkInfoImage1, 0, 0);
    lv_obj_add_flag(ui_NetworkInfoImage1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_NetworkInfoImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkInfoImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoImage2 = lv_img_create(ui_NetworkInfoScreenPanel);
    lv_img_set_src(ui_NetworkInfoImage2, &ui_img_pagemove_png);
    lv_obj_set_width(ui_NetworkInfoImage2, 68);
    lv_obj_set_height(ui_NetworkInfoImage2, 72);
    lv_obj_set_pos(ui_NetworkInfoImage2, 0, 72);
    lv_obj_add_flag(ui_NetworkInfoImage2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_NetworkInfoImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkInfoImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkInfoImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoImage3 = lv_img_create(ui_NetworkInfoScreenPanel);
    lv_img_set_src(ui_NetworkInfoImage3, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_NetworkInfoImage3, 68);
    lv_obj_set_height(ui_NetworkInfoImage3, 72);
    lv_obj_set_pos(ui_NetworkInfoImage3, 0, 144);
    lv_obj_add_flag(ui_NetworkInfoImage3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_NetworkInfoImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkInfoImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkInfoImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoImage4 = lv_img_create(ui_NetworkInfoScreenPanel);
    lv_img_set_src(ui_NetworkInfoImage4, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_NetworkInfoImage4, 68);
    lv_obj_set_height(ui_NetworkInfoImage4, 72);
    lv_obj_set_pos(ui_NetworkInfoImage4, 0, 216);
    lv_obj_add_flag(ui_NetworkInfoImage4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_NetworkInfoImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkInfoImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkInfoImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoImage5 = lv_img_create(ui_NetworkInfoScreenPanel);
    lv_img_set_src(ui_NetworkInfoImage5, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_NetworkInfoImage5, 68);
    lv_obj_set_height(ui_NetworkInfoImage5, 72);
    lv_obj_set_pos(ui_NetworkInfoImage5, 0, 288);
    lv_obj_add_flag(ui_NetworkInfoImage5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_NetworkInfoImage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkInfoImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkInfoImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfoPanel = lv_obj_create(ui_NetworkInfo);
    lv_obj_set_pos(ui_NetworkInfoPanel, 73, 68);
    lv_obj_set_size(ui_NetworkInfoPanel, 559, 344); 
    lv_obj_set_align(ui_NetworkInfoPanel, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_NetworkInfoPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkInfoPanel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkInfoPanel, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkInfoPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkInfoPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_NetworkInfoPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkInfotitle = lv_label_create(ui_NetworkInfoPanel);
    lv_obj_set_size(ui_NetworkInfotitle, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_pos(ui_NetworkInfotitle, 16, 0);//6
    lv_label_set_text(ui_NetworkInfotitle, NetworkInfoArray[language_index]);
    lv_obj_set_style_text_color(ui_NetworkInfotitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworkInfotitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkInfotitle, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_NetworkInfoPanelLine = lv_obj_create(ui_NetworkInfoPanel);
    lv_obj_set_size( ui_NetworkInfoPanelLine, 543, 1);
    lv_obj_set_pos( ui_NetworkInfoPanelLine, 7, 49);
    lv_obj_clear_flag( ui_NetworkInfoPanelLine, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_opa( ui_NetworkInfoPanelLine, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color( ui_NetworkInfoPanelLine, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color( ui_NetworkInfoPanelLine, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa( ui_NetworkInfoPanelLine, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width( ui_NetworkInfoPanelLine, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //返回按钮
    ui_NetworkInfoButtonBack = lv_btn_create(ui_NetworkInfoPanel);
    lv_obj_set_size(ui_NetworkInfoButtonBack, 68, 38);
    lv_obj_set_pos(ui_NetworkInfoButtonBack, 474, 6);
    lv_obj_add_flag(ui_NetworkInfoButtonBack, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_NetworkInfoButtonBack, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_NetworkInfoButtonBack, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_NetworkInfoButtonBack, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NetworkInfoButtonBack, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkInfoButtonBack, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_NetworkInfoButtonBack, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_NetworkInfoButtonBack, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_NetworkInfoButtonBack, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_NetworkInfoButtonBack, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_NetworkInfoButtonBack, lv_color_hex(0xB0F1FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_NetworkInfoButtonBack, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_NetworkInfoButtonBack, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_NetworkInfoButtonBack, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_NetworkInfoButtonBack, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_NetworkInfoButtonBack, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    ui_NetworkIPAddrLabel = lv_label_create( ui_NetworkInfoPanel);
    lv_obj_set_width(ui_NetworkIPAddrLabel, LV_SIZE_CONTENT);   /// 300
    lv_obj_set_height(ui_NetworkIPAddrLabel, LV_SIZE_CONTENT);    /// 28
    lv_obj_set_x(ui_NetworkIPAddrLabel, 24);
    lv_obj_set_y(ui_NetworkIPAddrLabel, 66);
    lv_label_set_long_mode(ui_NetworkIPAddrLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    char buff[30] = {0};
    sprintf(buff, "%s:", IPAddrArray[language_index]);
    lv_label_set_text(ui_NetworkIPAddrLabel, buff);
    lv_obj_set_style_text_color(ui_NetworkIPAddrLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworkIPAddrLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkIPAddrLabel, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkGatewayLabel = lv_label_create( ui_NetworkInfoPanel);
    lv_obj_set_width(ui_NetworkGatewayLabel, LV_SIZE_CONTENT);   /// 300
    lv_obj_set_height(ui_NetworkGatewayLabel, LV_SIZE_CONTENT);    /// 28
    lv_obj_set_x(ui_NetworkGatewayLabel, 24);
    lv_obj_set_y(ui_NetworkGatewayLabel, 112);
    lv_label_set_long_mode(ui_NetworkGatewayLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", GatewayArray[language_index]);
    lv_label_set_text(ui_NetworkGatewayLabel, buff);
    lv_obj_set_style_text_color(ui_NetworkGatewayLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworkGatewayLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkGatewayLabel, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkSubNetMaskLabel = lv_label_create(ui_NetworkInfoPanel);
    lv_obj_set_width(ui_NetworkSubNetMaskLabel, LV_SIZE_CONTENT);   /// 300
    lv_obj_set_height(ui_NetworkSubNetMaskLabel, LV_SIZE_CONTENT);    /// 28
    lv_obj_set_x(ui_NetworkSubNetMaskLabel, 24);
    lv_obj_set_y(ui_NetworkSubNetMaskLabel, 159);
    lv_label_set_long_mode(ui_NetworkSubNetMaskLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", SubNetMaskArray[language_index]);
    lv_label_set_text(ui_NetworkSubNetMaskLabel, buff);
    lv_obj_set_style_text_color(ui_NetworkSubNetMaskLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworkSubNetMaskLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkSubNetMaskLabel, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_NetworkDNSServerLabel = lv_label_create( ui_NetworkInfoPanel);
    lv_obj_set_width(ui_NetworkDNSServerLabel, LV_SIZE_CONTENT);   /// 300
    lv_obj_set_height(ui_NetworkDNSServerLabel, LV_SIZE_CONTENT);    /// 28
    lv_obj_set_x(ui_NetworkDNSServerLabel, 24);
    lv_obj_set_y(ui_NetworkDNSServerLabel, 206);
    lv_label_set_long_mode(ui_NetworkDNSServerLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s:", DNSServerArray[language_index]);
    lv_label_set_text(ui_NetworkDNSServerLabel, buff);
    lv_obj_set_style_text_color(ui_NetworkDNSServerLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_NetworkDNSServerLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_NetworkDNSServerLabel, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_NetworkInfoButtonBack, ui_event_NetworkInfoButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_NetworkInfo, ui_event_NetworkInfo, LV_EVENT_ALL, NULL);
}

void ui_event_NetworkInfoButton1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        //_ui_screen_change(ui_ScreenSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        BackPrepage(false);
    }
}

void ui_event_NetworkInfo(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
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
        snprintf(temp,60,"%s: %s", IPAddrArray[get_cur_language_index()], wire_net_ip);
        lv_label_set_text(  ui_NetworkIPAddrLabel, temp);

        memset(temp, 0, 60);
        snprintf(temp,60,"%s: %s", GatewayArray[get_cur_language_index()], wire_gateway);
        lv_label_set_text(  ui_NetworkGatewayLabel, temp);
    
        memset(temp, 0, 60);
        snprintf(temp,60,"%s: %s", SubNetMaskArray[get_cur_language_index()], wire_subnet_mask);
        lv_label_set_text(  ui_NetworkSubNetMaskLabel, temp);

        memset(temp, 0, 60);
        snprintf(temp,60,"%s: %s", DNSServerArray[get_cur_language_index()], wire_dns);
        lv_label_set_text( ui_NetworkDNSServerLabel, temp);
    // }
}

void network_info_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();

    if ( ui_NetworkInfotitle )
        lv_label_set_text(ui_NetworkInfotitle, NetworkInfoArray[language_index]);

    // if ( ui_NetworkInfoBtnlabel1 )
    //     lv_label_set_text(ui_NetworkInfoBtnlabel1, Back[language_index]);

    char buff[80] = {0};
    if ( ui_NetworkIPAddrLabel )
    {
        char *ip = lv_label_get_text(  ui_NetworkIPAddrLabel);
        char *ch = NULL;
        if ( ip )
        {
            ch = strchr(ip, ':');
        }

        if ( ch )
            sprintf(buff, "%s%s", IPAddrArray[language_index], ch);
        else
            sprintf(buff, "%s:", IPAddrArray[language_index]);

        lv_label_set_text(  ui_NetworkIPAddrLabel, buff);
    }

    if (ui_NetworkGatewayLabel )
    {
        char *gateway = lv_label_get_text(  ui_NetworkGatewayLabel);
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

        lv_label_set_text(  ui_NetworkGatewayLabel, buff);
    }

    if (   ui_NetworkSubNetMaskLabel )
    {
        char *mask = lv_label_get_text(  ui_NetworkSubNetMaskLabel);
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

        lv_label_set_text(  ui_NetworkSubNetMaskLabel, buff);
    }

    if (  ui_NetworkDNSServerLabel )
    {
        char *server = lv_label_get_text( ui_NetworkDNSServerLabel);
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

        lv_label_set_text( ui_NetworkDNSServerLabel, buff);
    }
}

static void LoadNetworkInfoPage()
{
    _ui_screen_change(ui_NetworkInfo, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}

static void NetworkInfoPageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    PageNode *NetworkInfo_node = find_page(ui_NetworkInfo);
    NetworkInfo_node->nav_level = index;
  
    lv_group_add_obj(encoder_group, ui_NetworkInfoButtonBack);
}
