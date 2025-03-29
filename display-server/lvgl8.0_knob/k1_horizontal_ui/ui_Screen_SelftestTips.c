#include "k1_horizontal_ui/ui_Screen_SelftestAll.h"
#include "page_switch.h"
#include "src/widgets/lv_label.h"
#include "ui.h"
#include "mult_language.h"

lv_obj_t *ui_SelftestTips;
lv_obj_t *ui_PanelSelfTestTips;
lv_obj_t *ui_TitleSelfTestTips;


lv_obj_t *ui_ButtonSelfTestTipsLeft;
lv_obj_t *ui_LabelSelfTestTipsLeft;
lv_obj_t *ui_ButtonSelfTestTipsRight;
lv_obj_t *ui_LabelSelfTestTipsRight;


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

static void LoadSelfTestTipsScreen(void);
static void SelfTestTipsPageChangeObjs(uint8_t index);
static void ui_event_ButtonSelfTestTipsLeft(lv_event_t *e);
static void ui_event_ButtonSelfTestTipsRight(lv_event_t *e);

void ui_event_SelftestTipsButton3(lv_event_t *e);
void ui_event_SelftestTips(lv_event_t *e);


void ui_SelftestTips_screen_init(void)
{
    uint8_t language_index = get_cur_language_index();
    ui_SelftestTips = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SelftestTips, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_SelftestTips, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestTips, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestTips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    init_pages(ui_SelftestTips, SelfTestTipsPageChangeObjs, LoadSelfTestTipsScreen);

    //页面板
    ui_PanelSelfTestTips = lv_obj_create(ui_SelftestTips);
    lv_obj_set_width(ui_PanelSelfTestTips, 640);
    lv_obj_set_height(ui_PanelSelfTestTips, 360);
    lv_obj_set_align(ui_PanelSelfTestTips, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelSelfTestTips, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelSelfTestTips, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelSelfTestTips, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelSelfTestTips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelSelfTestTips, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_PanelSelfTestTips, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_PanelSelfTestTips, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_PanelSelfTestTips, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_PanelSelfTestTips, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //隐私政策标题
    ui_TitleSelfTestTips = lv_label_create(ui_PanelSelfTestTips);
    lv_obj_set_width(ui_TitleSelfTestTips, 640);
    lv_obj_set_height(ui_TitleSelfTestTips, 60);
    lv_obj_set_x(ui_TitleSelfTestTips, 0);
    lv_obj_set_y(ui_TitleSelfTestTips, 20);
    lv_obj_set_align(ui_TitleSelfTestTips, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_TitleSelfTestTips, PrinterSelfTest[language_index]);
    lv_obj_set_style_text_color(ui_TitleSelfTestTips, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TitleSelfTestTips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TitleSelfTestTips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TitleSelfTestTips, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //欢迎来到自检流程
    ui_SelftestTipslabel1 = lv_label_create(ui_PanelSelfTestTips);
    lv_obj_set_width(ui_SelftestTipslabel1, 620);  /// 1
    lv_obj_set_height(ui_SelftestTipslabel1, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SelftestTipslabel1, 20);
    lv_obj_set_y(ui_SelftestTipslabel1, 60);
    lv_label_set_text(ui_SelftestTipslabel1, WelcomeSelfTest[language_index]);
    lv_obj_set_style_text_color(ui_SelftestTipslabel1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestTipslabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SelftestTipslabel1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestTipslabel1, lv_font30.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_SelftestTipslabel1, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_line_space(ui_SelftestTipslabel1, -10, LV_PART_MAIN|LV_STATE_DEFAULT);

    //
    ui_SelftestTipslabel2 = lv_label_create(ui_PanelSelfTestTips);
    lv_obj_set_width(ui_SelftestTipslabel2, 620);  /// 1
    lv_obj_set_height(ui_SelftestTipslabel2, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SelftestTipslabel2, 20);
    lv_obj_set_y(ui_SelftestTipslabel2, 120);
    lv_label_set_text(ui_SelftestTipslabel2, SelfTestCleanTip[language_index]);
    lv_obj_set_style_text_color(ui_SelftestTipslabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestTipslabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SelftestTipslabel2, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestTipslabel2, lv_font30.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_SelftestTipslabel2, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_line_space(ui_SelftestTipslabel2, -10, LV_PART_MAIN|LV_STATE_DEFAULT);

    ui_SelftestTipslabel3 = lv_label_create(ui_PanelSelfTestTips);
    //lv_label_set_long_mode(ui_SelftestTipslabel3, LV_LABEL_LONG_WRAP);
    lv_obj_set_width(ui_SelftestTipslabel3, 620);  /// 1
    lv_obj_set_height(ui_SelftestTipslabel3, LV_SIZE_CONTENT); /// 1
    lv_obj_set_x(ui_SelftestTipslabel3, 20);
    lv_obj_set_y(ui_SelftestTipslabel3, 180);
    lv_label_set_text(ui_SelftestTipslabel3, SelfTestTimeTip[language_index]);
    lv_obj_set_style_text_color(ui_SelftestTipslabel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestTipslabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SelftestTipslabel3, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestTipslabel3, lv_font30.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_SelftestTipslabel3, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_line_space(ui_SelftestTipslabel3, -10, LV_PART_MAIN|LV_STATE_DEFAULT);


    //上一步按钮
    ui_ButtonSelfTestTipsLeft = lv_btn_create(ui_PanelSelfTestTips);
    lv_obj_set_width(ui_ButtonSelfTestTipsLeft, 176);
    lv_obj_set_height(ui_ButtonSelfTestTipsLeft, 52);
    lv_obj_set_x(ui_ButtonSelfTestTipsLeft, 96);
    lv_obj_set_y(ui_ButtonSelfTestTipsLeft, 294);
    lv_obj_add_flag(ui_ButtonSelfTestTipsLeft, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSelfTestTipsLeft, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonSelfTestTipsLeft, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonSelfTestTipsLeft, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonSelfTestTipsLeft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonSelfTestTipsLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonSelfTestTipsLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_ButtonSelfTestTipsLeft, lv_color_hex(0xFFFFFF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonSelfTestTipsLeft, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonSelfTestTipsLeft, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonSelfTestTipsLeft, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonSelfTestTipsLeft, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //上一步按钮标签
    ui_LabelSelfTestTipsLeft = lv_label_create(ui_ButtonSelfTestTipsLeft);
    lv_obj_set_width(ui_LabelSelfTestTipsLeft, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelSelfTestTipsLeft, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelSelfTestTipsLeft, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelSelfTestTipsLeft, PrevStep[language_index]);
    lv_obj_set_style_text_color(ui_LabelSelfTestTipsLeft, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSelfTestTipsLeft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSelfTestTipsLeft, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //下一步按钮
    ui_ButtonSelfTestTipsRight = lv_btn_create(ui_PanelSelfTestTips);
    lv_obj_set_width(ui_ButtonSelfTestTipsRight, 176);
    lv_obj_set_height(ui_ButtonSelfTestTipsRight, 52);
    lv_obj_set_x(ui_ButtonSelfTestTipsRight, 368);
    lv_obj_set_y(ui_ButtonSelfTestTipsRight, 294);
    lv_obj_add_flag(ui_ButtonSelfTestTipsRight, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSelfTestTipsRight, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonSelfTestTipsRight, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonSelfTestTipsRight, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonSelfTestTipsRight, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonSelfTestTipsRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonSelfTestTipsRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_ButtonSelfTestTipsRight, lv_color_hex(0xFFFFFF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonSelfTestTipsRight, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonSelfTestTipsRight, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonSelfTestTipsRight, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonSelfTestTipsRight, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //下一步按钮标签
    ui_LabelSelfTestTipsRight = lv_label_create(ui_ButtonSelfTestTipsRight);
    lv_obj_set_width(ui_LabelSelfTestTipsRight, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelSelfTestTipsRight, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelSelfTestTipsRight, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelSelfTestTipsRight, NextStep[language_index]);
    lv_obj_set_style_text_color(ui_LabelSelfTestTipsRight, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSelfTestTipsRight, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSelfTestTipsRight, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_ButtonSelfTestTipsLeft, ui_event_ButtonSelfTestTipsLeft, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSelfTestTipsRight, ui_event_ButtonSelfTestTipsRight, LV_EVENT_ALL, NULL);


}

void ui_event_ButtonSelfTestTipsLeft(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    //lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        if (init_uiconfiginfo.AgreePrivacyPolicy)
        {
            LoadPage(ui_SelfTestPageDeviceBinding, 1);
        }
        else 
        {
            LoadPage(ui_TimezoneSettings, 0);
        }
    }
}

void ui_event_ButtonSelfTestTipsRight(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    //lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        LoadPage(ui_SelftestAll, 1);
    }
}

void ui_event_SelftestTipsButton1(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
      //  _ui_screen_change(ui_SelftestAll, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }
}
void ui_event_SelftestTipsButton2(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_CLICKED)
    {
        _ui_screen_change(ui_SelftestNetwork, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
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
        switch (UIType)
        {
            case CR_10_H1:  lv_img_set_src(ui_SelftestTips_Image1, &ui_img_machine_png);break;
            case CR_K1:     lv_img_set_src(ui_SelftestTips_Image1, &ui_img_machine_png);break;
            case CR_K1_Max: lv_img_set_src(ui_SelftestTips_Image1, &ui_img_k1max_selftest_png);break;
        }
    }
}

void self_test_tip_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_TitleSelfTestTips )
        lv_label_set_text(ui_TitleSelfTestTips, PrinterSelfTest[language_index]);

    if (ui_LabelSelfTestTipsLeft)
        lv_label_set_text(ui_LabelSelfTestTipsLeft, PrevStep[language_index]);

    if (ui_LabelSelfTestTipsRight)
        lv_label_set_text(ui_LabelSelfTestTipsRight, NextStep[language_index]);

    if ( ui_SelftestTipsBtnlabel3 )
        lv_label_set_text(ui_SelftestTipsBtnlabel3, JumpOver[language_index]);

    if ( ui_SelftestTipslabel1 )
        lv_label_set_text(ui_SelftestTipslabel1, WelcomeSelfTest[language_index]);

    if ( ui_SelftestTipslabel2 )
        lv_label_set_text(ui_SelftestTipslabel2, SelfTestCleanTip[language_index]);

    if ( ui_SelftestTipslabel3 )
    {
        lv_label_set_text(ui_SelftestTipslabel3, SelfTestTimeTip[language_index]);

        //redefine_label_size(ui_SelftestTipslabel3, lv_font24.font, 0, 0, 440, 0);
    }
}

void LoadSelfTestTipsScreen(void)
{
    lv_disp_load_scr(ui_SelftestTips);
}

// void LoadSelfTestTipsPageAndObjs()
// {
//     LoadPage(ui_SelftestTips, 1);
// }

void SelfTestTipsPageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    PageNode *SelfTestTipsPage_node = find_page(ui_SelftestTips);
    SelfTestTipsPage_node->nav_level = index;
    switch (index) 
    {
    case 1:
        lv_group_add_obj(encoder_group, ui_ButtonSelfTestTipsLeft);
        lv_group_add_obj(encoder_group, ui_ButtonSelfTestTipsRight);
        break;
    case 2:

        break;
    default:
        break;
    }
    
}
