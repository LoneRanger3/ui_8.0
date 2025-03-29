/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2023-02-02 14:59:41
 * @LastEditTime: 2023-03-10 18:15:39
 */
#include "ui.h"
#include "mult_language.h"

lv_obj_t * ui_SelftestCompleted;
lv_obj_t * ui_SelftestCompletedLabel1;
lv_obj_t * ui_SelftestCompletedButton1;
lv_obj_t * ui_SelftestCompletedBtnLabel1;
lv_obj_t * ui_SelftestCompletedButton2;
lv_obj_t * ui_SelftestCompletedBtnLabel2;
lv_obj_t * ui_SelftestCompletedImage1;
bool isCheckFireware = false;

void ui_event_SelftestCompletedButton1(lv_event_t * e);
void ui_event_SelftestCompletedButton2(lv_event_t * e);
void ui_event_SelftestCompleted(lv_event_t * e);

void ui_SelftestCompleted_screen_init(void)
{
    ui_SelftestCompleted = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SelftestCompleted, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_SelftestCompleted, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestCompleted, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestCompletedLabel1 = lv_label_create(ui_SelftestCompleted);
    lv_obj_set_width(ui_SelftestCompletedLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SelftestCompletedLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SelftestCompletedLabel1, 0);
    lv_obj_set_y(ui_SelftestCompletedLabel1, 205);
    lv_obj_set_align(ui_SelftestCompletedLabel1, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_SelftestCompletedLabel1, "恭喜您已完成所有流程！请开始您的高速打印吧！");
    lv_obj_set_style_text_color(ui_SelftestCompletedLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestCompletedLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestCompletedLabel1, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SelftestCompletedLabel1, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestCompletedButton1 = lv_btn_create(ui_SelftestCompleted);
    lv_obj_set_width(ui_SelftestCompletedButton1, 146);
    lv_obj_set_height(ui_SelftestCompletedButton1, 60);
    lv_obj_set_x(ui_SelftestCompletedButton1, 196);
    lv_obj_set_y(ui_SelftestCompletedButton1, 400);
    lv_obj_add_flag(ui_SelftestCompletedButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SelftestCompletedButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftestCompletedButton1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestCompletedButton1, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestCompletedButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SelftestCompletedButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SelftestCompletedButton1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestCompletedBtnLabel1 = lv_label_create(ui_SelftestCompletedButton1);
    lv_obj_set_width(ui_SelftestCompletedBtnLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SelftestCompletedBtnLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SelftestCompletedBtnLabel1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SelftestCompletedBtnLabel1, "上一步");
    lv_obj_set_style_text_font(ui_SelftestCompletedBtnLabel1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestCompletedButton2 = lv_btn_create(ui_SelftestCompleted);
    lv_obj_set_width(ui_SelftestCompletedButton2, 146);
    lv_obj_set_height(ui_SelftestCompletedButton2, 60);
    lv_obj_set_x(ui_SelftestCompletedButton2, 458);
    lv_obj_set_y(ui_SelftestCompletedButton2, 400);
    lv_obj_add_flag(ui_SelftestCompletedButton2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_SelftestCompletedButton2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SelftestCompletedButton2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestCompletedButton2, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestCompletedButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SelftestCompletedButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SelftestCompletedButton2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestCompletedBtnLabel2 = lv_label_create(ui_SelftestCompletedButton2);
    lv_obj_set_width(ui_SelftestCompletedBtnLabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SelftestCompletedBtnLabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SelftestCompletedBtnLabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SelftestCompletedBtnLabel2, "开始");
    lv_obj_set_style_text_font(ui_SelftestCompletedBtnLabel2, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestCompletedImage1 = lv_img_create(ui_SelftestCompleted);
    lv_img_set_src(ui_SelftestCompletedImage1, &ui_img_881581767);
    lv_obj_set_width(ui_SelftestCompletedImage1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SelftestCompletedImage1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_SelftestCompletedImage1, 385);
    lv_obj_set_y(ui_SelftestCompletedImage1, 138);
    lv_obj_add_flag(ui_SelftestCompletedImage1, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_SelftestCompletedImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_SelftestCompletedButton1, ui_event_SelftestCompletedButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SelftestCompletedButton2, ui_event_SelftestCompletedButton2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_SelftestCompleted, ui_event_SelftestCompleted, LV_EVENT_ALL, NULL);
}

void ui_event_SelftestCompletedButton1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        _ui_screen_change(ui_SelftestTips, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_SelftestCompletedButton2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        selftestflag = false;
        if( CheckUpdataFlag )
        {
            DotCheckVersion = 1;
            EnterUpdatepage(1);
        }
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
        lv_label_set_text(ui_SelftestCompletedLabel1, SelftestCompletedTips[index]);
        lv_label_set_text(ui_SelftestCompletedBtnLabel2, Boot1Tips3[index]);
        
        lv_obj_add_flag(ui_SelftestCompletedButton1, LV_OBJ_FLAG_HIDDEN);     /// Flags
        lv_obj_align(ui_SelftestCompletedButton2, LV_ALIGN_TOP_MID, 0, 400);      

        if(system_state.Udisk_state)
        {
            char tempbuff[300] = {0};
            snprintf(tempbuff, 256, "%s/%s", GetPrintRunState().uDiskPath, GetSELFTESTFIRMWAREFileName());
            CrLogI("the path %s", tempbuff);
            //检查U盘是否有特定文件，有则进入固件老化测试流程
            if(access(tempbuff, F_OK) == 0)
            {
                //停止按钮点击
                lv_obj_clear_flag(ui_SelftestCompletedButton2, LV_OBJ_FLAG_CLICKABLE);

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
