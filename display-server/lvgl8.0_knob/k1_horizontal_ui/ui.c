// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: SquareLine_Project

#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "ui_Screen_Settings.h"
#include "ui_screen_VedioInfo.h"
#include "ui_screen_CameraList.h"

#include "ui_screen_FullScreen.h"
#include "ui_screen_HomePrinting.h"
#include "ui_screen_HomeNormal.h"
#include "ui_screen_AxisMove.h"
#include "ui_screen_Adjustment.h"
#include "ui_screen_FileManage.h"
#include "ui_screen_SubDir.h"
#include "ui_screen_PrintHistory.h"
#include "ui_screen_Preview.h"
#include "ui_screen_camera_settings.h"
#include "ui_Screen_CustomerService.h"
#include "ui_screen_cool.h"
#include "custom/lvgl_cmd.h"
#include "ui_screen_DetectionAI.h"
#include "lv_drivers/indev/keypad_encoder.h"
#include <bits/types.h>
#include "CrLog.h"

///////////////////// VARIABLES ////////////////////



int CheckKlipperState = 0;
uint8_t CheckUiStartState = 0;
int DotCheckVersion = 0; //开机检查版本更新标志
bool FirstInitFlag = false;
PrintJobInfo_t print_job = {0};
///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
// void ui_event_SystemsettingImage4(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         _ui_screen_change(ui_SelftestSettime, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
//     }
// }

void AbnormalCloseSubPage(void)
{
    AxisMovePageCloseSubPage();
    SettingsPageCloseSubPage();
    CustomerServicePageCloseSubPage();
}

/**
 * @description: 用于监测事件组聚焦对象的状态，主要看事件组是否失去聚焦对象
 * @return {*}
 * @param {void} *arg
 */
static void *EventGroupMonitorThread(void *arg)
{
    char i = 0, child_obj_cnt = 0;
    lv_obj_t *child_obj = NULL;
    static char lose_focus_cnt = 0;
    while (1)
    {
        sleep(1);
        ui_pthread_mutex_lock();
        //失去聚焦对象处理
        if (lv_group_get_focused(encoder_group) == NULL)
        {
            CrLogE("focus obj %p, focus count = %d, lose_focus_cnt = %d", lv_group_get_focused(encoder_group), lv_group_get_obj_count(encoder_group), lose_focus_cnt);
            lv_group_focus_prev(encoder_group);
            lose_focus_cnt++;
            if (lose_focus_cnt == 3)
            {
                lose_focus_cnt = 0;
                if (isFactoryTest()) {
                   // BackFactoryTestScreen(); 
                }
                else if(isMachineTest()) {
                   // LoadMachinetestScreen();
                }
                else if (selftestflag) {
                    LoadPage(ui_changelanguage, 0);
                }
                else {
                    if ( home_printing_is_printing_finished() )
                        LoadHomeNormalPageAndObjs(false);
                    else
                        LoadHomePrintingPageAndObjs(false);
         
                    AbnormalCloseSubPage();                    
                }
            }
        }
        else
        {
            lose_focus_cnt = 0;
        }
        //检测
        if(!lv_obj_has_flag(ui_ScreenoffPanel1, LV_OBJ_FLAG_HIDDEN))
        {
            //printf("ui_ScreenoffPanel1 show!\n");
            if (lv_group_get_focused(encoder_group) != ui_ScreenoffPanel1)
            {
                CrLogI("lv_group_focus_obj(ui_ScreenoffPanel1);\n");
                enter_screenoff_mode(lv_scr_act());
                lv_group_focus_obj(ui_ScreenoffPanel1);
            }
        }
        //聚焦管理，处理聚焦异常,如果有高级别的弹框，聚焦却不在上面，需要调整聚焦
        if (IsFocusAbnormal())
        {
            ManagePopoutFocus();
        }
        //当top层隐藏时，如果top层有未隐藏子对象，应该让top层显示并可点击
        if( (child_obj_cnt = lv_obj_get_child_cnt(lv_layer_top())) )
        {
            if(lv_obj_has_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN))
            {
                for (i = 0; i < child_obj_cnt; i++)
                {
                    child_obj = lv_obj_get_child(lv_layer_top(), i);
                    if (!lv_obj_has_flag(child_obj, LV_OBJ_FLAG_HIDDEN))
                    {
                        CrLogI("lv_layer_top has other not hide child but lv_layer_top hide\n");
                        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
                        lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
                    }
                }
            }
        }
        ScreenOffAbnormalProcess();
        ui_pthread_mutex_unlock();
    }
}

void ui_init(UIInit_t init_ui)
{
    
#if LV_USE_LOG
    lv_log_register_print_cb(lvgl_log_print);
#endif
    LV_EVENT_GET_COMP_CHILD = lv_event_register_id();

    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_camerasetting_screen_init();
    ui_Cameralist_screen_init();
    ui_VedioInfo_screen_init();
    ui_changelanguage_screen_init();
    ui_Keytonesetting_screen_init();
    ui_SelfTestDevicebinding_screen_init();
    ui_Exportlog_screen_init();
    ui_Settings_screen_init();
    ui_UpdateVersion_screen_init();
    ui_AboutDevice_screen_init();
    ui_ResetMachine_screen_init();
    ui_SelftestPrivacyPolicy_screen_init();
    ui_SelftestNetwork_screen_init();
    ui_SelftestTips_screen_init();
    ui_SelftestAll_screen_init();
    ui_Manualtest_screen_init();
	ui_NetworkInfo_screen_init();
    ui_Screenoff_screen_init();
    ui_ScreenCool_screen_init();
    //ui_ScreenFilament_screen_init();

    ui_TimezoneSettings_screen_init();
    //ui_DeviceBinding_screen_init();
    ui_SelftestCompleted_screen_init();
    ui_CustomerFaq_screen_init();
    ui_CustomerWiki_screen_init();
    /*****************************/
    ui_ScreenHomePagePrinting_screen_init();
    ui_ScreenHomePageNormal_screen_init();
    ui_ScreenAxisMovePage_screen_init();
    ui_ScreenAdjustmentPage_screen_init();
    ui_ScreenFull_screen_init();
    ui_ScreenFileManage_screen_init();
    ui_ScreenSubDir_screen_init();
    ui_ScreenPrintHistory_screen_init();
    ui_ScreenPreview_screen_init();
    ui_ScreenCustomerService_screen_init();
    ui_ScreenAI_screen_init();
    init_msgbox();
    init_uploadlog_msg();
    send_get_cur_language_cmd();

    get_printer_data(CONTROL_MACHINE_STATE, 2, "4");//获取U盘状态
    get_printer_data(CONTROL_XYZ_AXIS_RANGE, 2, "1");//获取xyz最大移动值
    get_printer_data(CONTROL_PARAMETERS, 2, "o");   //获取更新提醒状态
    get_printer_data(CONTROL_PARAMETERS, 2, "7");   //获取断料状态
    //get_printer_data(CONTROL_PARAMETERS, 2, "l");   //TODO:获取静音模式状态--预留
    get_printer_data(CONTROL_MACHINE_STATE, 2, "b");//获取IOT状态
    get_printer_data(CONTROL_MACHINE_STATE, 2, "5");    //获取摄像头状态
    get_printer_data(CONTROL_MACHINE_STATE, 2, "a");    //获取轮廓仪状态
    axis_move_set_z_move_forward_dir(init_ui.ZAxisForwardMoveDir);
    
    if(system_state.Udisk_state)//检查U盘是否有特定文件，有则进入固件老化测试流程
    {
        char tempbuff[300] = {0};
        snprintf(tempbuff, 256, "%s/%s", GetPrintRunState().uDiskPath, GetSELFTESTFIRMWAREFileName());
        CrLogI("the path %s", tempbuff);
        if(access(tempbuff, F_OK) == 0)
        {
            selftestflag = true;
            LoadPage(ui_SelftestAll, 1);
            //_ui_screen_change(ui_SelftestAll, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
            return;
        }
    }
    FirstInitFlag = true;

    if(!selftestflag)
    {
        LoadHomeNormalPageAndObjs(false);
        // LoadHomePrintingPageAndObjs(false); //方便调试打印页面
        get_printer_data(0x1a,1,"1");//查询OTA版本升级信息
        systemsettingflag = true;   //开机查询一次OTA版本是否有更新
    }
    else
    {
        LoadPage(ui_changelanguage, 0);
        //_ui_screen_change(ui_changelanguage, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }

    // 创建检测事件组状态的线程
    pthread_t EventGroupMonitorHandle;
    int res = pthread_create(&EventGroupMonitorHandle, NULL, (void*)EventGroupMonitorThread, NULL);
    if (res)
    {
        CrLogE("create EventGroupMonitorThread error!\n");
        return;
    }

    // 启动产测程序
    if (isFactoryTest()) {
        ui_ScreenFactoryTest_screen_init();
       // ui_load_FactotytestScreen();
        LoadFactotytestScreen();
    }
    if(isMachineTest()) {
        ui_machine_test_init();
        //ui_load_machinetestScreen();
        LoadMachinetestScreen();
    }
    CheckUiStartState = 1;
   //lv_scr_load(ui_changelanguage);
   //LoadFileManageScreen();
}
#if LV_USE_LOG
//lvgl 日志注册函数
void lvgl_log_print(char * buff)
{
    CrLogI("%s",buff);
}

uint8_t EncoderModeChange(lv_group_t * group, lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    //切换编码器的编辑或导航模式
    if(event_code == LV_EVENT_SHORT_CLICKED) {  //短按进入
        if (lv_group_get_editing(group)) //当前是编辑模式
        {
            lv_group_set_editing(group, false);
            return 1;
        }
        else
        {
            lv_group_set_editing(group, true);
            return 0;
        }
    }
    return 2;
}

/**
 * @description: 
 * @return {0：编辑模式， 1：导航模式，2： 是}
 * @param {lv_event_t *} e
 */
void EncoderChangeLableValue(lv_obj_t * label,  lv_event_t * e, int32_t Min, int32_t Max)
{
    int32_t value = 0;
    char value_char[6] = {0};

    EncodeDirSpeed_t EncoderCmd = GetEncoderDirSpeed(e);
    if(!EncoderCmd){
        return;
    }

    //编辑下处理lable值
    switch (EncoderCmd)
    {
    case ENCODER_LEFT_FAST:
        /* code */
        //printf("左旋 快\n"); //设置label的值
        value = atoi(lv_label_get_text(label));
        sprintf(value_char, "%d", (value - 10) > Min? (value - 10) : Min);
        lv_label_set_text(label, value_char);
        break;
    case ENCODER_LEFT_SLOW:
        /* code */
        //printf("左旋 慢\n");
        value = atoi(lv_label_get_text(label));
        sprintf(value_char, "%d", (value - 1) > Min? (value - 1) : Min);
        lv_label_set_text(label, value_char);
        break;
    case ENCODER_RIGHT_FAST:
        /* code */
        //printf("右旋 快\n");
        value = atoi(lv_label_get_text(label));
        sprintf(value_char, "%d", (value + 10) < Max ? (value + 10) : Max);
        lv_label_set_text(label, value_char);
        break;
    case ENCODER_RIGHT_SLOW:
        /* code */
        //printf("右旋 慢\n");
        value = atoi(lv_label_get_text(label));
        sprintf(value_char, "%d", (value + 1) < Max ? (value + 1) : Max);
        lv_label_set_text(label, value_char);
        break;    
    default:
        //printf("無效的編碼器命令 %x\n", EncoderCmd);
        break;
    }
}

char *EncoderChangeValue(uint16_t inValue, uint8_t step, lv_event_t * e, int32_t Min, int32_t Max)
{
    static char value_char[6] = {0};

    EncodeDirSpeed_t EncoderCmd = GetEncoderDirSpeed(e);
    if (!EncoderCmd)
        return NULL;

    //编辑下处理lable值
    switch (EncoderCmd)
    {
    case ENCODER_LEFT_FAST:
        /* code */
        if (inValue <= step)
            inValue = Min;
       // printf("左旋 快\n"); //设置label的值  
        sprintf(value_char, "%d", (inValue - step) > Min? (inValue - step) : Min);
        break;
    case ENCODER_LEFT_SLOW:
        /* code */
        if (inValue <= 1)
            inValue = Min;
        //printf("左旋 慢\n");
        sprintf(value_char, "%d", (inValue - 1) > Min? (inValue - 1) : Min);
        break;
    case ENCODER_RIGHT_FAST:
        /* code */
       // printf("右旋 快\n");   
        sprintf(value_char, "%d", (inValue + step) < Max ? (inValue + step) : Max);
        break;
    case ENCODER_RIGHT_SLOW:
        /* code */
        // printf("右旋 慢\n");
        sprintf(value_char, "%d", (inValue + 1) < Max ? (inValue + 1) : Max);
        break;    
    default:
        //printf("無效的編碼器命令 %x\n", EncoderCmd);
        break;
    }

    return value_char;
}
#endif