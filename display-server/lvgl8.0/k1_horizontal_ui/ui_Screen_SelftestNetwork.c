/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-12-06 15:43:14
 * @LastEditTime: 2023-03-10 10:45:08
 */
#include "ui_Screen_SelftestNetwork.h"
#include "mult_language.h"

lv_obj_t * ui_SelftestNetwork;
lv_obj_t * ui_SelftestNetworkpanel1;
lv_obj_t * ui_SelftestNetworktitle;
void ui_event_SelftestNetworkButton1(lv_event_t * e);
lv_obj_t * ui_SelftestNetworkButton1;
lv_obj_t * ui_SelftestNetworkBtnlabel1;
void ui_event_SelftestNetworkButton2(lv_event_t * e);
lv_obj_t * ui_SelftestNetworkButton2;
lv_obj_t * ui_SelftestNetworkBtnlabel2;
lv_obj_t * ui_SelftestNetworkpanel2;
lv_obj_t * ui_SelftestNetwork_Image1;
lv_obj_t * ui_SelftestNetworkLabel1;
lv_obj_t * ui_SelftestNetworkLabel2;
lv_obj_t * ui_SelftestNetwork_Image2;
lv_obj_t * ui_SelftestNetworkpanel3;
void ui_event_SelftestNetworkButton3(lv_event_t * e);
lv_obj_t * ui_SelftestNetworkButton3;
lv_obj_t * ui_SelftestNetworkBtnlabel3;

wifi_list_t selftestwifilist_array[WIFI_MAX_NUMBER] = {0};
static char wifilist_name[64];         
static unsigned char wifilist_state;   
bool selftest_network_flag = false;
lv_obj_t * listbtn;

void ui_event_SelftestnetworkImage8(lv_event_t * e);
void ui_event_Selftestnetwork_Keyboard1(lv_event_t * e);
void ui_event_SelftestNetwork(lv_event_t * e);
static wifi_list_t create_wifi_list_item(lv_obj_t *parent, lv_align_t align_mode, lv_coord_t x, lv_coord_t y);

void ui_SelftestNetwork_screen_init(void)
{
    ui_SelftestNetwork = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SelftestNetwork, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftestNetwork, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestNetwork, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestNetwork, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    uint8_t language_index = get_cur_language_index();
    ui_SelftestNetworkpanel1 = lv_obj_create(ui_SelftestNetwork);
    lv_obj_set_width(ui_SelftestNetworkpanel1, 800);
    lv_obj_set_height(ui_SelftestNetworkpanel1, 480);
    lv_obj_set_align(ui_SelftestNetworkpanel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_SelftestNetworkpanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftestNetworkpanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestNetworkpanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestNetworkpanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SelftestNetworkpanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_SelftestNetworkpanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SelftestNetworkpanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SelftestNetworkpanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SelftestNetworkpanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestNetworktitle = lv_label_create(ui_SelftestNetworkpanel1);
    lv_obj_set_width(ui_SelftestNetworktitle, 600);
    lv_obj_set_height(ui_SelftestNetworktitle, 34);
    lv_obj_set_x(ui_SelftestNetworktitle, 0);
    lv_obj_set_y(ui_SelftestNetworktitle, 20);
    lv_obj_set_align(ui_SelftestNetworktitle, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_SelftestNetworktitle, PleaseSetNetwork[language_index]);
    lv_obj_set_style_text_color(ui_SelftestNetworktitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestNetworktitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SelftestNetworktitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestNetworktitle, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestNetworkButton1 = lv_btn_create(ui_SelftestNetworkpanel1);
    lv_obj_set_width(ui_SelftestNetworkButton1, 146);
    lv_obj_set_height(ui_SelftestNetworkButton1, 60);
    lv_obj_set_x(ui_SelftestNetworkButton1, 459);
    lv_obj_set_y(ui_SelftestNetworkButton1, 400);
    lv_obj_add_flag(ui_SelftestNetworkButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SelftestNetworkButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftestNetworkButton1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestNetworkButton1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestNetworkButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SelftestNetworkButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SelftestNetworkButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestNetworkBtnlabel1 = lv_label_create(ui_SelftestNetworkButton1);
    lv_obj_set_width(ui_SelftestNetworkBtnlabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SelftestNetworkBtnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SelftestNetworkBtnlabel1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SelftestNetworkBtnlabel1, NextStep[language_index]);
    lv_obj_set_style_text_color(ui_SelftestNetworkBtnlabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestNetworkBtnlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestNetworkBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestNetworkButton2 = lv_btn_create(ui_SelftestNetworkpanel1);
    lv_obj_set_width(ui_SelftestNetworkButton2, 146);
    lv_obj_set_height(ui_SelftestNetworkButton2, 60);
    lv_obj_set_x(ui_SelftestNetworkButton2, 196);
    lv_obj_set_y(ui_SelftestNetworkButton2, 400);
    lv_obj_add_flag(ui_SelftestNetworkButton2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SelftestNetworkButton2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftestNetworkButton2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestNetworkButton2, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestNetworkButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SelftestNetworkButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SelftestNetworkButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestNetworkBtnlabel2 = lv_label_create(ui_SelftestNetworkButton2);
    lv_obj_set_width(ui_SelftestNetworkBtnlabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SelftestNetworkBtnlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SelftestNetworkBtnlabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SelftestNetworkBtnlabel2, PrevStep[language_index]);
    lv_obj_set_style_text_color(ui_SelftestNetworkBtnlabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestNetworkBtnlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestNetworkBtnlabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestNetworkpanel2 = lv_obj_create(ui_SelftestNetworkpanel1);
    lv_obj_set_width(ui_SelftestNetworkpanel2, 780);
    lv_obj_set_height(ui_SelftestNetworkpanel2, 50);
    lv_obj_set_x(ui_SelftestNetworkpanel2, 10);
    lv_obj_set_y(ui_SelftestNetworkpanel2, 90);
    lv_obj_clear_flag(ui_SelftestNetworkpanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftestNetworkpanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestNetworkpanel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestNetworkpanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SelftestNetworkpanel2, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SelftestNetworkpanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SelftestNetworkpanel2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_SelftestNetworkpanel2, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_SelftestNetworkpanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SelftestNetworkpanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SelftestNetworkpanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SelftestNetworkpanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestNetwork_Image1 = lv_img_create(ui_SelftestNetworkpanel2);
    lv_img_set_src(ui_SelftestNetwork_Image1, &ui_img_network_png);
    lv_obj_set_width(ui_SelftestNetwork_Image1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SelftestNetwork_Image1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SelftestNetwork_Image1, 27);
    lv_obj_set_y(ui_SelftestNetwork_Image1, 5);
    lv_obj_add_flag(ui_SelftestNetwork_Image1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SelftestNetwork_Image1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_SelftestNetworkLabel1 = lv_label_create(ui_SelftestNetworkpanel2);
    lv_obj_set_width(ui_SelftestNetworkLabel1, 200);
    lv_obj_set_height(ui_SelftestNetworkLabel1, 28);
    lv_obj_set_x(ui_SelftestNetworkLabel1, 58);
    lv_obj_set_y(ui_SelftestNetworkLabel1, 5);
    lv_label_set_text(ui_SelftestNetworkLabel1, LocalNetworkArray[language_index]);
    lv_obj_set_style_text_color(ui_SelftestNetworkLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestNetworkLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SelftestNetworkLabel1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestNetworkLabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestNetworkLabel2 = lv_label_create(ui_SelftestNetworkpanel2);
    lv_obj_set_height(ui_SelftestNetworkLabel2, 28);
    lv_obj_set_width(ui_SelftestNetworkLabel2, LV_SIZE_CONTENT);   /// 123
    lv_obj_set_x(ui_SelftestNetworkLabel2, -39);
    lv_obj_set_y(ui_SelftestNetworkLabel2, 5);
    lv_obj_set_align(ui_SelftestNetworkLabel2, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_SelftestNetworkLabel2, UnConnectedArray[language_index]);
    lv_obj_set_style_text_color(ui_SelftestNetworkLabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestNetworkLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SelftestNetworkLabel2, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestNetworkLabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestNetwork_Image2 = lv_img_create(ui_SelftestNetworkpanel2);
    lv_img_set_src(ui_SelftestNetwork_Image2, &ui_img_vector_24_png);
    lv_obj_set_width(ui_SelftestNetwork_Image2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SelftestNetwork_Image2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SelftestNetwork_Image2, -15);
    lv_obj_set_y(ui_SelftestNetwork_Image2, 5);
    lv_obj_set_align(ui_SelftestNetwork_Image2, LV_ALIGN_TOP_RIGHT);
    lv_obj_add_flag(ui_SelftestNetwork_Image2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_SelftestNetwork_Image2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_SelftestNetworkpanel3 = lv_obj_create(ui_SelftestNetworkpanel1);
    lv_obj_set_width(ui_SelftestNetworkpanel3, 760);
    lv_obj_set_height(ui_SelftestNetworkpanel3, 232);
    lv_obj_set_x(ui_SelftestNetworkpanel3, 20);
    lv_obj_set_y(ui_SelftestNetworkpanel3, 156);
    lv_obj_set_style_radius(ui_SelftestNetworkpanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestNetworkpanel3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestNetworkpanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SelftestNetworkpanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_SelftestNetworkpanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SelftestNetworkpanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SelftestNetworkpanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SelftestNetworkpanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_SelftestNetworkpanel3, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_SelftestNetworkpanel3, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
    lv_obj_set_style_pad_column(ui_SelftestNetworkpanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestNetworkButton3 = lv_btn_create(ui_SelftestNetworkpanel1);
    lv_obj_set_width(ui_SelftestNetworkButton3, 120);
    lv_obj_set_height(ui_SelftestNetworkButton3, 50);
    lv_obj_set_x(ui_SelftestNetworkButton3, 660);
    lv_obj_set_y(ui_SelftestNetworkButton3, 14);
    lv_obj_add_flag(ui_SelftestNetworkButton3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SelftestNetworkButton3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftestNetworkButton3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestNetworkButton3, lv_color_hex(0x28292D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestNetworkButton3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SelftestNetworkButton3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SelftestNetworkButton3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestNetworkBtnlabel3 = lv_label_create(ui_SelftestNetworkButton3);
    lv_obj_set_width(ui_SelftestNetworkBtnlabel3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SelftestNetworkBtnlabel3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SelftestNetworkBtnlabel3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SelftestNetworkBtnlabel3, JumpOver[language_index]);
    lv_obj_set_style_text_color(ui_SelftestNetworkBtnlabel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestNetworkBtnlabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestNetworkBtnlabel3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_SelftestNetworkButton1, ui_event_SelftestNetworkButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SelftestNetworkButton2, ui_event_SelftestNetworkButton2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SelftestNetworkButton3, ui_event_SelftestNetworkButton3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SelftestNetwork, ui_event_SelftestNetwork, LV_EVENT_ALL, NULL);

    switch (UIType)
    {
        case CR_K1:     
                lv_obj_add_flag(ui_SelftestNetworkpanel2, LV_OBJ_FLAG_HIDDEN);     /// Flags
                lv_obj_set_x(ui_SelftestNetworkpanel3, 20);
                lv_obj_set_y(ui_SelftestNetworkpanel3, 100);
                break;
        case CR_K1_Max:
                lv_obj_clear_flag(ui_SelftestNetworkpanel2, LV_OBJ_FLAG_HIDDEN);     /// Flags
                lv_obj_set_x(ui_SelftestNetworkpanel3, 20);
                lv_obj_set_y(ui_SelftestNetworkpanel3, 156);
                break;
        default:
            break;
    }

}
void ui_event_SelftestNetworkButton1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_TimezoneSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_SelftestNetworkButton2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_SelftestPrivacyPolicy, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        // _ui_screen_change(ui_changelanguage, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);

    }
}
void ui_event_SelftestNetworkButton3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        _ui_screen_change(ui_TimezoneSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}
void ui_event_SelftestNetwork(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load the selftest network connect page");
        selftest_network_flag = true;
        // char te[100];
        // snprintf(te,100,"%s\t%s\t%s","2MW315R:2","CXSW-guest:1","CXSW:0");
        // get_response_printer_data(0x07,30,te);
        get_printer_data(0x07,1,"1");
        get_printer_data(0x07,1,"2");
        wifi_wait_animmotion(1);
    }
    if(event_code == LV_EVENT_SCREEN_UNLOADED) {
        selftest_network_flag = false;
    }
}

static void wifi_list_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t * obj = lv_event_get_target(e);
	unsigned char i = 0;
    switch (code)
    {
        case LV_EVENT_CLICKED:
        {
            wifi_list_t *user_data = lv_event_get_user_data(e);
            wifilist_state = user_data->wifi_type;
            const char * src = lv_label_get_text(user_data->wifi_name);
            if (src == NULL)
                return;
            switch(wifilist_state)
            {
                case 3:
                {
                    create_wificonect_page(lv_scr_act(), "", true);
                    break;
                }
                case 2:
                    wifi_msgbox(0, obj, user_data);
                    break;
                case 1:
                    wifi_msgbox(1, obj, user_data);
                    break;
                case 0:
                {
                    create_wificonect_page(lv_scr_act(), src, false);
                    break;
                }
                default:
                    break;
            }
        break;
        }
        default:
            break;
    }
        
    
}

void selftest_show_wifi_list(char *data,int len)
{
    if(selftest_network_flag)
    {
        char dis_wifi_name[60];
        char wifi_type[10] = {0};
        char wifi_dis[10] = {0};
        unsigned char i = 0,j = 0,k = 0;

        CrLogI("get data : %s",data);
        char *temp = strtok(data,"\t");

        lv_obj_clean(ui_SelftestNetworkpanel3);
        memset(selftestwifilist_array, 0, WIFI_MAX_NUMBER * sizeof(wifi_list_t));
        k = 0;
        while(temp)
        {
            CrLogI("single wifi data : %s,%d",temp,k);
            int result = sscanf(temp, "%[^:]:%[^:]:%[^:]",dis_wifi_name, wifi_type, wifi_dis);
            if( result < 3)
            {
                CrLogE("explain the wifi data error,result count:%d",result);
                return;
            }
            CrLogI("single wifi name : %s",dis_wifi_name);
            CrLogI("single wifi type : %s",wifi_type);
            CrLogI("single wifi dis : %s",wifi_dis);

            if(k >= WIFI_MAX_NUMBER) return;
            selftestwifilist_array[k] = create_wifi_list_item(ui_SelftestNetworkpanel3, LV_ALIGN_TOP_LEFT, 0, 0);
            switch(wifi_type[0])
            {
            case '2':{
                //设置wifi名字并更新相关图片
                lv_obj_align(selftestwifilist_array[k].wifi_name,LV_ALIGN_TOP_LEFT,0,0);
                lv_obj_align_to(selftestwifilist_array[k].wifi_info,selftestwifilist_array[k].wifi_name,LV_ALIGN_OUT_BOTTOM_LEFT,0,0);

                lv_label_set_text(selftestwifilist_array[k].wifi_name,dis_wifi_name);
                lv_label_set_text(selftestwifilist_array[k].wifi_info,wifi_ip);
                lv_obj_set_style_text_color(selftestwifilist_array[k].wifi_name,lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);

                lv_obj_clear_flag(selftestwifilist_array[k].wifi_state,LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(selftestwifilist_array[k].wifi_info,LV_OBJ_FLAG_HIDDEN);
                lv_img_set_src(selftestwifilist_array[k].wifi_state,&ui_img_state_normal_png);
                lv_img_set_src(selftestwifilist_array[k].wifi_logo,&ui_img_wifi_state_png);

                //绑定事件
                selftestwifilist_array[k].wifi_type = 2;
                lv_obj_add_event_cb(selftestwifilist_array[k].parent, wifi_list_event_handler, LV_EVENT_CLICKED, &selftestwifilist_array[k]);
                k++;
                break;
            }
            case '1':{
                //设置wifi名字并更新相关图片
                lv_label_set_text(selftestwifilist_array[k].wifi_name,dis_wifi_name);
                lv_obj_set_style_text_color(selftestwifilist_array[k].wifi_name,lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_clear_flag(selftestwifilist_array[k].wifi_state,LV_OBJ_FLAG_HIDDEN);
                lv_img_set_src(selftestwifilist_array[k].wifi_state,&ui_img_wifi_state_1_png);
                lv_img_set_src(selftestwifilist_array[k].wifi_logo,&ui_img_wifi_state_png);
                lv_obj_add_flag(selftestwifilist_array[k].wifi_info,LV_OBJ_FLAG_HIDDEN);
                //绑定事件
                selftestwifilist_array[k].wifi_type = 1;
                lv_obj_add_event_cb(selftestwifilist_array[k].parent, wifi_list_event_handler, LV_EVENT_CLICKED, &selftestwifilist_array[k]);
                k++;
                break;
            }
            case '0':{
                //设置wifi名字并更新相关图片
                lv_label_set_text(selftestwifilist_array[k].wifi_name,dis_wifi_name);
                lv_obj_set_style_text_color(selftestwifilist_array[k].wifi_name,lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_add_flag(selftestwifilist_array[k].wifi_state,LV_OBJ_FLAG_HIDDEN);
                lv_img_set_src(selftestwifilist_array[k].wifi_logo,&ui_img_wifi_state_png);
                lv_obj_add_flag(selftestwifilist_array[k].wifi_info,LV_OBJ_FLAG_HIDDEN);
                //绑定事件
                selftestwifilist_array[k].wifi_type = 0;
                lv_obj_add_event_cb(selftestwifilist_array[k].parent, wifi_list_event_handler, LV_EVENT_CLICKED, &selftestwifilist_array[k]);
                k++;
                break;
            }
            default:
                break;
            }
            temp = strtok(NULL,"\t");
        }
        selftestwifilist_array[k] = create_wifi_list_item(ui_SelftestNetworkpanel3, LV_ALIGN_TOP_LEFT, 0, 0);
        lv_label_set_text(selftestwifilist_array[k].wifi_name, OtherNetwork[get_cur_language_index()]);
        lv_obj_set_style_text_color(selftestwifilist_array[k].wifi_name,lv_color_hex(0xffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_add_flag(selftestwifilist_array[k].wifi_state,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(selftestwifilist_array[k].wifi_logo,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(selftestwifilist_array[k].wifi_info,LV_OBJ_FLAG_HIDDEN);
        //绑定事件
        selftestwifilist_array[k].wifi_type = 3;
        lv_obj_add_event_cb(selftestwifilist_array[k].parent, wifi_list_event_handler, LV_EVENT_CLICKED, &selftestwifilist_array[k]);

    }
}

static wifi_list_t  create_wifi_list_item(lv_obj_t *parent, lv_align_t align_mode, lv_coord_t x, lv_coord_t y)
{
    wifi_list_t singleList = {0};

    lv_obj_t * listPanel = lv_obj_create(parent);
    lv_obj_set_width(listPanel, 760);
    lv_obj_set_height(listPanel, 60);
    lv_obj_align(listPanel, align_mode, x, y);
    lv_obj_clear_flag(listPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(listPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(listPanel, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(listPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(listPanel, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(listPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(listPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(listPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(listPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(listPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(listPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    singleList.parent = listPanel;

    lv_obj_t * list_text = lv_label_create(listPanel);
    lv_obj_set_width(list_text, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(list_text, LV_SIZE_CONTENT); /// 1
    lv_obj_align(list_text,LV_ALIGN_LEFT_MID,0,0);
    lv_label_set_text(list_text, "");
    lv_obj_set_style_text_color(list_text, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(list_text, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(list_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(list_text, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    singleList.wifi_name = list_text;

    lv_obj_t *list_wifiinfo = lv_label_create(listPanel);
    lv_obj_set_width(list_wifiinfo, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(list_wifiinfo, LV_SIZE_CONTENT);    /// 1
    lv_obj_align_to(list_wifiinfo, list_text, LV_ALIGN_OUT_BOTTOM_LEFT,0,0);
    lv_obj_add_flag(list_wifiinfo, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_add_flag(list_wifiinfo, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(list_wifiinfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_text_color(list_wifiinfo, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(list_wifiinfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(list_wifiinfo, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(list_wifiinfo, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    singleList.wifi_info = list_wifiinfo;

    lv_obj_t *list_img2 = lv_img_create(listPanel);
    lv_img_set_src(list_img2,&ui_img_state_normal_png);
    lv_obj_set_width(list_img2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(list_img2, LV_SIZE_CONTENT);    /// 1
    lv_obj_align(list_img2,LV_ALIGN_RIGHT_MID,-20,0);
    lv_obj_add_flag(list_img2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(list_img2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_align(list_img2,LV_ALIGN_RIGHT_MID,-20,0);
    singleList.wifi_logo = list_img2;

    lv_obj_t *list_img1 = lv_img_create(listPanel);
    lv_obj_set_width(list_img1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(list_img1, LV_SIZE_CONTENT);    /// 1
    lv_obj_add_flag(list_img1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(list_img1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_src(list_img1,&ui_img_state_normal_png);
    lv_obj_align_to(list_img1,list_img2,LV_ALIGN_OUT_LEFT_MID,-20,0);
    singleList.wifi_state = list_img1;

    return singleList;
}

void selftest_network_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_SelftestNetworktitle )
        lv_label_set_text(ui_SelftestNetworktitle, PleaseSetNetwork[language_index]);
    
    if ( ui_SelftestNetworkBtnlabel1 )
        lv_label_set_text(ui_SelftestNetworkBtnlabel1, NextStep[language_index]);

    if ( ui_SelftestNetworkBtnlabel2 )
        lv_label_set_text(ui_SelftestNetworkBtnlabel2, PrevStep[language_index]);
        
    if ( ui_SelftestNetworkLabel1 )
        lv_label_set_text(ui_SelftestNetworkLabel1, LocalNetworkArray[language_index]);

    if ( ui_SelftestNetworkLabel2 )
        lv_label_set_text(ui_SelftestNetworkLabel2, UnConnectedArray[language_index]);
    
    if ( ui_SelftestNetworkBtnlabel3 )
        lv_label_set_text(ui_SelftestNetworkBtnlabel3, JumpOver[language_index]);
    
}

void refresh_selftestnetworkstate(bool connect_state)
{
    if(connect_state)
    {
        lv_label_set_text(ui_SelftestNetworkLabel2, ConnectedArray[get_cur_language_index()]);
    }
    else
    {
        lv_label_set_text(ui_SelftestNetworkLabel2, UnConnectedArray[get_cur_language_index()]);
    }
}
