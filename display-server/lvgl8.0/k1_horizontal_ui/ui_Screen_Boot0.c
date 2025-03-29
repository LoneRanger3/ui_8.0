#include "ui_Screen_Boot0.h"

lv_obj_t * ui_BootPart0;
lv_obj_t * ui_BootPart0Label1;
lv_obj_t * ui_BootPart0Label2;
lv_obj_t * ui_BootPart0Label3;
lv_obj_t * ui_BootPart0Image1;
void ui_event_BootPart0Button1(lv_event_t * e);
lv_obj_t * ui_BootPart0Button1;
lv_obj_t * ui_BootPart0BtnLabel1;

void ui_event_BootPart0Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_BootPart3, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_BootPart0_screen_init(void)
{
    uint8_t index = get_cur_language_index();
    ui_BootPart0 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_BootPart0, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BootPart0, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BootPart0, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BootPart0, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BootPart0, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BootPart0Label1 = lv_label_create(ui_BootPart0);
    lv_obj_set_width(ui_BootPart0Label1, 770);   /// 1
    lv_obj_set_height(ui_BootPart0Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_align(ui_BootPart0Label1, LV_ALIGN_TOP_MID, 0, 14);
    lv_label_set_text(ui_BootPart0Label1, Boot0Tips1[index]);
    lv_obj_set_style_text_color(ui_BootPart0Label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_BootPart0Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_BootPart0Label1, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_BootPart0Label1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BootPart0Label3 = lv_label_create(ui_BootPart0);
    lv_obj_set_width(ui_BootPart0Label3, 560);
    lv_obj_set_height(ui_BootPart0Label3, 286);
    lv_obj_set_x(ui_BootPart0Label3, 120);
    lv_obj_set_y(ui_BootPart0Label3, 104);
    lv_label_set_long_mode(ui_BootPart0Label3, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_BootPart0Label3, "");
    lv_obj_set_style_radius(ui_BootPart0Label3, 18, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BootPart0Label3, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BootPart0Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BootPart0Image1 = lv_img_create(ui_BootPart0Label3);
    lv_img_set_src(ui_BootPart0Image1, &ui_img_boot0_png);
    lv_obj_set_width(ui_BootPart0Image1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_BootPart0Image1, LV_SIZE_CONTENT);    /// 1
    lv_obj_align(ui_BootPart0Image1, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_add_flag(ui_BootPart0Image1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_BootPart0Image1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_BootPart0Button1 = lv_btn_create(ui_BootPart0);
    lv_obj_set_width(ui_BootPart0Button1, 146);
    lv_obj_set_height(ui_BootPart0Button1, 60);
    lv_obj_set_x(ui_BootPart0Button1, 0);
    lv_obj_set_y(ui_BootPart0Button1, 400);
    lv_obj_set_align(ui_BootPart0Button1, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_BootPart0Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BootPart0Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BootPart0Button1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BootPart0Button1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BootPart0Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_BootPart0Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_BootPart0Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BootPart0BtnLabel1 = lv_label_create(ui_BootPart0Button1);
    lv_obj_set_width(ui_BootPart0BtnLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_BootPart0BtnLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_BootPart0BtnLabel1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_BootPart0BtnLabel1, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_BootPart0BtnLabel1, Boot1Tips3[index]);
    lv_obj_set_style_text_color(ui_BootPart0BtnLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_BootPart0BtnLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_BootPart0BtnLabel1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_BootPart0Button1, ui_event_BootPart0Button1, LV_EVENT_ALL, NULL);

}

void boot0_change_language_text(void)
{
    uint8_t index = get_cur_language_index();
    if(ui_BootPart0Label1)
        lv_label_set_text(ui_BootPart0Label1, Boot0Tips1[index]);
    if(ui_BootPart0BtnLabel1)
        lv_label_set_text(ui_BootPart0BtnLabel1, Boot1Tips3[index]);

}