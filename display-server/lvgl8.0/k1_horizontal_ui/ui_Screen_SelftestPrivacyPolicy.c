/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-12-06 15:03:05
 * @LastEditTime: 2023-03-04 17:11:30
 */
#include "ui_Screen_SelftestPrivacyPolicy.h"
#include "mult_language.h"

lv_obj_t * ui_SelftestPrivacyPolicy;
lv_obj_t * ui_SelftestPrivacyPolicypanel;
lv_obj_t * ui_SelftestPrivacyPolicytitle1;
void ui_event_SelftestPrivacyPolicyButton1(lv_event_t * e);
lv_obj_t * ui_SelftestPrivacyPolicyButton1;
lv_obj_t * ui_SelftestPrivacyPolicyBtnlabel1;
lv_obj_t * ui_SelftestPrivacyPolicyLabel1;
void ui_event_SelftestPrivacyPolicyButton2(lv_event_t * e);
lv_obj_t * ui_SelftestPrivacyPolicyButton2;
lv_obj_t * ui_SelftestPrivacyPolicyBtnlabel2;
lv_obj_t * ui_SelftestPrivacyPolicyLabel2;
lv_obj_t * ui_SelftestPrivacyPolicy_Checkbox1;
lv_obj_t * ui_PrivacyPolicyTextPanel;
lv_obj_t * ui_PrivacyPolicyTextPanelmask;
void ui_event_SelftestPrivacyPolicyPageLoad(lv_event_t * e);
lv_obj_t * ui_PrivacyPolicyImageClosePage;
void ui_event_PrivacyPolicyClose(lv_event_t * e);

void ui_SelftestPrivacyPolicy_screen_init(void)
{
    uint8_t language_index = get_cur_language_index();
    ui_SelftestPrivacyPolicy = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SelftestPrivacyPolicy, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftestPrivacyPolicy, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestPrivacyPolicy, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestPrivacyPolicy, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestPrivacyPolicypanel = lv_obj_create(ui_SelftestPrivacyPolicy);
    lv_obj_set_width(ui_SelftestPrivacyPolicypanel, 800);
    lv_obj_set_height(ui_SelftestPrivacyPolicypanel, 480);
    lv_obj_set_align(ui_SelftestPrivacyPolicypanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_SelftestPrivacyPolicypanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftestPrivacyPolicypanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestPrivacyPolicypanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestPrivacyPolicypanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SelftestPrivacyPolicypanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_SelftestPrivacyPolicypanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SelftestPrivacyPolicypanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SelftestPrivacyPolicypanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SelftestPrivacyPolicypanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestPrivacyPolicytitle1 = lv_label_create(ui_SelftestPrivacyPolicypanel);
    lv_obj_set_width(ui_SelftestPrivacyPolicytitle1, 600);
    lv_obj_set_height(ui_SelftestPrivacyPolicytitle1, 34);
    lv_obj_set_x(ui_SelftestPrivacyPolicytitle1, 0);
    lv_obj_set_y(ui_SelftestPrivacyPolicytitle1, 20);
    lv_obj_set_align(ui_SelftestPrivacyPolicytitle1, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_SelftestPrivacyPolicytitle1, PrivacyPolicy[language_index]);
    lv_obj_set_style_text_color(ui_SelftestPrivacyPolicytitle1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestPrivacyPolicytitle1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SelftestPrivacyPolicytitle1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestPrivacyPolicytitle1, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestPrivacyPolicyButton1 = lv_btn_create(ui_SelftestPrivacyPolicypanel);
    lv_obj_set_width(ui_SelftestPrivacyPolicyButton1, 146);
    lv_obj_set_height(ui_SelftestPrivacyPolicyButton1, 60);
    lv_obj_set_x(ui_SelftestPrivacyPolicyButton1, 459);
    lv_obj_set_y(ui_SelftestPrivacyPolicyButton1, 400);
    lv_obj_add_flag(ui_SelftestPrivacyPolicyButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SelftestPrivacyPolicyButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftestPrivacyPolicyButton1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestPrivacyPolicyButton1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestPrivacyPolicyButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SelftestPrivacyPolicyButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SelftestPrivacyPolicyButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestPrivacyPolicyBtnlabel1 = lv_label_create(ui_SelftestPrivacyPolicyButton1);
    lv_obj_set_width(ui_SelftestPrivacyPolicyBtnlabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SelftestPrivacyPolicyBtnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SelftestPrivacyPolicyBtnlabel1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SelftestPrivacyPolicyBtnlabel1, NextStep[language_index]);
    lv_obj_set_style_text_color(ui_SelftestPrivacyPolicyBtnlabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestPrivacyPolicyBtnlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestPrivacyPolicyBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestPrivacyPolicyLabel1 = lv_label_create(ui_SelftestPrivacyPolicypanel);
    lv_obj_set_width(ui_SelftestPrivacyPolicyLabel1, 600);
    lv_obj_set_height(ui_SelftestPrivacyPolicyLabel1, 28);
    lv_obj_set_x(ui_SelftestPrivacyPolicyLabel1, 45);
    lv_obj_set_y(ui_SelftestPrivacyPolicyLabel1, 57);
    lv_label_set_text(ui_SelftestPrivacyPolicyLabel1, ForewordArray[language_index]);
    lv_obj_set_style_text_color(ui_SelftestPrivacyPolicyLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestPrivacyPolicyLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SelftestPrivacyPolicyLabel1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestPrivacyPolicyLabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestPrivacyPolicyButton2 = lv_btn_create(ui_SelftestPrivacyPolicypanel);
    lv_obj_set_width(ui_SelftestPrivacyPolicyButton2, 146);
    lv_obj_set_height(ui_SelftestPrivacyPolicyButton2, 60);
    lv_obj_set_x(ui_SelftestPrivacyPolicyButton2, 196);
    lv_obj_set_y(ui_SelftestPrivacyPolicyButton2, 400);
    lv_obj_add_flag(ui_SelftestPrivacyPolicyButton2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SelftestPrivacyPolicyButton2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftestPrivacyPolicyButton2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestPrivacyPolicyButton2, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestPrivacyPolicyButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SelftestPrivacyPolicyButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SelftestPrivacyPolicyButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestPrivacyPolicyBtnlabel2 = lv_label_create(ui_SelftestPrivacyPolicyButton2);
    lv_obj_set_width(ui_SelftestPrivacyPolicyBtnlabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SelftestPrivacyPolicyBtnlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SelftestPrivacyPolicyBtnlabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SelftestPrivacyPolicyBtnlabel2, PrevStep[language_index]);
    lv_obj_set_style_text_color(ui_SelftestPrivacyPolicyBtnlabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestPrivacyPolicyBtnlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestPrivacyPolicyBtnlabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PrivacyPolicyTextPanel = lv_obj_create(ui_SelftestPrivacyPolicypanel);
    lv_obj_set_width(ui_PrivacyPolicyTextPanel, 687);
    lv_obj_set_height(ui_PrivacyPolicyTextPanel, 289);
    lv_obj_set_x(ui_PrivacyPolicyTextPanel, 0);
    lv_obj_set_y(ui_PrivacyPolicyTextPanel, 96);
    lv_obj_set_align(ui_PrivacyPolicyTextPanel, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_PrivacyPolicyTextPanel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_radius(ui_PrivacyPolicyTextPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PrivacyPolicyTextPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PrivacyPolicyTextPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PrivacyPolicyTextPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PrivacyPolicyTextPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestPrivacyPolicyLabel2 = lv_label_create(ui_PrivacyPolicyTextPanel);
    lv_obj_add_flag(ui_SelftestPrivacyPolicyLabel2, LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_width(ui_SelftestPrivacyPolicyLabel2, 687);   /// 1
    lv_obj_set_height(ui_SelftestPrivacyPolicyLabel2, LV_SIZE_CONTENT);    /// 1
    lv_label_set_long_mode(ui_SelftestPrivacyPolicyLabel2, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_SelftestPrivacyPolicyLabel2, Privacycontent[language_index]);
    lv_obj_set_style_text_color(ui_SelftestPrivacyPolicyLabel2, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestPrivacyPolicyLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SelftestPrivacyPolicyLabel2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestPrivacyPolicyLabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PrivacyPolicyTextPanelmask = lv_img_create(ui_SelftestPrivacyPolicypanel);
    lv_img_set_src(ui_PrivacyPolicyTextPanelmask, &ui_img_mask2_png);
    lv_obj_set_width(ui_PrivacyPolicyTextPanelmask, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PrivacyPolicyTextPanelmask, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_PrivacyPolicyTextPanelmask, 0);
    lv_obj_set_y(ui_PrivacyPolicyTextPanelmask, 270);
    lv_obj_set_align(ui_PrivacyPolicyTextPanelmask, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_PrivacyPolicyTextPanelmask, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PrivacyPolicyTextPanelmask, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_SelftestPrivacyPolicy_Checkbox1 = lv_checkbox_create(ui_SelftestPrivacyPolicypanel);
    lv_checkbox_set_text(ui_SelftestPrivacyPolicy_Checkbox1, AgreePrivacyPolicy[language_index]);
    lv_obj_set_width(ui_SelftestPrivacyPolicy_Checkbox1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SelftestPrivacyPolicy_Checkbox1, LV_SIZE_CONTENT);    /// 1
    lv_obj_align(ui_SelftestPrivacyPolicy_Checkbox1, LV_ALIGN_TOP_MID, 0, 343);
    lv_obj_add_flag(ui_SelftestPrivacyPolicy_Checkbox1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_SelftestPrivacyPolicy_Checkbox1, lv_color_hex(0xFFFFFF),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestPrivacyPolicy_Checkbox1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestPrivacyPolicy_Checkbox1, lv_font24.font,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_SelftestPrivacyPolicy_Checkbox1, 6, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestPrivacyPolicy_Checkbox1, lv_color_hex(0x42BDD8),
                              LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestPrivacyPolicy_Checkbox1, lv_color_hex(0x42BDD8),
                              LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_SelftestPrivacyPolicy_Checkbox1, 6, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_SelftestPrivacyPolicy_Checkbox1, lv_color_hex(0x42BDD8),
                                  LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_SelftestPrivacyPolicy_Checkbox1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SelftestPrivacyPolicy_Checkbox1, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    ui_PrivacyPolicyImageClosePage = lv_img_create(ui_SelftestPrivacyPolicy);
    lv_obj_set_width(ui_PrivacyPolicyImageClosePage, 23);
    lv_obj_set_height(ui_PrivacyPolicyImageClosePage, 23);
    lv_obj_align(ui_PrivacyPolicyImageClosePage, LV_ALIGN_TOP_RIGHT, -26, 26);
    lv_obj_add_flag(ui_PrivacyPolicyImageClosePage, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_img_set_src(ui_PrivacyPolicyImageClosePage, &ui_img_close_png);

    lv_obj_add_event_cb(ui_SelftestPrivacyPolicyButton1, ui_event_SelftestPrivacyPolicyButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SelftestPrivacyPolicyButton2, ui_event_SelftestPrivacyPolicyButton2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SelftestPrivacyPolicy, ui_event_SelftestPrivacyPolicyPageLoad, LV_EVENT_SCREEN_LOADED, NULL);
    lv_obj_add_event_cb(ui_PrivacyPolicyImageClosePage, ui_event_PrivacyPolicyClose, LV_EVENT_ALL, NULL);
}

void ui_event_SelftestPrivacyPolicyButton1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        if(lv_obj_has_state(ui_SelftestPrivacyPolicy_Checkbox1,LV_STATE_CHECKED))
        {
            CrLogI("agree the PrivacyPolicy.");
            set_printer_data(CONTROL_PARAMETERS, 3, "q1");
        }
        _ui_screen_change(ui_SelftestNetwork, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
}
void ui_event_SelftestPrivacyPolicyButton2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(ui_BootPart3, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
    }
}
void ui_event_SelftestPrivacyPolicyPageLoad(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        if(!init_uiconfiginfo.SelftestFlag)
        {
            lv_obj_add_flag(ui_SelftestPrivacyPolicy_Checkbox1, LV_OBJ_FLAG_HIDDEN);     /// Flags
            lv_obj_add_flag(ui_SelftestPrivacyPolicyButton1, LV_OBJ_FLAG_HIDDEN);     /// Flags
            lv_obj_add_flag(ui_SelftestPrivacyPolicyButton2, LV_OBJ_FLAG_HIDDEN);     /// Flags
            lv_obj_clear_flag(ui_PrivacyPolicyImageClosePage, LV_OBJ_FLAG_HIDDEN);     /// Flags
            lv_obj_align(ui_PrivacyPolicyTextPanelmask, LV_ALIGN_TOP_MID, 0, 357);
        }
        else
        {
            lv_obj_clear_flag(ui_SelftestPrivacyPolicy_Checkbox1, LV_OBJ_FLAG_HIDDEN);     /// Flags
            lv_obj_clear_flag(ui_SelftestPrivacyPolicyButton1, LV_OBJ_FLAG_HIDDEN);     /// Flags
            lv_obj_clear_flag(ui_SelftestPrivacyPolicyButton2, LV_OBJ_FLAG_HIDDEN);     /// Flags
            lv_obj_add_flag(ui_PrivacyPolicyImageClosePage, LV_OBJ_FLAG_HIDDEN);     /// Flags
            lv_obj_align(ui_PrivacyPolicyTextPanelmask, LV_ALIGN_TOP_MID, 0, 270);
        }
    }
}
void ui_event_PrivacyPolicyClose(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(init_uiconfiginfo.SelftestFlag)
        {
            _ui_screen_change(ui_SelftestNetwork, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
        }
        else
        {
            QuitPrivacyPage();
        }
    }
}

void privacy_policy_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_SelftestPrivacyPolicytitle1 )
        lv_label_set_text(ui_SelftestPrivacyPolicytitle1, PrivacyPolicy[language_index]);
    
    if ( ui_SelftestPrivacyPolicyBtnlabel1 )
        lv_label_set_text(ui_SelftestPrivacyPolicyBtnlabel1, NextStep[language_index]);
    
    if ( ui_SelftestPrivacyPolicyLabel1 )
        lv_label_set_text(ui_SelftestPrivacyPolicyLabel1, ForewordArray[language_index]);
    
    if ( ui_SelftestPrivacyPolicyBtnlabel2 )
        lv_label_set_text(ui_SelftestPrivacyPolicyBtnlabel2, PrevStep[language_index]);
    
    if ( ui_SelftestPrivacyPolicy_Checkbox1 )
        lv_checkbox_set_text(ui_SelftestPrivacyPolicy_Checkbox1, AgreePrivacyPolicy[language_index]);
    if ( ui_SelftestPrivacyPolicyLabel2 )
        lv_checkbox_set_text(ui_SelftestPrivacyPolicyLabel2, Privacycontent[language_index]);

        
}

