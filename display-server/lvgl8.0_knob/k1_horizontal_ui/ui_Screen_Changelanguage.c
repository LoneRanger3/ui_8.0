#include "k1_horizontal_ui/ui_custom_vedioinfo_part.h"
#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "ui_Screen_Changelanguage.h"
#include "ui_Screen_Settings.h"
#include "mult_language.h"
#include "page_switch.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_changelanguage;
lv_obj_t * ui_changelanguage_list;
lv_obj_t * ui_ButtonCloseScreenLanguage;
lv_obj_t * ui_ImageCloseScreenLanguage;
lv_obj_t * ui_changelanguagetitle;
lv_obj_t * ui_ChangelanguageButton1;
lv_obj_t * ui_ChangelanguageBtnlabel1;
lv_obj_t * ui_ImageOkScreenLanguage1;
lv_obj_t * ui_ChangelanguageButton2;
lv_obj_t * ui_ChangelanguageBtnlabel2;
lv_obj_t * ui_ImageOkScreenLanguage2;
lv_obj_t * ui_ChangelanguageButton3;
lv_obj_t * ui_ChangelanguageBtnlabel3;
lv_obj_t * ui_ImageOkScreenLanguage3;
lv_obj_t * ui_ChangelanguageButton4;
lv_obj_t * ui_ChangelanguageBtnlabel4;
lv_obj_t * ui_ImageOkScreenLanguage4;
lv_obj_t * ui_ChangelanguageButton5;
lv_obj_t * ui_ChangelanguageBtnlabel5;
lv_obj_t * ui_ImageOkScreenLanguage5;
lv_obj_t * ui_ChangelanguageButton6;
lv_obj_t * ui_ChangelanguageBtnlabel6;
lv_obj_t * ui_ImageOkScreenLanguage6;
lv_obj_t * ui_ChangelanguageButton7;
lv_obj_t * ui_ChangelanguageBtnlabel7;
lv_obj_t * ui_ImageOkScreenLanguage7;
lv_obj_t * ui_ChangelanguageButton8;
lv_obj_t * ui_ChangelanguageBtnlabel8;
lv_obj_t * ui_ImageOkScreenLanguage8;
lv_obj_t * ui_ChangelanguageButton9;
lv_obj_t * ui_ChangelanguageBtnlabel9;
lv_obj_t * ui_ImageOkScreenLanguage9;
lv_obj_t * ui_ChangelanguageButtonTen;
lv_obj_t * ui_ChangelanguageBtnlabelTen;
lv_obj_t * ui_ImageOkScreenLanguageTen;
lv_obj_t * ui_ScreenLanguageButtonConfirm;
lv_obj_t * ui_ScreenLanguageLabelConfirm;
lv_timer_t * timerHandleJumpSelf = NULL;

/**************custom variable************************/
static char *languages_array[10] = {"中文", "English", "Deutsch", "Español", "Français", 
                                    "Italiano", "Português", "Русский", "Turkish", "日本語"};

static bool is_start_up_guide = false;
static char language_sign = '0';  //根据协议字符‘0’到字符‘9’分别对饮10中语言协议中确定的
static lv_group_t * changelanguage_g;

///////////////////// FUNCTIONS ////////////////////
void ui_event_changelanguage(lv_event_t * e);
static void ui_event_BtnCloseLanguage(lv_event_t * e);
static void ui_BtnConfirmLanguage(void);
static void language_btn_selected(uint8_t language_index);  //index 同字符‘0’到字符‘9’
static void ui_event_Pageinit(lv_event_t * e);

void LoadChangeLanguageScreen(void);


char *GetJumpSelftestFileName(void){ return JUMP_SELFTEST_FILENAME;}
char *GetSELFTESTFIRMWAREFileName(void){ return SELFTEST_FIRMWARE;}

void ui_changelanguage_screen_init(void)
{
    ui_changelanguage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_changelanguage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_changelanguage, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_changelanguage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_changelanguage, 6, LV_PART_MAIN | LV_STATE_DEFAULT);

    init_pages(ui_changelanguage, language_change_event_grop, LoadChangeLanguageScreen);

    /* 语言选择 */
    ui_changelanguagetitle = lv_label_create(ui_changelanguage);
    lv_obj_set_width(ui_changelanguagetitle, 138);
    lv_obj_set_height(ui_changelanguagetitle, 32);
    //lv_obj_set_x(ui_changelanguagetitle, 251);
    lv_obj_set_y(ui_changelanguagetitle, 75);//75
    
    lv_obj_set_size(ui_changelanguagetitle,LV_SIZE_CONTENT,70);
    lv_obj_set_align(ui_changelanguagetitle, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_changelanguagetitle, LanguageSelection[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_changelanguagetitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_changelanguagetitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_changelanguagetitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_changelanguagetitle, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);


    /*创建语言选择列表*/
    ui_changelanguage_list = lv_list_create(ui_changelanguage);
    lv_obj_set_x(ui_changelanguage_list, 10);
    lv_obj_set_y(ui_changelanguage_list, 121);//121
    lv_obj_set_size(ui_changelanguage_list, 622, 281);
   // lv_obj_center(ui_changelanguage_list);
    lv_obj_set_style_bg_color(ui_changelanguage_list, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
   // lv_obj_set_style_radius(ui_changelanguage_list, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_changelanguage_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_changelanguage_list, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_changelanguage_list, LV_ALIGN_CENTER, 0, 20);

    
   // lv_obj_set_style_border_color(ui_changelanguage_list, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUSED);
   // lv_label_set_long_mode(ui_changelanguage_list, LV_LABEL_LONG_DOT);
    // 设置水平滚动吸附位置为一页的宽度
   // lv_obj_set_scroll_snap_y(ui_changelanguage_list, lv_obj_get_height(ui_changelanguage_list));
     
    //设置scrollbar
#if 0
    lv_obj_set_style_border_width(ui_changelanguage_list, 3, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_changelanguage_list, 255, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_changelanguage_list, LV_BORDER_SIDE_FULL, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);//border 边款填充
    lv_obj_set_style_width(ui_changelanguage_list, 11,  LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_height(ui_changelanguage_list, 238,  LV_PART_MAIN| LV_STATE_DEFAULT);
    lv_obj_set_style_x(ui_changelanguage_list, 621, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    
    lv_obj_set_style_bg_color(ui_changelanguage_list,  lv_color_hex(0x9B9FA8), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
//     lv_obj_set_style_border_width(ui_changelanguage_list, 3, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_changelanguage_list, lv_color_hex(0x9B9FA8), LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
   // lv_obj_set_style_outline_width(ui_changelanguage_list, 3, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);
#endif
    uint8_t index = 0;

    ui_ChangelanguageButton1 = lv_list_add_btn(ui_changelanguage_list, NULL, languages_array[index++]);
    lv_obj_set_size(ui_ChangelanguageButton1, 574, 56);//572
    lv_obj_set_style_border_width(ui_ChangelanguageButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT); //列表项下边框写为0则不会显示
	//lv_obj_set_flex_align(ui_ChangelanguageButton1, lv_flex_align_t main_place, lv_flex_align_t cross_place, lv_flex_align_t track_cross_place)
    lv_obj_set_flex_align(ui_ChangelanguageButton1, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT); // 列表项背景
    lv_obj_set_style_bg_color(ui_ChangelanguageButton1, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUS_KEY); //列表选中后背景色
    lv_obj_set_style_border_color(ui_ChangelanguageButton1, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY); //边框颜色
    lv_obj_set_style_border_width(ui_ChangelanguageButton1, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton1, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_ChangelanguageButton1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);//border 边款填充
    lv_obj_set_style_radius(ui_ChangelanguageButton1, 6, LV_PART_MAIN | LV_STATE_FOCUS_KEY); // 设置列表选中矩形的圆角
    //lv_obj_set_style_pad_row(ui_ChangelanguageButton1, 24, LV_PART_KNOB | LV_STATE_DEFAULT); //行间距设置
    lv_obj_set_style_pad_all(ui_ChangelanguageButton1, 0, LV_PART_KNOB | LV_STATE_DEFAULT|LV_STATE_FOCUS_KEY); //行间距设置
    lv_obj_set_style_text_color(ui_ChangelanguageButton1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_align(ui_ChangelanguageButton1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageButton1, lv_font30.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_ImageOkScreenLanguage1 = lv_img_create(ui_ChangelanguageButton1);
    lv_img_set_src(ui_ImageOkScreenLanguage1, &ui_imag_ok_png);
    lv_obj_add_flag(ui_ImageOkScreenLanguage1, LV_OBJ_FLAG_HIDDEN);

    ui_ChangelanguageButton2 = lv_list_add_btn(ui_changelanguage_list, NULL, languages_array[index++]);
    lv_obj_set_size(ui_ChangelanguageButton2, 574, 56);
    lv_obj_set_style_border_width(ui_ChangelanguageButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT); //列表项下边框写为0则不会显示
    lv_obj_set_flex_align(ui_ChangelanguageButton2, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT); // 列表项背景
    lv_obj_set_style_bg_color(ui_ChangelanguageButton2, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUS_KEY); //列表选中后背景色
    lv_obj_set_style_border_color(ui_ChangelanguageButton2, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ChangelanguageButton2, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton2, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_ChangelanguageButton2, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);//border 边款填充
    lv_obj_set_style_radius(ui_ChangelanguageButton2, 6, LV_PART_MAIN | LV_STATE_FOCUS_KEY); // 设置列表选中矩形的圆角
    lv_obj_set_style_pad_row(ui_ChangelanguageButton2, 24, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ChangelanguageButton2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageButton2, lv_font30.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageOkScreenLanguage2 = lv_img_create(ui_ChangelanguageButton2);
    lv_img_set_src(ui_ImageOkScreenLanguage2, &ui_imag_ok_png);
    lv_obj_add_flag(ui_ImageOkScreenLanguage2, LV_OBJ_FLAG_HIDDEN);
   
   
    ui_ChangelanguageButton3 = lv_list_add_btn(ui_changelanguage_list, NULL, languages_array[index++]);
    lv_obj_set_size(ui_ChangelanguageButton3, 574, 56);//572
    lv_obj_set_style_border_width(ui_ChangelanguageButton3, 0, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_flex_align(ui_ChangelanguageButton3, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_bg_color(ui_ChangelanguageButton3, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_color(ui_ChangelanguageButton3, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_width(ui_ChangelanguageButton3, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton3, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_ChangelanguageButton3, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(ui_ChangelanguageButton3, 6, LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_pad_all(ui_ChangelanguageButton3, 0, LV_PART_KNOB | LV_STATE_DEFAULT|LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_text_color(ui_ChangelanguageButton3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageButton3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageButton3, lv_font30.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageOkScreenLanguage3 = lv_img_create(ui_ChangelanguageButton3);
    lv_img_set_src(ui_ImageOkScreenLanguage3, &ui_imag_ok_png);
    lv_obj_add_flag(ui_ImageOkScreenLanguage3, LV_OBJ_FLAG_HIDDEN);


    ui_ChangelanguageButton4 = lv_list_add_btn(ui_changelanguage_list, NULL, languages_array[index++]);
    lv_obj_set_size(ui_ChangelanguageButton4, 574, 56);//572
    lv_obj_set_style_border_width(ui_ChangelanguageButton4, 0, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_flex_align(ui_ChangelanguageButton4, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_bg_color(ui_ChangelanguageButton4, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_color(ui_ChangelanguageButton4, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_width(ui_ChangelanguageButton4, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton4, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_ChangelanguageButton4, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(ui_ChangelanguageButton4, 6, LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_pad_all(ui_ChangelanguageButton4, 0, LV_PART_KNOB | LV_STATE_DEFAULT|LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_text_color(ui_ChangelanguageButton4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageButton4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageButton4, lv_font30.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageOkScreenLanguage4 = lv_img_create(ui_ChangelanguageButton4);
    lv_img_set_src(ui_ImageOkScreenLanguage4, &ui_imag_ok_png);
    lv_obj_add_flag(ui_ImageOkScreenLanguage4, LV_OBJ_FLAG_HIDDEN);

    ui_ChangelanguageButton5 = lv_list_add_btn(ui_changelanguage_list, NULL, languages_array[index++]);
    lv_obj_set_size(ui_ChangelanguageButton5, 574, 56);//572
    lv_obj_set_style_border_width(ui_ChangelanguageButton5, 0, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_flex_align(ui_ChangelanguageButton5, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton5, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_bg_color(ui_ChangelanguageButton5, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_color(ui_ChangelanguageButton5, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_width(ui_ChangelanguageButton5, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton5, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_ChangelanguageButton5, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(ui_ChangelanguageButton5, 6, LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_pad_all(ui_ChangelanguageButton5, 0, LV_PART_KNOB | LV_STATE_DEFAULT|LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_text_color(ui_ChangelanguageButton5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageButton5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageButton5, lv_font30.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageOkScreenLanguage5 = lv_img_create(ui_ChangelanguageButton5);
    lv_img_set_src(ui_ImageOkScreenLanguage5, &ui_imag_ok_png);
    lv_obj_add_flag(ui_ImageOkScreenLanguage5, LV_OBJ_FLAG_HIDDEN);

    ui_ChangelanguageButton6 = lv_list_add_btn(ui_changelanguage_list, NULL, languages_array[index++]);
    lv_obj_set_size(ui_ChangelanguageButton6, 574, 56);//572
    lv_obj_set_style_border_width(ui_ChangelanguageButton6, 0, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_flex_align(ui_ChangelanguageButton6, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton6, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_bg_color(ui_ChangelanguageButton6, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_color(ui_ChangelanguageButton6, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_width(ui_ChangelanguageButton6, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton6, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_ChangelanguageButton6, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(ui_ChangelanguageButton6, 6, LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_pad_all(ui_ChangelanguageButton6, 0, LV_PART_KNOB | LV_STATE_DEFAULT|LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_text_color(ui_ChangelanguageButton6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageButton6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageButton6, lv_font30.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageOkScreenLanguage6 = lv_img_create(ui_ChangelanguageButton6);
    lv_img_set_src(ui_ImageOkScreenLanguage6, &ui_imag_ok_png);
    lv_obj_add_flag(ui_ImageOkScreenLanguage6, LV_OBJ_FLAG_HIDDEN);

    ui_ChangelanguageButton7 = lv_list_add_btn(ui_changelanguage_list, NULL, languages_array[index++]);
    lv_obj_set_size(ui_ChangelanguageButton7, 574, 56);//572
    lv_obj_set_style_border_width(ui_ChangelanguageButton7, 0, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_flex_align(ui_ChangelanguageButton7, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton7, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_bg_color(ui_ChangelanguageButton7, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_color(ui_ChangelanguageButton7, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_width(ui_ChangelanguageButton7, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton7, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_ChangelanguageButton7, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(ui_ChangelanguageButton7, 6, LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_pad_all(ui_ChangelanguageButton7, 0, LV_PART_KNOB | LV_STATE_DEFAULT|LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_text_color(ui_ChangelanguageButton7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageButton7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageButton7, lv_font30.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageOkScreenLanguage7 = lv_img_create(ui_ChangelanguageButton7);
    lv_img_set_src(ui_ImageOkScreenLanguage7, &ui_imag_ok_png);
    lv_obj_add_flag(ui_ImageOkScreenLanguage7, LV_OBJ_FLAG_HIDDEN);


    ui_ChangelanguageButton8 = lv_list_add_btn(ui_changelanguage_list, NULL, languages_array[index++]);
    lv_obj_set_size(ui_ChangelanguageButton8, 574, 56);//572
    lv_obj_set_style_border_width(ui_ChangelanguageButton8, 0, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_flex_align(ui_ChangelanguageButton8, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton8, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_bg_color(ui_ChangelanguageButton8, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_color(ui_ChangelanguageButton8, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_width(ui_ChangelanguageButton8, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton8, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_ChangelanguageButton8, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(ui_ChangelanguageButton8, 6, LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_pad_all(ui_ChangelanguageButton8, 0, LV_PART_KNOB | LV_STATE_DEFAULT|LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_text_color(ui_ChangelanguageButton8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageButton8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageButton8, lv_font30.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageOkScreenLanguage8 = lv_img_create(ui_ChangelanguageButton8);
    lv_img_set_src(ui_ImageOkScreenLanguage8, &ui_imag_ok_png);
    lv_obj_add_flag(ui_ImageOkScreenLanguage8, LV_OBJ_FLAG_HIDDEN);


    ui_ChangelanguageButton9 = lv_list_add_btn(ui_changelanguage_list, NULL, languages_array[index++]);
    lv_obj_set_size(ui_ChangelanguageButton9, 574, 56);//572
    lv_obj_set_style_border_width(ui_ChangelanguageButton9, 0, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_flex_align(ui_ChangelanguageButton9, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_ChangelanguageButton9, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_bg_color(ui_ChangelanguageButton9, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_color(ui_ChangelanguageButton9, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_width(ui_ChangelanguageButton9, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ChangelanguageButton9, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_ChangelanguageButton9, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(ui_ChangelanguageButton9, 6, LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_pad_all(ui_ChangelanguageButton9, 0, LV_PART_KNOB | LV_STATE_DEFAULT|LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_text_color(ui_ChangelanguageButton9, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageButton9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageButton9, lv_font30.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageOkScreenLanguage9 = lv_img_create(ui_ChangelanguageButton9);
    lv_img_set_src(ui_ImageOkScreenLanguage9, &ui_imag_ok_png);
    lv_obj_add_flag(ui_ImageOkScreenLanguage9, LV_OBJ_FLAG_HIDDEN);


    ui_ChangelanguageButtonTen = lv_list_add_btn(ui_changelanguage_list, NULL, languages_array[index++]);
    lv_obj_set_size(ui_ChangelanguageButtonTen, 574, 56);//572
    lv_obj_set_style_border_width(ui_ChangelanguageButtonTen, 0, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_flex_align(ui_ChangelanguageButtonTen, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_ChangelanguageButtonTen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_bg_color(ui_ChangelanguageButtonTen, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_color(ui_ChangelanguageButtonTen, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_width(ui_ChangelanguageButtonTen, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ChangelanguageButtonTen, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_ChangelanguageButtonTen, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(ui_ChangelanguageButtonTen, 6, LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_pad_all(ui_ChangelanguageButtonTen, 0, LV_PART_KNOB | LV_STATE_DEFAULT|LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_text_color(ui_ChangelanguageButtonTen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ChangelanguageButtonTen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ChangelanguageButtonTen, lv_font30.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_ImageOkScreenLanguageTen = lv_img_create(ui_ChangelanguageButtonTen);
    lv_img_set_src(ui_ImageOkScreenLanguageTen, &ui_imag_ok_png);
    lv_obj_add_flag(ui_ImageOkScreenLanguageTen, LV_OBJ_FLAG_HIDDEN);

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

   // language_change_event_grop();
    lv_obj_add_event_cb(ui_changelanguage, ui_event_Pageinit, LV_EVENT_ALL, NULL);
}

///////////////////// EVENTS ////////////////////
void ui_event_changelanguage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        CrLogI("change language btn clicked");
        char *userdata = lv_event_get_user_data(e);
        if ( userdata )
        {
            language_sign = *userdata;
            if ( language_sign >= '0' || language_sign <= '9' )
                language_btn_selected(language_sign - '0');
        }
        ui_BtnConfirmLanguage(); //发送语言刷新命令
    }
    else if (event_code == LV_EVENT_LONG_PRESSED)
    { 
        LoadSettingsScreen();
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

static void ui_BtnConfirmLanguage(void)
{
    wait_animmotion(true);
    if ( (language_sign >= '0') && (language_sign <= '9') )
        send_set_language_cmd(language_sign);
    else if ( language_sign < '0' )
    {
        send_set_language_cmd('0');
    }
    else
        send_set_language_cmd('9');

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
            //_ui_screen_change(ui_SelftestAll, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
            LoadPage(ui_SelftestAll, 1);
            return;
        }
        memset(tempbuff, 0, sizeof(tempbuff));
        snprintf(tempbuff, 256, "%s/%s", GetPrintRunState().uDiskPath, GetJumpSelftestFileName());
        CrLogI("the path %s", tempbuff);
    
        //检查U盘中是否有特定文件，有则跳过开机自检
        if(access(tempbuff, F_OK) == 0)
        {
            LoadHomeNormalPageAndObjs(false);
        }
    }
}

static void ui_event_Pageinit(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load the changelanguage");
        is_start_up_guide = selftestflag;   //确定是否属于开机自检
        language_change_language_text();    //页面刷新实时的语言选择
        language_btn_selected(get_cur_language_index());
        language_sign = '0' + get_cur_language_index();
        if(selftestflag)
        {
            //创建定时器检查U盘是否连接
            timerHandleJumpSelf = lv_timer_create(timerHadnle, 1000 * 3, NULL);
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

    lv_obj_add_flag(ui_ImageOkScreenLanguage1, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_ImageOkScreenLanguage2, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_ImageOkScreenLanguage3, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_ImageOkScreenLanguage4, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_ImageOkScreenLanguage5, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_ImageOkScreenLanguage6, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_ImageOkScreenLanguage7, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_ImageOkScreenLanguage8, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_ImageOkScreenLanguage9, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_ImageOkScreenLanguageTen, LV_OBJ_FLAG_HIDDEN);
    
    switch (language_index)
    {
    case 0:
        {
            
            lv_obj_clear_flag(ui_ImageOkScreenLanguage1, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    case 1:
        {
             lv_obj_clear_flag(ui_ImageOkScreenLanguage2, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    case 2:
        {
             lv_obj_clear_flag(ui_ImageOkScreenLanguage3, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    case 3:
        {
             lv_obj_clear_flag(ui_ImageOkScreenLanguage4, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    case 4:
        {
             lv_obj_clear_flag(ui_ImageOkScreenLanguage5, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    case 5:
        {
            lv_obj_clear_flag(ui_ImageOkScreenLanguage6, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    case 6:
        {
            lv_obj_clear_flag(ui_ImageOkScreenLanguage7, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    case 7:
        {
            lv_obj_clear_flag(ui_ImageOkScreenLanguage8, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    case 8:
        {
            lv_obj_clear_flag(ui_ImageOkScreenLanguage9, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    case 9:
        {
            lv_obj_clear_flag(ui_ImageOkScreenLanguageTen, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    default:
        break;
    }
    
    if ( ui_changelanguagetitle )
        lv_label_set_text(ui_changelanguagetitle, LanguageSelection[language_index]);
}

char *language_get_cur_language_text(int8_t language_index)
{
    if ( language_index < 0 || language_index > 9 )
        return NULL;
    
    language_btn_selected(language_index);

    return languages_array[language_index];
}

void language_change_language_text(void)
{
    if ( ui_changelanguagetitle )
        lv_label_set_text(ui_changelanguagetitle, LanguageSelection[get_cur_language_index()]);    
}

void language_set_screen_mode(bool is_guide)
{
    is_start_up_guide = is_guide;
}

void language_change_event_grop(uint8_t level)
{
    lv_group_remove_all_objs(encoder_group);
    // lv_indev_set_group(enc_indev, NULL); 
    // lv_indev_set_group(enc_indev, encoder_group); //关联组

    PageNode *changelanguage_node = find_page(ui_changelanguage);
    changelanguage_node->nav_level = level;
    lv_group_add_obj(encoder_group, ui_ChangelanguageButton1);
    lv_group_add_obj(encoder_group, ui_ChangelanguageButton2);
    lv_group_add_obj(encoder_group, ui_ChangelanguageButton3);
    lv_group_add_obj(encoder_group, ui_ChangelanguageButton4);

    lv_group_add_obj(encoder_group, ui_ChangelanguageButton5);
    lv_group_add_obj(encoder_group, ui_ChangelanguageButton6);
    lv_group_add_obj(encoder_group, ui_ChangelanguageButton7);
    lv_group_add_obj(encoder_group, ui_ChangelanguageButton8);

    lv_group_add_obj(encoder_group, ui_ChangelanguageButton9);
    lv_group_add_obj(encoder_group, ui_ChangelanguageButtonTen);
}

void change_language_end(unsigned char language)
{
    CrLogI("change end");
    if ( is_start_up_guide) //自检
    {
        // _ui_screen_change(ui_BootPart0, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        //_ui_screen_change(ui_SelftestPrivacyPolicy, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
         LoadSelftestPrivacyPolicyPageAndObjs();
        //_ui_screen_change(ui_SelftestNetwork, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
      
    }
    else //非自检正常退出进入设置页
    {
        // LoadPage(ui_ScreenSettings, 2);
        // lv_group_focus_obj(ui_VersionDetectPanel);
        BackPrepage(false);
    }
    wait_animmotion(false);
}


void LoadChangeLanguageScreen(void)
{
    _ui_screen_change(ui_changelanguage, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
    