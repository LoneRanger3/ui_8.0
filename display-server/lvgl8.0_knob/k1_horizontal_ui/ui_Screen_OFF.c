/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2023-01-04 17:42:33
 * @LastEditTime: 2023-09-27 06:08:24
 */
#include "ui.h"
#include "mult_language.h"
#include <stdbool.h>
#include <stdio.h>

//lv_obj_t * ui_Screenoff;
lv_obj_t * ui_ScreenoffPanel1;
lv_obj_t * last_screen_page;
bool ScreenOffFlag = false;

void ui_event_Screenoff(lv_event_t * e);
void ScreenoffAddObjsToGroup(void);

void ui_Screenoff_screen_init(void)
{
    //ui_Screenoff = lv_obj_create(NULL);
    //lv_obj_clear_flag(ui_Screenoff, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    //TODO：临时修改黑色背景
    ui_ScreenoffPanel1 = lv_obj_create(lv_layer_sys());
    lv_obj_set_width(ui_ScreenoffPanel1, 640);
    lv_obj_set_height(ui_ScreenoffPanel1, 480);
    lv_obj_clear_flag(ui_ScreenoffPanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScreenoffPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScreenoffPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenoffPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ScreenoffPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ScreenoffPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ScreenoffPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ScreenoffPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ScreenoffPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ScreenoffPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ScreenoffPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_ScreenoffPanel1, LV_OBJ_FLAG_HIDDEN);      /// Flags

    lv_obj_add_event_cb(ui_ScreenoffPanel1, ui_event_Screenoff, LV_EVENT_ALL, NULL);
    //lv_obj_add_event_cb(ui_Screenoff, ui_event_Screenoff, LV_EVENT_ALL, NULL);

} 

void ExitScreenOff()
{
    set_printer_data(0x1b,1,"2");//退出息屏
    DeinitPopoutManager(&ScreenOffPopout);
    lv_obj_add_flag(ui_ScreenoffPanel1, LV_OBJ_FLAG_HIDDEN);      /// Flags
    lv_obj_add_flag(lv_layer_sys(), LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(lv_layer_sys(), LV_OBJ_FLAG_CLICKABLE);
    // if (ErrorPopout.popout_focus_obj1 != NULL || ErrorPopout.popout_focus_obj2 != NULL)
    // {
    //     ErrorPopout.change_group_objs();
    // }
    // // //TODO:增加其他等级处理
    // else
    if (IsThereAnyPopout())
    {
        lv_indev_enable(enc_indev, true);
        ManagePopoutFocus();
    }
    else
    {
        //lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
        CrLogI("ui_event_Screenoff BackPrepage(true)");
        //lv_group_focus_freeze(encoder_group, false);
        lv_indev_enable(enc_indev, true);
        BackPrepage(true);
    }
    
    if(!lv_obj_has_flag(ui_Msgbox, LV_OBJ_FLAG_HIDDEN))
    {
        //lv_group_focus_freeze(encoder_group, true);
        lv_indev_enable(enc_indev, false);
    }
}

void ui_event_Screenoff(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load screen_off page");
        lv_obj_move_to_index(ui_ScreenoffPanel1, -1);
    }
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        CrLogI("quit screen_off page.");
        ScreenOffFlag = false;
        ExitScreenOff();
    }
}

/**
 * @description: 进入息屏模式，也可以理解为进入息屏页面
 * @return {*}
 * @param {lv_obj_t *} target
 */
void enter_screenoff_mode(lv_obj_t * target)
{
    ScreenOffFlag = true;
    system_state.HasEncoderEvent = false;
    //lv_group_focus_freeze(encoder_group, false);
    lv_indev_enable(enc_indev, true);
    if (!IsThereAnyPopout())
    {
        RecordObjBeforePopup();
    }

    last_screen_page = target;
    // _ui_screen_change(ui_Screenoff, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    lv_obj_clear_flag(ui_ScreenoffPanel1, LV_OBJ_FLAG_HIDDEN);      /// Flags
    lv_obj_clear_flag(lv_layer_sys(), LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(lv_layer_sys(), LV_OBJ_FLAG_CLICKABLE);
    //ScreenoffAddObjsToGroup();

    InitPopoutManager(&ScreenOffPopout, ui_ScreenoffPanel1, ScreenoffAddObjsToGroup);

    ScreenOffPopout.obj1_flag = true;
    ScreenOffPopout.popout_focus_obj1 = ui_ScreenoffPanel1;

    ManagePopoutFocus();
}

void ScreenOffAbnormalProcess()
{
    static char AbnormalTimes = 0;  //用于解决息屏关闭过程中偶尔会触发点击事件的问题
    if(ScreenOffFlag == true)
    {
        
        lv_indev_enable(enc_indev, true);
        if (system_state.HasEncoderEvent)
        {
            AbnormalTimes++;
            CrLogI("Screen off abnormal process. AbnormalTimes = %d", AbnormalTimes);
            if (AbnormalTimes == 2)
            {
                AbnormalTimes = 0;
                ScreenOffFlag = false;
                system_state.HasEncoderEvent = false;
                ExitScreenOff();
                CrLogI("Screen off abnormal process.");
            }
        }
        else
        {
            AbnormalTimes = 0;
        }
    }
}

void ScreenoffAddObjsToGroup(void)
{
    lv_group_remove_all_objs(encoder_group);
   // lv_indev_set_group(enc_indev, NULL); 
   // lv_indev_set_group(enc_indev, encoder_group); //关联组
    lv_group_add_obj(encoder_group, ui_ScreenoffPanel1);
    //lv_group_add_obj(encoder_group, ui_Screenoff);
}