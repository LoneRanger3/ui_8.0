#include "ui_screen_HomePrinting.h"
#include "page_switch.h"
#include "src/core/lv_obj.h"
#include "src/core/lv_obj_pos.h"
#include "ui_screen_HomeNormal.h"
#include "ui_screen_Adjustment.h"
#include "ui_screen_FileManage.h"
#include <stdio.h>
#include "../custom/lvgl_cmd.h"
#include "ui_custom_messagebox.h"
#include "ui_custom_reminderbox.h"
#include "ui_Screen_Settings.h"
#include "ui_custom_print_opt_screen.h"
#include "mult_language.h"
#include "lvgl/src/misc/lv_timer.h"
#include "ui.h"

/********HomePrinting Page***********/
static lv_obj_t * ui_ScreenHomePagePrinting;
/***********home printing page left panel************************/
static lv_obj_t * ui_PanelPage;
static lv_obj_t * ui_ImageHomePage;
static lv_obj_t * ui_ButtonHomePage;
static lv_obj_t * ui_ButtonAxisMove;
static lv_obj_t * ui_ButtonFIleManage;
static lv_obj_t * ui_ButtonSettings;
static lv_obj_t * ui_ButtonReserve;

/***********home printing page right panel************************/
static lv_obj_t * ui_PanelPrinting;
static lv_obj_t * ui_PanelTitleAndStatusPrinting;
static lv_obj_t * ui_LabelFileName;
static lv_obj_t * ui_PrintingDeviceIconPanel;


static lv_obj_t * ui_PanelPrintInfo;

/***********home printing page right panel print info ************************/
static lv_obj_t * ui_ImageWifiLarge;
static lv_obj_t * ui_ImageCamerastate;
static lv_obj_t * ui_ImageLaserPrinting;
static lv_obj_t * ui_PanelModelChart;
static lv_obj_t * ui_ImageGridBackground;
static lv_obj_t * ui_ImageModelChart;
static lv_obj_t * ui_ImageChartMask;
static lv_obj_t * ui_LabelPrepareTips;
static lv_obj_t * ui_ImageUsedTimes;
static lv_obj_t * ui_LabelUsedTimes;
static lv_obj_t * ui_ImageRemainderTimes;
static lv_obj_t * ui_LabelRemainingTimes;
static lv_obj_t * ui_LabelProcess;
static lv_obj_t * ui_LabelPercentSign;
static lv_obj_t * ui_BarPrintProccess;


/***********home printing page right panel temper info ************************/
static lv_obj_t * ui_PanelTemperInfo;
static lv_obj_t * ui_ImageCompany;

static lv_obj_t * ui_PanelHotendTemp;
static lv_obj_t * ui_ImageHotend;
static lv_obj_t * ui_LabelHotendTemper;
static lv_obj_t * ui_LabelHotendTemperCelsius;

static lv_obj_t * ui_PanelBedTemp;
static lv_obj_t * ui_ImageBed;
static lv_obj_t * ui_LabelBedTemper;
static lv_obj_t * ui_LabelBedTemperCelsius;

/************喷头、热床的重叠部分**************/
static lv_obj_t * ui_PanelHotendHeating;
static lv_obj_t * ui_ImageHotendHeating;
static lv_obj_t * ui_LabelHotendzCurTemper;
static lv_obj_t * ui_LabelHotendLeftSlash;   // '/'
static lv_obj_t * ui_LabelHotendHeatingTemperCelsius;
static lv_obj_t * ui_LabelHotendTargetTemper;
static lv_obj_t * ui_LabelHotendSettingTemper;
static lv_obj_t * ui_ImageHotendHeatingTo;
static lv_obj_t * ui_PanelBedHeating;
static lv_obj_t * ui_ImageBedHeating;
static lv_obj_t * ui_LabelBedCurTemper;
static lv_obj_t * ui_LabelBedLeftSlash;   // '/'
static lv_obj_t * ui_ImageBedHeatingTo;
static lv_obj_t * ui_LabelBedTargetTemper;
static lv_obj_t * ui_LabelBedSettingTemper;
static lv_obj_t * ui_LabelBedHeatingTemperCelsius;


static lv_obj_t * ui_PanelLine;
static lv_obj_t * ui_PanelStatus;
static lv_obj_t * ui_Panel_Lightes;
static lv_obj_t * ui_ImageLight;
static lv_obj_t * ui_PanelStatusLine;
static lv_obj_t * ui_Panel_Fans;
static lv_obj_t * ui_ImageFan;
static lv_obj_t * ui_GifFan;

/***********home printing page right panel print control ************************/
static lv_obj_t * ui_PanelPrintOpt;
static lv_obj_t * ui_ButtonPrintOpt;





/***********************custom variable********************************/
static int16_t  bed_temper_printing = -15;
static int16_t  bed_target_temper_printing = 0;
static int16_t  hotend_temper_printing = -15;
static int16_t  hotend_target_temper_printing = 0;
static bool     light_opened_printing = true;
static bool     fan_opened_printing = false;
static int wifi_Intensity_printing = 0;
static int32_t  used_time_printing = 90;
static int32_t  remained_time_printing = 100;
static int8_t   proccess_printing = 50;
static char     file_name_printing[256] = "";//"hello world";
static char     filling_chart_name[256] = {0};
static int8_t   print_status = 1;
static bool     printing_filament_runout = false;
static uint32_t gcode_layer_count = 1;
static bool     poweloss_flag = false;
static bool     printcomplete_flag = false;

static DialogMsgbox_t FilamentRunoutMessage;  //断料检测消息弹框

//typedef void (*lv_event_cb_t)(lv_event_t * e);
typedef struct{
    lv_obj_t *ui_Button;
    lv_obj_t *ui_Label;
    char **ButtonContent; //eg. Content = Pause;
    lv_event_cb_t ButtonEventCb;
}ButtonUnit_t;

typedef struct{
    lv_obj_t *ui_PanelTopLevelDialog;
    lv_obj_t *ui_LabelTitle;
    char **TitleContent; //eg. Content = Pause;
    lv_obj_t *ui_LabelMessage;
    char **MessageContent; //eg. Content = Pause;
    uint8_t ButtonNum;
    int16_t ButtonWidth;
    int16_t ButtonHight;
    ButtonUnit_t *ui_ButtonArray;  //
}TopLevelDialog_t;

typedef void (*HomePrintingAdd3rdLevelObjsCb_f)(void);  //添加三级导航对象回调函数
static HomePrintingAdd3rdLevelObjsCb_f HomePrintingAdd3rdLevelObjsCb = NULL; 

static ButtonUnit_t BtnArrayA[3] = {0};
static ButtonUnit_t BtnArrayB[3] = {0};
static TopLevelDialog_t DialogA;
static TopLevelDialog_t DialogB;

//打印控制对话框对象
static lv_obj_t *ui_PanelPrintCtrlDialog = NULL;
static lv_obj_t *ui_LabelDialogTitle = NULL;
static ButtonUnit_t BtnArray[3] = {0};

//打印结果对话框
lv_obj_t * ui_PanelPrintResultMsgboxBg = NULL;
static lv_obj_t * ui_PrintResulMsgbox = NULL;
static lv_obj_t * ui_ImagePrintResult = NULL;
static lv_obj_t * ui_LablePrintResult = NULL;
static lv_obj_t * ui_PanelPrintTime = NULL;
static lv_obj_t * ui_ImagePrintTime = NULL;
static lv_obj_t * ui_LablePrintTime = NULL;
static lv_obj_t * ui_ButtonMsgbox = NULL;
static lv_obj_t * ui_LableBtnMsgbox = NULL;

static bool CtrlDiagFlag;

extern char preview_filling_chart_name[256];
static bool StopAndResumeFlag = false;



///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

#define SLICE_SOFTNAME "Creality"

EventGrop_Data HomePageManage;

static void HomePageNormalGroupObjsAddLevel0();
static void HomePageNormalGroupObjsAddLevel1(bool CurPageFlag, lv_obj_t *CurFocusObj);
static void PageMenuChange(bool CurPageFlag, uint8_t Curpage_level, lv_obj_t *CurFocusObj);


/***********home printing page event ************************/
static void ui_event_ButtonAxisMove(lv_event_t * e);
static void ui_event_ButtonFIleManage(lv_event_t * e);
static void ui_event_ButtonSettings(lv_event_t * e);
static void ui_event_ButtonReserve(lv_event_t * e);
static void ui_event_PanelHotendTemp(lv_event_t * e);
static void ui_event_PanelBedTemp(lv_event_t * e);
static void ui_event_ImageLight(lv_event_t * e);
static void ui_event_ImageFan(lv_event_t * e);
static void ui_event_ButtonPrintOpt(lv_event_t * e);

static void ui_event_PanelHotendHeating(lv_event_t * e);
//static void ui_event_ImageHotendHeatingTo(lv_event_t * e);
static void ui_event_PanelBedHeating(lv_event_t * e);
//static void ui_event_ImageBedHeatingTo(lv_event_t * e);

/***********home printing page event call back ************************/
static void homePageAxisMoveBtnClicked(lv_event_t * e);
static void homePageFileManageBtnClicked(lv_event_t * e);
static void homePageSettingBtnClicked(lv_event_t * e);
static void HomePageHotendClicked(lv_event_t * e);
static void HomePageBedClicked(lv_event_t * e);
static void HomePageFanClicked(lv_event_t * e);
static void PrintOptClicked(lv_event_t * e);
static void HomePageHotendHeatingClicked(lv_event_t * e);
//void PrintPageSetHotendTargetEvent(lv_event_t * e);
static void HomePageBedHeatingClicked(lv_event_t * e);
//void PrintPageSetBedTargetEvent(lv_event_t * e);


/********************************************/
static void show_print_proccess(void);
static void show_print_used_time(void);
static void show_print_remained_time(void);
static void show_model_mask(int proccess_percent);
static void show_filling_chart(void);
static void show_printing_status(void);
static void show_printing_file_name(void);
static void printing_hotend_edit_target_temper_callback(void *param);
static void printing_bed_edit_target_temper_callback(void *param);
static void printing_pause_print_opt_callback(void);
static void printing_stop_print_opt_callback(void);
static void printing_resume_print_opt_callback(void);
static void printing_recovery_file_print_again_callback(void);
static void printing_recovery_file_stop_print_callback(void);
static void printing_replace_mater_callback();
static void printing_stop_replace_mater_callback(void);

static void stop_print_confirm_callback(struct _lv_timer_t *timer);

static void HomePrintingPageChangeObjs(uint8_t index);
static void ClosePrintCtrlDialog(void);
static void create_result_messagebox(bool PrintResult, char *PrintTimeStr);

static lv_timer_t * HomePrintingNavTimer;

/**
 * @description: 事件组冻结定时解冻
 * @return {*}
 * @param {lv_timer_t *} timer
 */
void HomePrintingNavFreezeTimerCb(lv_timer_t * timer)
{
    lv_group_focus_freeze(encoder_group, false);
    lv_timer_del(HomePrintingNavTimer);
}

void ui_event_ScreenHomePagePrinting(lv_event_t * e)
{
    bool IsEntered = false;
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_UNLOAD_START) {
        //关闭关闭未关闭的对话框
        if (ui_PanelPrintCtrlDialog && !lv_obj_has_flag(ui_PanelPrintCtrlDialog, LV_OBJ_FLAG_HIDDEN))
        {
            ClosePrintCtrlDialog();
        }  
    }
}

/********HomePrinting Page 函数实现***********/
void ui_event_ButtonHomePage(lv_event_t * e)
{
    bool IsEntered = false;
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        IsEntered = HomePageManage.stateValue;
        IsEntered = !IsEntered;
        LoadHomePrintingPageAndObjs(IsEntered);
    }
    // if(event_code == LV_EVENT_DEFOCUSED)
    // {
    //     if (HomePageManage.stateValue)
    //     {
    //         lv_obj_set_style_bg_img_src(ui_ButtonHomePage, &ui_img_pagehomeselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     }
    // }
    // if(event_code == LV_EVENT_FOCUSED)
    // {
    //     if (HomePageManage.stateValue)
    //     {
    //        // lv_obj_set_style_bg_img_src(ui_ButtonHomePage, &ui_img_pagehomefocus_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //         if (page_manager.objFreezzFlag == false)
    //         {
    //             page_manager.objFreezzFlag = true;
    //         }
    //         else if (page_manager.objFreezzFlag == true)
    //         {
    //             lv_group_focus_freeze(encoder_group, true);
    //             HomePrintingNavTimer = lv_timer_create(HomePrintingNavFreezeTimerCb, 300,  NULL);
    //         }
    //     }
    // }
}

void ui_event_ButtonAxisMove(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        LoadAxixMoveScreenAndObjs(true);
    }
    if(event_code == LV_EVENT_FOCUSED) {  
        LoadAxixMoveScreenAndObjs(false);
    }
}

void ui_event_ButtonFIleManage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    // if(event_code == LV_EVENT_SHORT_CLICKED) {
    //     homePageFileManageBtnClicked(e);
    // }
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        LoadFileManageScreenAndObjs(true);
    }
    if(event_code == LV_EVENT_FOCUSED) {  
        LoadFileManageScreenAndObjs(false);
    }
}

void ui_event_ButtonSettings(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    // if(event_code == LV_EVENT_SHORT_CLICKED) {
    //     homePageSettingBtnClicked(e);
    // }
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        // LoadSettingsScreenAndObjs(false, SCREEN_SETTINGS_BUTTON);
    }
    if(event_code == LV_EVENT_FOCUSED) {
        // LoadSettingsScreenAndObjs(false, SCREEN_SETTINGS_BUTTON);
    }
}

void ui_event_ButtonReserve(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    // if(event_code == LV_EVENT_SHORT_CLICKED) {
    //     homePageReserveBtnClicked(e);
    // }
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        LoadServiceScreenAndObjs(true);
    }
    if(event_code == LV_EVENT_FOCUSED) {   
        LoadServiceScreenAndObjs(false);
    }
}

void ui_event_PanelHotendTemp(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    uint8_t ret = 0;
    int16_t value = 0;
    char value_char[6] = {0};
    // if(event_code == LV_EVENT_LONG_PRESSED) {   //长按退出
    //     lv_obj_add_flag(ui_LabelHotendSettingTemper, LV_OBJ_FLAG_HIDDEN);
    //     lv_obj_clear_flag(ui_LabelHotendTargetTemper, LV_OBJ_FLAG_HIDDEN);
    //     PageMenuChange(MENU_RETURN, MENU_LEVEL_2, NULL);
    // }
    ret = EncoderModeChange(encoder_group, e);
    if(ret == 0)
    {//编辑模式
        if (lv_obj_has_flag(ui_ImageHotendHeatingTo,LV_OBJ_FLAG_HIDDEN)) //中间加热箭头是否隐藏
        {//非加热状态
            lv_obj_add_flag(ui_LabelHotendzCurTemper, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_LabelHotendSettingTemper, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {//加热状态
            lv_obj_add_flag(ui_LabelHotendTargetTemper, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_LabelHotendSettingTemper, LV_OBJ_FLAG_HIDDEN);
        }
        value = atoi(lv_label_get_text(ui_LabelHotendTargetTemper));
        sprintf(value_char, "%d", value);
        lv_label_set_text(ui_LabelHotendSettingTemper, value_char);        
    }
    else if(ret == 1)
    {//导航模式
        if (lv_obj_has_flag(ui_ImageHotendHeatingTo,LV_OBJ_FLAG_HIDDEN)) //中间加热箭头是否隐藏
        {//非加热状态
            lv_obj_clear_flag(ui_LabelHotendzCurTemper, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LabelHotendSettingTemper, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {//加热状态
            lv_obj_clear_flag(ui_LabelHotendTargetTemper, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LabelHotendSettingTemper, LV_OBJ_FLAG_HIDDEN);
        }
        //設置目標溫度
        value = atoi(lv_label_get_text(ui_LabelHotendSettingTemper));
        lv_label_set_text(ui_LabelHotendTargetTemper, lv_label_get_text(ui_LabelHotendSettingTemper));
        send_set_target_temper_cmd(value, true);
    }

    if(event_code == LV_EVENT_DEFOCUSED) {  //
        if (!lv_obj_has_flag(ui_LabelHotendSettingTemper, LV_OBJ_FLAG_HIDDEN))
        {
            if (lv_obj_has_flag(ui_ImageHotendHeatingTo,LV_OBJ_FLAG_HIDDEN)) //中间加热箭头是否隐藏
            {//非加热状态
                lv_obj_clear_flag(ui_LabelHotendzCurTemper, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_LabelHotendSettingTemper, LV_OBJ_FLAG_HIDDEN);
            }
            else
            {//加热状态
                lv_obj_clear_flag(ui_LabelHotendTargetTemper, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_LabelHotendSettingTemper, LV_OBJ_FLAG_HIDDEN);
            }
            //設置目標溫度
            value = atoi(lv_label_get_text(ui_LabelHotendSettingTemper));
            lv_label_set_text(ui_LabelHotendTargetTemper, lv_label_get_text(ui_LabelHotendSettingTemper));
        }
    }

    EncoderChangeLableValue(ui_LabelHotendSettingTemper, e, HOTEND_MIN_EDIT_TEMPER, HOTEND_MAX_EDIT_TEMPER);
}

void ui_event_PanelBedTemp(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    uint8_t ret = 0;
    int16_t value = 0;
    char value_char[6] = {0};
    // if(event_code == LV_EVENT_LONG_PRESSED) {   //长按退出
    //     lv_obj_add_flag(ui_LabelBedSettingTemper, LV_OBJ_FLAG_HIDDEN);
    //     lv_obj_clear_flag(ui_LabelBedTargetTemper, LV_OBJ_FLAG_HIDDEN);
    //     PageMenuChange(MENU_RETURN, MENU_LEVEL_2, NULL);
    // }
    ret = EncoderModeChange(encoder_group, e);
    if(ret == 0)
    {//编辑模式
        if (lv_obj_has_flag(ui_ImageBedHeatingTo,LV_OBJ_FLAG_HIDDEN)) //中间加热箭头是否隐藏
        {//非加热状态
            lv_obj_add_flag(ui_LabelBedCurTemper, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_LabelBedSettingTemper, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {//加热状态
            lv_obj_add_flag(ui_LabelBedTargetTemper, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_LabelBedSettingTemper, LV_OBJ_FLAG_HIDDEN);
        }
        value = atoi(lv_label_get_text(ui_LabelBedTargetTemper));
        sprintf(value_char, "%d", value);
        lv_label_set_text(ui_LabelBedSettingTemper, value_char);    
    }
    else if(ret == 1)
    {//导航模式
        if (lv_obj_has_flag(ui_ImageBedHeatingTo,LV_OBJ_FLAG_HIDDEN)) //中间加热箭头是否隐藏
        {//非加热状态
            lv_obj_clear_flag(ui_LabelBedCurTemper, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LabelBedSettingTemper, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {//加热状态
            lv_obj_clear_flag(ui_LabelBedTargetTemper, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LabelBedSettingTemper, LV_OBJ_FLAG_HIDDEN);
        }
        //設置目標溫度
        value = atoi(lv_label_get_text(ui_LabelBedSettingTemper));
        lv_label_set_text(ui_LabelBedTargetTemper, lv_label_get_text(ui_LabelBedSettingTemper));
        send_set_target_temper_cmd(value, false);
    }

    if(event_code == LV_EVENT_DEFOCUSED) {  //
        if (!lv_obj_has_flag(ui_LabelBedSettingTemper, LV_OBJ_FLAG_HIDDEN))
        {
            if (lv_obj_has_flag(ui_ImageBedHeatingTo,LV_OBJ_FLAG_HIDDEN)) //中间加热箭头是否隐藏
            {//非加热状态
                lv_obj_clear_flag(ui_LabelBedCurTemper, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_LabelBedSettingTemper, LV_OBJ_FLAG_HIDDEN);
            }
            else
            {//加热状态
                lv_obj_clear_flag(ui_LabelBedTargetTemper, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_LabelBedSettingTemper, LV_OBJ_FLAG_HIDDEN);
            }
            //設置目標溫度
            value = atoi(lv_label_get_text(ui_LabelBedSettingTemper));
            lv_label_set_text(ui_LabelBedTargetTemper, lv_label_get_text(ui_LabelBedSettingTemper));
        }
    }

    EncoderChangeLableValue(ui_LabelBedSettingTemper, e, BED_MIN_EDIT_TEMPER, BED_MAX_EDIT_TEMPER);
}

void ui_event_ImageLight(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HomePageLightClicked(e);
    }
}

void ui_event_ImageFan(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HomePageFanClicked(e);
    }
    if(event_code == LV_EVENT_LONG_PRESSED) {   //长按退出
        PageMenuChange(MENU_RETURN, MENU_LEVEL_2, NULL);
    }
}


void ui_event_ButtonPrintOpt(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        CtrlDiagFlag = true;
        PrintOptClicked(e);

        //测试
        // char buff[10] = {0};
        // sprintf(buff, "%dh%02dm", 31, 8); 
        // create_result_messagebox(true, buff);
    }
}

void ui_event_PanelHotendHeating(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HomePageHotendHeatingClicked(e);
    }
}
// void ui_event_ImageHotendHeatingTo(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         PrintPageSetHotendTargetEvent(e);
//     }
// }
void ui_event_PanelBedHeating(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        HomePageBedHeatingClicked(e);
    }
}
// void ui_event_ImageBedHeatingTo(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if(event_code == LV_EVENT_CLICKED) {
//         PrintPageSetBedTargetEvent(e);
//     }
// }


void ui_event_DialogStopAndResumeButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    //lv_obj_t * button = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        if (BtnArray[0].ButtonContent == Resume)
        {//继续
            CrLogI("ui_event_DialogResumeButton\n");
            ClosePrintCtrlDialog();
            //切换聚焦对象
            BackPrepage(false);
            if(material_seneor == '4')
            {
                set_filament_runout(true);
                return;
            }
            send_set_resume_print_cmd();
        }
        else
        {//暂停
            CrLogI("ui_event_DialogPauseButton\n");
            ClosePrintCtrlDialog();
            //切换聚焦对象
            BackPrepage(false);
            send_set_pause_print_cmd();
        }
        StopAndResumeFlag = true;
    }
}

//继续按钮的回调函数
void ui_event_DialogResumeButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        ClosePrintCtrlDialog();
        //切换聚焦对象
        BackPrepage(false);
        if(material_seneor == '4')
        {
            set_filament_runout(true);
            return;
        }
        send_set_resume_print_cmd();
    }
}

//停止按钮的回调函数
void ui_event_DialogStopButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        ClosePrintCtrlDialog();
        //切换聚焦对象
        CrLogI("ui_event_DialogStopButton BackPrepage(true)");
        BackPrepage(true);
        int height = (print_job.end_px - print_job.start_px) + (MAX_FILLINF_CHART_MASK_HEIGHT - print_job.end_px);
        lv_obj_set_height(ui_ImageChartMask, height);
        send_set_stop_print_cmd();
        //print_status = 1;
        //home_printing_set_printing_status(print_status);
    
        //LoadHomeNormalScreen();

        lv_timer_t *timer_offset = lv_timer_create(stop_print_confirm_callback, 2000, NULL);
        lv_timer_set_repeat_count(timer_offset, 1);
    }
}

//返回按钮的回调函数
void ui_event_DialogBackButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    //lv_obj_t *parents = lv_event_get_user_data(e);
    //TopLevelDialog_t *Dialog = (TopLevelDialog_t *)lv_event_get_user_data(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        //关闭对话框
        ClosePrintCtrlDialog();
        //切换聚焦对象
        BackPrepage(false);
    }
}

//暂停按钮的回调函数buff
void ui_event_DialogPauseButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        //homePageHomePageBtnClicked(e);
        ClosePrintCtrlDialog();
        //切换聚焦对象
        BackPrepage(false);
        send_set_pause_print_cmd();
    }
}

//增加进退料的导航对象
void FilamentRunoutPopoutNavObjs(void)
{
    for (size_t i = 0; i < FilamentRunoutMessage.btnNumber; i++)
    {
        lv_group_add_obj(encoder_group, FilamentRunoutMessage.btn[i].btn);
    }
}

static void FilamentRunoutPopoutBtnCb(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    int dat = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        switch(dat) //设置屏幕亮度
        {
            case 0: 
                //关闭对话框
                HiddenDialogMessagebox(&FilamentRunoutMessage);
                BackPrepage(false);
                break;
            case 1: 
                set_printer_data(0x06,2,"b5");
                break; 
            case 2: 
                set_printer_data(0x06,3,"b0");
                break;
            // case 3: set_printer_data(0x06,2,"b0");break;
            default:break;
        }
        
        // HiddenDialogMessagebox(&ScreenOffMessage);
        // Add3rLeveldObjsCb = NULL;
        // BackPrepage(false);
       // ChangeToSettingHomePageOjbs();
    }
}

static void FilamentRunoutPopoutBtnTextSetCb(lv_obj_t *label, uint8_t label_index, uint8_t language_index)
{
    switch (label_index) {
    case 0:
        lv_label_set_text(label, ForgetPasswordArray[language_index]);
        break;
    case 1:
        lv_label_set_text(label, ToChangeFilament[language_index]);
        break;
    default:break;
    }    
}

void FilamentRunoutPopoutStyleInit()
{
    static Msgboxbtn_t FilamentRunoutPopoutBtn[2]; 

    for (size_t i = 0; i < 2; i++)
    {
        FilamentRunoutPopoutBtn[i].btnsCallbackArray = FilamentRunoutPopoutBtnCb;
        FilamentRunoutPopoutBtn[i].SetLabelText = FilamentRunoutPopoutBtnTextSetCb;
    }
    
    FilamentRunoutMessage.hasSubPanel = true;
    FilamentRunoutMessage.title = &KindTips[get_cur_language_index()];
    FilamentRunoutMessage.btn = FilamentRunoutPopoutBtn;
    FilamentRunoutMessage.customStyle = &StyleDialogBtn;
    FilamentRunoutMessage.customFocusStyle = &StyleDialogFocusBtn;

    FilamentRunoutMessage.btnNumber = sizeof(FilamentRunoutPopoutBtn)/sizeof(Msgboxbtn_t);
    FilamentRunoutMessage.subPanelAttr.w = 371;
    FilamentRunoutMessage.subPanelAttr.h = 285;

       
    InitDialogMessagebox(&FilamentRunoutMessage);
    
    //lv_obj_add_style(FilamentRunoutMessage.btn[1].btn, dialog->customStyle, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(FilamentRunoutMessage.btn[1].btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(FilamentRunoutMessage.titleLabel, LV_ALIGN_TOP_MID, 0, 11);
    
    lv_label_set_text(FilamentRunoutMessage.contentLabel, FilamentRunOutMsg[get_cur_language_index()]);
    
    uint8_t btnBasePos_x = 26;
    for (size_t i = 0; i < FilamentRunoutMessage.btnNumber; i++)
    {
       // lv_obj_align(FilamentRunoutMessage.btn[i].label, LV_ALIGN_LEFT_MID, 0, 1);
        lv_obj_set_size(FilamentRunoutMessage.btn[i].btn, 140, 52);
        lv_obj_set_pos(FilamentRunoutMessage.btn[i].btn, btnBasePos_x, 221);
        
        btnBasePos_x += 174;
    }

}

void ui_ScreenHomePagePrinting_screen_init(void)
{
    ui_ScreenHomePagePrinting = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenHomePagePrinting, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenHomePagePrinting, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenHomePagePrinting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    HomePageManage.GropName = lv_group_create();
    HomePageManage.stateValue = false;
    init_pages(ui_ScreenHomePagePrinting, HomePrintingPageChangeObjs, LoadHomePrintingScreen);
#if 1
    //左边导航面板
    ui_PanelPage = lv_obj_create(ui_ScreenHomePagePrinting);
    lv_obj_set_size(ui_PanelPage, 68, 360);
    lv_obj_clear_flag(ui_PanelPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_PanelPage, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_pos(ui_PanelPage, 0, 60);

    //home按键
    //ui_ButtonHomePage = lv_btn_create(ui_PanelPage);
    ui_ButtonHomePage = lv_obj_create(ui_PanelPage);
    lv_obj_set_size(ui_ButtonHomePage, 68, 72);
    lv_obj_set_pos(ui_ButtonHomePage, -18, -18);
    lv_obj_add_flag(ui_ButtonHomePage, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonHomePage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    //默认样式
    lv_obj_set_style_bg_img_src(ui_ButtonHomePage, &ui_img_pagehomeselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_radius(ui_ButtonHomePageNormal, 10, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_color(ui_ButtonHomePage, lv_color_hex(0x1C1C1E),LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonHomePage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_radius(ui_ButtonHomePage, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_color(ui_ButtonHomePage, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonHomePage, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonHomePage, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonHomePage, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonHomePage, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
     lv_obj_set_style_border_width(ui_ButtonHomePage, 1, LV_PART_MAIN | LV_STATE_PRESSED);


    //准备按键
    ui_ButtonAxisMove = lv_btn_create(ui_PanelPage);
    lv_obj_set_size(ui_ButtonAxisMove, 68, 72);
    lv_obj_set_pos(ui_ButtonAxisMove, -18, 54);
    lv_obj_add_flag(ui_ButtonAxisMove, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonAxisMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonAxisMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonAxisMove, &ui_img_pagemove_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ButtonAxisMove, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_color(ui_ButtonAxisMove, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);                   
    lv_obj_set_style_border_opa(ui_ButtonAxisMove, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonAxisMove, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonAxisMove, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonAxisMove, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //文件按钮
    ui_ButtonFIleManage = lv_btn_create(ui_PanelPage);
    lv_obj_set_size(ui_ButtonFIleManage, 68, 72);
    lv_obj_set_pos(ui_ButtonFIleManage, -18, 126);
    lv_obj_add_flag(ui_ButtonFIleManage, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonFIleManage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonFIleManage, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonFIleManage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonFIleManage, &ui_img_pagefilemanage_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式  
    lv_obj_set_style_radius(ui_ButtonFIleManage, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_color(ui_ButtonFIleManage, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonFIleManage, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonFIleManage, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonFIleManage, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonFIleManage, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //设置按钮
    ui_ButtonSettings = lv_btn_create(ui_PanelPage);
    lv_obj_set_size(ui_ButtonSettings, 68, 72);
    lv_obj_set_pos(ui_ButtonSettings, -18, 198);
    lv_obj_add_flag(ui_ButtonSettings, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSettings, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonSettings, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonSettings, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonSettings, &ui_img_pagesetting_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式 
    lv_obj_set_style_radius(ui_ButtonSettings, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_color(ui_ButtonSettings, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonSettings, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonSettings, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonSettings, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonSettings, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //客服按钮
    ui_ButtonReserve = lv_btn_create(ui_PanelPage);
    lv_obj_set_size(ui_ButtonReserve, 68, 72);
    lv_obj_set_pos(ui_ButtonReserve, -18, 270);
    lv_obj_add_flag(ui_ButtonReserve, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonReserve, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonReserve, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonReserve, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonReserve, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式 
    lv_obj_set_style_radius(ui_ButtonReserve, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_color(ui_ButtonReserve, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonReserve, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonReserve, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonReserve, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonReserve, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

#endif
    //右边主面板
    ui_PanelPrinting = lv_obj_create(ui_ScreenHomePagePrinting);
    lv_obj_clear_flag(ui_PanelPrinting, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelPrinting, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelPrinting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_pos(ui_PanelPrinting, 68, 60); //页面导航栏宽度为68 
	lv_obj_set_size(ui_PanelPrinting, 572, 360);
   // lv_obj_set_align(ui_PanelPrinting, LV_ALIGN_TOP_LEFT);
    lv_obj_set_style_radius(ui_PanelPrinting, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPrinting, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelPrinting, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_PanelPrinting, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelPrinting, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //标题&状态栏面板
    ui_PanelTitleAndStatusPrinting = lv_obj_create(ui_PanelPrinting);
    lv_obj_set_pos(ui_PanelTitleAndStatusPrinting, 0, 0);
    lv_obj_set_size(ui_PanelTitleAndStatusPrinting, 572, 46);
    lv_obj_clear_flag(ui_PanelTitleAndStatusPrinting, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelTitleAndStatusPrinting, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelTitleAndStatusPrinting, lv_color_hex(0x101011), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelTitleAndStatusPrinting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelTitleAndStatusPrinting, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelTitleAndStatusPrinting, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelTitleAndStatusPrinting, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelTitleAndStatusPrinting, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelTitleAndStatusPrinting, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    //文件名
    ui_LabelFileName = lv_label_create(ui_PanelTitleAndStatusPrinting);
    lv_obj_set_size(ui_LabelFileName, 410, 30);
    //lv_obj_set_pos(ui_LabelFileName, 0, 0);   
    lv_label_set_text(ui_LabelFileName, "");
    lv_obj_clear_flag(ui_LabelFileName, LV_OBJ_FLAG_PRESS_LOCK);      /// Flags
    lv_obj_set_align(ui_LabelFileName, LV_ALIGN_LEFT_MID);
    lv_obj_set_style_text_color(ui_LabelFileName, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFileName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelFileName, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LabelFileName, LV_LABEL_LONG_DOT);
    lv_obj_set_style_text_font(ui_LabelFileName, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PrintingDeviceIconPanel = lv_obj_create(ui_PanelTitleAndStatusPrinting);
    lv_obj_set_size(ui_PrintingDeviceIconPanel, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_clear_flag(ui_PrintingDeviceIconPanel, LV_OBJ_FLAG_SCROLLABLE);  
    lv_obj_align(ui_PrintingDeviceIconPanel, LV_ALIGN_RIGHT_MID, 0, 0);
    lv_obj_set_style_radius(ui_PrintingDeviceIconPanel, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PrintingDeviceIconPanel, lv_color_hex(0x101011), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PrintingDeviceIconPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PrintingDeviceIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PrintingDeviceIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_PrintingDeviceIconPanel, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_pad_column(ui_PrintingDeviceIconPanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_align(ui_PrintingDeviceIconPanel, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    
    //激光雷达
    ui_ImageLaserPrinting = lv_img_create(ui_PrintingDeviceIconPanel);
    lv_obj_set_size(ui_ImageLaserPrinting, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_img_set_src(ui_ImageLaserPrinting, &ui_img_laser_png);
    lv_obj_add_flag(ui_ImageLaserPrinting, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageLaserPrinting, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_ImageLaserPrinting, LV_OBJ_FLAG_HIDDEN); 

    //摄像头
    ui_ImageCamerastate = lv_img_create(ui_PrintingDeviceIconPanel);
    lv_obj_set_size(ui_ImageCamerastate, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_img_set_src(ui_ImageCamerastate, &ui_img_camera_png);
    lv_obj_add_flag(ui_ImageCamerastate, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageCamerastate, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_ImageCamerastate, LV_OBJ_FLAG_HIDDEN); 

    //wifi图标
    ui_ImageWifiLarge = lv_img_create(ui_PrintingDeviceIconPanel);
    home_printing_set_wifi_status(wifi_Intensity_printing);
    lv_obj_set_size(ui_ImageWifiLarge, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_add_flag(ui_ImageWifiLarge, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageWifiLarge, LV_OBJ_FLAG_SCROLLABLE);      /// Flags



    /*******************************中间打印信息***********************************/
    //中间打印信息面板
    ui_PanelPrintInfo = lv_obj_create(ui_PanelPrinting);
    lv_obj_set_size(ui_PanelPrintInfo, 348, 296);
    lv_obj_set_pos(ui_PanelPrintInfo, 7, 54);
    lv_obj_clear_flag(ui_PanelPrintInfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_all(ui_PanelPrintInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_PanelPrintInfo, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelPrintInfo, lv_color_hex(0x0C0C0E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelPrintInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPrintInfo, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    //模型图面板,增加次面板主要是为了模型原图和掩图重合且在合适位置
    ui_PanelModelChart = lv_obj_create(ui_PanelPrintInfo);
    lv_obj_set_size(ui_PanelModelChart, 348, 248);
    //lv_obj_set_pos(ui_PanelModelChart, 20, 0);
    lv_obj_align(ui_PanelModelChart, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_clear_flag(ui_PanelModelChart, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_all(ui_PanelModelChart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelModelChart, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelModelChart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelModelChart, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    //网格背景图
    ui_ImageGridBackground = lv_img_create(ui_PanelModelChart);
    lv_img_set_src(ui_ImageGridBackground, &ui_img_GridBg_png);
    lv_obj_set_size(ui_ImageGridBackground, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_set_pos(ui_ImageGridBackground, 0, 0);
    lv_obj_align(ui_ImageGridBackground, LV_ALIGN_BOTTOM_MID, 0, -28);
    lv_obj_add_flag(ui_ImageGridBackground, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageGridBackground, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_ImageGridBackground, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ImageGridBackground, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //模型图
    ui_ImageModelChart = lv_img_create(ui_PanelModelChart);
    lv_img_set_src(ui_ImageModelChart, &ui_img_crealitylogo_png);
    lv_obj_set_size(ui_ImageModelChart, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_img_set_zoom(ui_ImageModelChart, 200);
    // lv_img_set_size_mode(ui_ImageModelChart, LV_IMG_SIZE_MODE_REAL);
    //lv_obj_set_pos(ui_ImageModelChart, 0, 0);
    lv_obj_align(ui_ImageModelChart, LV_ALIGN_TOP_MID, 0, -40);
    lv_obj_add_flag(ui_ImageModelChart, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageModelChart, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_ImageModelChart, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ImageModelChart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //模型图掩图，用来做注水效果
    ui_ImageChartMask = lv_img_create(ui_PanelModelChart);
    lv_obj_set_size(ui_ImageChartMask, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_img_set_zoom(ui_ImageChartMask, 200);
    // lv_img_set_size_mode(ui_ImageChartMask, LV_IMG_SIZE_MODE_REAL);
    //lv_obj_set_pos(ui_ImageChartMask, 0, 0);
    //lv_obj_align(ui_ImageChartMask, LV_ALIGN_CENTER, 0, -16);  //和ui_ImageModelChart的y坐标相差16，不知道为什么
    lv_obj_align(ui_ImageChartMask, LV_ALIGN_TOP_MID, 0, -40);
    lv_obj_add_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageChartMask, LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_all(ui_ImageChartMask, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //使用时间
    ui_LabelUsedTimes = lv_label_create(ui_PanelPrintInfo);
    lv_obj_set_size(ui_LabelUsedTimes, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_LabelUsedTimes, LV_ALIGN_BOTTOM_LEFT, 24, 0);
    lv_label_set_text(ui_LabelUsedTimes, "");
    lv_obj_set_style_text_color(ui_LabelUsedTimes, lv_color_hex(0x50535B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelUsedTimes, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelUsedTimes, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelUsedTimes, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //剩余时间
    ui_LabelRemainingTimes = lv_label_create(ui_PanelPrintInfo);
    lv_obj_set_size(ui_LabelRemainingTimes, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_LabelRemainingTimes, LV_ALIGN_BOTTOM_RIGHT, -24, 0);
    lv_label_set_text(ui_LabelRemainingTimes, "");
    lv_label_set_recolor(ui_LabelRemainingTimes, "true");
    lv_obj_set_style_text_color(ui_LabelRemainingTimes, lv_color_hex(0x50535B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelRemainingTimes, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelRemainingTimes, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelRemainingTimes, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //进度百分比数值
    ui_LabelProcess = lv_label_create(ui_PanelPrintInfo);
    lv_obj_set_size(ui_LabelProcess, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_LabelProcess, LV_ALIGN_BOTTOM_MID, 0, -2);
    lv_label_set_text(ui_LabelProcess, "");
    lv_obj_add_flag(ui_LabelProcess, LV_OBJ_FLAG_FLOATING);     /// Flags
    lv_obj_clear_flag(ui_LabelProcess, LV_OBJ_FLAG_CLICK_FOCUSABLE);      /// Flags
    lv_obj_set_style_text_color(ui_LabelProcess, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelProcess, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelProcess, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelProcess, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // //百分比符合
    // ui_LabelPercentSign = lv_label_create(ui_PanelPrintInfo);
    // lv_obj_set_size(ui_LabelPercentSign, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    // lv_obj_align_to(ui_LabelPercentSign, ui_LabelProcess, LV_ALIGN_OUT_RIGHT_MID, 9, -5);
    // lv_label_set_text(ui_LabelPercentSign, "%");
    // lv_obj_add_flag(ui_LabelPercentSign, LV_OBJ_FLAG_FLOATING);     /// Flags
    // lv_obj_set_style_text_color(ui_LabelPercentSign, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_LabelPercentSign, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_LabelPercentSign, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_LabelPercentSign, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //打印前进度提示
    ui_LabelPrepareTips = lv_label_create(ui_PanelPrintInfo);
    lv_obj_set_width(ui_LabelPrepareTips, 395);
    lv_obj_set_height(ui_LabelPrepareTips, 28);
   // lv_obj_set_pos(ui_LabelPrepareTips, 0, 0);
    lv_obj_align_to(ui_LabelPrepareTips, ui_LabelProcess, LV_ALIGN_OUT_TOP_MID, 0, -2);
    lv_label_set_text(ui_LabelPrepareTips, "");
    lv_obj_set_style_text_color(ui_LabelPrepareTips, lv_color_hex(0x50535B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelPrepareTips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelPrepareTips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelPrepareTips, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //进度条
    ui_BarPrintProccess = lv_bar_create(ui_PanelPrintInfo);
    lv_obj_set_size(ui_BarPrintProccess, 324, 16);
    lv_obj_align(ui_BarPrintProccess, LV_ALIGN_TOP_MID, 0, 246);
    lv_obj_set_style_bg_color(ui_BarPrintProccess, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BarPrintProccess, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BarPrintProccess, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BarPrintProccess, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_BarPrintProccess, &ui_img_proccess_png, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_tiled(ui_BarPrintProccess, true, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_BarPrintProccess, 16, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_bar_set_mode(ui_BarPrintProccess, LV_BAR_MODE_RANGE);
    lv_bar_set_start_value(ui_BarPrintProccess, 0, LV_ANIM_OFF);

    /*******************************右上角信息***********************************/
    // 温度信息面板，注意风扇也加到这个面板上
    ui_PanelTemperInfo = lv_obj_create(ui_PanelPrinting);
    lv_obj_set_size(ui_PanelTemperInfo, 199, 209);
    lv_obj_set_pos(ui_PanelTemperInfo, 363, 54);
    lv_obj_clear_flag(ui_PanelTemperInfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelTemperInfo, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelTemperInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelTemperInfo, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelTemperInfo, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelTemperInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //公司LOGO
    // ui_ImageCompany = lv_img_create(ui_PanelTemperInfo);
    // lv_img_set_src(ui_ImageCompany, &ui_img_company_png);
    // lv_obj_set_size(ui_ImageCompany, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    // lv_obj_align(ui_ImageCompany, LV_ALIGN_TOP_MID, 0, 17);
    // lv_obj_add_flag(ui_ImageCompany, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_ImageCompany, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ImageCompany, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ImageCompany, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //喷嘴温度面板
    ui_PanelHotendTemp = lv_obj_create(ui_PanelTemperInfo);
    lv_obj_set_size(ui_PanelHotendTemp, 188, 60);
    lv_obj_align(ui_PanelHotendTemp, LV_ALIGN_TOP_MID, 0, 2);
    lv_obj_clear_flag(ui_PanelHotendTemp, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    //lv_obj_set_style_radius(ui_PanelHotendTemp, 35, LV_PART_MAIN | LV_STATE_DEFAULT);
    //默认样式
    lv_obj_set_style_bg_color(ui_PanelHotendTemp, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHotendTemp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelHotendTemp, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelHotendTemp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelHotendTemp, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_PanelHotendTemp, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_PanelHotendTemp, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_PanelHotendTemp, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_PanelHotendTemp, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);    

    //喷嘴正常状态下的图片
    ui_ImageHotend = lv_img_create(ui_PanelHotendTemp);
    lv_img_set_src(ui_ImageHotend, &ui_img_hotend_png);
    lv_obj_set_size(ui_ImageHotend, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    // lv_obj_set_pos(ui_ImageHotend, 13, 10);
    lv_obj_align(ui_ImageHotend, LV_ALIGN_LEFT_MID, 18, 0);
    lv_obj_add_flag(ui_ImageHotend, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHotend, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    //当前温度标签
    ui_LabelHotendzCurTemper = lv_label_create(ui_PanelHotendTemp);
    lv_obj_set_size(ui_LabelHotendzCurTemper, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //默认非加热状态下，居中显示
    lv_obj_align(ui_LabelHotendzCurTemper, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(ui_LabelHotendzCurTemper, "0");
    lv_obj_set_style_text_color(ui_LabelHotendzCurTemper, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendzCurTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHotendzCurTemper, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendzCurTemper, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //喷嘴的目标设置温度标签
    ui_LabelHotendSettingTemper = lv_label_create(ui_PanelHotendTemp);
    lv_obj_set_size(ui_LabelHotendSettingTemper, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //默认非加热状态下，点击后出现，居中显示
    lv_obj_align(ui_LabelHotendSettingTemper, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(ui_LabelHotendSettingTemper, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_label_set_text(ui_LabelHotendSettingTemper, "0");
    lv_obj_set_style_bg_color(ui_LabelHotendSettingTemper, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LabelHotendSettingTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_LabelHotendSettingTemper, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LabelHotendSettingTemper, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendSettingTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHotendSettingTemper, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendSettingTemper, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //温度加热箭头
    ui_ImageHotendHeatingTo = lv_img_create(ui_PanelHotendTemp);
    lv_img_set_src(ui_ImageHotendHeatingTo, &ui_img_totarget2_png);
    lv_obj_set_size(ui_ImageHotendHeatingTo, 16, 15);
    //默认非加热状态，不设位置，并且隐藏
    lv_obj_align(ui_ImageHotendHeatingTo, LV_ALIGN_CENTER, 4, 0);
    lv_obj_add_flag(ui_ImageHotendHeatingTo, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_ImageHotendHeatingTo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
 
    // 目标温度
    ui_LabelHotendTargetTemper = lv_label_create(ui_PanelHotendTemp);
    lv_obj_set_size(ui_LabelHotendTargetTemper, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_add_flag(ui_LabelHotendTargetTemper, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_HIDDEN);
    lv_label_set_text(ui_LabelHotendTargetTemper, "0");
    lv_obj_set_style_radius(ui_LabelHotendTargetTemper, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LabelHotendTargetTemper, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendTargetTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHotendTargetTemper, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendTargetTemper, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //喷嘴温度单位
    ui_LabelHotendTemperCelsius = lv_label_create(ui_PanelHotendTemp);
    lv_obj_set_size(ui_LabelHotendTemperCelsius, 25, 30);
    //lv_obj_set_pos(ui_LabelHotendTemperCelsius, 125, 15);
    lv_obj_align(ui_LabelHotendTemperCelsius, LV_ALIGN_RIGHT_MID, -25, 3);
    lv_label_set_text(ui_LabelHotendTemperCelsius, "°C");
    lv_obj_set_style_text_color(ui_LabelHotendTemperCelsius, lv_color_hex(0x515459), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHotendTemperCelsius, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelHotendTemperCelsius, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHotendTemperCelsius, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //分割线
    ui_PanelLine = lv_obj_create(ui_PanelTemperInfo);
    lv_obj_set_size(ui_PanelLine, 195, 1);
    lv_obj_align(ui_PanelLine, LV_ALIGN_TOP_MID, 0, 64);
    lv_obj_clear_flag(ui_PanelLine, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_PanelLine, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelLine, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //热床温度控制面板
    ui_PanelBedTemp = lv_obj_create(ui_PanelTemperInfo);
    lv_obj_set_size(ui_PanelBedTemp, 188, 60);
    lv_obj_align_to(ui_PanelBedTemp, ui_PanelLine, LV_ALIGN_OUT_BOTTOM_MID, 0, 2);
    lv_obj_clear_flag(ui_PanelBedTemp, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelBedTemp, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    //默认样式
    lv_obj_set_style_bg_color(ui_PanelBedTemp, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelBedTemp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelBedTemp, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelBedTemp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_PanelBedTemp, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_PanelBedTemp, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_PanelBedTemp, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_PanelBedTemp, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //正常热床图片
    ui_ImageBed = lv_img_create(ui_PanelBedTemp);
    lv_img_set_src(ui_ImageBed, &ui_img_bed_png);
    lv_obj_set_size(ui_ImageBed, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    // lv_obj_set_pos(ui_ImageBed, 13, 15);
    lv_obj_align(ui_ImageBed, LV_ALIGN_LEFT_MID, 18, 0);
    lv_obj_add_flag(ui_ImageBed, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags

    //热床当前温度
    ui_LabelBedCurTemper = lv_label_create(ui_PanelBedTemp);
    lv_obj_set_size(ui_LabelBedCurTemper, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_align_to(ui_LabelBedCurTemper, ui_LabelBedLeftSlashNormal, LV_ALIGN_OUT_LEFT_MID, 0, -5);
    lv_obj_align(ui_LabelBedCurTemper, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(ui_LabelBedCurTemper, "0");
    lv_obj_set_style_text_color(ui_LabelBedCurTemper, lv_color_hex(0x0BD25B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedCurTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedCurTemper, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedCurTemper, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //热床设置温度标签
    ui_LabelBedSettingTemper = lv_label_create(ui_PanelBedTemp);
    lv_obj_set_size(ui_LabelBedSettingTemper, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_LabelBedSettingTemper, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(ui_LabelBedSettingTemper, "0");
    lv_obj_set_style_bg_color(ui_LabelBedSettingTemper, lv_color_hex(0x0BD25B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LabelBedSettingTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_LabelBedSettingTemper, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LabelBedSettingTemper, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedSettingTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedSettingTemper, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedSettingTemper, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_LabelBedSettingTemper, LV_OBJ_FLAG_HIDDEN);

    //热床加热箭头
    ui_ImageBedHeatingTo = lv_img_create(ui_PanelBedTemp);
    lv_img_set_src(ui_ImageBedHeatingTo, &ui_img_totarget_png);
    lv_obj_set_size(ui_ImageBedHeatingTo, 16, 15);
    //默认非加热状态，不设位置，并且隐藏
    lv_obj_align(ui_ImageBedHeatingTo, LV_ALIGN_CENTER, 4, 0);
    lv_obj_add_flag(ui_ImageBedHeatingTo, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_clear_flag(ui_ImageBedHeatingTo, LV_OBJ_FLAG_SCROLLABLE); 

    //热床目标温度标签
    ui_LabelBedTargetTemper = lv_label_create(ui_PanelBedTemp);
    lv_obj_set_size(ui_LabelBedTargetTemper, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_add_flag(ui_LabelBedTargetTemper, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_HIDDEN);
    lv_label_set_text(ui_LabelBedTargetTemper, "0");
    lv_obj_set_style_radius(ui_LabelBedTargetTemper, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LabelBedTargetTemper, lv_color_hex(0x3DE4AA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedTargetTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedTargetTemper, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedTargetTemper, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);


    //热床温度单位
    ui_LabelBedTemperCelsius = lv_label_create(ui_PanelBedTemp);
    lv_obj_set_size(ui_LabelBedTemperCelsius, 25, 30);
    // lv_obj_set_pos(ui_LabelBedTemperCelsius, 125, 15);
    lv_obj_align(ui_LabelBedTemperCelsius, LV_ALIGN_RIGHT_MID, -25, 0);
    lv_label_set_text(ui_LabelBedTemperCelsius, "°C");
    lv_obj_set_style_text_color(ui_LabelBedTemperCelsius, lv_color_hex(0x515459), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedTemperCelsius, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedTemperCelsius, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedTemperCelsius, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //分割线
    ui_PanelLine = lv_obj_create(ui_PanelTemperInfo);
    lv_obj_set_size(ui_PanelLine, 194, 1);
    lv_obj_align(ui_PanelLine, LV_ALIGN_TOP_MID, 0, 130);
    lv_obj_clear_flag(ui_PanelLine, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_PanelLine, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelLine, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //状态面板
    ui_PanelStatus = lv_obj_create(ui_PanelTemperInfo);
    lv_obj_set_size(ui_PanelStatus, 190, 66);
    lv_obj_align_to(ui_PanelStatus, ui_PanelLine, LV_ALIGN_OUT_BOTTOM_MID, 0, 4);
    lv_obj_clear_flag(ui_PanelStatus, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    //lv_obj_set_style_radius(ui_PanelStatus, 35, LV_PART_MAIN | LV_STATE_DEFAULT);
    //默认样式
    lv_obj_set_style_bg_color(ui_PanelStatus, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelStatus, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelStatus, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelStatus, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    // lv_obj_set_style_border_color(ui_PanelStatus, lv_color_hex(0xB0F1FF),
    //                               LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    // lv_obj_set_style_border_opa(ui_PanelStatus, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    // lv_obj_set_style_border_width(ui_PanelStatus, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    // lv_obj_set_style_border_side(ui_PanelStatus, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);

   //灯状态面板
    ui_Panel_Lightes = lv_obj_create(ui_PanelStatus);
    lv_obj_set_size(ui_Panel_Lightes, 84, 60);
    lv_obj_align(ui_Panel_Lightes, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_style_pad_all(ui_Panel_Lightes, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_Panel_Lightes, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    //默认样式
    lv_obj_set_style_bg_color(ui_Panel_Lightes, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel_Lightes, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel_Lightes, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Panel_Lightes, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_Panel_Lightes, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_Panel_Lightes, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_Panel_Lightes, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_Panel_Lightes, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //灯的图片
    ui_ImageLight = lv_img_create(ui_Panel_Lightes);
    lv_obj_set_size(ui_ImageLight, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_ImageLight, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ImageLight, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_src(ui_ImageLight, &ui_img_lightclosed_png);
    //home_normal_set_light_status(light_opened);

    //状态中间分割线
    ui_PanelStatusLine = lv_obj_create(ui_PanelStatus);
    lv_obj_set_size(ui_PanelStatusLine, 1, 66);
    lv_obj_align(ui_PanelStatusLine, LV_ALIGN_CENTER, 0, 0);
    lv_obj_clear_flag(ui_PanelStatusLine, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_PanelStatusLine, lv_color_hex(0x646464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelStatusLine, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //风扇状态面板
    ui_Panel_Fans = lv_obj_create(ui_PanelStatus);
    lv_obj_set_size(ui_Panel_Fans, 84, 60);
    lv_obj_align(ui_Panel_Fans, LV_ALIGN_RIGHT_MID, 0, 0);
    lv_obj_clear_flag(ui_Panel_Fans, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//    lv_obj_clear_flag(ui_Panel_Fans, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    //默认样式
    lv_obj_set_style_bg_color(ui_Panel_Fans, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel_Fans, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_Panel_Fans, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_Panel_Fans, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_Panel_Fans, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_Panel_Fans, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_Panel_Fans, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_Panel_Fans, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //关闭状态的风扇图片    
    ui_ImageFan = lv_img_create(ui_Panel_Fans);
    lv_obj_set_size(ui_ImageFan, 66, 66);
    lv_obj_set_align(ui_ImageFan, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ImageFan, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_src(ui_ImageFan, &ui_img_stop_fan_png);

    //打开状态的风扇图片
    ui_GifFan = lv_gif_create(ui_Panel_Fans);
    lv_obj_set_size(ui_GifFan, 66, 66);
    lv_obj_set_align(ui_GifFan, LV_ALIGN_CENTER);
    lv_gif_set_src(ui_GifFan, &ui_img_HomeFan);
    lv_obj_add_flag(ui_GifFan, LV_OBJ_FLAG_HIDDEN);

    ui_ButtonPrintOpt = lv_btn_create(ui_ScreenHomePagePrinting);
    lv_obj_set_size(ui_ButtonPrintOpt, 205, 80);
    lv_obj_set_pos(ui_ButtonPrintOpt, 431, 336);
    lv_obj_add_flag(ui_ButtonPrintOpt, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonPrintOpt, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    //默认模式
    lv_obj_set_style_bg_color(ui_ButtonPrintOpt, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPrintOpt, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_img_src(ui_ButtonPrintOpt, &ui_img_start_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ButtonPrintOpt, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ButtonPrintOpt, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonPrintOpt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonPrintOpt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦模式
    lv_obj_set_style_border_color(ui_ButtonPrintOpt, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonPrintOpt, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonPrintOpt, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_side(ui_ButtonPrintOpt, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);  
    lv_obj_set_style_outline_pad(ui_ButtonPrintOpt, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_outline_width(ui_ButtonPrintOpt, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //创建顶层对话框
    lv_obj_add_event_cb(ui_ScreenHomePagePrinting, ui_event_ScreenHomePagePrinting, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonHomePage, ui_event_ButtonHomePage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonAxisMove, ui_event_ButtonAxisMove, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonFIleManage, ui_event_ButtonFIleManage, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSettings, ui_event_ButtonSettings, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonReserve, ui_event_ButtonReserve, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelHotendTemp, ui_event_PanelHotendTemp, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelBedTemp, ui_event_PanelBedTemp, LV_EVENT_ALL, NULL);
    //lv_obj_add_event_cb(ui_Panel_Lightes, ui_event_ImageLight, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Panel_Fans, ui_event_ImageFan, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonPrintOpt, ui_event_ButtonPrintOpt, LV_EVENT_ALL, NULL);
    

    //FilamentRunoutPopoutStyleInit();
    
    /***********重叠部分*******************/
    //lv_obj_add_event_cb(ui_ImageHotendHeatingTo, ui_event_ImageHotendHeatingTo, LV_EVENT_ALL, NULL);
    //lv_obj_add_event_cb(ui_PanelHotendHeating, ui_event_PanelHotendHeating, LV_EVENT_ALL, NULL);
    //lv_obj_add_event_cb(ui_ImageBedHeatingTo, ui_event_ImageBedHeatingTo, LV_EVENT_ALL, NULL);
    //lv_obj_add_event_cb(ui_PanelBedHeating, ui_event_PanelBedHeating, LV_EVENT_ALL, NULL);

    /**********************add******************/
}

static int IsEntered = 1;
void LoadHomePrintingScreen(void)
{
    CrLogI("load the printing page");
    lv_disp_load_scr(ui_ScreenHomePagePrinting);
    send_get_cur_print_gcode_info_cmd();
    // RefreshModelFanFlag = true;
    send_get_fans_status_cmd();
    send_get_light_status_cmd();
    send_get_wifi_status_cmd();
    send_get_print_proccess();
    get_printer_data(CONTROL_MACHINE_STATE, 2, "5"); //获取摄像头状态
    show_printing_status();
    home_printing_set_hotend_temper(hotend_temper_printing, hotend_target_temper_printing);
    home_printing_set_bed_temper(bed_temper_printing, bed_target_temper_printing);
    show_filling_chart();
    show_model_mask(proccess_printing);
    show_printing_file_name();
    //PageMenuChange(MENU_ENTER, MENU_LEVEL_1, ui_ButtonHomePage);
}

void homePageHomePageBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadHomePrintingScreen();
}

void homePageAxisMoveBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadAxisMoveScreen();
}

void homePageFileManageBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadFileManageScreen();
}

void homePageSettingBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadSettingsScreen();
}

void homePageReserveBtnClicked(lv_event_t * e)
{
	// Your code here
}


void HomePageHotendClicked(lv_event_t * e)
{
	// Your code here
    char buff[300] = {0};
    sprintf(buff, "%s #42BDD8 %d-%d#", HotendInputRangle[get_cur_language_index()],HOTEND_MIN_EDIT_TEMPER, HOTEND_MAX_EDIT_TEMPER);
    numberskeyboardinput(buff, HOTEND_MAX_EDIT_TEMPER, HOTEND_MIN_EDIT_TEMPER,
                    printing_hotend_edit_target_temper_callback, key_reminder_callback, 92, 0);
}

void HomePageBedClicked(lv_event_t * e)
{
	// Your code here
    char buff[300] = {0};
    if(UIType == CR_K1_Max)
    {
        sprintf(buff, "%s #42BDD8 %d-%d#", BedInputRangle[get_cur_language_index()], BED_MIN_EDIT_TEMPER, K1_MAX_BED_MAX_EDIT_TEMPER);
        numberskeyboardinput(buff, K1_MAX_BED_MAX_EDIT_TEMPER, BED_MIN_EDIT_TEMPER,
                printing_bed_edit_target_temper_callback, key_reminder_callback, 92, 0);
    }
    else
    {
        sprintf(buff, "%s #42BDD8 %d-%d#", BedInputRangle[get_cur_language_index()], BED_MIN_EDIT_TEMPER, BED_MAX_EDIT_TEMPER);
        numberskeyboardinput(buff, BED_MAX_EDIT_TEMPER, BED_MIN_EDIT_TEMPER,
                    printing_bed_edit_target_temper_callback, key_reminder_callback, 92, 0);        
    }

}

void HomePageLightClicked(lv_event_t * e)
{
	// Your code here
    send_set_light_opt_cmd(!light_opened_printing);
}

void HomePageFanClicked(lv_event_t * e)
{
	// Your code here
    // uint8_t percent = 100;
    // if ( fan_opened_printing )
    // {
    //     percent = 0;
    //     home_printing_set_fan_status(false);
    // }
    // else
    // {
    //     home_printing_set_fan_status(true);
    // }
        
    // send_set_model_fan_opt_cmd(percent);

    ShowCoolSubPage(ui_ScreenHomePagePrinting);
    HomePrintingAdd3rdLevelObjsCb = AddFanCtrlNavObjs;
    LoadPage(ui_ScreenHomePagePrinting, 3);

    // send_set_model_fan_opt_cmd(percent);
    //不再发送命令改为跳转页面
    //LoadCoolScreen();
}

//传入title对象，按键对象数组（包括按键，label，回调函数），按键个数，按键大小
// void CreateTopLevelDialog(lv_group_t * group, TopLevelDialog_t * TopLevelDialog)
// {
//     int i = 0;
//     lv_obj_t *ui_PanelTopLevelDialog = NULL;
//     lv_obj_t *ui_LabelTitle = NULL;
//     lv_obj_t *ui_LabelMessage = NULL;
//     uint8_t ButtonNum = TopLevelDialog->ButtonNum;
//     int16_t ButtonWidth = TopLevelDialog->ButtonWidth;
//     int16_t ButtonHight = TopLevelDialog->ButtonHight;
//     lv_obj_t *ui_Button = NULL;
//     lv_obj_t *ui_Label = NULL;    
//     lv_obj_t *PreObj = NULL;
//     // ButtonUnit_t *ui_ButtonArray = TopLevelDialog->ui_ButtonArray;
//     ButtonUnit_t *ui_ButtonUnit = NULL;
    
//     if(TopLevelDialog->ui_PanelTopLevelDialog == NULL)
//     {
//         //顶层对话框父对象
//         TopLevelDialog->ui_PanelTopLevelDialog = lv_obj_create(lv_layer_top());
//         ui_PanelTopLevelDialog = TopLevelDialog->ui_PanelTopLevelDialog;
//         lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
//         lv_obj_set_width(ui_PanelTopLevelDialog, 640);
//         lv_obj_set_height(ui_PanelTopLevelDialog, 480);
//         lv_obj_set_align(ui_PanelTopLevelDialog, LV_ALIGN_CENTER);
//         lv_obj_clear_flag(ui_PanelTopLevelDialog, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//         lv_obj_set_style_radius(ui_PanelTopLevelDialog, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
//         lv_obj_set_style_bg_color(ui_PanelTopLevelDialog, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//         lv_obj_set_style_bg_opa(ui_PanelTopLevelDialog, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
//         lv_obj_set_style_border_side(ui_PanelTopLevelDialog, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
//         //create_custom_print_opt_screen
        
//         //Flex布局
//         lv_obj_t * cont_col = lv_obj_create(ui_PanelTopLevelDialog);
//         lv_obj_set_size(cont_col, 640, 360);
//         lv_obj_set_align(cont_col, LV_ALIGN_CENTER);
//         lv_obj_set_flex_flow(cont_col, LV_FLEX_FLOW_COLUMN);
//         lv_obj_set_flex_align(cont_col, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
//         lv_obj_set_style_bg_opa(cont_col, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//         lv_obj_set_style_border_side(cont_col, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        
//         //对话框标题
//         TopLevelDialog->ui_LabelTitle = lv_label_create(cont_col);
//         ui_LabelTitle = TopLevelDialog->ui_LabelTitle;
//         //lv_obj_set_width(ui_LabelTitle, 200);
//         //lv_obj_set_height(ui_LabelTitle, LV_SIZE_CONTENT);
//         //lv_obj_set_align(ui_LabelTitle, LV_ALIGN_TOP_MID);
//         lv_obj_set_size(ui_LabelTitle, LV_PCT(60), LV_SIZE_CONTENT);
        
//         lv_obj_set_style_text_color(ui_LabelTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//         lv_obj_set_style_text_opa(ui_LabelTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//         lv_obj_set_style_text_align(ui_LabelTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//         lv_obj_set_style_text_font(ui_LabelTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
//         lv_label_set_long_mode(ui_LabelTitle, LV_LABEL_LONG_SCROLL_CIRCULAR);

//         // ui_LabelMessage = lv_label_create(ui_PanelMessageBox);
//         // messagebox_text = ui_LabelMessage;
//         // lv_obj_set_width(ui_LabelMessage, MSG_BOX_WIDTH - 20);
//         // lv_obj_set_height(ui_LabelMessage, 90);
//         // lv_obj_set_x(ui_LabelMessage, -12);
//         // lv_obj_set_y(ui_LabelMessage, 48);
//         // lv_obj_set_style_text_color(ui_LabelMessage, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//         // lv_obj_set_style_text_opa(ui_LabelMessage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//         // lv_obj_set_style_text_align(ui_LabelMessage, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
//         // lv_obj_set_style_text_font(ui_LabelMessage, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
//         PreObj = ui_LabelTitle;  //用于对位
//         for(i = 0; i < ButtonNum; i++)
//         {
//             // 按键
//             ui_ButtonUnit = TopLevelDialog->ui_ButtonArray + i;
//             ui_ButtonUnit->ui_Button = lv_btn_create(cont_col);
//             ui_Button = ui_ButtonUnit->ui_Button;
//             lv_obj_set_size(ui_Button, LV_PCT(20), LV_SIZE_CONTENT);
//             lv_obj_add_flag(ui_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
//             lv_obj_clear_flag(ui_Button, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//             lv_obj_set_style_radius(ui_Button, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
//             lv_obj_set_style_bg_color(ui_Button, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
//             lv_obj_set_style_bg_opa(ui_Button, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//             lv_obj_set_style_shadow_width(ui_Button, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//             lv_obj_set_style_shadow_spread(ui_Button, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//             lv_obj_set_style_border_side(ui_Button, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
//             lv_obj_set_style_border_color(ui_Button, lv_color_hex(0x42BDD8),
//                                         LV_PART_MAIN | LV_STATE_PRESSED);
//             lv_obj_set_style_border_opa(ui_Button, 255, LV_PART_MAIN | LV_STATE_PRESSED);
//             lv_obj_set_style_border_width(ui_Button, 2, LV_PART_MAIN | LV_STATE_PRESSED);

//             // label
//             ui_ButtonUnit->ui_Label = lv_label_create(ui_Button);
//             ui_Label = ui_ButtonUnit->ui_Label;
//             lv_obj_set_width(ui_Label, LV_SIZE_CONTENT);
//             lv_obj_set_height(ui_Label, LV_SIZE_CONTENT);
//             lv_obj_set_align(ui_Label, LV_ALIGN_CENTER);
//             lv_label_set_long_mode(ui_Label, LV_LABEL_LONG_SCROLL_CIRCULAR);
//             lv_obj_set_style_text_font(ui_Label, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
//             lv_label_set_long_mode(ui_Label, LV_LABEL_LONG_SCROLL_CIRCULAR);
//             lv_obj_set_style_text_align(ui_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

//             lv_obj_add_event_cb(ui_Button, ui_ButtonUnit->ButtonEventCb, LV_EVENT_ALL, (void *)TopLevelDialog);
//             PreObj = ui_Button;
//         }
//     }
//     else
//     {
//         //ui_PanelTopLevelDialog = TopLevelDialog->ui_PanelTopLevelDialog;
//         //ui_LabelTitle = TopLevelDialog->ui_LabelTitle;
//         lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
//         lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
//         lv_obj_clear_flag(TopLevelDialog->ui_PanelTopLevelDialog, LV_OBJ_FLAG_HIDDEN);     /// Flags
//     }

//     //加载语言
//     uint8_t language_index = get_cur_language_index();

//     lv_label_set_text(TopLevelDialog->ui_LabelTitle, TopLevelDialog->TitleContent[language_index]);

//     lv_group_remove_all_objs(group);
//     lv_indev_set_group(enc_indev, NULL); 
//     lv_indev_set_group(enc_indev, group); //关联组

//     for(i = 0; i < ButtonNum; i++)
//     {
//         ui_ButtonUnit = TopLevelDialog->ui_ButtonArray + i;
//         lv_group_add_obj(group, ui_ButtonUnit->ui_Button);
//         lv_label_set_text(ui_ButtonUnit->ui_Label, ui_ButtonUnit->ButtonContent[language_index]);
//     }

//     lv_obj_set_style_bg_color(lv_layer_top(), lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(lv_layer_top(), 204, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(TopLevelDialog->ui_PanelTopLevelDialog, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(TopLevelDialog->ui_PanelTopLevelDialog, 0, LV_PART_MAIN | LV_STATE_DEFAULT);  
//     lv_obj_clear_flag(TopLevelDialog->ui_PanelTopLevelDialog, LV_OBJ_FLAG_HIDDEN);
// }



void AddPrintCtrlDialogNavObjs(void)
{
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        lv_group_add_obj(encoder_group, BtnArray[i].ui_Button);
    } 
}

void ClosePrintCtrlDialog(void)
{
    lv_obj_add_flag(ui_PanelPrintCtrlDialog, LV_OBJ_FLAG_HIDDEN);
    // lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
    // lv_obj_set_style_bg_opa(lv_layer_top(), 0, LV_PART_MAIN | LV_STATE_DEFAULT);
}

//传入title对象，按键对象数组（包括按键，label，回调函数），按键个数，按键大小
void CreatePrintCtrlDialog(bool DialogType)
{
    int i = 0;   
    lv_obj_t *ui_LabelMessage = NULL;
    lv_obj_t *ui_Button = NULL;
    lv_obj_t *ui_Label = NULL;    
    lv_obj_t *PreObj = NULL;
    
    if (DialogType) //继续
    {//设置按钮的lable和回调函数
        BtnArray[0].ButtonContent = Pause;
        BtnArray[0].ButtonEventCb = ui_event_DialogStopAndResumeButton;
        //printf("BtnArray[0].ButtonEventCb = ui_event_DialogPauseButton\n");
        BtnArray[1].ButtonContent = Stop;
        BtnArray[1].ButtonEventCb = ui_event_DialogStopButton;
        BtnArray[2].ButtonContent = Back;
        BtnArray[2].ButtonEventCb = ui_event_DialogBackButton;
    }
    else   //暂停
    {
        BtnArray[0].ButtonContent = Resume;
        BtnArray[0].ButtonEventCb = ui_event_DialogStopAndResumeButton;
        //printf("BtnArray[0].ButtonEventCb = ui_event_DialogResumeButton\n");
        BtnArray[1].ButtonContent = Stop;
        BtnArray[1].ButtonEventCb = ui_event_DialogStopButton;
        BtnArray[2].ButtonContent = Back;
        BtnArray[2].ButtonEventCb = ui_event_DialogBackButton;
    }
    
    if(ui_PanelPrintCtrlDialog == NULL)
    {
        //顶层对话框父对象
        //ui_PanelPrintCtrlDialog = lv_obj_create(lv_layer_top());
        ui_PanelPrintCtrlDialog = lv_obj_create(ui_ScreenHomePagePrinting);
        //lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_width(ui_PanelPrintCtrlDialog, 640);
        lv_obj_set_height(ui_PanelPrintCtrlDialog, 480);
        lv_obj_set_align(ui_PanelPrintCtrlDialog, LV_ALIGN_CENTER);
        lv_obj_clear_flag(ui_PanelPrintCtrlDialog, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_PanelPrintCtrlDialog, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_PanelPrintCtrlDialog, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_PanelPrintCtrlDialog, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_side(ui_PanelPrintCtrlDialog, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        //create_custom_print_opt_screen
        
        //Flex布局
        lv_obj_t * cont_col = lv_obj_create(ui_PanelPrintCtrlDialog);
        lv_obj_set_size(cont_col, 640, 360);
        lv_obj_set_align(cont_col, LV_ALIGN_CENTER);
        lv_obj_set_flex_flow(cont_col, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_flex_align(cont_col, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_style_bg_opa(cont_col, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_side(cont_col, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        
        //对话框标题
        ui_LabelDialogTitle = lv_label_create(cont_col);
        //lv_obj_set_width(ui_LabelTitle, 200);
        //lv_obj_set_height(ui_LabelTitle, LV_SIZE_CONTENT);
        //lv_obj_set_align(ui_LabelTitle, LV_ALIGN_TOP_MID);
        lv_obj_set_size(ui_LabelDialogTitle, LV_PCT(60), LV_SIZE_CONTENT);
        lv_obj_set_style_text_color(ui_LabelDialogTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_LabelDialogTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_LabelDialogTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_LabelDialogTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_long_mode(ui_LabelDialogTitle, LV_LABEL_LONG_SCROLL_CIRCULAR);

        for(i = 0; i < 3; i++)
        {
            // 按键
            BtnArray[i].ui_Button = lv_btn_create(cont_col);
            ui_Button = BtnArray[i].ui_Button;
            lv_obj_set_size(ui_Button, LV_PCT(22), LV_SIZE_CONTENT);
            lv_obj_add_flag(ui_Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
            lv_obj_clear_flag(ui_Button, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
            lv_obj_set_style_radius(ui_Button, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_Button, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(ui_Button, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(ui_Button, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(ui_Button, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            //聚焦样式
            lv_obj_set_style_border_color(ui_Button, lv_color_hex(0xFFFFFF),
                                        LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_border_opa(ui_Button, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_border_width(ui_Button, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_pad(ui_Button, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_outline_color(ui_Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            // label
            BtnArray[i].ui_Label = lv_label_create(ui_Button);
            ui_Label = BtnArray[i].ui_Label;
            lv_obj_set_width(ui_Label, LV_SIZE_CONTENT);
            lv_obj_set_height(ui_Label, LV_SIZE_CONTENT);
            lv_obj_set_align(ui_Label, LV_ALIGN_CENTER);
            lv_label_set_long_mode(ui_Label, LV_LABEL_LONG_SCROLL_CIRCULAR);
            lv_obj_set_style_text_font(ui_Label, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_long_mode(ui_Label, LV_LABEL_LONG_SCROLL_CIRCULAR);
            lv_obj_set_style_text_align(ui_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

            lv_obj_add_event_cb(ui_Button, BtnArray[i].ButtonEventCb, LV_EVENT_ALL, ui_Button);
        }
    }

    // lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_PanelPrintCtrlDialog, LV_OBJ_FLAG_CLICKABLE);
    //lv_obj_clear_flag(ui_PanelPrintCtrlDialog, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_PanelPrintCtrlDialog, LV_OBJ_FLAG_HIDDEN);     /// Flags


    //加载语言
    uint8_t language_index = get_cur_language_index();

    lv_label_set_text(ui_LabelDialogTitle, PrintActionTipTitle[language_index]);

    for(i = 0; i < 3; i++)
    {
        lv_label_set_text(BtnArray[i].ui_Label, BtnArray[i].ButtonContent[language_index]);
        //lv_obj_add_event_cb(ui_Button, BtnArray[i].ButtonEventCb, LV_EVENT_ALL, NULL);
    }

    // lv_obj_set_style_bg_color(lv_layer_top(), lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(lv_layer_top(), 204, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelPrintCtrlDialog, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelPrintCtrlDialog, 204, LV_PART_MAIN | LV_STATE_DEFAULT);  
    lv_obj_clear_flag(ui_PanelPrintCtrlDialog, LV_OBJ_FLAG_HIDDEN);

    HomePrintingAdd3rdLevelObjsCb = AddPrintCtrlDialogNavObjs;
}


void PrintOptClicked(lv_event_t * e)
{
	// Your code here
    if(system_state.PreStartprint_state)    //当前处于打印前准备
    {
        create_msgbox(PrintingTips[get_cur_language_index()], NULL, 2000, lv_scr_act());
        return;
    }
    if ( print_status == 3)  // 1 is printing
    {
        // char *btns[3] = {"暂停", "停止", "返回"};
        // void (*btns_callback[3])(void) = {&printing_pause_print_opt_callback, &printing_stop_print_opt_callback, NULL};
        // create_custom_messagebox("请选择你需要进行的操作!", NULL, btns, btns_callback, 3, false, false);
        // set_custom_messagebox_btn_bg_color(2, lv_color_hex(0x42BDD8));
        // create_custom_print_opt_screen(true, &printing_pause_print_opt_callback, &printing_stop_print_opt_callback);
        CreatePrintCtrlDialog(true);
        LoadPage(ui_ScreenHomePagePrinting, 3);
        
    }
    else
    {
        // char *btns[3] = {"继续", "停止", "返回"};
        // void (*btns_callback[3])(void) = {&printing_resume_print_opt_callback, &printing_stop_print_opt_callback, NULL};
        // create_custom_messagebox("请选择你需要进行的操作!", NULL, btns, btns_callback, 3, false, false);
        // set_custom_messagebox_btn_bg_color(2, lv_color_hex(0x42BDD8));
        // create_custom_print_opt_screen(false, &printing_resume_print_opt_callback, &printing_stop_print_opt_callback);
        CreatePrintCtrlDialog(false);        
        LoadPage(ui_ScreenHomePagePrinting, 3);
    }
    //clear_custom_messagebox_bg_color();

    //home_printing_set_printing_status(print_status);
}


void printing_hotend_edit_target_temper_callback(void *param)
{
    char *number_buff = (char*)param;
    if ( number_buff )
    {
        char *ch = strchr(number_buff, '.');
        if ( ch )
            *ch = '\0';
            
        send_set_target_temper_cmd(atoi(number_buff), true);
    }
}


void printing_bed_edit_target_temper_callback(void *param)
{
    char *number_buff = (char*)param;
    if ( number_buff )
    {
        char *ch = strchr(number_buff, '.');
        if ( ch )
            *ch = '\0';
            
        send_set_target_temper_cmd(atoi(number_buff), false);
    }
}

void HomePageHotendHeatingClicked(lv_event_t * e)
{
	// Your code here
    char buff[300] = {0};
    sprintf(buff, "%s #42BDD8 %d-%d#", HotendInputRangle[get_cur_language_index()], HOTEND_MIN_EDIT_TEMPER, HOTEND_MAX_EDIT_TEMPER);
    numberskeyboardinput(buff, HOTEND_MAX_EDIT_TEMPER, HOTEND_MIN_EDIT_TEMPER,
                    printing_hotend_edit_target_temper_callback, key_reminder_callback, 92, 0);
}

// void PrintPageSetHotendTargetEvent(lv_event_t * e)
// {
// 	// Your code here
// }

void HomePageBedHeatingClicked(lv_event_t * e)
{
	// Your code here
    char buff[300] = {0};
    if(UIType == CR_K1_Max)
    {
        sprintf(buff, "%s #42BDD8 %d-%d#", BedInputRangle[get_cur_language_index()], BED_MIN_EDIT_TEMPER, K1_MAX_BED_MAX_EDIT_TEMPER);
        numberskeyboardinput(buff, K1_MAX_BED_MAX_EDIT_TEMPER, BED_MIN_EDIT_TEMPER,
                printing_bed_edit_target_temper_callback, key_reminder_callback, 92, 0);        
    }
    else
    {
        sprintf(buff, "%s #42BDD8 %d-%d#", BedInputRangle[get_cur_language_index()], BED_MIN_EDIT_TEMPER, BED_MAX_EDIT_TEMPER);
        numberskeyboardinput(buff, BED_MAX_EDIT_TEMPER, BED_MIN_EDIT_TEMPER,
                printing_bed_edit_target_temper_callback, key_reminder_callback, 92, 0);        
    }

}

// void PrintPageSetBedTargetEvent(lv_event_t * e)
// {
// 	// Your code here
// }


void show_hotend_heating_status(bool show)
{
    if ( show )
    {//加热状态
        //改变喷嘴转态：改变图片，改变位置        
        lv_img_set_src(ui_ImageHotend, &ui_img_hotendheating_png);
        // lv_obj_set_pos(ui_ImageHotend, 0, 10);
        lv_obj_align(ui_ImageHotend, LV_ALIGN_LEFT_MID, 5, 0);

        //改变字体颜色
        lv_obj_set_style_text_color(ui_LabelHotendzCurTemper, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_LabelHotendTargetTemper, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

        //改变当前温度：改变位置
        lv_obj_align_to(ui_LabelHotendzCurTemper, ui_ImageHotendHeatingTo, LV_ALIGN_OUT_LEFT_MID, -3, 0);

        //改变箭头：改变隐藏
        lv_obj_clear_flag(ui_ImageHotendHeatingTo, LV_OBJ_FLAG_HIDDEN);

        //改变目标温度：改变隐藏
        if(lv_obj_has_flag(ui_LabelHotendSettingTemper, LV_OBJ_FLAG_HIDDEN))
        {
            lv_obj_clear_flag(ui_LabelHotendTargetTemper, LV_OBJ_FLAG_HIDDEN);
            lv_obj_align_to(ui_LabelHotendTargetTemper, ui_ImageHotendHeatingTo, LV_ALIGN_OUT_RIGHT_MID, 2, 0);
        }

        //改变℃：改变位置
        // lv_obj_set_pos(ui_LabelHotendTemperCelsius, 145, 15);
        lv_obj_align(ui_LabelHotendTemperCelsius, LV_ALIGN_RIGHT_MID, -5, 3);

        //改变编辑温度：改变位置
        lv_obj_align_to(ui_LabelHotendSettingTemper, ui_ImageHotendHeatingTo, LV_ALIGN_OUT_RIGHT_MID, 0, 0);
    }
    else
    {//非加热状态
        //改变喷嘴转态：改变图片，改变位置        
        lv_img_set_src(ui_ImageHotend, &ui_img_hotend_png);
        //lv_obj_set_pos(ui_ImageHotend, 18, 5);
        lv_obj_align(ui_ImageHotend, LV_ALIGN_LEFT_MID, 18, 0);

        //改变字体颜色
        lv_obj_set_style_text_color(ui_LabelHotendzCurTemper, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_LabelHotendTargetTemper, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);

        //改变当前温度：改变位置
        lv_obj_align(ui_LabelHotendzCurTemper, LV_ALIGN_CENTER, 0, 0);

        //改变箭头：改变隐藏
        lv_obj_add_flag(ui_ImageHotendHeatingTo, LV_OBJ_FLAG_HIDDEN);

        //改变目标温度：改变隐藏
        lv_obj_add_flag(ui_LabelHotendTargetTemper, LV_OBJ_FLAG_HIDDEN);

        //改变℃：改变位置
        // lv_obj_set_pos(ui_LabelHotendTemperCelsius, 125, 15);
        lv_obj_align(ui_LabelHotendTemperCelsius, LV_ALIGN_RIGHT_MID, -25, 3);

        //改变编辑温度：改变位置
        lv_obj_align(ui_LabelHotendSettingTemper, LV_ALIGN_CENTER, 0, 0);
    }
}

void show_bed_heating_status(bool show)
{
    if ( show )
    { //加热状态
        //改变喷嘴转态：改变图片，改变位置        
        lv_img_set_src(ui_ImageBed, &ui_img_bedheating_png);
        // lv_obj_set_pos(ui_ImageBed, 0, 15);
        lv_obj_align(ui_ImageBed, LV_ALIGN_LEFT_MID, 5, 0);

        //改变字体颜色
        lv_obj_set_style_text_color(ui_LabelBedCurTemper, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_LabelBedTargetTemper, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

        //改变当前温度：改变位置
        lv_obj_align_to(ui_LabelBedCurTemper, ui_ImageBedHeatingTo, LV_ALIGN_OUT_LEFT_MID, -3, 0);

        //改变箭头：改变隐藏
        lv_obj_clear_flag(ui_ImageBedHeatingTo, LV_OBJ_FLAG_HIDDEN);

        //改变目标温度：改变隐藏
        if(lv_obj_has_flag(ui_LabelBedSettingTemper, LV_OBJ_FLAG_HIDDEN))
        {
            lv_obj_clear_flag(ui_LabelBedTargetTemper, LV_OBJ_FLAG_HIDDEN);
            lv_obj_align_to(ui_LabelBedTargetTemper, ui_ImageBedHeatingTo, LV_ALIGN_OUT_RIGHT_MID, 2, 0);
        }

        //改变℃：改变位置
        // lv_obj_set_pos(ui_LabelBedTemperCelsius, 145, 15);
        lv_obj_align(ui_LabelBedTemperCelsius, LV_ALIGN_RIGHT_MID, -5, 0);

        //改变编辑温度：改变位置
        lv_obj_align_to(ui_LabelBedSettingTemper, ui_ImageBedHeatingTo, LV_ALIGN_OUT_RIGHT_MID, 0, 0);
    }
    else
    {//非加热状态
        //改变喷嘴转态：改变图片，改变位置        
        lv_img_set_src(ui_ImageBed, &ui_img_bed_png);
        // lv_obj_set_pos(ui_ImageBed, 13, 15);
        lv_obj_align(ui_ImageBed, LV_ALIGN_LEFT_MID, 18, 0);

        //改变字体颜色
        lv_obj_set_style_text_color(ui_LabelBedCurTemper, lv_color_hex(0x42D87E), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_LabelBedTargetTemper, lv_color_hex(0x42D87E), LV_PART_MAIN | LV_STATE_DEFAULT);

        //改变当前温度：改变位置
        lv_obj_align(ui_LabelBedCurTemper, LV_ALIGN_CENTER, 0, 0);

        //改变箭头：改变隐藏
        lv_obj_add_flag(ui_ImageBedHeatingTo, LV_OBJ_FLAG_HIDDEN);

        //改变目标温度：改变隐藏
        lv_obj_add_flag(ui_LabelBedTargetTemper, LV_OBJ_FLAG_HIDDEN);

        //改变℃：改变位置
        // lv_obj_set_pos(ui_LabelBedTemperCelsius, 125, 15);
        lv_obj_align(ui_LabelBedTemperCelsius, LV_ALIGN_RIGHT_MID, -25, 0);

        //改变编辑温度：改变位置
        lv_obj_align(ui_LabelBedSettingTemper, LV_ALIGN_CENTER, 0, 0);
    }
}

void home_printing_set_hotend_temper(int16_t curTemper, int16_t targetTemper)
{
    char buff[10] = {0};
    sprintf(buff, "%d", curTemper);
    lv_label_set_text(ui_LabelHotendzCurTemper, buff);
    //lv_label_set_text(ui_LabelHotendTemper, buff);
    hotend_temper_printing = curTemper;

    sprintf(buff, "%d", targetTemper);
    lv_label_set_text(ui_LabelHotendTargetTemper, buff);
    hotend_target_temper_printing = targetTemper;

    // bool show_heating = false;
    // if ( targetTemper > 0 )
    //     show_heating = true;
    
    // show_hotend_heating_status(show_heating);

    static int NozzleHeatingcount = 0;
    if(targetTemper == 0)
    {
        show_hotend_heating_status(false);
        return;
    }
    if(abs(curTemper - targetTemper) <= 2)
    {
        NozzleHeatingcount++;
        if(NozzleHeatingcount >= 20)
        {
            NozzleHeatingcount = 0;
            show_hotend_heating_status(false);
        }
        else
        {
            if (!lv_obj_has_flag(ui_ImageHotendHeatingTo, LV_OBJ_FLAG_HIDDEN))
            {
                lv_obj_align_to(ui_LabelHotendzCurTemper, ui_ImageHotendHeatingTo, LV_ALIGN_OUT_LEFT_MID, -3, 0);
            }
        }
    }
    else
    {
        NozzleHeatingcount = 0;
        show_hotend_heating_status(true);
    }
}

void home_printing_set_bed_temper(int16_t curTemper, int16_t targetTemper)
{
    char buff[10] = {0};
    sprintf(buff, "%d", curTemper);
    lv_label_set_text(ui_LabelBedCurTemper, buff);
    //lv_label_set_text(ui_LabelBedTemper, buff);
    bed_temper_printing = curTemper;

    sprintf(buff, "%d", targetTemper);
    lv_label_set_text(ui_LabelBedTargetTemper, buff);
    bed_target_temper_printing = targetTemper;

    // bool show_heating = false;
    // if ( targetTemper > 0 )
    //     show_heating = true;
    
    // show_bed_heating_status(show_heating);

    static int BedHeatingcount = 0;
    if(targetTemper == 0)
    {
        show_bed_heating_status(false);
        return;
    }
    if(abs(curTemper - targetTemper) <= 2)
    {
        BedHeatingcount++;
        if(BedHeatingcount >= 20)
        {
            BedHeatingcount = 0;
            show_bed_heating_status(false);
        }
        else
        {
            if (!lv_obj_has_flag(ui_ImageBedHeatingTo, LV_OBJ_FLAG_HIDDEN))
            {
                lv_obj_align_to(ui_LabelBedCurTemper, ui_ImageBedHeatingTo, LV_ALIGN_OUT_LEFT_MID, -3, 0);
            }
        }
    }
    else
    {
        BedHeatingcount = 0;
        show_bed_heating_status(true);
    }
}

void home_printing_set_fan_status(bool open)
{
    fan_opened_printing = open;
    if ( ui_ImageFan )
    {
        fan_opened_printing ? lv_obj_add_flag(ui_ImageFan, LV_OBJ_FLAG_HIDDEN) :
                              lv_obj_clear_flag(ui_ImageFan, LV_OBJ_FLAG_HIDDEN);
    }

    if ( ui_GifFan )
        fan_opened_printing ? lv_obj_clear_flag(ui_GifFan, LV_OBJ_FLAG_HIDDEN) :
                              lv_obj_add_flag(ui_GifFan, LV_OBJ_FLAG_HIDDEN);

}

void home_printing_set_light_status(bool open)
{
    // light_opened_printing = open;
    // if ( light_opened_printing )
    //     lv_img_set_src(ui_ImageLight, &ui_img_lightopened_png);
    // else
    //     lv_img_set_src(ui_ImageLight, &ui_img_lightclosed_png);
}

void print_page_refresh_camerastate(int camera_state)
{
    if(camera_state)
        lv_obj_clear_flag(ui_ImageCamerastate, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageCamerastate, LV_OBJ_FLAG_HIDDEN);
}

void print_page_refresh_laserstate(int laser_state)
{
    if(laser_state)
        lv_obj_clear_flag(ui_ImageLaserPrinting, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageLaserPrinting, LV_OBJ_FLAG_HIDDEN);
}

void home_printing_set_wifi_status(int intensity)
{
    int level = 0;
    if (intensity <= MIN_RSSI)
    {
        level = 0;
    } 
    else if (intensity >= MAX_RSSI)
    {
        level = RSSI_LEVELS - 1;
    }
    else
    {
        float inputRange = (MAX_RSSI - MIN_RSSI);
        float outputRange = (RSSI_LEVELS - 1);
        level = (int)((float)(intensity - MIN_RSSI) * outputRange / inputRange);
    }

    switch (level)
    {
        case 0:lv_img_set_src(ui_ImageWifiLarge, &ui_img_wifinosignel_png);break;
        case 1:lv_img_set_src(ui_ImageWifiLarge, &ui_img_wifismall_png);break;
        case 2:lv_img_set_src(ui_ImageWifiLarge, &ui_img_wifimid_png);break;
        case 3:lv_img_set_src(ui_ImageWifiLarge, &ui_img_wififull_png);break;
        default:lv_img_set_src(ui_ImageWifiLarge, &ui_img_wififull_png);break;
    }

    wifi_Intensity_printing = intensity;
}

void home_printing_set_chamber_temper(int16_t curTemper)
{
    CrLogI("set the chamber temperature in printing page");
    //TODO:腔体温度设置，后期拓展使用
    //char tempbuff[100] = {0};
    //sprintf(tempbuff, "%d", curTemper);
    // lv_label_set_text(ui_LabelChamberCurTemper, tempbuff);
}

void show_print_proccess(void)
{
    char buff[5] = {0};
    sprintf(buff, "%d%%", proccess_printing);
    lv_label_set_text(ui_LabelProcess, buff);
    lv_bar_set_value(ui_BarPrintProccess, proccess_printing, LV_ANIM_OFF);
}

void show_print_used_time(void)
{
    char buff[10] = {0};
    int32_t used_time_m = used_time_printing / 60; //trans to minters
    sprintf(buff, "%dh%02dm", used_time_m / 60, used_time_m % 60);
    lv_label_set_text(ui_LabelUsedTimes, buff);
}

void show_print_remained_time(void)
{
    char buff[10] = {0};
    int32_t temainder_time_m = remained_time_printing / 60; //trans to minters
    sprintf(buff, "%dh%02dm", temainder_time_m / 60, (temainder_time_m % 60) + 1);
    lv_label_set_text(ui_LabelRemainingTimes, buff);
}

void show_model_mask(int proccess_percent)
{
    if(strcmp(print_job.gcode_type, SLICE_SOFTNAME) == 0)
    {
        lv_obj_clear_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN);
    }
    if ( proccess_percent > 100 )
        proccess_percent = 100;
    if ( proccess_percent < 0 )
        proccess_percent = 0;

    // if ( ui_ImageChartMask && (gcode_layer_count <= 0) )
    // {
    //     // int height = ((100 - proccess_percent) * MAX_FILLINF_CHART_MASK_HEIGHT) / 100;
    //     int height = ((100 - proccess_percent) * (model_end_pix - model_start_pix)) / 100 + (MAX_FILLINF_CHART_MASK_HEIGHT - model_end_pix);
    //     //lv_obj_set_height(ui_ImageChartMask, height <= (MAX_FILLINF_CHART_MASK_HEIGHT - model_end_pix) ? 0 : height);
    //     // printf("height <= (MAX_FILLINF_CHART_MASK_HEIGHT - model_end_pix) ? 0 : height = %d\n", height <= (MAX_FILLINF_CHART_MASK_HEIGHT - model_end_pix) ? 0 : height);
    // }
}

static void show_printing_file_name(void)
{
    lv_label_set_text(ui_LabelFileName, file_name_printing);
}

void home_printing_set_print_proccess_info(int32_t used_time, int32_t left_time, int8_t proccess)
{
    if ( proccess > 100 )
        proccess = 100;
    used_time_printing = used_time;
    remained_time_printing = left_time;
    proccess_printing = proccess;
    show_print_proccess();
    show_print_remained_time();
    show_print_used_time();
    //update mask png
    show_model_mask(proccess_printing);
    //update print opt button
    // if ( proccess >= 100 )
    // {
    //     LoadHomeNormalScreen();
    //     used_time_printing = 0;
    //     remained_time_printing = 0;
    //     proccess_printing = 0;
    //     lv_obj_add_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN);
    // }

}

void home_printing_set_print_file_name(char *file_name)
{
    if ( file_name )
    {
        char *ch = strrchr(file_name, '.');
        if ( ch )
            *ch = '\0';

        strncpy(file_name_printing, file_name, sizeof(file_name_printing));
    }
    else
        strcpy(file_name_printing, "");
        
    show_printing_file_name();
}

void show_filling_chart(void)
{   
    lv_obj_set_style_img_recolor(ui_ImageModelChart, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_ImageModelChart, 100, LV_PART_MAIN | LV_STATE_DEFAULT);
    if ( home_printing_is_printing_finished() )
    {
        lv_obj_add_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN);
    }
    else
        lv_obj_clear_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN);

    if(strcmp(print_job.gcode_type, SLICE_SOFTNAME) == 0)
    {
        lv_obj_clear_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_style_img_recolor_opa(ui_ImageModelChart, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }

    if ( strlen(filling_chart_name) )
    {
        char buff[258] = {0};
        // buff[0] = PNG_DRV_LETTER;
        // strncpy(buff + 1, filling_chart_name, sizeof(buff) - 2);
        snprintf(buff, 258, "%s:%s", PNG_DRV_LETTER, filling_chart_name);
        lv_img_set_src(ui_ImageModelChart, buff);
        lv_img_set_src(ui_ImageChartMask, buff);
    }
    else
    {
        lv_img_set_src(ui_ImageModelChart, &ui_img_crealitylogo_png);
        lv_img_set_src(ui_ImageChartMask, &ui_img_crealitylogo_png);
    }

    //根据file_name_printing找到它对应的预览图

    // if ( strlen(preview_filling_chart_name) )
    // {
    //     char buff[258] = {0};
    //     // buff[0] = PNG_DRV_LETTER;
    //     // strncpy(buff + 1, preview_filling_chart_name, sizeof(buff) - 2);
    //     snprintf(buff, 258, "%s:%s", PNG_DRV_LETTER, preview_filling_chart_name);
    //     lv_img_set_src(ui_ImageModelChart, buff);
    //     lv_img_set_src(ui_ImageChartMask, buff);
    // }
    // else
    // {
    //     if ( strlen(filling_chart_name) )
    //     {
    //         printf("filling_chart_name = %s\n", filling_chart_name);
    //         char buff[258] = {0};
    //         // buff[0] = PNG_DRV_LETTER;
    //         // strncpy(buff + 1, filling_chart_name, sizeof(buff) - 2);
    //         snprintf(buff, 258, "%s:%s", PNG_DRV_LETTER, filling_chart_name);
    //         lv_img_set_src(ui_ImageModelChart, buff);
    //         lv_img_set_src(ui_ImageChartMask, buff);
    //     }
    //     else
    //     {
    //         lv_img_set_src(ui_ImageModelChart, &ui_img_crealitylogo_png);
    //         lv_img_set_src(ui_ImageChartMask, &ui_img_crealitylogo_png); 
    //     }
    // }
    //lv_obj_set_width(ui_ImageChartMask, 300);

    lv_obj_set_style_img_recolor(ui_ImageChartMask, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_ImageChartMask, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void home_printing_set_filling_chart_name(char *chart_name, uint16_t pixel_start, 
                                          uint16_t pixel_end, float model_height,float model_layer_height)
{
    if ( !chart_name )
    {
        memset(filling_chart_name, 0, sizeof(filling_chart_name));
    }
    else
    {
        strncpy(filling_chart_name, chart_name, sizeof(filling_chart_name) - 1);
    }

    if ( lv_obj_is_visible(ui_ScreenHomePagePrinting) )
        show_filling_chart();
}


void show_printing_status(void)
{
    if ( print_status ==  3)  //0: finished , 1:stoped, 2:paused, 3:printing.
    {
        lv_obj_set_style_bg_img_src(ui_ButtonPrintOpt, &ui_img_start_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    else
    {
        lv_obj_set_style_bg_img_src(ui_ButtonPrintOpt, &ui_img_pause_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}

void print_messagebox_close()
{
    send_buzzer(0x01);
    set_printer_data(0x0f, 1, "1");
    selftest_messagebox_close();
    printcomplete_flag = false;
    if( CheckUpdataFlag )
    {
        DotCheckVersion = 1;
        EnterUpdatepage(1); //打印完成后查询版本信息
    }
}

void close_result_messagebox()
{
    lv_obj_add_flag(ui_PanelPrintResultMsgboxBg, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
}

void ui_event_ButtonMsgbox(lv_event_t * e)
{
    bool IsEntered = false;
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        //Error_message_delete(user_data);
        send_buzzer(0x01);
        close_result_messagebox();
        printcomplete_flag = false;
        CrLogI("ui_event_ButtonMsgbox BackPrepage(true)");
        BackPrepage(true);
        if (lv_scr_act() == ui_ScreenHomePagePrinting) //
        {
            LoadHomeNormalPageAndObjs(false);
        }
        set_printer_data(0x0f, 1, "1");
    }
}

void ResultMsgboxAddObjsToGroup(void)
{
    lv_group_remove_all_objs(encoder_group);

    lv_group_add_obj(encoder_group, ui_ButtonMsgbox);

}

//打印结果对话框
void create_result_messagebox(bool PrintResult, char *PrintTimeStr)
{
    uint8_t language_index = get_cur_language_index();

    // ErrorPopout.popout_focus_obj1 = NULL;
    // ErrorPopout.popout_focus_obj2 = NULL;
    // ErrorPopout.obj1_flag = false;
    // ErrorPopout.obj2_flag = false;
    // ErrorPopout.change_group_objs = ResultMsgboxAddObjsToGroup;
    //创建前记录之前的聚焦对象，如果前面有弹框，那么就不用记录
    if (!IsThereAnyPopout())
    {
        RecordObjBeforePopup();
    }

    if(ui_PanelPrintResultMsgboxBg == NULL)
    {        
        //消息背景面板
        ui_PanelPrintResultMsgboxBg = lv_obj_create(lv_layer_top());
        //ui_PanelPrintResultMsgboxBg = lv_obj_create(lv_scr_act());
        lv_obj_set_width(ui_PanelPrintResultMsgboxBg, 640);
        lv_obj_set_height(ui_PanelPrintResultMsgboxBg, 360);
        lv_obj_set_pos(ui_PanelPrintResultMsgboxBg, 0, 60);
        // lv_obj_clear_flag(ui_PanelPrintResultMsgboxBg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_PanelPrintResultMsgboxBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_PanelPrintResultMsgboxBg, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_PanelPrintResultMsgboxBg, 180, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(ui_PanelPrintResultMsgboxBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_PanelPrintResultMsgboxBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        // lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        // lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
        //lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        

        //消息框
        ui_PrintResulMsgbox = lv_obj_create(ui_PanelPrintResultMsgboxBg);
        lv_obj_set_width(ui_PrintResulMsgbox, 371);
        lv_obj_set_height(ui_PrintResulMsgbox, 285);
        lv_obj_align(ui_PrintResulMsgbox, LV_ALIGN_CENTER, 0, 0);
        lv_obj_clear_flag(ui_PrintResulMsgbox, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_PrintResulMsgbox, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_PrintResulMsgbox, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_PrintResulMsgbox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(ui_PrintResulMsgbox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_PrintResulMsgbox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
 
        //打印结果图片
        ui_ImagePrintResult = lv_img_create(ui_PrintResulMsgbox);
        lv_obj_set_size(ui_ImagePrintResult, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        lv_obj_align(ui_ImagePrintResult, LV_ALIGN_TOP_MID, 0, 18);

        //打印结果lable
        ui_LablePrintResult = lv_label_create(ui_PrintResulMsgbox);
        lv_obj_set_size(ui_LablePrintResult, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        //lv_obj_align_to(ui_LablePrintResult, ui_ImagePrintResult, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
        lv_obj_align(ui_LablePrintResult, LV_ALIGN_TOP_MID, 0, 120);
        lv_obj_set_style_text_color(ui_LablePrintResult, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_LablePrintResult, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_LablePrintResult, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_LablePrintResult, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        //打印时间面板
        ui_PanelPrintTime = lv_obj_create(ui_PrintResulMsgbox);
        lv_obj_set_size(ui_PanelPrintTime, 130, 38);
        lv_obj_align(ui_PanelPrintTime, LV_ALIGN_TOP_MID, 0, 157);
        //lv_obj_align_to(ui_PanelPrintTime, ui_LablePrintResult, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
        //lv_obj_clear_flag(ui_PanelPrintTime, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        //lv_obj_set_style_radius(ui_PanelHotendTemp, 35, LV_PART_MAIN | LV_STATE_DEFAULT);
        //默认样式
        lv_obj_set_style_bg_color(ui_PanelPrintTime, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_PanelPrintTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_side(ui_PanelPrintTime, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_PanelPrintTime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        //打印时间图片
        ui_ImagePrintTime = lv_img_create(ui_PanelPrintTime);
        lv_img_set_src(ui_ImagePrintTime, &ui_img_printtingtime_png);
        lv_obj_set_size(ui_ImagePrintTime, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        lv_obj_align(ui_ImagePrintTime, LV_ALIGN_LEFT_MID, 0, 0);

        //打印时间lable
        ui_LablePrintTime = lv_label_create(ui_PanelPrintTime);
        lv_obj_set_size(ui_LablePrintTime, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
        lv_obj_align(ui_LablePrintTime, LV_ALIGN_RIGHT_MID, 0, 0);
        //lv_label_set_text(ui_LablePrintTime, "");
        //lv_label_set_recolor(ui_LablePrintTime, "true");
        lv_obj_set_style_text_color(ui_LablePrintTime, lv_color_hex(0x9398A1), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_LablePrintTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_LablePrintTime, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_LablePrintTime, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        //按键
        ui_ButtonMsgbox = lv_btn_create(ui_PrintResulMsgbox);
        lv_obj_set_width(ui_ButtonMsgbox, 176);
        lv_obj_set_height(ui_ButtonMsgbox, 52);
        lv_obj_align(ui_ButtonMsgbox, LV_ALIGN_TOP_MID, 0, 217);
        //lv_obj_align_to(ui_ButtonMsgbox, ui_PanelPrintTime, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
        lv_obj_add_flag(ui_ButtonMsgbox, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ButtonMsgbox, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_ButtonMsgbox, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_ButtonMsgbox, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ButtonMsgbox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_ButtonMsgbox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_ButtonMsgbox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        //聚焦样式
        lv_obj_set_style_border_color(ui_ButtonMsgbox, lv_color_hex(0xFFFFFF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_border_opa(ui_ButtonMsgbox, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_border_width(ui_ButtonMsgbox, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_outline_pad(ui_ButtonMsgbox, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_outline_color(ui_ButtonMsgbox, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        // ErrorPopout.popout_focus_obj1 = ui_ButtonMsgbox;

        //按键lable,
        ui_LableBtnMsgbox = lv_label_create(ui_ButtonMsgbox);
        lv_obj_set_width(ui_LableBtnMsgbox, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_LableBtnMsgbox, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_align(ui_LableBtnMsgbox, LV_ALIGN_CENTER);
        //lv_label_set_text(ui_LableBtnMsgbox, Confirm[language_index]);
        lv_obj_set_style_text_color(ui_LableBtnMsgbox, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_LableBtnMsgbox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_LableBtnMsgbox, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        //注册回调
        lv_obj_add_event_cb(ui_ButtonMsgbox, ui_event_ButtonMsgbox, LV_EVENT_ALL, NULL);
    }
    else
    {
        if(lv_obj_has_flag(ui_PanelPrintResultMsgboxBg,LV_OBJ_FLAG_HIDDEN))
        {
            CrLogI("cancle the msgbox hidden!");
        }
        else
        {
            CrLogI("msgbox exists,quit!");
            return;
        }

    }
    lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_PanelPrintResultMsgboxBg, LV_OBJ_FLAG_HIDDEN);     /// Flags  
    if (PrintResult)
    {
        lv_img_set_src(ui_ImagePrintResult, &ui_img_complete_png);
        lv_label_set_text(ui_LablePrintResult, PrintCompleted[language_index]);  //已完成打印
    }
    else
    {
        lv_img_set_src(ui_ImagePrintResult, &ui_img_complete_png);
        lv_label_set_text(ui_LablePrintResult, "打印失败");  //已完成打印
    }
    lv_label_set_text(ui_LablePrintTime, PrintTimeStr);
    lv_label_set_text(ui_LableBtnMsgbox, Confirm[language_index]);

    //RecordObjBeforePopup();//记录原来的导航对象
    //ResultMsgboxAddObjsToGroup();
    InitPopoutManager(&BtnDialogPopout, ui_PanelPrintResultMsgboxBg, ResultMsgboxAddObjsToGroup);

    BtnDialogPopout.obj1_flag = true;
    BtnDialogPopout.popout_focus_obj1 = ui_ButtonMsgbox;

    //弹框聚焦对象处理
    ManagePopoutFocus();
}

void home_printing_set_printing_status(int status)
{
    // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
    if ( print_status == status )
        return;
    print_status = status;
    if ( (print_status == 2) || (print_status == 3) )
    {
        if(printcomplete_flag == true)
        {
            selftest_messagebox_close();
            printcomplete_flag = false;
        }



        if (lv_obj_has_flag(ui_PanelExtrudeRetract, LV_OBJ_FLAG_HIDDEN))
        {
            if(!ui_PanelPrintCtrlDialog)
            {
                LoadHomePrintingPageAndObjs(false);
                LoadHomePrintingPageAndObjs(true);
                lv_group_focus_obj(ui_ButtonPrintOpt);
            }
            else if (lv_obj_has_flag(ui_PanelPrintCtrlDialog, LV_OBJ_FLAG_HIDDEN))
            {
                LoadHomePrintingPageAndObjs(false);
                LoadHomePrintingPageAndObjs(true);
                lv_group_focus_obj(ui_ButtonPrintOpt);
            }
        }


        //LoadHomePrintingScreen();
        // if(CtrlDiagFlag)
        // {
        //     CtrlDiagFlag = false;
        //     // ClosePrintCtrlDialog();
        //     //切换聚焦对象
        //     // BackPrepage(false);
        // }
        // else
        // {
        //     LoadHomePrintingPageAndObjs(false);
        //     //LoadHomePrintingPageAndObjs(true);
        //     //lv_group_focus_obj(ui_event_ButtonPrintOpt);
        // }
        
    }
    else if ( (print_status == 1) )
    {
        if (StopAndResumeFlag)  //解决暂停或者继续会刷一下正常首页的问题
        {
            StopAndResumeFlag = false;
            return;
        }
        if(printcomplete_flag == true)
        {
            selftest_messagebox_close();
            printcomplete_flag = false;
        }

        //打印停止将模型图恢复一下
        int height = (print_job.end_px - print_job.start_px) + (MAX_FILLINF_CHART_MASK_HEIGHT - print_job.end_px);
        lv_obj_set_height(ui_ImageChartMask, height);
        //LoadHomeNormalScreen();
        if (lv_scr_act() == ui_ScreenHomePagePrinting) //如果时其他页面则不返回首页
        {
            LoadHomeNormalPageAndObjs(false);
        }
        
    }
    else if( print_status == 0 ){
        char buff[10] = {0};
        printcomplete_flag = true;
        void (*btns_callback[2])(void) = {NULL, &print_messagebox_close};
        uint8_t language_index = get_cur_language_index(); 
        //TODO:优化时间的获取       
        int32_t used_time_m = used_time_printing / 60; //trans to minters
        sprintf(buff, "%dh%02dm", used_time_m / 60, used_time_m % 60); 
        //if (!lv_obj_has_flag(ui_ScreenoffPanel1, LV_OBJ_FLAG_HIDDEN))
        {
            create_result_messagebox(true, buff);
            // HomePrintingAdd3rdLevelObjsCb = ResultMsgboxAddObjsToGroup;
            // LoadPage(ui_ScreenHomePagePrinting, 3);
        }
        //create_selftest_messagebox(KindTips[language_index], PrintCompleted[get_cur_language_index()],NULL, FinishedArray[language_index], btns_callback);
        //打印完成将模型图恢复一下
        int height = (print_job.end_px - print_job.start_px) + (MAX_FILLINF_CHART_MASK_HEIGHT - print_job.end_px);
        lv_obj_set_height(ui_ImageChartMask, height);
        used_time_printing = 0;
        remained_time_printing = 0;
        proccess_printing = 0;
        lv_obj_add_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN);
    }
}

bool home_printing_is_printing_finished()  // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
{
    if ( (print_status == 0) || (print_status == 1) )
        return true;
    
    return false;
}

bool home_printing_is_printing()  // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
{
    return print_status == 3 ?  true : false;
}

bool home_printing_is_paused()  // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
{
    return print_status == 2 ? true : false;
}

void printing_pause_print_opt_callback(void)
{
    send_set_pause_print_cmd();
    // print_status = 2;
    // home_printing_set_printing_status(print_status);
}

void stop_print_confirm_callback(struct _lv_timer_t *timer)
{
    memset(file_name_printing, 0, sizeof(file_name_printing));
    memset(filling_chart_name, 0, sizeof(filling_chart_name));
}

void printing_stop_print_opt_callback(void)
{
    send_set_stop_print_cmd();
    //print_status = 1;
    //home_printing_set_printing_status(print_status);
    
    //LoadHomeNormalScreen();

    lv_timer_t *timer_offset = lv_timer_create(stop_print_confirm_callback, 2000, NULL);
    lv_timer_set_repeat_count(timer_offset, 1);
}

void printing_resume_print_opt_callback(void)
{
    if(material_seneor == '4')
    {
        set_filament_runout(true);
        return;
    }
    send_set_resume_print_cmd();
    // print_status = 3;
    // home_printing_set_printing_status(print_status);
}

void printing_recovery_file_print_again_callback(void)
{
    poweloss_flag = false;
    send_set_start_print_recovery_file();
}

void printing_recovery_file_stop_print_callback(void)
{
    poweloss_flag = false;
    send_set_stop_print_recovery_file();
    BackPrepage(true);
}

void home_printing_set_powerloss_recovery_info(int state)
{
    if(state)
    {
        if(poweloss_flag)
        {
            CrLogI("powerloss tips is exist.");
            return;
        }
        poweloss_flag = true;
        uint8_t cur_language = get_cur_language_index();
        char *btns[2] = {0};
        char buff[20] = {0};
        sprintf(buff, "%s%s", Resume[cur_language], Print[cur_language]);
        btns[0] = buff;
        btns[1] = Cancel[cur_language];
        void (*btns_callback[2])(void) = {&printing_recovery_file_print_again_callback, &printing_recovery_file_stop_print_callback};
        create_custom_messagebox(KindTips[cur_language], PowerLossRecoverMsg[cur_language], btns, btns_callback, 2, true, false);
        set_custom_messagebox_btn_bg_color(0, lv_color_hex(0x42BDD8));
    }
    else
    {
        if(poweloss_flag)
        {
            CrLogI("cancle the powerloss tips");
            poweloss_flag = false;
            // printing_recovery_file_stop_print_callback();
            messagebox_close();
        }
        if(FirstInitFlag && CheckUpdataFlag)//首次UI初始化查询版本更新信息
        {
            FirstInitFlag = false;
            DotCheckVersion = 1;
            EnterUpdatepage(1);
        }
    }
}

void printing_replace_mater_callback()
{
    // if (  printing_filament_runout )
    // {
    //     uint8_t cur_language = get_cur_language_index();
    //     char *btns[2] = {0};
    //     btns[0] = Confirm[cur_language];
    //     btns[1] = Stop[cur_language];
    //     void (*btns_callback[2])(void) = {&printing_replace_mater_callback, &printing_stop_replace_mater_callback};
    //     create_custom_messagebox(KindTips[cur_language], FilamentRunOutMsg[cur_language], btns, btns_callback, 2, true, false);
    //     set_custom_messagebox_btn_bg_color(1, lv_color_hex(0x42BDD8));
    //     return ;
    // }

    // printing_resume_print_opt_callback();
    CrLogI("printing_replace_mater_callback BackPrepage(true)");
    BackPrepage(true);
}

void printing_stop_replace_mater_callback(void)
{
    // printing_stop_print_opt_callback();
    lv_obj_set_parent(ui_PanelExtrudeRetract, lv_scr_act());
    HomePrintingAdd3rdLevelObjsCb = AddExtrudeRetractNavObjs;
    //TODO:显示进退料子页，并聚焦到上面,参考函数MovePageExtrudeRetractBtnClicked
    lv_obj_clear_flag(ui_PanelExtrudeRetract, LV_OBJ_FLAG_HIDDEN);
    if (filament_action == FILA_ACTION_NONE)
    {
        show_proccess_panel(PROMPT_STATE_TIP);
        show_temper_panel(SHOW_TEMPER_EDIT_PANEL);
        filament_actions_status(false);
    }
    LoadPage(lv_scr_act(), 3);
}

void home_printing_set_filament_runout(bool filamen_runout)
{
    if ( home_printing_is_printing_finished() )
        return;

    if ( filamen_runout )
    {
        uint8_t cur_language = get_cur_language_index();
        char *btns[2] = {0};
        btns[0] = ForgetPasswordArray[cur_language];
        btns[1] = ToChangeFilament[cur_language];
        void (*btns_callback[2])(void) = {&printing_replace_mater_callback, &printing_stop_replace_mater_callback};
        create_custom_messagebox(KindTips[cur_language], FilamentRunOutMsg[cur_language], btns, btns_callback, 2, true, false);
        set_custom_messagebox_btn_bg_color(0, lv_color_hex(0x50535A));
        // HomePrintingAdd3rdLevelObjsCb = FilamentRunoutPopoutNavObjs;
        // ShowDialogMessagebox(&FilamentRunoutMessage);
        // LoadPage(ui_ScreenHomePagePrinting, 3);
    }

    printing_filament_runout = filamen_runout;
}

void home_printing_set_home_status(bool is_homing)
{
    // if ( is_homing )
    // {
    //     //if ( !lv_obj_has_flag(ui_ScreenHomePagePrinting, LV_OBJ_FLAG_HIDDEN) )
    //     if ( home_printing_is_printing() )
    //     {
    //         create_custom_reminderbox("printing homing...", false);
    //         set_custom_reminderbox_clickable(false);
    //         set_custom_reminderbox_display_timeout(30, NULL);
    //     }
    // }
    // else
    // {
    //     if ( !lv_obj_has_flag(ui_ScreenHomePagePrinting, LV_OBJ_FLAG_HIDDEN) )
    //         close_custom_reminderbox();
    // }
}

void home_printing_set_gcode_layers_count(uint32_t layer_count)
{
    gcode_layer_count = layer_count;
}

void home_printing_set_gcode_cur_layer_index(uint32_t layer_index)
{
    lv_obj_clear_flag(ui_ImageChartMask, LV_OBJ_FLAG_HIDDEN);

    // if ( ui_ImageChartMask && gcode_layer_count )
    // {
    //     if ( layer_index > gcode_layer_count )
    //         layer_index = gcode_layer_count; 

    //     int height = ((gcode_layer_count - layer_index) * (print_job.end_px - print_job.start_px)) / gcode_layer_count + (MAX_FILLINF_CHART_MASK_HEIGHT - print_job.end_px);
    //     CrLogI("height count is:%d,%d,%d,%d,%d",height,gcode_layer_count,layer_index,print_job.end_px,print_job.start_px);
    //     lv_obj_set_height(ui_ImageChartMask, height <= (MAX_FILLINF_CHART_MASK_HEIGHT - print_job.end_px) ? 0 : height);
    //     //printf("height <= (MAX_FILLINF_CHART_MASK_HEIGHT - print_job.end_px) ? 0 : height = %d\n", height <= (MAX_FILLINF_CHART_MASK_HEIGHT - print_job.end_px) ? 0 : height);
    // }
    if ( ui_ImageChartMask )
    {
        if ( gcode_layer_count > 0)
        {
            // int height = ((gcode_layer_count - layer_index) * MAX_FILLINF_CHART_MASK_HEIGHT) / gcode_layer_count;
            int height = ((gcode_layer_count - layer_index) * (print_job.end_px - print_job.start_px)) / gcode_layer_count + (MAX_FILLINF_CHART_MASK_HEIGHT - print_job.end_px);
            CrLogI("height count is:%d,%d,%d,%d,%d",height,gcode_layer_count,layer_index,print_job.end_px,print_job.start_px);
            lv_obj_set_height(ui_ImageChartMask, height <= (MAX_FILLINF_CHART_MASK_HEIGHT - print_job.end_px) ? 0 : height);
        }
        else
        {
            lv_obj_set_height(ui_ImageChartMask, 300);
        }
    }
}



static void HomePageNormalGroupObjsAddLevel0()
{
    lv_group_remove_all_objs(HomePageManage.GropName);
    lv_indev_set_group(enc_indev, NULL); 
    lv_indev_set_group(enc_indev,  HomePageManage.GropName); //关联组
    lv_group_add_obj(HomePageManage.GropName, ui_ButtonHomePage);
    lv_group_add_obj(HomePageManage.GropName, ui_ButtonAxisMove);
    lv_group_add_obj(HomePageManage.GropName, ui_ButtonFIleManage);
    lv_group_add_obj(HomePageManage.GropName, ui_ButtonSettings);
    lv_group_add_obj(HomePageManage.GropName, ui_ButtonReserve);
 
   
    lv_group_focus_obj(HomePageManage.HistorySelObjOfLevel[0]);
}

static void HomePageNormalGroupObjsAddLevel1(bool CurPageFlag, lv_obj_t *CurFocusObj)
{
    lv_group_remove_all_objs(HomePageManage.GropName);
    lv_indev_set_group(enc_indev, NULL); 
    lv_indev_set_group(enc_indev, HomePageManage.GropName ); //关联组
    lv_group_add_obj(HomePageManage.GropName, ui_ButtonHomePage);
    lv_group_add_obj(HomePageManage.GropName, ui_PanelHotendTemp);
    lv_group_add_obj(HomePageManage.GropName, ui_PanelBedTemp);
    lv_group_add_obj(HomePageManage.GropName, ui_Panel_Fans);
    lv_group_add_obj(HomePageManage.GropName, ui_ButtonPrintOpt);
    if (CurPageFlag)
        HomePageManage.HistorySelObjOfLevel[HomePageManage.CurLevel] = CurFocusObj;
    else {
        lv_group_focus_obj(HomePageManage.HistorySelObjOfLevel[HomePageManage.CurLevel]);
    }
}

static void HomePageNormalGroupObjsAddLevel2(bool CurPageFlag, lv_obj_t *CurFocusObj)
{
    lv_group_remove_all_objs(HomePageManage.GropName);
    lv_indev_set_group(enc_indev, NULL); 
    lv_indev_set_group(enc_indev, HomePageManage.GropName ); //关联组
    //lv_group_add_obj( HomePageManage.GropName, ui_ButtonHomePage);
    lv_group_add_obj(HomePageManage.GropName, ui_PanelHotendTemp);
    lv_group_add_obj(HomePageManage.GropName, ui_PanelBedTemp);
    lv_group_add_obj(HomePageManage.GropName, ui_Panel_Fans);
    lv_group_add_obj(HomePageManage.GropName, ui_ButtonPrintOpt);
    if (CurPageFlag)
        HomePageManage.HistorySelObjOfLevel[HomePageManage.CurLevel] = CurFocusObj;
    else {
        lv_group_focus_obj(HomePageManage.HistorySelObjOfLevel[HomePageManage.CurLevel]);
    }
}

static void PageMenuChange(bool CurPageFlag, uint8_t Curpage_level, lv_obj_t *CurFocusObj)
{
    static uint8_t level_tmp;
    HomePageManage.CurLevel = Curpage_level;

    if(CurPageFlag) { //进入下一页面
        level_tmp =  Curpage_level + 1; 
    }
    else { //返回上一页面
        if (Curpage_level > 0)
            level_tmp =  Curpage_level - 1;
        if (Curpage_level == 0) //当前页面为1级页面
            level_tmp = 0;
    }

    switch (level_tmp)
    {
    case 0:
        HomePageNormalGroupObjsAddLevel0();
        break;
    case 1:
        HomePageNormalGroupObjsAddLevel1(CurPageFlag, CurFocusObj);
        break;
    case 2:
        HomePageNormalGroupObjsAddLevel2(CurPageFlag, CurFocusObj);
        break;
    default:
        break;
    }
   
}

/**
 * @description:  改变正常首页编码器的导航对象
 * @return {void}
 * @param {levelIndex: 表示导航对象的等级，IsEntered：是否进入}
 */
void LoadHomePrintingPageAndObjs(bool IsEntered)
{
    HomePageManage.stateValue = IsEntered;
   // ScreenStatusValue = IsEntered;
    if(HomePageManage.stateValue == 0) //一级页面导航模式
    {
        //PageMenuChange(MENU_RETURN, MENU_LEVEL_2, NULL);
        LoadPage(ui_ScreenHomePagePrinting, 1);
        lv_obj_set_style_bg_img_src(ui_ButtonHomePage, &ui_img_pagehome_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_group_focus_cycle(encoder_group, true);
    }
    else //二级页面导航模式
    {    
        //PageMenuChange(MENU_ENTER, MENU_LEVEL_1, ui_ButtonHomePageNormal);
        LoadPage(ui_ScreenHomePagePrinting, 2);
        lv_obj_set_style_bg_img_src(ui_ButtonHomePage, &ui_img_pagehomeselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_group_focus_cycle(encoder_group, false);
    }
}


static void HomePrintingPageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);

    PageNode *HomePrintingPage_node = find_page(ui_ScreenHomePagePrinting);
    HomePrintingPage_node->nav_level = index;
    page_manager.objFreezzFlag = false;

    switch (index)
    {
    case 1: //1级事件组
        lv_group_add_obj(encoder_group, ui_ButtonHomePage);
        lv_group_add_obj(encoder_group, ui_ButtonAxisMove);
        lv_group_add_obj(encoder_group, ui_ButtonFIleManage);
        lv_group_add_obj(encoder_group, ui_ButtonSettings);
        lv_group_add_obj(encoder_group, ui_ButtonReserve);
        HomePrintingAdd3rdLevelObjsCb = NULL;
        break;
    case 2: //2级事件组
        lv_group_add_obj(encoder_group, ui_ButtonHomePage);
        lv_group_add_obj(encoder_group, ui_PanelHotendTemp);
        lv_group_add_obj(encoder_group, ui_PanelBedTemp);
        lv_group_add_obj(encoder_group, ui_Panel_Fans);
        lv_group_add_obj(encoder_group, ui_ButtonPrintOpt);
        HomePrintingAdd3rdLevelObjsCb = NULL;
        break;
    case 3: //3级事件动态加载
        if (HomePrintingAdd3rdLevelObjsCb)
        {
            HomePrintingAdd3rdLevelObjsCb();
        }
        break;
    // case 4: //4级事件动态加载 
    //     if ()
    //     {

    //     }
    //     break;
    default:
        break;
    }
 
}

void refresh_prepare_process(int process)
{
    CrLogI("current prepart print process:%d", process);
    int language = get_cur_language_index();
    switch(process)
    {
        case PREPARE_STEP_NULL:             lv_label_set_text(ui_LabelPrepareTips, "");break;
        case PREPARE_STEP_FOREIGN_BODY:     lv_label_set_text(ui_LabelPrepareTips, FOREIGN_BODY[language]);break;
        case PREPARE_STEP_NOZZLE_CLEAR:     lv_label_set_text(ui_LabelPrepareTips, NOZZLE_CLEAR[language]);break;
        case PREPARE_STEP_ROUGH_G28:        lv_label_set_text(ui_LabelPrepareTips, ROUGH_G28[language]);break;
        case PREPARE_STEP_ACCURATE_G28:     lv_label_set_text(ui_LabelPrepareTips, ACCURATE_G28[language]);break;
        case PREPARE_STEP_LEVEL_DELECT:     lv_label_set_text(ui_LabelPrepareTips, LEVEL_DELECT[language]);break;
        case PREPARE_STEP_LASER_CALIBRATION:lv_label_set_text(ui_LabelPrepareTips, LASER_CALIBRATION[language]);break;
        // 流量检测
        case PREPARE_STEP_FLOW_SCAN_TABLE:  
        case PREPARE_STEP_FLOW_PRINT_LINE:  lv_label_set_text(ui_LabelPrepareTips, PRINT_LINE[language]);break;
        case PREPARE_STEP_FLOW_COOL_DOWN :  lv_label_set_text(ui_LabelPrepareTips, COOL_DOWN[language]);break;
        case PREPARE_STEP_FLOW_SCAN_MODEL:  lv_label_set_text(ui_LabelPrepareTips, SCAN_MODEL[language] );break;
        case PREPARE_STEP_FLOW_AI_CALCULATE:break;
        // 首层检测
        case PREPARE_STEP_FLOOR_SCAN_TABLE: lv_label_set_text(ui_LabelPrepareTips, FLOOR_SCAN_TABLE[language]);break;
        case PREPARE_STEP_FLOOR_PRINT_LINE: lv_label_set_text(ui_LabelPrepareTips, FLOOR_PRINT_LINE[language]);break;
        case PREPARE_STEP_FLOOR_COOL_DOWN:  lv_label_set_text(ui_LabelPrepareTips, FLOOR_COOL_DOWN[language]);break;
        case PREPARE_STEP_FLOOR_SCAN_MODEL: lv_label_set_text(ui_LabelPrepareTips, FLOOR_SCAN_MODEL[language]);break;
        case PREPARE_STEP_FLOOR_AI_CALCULATE:lv_label_set_text(ui_LabelPrepareTips,FLOOR_AI_CALCULATE[language]);break;
        case PREPARE_STEP_FLOOR_HEAT_UP:    lv_label_set_text(ui_LabelPrepareTips, FLOOR_HEAT_UP[language]);break;
        // 完成
        case PREPARE_STEP_FINISH:           lv_label_set_text(ui_LabelPrepareTips, "");break;
        default:                            CrLogW("process error");break;
    }
}


