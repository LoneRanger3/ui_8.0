#include "ui_screen_AxisMove.h"
#include <stdio.h>
#include <stdlib.h>
#include "ui_screen_HomeNormal.h"
#include "ui_screen_FileManage.h"
#include "ui_custom_messagebox.h"
#include "ui_custom_reminderbox.h"
#include "../custom/lvgl_cmd.h"
#include "ui_Screen_Settings.h"
#include "ui_Screen_CustomerService.h"
#include "mult_language.h"
#include "ui_screen_cool.h"
#include "ui.h"
#include "custom.h"
#include "src/core/lv_event.h"
#include "src/core/lv_obj.h"
#include "src/core/lv_obj_pos.h"
#include "src/misc/lv_txt.h"
#include "ui_custom_dirent_info_part.h"

/********axis Move Page***********/
static lv_obj_t * ui_ScreenAxisMovePage;
/******************axis move screen left panel**********************/
static lv_obj_t * ui_PanelPageScreenAxisMove;
static lv_obj_t * ui_ButtonHomeScreenAxisMove;
// static lv_obj_t * ui_ImageAxisMovePage;
static lv_obj_t * ui_ButtonAxisMoveAxisMove;
static lv_obj_t * ui_ButtonFileManageScreenAxisMove;
static lv_obj_t * ui_ButtonSettingsScreenAxisMove;
static lv_obj_t * ui_ButtonReserveScreenAxisMove;

/******************axis move screen right panel**********************/
static lv_obj_t * ui_PanelMoveAndTemper;
/******************axis move screen right top panel title and status**********************/
static lv_obj_t * ui_PanelTitleAndStatusAxisMove;
static lv_obj_t * ui_AxisMoveDeviceIconPanel;
static lv_obj_t * ui_LabelCtrlTitle;

static lv_obj_t * ui_ImageLaserAxisMove;
static lv_obj_t * ui_ImageWifiAxisMove;
static lv_obj_t * ui_ImageCamerastateAxisMove;

/******************axis move screen main body**********************/
static lv_obj_t * ui_PanelCtrlList;

static int wifi_Intensity = 0;

/*************axis move screen right panel hotend temper opt******************/
static lv_obj_t * ui_LabelTemperUnitScreenMove;

static lv_obj_t * ui_ModelFanPanel; //风扇速度设置
static lv_obj_t * ui_ModelFanLabel;
static lv_obj_t * ui_ModelFanValLabel;
static lv_obj_t * ui_ModelFanValSetLabel;
// static lv_obj_t * ui_LabelModelFanPercent;
// static lv_obj_t * ui_ValueModelFanPercent;

static lv_obj_t * ui_AuxiliaryFanPanel; //风扇速度设置
static lv_obj_t * ui_AuxiliaryFanLabel;
static lv_obj_t * ui_AuxiliaryFanValLabel;
static lv_obj_t * ui_AuxiliaryFanValSetLabel;
// static lv_obj_t * ui_LabelAuxiliaryFanPercent;
// static lv_obj_t * ui_ValueAuxiliaryFanPercent;

static lv_obj_t * ui_XAxisMovePanel; //X轴移动设置
static lv_obj_t * ui_XAxisMoveLabel;
static lv_obj_t * ui_XAxisMoveValLabel;
static lv_obj_t * ui_XAxisMoveValSetLabel;

static lv_obj_t * ui_YAxisMovePanel; //Y轴移动设置
static lv_obj_t * ui_YAxisMoveLabel;
static lv_obj_t * ui_YAxisMoveValLabel;
static lv_obj_t * ui_YAxisMoveValSetLabel;

static lv_obj_t * ui_ZAxisMovePanel; //Y轴移动设置
static lv_obj_t * ui_ZAxisMoveLabel;
static lv_obj_t * ui_ZAxisMoveValLabel;
static lv_obj_t * ui_ZAxisMoveValSetLabel;

/*************axis move screen right panel hotend heating opt******************/
// static lv_obj_t * ui_PanelHotendHeatingScreenMove;
// static lv_obj_t * ui_ImageHotendHeatingScreenMove;
static lv_obj_t * ui_LabelTargetTemperScreenMove;
// static lv_obj_t * ui_LabelTemperUnitHeatingScreenMove;
static lv_obj_t * ui_LabelCurTemperScreenMove;
static lv_obj_t * ui_LabelEditTemperScreenMove;
// static lv_obj_t * ui_ImageToTargetScreenMove;
static lv_obj_t * ui_LabelLeftSlashScreenMove;

// static lv_obj_t * ui_Panel1;

/*************axis move screen right panel bed temper opt******************/
// static lv_obj_t * ui_PanelBed;
// static lv_obj_t * ui_ImageBedScreenMove;
// static lv_obj_t * ui_LabelBedTemperScreenMove;
static lv_obj_t * ui_LabelBedTemperUnitScreenMove;

/*************axis move screen right panel bed heating opt******************/
// static lv_obj_t * ui_PanelBedHeatingScreenMove;
// static lv_obj_t * ui_ImageBedToTargetScreenMove;
static lv_obj_t * ui_LabelBedLeftSlashScreenMove;
static lv_obj_t * ui_LabelBedCurTemperScreenMove;
static lv_obj_t * ui_LabelBedEditTemperScreenMove;
// static lv_obj_t * ui_LabelBedTemperUnitScreenMove1;
static lv_obj_t * ui_LabelBedTargetTemperScreenMove;
// static lv_obj_t * ui_ImageBedHeatingScreenMove;

// static lv_obj_t * ui_Panel2;


/*************axis move screen right panel thermostat temper opt******************/
// static lv_obj_t * ui_PanelThermostat;
// static lv_obj_t * ui_ImageThermostatScreenMove;
static lv_obj_t * ui_LabelThermostatTemperScreenMove;
// static lv_obj_t * ui_LabelThermostatTemperUnitScreenMove;


/*************axis move screen right panel move E opt******************/
static uint8_t model_fan_speed;
static int16_t x_cur_pos;
static int16_t y_cur_pos;
static int16_t z_cur_pos;

/***********************menu lable*****************************/
static lv_obj_t * LableHotendTemp;
static lv_obj_t * LableBedTemp;
static lv_obj_t * LableHomeXY;
static lv_obj_t * LableHomeZ;
static lv_obj_t * LableXAxisMove;
static lv_obj_t * LableYAxisMove;
static lv_obj_t * LableZAxisMove;
static lv_obj_t * LableTurnOffTheMotor;
static lv_obj_t * LableInOrOutMaterial;
static lv_obj_t * LableFan;
static lv_obj_t * LableModelFan;
static lv_obj_t * LableAuxiliaryFan;

//进退料
lv_obj_t * ui_PanelExtrudeRetract;       //进退料主面板
static lv_obj_t * ui_LableExtrudeRetractTitle;
static lv_obj_t * ui_ExtrudeRetractBackBtn;
static lv_obj_t * ui_LineUpperLowerDividing;
static lv_obj_t * ui_LineLeftRightDividing;

//中间，喷嘴的初始化状态
static lv_obj_t * ui_PanelHotendInitState;
static lv_obj_t * ui_TitleHotendTemp;
static lv_obj_t * ui_PanelHotendTemp;
static lv_obj_t * ui_LableHotendTemp;
static lv_obj_t * ui_LabelTemperUnit;
static uint16_t ExtrudeRetractTargetTemper = 240;

//中间，喷嘴的正常状态
static lv_obj_t * ui_PanelHotendNormalState;
static lv_obj_t * ui_ImageHotendNormal;
static lv_obj_t * ui_LabelNormalRealTemper;
// static lv_obj_t * ui_LabelNormalRealTemperUnit;
//static lv_obj_t * ui_LableHotendTempNormal;

//中间，喷嘴的加热状态
static lv_obj_t * ui_PanelHotendHeatingState;
static lv_obj_t * ui_ImageHotendHeating;
static lv_obj_t * ui_LableRealHotendTempHeating;
static lv_obj_t * ui_ImageTemperTo;
static lv_obj_t * ui_LableTargetHotendTempHeating;

//两个按钮
static lv_obj_t * ui_BntExtrude;    //进料按钮
static lv_obj_t * ui_LableExtrude;
static lv_obj_t * ui_BntRetract;    //退料按钮
static lv_obj_t * ui_LableRetract;

//进退料右边信息面板
static lv_obj_t * ui_PanelInfoExtrudeRetract;

//提示信息
static lv_obj_t * ui_LableTipInfoContent;

//进料进度信息面板
static lv_obj_t * ui_PanelExtrudeProccessInfo;

static lv_obj_t * ui_RoundExtrudeFirstStepNum;
static lv_obj_t * ui_LableExtrudeFirstStepNum;
static lv_obj_t * ui_LableExtrudeFirstStepContent;
static lv_obj_t * ui_CableExtrudeFirstStep;

static lv_obj_t * ui_RoundExtrudeSecondStepNum;
static lv_obj_t * ui_LableExtrudeSecondStepNum;
// static lv_obj_t * ui_LableExtrudeSecondStepContent;
static lv_obj_t * ui_CableExtrudeSecondStep;

static lv_obj_t * ui_RoundExtrudeThirdStepNum;
static lv_obj_t * ui_LableExtrudeThirdStepNum;
static lv_obj_t * ui_LableExtrudeThirdStepContent;

//退料进度信息面板
static lv_obj_t * ui_PanelRetractProccessInfo;

static lv_obj_t * ui_RoundRetractFirstStepNum;
static lv_obj_t * ui_LableRetractFirstStepNum;
static lv_obj_t * ui_LableRetractFirstStepContent;
static lv_obj_t * ui_CableRetractFirstStep;

static lv_obj_t * ui_RoundRetractSecondStepNum;
static lv_obj_t * ui_LableRetractSecondStepNum;
static lv_obj_t * ui_LableRetractSecondStepContent;
static lv_obj_t * ui_CableRetractSecondStep;

static lv_obj_t * ui_RoundRetractThirdStepNum;
static lv_obj_t * ui_LableRetractThirdStepNum;
static lv_obj_t * ui_LableRetractThirdStepContent;
static lv_obj_t * ui_CableRetractThirdStep;

static lv_obj_t * ui_RoundRetractFourthStepNum;
static lv_obj_t * ui_LableRetractFourthStepNum;
static lv_obj_t * ui_LableRetractFourthStepContent;

static lv_timer_t *encode_display_timer = NULL;

/***********************custom variable*****************************/
#define SMALL_DIS_UNIIT_VALUE (1)
#define MID_DIS_UNIIT_VALUE (10)
#define LARGE_DIS_UNIIT_VALUE (30)
#define Z_AXIS_MIN_DIS 0.0f


enum FILA_ACTION_TYPE filament_action = FILA_ACTION_NONE;
static uint8_t filament_action_step_order = 0;
static int targettemp = 0;
// static int dis_unit = 0;  // 0:small dis unit (1), 1: mid dis unit (10), 2:large dis unit(50).
static int16_t bed_temper_move = -15;
static int16_t bed_target_temper_move = 0;
static int16_t hotend_temper_move = -15;
static int16_t hotend_target_temper_move = 0;
// static bool model_fan_opened = false;
// static lv_timer_t *fan_timer = NULL;
int16_t axis_move_feedrate_xy = 3000;
int16_t axis_move_feedrate_z  = 600;    
int16_t axis_move_feedrate_e  = 120;
static uint8_t home_action = 0;   // 第1个bit位为1表示X轴归零动作，第2个bit位为1表示Y轴归零动作，第3个bit位为1表示Z轴归零动作，
static uint8_t home_flag = 0;  //第1个bit位表示X轴归零标识（1：归零， 0未归零），第2个bit位表示Y轴归零标识（1：归零， 0未归零），第3个bit位表示Z轴归零标识（1：归零， 0未归零）
static uint8_t z_move_forward_dir = 0;  //0:正向，1：反向. 
// static char language_sign = '0';  //根据协议字符‘0’到字符‘7’分别对应8个label
// static lv_group_t * changelabel_g;
// static dirent_info_part_t *part_array[8] = {NULL};
ctrl_list_t *ctrl_array[13] = {NULL};
ctrl_list_t *fan_ctrl_array[4] = {NULL};
lv_timer_t * FanCtrltimer;
EventGrop_Data AxisMove;
typedef void (*add_3rd_level_nav_objs_f)(void);  //添加三级导航对象
static add_3rd_level_nav_objs_f add_3rd_level_nav_objs = NULL;
//bool RefreshModelFanFlag = false;
static const double FanMinDutyValue = 40.0;
static bool OperableFlag = true;   //默认所有功能都可以操作，但打印过程中一些功能是不可以操作的

/************************event****************************/
static void ui_event_ExtrudeRetract(lv_event_t * e);
static void ui_event_ButtonHomeScreenAxisMove(lv_event_t * e);
static void ui_event_ButtonFileManageScreenAxisMove(lv_event_t * e);
static void ui_event_ButtonSettingsScreenAxisMove(lv_event_t * e);
static void ui_event_ButtonReserveScreenAxisMove(lv_event_t * e);
static void ui_event_PanelHotend(lv_event_t * e);
static void ui_event_PanelBed(lv_event_t * e);
static void ui_event_PanelCool(lv_event_t * e);
static void ui_event_ImgButtonStepperDisable(lv_event_t * e);
static void ui_event_ButtonHomeXYScreenMove(lv_event_t * e);
static void ui_event_ButtonHomeZ(lv_event_t * e);

/**********************event call back****************************/
static void MovePageCoolBtnClicked(lv_event_t * e);
static void MovePageStepperDisableBtnClicked(lv_event_t * e);
static void MovePageHomeXYBtnClicked(lv_event_t * e);
static void MovePageHomeZBtnClicked(lv_event_t * e);

/**********************custom funs***********************************/
static void show_hotend_heating_status_screen_move(bool show);
static void show_bed_heating_status_screen_move(bool show);
static void axis_move_change_move_btns_status(int8_t axis_home_flag); //第1个bit位表示X轴归零标识（1：归零， 0未归零），第2个bit位表示Y轴归零标识（1：归零， 0未归零），第3个bit位表示Z轴归零标识（1：归零， 0未归零）
static void MovePageExtrudeRetractBtnClicked(lv_event_t * e);
static void ui_event_update_AxisMove_page(lv_event_t * e);
static void AxisMovePageChangeObjs(uint8_t index);
static ctrl_list_t *create_ctrl_list_item(lv_obj_t *parent, uint8_t index, int16_t pos_x, int16_t pos_y, void (*part_event_callback)(lv_event_t *));
static ctrl_list_t *create_fan_ctrl_list_item(lv_obj_t *parent, uint8_t index, int16_t pos_x, int16_t pos_y, void (*part_event_callback)(lv_event_t *));
static void show_in_filament_proccess(enum IN_FILA_PROCCESS in_step);
static char *AxisMoveEncoderChangeValue(int16_t inValue, uint8_t step, lv_event_t * e, int32_t Min, int32_t Max);
static void ui_event_CtrlItem(lv_event_t * e);
static void ui_event_FanCtrlItem(lv_event_t * e);
static void ScreenHotendTempStyleInit(ctrl_list_t *part, const char *item_name);
static void ScreenBedTempStyleInit(ctrl_list_t *part, const char *item_name);
static void ScreenHomeXYStyleInit(ctrl_list_t *part, const char *item_name);
static void ScreenHomeZStyleInit(ctrl_list_t *part, const char *item_name);
static void ScreenXAxisMoveStyleInit(ctrl_list_t *part, const char *item_name);
static void ScreenYAxisMoveStyleInit(ctrl_list_t *part, const char *item_name);
static void ScreenZAxisMoveStyleInit(ctrl_list_t *part, const char *item_name);
static void ScreenTurnOffTheMotorStyleInit(ctrl_list_t *part, const char *item_name);
static void ScreenInOrOutMaterialStyleInit(ctrl_list_t *part, const char *item_name);
static void ScreenFanStyleInit(ctrl_list_t *part, const char *item_name);
static void ScreenModelFanStyleInit(ctrl_list_t *part, const char *item_name);
static void ScreenAuxiliaryFanStyleInit(ctrl_list_t *part, const char *item_name);
static void ui_CoolSubPage_init(lv_obj_t *parent);
static void AxisMoveNavTimerCb(lv_timer_t * timer);
static void JudgeAxisRangeOut(axis_type_t Axis, float *distance, int direction);
static void show_out_filament_proccess(enum OUT_FILA_PROCCESS out_step);
static void Encoder_timeout_cb(struct _lv_timer_t *timer);


/********axis Move Page***********/
void ui_event_ButtonHomeScreenAxisMove(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        if ( home_printing_is_printing_finished() )
        {
            LoadHomeNormalPageAndObjs(true);
        }
        else
        {
            LoadHomePrintingPageAndObjs(true);
        }
    }
    if(event_code == LV_EVENT_FOCUSED) {  
        if ( home_printing_is_printing_finished() )
        {
            LoadHomeNormalPageAndObjs(false);
            //LoadHomePrintingPageAndObjs(true);
        }
        else
        {
            LoadHomePrintingPageAndObjs(false);
        }
    }
}

void ui_event_ButtonFileManageScreenAxisMove(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        //LoadFileManageScreen();
        LoadFileManageScreenAndObjs(false);
    }
    if(event_code == LV_EVENT_FOCUSED) {  
       // LoadFileManageScreen(); 
        LoadFileManageScreenAndObjs(false);
    }
}

void ui_event_ButtonSettingsScreenAxisMove(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        //LoadSettingsScreen();
        LoadSettingsScreenAndObjs(false, SCREEN_SETTINGS_BUTTON);
    }
    if(event_code == LV_EVENT_FOCUSED) {  
       // LoadSettingsScreen(); 
        LoadSettingsScreenAndObjs(false, SCREEN_SETTINGS_BUTTON);
    }
}

void ui_event_ButtonReserveScreenAxisMove(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        // _ui_screen_change(ui_Cameralist, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        LoadServiceScreenAndObjs(true);
    }
    if(event_code == LV_EVENT_FOCUSED) {  
        //LoadCustomerServiceScreen();   
        LoadServiceScreenAndObjs(false);
    }
}

void ui_event_PanelHotend(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    uint8_t ret = 0;
    int16_t value = 0;
    char value_char[6] = {0};
    ret = EncoderModeChange(encoder_group, e);
    if(ret == 0)
    {//编辑模式
        lv_obj_add_flag(ui_LabelTargetTemperScreenMove, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_LabelEditTemperScreenMove, LV_OBJ_FLAG_HIDDEN);
        value = atoi(lv_label_get_text(ui_LabelTargetTemperScreenMove));
        sprintf(value_char, "%d", value);
        lv_label_set_text(ui_LabelEditTemperScreenMove, value_char);        
    }
    else if(ret == 1)
    {//导航模式
        lv_obj_clear_flag(ui_LabelTargetTemperScreenMove, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_LabelEditTemperScreenMove, LV_OBJ_FLAG_HIDDEN);
        //設置目標溫度
        value = atoi(lv_label_get_text(ui_LabelEditTemperScreenMove));
        lv_label_set_text(ui_LabelTargetTemperScreenMove, lv_label_get_text(ui_LabelEditTemperScreenMove)); 
        send_set_target_temper_cmd(value, true);
    }

    if(event_code == LV_EVENT_DEFOCUSED) {  //
        lv_obj_clear_flag(ui_LabelTargetTemperScreenMove, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_LabelEditTemperScreenMove, LV_OBJ_FLAG_HIDDEN);
    }
 
    EncoderChangeLableValue(ui_LabelEditTemperScreenMove, e, HOTEND_MIN_EDIT_TEMPER, HOTEND_MAX_EDIT_TEMPER);
    if(event_code == LV_EVENT_KEY) {  //
        value = atoi(lv_label_get_text(ui_LabelEditTemperScreenMove));
        if (value < 10)
        {
            lv_obj_align(ui_LabelCurTemperScreenMove, LV_ALIGN_RIGHT_MID, -72, -4);
            lv_obj_align(ui_LabelLeftSlashScreenMove, LV_ALIGN_RIGHT_MID, -59, -6);
        }
        else if (value < 100) {
            lv_obj_align(ui_LabelCurTemperScreenMove, LV_ALIGN_RIGHT_MID, -86, -4);
            lv_obj_align(ui_LabelLeftSlashScreenMove, LV_ALIGN_RIGHT_MID, -73, -6);
        }
        else if (value >= 100) {
            lv_obj_align(ui_LabelCurTemperScreenMove, LV_ALIGN_RIGHT_MID, -99, -4);
            lv_obj_align(ui_LabelLeftSlashScreenMove, LV_ALIGN_RIGHT_MID, -86, -6);
        }
        printf("test..value:%d\n", value);
    }
}

void ui_event_PanelBed(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    uint8_t ret = 0;
    int16_t value = 0;
    char value_char[6] = {0};
    ret = EncoderModeChange(encoder_group, e);
    if(ret == 0)
    {//编辑模式
        lv_obj_add_flag(ui_LabelBedTargetTemperScreenMove, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_LabelBedEditTemperScreenMove, LV_OBJ_FLAG_HIDDEN);
        value = atoi(lv_label_get_text(ui_LabelBedTargetTemperScreenMove));
        sprintf(value_char, "%d", value);
        lv_label_set_text(ui_LabelBedEditTemperScreenMove, value_char);        
    }
    else if(ret == 1)
    {//导航模式
        lv_obj_clear_flag(ui_LabelBedTargetTemperScreenMove, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_LabelBedEditTemperScreenMove, LV_OBJ_FLAG_HIDDEN);
        //設置目標溫度
        value = atoi(lv_label_get_text(ui_LabelBedEditTemperScreenMove));
        lv_label_set_text(ui_LabelBedTargetTemperScreenMove, lv_label_get_text(ui_LabelBedEditTemperScreenMove)); 
        send_set_target_temper_cmd(value, false);
    }

    if(event_code == LV_EVENT_DEFOCUSED) {  //
        lv_obj_clear_flag(ui_LabelBedTargetTemperScreenMove, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_LabelBedEditTemperScreenMove, LV_OBJ_FLAG_HIDDEN);
    }

    EncoderChangeLableValue(ui_LabelBedEditTemperScreenMove, e, BED_MIN_EDIT_TEMPER, BED_MAX_EDIT_TEMPER);
    if(event_code == LV_EVENT_KEY) {  //
        value = atoi(lv_label_get_text(ui_LabelBedEditTemperScreenMove));
        if (value < 10)
        {
            lv_obj_align(ui_LabelBedCurTemperScreenMove, LV_ALIGN_RIGHT_MID, -72, -4);
            lv_obj_align(ui_LabelBedLeftSlashScreenMove, LV_ALIGN_RIGHT_MID, -59, -6);
        }
        else if (value < 100) {
            lv_obj_align(ui_LabelBedCurTemperScreenMove, LV_ALIGN_RIGHT_MID, -86, -4);
            lv_obj_align(ui_LabelBedLeftSlashScreenMove, LV_ALIGN_RIGHT_MID, -73, -6);
        }
        else if (value >= 100) {
            lv_obj_align(ui_LabelBedCurTemperScreenMove, LV_ALIGN_RIGHT_MID, -99, -4);
            lv_obj_align(ui_LabelBedLeftSlashScreenMove, LV_ALIGN_RIGHT_MID, -86, -6);
        }
    }
}

void ui_event_PanelCool(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        MovePageCoolBtnClicked(e);
    }
}

void ui_event_ImgButtonStepperDisable(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        MovePageStepperDisableBtnClicked(e);
    }
}

void ui_event_ExtrudeRetract(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        
        MovePageExtrudeRetractBtnClicked(e);
    }
}

void ui_event_ButtonHomeXYScreenMove(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        MovePageHomeXYBtnClicked(e);
    }
}

void ui_event_ButtonHomeZ(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        //printf("ui_event_ButtonHomeZ\n");
        MovePageHomeZBtnClicked(e);
    }
}

typedef enum {
    ENCODER_LEFT_FAST = 0x11,   
    ENCODER_LEFT_SLOW = 0x10,
    ENCODER_RIGHT_FAST = 0x21,
    ENCODER_RIGHT_SLOW = 0x20
}EncodeDirSpeed_t;

char *AxisMoveEncoderChangeValue(int16_t inValue, uint8_t step, lv_event_t * e, int32_t Min, int32_t Max)
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
        //printf("左旋 快\n"); //设置label的值  
        sprintf(value_char, "%d", (inValue - step) > Min? (inValue - step) : Min);
        break;
    case ENCODER_LEFT_SLOW:
        /* code */
        //printf("左旋 慢\n");
        sprintf(value_char, "%d", (inValue - 1) > Min? (inValue - 1) : Min);
        break;
    case ENCODER_RIGHT_FAST:
        /* code */
        //printf("右旋 快\n");   
        sprintf(value_char, "%d", (inValue + step) < Max ? (inValue + step) : Max);
        break;
    case ENCODER_RIGHT_SLOW:
        /* code */
        //printf("右旋 慢\n");
        sprintf(value_char, "%d", (inValue + 1) < Max ? (inValue + 1) : Max);
        break;    
    default:
        //printf("無效的編碼器命令 %x\n", EncoderCmd);
        break;
    }

    return value_char;
}

///////////////////// FUNCTIONS ////////////////////
// X轴移动设置Label替换--(编辑label和默认面板显示label)
static void ScreenXAxisMoveSet(uint8_t flag, char *val)
{
    if (flag){
        lv_obj_add_flag(ui_XAxisMoveValLabel, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_XAxisMoveValSetLabel, LV_OBJ_FLAG_HIDDEN); 
        lv_label_set_text(ui_XAxisMoveValSetLabel, val);     
    }
    else {
        lv_label_set_text(ui_XAxisMoveValLabel, val);
        //printf("val:%s\n",val);
        lv_obj_clear_flag(ui_XAxisMoveValLabel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_XAxisMoveValSetLabel, LV_OBJ_FLAG_HIDDEN);
    }
}


static int16_t x_pos = 0;
static int16_t x_pre_pos = 0;
uint16_t AxisMoveStateVal = 0;
struct AxisMovePos
{
   // int16_t pos;
    int16_t pre_pos;
    char *value_char;
    bool move_flag; 
};

static struct AxisMovePos XAxisMovePos;
static struct AxisMovePos YAxisMovePos;
static struct AxisMovePos ZAxisMovePos;
void Encoder_timeout_cb(struct _lv_timer_t *timer)
{
    uint8_t direction = 0;
    axis_type_t axis_type;
    int axis_Max = 0;
    // float x_pos_diff = 0;
    // static char value_char[6] = {0};
    //encode_display_timer = NULL;
    uint16_t pos_temp, pos_diff, axis_move_feedrate;
    struct AxisMovePos *AxisMovePosTemp; 
    //发送命令
    // x_pos = atoi(value_char);
    if (AxisMoveStateVal & 0x01)
    {
        AxisMovePosTemp = &XAxisMovePos;
        axis_type = AXIS_X;
        axis_move_feedrate = axis_move_feedrate_xy;
        axis_Max = system_state.X_Axis_Max;
    }
    else if (AxisMoveStateVal & 0x02)
    {
        AxisMovePosTemp = &YAxisMovePos;
        axis_move_feedrate = axis_move_feedrate_xy;
        axis_type = AXIS_Y;
        axis_Max = system_state.Y_Axis_Max;
    }
    else if (AxisMoveStateVal & 0x04)
    {
        AxisMovePosTemp = &ZAxisMovePos;
        axis_move_feedrate = axis_move_feedrate_z;
        axis_type = AXIS_Z;
        axis_Max = system_state.Z_Axis_Max;
    }
   
    if (!AxisMovePosTemp->move_flag)
        return;

    AxisMovePosTemp->move_flag = false;
    pos_temp = atoi(AxisMovePosTemp->value_char);
    if (pos_temp > AxisMovePosTemp->pre_pos)
    {//正方向
        pos_diff = pos_temp - AxisMovePosTemp->pre_pos;
        direction = 1;
        //x_pos_diff = x_pos - x_pre_pos;
        //JudgeAxisRangeOut(AXIS_X, &x_pos_diff, 1);
        send_set_axis_move_opt_cmd(axis_type, 1, pos_diff, axis_move_feedrate);
        CrLogI("Axis:%d direction:%d, step:%f, pos:%d", axis_type, direction, pos_diff, pos_temp);
        if (pos_temp == axis_Max / 100.0f - 1)
        {
            send_set_axis_move_opt_cmd(axis_type, 1, 1, axis_move_feedrate);
            CrLogI("Axis:%d direction:%d, step:%f, pos:%d", axis_type, direction, 1.0, pos_temp);
            create_msgbox(MoveAxisTips2[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
        }
    }
    else if (pos_temp < AxisMovePosTemp->pre_pos)
    {//反方向
        direction = 0;
        //x_pos_diff = x_pre_pos - x_pos;
         pos_diff = AxisMovePosTemp->pre_pos - pos_temp;
        //JudgeAxisRangeOut(AXIS_X, &x_pos_diff, 0);
        send_set_axis_move_opt_cmd(axis_type, 0, pos_diff, axis_move_feedrate);
        CrLogI("Axis:%d direction:%d, step:%f", axis_type, direction, pos_diff);
        if (pos_temp == 0)
        {
            create_msgbox(MoveAxisTips[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
        }
    }
    else
    {
        if (pos_temp == 0)
        {
            create_msgbox(MoveAxisTips[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
        }
        else if (pos_temp == axis_Max / 100 -1)
        {
            create_msgbox(MoveAxisTips2[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
        }
    }
    AxisMovePosTemp->pre_pos = pos_temp;
  //  sprintf(value_char, "%d", x_pos);
    // lv_label_set_text(ui_XAxisMoveValSetLabel, value_char);
}

/**
 * @description: X轴移动事件处理
 * @return {*}
 * @param {lv_event_t *} e
 */
static void ui_event_XAxisMovePanelSet(lv_event_t * e)
{
    uint8_t ret = 0;
    // static uint8_t fanvalue;
    char temp[5] = {0};
    char *value_char;

    float x_pos_diff = 0;
    uint8_t x_direction = 0;
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_SHORT_CLICKED)
    {
        if (!OperableFlag)
        {
            create_msgbox(PrintingTips[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
            return;
        }

        if ( !(home_flag & 0x01)  )
        {
            char buff[80] = {0};
            sprintf(buff, "X%s", NotHomedMsg[get_cur_language_index()]);
            // create_custom_reminderbox(buff, false);
            // set_custom_reminderbox_clickable(false);
            // set_custom_reminderbox_display_timeout(3, NULL);
            create_msgbox(buff, NULL,  1000 * 2, lv_layer_top());
            return ;
        }
    }

    ret = EncoderModeChange(encoder_group, e);
    if(ret == 0) {//编辑模式
        x_pos = x_cur_pos;
        x_pre_pos = x_cur_pos;
        sprintf(temp, "%d", x_cur_pos);
        ScreenXAxisMoveSet(true, temp);
        AxisMoveStateVal = 0x01;
        memset(&XAxisMovePos, 0, sizeof(struct AxisMovePos));
        XAxisMovePos.pre_pos = x_pre_pos;
        lv_timer_resume(encode_display_timer);
    }
    else if(ret == 1) { //导航模式
        sprintf(temp, "%d", x_pos);
        ScreenXAxisMoveSet(false, temp);
        lv_timer_pause(encode_display_timer);
    }

    if(event_code == LV_EVENT_DEFOCUSED) {  //
        sprintf(temp, "%d", x_cur_pos);
        ScreenXAxisMoveSet(false, temp);
        lv_timer_pause(encode_display_timer);
    }
 
    value_char = AxisMoveEncoderChangeValue(x_pos, 20, e, 0, system_state.X_Axis_Max / 100.0f - 1);
    if (value_char != NULL)
    {
        //启动定时器
        XAxisMovePos.value_char = value_char;
        XAxisMovePos.move_flag = true;
        x_pos = atoi(XAxisMovePos.value_char);
        //启动定时器
        lv_timer_reset(encode_display_timer);
        lv_label_set_text(ui_XAxisMoveValSetLabel, XAxisMovePos.value_char);
    }
}

///////////////////// FUNCTIONS ////////////////////
// X轴移动设置Label替换--(编辑label和默认面板显示label)
static void ScreenYAxisMoveSet(uint8_t flag, char *val)
{
    if (flag){
        lv_obj_add_flag(ui_YAxisMoveValLabel, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_YAxisMoveValSetLabel, LV_OBJ_FLAG_HIDDEN);    
        lv_label_set_text(ui_YAxisMoveValSetLabel, val);      
    }
    else {
        lv_label_set_text(ui_YAxisMoveValLabel, val);
        //printf("val:%s\n",val);
        lv_obj_clear_flag(ui_YAxisMoveValLabel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_YAxisMoveValSetLabel, LV_OBJ_FLAG_HIDDEN);
    }
}
/**
 * @description: Y轴移动事件处理
 * @return {*}
 * @param {lv_event_t *} e
 */
  
static void ui_event_YAxisMovePanelSet(lv_event_t * e)
{
    uint8_t ret = 0;
    // static uint8_t fanvalue;
    char temp[5] = {0};
    char *value_char;
    static int16_t y_pos = 0;
    static int16_t y_pre_pos = 0;
    float y_pos_diff = 0;
    uint8_t y_direction = 0;
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_SHORT_CLICKED)
    {
        if (!OperableFlag)
        {
            create_msgbox(PrintingTips[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
            return;
        }

        if ( !(home_flag & 0x02)  )
        {
            char buff[80] = {0};
            sprintf(buff, "Y%s", NotHomedMsg[get_cur_language_index()]);
            // create_custom_reminderbox(buff, false);
            // set_custom_reminderbox_clickable(false);
            // set_custom_reminderbox_display_timeout(3, NULL);
            create_msgbox(buff, NULL,  1000 * 2, lv_layer_top());
            return ;
        }
    }
    
    ret = EncoderModeChange(encoder_group, e);
    if(ret == 0) {//编辑模式
        y_pos = y_cur_pos;
        y_pre_pos = y_cur_pos;
        sprintf(temp, "%d", y_cur_pos);
        ScreenYAxisMoveSet(true, temp);
        AxisMoveStateVal = 0x02;
        memset(&YAxisMovePos, 0, sizeof(struct AxisMovePos));
        YAxisMovePos.pre_pos = y_pre_pos;
        lv_timer_resume(encode_display_timer);
    }
    else if(ret == 1) { //导航模式
        sprintf(temp, "%d", y_pos);
        ScreenYAxisMoveSet(false, temp);
        lv_timer_pause(encode_display_timer);
    }

    if(event_code == LV_EVENT_DEFOCUSED) {  //
        sprintf(temp, "%d", y_cur_pos);
        ScreenYAxisMoveSet(false, temp);
        lv_timer_pause(encode_display_timer);
    }
  
    value_char = AxisMoveEncoderChangeValue(y_pos, 20, e, 0, system_state.Y_Axis_Max / 100.0f - 1);
    if (value_char != NULL)
    {        
        //启动定时器
        YAxisMovePos.value_char = value_char;
        YAxisMovePos.move_flag = true;
        y_pos = atoi(YAxisMovePos.value_char);
        //启动定时器
        lv_timer_reset(encode_display_timer);
        lv_label_set_text(ui_YAxisMoveValSetLabel, YAxisMovePos.value_char);
    }
    if (event_code == LV_EVENT_FOCUSED)
    {
        lv_obj_scroll_to_y(ui_PanelCtrlList, 100 , true);
    }

}

///////////////////// FUNCTIONS ////////////////////
// X轴移动设置Label替换--(编辑label和默认面板显示label)
static void ScreenZAxisMoveSet(uint8_t flag, char *val)
{
    if (flag){
        lv_obj_add_flag(ui_ZAxisMoveValLabel, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_ZAxisMoveValSetLabel, LV_OBJ_FLAG_HIDDEN);   
        lv_label_set_text(ui_ZAxisMoveValSetLabel, val);     
    }
    else {
        lv_label_set_text(ui_ZAxisMoveValLabel, val);
        //printf("val:%s\n",val);
        lv_obj_clear_flag(ui_ZAxisMoveValLabel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_ZAxisMoveValSetLabel, LV_OBJ_FLAG_HIDDEN);
    }
}
/**
 * @description: Z轴移动事件处理
 * @return {*}
 * @param {lv_event_t *} e
 */
  
static void ui_event_ZAxisMovePanelSet(lv_event_t * e)
{
    uint8_t ret = 0;
    // static uint8_t fanvalue;
    char temp[5] = {0};
    char *value_char;
    static int16_t z_pos = 0;
    static int16_t z_pre_pos = 0;
    float z_pos_diff = 0;
    uint8_t z_direction = 0;
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_SHORT_CLICKED)
    {
        if (!OperableFlag)
        {
            create_msgbox(PrintingTips[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
            return;
        }

        if ( !(home_flag & 0x04)  )
        {
            char buff[80] = {0};
            sprintf(buff, "Z%s", NotHomedMsg[get_cur_language_index()]);
            // create_custom_reminderbox(buff, false);
            // set_custom_reminderbox_clickable(false);
            // set_custom_reminderbox_display_timeout(3, NULL);
            create_msgbox(buff, NULL,  1000 * 2, lv_layer_top());
            return ;
        }
    }

    ret = EncoderModeChange(encoder_group, e);
    if(ret == 0) {//编辑模式
        z_pos = z_cur_pos;
        z_pre_pos = z_cur_pos;
        sprintf(temp, "%d", z_cur_pos);
        ScreenZAxisMoveSet(true, temp);
        AxisMoveStateVal = 0x04;
        memset(&ZAxisMovePos, 0, sizeof(struct AxisMovePos));
        ZAxisMovePos.pre_pos = z_pre_pos;
        lv_timer_resume(encode_display_timer);
    }
    else if(ret == 1) { //导航模式
        sprintf(temp, "%d", z_pos);
        ScreenZAxisMoveSet(false, temp);
        lv_timer_pause(encode_display_timer);
    }

    if(event_code == LV_EVENT_DEFOCUSED) {  //
        sprintf(temp, "%d", z_cur_pos);
        ScreenZAxisMoveSet(false, temp);
        lv_timer_pause(encode_display_timer);
    }
 
    value_char = AxisMoveEncoderChangeValue(z_pos, 20, e, 0, system_state.Z_Axis_Max / 100.0f - 1);
    if (value_char != NULL)
    {
        //启动定时器
        ZAxisMovePos.value_char = value_char;
        ZAxisMovePos.move_flag = true;
        z_pos = atoi(ZAxisMovePos.value_char);
        //启动定时器
        lv_timer_reset(encode_display_timer);
        lv_label_set_text(ui_ZAxisMoveValSetLabel, ZAxisMovePos.value_char);
    }

}

static void ui_event_FanPanelSet(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        if (lv_scr_act() == ui_ScreenAxisMovePage)
        {
            lv_obj_add_flag(ui_PanelMoveAndTemper, LV_OBJ_FLAG_HIDDEN);
        }
        //lv_obj_clear_flag(ui_PanelExtrudeRetract, LV_OBJ_FLAG_HIDDEN);
        ShowCoolSubPage(ui_ScreenAxisMovePage);
        add_3rd_level_nav_objs = AddFanCtrlNavObjs;
        LoadPage(ui_ScreenAxisMovePage, 3);
    }
}

///////////////////// FUNCTIONS ////////////////////
// 风扇速度设置Label替换--(编辑label和默认面板显示label)
static void ScreenModelFanSet(uint8_t flag, char *val)
{
    if (flag){
        lv_obj_add_flag(ui_ModelFanValLabel, LV_OBJ_FLAG_HIDDEN); //设置亮度时隐藏掉默认显示的label
        lv_obj_clear_flag(ui_ModelFanValSetLabel, LV_OBJ_FLAG_HIDDEN);      
    }
    else {
        lv_label_set_text(ui_ModelFanValLabel, val);
        //printf("val:%s\n",val);
        lv_obj_clear_flag(ui_ModelFanValLabel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_ModelFanValSetLabel, LV_OBJ_FLAG_HIDDEN);
    }
}
/**
 * @description: 风扇速度事件处理
 * @return {*}
 * @param {lv_event_t *} e
 */
static void ui_event_ModelFanPanelSet(lv_event_t * e)
{
    uint8_t ret = 0;
    //static uint8_t fanvalue;
    static uint8_t percent = 0;
    // uint8_t set_percent = 0;
    char temp[5] = {0};
    char *value_char;
    lv_event_code_t event_code = lv_event_get_code(e);
    
    ret = EncoderModeChange(encoder_group, e);
    if(ret == 0) {//编辑模式
        ScreenModelFanSet(true, NULL);
        percent = atoi(lv_label_get_text(ui_ModelFanValSetLabel));
    }
    else if(ret == 1) { //导航模式
        sprintf(temp, "%d%%", percent);
        ScreenModelFanSet(false, temp);
    }

    if(event_code == LV_EVENT_DEFOCUSED) {  //
        percent = atoi(lv_label_get_text(ui_ModelFanValLabel));
        sprintf(temp, "%d%%", percent);
        ScreenModelFanSet(false, temp);
    }

    //EncoderChangeLableValue(ui_ModelFanValSetLabel, e, 0, 100);

    value_char = EncoderChangeValue(percent, 10, e, 0, 100);
    if (value_char != NULL)
    {
#ifdef FAN_CONTROL_A
        percent = atoi(value_char);

        if (0 == percent)
        {
            set_percent = percent;
        }
        else if (1 == percent)
        {
            set_percent = FanMinDutyValue + 1;
        }
        else
        {
            set_percent = (double)percent * (100.0 - FanMinDutyValue) / 100.0 + FanMinDutyValue;  
        }

        printf("percent %d, set_percent %d\n", percent, set_percent);
        send_set_model_fan_opt_cmd(set_percent);   

        strcat(value_char, "%");  

        lv_label_set_text(ui_ModelFanValLabel, value_char);
        lv_label_set_text(ui_ModelFanValSetLabel, value_char);
#else
        if (0 == percent && atoi(value_char) > percent)
        {
            percent = FanMinDutyValue;
            send_set_model_fan_opt_cmd(FanMinDutyValue);
            char buff[5] = {0};
            sprintf(buff, "%d%%", percent); 
            lv_label_set_text(ui_ModelFanValLabel, buff);
            lv_label_set_text(ui_ModelFanValSetLabel, buff);
        }
        else
        {
            percent = atoi(value_char);
            send_set_model_fan_opt_cmd(atoi(value_char));   

            strcat(value_char, "%");  

            lv_label_set_text(ui_ModelFanValLabel, value_char);
            lv_label_set_text(ui_ModelFanValSetLabel, value_char);
        }
        
#endif
        

    }

}

static void ui_event_AuxiliaryFanPanelSet(lv_event_t * e)
{

}

//进退料返回按钮回调
static void ui_event_ExtrudeRetractBackBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        printf("ui_event_ExtrudeRetractBackBtn\n");
        if (lv_scr_act() == ui_ScreenAxisMovePage)
        {
            BackPrepage(false);
            lv_obj_clear_flag(ui_PanelMoveAndTemper, LV_OBJ_FLAG_HIDDEN); 
            lv_obj_add_flag(ui_PanelExtrudeRetract, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {
            BackPrepage(false);
            lv_obj_add_flag(ui_PanelExtrudeRetract, LV_OBJ_FLAG_HIDDEN);
        }
        
    }
}

//普通温度面板回调
static void ui_event_PanelHotendTemp(lv_event_t * e)
{
    // lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    uint8_t ret = 0;
    // int16_t value = 0;
    // char value_char[6] = {0};
    lv_event_code_t event_code = lv_event_get_code(e);
    
    ret = EncoderModeChange(encoder_group, e);
    if(ret == 0)
    {//编辑模式
        lv_obj_set_style_bg_opa(ui_LableHotendTemp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);    
    }
    else if(ret == 1)
    {//导航模式
        lv_obj_set_style_bg_opa(ui_LableHotendTemp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        //设置目标温度
        lv_obj_set_style_bg_opa(ui_LableHotendTemp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        ExtrudeRetractTargetTemper = atoi(lv_label_get_text(ui_LableHotendTemp));
    }

    if(event_code == LV_EVENT_DEFOCUSED) {  //
        lv_obj_set_style_bg_opa(ui_LableHotendTemp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        //设置目标温度
        lv_obj_set_style_bg_opa(ui_LableHotendTemp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        ExtrudeRetractTargetTemper = atoi(lv_label_get_text(ui_LableHotendTemp));
    }

    EncoderChangeLableValue(ui_LableHotendTemp, e, 180, 300);
    if(event_code == LV_EVENT_KEY)
    {
        char buf[256] = {0};
        sprintf(buf, HotTips[get_cur_language_index()], atoi(lv_label_get_text(ui_LableHotendTemp)));
        lv_label_set_text(ui_LableTipInfoContent, buf);
    }
}

//进料按钮回调
static void ui_event_ExtrudeBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        printf("ui_event_ExtrudeBtn\n");
        show_proccess_panel(PROMPT_STATE_EXTRUDE_POCCESS);
        
        filament_action = FILA_ACTION_IN;
        filament_action_step_order = 0;
        CrLogI("extrude filament,the last targettemp is:%d",ExtrudeRetractTargetTemper);
        char buff[30] = {0};
        snprintf(buff, 30, "1%d", ExtrudeRetractTargetTemper);
        set_printer_data(0x08, strlen(buff), buff);
    }

}

//退料按钮回调
static void ui_event_RetractBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_SHORT_CLICKED) {
        // ShowPanelHotendState(HOTEND_STATE_HEATING);
        // ShowPanelProcessState(PROMPT_STATE_RETRACT_POCCESS);

        show_proccess_panel(PROMPT_STATE_RETRACT_POCCESS);
        // if ( edit_target_temper < FILAMENT_COOL_EXTRUDE_TEMPER )
        //     edit_target_temper = FILAMENT_COOL_EXTRUDE_TEMPER;
        
        filament_action = FILA_ACTION_OUT;
        filament_action_step_order = 0;
        // send_set_target_temper_cmd(edit_target_temper, true);
        // show_out_filament_proccess(OUT_FILAMENT_FIRST_STEP);
        // targettemp = atoi(hotend_max_temp);

        CrLogI("retract filament,the last targettemp is:%d",ExtrudeRetractTargetTemper);
        char buff[30] = {0};
        snprintf(buff, 30, "2%d", ExtrudeRetractTargetTemper);
        set_printer_data(0x08, strlen(buff), buff);
    }

}

/**
 * @description: 控制页总回调接口
 * @return {*}
 * @param {lv_event_t *} e
 */
void ui_event_CtrlItem(lv_event_t * e)
{
    // lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    ctrl_list_t *part = lv_event_get_user_data(e);

    if (!part) return;
    //printf("part->index :%d\n", part->index);
    //SettingsItemIndex = part->index;
    switch (part->index) //填上对应的之前的事件回调函数
    {
    case 1: //喷嘴温度
        ui_event_PanelHotend(e);
        break;
    case 2: //热床温度
        ui_event_PanelBed(e);
        break;
    case 3: //XY轴归位
        ui_event_ButtonHomeXYScreenMove(e);
        break;
    case 4: //Z轴归位
        ui_event_ButtonHomeZ(e);
        break;
    case 5: //X轴移动
        ui_event_XAxisMovePanelSet(e);
        break;
    case 6: //Y轴移动
        ui_event_YAxisMovePanelSet(e);
        break;
    case 7: //Z轴移动
        ui_event_ZAxisMovePanelSet(e);
        break;
    case 8: //关闭电机
        ui_event_ImgButtonStepperDisable(e);
        break;
    case 9: //进退料
        ui_event_ExtrudeRetract(e);
        break;
    case 10: //模型风扇
        //ui_event_ModelFanPanelSet(e);
        ui_event_FanPanelSet(e);
        break;
    default:
        break;
    }
}

void ui_event_FanCtrlItem(lv_event_t * e)
{
    // lv_event_code_t event_code = lv_event_get_code(e);
    // lv_obj_t * target = lv_event_get_target(e);
    ctrl_list_t *part = lv_event_get_user_data(e);

    if (!part) return;
    //printf("part->index :%d\n", part->index);
    //SettingsItemIndex = part->index;
    switch (part->index) //填上对应的之前的事件回调函数
    {
    case 1:  //模型风扇
        ui_event_ModelFanPanelSet(e);
        break;
    case 2:  //模型风扇
        ui_event_AuxiliaryFanPanelSet(e);
        break;
    default:
        break;
    }
}

//喷嘴温度菜单初始化, 图片，名字，当前温度，‘/’，目标温度，℃
void ScreenHotendTempStyleInit(ctrl_list_t *part, const char *item_name)
{
    if (!part || !item_name)
        return;
    lv_label_set_text(part->label_item_name, item_name);
    lv_img_set_src(part->image_item, &ui_img_hotend_ctrl_png);

    LableHotendTemp = part->label_item_name;

    // ℃
    ui_LabelTemperUnitScreenMove = lv_label_create(part->part_panel);
    lv_obj_set_size(ui_LabelTemperUnitScreenMove, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_LabelTemperUnitScreenMove, LV_ALIGN_RIGHT_MID, -13, -4);
    lv_label_set_text(ui_LabelTemperUnitScreenMove, "°C");
    lv_obj_set_style_text_color(ui_LabelTemperUnitScreenMove, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTemperUnitScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTemperUnitScreenMove, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTemperUnitScreenMove, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //目标温度
    ui_LabelTargetTemperScreenMove = lv_label_create(part->part_panel);
    lv_obj_set_size(ui_LabelTargetTemperScreenMove, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_align_to(ui_LabelTargetTemperScreenMove, ui_LabelTemperUnitScreenMove, LV_ALIGN_OUT_LEFT_MID, 0, 0);
    lv_obj_align(ui_LabelTargetTemperScreenMove, LV_ALIGN_RIGHT_MID, -42, -4);
    lv_label_set_text(ui_LabelTargetTemperScreenMove, "220");
    lv_obj_set_style_text_color(ui_LabelTargetTemperScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTargetTemperScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTargetTemperScreenMove, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTargetTemperScreenMove, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //'/'
    ui_LabelLeftSlashScreenMove = lv_label_create(part->part_panel);
    lv_obj_set_size(ui_LabelLeftSlashScreenMove, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    // lv_obj_align_to(ui_LabelLeftSlashScreenMove, ui_LabelEditTemperScreenMove, LV_ALIGN_OUT_LEFT_MID, 0, 0);
    lv_obj_align(ui_LabelLeftSlashScreenMove, LV_ALIGN_RIGHT_MID, -80, -6);
    lv_label_set_text(ui_LabelLeftSlashScreenMove, "/");
    lv_obj_set_style_text_color(ui_LabelLeftSlashScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelLeftSlashScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelLeftSlashScreenMove, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelLeftSlashScreenMove, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //当前温度
    ui_LabelCurTemperScreenMove = lv_label_create(part->part_panel);
    lv_obj_set_size(ui_LabelCurTemperScreenMove, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_align_to(ui_LabelCurTemperScreenMove, ui_LabelLeftSlashScreenMove, LV_ALIGN_OUT_LEFT_MID, 0, 8);
    lv_obj_align(ui_LabelCurTemperScreenMove, LV_ALIGN_RIGHT_MID, -90, -4);
    lv_label_set_text(ui_LabelCurTemperScreenMove, "220");
    lv_obj_set_style_text_color(ui_LabelCurTemperScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelCurTemperScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelCurTemperScreenMove, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelCurTemperScreenMove, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //设置温度
    ui_LabelEditTemperScreenMove = lv_label_create(part->part_panel);
    lv_obj_add_flag(ui_LabelEditTemperScreenMove, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_size(ui_LabelEditTemperScreenMove, LV_SIZE_CONTENT, 48);
    //lv_obj_align_to(ui_LabelEditTemperScreenMove, ui_LabelLeftSlashScreenMove, LV_ALIGN_OUT_RIGHT_MID, 0, 8);
    lv_obj_align(ui_LabelEditTemperScreenMove, LV_ALIGN_RIGHT_MID, -40, 0);
    lv_label_set_text(ui_LabelEditTemperScreenMove, "220");
    lv_obj_set_style_bg_color(ui_LabelEditTemperScreenMove, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LabelEditTemperScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_LabelEditTemperScreenMove, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LabelEditTemperScreenMove, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelEditTemperScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelEditTemperScreenMove, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelEditTemperScreenMove, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

}

void ScreenBedTempStyleInit(ctrl_list_t *part, const char *item_name)
{
    if (!part || !item_name)
        return;
    lv_label_set_text(part->label_item_name, item_name);
    lv_img_set_src(part->image_item, &ui_img_bed_ctrl_png);

    LableBedTemp = part->label_item_name;

    // ℃
    ui_LabelBedTemperUnitScreenMove = lv_label_create(part->part_panel);
    lv_obj_set_size(ui_LabelBedTemperUnitScreenMove, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_LabelBedTemperUnitScreenMove, LV_ALIGN_RIGHT_MID, -13, -4);
    lv_label_set_text(ui_LabelBedTemperUnitScreenMove, "°C");
    lv_obj_set_style_text_color(ui_LabelBedTemperUnitScreenMove, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedTemperUnitScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedTemperUnitScreenMove, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedTemperUnitScreenMove, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //目标温度
    ui_LabelBedTargetTemperScreenMove = lv_label_create(part->part_panel);
    lv_obj_set_size(ui_LabelBedTargetTemperScreenMove, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_align_to(ui_LabelTargetTemperScreenMove, ui_LabelTemperUnitScreenMove, LV_ALIGN_OUT_LEFT_MID, 0, 0);
    lv_obj_align(ui_LabelBedTargetTemperScreenMove, LV_ALIGN_RIGHT_MID, -42, -4);
    lv_label_set_text(ui_LabelBedTargetTemperScreenMove, "220");
    lv_obj_set_style_text_color(ui_LabelBedTargetTemperScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedTargetTemperScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedTargetTemperScreenMove, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedTargetTemperScreenMove, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //'/'
    ui_LabelBedLeftSlashScreenMove = lv_label_create(part->part_panel);
    lv_obj_set_size(ui_LabelBedLeftSlashScreenMove, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_align_to(ui_LabelLeftSlashScreenMove, ui_LabelTargetTemperScreenMove, LV_ALIGN_OUT_LEFT_MID, 0, -5);
    lv_obj_align(ui_LabelBedLeftSlashScreenMove, LV_ALIGN_RIGHT_MID, -80, -6);
    lv_label_set_text(ui_LabelBedLeftSlashScreenMove, "/");
    lv_obj_set_style_text_color(ui_LabelBedLeftSlashScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedLeftSlashScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedLeftSlashScreenMove, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedLeftSlashScreenMove, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //当前温度
    ui_LabelBedCurTemperScreenMove = lv_label_create(part->part_panel);
    lv_obj_set_size(ui_LabelBedCurTemperScreenMove, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_align_to(ui_LabelCurTemperScreenMove, ui_LabelLeftSlashScreenMove, LV_ALIGN_OUT_LEFT_MID, 0, 8);
    lv_obj_align(ui_LabelBedCurTemperScreenMove, LV_ALIGN_RIGHT_MID, -90, -4);
    lv_label_set_text(ui_LabelBedCurTemperScreenMove, "220");
    lv_obj_set_style_text_color(ui_LabelBedCurTemperScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedCurTemperScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedCurTemperScreenMove, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedCurTemperScreenMove, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //设置温度
    ui_LabelBedEditTemperScreenMove = lv_label_create(part->part_panel);
    lv_obj_add_flag(ui_LabelBedEditTemperScreenMove, LV_OBJ_FLAG_HIDDEN);
    lv_obj_set_size(ui_LabelBedEditTemperScreenMove, LV_SIZE_CONTENT, 48);
    //lv_obj_align_to(ui_LabelBedEditTemperScreenMove, ui_LabelLeftSlashScreenMove, LV_ALIGN_OUT_RIGHT_MID, 0, 8);
    lv_obj_align(ui_LabelBedEditTemperScreenMove, LV_ALIGN_RIGHT_MID, -40, 0);
    lv_label_set_text(ui_LabelBedEditTemperScreenMove, "220");
    lv_obj_set_style_bg_color(ui_LabelBedEditTemperScreenMove, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LabelBedEditTemperScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_LabelBedEditTemperScreenMove, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LabelBedEditTemperScreenMove, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedEditTemperScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedEditTemperScreenMove, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedEditTemperScreenMove, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);

}

void ScreenHomeXYStyleInit(ctrl_list_t *part, const char *item_name)
{
    if (!part || !item_name)
        return;
    lv_label_set_text(part->label_item_name, item_name);
    lv_img_set_src(part->image_item, &ui_img_homexy_png);

    LableHomeXY = part->label_item_name;

    // //右箭头图
    // lv_obj_t *ui_ImageArrow = lv_img_create(part->part_panel);
    // lv_img_set_src(ui_ImageArrow, &ui_img_rightarrow_png);
    // lv_obj_set_width(ui_ImageArrow, 11);  //11 LV_SIZE_CONTENT
    // lv_obj_set_height(ui_ImageArrow, 21);    
    // lv_obj_align(ui_ImageArrow, LV_ALIGN_RIGHT_MID, -20, 0);
    // lv_obj_add_flag(ui_ImageArrow, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_ImageArrow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
}

void ScreenHomeZStyleInit(ctrl_list_t *part, const char *item_name)
{
    if (!part || !item_name)
        return;
    lv_label_set_text(part->label_item_name, item_name);
    lv_img_set_src(part->image_item, &ui_img_homez_png);

    LableHomeZ = part->label_item_name;

    // //右箭头图
    // lv_obj_t *ui_ImageArrow = lv_img_create(part->part_panel);
    // lv_img_set_src(ui_ImageArrow, &ui_img_rightarrow_png);
    // lv_obj_set_width(ui_ImageArrow, 11);  //11 LV_SIZE_CONTENT
    // lv_obj_set_height(ui_ImageArrow, 21);    
    // lv_obj_align(ui_ImageArrow, LV_ALIGN_RIGHT_MID, -20, 0);
    // lv_obj_add_flag(ui_ImageArrow, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_ImageArrow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
}

void ScreenXAxisMoveStyleInit(ctrl_list_t *part, const char *item_name)
{
    if (!part || !item_name)
        return;
    lv_label_set_text(part->label_item_name, item_name);
    lv_img_set_src(part->image_item, &ui_img_movex_png);

    LableXAxisMove = part->label_item_name;

    //增加label, 显示X轴的坐标范围，例如 [0~200]
    ui_XAxisMovePanel = part->part_panel;
    ui_XAxisMoveLabel = part->label_item_name;
    ui_XAxisMoveValLabel = lv_label_create(ui_XAxisMovePanel);
    lv_obj_set_width(ui_XAxisMoveValLabel, 60); //LV_SIZE_CONTENT
    lv_obj_set_height(ui_XAxisMoveValLabel, LV_SIZE_CONTENT); 
    lv_obj_align(ui_XAxisMoveValLabel, LV_ALIGN_RIGHT_MID, -2, 0);
    lv_label_set_text(ui_XAxisMoveValLabel,"0"); //
    //lv_obj_set_flex_align(ui_XAxisMoveValLabel, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    //lv_obj_set_style_bg_color(ui_XAxisMoveValLabel, lv_color_hex(0xC2F4FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_opa(ui_XAxisMoveValLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_XAxisMoveValLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_XAxisMoveValLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_XAxisMoveValLabel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_XAxisMoveValLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_XAxisMoveValLabel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    
    ui_XAxisMoveValSetLabel = lv_label_create(ui_XAxisMovePanel);
    lv_obj_set_width(ui_XAxisMoveValSetLabel, 60); //LV_SIZE_CONTENT
    lv_obj_set_height(ui_XAxisMoveValSetLabel, 48); 
    lv_obj_align(ui_XAxisMoveValSetLabel, LV_ALIGN_RIGHT_MID, -2, 0);
    lv_label_set_text(ui_XAxisMoveValSetLabel,"0"); //
    //lv_obj_set_flex_align(ui_XAxisMoveValSetLabel, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_XAxisMoveValSetLabel, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_XAxisMoveValSetLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_XAxisMoveValSetLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_XAxisMoveValSetLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_XAxisMoveValSetLabel, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_XAxisMoveValSetLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_XAxisMoveValSetLabel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_XAxisMoveValSetLabel, LV_OBJ_FLAG_HIDDEN);
    //增加lable，显示当前X轴坐标
}

void ScreenYAxisMoveStyleInit(ctrl_list_t *part, const char *item_name)
{
    if (!part || !item_name)
        return;
    lv_label_set_text(part->label_item_name, item_name);
    lv_img_set_src(part->image_item, &ui_img_movey_png);

    LableYAxisMove = part->label_item_name;

    //增加label, 显示Y轴的坐标范围，例如 [0~200]
    ui_YAxisMovePanel = part->part_panel;
    ui_YAxisMoveLabel = part->label_item_name;
    ui_YAxisMoveValLabel = lv_label_create(ui_YAxisMovePanel);
    lv_obj_set_width(ui_YAxisMoveValLabel, 60); //LV_SIZE_CONTENT
    lv_obj_set_height(ui_YAxisMoveValLabel, LV_SIZE_CONTENT); 
    lv_obj_align(ui_YAxisMoveValLabel, LV_ALIGN_RIGHT_MID, -2, 0);
    lv_label_set_text(ui_YAxisMoveValLabel,"0"); //
    //lv_obj_set_flex_align(ui_YAxisMoveValLabel, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    //lv_obj_set_style_bg_color(ui_YAxisMoveValLabel, lv_color_hex(0xC2F4FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_opa(ui_YAxisMoveValLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_YAxisMoveValLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_YAxisMoveValLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_YAxisMoveValLabel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_YAxisMoveValLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_YAxisMoveValLabel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    
    ui_YAxisMoveValSetLabel = lv_label_create(ui_YAxisMovePanel);
    lv_obj_set_width(ui_YAxisMoveValSetLabel, 60); //LV_SIZE_CONTENT
    lv_obj_set_height(ui_YAxisMoveValSetLabel, 48); 
    lv_obj_align(ui_YAxisMoveValSetLabel, LV_ALIGN_RIGHT_MID, -2, 0);
    lv_label_set_text(ui_YAxisMoveValSetLabel,"0.00"); //
   // lv_obj_set_flex_align(ui_YAxisMoveValSetLabel, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_YAxisMoveValSetLabel, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_YAxisMoveValSetLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_YAxisMoveValSetLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_YAxisMoveValSetLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_YAxisMoveValSetLabel, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_YAxisMoveValSetLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_YAxisMoveValSetLabel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_YAxisMoveValSetLabel, LV_OBJ_FLAG_HIDDEN);
    //增加lable，显示当前X轴坐标
}

void ScreenZAxisMoveStyleInit(ctrl_list_t *part, const char *item_name)
{
    if (!part || !item_name)
        return;
    lv_label_set_text(part->label_item_name, item_name);
    lv_img_set_src(part->image_item, &ui_img_movez_png);
    LableZAxisMove = part->label_item_name;

    //增加label, 显示X轴的坐标范围，例如 [0~200]
    ui_ZAxisMovePanel = part->part_panel;
    ui_ZAxisMoveLabel = part->label_item_name;
    ui_ZAxisMoveValLabel = lv_label_create(ui_ZAxisMovePanel);
    lv_obj_set_width(ui_ZAxisMoveValLabel, 60); //LV_SIZE_CONTENT
    lv_obj_set_height(ui_ZAxisMoveValLabel, LV_SIZE_CONTENT); 
    lv_obj_align(ui_ZAxisMoveValLabel, LV_ALIGN_RIGHT_MID, -2, 0);
    lv_label_set_text(ui_ZAxisMoveValLabel,"0"); //
    //lv_obj_set_flex_align(ui_ZAxisMoveValLabel, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    //lv_obj_set_style_bg_color(ui_ZAxisMoveValLabel, lv_color_hex(0xC2F4FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_opa(ui_ZAxisMoveValLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ZAxisMoveValLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ZAxisMoveValLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ZAxisMoveValLabel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ZAxisMoveValLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ZAxisMoveValLabel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_ZAxisMoveValSetLabel = lv_label_create(ui_ZAxisMovePanel);
    lv_obj_set_width(ui_ZAxisMoveValSetLabel, 60); //LV_SIZE_CONTENT
    lv_obj_set_height(ui_ZAxisMoveValSetLabel, 48); 
    lv_obj_align(ui_ZAxisMoveValSetLabel, LV_ALIGN_RIGHT_MID, -2, 0);
    lv_label_set_text(ui_ZAxisMoveValSetLabel,"0.00"); //
   // lv_obj_set_flex_align(ui_ZAxisMoveValSetLabel, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_ZAxisMoveValSetLabel, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ZAxisMoveValSetLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ZAxisMoveValSetLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ZAxisMoveValSetLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ZAxisMoveValSetLabel, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ZAxisMoveValSetLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ZAxisMoveValSetLabel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_ZAxisMoveValSetLabel, LV_OBJ_FLAG_HIDDEN);
    //增加lable，显示当前X轴坐标
}

void ScreenTurnOffTheMotorStyleInit(ctrl_list_t *part, const char *item_name)
{
    if (!part || !item_name)
        return;
    lv_label_set_text(part->label_item_name, item_name);
    lv_img_set_src(part->image_item, &ui_img_close_motor_png);
    LableTurnOffTheMotor = part->label_item_name;

    // //右箭头图
    // lv_obj_t *ui_ImageArrow = lv_img_create(part->part_panel);
    // lv_img_set_src(ui_ImageArrow, &ui_img_rightarrow_png);
    // lv_obj_set_width(ui_ImageArrow, 11);  //11 LV_SIZE_CONTENT
    // lv_obj_set_height(ui_ImageArrow, 21);    
    // lv_obj_align(ui_ImageArrow, LV_ALIGN_RIGHT_MID, -20, 0);
    // lv_obj_add_flag(ui_ImageArrow, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_ImageArrow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
}

void ScreenInOrOutMaterialStyleInit(ctrl_list_t *part, const char *item_name)
{
    if (!part || !item_name)
        return;
    lv_label_set_text(part->label_item_name, item_name);
    lv_img_set_src(part->image_item, &ui_img_in_out_material_png);
    LableInOrOutMaterial = part->label_item_name;

    //右箭头图
    lv_obj_t *ui_ImageArrow = lv_img_create(part->part_panel);
    lv_img_set_src(ui_ImageArrow, &ui_img_rightarrow_png);
    lv_obj_set_width(ui_ImageArrow, 11);  //11 LV_SIZE_CONTENT
    lv_obj_set_height(ui_ImageArrow, 21);    
    lv_obj_align(ui_ImageArrow, LV_ALIGN_RIGHT_MID, -20, 0);
    lv_obj_add_flag(ui_ImageArrow, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageArrow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
}

void ScreenFanStyleInit(ctrl_list_t *part, const char *item_name)
{
    // char buf[5] = {0};
    if (!part || !item_name)
        return; 
    lv_label_set_text(part->label_item_name, item_name);
    lv_img_set_src(part->image_item, &ui_img_model_fan_ctrl_png);

    LableFan = part->label_item_name;
    
    //右箭头图
    lv_obj_t *ui_ImageArrow = lv_img_create(part->part_panel);
    lv_img_set_src(ui_ImageArrow, &ui_img_rightarrow_png);
    lv_obj_set_width(ui_ImageArrow, 11);  //11 LV_SIZE_CONTENT
    lv_obj_set_height(ui_ImageArrow, 21);    
    lv_obj_align(ui_ImageArrow, LV_ALIGN_RIGHT_MID, -20, 0);
    lv_obj_add_flag(ui_ImageArrow, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageArrow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

}

void ScreenModelFanStyleInit(ctrl_list_t *part, const char *item_name)
{
    // char buf[5] = {0};
    if (!part || !item_name)
        return; 
    lv_label_set_text(part->label_item_name, item_name);
    lv_img_set_src(part->image_item, &ui_img_model_fan_ctrl_png);

    LableModelFan = part->label_item_name;
    
    ui_ModelFanPanel = part->part_panel;
    ui_ModelFanLabel = part->label_item_name;
    // ui_ModelFanValLabel = part->label_content_name;  
    // lv_obj_align(ui_ModelFanValLabel, LV_ALIGN_RIGHT_MID, -20, 1);
    
    //lv_obj_add_flag(part->img_arrow_png, LV_OBJ_FLAG_HIDDEN);

    
    //lv_obj_set_style_bg_color(ui_ModelFanPanel, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ModelFanValLabel = lv_label_create(part->part_panel);
    lv_obj_set_width(ui_ModelFanValLabel, 80); //LV_SIZE_CONTENT
    lv_obj_set_height(ui_ModelFanValLabel, LV_SIZE_CONTENT); 
    lv_obj_align(ui_ModelFanValLabel, LV_ALIGN_RIGHT_MID, -2, 0);
    lv_label_set_text(ui_ModelFanValLabel,"0%"); //默认初始化若设备没反馈显示0%
   // lv_obj_set_flex_align(ui_ModelFanValLabel, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    //lv_obj_set_style_bg_color(ui_ModelFanValLabel, lv_color_hex(0xC2F4FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_opa(ui_ModelFanValLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ModelFanValLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ModelFanValLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ModelFanValLabel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ModelFanValLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ModelFanValLabel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_add_flag(ui_ModelFanValLabel, LV_OBJ_FLAG_HIDDEN);

    ui_ModelFanValSetLabel = lv_label_create(part->part_panel);
    lv_obj_set_width(ui_ModelFanValSetLabel, 80); //LV_SIZE_CONTENT
    lv_obj_set_height(ui_ModelFanValSetLabel, 48); 
    lv_obj_align(ui_ModelFanValSetLabel, LV_ALIGN_RIGHT_MID, -2, 0);
    lv_label_set_text(ui_ModelFanValSetLabel,"0%"); //默认初始化若设备没反馈显示0%
   // lv_obj_set_flex_align(ui_ModelFanValSetLabel, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_ModelFanValSetLabel, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ModelFanValSetLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ModelFanValSetLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ModelFanValSetLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ModelFanValSetLabel, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ModelFanValSetLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ModelFanValSetLabel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_ModelFanValSetLabel, LV_OBJ_FLAG_HIDDEN);

}

void ScreenAuxiliaryFanStyleInit(ctrl_list_t *part, const char *item_name)
{
    // char buf[5] = {0};
    if (!part || !item_name)
        return; 
    lv_label_set_text(part->label_item_name, item_name);
    lv_img_set_src(part->image_item, &ui_img_model_fan_ctrl_png);

    LableAuxiliaryFan = part->label_item_name;
    
    ui_AuxiliaryFanPanel = part->part_panel;
    ui_AuxiliaryFanLabel = part->label_item_name;
    // ui_ModelFanValLabel = part->label_content_name;  
    // lv_obj_align(ui_ModelFanValLabel, LV_ALIGN_RIGHT_MID, -20, 1);
    
    //lv_obj_add_flag(part->img_arrow_png, LV_OBJ_FLAG_HIDDEN);

    //lv_obj_set_style_bg_color(ui_ModelFanPanel, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AuxiliaryFanValLabel = lv_label_create(part->part_panel);
    lv_obj_set_width(ui_AuxiliaryFanValLabel, 80); //LV_SIZE_CONTENT
    lv_obj_set_height(ui_AuxiliaryFanValLabel, LV_SIZE_CONTENT); 
    lv_obj_align(ui_AuxiliaryFanValLabel, LV_ALIGN_RIGHT_MID, -2, 0);
    lv_label_set_text(ui_AuxiliaryFanValLabel,"0%"); //默认初始化若设备没反馈显示0%
   // lv_obj_set_flex_align(ui_AuxiliaryFanValLabel, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    //lv_obj_set_style_bg_color(ui_AuxiliaryFanValLabel, lv_color_hex(0xC2F4FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_opa(ui_AuxiliaryFanValLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_AuxiliaryFanValLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AuxiliaryFanValLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AuxiliaryFanValLabel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_AuxiliaryFanValLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_AuxiliaryFanValLabel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_add_flag(ui_AuxiliaryFanValLabel, LV_OBJ_FLAG_HIDDEN);

    ui_AuxiliaryFanValSetLabel = lv_label_create(part->part_panel);
    lv_obj_set_width(ui_AuxiliaryFanValSetLabel, 80); //LV_SIZE_CONTENT
    lv_obj_set_height(ui_AuxiliaryFanValSetLabel, LV_SIZE_CONTENT); 
    lv_obj_align(ui_AuxiliaryFanValSetLabel, LV_ALIGN_RIGHT_MID, -2, 0);
    lv_label_set_text(ui_AuxiliaryFanValSetLabel,"0%"); //默认初始化若设备没反馈显示0%
   // lv_obj_set_flex_align(ui_AuxiliaryFanValSetLabel, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_AuxiliaryFanValSetLabel, lv_color_hex(0xC2F4FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AuxiliaryFanValSetLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_AuxiliaryFanValSetLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_AuxiliaryFanValSetLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AuxiliaryFanValSetLabel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_AuxiliaryFanValSetLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_AuxiliaryFanValSetLabel, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_AuxiliaryFanValSetLabel, LV_OBJ_FLAG_HIDDEN);

}

void axismove_page_refresh_laserstate(int laser_state)
{
    if(laser_state)
        lv_obj_clear_flag(ui_ImageLaserAxisMove, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageLaserAxisMove, LV_OBJ_FLAG_HIDDEN);
}

void axismove_page_refresh_camerastate(int camera_state)
{
    if(camera_state)
        lv_obj_clear_flag(ui_ImageCamerastateAxisMove, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(ui_ImageCamerastateAxisMove, LV_OBJ_FLAG_HIDDEN);
}

void axismove_page_set_wifi_status(int intensity)
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
        case 0:lv_img_set_src(ui_ImageWifiAxisMove, &ui_img_wifinosignel_png);break;
        case 1:lv_img_set_src(ui_ImageWifiAxisMove, &ui_img_wifismall_png);break;
        case 2:lv_img_set_src(ui_ImageWifiAxisMove, &ui_img_wifimid_png);break;
        case 3:lv_img_set_src(ui_ImageWifiAxisMove, &ui_img_wififull_png);break;
        default:lv_img_set_src(ui_ImageWifiAxisMove, &ui_img_wififull_png);break;
    }
    wifi_Intensity = intensity;
}

//增加进退料的导航对象
void AddExtrudeRetractNavObjs(void)
{
    lv_group_add_obj(encoder_group, ui_ExtrudeRetractBackBtn);
    lv_group_add_obj(encoder_group, ui_PanelHotendTemp);
    lv_group_add_obj(encoder_group, ui_BntExtrude);
    lv_group_add_obj(encoder_group, ui_BntRetract);
}


lv_obj_t * ui_PanelCoolSubPage;       //冷却页主面板
static lv_obj_t * ui_LableCoolSubPageTitle;
static lv_obj_t * ui_CoolSubPageBackBtn;
static lv_obj_t * ui_LineUpperLowerDividing;
static lv_obj_t * ui_FanCtrlPanelList;

// static lv_obj_t * ui_CoolSubPageModelFanImage;
// static lv_obj_t * ui_CoolSubPageLabelModelFan;
// static lv_obj_t * ui_CoolSubPageSliderModelFan;
// static lv_obj_t * ui_CoolSubPageLabelModelPercent;
// static bool HomeNormalRefreshModelFanFlag = false;
// static lv_obj_t * ui_ScreenCoolImageAuxiliaryFan;
// static lv_obj_t * ui_ScreenCoolLabelAuxiliaryFan;
// static lv_obj_t * ui_ScreenCoolSliderAuxiliaryFan;
// static lv_obj_t * ui_ScreenCoolLabelAuxiliaryPercent;
// static lv_obj_t * ui_ScreenCoolImageChassisFan;
// static lv_obj_t * ui_ScreenCoolLabelChassisFan;
// static lv_obj_t * ui_ScreenCoolSliderChassisFan;
// static lv_obj_t * ui_ScreenCoolLabelChassisPercent;

// void CoolSubPage_set_model_fan_duty_percent(uint8_t percent)
// {
//     uint8_t show_percent = 0;
//     if ( percent > 100 )
//         percent = 100;

//     char buff[5] = {0};

// #ifdef FAN_CONTROL_A
//     if (0 == percent)
//     {
//         show_percent = percent;
//     }
//     else
//     {
//         show_percent = ((double)percent - FanMinDutyValue) / (100.0 - FanMinDutyValue) * 100.0;
//     }

//     sprintf(buff, "%d%%", show_percent); 
//     printf("real_percent %d, show_percent %d\n", percent, show_percent);
// #else
//     sprintf(buff, "%d%%", percent); 
// #endif

//     if (HomeNormalRefreshModelFanFlag)
//     {
//         HomeNormalRefreshModelFanFlag = false;
//         lv_label_set_text(ui_CoolSubPageLabelModelPercent, buff);
//         //lv_slider_set_value(ui_CoolSubPageSliderModelFan, show_percent, LV_ANIM_OFF);
//     }
// }

//增加进退料的导航对象
void AddCoolSubPageNavObjs(void)
{
    lv_group_add_obj(encoder_group, ui_CoolSubPageBackBtn);
    //lv_group_add_obj(encoder_group, ui_CoolSubPageSliderModelFan);
}

// static void ui_event_SliderModelFans(lv_event_t * e)
// {
//     lv_event_code_t event_code = lv_event_get_code(e);
//     lv_obj_t * target = lv_event_get_target(e);
//     if ( event_code == LV_EVENT_VALUE_CHANGED ) {
//         //ModelFanValueChanged(e);
//         uint8_t percent = lv_slider_get_value(ui_CoolSubPageSliderModelFan);
// #ifdef FAN_CONTROL_A
//         uint8_t set_percent = 0;
//         if (0 == percent)
//         {
//             set_percent = percent;
//         }
//         else if (1 == percent)
//         {
//             set_percent = FanMinDutyValue + 1;
//         }
//         else
//         {
//             set_percent = (double)percent * (100.0 - FanMinDutyValue) / 100.0 + FanMinDutyValue + 0.5; 
//         }
//         printf("percent %d, set_percent %d\n", percent, set_percent);
//         send_set_model_fan_opt_cmd(set_percent);
// #else
//         send_set_model_fan_opt_cmd(percent);
// #endif
//         char buff[5] = {0};
//         sprintf(buff, "%d%%", percent); 
//         lv_label_set_text(ui_CoolSubPageLabelModelPercent, buff);
//         lv_slider_set_value(ui_CoolSubPageSliderModelFan, percent, LV_ANIM_OFF);
//     }
// }

static void ui_event_CoolSubPageBackBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if ( event_code == LV_EVENT_SHORT_CLICKED )
    {
        if (lv_scr_act() == ui_ScreenAxisMovePage)
        {
            lv_obj_clear_flag(ui_PanelMoveAndTemper, LV_OBJ_FLAG_HIDDEN);
        }
        HideCoolSubPage();
        BackPrepage(false);
    }
}

void AddFanCtrlNavObjs(void)
{
    lv_group_add_obj(encoder_group, ui_CoolSubPageBackBtn);
    lv_group_add_obj(encoder_group, fan_ctrl_array[1]->part_panel);
    //lv_group_add_obj(encoder_group, fan_ctrl_array[2]->part_panel);
}

void ui_CoolSubPage_init(lv_obj_t *parent)
{
    //风扇面板
    ui_PanelCoolSubPage = lv_obj_create(parent);
    lv_obj_set_pos(ui_PanelCoolSubPage, 76, 68);
    lv_obj_set_size(ui_PanelCoolSubPage, 556, 344);
    lv_obj_set_align(ui_PanelCoolSubPage, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_PanelCoolSubPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelCoolSubPage, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelCoolSubPage, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCoolSubPage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelCoolSubPage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelCoolSubPage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelCoolSubPage, LV_OBJ_FLAG_HIDDEN);

    //风扇标题
    ui_LableCoolSubPageTitle = lv_label_create(ui_PanelCoolSubPage);
    lv_obj_set_size(ui_LableCoolSubPageTitle, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_align(ui_LableCoolSubPageTitle, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_pos(ui_LableCoolSubPageTitle, 16, 0);
    lv_label_set_text(ui_LableCoolSubPageTitle, Fans[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LableCoolSubPageTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableCoolSubPageTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableCoolSubPageTitle, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LableCoolSubPageTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //返回按钮
    ui_CoolSubPageBackBtn = lv_btn_create(ui_PanelCoolSubPage);
    lv_obj_set_size(ui_CoolSubPageBackBtn, 68, 38);
    lv_obj_set_pos(ui_CoolSubPageBackBtn, 474, 6);
    lv_obj_add_flag(ui_CoolSubPageBackBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_CoolSubPageBackBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CoolSubPageBackBtn, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CoolSubPageBackBtn, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CoolSubPageBackBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CoolSubPageBackBtn, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CoolSubPageBackBtn, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_CoolSubPageBackBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_CoolSubPageBackBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_CoolSubPageBackBtn, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CoolSubPageBackBtn, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_CoolSubPageBackBtn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_CoolSubPageBackBtn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_CoolSubPageBackBtn, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_CoolSubPageBackBtn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_CoolSubPageBackBtn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //上下分割线
    ui_LineUpperLowerDividing = lv_obj_create(ui_PanelCoolSubPage);
    lv_obj_set_size(ui_LineUpperLowerDividing, 543, 1);
    lv_obj_set_pos(ui_LineUpperLowerDividing, 7, 52);
    lv_obj_clear_flag(ui_LineUpperLowerDividing, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_opa(ui_LineUpperLowerDividing, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_LineUpperLowerDividing, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_LineUpperLowerDividing, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_LineUpperLowerDividing, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_LineUpperLowerDividing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //导出菜单列表面板
    ui_FanCtrlPanelList = lv_obj_create(ui_PanelCoolSubPage);
    lv_obj_set_size(ui_FanCtrlPanelList, 540, 275);
    // lv_obj_set_pos(ui_FanCtrlPanelList, 0, 53);
    // lv_obj_set_align(ui_FanCtrlPanelList, LV_ALIGN_TOP_LEFT);
    lv_obj_align(ui_FanCtrlPanelList, LV_ALIGN_TOP_MID, 0, 61);
    lv_obj_add_flag(ui_FanCtrlPanelList, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_FanCtrlPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_FanCtrlPanelList, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FanCtrlPanelList, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_FanCtrlPanelList, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_FanCtrlPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_FanCtrlPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_FanCtrlPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_FanCtrlPanelList, LV_FLEX_FLOW_COLUMN);
    //lv_obj_set_style_pad_left(ui_FanCtrlPanelList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_FanCtrlPanelList, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_align(ui_FanCtrlPanelList, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER);


    //int y_pos_offset = 0;
    for (size_t index = 1; index < 2; index++)
    {
         fan_ctrl_array[index] = create_fan_ctrl_list_item(ui_FanCtrlPanelList, index, 9, 0, ui_event_FanCtrlItem);
         //y_pos_offset += 60;
    }

    ScreenModelFanStyleInit(fan_ctrl_array[1], ModelFans[get_cur_language_index()]);
    //ScreenAuxiliaryFanStyleInit(fan_ctrl_array[2], CoolFan[get_cur_language_index()]);

    //模型风扇进度条
    // ui_CoolSubPageModelFanImage = lv_img_create(ui_PanelCoolSubPage);
    // lv_img_set_src(ui_CoolSubPageModelFanImage, &ui_img_cool_stop_fan_png);
    // lv_obj_set_width(ui_CoolSubPageModelFanImage, 39);
    // lv_obj_set_height(ui_CoolSubPageModelFanImage, 39);
    // lv_obj_set_x(ui_CoolSubPageModelFanImage, 13);
    // lv_obj_set_y(ui_CoolSubPageModelFanImage, 89);
    // lv_obj_add_flag(ui_CoolSubPageModelFanImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_CoolSubPageModelFanImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    // ui_CoolSubPageLabelModelFan = lv_label_create(ui_PanelCoolSubPage);
    // lv_obj_set_width(ui_CoolSubPageLabelModelFan, LV_SIZE_CONTENT);
    // lv_obj_set_height(ui_CoolSubPageLabelModelFan, LV_SIZE_CONTENT);
    // lv_obj_set_x(ui_CoolSubPageLabelModelFan, 62);
    // lv_obj_set_y(ui_CoolSubPageLabelModelFan, 55);   //从40改成30
    // lv_label_set_text(ui_CoolSubPageLabelModelFan, "模型风扇");
    // lv_obj_set_style_text_color(ui_CoolSubPageLabelModelFan, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_CoolSubPageLabelModelFan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_CoolSubPageLabelModelFan, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_CoolSubPageSliderModelFan = lv_slider_create(ui_PanelCoolSubPage);
    // lv_slider_set_value(ui_CoolSubPageSliderModelFan, 20, LV_ANIM_OFF);
    // if(lv_slider_get_mode(ui_CoolSubPageSliderModelFan) == LV_SLIDER_MODE_RANGE) 
    //     lv_slider_set_left_value(ui_CoolSubPageSliderModelFan, 0, LV_ANIM_OFF);
    // lv_obj_set_width(ui_CoolSubPageSliderModelFan, 400);
    // lv_obj_set_height(ui_CoolSubPageSliderModelFan, 16);
    // lv_obj_set_x(ui_CoolSubPageSliderModelFan, 62);
    // lv_obj_set_y(ui_CoolSubPageSliderModelFan, 99);
    // lv_obj_set_style_radius(ui_CoolSubPageSliderModelFan, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_CoolSubPageSliderModelFan, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_CoolSubPageSliderModelFan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // lv_obj_set_style_radius(ui_CoolSubPageSliderModelFan, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_CoolSubPageSliderModelFan, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_CoolSubPageSliderModelFan, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    // lv_obj_set_style_radius(ui_CoolSubPageSliderModelFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_CoolSubPageSliderModelFan, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_CoolSubPageSliderModelFan, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_left(ui_CoolSubPageSliderModelFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_right(ui_CoolSubPageSliderModelFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_top(ui_CoolSubPageSliderModelFan, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_bottom(ui_CoolSubPageSliderModelFan, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_row(ui_CoolSubPageSliderModelFan, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_column(ui_CoolSubPageSliderModelFan, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    // lv_obj_set_ext_click_area(ui_CoolSubPageSliderModelFan, 50);

    // lv_slider_set_range(ui_CoolSubPageSliderModelFan, 0, 100);
    // lv_slider_set_value(ui_CoolSubPageSliderModelFan, 0, LV_ANIM_OFF);



    // ui_CoolSubPageLabelModelPercent = lv_label_create(ui_PanelCoolSubPage);
    // lv_obj_set_width(ui_CoolSubPageLabelModelPercent, 70);
    // lv_obj_set_height(ui_CoolSubPageLabelModelPercent, 30);
    // lv_obj_set_x(ui_CoolSubPageLabelModelPercent, 480);
    // lv_obj_set_y(ui_CoolSubPageLabelModelPercent, 91);
    // lv_label_set_text(ui_CoolSubPageLabelModelPercent, "");
    // lv_obj_set_style_text_color(ui_CoolSubPageLabelModelPercent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_CoolSubPageLabelModelPercent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_CoolSubPageLabelModelPercent, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //lv_obj_add_event_cb(ui_CoolSubPageSliderModelFan, ui_event_SliderModelFans, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_CoolSubPageBackBtn, ui_event_CoolSubPageBackBtn, LV_EVENT_ALL, NULL);
}

void ShowCoolSubPage(lv_obj_t *parent)
{
    lv_obj_set_parent(ui_PanelCoolSubPage, parent);
    lv_obj_clear_flag(ui_PanelCoolSubPage, LV_OBJ_FLAG_HIDDEN);
}

void HideCoolSubPage(void)
{
    lv_obj_add_flag(ui_PanelCoolSubPage, LV_OBJ_FLAG_HIDDEN);
}


void ui_ScreenAxisMovePage_screen_init(void)
{
    AxisMove.stateValue = false;

    //控制页面父对象
    ui_ScreenAxisMovePage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenAxisMovePage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenAxisMovePage, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenAxisMovePage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_ScreenAxisMovePage, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);

    init_pages(ui_ScreenAxisMovePage, AxisMovePageChangeObjs, LoadAxisMoveScreen);

    //左边导航面板
    ui_PanelPageScreenAxisMove = lv_obj_create(ui_ScreenAxisMovePage);
    lv_obj_set_width(ui_PanelPageScreenAxisMove, 68);
    lv_obj_set_height(ui_PanelPageScreenAxisMove, 360);
    lv_obj_clear_flag(ui_PanelPageScreenAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_PanelPageScreenAxisMove, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_pos(ui_PanelPageScreenAxisMove, 0, 60);

    //home按键
    ui_ButtonHomeScreenAxisMove = lv_btn_create(ui_PanelPageScreenAxisMove);
    lv_obj_set_width(ui_ButtonHomeScreenAxisMove, 68);
    lv_obj_set_height(ui_ButtonHomeScreenAxisMove, 72);
    lv_obj_set_x(ui_ButtonHomeScreenAxisMove, -18);
    lv_obj_set_y(ui_ButtonHomeScreenAxisMove, -18);
    lv_obj_add_flag(ui_ButtonHomeScreenAxisMove, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonHomeScreenAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonHomeScreenAxisMove, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_ButtonHomeScreenAxisMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonHomeScreenAxisMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonHomeScreenAxisMove, &ui_img_pagehome_png, LV_PART_MAIN | LV_STATE_DEFAULT);
     lv_obj_set_style_border_color(ui_ButtonHomeScreenAxisMove, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonHomeScreenAxisMove, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonHomeScreenAxisMove, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonHomeScreenAxisMove, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonHomeScreenAxisMove, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //准备按键
    //ui_ButtonAxisMoveAxisMove = lv_btn_create(ui_PanelPageScreenAxisMove);
    ui_ButtonAxisMoveAxisMove = lv_obj_create(ui_PanelPageScreenAxisMove);
    lv_obj_set_width(ui_ButtonAxisMoveAxisMove, 68);
    lv_obj_set_height(ui_ButtonAxisMoveAxisMove, 72);   
    lv_obj_set_x(ui_ButtonAxisMoveAxisMove, -18);
    lv_obj_set_y(ui_ButtonAxisMoveAxisMove, 54);
    lv_obj_add_flag(ui_ButtonAxisMoveAxisMove, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAxisMoveAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    //默认样式
    lv_obj_set_style_radius(ui_ButtonAxisMoveAxisMove, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveAxisMove, &ui_img_pagemove_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_radius(ui_ButtonFileManageScreenFile, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonAxisMoveAxisMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_ButtonAxisMoveAxisMove, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonAxisMoveAxisMove, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonAxisMoveAxisMove, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonAxisMoveAxisMove, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonAxisMoveAxisMove, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonAxisMoveAxisMove, 1, LV_PART_MAIN | LV_STATE_PRESSED);

    //文件按钮
    ui_ButtonFileManageScreenAxisMove = lv_btn_create(ui_PanelPageScreenAxisMove);
    lv_obj_set_width(ui_ButtonFileManageScreenAxisMove, 68);
    lv_obj_set_height(ui_ButtonFileManageScreenAxisMove, 72);
    lv_obj_set_x(ui_ButtonFileManageScreenAxisMove, -18);
    lv_obj_set_y(ui_ButtonFileManageScreenAxisMove, 126);
    lv_obj_add_flag(ui_ButtonFileManageScreenAxisMove, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonFileManageScreenAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonFileManageScreenAxisMove, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_ButtonFileManageScreenAxisMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonFileManageScreenAxisMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonFileManageScreenAxisMove, &ui_img_pagefilemanage_png,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonFileManageScreenAxisMove, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonFileManageScreenAxisMove, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonFileManageScreenAxisMove, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonFileManageScreenAxisMove, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonFileManageScreenAxisMove, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //设置按钮
    ui_ButtonSettingsScreenAxisMove = lv_btn_create(ui_PanelPageScreenAxisMove);
    lv_obj_set_width(ui_ButtonSettingsScreenAxisMove, 68);
    lv_obj_set_height(ui_ButtonSettingsScreenAxisMove, 72);
    lv_obj_set_x(ui_ButtonSettingsScreenAxisMove, -18);
    lv_obj_set_y(ui_ButtonSettingsScreenAxisMove, 198);
    lv_obj_add_flag(ui_ButtonSettingsScreenAxisMove, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSettingsScreenAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonSettingsScreenAxisMove, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_ButtonSettingsScreenAxisMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonSettingsScreenAxisMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonSettingsScreenAxisMove, &ui_img_pagesetting_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonSettingsScreenAxisMove, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonSettingsScreenAxisMove, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonSettingsScreenAxisMove, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonSettingsScreenAxisMove, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonSettingsScreenAxisMove, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //客服按钮
    ui_ButtonReserveScreenAxisMove = lv_btn_create(ui_PanelPageScreenAxisMove);
    lv_obj_set_width(ui_ButtonReserveScreenAxisMove, 68);
    lv_obj_set_height(ui_ButtonReserveScreenAxisMove, 72);
    lv_obj_set_x(ui_ButtonReserveScreenAxisMove, -18);
    lv_obj_set_y(ui_ButtonReserveScreenAxisMove, 270);
    lv_obj_add_flag(ui_ButtonReserveScreenAxisMove, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonReserveScreenAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonReserveScreenAxisMove, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_ButtonReserveScreenAxisMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonReserveScreenAxisMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonReserveScreenAxisMove, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonReserveScreenAxisMove, lv_color_hex(0xCDF6FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ButtonReserveScreenAxisMove, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ButtonReserveScreenAxisMove, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ButtonReserveScreenAxisMove, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ButtonReserveScreenAxisMove, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    lv_obj_add_event_cb(ui_ButtonHomeScreenAxisMove, ui_event_ButtonHomeScreenAxisMove, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonAxisMoveAxisMove, ui_event_update_AxisMove_page, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonFileManageScreenAxisMove, ui_event_ButtonFileManageScreenAxisMove, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSettingsScreenAxisMove, ui_event_ButtonSettingsScreenAxisMove, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonReserveScreenAxisMove, ui_event_ButtonReserveScreenAxisMove, LV_EVENT_ALL, NULL);

    //右边主面板
    ui_PanelMoveAndTemper = lv_obj_create(ui_ScreenAxisMovePage);
    lv_obj_clear_flag(ui_PanelMoveAndTemper, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelMoveAndTemper, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelMoveAndTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_pos(ui_PanelMoveAndTemper, 68, 60); //页面导航栏宽度为68 
	lv_obj_set_size(ui_PanelMoveAndTemper, 572, 360);
   // lv_obj_set_align(ui_PanelMoveAndTemper, LV_ALIGN_TOP_LEFT);
    lv_obj_set_style_radius(ui_PanelMoveAndTemper, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelMoveAndTemper, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelMoveAndTemper, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_PanelMoveAndTemper, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelMoveAndTemper, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
   // lv_obj_add_flag(ui_PanelMoveAndTemper, LV_OBJ_FLAG_HIDDEN);

    //标题&状态栏面板
    ui_PanelTitleAndStatusAxisMove = lv_obj_create(ui_PanelMoveAndTemper);
    lv_obj_set_pos(ui_PanelTitleAndStatusAxisMove, 0, 0);
    lv_obj_set_size(ui_PanelTitleAndStatusAxisMove, 572, 46);
    lv_obj_clear_flag(ui_PanelTitleAndStatusAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelTitleAndStatusAxisMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelTitleAndStatusAxisMove, lv_color_hex(0x101011), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelTitleAndStatusAxisMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelTitleAndStatusAxisMove, lv_color_hex(0x565656), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelTitleAndStatusAxisMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelTitleAndStatusAxisMove, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelTitleAndStatusAxisMove, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelTitleAndStatusAxisMove, 0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

    //控制标题lable
    ui_LabelCtrlTitle = lv_label_create(ui_PanelTitleAndStatusAxisMove);
    lv_obj_set_size(ui_LabelCtrlTitle, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_LabelCtrlTitle, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_LabelCtrlTitle, Control[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelCtrlTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelCtrlTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelCtrlTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LabelCtrlTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // //wifi图标
    // ui_ImageWifiAxisMove = lv_img_create(ui_PanelTitleAndStatusAxisMove);
    // axismove_page_set_wifi_status(wifi_Intensity);
    // lv_obj_set_size(ui_ImageWifiAxisMove, 45, 45);
    // lv_obj_align(ui_ImageWifiAxisMove, LV_ALIGN_RIGHT_MID, -4, -3);
    // //lv_obj_set_align(ui_ImageWifiNormal, LV_ALIGN_RIGHT_MID);
    // lv_obj_add_flag(ui_ImageWifiAxisMove, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_ImageWifiAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    
    // //摄像头
    // ui_ImageCamerastateAxisMove = lv_img_create(ui_PanelTitleAndStatusAxisMove);
    // lv_obj_set_size(ui_ImageCamerastateAxisMove, 23, 30);
    // lv_obj_align(ui_ImageCamerastateAxisMove, LV_ALIGN_RIGHT_MID, -65, 0);
    // lv_img_set_src(ui_ImageCamerastateAxisMove, &ui_img_camera_png);
    // lv_obj_add_flag(ui_ImageCamerastateAxisMove, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_ImageCamerastateAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    
    ui_AxisMoveDeviceIconPanel = lv_obj_create(ui_PanelTitleAndStatusAxisMove);
    lv_obj_set_size(ui_AxisMoveDeviceIconPanel, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_clear_flag(ui_AxisMoveDeviceIconPanel, LV_OBJ_FLAG_SCROLLABLE);  
    lv_obj_align(ui_AxisMoveDeviceIconPanel, LV_ALIGN_RIGHT_MID, 0, 0);
    lv_obj_set_style_radius(ui_AxisMoveDeviceIconPanel, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AxisMoveDeviceIconPanel, lv_color_hex(0x101011), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AxisMoveDeviceIconPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_AxisMoveDeviceIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_AxisMoveDeviceIconPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_AxisMoveDeviceIconPanel, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_pad_column(ui_AxisMoveDeviceIconPanel, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_align(ui_AxisMoveDeviceIconPanel, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    
    //激光雷达
    ui_ImageLaserAxisMove = lv_img_create(ui_AxisMoveDeviceIconPanel);
    lv_obj_set_size(ui_ImageLaserAxisMove, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_img_set_src(ui_ImageLaserAxisMove, &ui_img_laser_png);
    lv_obj_add_flag(ui_ImageLaserAxisMove, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageLaserAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_ImageLaserAxisMove, LV_OBJ_FLAG_HIDDEN); 

    //摄像头
    ui_ImageCamerastateAxisMove = lv_img_create(ui_AxisMoveDeviceIconPanel);
    lv_obj_set_size(ui_ImageCamerastateAxisMove, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_img_set_src(ui_ImageCamerastateAxisMove, &ui_img_camera_png);
    lv_obj_add_flag(ui_ImageCamerastateAxisMove, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageCamerastateAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_ImageCamerastateAxisMove, LV_OBJ_FLAG_HIDDEN); 

    //wifi图标
    ui_ImageWifiAxisMove = lv_img_create(ui_AxisMoveDeviceIconPanel);
    axismove_page_set_wifi_status(wifi_Intensity);
    lv_obj_set_size(ui_ImageWifiAxisMove, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_add_flag(ui_ImageWifiAxisMove, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageWifiAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags



    //主体部分-控制菜单列表面板
    ui_PanelCtrlList = lv_obj_create(ui_PanelMoveAndTemper);
    lv_obj_set_size(ui_PanelCtrlList, 572, 308);
    lv_obj_set_pos(ui_PanelCtrlList, 0, 52);
    lv_obj_set_align(ui_PanelCtrlList, LV_ALIGN_TOP_LEFT);
    lv_obj_add_flag(ui_PanelCtrlList, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelCtrlList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelCtrlList, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCtrlList, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelCtrlList, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelCtrlList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_PanelCtrlList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelCtrlList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);


    int y_pos_offset = 0;
    for (size_t index = 1; index < 11; index++)
    {
         ctrl_array[index] = create_ctrl_list_item(ui_PanelCtrlList, index, 9, y_pos_offset, ui_event_CtrlItem);
         y_pos_offset += 60;
    }

    ScreenHotendTempStyleInit(ctrl_array[1], HotendTemp[get_cur_language_index()]);
    ScreenBedTempStyleInit(ctrl_array[2], Bed_temp[get_cur_language_index()]);
    ScreenHomeXYStyleInit(ctrl_array[3], XY_HomeArray[get_cur_language_index()]);
    ScreenHomeZStyleInit(ctrl_array[4], Z_HomeArray[get_cur_language_index()]);
    ScreenXAxisMoveStyleInit(ctrl_array[5], X_AxisMove[get_cur_language_index()]);
    ScreenYAxisMoveStyleInit(ctrl_array[6], Y_AxisMove[get_cur_language_index()]);
    ScreenZAxisMoveStyleInit(ctrl_array[7], Z_AxisMove[get_cur_language_index()]);
    ScreenTurnOffTheMotorStyleInit(ctrl_array[8], Turn_off_the_motor[get_cur_language_index()]);
    ScreenInOrOutMaterialStyleInit(ctrl_array[9], Extrude_Retract[get_cur_language_index()]);
    //ScreenModelFanStyleInit(ctrl_array[10], ModelFans[get_cur_language_index()]);
    ScreenFanStyleInit(ctrl_array[10], Fans[get_cur_language_index()]);

    //进退料面板
    ui_PanelExtrudeRetract = lv_obj_create(ui_ScreenAxisMovePage);
    lv_obj_set_pos(ui_PanelExtrudeRetract, 76, 68);
    lv_obj_set_size(ui_PanelExtrudeRetract, 556, 344);
    lv_obj_set_align(ui_PanelExtrudeRetract, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_PanelExtrudeRetract, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelExtrudeRetract, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelExtrudeRetract, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelExtrudeRetract, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelExtrudeRetract, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelExtrudeRetract, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelExtrudeRetract, LV_OBJ_FLAG_HIDDEN);

    //进退料标题
    ui_LableExtrudeRetractTitle = lv_label_create(ui_PanelExtrudeRetract);
    lv_obj_set_size(ui_LableExtrudeRetractTitle, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_align(ui_LableExtrudeRetractTitle, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_pos(ui_LableExtrudeRetractTitle, 26, 6);
    lv_label_set_text(ui_LableExtrudeRetractTitle, Extrude_Retract[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LableExtrudeRetractTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableExtrudeRetractTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableExtrudeRetractTitle, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LableExtrudeRetractTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //返回按钮
    ui_ExtrudeRetractBackBtn = lv_btn_create(ui_PanelExtrudeRetract);
    lv_obj_set_size(ui_ExtrudeRetractBackBtn, 68, 38);
    lv_obj_set_pos(ui_ExtrudeRetractBackBtn, 474, 6);
    lv_obj_add_flag(ui_ExtrudeRetractBackBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ExtrudeRetractBackBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExtrudeRetractBackBtn, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ExtrudeRetractBackBtn, lv_color_hex(0x393A3E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExtrudeRetractBackBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ExtrudeRetractBackBtn, lv_color_hex(0x5C6068), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExtrudeRetractBackBtn, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ExtrudeRetractBackBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ExtrudeRetractBackBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ExtrudeRetractBackBtn, &ui_img_goback_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ExtrudeRetractBackBtn, lv_color_hex(0xCDF6FF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_ExtrudeRetractBackBtn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_ExtrudeRetractBackBtn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_ExtrudeRetractBackBtn, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(ui_ExtrudeRetractBackBtn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_ExtrudeRetractBackBtn, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //上下分割线
    ui_LineUpperLowerDividing = lv_obj_create(ui_PanelExtrudeRetract);
    lv_obj_set_size(ui_LineUpperLowerDividing, 543, 1);
    lv_obj_set_pos(ui_LineUpperLowerDividing, 6, 52);
    lv_obj_clear_flag(ui_LineUpperLowerDividing, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_opa(ui_LineUpperLowerDividing, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_LineUpperLowerDividing, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_LineUpperLowerDividing, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_LineUpperLowerDividing, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_LineUpperLowerDividing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //左右分割线
    ui_LineLeftRightDividing = lv_obj_create(ui_PanelExtrudeRetract);
    lv_obj_set_size(ui_LineLeftRightDividing, 1, 291);
    lv_obj_set_pos(ui_LineLeftRightDividing, 362, 53);
    lv_obj_clear_flag(ui_LineLeftRightDividing, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_opa(ui_LineLeftRightDividing, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_LineLeftRightDividing, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_LineLeftRightDividing, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_LineLeftRightDividing, 153, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_LineLeftRightDividing, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //喷嘴初始状态面板
    ui_PanelHotendInitState = lv_obj_create(ui_PanelExtrudeRetract);
    // lv_obj_set_pos(ui_PanelHotendInitState, 80, 70);
    lv_obj_set_size(ui_PanelHotendInitState, 360, 200);
    lv_obj_align(ui_PanelHotendInitState, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_clear_flag(ui_PanelHotendInitState, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelHotendInitState, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelHotendInitState, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHotendInitState, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelHotendInitState, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelHotendInitState, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_add_flag(ui_PanelHotendInitState, LV_OBJ_FLAG_HIDDEN);

    //喷嘴温度标题
    ui_TitleHotendTemp = lv_label_create(ui_PanelHotendInitState);
    lv_obj_set_size(ui_TitleHotendTemp, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_set_pos(ui_TitleHotendTemp, 26, 6);
    lv_obj_align(ui_TitleHotendTemp, LV_ALIGN_TOP_MID, 0, 25);
    lv_label_set_text(ui_TitleHotendTemp, HotendTemp[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_TitleHotendTemp, lv_color_hex(0x9398A1), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TitleHotendTemp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TitleHotendTemp, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_TitleHotendTemp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //喷嘴温度面板
    ui_PanelHotendTemp = lv_obj_create(ui_PanelHotendInitState);
    lv_obj_set_size(ui_PanelHotendTemp, 186, 54);
    lv_obj_align(ui_PanelHotendTemp, LV_ALIGN_TOP_MID, 0, 80);
    //lv_obj_set_align(ui_PanelHotendTemp, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_PanelHotendTemp, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelHotendTemp, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelHotendTemp, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHotendTemp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelHotendTemp, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelHotendTemp, lv_color_hex(0x5E6166), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelHotendTemp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_PanelHotendTemp, lv_color_hex(0xFFFFFF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_PanelHotendTemp, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_PanelHotendTemp, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_PanelHotendTemp, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_PanelHotendTemp, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    //lv_obj_add_flag(ui_PanelHotendTemp, LV_OBJ_FLAG_HIDDEN);

    //喷嘴温度标签
    ui_LableHotendTemp = lv_label_create(ui_PanelHotendTemp);
    lv_obj_set_size(ui_LableHotendTemp, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_set_pos(ui_LableHotendTemp, 60, 7);
    lv_obj_align(ui_LableHotendTemp, LV_ALIGN_CENTER, -5, 0);
    char tmp_buf[6] = {0};
    sprintf(tmp_buf, "%d", ExtrudeRetractTargetTemper);
    lv_label_set_text(ui_LableHotendTemp, tmp_buf);
    lv_obj_set_style_text_color(ui_LableHotendTemp, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_LableHotendTemp, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LableHotendTemp, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableHotendTemp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableHotendTemp, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LableHotendTemp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //温度单位℃
    ui_LabelTemperUnit = lv_label_create(ui_PanelHotendTemp);
    lv_obj_set_size(ui_LabelTemperUnit, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    //lv_obj_set_pos(ui_LabelTemperUnit, 110, 2);
    lv_obj_align(ui_LabelTemperUnit, LV_ALIGN_CENTER, 35, 4);
    lv_label_set_text(ui_LabelTemperUnit, "°C");
    lv_obj_set_style_text_color(ui_LabelTemperUnit, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTemperUnit, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTemperUnit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTemperUnit, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //喷嘴正常状态面板
    ui_PanelHotendNormalState = lv_obj_create(ui_PanelExtrudeRetract);
    lv_obj_set_pos(ui_PanelHotendNormalState, 80, 70);
    lv_obj_set_size(ui_PanelHotendNormalState, 200, 200);
    //lv_obj_set_align(ui_PanelHotendNormalState, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_PanelHotendNormalState, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelHotendNormalState, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelHotendNormalState, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHotendNormalState, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelHotendNormalState, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelHotendNormalState, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelHotendNormalState, LV_OBJ_FLAG_HIDDEN);

    //正常喷嘴图片
    ui_ImageHotendNormal = lv_img_create(ui_PanelHotendNormalState);
    lv_img_set_src(ui_ImageHotendNormal, &ui_img_filament_hotend_normal_png);
    lv_obj_align(ui_ImageHotendNormal, LV_ALIGN_TOP_MID, 0, 30);
    lv_obj_add_flag(ui_ImageHotendNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHotendNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    //正常实时温度
    ui_LabelNormalRealTemper = lv_label_create(ui_PanelHotendNormalState);
    lv_obj_set_size(ui_LabelNormalRealTemper, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_LabelNormalRealTemper, LV_ALIGN_TOP_MID, 0, 105);
    lv_label_set_text(ui_LabelNormalRealTemper, "240℃");
    lv_obj_set_style_text_color(ui_LabelNormalRealTemper, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelNormalRealTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelNormalRealTemper, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LabelNormalRealTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //喷嘴加热状态面板
    ui_PanelHotendHeatingState = lv_obj_create(ui_PanelExtrudeRetract);
    lv_obj_set_pos(ui_PanelHotendHeatingState, 80, 70);
    lv_obj_set_size(ui_PanelHotendHeatingState, 200, 200);
    //lv_obj_set_align(ui_PanelHotendHeatingState, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_PanelHotendHeatingState, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelHotendHeatingState, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelHotendHeatingState, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHotendHeatingState, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelHotendHeatingState, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelHotendHeatingState, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelHotendHeatingState, LV_OBJ_FLAG_HIDDEN);

    //加热喷嘴图片
    ui_ImageHotendHeating = lv_img_create(ui_PanelHotendHeatingState);
    lv_img_set_src(ui_ImageHotendHeating, &ui_img_filament_hotend_heat_png);
    lv_obj_align(ui_ImageHotendHeating, LV_ALIGN_TOP_MID, 0, 30);
    lv_obj_add_flag(ui_ImageHotendHeating, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHotendHeating, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    //加热实时温度
    ui_LableRealHotendTempHeating = lv_label_create(ui_PanelHotendHeatingState);
    lv_obj_set_size(ui_LableRealHotendTempHeating, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_LableRealHotendTempHeating, LV_ALIGN_TOP_MID, -50, 105);
    lv_label_set_text(ui_LableRealHotendTempHeating, "240℃");
    lv_obj_set_style_text_color(ui_LableRealHotendTempHeating, lv_color_hex(0xFA6D31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableRealHotendTempHeating, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableRealHotendTempHeating, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LableRealHotendTempHeating, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //加热箭头
    ui_ImageTemperTo = lv_img_create(ui_PanelHotendHeatingState);
    lv_img_set_src(ui_ImageTemperTo, &ui_img_totarget_png);
    lv_obj_align(ui_ImageTemperTo, LV_ALIGN_TOP_MID, 0, 110);
    lv_obj_add_flag(ui_ImageTemperTo, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageTemperTo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    //加热目标温度
    ui_LableTargetHotendTempHeating = lv_label_create(ui_PanelHotendHeatingState);
    lv_obj_set_size(ui_LableTargetHotendTempHeating, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_LableTargetHotendTempHeating, LV_ALIGN_TOP_MID, 50, 105);
    lv_label_set_text(ui_LableTargetHotendTempHeating, "240℃");
    lv_obj_set_style_text_color(ui_LableTargetHotendTempHeating, lv_color_hex(0xFA6D31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableTargetHotendTempHeating, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableTargetHotendTempHeating, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LableTargetHotendTempHeating, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    /***********************************底部进退料按钮**************************************/
    //进料按钮
    ui_BntExtrude = lv_btn_create(ui_PanelExtrudeRetract);
    lv_obj_set_size(ui_BntExtrude, 154, 52);
    lv_obj_set_pos(ui_BntExtrude, 16, 284);
    lv_obj_add_flag(ui_BntExtrude, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BntExtrude, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BntExtrude, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BntExtrude, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BntExtrude, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_BntExtrude, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_BntExtrude, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_BntExtrude, lv_color_hex(0xFFFFFF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_BntExtrude, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_BntExtrude, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_BntExtrude, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_BntExtrude, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //进料标签
    ui_LableExtrude = lv_label_create(ui_BntExtrude);
    lv_obj_set_size(ui_LableExtrude, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_LableExtrude, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(ui_LableExtrude, FilamentIn[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LableExtrude, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableExtrude, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableExtrude, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LableExtrude, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //退料按钮
    ui_BntRetract = lv_btn_create(ui_PanelExtrudeRetract);
    lv_obj_set_size(ui_BntRetract, 154, 52);
    lv_obj_set_pos(ui_BntRetract, 189, 284);
    lv_obj_add_flag(ui_BntRetract, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BntRetract, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BntRetract, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BntRetract, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BntRetract, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_BntRetract, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_BntRetract, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(ui_BntRetract, lv_color_hex(0xFFFFFF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(ui_BntRetract, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_BntRetract, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(ui_BntRetract, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(ui_BntRetract, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    //退料标签
    ui_LableRetract = lv_label_create(ui_BntRetract);
    lv_obj_set_size(ui_LableRetract, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_LableRetract, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(ui_LableRetract, FilamentOut[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LableRetract, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableRetract, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableRetract, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_LableRetract, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    /***********************************右边提示信息**************************************/
    //进退料提示信息面板
    ui_PanelInfoExtrudeRetract = lv_obj_create(ui_PanelExtrudeRetract);
    lv_obj_set_pos(ui_PanelInfoExtrudeRetract, 365, 55);
    lv_obj_set_size(ui_PanelInfoExtrudeRetract, 185, 280);
    //lv_obj_set_align(ui_PanelInfoExtrudeRetract, LV_ALIGN_TOP_LEFT);
    lv_obj_clear_flag(ui_PanelInfoExtrudeRetract, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelInfoExtrudeRetract, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelInfoExtrudeRetract, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelInfoExtrudeRetract, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelInfoExtrudeRetract, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelInfoExtrudeRetract, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //提示信息内容标签
    ui_LableTipInfoContent = lv_label_create(ui_PanelInfoExtrudeRetract);
    lv_obj_set_size(ui_LableTipInfoContent, 170, LV_SIZE_CONTENT);
    lv_obj_align(ui_LableTipInfoContent, LV_ALIGN_TOP_MID, 0, 10);
    char buf[256] = {0};
    sprintf(buf, HotTips[get_cur_language_index()], 240);
    lv_label_set_text(ui_LableTipInfoContent, buf);
    lv_obj_set_style_text_color(ui_LableTipInfoContent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableTipInfoContent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableTipInfoContent, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LableTipInfoContent, LV_LABEL_LONG_WRAP);
    //lv_obj_add_flag(ui_LableTipInfoContent, LV_OBJ_FLAG_HIDDEN);

    //进料进度信息面板
    ui_PanelExtrudeProccessInfo = lv_obj_create(ui_PanelInfoExtrudeRetract);
    lv_obj_set_size(ui_PanelExtrudeProccessInfo, 185, 280);
    lv_obj_set_align(ui_PanelExtrudeProccessInfo, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelExtrudeProccessInfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelExtrudeProccessInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelExtrudeProccessInfo, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelExtrudeProccessInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelExtrudeProccessInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelExtrudeProccessInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelExtrudeProccessInfo, LV_OBJ_FLAG_HIDDEN);

    //圆圈1
    ui_RoundExtrudeFirstStepNum = lv_obj_create(ui_PanelExtrudeProccessInfo);
    lv_obj_set_width(ui_RoundExtrudeFirstStepNum, 30);
    lv_obj_set_height(ui_RoundExtrudeFirstStepNum, 30);
    lv_obj_set_x(ui_RoundExtrudeFirstStepNum, 9);
    lv_obj_set_y(ui_RoundExtrudeFirstStepNum, 17);
    lv_obj_add_flag(ui_RoundExtrudeFirstStepNum, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_RoundExtrudeFirstStepNum, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_RoundExtrudeFirstStepNum, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RoundExtrudeFirstStepNum, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RoundExtrudeFirstStepNum, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_RoundExtrudeFirstStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_RoundExtrudeFirstStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_RoundExtrudeFirstStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //"1" lable
    ui_LableExtrudeFirstStepNum = lv_label_create(ui_RoundExtrudeFirstStepNum);
    lv_obj_set_width(ui_LableExtrudeFirstStepNum, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LableExtrudeFirstStepNum, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LableExtrudeFirstStepNum, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LableExtrudeFirstStepNum, "1");
    lv_obj_set_style_text_font(ui_LableExtrudeFirstStepNum, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LableExtrudeFirstStepNum, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //步骤1内容
    ui_LableExtrudeFirstStepContent = lv_label_create(ui_PanelExtrudeProccessInfo);
    lv_obj_set_width(ui_LableExtrudeFirstStepContent, 140);
    lv_obj_set_height(ui_LableExtrudeFirstStepContent, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_LableExtrudeFirstStepContent, 43);
    lv_obj_set_y(ui_LableExtrudeFirstStepContent, 18);
    lv_label_set_text(ui_LableExtrudeFirstStepContent, HotendHeating[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LableExtrudeFirstStepContent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableExtrudeFirstStepContent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableExtrudeFirstStepContent, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LableExtrudeFirstStepContent, LV_LABEL_LONG_WRAP);

    //连接线
    ui_CableExtrudeFirstStep = lv_obj_create(ui_PanelExtrudeProccessInfo);
    lv_obj_set_width(ui_CableExtrudeFirstStep, 3);
    lv_obj_set_height(ui_CableExtrudeFirstStep, 59);
    lv_obj_set_x(ui_CableExtrudeFirstStep, 22);
    lv_obj_set_y(ui_CableExtrudeFirstStep, 43);
    lv_obj_clear_flag(ui_CableExtrudeFirstStep, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CableExtrudeFirstStep, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CableExtrudeFirstStep, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CableExtrudeFirstStep, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_CableExtrudeFirstStep, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_CableExtrudeFirstStep, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CableExtrudeFirstStep, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_CableExtrudeFirstStep, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    //圆圈2
    ui_RoundExtrudeSecondStepNum = lv_obj_create(ui_PanelExtrudeProccessInfo);
    lv_obj_set_width(ui_RoundExtrudeSecondStepNum, 30);
    lv_obj_set_height(ui_RoundExtrudeSecondStepNum, 30);
    lv_obj_set_x(ui_RoundExtrudeSecondStepNum, 9);
    lv_obj_set_y(ui_RoundExtrudeSecondStepNum, 101);
    lv_obj_add_flag(ui_RoundExtrudeSecondStepNum, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_RoundExtrudeSecondStepNum, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_RoundExtrudeSecondStepNum, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RoundExtrudeSecondStepNum, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RoundExtrudeSecondStepNum, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_RoundExtrudeSecondStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_RoundExtrudeSecondStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_RoundExtrudeSecondStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //步骤“2”
    ui_LableExtrudeSecondStepNum = lv_label_create(ui_RoundExtrudeSecondStepNum);
    lv_obj_set_width(ui_LableExtrudeSecondStepNum, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LableExtrudeSecondStepNum, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LableExtrudeSecondStepNum, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LableExtrudeSecondStepNum, "2");
    lv_obj_set_style_text_font(ui_LableExtrudeSecondStepNum, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LableExtrudeSecondStepNum, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

    //步骤2内容
    ui_LableExtrudeSecondStepNum = lv_label_create(ui_PanelExtrudeProccessInfo);
    lv_obj_set_width(ui_LableExtrudeSecondStepNum, 140);
    lv_obj_set_height(ui_LableExtrudeSecondStepNum, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_LableExtrudeSecondStepNum, 43);
    lv_obj_set_y(ui_LableExtrudeSecondStepNum, 102);
    lv_label_set_text(ui_LableExtrudeSecondStepNum, FilamentIning[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LableExtrudeSecondStepNum, lv_color_hex(0x9A9DA0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableExtrudeSecondStepNum, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableExtrudeSecondStepNum, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LableExtrudeSecondStepNum, LV_LABEL_LONG_WRAP);

    //连接线
    ui_CableExtrudeSecondStep = lv_obj_create(ui_PanelExtrudeProccessInfo);
    lv_obj_set_width(ui_CableExtrudeSecondStep, 3);
    lv_obj_set_height(ui_CableExtrudeSecondStep, 59);
    lv_obj_set_x(ui_CableExtrudeSecondStep, 22);
    lv_obj_set_y(ui_CableExtrudeSecondStep, 128);
    lv_obj_clear_flag(ui_CableExtrudeSecondStep, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CableExtrudeSecondStep, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CableExtrudeSecondStep, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CableExtrudeSecondStep, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_CableExtrudeSecondStep, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_CableExtrudeSecondStep, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CableExtrudeSecondStep, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_CableExtrudeSecondStep, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    //圆圈3
    ui_RoundExtrudeThirdStepNum = lv_obj_create(ui_PanelExtrudeProccessInfo);
    lv_obj_set_width(ui_RoundExtrudeThirdStepNum, 30);
    lv_obj_set_height(ui_RoundExtrudeThirdStepNum, 30);
    lv_obj_set_x(ui_RoundExtrudeThirdStepNum, 9);
    lv_obj_set_y(ui_RoundExtrudeThirdStepNum, 187);
    lv_obj_add_flag(ui_RoundExtrudeThirdStepNum, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_RoundExtrudeThirdStepNum, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_RoundExtrudeThirdStepNum, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RoundExtrudeThirdStepNum, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RoundExtrudeThirdStepNum, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_RoundExtrudeThirdStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_RoundExtrudeThirdStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_RoundExtrudeThirdStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //步骤“3”
    ui_LableExtrudeThirdStepNum = lv_label_create(ui_RoundExtrudeThirdStepNum);
    lv_obj_set_width(ui_LableExtrudeThirdStepNum, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LableExtrudeThirdStepNum, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LableExtrudeThirdStepNum, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LableExtrudeThirdStepNum, "3");
    lv_obj_set_style_text_font(ui_LableExtrudeThirdStepNum, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LableExtrudeThirdStepNum, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LableExtrudeThirdStepNum = lv_label_create(ui_PanelExtrudeProccessInfo);
    // lv_obj_set_width(ui_LableExtrudeThirdStepNum, 29);
    // lv_obj_set_height(ui_LableExtrudeThirdStepNum, 29);
    // lv_obj_set_x(ui_LableExtrudeThirdStepNum, 9);
    // lv_obj_set_y(ui_LableExtrudeThirdStepNum, 187);
    // lv_obj_add_flag(ui_LableExtrudeThirdStepNum, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    // lv_obj_clear_flag(ui_LableExtrudeThirdStepNum, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ui_LableExtrudeThirdStepNum, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_LableExtrudeThirdStepNum, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_LableExtrudeThirdStepNum, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_width(ui_LableExtrudeThirdStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_spread(ui_LableExtrudeThirdStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ui_LableExtrudeThirdStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);


    //步骤3内容
    ui_LableExtrudeThirdStepContent = lv_label_create(ui_PanelExtrudeProccessInfo);
    lv_obj_set_width(ui_LableExtrudeThirdStepContent, 140);
    lv_obj_set_height(ui_LableExtrudeThirdStepContent, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_LableExtrudeThirdStepContent, 43);
    lv_obj_set_y(ui_LableExtrudeThirdStepContent, 188);
    lv_label_set_text(ui_LableExtrudeThirdStepContent, "Third Step");
    lv_obj_set_style_text_color(ui_LableExtrudeThirdStepContent, lv_color_hex(0x9A9DA0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableExtrudeThirdStepContent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableExtrudeThirdStepContent, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LableExtrudeSecondStepNum, LV_LABEL_LONG_WRAP);

    //退料进度信息面板
    ui_PanelRetractProccessInfo = lv_obj_create(ui_PanelInfoExtrudeRetract);
    lv_obj_set_size(ui_PanelRetractProccessInfo, 185, 280);
    lv_obj_set_align(ui_PanelRetractProccessInfo, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelRetractProccessInfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelRetractProccessInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelRetractProccessInfo, lv_color_hex(0x1C1C1E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelRetractProccessInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelRetractProccessInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelRetractProccessInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelRetractProccessInfo, LV_OBJ_FLAG_HIDDEN);

    //圆圈1
    ui_RoundRetractFirstStepNum = lv_obj_create(ui_PanelRetractProccessInfo);
    lv_obj_set_width(ui_RoundRetractFirstStepNum, 30);
    lv_obj_set_height(ui_RoundRetractFirstStepNum, 30);
    lv_obj_set_x(ui_RoundRetractFirstStepNum, 9);
    lv_obj_set_y(ui_RoundRetractFirstStepNum, 17);
    lv_obj_add_flag(ui_RoundRetractFirstStepNum, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_RoundRetractFirstStepNum, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_RoundRetractFirstStepNum, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RoundRetractFirstStepNum, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RoundRetractFirstStepNum, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_RoundRetractFirstStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_RoundRetractFirstStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_RoundRetractFirstStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //"1" lable
    ui_LableRetractFirstStepNum = lv_label_create(ui_RoundRetractFirstStepNum);
    lv_obj_set_width(ui_LableRetractFirstStepNum, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LableRetractFirstStepNum, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LableRetractFirstStepNum, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LableRetractFirstStepNum, "1");
    lv_obj_set_style_text_font(ui_LableRetractFirstStepNum, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LableRetractFirstStepNum, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //步骤1内容
    ui_LableRetractFirstStepContent = lv_label_create(ui_PanelRetractProccessInfo);
    lv_obj_set_width(ui_LableRetractFirstStepContent, 140);
    lv_obj_set_height(ui_LableRetractFirstStepContent, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_LableRetractFirstStepContent, 43);
    lv_obj_set_y(ui_LableRetractFirstStepContent, 19);
    lv_label_set_text(ui_LableRetractFirstStepContent, HotendHeating[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LableRetractFirstStepContent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableRetractFirstStepContent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableRetractFirstStepContent, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LableRetractFirstStepContent, LV_LABEL_LONG_WRAP);

    //连接线
    ui_CableRetractFirstStep = lv_obj_create(ui_PanelRetractProccessInfo);
    lv_obj_set_width(ui_CableRetractFirstStep, 3);
    lv_obj_set_height(ui_CableRetractFirstStep, 54);
    lv_obj_set_x(ui_CableRetractFirstStep, 22);
    lv_obj_set_y(ui_CableRetractFirstStep, 43);
    lv_obj_clear_flag(ui_CableRetractFirstStep, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CableRetractFirstStep, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CableRetractFirstStep, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CableRetractFirstStep, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_CableRetractFirstStep, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_CableRetractFirstStep, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CableRetractFirstStep, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_CableRetractFirstStep, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    //圆圈2
    ui_RoundRetractSecondStepNum = lv_obj_create(ui_PanelRetractProccessInfo);
    lv_obj_set_width(ui_RoundRetractSecondStepNum, 30);
    lv_obj_set_height(ui_RoundRetractSecondStepNum, 30);
    lv_obj_set_x(ui_RoundRetractSecondStepNum, 9);
    lv_obj_set_y(ui_RoundRetractSecondStepNum, 94);
    lv_obj_add_flag(ui_RoundRetractSecondStepNum, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_RoundRetractSecondStepNum, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_RoundRetractSecondStepNum, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RoundRetractSecondStepNum, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RoundRetractSecondStepNum, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_RoundRetractSecondStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_RoundRetractSecondStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_RoundRetractSecondStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //步骤“2”
    ui_LableRetractSecondStepNum = lv_label_create(ui_RoundRetractSecondStepNum);
    lv_obj_set_width(ui_LableRetractSecondStepNum, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LableRetractSecondStepNum, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LableRetractSecondStepNum, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LableRetractSecondStepNum, "2");
    lv_obj_set_style_text_font(ui_LableRetractSecondStepNum, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LableRetractSecondStepNum, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

    //步骤2内容
    ui_LableRetractSecondStepContent = lv_label_create(ui_PanelRetractProccessInfo);
    lv_obj_set_width(ui_LableRetractSecondStepContent, 140);
    lv_obj_set_height(ui_LableRetractSecondStepContent, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_LableRetractSecondStepContent, 43);
    lv_obj_set_y(ui_LableRetractSecondStepContent, 96);
    lv_label_set_text(ui_LableRetractSecondStepContent, FilamentOutPrep[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LableRetractSecondStepContent, lv_color_hex(0x9A9DA0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableRetractSecondStepContent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableRetractSecondStepContent, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LableRetractSecondStepContent, LV_LABEL_LONG_WRAP);

    //连接线
    ui_CableRetractSecondStep = lv_obj_create(ui_PanelRetractProccessInfo);
    lv_obj_set_width(ui_CableRetractSecondStep, 3);
    lv_obj_set_height(ui_CableRetractSecondStep, 59);
    lv_obj_set_x(ui_CableRetractSecondStep, 22);
    lv_obj_set_y(ui_CableRetractSecondStep, 118);
    lv_obj_clear_flag(ui_CableRetractSecondStep, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CableRetractSecondStep, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CableRetractSecondStep, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CableRetractSecondStep, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_CableRetractSecondStep, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_CableRetractSecondStep, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CableRetractSecondStep, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_CableRetractSecondStep, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    //圆圈3
    ui_RoundRetractThirdStepNum = lv_obj_create(ui_PanelRetractProccessInfo);
    lv_obj_set_width(ui_RoundRetractThirdStepNum, 30);
    lv_obj_set_height(ui_RoundRetractThirdStepNum, 30);
    lv_obj_set_x(ui_RoundRetractThirdStepNum, 9);
    lv_obj_set_y(ui_RoundRetractThirdStepNum, 170);
    lv_obj_add_flag(ui_RoundRetractThirdStepNum, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_RoundRetractThirdStepNum, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_RoundRetractThirdStepNum, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RoundRetractThirdStepNum, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RoundRetractThirdStepNum, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_RoundRetractThirdStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_RoundRetractThirdStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_RoundRetractThirdStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //步骤“3”
    ui_LableRetractThirdStepNum = lv_label_create(ui_RoundRetractThirdStepNum);
    lv_obj_set_width(ui_LableRetractThirdStepNum, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LableRetractThirdStepNum, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LableRetractThirdStepNum, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LableRetractThirdStepNum, "3");
    lv_obj_set_style_text_font(ui_LableRetractThirdStepNum, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LableRetractThirdStepNum, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

    //步骤3内容
    ui_LableRetractThirdStepContent = lv_label_create(ui_PanelRetractProccessInfo);
    lv_obj_set_width(ui_LableRetractThirdStepContent, 140);
    lv_obj_set_height(ui_LableRetractThirdStepContent, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_LableRetractThirdStepContent, 43);
    lv_obj_set_y(ui_LableRetractThirdStepContent, 172);
    lv_label_set_text(ui_LableRetractThirdStepContent, "Third Step");
    lv_obj_set_style_text_color(ui_LableRetractThirdStepContent, lv_color_hex(0x9A9DA0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableRetractThirdStepContent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableRetractThirdStepContent, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LableRetractThirdStepContent, LV_LABEL_LONG_WRAP);

    //连接线
    ui_CableRetractThirdStep = lv_obj_create(ui_PanelRetractProccessInfo);
    lv_obj_set_width(ui_CableRetractThirdStep, 3);
    lv_obj_set_height(ui_CableRetractThirdStep, 59);
    lv_obj_set_x(ui_CableRetractThirdStep, 22);
    lv_obj_set_y(ui_CableRetractThirdStep, 197);
    lv_obj_clear_flag(ui_CableRetractThirdStep, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_CableRetractThirdStep, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CableRetractThirdStep, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CableRetractThirdStep, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_CableRetractThirdStep, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_CableRetractThirdStep, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CableRetractThirdStep, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_CableRetractThirdStep, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    //圆圈4
    ui_RoundRetractFourthStepNum = lv_obj_create(ui_PanelRetractProccessInfo);
    lv_obj_set_width(ui_RoundRetractFourthStepNum, 30);
    lv_obj_set_height(ui_RoundRetractFourthStepNum, 30);
    lv_obj_set_x(ui_RoundRetractFourthStepNum, 9);
    lv_obj_set_y(ui_RoundRetractFourthStepNum, 245);
    lv_obj_add_flag(ui_RoundRetractFourthStepNum, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_RoundRetractFourthStepNum, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_RoundRetractFourthStepNum, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_RoundRetractFourthStepNum, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RoundRetractFourthStepNum, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_RoundRetractFourthStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_RoundRetractFourthStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_RoundRetractFourthStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    //步骤“4”
    ui_LableRetractFourthStepNum = lv_label_create(ui_RoundRetractFourthStepNum);
    lv_obj_set_width(ui_LableRetractFourthStepNum, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LableRetractFourthStepNum, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LableRetractFourthStepNum, -2);
    lv_obj_set_y(ui_LableRetractFourthStepNum, -1);
    lv_obj_set_align(ui_LableRetractFourthStepNum, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LableRetractFourthStepNum, "4");
    lv_obj_set_style_text_font(ui_LableRetractFourthStepNum, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LableRetractFourthStepNum, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LableRetractFourthStepNum = lv_label_create(ui_PanelRetractProccessInfo);
    // lv_obj_set_width(ui_LableRetractFourthStepNum, 29);
    // lv_obj_set_height(ui_LableRetractFourthStepNum, 29);
    // lv_obj_set_x(ui_LableRetractFourthStepNum, 9);
    // lv_obj_set_y(ui_LableRetractFourthStepNum, 245);
    // lv_obj_add_flag(ui_LableRetractFourthStepNum, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    // lv_obj_clear_flag(ui_LableRetractFourthStepNum, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ui_LableRetractFourthStepNum, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_LableRetractFourthStepNum, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_LableRetractFourthStepNum, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // // lv_obj_set_style_shadow_width(ui_LableRetractFourthStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // // lv_obj_set_style_shadow_spread(ui_LableRetractFourthStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // // lv_obj_set_style_border_width(ui_LableRetractFourthStepNum, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_label_set_text(ui_LableRetractFourthStepNum, "4");
    // lv_obj_set_style_text_font(ui_LableRetractFourthStepNum, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_color(ui_LableRetractFourthStepNum, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_LableRetractFourthStepNum, LV_ALIGN_TOP_MID, LV_PART_MAIN | LV_STATE_DEFAULT);

    //步骤4内容
    ui_LableRetractFourthStepContent = lv_label_create(ui_PanelRetractProccessInfo);
    lv_obj_set_width(ui_LableRetractFourthStepContent, 140);
    lv_obj_set_height(ui_LableRetractFourthStepContent, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_LableRetractFourthStepContent, 43);
    lv_obj_set_y(ui_LableRetractFourthStepContent, 247);
    lv_label_set_text(ui_LableRetractFourthStepContent, FilamentOutEnd[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LableRetractFourthStepContent, lv_color_hex(0x9A9DA0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LableRetractFourthStepContent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LableRetractFourthStepContent, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_LableRetractFourthStepContent, LV_LABEL_LONG_WRAP);

    //子页，冷却页，风扇控制页
    ui_CoolSubPage_init(ui_ScreenAxisMovePage);

    lv_obj_add_event_cb(ui_ExtrudeRetractBackBtn, ui_event_ExtrudeRetractBackBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelHotendTemp, ui_event_PanelHotendTemp, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BntExtrude, ui_event_ExtrudeBtn, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BntRetract, ui_event_RetractBtn, LV_EVENT_ALL, NULL);


    encode_display_timer = lv_timer_create(Encoder_timeout_cb, 300, NULL);
   // lv_timer_set_repeat_count(encode_display_timer, -1);
    lv_timer_pause(encode_display_timer);

}
lv_timer_t * AxisMoveNavTimer;
void AxisMoveNavTimerCb(lv_timer_t * timer)
{
  /*Use the user_data*/
    lv_group_focus_freeze(encoder_group, false);
    lv_timer_del(AxisMoveNavTimer);
}

void ui_event_update_AxisMove_page(lv_event_t * e)
{
    bool IsEntered = false;
	lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_SHORT_CLICKED) {
        //printf("ui_event_ButtonServicePage\n");
        
        IsEntered = AxisMove.stateValue;
        IsEntered = !IsEntered;
        LoadAxixMoveScreenAndObjs(IsEntered);
       
    }
    // if(event_code == LV_EVENT_DEFOCUSED)
    // {
    //     if (AxisMove.stateValue)
    //     {
    //         lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveAxisMove, &ui_img_pagemoveselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     }
    // }
    // if(event_code == LV_EVENT_FOCUSED)
    // {
    //     //lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveAxisMove, &ui_img_pagemoveselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     // if (AxisMove.stateValue)
    //     // {
    //     //     lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveAxisMove, &ui_img_pagemovefocus_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    //     //     if (page_manager.objFreezzFlag == false)
    //     //     {
    //     //         page_manager.objFreezzFlag = true;
    //     //     }
    //     //     else if (page_manager.objFreezzFlag == true)
    //     //     {
    //     //         lv_group_focus_freeze(encoder_group, true);
    //     //         AxisMoveNavTimer = lv_timer_create(AxisMoveNavTimerCb, 300,  NULL);
    //     //     }
    //     // }    
    // }
}


void LoadAxisMoveScreen(void)
{
    CrLogI("load the axismove page");
    lv_disp_load_scr(ui_ScreenAxisMovePage);
    /******************************************************************/
    // RefreshModelFanFlag = true;
    send_get_fans_status_cmd();
    // send_get_light_status_cmd();
    send_get_axis_home_status_cmd();
    send_get_print_status();
    get_printer_data(CONTROL_HOT_BED_TEMP, 2, "\0");    //获取温度
    get_printer_data(CONTROL_XYZ_AXIS_RANGE, 2, "1");    //获取xyz轴的移动范围
    axis_move_set_bed_temper(bed_temper_move, bed_target_temper_move);
    axis_move_set_hotend_temper(hotend_temper_move, hotend_target_temper_move);
}

void MovePageCoolBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadCoolScreen();
}

void MovePageStepperDisableBtnClicked(lv_event_t * e)
{
	// Your code here
    if (OperableFlag)
    {
        home_flag = 0;
        send_set_disable_stepper_cmd();
    }
    else
    {
        create_msgbox(PrintingTips[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
    }
}

void MovePageExtrudeRetractBtnClicked(lv_event_t * e)
{
	// Your code here
    // if (OperableFlag)
    // {
        char buf[256] = {0};
        sprintf(buf, HotTips[get_cur_language_index()], atoi(lv_label_get_text(ui_LableHotendTemp)));
        lv_label_set_text(ui_LableTipInfoContent, buf);
        add_3rd_level_nav_objs = AddExtrudeRetractNavObjs;
        lv_obj_add_flag(ui_PanelMoveAndTemper, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_PanelExtrudeRetract, LV_OBJ_FLAG_HIDDEN);
        if (filament_action == FILA_ACTION_NONE)
        {
            show_proccess_panel(PROMPT_STATE_TIP);
            show_temper_panel(SHOW_TEMPER_EDIT_PANEL);
        }
        LoadPage(ui_ScreenAxisMovePage, 3);
    // }
    // else
    // {
    //     create_msgbox(PrintingTips[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
    // }
}

void JudgeAxisRangeOut(axis_type_t Axis, float *distance, int direction)//direction （1:+ 0：-）
{
    float dis = *distance;
    float position = 0.0f;
    float limitmin = 0.0f;
    float limitmax = 0.0f;
    int speed = 0;

    CrLogI("distance = %f direction = %d\n", dis, direction);

    if (direction == 0)dis = -dis;
    switch (Axis)
    {
        case AXIS_X:
        {
            position = atof(cur_xposition);
            speed = axis_move_feedrate_xy;
            limitmin = (system_state.X_Axis_Min / 100.0f);
            limitmax = (system_state.X_Axis_Max / 100.0f);
            break;
        }
        case AXIS_Y:
        {
            position = atof(cur_yposition); 
            speed = axis_move_feedrate_xy;
            limitmin = (system_state.Y_Axis_Min / 100.0f);
            limitmax = (system_state.Y_Axis_Max / 100.0f);
            break;
        }
        case AXIS_Z: 
        {
            position = atof(cur_zposition);
            speed = axis_move_feedrate_z; 
            limitmin = (system_state.Z_Axis_Min / 100.0f);
            limitmax = (system_state.Z_Axis_Max / 100.0f);
            break;
        }
        default:CrLogE("don't have axis data");return;break;
    }

    CrLogI("Axis:%d dis:%f, position:%f, limitmin:%f, limitmax:%f", Axis, dis, position, limitmin, limitmax);
    // printf("Axis:%d dis:%f, position:%f, limitmin:%f, limitmax:%f\n", Axis, dis, position, limitmin, limitmax);
    if(position + dis <= limitmax && position + dis >= limitmin)
    {
        send_set_axis_move_opt_cmd(Axis, direction, *distance, speed);
    }
    else if(position + dis < limitmin)
    {
        if(position - limitmin <= 0.1f)//相差0.1以内认为已经到了零点
        {
            create_msgbox(MoveAxisTips[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
            return;
        }
        *distance = (int)((position -  limitmin) * 100) / 100.0f;//精度只到小数点后两位

        send_set_axis_move_opt_cmd(Axis, direction, *distance, speed);
    }
    else if(position + dis > limitmax)
    {
        if(limitmax + 0.5 - position <= 0.1f)//相差0.1以内认为已经到了零点
        {
            create_msgbox(MoveAxisTips2[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
            return;
        }
        *distance = (int)((limitmax - position) * 100) / 100.0f;//精度只到小数点后两位

        CrLogI("step : %f, curpos : %f", *distance, position);
        send_set_axis_move_opt_cmd(Axis, direction, *distance, speed);
    }
}

void MovePageHomeXYBtnClicked(lv_event_t * e)
{
    if (OperableFlag)
    {
        home_action |= 0x03;
        send_set_axis_home_cmd(true, true, false);
    }
    else
    {
        create_msgbox(PrintingTips[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
    }
}

void MovePageHomeZBtnClicked(lv_event_t * e)
{
	// Your code here
    if ( !(home_flag & 0x01) || !(home_flag & 0x02) )
    {
        char buff[80] = {0};
        sprintf(buff, "XY%s", NotHomedMsg[get_cur_language_index()]);
        // create_custom_reminderbox("请先归位XY轴!", false);
        // set_custom_reminderbox_clickable(false);
        // set_custom_reminderbox_display_timeout(3, NULL);
        create_msgbox(buff, NULL,  1000 * 2, lv_layer_top());
        return ;
    }

    if (OperableFlag)
    {
        home_action |= 0x04;
        send_set_axis_home_cmd(false, false, true);
    }
    else
    {
        create_msgbox(PrintingTips[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
    }
}

void show_hotend_heating_status_screen_move(bool show)
{
    // if ( show )
    // {
    //     lv_obj_add_flag(ui_PanelHotend, LV_OBJ_FLAG_HIDDEN); 
    //     lv_obj_clear_flag(ui_PanelHotendHeatingScreenMove, LV_OBJ_FLAG_HIDDEN);
    // }
    // else
    // {
    //     lv_obj_add_flag(ui_PanelHotendHeatingScreenMove, LV_OBJ_FLAG_HIDDEN); 
    //     lv_obj_clear_flag(ui_PanelHotend, LV_OBJ_FLAG_HIDDEN);
    // }
}

void show_bed_heating_status_screen_move(bool show)
{
    // if ( show )
    // {
    //     lv_obj_add_flag(ui_PanelBed, LV_OBJ_FLAG_HIDDEN); 
    //     lv_obj_clear_flag(ui_PanelBedHeatingScreenMove, LV_OBJ_FLAG_HIDDEN);
    // }
    // else
    // {
    //     lv_obj_add_flag(ui_PanelBedHeatingScreenMove, LV_OBJ_FLAG_HIDDEN); 
    //     lv_obj_clear_flag(ui_PanelBed, LV_OBJ_FLAG_HIDDEN);
    // }
}

void axis_move_set_hotend_temper(int16_t curTemper, int16_t targetTemper)
{
    char buff[10] = {0};
    sprintf(buff, "%d", curTemper);
    lv_label_set_text(ui_LabelCurTemperScreenMove, buff);
    //lv_label_set_text(ui_LabelTemperScreenMove, buff);
    hotend_temper_move = curTemper;

    sprintf(buff, "%d", targetTemper);
    lv_label_set_text(ui_LabelTargetTemperScreenMove, buff);
    hotend_target_temper_move = targetTemper;
    
    // 动态修改温度值对齐
    if (!lv_group_get_editing(encoder_group)) //编辑模式不刷新
    {
         if (targetTemper < 10)
        {
            lv_obj_align(ui_LabelCurTemperScreenMove, LV_ALIGN_RIGHT_MID, -72, -4);
            lv_obj_align(ui_LabelLeftSlashScreenMove, LV_ALIGN_RIGHT_MID, -59, -6);
        }
        else if (targetTemper < 100) {
            lv_obj_align(ui_LabelCurTemperScreenMove, LV_ALIGN_RIGHT_MID, -86, -4);
            lv_obj_align(ui_LabelLeftSlashScreenMove, LV_ALIGN_RIGHT_MID, -73, -6);
        }
        else if (targetTemper >= 100) {
            lv_obj_align(ui_LabelCurTemperScreenMove, LV_ALIGN_RIGHT_MID, -99, -4);
            lv_obj_align(ui_LabelLeftSlashScreenMove, LV_ALIGN_RIGHT_MID, -86, -6);
        }
    }

    static int NozzleHeatingcountAxisMove = 0;
    if(targetTemper == 0)
    {
        show_hotend_heating_status_screen_move(false);
        return;
    }
    if(abs(curTemper - targetTemper) <= 2)
    {
        NozzleHeatingcountAxisMove++;
        if(NozzleHeatingcountAxisMove >= 20)
        {
            CrLogI("hide the target temp,count %d.", NozzleHeatingcountAxisMove);
            show_hotend_heating_status_screen_move(false);
            NozzleHeatingcountAxisMove = 0;
        }
    }
    else
    {
        NozzleHeatingcountAxisMove = 0;
        show_hotend_heating_status_screen_move(true);
    }
}

void axis_move_set_bed_temper(int16_t curTemper, int16_t targetTemper)
{
    char buff[10] = {0};
    sprintf(buff, "%d", curTemper);
    //lv_label_set_text(ui_LabelBedTemperScreenMove, buff);
    lv_label_set_text(ui_LabelBedCurTemperScreenMove, buff);
    bed_temper_move = curTemper;

    sprintf(buff, "%d", targetTemper);
    lv_label_set_text(ui_LabelBedTargetTemperScreenMove, buff);
    bed_target_temper_move = targetTemper;

    // 动态修改温度值对齐
    if (!lv_group_get_editing(encoder_group)) //编辑模式不刷新
    {
         if (targetTemper < 10)
        {
            lv_obj_align(ui_LabelBedCurTemperScreenMove, LV_ALIGN_RIGHT_MID, -72, -4);
            lv_obj_align(ui_LabelBedLeftSlashScreenMove, LV_ALIGN_RIGHT_MID, -59, -6);
        }
        else if (targetTemper < 100) {
            lv_obj_align(ui_LabelBedCurTemperScreenMove, LV_ALIGN_RIGHT_MID, -86, -4);
            lv_obj_align(ui_LabelBedLeftSlashScreenMove, LV_ALIGN_RIGHT_MID, -73, -6);
        }
        else if (targetTemper >= 100) {
            lv_obj_align(ui_LabelBedCurTemperScreenMove, LV_ALIGN_RIGHT_MID, -99, -4);
            lv_obj_align(ui_LabelBedLeftSlashScreenMove, LV_ALIGN_RIGHT_MID, -86, -6);
        }
    }

    static int BedHeatingcountAxisMove = 0;
    if(targetTemper == 0)
    {
        show_bed_heating_status_screen_move(false);
        return;
    }
    if(abs(curTemper - targetTemper) <= 2)
    {
        BedHeatingcountAxisMove++;
        if(BedHeatingcountAxisMove >= 20)
        {
            BedHeatingcountAxisMove = 0;
            show_bed_heating_status_screen_move(false);
        }
    }
    else
    {
        BedHeatingcountAxisMove = 0;
        show_bed_heating_status_screen_move(true);
    }
}

void axis_move_set_chassis_temper(int16_t Temper)
{
    if ( ui_LabelThermostatTemperScreenMove )
    {
        char buff[20] = {0};
        sprintf(buff, "%d", Temper);
        lv_label_set_text(ui_LabelThermostatTemperScreenMove, buff);
    }
    
}

void axis_move_set_fan_status(bool opened)
{
    // model_fan_opened = opened;
    // if ( ui_ImgButtonModeFan )
    //     model_fan_opened ? lv_obj_add_flag(ui_ImgButtonModeFan, LV_OBJ_FLAG_HIDDEN): 
    //                         lv_obj_clear_flag(ui_ImgButtonModeFan, LV_OBJ_FLAG_HIDDEN);
    // if ( ui_GifButtonModeFan )
    //     model_fan_opened ? lv_obj_clear_flag(ui_GifButtonModeFan, LV_OBJ_FLAG_HIDDEN): 
    //                         lv_obj_add_flag(ui_GifButtonModeFan, LV_OBJ_FLAG_HIDDEN);
}

void axis_move_set_home_status(bool x_home_flag, bool y_home_flag, bool z_home_flag)
{
    if ( x_home_flag )
    {
        if ( home_action & 0x01 )
        {
            home_action &= 0xFE;
        }

        home_flag |= 0x01;
    }

    if ( y_home_flag )
    {
        if ( home_action & 0x02 )
        {
            home_action &= 0xFD;
        }

        home_flag |= 0x02;
    }

    if ( z_home_flag )
    {
        if ( home_action & 0x04 )
        {
            home_action &= 0xFB;
        }

        home_flag |= 0x04;
    }

    //if ( home_printing_is_printing_finished() )
    
    axis_move_change_move_btns_status(home_flag);
}

void axis_move_change_move_btns_status(int8_t axis_home_flag)
{
    /*第1个bit位表示X轴归零标识（1：归零， 0未归零），
    第2个bit位表示Y轴归零标识（1：归零， 0未归零），
    第3个bit位表示Z轴归零标识（1：归零， 0未归零）*/
    // if ( axis_home_flag & 0x01 )
    // {
    //     lv_obj_add_flag(ui_ButtonAddXScreenMove, LV_OBJ_FLAG_CLICKABLE);
    //     lv_obj_add_flag(ui_ButtonSubXScreenMove, LV_OBJ_FLAG_CLICKABLE);
    // }
    // else
    // {
    //     lv_obj_clear_flag(ui_ButtonAddXScreenMove, LV_OBJ_FLAG_CLICKABLE);
    //     lv_obj_clear_flag(ui_ButtonSubXScreenMove, LV_OBJ_FLAG_CLICKABLE);
    // }

    // if ( axis_home_flag & 0x02 )
    // {
    //     lv_obj_add_flag(ui_ButtonAddYScreenMove, LV_OBJ_FLAG_CLICKABLE);
    //     lv_obj_add_flag(ui_ButtonSubYScreenMove, LV_OBJ_FLAG_CLICKABLE);
    // }
    // else
    // {
    //     lv_obj_clear_flag(ui_ButtonAddYScreenMove, LV_OBJ_FLAG_CLICKABLE);
    //     lv_obj_clear_flag(ui_ButtonSubYScreenMove, LV_OBJ_FLAG_CLICKABLE);
    // }

    // if ( axis_home_flag & 0x04 )
    // {
    //     lv_obj_add_flag(ui_PanelUpperZ, LV_OBJ_FLAG_CLICKABLE);
    //     lv_obj_add_flag(ui_PanelDownZ, LV_OBJ_FLAG_CLICKABLE);
    // }
    // else
    // {
    //     lv_obj_clear_flag(ui_PanelUpperZ, LV_OBJ_FLAG_CLICKABLE);
    //     lv_obj_clear_flag(ui_PanelDownZ, LV_OBJ_FLAG_CLICKABLE);
    // }

}

void axis_move_set_homing_status(uint8_t homing_status)
{
    // '0':失败，'1'：成功，'2'：正在进行归零中
    uint8_t language_index = get_cur_language_index();
    if ( homing_status == '2' )
    {
        // create_custom_reminderbox(HomeMsg[language_index], false);
        // set_custom_reminderbox_clickable(false);
        // set_custom_reminderbox_display_timeout(30, NULL);
        create_msgbox(HomeMsg[language_index], NULL, 0, lv_scr_act());
    }
    else
    {
        // close_custom_reminderbox();
        create_msgbox(HomeMsg[language_index], NULL, 500, lv_scr_act());
    }

    if ( homing_status == '0' )
    {
        // create_custom_reminderbox(HomeFailedMsg[language_index], false);
        // set_custom_reminderbox_clickable(false);
        // set_custom_reminderbox_display_timeout(3, NULL);
        create_msgbox(HomeFailedMsg[language_index], NULL, 2000, lv_scr_act());
    }
}


void axis_move_set_print_status(int8_t print_status)
{
    // 0: finished, 1:stoped, 2:paused, 3:printing,6:温度升温中  依赖于协议
    if ( (print_status == 2) || (print_status == 3) || (print_status == 6) )  
    {
        //不可以操作
        OperableFlag = false;
    }
    else if ( (print_status == 0) || (print_status == 1) )
    {
        //可操作
        OperableFlag = true;
    }
}

void axis_move_change_language_text(void)
{
    if ( ui_LabelCtrlTitle )
        lv_label_set_text(ui_LabelCtrlTitle, Control[get_cur_language_index()]);
    if ( LableHotendTemp )
        lv_label_set_text(LableHotendTemp, HotendTemp[get_cur_language_index()]);
    if ( LableBedTemp )
        lv_label_set_text(LableBedTemp, Bed_temp[get_cur_language_index()]);
    if ( LableHomeXY )
        lv_label_set_text(LableHomeXY, XY_HomeArray[get_cur_language_index()]);
    if ( LableHomeZ )
        lv_label_set_text(LableHomeZ, Z_HomeArray[get_cur_language_index()]);
    if ( LableXAxisMove )
        lv_label_set_text(LableXAxisMove, X_AxisMove[get_cur_language_index()]);
    if ( LableYAxisMove )
        lv_label_set_text(LableYAxisMove, Y_AxisMove[get_cur_language_index()]);
    if ( LableZAxisMove )
        lv_label_set_text(LableZAxisMove, Z_AxisMove[get_cur_language_index()]);
    if ( LableTurnOffTheMotor )
        lv_label_set_text(LableTurnOffTheMotor, Turn_off_the_motor[get_cur_language_index()]);
    if ( LableInOrOutMaterial )
        lv_label_set_text(LableInOrOutMaterial, Extrude_Retract[get_cur_language_index()]);
    if ( LableFan )
        lv_label_set_text(LableFan, Fans[get_cur_language_index()]);
    if ( LableModelFan )
        lv_label_set_text(LableModelFan, ModelFans[get_cur_language_index()]);
    if ( LableAuxiliaryFan )
        lv_label_set_text(LableAuxiliaryFan, CoolFan[get_cur_language_index()]);

    // if (ui_LableCoolSubPageTitle)
    //     lv_label_set_text(ui_LableCoolSubPageTitle, Fans[get_cur_language_index()]);


    axis_move_filament_infor_change_language_text();
}

void refresh_xyz_value(int x_value, int y_value, int z_value)
{
    char num[20] = {0};
    x_cur_pos = x_value;
    // if ( x_value > 220 )
    //   x_value = 220;

    y_cur_pos = y_value;
    // if ( y_value > 220 )
    //   y_value = 220;

    z_cur_pos = z_value;
    // if ( z_value > 250 )
    //   z_value = 250;

    memset(num, 0, 20);
    sprintf(num, "%d", x_value);
    //printf("x_value = %d\n",x_value);
    lv_label_set_text(ui_XAxisMoveValLabel, num);

    memset(num, 0, 20);
    sprintf(num, "%d", y_value);
    // printf("y_value = %d\n",y_value);
    lv_label_set_text(ui_YAxisMoveValLabel, num);

    memset(num, 0, 20);
    sprintf(num, "%d", z_value);
    //printf("z_value = %d\n",z_value);
    lv_label_set_text(ui_ZAxisMoveValLabel, num);
}

void refresh_fan_value(int fanvalue)
{
    model_fan_speed = fanvalue;
    if ( fanvalue > 100 )
      fanvalue = 100;

    char buff[5] = {0};
    sprintf(buff, "%d%%", fanvalue); 
    //printf("fanvalue:%d\n",fanvalue);
   // lv_label_set_text(ui_ModelFanLabel, buff);
    //lv_label_set_text(ui_ModelFanValLabel, buff);
}

void axis_move_set_model_fan_duty_percent(uint8_t percent)
{
    if ( percent > 100 )
        percent = 100;

    char buff[5] = {0};

#ifdef FAN_CONTROL_A
    if (percent <= 40)
    {
        show_percent = 0;
    }
    else
    {
        show_percent = ((double)percent - FanMinDutyValue) / (100.0 - FanMinDutyValue) * 100.0;
    }
    sprintf(buff, "%d%%", show_percent); 
    printf("real_percent %d, show_percent %d\n", percent, show_percent);
#else
    sprintf(buff, "%d%%", percent); 
#endif

    if (!lv_group_get_editing(encoder_group))
    {
        //RefreshModelFanFlag = false;
        lv_label_set_text(ui_ModelFanValLabel, buff);
        lv_label_set_text(ui_ModelFanValSetLabel, buff);
    }
}

void axis_move_set_z_move_forward_dir(uint8_t dir)   
{
    //0:正向，1：反向. 
    z_move_forward_dir = dir;
}

static ctrl_list_t *create_ctrl_list_item(lv_obj_t *parent, uint8_t index, int16_t pos_x, int16_t pos_y, void (*part_event_callback)(lv_event_t *))
{
    ctrl_list_t *part = (ctrl_list_t *)lv_mem_alloc(sizeof(ctrl_list_t));
    if ( !part )
        return NULL;

    lv_obj_t * ui_CtrlItemPanelInfo = lv_obj_create(parent);
    lv_obj_set_width(ui_CtrlItemPanelInfo, 545);//534
    lv_obj_set_height(ui_CtrlItemPanelInfo, 56);
    lv_obj_set_x(ui_CtrlItemPanelInfo, pos_x);
    lv_obj_set_y(ui_CtrlItemPanelInfo, pos_y);
    lv_obj_add_flag(ui_CtrlItemPanelInfo, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    //lv_obj_align_to(ui_CtrlItemPanelInfo, ui_CtrlstitleSystem, LV_ALIGN_TOP_LEFT, 10, 10);
   // lv_obj_align(ui_CtrlItemPanelInfo, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_clear_flag(ui_CtrlItemPanelInfo, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_set_style_bg_color(ui_CtrlItemPanelInfo, lv_color_hex(0x18181B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CtrlItemPanelInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CtrlItemPanelInfo, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CtrlItemPanelInfo, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_CtrlItemPanelInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_CtrlItemPanelInfo, 4, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_pad_all(ui_CtrlItemPanelInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //选中后样式设置
    //lv_obj_set_style_border_width(ui_CtrlItemPanelInfo, 3, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui_CtrlItemPanelInfo, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_CtrlItemPanelInfo, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_CtrlItemPanelInfo, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_CtrlItemPanelInfo, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
    part->part_panel = ui_CtrlItemPanelInfo;

    //列表图片
    lv_obj_t *ui_CtrlItemImage = lv_img_create(ui_CtrlItemPanelInfo);
    lv_obj_set_width(ui_CtrlItemImage, LV_SIZE_CONTENT);   
    lv_obj_set_height(ui_CtrlItemImage, LV_SIZE_CONTENT);    
    lv_obj_align(ui_CtrlItemImage, LV_ALIGN_LEFT_MID, 10, 0);
    //lv_obj_add_flag(ui_CtrlItemImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    //lv_obj_clear_flag(ui_CtrlItemImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_CtrlItemImage, lv_color_hex(0x000000),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_CtrlItemImage, 100, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_CtrlItemImage, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    part->image_item = ui_CtrlItemImage;
   
    //设置列表项名
    lv_obj_t * ui_CtrlItemName = lv_label_create(ui_CtrlItemPanelInfo);
    lv_obj_set_width(ui_CtrlItemName, LV_SIZE_CONTENT); //261
    lv_obj_set_height(ui_CtrlItemName, LV_SIZE_CONTENT); //30
    lv_obj_align(ui_CtrlItemName, LV_ALIGN_LEFT_MID, 50, 1);
    lv_label_set_text(ui_CtrlItemName,"");
     lv_obj_clear_flag(ui_CtrlItemName, LV_OBJ_FLAG_SCROLLABLE); 
   // lv_label_set_text(ui_CtrlItemName, ScreenModelFanArray[language_index]);
    lv_obj_set_style_text_color(ui_CtrlItemName, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CtrlItemName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_CtrlItemName, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CtrlItemName, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_CtrlItemName, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->label_item_name = ui_CtrlItemName;
    
    //右箭头图
    // lv_obj_t *ui_ImageArrow = lv_img_create(ui_CtrlItemPanelInfo);
    // lv_img_set_src(ui_ImageArrow, &ui_img_rightarrow_png);
    // lv_obj_set_width(ui_ImageArrow, 11);  //11 LV_SIZE_CONTENT
    // lv_obj_set_height(ui_ImageArrow, 21);    
    // lv_obj_align(ui_ImageArrow, LV_ALIGN_RIGHT_MID, -20, 0);
    // lv_obj_add_flag(ui_ImageArrow, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_ImageArrow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    // part->img_arrow_png = ui_ImageArrow;

    //设置列表内容
    lv_obj_t * ui_CtrlContentName = lv_label_create(ui_CtrlItemPanelInfo);
    lv_obj_set_width(ui_CtrlContentName, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_CtrlContentName, LV_SIZE_CONTENT); //39
    lv_obj_align(ui_CtrlContentName, LV_ALIGN_RIGHT_MID, -40, 1);
    //lv_obj_align_to(ui_CtrlContentName, ui_ImageArrow, LV_ALIGN_OUT_LEFT_MID, -20, 0);
    lv_label_set_text(ui_CtrlContentName,"");
    lv_obj_set_style_text_color(ui_CtrlContentName, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CtrlContentName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_CtrlContentName, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CtrlContentName, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_CtrlContentName, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_CtrlContentName, LV_OBJ_FLAG_SCROLLABLE);

    part->label_content_name = ui_CtrlContentName;

    part->index = index;
    lv_obj_add_event_cb(ui_CtrlItemPanelInfo, part_event_callback, LV_EVENT_ALL, part); //事件回调接口
    
    return part;
}

static ctrl_list_t *create_fan_ctrl_list_item(lv_obj_t *parent, uint8_t index, int16_t pos_x, int16_t pos_y, void (*part_event_callback)(lv_event_t *))
{
    ctrl_list_t *part = (ctrl_list_t *)lv_mem_alloc(sizeof(ctrl_list_t));
    if ( !part )
        return NULL;

    lv_obj_t * ui_CtrlItemPanelInfo = lv_obj_create(parent);
    lv_obj_set_width(ui_CtrlItemPanelInfo, 528);//534
    lv_obj_set_height(ui_CtrlItemPanelInfo, 56);
    lv_obj_set_x(ui_CtrlItemPanelInfo, pos_x);
    lv_obj_set_y(ui_CtrlItemPanelInfo, pos_y);
    lv_obj_add_flag(ui_CtrlItemPanelInfo, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    //lv_obj_align_to(ui_CtrlItemPanelInfo, ui_CtrlstitleSystem, LV_ALIGN_TOP_LEFT, 10, 10);
   // lv_obj_align(ui_CtrlItemPanelInfo, LV_ALIGN_TOP_LEFT, 10, 10);
    lv_obj_clear_flag(ui_CtrlItemPanelInfo, LV_OBJ_FLAG_SCROLLABLE); 
    lv_obj_set_style_bg_color(ui_CtrlItemPanelInfo, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CtrlItemPanelInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CtrlItemPanelInfo, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CtrlItemPanelInfo, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_CtrlItemPanelInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_CtrlItemPanelInfo, 4, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_set_style_pad_all(ui_CtrlItemPanelInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //选中后样式设置
    //lv_obj_set_style_border_width(ui_CtrlItemPanelInfo, 3, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_bg_color(ui_CtrlItemPanelInfo, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED); 
    lv_obj_set_style_border_width(ui_CtrlItemPanelInfo, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_CtrlItemPanelInfo, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_CtrlItemPanelInfo, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
    part->part_panel = ui_CtrlItemPanelInfo;

    //列表图片
    lv_obj_t *ui_CtrlItemImage = lv_img_create(ui_CtrlItemPanelInfo);
    lv_obj_set_width(ui_CtrlItemImage, LV_SIZE_CONTENT);   
    lv_obj_set_height(ui_CtrlItemImage, LV_SIZE_CONTENT);    
    lv_obj_align(ui_CtrlItemImage, LV_ALIGN_LEFT_MID, 10, 0);
    //lv_obj_add_flag(ui_CtrlItemImage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    //lv_obj_clear_flag(ui_CtrlItemImage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_CtrlItemImage, lv_color_hex(0x000000),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_CtrlItemImage, 100, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_CtrlItemImage, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    part->image_item = ui_CtrlItemImage;
   
    //设置列表项名
    lv_obj_t * ui_CtrlItemName = lv_label_create(ui_CtrlItemPanelInfo);
    lv_obj_set_width(ui_CtrlItemName, LV_SIZE_CONTENT); //261
    lv_obj_set_height(ui_CtrlItemName, LV_SIZE_CONTENT); //30
    lv_obj_align(ui_CtrlItemName, LV_ALIGN_LEFT_MID, 50, 1);
    lv_label_set_text(ui_CtrlItemName,"");
     lv_obj_clear_flag(ui_CtrlItemName, LV_OBJ_FLAG_SCROLLABLE); 
   // lv_label_set_text(ui_CtrlItemName, ScreenModelFanArray[language_index]);
    lv_obj_set_style_text_color(ui_CtrlItemName, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CtrlItemName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_CtrlItemName, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CtrlItemName, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_CtrlItemName, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->label_item_name = ui_CtrlItemName;
    
    //右箭头图
    // lv_obj_t *ui_ImageArrow = lv_img_create(ui_CtrlItemPanelInfo);
    // lv_img_set_src(ui_ImageArrow, &ui_img_rightarrow_png);
    // lv_obj_set_width(ui_ImageArrow, 11);  //11 LV_SIZE_CONTENT
    // lv_obj_set_height(ui_ImageArrow, 21);    
    // lv_obj_align(ui_ImageArrow, LV_ALIGN_RIGHT_MID, -20, 0);
    // lv_obj_add_flag(ui_ImageArrow, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_ImageArrow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    // part->img_arrow_png = ui_ImageArrow;

    //设置列表内容
    lv_obj_t * ui_CtrlContentName = lv_label_create(ui_CtrlItemPanelInfo);
    lv_obj_set_width(ui_CtrlContentName, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_CtrlContentName, LV_SIZE_CONTENT); //39
    lv_obj_align(ui_CtrlContentName, LV_ALIGN_RIGHT_MID, -40, 1);
    //lv_obj_align_to(ui_CtrlContentName, ui_ImageArrow, LV_ALIGN_OUT_LEFT_MID, -20, 0);
    lv_label_set_text(ui_CtrlContentName,"");
    lv_obj_set_style_text_color(ui_CtrlContentName, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_CtrlContentName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_CtrlContentName, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_CtrlContentName, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_CtrlContentName, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_CtrlContentName, LV_OBJ_FLAG_SCROLLABLE);

    part->label_content_name = ui_CtrlContentName;

    part->index = index;
    lv_obj_add_event_cb(ui_CtrlItemPanelInfo, part_event_callback, LV_EVENT_ALL, part); //事件回调接口
    
    return part;
}

static void show_step_round_state(lv_obj_t *step_round, bool is_start)
{
    if ( step_round )
    {
        if ( is_start )
            lv_obj_set_style_bg_color(step_round, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
        else
            lv_obj_set_style_bg_color(step_round, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}

static void show_step_label_state(lv_obj_t *step_label, bool is_start)
{
    if ( step_label )
    {
        if ( is_start )
            lv_obj_set_style_text_color(step_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        else
            lv_obj_set_style_text_color(step_label, lv_color_hex(0x9A9DA0), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}

static void show_step_dir_panel_state(lv_obj_t *step_dir, enum STEP_DIR_STATE state)
{
    if ( !step_dir )
        return;
    
    switch (state)
    {
    case STEP_NOT_START:
        {
            lv_obj_set_style_bg_color(step_dir, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(step_dir, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        break;
    case STEP_PROCCESSING:
        {
            lv_obj_set_style_bg_color(step_dir, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(step_dir, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        break;
    case STEP_FINISHED:
        {
            lv_obj_set_style_bg_color(step_dir, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(step_dir, LV_GRAD_DIR_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        break;

    default:
        break;
    }

}

void show_temper_panel(enum SHOW_TEMPER_PANEL panel)
{
    lv_obj_add_flag(ui_PanelHotendInitState, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_PanelHotendNormalState, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_PanelHotendHeatingState, LV_OBJ_FLAG_HIDDEN);
    
    switch (panel)
    {
    case SHOW_NORMAL_PANEL:
        {
            lv_obj_clear_flag(ui_PanelHotendNormalState, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    case SHOW_HEATING_PANEL:
        {
            lv_obj_clear_flag(ui_PanelHotendHeatingState, LV_OBJ_FLAG_HIDDEN);
        }
        break;  
    default:
        {
            lv_obj_clear_flag(ui_PanelHotendInitState, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    }
}

void show_proccess_panel(PromptState_t show_proccess)
{
    lv_obj_add_flag(ui_LableTipInfoContent, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_PanelExtrudeProccessInfo, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_PanelRetractProccessInfo, LV_OBJ_FLAG_HIDDEN);

    switch (show_proccess)
    {
    case PROMPT_STATE_TIP:
        lv_obj_clear_flag(ui_LableTipInfoContent, LV_OBJ_FLAG_HIDDEN);
        break;
    case PROMPT_STATE_EXTRUDE_POCCESS:
        lv_obj_clear_flag(ui_PanelExtrudeProccessInfo, LV_OBJ_FLAG_HIDDEN);
        break;
    case PROMPT_STATE_RETRACT_POCCESS:
        lv_obj_clear_flag(ui_PanelRetractProccessInfo, LV_OBJ_FLAG_HIDDEN);
        break;
    
    default:
        break;
    }
}

void filament_actions_status(bool disable)
{
    if ( disable )
    {
        lv_obj_add_state(ui_BntExtrude, LV_STATE_DISABLED);       /// States
        lv_obj_add_state(ui_BntRetract, LV_STATE_DISABLED);       /// States  
        lv_obj_add_state(ui_LableExtrude, LV_STATE_DISABLED);       /// States
        lv_obj_add_state(ui_LableRetract, LV_STATE_DISABLED);       /// States  
        // lv_obj_add_state(ui_ExtrudeRetractBackBtn, LV_STATE_DISABLED);
    }
    else
    {
        lv_obj_clear_state(ui_BntExtrude, LV_STATE_DISABLED);       /// States
        lv_obj_clear_state(ui_BntRetract, LV_STATE_DISABLED);       /// States
        lv_obj_clear_state(ui_LableExtrude, LV_STATE_DISABLED);       /// States
        lv_obj_clear_state(ui_LableRetract, LV_STATE_DISABLED);       /// States
        // lv_obj_clear_state(ui_ExtrudeRetractBackBtn, LV_STATE_DISABLED);
    }
    
}

//根据步骤数in_step设置精度信息
void show_in_filament_proccess(enum IN_FILA_PROCCESS in_step)
{
    show_proccess_panel(PROMPT_STATE_EXTRUDE_POCCESS);
    //show_filament_proccess_steps(true);
    switch (in_step)
    {
    case IN_FILAMENT_FIRST_STEP:
        {
            show_step_round_state(ui_RoundExtrudeFirstStepNum, true);
            show_step_round_state(ui_RoundExtrudeSecondStepNum, false);
            show_step_round_state(ui_RoundExtrudeThirdStepNum, false);
            show_step_label_state(ui_LableExtrudeFirstStepNum, true);
            show_step_label_state(ui_LableExtrudeSecondStepNum, false);
            show_step_label_state(ui_LableExtrudeThirdStepNum, false);
            show_step_dir_panel_state(ui_CableExtrudeFirstStep, STEP_PROCCESSING);
            show_step_dir_panel_state(ui_CableExtrudeSecondStep, STEP_NOT_START);
            show_temper_panel(SHOW_HEATING_PANEL);
            filament_actions_status(true);
        }
        break;
    case IN_FILAMENT_SECOND_STEP:
        {
            show_step_round_state(ui_RoundExtrudeFirstStepNum, true);
            show_step_round_state(ui_RoundExtrudeSecondStepNum, true);
            show_step_round_state(ui_RoundExtrudeThirdStepNum, false);
            show_step_label_state(ui_LableExtrudeFirstStepNum, true);
            show_step_label_state(ui_LableExtrudeSecondStepNum, true);
            show_step_label_state(ui_LableExtrudeThirdStepNum, false);
            show_step_dir_panel_state(ui_CableExtrudeFirstStep, STEP_FINISHED);
            show_step_dir_panel_state(ui_CableExtrudeSecondStep, STEP_PROCCESSING);
            show_temper_panel(SHOW_NORMAL_PANEL);
            filament_actions_status(true);
        }
        break;
    case IN_FILAMENT_THIRD_STEP:
        {
            show_step_round_state(ui_RoundExtrudeFirstStepNum, true);
            show_step_round_state(ui_RoundExtrudeSecondStepNum, true);
            show_step_round_state(ui_RoundExtrudeThirdStepNum, true);
            show_step_label_state(ui_LableExtrudeFirstStepNum, true);
            show_step_label_state(ui_LableExtrudeSecondStepNum, true);
            show_step_label_state(ui_LableExtrudeThirdStepNum, true);
            show_step_dir_panel_state(ui_CableExtrudeFirstStep, STEP_FINISHED);
            show_step_dir_panel_state(ui_CableExtrudeSecondStep, STEP_FINISHED);
            show_temper_panel(SHOW_TEMPER_EDIT_PANEL);
            if ( !home_printing_is_printing() ) //只有非打印进行中状态时才能进行消除不能使用状态
                filament_actions_status(false);
                
            filament_action = FILA_ACTION_NONE;
            filament_action_step_order = 0;
            send_set_target_temper_cmd(targettemp, true);
        }
        break;

    default:
        break;
    }

}

void show_out_filament_proccess(enum OUT_FILA_PROCCESS out_step)
{
    show_proccess_panel(PROMPT_STATE_RETRACT_POCCESS);
    //show_filament_proccess_steps(false);

    switch (out_step)
    {
    case OUT_FILAMENT_FIRST_STEP:
        {
            show_step_round_state(ui_RoundRetractFirstStepNum, true);
            show_step_round_state(ui_RoundRetractSecondStepNum, false);
            show_step_round_state(ui_RoundRetractThirdStepNum, false);
            show_step_round_state(ui_RoundRetractFourthStepNum, false);
            show_step_label_state(ui_LableRetractFirstStepNum, true);
            show_step_label_state(ui_LableRetractSecondStepNum, false);
            show_step_label_state(ui_LableRetractThirdStepNum, false);
            show_step_label_state(ui_LableRetractFourthStepNum, false);
            show_step_dir_panel_state(ui_CableRetractFirstStep, STEP_PROCCESSING);
            show_step_dir_panel_state(ui_CableRetractSecondStep, STEP_NOT_START);
            show_step_dir_panel_state(ui_CableRetractThirdStep, STEP_NOT_START);
            show_temper_panel(SHOW_HEATING_PANEL);
            filament_actions_status(true);
        }
        break;
    case OUT_FILAMENT_SECOND_STEP:
        {
            show_step_round_state(ui_RoundRetractFirstStepNum, true);
            show_step_round_state(ui_RoundRetractSecondStepNum, true);
            show_step_round_state(ui_RoundRetractThirdStepNum, false);
            show_step_round_state(ui_RoundRetractFourthStepNum, false);
            show_step_label_state(ui_LableRetractFirstStepNum, true);
            show_step_label_state(ui_LableRetractSecondStepNum, true);
            show_step_label_state(ui_LableRetractThirdStepNum, false);
            show_step_label_state(ui_LableRetractFourthStepNum, false);
            show_step_dir_panel_state(ui_CableRetractFirstStep, STEP_FINISHED);
            show_step_dir_panel_state(ui_CableRetractSecondStep, STEP_PROCCESSING);
            show_step_dir_panel_state(ui_CableRetractThirdStep, STEP_NOT_START);
            show_temper_panel(SHOW_NORMAL_PANEL);
            filament_actions_status(true);
        }
        break;
    case OUT_FILAMENT_THIRD_STEP:
        {
            show_step_round_state(ui_RoundRetractFirstStepNum, true);
            show_step_round_state(ui_RoundRetractSecondStepNum, true);
            show_step_round_state(ui_RoundRetractThirdStepNum, true);
            show_step_round_state(ui_RoundRetractFourthStepNum, false);
            show_step_label_state(ui_LableRetractFirstStepNum, true);
            show_step_label_state(ui_LableRetractSecondStepNum, true);
            show_step_label_state(ui_LableRetractThirdStepNum, true);
            show_step_label_state(ui_LableRetractFourthStepNum, false);
            show_step_dir_panel_state(ui_CableRetractFirstStep, STEP_FINISHED);
            show_step_dir_panel_state(ui_CableRetractSecondStep, STEP_FINISHED);
            show_step_dir_panel_state(ui_CableRetractThirdStep, STEP_PROCCESSING);
            show_temper_panel(SHOW_NORMAL_PANEL);
            filament_actions_status(true);
        }
        break;
    case OUT_FILAMENT_FOURTH_STEP:
        {
            show_step_round_state(ui_RoundRetractFirstStepNum, true);
            show_step_round_state(ui_RoundRetractSecondStepNum, true);
            show_step_round_state(ui_RoundRetractThirdStepNum, true);
            show_step_round_state(ui_RoundRetractFourthStepNum, true);
            show_step_label_state(ui_LableRetractFirstStepNum, true);
            show_step_label_state(ui_LableRetractSecondStepNum, true);
            show_step_label_state(ui_LableRetractThirdStepNum, true);
            show_step_label_state(ui_LableRetractFourthStepNum, true);
            show_step_dir_panel_state(ui_CableRetractFirstStep, STEP_FINISHED);
            show_step_dir_panel_state(ui_CableRetractSecondStep, STEP_FINISHED);
            show_step_dir_panel_state(ui_CableRetractThirdStep, STEP_FINISHED);
            show_temper_panel(SHOW_TEMPER_EDIT_PANEL);
            if ( !home_printing_is_printing() ) //只有非打印进行中状态时才能进行消除不能使用状态
                filament_actions_status(false);

            filament_action = FILA_ACTION_NONE;
            filament_action_step_order = 0;
            send_set_target_temper_cmd(targettemp, true);
        }
        break;

    default:
        break;
    }

}

void axis_move_filament_set_hotend_temper(uint16_t cur_temper, uint16_t target_temper)
{
    if ( target_temper <= 0 || ((filament_action != FILA_ACTION_IN) && (filament_action != FILA_ACTION_OUT)) )
        return;
    
    if ( cur_temper >=  target_temper )
    {
        if ( filament_action_step_order > 0 )
            return;

        filament_action_step_order = 1;
        if ( filament_action == FILA_ACTION_IN )
        {
            show_in_filament_proccess(IN_FILAMENT_SECOND_STEP);
            send_set_axis_move_opt_cmd(AXIS_E, true, 100, 300);
        }
        else if ( filament_action == FILA_ACTION_OUT )
        {
            show_out_filament_proccess(OUT_FILAMENT_SECOND_STEP);
            // 发送退料准备的命令内容
            send_set_axis_move_opt_cmd(AXIS_E, true, 10, 300);  // 5mm/s改成2.5mm/s(待测试后再改)
        }
    }
}

//进退料的动作过程，只有开始和结束，不包含加热温度
void axis_move_filament_set_filament_action_state(enum FILAMENT_ACTION_STATE state)
{
    if ( filament_action == FILA_ACTION_IN )
    {
        if ( state ==  FILAMENT_ACTION_SUCCESS )
        {
            if ( filament_action_step_order >= 1 )
                show_in_filament_proccess(IN_FILAMENT_THIRD_STEP);
        }
        else if ( state ==  FILAMENT_ACTION_FAILED )
        {
            show_in_filament_proccess(IN_FILAMENT_THIRD_STEP);
            //是否有进料失败的提示

        }
        

    }
    else if ( filament_action == FILA_ACTION_OUT )
    {
        if ( state ==  FILAMENT_ACTION_SUCCESS )
        {
            if ( filament_action_step_order == 1 )
            {
                show_out_filament_proccess(OUT_FILAMENT_THIRD_STEP);

                //发送退料的命令
                send_set_axis_move_opt_cmd(AXIS_E, false, 110, 300);

                filament_action_step_order = 2;
            }
            else if ( filament_action_step_order > 1 )
            {
                show_out_filament_proccess(OUT_FILAMENT_FOURTH_STEP);
            }
        }
        else if ( state ==  FILAMENT_ACTION_FAILED )
        {
            show_out_filament_proccess(OUT_FILAMENT_FOURTH_STEP);
        }
    }
}

void axis_move_filament_set_print_status(int8_t print_status)  // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
{
    // 0: finished, 1:stoped, 2:paused, 3:printing,6:温度升温中  依赖于协议
    if ( (print_status == 3) || (print_status == 6) )  
    {
        filament_actions_status(true);    
    }
    else if ( (print_status == 2) || (print_status == 0) || (print_status == 1) )
    {
        if ( (filament_action == FILA_ACTION_NONE) && (filament_action_step_order == 0) )
            filament_actions_status(false); 
        if(system_state.PreStartprint_state)
            filament_actions_status(true);
    }
    else//中间状态都认为不可以进退料
    {
        filament_actions_status(true);
    }

}

void axis_move_refresh_filament_process(int flag, int process)
{
    if(flag == 1)
    {
        switch (process)
        {
            case 1:show_in_filament_proccess(IN_FILAMENT_FIRST_STEP);break;
            case 4:show_in_filament_proccess(IN_FILAMENT_SECOND_STEP);break;
            case 6:
            case 100:show_in_filament_proccess(IN_FILAMENT_THIRD_STEP);break;
            default:
                break;
        }
    }
    if(flag == 2)
    {
        switch (process)
        {
            case 1:show_out_filament_proccess(OUT_FILAMENT_FIRST_STEP);break;
            case 4:show_out_filament_proccess(OUT_FILAMENT_SECOND_STEP);break;
            case 5:show_out_filament_proccess(OUT_FILAMENT_THIRD_STEP);break;
            case 7:
            case 100:show_out_filament_proccess(OUT_FILAMENT_FOURTH_STEP);break;
            default:
                break;
        }
    }
}

void axis_move_set_hotend_temper_filament(char * curtemp, char * tartemp)
{
    if (lv_obj_has_flag(ui_PanelExtrudeRetract, LV_OBJ_FLAG_HIDDEN))return;
    // char buff[30] = {0};
    // snprintf(buff, 30, "%s°C", curtemp);
    if(ui_LabelNormalRealTemper && curtemp[0] != '\0')
    {
        char buff[30] = {0};
        snprintf(buff, 30, "%s°C", curtemp);
        lv_label_set_text(ui_LabelNormalRealTemper, buff);
        lv_label_set_text(ui_LableRealHotendTempHeating, buff);
    }
    if(ui_LableTargetHotendTempHeating && tartemp[0] != '\0')
    {
        char buff[30] = {0};
        snprintf(buff, 30, "%s°C", tartemp);
        lv_label_set_text(ui_LableTargetHotendTempHeating, buff);
        //lv_label_set_text(ui_LableRealHotendTempHeating, buff);
    }
}

void axis_move_filament_infor_change_language_text(void)
{
    if (ui_LableExtrudeRetractTitle)
        lv_label_set_text(ui_LableExtrudeRetractTitle, Extrude_Retract[get_cur_language_index()]);
    if (ui_TitleHotendTemp)
        lv_label_set_text(ui_TitleHotendTemp, HotendTemp[get_cur_language_index()]);
    if (ui_LableExtrude)
        lv_label_set_text(ui_LableExtrude, FilamentIn[get_cur_language_index()]);
    if (ui_LableRetract)
        lv_label_set_text(ui_LableRetract, FilamentOut[get_cur_language_index()]);
    if (ui_LableTipInfoContent)
    {
        char buf[256] = {0};
        sprintf(buf, HotTips[get_cur_language_index()], 240);
        lv_label_set_text(ui_LableTipInfoContent, buf);
    }
    if (ui_LableExtrudeFirstStepContent)
        lv_label_set_text(ui_LableExtrudeFirstStepContent, HotendHeating[get_cur_language_index()]);
    if (ui_LableExtrudeSecondStepNum)
        lv_label_set_text(ui_LableExtrudeSecondStepNum, FilamentIning[get_cur_language_index()]);
    if (ui_LableExtrudeThirdStepContent)
        lv_label_set_text(ui_LableExtrudeThirdStepContent, FilamentEnd[get_cur_language_index()]);
    if (ui_LableRetractFirstStepContent)
        lv_label_set_text(ui_LableRetractFirstStepContent, HotendHeating[get_cur_language_index()]);
    if (ui_LableRetractSecondStepContent)
        lv_label_set_text(ui_LableRetractSecondStepContent, FilamentOutPrep[get_cur_language_index()]);
    if (ui_LableRetractThirdStepContent)
        lv_label_set_text(ui_LableRetractThirdStepContent, FilamentOuting[get_cur_language_index()]);
    if (ui_LableRetractFourthStepContent)
        lv_label_set_text(ui_LableRetractFourthStepContent, FilamentOutEnd[get_cur_language_index()]);
        
    if (ui_LableCoolSubPageTitle)
        lv_label_set_text(ui_LableCoolSubPageTitle, Fans[get_cur_language_index()]);
}

void LoadAxixMoveScreenAndObjs(bool IsEntered)
{
    AxisMove.stateValue = IsEntered;
   // ScreenStatusValue = IsEntered;
    if(AxisMove.stateValue == 0) //一级页面导航模式
    {
        LoadPage(ui_ScreenAxisMovePage, 1);
        //printf("ScreenStatusValue = 0\n");
        lv_obj_set_parent(ui_PanelExtrudeRetract, ui_ScreenAxisMovePage);
        lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveAxisMove, &ui_img_pagemove_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_group_focus_cycle(encoder_group, true);
    }
    else //二级页面导航模式
    {    
        LoadPage(ui_ScreenAxisMovePage, 2);
        // if(lv_group_get_focused(encoder_group) == ui_ButtonAxisMoveAxisMove)
        // {
        //     lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveAxisMove, &ui_img_pagemovefocus_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        // }
        // else
        // {
        //     lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveAxisMove, &ui_img_pagemoveselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        // }
        lv_obj_set_style_bg_img_src(ui_ButtonAxisMoveAxisMove, &ui_img_pagemoveselected_png, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_group_focus_cycle(encoder_group, false);
    }
}

static void AxisMovePageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    PageNode *AxisMove_node = find_page(ui_ScreenAxisMovePage);
    AxisMove_node->nav_level = index;

    switch (index)
    {
    case 1: //1级事件组
        // page_manager.objFreezzFlag = false;
        lv_group_add_obj(encoder_group, ui_ButtonAxisMoveAxisMove);
        lv_group_add_obj(encoder_group, ui_ButtonFileManageScreenAxisMove);
        lv_group_add_obj(encoder_group, ui_ButtonSettingsScreenAxisMove);
        lv_group_add_obj(encoder_group, ui_ButtonReserveScreenAxisMove);
        lv_group_add_obj(encoder_group, ui_ButtonHomeScreenAxisMove);
        add_3rd_level_nav_objs = NULL;
        break;
    case 2: //2级事件组
        // page_manager.objFreezzFlag = false;
        lv_group_add_obj(encoder_group, ui_ButtonAxisMoveAxisMove);
        for (size_t i = 1; i < 11; i++)
        {
            lv_group_add_obj(encoder_group, ctrl_array[i]->part_panel);
        }
        add_3rd_level_nav_objs = NULL;
        break;
    case 3: //3级事件组
        if (add_3rd_level_nav_objs)
        {
            add_3rd_level_nav_objs();
        }
        break;
    default:
        break;
    }
 
}

void AxisMovePageCloseSubPage(void)
{
    lv_obj_clear_flag(ui_PanelMoveAndTemper, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_PanelExtrudeRetract, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_PanelCoolSubPage, LV_OBJ_FLAG_HIDDEN);
}
