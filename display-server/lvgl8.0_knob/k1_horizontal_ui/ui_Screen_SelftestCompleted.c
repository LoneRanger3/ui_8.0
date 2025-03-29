/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2023-02-02 14:59:41
 * @LastEditTime: 2023-11-01 22:58:52
 */
#include "ui.h"
#include "mult_language.h"

lv_obj_t * ui_SelftestCompleted;
static lv_obj_t * ui_PanelSelfTestCompleted;
static lv_obj_t * ui_ImgSelfTestCompleted;
static lv_obj_t * ui_LabelSelfTestCompleted;
static lv_obj_t * ui_ButtonConfirm;
static lv_obj_t * ui_LabelConfirm;
static void LoadSelfTestCompletedScreen(void);
static void SelfTestCompletedPageChangeObjs(uint8_t index);

lv_obj_t * ui_SelftestCompletedLabel1;
lv_obj_t * ui_SelftestCompletedButton1;
lv_obj_t * ui_SelftestCompletedBtnLabel1;
lv_obj_t * ui_SelftestCompletedButton2;
lv_obj_t * ui_SelftestCompletedBtnLabel2;
lv_obj_t * ui_SelftestCompletedImage1;
bool isCheckFireware = false;

void ui_event_ButtonConfirm(lv_event_t * e);
void ui_event_SelftestCompletedButton2(lv_event_t * e);
void ui_event_SelftestCompleted(lv_event_t * e);

void ui_SelftestCompleted_screen_init(void)
{
    uint8_t language_index = get_cur_language_index();
    ui_SelftestCompleted = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SelftestCompleted, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_SelftestCompleted, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestCompleted, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    init_pages(ui_SelftestCompleted, SelfTestCompletedPageChangeObjs, LoadSelfTestCompletedScreen);

    //页面板
    ui_PanelSelfTestCompleted = lv_obj_create(ui_SelftestCompleted);
    lv_obj_set_width(ui_PanelSelfTestCompleted, 640);
    lv_obj_set_height(ui_PanelSelfTestCompleted, 360);
    lv_obj_set_align(ui_PanelSelfTestCompleted, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelSelfTestCompleted, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelSelfTestCompleted, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelSelfTestCompleted, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelSelfTestCompleted, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelSelfTestCompleted, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_PanelSelfTestCompleted, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_PanelSelfTestCompleted, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_PanelSelfTestCompleted, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_PanelSelfTestCompleted, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //自检完成图片
    ui_ImgSelfTestCompleted = lv_img_create(ui_PanelSelfTestCompleted);
    lv_obj_set_size(ui_ImgSelfTestCompleted, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_ImgSelfTestCompleted, LV_ALIGN_TOP_MID, 0, 80);
    lv_img_set_src(ui_ImgSelfTestCompleted, &ui_img_complete_png);
    lv_obj_add_flag(ui_ImgSelfTestCompleted, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgSelfTestCompleted, LV_OBJ_FLAG_SCROLLABLE); 

    //自检完成标签
    ui_LabelSelfTestCompleted = lv_label_create(ui_PanelSelfTestCompleted);
    lv_obj_set_width(ui_LabelSelfTestCompleted, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelSelfTestCompleted, LV_SIZE_CONTENT);    /// 1
    lv_obj_align(ui_LabelSelfTestCompleted, LV_ALIGN_TOP_MID, 0, 192);
    lv_label_set_text(ui_LabelSelfTestCompleted, SelftestCompletedTips[language_index]);
    lv_obj_set_style_text_color(ui_LabelSelfTestCompleted, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSelfTestCompleted, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSelfTestCompleted, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelSelfTestCompleted, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    //确定按钮
    ui_ButtonConfirm = lv_btn_create(ui_PanelSelfTestCompleted);
    lv_obj_set_width(ui_ButtonConfirm, 176);
    lv_obj_set_height(ui_ButtonConfirm, 52);
    lv_obj_align(ui_ButtonConfirm, LV_ALIGN_TOP_MID, 0, 294);
    lv_obj_add_flag(ui_ButtonConfirm, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonConfirm, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonConfirm, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonConfirm, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonConfirm, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonConfirm, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonConfirm, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_ButtonConfirm, lv_color_hex(0xFFFFFF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonConfirm, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonConfirm, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonConfirm, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonConfirm, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    //确定标签
    ui_LabelConfirm = lv_label_create(ui_ButtonConfirm);
    lv_obj_set_width(ui_LabelConfirm, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelConfirm, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelConfirm, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelConfirm, Confirm[language_index]);
    lv_obj_set_style_text_font(ui_LabelConfirm, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_ButtonConfirm, ui_event_ButtonConfirm, LV_EVENT_ALL, NULL);
    //lv_obj_add_event_cb(ui_SelftestCompletedButton2, ui_event_SelftestCompletedButton2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SelftestCompleted, ui_event_SelftestCompleted, LV_EVENT_ALL, NULL);
}

void ui_event_ButtonConfirm(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        set_printer_data(0x06,2,"90");
        selftestflag = false;
        if( CheckUpdataFlag )
        {
            DotCheckVersion = 1;
            EnterUpdatepage(1);
        }
        LoadHomeNormalPageAndObjs(false);
    }
}

void ui_event_SelftestCompletedButton2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        set_printer_data(0x06,2,"90");
        selftestflag = false;
        if ( home_printing_is_printing_finished() )
            LoadHomeNormalScreen();
        else
            LoadHomePrintingScreen();
    }
}

void ui_event_SelftestCompleted(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        uint8_t index = get_cur_language_index();
        // lv_label_set_text(ui_LabelSelfTestCompleted, SelftestCompletedTips[index]);
        // lv_label_set_text(ui_SelftestCompletedBtnLabel2, Boot1Tips3[index]);
        
       // lv_obj_add_flag(ui_ButtonConfirm, LV_OBJ_FLAG_HIDDEN);     /// Flags
      //  lv_obj_align(ui_SelftestCompletedButton2, LV_ALIGN_TOP_MID, 0, 400);  

        if(system_state.Udisk_state)
        {
            char tempbuff[300] = {0};
            snprintf(tempbuff, 256, "%s/%s", GetPrintRunState().uDiskPath, GetSELFTESTFIRMWAREFileName());
            CrLogI("the path %s", tempbuff);
            //检查U盘是否有特定文件，有则进入固件老化测试流程
            if(access(tempbuff, F_OK) == 0)
            {
                //停止按钮点击
                lv_obj_add_state(ui_ButtonConfirm, LV_STATE_DISABLED);

                //归零并移动到最下方
                isCheckFireware = true;
                set_printer_data(CONTROL_XYZ_AXIS, 3, "E00");

            } 
        } 

    }
}

void judgeEnterCheckFireware(int number)
{
    if(!isCheckFireware)return;
    if(number == 1)//归零结束移动到最下方
    {
        float zposition = atof(cur_zposition);
        float zmaxposition = 0;
        if(UIType == CR_K1_Max)
            zmaxposition = 300.0 - 1;
        else
            zmaxposition = 250.0 - 1;
        CrLogI("z position:%f", zposition);
        char tempbuff[64] = {0};
        snprintf(tempbuff, 64, "Z%.0f F%s", (zmaxposition - zposition), "600"); // system_state.Z_Axis_Max
        set_printer_data(CONTROL_XYZ_AXIS, strlen(tempbuff), tempbuff);
    }
    else if(number == 2)//移动结束判断是否存在文件恢复出厂设置
    {
        CrLogI("number:%d", number);
        if(system_state.Udisk_state)
        {
            char tempbuff[300] = {0};
            snprintf(tempbuff, 256, "%s/%s", GetPrintRunState().uDiskPath, GetSELFTESTFIRMWAREFileName());
            CrLogI("tempbuff:%s", tempbuff);
            //检查U盘是否有特定文件，有则恢复出厂设置
            if(access(tempbuff, F_OK) == 0)
            {
                set_printer_data(0x06,6,"61111");
            } 
        }
    }
}


void selftest_complete_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if (ui_LabelSelfTestCompleted)
        lv_label_set_text(ui_LabelSelfTestCompleted, SelftestCompletedTips[language_index]);

    if (ui_LabelConfirm)
        lv_label_set_text(ui_LabelConfirm, Confirm[language_index]);

}

void LoadSelfTestCompletedScreen(void)
{
    _ui_screen_change(ui_SelftestCompleted, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}

// void LoadHomeNormalPageAndObjs(bool IsEntered)
// {

// }


void SelfTestCompletedPageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    PageNode *SelfTestCompletedPage_node = find_page(ui_SelftestCompleted);
    SelfTestCompletedPage_node->nav_level = index;
    page_manager.objFreezzFlag = false;

    switch (index)
    {
    case 1: //1级事件组
        lv_group_add_obj(encoder_group, ui_ButtonConfirm);
        break;
    default:
        break;
    }
}