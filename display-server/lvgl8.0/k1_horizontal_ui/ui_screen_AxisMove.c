#include "ui_screen_AxisMove.h"
#include <stdio.h>
#include "ui_screen_HomeNormal.h"
#include "ui_screen_FileManage.h"
#include "ui_custom_messagebox.h"
#include "ui_custom_reminderbox.h"
#include "../custom/lvgl_cmd.h"
#include "ui_Screen_Settings.h"
#include "ui_Screen_CustomerService.h"
#include "mult_language.h"
#include "ui_screen_cool.h"
#include "ui_screen_filament_Infor.h"
#include "lvgl/src/misc/lv_timer.h"

/********axis Move Page***********/
static lv_obj_t * ui_ScreenAxisMovePage;
/******************axis move screen left panel**********************/
static lv_obj_t * ui_PanelPageScreenAxisMove;
static lv_obj_t * ui_ButtonHomeScreenAxisMove;
static lv_obj_t * ui_ImageAxisMovePage;
static lv_obj_t * ui_ButtonFileManageScreenAxisMove;
static lv_obj_t * ui_ButtonSettingsScreenAxisMove;
static lv_obj_t * ui_ButtonReserveScreenAxisMove;

/******************axis move screen right panel**********************/
static lv_obj_t * ui_PanelMoveAndTemper;
/******************axis move screen right panel title**********************/
static lv_obj_t * ui_ImgMoveLeft;
static lv_obj_t * ui_ImgMoveRight;
static lv_obj_t * ui_PanelMoveTitle;
static lv_obj_t * ui_LabelMoveAndTemperTitle;
static lv_obj_t * ui_ImgFilamentLeft;
static lv_obj_t * ui_ImgFilamentRight;
static lv_obj_t * ui_PanelFilament;
static lv_obj_t * ui_LabelFilament;
static lv_obj_t * ui_ImgCoolLeft;
static lv_obj_t * ui_ImgCoolRight;
static lv_obj_t * ui_PanelCool;
static lv_obj_t * ui_LabelCool;
static lv_obj_t * ui_PanelAdjustment;
static lv_obj_t * ui_LabelAdjustment;

/******************axis move screen right panel content**********************/
static lv_obj_t * ui_ScreenAxisMovePageCenterPanel;

/******************axis move screen right panel temper opt**********************/
static lv_obj_t * ui_PanelTempers;
/*************axis move screen right panel hotend temper opt******************/
static lv_obj_t * ui_PanelHotend;
static lv_obj_t * ui_ImageHotendScreenMove;
static lv_obj_t * ui_LabelTemperScreenMove;
static lv_obj_t * ui_LabelTemperUnitScreenMove;

/*************axis move screen right panel hotend heating opt******************/
static lv_obj_t * ui_PanelHotendHeatingScreenMove;
static lv_obj_t * ui_ImageHotendHeatingScreenMove;
static lv_obj_t * ui_LabelTargetTemperScreenMove;
static lv_obj_t * ui_LabelTemperUnitHeatingScreenMove;
static lv_obj_t * ui_LabelCurTemperScreenMove;
static lv_obj_t * ui_ImageToTargetScreenMove;

static lv_obj_t * ui_Panel1;

/*************axis move screen right panel bed temper opt******************/
static lv_obj_t * ui_PanelBed;
static lv_obj_t * ui_ImageBedScreenMove;
static lv_obj_t * ui_LabelBedTemperScreenMove;
static lv_obj_t * ui_LabelBedTemperUnitScreenMove;

/*************axis move screen right panel bed heating opt******************/
static lv_obj_t * ui_PanelBedHeatingScreenMove;
static lv_obj_t * ui_ImageBedToTargetScreenMove;
static lv_obj_t * ui_LabelBedCurTemperScreenMove;
static lv_obj_t * ui_LabelBedTemperUnitScreenMove1;
static lv_obj_t * ui_LabelBedTargetTemperScreenMove;
static lv_obj_t * ui_ImageBedHeatingScreenMove;

static lv_obj_t * ui_Panel2;


/*************axis move screen right panel thermostat temper opt******************/
static lv_obj_t * ui_PanelThermostat;
static lv_obj_t * ui_ImageThermostatScreenMove;
static lv_obj_t * ui_LabelThermostatTemperScreenMove;
static lv_obj_t * ui_LabelThermostatTemperUnitScreenMove;

static lv_obj_t * ui_Panel3;

/*************axis move screen right panel stepper disable opt******************/
static lv_obj_t * ui_PanelStepper;
static lv_obj_t * ui_ImageStepperScreenMove;
static lv_obj_t * ui_LabelStepperScreenMove;

// /*************axis move screen right panel fans opt******************/
// static lv_obj_t * ui_PanelFans;
// static lv_obj_t * ui_ImgButtonModeFan;
// static lv_obj_t * ui_GifButtonModeFan;
// static lv_obj_t * ui_LabelModeFan;

/*************axis move screen right panel move dis opt******************/
static lv_obj_t * ui_PanelMoveDis;
static lv_obj_t * ui_ButtonSmallDis;
static lv_obj_t * ui_LabelSmartDis;
static lv_obj_t * ui_ButtonMidDis;
static lv_obj_t * ui_LabelMidDis;
static lv_obj_t * ui_ButtonLargeDis;
static lv_obj_t * ui_LabelLargeDis;

/*************axis move screen right panel move xy opt******************/
static lv_obj_t * ui_PanelMoveXY;
static lv_obj_t * ui_ButtonSubXScreenMove;
static lv_obj_t * ui_LabelSubXScreenMove;
static lv_obj_t * ui_ButtonAddXScreenMove;
static lv_obj_t * ui_LabelAddXScreenMove;
static lv_obj_t * ui_ButtonAddYScreenMove;
static lv_obj_t * ui_LabelAddYScreenMove;
static lv_obj_t * ui_ButtonSubYScreenMove;
static lv_obj_t * ui_LabelSubYScreenMove;
static lv_obj_t * ui_ButtonHomeXYScreenMove;
static lv_obj_t * ui_LabelHomeXYScreenMove;

/*************axis move screen right panel move Z opt******************/
static lv_obj_t * ui_PanelMoveZ;
static lv_obj_t * ui_PanelUpperZ;
static lv_obj_t * ui_LabelFlagZ;
static lv_obj_t * ui_ImageUpperZ;
static lv_obj_t * ui_ButtonHomeZ;
static lv_obj_t * ui_ImageHomeZ;
static lv_obj_t * ui_PanelDownZ;
static lv_obj_t * ui_LabelFlagZDown;
static lv_obj_t * ui_ImageDownZ;

/*************axis move screen right panel move E opt******************/
static lv_obj_t * ui_PanelMoveE;
static lv_obj_t * ui_PanelOutFila;
static lv_obj_t * ui_ImageOutFila;
static lv_obj_t * ui_ImageFilaMoveDir;
static lv_obj_t * ui_PanelEnterFila;
static lv_obj_t * ui_ImageEnterFila;

//风扇子页面控件
static lv_obj_t * ui_ScreenCoolPanelCenter;
static lv_obj_t * ui_ScreenCoolPanelFans;
static lv_obj_t * ui_ScreenCoolImageModelFan;
static lv_obj_t * ui_ScreenCoolLabelModelFan;
static lv_obj_t * ui_ScreenCoolSliderModelFan;
static lv_obj_t * ui_ScreenCoolLabelModelPercent;
static lv_obj_t * ui_ScreenCoolImageAuxiliaryFan;
static lv_obj_t * ui_ScreenCoolLabelAuxiliaryFan;
static lv_obj_t * ui_ScreenCoolSliderAuxiliaryFan;
static lv_obj_t * ui_ScreenCoolLabelAuxiliaryPercent;
static lv_obj_t * ui_ScreenCoolImageChassisFan;
static lv_obj_t * ui_ScreenCoolLabelChassisFan;
static lv_obj_t * ui_ScreenCoolSliderChassisFan;
static lv_obj_t * ui_ScreenCoolLabelChassisPercent;

//进退料子页面
static lv_obj_t * ui_PanelCenterScreenFila;
/********************action panel***************************/
static lv_obj_t * ui_PanelActionScreenFila;

/********************hotend temper edit panel***************************/
static lv_obj_t * ui_PanelTempScreenFilament;
static lv_obj_t * ui_LabelTitleScreenFilament;
static lv_obj_t * ui_ButtonSubTemperScreenFilament;
static lv_obj_t * ui_ButtonAddTemperScreenFilament;
static lv_obj_t * ui_PanelTemperValueScreenFilament;
static lv_obj_t * ui_LabelTemperScreenFilament;
static lv_obj_t * ui_LabelTemperUnitScreenFilament;

/********************hotend heating panel***************************/
static lv_obj_t * ui_PanelhotendHeatScreenFilament;
static lv_obj_t * ui_ImageHotendHeating;
static lv_obj_t * ui_LabelRealTemper;
static lv_obj_t * ui_LabelTargetTemper;
static lv_obj_t * ui_ImageTemperTo;

/********************hotend normal panel***************************/
static lv_obj_t * ui_PanelhotendNormalScreenFila;
static lv_obj_t * ui_ImageHotendNormal;
static lv_obj_t * ui_LabelNormalRealTemper;

/********************filament action panel***************************/
static lv_obj_t * ui_PanelInAndOutAction;
static lv_obj_t * ui_ButtonInFilaScreenFilament;
static lv_obj_t * ui_LabelInFilaScreenFilament;
static lv_obj_t * ui_ButtonOutFilaScreenFilament;
static lv_obj_t * ui_LabelOutFilaScreenFilament;

/**************Prompt panel****************/
static lv_obj_t * ui_PanelPromptScreenFila;
static lv_obj_t * ui_Panel6ScreenFilament;

/**************tips infor****************/
static lv_obj_t * ui_LabelTitleTips;
static lv_obj_t * ui_LabelTipsContentScreenFila;

/**************filament step****************/
static lv_obj_t * ui_LabelTitleFilament;
static lv_obj_t * ui_PanelFilamentProccess;
static lv_obj_t * ui_BtnFirstStepScreenFila;
static lv_obj_t * ui_LabelFirstStepScreenFila;
static lv_obj_t * ui_LabelFilamentFirstStep;
static lv_obj_t * ui_PanelFirstStepScreenFila;
static lv_obj_t * ui_BtnSecondStepScreenFila;
static lv_obj_t * ui_LabelSecondStepScreenFila;
static lv_obj_t * ui_LabelFilamentSecondStep;
static lv_obj_t * ui_PanelSecondStepScreenFila;
static lv_obj_t * ui_BtnThirdStepScreenFila;
static lv_obj_t * ui_LabelThirdStepScreenFila;
static lv_obj_t * ui_LabelFilamentThirdStep;
static lv_obj_t * ui_PanelThirdStepScreenFila;
static lv_obj_t * ui_BtnFourthStepScreenFila;
static lv_obj_t * ui_LabelFourthStepScreenFila;
static lv_obj_t * ui_LabelFilamentFourthStep;
/*************speed mode******************/
static lv_obj_t * ui_PanelSpeed;
static lv_obj_t * ui_LabelSpeed;
static lv_obj_t * ui_ImageSpeed;
static lv_obj_t * ui_SpeedModePanel;
static lv_obj_t * ui_SpeedcheckboxBg;
static lv_obj_t * ui_SpeedCheckbox[5];
static lv_obj_t * ui_SpeedCheckboxPoint[5];
static lv_obj_t * ui_SpeedModeAdjLabel;
static lv_obj_t * ui_VerLineX[4];
static lv_obj_t * ui_speedModeAdjLabel;
/***********************custom variable*****************************/
//当前页面标志
static int current_subpage = 0; //0:axispage  1:coolfan  2:filamentoption

//轴移动子页面的变量
#define SMALL_DIS_UNIIT_VALUE (1)
#define MID_DIS_UNIIT_VALUE (10)
#define LARGE_DIS_UNIIT_VALUE (30)

static int dis_unit = 0;  // 0:small dis unit (1), 1: mid dis unit (10), 2:large dis unit(50).
static int16_t bed_temper_move = -15;
static int16_t bed_target_temper_move = 0;
static int16_t hotend_temper_move = -15;
static int16_t hotend_target_temper_move = 0;
static bool model_fan_opened = false;
static lv_timer_t *fan_timer = NULL;
int16_t axis_move_feedrate_xy = 3000;
int16_t axis_move_feedrate_z  = 600;    
int16_t axis_move_feedrate_e  = 120;
static uint8_t home_action = 0;   // 第1个bit位为1表示X轴归零动作，第2个bit位为1表示Y轴归零动作，第3个bit位为1表示Z轴归零动作，
static uint8_t home_flag = 0;  //第1个bit位表示X轴归零标识（1：归零， 0未归零），第2个bit位表示Y轴归零标识（1：归零， 0未归零），第3个bit位表示Z轴归零标识（1：归零， 0未归零）
static uint8_t z_move_forward_dir = 0;  //0:正向，1：反向. 

//进退料子页面变量
int targettemp = 0;
static lv_timer_t *timer_proccess = NULL;
static uint16_t edit_target_temper = 240;
static enum FILA_ACTION_TYPE filament_action = FILA_ACTION_NONE;
static uint8_t filament_action_step_order = 0;
//速度模式
static uint32_t checkbox_index = 0;
static char* speedGear[4]={"125%","100%","75%","50%"};
/************************event****************************/
static void ui_event_PageChange(lv_event_t * e);
static void ui_event_PanelHotend(lv_event_t * e);
static void ui_event_PanelBed(lv_event_t * e);
static void ui_event_TitleChange(lv_event_t * e);
static void ui_event_PanelCool(lv_event_t * e);
static void ui_event_PanelAdjustment(lv_event_t * e);
static void ui_event_ImgButtonStepperDisable(lv_event_t * e);
static void ui_event_ImgButtonModeFan(lv_event_t * e);
static void ui_event_ButtonSmallDis(lv_event_t * e);
static void ui_event_ButtonMidDis(lv_event_t * e);
static void ui_event_ButtonLargeDis(lv_event_t * e);
static void ui_event_ButtonSubXScreenMove(lv_event_t * e);
static void ui_event_ButtonAddXScreenMove(lv_event_t * e);
static void ui_event_ButtonAddYScreenMove(lv_event_t * e);
static void ui_event_ButtonSubYScreenMove(lv_event_t * e);
static void ui_event_ButtonHomeXYScreenMove(lv_event_t * e);
static void ui_event_PanelUpperZ(lv_event_t * e);
static void ui_event_ButtonHomeZ(lv_event_t * e);
static void ui_event_PanelDownZ(lv_event_t * e);
static void ui_event_PanelEnterFila(lv_event_t * e);
static void ui_event_PanelHotendHeatingScreenMove(lv_event_t * e);
static void ui_event_PanelBedHeatingScreenMove(lv_event_t * e);

//冷却子页面
static void ui_event_SliderFansChange(lv_event_t * e);

//进退料子页面
static void ui_event_BtnFilamentOptions(lv_event_t * e);
static void ui_event_BtnTargetTemperChange(lv_event_t * e);
static void ui_event_PanelTargetTemper(lv_event_t * e);
void time_too_close(struct _lv_timer_t *timer);

void show_temper_panel(enum SHOW_TEMPER_PANEL panel);
void show_proccess_panel(bool show_proccess);
void show_in_filament_proccess(enum IN_FILA_PROCCESS in_step);
void show_out_filament_proccess(enum OUT_FILA_PROCCESS out_step);
void show_step_btn_state(lv_obj_t *step_btn, bool is_start);
void show_step_label_state(lv_obj_t *step_label, bool is_start);
void show_step_dir_panel_state(lv_obj_t *step_dir, enum STEP_DIR_STATE state);
void show_filament_proccess_steps(bool in_fila);
void fila_hotend_edit_target_temper_callback(void *param);

/**********************event call back****************************/

static void MovePageHotendBtnClicked(lv_event_t * e);
static void MovePageBedBtnClicked(lv_event_t * e);
static void MovePageFilamentBtnClicked(lv_event_t * e);
static void MovePageCoolBtnClicked(lv_event_t * e);
static void MovePageAdjustmentBtnClicked(lv_event_t * e);
static void MovePageStepperDisableBtnClicked(lv_event_t * e);
static void MovePageModeFanBtnClicked(lv_event_t * e);
static void MovePageSmallDisBtnClicked(lv_event_t * e);
static void MovePageMidDisBtnClicked(lv_event_t * e);
static void MovePageLargeDisBtnClicked(lv_event_t * e);
static void MovePageSubXBtnClicked(lv_event_t * e);
static void MovePageAddXBtnClicked(lv_event_t * e);
static void MovePageAddYBtnClicked(lv_event_t * e);
static void MovePageSubYBtnClicked(lv_event_t * e);
static void MovePageHomeXYBtnClicked(lv_event_t * e);
static void MovePageUpperZBtnClicked(lv_event_t * e);
static void MovePageHomeZBtnClicked(lv_event_t * e);
static void MovePageDownZBtnClicked(lv_event_t * e);
static void MovePageEnterFilaBtnClicked(lv_event_t * e);

static void ScreenMovePanelHotHeatingClicked(lv_event_t * e);
static void ScreenMovePanelBedHeatingClicked(lv_event_t * e);

/**********************custom funs***********************************/
static float get_dis_unit_value(void); 
static void show_hotend_heating_status_screen_move(bool show);
static void show_bed_heating_status_screen_move(bool show);
static void show_dis_unit(void);
static void ui_event_out_fila_warning(lv_event_t * e);
static void move_hotend_edit_target_temper_callback(void *param);
static void move_bed_edit_target_temper_callback(void *param);
static void axis_move_change_move_btns_status(int8_t axis_home_flag); //第1个bit位表示X轴归零标识（1：归零， 0未归零），第2个bit位表示Y轴归零标识（1：归零， 0未归零），第3个bit位表示Z轴归零标识（1：归零， 0未归零）
static void speed_mode_init(void);
static void show_speed_mode_select(void);

#define Z_AXIS_MIN_DIS 0.0f
/********axis Move Page***********/
void ui_event_PageChange(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    char * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        switch(atoi(userdata))
        {
            case PAGE_HOME:home_printing_is_printing_finished() ? ui_change(PAGE_HOME) : ui_change(PAGE_HOME_PRINT);break;
            case PAGE_AXIS:ui_change(PAGE_AXIS);break;
            case PAGE_FILEMANAGE:ui_change(PAGE_FILEMANAGE);break;
            case PAGE_SETING:ui_change(PAGE_SETING);break;
            case PAGE_HELP:ui_change(PAGE_HELP);break;
            default:
                break;
        }
    }
}

void ui_event_PanelHotend(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        MovePageHotendBtnClicked(e);
    }
}
void ui_event_PanelBed(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        MovePageBedBtnClicked(e);
    }
}

void set_current_subpage(int pagenumber)
{
    if(pagenumber > 3 || pagenumber < 0)//不合法默认调到第一个子页面
        pagenumber = 0;
    current_subpage = pagenumber;
}

void ui_event_TitleChange(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    char * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        //TODO
        if(strcmp(userdata, "0") == 0)//axismove
        {
            lv_obj_add_flag(ui_PanelCenterScreenFila, LV_OBJ_FLAG_HIDDEN);      /// Flags
            lv_obj_add_flag(ui_ScreenCoolPanelCenter, LV_OBJ_FLAG_HIDDEN);      /// Flags
            lv_obj_clear_flag(ui_ScreenAxisMovePageCenterPanel, LV_OBJ_FLAG_HIDDEN);      /// Flags
            current_subpage = 0;

            lv_obj_set_style_img_opa(ui_ImgMoveLeft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgMoveRight, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgFilamentLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgFilamentRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgCoolLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgCoolRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

            lv_obj_set_style_bg_color(ui_PanelMoveTitle, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_PanelFilament, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_PanelCool, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_LabelMoveAndTemperTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_LabelFilament, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_LabelCool, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else if(strcmp(userdata, "1") == 0)//filament
        {
            lv_obj_clear_flag(ui_PanelCenterScreenFila, LV_OBJ_FLAG_HIDDEN);      /// Flags
            lv_obj_add_flag(ui_ScreenCoolPanelCenter, LV_OBJ_FLAG_HIDDEN);      /// Flags
            lv_obj_add_flag(ui_ScreenAxisMovePageCenterPanel, LV_OBJ_FLAG_HIDDEN);      /// Flags
            current_subpage = 1;

            lv_obj_set_style_img_opa(ui_ImgMoveLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgMoveRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgFilamentLeft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgFilamentRight, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgCoolLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgCoolRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

            lv_obj_set_style_bg_color(ui_PanelMoveTitle, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_PanelFilament, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_PanelCool, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_LabelMoveAndTemperTitle, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_LabelFilament, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_LabelCool, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else if(strcmp(userdata, "2") == 0)//coolfan
        {
            lv_obj_add_flag(ui_PanelCenterScreenFila, LV_OBJ_FLAG_HIDDEN);      /// Flags
            lv_obj_clear_flag(ui_ScreenCoolPanelCenter, LV_OBJ_FLAG_HIDDEN);      /// Flags
            lv_obj_add_flag(ui_ScreenAxisMovePageCenterPanel, LV_OBJ_FLAG_HIDDEN);      /// Flags
            current_subpage = 2;

            lv_obj_set_style_img_opa(ui_ImgMoveLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgMoveRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgFilamentLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgFilamentRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgCoolLeft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_img_opa(ui_ImgCoolRight, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

            lv_obj_set_style_bg_color(ui_PanelMoveTitle, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_PanelFilament, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_PanelCool, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_LabelMoveAndTemperTitle, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_LabelFilament, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_LabelCool, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else//adjust
        {

        }
    }
}

void ui_event_ImgButtonStepperDisable(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        MovePageStepperDisableBtnClicked(e);
    }
}


void ui_event_ImgButtonModeFan(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        MovePageModeFanBtnClicked(e);
    }
}
void ui_event_ButtonSmallDis(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        MovePageSmallDisBtnClicked(e);
    }
}
void ui_event_ButtonMidDis(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        MovePageMidDisBtnClicked(e);
    }
}
void ui_event_ButtonLargeDis(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        MovePageLargeDisBtnClicked(e);
    }
}
void ui_event_ButtonSubXScreenMove(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        MovePageSubXBtnClicked(e);
    }
}
void ui_event_ButtonAddXScreenMove(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        MovePageAddXBtnClicked(e);
    }
}
void ui_event_ButtonAddYScreenMove(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        MovePageAddYBtnClicked(e);
    }
}
void ui_event_ButtonSubYScreenMove(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        MovePageSubYBtnClicked(e);
    }
}
//void ui_event_ButtonSubXScreenMove1(lv_event_t * e)
void ui_event_ButtonHomeXYScreenMove(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        MovePageHomeXYBtnClicked(e);
    }
}
void ui_event_PanelUpperZ(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        MovePageUpperZBtnClicked(e);
    }
}
void ui_event_ButtonHomeZ(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        MovePageHomeZBtnClicked(e);
    }
}
void ui_event_PanelDownZ(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        MovePageDownZBtnClicked(e);
    }
}
void ui_event_ScreenAxisMovePage(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        //初始化时默认选择一个单位移动值
        MovePageSmallDisBtnClicked(e);
        char userdata[10] = {0};
        snprintf(userdata, 10, "%d", current_subpage);
        switch (current_subpage)
        {
            case 0:lv_event_send(ui_PanelMoveTitle, LV_EVENT_CLICKED, "0");break;
            case 1:lv_event_send(ui_PanelFilament, LV_EVENT_CLICKED, "1");break;
            case 2:lv_event_send(ui_PanelCool, LV_EVENT_CLICKED, "2");break;
            case 3:lv_event_send(ui_PanelAdjustment, LV_EVENT_CLICKED, "3");break;
            default:lv_event_send(ui_PanelMoveTitle, LV_EVENT_CLICKED, "0");break;
        }
    }
}

void ui_event_PanelEnterFila(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        MovePageEnterFilaBtnClicked(e);
    }
}

void ui_event_PanelHotendHeatingScreenMove(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ScreenMovePanelHotHeatingClicked(e);
    }
}
void ui_event_PanelBedHeatingScreenMove(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        ScreenMovePanelBedHeatingClicked(e);
    }
}

void ui_event_SpeedAdjustScreenMove(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        CrLogI("speed mode clicked\n");
        show_speed_mode_select();
    }
}


void ui_ScreenAxisMovePage_screen_init(void)
{
    ui_ScreenAxisMovePage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenAxisMovePage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenAxisMovePage, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenAxisMovePage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_ScreenAxisMovePage, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelPageScreenAxisMove = lv_obj_create(ui_ScreenAxisMovePage);
    lv_obj_set_width(ui_PanelPageScreenAxisMove, 80);
    lv_obj_set_height(ui_PanelPageScreenAxisMove, 480);
    lv_obj_clear_flag(ui_PanelPageScreenAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_PanelPageScreenAxisMove, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonHomeScreenAxisMove = lv_btn_create(ui_PanelPageScreenAxisMove);
    lv_obj_set_width(ui_ButtonHomeScreenAxisMove, 80);
    lv_obj_set_height(ui_ButtonHomeScreenAxisMove, 96);
    lv_obj_set_x(ui_ButtonHomeScreenAxisMove, -22);
    lv_obj_set_y(ui_ButtonHomeScreenAxisMove, -22);
    lv_obj_add_flag(ui_ButtonHomeScreenAxisMove, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonHomeScreenAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonHomeScreenAxisMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonHomeScreenAxisMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonHomeScreenAxisMove, &ui_img_pagehome_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ButtonHomeScreenAxisMove, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_ButtonHomeScreenAxisMove, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonHomeScreenAxisMove, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonHomeScreenAxisMove, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageAxisMovePage = lv_img_create(ui_PanelPageScreenAxisMove);
    lv_img_set_src(ui_ImageAxisMovePage, &ui_img_pagemoveselected_png);
    lv_obj_set_width(ui_ImageAxisMovePage, 80);
    lv_obj_set_height(ui_ImageAxisMovePage, LV_SIZE_CONTENT);    /// 92
    lv_obj_set_x(ui_ImageAxisMovePage, -22);
    lv_obj_set_y(ui_ImageAxisMovePage, 74);
    lv_obj_add_flag(ui_ImageAxisMovePage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageAxisMovePage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonFileManageScreenAxisMove = lv_btn_create(ui_PanelPageScreenAxisMove);
    lv_obj_set_width(ui_ButtonFileManageScreenAxisMove, 80);
    lv_obj_set_height(ui_ButtonFileManageScreenAxisMove, 96);
    lv_obj_set_x(ui_ButtonFileManageScreenAxisMove, -22);
    lv_obj_set_y(ui_ButtonFileManageScreenAxisMove, 170);
    lv_obj_add_flag(ui_ButtonFileManageScreenAxisMove, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonFileManageScreenAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonFileManageScreenAxisMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonFileManageScreenAxisMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonFileManageScreenAxisMove, &ui_img_pagefilemanage_png,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonFileManageScreenAxisMove, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonFileManageScreenAxisMove, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonFileManageScreenAxisMove, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonFileManageScreenAxisMove, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonSettingsScreenAxisMove = lv_btn_create(ui_PanelPageScreenAxisMove);
    lv_obj_set_width(ui_ButtonSettingsScreenAxisMove, 80);
    lv_obj_set_height(ui_ButtonSettingsScreenAxisMove, 96);
    lv_obj_set_x(ui_ButtonSettingsScreenAxisMove, -22);
    lv_obj_set_y(ui_ButtonSettingsScreenAxisMove, 266);
    lv_obj_add_flag(ui_ButtonSettingsScreenAxisMove, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSettingsScreenAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonSettingsScreenAxisMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonSettingsScreenAxisMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonSettingsScreenAxisMove, &ui_img_pagesetting_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonSettingsScreenAxisMove, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonSettingsScreenAxisMove, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonSettingsScreenAxisMove, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonSettingsScreenAxisMove, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonReserveScreenAxisMove = lv_btn_create(ui_PanelPageScreenAxisMove);
    lv_obj_set_width(ui_ButtonReserveScreenAxisMove, 80);
    lv_obj_set_height(ui_ButtonReserveScreenAxisMove, 96);
    lv_obj_set_x(ui_ButtonReserveScreenAxisMove, -22);
    lv_obj_set_y(ui_ButtonReserveScreenAxisMove, 362);
    lv_obj_add_flag(ui_ButtonReserveScreenAxisMove, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonReserveScreenAxisMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonReserveScreenAxisMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonReserveScreenAxisMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonReserveScreenAxisMove, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonReserveScreenAxisMove, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonReserveScreenAxisMove, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonReserveScreenAxisMove, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonReserveScreenAxisMove, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_PanelMoveAndTemper = lv_obj_create(ui_ScreenAxisMovePage);
    lv_obj_set_width(ui_PanelMoveAndTemper, 720);
    lv_obj_set_height(ui_PanelMoveAndTemper, 50);
    lv_obj_set_x(ui_PanelMoveAndTemper, 80);
    lv_obj_set_y(ui_PanelMoveAndTemper, 0);
    lv_obj_add_flag(ui_PanelMoveAndTemper, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_clear_flag(ui_PanelMoveAndTemper, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelMoveAndTemper, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelMoveAndTemper, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelMoveAndTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_PanelMoveAndTemper, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelMoveAndTemper, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelMoveAndTemper, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_PanelMoveAndTemper, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_PanelMoveAndTemper, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_END);
    lv_obj_set_style_pad_column(ui_PanelMoveAndTemper, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImgMoveLeft = lv_img_create(ui_PanelMoveAndTemper);
    char tempbuffb[256] = {0};
    snprintf(tempbuffb, 256, "S:%s/%s", GetK1ImageResourcePtah(), "TilteLeftstyle.png");
    lv_img_set_src(ui_ImgMoveLeft, tempbuffb);
    lv_obj_set_width(ui_ImgMoveLeft, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImgMoveLeft, LV_SIZE_CONTENT);    /// 92
    lv_obj_add_flag(ui_ImgMoveLeft, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgMoveLeft, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PanelMoveTitle = lv_obj_create(ui_PanelMoveAndTemper);
    lv_obj_set_width(ui_PanelMoveTitle, 210);
    lv_obj_set_height(ui_PanelMoveTitle, 46);
    lv_obj_add_flag(ui_PanelMoveTitle, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_clear_flag(ui_PanelMoveTitle, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_PanelMoveTitle, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelMoveTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelMoveTitle, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelMoveTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelMoveTitle, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelMoveAndTemperTitle = lv_label_create(ui_PanelMoveTitle);
    lv_obj_set_width(ui_LabelMoveAndTemperTitle, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelMoveAndTemperTitle, 46);
    lv_obj_set_align(ui_LabelMoveAndTemperTitle, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelMoveAndTemperTitle, MovePageTitle[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelMoveAndTemperTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelMoveAndTemperTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelMoveAndTemperTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelMoveAndTemperTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImgMoveRight = lv_img_create(ui_PanelMoveAndTemper);
    char tempbuffa[256] = {0};
    snprintf(tempbuffa, 256, "S:%s/%s", GetK1ImageResourcePtah(), "TitleRightstyle.png");
    lv_img_set_src(ui_ImgMoveRight, tempbuffa);
    lv_obj_set_width(ui_ImgMoveRight, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImgMoveRight, LV_SIZE_CONTENT);    /// 92
    lv_obj_add_flag(ui_ImgMoveRight, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgMoveRight, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ImgFilamentLeft = lv_img_create(ui_PanelMoveAndTemper);
    memset(tempbuffb, 0, 256);
    snprintf(tempbuffb, 256, "S:%s/%s", GetK1ImageResourcePtah(), "TilteLeftstyle.png");
    lv_img_set_src(ui_ImgFilamentLeft, tempbuffb);
    lv_obj_set_width(ui_ImgFilamentLeft, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImgFilamentLeft, LV_SIZE_CONTENT);    /// 92
    lv_obj_add_flag(ui_ImgFilamentLeft, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgFilamentLeft, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PanelFilament = lv_obj_create(ui_PanelMoveAndTemper);
    lv_obj_set_width(ui_PanelFilament, 199);
    lv_obj_set_height(ui_PanelFilament, 46);
    lv_obj_clear_flag(ui_PanelFilament, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_PanelFilament, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelFilament, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelFilament, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_PanelFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelFilament, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFilament  = lv_label_create(ui_PanelFilament);
    lv_obj_set_width(ui_LabelFilament, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelFilament, 46);
    lv_obj_set_align(ui_LabelFilament, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_LabelFilament, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelFilament, Extrude_Retract[get_cur_language_index()]);   //进退料
    lv_obj_set_style_text_color(ui_LabelFilament, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFilament, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_ImgFilamentRight = lv_img_create(ui_PanelMoveAndTemper);
    memset(tempbuffa, 0, 256);
    snprintf(tempbuffa, 256, "S:%s/%s", GetK1ImageResourcePtah(), "TitleRightstyle.png");
    lv_img_set_src(ui_ImgFilamentRight, tempbuffa);
    lv_obj_set_width(ui_ImgFilamentRight, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImgFilamentRight, LV_SIZE_CONTENT);    /// 92
    lv_obj_add_flag(ui_ImgFilamentRight, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgFilamentRight, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ImgCoolLeft = lv_img_create(ui_PanelMoveAndTemper);
    memset(tempbuffb, 0, 256);
    snprintf(tempbuffb, 256, "S:%s/%s", GetK1ImageResourcePtah(), "TilteLeftstyle.png");
    lv_img_set_src(ui_ImgCoolLeft, tempbuffb);
    lv_obj_set_width(ui_ImgCoolLeft, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImgCoolLeft, LV_SIZE_CONTENT);    /// 92
    lv_obj_add_flag(ui_ImgCoolLeft, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImgCoolLeft, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PanelCool = lv_obj_create(ui_PanelMoveAndTemper);
    lv_obj_set_width(ui_PanelCool, 165);
    lv_obj_set_height(ui_PanelCool, 45);
    lv_obj_clear_flag(ui_PanelCool, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_PanelCool, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelCool, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelCool, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCool, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelCool, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_PanelCool, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelCool, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelCool = lv_label_create(ui_PanelCool);
    lv_obj_set_width(ui_LabelCool, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelCool, 45);
    lv_obj_set_align(ui_LabelCool, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_LabelCool, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelCool, Cooling[get_cur_language_index()]);     //冷却
    lv_obj_set_style_text_color(ui_LabelCool, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelCool, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelCool, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImgCoolRight = lv_img_create(ui_PanelMoveAndTemper);
    memset(tempbuffa, 0, 256);
    snprintf(tempbuffa, 256, "S:%s/%s", GetK1ImageResourcePtah(), "TitleRightstyle.png");
    lv_img_set_src(ui_ImgCoolRight, tempbuffa);
    lv_obj_set_width(ui_ImgCoolRight, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImgCoolRight, LV_SIZE_CONTENT);
    lv_obj_add_flag(ui_ImgCoolRight, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_ImgCoolRight, LV_OBJ_FLAG_SCROLLABLE);

    //标题栏初始化
    lv_obj_set_style_img_opa(ui_ImgMoveLeft, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui_ImgMoveRight, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui_ImgFilamentLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui_ImgFilamentRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui_ImgCoolLeft, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui_ImgCoolRight, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelAdjustment = lv_obj_create(ui_PanelMoveAndTemper);
    lv_obj_set_width(ui_PanelAdjustment, 150);
    lv_obj_set_height(ui_PanelAdjustment, 46);
    lv_obj_set_x(ui_PanelAdjustment, 546);
    lv_obj_set_y(ui_PanelAdjustment, -17);
    lv_obj_add_flag(ui_PanelAdjustment, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_clear_flag(ui_PanelAdjustment, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelAdjustment, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelAdjustment, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelAdjustment, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelAdjustment, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelAdjustment, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelAdjustment, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelAdjustment, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelAdjustment, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_PanelAdjustment, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_PanelAdjustment, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelAdjustment, LV_OBJ_FLAG_HIDDEN);      /// Flags

    ui_LabelAdjustment = lv_label_create(ui_PanelAdjustment);
    lv_obj_set_width(ui_LabelAdjustment, 160);
    lv_obj_set_height(ui_LabelAdjustment, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_LabelAdjustment, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_LabelAdjustment, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelAdjustment, Adjustment[get_cur_language_index()]);  //调整
    //lv_label_set_recolor(ui_LabelAdjustment, "true");
    lv_obj_set_style_text_color(ui_LabelAdjustment, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelAdjustment, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelAdjustment, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelAdjustment, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenAxisMovePageCenterPanel = lv_obj_create(ui_ScreenAxisMovePage);
    lv_obj_set_width(ui_ScreenAxisMovePageCenterPanel, 720);
    lv_obj_set_height(ui_ScreenAxisMovePageCenterPanel, 430);
    lv_obj_align(ui_ScreenAxisMovePageCenterPanel, LV_ALIGN_TOP_LEFT, 80, 50);
    lv_obj_clear_flag(ui_ScreenAxisMovePageCenterPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScreenAxisMovePageCenterPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScreenAxisMovePageCenterPanel, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenAxisMovePageCenterPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ScreenAxisMovePageCenterPanel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelTempers = lv_obj_create(ui_ScreenAxisMovePageCenterPanel);
    lv_obj_set_width(ui_PanelTempers, 134);
    lv_obj_set_height(ui_PanelTempers, 344);
    lv_obj_set_x(ui_PanelTempers, -2);
    lv_obj_set_y(ui_PanelTempers, 12);
    lv_obj_clear_flag(ui_PanelTempers, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelTempers, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelTempers, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_border_side(ui_PanelTempers, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelTempers, lv_color_hex(0x434549),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelTempers, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelTempers, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelHotend = lv_obj_create(ui_PanelTempers);
    lv_obj_set_width(ui_PanelHotend, 130);
    lv_obj_set_height(ui_PanelHotend, 81);
    lv_obj_set_x(ui_PanelHotend, -20);
    lv_obj_set_y(ui_PanelHotend, -20);
    lv_obj_clear_flag(ui_PanelHotend, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelHotend, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHotend, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelHotend, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelHotend, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelHotend, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelHotend, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelHotend, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageHotendScreenMove = lv_img_create(ui_PanelHotend);
    lv_img_set_src(ui_ImageHotendScreenMove, &ui_img_hotend_png);
    lv_obj_set_width(ui_ImageHotendScreenMove, 33);
    lv_obj_set_height(ui_ImageHotendScreenMove, 33);
    lv_obj_set_x(ui_ImageHotendScreenMove, -10);
    lv_obj_set_y(ui_ImageHotendScreenMove, 3);
    lv_obj_add_flag(ui_ImageHotendScreenMove, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHotendScreenMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelTemperScreenMove = lv_label_create(ui_PanelHotend);
    lv_obj_set_width(ui_LabelTemperScreenMove, 60);
    lv_obj_set_height(ui_LabelTemperScreenMove, 32);
    lv_obj_set_x(ui_LabelTemperScreenMove, 10);
    lv_obj_set_y(ui_LabelTemperScreenMove, 3);
    lv_label_set_text(ui_LabelTemperScreenMove, "200");
    lv_obj_set_style_text_color(ui_LabelTemperScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTemperScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTemperScreenMove, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTemperScreenMove, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTemperScreenMove, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTemperUnitScreenMove = lv_label_create(ui_PanelHotend);
    lv_obj_set_width(ui_LabelTemperUnitScreenMove, 25);
    lv_obj_set_height(ui_LabelTemperUnitScreenMove, 22);
    lv_obj_set_x(ui_LabelTemperUnitScreenMove, 70);
    lv_obj_set_y(ui_LabelTemperUnitScreenMove, 7);
    lv_label_set_text(ui_LabelTemperUnitScreenMove, "°C");
    lv_obj_set_style_text_color(ui_LabelTemperUnitScreenMove, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTemperUnitScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTemperUnitScreenMove, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTemperUnitScreenMove, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    /************************************************/
    ui_PanelHotendHeatingScreenMove = lv_obj_create(ui_PanelTempers);
    lv_obj_set_width(ui_PanelHotendHeatingScreenMove, 130);
    lv_obj_set_height(ui_PanelHotendHeatingScreenMove, 81);
    lv_obj_set_x(ui_PanelHotendHeatingScreenMove, -20);
    lv_obj_set_y(ui_PanelHotendHeatingScreenMove, -20);
    lv_obj_clear_flag(ui_PanelHotendHeatingScreenMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelHotendHeatingScreenMove, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelHotendHeatingScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelHotendHeatingScreenMove, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelHotendHeatingScreenMove, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelHotendHeatingScreenMove, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelHotendHeatingScreenMove, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelHotendHeatingScreenMove, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageHotendHeatingScreenMove = lv_img_create(ui_PanelHotendHeatingScreenMove);
    lv_img_set_src(ui_ImageHotendHeatingScreenMove, &ui_img_hotendheating_png);
    lv_obj_set_width(ui_ImageHotendHeatingScreenMove, 28);
    lv_obj_set_height(ui_ImageHotendHeatingScreenMove, 28);
    lv_obj_set_x(ui_ImageHotendHeatingScreenMove, 29);
    lv_obj_set_y(ui_ImageHotendHeatingScreenMove, -9);
    lv_obj_add_flag(ui_ImageHotendHeatingScreenMove, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHotendHeatingScreenMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelTargetTemperScreenMove = lv_label_create(ui_PanelHotendHeatingScreenMove);
    lv_obj_set_width(ui_LabelTargetTemperScreenMove, 42);
    lv_obj_set_height(ui_LabelTargetTemperScreenMove, 32);
    lv_obj_set_x(ui_LabelTargetTemperScreenMove, 41);
    lv_obj_set_y(ui_LabelTargetTemperScreenMove, 18);
    lv_label_set_text(ui_LabelTargetTemperScreenMove, "");
    lv_obj_set_style_text_color(ui_LabelTargetTemperScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTargetTemperScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTargetTemperScreenMove, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTargetTemperScreenMove, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTemperUnitHeatingScreenMove = lv_label_create(ui_PanelHotendHeatingScreenMove);
    lv_obj_set_width(ui_LabelTemperUnitHeatingScreenMove, 25);
    lv_obj_set_height(ui_LabelTemperUnitHeatingScreenMove, 22);
    lv_obj_set_x(ui_LabelTemperUnitHeatingScreenMove, 82);
    lv_obj_set_y(ui_LabelTemperUnitHeatingScreenMove, 24);
    lv_label_set_text(ui_LabelTemperUnitHeatingScreenMove, "°C");
    lv_obj_set_style_text_color(ui_LabelTemperUnitHeatingScreenMove, lv_color_hex(0x83868B),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTemperUnitHeatingScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTemperUnitHeatingScreenMove, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTemperUnitHeatingScreenMove, lv_font22.font,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelCurTemperScreenMove = lv_label_create(ui_PanelHotendHeatingScreenMove);
    lv_obj_set_width(ui_LabelCurTemperScreenMove, 42);
    lv_obj_set_height(ui_LabelCurTemperScreenMove, 32);
    lv_obj_set_x(ui_LabelCurTemperScreenMove, -18);
    lv_obj_set_y(ui_LabelCurTemperScreenMove, 18);
    lv_label_set_text(ui_LabelCurTemperScreenMove, "");
    lv_obj_set_style_text_color(ui_LabelCurTemperScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelCurTemperScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelCurTemperScreenMove, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelCurTemperScreenMove, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageToTargetScreenMove = lv_img_create(ui_PanelHotendHeatingScreenMove);
    lv_img_set_src(ui_ImageToTargetScreenMove, &ui_img_totarget_png);
    lv_obj_set_width(ui_ImageToTargetScreenMove, 16);
    lv_obj_set_height(ui_ImageToTargetScreenMove, 15);
    lv_obj_set_x(ui_ImageToTargetScreenMove, 24);
    lv_obj_set_y(ui_ImageToTargetScreenMove, 26);
    lv_obj_add_flag(ui_ImageToTargetScreenMove, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageToTargetScreenMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_flag(ui_PanelHotendHeatingScreenMove, LV_OBJ_FLAG_HIDDEN);     /// Flags
    /************************************************/

    ui_Panel1 = lv_obj_create(ui_PanelTempers);
    lv_obj_set_width(ui_Panel1, 122);
    lv_obj_set_height(ui_Panel1, 1);
    lv_obj_set_x(ui_Panel1, -16);
    lv_obj_set_y(ui_Panel1, 63);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel1, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel1, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelBed = lv_obj_create(ui_PanelTempers);
    lv_obj_set_width(ui_PanelBed, 130);
    lv_obj_set_height(ui_PanelBed, 81);
    lv_obj_set_x(ui_PanelBed, -20);
    lv_obj_set_y(ui_PanelBed, 66);
    lv_obj_clear_flag(ui_PanelBed, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelBed, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelBed, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelBed, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelBed, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelBed, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelBed, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelBed, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageBedScreenMove = lv_img_create(ui_PanelBed);
    lv_img_set_src(ui_ImageBedScreenMove, &ui_img_bed_png);
    lv_obj_set_width(ui_ImageBedScreenMove, 33);
    lv_obj_set_height(ui_ImageBedScreenMove, 33);
    lv_obj_set_x(ui_ImageBedScreenMove, -10);
    lv_obj_set_y(ui_ImageBedScreenMove, 3);
    lv_obj_add_flag(ui_ImageBedScreenMove, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageBedScreenMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelBedTemperScreenMove = lv_label_create(ui_PanelBed);
    lv_obj_set_width(ui_LabelBedTemperScreenMove, 60);
    lv_obj_set_height(ui_LabelBedTemperScreenMove, 32);
    lv_obj_set_x(ui_LabelBedTemperScreenMove, 10);
    lv_obj_set_y(ui_LabelBedTemperScreenMove, 3);
    lv_label_set_text(ui_LabelBedTemperScreenMove, "");
    lv_obj_set_style_text_color(ui_LabelBedTemperScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedTemperScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedTemperScreenMove, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedTemperScreenMove, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelBedTemperUnitScreenMove = lv_label_create(ui_PanelBed);
    lv_obj_set_width(ui_LabelBedTemperUnitScreenMove, 25);
    lv_obj_set_height(ui_LabelBedTemperUnitScreenMove, 22);
    lv_obj_set_x(ui_LabelBedTemperUnitScreenMove, 70);
    lv_obj_set_y(ui_LabelBedTemperUnitScreenMove, 7);
    lv_label_set_text(ui_LabelBedTemperUnitScreenMove, "°C");
    lv_obj_set_style_text_color(ui_LabelBedTemperUnitScreenMove, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedTemperUnitScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedTemperUnitScreenMove, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedTemperUnitScreenMove, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    /**********************************************************/
    ui_PanelBedHeatingScreenMove = lv_obj_create(ui_PanelTempers);
    lv_obj_set_width(ui_PanelBedHeatingScreenMove, 130);
    lv_obj_set_height(ui_PanelBedHeatingScreenMove, 81);
    lv_obj_set_x(ui_PanelBedHeatingScreenMove, -20);
    lv_obj_set_y(ui_PanelBedHeatingScreenMove, 66);
    lv_obj_clear_flag(ui_PanelBedHeatingScreenMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelBedHeatingScreenMove, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelBedHeatingScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelBedHeatingScreenMove, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelBedHeatingScreenMove, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelBedHeatingScreenMove, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelBedHeatingScreenMove, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelBedHeatingScreenMove, 1, LV_PART_MAIN |  LV_STATE_PRESSED);

    ui_ImageBedToTargetScreenMove = lv_img_create(ui_PanelBedHeatingScreenMove);
    lv_img_set_src(ui_ImageBedToTargetScreenMove, &ui_img_totarget_png);
    lv_obj_set_width(ui_ImageBedToTargetScreenMove, 16);
    lv_obj_set_height(ui_ImageBedToTargetScreenMove, 15);
    lv_obj_set_x(ui_ImageBedToTargetScreenMove, 24);
    lv_obj_set_y(ui_ImageBedToTargetScreenMove, 26);
    lv_obj_add_flag(ui_ImageBedToTargetScreenMove, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageBedToTargetScreenMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelBedCurTemperScreenMove = lv_label_create(ui_PanelBedHeatingScreenMove);
    lv_obj_set_width(ui_LabelBedCurTemperScreenMove, 42);
    lv_obj_set_height(ui_LabelBedCurTemperScreenMove, 32);
    lv_obj_set_x(ui_LabelBedCurTemperScreenMove, -18);
    lv_obj_set_y(ui_LabelBedCurTemperScreenMove, 18);
    lv_label_set_text(ui_LabelBedCurTemperScreenMove, "");
    lv_obj_set_style_text_color(ui_LabelBedCurTemperScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedCurTemperScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedCurTemperScreenMove, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedCurTemperScreenMove, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelBedTemperUnitScreenMove1 = lv_label_create(ui_PanelBedHeatingScreenMove);
    lv_obj_set_width(ui_LabelBedTemperUnitScreenMove1, 25);
    lv_obj_set_height(ui_LabelBedTemperUnitScreenMove1, 22);
    lv_obj_set_x(ui_LabelBedTemperUnitScreenMove1, 82);
    lv_obj_set_y(ui_LabelBedTemperUnitScreenMove1, 24);
    lv_label_set_text(ui_LabelBedTemperUnitScreenMove1, "°C");
    lv_obj_set_style_text_color(ui_LabelBedTemperUnitScreenMove1, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedTemperUnitScreenMove1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedTemperUnitScreenMove1, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedTemperUnitScreenMove1, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelBedTargetTemperScreenMove = lv_label_create(ui_PanelBedHeatingScreenMove);
    lv_obj_set_width(ui_LabelBedTargetTemperScreenMove, 42);
    lv_obj_set_height(ui_LabelBedTargetTemperScreenMove, 32);
    lv_obj_set_x(ui_LabelBedTargetTemperScreenMove, 41);
    lv_obj_set_y(ui_LabelBedTargetTemperScreenMove, 18);
    lv_label_set_text(ui_LabelBedTargetTemperScreenMove, "");
    lv_obj_set_style_text_color(ui_LabelBedTargetTemperScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelBedTargetTemperScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelBedTargetTemperScreenMove, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBedTargetTemperScreenMove, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageBedHeatingScreenMove = lv_img_create(ui_PanelBedHeatingScreenMove);
    lv_img_set_src(ui_ImageBedHeatingScreenMove, &ui_img_bedheating_png);
    lv_obj_set_width(ui_ImageBedHeatingScreenMove, 28);
    lv_obj_set_height(ui_ImageBedHeatingScreenMove, 28);
    lv_obj_set_x(ui_ImageBedHeatingScreenMove, 29);
    lv_obj_set_y(ui_ImageBedHeatingScreenMove, -9);
    lv_obj_add_flag(ui_ImageBedHeatingScreenMove, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageBedHeatingScreenMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags


    lv_obj_add_flag(ui_PanelBedHeatingScreenMove, LV_OBJ_FLAG_HIDDEN);     /// Flags
    /**********************************************************/
 
    ui_Panel2 = lv_obj_create(ui_PanelTempers);
    lv_obj_set_width(ui_Panel2, 122);
    lv_obj_set_height(ui_Panel2, 1);
    lv_obj_set_x(ui_Panel2, -16);
    lv_obj_set_y(ui_Panel2, 149);
    lv_obj_clear_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel2, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelSpeed = lv_obj_create(ui_PanelTempers);
    lv_obj_set_width(ui_PanelSpeed, 130);
    lv_obj_set_height(ui_PanelSpeed, 81);
    lv_obj_set_x(ui_PanelSpeed, -20);
    lv_obj_set_y(ui_PanelSpeed, 151);
    lv_obj_clear_flag(ui_PanelSpeed, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelSpeed, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelSpeed, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelSpeed, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelSpeed, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelSpeed, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelSpeed, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelSpeed, 2, LV_PART_MAIN |  LV_STATE_PRESSED);

    char imgPath[256] = {0};
    snprintf(imgPath, sizeof(imgPath), "S:%s/%s", GetK1ImageResourcePtah(), "speed_mode.png");
    ui_ImageSpeed = lv_img_create(ui_PanelSpeed);
    lv_img_set_src(ui_ImageSpeed, imgPath);
    lv_obj_set_width(ui_ImageSpeed, 26);
    lv_obj_set_height(ui_ImageSpeed, 16);
    lv_obj_add_flag(ui_ImageSpeed, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageSpeed, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_align_to(ui_ImageSpeed,ui_PanelSpeed,LV_ALIGN_LEFT_MID,-5,0);

    ui_LabelSpeed = lv_label_create(ui_PanelSpeed);
    lv_obj_set_width(ui_LabelSpeed, 65);
    lv_obj_set_height(ui_LabelSpeed, 60);
    lv_label_set_recolor(ui_LabelSpeed, true);     
    lv_label_set_text(ui_LabelSpeed, "100#83868b %#");
    lv_obj_set_style_text_color(ui_LabelSpeed, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSpeed, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelSpeed, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSpeed, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align_to(ui_LabelSpeed,ui_ImageSpeed,LV_ALIGN_OUT_RIGHT_MID,13,18);
    lv_label_set_long_mode(ui_LabelSpeed,LV_LABEL_LONG_WRAP);
    //UI加入了速度调整模式，所以去掉腔体温度
#if 0
    ui_PanelThermostat = lv_obj_create(ui_PanelTempers);
    lv_obj_set_width(ui_PanelThermostat, 130);
    lv_obj_set_height(ui_PanelThermostat, 81);
    lv_obj_set_x(ui_PanelThermostat, -20);
    lv_obj_set_y(ui_PanelThermostat, 151);
    lv_obj_clear_flag(ui_PanelThermostat, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelThermostat, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelThermostat, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelThermostat, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelThermostat, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelThermostat, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelThermostat, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelThermostat, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageThermostatScreenMove = lv_img_create(ui_PanelThermostat);
    lv_img_set_src(ui_ImageThermostatScreenMove, &ui_img_temper_chassis_png);
    lv_obj_set_width(ui_ImageThermostatScreenMove, 33);
    lv_obj_set_height(ui_ImageThermostatScreenMove, 33);
    lv_obj_set_x(ui_ImageThermostatScreenMove, -10);
    lv_obj_set_y(ui_ImageThermostatScreenMove, 3);
    lv_obj_add_flag(ui_ImageThermostatScreenMove, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageThermostatScreenMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelThermostatTemperScreenMove = lv_label_create(ui_PanelThermostat);
    lv_obj_set_width(ui_LabelThermostatTemperScreenMove, 60);
    lv_obj_set_height(ui_LabelThermostatTemperScreenMove, 32);
    lv_obj_set_x(ui_LabelThermostatTemperScreenMove, 10);
    lv_obj_set_y(ui_LabelThermostatTemperScreenMove, 3);
    lv_label_set_text(ui_LabelThermostatTemperScreenMove, "");
    lv_obj_set_style_text_color(ui_LabelThermostatTemperScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelThermostatTemperScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelThermostatTemperScreenMove, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelThermostatTemperScreenMove, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelThermostatTemperUnitScreenMove = lv_label_create(ui_PanelThermostat);
    lv_obj_set_width(ui_LabelThermostatTemperUnitScreenMove, 25);
    lv_obj_set_height(ui_LabelThermostatTemperUnitScreenMove, 22);
    lv_obj_set_x(ui_LabelThermostatTemperUnitScreenMove, 70);
    lv_obj_set_y(ui_LabelThermostatTemperUnitScreenMove, 7);
    lv_label_set_text(ui_LabelThermostatTemperUnitScreenMove, "°C");
    lv_obj_set_style_text_color(ui_LabelThermostatTemperUnitScreenMove, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelThermostatTemperUnitScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelThermostatTemperUnitScreenMove, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelThermostatTemperUnitScreenMove, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
#endif
    ui_Panel3 = lv_obj_create(ui_PanelTempers);
    lv_obj_set_width(ui_Panel3, 122);
    lv_obj_set_height(ui_Panel3, 1);
    lv_obj_set_x(ui_Panel3, -16);
    lv_obj_set_y(ui_Panel3, 233);
    lv_obj_clear_flag(ui_Panel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Panel3, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel3, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel3, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelStepper = lv_obj_create(ui_PanelTempers);
    lv_obj_set_width(ui_PanelStepper, 130);
    lv_obj_set_height(ui_PanelStepper, 81);
    lv_obj_set_x(ui_PanelStepper, -20);
    lv_obj_set_y(ui_PanelStepper, 237);
    lv_obj_clear_flag(ui_PanelStepper, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelStepper, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelStepper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelStepper, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelStepper, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelStepper, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelStepper, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelStepper, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageStepperScreenMove = lv_img_create(ui_PanelStepper);
    lv_img_set_src(ui_ImageStepperScreenMove, &ui_img_disable_stepper_png);
    lv_obj_set_width(ui_ImageStepperScreenMove, 33);
    lv_obj_set_height(ui_ImageStepperScreenMove, 33);
    lv_obj_set_x(ui_ImageStepperScreenMove, -10);
    lv_obj_set_y(ui_ImageStepperScreenMove, 3);
    lv_obj_add_flag(ui_ImageStepperScreenMove, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageStepperScreenMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelStepperScreenMove = lv_label_create(ui_PanelStepper);
    lv_obj_set_width(ui_LabelStepperScreenMove, 60);
    lv_obj_set_height(ui_LabelStepperScreenMove, 32);
    lv_obj_set_x(ui_LabelStepperScreenMove, 25);
    lv_obj_set_y(ui_LabelStepperScreenMove, 5);
    lv_label_set_text(ui_LabelStepperScreenMove, "OFF");
    lv_obj_set_style_text_color(ui_LabelStepperScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelStepperScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelStepperScreenMove, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelStepperScreenMove, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelMoveDis = lv_obj_create(ui_ScreenAxisMovePageCenterPanel);
    lv_obj_set_width(ui_PanelMoveDis, 367);
    lv_obj_set_height(ui_PanelMoveDis, 54);
    lv_obj_set_x(ui_PanelMoveDis, 189);
    lv_obj_set_y(ui_PanelMoveDis, 9);
    lv_obj_clear_flag(ui_PanelMoveDis, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelMoveDis, 32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelMoveDis, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelMoveDis, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelMoveDis, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonSmallDis = lv_btn_create(ui_PanelMoveDis);
    lv_obj_set_width(ui_ButtonSmallDis, 110);
    lv_obj_set_height(ui_ButtonSmallDis, 54);
    lv_obj_set_x(ui_ButtonSmallDis, -22);
    lv_obj_set_y(ui_ButtonSmallDis, -22);
    lv_obj_add_flag(ui_ButtonSmallDis, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSmallDis, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonSmallDis, 32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonSmallDis, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonSmallDis, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonSmallDis, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonSmallDis, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonSmallDis, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ButtonSmallDis, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelSmartDis = lv_label_create(ui_ButtonSmallDis);
    lv_obj_set_width(ui_LabelSmartDis, 90);
    lv_obj_set_height(ui_LabelSmartDis, 35);
    lv_obj_set_x(ui_LabelSmartDis, -12);
    lv_obj_set_y(ui_LabelSmartDis, -2);
    lv_label_set_long_mode(ui_LabelSmartDis, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelSmartDis, "1mm");
    lv_obj_set_style_text_align(ui_LabelSmartDis, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSmartDis, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonMidDis = lv_btn_create(ui_PanelMoveDis);
    lv_obj_set_width(ui_ButtonMidDis, 110);
    lv_obj_set_height(ui_ButtonMidDis, 54);
    lv_obj_set_x(ui_ButtonMidDis, 105);
    lv_obj_set_y(ui_ButtonMidDis, -22);
    lv_obj_add_flag(ui_ButtonMidDis, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonMidDis, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonMidDis, 32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonMidDis, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonMidDis, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonMidDis, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonMidDis, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonMidDis, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ButtonMidDis, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelMidDis = lv_label_create(ui_ButtonMidDis);
    lv_obj_set_width(ui_LabelMidDis, 90);
    lv_obj_set_height(ui_LabelMidDis, 35);
    lv_obj_set_x(ui_LabelMidDis, -12);
    lv_obj_set_y(ui_LabelMidDis, -2);
    lv_label_set_long_mode(ui_LabelMidDis, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelMidDis, "10mm");
    lv_obj_set_style_text_align(ui_LabelMidDis, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelMidDis, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonLargeDis = lv_btn_create(ui_PanelMoveDis);
    lv_obj_set_width(ui_ButtonLargeDis, 110);
    lv_obj_set_height(ui_ButtonLargeDis, 54);
    lv_obj_set_x(ui_ButtonLargeDis, 235);
    lv_obj_set_y(ui_ButtonLargeDis, -22);
    lv_obj_add_flag(ui_ButtonLargeDis, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonLargeDis, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonLargeDis, 32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonLargeDis, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonLargeDis, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonLargeDis, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonLargeDis, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonLargeDis, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ButtonLargeDis, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelLargeDis = lv_label_create(ui_ButtonLargeDis);
    lv_obj_set_width(ui_LabelLargeDis, 90);
    lv_obj_set_height(ui_LabelLargeDis, 35);
    lv_obj_set_x(ui_LabelLargeDis, -12);
    lv_obj_set_y(ui_LabelLargeDis, -2);
    lv_label_set_long_mode(ui_LabelLargeDis, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelLargeDis, "30mm");
    lv_obj_set_style_text_align(ui_LabelLargeDis, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelLargeDis, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelMoveXY = lv_obj_create(ui_ScreenAxisMovePageCenterPanel);
    lv_obj_set_width(ui_PanelMoveXY, 277);
    lv_obj_set_height(ui_PanelMoveXY, 277);
    lv_obj_set_x(ui_PanelMoveXY, 228);
    lv_obj_set_y(ui_PanelMoveXY, 76);
    lv_obj_clear_flag(ui_PanelMoveXY, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelMoveXY, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelMoveXY, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_PanelMoveXY, &ui_img_blackmovexy_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelMoveXY, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonSubXScreenMove = lv_btn_create(ui_PanelMoveXY);
    lv_obj_set_width(ui_ButtonSubXScreenMove, 76);
    lv_obj_set_height(ui_ButtonSubXScreenMove, 94);
    lv_obj_set_x(ui_ButtonSubXScreenMove, -22);
    lv_obj_set_y(ui_ButtonSubXScreenMove, 69);
    lv_obj_add_flag(ui_ButtonSubXScreenMove, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSubXScreenMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonSubXScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonSubXScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonSubXScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ButtonSubXScreenMove, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonSubXScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonSubXScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_ButtonSubXScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_ButtonSubXScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonSubXScreenMove, lv_color_hex(0x42BDD8),
                                LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_ButtonSubXScreenMove, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelSubXScreenMove = lv_label_create(ui_ButtonSubXScreenMove);
    lv_obj_set_width(ui_LabelSubXScreenMove, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelSubXScreenMove, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelSubXScreenMove, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelSubXScreenMove, "X-");
    lv_obj_set_style_text_font(ui_LabelSubXScreenMove, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LabelSubXScreenMove, lv_color_hex(0x42BDD8),
                                LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_LabelSubXScreenMove, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonAddXScreenMove = lv_btn_create(ui_PanelMoveXY);
    lv_obj_set_width(ui_ButtonAddXScreenMove, 76);
    lv_obj_set_height(ui_ButtonAddXScreenMove, 94);
    lv_obj_set_x(ui_ButtonAddXScreenMove, 182);
    lv_obj_set_y(ui_ButtonAddXScreenMove, 69);
    lv_obj_add_flag(ui_ButtonAddXScreenMove, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAddXScreenMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonAddXScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonAddXScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonAddXScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ButtonAddXScreenMove, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonAddXScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonAddXScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_ButtonAddXScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_ButtonAddXScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonAddXScreenMove, lv_color_hex(0x42BDD8),
                                LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_ButtonAddXScreenMove, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelAddXScreenMove = lv_label_create(ui_ButtonAddXScreenMove);
    lv_obj_set_width(ui_LabelAddXScreenMove, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelAddXScreenMove, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelAddXScreenMove, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelAddXScreenMove, "X+");
    lv_obj_set_style_text_font(ui_LabelAddXScreenMove, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonAddYScreenMove = lv_btn_create(ui_PanelMoveXY);
    lv_obj_set_width(ui_ButtonAddYScreenMove, 96);
    lv_obj_set_height(ui_ButtonAddYScreenMove, 70);
    lv_obj_set_x(ui_ButtonAddYScreenMove, 67);
    lv_obj_set_y(ui_ButtonAddYScreenMove, -20);
    lv_obj_add_flag(ui_ButtonAddYScreenMove, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAddYScreenMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonAddYScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonAddYScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonAddYScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ButtonAddYScreenMove, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonAddYScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonAddYScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_ButtonAddYScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_ButtonAddYScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonAddYScreenMove, lv_color_hex(0x42BDD8),
                                LV_PART_MAIN  | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_ButtonAddYScreenMove, 255, LV_PART_MAIN  | LV_STATE_PRESSED);

    ui_LabelAddYScreenMove = lv_label_create(ui_ButtonAddYScreenMove);
    lv_obj_set_width(ui_LabelAddYScreenMove, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelAddYScreenMove, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelAddYScreenMove, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelAddYScreenMove, "Y+");
    lv_obj_set_style_text_font(ui_LabelAddYScreenMove, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonSubYScreenMove = lv_btn_create(ui_PanelMoveXY);
    lv_obj_set_width(ui_ButtonSubYScreenMove, 96);
    lv_obj_set_height(ui_ButtonSubYScreenMove, 70);
    lv_obj_set_x(ui_ButtonSubYScreenMove, 67);
    lv_obj_set_y(ui_ButtonSubYScreenMove, 185);
    lv_obj_add_flag(ui_ButtonSubYScreenMove, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSubYScreenMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonSubYScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonSubYScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonSubYScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ButtonSubYScreenMove, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonSubYScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonSubYScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_ButtonSubYScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_ButtonSubYScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonSubYScreenMove, lv_color_hex(0x42BDD8),
                                LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_ButtonSubYScreenMove, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelSubYScreenMove = lv_label_create(ui_ButtonSubYScreenMove);
    lv_obj_set_width(ui_LabelSubYScreenMove, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelSubYScreenMove, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelSubYScreenMove, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelSubYScreenMove, "Y-");
    lv_obj_set_style_text_font(ui_LabelSubYScreenMove, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LabelSubYScreenMove, lv_color_hex(0x42BDD8),
                                LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_LabelSubYScreenMove, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonHomeXYScreenMove = lv_btn_create(ui_PanelMoveXY);
    lv_obj_set_width(ui_ButtonHomeXYScreenMove, 106);
    lv_obj_set_height(ui_ButtonHomeXYScreenMove, 106);
    lv_obj_set_x(ui_ButtonHomeXYScreenMove, 63);
    lv_obj_set_y(ui_ButtonHomeXYScreenMove, 63);
    lv_obj_add_flag(ui_ButtonHomeXYScreenMove, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonHomeXYScreenMove, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonHomeXYScreenMove, 53, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonHomeXYScreenMove, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonHomeXYScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ButtonHomeXYScreenMove, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonHomeXYScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonHomeXYScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_x(ui_ButtonHomeXYScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_ofs_y(ui_ButtonHomeXYScreenMove, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonHomeXYScreenMove, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonHomeXYScreenMove, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonHomeXYScreenMove, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonHomeXYScreenMove, LV_BORDER_SIDE_FULL,
                                 LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui_ButtonHomeXYScreenMove, lv_color_hex(0x42BDD8),
                                LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui_ButtonHomeXYScreenMove, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelHomeXYScreenMove = lv_label_create(ui_ButtonHomeXYScreenMove);
    lv_obj_set_width(ui_LabelHomeXYScreenMove, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelHomeXYScreenMove, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelHomeXYScreenMove, 0);
    lv_obj_set_y(ui_LabelHomeXYScreenMove, 2);
    lv_obj_set_align(ui_LabelHomeXYScreenMove, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelHomeXYScreenMove, "XY");
    lv_obj_set_style_text_color(ui_LabelHomeXYScreenMove, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelHomeXYScreenMove, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelHomeXYScreenMove, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelMoveZ = lv_obj_create(ui_ScreenAxisMovePageCenterPanel);
    lv_obj_set_width(ui_PanelMoveZ, 64);
    lv_obj_set_height(ui_PanelMoveZ, 240);
    lv_obj_align(ui_PanelMoveZ, LV_ALIGN_TOP_LEFT, 593, 90);
    lv_obj_clear_flag(ui_PanelMoveZ, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelMoveZ, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelMoveZ, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelMoveZ, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelUpperZ = lv_obj_create(ui_PanelMoveZ);
    lv_obj_set_width(ui_PanelUpperZ, 60);
    lv_obj_set_height(ui_PanelUpperZ, 60);
    lv_obj_set_x(ui_PanelUpperZ, -20);
    lv_obj_set_y(ui_PanelUpperZ, -20);
    lv_obj_clear_flag(ui_PanelUpperZ, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelUpperZ, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelUpperZ, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelUpperZ, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelUpperZ, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelUpperZ, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelUpperZ, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelUpperZ, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelFlagZ = lv_label_create(ui_PanelUpperZ);
    lv_obj_set_width(ui_LabelFlagZ, 20);
    lv_obj_set_height(ui_LabelFlagZ, 30);
    lv_obj_set_x(ui_LabelFlagZ, -1);
    lv_obj_set_y(ui_LabelFlagZ, 3);
    lv_label_set_text(ui_LabelFlagZ, "Z");
    lv_obj_set_style_text_color(ui_LabelFlagZ, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFlagZ, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelFlagZ, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFlagZ, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageUpperZ = lv_img_create(ui_PanelUpperZ);
    lv_img_set_src(ui_ImageUpperZ, &ui_img_up_png);
    lv_obj_set_width(ui_ImageUpperZ, 25);
    lv_obj_set_height(ui_ImageUpperZ, 25);
    lv_obj_set_x(ui_ImageUpperZ, -4);
    lv_obj_set_y(ui_ImageUpperZ, -20);
    lv_obj_add_flag(ui_ImageUpperZ, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageUpperZ, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonHomeZ = lv_btn_create(ui_PanelMoveZ);
    lv_obj_set_width(ui_ButtonHomeZ, 60);
    lv_obj_set_height(ui_ButtonHomeZ, 60);
    lv_obj_set_x(ui_ButtonHomeZ, -20);
    lv_obj_set_y(ui_ButtonHomeZ, 68);
    lv_obj_add_flag(ui_ButtonHomeZ, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonHomeZ, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonHomeZ, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonHomeZ, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonHomeZ, &ui_img_homez_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ButtonHomeZ, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ButtonHomeZ, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui_ButtonHomeZ, 0, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_ButtonHomeZ, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonHomeZ, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonHomeZ, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_ButtonHomeZ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonHomeZ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelDownZ = lv_obj_create(ui_PanelMoveZ);
    lv_obj_set_width(ui_PanelDownZ, 60);
    lv_obj_set_height(ui_PanelDownZ, 60);
    lv_obj_set_x(ui_PanelDownZ, -20);
    lv_obj_set_y(ui_PanelDownZ, 158);
    lv_obj_clear_flag(ui_PanelDownZ, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelDownZ, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelDownZ, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelDownZ, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelDownZ, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelDownZ, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelDownZ, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelDownZ, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelFlagZDown = lv_label_create(ui_PanelDownZ);
    lv_obj_set_width(ui_LabelFlagZDown, 20);
    lv_obj_set_height(ui_LabelFlagZDown, 30);
    lv_obj_set_x(ui_LabelFlagZDown, -1);
    lv_obj_set_y(ui_LabelFlagZDown, -20);
    lv_label_set_text(ui_LabelFlagZDown, "Z");
    lv_obj_set_style_text_color(ui_LabelFlagZDown, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFlagZDown, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelFlagZDown, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFlagZDown, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageDownZ = lv_img_create(ui_PanelDownZ);
    lv_img_set_src(ui_ImageDownZ, &ui_img_down_png);
    lv_obj_set_width(ui_ImageDownZ, 25);
    lv_obj_set_height(ui_ImageDownZ, 25);
    lv_obj_set_x(ui_ImageDownZ, -4);
    lv_obj_set_y(ui_ImageDownZ, 8);
    lv_obj_add_flag(ui_ImageDownZ, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageDownZ, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_ButtonHomeScreenAxisMove, ui_event_PageChange, LV_EVENT_ALL, "0");
    lv_obj_add_event_cb(ui_ButtonFileManageScreenAxisMove, ui_event_PageChange, LV_EVENT_ALL, "3");
    lv_obj_add_event_cb(ui_ButtonSettingsScreenAxisMove, ui_event_PageChange, LV_EVENT_ALL, "4");
    lv_obj_add_event_cb(ui_ButtonReserveScreenAxisMove, ui_event_PageChange, LV_EVENT_ALL, "5");

    lv_obj_add_event_cb(ui_PanelHotend, ui_event_PanelHotend, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelBed, ui_event_PanelBed, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelHotendHeatingScreenMove, ui_event_PanelHotend, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelBedHeatingScreenMove, ui_event_PanelBed, LV_EVENT_ALL, NULL);

    lv_obj_add_event_cb(ui_PanelMoveTitle, ui_event_TitleChange, LV_EVENT_ALL, "0");
    lv_obj_add_event_cb(ui_PanelFilament, ui_event_TitleChange, LV_EVENT_ALL, "1");
    lv_obj_add_event_cb(ui_PanelCool, ui_event_TitleChange, LV_EVENT_ALL, "2");
    lv_obj_add_event_cb(ui_PanelAdjustment, ui_event_TitleChange, LV_EVENT_ALL, "3"); 

    lv_obj_add_event_cb(ui_PanelStepper, ui_event_ImgButtonStepperDisable, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSmallDis, ui_event_ButtonSmallDis, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonMidDis, ui_event_ButtonMidDis, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonLargeDis, ui_event_ButtonLargeDis, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSubXScreenMove, ui_event_ButtonSubXScreenMove, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonAddXScreenMove, ui_event_ButtonAddXScreenMove, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonAddYScreenMove, ui_event_ButtonAddYScreenMove, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSubYScreenMove, ui_event_ButtonSubYScreenMove, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonHomeXYScreenMove, ui_event_ButtonHomeXYScreenMove, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelUpperZ, ui_event_PanelUpperZ, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonHomeZ, ui_event_ButtonHomeZ, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelDownZ, ui_event_PanelDownZ, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ScreenAxisMovePage, ui_event_ScreenAxisMovePage, LV_EVENT_ALL, NULL);

    //冷却页面
    ui_ScreenCoolPanelCenter = lv_obj_create(ui_ScreenAxisMovePage);
    lv_obj_set_width(ui_ScreenCoolPanelCenter, 720);
    lv_obj_set_height(ui_ScreenCoolPanelCenter, 430);
    lv_obj_set_x(ui_ScreenCoolPanelCenter, 80);
    lv_obj_set_y(ui_ScreenCoolPanelCenter, 50);
    lv_obj_clear_flag(ui_ScreenCoolPanelCenter, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScreenCoolPanelCenter, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScreenCoolPanelCenter, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenCoolPanelCenter, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ScreenCoolPanelCenter, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenCoolPanelFans = lv_obj_create(ui_ScreenCoolPanelCenter);
    lv_obj_set_width(ui_ScreenCoolPanelFans, 696);
    lv_obj_set_height(ui_ScreenCoolPanelFans, 406);
    lv_obj_set_x(ui_ScreenCoolPanelFans, -10);
    lv_obj_set_y(ui_ScreenCoolPanelFans, -10);
    lv_obj_clear_flag(ui_ScreenCoolPanelFans, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenCoolPanelFans, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenCoolPanelFans, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ScreenCoolPanelFans, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenCoolImageModelFan = lv_img_create(ui_ScreenCoolPanelFans);
    lv_img_set_src(ui_ScreenCoolImageModelFan, &ui_img_cool_stop_fan_png);
    lv_obj_set_width(ui_ScreenCoolImageModelFan, 39);
    lv_obj_set_height(ui_ScreenCoolImageModelFan, 39);
    lv_obj_set_x(ui_ScreenCoolImageModelFan, 13);
    lv_obj_set_y(ui_ScreenCoolImageModelFan, 64);
    lv_obj_add_flag(ui_ScreenCoolImageModelFan, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ScreenCoolImageModelFan, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ScreenCoolLabelModelFan = lv_label_create(ui_ScreenCoolPanelFans);
    lv_obj_set_width(ui_ScreenCoolLabelModelFan, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ScreenCoolLabelModelFan, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_ScreenCoolLabelModelFan, 62);
    lv_obj_set_y(ui_ScreenCoolLabelModelFan, 30);
    lv_label_set_text(ui_ScreenCoolLabelModelFan, "");
    lv_obj_set_style_text_color(ui_ScreenCoolLabelModelFan, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenCoolLabelModelFan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScreenCoolLabelModelFan, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenCoolSliderModelFan = lv_slider_create(ui_ScreenCoolPanelFans);
    lv_slider_set_value(ui_ScreenCoolSliderModelFan, 20, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_ScreenCoolSliderModelFan) == LV_SLIDER_MODE_RANGE) 
        lv_slider_set_left_value(ui_ScreenCoolSliderModelFan, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_ScreenCoolSliderModelFan, 492);
    lv_obj_set_height(ui_ScreenCoolSliderModelFan, 16);
    lv_obj_set_x(ui_ScreenCoolSliderModelFan, 62);
    lv_obj_set_y(ui_ScreenCoolSliderModelFan, 74);
    lv_obj_set_style_radius(ui_ScreenCoolSliderModelFan, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScreenCoolSliderModelFan, lv_color_hex(0x616367), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenCoolSliderModelFan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ScreenCoolSliderModelFan, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScreenCoolSliderModelFan, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenCoolSliderModelFan, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ScreenCoolSliderModelFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScreenCoolSliderModelFan, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenCoolSliderModelFan, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ScreenCoolSliderModelFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ScreenCoolSliderModelFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ScreenCoolSliderModelFan, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ScreenCoolSliderModelFan, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_ScreenCoolSliderModelFan, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_ScreenCoolSliderModelFan, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_ext_click_area(ui_ScreenCoolSliderModelFan, 50);

    ui_ScreenCoolLabelModelPercent = lv_label_create(ui_ScreenCoolPanelFans);
    lv_obj_set_width(ui_ScreenCoolLabelModelPercent, 70);
    lv_obj_set_height(ui_ScreenCoolLabelModelPercent, 30);
    lv_obj_set_x(ui_ScreenCoolLabelModelPercent, 572);
    lv_obj_set_y(ui_ScreenCoolLabelModelPercent, 66);
    lv_label_set_text(ui_ScreenCoolLabelModelPercent, "");
    lv_obj_set_style_text_color(ui_ScreenCoolLabelModelPercent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenCoolLabelModelPercent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScreenCoolLabelModelPercent, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenCoolImageAuxiliaryFan = lv_img_create(ui_ScreenCoolPanelFans);
    lv_img_set_src(ui_ScreenCoolImageAuxiliaryFan, &ui_img_cool_stop_fan_png);
    lv_obj_set_width(ui_ScreenCoolImageAuxiliaryFan, 39);
    lv_obj_set_height(ui_ScreenCoolImageAuxiliaryFan, 39);
    lv_obj_set_x(ui_ScreenCoolImageAuxiliaryFan, 13);
    lv_obj_set_y(ui_ScreenCoolImageAuxiliaryFan, 169);
    lv_obj_add_flag(ui_ScreenCoolImageAuxiliaryFan, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ScreenCoolImageAuxiliaryFan, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ScreenCoolLabelAuxiliaryFan = lv_label_create(ui_ScreenCoolPanelFans);
    lv_obj_set_width(ui_ScreenCoolLabelAuxiliaryFan, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ScreenCoolLabelAuxiliaryFan, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_ScreenCoolLabelAuxiliaryFan, 62);
    lv_obj_set_y(ui_ScreenCoolLabelAuxiliaryFan, 135);
    lv_label_set_text(ui_ScreenCoolLabelAuxiliaryFan, "辅助风扇");
    lv_obj_set_style_text_color(ui_ScreenCoolLabelAuxiliaryFan, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenCoolLabelAuxiliaryFan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScreenCoolLabelAuxiliaryFan, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenCoolSliderAuxiliaryFan = lv_slider_create(ui_ScreenCoolPanelFans);
    if(lv_slider_get_mode(ui_ScreenCoolSliderAuxiliaryFan) == LV_SLIDER_MODE_RANGE) 
        lv_slider_set_left_value(ui_ScreenCoolSliderAuxiliaryFan, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_ScreenCoolSliderAuxiliaryFan, 492);
    lv_obj_set_height(ui_ScreenCoolSliderAuxiliaryFan, 16);
    lv_obj_set_x(ui_ScreenCoolSliderAuxiliaryFan, 62);
    lv_obj_set_y(ui_ScreenCoolSliderAuxiliaryFan, 179);
    lv_obj_set_style_radius(ui_ScreenCoolSliderAuxiliaryFan, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScreenCoolSliderAuxiliaryFan, lv_color_hex(0x616367), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenCoolSliderAuxiliaryFan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ScreenCoolSliderAuxiliaryFan, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScreenCoolSliderAuxiliaryFan, lv_color_hex(0x42BDD8),
                              LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenCoolSliderAuxiliaryFan, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ScreenCoolSliderAuxiliaryFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScreenCoolSliderAuxiliaryFan, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenCoolSliderAuxiliaryFan, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ScreenCoolSliderAuxiliaryFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ScreenCoolSliderAuxiliaryFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ScreenCoolSliderAuxiliaryFan, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ScreenCoolSliderAuxiliaryFan, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_ScreenCoolSliderAuxiliaryFan, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_ScreenCoolSliderAuxiliaryFan, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_ext_click_area(ui_ScreenCoolSliderAuxiliaryFan, 50);

    ui_ScreenCoolLabelAuxiliaryPercent = lv_label_create(ui_ScreenCoolPanelFans);
    lv_obj_set_width(ui_ScreenCoolLabelAuxiliaryPercent, 70);
    lv_obj_set_height(ui_ScreenCoolLabelAuxiliaryPercent, 30);
    lv_obj_set_x(ui_ScreenCoolLabelAuxiliaryPercent, 572);
    lv_obj_set_y(ui_ScreenCoolLabelAuxiliaryPercent, 171);
    lv_label_set_text(ui_ScreenCoolLabelAuxiliaryPercent, "");
    lv_obj_set_style_text_color(ui_ScreenCoolLabelAuxiliaryPercent, lv_color_hex(0xFFFFFF),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenCoolLabelAuxiliaryPercent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScreenCoolLabelAuxiliaryPercent, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenCoolImageChassisFan = lv_img_create(ui_ScreenCoolPanelFans);
    lv_img_set_src(ui_ScreenCoolImageChassisFan, &ui_img_cool_stop_fan_png);
    lv_obj_set_width(ui_ScreenCoolImageChassisFan, 39);
    lv_obj_set_height(ui_ScreenCoolImageChassisFan, 39);
    lv_obj_set_x(ui_ScreenCoolImageChassisFan, 13);
    lv_obj_set_y(ui_ScreenCoolImageChassisFan, 271);
    lv_obj_add_flag(ui_ScreenCoolImageChassisFan, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ScreenCoolImageChassisFan, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ScreenCoolLabelChassisFan = lv_label_create(ui_ScreenCoolPanelFans);
    lv_obj_set_width(ui_ScreenCoolLabelChassisFan, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ScreenCoolLabelChassisFan, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_ScreenCoolLabelChassisFan, 62);
    lv_obj_set_y(ui_ScreenCoolLabelChassisFan, 237);
    lv_label_set_text(ui_ScreenCoolLabelChassisFan, "机箱风扇");
    lv_obj_set_style_text_color(ui_ScreenCoolLabelChassisFan, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenCoolLabelChassisFan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScreenCoolLabelChassisFan, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenCoolSliderChassisFan = lv_slider_create(ui_ScreenCoolPanelFans);
    lv_slider_set_value(ui_ScreenCoolSliderChassisFan, 20, LV_ANIM_OFF);
    if(lv_slider_get_mode(ui_ScreenCoolSliderChassisFan) == LV_SLIDER_MODE_RANGE) 
        lv_slider_set_left_value(ui_ScreenCoolSliderChassisFan, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_ScreenCoolSliderChassisFan, 492);
    lv_obj_set_height(ui_ScreenCoolSliderChassisFan, 16);
    lv_obj_set_x(ui_ScreenCoolSliderChassisFan, 62);
    lv_obj_set_y(ui_ScreenCoolSliderChassisFan, 281);
    lv_obj_set_style_radius(ui_ScreenCoolSliderChassisFan, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScreenCoolSliderChassisFan, lv_color_hex(0x616367), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenCoolSliderChassisFan, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ScreenCoolSliderChassisFan, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScreenCoolSliderChassisFan, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenCoolSliderChassisFan, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_radius(ui_ScreenCoolSliderChassisFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScreenCoolSliderChassisFan, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenCoolSliderChassisFan, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ScreenCoolSliderChassisFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ScreenCoolSliderChassisFan, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ScreenCoolSliderChassisFan, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ScreenCoolSliderChassisFan, 8, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_ScreenCoolSliderChassisFan, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_ScreenCoolSliderChassisFan, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_ext_click_area(ui_ScreenCoolSliderChassisFan, 50);

    ui_ScreenCoolLabelChassisPercent = lv_label_create(ui_ScreenCoolPanelFans);
    lv_obj_set_width(ui_ScreenCoolLabelChassisPercent, 70);
    lv_obj_set_height(ui_ScreenCoolLabelChassisPercent, 30);
    lv_obj_set_x(ui_ScreenCoolLabelChassisPercent, 572);
    lv_obj_set_y(ui_ScreenCoolLabelChassisPercent, 273);
    lv_label_set_text(ui_ScreenCoolLabelChassisPercent, "");
    lv_obj_set_style_text_color(ui_ScreenCoolLabelChassisPercent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenCoolLabelChassisPercent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScreenCoolLabelChassisPercent, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_add_event_cb(ui_ScreenCoolSliderModelFan, ui_event_SliderFansChange, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ScreenCoolSliderAuxiliaryFan, ui_event_SliderFansChange, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ScreenCoolSliderChassisFan, ui_event_SliderFansChange, LV_EVENT_ALL, NULL);

    /*************************************/
    lv_slider_set_range(ui_ScreenCoolSliderModelFan, 0, 100);
    lv_slider_set_range(ui_ScreenCoolSliderAuxiliaryFan, 0, 100);
    lv_slider_set_range(ui_ScreenCoolSliderChassisFan, 0, 100);


    //进退料子页面
    ui_PanelCenterScreenFila = lv_obj_create(ui_ScreenAxisMovePage);
    lv_obj_set_width(ui_PanelCenterScreenFila, 720);
    lv_obj_set_height(ui_PanelCenterScreenFila, 430);
    lv_obj_set_x(ui_PanelCenterScreenFila, 80);
    lv_obj_set_y(ui_PanelCenterScreenFila, 50);
    lv_obj_clear_flag(ui_PanelCenterScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelCenterScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelCenterScreenFila, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCenterScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelCenterScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    /**--------------------------------action pan------------------------***/
    ui_PanelActionScreenFila = lv_obj_create(ui_PanelCenterScreenFila);
    lv_obj_set_width(ui_PanelActionScreenFila, 424);
    lv_obj_set_height(ui_PanelActionScreenFila, 406);
    lv_obj_set_x(ui_PanelActionScreenFila, -9);
    lv_obj_set_y(ui_PanelActionScreenFila, -12);
    lv_obj_clear_flag(ui_PanelActionScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelActionScreenFila, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelActionScreenFila, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelActionScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelActionScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);


    /************************hotend temper edit panel******************************/
    ui_PanelTempScreenFilament = lv_obj_create(ui_PanelActionScreenFila);
    lv_obj_set_width(ui_PanelTempScreenFilament, 424);
    lv_obj_set_height(ui_PanelTempScreenFilament, 110);
    lv_obj_set_x(ui_PanelTempScreenFilament, -22);
    lv_obj_set_y(ui_PanelTempScreenFilament, 54);
    lv_obj_clear_flag(ui_PanelTempScreenFilament, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelTempScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelTempScreenFilament, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelTempScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelTempScreenFilament, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTitleScreenFilament = lv_label_create(ui_PanelTempScreenFilament);
    lv_obj_set_width(ui_LabelTitleScreenFilament, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTitleScreenFilament, 30);
    lv_obj_align(ui_LabelTitleScreenFilament, LV_ALIGN_TOP_MID, 0, -5);
    lv_label_set_text(ui_LabelTitleScreenFilament, HotendTemp[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelTitleScreenFilament, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTitleScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTitleScreenFilament, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTitleScreenFilament, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonSubTemperScreenFilament = lv_btn_create(ui_PanelTempScreenFilament);
    lv_obj_set_width(ui_ButtonSubTemperScreenFilament, 52);
    lv_obj_set_height(ui_ButtonSubTemperScreenFilament, 52);
    lv_obj_set_x(ui_ButtonSubTemperScreenFilament, 38);
    lv_obj_set_y(ui_ButtonSubTemperScreenFilament, 33);
    lv_obj_add_flag(ui_ButtonSubTemperScreenFilament, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSubTemperScreenFilament, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonSubTemperScreenFilament, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonSubTemperScreenFilament, &ui_img_sub_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonSubTemperScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonSubTemperScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonAddTemperScreenFilament = lv_btn_create(ui_PanelTempScreenFilament);
    lv_obj_set_width(ui_ButtonAddTemperScreenFilament, 52);
    lv_obj_set_height(ui_ButtonAddTemperScreenFilament, 52);
    lv_obj_set_x(ui_ButtonAddTemperScreenFilament, 290);
    lv_obj_set_y(ui_ButtonAddTemperScreenFilament, 33);
    lv_obj_add_flag(ui_ButtonAddTemperScreenFilament, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonAddTemperScreenFilament, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonAddTemperScreenFilament, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonAddTemperScreenFilament, &ui_img_add_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonAddTemperScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonAddTemperScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelTemperValueScreenFilament = lv_obj_create(ui_PanelTempScreenFilament);
    lv_obj_set_width(ui_PanelTemperValueScreenFilament, 146);
    lv_obj_set_height(ui_PanelTemperValueScreenFilament, 54);
    lv_obj_set_x(ui_PanelTemperValueScreenFilament, 117);
    lv_obj_set_y(ui_PanelTemperValueScreenFilament, 32);
    lv_obj_clear_flag(ui_PanelTemperValueScreenFilament, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelTemperValueScreenFilament, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelTemperValueScreenFilament, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelTemperValueScreenFilament, 128, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelTemperValueScreenFilament, lv_color_hex(0x5E6166),
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelTemperValueScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelTemperValueScreenFilament, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTemperScreenFilament = lv_label_create(ui_PanelTemperValueScreenFilament);
    lv_obj_set_width(ui_LabelTemperScreenFilament, 62);
    lv_obj_set_height(ui_LabelTemperScreenFilament, 30);
    lv_obj_set_x(ui_LabelTemperScreenFilament, 12);
    lv_obj_set_y(ui_LabelTemperScreenFilament, -9);
    char buf[10] = {0};
    sprintf(buf, "%d", edit_target_temper);
    lv_label_set_text(ui_LabelTemperScreenFilament, buf);
    lv_obj_set_style_text_color(ui_LabelTemperScreenFilament, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTemperScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTemperScreenFilament, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTemperScreenFilament, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTemperUnitScreenFilament = lv_label_create(ui_PanelTemperValueScreenFilament);
    lv_obj_set_width(ui_LabelTemperUnitScreenFilament, 26);
    lv_obj_set_height(ui_LabelTemperUnitScreenFilament, 22);
    lv_obj_set_x(ui_LabelTemperUnitScreenFilament, 76);
    lv_obj_set_y(ui_LabelTemperUnitScreenFilament, -3);
    lv_label_set_text(ui_LabelTemperUnitScreenFilament, "°C");
    lv_obj_set_style_text_color(ui_LabelTemperUnitScreenFilament, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTemperUnitScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTemperUnitScreenFilament, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);


    /**********************hotend heating panel************************************/
    ui_PanelhotendHeatScreenFilament = lv_obj_create(ui_PanelActionScreenFila);
    lv_obj_set_width(ui_PanelhotendHeatScreenFilament, 424);
    lv_obj_set_height(ui_PanelhotendHeatScreenFilament, 115);
    lv_obj_set_x(ui_PanelhotendHeatScreenFilament, -22);
    lv_obj_set_y(ui_PanelhotendHeatScreenFilament, 72);
    lv_obj_clear_flag(ui_PanelhotendHeatScreenFilament, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelhotendHeatScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelhotendHeatScreenFilament, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelhotendHeatScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelhotendHeatScreenFilament, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageHotendHeating = lv_img_create(ui_PanelhotendHeatScreenFilament);
    lv_img_set_src(ui_ImageHotendHeating, &ui_img_filament_hotend_heat_png);
    lv_obj_set_width(ui_ImageHotendHeating, 74);
    lv_obj_set_height(ui_ImageHotendHeating, 75);
    lv_obj_set_x(ui_ImageHotendHeating, 153);
    lv_obj_set_y(ui_ImageHotendHeating, -22);
    lv_obj_add_flag(ui_ImageHotendHeating, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHotendHeating, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelRealTemper = lv_label_create(ui_PanelhotendHeatScreenFilament);
    lv_obj_set_width(ui_LabelRealTemper, 80);
    lv_obj_set_height(ui_LabelRealTemper, 30);
    lv_obj_set_x(ui_LabelRealTemper, 91);
    lv_obj_set_y(ui_LabelRealTemper, 59);
    lv_label_set_text(ui_LabelRealTemper, "240°C");
    lv_obj_set_style_text_color(ui_LabelRealTemper, lv_color_hex(0xFA6D31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelRealTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelRealTemper, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelRealTemper, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTargetTemper = lv_label_create(ui_PanelhotendHeatScreenFilament);
    lv_obj_set_width(ui_LabelTargetTemper, 80);
    lv_obj_set_height(ui_LabelTargetTemper, 30);
    lv_obj_set_x(ui_LabelTargetTemper, 210);
    lv_obj_set_y(ui_LabelTargetTemper, 59);
    lv_label_set_text(ui_LabelTargetTemper, "240°C");
    lv_obj_set_style_text_color(ui_LabelTargetTemper, lv_color_hex(0xFA6D31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTargetTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTargetTemper, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTargetTemper, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageTemperTo = lv_img_create(ui_PanelhotendHeatScreenFilament);
    lv_img_set_src(ui_ImageTemperTo, &ui_img_filament_to_png);
    lv_obj_set_width(ui_ImageTemperTo, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ImageTemperTo, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ImageTemperTo, 0);
    lv_obj_set_y(ui_ImageTemperTo, 38);
    lv_obj_set_align(ui_ImageTemperTo, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ImageTemperTo, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageTemperTo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    /*****************hotend normal panel*************************/
    ui_PanelhotendNormalScreenFila = lv_obj_create(ui_PanelActionScreenFila);
    lv_obj_set_width(ui_PanelhotendNormalScreenFila, 424);
    lv_obj_set_height(ui_PanelhotendNormalScreenFila, 115);
    lv_obj_set_x(ui_PanelhotendNormalScreenFila, -22);
    lv_obj_set_y(ui_PanelhotendNormalScreenFila, 72);
    lv_obj_clear_flag(ui_PanelhotendNormalScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelhotendNormalScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelhotendNormalScreenFila, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelhotendNormalScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelhotendNormalScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageHotendNormal = lv_img_create(ui_PanelhotendNormalScreenFila);
    lv_img_set_src(ui_ImageHotendNormal, &ui_img_filament_hotend_normal_png);
    lv_obj_set_width(ui_ImageHotendNormal, 74);
    lv_obj_set_height(ui_ImageHotendNormal, 75);
    lv_obj_set_x(ui_ImageHotendNormal, 153);
    lv_obj_set_y(ui_ImageHotendNormal, -22);
    lv_obj_add_flag(ui_ImageHotendNormal, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageHotendNormal, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelNormalRealTemper = lv_label_create(ui_PanelhotendNormalScreenFila);
    lv_obj_set_width(ui_LabelNormalRealTemper, 80);
    lv_obj_set_height(ui_LabelNormalRealTemper, 30);
    lv_obj_set_x(ui_LabelNormalRealTemper, 150);
    lv_obj_set_y(ui_LabelNormalRealTemper, 60);
    lv_label_set_text(ui_LabelNormalRealTemper, "240°C");
    lv_obj_set_style_text_color(ui_LabelNormalRealTemper, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelNormalRealTemper, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelNormalRealTemper, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelNormalRealTemper, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    /***************************filament action panel******************************/
    ui_PanelInAndOutAction = lv_obj_create(ui_PanelActionScreenFila);
    lv_obj_set_width(ui_PanelInAndOutAction, 424);
    lv_obj_set_height(ui_PanelInAndOutAction, 64);
    lv_obj_set_x(ui_PanelInAndOutAction, -22);
    lv_obj_set_y(ui_PanelInAndOutAction, 299);
    lv_obj_clear_flag(ui_PanelInAndOutAction, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelInAndOutAction, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelInAndOutAction, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelInAndOutAction, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelInAndOutAction, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonInFilaScreenFilament = lv_btn_create(ui_PanelInAndOutAction);
    lv_obj_set_width(ui_ButtonInFilaScreenFilament, 116);
    lv_obj_set_height(ui_ButtonInFilaScreenFilament, 60);
    lv_obj_set_x(ui_ButtonInFilaScreenFilament, 38);
    lv_obj_set_y(ui_ButtonInFilaScreenFilament, -20);
    lv_obj_add_flag(ui_ButtonInFilaScreenFilament, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonInFilaScreenFilament, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonInFilaScreenFilament, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonInFilaScreenFilament, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonInFilaScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonInFilaScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonInFilaScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_bg_color(ui_ButtonInFilaScreenFilament, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_bg_opa(ui_ButtonInFilaScreenFilament, 178, LV_STATE_DISABLED);

    ui_LabelInFilaScreenFilament = lv_label_create(ui_ButtonInFilaScreenFilament);
    lv_obj_set_width(ui_LabelInFilaScreenFilament, 116);
    lv_obj_set_height(ui_LabelInFilaScreenFilament, 30);
    lv_obj_set_align(ui_LabelInFilaScreenFilament, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelInFilaScreenFilament, "进料");
    lv_obj_set_style_text_align(ui_LabelInFilaScreenFilament, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelInFilaScreenFilament, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_LabelInFilaScreenFilament, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelInFilaScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelInFilaScreenFilament, 178, LV_PART_MAIN | LV_STATE_DISABLED);

    ui_ButtonOutFilaScreenFilament = lv_btn_create(ui_PanelInAndOutAction);
    lv_obj_set_width(ui_ButtonOutFilaScreenFilament, 116);
    lv_obj_set_height(ui_ButtonOutFilaScreenFilament, 60);
    lv_obj_set_x(ui_ButtonOutFilaScreenFilament, 226);
    lv_obj_set_y(ui_ButtonOutFilaScreenFilament, -20);
    lv_obj_add_flag(ui_ButtonOutFilaScreenFilament, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonOutFilaScreenFilament, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonOutFilaScreenFilament, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonOutFilaScreenFilament, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonOutFilaScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonOutFilaScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonOutFilaScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonOutFilaScreenFilament, 178, LV_PART_MAIN | LV_STATE_DISABLED);

    ui_LabelOutFilaScreenFilament = lv_label_create(ui_ButtonOutFilaScreenFilament);
    lv_obj_set_width(ui_LabelOutFilaScreenFilament, 116);
    lv_obj_set_height(ui_LabelOutFilaScreenFilament, 30);
    lv_obj_set_align(ui_LabelOutFilaScreenFilament, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelOutFilaScreenFilament, "退料");
    lv_obj_set_style_text_align(ui_LabelOutFilaScreenFilament, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelOutFilaScreenFilament, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelOutFilaScreenFilament, 178, LV_PART_MAIN | LV_STATE_DISABLED);

    /**--------------------------------action pan------------------------***/


    /***++++++++++++++++++++++++++++Prompt panel+++++++++++++++++++++++++++++*****/
    ui_PanelPromptScreenFila = lv_obj_create(ui_PanelCenterScreenFila);
    lv_obj_set_width(ui_PanelPromptScreenFila, 266);
    lv_obj_set_height(ui_PanelPromptScreenFila, 406);
    lv_obj_set_x(ui_PanelPromptScreenFila, 424);
    lv_obj_set_y(ui_PanelPromptScreenFila, -12);
    lv_obj_clear_flag(ui_PanelPromptScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPromptScreenFila, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelPromptScreenFila, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelPromptScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPromptScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelPromptScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel6ScreenFilament = lv_obj_create(ui_PanelPromptScreenFila);
    lv_obj_set_width(ui_Panel6ScreenFilament, 256);
    lv_obj_set_height(ui_Panel6ScreenFilament, 1);
    lv_obj_align(ui_Panel6ScreenFilament, LV_ALIGN_TOP_MID, 0, 60);
    lv_obj_clear_flag(ui_Panel6ScreenFilament, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel6ScreenFilament, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel6ScreenFilament, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel6ScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel6ScreenFilament, lv_color_hex(0x55585C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel6ScreenFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel6ScreenFilament, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    /*****************************tips infor********************************************/
    ui_LabelTitleTips = lv_label_create(ui_PanelPromptScreenFila);
    lv_obj_set_width(ui_LabelTitleTips, 240);
    lv_obj_set_height(ui_LabelTitleTips, 30);
    lv_obj_align(ui_LabelTitleTips, LV_ALIGN_TOP_MID, 0, 12);
    lv_label_set_text(ui_LabelTitleTips, "提示");
    lv_obj_set_style_text_color(ui_LabelTitleTips, lv_color_hex(0x40BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTitleTips, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTitleTips, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTitleTips, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTipsContentScreenFila = lv_label_create(ui_PanelPromptScreenFila);
    lv_obj_set_width(ui_LabelTipsContentScreenFila, 229);
    lv_obj_set_height(ui_LabelTipsContentScreenFila, 300);
    lv_obj_align(ui_LabelTipsContentScreenFila, LV_ALIGN_TOP_MID, 0, 79);
    lv_label_set_text(ui_LabelTipsContentScreenFila, "进退料前温度将自动加热");
    lv_obj_set_style_text_color(ui_LabelTipsContentScreenFila, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTipsContentScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTipsContentScreenFila, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);


    /**************************in and out filament proccess*********************************/
    ui_LabelTitleFilament = lv_label_create(ui_PanelPromptScreenFila);
    lv_obj_set_width(ui_LabelTitleFilament, 240);
    lv_obj_set_height(ui_LabelTitleFilament, 30);
    lv_obj_align(ui_LabelTitleFilament, LV_ALIGN_TOP_MID, 0, 12);
    lv_label_set_text(ui_LabelTitleFilament, "");
    lv_obj_set_style_text_color(ui_LabelTitleFilament, lv_color_hex(0x40BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTitleFilament, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTitleFilament, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTitleFilament, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelFilamentProccess = lv_obj_create(ui_PanelPromptScreenFila);
    lv_obj_set_width(ui_PanelFilamentProccess, 266);
    lv_obj_set_height(ui_PanelFilamentProccess, 330);
    lv_obj_align(ui_PanelFilamentProccess, LV_ALIGN_TOP_MID, 0, 62);
    lv_obj_clear_flag(ui_PanelFilamentProccess, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelFilamentProccess, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelFilamentProccess, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelFilamentProccess, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelFilamentProccess, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BtnFirstStepScreenFila = lv_btn_create(ui_PanelFilamentProccess);
    lv_obj_set_width(ui_BtnFirstStepScreenFila, 30);
    lv_obj_set_height(ui_BtnFirstStepScreenFila, 30);
    lv_obj_set_x(ui_BtnFirstStepScreenFila, -4);
    lv_obj_set_y(ui_BtnFirstStepScreenFila, -1);
    lv_obj_add_flag(ui_BtnFirstStepScreenFila, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BtnFirstStepScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BtnFirstStepScreenFila, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BtnFirstStepScreenFila, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BtnFirstStepScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_BtnFirstStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_BtnFirstStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFirstStepScreenFila = lv_label_create(ui_BtnFirstStepScreenFila);
    lv_obj_set_width(ui_LabelFirstStepScreenFila, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelFirstStepScreenFila, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelFirstStepScreenFila, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelFirstStepScreenFila, "1");
    lv_obj_set_style_text_font(ui_LabelFirstStepScreenFila, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFilamentFirstStep = lv_label_create(ui_PanelFilamentProccess);
    lv_obj_set_width(ui_LabelFilamentFirstStep, 200);
    lv_obj_set_height(ui_LabelFilamentFirstStep, 50);
    lv_obj_set_x(ui_LabelFilamentFirstStep, 34);
    lv_obj_set_y(ui_LabelFilamentFirstStep, -1);
    lv_label_set_text(ui_LabelFilamentFirstStep, "");
    lv_obj_set_style_text_color(ui_LabelFilamentFirstStep, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFilamentFirstStep, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFilamentFirstStep, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelFirstStepScreenFila = lv_obj_create(ui_PanelFilamentProccess);
    lv_obj_set_width(ui_PanelFirstStepScreenFila, 3);
    lv_obj_set_height(ui_PanelFirstStepScreenFila, 59);
    lv_obj_set_x(ui_PanelFirstStepScreenFila, 10);
    lv_obj_set_y(ui_PanelFirstStepScreenFila, 29);
    lv_obj_clear_flag(ui_PanelFirstStepScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelFirstStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelFirstStepScreenFila, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelFirstStepScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_PanelFirstStepScreenFila, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_PanelFirstStepScreenFila, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelFirstStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelFirstStepScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BtnSecondStepScreenFila = lv_btn_create(ui_PanelFilamentProccess);
    lv_obj_set_width(ui_BtnSecondStepScreenFila, 30);
    lv_obj_set_height(ui_BtnSecondStepScreenFila, 30);
    lv_obj_set_x(ui_BtnSecondStepScreenFila, -4);
    lv_obj_set_y(ui_BtnSecondStepScreenFila, 88);
    lv_obj_add_flag(ui_BtnSecondStepScreenFila, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BtnSecondStepScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BtnSecondStepScreenFila, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BtnSecondStepScreenFila, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BtnSecondStepScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_BtnSecondStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_BtnSecondStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelSecondStepScreenFila = lv_label_create(ui_BtnSecondStepScreenFila);
    lv_obj_set_width(ui_LabelSecondStepScreenFila, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelSecondStepScreenFila, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelSecondStepScreenFila, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelSecondStepScreenFila, "2");
    lv_obj_set_style_text_font(ui_LabelSecondStepScreenFila, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFilamentSecondStep = lv_label_create(ui_PanelFilamentProccess);
    lv_obj_set_width(ui_LabelFilamentSecondStep, 200);
    lv_obj_set_height(ui_LabelFilamentSecondStep, 30);
    lv_obj_set_x(ui_LabelFilamentSecondStep, 34);
    lv_obj_set_y(ui_LabelFilamentSecondStep, 88);
    lv_label_set_text(ui_LabelFilamentSecondStep, "");
    lv_obj_set_style_text_color(ui_LabelFilamentSecondStep, lv_color_hex(0x9A9DA0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFilamentSecondStep, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFilamentSecondStep, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelSecondStepScreenFila = lv_obj_create(ui_PanelFilamentProccess);
    lv_obj_set_width(ui_PanelSecondStepScreenFila, 3);
    lv_obj_set_height(ui_PanelSecondStepScreenFila, 59);
    lv_obj_set_x(ui_PanelSecondStepScreenFila, 10);
    lv_obj_set_y(ui_PanelSecondStepScreenFila, 118);
    lv_obj_clear_flag(ui_PanelSecondStepScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelSecondStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelSecondStepScreenFila, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelSecondStepScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_PanelSecondStepScreenFila, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_PanelSecondStepScreenFila, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelSecondStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelSecondStepScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BtnThirdStepScreenFila = lv_btn_create(ui_PanelFilamentProccess);
    lv_obj_set_width(ui_BtnThirdStepScreenFila, 30);
    lv_obj_set_height(ui_BtnThirdStepScreenFila, 30);
    lv_obj_set_x(ui_BtnThirdStepScreenFila, -4);
    lv_obj_set_y(ui_BtnThirdStepScreenFila, 177);
    lv_obj_add_flag(ui_BtnThirdStepScreenFila, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BtnThirdStepScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BtnThirdStepScreenFila, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BtnThirdStepScreenFila, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BtnThirdStepScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_BtnThirdStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_BtnThirdStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelThirdStepScreenFila = lv_label_create(ui_BtnThirdStepScreenFila);
    lv_obj_set_width(ui_LabelThirdStepScreenFila, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelThirdStepScreenFila, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LabelThirdStepScreenFila, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelThirdStepScreenFila, "3");
    lv_obj_set_style_text_font(ui_LabelThirdStepScreenFila, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFilamentThirdStep = lv_label_create(ui_PanelFilamentProccess);
    lv_obj_set_width(ui_LabelFilamentThirdStep, 200);
    lv_obj_set_height(ui_LabelFilamentThirdStep, 30);
    lv_obj_set_x(ui_LabelFilamentThirdStep, 34);
    lv_obj_set_y(ui_LabelFilamentThirdStep, 177);
    lv_label_set_text(ui_LabelFilamentThirdStep, FilamentEnd[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelFilamentThirdStep, lv_color_hex(0x9A9DA0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFilamentThirdStep, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFilamentThirdStep, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelThirdStepScreenFila = lv_obj_create(ui_PanelFilamentProccess);
    lv_obj_set_width(ui_PanelThirdStepScreenFila, 3);
    lv_obj_set_height(ui_PanelThirdStepScreenFila, 59);
    lv_obj_set_x(ui_PanelThirdStepScreenFila, 10);
    lv_obj_set_y(ui_PanelThirdStepScreenFila, 207);
    lv_obj_clear_flag(ui_PanelThirdStepScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelThirdStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelThirdStepScreenFila, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelThirdStepScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_PanelThirdStepScreenFila, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_PanelThirdStepScreenFila, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelThirdStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelThirdStepScreenFila, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BtnFourthStepScreenFila = lv_btn_create(ui_PanelFilamentProccess);
    lv_obj_set_width(ui_BtnFourthStepScreenFila, 30);
    lv_obj_set_height(ui_BtnFourthStepScreenFila, 30);
    lv_obj_set_x(ui_BtnFourthStepScreenFila, -4);
    lv_obj_set_y(ui_BtnFourthStepScreenFila, 266);
    lv_obj_add_flag(ui_BtnFourthStepScreenFila, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BtnFourthStepScreenFila, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BtnFourthStepScreenFila, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BtnFourthStepScreenFila, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BtnFourthStepScreenFila, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_BtnFourthStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_BtnFourthStepScreenFila, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFourthStepScreenFila = lv_label_create(ui_BtnFourthStepScreenFila);
    lv_obj_set_width(ui_LabelFourthStepScreenFila, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelFourthStepScreenFila, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelFourthStepScreenFila, -2);
    lv_obj_set_y(ui_LabelFourthStepScreenFila, -1);
    lv_obj_set_align(ui_LabelFourthStepScreenFila, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelFourthStepScreenFila, "4");
    lv_obj_set_style_text_font(ui_LabelFourthStepScreenFila, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFilamentFourthStep = lv_label_create(ui_PanelFilamentProccess);
    lv_obj_set_width(ui_LabelFilamentFourthStep, 230);
    lv_obj_set_height(ui_LabelFilamentFourthStep, 60);
    lv_obj_set_x(ui_LabelFilamentFourthStep, 34);
    lv_obj_set_y(ui_LabelFilamentFourthStep, 266);
    lv_obj_set_style_text_letter_space(ui_LabelFilamentFourthStep, -2, LV_PART_MAIN | LV_STATE_DEFAULT);  //设置行间距
    lv_label_set_text(ui_LabelFilamentFourthStep, "");
    lv_obj_set_style_text_color(ui_LabelFilamentFourthStep, lv_color_hex(0x9A9DA0), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFilamentFourthStep, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFilamentFourthStep, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    /******************打印速度页面****************/
    speed_mode_init();

    lv_obj_add_event_cb(ui_ButtonInFilaScreenFilament, ui_event_BtnFilamentOptions, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonOutFilaScreenFilament, ui_event_BtnFilamentOptions, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonAddTemperScreenFilament, ui_event_BtnTargetTemperChange, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSubTemperScreenFilament, ui_event_BtnTargetTemperChange, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelTemperValueScreenFilament, ui_event_PanelTargetTemper, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelSpeed, ui_event_SpeedAdjustScreenMove, LV_EVENT_SHORT_CLICKED, NULL);
    /*****************init action*********************/
    show_temper_panel(SHOW_TEMPER_EDIT_PANEL);
    show_proccess_panel(false);
}

void LoadAxisMoveScreen(void)
{
    CrLogI("load the axismove page");
    lv_disp_load_scr(ui_ScreenAxisMovePage);
    /******************************************************************/
    send_get_fans_status_cmd();
    // send_get_light_status_cmd();
    send_get_axis_home_status_cmd();
    send_get_print_status();
    get_printer_data(CONTROL_HOT_BED_TEMP, 2, "\0");    //获取温度
    get_printer_data(CONTROL_XYZ_AXIS_RANGE, 2, "1");    //获取xyz轴的移动范围
    //show_dis_unit();
    axis_move_set_bed_temper(bed_temper_move, bed_target_temper_move);
    axis_move_set_hotend_temper(hotend_temper_move, hotend_target_temper_move);
}

void MovePageHotendBtnClicked(lv_event_t * e)
{
	// Your code here
    // "#0000ff Re-color# #ff00ff words# #ff0000 of a# label "
    //                           "and  wrap long text automatically."
    char buff[300] = {0};
    sprintf(buff, "%s #42BDD8 %d-%d#", HotendInputRangle[get_cur_language_index()], HOTEND_MIN_EDIT_TEMPER, HOTEND_MAX_EDIT_TEMPER);
    numberskeyboardinput(buff, HOTEND_MAX_EDIT_TEMPER, HOTEND_MIN_EDIT_TEMPER,
                    move_hotend_edit_target_temper_callback, key_reminder_callback, 320, 0);
    
}

void MovePageBedBtnClicked(lv_event_t * e)
{
	// Your code here
    char buff[300] = {0};
    if(UIType == CR_K1_Max)
    {
        int maxtemp = (IsK1MaxSe == true) ? K1_MAX_SE_BED_MAX_EDIT_TEMPER : K1_MAX_BED_MAX_EDIT_TEMPER;
        sprintf(buff, "%s #42BDD8 %d-%d#", BedInputRangle[get_cur_language_index()], BED_MIN_EDIT_TEMPER, maxtemp);
        numberskeyboardinput(buff, maxtemp, BED_MIN_EDIT_TEMPER,
            move_bed_edit_target_temper_callback, key_reminder_callback, 320, 0);        
    }
    else
    {
        sprintf(buff, "%s #42BDD8 %d-%d#", BedInputRangle[get_cur_language_index()], BED_MIN_EDIT_TEMPER, BED_MAX_EDIT_TEMPER);
        numberskeyboardinput(buff, BED_MAX_EDIT_TEMPER, BED_MIN_EDIT_TEMPER,
            move_bed_edit_target_temper_callback, key_reminder_callback, 320, 0);
    }
}

void MovePageStepperDisableBtnClicked(lv_event_t * e)
{
	// Your code here
    send_set_disable_stepper_cmd();
}

void MovePageModeFanBtnClicked(lv_event_t * e)
{
	// Your code here
    uint8_t percent = 100;
    if ( model_fan_opened )
        percent = 0;

    send_set_model_fan_opt_cmd(percent);
}

void MovePageSmallDisBtnClicked(lv_event_t * e)
{
	// Your code here
    dis_unit = 0;
    show_dis_unit();
}

void MovePageMidDisBtnClicked(lv_event_t * e)
{
	// Your code here
    dis_unit = 1;
    show_dis_unit();
}

void MovePageLargeDisBtnClicked(lv_event_t * e)
{
	// Your code here
    dis_unit = 2;
    show_dis_unit();
}

void JudgeAxisRangeOut(axis_type_t Axis, float distance, int direction)//direction （1:+ 0：-）
{
    float dis = distance;
    float position = 0.0f;
    float limitmin = 0.0f;
    float limitmax = 0.0f;
    int speed = 0;

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
    if(position + dis <= limitmax && position + dis >= limitmin)
    {
        send_set_axis_move_opt_cmd(Axis, direction, distance, speed);
    }
    else if(position + dis < limitmin)
    {
        if(position - limitmin <= 0.1f)//相差0.1以内认为已经到了零点
        {
            create_msgbox(MoveAxisTips[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
            return;
        }
        distance = (int)((position -  limitmin) * 100) / 100.0f;//精度只到小数点后两位

        send_set_axis_move_opt_cmd(Axis, direction, distance, speed);
    }
    else if(position + dis > limitmax)
    {
        if(limitmax - position <= 0.1f)//相差0.1以内认为已经到了零点
        {
            create_msgbox(MoveAxisTips2[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
            return;
        }
        distance = (int)((limitmax - position) * 100) / 100.0f;//精度只到小数点后两位

        send_set_axis_move_opt_cmd(Axis, direction, distance, speed);
    }
}

void MovePageSubXBtnClicked(lv_event_t * e)
{
	// Your code here
    if ( !(home_flag & 0x01)  )
    {
        char buff[80] = {0};
        sprintf(buff, "X%s", NotHomedMsg[get_cur_language_index()]);
        create_custom_reminderbox(buff, false);
        set_custom_reminderbox_clickable(false);
        set_custom_reminderbox_display_timeout(10, NULL);
        return ;
    }
    float dis = get_dis_unit_value();
    JudgeAxisRangeOut(AXIS_X, dis, 0);
}

void MovePageAddXBtnClicked(lv_event_t * e)
{
	// Your code here
    if ( !(home_flag & 0x01)  )
    {
        char buff[80] = {0};
        sprintf(buff, "X%s", NotHomedMsg[get_cur_language_index()]);
        create_custom_reminderbox(buff, false);
        set_custom_reminderbox_clickable(false);
        set_custom_reminderbox_display_timeout(10, NULL);
        return ;
    }

    float dis = get_dis_unit_value();
    JudgeAxisRangeOut(AXIS_X, dis, 1);
}

void MovePageAddYBtnClicked(lv_event_t * e)
{
	// Your code here
    if ( !(home_flag & 0x01)  )
    {
        char buff[80] = {0};
        sprintf(buff, "Y%s", NotHomedMsg[get_cur_language_index()]);
        create_custom_reminderbox(buff, false);
        set_custom_reminderbox_clickable(false);
        set_custom_reminderbox_display_timeout(10, NULL);
        return ;
    }
    float dis = get_dis_unit_value();
    JudgeAxisRangeOut(AXIS_Y, dis, 1);
}

void MovePageSubYBtnClicked(lv_event_t * e)
{
	// Your code here
    if ( !(home_flag & 0x01)  )
    {
        char buff[80] = {0};
        sprintf(buff, "Y%s", NotHomedMsg[get_cur_language_index()]);
        create_custom_reminderbox(buff, false);
        set_custom_reminderbox_clickable(false);
        set_custom_reminderbox_display_timeout(10, NULL);
        return ;
    }

    float dis = get_dis_unit_value();
    JudgeAxisRangeOut(AXIS_Y, dis, 0);
}

void MovePageHomeXYBtnClicked(lv_event_t * e)
{
    home_action |= 0x03;
    send_set_axis_home_cmd(true, true, false);
}

void MovePageUpperZBtnClicked(lv_event_t * e)
{
    //Z轴上升
	// Your code here
    if ( !(home_flag & 0x01)  )
    {
        char buff[80] = {0};
        sprintf(buff, "Z%s", NotHomedMsg[get_cur_language_index()]);
        create_custom_reminderbox(buff, false);
        set_custom_reminderbox_clickable(false);
        set_custom_reminderbox_display_timeout(10, NULL);
        return ;
    }

    float dis = get_dis_unit_value();
    if ( z_move_forward_dir == 1 )  //0:正向，1：反向. 
        dis = 0 - dis;

    // Z轴的方向位不起作用，移动方向有距离值的正反来确定。
    float zposition = atof(cur_zposition);
    CrLogI("axis_z position: %.3f", zposition);
    if(zposition + dis >= Z_AXIS_MIN_DIS)
    {
        send_set_axis_move_opt_cmd(AXIS_Z, true, dis, axis_move_feedrate_z);
    }
    else if(zposition + dis < Z_AXIS_MIN_DIS)
    {
        if(zposition - Z_AXIS_MIN_DIS < 0.001f)//相差0.001以内认为已经到了零点
        {
            create_msgbox(MoveAxisTips[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
        }
        dis = (int)((zposition - Z_AXIS_MIN_DIS) * 100) / 100.0f;//精度只到小数点后两位
        if ( z_move_forward_dir == 1 )  //0:正向，1：反向. 
            dis = 0 - dis;
        send_set_axis_move_opt_cmd(AXIS_Z, true, dis, axis_move_feedrate_z);
    }
}

void MovePageHomeZBtnClicked(lv_event_t * e)
{
	// Your code here
    // if ( !(home_flag & 0x01) || !(home_flag & 0x02) )
    // {
    //     create_custom_reminderbox("请先归位XY轴!", false);
    //     set_custom_reminderbox_clickable(false);
    //     set_custom_reminderbox_display_timeout(3, NULL);
    //     return ;
    // }

    home_action |= 0x04;
    send_set_axis_home_cmd(false, false, true);
}

void MovePageDownZBtnClicked(lv_event_t * e)
{
    //Z轴下降
	// Your code here
    if ( !(home_flag & 0x01)  )
    {
        char buff[80] = {0};
        sprintf(buff, "Z%s", NotHomedMsg[get_cur_language_index()]);
        create_custom_reminderbox(buff, false);
        set_custom_reminderbox_clickable(false);
        set_custom_reminderbox_display_timeout(10, NULL);
        return ;
    }

    float dis = get_dis_unit_value();
    dis = 0 - dis;
    if ( z_move_forward_dir == 1 )   ///0:正向，1：反向. 
        dis = 0 - dis;

    // Z轴的方向位不起作用，移动方向有距离值的正反来确定。
    JudgeAxisRangeOut(AXIS_Z, dis, z_move_forward_dir);
}



void MovePageEnterFilaBtnClicked(lv_event_t * e)
{
    if ( hotend_temper_move < COLD_EXTRUSION_TEMPER )  //2 is large dis unit, out fila can not larger than 10mm
    {
        //char buff[60] = "喷头温度低于最小挤出温度!";
        create_custom_reminderbox(ColdExtrudeMsg[get_cur_language_index()], false);
        set_custom_reminderbox_display_timeout(10, NULL);
        
        return;
    }

	// Your code here
    float dis = get_dis_unit_value();
    send_set_axis_move_opt_cmd(AXIS_E, true, dis, axis_move_feedrate_e);
    
    if ( ui_ImageFilaMoveDir )
        lv_img_set_src(ui_ImageFilaMoveDir, &ui_img_enterfila_png);
}

void move_hotend_edit_target_temper_callback(void *param)
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

void move_bed_edit_target_temper_callback(void *param)
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

void ScreenMovePanelHotHeatingClicked(lv_event_t * e)
{
	// Your code here
    char buff[300] = {0};
    sprintf(buff, "%s #42BDD8 %d-%d#", HotendInputRangle[get_cur_language_index()], HOTEND_MIN_EDIT_TEMPER, HOTEND_MAX_EDIT_TEMPER);
    numberskeyboardinput(buff, HOTEND_MAX_EDIT_TEMPER, HOTEND_MIN_EDIT_TEMPER,
                    move_hotend_edit_target_temper_callback, key_reminder_callback, 240, 0);
}

void ScreenMovePanelBedHeatingClicked(lv_event_t * e)
{
	// Your code here
    char buff[300] = {0};
    if(UIType == CR_K1_Max)
    {
        int maxtemp = (IsK1MaxSe == true) ? K1_MAX_SE_BED_MAX_EDIT_TEMPER : K1_MAX_BED_MAX_EDIT_TEMPER;
        sprintf(buff, "%s #42BDD8 %d-%d#", BedInputRangle[get_cur_language_index()], BED_MIN_EDIT_TEMPER, maxtemp);
        numberskeyboardinput(buff, maxtemp, BED_MIN_EDIT_TEMPER,
            move_bed_edit_target_temper_callback, key_reminder_callback, 240, 0);
    }
    else
    {
        sprintf(buff, "%s #42BDD8 %d-%d#", BedInputRangle[get_cur_language_index()], BED_MIN_EDIT_TEMPER, BED_MAX_EDIT_TEMPER);
        numberskeyboardinput(buff, BED_MAX_EDIT_TEMPER, BED_MIN_EDIT_TEMPER,
            move_bed_edit_target_temper_callback, key_reminder_callback, 240, 0);
    }
}

void show_hotend_heating_status_screen_move(bool show)
{
    if ( show )
    {
        lv_obj_add_flag(ui_PanelHotend, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelHotendHeatingScreenMove, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(ui_PanelHotendHeatingScreenMove, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelHotend, LV_OBJ_FLAG_HIDDEN);
    }
}

void show_bed_heating_status_screen_move(bool show)
{
    if ( show )
    {
        lv_obj_add_flag(ui_PanelBed, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelBedHeatingScreenMove, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_add_flag(ui_PanelBedHeatingScreenMove, LV_OBJ_FLAG_HIDDEN); 
        lv_obj_clear_flag(ui_PanelBed, LV_OBJ_FLAG_HIDDEN);
    }
}

void axis_move_set_hotend_temper(int16_t curTemper, int16_t targetTemper)
{
    char buff[10] = {0};
    sprintf(buff, "%d", curTemper);
    lv_label_set_text(ui_LabelCurTemperScreenMove, buff);
    lv_label_set_text(ui_LabelTemperScreenMove, buff);
    hotend_temper_move = curTemper;

    sprintf(buff, "%d", targetTemper);
    lv_label_set_text(ui_LabelTargetTemperScreenMove, buff);
    hotend_target_temper_move = targetTemper;

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
    lv_label_set_text(ui_LabelBedTemperScreenMove, buff);
    lv_label_set_text(ui_LabelBedCurTemperScreenMove, buff);
    bed_temper_move = curTemper;

    sprintf(buff, "%d", targetTemper);
    lv_label_set_text(ui_LabelBedTargetTemperScreenMove, buff);
    bed_target_temper_move = targetTemper;

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


float get_dis_unit_value(void)
{
    float value = 1.0f;
    switch (dis_unit)
    {
        case 0:
            value = SMALL_DIS_UNIIT_VALUE;
            break;
        case 1:
            value = MID_DIS_UNIIT_VALUE;
            break;
        case 2:
            value = LARGE_DIS_UNIIT_VALUE;
            break;
        
        default:
            break;
    }

    return value;
}

void show_dis_unit(void)
{

    lv_obj_set_style_bg_color(ui_ButtonSmallDis, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonSmallDis, 0xFF, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonSmallDis, lv_color_hex(0x434549),LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ButtonSmallDis, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonSmallDis, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ButtonMidDis, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonMidDis, 0xFF, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonMidDis, lv_color_hex(0x434549),LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ButtonMidDis, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonMidDis, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonLargeDis, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonLargeDis, 0xFF, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonLargeDis, lv_color_hex(0x434549),LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ButtonLargeDis, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonLargeDis, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    struct _lv_obj_t * obj = ui_ButtonSmallDis;
    switch (dis_unit)
    {
    case 0:
        {
            obj = ui_ButtonSmallDis;
        }
        break;
    case 1:
        {
            obj = ui_ButtonMidDis;
        }
        break;
    case 2:
        {
            obj = ui_ButtonLargeDis;
        }
        break;
    default:
        break;
    }

    if (obj)
    {    
        lv_obj_set_style_border_color(obj, lv_color_hex(0x42BDD8),LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(obj, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(obj, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(obj, 0x1A, LV_PART_MAIN | LV_STATE_DEFAULT);
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
    int action = home_action;
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
    if ( axis_home_flag & 0x01 )
    {
        lv_obj_add_flag(ui_ButtonAddXScreenMove, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_add_flag(ui_ButtonSubXScreenMove, LV_OBJ_FLAG_CLICKABLE);
    }
    else
    {
        lv_obj_clear_flag(ui_ButtonAddXScreenMove, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_clear_flag(ui_ButtonSubXScreenMove, LV_OBJ_FLAG_CLICKABLE);
    }

    if ( axis_home_flag & 0x02 )
    {
        lv_obj_add_flag(ui_ButtonAddYScreenMove, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_add_flag(ui_ButtonSubYScreenMove, LV_OBJ_FLAG_CLICKABLE);
    }
    else
    {
        lv_obj_clear_flag(ui_ButtonAddYScreenMove, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_clear_flag(ui_ButtonSubYScreenMove, LV_OBJ_FLAG_CLICKABLE);
    }

    if ( axis_home_flag & 0x04 )
    {
        lv_obj_add_flag(ui_PanelUpperZ, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_add_flag(ui_PanelDownZ, LV_OBJ_FLAG_CLICKABLE);
    }
    else
    {
        lv_obj_clear_flag(ui_PanelUpperZ, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_clear_flag(ui_PanelDownZ, LV_OBJ_FLAG_CLICKABLE);
    }

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
}

void axis_move_set_print_status(int8_t print_status)
{
    // 0: finished, 1:stoped, 2:paused, 3:printing,6:温度升温中  依赖于协议
    if ( (print_status == 2) || (print_status == 3) || (print_status == 6) )  
    {
        //if ( !lv_obj_has_flag(ui_ScreenAxisMovePage, LV_OBJ_FLAG_HIDDEN) )
        // if ( lv_obj_is_visible(ui_ScreenAxisMovePage) )
        //     LoadAdjustmentScreen();

        lv_obj_add_state(ui_ButtonAddXScreenMove, LV_STATE_DISABLED);
        lv_obj_add_state(ui_ButtonSubXScreenMove, LV_STATE_DISABLED);
        lv_obj_add_state(ui_ButtonAddYScreenMove, LV_STATE_DISABLED);
        lv_obj_add_state(ui_ButtonSubYScreenMove, LV_STATE_DISABLED);
        lv_obj_add_state(ui_PanelUpperZ, LV_STATE_DISABLED);
        lv_obj_add_state(ui_PanelDownZ, LV_STATE_DISABLED);
        lv_obj_add_state(ui_ButtonHomeZ, LV_STATE_DISABLED);
/**轴移动页面去掉E轴进退料
        lv_obj_add_state(ui_PanelOutFila, LV_STATE_DISABLED);
        lv_obj_add_state(ui_PanelEnterFila, LV_STATE_DISABLED);
******************/
        lv_obj_add_state(ui_ButtonHomeXYScreenMove, LV_STATE_DISABLED);
        lv_obj_add_state(ui_PanelStepper, LV_STATE_DISABLED);

    }
    else if ( (print_status == 0) || (print_status == 1) )
    {
        lv_obj_clear_state(ui_ButtonAddXScreenMove, LV_STATE_DISABLED);
        lv_obj_clear_state(ui_ButtonSubXScreenMove, LV_STATE_DISABLED);
        lv_obj_clear_state(ui_ButtonAddYScreenMove, LV_STATE_DISABLED);
        lv_obj_clear_state(ui_ButtonSubYScreenMove, LV_STATE_DISABLED);
        lv_obj_clear_state(ui_PanelUpperZ, LV_STATE_DISABLED);
        lv_obj_clear_state(ui_PanelDownZ, LV_STATE_DISABLED);
        lv_obj_clear_state(ui_ButtonHomeZ, LV_STATE_DISABLED);
/**轴移动页面去掉E轴进退料
        lv_obj_clear_state(ui_PanelOutFila, LV_STATE_DISABLED);
        lv_obj_clear_state(ui_PanelEnterFila, LV_STATE_DISABLED);
******************/
        lv_obj_clear_state(ui_ButtonHomeXYScreenMove, LV_STATE_DISABLED);
        lv_obj_clear_state(ui_PanelStepper, LV_STATE_DISABLED);
    }
}

void axis_move_change_language_text(void)
{
    if ( ui_LabelMoveAndTemperTitle )
    {
        lv_coord_t letter_space = 0;
        lv_coord_t width_offset = 0;
        if(get_cur_language_index() == 3 || get_cur_language_index() == 4 || get_cur_language_index() == 5)
        {
            letter_space = -1;
            width_offset = 0;
        }
        lv_obj_set_style_text_letter_space(ui_LabelMoveAndTemperTitle, letter_space, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text(ui_LabelMoveAndTemperTitle, MovePageTitle[get_cur_language_index()]);
        redefine_label_size(ui_LabelMoveAndTemperTitle, lv_font25.font, letter_space, 0, 400, 0);
        
        lv_obj_update_layout(ui_PanelMoveTitle);
        redefine_widgets_size(ui_PanelMoveTitle, ui_LabelMoveAndTemperTitle, width_offset, 0, 210, 46);
    }
    if ( ui_LabelAdjustment )
    {
        lv_label_set_text(ui_LabelAdjustment, Adjustment[get_cur_language_index()]);
        redefine_label_size(ui_LabelAdjustment, lv_font25.font, 0, 0, 150, 0);

        lv_obj_update_layout(ui_PanelAdjustment);
        redefine_widgets_size(ui_PanelAdjustment, ui_LabelAdjustment, 5, 0, 100, 45);
    }
    if ( ui_LabelCool )
    {
        lv_coord_t letter_space = 0;
        lv_coord_t width_offset = 0;
        if(get_cur_language_index() == 5)
        {
            letter_space = -1;
            width_offset = 0;
        }
        lv_obj_set_style_text_letter_space(ui_LabelCool, letter_space, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text(ui_LabelCool, Cooling[get_cur_language_index()]);     //冷却
        redefine_label_size(ui_LabelCool, lv_font25.font, letter_space, 0, 400, 0);
        
        lv_obj_update_layout(ui_PanelCool);
        redefine_widgets_size(ui_PanelCool, ui_LabelCool, width_offset, 0, 120, 45);
    }
    if ( ui_LabelFilament )
    {
        lv_coord_t letter_space = 0;
        lv_coord_t width_offset = 0;
        if(get_cur_language_index() == 5)
        {
            letter_space = -1;
            width_offset = 0;
        }
        lv_obj_set_style_text_letter_space(ui_LabelFilament, letter_space, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text(ui_LabelFilament, Extrude_Retract[get_cur_language_index()]);     //冷却
        redefine_label_size(ui_LabelFilament, lv_font25.font, letter_space, 0, 400, 0);
        
        lv_obj_update_layout(ui_PanelFilament);
        redefine_widgets_size(ui_PanelFilament, ui_LabelFilament, width_offset, 0, 150, 46);
    }
}

void axis_move_set_z_move_forward_dir(uint8_t dir)   
{
    //0:正向，1：反向. 
    z_move_forward_dir = dir;
}

/***********************冷却子页面函数*************************/
void ui_event_SliderFansChange(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if ( event_code == LV_EVENT_RELEASED ) {
        uint8_t percent = lv_slider_get_value(target);
        CrLogI("fans value change:%d", percent);

        if(target == ui_ScreenCoolSliderModelFan)
        {
            send_set_model_fan_opt_cmd(percent);
        }
        else if(target == ui_ScreenCoolSliderAuxiliaryFan)
        {
            send_set_auxiliary_fan_opt_cmd(percent);
        }
        else
        {
            send_set_chassis_fan_opt_cmd(percent);
        }
    }
}

void cool_set_model_fan_duty_percent(uint8_t percent)
{
    if ( percent > 100 )
        percent = 100;

    char buff[5] = {0};
    sprintf(buff, "%d%%", percent); 
    lv_label_set_text(ui_ScreenCoolLabelModelPercent, buff);
    lv_slider_set_value(ui_ScreenCoolSliderModelFan, percent, LV_ANIM_OFF);
}

void cool_set_cool_fan_duty_percent(uint8_t percent)
{
    if ( percent > 100 )
        percent = 100;
    CrLogI("COOL FAN value get :%d",percent);
    // percent = percent * 65 / 255 + 0; //风扇生效范围在190-255区间内
    // CrLogI("COOL FAN value get after:%d",percent);
    char buff[5] = {0};
    sprintf(buff, "%d%%", percent); 
    lv_label_set_text(ui_ScreenCoolLabelAuxiliaryPercent, buff);
    lv_slider_set_value(ui_ScreenCoolSliderAuxiliaryFan, percent, LV_ANIM_OFF);
}

void cool_set_Chassis_fan_duty_percent(uint8_t percent)
{
    if ( percent > 100 )
        percent = 100;

    char buff[5] = {0};
    sprintf(buff, "%d%%", percent); 
    lv_label_set_text(ui_ScreenCoolLabelChassisPercent, buff);
    lv_slider_set_value(ui_ScreenCoolSliderChassisFan, percent, LV_ANIM_OFF);
}

void cool_change_language_text()
{
    if ( ui_ScreenCoolLabelModelFan )
        lv_label_set_text(ui_ScreenCoolLabelModelFan, ModelFan[get_cur_language_index()]);
    if ( ui_ScreenCoolLabelAuxiliaryFan )
        lv_label_set_text(ui_ScreenCoolLabelAuxiliaryFan, CoolFan[get_cur_language_index()]);
    if ( ui_ScreenCoolLabelChassisFan )
        lv_label_set_text(ui_ScreenCoolLabelChassisFan, BackFan[get_cur_language_index()]);
}







//进退料页面
/**********************事件函数实现**********************/
void ui_event_BtnFilamentOptions(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        show_proccess_panel(true);
        if ( edit_target_temper < FILAMENT_COOL_EXTRUDE_TEMPER )
            edit_target_temper = FILAMENT_COOL_EXTRUDE_TEMPER;
        filament_action_step_order = 0;
        targettemp = atoi(hotend_max_temp);
        char buff[30] = {0};

        if(target == ui_ButtonInFilaScreenFilament) //进料
        {
            filament_action = FILA_ACTION_IN;
            CrLogI("extrude filament,the last targettemp is:%d",targettemp);
            snprintf(buff, 30, "1%d", edit_target_temper);
        }
        else                                        //退料
        {
            filament_action = FILA_ACTION_OUT;
            CrLogI("retract filament,the last targettemp is:%d",targettemp);
            snprintf(buff, 30, "2%d", edit_target_temper);  
        }
        set_printer_data(0x08, strlen(buff), buff);
        filament_actions_status(true);

        timer_proccess = lv_timer_create(time_too_close, 1000 * 3, NULL);
        lv_timer_set_repeat_count(timer_proccess, 1);
    }
}

void ui_event_BtnTargetTemperChange(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        CrLogI("change the FilamentTarget temp");
        if(target == ui_ButtonAddTemperScreenFilament)//Add
        {
            if ( edit_target_temper >= HOTEND_MAX_EDIT_TEMPER )
            {
                create_msgbox(FilamentTempTips1[get_cur_language_index()], NULL, 2000, lv_scr_act());
                return ;
            }

            edit_target_temper += FILAMENT_ACTION_INCREASE_TEMPER;
            char buf[10] = {0};
            sprintf(buf, "%d", edit_target_temper);
            lv_label_set_text(ui_LabelTemperScreenFilament, buf);
        }
        else
        {
            if ( edit_target_temper <= FILAMENT_COOL_EXTRUDE_TEMPER )
            {
                create_msgbox(FilamentTempTips2[get_cur_language_index()], NULL, 2000, lv_scr_act());

                return ;
            }

            edit_target_temper -= FILAMENT_ACTION_INCREASE_TEMPER;
            char buf[10] = {0};
            sprintf(buf, "%d", edit_target_temper);
            lv_label_set_text(ui_LabelTemperScreenFilament, buf);
        }
    }
}

void ui_event_PanelTargetTemper(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        char buff[300] = {0};
        sprintf(buff, "%s #42BDD8 %d-%d#", HotendInputRangle[get_cur_language_index()], FILAMENT_COOL_EXTRUDE_TEMPER, HOTEND_MAX_EDIT_TEMPER);
        numberskeyboardinput(buff, HOTEND_MAX_EDIT_TEMPER, FILAMENT_COOL_EXTRUDE_TEMPER,
                        fila_hotend_edit_target_temper_callback, key_reminder_callback, 320, 0);
    }
}

/**********************事件响应函数实现**********************/
void time_too_close(struct _lv_timer_t *timer)
{
    CrLogI("out of time,stop the filament option.");
    filament_actions_status(false);
}

void fila_hotend_edit_target_temper_callback(void *param)
{
    char *number_buff = (char*)param;
    if ( number_buff )
    {
        char *ch = strchr(number_buff, '.');
        if ( ch )
            *ch = '\0';

        edit_target_temper = atoi(number_buff);
        lv_label_set_text(ui_LabelTemperScreenFilament, number_buff);
    }
}

void show_temper_panel(enum SHOW_TEMPER_PANEL panel)
{
    lv_obj_add_flag(ui_PanelhotendHeatScreenFilament, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_PanelhotendNormalScreenFila, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_PanelTempScreenFilament, LV_OBJ_FLAG_HIDDEN);
    
    switch (panel)
    {
    case SHOW_NORMAL_PANEL:
        {
            lv_obj_clear_flag(ui_PanelhotendNormalScreenFila, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    case SHOW_HEATING_PANEL:
        {
            lv_obj_clear_flag(ui_PanelhotendHeatScreenFilament, LV_OBJ_FLAG_HIDDEN);
        }
        break;  
    default:
        {
            lv_obj_clear_flag(ui_PanelTempScreenFilament, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    }
}

void show_proccess_panel(bool show_proccess)
{
    lv_obj_add_flag(ui_LabelTitleTips, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_LabelTipsContentScreenFila, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_LabelTitleFilament, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_PanelFilamentProccess, LV_OBJ_FLAG_HIDDEN);

    if ( show_proccess )
    {
        lv_obj_clear_flag(ui_LabelTitleFilament, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_PanelFilamentProccess, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        lv_obj_clear_flag(ui_LabelTitleTips, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_LabelTipsContentScreenFila, LV_OBJ_FLAG_HIDDEN);
    }
}

void show_in_filament_proccess(enum IN_FILA_PROCCESS in_step)
{
    show_proccess_panel(true);
    show_filament_proccess_steps(true);
    switch (in_step)
    {
        case IN_FILAMENT_FIRST_STEP:
        {
            show_step_btn_state(ui_BtnFirstStepScreenFila, true);
            show_step_btn_state(ui_BtnSecondStepScreenFila, false);
            show_step_btn_state(ui_BtnThirdStepScreenFila, false);
            show_step_label_state(ui_LabelFilamentFirstStep, true);
            show_step_label_state(ui_LabelFilamentSecondStep, false);
            show_step_label_state(ui_LabelFilamentThirdStep, false);
            show_step_dir_panel_state(ui_PanelFirstStepScreenFila, STEP_PROCCESSING);
            show_step_dir_panel_state(ui_PanelSecondStepScreenFila, STEP_NOT_START);
            show_temper_panel(SHOW_HEATING_PANEL);
            filament_actions_status(true);
        }
        break;
        case IN_FILAMENT_SECOND_STEP:
        {
            show_step_btn_state(ui_BtnFirstStepScreenFila, true);
            show_step_btn_state(ui_BtnSecondStepScreenFila, true);
            show_step_btn_state(ui_BtnThirdStepScreenFila, false);
            show_step_label_state(ui_LabelFilamentFirstStep, true);
            show_step_label_state(ui_LabelFilamentSecondStep, true);
            show_step_label_state(ui_LabelFilamentThirdStep, false);
            show_step_dir_panel_state(ui_PanelFirstStepScreenFila, STEP_FINISHED);
            show_step_dir_panel_state(ui_PanelSecondStepScreenFila, STEP_PROCCESSING);
            show_temper_panel(SHOW_NORMAL_PANEL);
            filament_actions_status(true);
        }
        break;
        case IN_FILAMENT_THIRD_STEP:
        {
            show_step_btn_state(ui_BtnFirstStepScreenFila, true);
            show_step_btn_state(ui_BtnSecondStepScreenFila, true);
            show_step_btn_state(ui_BtnThirdStepScreenFila, true);
            show_step_label_state(ui_LabelFilamentFirstStep, true);
            show_step_label_state(ui_LabelFilamentSecondStep, true);
            show_step_label_state(ui_LabelFilamentThirdStep, true);
            show_step_dir_panel_state(ui_PanelFirstStepScreenFila, STEP_FINISHED);
            show_step_dir_panel_state(ui_PanelSecondStepScreenFila, STEP_FINISHED);
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
    show_proccess_panel(true);
    show_filament_proccess_steps(false);

    switch (out_step)
    {
    case OUT_FILAMENT_FIRST_STEP:
        {
            show_step_btn_state(ui_BtnFirstStepScreenFila, true);
            show_step_btn_state(ui_BtnSecondStepScreenFila, false);
            show_step_btn_state(ui_BtnThirdStepScreenFila, false);
            show_step_btn_state(ui_BtnFourthStepScreenFila, false);
            show_step_label_state(ui_LabelFilamentFirstStep, true);
            show_step_label_state(ui_LabelFilamentSecondStep, false);
            show_step_label_state(ui_LabelFilamentThirdStep, false);
            show_step_label_state(ui_LabelFilamentFourthStep, false);
            show_step_dir_panel_state(ui_PanelFirstStepScreenFila, STEP_PROCCESSING);
            show_step_dir_panel_state(ui_PanelSecondStepScreenFila, STEP_NOT_START);
            show_step_dir_panel_state(ui_PanelThirdStepScreenFila, STEP_NOT_START);
            show_temper_panel(SHOW_HEATING_PANEL);
            filament_actions_status(true);
        }
        break;
    case OUT_FILAMENT_SECOND_STEP:
        {
            show_step_btn_state(ui_BtnFirstStepScreenFila, true);
            show_step_btn_state(ui_BtnSecondStepScreenFila, true);
            show_step_btn_state(ui_BtnThirdStepScreenFila, false);
            show_step_btn_state(ui_BtnFourthStepScreenFila, false);
            show_step_label_state(ui_LabelFilamentFirstStep, true);
            show_step_label_state(ui_LabelFilamentSecondStep, true);
            show_step_label_state(ui_LabelFilamentThirdStep, false);
            show_step_label_state(ui_LabelFilamentFourthStep, false);
            show_step_dir_panel_state(ui_PanelFirstStepScreenFila, STEP_FINISHED);
            show_step_dir_panel_state(ui_PanelSecondStepScreenFila, STEP_PROCCESSING);
            show_step_dir_panel_state(ui_PanelThirdStepScreenFila, STEP_NOT_START);
            show_temper_panel(SHOW_NORMAL_PANEL);
            filament_actions_status(true);
        }
        break;
    case OUT_FILAMENT_THIRD_STEP:
        {
            show_step_btn_state(ui_BtnFirstStepScreenFila, true);
            show_step_btn_state(ui_BtnSecondStepScreenFila, true);
            show_step_btn_state(ui_BtnThirdStepScreenFila, true);
            show_step_btn_state(ui_BtnFourthStepScreenFila, false);
            show_step_label_state(ui_LabelFilamentFirstStep, true);
            show_step_label_state(ui_LabelFilamentSecondStep, true);
            show_step_label_state(ui_LabelFilamentThirdStep, true);
            show_step_label_state(ui_LabelFilamentFourthStep, false);
            show_step_dir_panel_state(ui_PanelFirstStepScreenFila, STEP_FINISHED);
            show_step_dir_panel_state(ui_PanelSecondStepScreenFila, STEP_FINISHED);
            show_step_dir_panel_state(ui_PanelThirdStepScreenFila, STEP_PROCCESSING);
            show_temper_panel(SHOW_NORMAL_PANEL);
            filament_actions_status(true);
        }
        break;
    case OUT_FILAMENT_FOURTH_STEP:
        {
            show_step_btn_state(ui_BtnFirstStepScreenFila, true);
            show_step_btn_state(ui_BtnSecondStepScreenFila, true);
            show_step_btn_state(ui_BtnThirdStepScreenFila, true);
            show_step_btn_state(ui_BtnFourthStepScreenFila, true);
            show_step_label_state(ui_LabelFilamentFirstStep, true);
            show_step_label_state(ui_LabelFilamentSecondStep, true);
            show_step_label_state(ui_LabelFilamentThirdStep, true);
            show_step_label_state(ui_LabelFilamentFourthStep, true);
            show_step_dir_panel_state(ui_PanelFirstStepScreenFila, STEP_FINISHED);
            show_step_dir_panel_state(ui_PanelSecondStepScreenFila, STEP_FINISHED);
            show_step_dir_panel_state(ui_PanelThirdStepScreenFila, STEP_FINISHED);
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

void show_step_btn_state(lv_obj_t *step_btn, bool is_start)
{
    if ( step_btn )
    {
        if ( is_start )
            lv_obj_set_style_bg_color(step_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
        else
            lv_obj_set_style_bg_color(step_btn, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}

void show_step_label_state(lv_obj_t *step_label, bool is_start)
{
    if ( step_label )
    {
        if ( is_start )
            lv_obj_set_style_text_color(step_label, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        else
            lv_obj_set_style_text_color(step_label, lv_color_hex(0x9A9DA0), LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}

void show_step_dir_panel_state(lv_obj_t *step_dir, enum STEP_DIR_STATE state)
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

void show_filament_proccess_steps(bool in_fila)
{
    if ( in_fila )
    {
        lv_obj_add_flag(ui_BtnFourthStepScreenFila, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_LabelFilamentFourthStep, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_PanelThirdStepScreenFila, LV_OBJ_FLAG_HIDDEN);
        lv_label_set_text(ui_LabelFilamentFirstStep, HotendHeating[get_cur_language_index()]);
        lv_label_set_text(ui_LabelTitleFilament, FilamentIn[get_cur_language_index()]);
        lv_label_set_text(ui_LabelFilamentSecondStep, FilamentIning[get_cur_language_index()]);
        lv_label_set_text(ui_LabelFilamentThirdStep, FilamentEnd[get_cur_language_index()]);
    }
    else
    {
        lv_obj_clear_flag(ui_BtnFourthStepScreenFila, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_LabelFilamentFourthStep, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_PanelThirdStepScreenFila, LV_OBJ_FLAG_HIDDEN);
        lv_label_set_text(ui_LabelFilamentFirstStep, HotendHeating[get_cur_language_index()]);
        lv_label_set_text(ui_LabelTitleFilament, FilamentOut[get_cur_language_index()]);
        lv_label_set_text(ui_LabelFilamentSecondStep, FilamentOutPrep[get_cur_language_index()]);
        lv_label_set_text(ui_LabelFilamentThirdStep, FilamentOuting[get_cur_language_index()]);
        lv_label_set_text(ui_LabelFilamentFourthStep, FilamentOutEnd[get_cur_language_index()]);
    }
}

void filament_actions_status(bool disable)
{
    CrLogI("refresh the filament state:%d.",disable);
    if ( disable )
    {
        lv_obj_add_state(ui_ButtonInFilaScreenFilament, LV_STATE_DISABLED);       /// States
        lv_obj_add_state(ui_ButtonOutFilaScreenFilament, LV_STATE_DISABLED);       /// States  
        lv_obj_add_state(ui_LabelInFilaScreenFilament, LV_STATE_DISABLED);       /// States
        lv_obj_add_state(ui_LabelOutFilaScreenFilament, LV_STATE_DISABLED);       /// States  
          
    }
    else
    {
        lv_obj_clear_state(ui_ButtonInFilaScreenFilament, LV_STATE_DISABLED);       /// States
        lv_obj_clear_state(ui_ButtonOutFilaScreenFilament, LV_STATE_DISABLED);       /// States
        lv_obj_clear_state(ui_LabelInFilaScreenFilament, LV_STATE_DISABLED);       /// States
        lv_obj_clear_state(ui_LabelOutFilaScreenFilament, LV_STATE_DISABLED);       /// States
    }
    
}

//进退料的动作过程，只有开始和结束，不包含加热温度
void filament_set_filament_action_state(enum FILAMENT_ACTION_STATE state)
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

void filament_set_print_status(int8_t print_status)  // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
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

void set_hotend_temper_filament(char * curtemp, char * tartemp)
{
    char buff[30] = {0};
    snprintf(buff, 30, "%s°C", curtemp);
    if(ui_LabelRealTemper && curtemp[0] != '\0')
    {
        char buff[30] = {0};
        snprintf(buff, 30, "%s°C", curtemp);
        lv_label_set_text(ui_LabelRealTemper, buff);
    }
    if(ui_LabelTargetTemper && tartemp[0] != '\0')
    {
        char buff[30] = {0};
        snprintf(buff, 30, "%s°C", tartemp);
        lv_label_set_text(ui_LabelTargetTemper, buff);
        lv_label_set_text(ui_LabelNormalRealTemper, buff);
    }
}

void refresh_filament_process(int flag, int process)
{
    if(flag == 1)
    {
        switch (process)
        {
            case 2: lv_timer_set_repeat_count(timer_proccess, 0);
                    show_in_filament_proccess(IN_FILAMENT_FIRST_STEP);break;
            case 4:show_in_filament_proccess(IN_FILAMENT_SECOND_STEP);break;
            case 100:show_in_filament_proccess(IN_FILAMENT_THIRD_STEP);break;
            default:
                break;
        }
    }
    if(flag == 2)
    {
        switch (process)
        {
            case 2:lv_timer_set_repeat_count(timer_proccess, 0);
                   show_out_filament_proccess(OUT_FILAMENT_FIRST_STEP);break;
            case 4:show_out_filament_proccess(OUT_FILAMENT_SECOND_STEP);break;
            case 5:show_out_filament_proccess(OUT_FILAMENT_THIRD_STEP);break;
            case 100:show_out_filament_proccess(OUT_FILAMENT_FOURTH_STEP);break;
            default:
                break;
        }
    }
}

void filament_infor_change_language_text()
{
    if ( ui_LabelTipsContentScreenFila )
        lv_label_set_text(ui_LabelTipsContentScreenFila, HotTips[get_cur_language_index()]);
    if ( ui_LabelTitleTips )
        lv_label_set_text(ui_LabelTitleTips, FilamentTips[get_cur_language_index()]);
    if ( ui_LabelInFilaScreenFilament )
    {
        lv_label_set_text(ui_LabelInFilaScreenFilament, FilamentIn[get_cur_language_index()]);
        redefine_label_size(ui_LabelInFilaScreenFilament, lv_font25.font, 0, 0, 220, 0);
        
        lv_obj_update_layout(ui_ButtonInFilaScreenFilament);
        redefine_widgets_size(ui_ButtonInFilaScreenFilament, ui_LabelInFilaScreenFilament, 10, 0, 116, 60);
    }
    if ( ui_LabelOutFilaScreenFilament )
    {
        lv_label_set_text(ui_LabelOutFilaScreenFilament, FilamentOut[get_cur_language_index()]);
        redefine_label_size(ui_LabelOutFilaScreenFilament, lv_font25.font, 0, 0, 220, 0);
        
        lv_obj_update_layout(ui_ButtonOutFilaScreenFilament);
        redefine_widgets_size(ui_ButtonOutFilaScreenFilament, ui_LabelOutFilaScreenFilament, 10, 0, 116, 60);
    }
    if ( ui_LabelTitleScreenFilament )
        lv_label_set_text(ui_LabelTitleScreenFilament, HotendTemp[get_cur_language_index()]); 
    if ( ui_LabelFilamentFirstStep )
        lv_label_set_text(ui_LabelFilamentFirstStep, HotendHeating[get_cur_language_index()]);

    if(ui_LabelTitleFilament)
    {
        for(int i = 0; i < MAX_LANGUAGE; i++)
        {
            if(strcmp(lv_label_get_text(ui_LabelTitleFilament),FilamentIn[i])== 0)
            {
                lv_label_set_text(ui_LabelTitleFilament, FilamentIn[get_cur_language_index()]);
                break;
            }
            else if(strcmp(lv_label_get_text(ui_LabelTitleFilament),FilamentOut[i])== 0)
            {
                lv_label_set_text(ui_LabelTitleFilament, FilamentOut[get_cur_language_index()]);
                break;
            }
        }
    }

    if(ui_LabelFilamentSecondStep)
    {
        for(int i = 0; i < MAX_LANGUAGE; i++)
        {
            if(strcmp(lv_label_get_text(ui_LabelFilamentSecondStep),FilamentIning[i])== 0)
            {
                lv_label_set_text(ui_LabelFilamentSecondStep, FilamentIning[get_cur_language_index()]);
                break;
            }
            else if(strcmp(lv_label_get_text(ui_LabelFilamentSecondStep),FilamentOutPrep[i])== 0)
            {
                lv_label_set_text(ui_LabelFilamentSecondStep, FilamentOutPrep[get_cur_language_index()]);
                break;
            }
        }
    }

    if(ui_LabelFilamentThirdStep)
    {
        for(int i = 0; i < MAX_LANGUAGE; i++)
        {
            if(strcmp(lv_label_get_text(ui_LabelFilamentThirdStep),FilamentEnd[i])== 0)
            {
                lv_label_set_text(ui_LabelFilamentThirdStep, FilamentEnd[get_cur_language_index()]);
                break;
            }
            else if(strcmp(lv_label_get_text(ui_LabelFilamentThirdStep),FilamentOuting[i])== 0)
            {
                lv_label_set_text(ui_LabelFilamentThirdStep, FilamentOuting[get_cur_language_index()]);
                break;
            }
        }
    }
    
    if(ui_LabelFilamentFourthStep)
        lv_label_set_text(ui_LabelFilamentFourthStep, FilamentOutEnd[get_cur_language_index()]);

    if(ui_LabelSpeed && checkbox_index==4){
        lv_obj_set_style_text_font(ui_LabelSpeed, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text(ui_LabelSpeed, SlicenMode[get_cur_language_index()]);
        lv_obj_align_to(ui_LabelSpeed,ui_ImageSpeed,LV_ALIGN_OUT_RIGHT_MID,11,5);
    }
    if(ui_speedModeAdjLabel){
        lv_checkbox_set_text(ui_SpeedCheckbox[4], SlicenMode[get_cur_language_index()]);
        lv_label_set_text(ui_speedModeAdjLabel, Speed[get_cur_language_index()]);
    }
        
}

int get_fila_action_type(void)
{
    return filament_action;
}

//速度模式
static void speed_mode_checkbox_event_handler(lv_event_t * e)
{
    uint32_t * active_id = lv_event_get_user_data(e);
    lv_obj_t * cont = lv_event_get_current_target(e);
    lv_obj_t * act_cb = lv_event_get_target(e);
    lv_obj_t * old_cb = lv_obj_get_child(cont, *active_id);
    /*Do nothing if the container was clicked*/
    if(act_cb == cont) return;

    lv_obj_clear_state(old_cb, LV_STATE_CHECKED);   
    lv_obj_add_state(act_cb, LV_STATE_CHECKED);     

    *active_id = lv_obj_get_index(act_cb);

    lv_obj_add_flag(lv_obj_get_child(old_cb,0), LV_OBJ_FLAG_HIDDEN);   /*Uncheck the previous radio button*/
    lv_obj_clear_flag(lv_obj_get_child(act_cb,0), LV_OBJ_FLAG_HIDDEN); 
    if(*active_id==0){
        CrLogI("set speed 125 percent");
        lv_obj_set_style_text_font(ui_LabelSpeed, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text_fmt(ui_LabelSpeed, "%d#83868b %%#",125);
        lv_obj_align_to(ui_LabelSpeed,ui_ImageSpeed,LV_ALIGN_OUT_RIGHT_MID,11,18);
        set_printer_data(0x06, 3, "l0");//关闭静音模式
        send_set_print_speed_cmd(125);
    }else if(*active_id==1){
        CrLogI("set speed 100 percent");
        lv_obj_set_style_text_font(ui_LabelSpeed, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text_fmt(ui_LabelSpeed, "%d#83868b %%#",100);
        lv_obj_align_to(ui_LabelSpeed,ui_ImageSpeed,LV_ALIGN_OUT_RIGHT_MID,11,18);
        set_printer_data(0x06, 3, "l0");//关闭静音模式
        send_set_print_speed_cmd(100);
    }else if(*active_id==2){
        CrLogI("set speed 75 percent");
        lv_obj_set_style_text_font(ui_LabelSpeed, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text_fmt(ui_LabelSpeed, "%d#83868b %%#",75);
        lv_obj_align_to(ui_LabelSpeed,ui_ImageSpeed,LV_ALIGN_OUT_RIGHT_MID,11,18);
        set_printer_data(0x06, 3, "l0");//关闭静音模式
        send_set_print_speed_cmd(75);
    }else if(*active_id==3){
        CrLogI("set speed 50 percent");
        lv_obj_set_style_text_font(ui_LabelSpeed, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text_fmt(ui_LabelSpeed, "%d#83868b %%#",50);
        lv_obj_align_to(ui_LabelSpeed,ui_ImageSpeed,LV_ALIGN_OUT_RIGHT_MID,11,18);
        set_printer_data(0x06, 3, "l0");//关闭静音模式
        send_set_print_speed_cmd(50);
    }else if(*active_id==4){
        CrLogI("open the silent mode");
        lv_obj_set_style_text_font(ui_LabelSpeed, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_text(ui_LabelSpeed, SlicenMode[get_cur_language_index()]);
        lv_obj_align_to(ui_LabelSpeed,ui_ImageSpeed,LV_ALIGN_OUT_RIGHT_MID,11,5);
        set_printer_data(0x06, 3, "l1");
    }
    lv_obj_add_flag(ui_SpeedModePanel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    CrLogI("speed Selected radio buttons: %d\n", (int)checkbox_index);
}

// 画直线
/*
x：线的起点
y：线的终点
width：线宽
height：线长
color：线颜色
*/
void ui_DrawStraightLine(lv_obj_t * parent, lv_obj_t * line, uint16_t x, uint16_t y, uint16_t width, uint16_t height, lv_color_t color)
{

    line = lv_obj_create(parent);
    lv_obj_set_width(line, width);
    lv_obj_set_height(line, height);
    lv_obj_set_x(line, x);
    lv_obj_set_y(line, y);
    lv_obj_clear_flag(line, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(line, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(line, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(line, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(line, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(line, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
}

/* 
parent：    父对象
x：         x坐标          
y：         y坐标
txt：       显示文本
*/
lv_obj_t * ui_AddSpeedCheckbox(lv_obj_t * parent, uint16_t x, uint16_t y, const char * txt)
{
    lv_obj_t * Checkbox = lv_checkbox_create(parent);
    lv_obj_set_pos(Checkbox,x,y);
    lv_obj_add_flag(Checkbox, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_style_radius(Checkbox, LV_RADIUS_CIRCLE, LV_PART_INDICATOR);
    lv_checkbox_set_text(Checkbox, txt);
    lv_obj_set_style_text_font(Checkbox, lv_font25.font,LV_PART_MAIN);
    lv_obj_set_style_text_color(Checkbox, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(Checkbox, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(Checkbox,2,LV_PART_INDICATOR);
    lv_obj_set_style_border_color(Checkbox,lv_color_hex(0x9B9FA5),LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(Checkbox,lv_color_hex(0x42BDD8),LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(Checkbox,lv_color_hex(0x42BDD8),LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(Checkbox,LV_OPA_0,LV_PART_INDICATOR );
    lv_obj_set_style_bg_opa(Checkbox,LV_OPA_0,LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_img_src(Checkbox, NULL, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_pad_column(Checkbox,20,LV_PART_MAIN);

    return Checkbox;
}

lv_obj_t * ui_AddSpeedCheckboxBg(lv_obj_t * parent)
{
    lv_obj_t * CheckboxPointBg = lv_obj_create(parent);
    lv_obj_set_style_radius(CheckboxPointBg, LV_RADIUS_CIRCLE, LV_PART_INDICATOR);
    lv_obj_set_style_border_width(CheckboxPointBg,0,LV_PART_MAIN);
    lv_obj_set_size(CheckboxPointBg, 17, 17);
    lv_obj_set_pos(CheckboxPointBg, 8, 8);
    lv_obj_set_style_bg_color(CheckboxPointBg, lv_color_hex(0x42BDD8), LV_PART_MAIN);
    lv_obj_add_flag(CheckboxPointBg,LV_OBJ_FLAG_HIDDEN);

    return CheckboxPointBg;
}


void speed_mode_init(void)
{
    char buf[64]={0};

    ui_SpeedModePanel = lv_obj_create(lv_layer_top());
    lv_obj_set_style_bg_opa(lv_layer_top(), 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_width(ui_SpeedModePanel, 462);
    lv_obj_set_height(ui_SpeedModePanel, 480);
    lv_obj_clear_flag(ui_SpeedModePanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SpeedModePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SpeedModePanel, lv_color_hex(0x050505), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SpeedModePanel, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SpeedModePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_SpeedModePanel,LV_ALIGN_RIGHT_MID,0,0);
    lv_obj_add_flag(ui_SpeedModePanel, LV_OBJ_FLAG_HIDDEN);

    lv_obj_t* ui_SpeedModeBg = lv_obj_create(ui_SpeedModePanel);
    lv_obj_set_width(ui_SpeedModeBg, 370);
    lv_obj_set_height(ui_SpeedModeBg, 450);
    lv_obj_clear_flag(ui_SpeedModeBg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_SpeedModeBg, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SpeedModeBg, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SpeedModeBg, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SpeedModeBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_SpeedModeBg,LV_ALIGN_CENTER,0,0);

    lv_obj_t* ui_SpeedcheckboxBg = lv_obj_create(ui_SpeedModeBg);
    lv_obj_set_size(ui_SpeedcheckboxBg, 253, 400);
    lv_obj_set_pos(ui_SpeedcheckboxBg, 29, 40);
    lv_obj_set_style_radius(ui_SpeedcheckboxBg, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_SpeedcheckboxBg, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_event_cb(ui_SpeedcheckboxBg, speed_mode_checkbox_event_handler, LV_EVENT_CLICKED, &checkbox_index);
    lv_obj_set_style_border_width(ui_SpeedcheckboxBg, 0, LV_PART_MAIN);              // 设置线宽
    lv_obj_set_style_bg_opa(ui_SpeedcheckboxBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT); // 透明度设置

    // speed checkbox 
    for (int i = 0; i < 5; i++)
    {
        memset(buf, 0, sizeof(buf));
        if (i != 4)
            ui_SpeedCheckbox[i] = ui_AddSpeedCheckbox(ui_SpeedcheckboxBg, 0, 75*i, speedGear[i]);
        else 
            ui_SpeedCheckbox[i] = ui_AddSpeedCheckbox(ui_SpeedcheckboxBg, 0, 75*i, SlicenMode[get_cur_language_index()]);

        ui_SpeedCheckboxPoint[i] = ui_AddSpeedCheckboxBg(ui_SpeedCheckbox[i]);
    } 

    for (int i = 0; i < 4; i++)
    {
        // ui_DrawStraightLine(ui_checkboxBg, ui_VerLineX[i], 52, 73 + 75*i, 2, 48, lv_color_hex(0x9B9FA5));
        ui_DrawStraightLine(ui_SpeedcheckboxBg, ui_VerLineX[i], 15, 31 + 75*i, 2, 44, lv_color_hex(0x9B9FA5));
    }
    lv_obj_add_state(ui_SpeedCheckbox[1], LV_STATE_CHECKED);  
    lv_obj_clear_flag(ui_SpeedCheckboxPoint[1], LV_OBJ_FLAG_HIDDEN);
    checkbox_index=1;//初始化选中速度100% 

    ui_speedModeAdjLabel = lv_label_create(ui_SpeedModeBg);
    lv_obj_set_width(ui_speedModeAdjLabel, 190);
    lv_obj_set_height(ui_speedModeAdjLabel, 60);
    lv_label_set_text(ui_speedModeAdjLabel, Speed[get_cur_language_index()]);
    lv_obj_align(ui_speedModeAdjLabel,LV_ALIGN_TOP_MID,0,10);
    lv_obj_set_style_text_color(ui_speedModeAdjLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_speedModeAdjLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_speedModeAdjLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_speedModeAdjLabel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);


}

void show_speed_mode_select(void)
{    
    lv_obj_clear_flag(ui_SpeedModePanel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);  
}
