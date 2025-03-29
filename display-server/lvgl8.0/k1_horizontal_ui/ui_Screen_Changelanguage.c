#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "ui_Screen_Changelanguage.h"
#include "ui_Screen_Settings.h"
#include "mult_language.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_changelanguage;
lv_obj_t * ui_ButtonCloseScreenLanguage;
lv_obj_t * ui_ImageCloseScreenLanguage;
lv_obj_t * ui_changelanguagetitle;
lv_obj_t * ui_ChangelanguageButton1;
lv_obj_t * ui_ChangelanguageBtnlabel1;
lv_obj_t * ui_ChangelanguageButton2;
lv_obj_t * ui_ChangelanguageBtnlabel2;
lv_obj_t * ui_ChangelanguageButton3;
lv_obj_t * ui_ChangelanguageBtnlabel3;
lv_obj_t * ui_ChangelanguageButton4;
lv_obj_t * ui_ChangelanguageBtnlabel4;
lv_obj_t * ui_ChangelanguageButton5;
lv_obj_t * ui_ChangelanguageBtnlabel5;
lv_obj_t * ui_ChangelanguageButton6;
lv_obj_t * ui_ChangelanguageBtnlabel6;
lv_obj_t * ui_ChangelanguageButton7;
lv_obj_t * ui_ChangelanguageBtnlabel7;
lv_obj_t * ui_ChangelanguageButton8;
lv_obj_t * ui_ChangelanguageBtnlabel8;
lv_obj_t * ui_ChangelanguageButton9;
lv_obj_t * ui_ChangelanguageBtnlabel9;
lv_obj_t * ui_ChangelanguageButtonTen;
lv_obj_t * ui_ChangelanguageBtnlabelTen;
lv_obj_t * ui_ChangelanguageButton11;
lv_obj_t * ui_ChangelanguageBtnlabel11;
lv_obj_t * ui_ScreenLanguageButtonConfirm;
lv_obj_t * ui_ScreenLanguageLabelConfirm;
lv_timer_t * timerHandleJumpSelf = NULL;

/**************custom variable************************/
static char *languages_array[11] = {"中文", "English", "Deutsch", "Español", "Français", 
                                    "Italiano", "Português", "Русский", "Turkish", "日本語","한국인"};

static int language_sign = 0;  //根据协议字符‘0’到字符‘9’分别对饮10中语言协议中确定的
///////////////////// FUNCTIONS ////////////////////
void ui_event_changelanguage(lv_event_t * e);
static void ui_event_BtnCloseLanguage(lv_event_t * e);
static void ui_event_BtnConfirmLanguage(lv_event_t * e);
static void language_btn_selected(uint8_t language_index);  //index 同字符‘0’到字符‘9’
static void ui_event_Pageinit(lv_event_t * e);

#define JUMP_SELFTEST_FILENAME  "debugmode_JumpSelftest"

char *GetJumpSelftestFileName(void){ return JUMP_SELFTEST_FILENAME;}
char *GetSELFTESTFIRMWAREFileName(void){ return SELFTEST_FIRMWARE;}

void ui_changelanguage_screen_init(void)
{
    ui_changelanguage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_changelanguage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_changelanguage, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_changelanguage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonCloseScreenLanguage = lv_btn_create(ui_changelanguage);
    lv_obj_set_width(ui_ButtonCloseScreenLanguage, 120);
    lv_obj_set_height(ui_ButtonCloseScreenLanguage, 50);
    lv_obj_set_x(ui_ButtonCloseScreenLanguage, 20);
    lv_obj_set_y(ui_ButtonCloseScreenLanguage, 10);
    lv_obj_add_flag(ui_ButtonCloseScreenLanguage, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonCloseScreenLanguage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonCloseScreenLanguage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonCloseScreenLanguage, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonCloseScreenLanguage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonCloseScreenLanguage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonCloseScreenLanguage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageCloseScreenLanguage = lv_img_create(ui_ButtonCloseScreenLanguage);
    lv_obj_set_width(ui_ImageCloseScreenLanguage, 23);
    lv_obj_set_height(ui_ImageCloseScreenLanguage, 23);
    lv_obj_set_x(ui_ImageCloseScreenLanguage, -11);
    lv_obj_set_y(ui_ImageCloseScreenLanguage, 0);
    //lv_obj_add_flag(ui_ImageCloseScreenLanguage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageCloseScreenLanguage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    //lv_img_set_src(ui_ImageCloseScreenLanguage, &ui_img_cross_png);
    lv_img_set_src(ui_ImageCloseScreenLanguage, &ui_img_close_png);

    ui_changelanguagetitle = lv_label_create(ui_changelanguage);
    lv_obj_set_width(ui_changelanguagetitle, 400);
    lv_obj_set_height(ui_changelanguagetitle, 32);
    lv_obj_set_x(ui_changelanguagetitle, 200);
    lv_obj_set_y(ui_changelanguagetitle, 20);
    lv_obj_set_align(ui_changelanguagetitle, LV_ALIGN_TOP_LEFT);
    lv_label_set_text(ui_changelanguagetitle, LanguageSelection[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_changelanguagetitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_changelanguagetitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_changelanguagetitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_changelanguagetitle, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageButton1 = lv_btn_create(ui_changelanguage);
    lv_obj_set_width(ui_ChangelanguageButton1, 175);
    lv_obj_set_height(ui_ChangelanguageButton1, 90);
    lv_obj_set_x(ui_ChangelanguageButton1, 20);
    lv_obj_set_y(ui_ChangelanguageButton1, 73);
    lv_obj_add_flag(ui_ChangelanguageButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ChangelanguageButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ChangelanguageButton1, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton1, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ChangelanguageButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ChangelanguageButton1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ChangelanguageButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ChangelanguageButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    uint8_t index = 0;
    ui_ChangelanguageBtnlabel1 = lv_label_create(ui_ChangelanguageButton1);
    lv_obj_set_width(ui_ChangelanguageBtnlabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChangelanguageBtnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ChangelanguageBtnlabel1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChangelanguageBtnlabel1, languages_array[index++]);
    lv_obj_set_style_text_color(ui_ChangelanguageBtnlabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageBtnlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ChangelanguageBtnlabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageBtnlabel1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageButton2 = lv_btn_create(ui_changelanguage);
    lv_obj_set_width(ui_ChangelanguageButton2, 175);
    lv_obj_set_height(ui_ChangelanguageButton2, 90);
    lv_obj_set_x(ui_ChangelanguageButton2, 215);
    lv_obj_set_y(ui_ChangelanguageButton2, 73);
    lv_obj_add_flag(ui_ChangelanguageButton2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ChangelanguageButton2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ChangelanguageButton2, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton2, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ChangelanguageButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ChangelanguageButton2, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ChangelanguageButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ChangelanguageButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageBtnlabel2 = lv_label_create(ui_ChangelanguageButton2);
    lv_obj_set_width(ui_ChangelanguageBtnlabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChangelanguageBtnlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ChangelanguageBtnlabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChangelanguageBtnlabel2, languages_array[index++]);
    lv_obj_set_style_text_color(ui_ChangelanguageBtnlabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageBtnlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ChangelanguageBtnlabel2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageBtnlabel2, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageButton3 = lv_btn_create(ui_changelanguage);
    lv_obj_set_width(ui_ChangelanguageButton3, 175);
    lv_obj_set_height(ui_ChangelanguageButton3, 90);
    lv_obj_set_x(ui_ChangelanguageButton3, 410);
    lv_obj_set_y(ui_ChangelanguageButton3, 73);
    lv_obj_add_flag(ui_ChangelanguageButton3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ChangelanguageButton3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ChangelanguageButton3, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton3, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ChangelanguageButton3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ChangelanguageButton3, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ChangelanguageButton3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ChangelanguageButton3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageBtnlabel3 = lv_label_create(ui_ChangelanguageButton3);
    lv_obj_set_width(ui_ChangelanguageBtnlabel3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChangelanguageBtnlabel3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ChangelanguageBtnlabel3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChangelanguageBtnlabel3, languages_array[index++]);
    lv_obj_set_style_text_color(ui_ChangelanguageBtnlabel3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageBtnlabel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ChangelanguageBtnlabel3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageBtnlabel3, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageButton4 = lv_btn_create(ui_changelanguage);
    lv_obj_set_width(ui_ChangelanguageButton4, 175);
    lv_obj_set_height(ui_ChangelanguageButton4, 90);
    lv_obj_set_x(ui_ChangelanguageButton4, 605);
    lv_obj_set_y(ui_ChangelanguageButton4, 73);
    lv_obj_add_flag(ui_ChangelanguageButton4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ChangelanguageButton4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ChangelanguageButton4, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton4, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ChangelanguageButton4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ChangelanguageButton4, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ChangelanguageButton4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ChangelanguageButton4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageBtnlabel4 = lv_label_create(ui_ChangelanguageButton4);
    lv_obj_set_width(ui_ChangelanguageBtnlabel4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChangelanguageBtnlabel4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ChangelanguageBtnlabel4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChangelanguageBtnlabel4, languages_array[index++]);
    lv_obj_set_style_text_color(ui_ChangelanguageBtnlabel4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageBtnlabel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ChangelanguageBtnlabel4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageBtnlabel4, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageButton5 = lv_btn_create(ui_changelanguage);
    lv_obj_set_width(ui_ChangelanguageButton5, 175);
    lv_obj_set_height(ui_ChangelanguageButton5, 90);
    lv_obj_set_x(ui_ChangelanguageButton5, 20);
    lv_obj_set_y(ui_ChangelanguageButton5, 181);
    lv_obj_add_flag(ui_ChangelanguageButton5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ChangelanguageButton5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ChangelanguageButton5, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton5, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ChangelanguageButton5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ChangelanguageButton5, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ChangelanguageButton5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ChangelanguageButton5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageBtnlabel5 = lv_label_create(ui_ChangelanguageButton5);
    lv_obj_set_width(ui_ChangelanguageBtnlabel5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChangelanguageBtnlabel5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ChangelanguageBtnlabel5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChangelanguageBtnlabel5, languages_array[index++]);
    lv_obj_set_style_text_color(ui_ChangelanguageBtnlabel5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageBtnlabel5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ChangelanguageBtnlabel5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageBtnlabel5, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageButton6 = lv_btn_create(ui_changelanguage);
    lv_obj_set_width(ui_ChangelanguageButton6, 175);
    lv_obj_set_height(ui_ChangelanguageButton6, 90);
    lv_obj_set_x(ui_ChangelanguageButton6, 215);
    lv_obj_set_y(ui_ChangelanguageButton6, 181);
    lv_obj_add_flag(ui_ChangelanguageButton6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ChangelanguageButton6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ChangelanguageButton6, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton6, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ChangelanguageButton6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ChangelanguageButton6, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ChangelanguageButton6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ChangelanguageButton6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageBtnlabel6 = lv_label_create(ui_ChangelanguageButton6);
    lv_obj_set_width(ui_ChangelanguageBtnlabel6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChangelanguageBtnlabel6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ChangelanguageBtnlabel6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChangelanguageBtnlabel6, languages_array[index++]);
    lv_obj_set_style_text_color(ui_ChangelanguageBtnlabel6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageBtnlabel6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ChangelanguageBtnlabel6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageBtnlabel6, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageButton7 = lv_btn_create(ui_changelanguage);
    lv_obj_set_width(ui_ChangelanguageButton7, 175);
    lv_obj_set_height(ui_ChangelanguageButton7, 90);
    lv_obj_set_x(ui_ChangelanguageButton7, 410);
    lv_obj_set_y(ui_ChangelanguageButton7, 181);
    lv_obj_add_flag(ui_ChangelanguageButton7, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ChangelanguageButton7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ChangelanguageButton7, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton7, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ChangelanguageButton7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ChangelanguageButton7, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ChangelanguageButton7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ChangelanguageButton7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageBtnlabel7 = lv_label_create(ui_ChangelanguageButton7);
    lv_obj_set_width(ui_ChangelanguageBtnlabel7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChangelanguageBtnlabel7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ChangelanguageBtnlabel7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChangelanguageBtnlabel7, languages_array[index++]);
    lv_obj_set_style_text_color(ui_ChangelanguageBtnlabel7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageBtnlabel7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ChangelanguageBtnlabel7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageBtnlabel7, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageButton8 = lv_btn_create(ui_changelanguage);
    lv_obj_set_width(ui_ChangelanguageButton8, 175);
    lv_obj_set_height(ui_ChangelanguageButton8, 90);
    lv_obj_set_x(ui_ChangelanguageButton8, 605);
    lv_obj_set_y(ui_ChangelanguageButton8, 181);
    lv_obj_add_flag(ui_ChangelanguageButton8, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ChangelanguageButton8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ChangelanguageButton8, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton8, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ChangelanguageButton8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ChangelanguageButton8, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ChangelanguageButton8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ChangelanguageButton8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageBtnlabel8 = lv_label_create(ui_ChangelanguageButton8);
    lv_obj_set_width(ui_ChangelanguageBtnlabel8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChangelanguageBtnlabel8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ChangelanguageBtnlabel8, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChangelanguageBtnlabel8, languages_array[index++]);
    lv_obj_set_style_text_color(ui_ChangelanguageBtnlabel8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageBtnlabel8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ChangelanguageBtnlabel8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageBtnlabel8, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageButton9 = lv_btn_create(ui_changelanguage);
    lv_obj_set_width(ui_ChangelanguageButton9, 175);
    lv_obj_set_height(ui_ChangelanguageButton9, 90);
    lv_obj_set_x(ui_ChangelanguageButton9, 20);
    lv_obj_set_y(ui_ChangelanguageButton9, 289);
    lv_obj_add_flag(ui_ChangelanguageButton9, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ChangelanguageButton9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ChangelanguageButton9, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton9, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ChangelanguageButton9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ChangelanguageButton9, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ChangelanguageButton9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ChangelanguageButton9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageBtnlabel9 = lv_label_create(ui_ChangelanguageButton9);
    lv_obj_set_width(ui_ChangelanguageBtnlabel9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChangelanguageBtnlabel9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ChangelanguageBtnlabel9, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChangelanguageBtnlabel9, languages_array[index++]);
    lv_obj_set_style_text_color(ui_ChangelanguageBtnlabel9, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageBtnlabel9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ChangelanguageBtnlabel9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageBtnlabel9, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageButtonTen = lv_btn_create(ui_changelanguage);
    lv_obj_set_width(ui_ChangelanguageButtonTen, 175);
    lv_obj_set_height(ui_ChangelanguageButtonTen, 90);
    lv_obj_set_x(ui_ChangelanguageButtonTen, 215);
    lv_obj_set_y(ui_ChangelanguageButtonTen, 289);
    lv_obj_add_flag(ui_ChangelanguageButtonTen, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ChangelanguageButtonTen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ChangelanguageButtonTen, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ChangelanguageButtonTen, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ChangelanguageButtonTen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ChangelanguageButtonTen, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ChangelanguageButtonTen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButtonTen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ChangelanguageButtonTen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ChangelanguageButtonTen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageBtnlabelTen = lv_label_create(ui_ChangelanguageButtonTen);
    lv_obj_set_width(ui_ChangelanguageBtnlabelTen, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChangelanguageBtnlabelTen, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ChangelanguageBtnlabelTen, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChangelanguageBtnlabelTen, languages_array[index++]);
    lv_obj_set_style_text_color(ui_ChangelanguageBtnlabelTen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageBtnlabelTen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ChangelanguageBtnlabelTen, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageBtnlabelTen, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageButton11 = lv_btn_create(ui_changelanguage);
    lv_obj_set_width(ui_ChangelanguageButton11, 175);
    lv_obj_set_height(ui_ChangelanguageButton11, 90);
    lv_obj_align_to(ui_ChangelanguageButton11, ui_ChangelanguageButtonTen, LV_ALIGN_OUT_RIGHT_MID, 20, 0);
    lv_obj_add_flag(ui_ChangelanguageButton11, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ChangelanguageButton11, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ChangelanguageButton11, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton11, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ChangelanguageButton11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ChangelanguageButton11, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ChangelanguageButton11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ChangelanguageButton11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ChangelanguageBtnlabel11 = lv_label_create(ui_ChangelanguageButton11);
    lv_obj_set_width(ui_ChangelanguageBtnlabel11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ChangelanguageBtnlabel11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_ChangelanguageBtnlabel11, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ChangelanguageBtnlabel11, languages_array[index++]);
    lv_obj_set_style_text_color(ui_ChangelanguageBtnlabel11, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageBtnlabel11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ChangelanguageBtnlabel11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageBtnlabel11, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenLanguageButtonConfirm = lv_btn_create(ui_changelanguage);
    lv_obj_set_width(ui_ScreenLanguageButtonConfirm, 146);
    lv_obj_set_height(ui_ScreenLanguageButtonConfirm, 60);
    lv_obj_set_x(ui_ScreenLanguageButtonConfirm, 328);
    lv_obj_set_y(ui_ScreenLanguageButtonConfirm, 400);
    lv_obj_add_flag(ui_ScreenLanguageButtonConfirm, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ScreenLanguageButtonConfirm, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScreenLanguageButtonConfirm, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScreenLanguageButtonConfirm, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenLanguageButtonConfirm, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ScreenLanguageButtonConfirm, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ScreenLanguageButtonConfirm, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenLanguageLabelConfirm = lv_label_create(ui_ScreenLanguageButtonConfirm);
    lv_obj_set_width(ui_ScreenLanguageLabelConfirm, 146);
    lv_obj_set_height(ui_ScreenLanguageLabelConfirm, 30);
    lv_obj_set_align(ui_ScreenLanguageLabelConfirm, LV_ALIGN_CENTER);
    lv_label_set_text(ui_ScreenLanguageLabelConfirm, Confirm[get_cur_language_index()]);
    lv_obj_set_style_text_align(ui_ScreenLanguageLabelConfirm, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScreenLanguageLabelConfirm, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_ChangelanguageButton1, ui_event_changelanguage, LV_EVENT_ALL, "0");
    lv_obj_add_event_cb(ui_ChangelanguageButton2, ui_event_changelanguage, LV_EVENT_ALL, "1");
    lv_obj_add_event_cb(ui_ChangelanguageButton3, ui_event_changelanguage, LV_EVENT_ALL, "2");
    lv_obj_add_event_cb(ui_ChangelanguageButton4, ui_event_changelanguage, LV_EVENT_ALL, "3");
    lv_obj_add_event_cb(ui_ChangelanguageButton5, ui_event_changelanguage, LV_EVENT_ALL, "4");
    lv_obj_add_event_cb(ui_ChangelanguageButton6, ui_event_changelanguage, LV_EVENT_ALL, "5");
    lv_obj_add_event_cb(ui_ChangelanguageButton7, ui_event_changelanguage, LV_EVENT_ALL, "6");
    lv_obj_add_event_cb(ui_ChangelanguageButton8, ui_event_changelanguage, LV_EVENT_ALL, "7");
    lv_obj_add_event_cb(ui_ChangelanguageButton9, ui_event_changelanguage, LV_EVENT_ALL, "8");
    lv_obj_add_event_cb(ui_ChangelanguageButtonTen, ui_event_changelanguage, LV_EVENT_ALL, "9");
    lv_obj_add_event_cb(ui_ChangelanguageButton11, ui_event_changelanguage, LV_EVENT_ALL, "A");

    lv_obj_add_event_cb(ui_ButtonCloseScreenLanguage, ui_event_BtnCloseLanguage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ScreenLanguageButtonConfirm, ui_event_BtnConfirmLanguage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_changelanguage, ui_event_Pageinit, LV_EVENT_ALL, NULL);
}

///////////////////// EVENTS ////////////////////
void ui_event_changelanguage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        char *userdata = lv_event_get_user_data(e);
        CrLogI("change language btn clicked,:%s",userdata);
        if ( userdata != NULL)
        {
            int language = 0;
            switch (userdata[0])
            {
                case '0':language = 0;break;
                case '1':language = 1;break;
                case '2':language = 2;break;
                case '3':language = 3;break;
                case '4':language = 4;break;
                case '5':language = 5;break;
                case '6':language = 6;break;
                case '7':language = 7;break;
                case '8':language = 8;break;
                case '9':language = 9;break;
                case 'A':language = 10;break;
                default:language = 0;break;
            }
            CrLogI("change lanicked,:%d",language);
            language_sign = language;
            language_btn_selected(language);
        }
    }
}

void ui_event_BtnCloseLanguage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        LoadSettingsScreen();
    }
}

static void ui_event_BtnConfirmLanguage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        wifi_wait_animmotion(true);
        CrLogI("change language :%d", language_sign);
        if ( (language_sign >= 0) && (language_sign <= 10) )
            send_set_language_cmd(language_sign);
        else
            send_set_language_cmd(0);
    }
}

void timerHadnle(lv_timer_t * timer)
{
    CrLogI("check the udisk exist.");
    if(system_state.Udisk_state)
    {
        char tempbuff[300] = {0};
        snprintf(tempbuff, 256, "%s/%s", GetPrintRunState().uDiskPath, GetSELFTESTFIRMWAREFileName());
        CrLogI("the path %s", tempbuff);
        //检查U盘是否有特定文件，有则进入固件老化测试流程
        if(access(tempbuff, F_OK) == 0)
        {
            _ui_screen_change(ui_SelftestAll, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
            return;
        }
        memset(tempbuff, 0, sizeof(tempbuff));
        snprintf(tempbuff, 256, "%s/%s", GetPrintRunState().uDiskPath, GetJumpSelftestFileName());
        CrLogI("the path %s", tempbuff);
        //检查U盘中是否有特定文件，有则跳过开机自检
        if(access(tempbuff, F_OK) == 0)
        {
            LoadHomeNormalScreen();
        }
    }
}

static void ui_event_Pageinit(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load the changelanguage.");
        language_change_language_text();    //页面刷新实时的语言选择
        language_btn_selected(get_cur_language_index());
        language_sign = get_cur_language_index();
        lv_obj_add_flag(ui_ChangelanguageButton11, LV_OBJ_FLAG_HIDDEN);
        if(selftestflag)
        {
            lv_obj_add_flag(ui_ButtonCloseScreenLanguage, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(ui_ScreenLanguageLabelConfirm, NextStep[get_cur_language_index()]);

            //创建定时器检查U盘是否连接
            timerHandleJumpSelf = lv_timer_create(timerHadnle, 1000 * 3, NULL);
        }
        else
        {
            lv_obj_clear_flag(ui_ButtonCloseScreenLanguage, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(ui_ScreenLanguageLabelConfirm, Confirm[get_cur_language_index()]);
        }
    }   
    else if(event_code == LV_EVENT_SCREEN_UNLOADED)
    {
        if(selftestflag)
        {
            lv_timer_set_repeat_count(timerHandleJumpSelf, 0);
            timerHandleJumpSelf = NULL;
        }
    }
}

void language_btn_selected(uint8_t language_index)
{
    lv_obj_set_style_border_width(ui_ChangelanguageButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButtonTen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ChangelanguageButton11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    switch (language_index)
    {
    case 0:lv_obj_set_style_border_width(ui_ChangelanguageButton1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);break;
    case 1:lv_obj_set_style_border_width(ui_ChangelanguageButton2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);break;
    case 2:lv_obj_set_style_border_width(ui_ChangelanguageButton3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);break;
    case 3:lv_obj_set_style_border_width(ui_ChangelanguageButton4, 2, LV_PART_MAIN | LV_STATE_DEFAULT);break;
    case 4:lv_obj_set_style_border_width(ui_ChangelanguageButton5, 2, LV_PART_MAIN | LV_STATE_DEFAULT);break;
    case 5:lv_obj_set_style_border_width(ui_ChangelanguageButton6, 2, LV_PART_MAIN | LV_STATE_DEFAULT);break;
    case 6:lv_obj_set_style_border_width(ui_ChangelanguageButton7, 2, LV_PART_MAIN | LV_STATE_DEFAULT);break;
    case 7:lv_obj_set_style_border_width(ui_ChangelanguageButton8, 2, LV_PART_MAIN | LV_STATE_DEFAULT);break;
    case 8:lv_obj_set_style_border_width(ui_ChangelanguageButton9, 2, LV_PART_MAIN | LV_STATE_DEFAULT);break;
    case 9:lv_obj_set_style_border_width(ui_ChangelanguageButtonTen,2, LV_PART_MAIN | LV_STATE_DEFAULT);break;
    case 10:lv_obj_set_style_border_width(ui_ChangelanguageButton11,2, LV_PART_MAIN | LV_STATE_DEFAULT);break;
    default:lv_obj_set_style_border_width(ui_ChangelanguageButton1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);break;
    }
    if ( ui_changelanguagetitle )
        lv_label_set_text(ui_changelanguagetitle, LanguageSelection[language_index]);
    
    if ( ui_ScreenLanguageLabelConfirm )
    {
        if ( selftestflag )
        {
            lv_label_set_text(ui_ScreenLanguageLabelConfirm, NextStep[language_index]);
        }
        else
            lv_label_set_text(ui_ScreenLanguageLabelConfirm, Confirm[language_index]);
    }
}

char *language_get_cur_language_text(int8_t language_index)
{
    if ( cur_language < 0 || cur_language > MAX_LANGUAGE - 1)
        return NULL;
    
    language_btn_selected(language_index);

    return languages_array[language_index];
}

void language_change_language_text(void)
{
    if ( ui_changelanguagetitle )
        lv_label_set_text(ui_changelanguagetitle, LanguageSelection[get_cur_language_index()]);
    
    if ( ui_ScreenLanguageLabelConfirm )
    {
        if ( selftestflag )
        {
            lv_label_set_text(ui_ScreenLanguageLabelConfirm, NextStep[get_cur_language_index()]);
        }
        else
            lv_label_set_text(ui_ScreenLanguageLabelConfirm, Confirm[get_cur_language_index()]);
    }
        
}

void change_language_end(unsigned char language)
{
    CrLogI("change end");
    if ( selftestflag ) 
    {
        _ui_screen_change(ui_BootPart0, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
    else
    {
        LoadSettingsScreen();
    }
    wifi_wait_animmotion(false);
}