/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-12-06 15:03:05
 * @LastEditTime: 2023-10-29 22:29:44
 */
#include "ui_Screen_SelftestPrivacyPolicy.h"
#include "mult_language.h"
#include "src/core/lv_obj_pos.h"
#include "src/misc/lv_area.h"

lv_obj_t * ui_SelftestPrivacyPolicy;
static lv_obj_t * ui_PanelPrivacyPolicy;
static lv_obj_t * ui_TitlePrivacyPolicy;
static lv_obj_t * ui_ButtonPrivacyPolicyRight;
static lv_obj_t * ui_LabelPrivacyPolicyRight;
static lv_obj_t * ui_PanelForeword;
static lv_obj_t * ui_LabelForeword;
static lv_obj_t * ui_ButtonPrivacyPolicyLeft;
static lv_obj_t * ui_LabelPrivacyPolicyLeft;
static lv_obj_t * ui_LabelPrivacyPolicyContent;
static lv_obj_t * ui_LabelPrivacyPolicyContentPreview;
static lv_obj_t * ui_PanelPrivacyPolicyContentPreview;
static lv_obj_t * ui_CheckboxAgree;
static lv_obj_t * ui_PanelPrivacyPolicyContent;
static lv_obj_t * ui_PanelPrivacyPolicyContentmask;

PrivacyPolicyButtonCb_f PrivacyPolicyRightBtnCb = NULL;
PrivacyPolicyButtonCb_f PrivacyPolicyLeftBtnCb = NULL; 

void ui_event_SelftestPrivacyPolicyRightButton(lv_event_t * e);
void ui_event_SelftestPrivacyPolicyLeftButton(lv_event_t * e);
static void SelftestPrivacyPolicyPageChangeObjs(uint8_t index);
static void LoadPrivacyPolicyScreen(void);
void ui_event_PanelPrivacyPolicyContent(lv_event_t * e);

void ui_event_PanelPrivacyPolicyContent(lv_event_t * e)
{
    static int ScrollCnt = 0;
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_SHORT_CLICKED) { //事件组在导航模式下, 这里不会响应面板的点击事件,但会进入编辑模式，进入编辑模式后，这里才会响应点击事件
        lv_group_set_editing(encoder_group, false);
    }
    if(code == LV_EVENT_KEY) //让文本滚动过程中，鼠标滚动一次，出发两次滚动事件，加快滚动速度
    {
        CrLogI("ui_event_PanelPrivacyPolicyContent, ScrollCnt = %d\n", ScrollCnt);
        if (ScrollCnt == 1)
        {
            ScrollCnt = 0;
        }
        else
        {
            ScrollCnt++;
            lv_event_send(ui_PanelPrivacyPolicyContent, LV_EVENT_KEY, lv_event_get_param(e));
        }
    }
    // if(code == LV_EVENT_FOCUSED) { 
    //     //printf("ui_event_PanelPrivacyPolicyContent\n");
    //     //lv_label_set_text(ui_LabelPrivacyPolicyContent, Privacycontent[language_index]);
    //     printf("LV_LABEL_LONG_TXT_HINT = %d\n", LV_LABEL_LONG_TXT_HINT);
    //     if(lv_group_get_editing(encoder_group))
    //     {
    //         lv_label_set_text(ui_LabelPrivacyPolicyContent, Privacycontent[get_cur_language_index()]);
    //         //lv_obj_add_flag(ui_LabelPrivacyPolicyContentPreview, LV_OBJ_FLAG_HIDDEN);
    //     }
    //     else
    //     {
    //         lv_label_set_text(ui_LabelPrivacyPolicyContent, Privacycontent[get_cur_language_index()]);
    //         //lv_obj_clear_flag(ui_LabelPrivacyPolicyContentPreview, LV_OBJ_FLAG_HIDDEN);
    //     }
    // }
}

void ui_event_CheckboxAgree(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        if(lv_obj_has_state(ui_CheckboxAgree,LV_STATE_CHECKED))
        {
            CrLogI("agree the PrivacyPolicy.");
            SelfTestDevicebindingAgreeFlag = true;
            set_printer_data(CONTROL_PARAMETERS, 3, "q1");
        }
        else
        {
            CrLogI("disagree the PrivacyPolicy.");
            SelfTestDevicebindingAgreeFlag = false;
            set_printer_data(CONTROL_PARAMETERS, 3, "q0");
        }
        //SelftestPrivacyPolicyPageChangeObjs(2);
    }
}

void ui_event_SelftestPrivacyPolicyRightButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);

        if (selftestflag && !SelfTestDevicebindingFlag)
        {//下一步
            LoadPage(ui_SelftestNetwork, 0);
        }
        else
        {//确定
            if (PrivacyPolicyRightBtnCb)
            {
                PrivacyPolicyRightBtnCb();
                PrivacyPolicyRightBtnCb = NULL;
            }
            else
            {
                CrLogE("PrivacyPolicyRightBtnCb is NULL");
            }
        }
    }
}

void ui_event_SelftestPrivacyPolicyLeftButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        //_ui_screen_change(ui_changelanguage, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0);
        if (selftestflag && !SelfTestDevicebindingFlag)
        {//上一步
            LoadPage(ui_changelanguage, 0);
        }
        else
        {//再想想
            if (PrivacyPolicyLeftBtnCb)
            {
                PrivacyPolicyLeftBtnCb();
                PrivacyPolicyLeftBtnCb = NULL;
            }
            else
            {
                CrLogE("PrivacyPolicyLeftBtnCb is NULL");
            }
        }
    }
}

void ui_SelftestPrivacyPolicy_screen_init(void)
{
    uint8_t language_index = get_cur_language_index();
    ui_SelftestPrivacyPolicy = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SelftestPrivacyPolicy, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftestPrivacyPolicy, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestPrivacyPolicy, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestPrivacyPolicy, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    init_pages(ui_SelftestPrivacyPolicy, SelftestPrivacyPolicyPageChangeObjs, LoadPrivacyPolicyScreen);
    //页面板
    ui_PanelPrivacyPolicy = lv_obj_create(ui_SelftestPrivacyPolicy);
    lv_obj_set_width(ui_PanelPrivacyPolicy, 640);
    lv_obj_set_height(ui_PanelPrivacyPolicy, 360);
    lv_obj_set_align(ui_PanelPrivacyPolicy, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelPrivacyPolicy, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPrivacyPolicy, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelPrivacyPolicy, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelPrivacyPolicy, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelPrivacyPolicy, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_PanelPrivacyPolicy, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_PanelPrivacyPolicy, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_PanelPrivacyPolicy, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_PanelPrivacyPolicy, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //隐私政策标题
    ui_TitlePrivacyPolicy = lv_label_create(ui_PanelPrivacyPolicy);
    lv_obj_set_width(ui_TitlePrivacyPolicy, 640);
    lv_obj_set_height(ui_TitlePrivacyPolicy, 60);
    lv_obj_set_x(ui_TitlePrivacyPolicy, 0);
    lv_obj_set_y(ui_TitlePrivacyPolicy, 20);
    lv_obj_set_align(ui_TitlePrivacyPolicy, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_TitlePrivacyPolicy, PrivacyPolicy[language_index]);
    lv_obj_set_style_text_color(ui_TitlePrivacyPolicy, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TitlePrivacyPolicy, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_TitlePrivacyPolicy, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TitlePrivacyPolicy, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //隐私内容面板
    ui_PanelPrivacyPolicyContent = lv_obj_create(ui_PanelPrivacyPolicy);
    lv_obj_set_width(ui_PanelPrivacyPolicyContent, 620);
    lv_obj_set_height(ui_PanelPrivacyPolicyContent, 190);
    lv_obj_set_x(ui_PanelPrivacyPolicyContent, 0);
    lv_obj_set_y(ui_PanelPrivacyPolicyContent, 60);
    lv_obj_set_align(ui_PanelPrivacyPolicyContent, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_PanelPrivacyPolicyContent, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    //默认样式
    lv_obj_set_style_radius(ui_PanelPrivacyPolicyContent, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelPrivacyPolicyContent, lv_color_hex(0x141515), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelPrivacyPolicyContent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelPrivacyPolicyContent, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelPrivacyPolicyContent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelPrivacyPolicyContent, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelPrivacyPolicyContent, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_PanelPrivacyPolicyContent, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_PanelPrivacyPolicyContent, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_PanelPrivacyPolicyContent, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_PanelPrivacyPolicyContent, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_PanelPrivacyPolicyContent, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //隐私内容标签
    ui_LabelPrivacyPolicyContent = lv_label_create(ui_PanelPrivacyPolicyContent);
    //lv_obj_add_flag(ui_LabelPrivacyPolicyContent, LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    lv_obj_set_width(ui_LabelPrivacyPolicyContent, 585);   /// 1
    lv_obj_set_height(ui_LabelPrivacyPolicyContent, LV_SIZE_CONTENT);    /// 1
    lv_obj_align(ui_LabelPrivacyPolicyContent, LV_ALIGN_TOP_MID, 0, 40);
    lv_label_set_long_mode(ui_LabelPrivacyPolicyContent, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_LabelPrivacyPolicyContent, Privacycontent[language_index]);
    lv_obj_set_style_text_color(ui_LabelPrivacyPolicyContent, lv_color_hex(0xDFDFDF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelPrivacyPolicyContent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelPrivacyPolicyContent, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelPrivacyPolicyContent, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //前言面板
    ui_PanelForeword = lv_obj_create(ui_PanelPrivacyPolicy);
    lv_obj_set_width(ui_PanelForeword, 600);
    lv_obj_set_height(ui_PanelForeword, 42);
    lv_obj_set_x(ui_PanelForeword, 0);
    lv_obj_set_y(ui_PanelForeword, 62);
    lv_obj_set_align(ui_PanelForeword, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_PanelForeword, LV_OBJ_FLAG_SCROLLABLE); 
    // lv_obj_add_flag(ui_PanelForeword, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    //默认样式
    lv_obj_set_style_radius(ui_PanelForeword, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelForeword, lv_color_hex(0x141515), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelForeword, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelForeword, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelForeword, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelForeword, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //前言
    ui_LabelForeword = lv_label_create(ui_PanelForeword);
    lv_obj_set_width(ui_LabelForeword, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelForeword, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_LabelForeword, 6);
    lv_obj_set_y(ui_LabelForeword, 3);
    lv_label_set_text(ui_LabelForeword, ForewordArray[language_index]);
    lv_obj_set_style_text_color(ui_LabelForeword, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelForeword, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelForeword, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelForeword, lv_font30.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // //隐私内容预览面板
    // ui_PanelPrivacyPolicyContentPreview = lv_obj_create(ui_PanelPrivacyPolicy);
    // lv_obj_set_width(ui_PanelPrivacyPolicyContentPreview, 615);
    // lv_obj_set_height(ui_PanelPrivacyPolicyContentPreview, 140);
    // lv_obj_set_x(ui_PanelPrivacyPolicyContentPreview, 0);
    // lv_obj_set_y(ui_PanelPrivacyPolicyContentPreview, 100);
    // lv_obj_set_align(ui_PanelPrivacyPolicyContentPreview, LV_ALIGN_TOP_MID);
    // lv_obj_add_flag(ui_PanelPrivacyPolicyContentPreview, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    // //默认样式
    // lv_obj_set_style_radius(ui_PanelPrivacyPolicyContentPreview, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_PanelPrivacyPolicyContentPreview, lv_color_hex(0x141515), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_PanelPrivacyPolicyContentPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ui_PanelPrivacyPolicyContentPreview, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_opa(ui_PanelPrivacyPolicyContentPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_all(ui_PanelPrivacyPolicyContentPreview, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_PanelPrivacyPolicyContentPreview, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    // //聚焦样式
    // lv_obj_set_style_border_color(ui_PanelPrivacyPolicyContentPreview, lv_color_hex(0xCDF6FF),
    //                               LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    // lv_obj_set_style_border_opa(ui_PanelPrivacyPolicyContentPreview, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    // lv_obj_set_style_border_width(ui_PanelPrivacyPolicyContentPreview, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    // lv_obj_set_style_outline_pad(ui_PanelPrivacyPolicyContentPreview, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    // lv_obj_set_style_outline_color(ui_PanelPrivacyPolicyContentPreview, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    // lv_obj_add_flag(ui_PanelPrivacyPolicyContentPreview, LV_OBJ_FLAG_HIDDEN); 

    // //隐私内容预览标签
    // ui_PanelPrivacyPolicyContentPreview = lv_label_create(ui_PanelPrivacyPolicyContentPreview);
    // //lv_obj_add_flag(ui_PanelPrivacyPolicyContentPreview, LV_OBJ_FLAG_SCROLLABLE);     /// Flags
    // lv_obj_set_width(ui_PanelPrivacyPolicyContentPreview, 585);   /// 1
    // lv_obj_set_height(ui_PanelPrivacyPolicyContentPreview, 140);    /// 1
    // lv_obj_align(ui_PanelPrivacyPolicyContentPreview, LV_ALIGN_TOP_MID, 0, 40);
    // lv_label_set_long_mode(ui_PanelPrivacyPolicyContentPreview, LV_LABEL_LONG_WRAP);
    // lv_label_set_text(ui_PanelPrivacyPolicyContentPreview, PrivacycontentPreview[language_index]);
    // lv_obj_set_style_text_color(ui_PanelPrivacyPolicyContentPreview, lv_color_hex(0xDFDFDF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_PanelPrivacyPolicyContentPreview, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_PanelPrivacyPolicyContentPreview, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_PanelPrivacyPolicyContentPreview, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelPrivacyPolicyContentmask = lv_img_create(ui_PanelPrivacyPolicy);
    lv_img_set_src(ui_PanelPrivacyPolicyContentmask, &ui_img_mask2_png);
    lv_obj_set_width(ui_PanelPrivacyPolicyContentmask, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PanelPrivacyPolicyContentmask, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ui_PanelPrivacyPolicyContentmask, 0);
    // lv_obj_set_y(ui_PanelPrivacyPolicyContentmask, 200);
    //lv_obj_set_align(ui_PanelPrivacyPolicyContentmask, LV_ALIGN_TOP_MID);
    lv_obj_align_to(ui_PanelPrivacyPolicyContentmask, ui_PanelPrivacyPolicyContent, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_add_flag(ui_PanelPrivacyPolicyContentmask, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PanelPrivacyPolicyContentmask, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    //是否同意勾选框
    ui_CheckboxAgree = lv_checkbox_create(ui_PanelPrivacyPolicy);
    lv_checkbox_set_text(ui_CheckboxAgree, AgreePrivacyPolicy[language_index]);
    lv_obj_set_width(ui_CheckboxAgree, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_CheckboxAgree, LV_SIZE_CONTENT);    /// 1
    lv_obj_align(ui_CheckboxAgree, LV_ALIGN_TOP_MID, 0, 256);
    lv_obj_clear_flag(ui_CheckboxAgree, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_add_flag(ui_CheckboxAgree, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_CheckboxAgree, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CheckboxAgree, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CheckboxAgree, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CheckboxAgree, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_CheckboxAgree, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_CheckboxAgree, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui_CheckboxAgree, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_CheckboxAgree, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_CheckboxAgree, lv_color_hex(0x6A6C75), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CheckboxAgree, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CheckboxAgree, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CheckboxAgree, lv_color_hex(0x000000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CheckboxAgree, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_ext_click_area(ui_CheckboxAgree, 20);
    //选中后样式
    lv_obj_set_style_border_color(ui_CheckboxAgree, lv_color_hex(0xCDF6FF),
                                    LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_CheckboxAgree, 255, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_CheckboxAgree, 4, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_CheckboxAgree, 0, LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_CheckboxAgree, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_CheckboxAgree, lv_color_hex(0xCDF6FF), LV_PART_INDICATOR | LV_STATE_FOCUS_KEY);
  //  lv_obj_set_style_outline_color(ui_ManualtestCheckbox1, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_opa(ui_CheckboxAgree, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
  //  lv_obj_set_style_pad_all(ui_CheckboxAgree, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //上一步按钮
    ui_ButtonPrivacyPolicyLeft = lv_btn_create(ui_PanelPrivacyPolicy);
    lv_obj_set_width(ui_ButtonPrivacyPolicyLeft, 176);
    lv_obj_set_height(ui_ButtonPrivacyPolicyLeft, 52);
    lv_obj_set_x(ui_ButtonPrivacyPolicyLeft, 96);
    lv_obj_set_y(ui_ButtonPrivacyPolicyLeft, 294);
    lv_obj_add_flag(ui_ButtonPrivacyPolicyLeft, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonPrivacyPolicyLeft, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonPrivacyPolicyLeft, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonPrivacyPolicyLeft, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPrivacyPolicyLeft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonPrivacyPolicyLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonPrivacyPolicyLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_ButtonPrivacyPolicyLeft, lv_color_hex(0xFFFFFF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonPrivacyPolicyLeft, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonPrivacyPolicyLeft, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonPrivacyPolicyLeft, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonPrivacyPolicyLeft, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //上一步按钮标签
    ui_LabelPrivacyPolicyLeft = lv_label_create(ui_ButtonPrivacyPolicyLeft);
    lv_obj_set_width(ui_LabelPrivacyPolicyLeft, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelPrivacyPolicyLeft, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelPrivacyPolicyLeft, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelPrivacyPolicyLeft, PrevStep[language_index]);
    lv_obj_set_style_text_color(ui_LabelPrivacyPolicyLeft, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelPrivacyPolicyLeft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelPrivacyPolicyLeft, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //下一步按钮
    ui_ButtonPrivacyPolicyRight = lv_btn_create(ui_PanelPrivacyPolicy);
    lv_obj_set_width(ui_ButtonPrivacyPolicyRight, 176);
    lv_obj_set_height(ui_ButtonPrivacyPolicyRight, 52);
    lv_obj_set_x(ui_ButtonPrivacyPolicyRight, 368);
    lv_obj_set_y(ui_ButtonPrivacyPolicyRight, 294);
    lv_obj_add_flag(ui_ButtonPrivacyPolicyRight, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonPrivacyPolicyRight, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonPrivacyPolicyRight, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonPrivacyPolicyRight, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPrivacyPolicyRight, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonPrivacyPolicyRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonPrivacyPolicyRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_ButtonPrivacyPolicyRight, lv_color_hex(0xFFFFFF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonPrivacyPolicyRight, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonPrivacyPolicyRight, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonPrivacyPolicyRight, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonPrivacyPolicyRight, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //下一步按钮标签
    ui_LabelPrivacyPolicyRight = lv_label_create(ui_ButtonPrivacyPolicyRight);
    lv_obj_set_width(ui_LabelPrivacyPolicyRight, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelPrivacyPolicyRight, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelPrivacyPolicyRight, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelPrivacyPolicyRight, NextStep[language_index]);
    lv_obj_set_style_text_color(ui_LabelPrivacyPolicyRight, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelPrivacyPolicyRight, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelPrivacyPolicyRight, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_PanelPrivacyPolicyContent, ui_event_PanelPrivacyPolicyContent, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CheckboxAgree, ui_event_CheckboxAgree, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonPrivacyPolicyRight, ui_event_SelftestPrivacyPolicyRightButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonPrivacyPolicyLeft, ui_event_SelftestPrivacyPolicyLeftButton, LV_EVENT_ALL, NULL);

}

void privacy_policy_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_TitlePrivacyPolicy )
        lv_label_set_text(ui_TitlePrivacyPolicy, PrivacyPolicy[language_index]);
    
    if ( ui_LabelPrivacyPolicyRight )
        lv_label_set_text(ui_LabelPrivacyPolicyRight, NextStep[language_index]);
    
    if ( ui_LabelForeword )
        lv_label_set_text(ui_LabelForeword, ForewordArray[language_index]);
    
    if ( ui_LabelPrivacyPolicyLeft )
        lv_label_set_text(ui_LabelPrivacyPolicyLeft, PrevStep[language_index]);
    
    if ( ui_CheckboxAgree )
        lv_checkbox_set_text(ui_CheckboxAgree, AgreePrivacyPolicy[language_index]);

    if ( ui_LabelPrivacyPolicyContent )
        lv_checkbox_set_text(ui_LabelPrivacyPolicyContent, Privacycontent[language_index]);

    // if ( ui_LabelPrivacyPolicyContentPreview )
    //     lv_checkbox_set_text(ui_LabelPrivacyPolicyContentPreview, PrivacycontentPreview[1]);
        
    if (selftestflag)
    {
        lv_label_set_text(ui_LabelPrivacyPolicyLeft, PrevStep[language_index]);
        lv_label_set_text(ui_LabelPrivacyPolicyRight, NextStep[language_index]);
    }
    else
    {
        lv_label_set_text(ui_LabelPrivacyPolicyLeft, Reconsider[language_index]);
        lv_label_set_text(ui_LabelPrivacyPolicyRight, Confirm[language_index]);
    }

}

void LoadPrivacyPolicyScreen(void)
{
    uint8_t language_index = get_cur_language_index();
    lv_disp_load_scr(ui_SelftestPrivacyPolicy);
    if (selftestflag && !SelfTestDevicebindingFlag)
    {
        lv_obj_clear_flag(ui_CheckboxAgree, LV_OBJ_FLAG_HIDDEN);
        if (init_uiconfiginfo.AgreePrivacyPolicy)
        {
            lv_obj_add_state(ui_CheckboxAgree,LV_STATE_CHECKED);
        }
        else 
        {
            lv_obj_clear_state(ui_CheckboxAgree,LV_STATE_CHECKED);
        }
        lv_obj_set_height(ui_PanelPrivacyPolicyContent, 190);
        lv_label_set_text(ui_LabelPrivacyPolicyLeft, PrevStep[language_index]);
        lv_label_set_text(ui_LabelPrivacyPolicyRight, NextStep[language_index]);
    }
    else
    {
        lv_obj_add_flag(ui_CheckboxAgree, LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_height(ui_PanelPrivacyPolicyContent, 222);
        lv_label_set_text(ui_LabelPrivacyPolicyLeft, Reconsider[language_index]);
        lv_label_set_text(ui_LabelPrivacyPolicyRight, Agree[language_index]);
    }
    lv_obj_align_to(ui_PanelPrivacyPolicyContentmask, ui_PanelPrivacyPolicyContent, LV_ALIGN_BOTTOM_MID, 0, 0);
}

void LoadSelftestPrivacyPolicyPageAndObjs()
{
    LoadPage(ui_SelftestPrivacyPolicy, 1);
}

void SelftestPrivacyPolicyPageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    PageNode *PrivacyPolicyPage_node = find_page(ui_SelftestPrivacyPolicy);
    PrivacyPolicyPage_node->nav_level = index;
    switch (index) 
    {
    case 1:
        if (lv_obj_has_flag(ui_CheckboxAgree, LV_OBJ_FLAG_HIDDEN))
        {
            lv_group_add_obj(encoder_group, ui_ButtonPrivacyPolicyLeft);
            lv_group_add_obj(encoder_group, ui_ButtonPrivacyPolicyRight);
            lv_group_add_obj(encoder_group, ui_PanelPrivacyPolicyContent);
        }
        else 
        {
            lv_group_add_obj(encoder_group, ui_PanelPrivacyPolicyContent);
            lv_group_add_obj(encoder_group, ui_CheckboxAgree);
            lv_group_add_obj(encoder_group, ui_ButtonPrivacyPolicyLeft);
            lv_group_add_obj(encoder_group, ui_ButtonPrivacyPolicyRight);
        }
        break;
    case 2:
        // if (lv_obj_has_state(ui_CheckboxAgree, LV_STATE_CHECKED))
        // {
        //     lv_group_add_obj(encoder_group, ui_CheckboxAgree);
        //     lv_group_add_obj(encoder_group, ui_ButtonPrivacyPolicyLeft);
        //     lv_group_add_obj(encoder_group, ui_ButtonPrivacyPolicyRight);
        //     lv_group_add_obj(encoder_group, ui_PanelPrivacyPolicyContent);
        // }
        // else
        // {
        //     lv_group_add_obj(encoder_group, ui_CheckboxAgree);
        //     lv_group_add_obj(encoder_group, ui_ButtonPrivacyPolicyLeft);
        //     lv_group_add_obj(encoder_group, ui_ButtonPrivacyPolicyRight);
        //     lv_group_add_obj(encoder_group, ui_PanelPrivacyPolicyContent);
        // }
        break;
    default:
        break;
    }
    
}
