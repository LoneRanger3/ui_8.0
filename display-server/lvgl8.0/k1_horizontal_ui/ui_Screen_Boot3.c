/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2023-03-04 15:26:06
 * @LastEditTime: 2023-03-12 11:38:48
 */
#include "ui_Screen_Boot3.h"

lv_obj_t * ui_BootPart3;
lv_obj_t * ui_BootPart3Label1;
lv_obj_t * ui_BootLabel2Panle;
lv_obj_t * ui_BootPart3Label2;
lv_obj_t * ui_BootPart3Label3;
lv_obj_t * ui_BootPart3Image1;
void ui_event_BootPart3Button1(lv_event_t * e);
lv_obj_t * ui_BootPart3Button1;
lv_obj_t * ui_BootPart3BtnLabel1;

void ui_event_BootPart3Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
#ifdef BRAZIL_CUSTOM_ORDER
        _ui_screen_change(ui_TimezoneSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
#else
        _ui_screen_change(ui_SelftestPrivacyPolicy, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
#endif
    }
}

void ui_event_BootPart3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        uint8_t index = get_cur_language_index();
    }
}

void ui_BootPart3_screen_init(void)
{
    uint8_t index = get_cur_language_index();
    ui_BootPart3 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_BootPart3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BootPart3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BootPart3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BootPart3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BootPart3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BootPart3Label1 = lv_label_create(ui_BootPart3);
    lv_obj_set_width(ui_BootPart3Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_BootPart3Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_BootPart3Label1, 0);
    lv_obj_set_y(ui_BootPart3Label1, 16);
    lv_obj_set_align(ui_BootPart3Label1, LV_ALIGN_TOP_MID);
    lv_label_set_long_mode(ui_BootPart3Label1, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_BootPart3Label1, Boot3Tips1[index]);
    lv_obj_set_style_text_color(ui_BootPart3Label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_BootPart3Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_BootPart3Label1, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BootLabel2Panle = lv_obj_create(ui_BootPart3);
    lv_obj_set_width(ui_BootLabel2Panle, 780);   /// 1
    lv_obj_set_height(ui_BootLabel2Panle, 56);    /// 1
    lv_obj_set_x(ui_BootLabel2Panle, 0);
    lv_obj_set_y(ui_BootLabel2Panle, 48);
    lv_obj_set_align(ui_BootLabel2Panle, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_BootLabel2Panle, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BootLabel2Panle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BootLabel2Panle, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BootLabel2Panle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BootLabel2Panle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_BootLabel2Panle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BootPart3Label2 = lv_label_create(ui_BootLabel2Panle);
    lv_obj_set_width(ui_BootPart3Label2, 770);   /// 1
    lv_obj_set_height(ui_BootPart3Label2, LV_SIZE_CONTENT);    /// 1
    lv_label_set_text(ui_BootPart3Label2, Boot3Tips2[index]);
    lv_obj_align(ui_BootPart3Label2, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_color(ui_BootPart3Label2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_BootPart3Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_BootPart3Label2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_BootPart3Label2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BootPart3Label3 = lv_label_create(ui_BootPart3);
    lv_obj_set_width(ui_BootPart3Label3, 560);
    lv_obj_set_height(ui_BootPart3Label3, 286);
    lv_obj_set_x(ui_BootPart3Label3, 120);
    lv_obj_set_y(ui_BootPart3Label3, 104);
    lv_label_set_long_mode(ui_BootPart3Label3, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_BootPart3Label3, "");
    lv_obj_set_style_radius(ui_BootPart3Label3, 18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BootPart3Label3, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BootPart3Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BootPart3Image1 = lv_img_create(ui_BootPart3Label3);
    lv_img_set_src(ui_BootPart3Image1, &ui_img_boot4_png);
    lv_obj_set_width(ui_BootPart3Image1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_BootPart3Image1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_BootPart3Image1, 0);
    lv_obj_set_y(ui_BootPart3Image1, 26);
    lv_obj_set_align(ui_BootPart3Image1, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_BootPart3Image1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_BootPart3Image1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_BootPart3Button1 = lv_btn_create(ui_BootPart3);
    lv_obj_set_width(ui_BootPart3Button1, 146);
    lv_obj_set_height(ui_BootPart3Button1, 60);
    lv_obj_set_x(ui_BootPart3Button1, 0);
    lv_obj_set_y(ui_BootPart3Button1, 400);
    lv_obj_set_align(ui_BootPart3Button1, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_BootPart3Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BootPart3Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BootPart3Button1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BootPart3Button1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BootPart3Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_BootPart3Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_BootPart3Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BootPart3BtnLabel1 = lv_label_create(ui_BootPart3Button1);
    lv_obj_set_width(ui_BootPart3BtnLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_BootPart3BtnLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_BootPart3BtnLabel1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_BootPart3BtnLabel1, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_BootPart3BtnLabel1, Boot1Tips3[index]);
    lv_obj_set_style_text_color(ui_BootPart3BtnLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_BootPart3BtnLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_BootPart3BtnLabel1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_BootPart3Button1, ui_event_BootPart3Button1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BootPart3, ui_event_BootPart3, LV_EVENT_ALL, NULL);

}

void boot3_change_language_text(void)
{
    uint8_t index = get_cur_language_index();
    if(ui_BootPart3Label1)
        lv_label_set_text(ui_BootPart3Label1, Boot3Tips1[index]);
    if(ui_BootPart3Label2)
        lv_label_set_text(ui_BootPart3Label2, Boot3Tips2[index]);
    if(ui_BootPart3BtnLabel1)
        lv_label_set_text(ui_BootPart3BtnLabel1, Boot1Tips3[index]);
}