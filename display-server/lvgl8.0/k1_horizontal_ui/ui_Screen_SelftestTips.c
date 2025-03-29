#include "ui.h"
#include "../Base/DisplayMsgBase.h"
#include "mult_language.h"

lv_obj_t *ui_SelftestTips;
lv_obj_t *ui_SelftestTipstitle;
void ui_event_SelftestTipsButton1(lv_event_t *e);
lv_obj_t *ui_SelftestTipsButton1;
lv_obj_t *ui_SelftestTipsBtnlabel1;
void ui_event_SelftestTipsButton2(lv_event_t *e);
lv_obj_t *ui_SelftestTipsButton2;
lv_obj_t *ui_SelftestTipsBtnlabel2;
lv_obj_t *ui_SelftestTipsButton3;
lv_obj_t *ui_SelftestTipsBtnlabel3;
lv_obj_t *ui_SelftestTips_Panel1;
lv_obj_t *ui_SelftestTips_Image1;
lv_obj_t *ui_SelftestTips_Panel2;
lv_obj_t *ui_SelftestTipslabel1;
lv_obj_t *ui_SelftestTipslabel2;
lv_obj_t *ui_SelftestTipslabel3;

void ui_event_SelftestTipsButton3(lv_event_t *e);
void ui_event_SelftestTips(lv_event_t *e);


void ui_SelftestTips_screen_init(void)
{
    ui_SelftestTips = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SelftestTips, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_SelftestTips, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestTips, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestTips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    uint8_t language_index = get_cur_language_index();
    ui_SelftestTipstitle = lv_label_create(ui_SelftestTips);
    lv_obj_set_width(ui_SelftestTipstitle, 600);
    lv_obj_set_height(ui_SelftestTipstitle, 34);
    lv_obj_set_x(ui_SelftestTipstitle, 0);
    lv_obj_set_y(ui_SelftestTipstitle, 20);
    lv_obj_set_align(ui_SelftestTipstitle, LV_ALIGN_TOP_MID);

    lv_label_set_text(ui_SelftestTipstitle, PrinterSelfTest[language_index]);
    lv_obj_set_style_text_color(ui_SelftestTipstitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestTipstitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SelftestTipstitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestTipstitle, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestTipsButton1 = lv_btn_create(ui_SelftestTips);
    lv_obj_set_width(ui_SelftestTipsButton1, 146);
    lv_obj_set_height(ui_SelftestTipsButton1, 60);
    lv_obj_set_x(ui_SelftestTipsButton1, 459);
    lv_obj_set_y(ui_SelftestTipsButton1, 400);
    lv_obj_add_flag(ui_SelftestTipsButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SelftestTipsButton1, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(ui_SelftestTipsButton1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestTipsButton1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestTipsButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SelftestTipsButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SelftestTipsButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestTipsBtnlabel1 = lv_label_create(ui_SelftestTipsButton1);
    lv_obj_set_width(ui_SelftestTipsBtnlabel1, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SelftestTipsBtnlabel1, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SelftestTipsBtnlabel1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SelftestTipsBtnlabel1, StartDetection[language_index]);
    lv_obj_set_style_text_color(ui_SelftestTipsBtnlabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestTipsBtnlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestTipsBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestTipsButton2 = lv_btn_create(ui_SelftestTips);
    lv_obj_set_width(ui_SelftestTipsButton2, 146);
    lv_obj_set_height(ui_SelftestTipsButton2, 60);
    lv_obj_set_x(ui_SelftestTipsButton2, 196);
    lv_obj_set_y(ui_SelftestTipsButton2, 400);
    lv_obj_add_flag(ui_SelftestTipsButton2, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SelftestTipsButton2, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(ui_SelftestTipsButton2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestTipsButton2, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestTipsButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SelftestTipsButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SelftestTipsButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestTipsBtnlabel2 = lv_label_create(ui_SelftestTipsButton2);
    lv_obj_set_width(ui_SelftestTipsBtnlabel2, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SelftestTipsBtnlabel2, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SelftestTipsBtnlabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SelftestTipsBtnlabel2, PrevStep[language_index]);
    lv_obj_set_style_text_color(ui_SelftestTipsBtnlabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestTipsBtnlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestTipsBtnlabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestTipsButton3 = lv_btn_create(ui_SelftestTips);
    lv_obj_set_width(ui_SelftestTipsButton3, 120);
    lv_obj_set_height(ui_SelftestTipsButton3, 50);
    lv_obj_set_x(ui_SelftestTipsButton3, 660);
    lv_obj_set_y(ui_SelftestTipsButton3, 14);
    lv_obj_add_flag(ui_SelftestTipsButton3, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SelftestTipsButton3, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(ui_SelftestTipsButton3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestTipsButton3, lv_color_hex(0x28292D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestTipsButton3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SelftestTipsButton3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SelftestTipsButton3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_SelftestTipsButton3, LV_OBJ_FLAG_HIDDEN); /// Flags

    ui_SelftestTipsBtnlabel3 = lv_label_create(ui_SelftestTipsButton3);
    lv_obj_set_width(ui_SelftestTipsBtnlabel3, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SelftestTipsBtnlabel3, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SelftestTipsBtnlabel3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SelftestTipsBtnlabel3, JumpOver[language_index]);
    lv_obj_set_style_text_color(ui_SelftestTipsBtnlabel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestTipsBtnlabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestTipsBtnlabel3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestTips_Panel1 = lv_obj_create(ui_SelftestTips);
    lv_obj_set_width(ui_SelftestTips_Panel1, 243);
    lv_obj_set_height(ui_SelftestTips_Panel1, 294);
    lv_obj_set_x(ui_SelftestTips_Panel1, 20);
    lv_obj_set_y(ui_SelftestTips_Panel1, 74);
    lv_obj_clear_flag(ui_SelftestTips_Panel1, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_SelftestTips_Panel1, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestTips_Panel1, lv_color_hex(0x1C1C1D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestTips_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_SelftestTips_Panel1, lv_color_hex(0x080809), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_SelftestTips_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_SelftestTips_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_SelftestTips_Panel1, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SelftestTips_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_SelftestTips_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SelftestTips_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SelftestTips_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SelftestTips_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestTips_Image1 = lv_img_create(ui_SelftestTips_Panel1);
    lv_img_set_src(ui_SelftestTips_Image1, &ui_img_machine_png);
    lv_obj_set_width(ui_SelftestTips_Image1, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SelftestTips_Image1, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SelftestTips_Image1, 0);
    lv_obj_set_y(ui_SelftestTips_Image1, 42);
    lv_obj_set_align(ui_SelftestTips_Image1, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_SelftestTips_Image1, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
    lv_obj_clear_flag(ui_SelftestTips_Image1, LV_OBJ_FLAG_SCROLLABLE); /// Flags

    ui_SelftestTips_Panel2 = lv_obj_create(ui_SelftestTips);
    lv_obj_set_width(ui_SelftestTips_Panel2, 505);
    lv_obj_set_height(ui_SelftestTips_Panel2, 294);
    lv_obj_set_x(ui_SelftestTips_Panel2, 275);
    lv_obj_set_y(ui_SelftestTips_Panel2, 74);
    lv_obj_clear_flag(ui_SelftestTips_Panel2, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_SelftestTips_Panel2, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestTips_Panel2, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestTips_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_SelftestTips_Panel2, lv_color_hex(0x080808), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_SelftestTips_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_SelftestTips_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_SelftestTips_Panel2, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SelftestTips_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_SelftestTips_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SelftestTips_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SelftestTips_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SelftestTips_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestTipslabel1 = lv_label_create(ui_SelftestTips_Panel2);
    lv_obj_set_width(ui_SelftestTipslabel1, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SelftestTipslabel1, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SelftestTipslabel1, 27);
    lv_obj_set_y(ui_SelftestTipslabel1, 20);
    lv_label_set_text(ui_SelftestTipslabel1, WelcomeSelfTest[language_index]);
    lv_obj_set_style_text_letter_space(ui_SelftestTipslabel1, -1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_SelftestTipslabel1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestTipslabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SelftestTipslabel1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestTipslabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestTipslabel2 = lv_label_create(ui_SelftestTips_Panel2);
    lv_obj_set_width(ui_SelftestTipslabel2, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SelftestTipslabel2, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SelftestTipslabel2, 27);
    lv_obj_set_y(ui_SelftestTipslabel2, 67);
    lv_label_set_text(ui_SelftestTipslabel2, HeaterPurifyingTip[language_index]);
    lv_obj_set_style_text_color(ui_SelftestTipslabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestTipslabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SelftestTipslabel2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestTipslabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestTipslabel3 = lv_label_create(ui_SelftestTips_Panel2);
    lv_label_set_long_mode(ui_SelftestTipslabel3, LV_LABEL_LONG_WRAP);
    lv_obj_set_width(ui_SelftestTipslabel3, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SelftestTipslabel3, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SelftestTipslabel3, 27);
    lv_obj_set_y(ui_SelftestTipslabel3, 105);
    lv_label_set_text(ui_SelftestTipslabel3, SelfTestTimeTip[language_index]);
    lv_obj_set_style_text_color(ui_SelftestTipslabel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestTipslabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SelftestTipslabel3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestTipslabel3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_SelftestTipsButton1, ui_event_SelftestTipsButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SelftestTipsButton2, ui_event_SelftestTipsButton2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SelftestTipsButton3, ui_event_SelftestTipsButton3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SelftestTips, ui_event_SelftestTips, LV_EVENT_ALL, NULL);

}
void ui_event_SelftestTipsButton1(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(ui_SelftestAll, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
}
void ui_event_SelftestTipsButton2(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
#ifdef BRAZIL_CUSTOM_ORDER
        _ui_screen_change(ui_TimezoneSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
#else
        _ui_screen_change(ui_DeviceBinding, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
#endif
    }
}
void ui_event_SelftestTipsButton3(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        // _ui_screen_change(ui_SelftestResult, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
}
void ui_event_SelftestTips(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_SCREEN_LOADED)
    {
        char tempbuff[256] = {0};
        switch (UIType)
        {
            case CR_10_H1:  lv_img_set_src(ui_SelftestTips_Image1, &ui_img_machine_png);break;
            case CR_K1:{
                snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "K1_Machine.png");
                lv_img_set_src(ui_SelftestTips_Image1, tempbuff);break;
            }
            case CR_K1_Max:{
                snprintf(tempbuff, 256, "S:%s/%s", GetK1MaxImageResourcePtah(), "K1MAX_Machine.png");
                lv_img_set_src(ui_SelftestTips_Image1, tempbuff);break;
            }
        }
    }
}

void self_test_tip_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_SelftestTipstitle )
        lv_label_set_text(ui_SelftestTipstitle, PrinterSelfTest[language_index]);
    
    if ( ui_SelftestTipsBtnlabel1 )
    {
        lv_label_set_text(ui_SelftestTipsBtnlabel1, StartDetection[language_index]);
        redefine_label_size(ui_SelftestTipsBtnlabel1, lv_font24.font, 0, 0, 220, 0);
        
        lv_obj_update_layout(ui_SelftestTipsButton1);
        redefine_widgets_size(ui_SelftestTipsButton1, ui_SelftestTipsBtnlabel1, 10, 0, 146, 60);
    } 

    if ( ui_SelftestTipsBtnlabel2 )
        lv_label_set_text(ui_SelftestTipsBtnlabel2, PrevStep[language_index]);

    if ( ui_SelftestTipsBtnlabel3 )
        lv_label_set_text(ui_SelftestTipsBtnlabel3, JumpOver[language_index]);

    if ( ui_SelftestTipslabel1 )
        lv_label_set_text(ui_SelftestTipslabel1, WelcomeSelfTest[language_index]);

    if ( ui_SelftestTipslabel2 )
        lv_label_set_text(ui_SelftestTipslabel2, HeaterPurifyingTip[language_index]);

    if ( ui_SelftestTipslabel3 )
    {
        lv_label_set_text(ui_SelftestTipslabel3, SelfTestTimeTip[language_index]);

        redefine_label_size(ui_SelftestTipslabel3, lv_font24.font, 0, 0, 440, 0);
    }

}