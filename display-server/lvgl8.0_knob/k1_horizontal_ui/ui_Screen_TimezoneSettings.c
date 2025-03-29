/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2023-02-02 14:14:40
 * @LastEditTime: 2023-10-23 02:08:11
 */

#include "ui.h"
#include "mult_language.h"

lv_obj_t * ui_TimezoneSettings;
lv_obj_t * ui_Manualtest_Panel1;
lv_obj_t * ui_TimezoneSettingsLabel1;
lv_obj_t * ui_TimezoneSettings_Image2;
lv_obj_t * ui_TimezoneSettings_Button1;
lv_obj_t * ui_TimezoneSettings_Label1;
lv_obj_t * ui_TimezoneSettings_Button2;
lv_obj_t * ui_TimezoneSettings_Label2;

void ui_event_checkbox_panel(lv_event_t * e);
void ui_event_checkbox(lv_event_t * e);
void ui_event_TimezoneSettings_Button1(lv_event_t * e);
void ui_event_TimezoneSettings_Button2(lv_event_t * e);
void ui_event_TimezoneSettings(lv_event_t * e);

static void TimezonePageChangeObjs(uint8_t index);
void LoadTimezoneSettingsScreen(void);

#define MAX_TIMEZONE 37

static lv_style_t style_radio;
static lv_style_t style_radio_chk;

const char *timezonetext[MAX_TIMEZONE] = { \
    "UTC-12:00(IDLW-国际换日线)", \
    "UTC-11:00(SST-美属萨摩亚标准时间)", \
    "UTC-10:00(HST-夏威夷-阿留申标准时间)", \
    "UTC-09:30(MIT-马克萨斯群岛标准时间)", \
    "UTC-09:00(AKST-阿拉斯加标准时间)", \
    "UTC-08:00(PST-太平洋标准时间)", \
    "UTC-07:00(MST-北美山区标准时间)", \
    "UTC-06:00(CST-北美中部标准时间)", \
    "UTC-05:00(EST-北美东部标准时间)", \
    "UTC-04:00(AST-大西洋标准时间)", \
    "UTC-03:30(NST-纽芬兰岛标准时间)", \
    "UTC-03:00(BRT-巴西利亚标准时间)", \
    "UTC-02:00(FNT-费尔南多迪诺罗尼尔群岛标准时间)", \
    "UTC-01:00(CVT-佛得角标准时间)", \
    "UTC+00:00(WET-欧洲西部时区,GMT-格林威治标准时间)", \
    "UTC+01:00(CET-欧洲中部时区)", \
    "UTC+02:00(EET-欧洲东部时区)", \
    "UTC+03:00(MSK-莫斯科时区)", \
    "UTC+03:30(IRST-伊朗标准时间)", \
    "UTC+04:00(GST-海湾标准时间)", \
    "UTC+04:30(AFT-阿富汗标准时间)",\
    "UTC+05:00(PKT-巴基斯坦标准时间)", \
    "UTC+05:30(IST-印度标准时间)", \
    "UTC+05:45(NPT-尼泊尔标准时间)", \
    "UTC+06:00(BHT-孟加拉标准时间)", \
    "UTC+06:30(MMT-缅甸标准时间)", \
    "UTC+07:00(ICT-中南半岛标准时间)", \
    "UTC+08:00(CT/CST-中国标准时间)", \
    "UTC+09:00(JST-日本标准时间)", \
    "UTC+09:30(ACST-澳洲中部标准时间)", \
    "UTC+10:00(AEST-澳洲东部标准时间)", \
    "UTC+10:30(LHST-豪勋爵群岛标准时间)", \
    "UTC+11:00(VUT-瓦努阿图标准时间)", \
    "UTC+12:00(NZST-纽西兰标准时间)", \
    "UTC+12:45(CHAST-查塔姆群岛标准时间)", \
    "UTC+13:00(PHOT-菲尼克斯群岛标准时间)", \
    "UTC+14:00(LINT-莱恩群岛标准时间)", \
};

typedef struct Single_timezone{
    lv_obj_t * check_panel;
    lv_obj_t * check_box;
    lv_obj_t * check_img;
}Single_timezone_t;

Single_timezone_t * ui_current_timezone;
Single_timezone_t * timezone_list[MAX_TIMEZONE];


Single_timezone_t * create_timezone_list(lv_obj_t * parent, const char * txt, lv_align_t align_mode, lv_coord_t x, lv_coord_t y)
{
    //create the single panel
    Single_timezone_t * timezone_obj = (Single_timezone_t *)lv_mem_alloc(sizeof(Single_timezone_t));
    if ( !timezone_obj )
        return NULL;
        
    lv_obj_t * single_panel = lv_obj_create(parent);
    
 
    lv_obj_set_size(single_panel, 613, 56);
    lv_obj_align(single_panel, align_mode, x, y);
   // lv_obj_add_flag(single_panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
   // lv_obj_add_flag(single_panel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(single_panel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(single_panel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_set_style_radius(single_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(single_panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(single_panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(single_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(single_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(single_panel, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_width(single_panel, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_color(single_panel, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(single_panel, 6, LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    //create the checkbox
    lv_obj_t * obj = lv_checkbox_create(single_panel);
    lv_checkbox_set_text(obj, txt);
    //lv_obj_add_flag(obj, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_width(obj, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(obj, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_pos(obj, -30, 10); //隐藏掉checkbox 左边的复选框
    lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_text_color(obj, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(obj, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(obj, 255, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_text_font(obj, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_width(obj, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(obj, LV_RADIUS_CIRCLE, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x000000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(obj, lv_color_hex(0x50555F),LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(obj, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(obj, LV_RADIUS_CIRCLE, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(obj, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(obj, lv_color_hex(0x50555F),LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(obj, 0, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(obj, 4, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_img_src(obj, NULL, LV_PART_INDICATOR | LV_STATE_CHECKED);
    
    //create the select img
    lv_obj_t * obj_img = lv_img_create(single_panel);
    lv_img_set_src(obj_img, &ui_img_timezonecheck_png);
    lv_obj_set_width(obj_img, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(obj_img, LV_SIZE_CONTENT);    /// 1
    lv_obj_align(obj_img, LV_ALIGN_RIGHT_MID, -19,0);
    lv_obj_add_flag(obj_img, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(obj_img, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    timezone_obj->check_panel = single_panel;
    timezone_obj->check_box = obj;
    timezone_obj->check_img = obj_img;
    lv_obj_add_event_cb(single_panel, ui_event_checkbox_panel, LV_EVENT_ALL, timezone_obj);
    lv_obj_add_event_cb(obj, ui_event_checkbox, LV_EVENT_ALL, timezone_obj);

    return timezone_obj;
}

void ui_TimezoneSettings_screen_init(void)
{
    ui_TimezoneSettings = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_TimezoneSettings, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_TimezoneSettings, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TimezoneSettings, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    init_pages(ui_TimezoneSettings, TimezonePageChangeObjs, LoadTimezoneSettingsScreen);

    ui_Manualtest_Panel1 = lv_obj_create(ui_TimezoneSettings);
    lv_obj_set_size(ui_Manualtest_Panel1, 640, 250);
    lv_obj_set_pos(ui_Manualtest_Panel1, 0, 115);
   // lv_obj_add_flag(ui_Manualtest_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_Manualtest_Panel1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
   // lv_obj_clear_flag(ui_Manualtest_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Manualtest_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Manualtest_Panel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Manualtest_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Manualtest_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_Manualtest_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_style_init(&style_radio);
    lv_style_set_radius(&style_radio, LV_RADIUS_CIRCLE);

    lv_style_init(&style_radio_chk);
    lv_style_set_bg_img_src(&style_radio_chk, NULL);
    
    for(int i=0; i < MAX_TIMEZONE; i++)
    {
        timezone_list[i] = create_timezone_list(ui_Manualtest_Panel1, timezonetext[i], LV_ALIGN_TOP_LEFT,10,(56*i));
    }
    //初始化

    ui_TimezoneSettingsLabel1 = lv_label_create(ui_TimezoneSettings);
    lv_obj_set_width(ui_TimezoneSettingsLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimezoneSettingsLabel1, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ui_TimezoneSettingsLabel1, 0);
    // lv_obj_set_y(ui_TimezoneSettingsLabel1, 70);
    lv_obj_align(ui_TimezoneSettingsLabel1, LV_ALIGN_TOP_MID, 0, 70);
    //lv_obj_set_align(ui_TimezoneSettingsLabel1, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_TimezoneSettingsLabel1, "时区设置");
    lv_obj_set_style_text_color(ui_TimezoneSettingsLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TimezoneSettingsLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TimezoneSettingsLabel1, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_TimezoneSettings_Image2 = lv_img_create(ui_TimezoneSettings);
    // lv_img_set_src(ui_TimezoneSettings_Image2, &ui_img_mask_png);
    // lv_obj_set_width(ui_TimezoneSettings_Image2, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_TimezoneSettings_Image2, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ui_TimezoneSettings_Image2, 0);
    // lv_obj_set_y(ui_TimezoneSettings_Image2, 323);
    // lv_obj_add_flag(ui_TimezoneSettings_Image2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_TimezoneSettings_Image2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_TimezoneSettings_Button1 = lv_btn_create(ui_TimezoneSettings);
    lv_obj_set_width(ui_TimezoneSettings_Button1, 180);
    lv_obj_set_height(ui_TimezoneSettings_Button1, 56);
    // lv_obj_set_x(ui_TimezoneSettings_Button1, 196);
    // lv_obj_set_y(ui_TimezoneSettings_Button1, 400);
    lv_obj_align(ui_TimezoneSettings_Button1, LV_ALIGN_BOTTOM_MID, 0, -74);
    lv_obj_add_flag(ui_TimezoneSettings_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_TimezoneSettings_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_TimezoneSettings_Button1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TimezoneSettings_Button1, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TimezoneSettings_Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_TimezoneSettings_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_TimezoneSettings_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
       //聚焦样式
    lv_obj_set_style_border_color(ui_TimezoneSettings_Button1, lv_color_hex(0xFFFFFF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_TimezoneSettings_Button1, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_TimezoneSettings_Button1, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_TimezoneSettings_Button1, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_TimezoneSettings_Button1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    lv_obj_add_event_cb(ui_TimezoneSettings_Button1,ui_event_TimezoneSettings_Button1,LV_EVENT_ALL,NULL);
    
    ui_TimezoneSettings_Label1 = lv_label_create(ui_TimezoneSettings_Button1);
    lv_obj_set_width(ui_TimezoneSettings_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimezoneSettings_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_TimezoneSettings_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TimezoneSettings_Label1, "上一步");
    lv_obj_set_style_text_font(ui_TimezoneSettings_Label1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_TimezoneSettings_Button2 = lv_btn_create(ui_TimezoneSettings);
    lv_obj_set_width(ui_TimezoneSettings_Button2, 146);
    lv_obj_set_height(ui_TimezoneSettings_Button2, 60);
    lv_obj_set_x(ui_TimezoneSettings_Button2, 458);
    lv_obj_set_y(ui_TimezoneSettings_Button2, 400);
    lv_obj_add_flag(ui_TimezoneSettings_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_TimezoneSettings_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_TimezoneSettings_Button2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_TimezoneSettings_Button2, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TimezoneSettings_Button2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_TimezoneSettings_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_TimezoneSettings_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(ui_TimezoneSettings_Button2,ui_event_TimezoneSettings_Button2,LV_EVENT_ALL,NULL);

    ui_TimezoneSettings_Label2 = lv_label_create(ui_TimezoneSettings_Button2);
    lv_obj_set_width(ui_TimezoneSettings_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TimezoneSettings_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_TimezoneSettings_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TimezoneSettings_Label2, "下一步");
    lv_obj_set_style_text_font(ui_TimezoneSettings_Label2, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_TimezoneSettings,ui_event_TimezoneSettings,LV_EVENT_ALL,NULL);
}


void ui_event_checkbox_panel(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    Single_timezone_t * target = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
       lv_event_send(target->check_box, LV_EVENT_SHORT_CLICKED, NULL);
    }
}

void ui_event_checkbox(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    Single_timezone_t * target = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        lv_obj_clear_state(ui_current_timezone->check_box, LV_STATE_CHECKED);   /*Uncheck the previous radio button*/
        lv_obj_add_flag(ui_current_timezone->check_img,LV_OBJ_FLAG_HIDDEN);

        lv_obj_add_state(target->check_box, LV_STATE_CHECKED);     /*Uncheck the current radio button*/
        lv_obj_clear_flag(target->check_img,LV_OBJ_FLAG_HIDDEN);

        ui_current_timezone = target;
        char *temp = lv_checkbox_get_text(ui_current_timezone->check_box);
        char timezone_txt[100] = {0};
        sscanf(temp, "%[^(]", timezone_txt);
        CrLogI("timezone_txt:%s",timezone_txt);
        char sendbuff[32] = {0};
        snprintf(sendbuff, 32, "m%s", timezone_txt);
        //发送时区设置命令
        set_printer_data(0x06, strlen(sendbuff)+1, sendbuff);

        CrLogI("timezone_txt:%s\n",timezone_txt);

        if(selftestflag) {
             //_ui_screen_change(ui_DeviceBinding, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0); //----
             LoadPage(ui_SelfTestPageDeviceBinding, 1);
        }
        else {
             //_ui_screen_change(ui_ScreenSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
             BackPrepage(false); //设置页进入返回设置页
        }
        
    }
}

void ui_event_TimezoneSettings_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(selftestflag)
            //_ui_screen_change(ui_SelftestNetwork, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);//ui_SelftestPrivacyPolicy
            //_ui_screen_change(ui_SelftestPrivacyPolicy, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
            LoadPage(ui_SelftestNetwork, 0);
        else
            _ui_screen_change(ui_ScreenSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_TimezoneSettings_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(selftestflag)
            //_ui_screen_change(ui_DeviceBinding, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
            LoadPage(ui_SelfTestPageDeviceBinding, 1);
        else
            _ui_screen_change(ui_ScreenSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_TimezoneSettings(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load the TimezoneSettings.");
        get_printer_data(0x06,1,"9");       //
        get_printer_data(0x06,1,"m");       //
        uint8_t language_index = get_cur_language_index();
        if(selftestflag)
        {
            lv_obj_set_size(ui_Manualtest_Panel1, 640, 220);
            lv_obj_clear_flag(ui_TimezoneSettings_Button1, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_TimezoneSettings_Button2, LV_OBJ_FLAG_HIDDEN);
            lv_obj_align(ui_TimezoneSettings_Button1, LV_ALIGN_BOTTOM_MID, 0, -74);
            //lv_obj_align(ui_TimezoneSettings_Button2, LV_ALIGN_TOP_LEFT, 458, 400);
            lv_label_set_text(ui_TimezoneSettings_Label2, NextStep[get_cur_language_index()]);
        }
        else
        {
            // lv_obj_align(ui_TimezoneSettings_Button2, LV_ALIGN_TOP_MID, 0, 400);
            // lv_label_set_text(ui_TimezoneSettings_Label2, ErrorBtnConfirm[get_cur_language_index()]);
            lv_obj_add_flag(ui_TimezoneSettings_Button2, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_TimezoneSettings_Button1, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_size(ui_Manualtest_Panel1, 640, 290);
        }

    }
}

void refresh_timezoneseting(char * timezone)
{
    if(timezone != NULL)
    {
        char timezone_txt[100] = {0};
        char *temp = NULL;
        for(int i=0; i < MAX_TIMEZONE; i++)
        {
            temp = lv_checkbox_get_text(timezone_list[i]->check_box);
            sscanf(temp, "%[^(]", timezone_txt);
            if(strcmp(timezone_txt, timezone) == 0) //匹配到选择项
            {
                ui_current_timezone = timezone_list[i];
                lv_obj_add_state(ui_current_timezone->check_box, LV_STATE_CHECKED);     /*Uncheck the current radio button*/
                lv_obj_clear_flag(ui_current_timezone->check_img,LV_OBJ_FLAG_HIDDEN);
                CrLogI("timezone successful match");
            }
        }
    }
}

void timezone_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    // char buff[30] = {0};
    // memset(buff, 0, sizeof(buff));
    // sprintf(buff, "%s%s", TimeZoneArray[language_index], SettingArray[language_index]);
    lv_label_set_text(ui_TimeZoneSetLabel, TimeZoneArray[language_index]);
    if(ui_TimezoneSettingsLabel1)
        lv_label_set_text(ui_TimezoneSettingsLabel1, TimeZoneArray[language_index]);
    if(ui_TimezoneSettings_Label1)
        lv_label_set_text(ui_TimezoneSettings_Label1, PrevStep[language_index]);
    if(ui_TimezoneSettings_Label2)
        lv_label_set_text(ui_TimezoneSettings_Label2, NextStep[language_index]);

    if(language_index != 0)
    {
        for(int i = 0; i < MAX_TIMEZONE; i++)
        {
            char *temp = lv_checkbox_get_text(timezone_list[i]->check_box);
            char txt[100] = {0};
            sscanf(temp, "%[^(]", txt);
            lv_checkbox_set_text(timezone_list[i]->check_box, txt);
        }
    }
    else
    {
        for(int i = 0; i < MAX_TIMEZONE; i++)
        {
            lv_checkbox_set_text(timezone_list[i]->check_box, timezonetext[i]);
        }
    }
}

void LoadTimezoneSettingsScreen(void)
{
    _ui_screen_change(ui_TimezoneSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}

static void TimezonePageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    // lv_indev_set_group(enc_indev, NULL); 
    // lv_indev_set_group(enc_indev, encoder_group); //关联组
    PageNode *Timezone_node = find_page(ui_TimezoneSettings);
    Timezone_node->nav_level = index;


    switch (index)
    {
    case 1: //1级事件组
        for (size_t i = 0; i < MAX_TIMEZONE; i++)
        {
            lv_group_add_obj(encoder_group, timezone_list[i]->check_panel);
        }
        lv_group_add_obj(encoder_group, ui_TimezoneSettings_Button1);
        break;
    default:
        break;
    }
 
}
