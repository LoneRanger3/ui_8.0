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

///////////////////// VARIABLES ////////////////////

int CheckKlipperState = 0;
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
    ui_Devicebinding_screen_init();
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
    // ui_ScreenCool_screen_init();
    // ui_ScreenFilament_screen_init();

    ui_TimezoneSettings_screen_init();
    ui_DeviceBinding_screen_init();
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
    ui_BootPart0_screen_init();
    ui_BootPart3_screen_init();
    ui_ExcludeObject_screen_init();
    ui_Expert_mode_screen_init();
    ui_ScreenZoffsetPage_screen_init();
    ui_ScreenTrafficPage_screen_init();
    ui_BedMesh_screen_init();
    ui_ScreenBedPidPage_screen_init();
    ui_ScreenHotPidPage_screen_init();

    init_msgbox();
    init_uploadlog_msg();
    init_printcompleted_msg();

    send_get_cur_language_cmd();
    get_printer_data(CONTROL_MACHINE_STATE, 2, "4");//获取U盘状态
    get_printer_data(CONTROL_XYZ_AXIS_RANGE, 2, "1");//获取xyz最大移动值
    get_printer_data(CONTROL_PARAMETERS, 2, "o");   //获取更新提醒状态
    get_printer_data(CONTROL_PARAMETERS, 2, "7");   //获取断料状态
    get_printer_data(CONTROL_PARAMETERS, 2, "l");   //获取静音模式状态
    get_printer_data(CONTROL_MACHINE_STATE, 2, "b");//获取IOT状态
    axis_move_set_z_move_forward_dir(init_ui.ZAxisForwardMoveDir);
    
    if(system_state.Udisk_state)//检查U盘是否有特定文件，有则进入固件老化测试流程
    {
        char tempbuff[300] = {0};
        snprintf(tempbuff, 256, "%s/%s", GetPrintRunState().uDiskPath, GetSELFTESTFIRMWAREFileName());
        CrLogI("the path %s", tempbuff);
        if(access(tempbuff, F_OK) == 0)
        {
            selftestflag = true;
            _ui_screen_change(ui_SelftestAll, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
            return;
        }
    }
    FirstInitFlag = true;

    if(!selftestflag)
    {
        LoadHomeNormalScreen();
        get_printer_data(0x1a,1,"1");//查询OTA版本升级信息
        systemsettingflag = true;   //开机查询一次OTA版本是否有更新
    }
    else
    {
        _ui_screen_change(ui_changelanguage, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0);
    }

    // 启动产测程序
    if (isFactoryTest()) {
        ui_ScreenFactoryTest_screen_init();
        ui_load_FactotytestScreen();
    }
    if(isMachineTest()) {
        ui_machine_test_init();
        ui_load_machinetestScreen();
    }
}
#if LV_USE_LOG
//lvgl 日志注册函数
void lvgl_log_print(char * buff)
{
    CrLogI("%s",buff);
}
#endif

void ui_change(int pagenumber)
{
    if(pagenumber >= PAGE_COUNT)
    {
        CrLogE("page number error, exit");
        return;
    }
    CrLogI("change page,pagenumber:%d", pagenumber);

    switch (pagenumber)
    {
        case PAGE_HOME:         LoadHomeNormalScreen();break;
        case PAGE_HOME_PRINT:   LoadHomePrintingScreen();break;
        case PAGE_AXIS:         LoadAxisMoveScreen();break;
        case PAGE_FILEMANAGE:   LoadFileManageScreen();break;
        case PAGE_SETING:       LoadSettingsScreen();break;
        case PAGE_HELP:         LoadCustomerServiceScreen();break;
        case PAGE_ADVANCEDMODE: _ui_screen_change(ui_ExpertModePage, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);break;
        case PAGE_BEDLEVEL:     _ui_screen_change(ui_BedMeshBg, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);break;
        default:CrLogW("don't match the numberpage");break;
    }
}