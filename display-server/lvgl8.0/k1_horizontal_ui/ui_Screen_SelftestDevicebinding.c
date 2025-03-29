#include "ui.h"
#include "mult_language.h"

lv_obj_t * ui_DeviceBinding;
lv_obj_t * ui_DeviceBindingLabel1;
lv_obj_t * ui_DeviceBindingButton1;
lv_obj_t * ui_DeviceBindingLabel2;
lv_obj_t * ui_DeviceBindingButton2;
lv_obj_t * ui_DeviceBindingLabel3;
lv_obj_t * ui_DeviceBindingButton3;
lv_obj_t * ui_DeviceBindingLabel4;
lv_obj_t * ui_DeviceBindingLabel5;
lv_obj_t * ui_DeviceBinding_Image3;
lv_obj_t * ui_DeviceBindingDropdown1;
lv_obj_t * ui_DeviceBindingLabel6;
lv_obj_t * ui_DeviceBindingPanel;
lv_obj_t * ui_DeviceBindingPanel6;
lv_obj_t * ui_DeviceBindingLabel7;
lv_obj_t * ui_DeviceBindingLabel8;
lv_obj_t * ui_DeviceBindingUserimg;
lv_obj_t * ui_DeviceBindingUsername;
lv_obj_t * ui_DeviceBindingUserid;
lv_obj_t * ui_DeviceBindingUserBtn;
lv_obj_t * ui_DeviceBindingUserBtnlabel;
int IsrefreshCxyUserInfo = 0;

void ui_event_DeviceBindingButton1(lv_event_t * e);
void ui_event_DeviceBindingButton2(lv_event_t * e);
void ui_event_DeviceBindingButton3(lv_event_t * e);
void ui_event_DeviceBinding(lv_event_t * e);
void ui_event_SelftestDeviceBingdingDropdown1(lv_event_t * e);
void ui_event_SelftestDeviceLogOut(lv_event_t * e);

void ui_DeviceBinding_screen_init(void)
{
    ui_DeviceBinding = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_DeviceBinding, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_DeviceBinding, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DeviceBinding, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceBindingLabel1 = lv_label_create(ui_DeviceBinding);
    lv_obj_set_width(ui_DeviceBindingLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_DeviceBindingLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_DeviceBindingLabel1, 0);
    lv_obj_set_y(ui_DeviceBindingLabel1, 20);
    lv_obj_set_align(ui_DeviceBindingLabel1, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_DeviceBindingLabel1, "设备绑定");
    lv_obj_set_style_text_color(ui_DeviceBindingLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DeviceBindingLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DeviceBindingLabel1, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceBindingButton1 = lv_btn_create(ui_DeviceBinding);
    lv_obj_set_width(ui_DeviceBindingButton1, 146);
    lv_obj_set_height(ui_DeviceBindingButton1, 60);
    lv_obj_set_x(ui_DeviceBindingButton1, 196);
    lv_obj_set_y(ui_DeviceBindingButton1, 400);
    lv_obj_add_flag(ui_DeviceBindingButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_DeviceBindingButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DeviceBindingButton1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DeviceBindingButton1, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DeviceBindingButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_DeviceBindingButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_DeviceBindingButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceBindingLabel2 = lv_label_create(ui_DeviceBindingButton1);
    lv_obj_set_width(ui_DeviceBindingLabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_DeviceBindingLabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_DeviceBindingLabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DeviceBindingLabel2, "上一步");
    lv_obj_set_style_text_font(ui_DeviceBindingLabel2, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceBindingButton2 = lv_btn_create(ui_DeviceBinding);
    lv_obj_set_width(ui_DeviceBindingButton2, 146);
    lv_obj_set_height(ui_DeviceBindingButton2, 60);
    lv_obj_set_x(ui_DeviceBindingButton2, 458);
    lv_obj_set_y(ui_DeviceBindingButton2, 400);
    lv_obj_add_flag(ui_DeviceBindingButton2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_DeviceBindingButton2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DeviceBindingButton2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DeviceBindingButton2, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DeviceBindingButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_DeviceBindingButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_DeviceBindingButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceBindingLabel3 = lv_label_create(ui_DeviceBindingButton2);
    lv_obj_set_width(ui_DeviceBindingLabel3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_DeviceBindingLabel3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_DeviceBindingLabel3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DeviceBindingLabel3, "下一步");
    lv_obj_set_style_text_font(ui_DeviceBindingLabel3, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceBindingButton3 = lv_btn_create(ui_DeviceBinding);
    lv_obj_set_width(ui_DeviceBindingButton3, 90);
    lv_obj_set_height(ui_DeviceBindingButton3, 50);
    lv_obj_set_x(ui_DeviceBindingButton3, 697);
    lv_obj_set_y(ui_DeviceBindingButton3, 14);
    lv_obj_add_flag(ui_DeviceBindingButton3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_DeviceBindingButton3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DeviceBindingButton3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DeviceBindingButton3, lv_color_hex(0x28292D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DeviceBindingButton3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_DeviceBindingButton3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_DeviceBindingButton3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_DeviceBindingButton3, LV_OBJ_FLAG_HIDDEN);     /// Flags

    ui_DeviceBindingLabel4 = lv_label_create(ui_DeviceBindingButton3);
    lv_obj_set_width(ui_DeviceBindingLabel4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_DeviceBindingLabel4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_DeviceBindingLabel4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_DeviceBindingLabel4, "跳过");
    lv_obj_set_style_text_font(ui_DeviceBindingLabel4, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_DeviceBindingLabel5 = lv_label_create(ui_DeviceBinding);
    lv_obj_set_width(ui_DeviceBindingLabel5, 720);   /// 1
    lv_obj_set_height(ui_DeviceBindingLabel5, 52);    /// 1
    lv_obj_align(ui_DeviceBindingLabel5, LV_ALIGN_TOP_MID, 0, 75);
    lv_label_set_text(ui_DeviceBindingLabel5, "请使用创想云APP扫码绑定设备");
    lv_obj_set_style_text_color(ui_DeviceBindingLabel5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DeviceBindingLabel5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DeviceBindingLabel5, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_DeviceBindingLabel5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceBinding_Image3 = lv_qrcode_create(ui_DeviceBinding, 160, lv_color_hex(0xFFFFFF), lv_color_hex(0x000000));
    lv_obj_set_width(ui_DeviceBinding_Image3, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_DeviceBinding_Image3, LV_SIZE_CONTENT);
    lv_obj_align(ui_DeviceBinding_Image3, LV_ALIGN_TOP_MID, 0, 206);
    lv_obj_add_flag(ui_DeviceBinding_Image3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_DeviceBinding_Image3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    char buff[150] = {0};
    sprintf(buff, "%s\n%s", "中国大陆","海外服务器");

    ui_DeviceBindingDropdown1 = lv_dropdown_create(ui_DeviceBinding);
    lv_dropdown_set_options(ui_DeviceBindingDropdown1, buff);
    lv_obj_set_width(ui_DeviceBindingDropdown1, 363);
    lv_obj_set_height(ui_DeviceBindingDropdown1, 52);
    lv_obj_align(ui_DeviceBindingDropdown1, LV_ALIGN_TOP_LEFT, 262, 131);
    lv_obj_add_flag(ui_DeviceBindingDropdown1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_DeviceBindingDropdown1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DeviceBindingDropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_DeviceBindingDropdown1, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DeviceBindingDropdown1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_DeviceBindingDropdown1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DeviceBindingDropdown1, lv_color_hex(0x252729), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DeviceBindingDropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_DeviceBindingDropdown1, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_DeviceBindingDropdown1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DeviceBindingDropdown1, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_DeviceBindingDropdown1, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DeviceBindingDropdown1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DeviceBindingDropdown1, lv_font24.font, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_dropdown_set_symbol(ui_DeviceBindingDropdown1, &ui_img_expand_down_png);

    ui_DeviceBindingLabel6 = lv_label_create(ui_DeviceBinding);
    lv_label_set_text(ui_DeviceBindingLabel6, "区域");
    lv_obj_set_width(ui_DeviceBindingLabel6, 200);   /// 1
    lv_obj_set_height(ui_DeviceBindingLabel6, 28);    /// 1
    lv_obj_align_to(ui_DeviceBindingLabel6, ui_DeviceBindingDropdown1, LV_ALIGN_OUT_LEFT_MID, -10, 0);
    lv_obj_set_style_text_font(ui_DeviceBindingLabel6, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_DeviceBindingLabel6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_DeviceBindingLabel6, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceBindingLabel8 = lv_label_create(ui_DevicebindingPanel3);
    lv_obj_set_width(ui_DeviceBindingLabel8, 600);
    lv_obj_set_height(ui_DeviceBindingLabel8, 30);
    lv_obj_align(ui_DeviceBindingLabel8, LV_ALIGN_TOP_MID, 0, 217);
    lv_label_set_long_mode(ui_DeviceBindingLabel8, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_DeviceBindingLabel8, IOTTips[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_DeviceBindingLabel8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DeviceBindingLabel8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DeviceBindingLabel8, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_DeviceBindingLabel8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_DeviceBindingLabel8, LV_OBJ_FLAG_HIDDEN);      /// Flags

    ui_DeviceBindingPanel = lv_obj_create(ui_DeviceBinding);
    lv_obj_set_width(ui_DeviceBindingPanel, 800);
    lv_obj_set_height(ui_DeviceBindingPanel, 300);
    lv_obj_align(ui_DeviceBindingPanel, LV_ALIGN_TOP_MID, 0, 80);
    lv_obj_clear_flag(ui_DeviceBindingPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DeviceBindingPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DeviceBindingPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DeviceBindingPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DeviceBindingPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_DeviceBindingPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceBindingPanel6 = lv_obj_create(ui_DeviceBindingPanel);
    lv_obj_set_width(ui_DeviceBindingPanel6, 78);
    lv_obj_set_height(ui_DeviceBindingPanel6, 78);
    lv_obj_align(ui_DeviceBindingPanel6, LV_ALIGN_TOP_LEFT, 30, 82);
    lv_obj_clear_flag(ui_DeviceBindingPanel6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DeviceBindingPanel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DeviceBindingPanel6, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DeviceBindingPanel6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DeviceBindingPanel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_DeviceBindingPanel6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceBindingUserimg = lv_img_create(ui_DeviceBindingPanel6);
    lv_obj_set_width(ui_DeviceBindingUserimg, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_DeviceBindingUserimg, LV_SIZE_CONTENT);
    lv_obj_align(ui_DeviceBindingUserimg, LV_ALIGN_CENTER, 0 ,0);
    lv_obj_add_flag(ui_DeviceBindingUserimg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_DeviceBindingUserimg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_DeviceBindingUsername = lv_label_create(ui_DeviceBindingPanel);
    lv_obj_set_width(ui_DeviceBindingUsername, 600);
    lv_obj_set_height(ui_DeviceBindingUsername, 30);
    lv_obj_align_to(ui_DeviceBindingUsername, ui_DeviceBindingPanel6, LV_ALIGN_OUT_RIGHT_TOP, 10, 0);
    lv_label_set_long_mode(ui_DeviceBindingUsername, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_DeviceBindingUsername, UserName[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_DeviceBindingUsername, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DeviceBindingUsername, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DeviceBindingUsername, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceBindingUserid = lv_label_create(ui_DeviceBindingPanel);
    lv_obj_set_width(ui_DeviceBindingUserid, 600);
    lv_obj_set_height(ui_DeviceBindingUserid, 30);
    lv_obj_align_to(ui_DeviceBindingUserid, ui_DeviceBindingUsername, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 5);
    lv_label_set_long_mode(ui_DeviceBindingUserid, LV_LABEL_LONG_WRAP);
    lv_label_set_text(ui_DeviceBindingUserid, "ID:");
    lv_obj_set_style_text_color(ui_DeviceBindingUserid, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DeviceBindingUserid, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DeviceBindingUserid, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceBindingUserBtn = lv_btn_create(ui_DeviceBindingPanel);
    lv_obj_set_width(ui_DeviceBindingUserBtn, 106);
    lv_obj_set_height(ui_DeviceBindingUserBtn, 50);
    lv_obj_align(ui_DeviceBindingUserBtn, LV_ALIGN_TOP_RIGHT, -30, 93);
    lv_obj_add_flag(ui_DeviceBindingUserBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_DeviceBindingUserBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DeviceBindingUserBtn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DeviceBindingUserBtn, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DeviceBindingUserBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_DeviceBindingUserBtn, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_DeviceBindingUserBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_DeviceBindingUserBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_DeviceBindingUserBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_DeviceBindingUserBtn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DeviceBindingUserBtn, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_DeviceBindingUserBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DeviceBindingUserBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DeviceBindingUserBtn, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceBindingUserBtnlabel = lv_label_create(ui_DeviceBindingUserBtn);
    lv_obj_set_width(ui_DeviceBindingUserBtnlabel, lv_pct(100));
    lv_obj_set_height(ui_DeviceBindingUserBtnlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_DeviceBindingUserBtnlabel, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_DeviceBindingUserBtnlabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_DeviceBindingUserBtnlabel, LogOut[get_cur_language_index()]);
    lv_obj_set_style_text_align(ui_DeviceBindingUserBtnlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DeviceBindingUserBtnlabel, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_DeviceBindingUserBtnlabel, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DeviceBindingLabel7 = lv_label_create(ui_DeviceBindingPanel);
    lv_obj_set_width(ui_DeviceBindingLabel7, lv_pct(100));
    lv_obj_set_height(ui_DeviceBindingLabel7, LV_SIZE_CONTENT);    /// 1
    lv_obj_align(ui_DeviceBindingLabel7, LV_ALIGN_TOP_MID, 0, 20);
    lv_label_set_long_mode(ui_DeviceBindingLabel7, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_DeviceBindingLabel7, BindingTips[get_cur_language_index()]);
    lv_obj_set_style_text_align(ui_DeviceBindingLabel7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DeviceBindingLabel7, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_DeviceBindingLabel7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_DeviceBindingPanel, LV_OBJ_FLAG_HIDDEN);     /// Flags

    lv_obj_add_event_cb(ui_DeviceBindingButton1, ui_event_DeviceBindingButton1, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(ui_DeviceBindingButton2, ui_event_DeviceBindingButton2, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(ui_DeviceBindingButton3, ui_event_DeviceBindingButton3, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(ui_DeviceBinding, ui_event_DeviceBinding, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_DeviceBindingDropdown1, ui_event_SelftestDeviceBingdingDropdown1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_DeviceBindingUserBtn, ui_event_SelftestDeviceLogOut, LV_EVENT_CLICKED, NULL);

}

void ui_event_DeviceBindingButton1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        _ui_screen_change(ui_TimezoneSettings, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_DeviceBindingButton2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        _ui_screen_change(ui_SelftestTips, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_DeviceBindingButton3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        _ui_screen_change(ui_SelftestTips, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_SelftestPrivacypolicyHandle(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(target == userdata)//btn1
        {   
            lv_label_set_recolor(ui_DeviceBindingLabel5, true);  
            lv_label_set_text(ui_DeviceBindingLabel5, PrivacyPolicyTips[get_cur_language_index()]);
        }
        else                  //btn2
        {
            if (system_state.Mqtt_state) {
                CrLogI("device binding qrcode exist");
                char temp[64] = {0};
                snprintf(temp, 64, "%s %s", GetSystemConfig().device_sn, GetSystemConfig().device_mac);
                lv_obj_clear_flag(ui_DeviceBindingDropdown1, LV_OBJ_FLAG_HIDDEN);      /// Flags
                lv_qrcode_update(ui_DeviceBinding_Image3, temp, strlen(temp));
                IsrefreshCxyUserInfo = 1;
                lv_obj_add_flag(ui_DeviceBindingPanel, LV_OBJ_FLAG_HIDDEN);      /// Flags
                lv_obj_add_flag(ui_DeviceBindingLabel8, LV_OBJ_FLAG_HIDDEN);      /// Flags
                get_printer_data(CONTROL_MACHINE_STATE, 2, "6");//查询创想云绑定状态
            }
            else
            {
                CrLogI("device binding qrcode not exist");
                lv_obj_add_flag(ui_DeviceBinding_Image3, LV_OBJ_FLAG_HIDDEN);

                lv_obj_clear_flag(ui_DeviceBindingDropdown1, LV_OBJ_FLAG_HIDDEN);      /// Flags
                lv_obj_clear_flag(ui_DeviceBindingLabel8, LV_OBJ_FLAG_HIDDEN);      /// Flags
            }
        }
    }
}

void ui_event_DeviceBinding(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("Load SelftestDevice bingding page");

        if(!init_uiconfiginfo.AgreePrivacyPolicy)
        {
            int index = get_cur_language_index();
            create_PrivacyMessagebox(PrivacyPolicyTips[index], NotAgree[index], Agree[index], ui_event_SelftestPrivacypolicyHandle, ui_event_SelftestPrivacypolicyHandle);
            lv_obj_add_flag(ui_DeviceBindingDropdown1, LV_OBJ_FLAG_HIDDEN);      /// Flags
            lv_obj_add_flag(ui_DeviceBindingLabel6, LV_OBJ_FLAG_HIDDEN);      /// Flags
            lv_obj_add_flag(ui_DeviceBinding_Image3, LV_OBJ_FLAG_HIDDEN);

            lv_obj_add_flag(ui_DeviceBindingPanel, LV_OBJ_FLAG_HIDDEN);      //隐藏创想云已绑定页面
            return;
        }
        else
        {
            lv_label_set_text(ui_DeviceBindingLabel5, DeviceBindTipsMsg[get_cur_language_index()]);
            if (system_state.Mqtt_state) {
                CrLogI("device binding qrcode exist");
                char temp[64] = {0};
                snprintf(temp, 64, "%s %s", GetSystemConfig().device_sn, GetSystemConfig().device_mac);
                lv_obj_clear_flag(ui_DeviceBindingDropdown1, LV_OBJ_FLAG_HIDDEN);      /// Flags
                lv_qrcode_update(ui_DeviceBinding_Image3, temp, strlen(temp));
                lv_obj_clear_flag(ui_DeviceBinding_Image3, LV_OBJ_FLAG_HIDDEN);
                IsrefreshCxyUserInfo = 1;
                lv_obj_add_flag(ui_DeviceBindingPanel, LV_OBJ_FLAG_HIDDEN);      /// Flags
                lv_obj_add_flag(ui_DeviceBindingLabel8, LV_OBJ_FLAG_HIDDEN);      /// Flags
                get_printer_data(CONTROL_MACHINE_STATE, 2, "6");//查询创想云绑定状态
            }
            else
            {
                CrLogI("device binding qrcode not exist");
                lv_obj_add_flag(ui_DeviceBinding_Image3, LV_OBJ_FLAG_HIDDEN);

                lv_obj_clear_flag(ui_DeviceBindingDropdown1, LV_OBJ_FLAG_HIDDEN);      /// Flags
                lv_obj_clear_flag(ui_DeviceBindingLabel8, LV_OBJ_FLAG_HIDDEN);      /// Flags
            }
            get_printer_data(CONTROL_PARAMETERS, 2, "p");//查询创想云服务器状态
        }
    }
}

void ui_event_SelftestDeviceBingdingDropdown1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_READY) {
        static lv_style_t list_selected_default;
        if (list_selected_default.prop_cnt > 1)
            lv_style_reset(&list_selected_default);
        else
            lv_style_init(&list_selected_default);
        lv_style_set_radius(&list_selected_default, 0);
        lv_style_set_bg_color(&list_selected_default, lv_color_hex(0x42BDD8));
        // lv_style_set_bg_grad_color(&list_selected_default, lv_color_hex(0x42BDD8));
        lv_style_set_bg_grad_dir(&list_selected_default, LV_GRAD_DIR_NONE);
        lv_style_set_bg_opa(&list_selected_default, 255);
        lv_style_set_border_color(&list_selected_default, lv_color_make(0xe1, 0xe6, 0xee));
        lv_style_set_border_width(&list_selected_default, 0);
        lv_style_set_text_color(&list_selected_default, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_text_font(&list_selected_default, lv_font25.font);
        lv_obj_add_style(lv_dropdown_get_list(target), &list_selected_default, LV_PART_SELECTED|LV_STATE_FOCUSED);
        lv_obj_add_style(lv_dropdown_get_list(target), &list_selected_default, LV_PART_SELECTED|LV_STATE_PRESSED);

        static lv_style_t list_main_default;
        if (list_main_default.prop_cnt > 1)
            lv_style_reset(&list_main_default);
        else
            lv_style_init(&list_main_default);
        lv_style_set_radius(&list_main_default, 0);
        lv_style_set_bg_color(&list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
        lv_style_set_bg_grad_color(&list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
        lv_style_set_bg_grad_dir(&list_main_default, LV_GRAD_DIR_VER);
        lv_style_set_bg_opa(&list_main_default, 255);
        lv_style_set_border_color(&list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
        lv_style_set_border_width(&list_main_default, 0);
        lv_style_set_text_color(&list_main_default, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_text_font(&list_main_default, lv_font25.font);
        lv_style_set_max_height(&list_main_default, 150);
        lv_obj_add_style(lv_dropdown_get_list(target), &list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

        static lv_style_t scrollbar_default;
        if (scrollbar_default.prop_cnt > 1)
            lv_style_reset(&scrollbar_default);
        else
            lv_style_init(&scrollbar_default);
        lv_style_set_radius(&scrollbar_default, 3);
        lv_style_set_bg_grad_color(&scrollbar_default, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_bg_grad_dir(&scrollbar_default, LV_GRAD_DIR_VER);
        lv_style_set_bg_opa(&scrollbar_default, 0);
        lv_obj_add_style(lv_dropdown_get_list(target), &scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    }
    else if(event_code == LV_EVENT_VALUE_CHANGED) {
        int option = lv_dropdown_get_selected(target);
        CrLogI("Change the Serveroptions:%d", option);
        char tempbuff[10] = {0};
        snprintf(tempbuff, 10, "p%d", option+1);
        set_printer_data(0x06, 3, tempbuff);
    }
}

void selftest_log_out()
{
    send_buzzer(0x01);
    CrLogI("log out cxyclound");
    set_printer_data(CONTROL_MACHINE_STATE, 3, "61");//解绑用户
    selftest_messagebox_close();
    lv_obj_add_flag(ui_DeviceBindingPanel, LV_OBJ_FLAG_HIDDEN);     //隐藏创想云绑定页面
}

void selftest_not_log_out()
{
    send_buzzer(0x01);
    selftest_messagebox_close();
}

void ui_event_SelftestDeviceLogOut(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        CrLogI("user sure log out");
        void (*btns_callback[2])(void) = {&selftest_not_log_out, &selftest_log_out};
        create_selftest_messagebox(KindTips[get_cur_language_index()], LogOutTips[get_cur_language_index()],Cancel[get_cur_language_index()], ErrorBtnConfirm[get_cur_language_index()], btns_callback);
    }
}

void refresh_selftestbinding_page(char *src)
{
    if(src != NULL)
    {
        char buff[258] = {0};
        CrLogI("refresh a QR code image.");
        buff[0] = PNG_DRV_LETTER;
        strncpy(buff + 1, src, sizeof(buff) - 2);
        lv_img_set_src(ui_DeviceBinding_Image3, buff);
        lv_img_set_zoom(ui_DeviceBinding_Image3, 140);
    }
}

void selftest_bind_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if( ui_DeviceBindingLabel1 )
        lv_label_set_text(ui_DeviceBindingLabel5, DeviceBindTipsMsg[language_index]);
    if( ui_DeviceBindingLabel1 )
        lv_label_set_text(ui_DeviceBindingLabel4, JumpOver[language_index]);
    if( ui_DeviceBindingLabel1 )
        lv_label_set_text(ui_DeviceBindingLabel3, NextStep[language_index]);
    if( ui_DeviceBindingLabel1 )
        lv_label_set_text(ui_DeviceBindingLabel2, PrevStep[language_index]);
    if( ui_DeviceBindingLabel1 )
        lv_label_set_text(ui_DeviceBindingLabel1, DeviceMachine[language_index]);
    if( ui_DeviceBindingLabel6 )
        lv_label_set_text(ui_DeviceBindingLabel6, Area[language_index]);
    if ( ui_DeviceBindingDropdown1 )
    {
        char buff[256] = {0};
        memset(buff, 0, sizeof(buff));
        sprintf(buff, "%s\n%s", AreaChinese[language_index], AreaOthers[language_index]);

        uint8_t id = lv_dropdown_get_selected(ui_DeviceBindingDropdown1);
        lv_dropdown_clear_options(ui_DeviceBindingDropdown1);
        lv_dropdown_set_options(ui_DeviceBindingDropdown1, buff);
        lv_dropdown_set_selected(ui_DeviceBindingDropdown1, id);
    }
    if(ui_DeviceBindingLabel7)
        lv_label_set_text(ui_DeviceBindingLabel7, BindingTips[language_index]);

    if(ui_DeviceBindingUserBtnlabel)
        lv_label_set_text(ui_DeviceBindingUserBtnlabel, LogOut[language_index]);

    if(ui_DeviceBindingLabel8)
        lv_label_set_text(ui_DeviceBindingLabel8, IOTTips[get_cur_language_index()]);

}

void refresh_DeviceUserInfo_selftest(CloudUserInfo_t user)
{
    if(IsrefreshCxyUserInfo != 1)return;
    CrLogI("Load cloud user information,Device bingding page");
    IsrefreshCxyUserInfo = 0;

    if(!system_state.CxyUserInfoState)return;   //如果无创想云用户信息
    lv_obj_clear_flag(ui_DeviceBindingPanel, LV_OBJ_FLAG_HIDDEN);      /// Flags
    if(ui_DeviceBindingUsername != NULL)
    {
        char namebuff[100] = {0};
        snprintf(namebuff, 100, "%s:%s", UserName[get_cur_language_index()], user.UserName);
        lv_label_set_text(ui_DeviceBindingUsername, namebuff);
    }

    if(ui_DeviceBindingUserid != NULL)
    {
        char namebuff[100] = {0};
        snprintf(namebuff, 100, "ID:%s", user.UserID);
        lv_label_set_text(ui_DeviceBindingUserid, namebuff);
    }

    if(ui_DeviceBindingUserimg != NULL)
    {
        char buff[258] = {0};
        snprintf(buff, 258, "%s:%s", PNG_DRV_LETTER, user.UserImg);
        CrLogI("UserImg file path: %s", buff);
        lv_obj_clear_flag(ui_DeviceBindingUserimg, LV_OBJ_FLAG_HIDDEN);      /// Flags
        lv_img_set_src(ui_DeviceBindingUserimg, buff);
        lv_obj_update_layout(ui_DeviceBindingUserimg);
        int width = lv_obj_get_width(ui_DeviceBindingUserimg);
        int height = lv_obj_get_height(ui_DeviceBindingUserimg);
        if(width > 0 && height > 0)
        {
            int scale = 256 * 78 / width;
            CrLogI("UserImg width: %d,height:%d, scale:%d", width, height, scale);
            lv_img_set_zoom(ui_DeviceBindingUserimg, scale);

        }
        else
        {
            CrLogI("UserImg width: %d,height:%d", width, height);
            lv_obj_add_flag(ui_DeviceBindingUserimg, LV_OBJ_FLAG_HIDDEN);      /// Flags
        }
    }
}

void SelftsetChangeServerOption(int ServerOption)
{
    CrLogI("selftestdevicepage Change Server Option:%d", ServerOption);
    if(ui_DeviceBindingDropdown1)
        lv_dropdown_set_selected(ui_DeviceBindingDropdown1, ServerOption - 1);
}