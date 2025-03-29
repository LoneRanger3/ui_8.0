#include "ui_screen_Adjustment.h"
#include <stdio.h>
#include "ui_screen_HomePrinting.h"
#include "ui_screen_FileManage.h"
#include "../custom/lvgl_cmd.h"
#include "ui_custom_reminderbox.h"
#include "ui_Screen_Settings.h"
#include "lvgl/src/misc/lv_timer.h"
#include "mult_language.h"
#include "ui_screen_AxisMove.h"
#include "ui_screen_cool.h"
#include "ui_Screen_CustomerService.h"
#include "ui_screen_filament_Infor.h"
#include "ui_screen_HomeNormal.h"

#define Z_OFFSET_INCREASE_UNIT (0.05)
#define PRINT_SPEED_INCREASE_UNIT (10)
#define PRINT_FLOW_INCREASE_UNIT (1)

/********Adjustment Page***********/
static lv_obj_t * ui_ScreenAdjustmentPage;
static lv_obj_t * ui_PanelPageScreenAdjustment;

static lv_obj_t * ui_ButtonHomeScreenAdjustment;
static lv_obj_t * ui_ImageAdjustmentPage;
static lv_obj_t * ui_ButtonFileManageScreenAdjustment;
static lv_obj_t * ui_ButtonSettingsScreenAdjustment;
static lv_obj_t * ui_ButtonReserveScreenAdjustment;

static lv_obj_t * ui_PanelAdjustment;

static lv_obj_t * ui_PanelMoveScreenAdjust;
static lv_obj_t * ui_LabelMoveScreenAdjust;
static lv_obj_t * ui_PanelFilamentScreenAdjust;
static lv_obj_t * ui_LabelFilamentScreenAdjust;
static lv_obj_t * ui_PanelCoolScreenAdjust;
static lv_obj_t * ui_LabelCoolScreenAdjust;
static lv_obj_t * ui_PanelAdjustmentScreenAdjust;
static lv_obj_t * ui_LabelAdjustmentScreenAdjust;

static lv_obj_t * ui_ScreenAdjustPanelCenter;
static lv_obj_t * ui_ScreenAdjustmentPanelAdjust;
static lv_obj_t * ui_ScreenAdjustmentLabelOffset;
static lv_obj_t * ui_ScreenAdjustmentBtnSubOffset;
static lv_obj_t * ui_ScreenAdjustmentBtnAddOffset;
static lv_obj_t * ui_ScreenAdjustmentPanelOffset;
static lv_obj_t * ui_ScreenAdjustmentLabelOffsetValue;
static lv_obj_t * ui_ScreenAdjustmentLabelOffsetUnit;
static lv_obj_t * ui_ScreenAdjustmentLabelSpeed;
static lv_obj_t * ui_ScreenAdjustmentBtnSubSpeed;
static lv_obj_t * ui_ScreenAdjustmentPanelSpeed;
static lv_obj_t * ui_ScreenAdjustmentLabelSpeedValue;
static lv_obj_t * ui_ScreenAdjustmentLabelSpeedUnit;
static lv_obj_t * ui_ScreenAdjustmentBtnAddSpeed;
static lv_obj_t * ui_ScreenAdjustmentLabelFlow;
static lv_obj_t * ui_ScreenAdjustmentBtnSubFlow;
static lv_obj_t * ui_ScreenAdjustmentPanelFlow;
static lv_obj_t * ui_ScreenAdjustmentLabelFlowValue;
static lv_obj_t * ui_ScreenAdjustmentLabelFlowUnit;
static lv_obj_t * ui_ScreenAdjustmentBtnAddFlow;
static lv_obj_t * ui_ScreenAdjustmentSilentModePanel;
static lv_obj_t * ui_ScreenAdjustmentSilentModeLabal;
static lv_obj_t * ui_ScreenAdjustmentSilentModeSwitch;
static lv_obj_t * ui_AdjustmentSilentMode;
static lv_obj_t * ui_AdjustmentNormalMode;
#if 0
static lv_obj_t * ui_PanelAdjustmentTitle;
static lv_obj_t * ui_LabelAdjustment;

static lv_obj_t * ui_ScreenAdjustmentPageCenterPanel;
static lv_obj_t * ui_PanelOffsetZ;
static lv_obj_t * ui_LabelOffsetTitle;
static lv_obj_t * ui_PanelOffsetDis;
static lv_obj_t * ui_ButtonSmallOffset;
static lv_obj_t * ui_LabelSmallOffset;
static lv_obj_t * ui_ButtonLargeOffset;
static lv_obj_t * ui_LabelLargeOffset;

static lv_obj_t * ui_PanelOptOffsetAdd;
static lv_obj_t * ui_ImageOptOffsetAdd;
static lv_obj_t * ui_LabelOptOffsetAdd;
static lv_obj_t * ui_LabelOffsetValue;
static lv_obj_t * ui_LabelOffsetValueUnit;
static lv_obj_t * ui_PanelOptOffsetSub;
static lv_obj_t * ui_ImageOptOffsetSub;
static lv_obj_t * ui_LabelOptOffsetSub;

static lv_obj_t * ui_PanelPrintSpeedAndFlow;
static lv_obj_t * ui_LabelPrintSpeedAndFlowTitle;
static lv_obj_t * ui_PanelPercent;
static lv_obj_t * ui_ButtonPercentOne;
static lv_obj_t * ui_LabelPrecentOne;
static lv_obj_t * ui_ButtonPercentFive;
static lv_obj_t * ui_LabelPrecentFive;
static lv_obj_t * ui_ButtonPercentTen;
static lv_obj_t * ui_LabelPrecentTen;
static lv_obj_t * ui_ButtonPercentTwentyFive;
static lv_obj_t * ui_LabelPrecentTwentyFive;

static lv_obj_t * ui_PanelAddSpeed;
static lv_obj_t * ui_LabelAddSpeed;
static lv_obj_t * ui_ImageAddSpeed;
static lv_obj_t * ui_LabelSpeedValue;
static lv_obj_t * ui_PanelSubSpeed;
static lv_obj_t * ui_LabelSubSpeed;
static lv_obj_t * ui_ImageSubSpeed;

static lv_obj_t * ui_PanelAddFlow;
static lv_obj_t * ui_LabelAddFlow;
static lv_obj_t * ui_ImageAddFlow;
static lv_obj_t * ui_LabelFlowValue;
static lv_obj_t * ui_PanelSubFlow;
static lv_obj_t * ui_LabelSubFlow;
static lv_obj_t * ui_ImageSubFlow;
#endif

/**********************custom variable*******************/
#define SMALL_OFFSET_UNIT (0.01f)
#define LARGE_OFFSET_UNIT (0.05f)

#define SMALL_PERCENT_UNIT (1)
#define MID_PERCENT_UNIT (5)
#define LARGE_PERCENT_UNIT (10)
#define LARGEST_PERCENT_UNIT (25)

static float adjust_offset_z = 0.0f;
static bool small_offset_unit = true;  //
static uint8_t percent_unit = 0; //0 : 1%, 1:5%, 2: 10%, 25%
static int flow_percent = 100;
static int speed_percent = 100;
static bool is_lastest_offset_z = false;
static bool is_lastest_flow_percent = false;
static bool is_lastest_speed_percent = false;
static lv_timer_t *timer_offset = NULL;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif


static void ui_event_ButtonHomeScreenAdjustment(lv_event_t * e);
static void ui_event_ButtonFileManageScreenAdjustment(lv_event_t * e);
static void ui_event_ButtonSettingsScreenAdjustment(lv_event_t * e);
static void ui_event_ButtonReserveScreenAdjustment(lv_event_t * e);
static void ui_event_ButtonMoveScreenAdjust(lv_event_t * e);
static void ui_event_ButtonFilamentScreenAdjust(lv_event_t * e);
static void ui_event_ButtonCoolScreenAdjust(lv_event_t * e);
static void ui_event_ButtonSmallOffset(lv_event_t * e);
static void ui_event_ButtonLargeOffset(lv_event_t * e);
static void ui_event_PanelOptOffsetAdd(lv_event_t * e);
static void ui_event_PanelOptOffsetSub(lv_event_t * e);
static void ui_event_ButtonPercentOne(lv_event_t * e);
static void ui_event_ButtonPercentFive(lv_event_t * e);
static void ui_event_ButtonPercentTen(lv_event_t * e);
static void ui_event_ButtonPercentTwentyFive(lv_event_t * e);
static void ui_event_PanelOffsetScreenAdjust(lv_event_t * e);
static void ui_event_PanelSpeedScreenAdjust(lv_event_t * e);
static void ui_event_PanelFlowScreenAdjust(lv_event_t * e);
static void ui_event_SilentModeSwitch(lv_event_t * e);

static void AdjPageHomeBtnClicked(lv_event_t * e);
static void AdjPageFileManageBtnClicked(lv_event_t * e);
static void AdjPageSettingBtnClicked(lv_event_t * e);
static void SmallOffsetUnitBtnClicked(lv_event_t * e);
static void LargeOffsetUnitBtnClicked(lv_event_t * e);
static void MoveBtnClicked(lv_event_t * e);
static void FilamentBtnClicked(lv_event_t * e);
static void CoolBtnClicked(lv_event_t * e);
static void OffsetAddClicked(lv_event_t * e);
static void OffsetSubClicked(lv_event_t * e);
static void PercentOneBtnClicked(lv_event_t * e);
static void PercentFiveBtnClicked(lv_event_t * e);
static void PercentTenBtnClicked(lv_event_t * e);
static void PercentTwentyFiveBtnClicked(lv_event_t * e);

static void PanelOffsetClicked(lv_event_t * e);
static void PanelFlowClicked(lv_event_t * e);
static void PanelSpeedClicked(lv_event_t * e);


/*******************custom funs************************/

static void show_offset_z(void);
static void show_speed_percent(void);
static void show_flow_percent(void);
static void show_offset_z_unit(void);
static void show_percent_unit(void);
static float get_offset_z_unit_value();
static int get_percent_unit_value();

/********Adjustment Page***********/
void ui_event_ButtonHomeScreenAdjustment(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        AdjPageHomeBtnClicked(e);
    }
}
void ui_event_ButtonFileManageScreenAdjustment(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        AdjPageFileManageBtnClicked(e);
    }
}
void ui_event_ButtonSettingsScreenAdjustment(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        AdjPageSettingBtnClicked(e);
    }
}
void ui_event_ButtonReserveScreenAdjustment(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        AdjPageReserveBtnClicked(e);
    }
}
void ui_event_ButtonSmallOffset(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        SmallOffsetUnitBtnClicked(e);
    }
}
void ui_event_ButtonLargeOffset(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        LargeOffsetUnitBtnClicked(e);
    }
}

void ui_event_ButtonMoveScreenAdjust(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        MoveBtnClicked(e);
    }
}
void ui_event_ButtonFilamentScreenAdjust(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        FilamentBtnClicked(e);
    }
}
void ui_event_ButtonCoolScreenAdjust(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        CoolBtnClicked(e);
    }
}

void ui_event_PanelOptOffsetAdd(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        OffsetAddClicked(e);
    }
}

void ui_event_PanelOptOffsetSub(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        OffsetSubClicked(e);
    }
}
void ui_event_ButtonPercentOne(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        PercentOneBtnClicked(e);
    }
}
void ui_event_ButtonPercentFive(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        PercentFiveBtnClicked(e);
    }
}
void ui_event_ButtonPercentTen(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        PercentTenBtnClicked(e);
    }
}
void ui_event_ButtonPercentTwentyFive(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        PercentTwentyFiveBtnClicked(e);
    }
}

void ui_event_PanelOffsetScreenAdjust(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        PanelOffsetClicked(e);
    }
}

void ui_event_PanelSpeedScreenAdjust(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        PanelSpeedClicked(e);
    }
}

void ui_event_PanelFlowScreenAdjust(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        PanelFlowClicked(e);
    }
}
void ui_event_SilentModeSwitch(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        if(lv_obj_has_state(ui_ScreenAdjustmentSilentModeSwitch,LV_STATE_CHECKED))
        {
            CrLogI("open the silent mode");
            set_printer_data(0x06, 3, "l1");
        }
        else
        {
            CrLogI("close the silent mode");
            set_printer_data(0x06, 3, "l0");
        }
    }
}

void ui_event_ModeChange(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        send_buzzer(0x01);
        if(target == ui_AdjustmentSilentMode)
        {
            CrLogI("open the silent mode");
            lv_obj_add_state(ui_AdjustmentSilentMode, LV_STATE_CHECKED);
            lv_obj_clear_state(ui_AdjustmentNormalMode, LV_STATE_CHECKED);
            set_printer_data(0x06, 3, "l1");
        }
        if(target == ui_AdjustmentNormalMode)
        {
            CrLogI("close the silent mode");
            lv_obj_clear_state(ui_AdjustmentSilentMode, LV_STATE_CHECKED);
            lv_obj_add_state(ui_AdjustmentNormalMode, LV_STATE_CHECKED);
            set_printer_data(0x06, 3, "l0");
        }
    }
}

void ui_ScreenAdjustmentPage_screen_init(void)
{
    uint8_t language_index = get_cur_language_index();
    ui_ScreenAdjustmentPage = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenAdjustmentPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenAdjustmentPage, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenAdjustmentPage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_ScreenAdjustmentPage, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelPageScreenAdjustment = lv_obj_create(ui_ScreenAdjustmentPage);
    lv_obj_set_width(ui_PanelPageScreenAdjustment, 80);
    lv_obj_set_height(ui_PanelPageScreenAdjustment, 480);
    lv_obj_clear_flag(ui_PanelPageScreenAdjustment, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_PanelPageScreenAdjustment, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonHomeScreenAdjustment = lv_btn_create(ui_PanelPageScreenAdjustment);
    lv_obj_set_width(ui_ButtonHomeScreenAdjustment, 80);
    lv_obj_set_height(ui_ButtonHomeScreenAdjustment, 96);
    lv_obj_set_x(ui_ButtonHomeScreenAdjustment, -22);
    lv_obj_set_y(ui_ButtonHomeScreenAdjustment, -22);
    lv_obj_add_flag(ui_ButtonHomeScreenAdjustment, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonHomeScreenAdjustment, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonHomeScreenAdjustment, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonHomeScreenAdjustment, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonHomeScreenAdjustment, &ui_img_pagehome_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ButtonHomeScreenAdjustment, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonHomeScreenAdjustment, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonHomeScreenAdjustment, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonHomeScreenAdjustment, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonHomeScreenAdjustment, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageAdjustmentPage = lv_img_create(ui_PanelPageScreenAdjustment);
    lv_img_set_src(ui_ImageAdjustmentPage, &ui_img_pagemoveselected_png);
    lv_obj_set_width(ui_ImageAdjustmentPage, 80);
    lv_obj_set_height(ui_ImageAdjustmentPage, LV_SIZE_CONTENT);    /// 92
    lv_obj_set_x(ui_ImageAdjustmentPage, -22);
    lv_obj_set_y(ui_ImageAdjustmentPage, 74);
    lv_obj_add_flag(ui_ImageAdjustmentPage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageAdjustmentPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ButtonFileManageScreenAdjustment = lv_btn_create(ui_PanelPageScreenAdjustment);
    lv_obj_set_width(ui_ButtonFileManageScreenAdjustment, 80);
    lv_obj_set_height(ui_ButtonFileManageScreenAdjustment, 96);
    lv_obj_set_x(ui_ButtonFileManageScreenAdjustment, -22);
    lv_obj_set_y(ui_ButtonFileManageScreenAdjustment, 170);
    lv_obj_add_flag(ui_ButtonFileManageScreenAdjustment, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonFileManageScreenAdjustment, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonFileManageScreenAdjustment, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonFileManageScreenAdjustment, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonFileManageScreenAdjustment, &ui_img_pagefilemanage_png,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ButtonFileManageScreenAdjustment, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonFileManageScreenAdjustment, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonFileManageScreenAdjustment, 255,
                                LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonFileManageScreenAdjustment, 2,
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonFileManageScreenAdjustment, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonSettingsScreenAdjustment = lv_btn_create(ui_PanelPageScreenAdjustment);
    lv_obj_set_width(ui_ButtonSettingsScreenAdjustment, 80);
    lv_obj_set_height(ui_ButtonSettingsScreenAdjustment, 96);
    lv_obj_set_x(ui_ButtonSettingsScreenAdjustment, -22);
    lv_obj_set_y(ui_ButtonSettingsScreenAdjustment, 266);
    lv_obj_add_flag(ui_ButtonSettingsScreenAdjustment, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSettingsScreenAdjustment, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonSettingsScreenAdjustment, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonSettingsScreenAdjustment, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonSettingsScreenAdjustment, &ui_img_pagesetting_png,
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonSettingsScreenAdjustment, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonSettingsScreenAdjustment, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonSettingsScreenAdjustment, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonSettingsScreenAdjustment, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ButtonReserveScreenAdjustment = lv_btn_create(ui_PanelPageScreenAdjustment);
    lv_obj_set_width(ui_ButtonReserveScreenAdjustment, 80);
    lv_obj_set_height(ui_ButtonReserveScreenAdjustment, 96);
    lv_obj_set_x(ui_ButtonReserveScreenAdjustment, -22);
    lv_obj_set_y(ui_ButtonReserveScreenAdjustment, 362);
    lv_obj_add_flag(ui_ButtonReserveScreenAdjustment, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonReserveScreenAdjustment, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ButtonReserveScreenAdjustment, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ButtonReserveScreenAdjustment, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ButtonReserveScreenAdjustment, &ui_img_pagereserve_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonReserveScreenAdjustment, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonReserveScreenAdjustment, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonReserveScreenAdjustment, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_side(ui_ButtonReserveScreenAdjustment, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_PanelAdjustment = lv_obj_create(ui_ScreenAdjustmentPage);
    lv_obj_set_width(ui_PanelAdjustment, 720);
    lv_obj_set_height(ui_PanelAdjustment, 52);
    lv_obj_set_x(ui_PanelAdjustment, 80);
    lv_obj_set_y(ui_PanelAdjustment, 0);
    lv_obj_clear_flag(ui_PanelAdjustment, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelAdjustment, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelAdjustment, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelAdjustment, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelAdjustment, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelMoveScreenAdjust = lv_obj_create(ui_PanelAdjustment);
    lv_obj_set_width(ui_PanelMoveScreenAdjust, 240);
    lv_obj_set_height(ui_PanelMoveScreenAdjust, 46);
    lv_obj_set_x(ui_PanelMoveScreenAdjust, 1);
    lv_obj_set_y(ui_PanelMoveScreenAdjust, -18);
    lv_obj_clear_flag(ui_PanelMoveScreenAdjust, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_side(ui_PanelMoveScreenAdjust, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelMoveScreenAdjust, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelMoveScreenAdjust, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelMoveScreenAdjust, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelMoveScreenAdjust, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_border_side(ui_PanelMoveScreenAdjust, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelMoveScreenAdjust, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelMoveScreenAdjust, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelMoveScreenAdjust, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelMoveScreenAdjust, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_PanelMoveScreenAdjust, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_PanelMoveScreenAdjust, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelMoveScreenAdjust = lv_label_create(ui_PanelMoveScreenAdjust);
    lv_obj_set_width(ui_LabelMoveScreenAdjust, 240);
    lv_obj_set_height(ui_LabelMoveScreenAdjust, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_LabelMoveScreenAdjust, LV_ALIGN_CENTER);
    //lv_label_set_long_mode(ui_LabelMoveAndTemperTitle, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelMoveScreenAdjust, MovePageTitle[get_cur_language_index()]);
    //lv_label_set_recolor(ui_LabelMoveAndTemperTitle, "true");
    lv_obj_set_style_text_color(ui_LabelMoveScreenAdjust, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelMoveScreenAdjust, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelMoveScreenAdjust, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelMoveScreenAdjust, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelFilamentScreenAdjust = lv_obj_create(ui_PanelAdjustment);
    lv_obj_set_width(ui_PanelFilamentScreenAdjust, 200);
    lv_obj_set_height(ui_PanelFilamentScreenAdjust, 46);
    lv_obj_set_x(ui_PanelFilamentScreenAdjust, 242);
    lv_obj_set_y(ui_PanelFilamentScreenAdjust, -18);
    lv_obj_clear_flag(ui_PanelFilamentScreenAdjust, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_PanelFilamentScreenAdjust, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelFilamentScreenAdjust, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelFilamentScreenAdjust, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelFilamentScreenAdjust, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelFilamentScreenAdjust, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelFilamentScreenAdjust, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelFilamentScreenAdjust, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelFilamentScreenAdjust, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelFilamentScreenAdjust, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_PanelFilamentScreenAdjust, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_PanelFilamentScreenAdjust, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_add_flag(ui_PanelFilamentScreenAdjust, LV_OBJ_FLAG_HIDDEN);      /// Flags

    ui_LabelFilamentScreenAdjust  = lv_label_create(ui_PanelFilamentScreenAdjust);
    lv_obj_set_width(ui_LabelFilamentScreenAdjust, 200);
    lv_obj_set_height(ui_LabelFilamentScreenAdjust, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_LabelFilamentScreenAdjust, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_LabelFilamentScreenAdjust, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelFilamentScreenAdjust, Extrude_Retract[get_cur_language_index()]);   //进退料
    //lv_label_set_recolor(ui_LabelFilament, "true");
    lv_obj_set_style_text_color(ui_LabelFilamentScreenAdjust, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFilamentScreenAdjust, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelFilamentScreenAdjust, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFilamentScreenAdjust, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_PanelCoolScreenAdjust = lv_obj_create(ui_PanelAdjustment);
    lv_obj_set_width(ui_PanelCoolScreenAdjust, 100);
    lv_obj_set_height(ui_PanelCoolScreenAdjust, 46);
    lv_obj_set_x(ui_PanelCoolScreenAdjust, 444);
    lv_obj_set_y(ui_PanelCoolScreenAdjust, -18);
    lv_obj_clear_flag(ui_PanelCoolScreenAdjust, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_flag(ui_PanelCoolScreenAdjust, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelCoolScreenAdjust, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelCoolScreenAdjust, lv_color_hex(0x121212), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelCoolScreenAdjust, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelCoolScreenAdjust, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelCoolScreenAdjust, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelCoolScreenAdjust, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelCoolScreenAdjust, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelCoolScreenAdjust, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui_PanelCoolScreenAdjust, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_PanelCoolScreenAdjust, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_add_flag(ui_PanelCoolScreenAdjust, LV_OBJ_FLAG_HIDDEN);      /// Flags

    ui_LabelCoolScreenAdjust = lv_label_create(ui_PanelCoolScreenAdjust);
    lv_obj_set_width(ui_LabelCoolScreenAdjust, 100);
    lv_obj_set_height(ui_LabelCoolScreenAdjust, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_LabelCoolScreenAdjust, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_LabelCoolScreenAdjust, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelCoolScreenAdjust, "冷却");     //冷却
    //lv_label_set_recolor(ui_LabelCool, "true");
    lv_obj_set_style_text_color(ui_LabelCoolScreenAdjust, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelCoolScreenAdjust, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelCoolScreenAdjust, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelCoolScreenAdjust, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_PanelAdjustmentScreenAdjust = lv_obj_create(ui_PanelAdjustment);
    lv_obj_set_width(ui_PanelAdjustmentScreenAdjust, 152);
    lv_obj_set_height(ui_PanelAdjustmentScreenAdjust, 46);
    lv_obj_set_x(ui_PanelAdjustmentScreenAdjust, 546);
    lv_obj_set_y(ui_PanelAdjustmentScreenAdjust, -18);
    //lv_obj_add_flag(ui_PanelAdjustmentScreenAdjust, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_clear_flag(ui_PanelAdjustmentScreenAdjust, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelAdjustmentScreenAdjust, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelAdjustmentScreenAdjust, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelAdjustmentScreenAdjust, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelAdjustmentScreenAdjust, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_side(ui_PanelAdjustmentScreenAdjust, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_color(ui_PanelAdjustmentScreenAdjust, lv_color_hex(0x42BDD8),
    //                               LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_opa(ui_PanelAdjustmentScreenAdjust, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_width(ui_PanelAdjustmentScreenAdjust, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_shadow_width(ui_PanelAdjustmentScreenAdjust, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_spread(ui_PanelAdjustmentScreenAdjust, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_PanelAdjustmentScreenAdjust, LV_OBJ_FLAG_HIDDEN);      /// Flags

    ui_LabelAdjustmentScreenAdjust = lv_label_create(ui_PanelAdjustmentScreenAdjust);
    lv_obj_set_width(ui_LabelAdjustmentScreenAdjust, 152);
    lv_obj_set_height(ui_LabelAdjustmentScreenAdjust, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_LabelAdjustmentScreenAdjust, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_LabelAdjustmentScreenAdjust, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelAdjustmentScreenAdjust, Adjustment[get_cur_language_index()]);  //调整
    lv_obj_set_style_text_color(ui_LabelAdjustmentScreenAdjust, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelAdjustmentScreenAdjust, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelAdjustmentScreenAdjust, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelAdjustmentScreenAdjust, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenAdjustPanelCenter = lv_obj_create(ui_ScreenAdjustmentPage);
    lv_obj_set_width(ui_ScreenAdjustPanelCenter, 720);
    lv_obj_set_height(ui_ScreenAdjustPanelCenter, 430);
    lv_obj_set_x(ui_ScreenAdjustPanelCenter, 80);
    lv_obj_set_y(ui_ScreenAdjustPanelCenter, 50);
    lv_obj_clear_flag(ui_ScreenAdjustPanelCenter, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScreenAdjustPanelCenter, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScreenAdjustPanelCenter, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenAdjustPanelCenter, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ScreenAdjustPanelCenter, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenAdjustmentPanelAdjust = lv_obj_create(ui_ScreenAdjustPanelCenter);
    lv_obj_set_width(ui_ScreenAdjustmentPanelAdjust, 696);
    lv_obj_set_height(ui_ScreenAdjustmentPanelAdjust, 406);
    lv_obj_set_x(ui_ScreenAdjustmentPanelAdjust, -10);
    lv_obj_set_y(ui_ScreenAdjustmentPanelAdjust, -10);
    lv_obj_clear_flag(ui_ScreenAdjustmentPanelAdjust, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenAdjustmentPanelAdjust, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenAdjustmentPanelAdjust, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ScreenAdjustmentPanelAdjust, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ScreenAdjustmentPanelAdjust, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_ScreenAdjustmentPanelAdjust, LV_OBJ_FLAG_HIDDEN);      /// Flags

/*******  屏蔽z轴补偿初始化内容 ********   
    ui_ScreenAdjustmentLabelOffset = lv_label_create(ui_ScreenAdjustmentPanelAdjust);
    lv_obj_set_width(ui_ScreenAdjustmentLabelOffset, 100);
    lv_obj_set_height(ui_ScreenAdjustmentLabelOffset, 38);
    lv_obj_set_x(ui_ScreenAdjustmentLabelOffset, 16);
    lv_obj_set_y(ui_ScreenAdjustmentLabelOffset, 34);
    lv_label_set_text(ui_ScreenAdjustmentLabelOffset, "Z轴补偿");
    lv_obj_set_style_text_color(ui_ScreenAdjustmentLabelOffset, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenAdjustmentLabelOffset, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScreenAdjustmentLabelOffset, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenAdjustmentBtnSubOffset = lv_btn_create(ui_ScreenAdjustmentPanelAdjust);
    lv_obj_set_width(ui_ScreenAdjustmentBtnSubOffset, 52);
    lv_obj_set_height(ui_ScreenAdjustmentBtnSubOffset, 52);
    lv_obj_set_x(ui_ScreenAdjustmentBtnSubOffset, 322);
    lv_obj_set_y(ui_ScreenAdjustmentBtnSubOffset, 29);
    lv_obj_add_flag(ui_ScreenAdjustmentBtnSubOffset, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ScreenAdjustmentBtnSubOffset, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScreenAdjustmentBtnSubOffset, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ScreenAdjustmentBtnSubOffset, &ui_img_sub_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ScreenAdjustmentBtnSubOffset, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ScreenAdjustmentBtnSubOffset, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenAdjustmentBtnAddOffset = lv_btn_create(ui_ScreenAdjustmentPanelAdjust);
    lv_obj_set_width(ui_ScreenAdjustmentBtnAddOffset, 52);
    lv_obj_set_height(ui_ScreenAdjustmentBtnAddOffset, 52);
    lv_obj_set_x(ui_ScreenAdjustmentBtnAddOffset, 574);
    lv_obj_set_y(ui_ScreenAdjustmentBtnAddOffset, 29);
    lv_obj_add_flag(ui_ScreenAdjustmentBtnAddOffset, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ScreenAdjustmentBtnAddOffset, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScreenAdjustmentBtnAddOffset, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_ScreenAdjustmentBtnAddOffset, &ui_img_add_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ScreenAdjustmentBtnAddOffset, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ScreenAdjustmentBtnAddOffset, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenAdjustmentPanelOffset = lv_obj_create(ui_ScreenAdjustmentPanelAdjust);
    lv_obj_set_width(ui_ScreenAdjustmentPanelOffset, 146);
    lv_obj_set_height(ui_ScreenAdjustmentPanelOffset, 54);
    lv_obj_set_x(ui_ScreenAdjustmentPanelOffset, 401);
    lv_obj_set_y(ui_ScreenAdjustmentPanelOffset, 28);
    lv_obj_clear_flag(ui_ScreenAdjustmentPanelOffset, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenAdjustmentPanelOffset, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenAdjustmentPanelOffset, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ScreenAdjustmentPanelOffset, lv_color_hex(0x5E6166), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ScreenAdjustmentPanelOffset, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ScreenAdjustmentPanelOffset, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ScreenAdjustmentPanelOffset, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenAdjustmentLabelOffsetValue = lv_label_create(ui_ScreenAdjustmentPanelOffset);
    lv_obj_set_width(ui_ScreenAdjustmentLabelOffsetValue, 80);
    lv_obj_set_height(ui_ScreenAdjustmentLabelOffsetValue, 30);
    lv_obj_set_x(ui_ScreenAdjustmentLabelOffsetValue, -13);
    lv_obj_set_y(ui_ScreenAdjustmentLabelOffsetValue, -10);
    lv_label_set_text(ui_ScreenAdjustmentLabelOffsetValue, "-8.88");
    lv_obj_set_style_text_color(ui_ScreenAdjustmentLabelOffsetValue, lv_color_hex(0xFFFFFF),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenAdjustmentLabelOffsetValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ScreenAdjustmentLabelOffsetValue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScreenAdjustmentLabelOffsetValue, lv_font28.font,
                               LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenAdjustmentLabelOffsetUnit = lv_label_create(ui_ScreenAdjustmentPanelOffset);
    lv_obj_set_width(ui_ScreenAdjustmentLabelOffsetUnit, 50);
    lv_obj_set_height(ui_ScreenAdjustmentLabelOffsetUnit, 22);
    lv_obj_set_x(ui_ScreenAdjustmentLabelOffsetUnit, 68);
    lv_obj_set_y(ui_ScreenAdjustmentLabelOffsetUnit, -6);
    lv_label_set_text(ui_ScreenAdjustmentLabelOffsetUnit, "mm");
    lv_obj_set_style_text_color(ui_ScreenAdjustmentLabelOffsetUnit, lv_color_hex(0xFFFFFF),
                                LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenAdjustmentLabelOffsetUnit, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_ScreenAdjustmentLabelOffsetUnit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScreenAdjustmentLabelOffsetUnit, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
*******  屏蔽z轴补偿初始化内容 ********/   

    ui_ScreenAdjustmentLabelSpeed = lv_label_create(ui_ScreenAdjustmentPanelAdjust);
    lv_obj_set_width(ui_ScreenAdjustmentLabelSpeed, 100);
    lv_obj_set_height(ui_ScreenAdjustmentLabelSpeed, 38);
    lv_obj_set_x(ui_ScreenAdjustmentLabelSpeed, 38);
    lv_obj_set_y(ui_ScreenAdjustmentLabelSpeed, 38);
    lv_label_set_text(ui_ScreenAdjustmentLabelSpeed, "打印速度");
    lv_obj_set_style_text_color(ui_ScreenAdjustmentLabelSpeed, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ScreenAdjustmentLabelSpeed, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ScreenAdjustmentLabelSpeed, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ScreenAdjustmentBtnSubSpeed = lv_btn_create(ui_ScreenAdjustmentPanelAdjust);
    // lv_obj_set_width(ui_ScreenAdjustmentBtnSubSpeed, 52);
    // lv_obj_set_height(ui_ScreenAdjustmentBtnSubSpeed, 52);
    // lv_obj_set_x(ui_ScreenAdjustmentBtnSubSpeed, 344);
    // lv_obj_set_y(ui_ScreenAdjustmentBtnSubSpeed, 41);
    // lv_obj_add_flag(ui_ScreenAdjustmentBtnSubSpeed, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    // lv_obj_clear_flag(ui_ScreenAdjustmentBtnSubSpeed, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ui_ScreenAdjustmentBtnSubSpeed, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_img_src(ui_ScreenAdjustmentBtnSubSpeed, &ui_img_sub_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_width(ui_ScreenAdjustmentBtnSubSpeed, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_spread(ui_ScreenAdjustmentBtnSubSpeed, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ScreenAdjustmentPanelSpeed = lv_obj_create(ui_ScreenAdjustmentPanelAdjust);
    // lv_obj_set_width(ui_ScreenAdjustmentPanelSpeed, 146);
    // lv_obj_set_height(ui_ScreenAdjustmentPanelSpeed, 54);
    // lv_obj_set_x(ui_ScreenAdjustmentPanelSpeed, 423);
    // lv_obj_set_y(ui_ScreenAdjustmentPanelSpeed, 40);
    // lv_obj_clear_flag(ui_ScreenAdjustmentPanelSpeed, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ScreenAdjustmentPanelSpeed, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ScreenAdjustmentPanelSpeed, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_ScreenAdjustmentPanelSpeed, lv_color_hex(0x5E6166), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_opa(ui_ScreenAdjustmentPanelSpeed, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ui_ScreenAdjustmentPanelSpeed, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_side(ui_ScreenAdjustmentPanelSpeed, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ScreenAdjustmentLabelSpeedValue = lv_label_create(ui_ScreenAdjustmentPanelSpeed);
    // lv_obj_set_width(ui_ScreenAdjustmentLabelSpeedValue, 80);
    // lv_obj_set_height(ui_ScreenAdjustmentLabelSpeedValue, 30);
    // lv_obj_set_x(ui_ScreenAdjustmentLabelSpeedValue, -13);
    // lv_obj_set_y(ui_ScreenAdjustmentLabelSpeedValue, -10);
    // lv_label_set_text(ui_ScreenAdjustmentLabelSpeedValue, "100");
    // lv_obj_set_style_text_color(ui_ScreenAdjustmentLabelSpeedValue, lv_color_hex(0xFFFFFF),
    //                             LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_ScreenAdjustmentLabelSpeedValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_ScreenAdjustmentLabelSpeedValue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_ScreenAdjustmentLabelSpeedValue, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ScreenAdjustmentLabelSpeedUnit = lv_label_create(ui_ScreenAdjustmentPanelSpeed);
    // lv_obj_set_width(ui_ScreenAdjustmentLabelSpeedUnit, 50);
    // lv_obj_set_height(ui_ScreenAdjustmentLabelSpeedUnit, 22);
    // lv_obj_set_x(ui_ScreenAdjustmentLabelSpeedUnit, 68);
    // lv_obj_set_y(ui_ScreenAdjustmentLabelSpeedUnit, -6);
    // lv_label_set_text(ui_ScreenAdjustmentLabelSpeedUnit, "%");
    // lv_obj_set_style_text_color(ui_ScreenAdjustmentLabelSpeedUnit, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_ScreenAdjustmentLabelSpeedUnit, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_ScreenAdjustmentLabelSpeedUnit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_ScreenAdjustmentLabelSpeedUnit, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ScreenAdjustmentBtnAddSpeed = lv_btn_create(ui_ScreenAdjustmentPanelAdjust);
    // lv_obj_set_width(ui_ScreenAdjustmentBtnAddSpeed, 52);
    // lv_obj_set_height(ui_ScreenAdjustmentBtnAddSpeed, 52);
    // lv_obj_set_x(ui_ScreenAdjustmentBtnAddSpeed, 596);
    // lv_obj_set_y(ui_ScreenAdjustmentBtnAddSpeed, 41);
    // lv_obj_add_flag(ui_ScreenAdjustmentBtnAddSpeed, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    // lv_obj_clear_flag(ui_ScreenAdjustmentBtnAddSpeed, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ui_ScreenAdjustmentBtnAddSpeed, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_img_src(ui_ScreenAdjustmentBtnAddSpeed, &ui_img_add_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_width(ui_ScreenAdjustmentBtnAddSpeed, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_spread(ui_ScreenAdjustmentBtnAddSpeed, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ScreenAdjustmentLabelFlow = lv_label_create(ui_ScreenAdjustmentPanelAdjust);
    // lv_obj_set_width(ui_ScreenAdjustmentLabelFlow, 100);
    // lv_obj_set_height(ui_ScreenAdjustmentLabelFlow, 38);
    // lv_obj_set_x(ui_ScreenAdjustmentLabelFlow, 38);
    // lv_obj_set_y(ui_ScreenAdjustmentLabelFlow, 146);
    // lv_label_set_text(ui_ScreenAdjustmentLabelFlow, "打印流量");
    // lv_obj_set_style_text_color(ui_ScreenAdjustmentLabelFlow, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_ScreenAdjustmentLabelFlow, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_ScreenAdjustmentLabelFlow, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ScreenAdjustmentBtnSubFlow = lv_btn_create(ui_ScreenAdjustmentPanelAdjust);
    // lv_obj_set_width(ui_ScreenAdjustmentBtnSubFlow, 52);
    // lv_obj_set_height(ui_ScreenAdjustmentBtnSubFlow, 52);
    // lv_obj_set_x(ui_ScreenAdjustmentBtnSubFlow, 344);
    // lv_obj_set_y(ui_ScreenAdjustmentBtnSubFlow, 139);
    // lv_obj_add_flag(ui_ScreenAdjustmentBtnSubFlow, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    // lv_obj_clear_flag(ui_ScreenAdjustmentBtnSubFlow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ui_ScreenAdjustmentBtnSubFlow, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_img_src(ui_ScreenAdjustmentBtnSubFlow, &ui_img_sub_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_width(ui_ScreenAdjustmentBtnSubFlow, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_spread(ui_ScreenAdjustmentBtnSubFlow, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ScreenAdjustmentPanelFlow = lv_obj_create(ui_ScreenAdjustmentPanelAdjust);
    // lv_obj_set_width(ui_ScreenAdjustmentPanelFlow, 146);
    // lv_obj_set_height(ui_ScreenAdjustmentPanelFlow, 54);
    // lv_obj_set_x(ui_ScreenAdjustmentPanelFlow, 423);
    // lv_obj_set_y(ui_ScreenAdjustmentPanelFlow, 138);
    // lv_obj_clear_flag(ui_ScreenAdjustmentPanelFlow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_bg_color(ui_ScreenAdjustmentPanelFlow, lv_color_hex(0x3A3D42), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ScreenAdjustmentPanelFlow, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_color(ui_ScreenAdjustmentPanelFlow, lv_color_hex(0x5E6166), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_opa(ui_ScreenAdjustmentPanelFlow, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ui_ScreenAdjustmentPanelFlow, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_side(ui_ScreenAdjustmentPanelFlow, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ScreenAdjustmentLabelFlowValue = lv_label_create(ui_ScreenAdjustmentPanelFlow);
    // lv_obj_set_width(ui_ScreenAdjustmentLabelFlowValue, 80);
    // lv_obj_set_height(ui_ScreenAdjustmentLabelFlowValue, 30);
    // lv_obj_set_x(ui_ScreenAdjustmentLabelFlowValue, -13);
    // lv_obj_set_y(ui_ScreenAdjustmentLabelFlowValue, -10);
    // lv_label_set_text(ui_ScreenAdjustmentLabelFlowValue, "100");
    // lv_obj_set_style_text_color(ui_ScreenAdjustmentLabelFlowValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_ScreenAdjustmentLabelFlowValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_ScreenAdjustmentLabelFlowValue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_ScreenAdjustmentLabelFlowValue, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ScreenAdjustmentLabelFlowUnit = lv_label_create(ui_ScreenAdjustmentPanelFlow);
    // lv_obj_set_width(ui_ScreenAdjustmentLabelFlowUnit, 50);
    // lv_obj_set_height(ui_ScreenAdjustmentLabelFlowUnit, 22);
    // lv_obj_set_x(ui_ScreenAdjustmentLabelFlowUnit, 68);
    // lv_obj_set_y(ui_ScreenAdjustmentLabelFlowUnit, -6);
    // lv_label_set_text(ui_ScreenAdjustmentLabelFlowUnit, "%");
    // lv_obj_set_style_text_color(ui_ScreenAdjustmentLabelFlowUnit, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_ScreenAdjustmentLabelFlowUnit, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_ScreenAdjustmentLabelFlowUnit, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_ScreenAdjustmentLabelFlowUnit, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ScreenAdjustmentBtnAddFlow = lv_btn_create(ui_ScreenAdjustmentPanelAdjust);
    // lv_obj_set_width(ui_ScreenAdjustmentBtnAddFlow, 52);
    // lv_obj_set_height(ui_ScreenAdjustmentBtnAddFlow, 52);
    // lv_obj_set_x(ui_ScreenAdjustmentBtnAddFlow, 596);
    // lv_obj_set_y(ui_ScreenAdjustmentBtnAddFlow, 139);
    // lv_obj_add_flag(ui_ScreenAdjustmentBtnAddFlow, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    // lv_obj_clear_flag(ui_ScreenAdjustmentBtnAddFlow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_set_style_radius(ui_ScreenAdjustmentBtnAddFlow, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_img_src(ui_ScreenAdjustmentBtnAddFlow, &ui_img_add_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_width(ui_ScreenAdjustmentBtnAddFlow, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_spread(ui_ScreenAdjustmentBtnAddFlow, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

/*******************增加静音模式开关***********************/
    ui_ScreenAdjustmentSilentModePanel = lv_obj_create(ui_ScreenAdjustmentPanelAdjust);
    lv_obj_set_width(ui_ScreenAdjustmentSilentModePanel, 696);
    lv_obj_set_height(ui_ScreenAdjustmentSilentModePanel, 38);
    lv_obj_set_x(ui_ScreenAdjustmentSilentModePanel, 0);
    lv_obj_set_y(ui_ScreenAdjustmentSilentModePanel, 108);
    lv_obj_clear_flag(ui_ScreenAdjustmentSilentModePanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ScreenAdjustmentSilentModePanel, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenAdjustmentSilentModePanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ScreenAdjustmentSilentModePanel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ScreenAdjustmentSilentModePanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_AdjustmentSilentMode = lv_checkbox_create(ui_ScreenAdjustmentSilentModePanel);
    lv_checkbox_set_text(ui_AdjustmentSilentMode, "静音模式");
    lv_obj_add_flag(ui_AdjustmentSilentMode, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_width(ui_AdjustmentSilentMode, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AdjustmentSilentMode, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AdjustmentSilentMode, 387);
    lv_obj_set_y(ui_AdjustmentSilentMode, 0);
    lv_obj_add_flag(ui_AdjustmentSilentMode, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_AdjustmentSilentMode, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AdjustmentSilentMode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AdjustmentSilentMode, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_width(ui_AdjustmentSilentMode, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_AdjustmentSilentMode, LV_RADIUS_CIRCLE, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AdjustmentSilentMode, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AdjustmentSilentMode, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_AdjustmentSilentMode, lv_color_hex(0x484D56),LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_AdjustmentSilentMode, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_AdjustmentSilentMode, LV_RADIUS_CIRCLE, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_AdjustmentSilentMode, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_AdjustmentSilentMode, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_AdjustmentSilentMode, lv_color_hex(0x484D56),LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui_AdjustmentSilentMode, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_AdjustmentSilentMode, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_img_src(ui_AdjustmentSilentMode, NULL, LV_PART_INDICATOR | LV_STATE_CHECKED);

    ui_AdjustmentNormalMode = lv_checkbox_create(ui_ScreenAdjustmentSilentModePanel);
    lv_checkbox_set_text(ui_AdjustmentNormalMode, "常规模式");
    lv_obj_add_flag(ui_AdjustmentNormalMode, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_width(ui_AdjustmentNormalMode, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_AdjustmentNormalMode, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_AdjustmentNormalMode, 38);
    lv_obj_set_y(ui_AdjustmentNormalMode, 0);
    lv_obj_add_flag(ui_AdjustmentNormalMode, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_add_state(ui_AdjustmentNormalMode, LV_STATE_CHECKED);     /// Flags
    lv_obj_set_style_text_color(ui_AdjustmentNormalMode, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_AdjustmentNormalMode, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_AdjustmentNormalMode, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_width(ui_AdjustmentNormalMode, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_AdjustmentNormalMode, LV_RADIUS_CIRCLE, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_AdjustmentNormalMode, lv_color_hex(0x2D2E31), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_AdjustmentNormalMode, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_AdjustmentNormalMode, lv_color_hex(0x484D56),LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_AdjustmentNormalMode, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_AdjustmentNormalMode, LV_RADIUS_CIRCLE, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_AdjustmentNormalMode, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_AdjustmentNormalMode, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_color(ui_AdjustmentNormalMode, lv_color_hex(0x50555F),LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_opa(ui_AdjustmentNormalMode, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_AdjustmentNormalMode, 2, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_border_width(ui_AdjustmentNormalMode, 2, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui_AdjustmentNormalMode, NULL, LV_PART_INDICATOR | LV_STATE_CHECKED);

    // ui_ScreenAdjustmentSilentModeLabal = lv_label_create(ui_ScreenAdjustmentSilentModePanel);
    // lv_obj_set_width(ui_ScreenAdjustmentSilentModeLabal, 200);
    // lv_obj_set_height(ui_ScreenAdjustmentSilentModeLabal, 25);
    // lv_obj_align(ui_ScreenAdjustmentSilentModeLabal, LV_ALIGN_LEFT_MID, 38, 0);
    // lv_label_set_text(ui_ScreenAdjustmentSilentModeLabal, "静音模式");
    // lv_obj_set_style_text_color(ui_ScreenAdjustmentSilentModeLabal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_ScreenAdjustmentSilentModeLabal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_ScreenAdjustmentSilentModeLabal, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ScreenAdjustmentSilentModeSwitch = lv_switch_create(ui_ScreenAdjustmentSilentModePanel);
    // lv_obj_set_width(ui_ScreenAdjustmentSilentModeSwitch, 74);
    // lv_obj_set_height(ui_ScreenAdjustmentSilentModeSwitch, 36);
    // lv_obj_align(ui_ScreenAdjustmentSilentModeSwitch, LV_ALIGN_LEFT_MID, 574, 0);
    // lv_obj_add_flag(ui_ScreenAdjustmentSilentModeSwitch, LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_set_style_radius(ui_ScreenAdjustmentSilentModeSwitch, 90, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_ScreenAdjustmentSilentModeSwitch, lv_color_hex(0x43454A), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ScreenAdjustmentSilentModeSwitch, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_ScreenAdjustmentSilentModeSwitch, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_CHECKED);
    // lv_obj_set_style_bg_opa(ui_ScreenAdjustmentSilentModeSwitch, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    // lv_obj_set_style_bg_color(ui_ScreenAdjustmentSilentModeSwitch, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_CHECKED);
    // lv_obj_set_style_bg_opa(ui_ScreenAdjustmentSilentModeSwitch, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);

    // lv_obj_set_style_radius(ui_ScreenAdjustmentSilentModeSwitch, 30, LV_PART_KNOB | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_ScreenAdjustmentSilentModeSwitch, lv_color_hex(0x5F646C), LV_PART_KNOB | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_ScreenAdjustmentSilentModeSwitch, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_ScreenAdjustmentSilentModeSwitch, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_CHECKED);
    // lv_obj_set_style_bg_opa(ui_ScreenAdjustmentSilentModeSwitch, 255, LV_PART_KNOB | LV_STATE_CHECKED);

/*******************增加静音模式开关***********************/
#if 0
    ui_PanelAdjustmentTitle = lv_label_create(ui_PanelAdjustment);
    lv_obj_set_width(ui_PanelAdjustmentTitle, 211);
    lv_obj_set_height(ui_PanelAdjustmentTitle, 46);
    lv_obj_set_x(ui_PanelAdjustmentTitle, 1);
    lv_obj_set_y(ui_PanelAdjustmentTitle, -16);
    lv_obj_set_style_bg_color(ui_PanelAdjustmentTitle, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelAdjustmentTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelAdjustment = lv_label_create(ui_PanelAdjustmentTitle);
    lv_obj_set_width(ui_LabelAdjustment, 211);
    lv_obj_set_height(ui_LabelAdjustment, 35);
    lv_obj_set_align(ui_LabelAdjustment, LV_ALIGN_CENTER);
    // lv_obj_set_x(ui_LabelAdjustment, 1);
    // lv_obj_set_y(ui_LabelAdjustment, -5);
    lv_label_set_long_mode(ui_LabelAdjustment, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelAdjustment, Adjustment[language_index]);
    lv_label_set_recolor(ui_LabelAdjustment, "true");
    lv_obj_set_style_text_color(ui_LabelAdjustment, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelAdjustment, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelAdjustment, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelAdjustment, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_LabelAdjustment, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_LabelAdjustment, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ScreenAdjustmentPageCenterPanel = lv_obj_create(ui_ScreenAdjustmentPage);
    lv_obj_set_width(ui_ScreenAdjustmentPageCenterPanel, 720);
    lv_obj_set_height(ui_ScreenAdjustmentPageCenterPanel, 430);
    lv_obj_set_x(ui_ScreenAdjustmentPageCenterPanel, 82);
    lv_obj_set_y(ui_ScreenAdjustmentPageCenterPanel, 52);
    lv_obj_clear_flag(ui_ScreenAdjustmentPageCenterPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ScreenAdjustmentPageCenterPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ScreenAdjustmentPageCenterPanel, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenAdjustmentPageCenterPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_ScreenAdjustmentPageCenterPanel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelOffsetZ = lv_obj_create(ui_ScreenAdjustmentPageCenterPanel);
    lv_obj_set_width(ui_PanelOffsetZ, 280);
    lv_obj_set_height(ui_PanelOffsetZ, 430);
    lv_obj_set_x(ui_PanelOffsetZ, -22);
    lv_obj_set_y(ui_PanelOffsetZ, -22);
    lv_obj_clear_flag(ui_PanelOffsetZ, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelOffsetZ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelOffsetZ, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelOffsetZ, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelOffsetZ, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelOffsetTitle = lv_label_create(ui_PanelOffsetZ);
    lv_obj_set_width(ui_LabelOffsetTitle, 160);
    lv_obj_set_height(ui_LabelOffsetTitle, 33);
    lv_obj_set_x(ui_LabelOffsetTitle, 52);
    lv_obj_set_y(ui_LabelOffsetTitle, -7);
    lv_label_set_long_mode(ui_LabelOffsetTitle, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_style_text_color(ui_LabelOffsetTitle, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelOffsetTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelOffsetTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelOffsetTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelOffsetDis = lv_obj_create(ui_PanelOffsetZ);
    lv_obj_set_width(ui_PanelOffsetDis, 242);
    lv_obj_set_height(ui_PanelOffsetDis, 54);
    lv_obj_set_x(ui_PanelOffsetDis, 11);
    lv_obj_set_y(ui_PanelOffsetDis, 36);
    lv_obj_clear_flag(ui_PanelOffsetDis, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelOffsetDis, 32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelOffsetDis, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelOffsetDis, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelOffsetDis, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonSmallOffset = lv_btn_create(ui_PanelOffsetDis);
    lv_obj_set_width(ui_ButtonSmallOffset, 120);
    lv_obj_set_height(ui_ButtonSmallOffset, 54);
    lv_obj_set_x(ui_ButtonSmallOffset, -22);
    lv_obj_set_y(ui_ButtonSmallOffset, -22);
    lv_obj_add_flag(ui_ButtonSmallOffset, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonSmallOffset, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonSmallOffset, 32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonSmallOffset, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonSmallOffset, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonSmallOffset, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonSmallOffset, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonSmallOffset, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ButtonSmallOffset, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonSmallOffset, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonSmallOffset, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonSmallOffset, 1, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelSmallOffset = lv_label_create(ui_ButtonSmallOffset);
    lv_obj_set_width(ui_LabelSmallOffset, 110);
    lv_obj_set_height(ui_LabelSmallOffset, 35);
    lv_obj_set_x(ui_LabelSmallOffset, -18);
    lv_obj_set_y(ui_LabelSmallOffset, -2);
    lv_label_set_long_mode(ui_LabelSmallOffset, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelSmallOffset, "0.01mm");
    lv_obj_set_style_text_align(ui_LabelSmallOffset, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSmallOffset, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonLargeOffset = lv_btn_create(ui_PanelOffsetDis);
    lv_obj_set_width(ui_ButtonLargeOffset, 120);
    lv_obj_set_height(ui_ButtonLargeOffset, 54);
    lv_obj_set_x(ui_ButtonLargeOffset, 100);
    lv_obj_set_y(ui_ButtonLargeOffset, -22);
    lv_obj_add_flag(ui_ButtonLargeOffset, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonLargeOffset, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonLargeOffset, 32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonLargeOffset, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonLargeOffset, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonLargeOffset, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonLargeOffset, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonLargeOffset, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ButtonLargeOffset, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonLargeOffset, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonLargeOffset, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonLargeOffset, 1, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelLargeOffset = lv_label_create(ui_ButtonLargeOffset);
    lv_obj_set_width(ui_LabelLargeOffset, 114);
    lv_obj_set_height(ui_LabelLargeOffset, 35);
    lv_obj_set_x(ui_LabelLargeOffset, -18);
    lv_obj_set_y(ui_LabelLargeOffset, -2);
    lv_label_set_long_mode(ui_LabelLargeOffset, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelLargeOffset, "0.05mm");
    lv_obj_set_style_text_align(ui_LabelLargeOffset, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelLargeOffset, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelOptOffsetAdd = lv_obj_create(ui_PanelOffsetZ);
    lv_obj_set_width(ui_PanelOptOffsetAdd, 170);
    lv_obj_set_height(ui_PanelOptOffsetAdd, 90);
    lv_obj_set_x(ui_PanelOptOffsetAdd, 47);
    lv_obj_set_y(ui_PanelOptOffsetAdd, 135);
    lv_obj_clear_flag(ui_PanelOptOffsetAdd, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelOptOffsetAdd, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelOptOffsetAdd, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelOptOffsetAdd, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelOptOffsetAdd, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelOptOffsetAdd, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelOptOffsetAdd, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelOptOffsetAdd, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_ImageOptOffsetAdd = lv_img_create(ui_PanelOptOffsetAdd);
    lv_img_set_src(ui_ImageOptOffsetAdd, &ui_img_offsetup_png);
    lv_obj_set_width(ui_ImageOptOffsetAdd, 42);
    lv_obj_set_height(ui_ImageOptOffsetAdd, 42);
    lv_obj_set_x(ui_ImageOptOffsetAdd, 45);
    lv_obj_set_y(ui_ImageOptOffsetAdd, -12);
    lv_obj_add_flag(ui_ImageOptOffsetAdd, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageOptOffsetAdd, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelOptOffsetAdd = lv_label_create(ui_PanelOptOffsetAdd);
    lv_obj_set_width(ui_LabelOptOffsetAdd, 40);
    lv_obj_set_height(ui_LabelOptOffsetAdd, 33);
    lv_obj_set_x(ui_LabelOptOffsetAdd, 50);
    lv_obj_set_y(ui_LabelOptOffsetAdd, 28);
    lv_label_set_text(ui_LabelOptOffsetAdd, "Z+");
    lv_obj_set_style_text_color(ui_LabelOptOffsetAdd, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelOptOffsetAdd, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelOptOffsetAdd, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelOptOffsetAdd, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelOffsetValue = lv_label_create(ui_PanelOffsetZ);
    lv_obj_set_width(ui_LabelOffsetValue, 88);
    lv_obj_set_height(ui_LabelOffsetValue, 33);
    lv_obj_set_x(ui_LabelOffsetValue, 51);
    lv_obj_set_y(ui_LabelOffsetValue, 235);
    lv_label_set_text(ui_LabelOffsetValue, "-4.60");
    //lv_label_set_long_mode(ui_LabelOffsetValue, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_style_text_color(ui_LabelOffsetValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelOffsetValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelOffsetValue, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelOffsetValue, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelOffsetValueUnit = lv_label_create(ui_PanelOffsetZ);
    lv_obj_set_width(ui_LabelOffsetValueUnit, 60);
    lv_obj_set_height(ui_LabelOffsetValueUnit, 33);
    lv_obj_set_x(ui_LabelOffsetValueUnit, 137);
    lv_obj_set_y(ui_LabelOffsetValueUnit, 235);
    lv_label_set_text(ui_LabelOffsetValueUnit, "mm");
    lv_obj_set_style_text_color(ui_LabelOffsetValueUnit, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelOffsetValueUnit, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelOffsetValueUnit, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelOffsetValueUnit, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelOptOffsetSub = lv_obj_create(ui_PanelOffsetZ);
    lv_obj_set_width(ui_PanelOptOffsetSub, 170);
    lv_obj_set_height(ui_PanelOptOffsetSub, 90);
    lv_obj_set_x(ui_PanelOptOffsetSub, 47);
    lv_obj_set_y(ui_PanelOptOffsetSub, 280);
    lv_obj_clear_flag(ui_PanelOptOffsetSub, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelOptOffsetSub, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelOptOffsetSub, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelOptOffsetSub, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelOptOffsetSub, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelOptOffsetSub, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelOptOffsetSub, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelOptOffsetSub, 2, LV_PART_MAIN | LV_STATE_PRESSED);


    ui_ImageOptOffsetSub = lv_img_create(ui_PanelOptOffsetSub);
    lv_img_set_src(ui_ImageOptOffsetSub, &ui_img_offsetdown_png);
    lv_obj_set_width(ui_ImageOptOffsetSub, 42);
    lv_obj_set_height(ui_ImageOptOffsetSub, 42);
    lv_obj_set_x(ui_ImageOptOffsetSub, 45);
    lv_obj_set_y(ui_ImageOptOffsetSub, -12);
    lv_obj_add_flag(ui_ImageOptOffsetSub, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageOptOffsetSub, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelOptOffsetSub = lv_label_create(ui_PanelOptOffsetSub);
    lv_obj_set_width(ui_LabelOptOffsetSub, 40);
    lv_obj_set_height(ui_LabelOptOffsetSub, 33);
    lv_obj_set_x(ui_LabelOptOffsetSub, 50);
    lv_obj_set_y(ui_LabelOptOffsetSub, 28);
    lv_label_set_text(ui_LabelOptOffsetSub, "Z-");
    lv_obj_set_style_text_color(ui_LabelOptOffsetSub, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelOptOffsetSub, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelOptOffsetSub, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelOptOffsetSub, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelPrintSpeedAndFlow = lv_obj_create(ui_ScreenAdjustmentPageCenterPanel);
    lv_obj_set_width(ui_PanelPrintSpeedAndFlow, 440);
    lv_obj_set_height(ui_PanelPrintSpeedAndFlow, 430);
    lv_obj_set_x(ui_PanelPrintSpeedAndFlow, 258);
    lv_obj_set_y(ui_PanelPrintSpeedAndFlow, -22);
    lv_obj_clear_flag(ui_PanelPrintSpeedAndFlow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPrintSpeedAndFlow, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelPrintSpeedAndFlow, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelPrintSpeedAndFlow, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPrintSpeedAndFlow, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelPrintSpeedAndFlowTitle = lv_label_create(ui_PanelPrintSpeedAndFlow);
    lv_obj_set_width(ui_LabelPrintSpeedAndFlowTitle, 300);
    lv_obj_set_height(ui_LabelPrintSpeedAndFlowTitle, 33);
    lv_obj_set_x(ui_LabelPrintSpeedAndFlowTitle, 31);
    lv_obj_set_y(ui_LabelPrintSpeedAndFlowTitle, -7);
    lv_label_set_long_mode(ui_LabelPrintSpeedAndFlowTitle, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_style_text_color(ui_LabelPrintSpeedAndFlowTitle, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelPrintSpeedAndFlowTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelPrintSpeedAndFlowTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelPrintSpeedAndFlowTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelPercent = lv_obj_create(ui_PanelPrintSpeedAndFlow);
    lv_obj_set_width(ui_PanelPercent, 373);
    lv_obj_set_height(ui_PanelPercent, 54);
    lv_obj_set_x(ui_PanelPercent, -3);
    lv_obj_set_y(ui_PanelPercent, 36);
    lv_obj_clear_flag(ui_PanelPercent, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_PanelPercent, 32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelPercent, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelPercent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelPercent, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonPercentOne = lv_btn_create(ui_PanelPercent);
    lv_obj_set_width(ui_ButtonPercentOne, 90);
    lv_obj_set_height(ui_ButtonPercentOne, 54);
    lv_obj_set_x(ui_ButtonPercentOne, -22);
    lv_obj_set_y(ui_ButtonPercentOne, -22);
    lv_obj_add_flag(ui_ButtonPercentOne, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonPercentOne, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonPercentOne, 32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonPercentOne, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPercentOne, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonPercentOne, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonPercentOne, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonPercentOne, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ButtonPercentOne, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonPercentOne, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonPercentOne, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonPercentOne, 1, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelPrecentOne = lv_label_create(ui_ButtonPercentOne);
    lv_obj_set_width(ui_LabelPrecentOne, 66);
    lv_obj_set_height(ui_LabelPrecentOne, 35);
    lv_obj_set_x(ui_LabelPrecentOne, -10);
    lv_obj_set_y(ui_LabelPrecentOne, -2);
    lv_label_set_text(ui_LabelPrecentOne, "1%");
    lv_obj_set_style_text_align(ui_LabelPrecentOne, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelPrecentOne, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonPercentFive = lv_btn_create(ui_PanelPercent);
    lv_obj_set_width(ui_ButtonPercentFive, 90);
    lv_obj_set_height(ui_ButtonPercentFive, 54);
    lv_obj_set_x(ui_ButtonPercentFive, 72);
    lv_obj_set_y(ui_ButtonPercentFive, -22);
    lv_obj_add_flag(ui_ButtonPercentFive, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonPercentFive, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonPercentFive, 32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonPercentFive, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPercentFive, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonPercentFive, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonPercentFive, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonPercentFive, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ButtonPercentFive, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonPercentFive, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonPercentFive, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonPercentFive, 1, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelPrecentFive = lv_label_create(ui_ButtonPercentFive);
    lv_obj_set_width(ui_LabelPrecentFive, 66);
    lv_obj_set_height(ui_LabelPrecentFive, 35);
    lv_obj_set_x(ui_LabelPrecentFive, -10);
    lv_obj_set_y(ui_LabelPrecentFive, -2);
    lv_label_set_text(ui_LabelPrecentFive, "5%");
    lv_obj_set_style_text_align(ui_LabelPrecentFive, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelPrecentFive, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonPercentTen = lv_btn_create(ui_PanelPercent);
    lv_obj_set_width(ui_ButtonPercentTen, 90);
    lv_obj_set_height(ui_ButtonPercentTen, 54);
    lv_obj_set_x(ui_ButtonPercentTen, 166);
    lv_obj_set_y(ui_ButtonPercentTen, -22);
    lv_obj_add_flag(ui_ButtonPercentTen, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonPercentTen, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonPercentTen, 32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonPercentTen, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPercentTen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonPercentTen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonPercentTen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonPercentTen, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ButtonPercentTen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonPercentTen, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonPercentTen, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonPercentTen, 1, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelPrecentTen = lv_label_create(ui_ButtonPercentTen);
    lv_obj_set_width(ui_LabelPrecentTen, 66);
    lv_obj_set_height(ui_LabelPrecentTen, 35);
    lv_obj_set_x(ui_LabelPrecentTen, -10);
    lv_obj_set_y(ui_LabelPrecentTen, -2);
    lv_label_set_text(ui_LabelPrecentTen, "10%");
    lv_obj_set_style_text_align(ui_LabelPrecentTen, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelPrecentTen, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonPercentTwentyFive = lv_btn_create(ui_PanelPercent);
    lv_obj_set_width(ui_ButtonPercentTwentyFive, 90);
    lv_obj_set_height(ui_ButtonPercentTwentyFive, 54);
    lv_obj_set_x(ui_ButtonPercentTwentyFive, 261);
    lv_obj_set_y(ui_ButtonPercentTwentyFive, -22);
    lv_obj_add_flag(ui_ButtonPercentTwentyFive, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_ButtonPercentTwentyFive, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonPercentTwentyFive, 32, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonPercentTwentyFive, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPercentTwentyFive, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonPercentTwentyFive, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonPercentTwentyFive, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_ButtonPercentTwentyFive, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ButtonPercentTwentyFive, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonPercentTwentyFive, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_ButtonPercentTwentyFive, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_ButtonPercentTwentyFive, 0, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelPrecentTwentyFive = lv_label_create(ui_ButtonPercentTwentyFive);
    lv_obj_set_width(ui_LabelPrecentTwentyFive, 66);
    lv_obj_set_height(ui_LabelPrecentTwentyFive, 35);
    lv_obj_set_x(ui_LabelPrecentTwentyFive, -10);
    lv_obj_set_y(ui_LabelPrecentTwentyFive, -2);
    lv_label_set_text(ui_LabelPrecentTwentyFive, "25%");
    lv_obj_set_style_text_align(ui_LabelPrecentTwentyFive, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelPrecentTwentyFive, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelAddSpeed = lv_obj_create(ui_PanelPrintSpeedAndFlow);
    lv_obj_set_width(ui_PanelAddSpeed, 170);
    lv_obj_set_height(ui_PanelAddSpeed, 90);
    lv_obj_set_x(ui_PanelAddSpeed, 2);
    lv_obj_set_y(ui_PanelAddSpeed, 135);
    lv_obj_clear_flag(ui_PanelAddSpeed, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelAddSpeed, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelAddSpeed, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelAddSpeed, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelAddSpeed, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelAddSpeed, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelAddSpeed, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelAddSpeed, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelAddSpeed = lv_label_create(ui_PanelAddSpeed);
    lv_obj_set_width(ui_LabelAddSpeed, 160);
    lv_obj_set_height(ui_LabelAddSpeed, 33);
    lv_obj_set_x(ui_LabelAddSpeed, -17);
    lv_obj_set_y(ui_LabelAddSpeed, 28);
    lv_label_set_long_mode(ui_LabelAddSpeed, LV_LABEL_LONG_SCROLL_CIRCULAR);
    char buff[30] = {0};
    sprintf(buff, "%s%s +", Print[language_index], Speed[language_index]);
    lv_label_set_text(ui_LabelAddSpeed, buff);
    lv_obj_set_style_text_color(ui_LabelAddSpeed, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelAddSpeed, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelAddSpeed, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelAddSpeed, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageAddSpeed = lv_img_create(ui_PanelAddSpeed);
    lv_img_set_src(ui_ImageAddSpeed, &ui_img_addprintspeed_png);
    lv_obj_set_width(ui_ImageAddSpeed, 42);
    lv_obj_set_height(ui_ImageAddSpeed, 42);
    lv_obj_set_x(ui_ImageAddSpeed, 46);
    lv_obj_set_y(ui_ImageAddSpeed, -12);
    lv_obj_add_flag(ui_ImageAddSpeed, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageAddSpeed, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelSpeedValue = lv_label_create(ui_PanelPrintSpeedAndFlow);
    lv_obj_set_width(ui_LabelSpeedValue, 88);
    lv_obj_set_height(ui_LabelSpeedValue, 33);
    lv_obj_set_x(ui_LabelSpeedValue, 51);
    lv_obj_set_y(ui_LabelSpeedValue, 235);
    lv_label_set_text(ui_LabelSpeedValue, "100%");
    //lv_label_set_long_mode(ui_LabelOffsetValue, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_style_text_color(ui_LabelSpeedValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSpeedValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelSpeedValue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSpeedValue, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelSubSpeed = lv_obj_create(ui_PanelPrintSpeedAndFlow);
    lv_obj_set_width(ui_PanelSubSpeed, 170);
    lv_obj_set_height(ui_PanelSubSpeed, 90);
    lv_obj_set_x(ui_PanelSubSpeed, 2);
    lv_obj_set_y(ui_PanelSubSpeed, 280);
    lv_obj_clear_flag(ui_PanelSubSpeed, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelSubSpeed, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelSubSpeed, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelSubSpeed, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelSubSpeed, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelSubSpeed, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelSubSpeed, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelSubSpeed, 2, LV_PART_MAIN | LV_STATE_PRESSED);

    ui_LabelSubSpeed = lv_label_create(ui_PanelSubSpeed);
    lv_obj_set_width(ui_LabelSubSpeed, 160);
    lv_obj_set_height(ui_LabelSubSpeed, 33);
    lv_obj_set_x(ui_LabelSubSpeed, -17);
    lv_obj_set_y(ui_LabelSubSpeed, 28);
    lv_label_set_long_mode(ui_LabelSubSpeed, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s%s -", Print[language_index], Speed[language_index]);
    lv_label_set_text(ui_LabelSubSpeed, buff);
    lv_obj_set_style_text_color(ui_LabelSubSpeed, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSubSpeed, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelSubSpeed, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSubSpeed, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageSubSpeed = lv_img_create(ui_PanelSubSpeed);
    lv_img_set_src(ui_ImageSubSpeed, &ui_img_subprintspeed_png);
    lv_obj_set_width(ui_ImageSubSpeed, 42);
    lv_obj_set_height(ui_ImageSubSpeed, 42);
    lv_obj_set_x(ui_ImageSubSpeed, 46);
    lv_obj_set_y(ui_ImageSubSpeed, -12);
    lv_obj_add_flag(ui_ImageSubSpeed, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageSubSpeed, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PanelAddFlow = lv_obj_create(ui_PanelPrintSpeedAndFlow);
    lv_obj_set_width(ui_PanelAddFlow, 170);
    lv_obj_set_height(ui_PanelAddFlow, 90);
    lv_obj_set_x(ui_PanelAddFlow, 192);
    lv_obj_set_y(ui_PanelAddFlow, 135);
    lv_obj_clear_flag(ui_PanelAddFlow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelAddFlow, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelAddFlow, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelAddFlow, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelAddFlow, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelAddFlow, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelAddFlow, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelAddFlow, 2, LV_PART_MAIN | LV_STATE_PRESSED);


    ui_LabelAddFlow = lv_label_create(ui_PanelAddFlow);
    lv_obj_set_width(ui_LabelAddFlow, 150);
    lv_obj_set_height(ui_LabelAddFlow, 33);
    lv_obj_set_x(ui_LabelAddFlow, -12);
    lv_obj_set_y(ui_LabelAddFlow, 28);
    lv_label_set_long_mode(ui_LabelAddFlow, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s%s +", Print[language_index], Flow[language_index]);
    lv_label_set_text(ui_LabelAddFlow, buff);
    lv_obj_set_style_text_color(ui_LabelAddFlow, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelAddFlow, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelAddFlow, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelAddFlow, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageAddFlow = lv_img_create(ui_PanelAddFlow);
    lv_img_set_src(ui_ImageAddFlow, &ui_img_addflow_png);
    lv_obj_set_width(ui_ImageAddFlow, 42);
    lv_obj_set_height(ui_ImageAddFlow, 42);
    lv_obj_set_x(ui_ImageAddFlow, 46);
    lv_obj_set_y(ui_ImageAddFlow, -12);
    lv_obj_add_flag(ui_ImageAddFlow, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageAddFlow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_LabelFlowValue = lv_label_create(ui_PanelPrintSpeedAndFlow);
    lv_obj_set_width(ui_LabelFlowValue, 88);
    lv_obj_set_height(ui_LabelFlowValue, 33);
    lv_obj_set_x(ui_LabelFlowValue, 231);
    lv_obj_set_y(ui_LabelFlowValue, 235);
    lv_label_set_text(ui_LabelFlowValue, "100%");
    //lv_label_set_long_mode(ui_LabelOffsetValue, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_style_text_color(ui_LabelFlowValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFlowValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelFlowValue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFlowValue, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelSubFlow = lv_obj_create(ui_PanelPrintSpeedAndFlow);
    lv_obj_set_width(ui_PanelSubFlow, 170);
    lv_obj_set_height(ui_PanelSubFlow, 90);
    lv_obj_set_x(ui_PanelSubFlow, 192);
    lv_obj_set_y(ui_PanelSubFlow, 280);
    lv_obj_clear_flag(ui_PanelSubFlow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelSubFlow, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelSubFlow, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelSubFlow, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_PanelSubFlow, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(ui_PanelSubFlow, lv_color_hex(0x42BDD8),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_PanelSubFlow, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_PanelSubFlow, 2, LV_PART_MAIN | LV_STATE_PRESSED);


    ui_LabelSubFlow = lv_label_create(ui_PanelSubFlow);
    lv_obj_set_width(ui_LabelSubFlow, 150);
    lv_obj_set_height(ui_LabelSubFlow, 33);
    lv_obj_set_x(ui_LabelSubFlow, -12);
    lv_obj_set_y(ui_LabelSubFlow, 28);
    lv_label_set_long_mode(ui_LabelSubFlow, LV_LABEL_LONG_SCROLL_CIRCULAR);
    memset(buff, 0, sizeof(buff));
    sprintf(buff, "%s%s -", Print[language_index], Flow[language_index]);
    lv_label_set_text(ui_LabelSubFlow, buff);
    lv_obj_set_style_text_color(ui_LabelSubFlow, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSubFlow, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelSubFlow, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSubFlow, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ImageSubFlow = lv_img_create(ui_PanelSubFlow);
    lv_img_set_src(ui_ImageSubFlow, &ui_img_subflow_png);
    lv_obj_set_width(ui_ImageSubFlow, 42);
    lv_obj_set_height(ui_ImageSubFlow, 42);
    lv_obj_set_x(ui_ImageSubFlow, 46);
    lv_obj_set_y(ui_ImageSubFlow, -12);
    lv_obj_add_flag(ui_ImageSubFlow, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageSubFlow, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
#endif

    lv_obj_add_event_cb(ui_ButtonHomeScreenAdjustment, ui_event_ButtonHomeScreenAdjustment, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonFileManageScreenAdjustment, ui_event_ButtonFileManageScreenAdjustment, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonSettingsScreenAdjustment, ui_event_ButtonSettingsScreenAdjustment, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonReserveScreenAdjustment, ui_event_ButtonReserveScreenAdjustment, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ButtonSmallOffset, ui_event_ButtonSmallOffset, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ButtonLargeOffset, ui_event_ButtonLargeOffset, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ButtonPercentOne, ui_event_ButtonPercentOne, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ButtonPercentFive, ui_event_ButtonPercentFive, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ButtonPercentTen, ui_event_ButtonPercentTen, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ButtonPercentTwentyFive, ui_event_ButtonPercentTwentyFive, LV_EVENT_ALL, NULL);

    lv_obj_add_event_cb(ui_PanelMoveScreenAdjust, ui_event_ButtonMoveScreenAdjust, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelFilamentScreenAdjust, ui_event_ButtonFilamentScreenAdjust, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_PanelCoolScreenAdjust, ui_event_ButtonCoolScreenAdjust, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ScreenAdjustmentBtnAddOffset, ui_event_PanelOptOffsetAdd, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ScreenAdjustmentBtnSubOffset, ui_event_PanelOptOffsetSub, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ScreenAdjustmentBtnAddSpeed, ui_event_PanelAddSpeed, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ScreenAdjustmentBtnSubSpeed, ui_event_PanelSubSpeed, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ScreenAdjustmentBtnAddFlow, ui_event_PanelAddFlow, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ScreenAdjustmentBtnSubFlow, ui_event_PanelSubFlow, LV_EVENT_ALL, NULL);

    // lv_obj_add_event_cb(ui_ScreenAdjustmentPanelOffset, ui_event_PanelOffsetScreenAdjust, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ScreenAdjustmentPanelSpeed, ui_event_PanelSpeedScreenAdjust, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_ScreenAdjustmentPanelFlow, ui_event_PanelFlowScreenAdjust, LV_EVENT_ALL, NULL);
    //增加静音模式开关
    // lv_obj_add_event_cb(ui_ScreenAdjustmentSilentModeSwitch, ui_event_SilentModeSwitch, LV_EVENT_ALL, NULL);

    lv_obj_add_event_cb(ui_AdjustmentNormalMode, ui_event_ModeChange, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_AdjustmentSilentMode, ui_event_ModeChange, LV_EVENT_ALL, NULL);
    /******************************************************************/
    // show_offset_z_unit();
    // show_percent_unit();
}

void LoadAdjustmentScreen(void)
{
    lv_disp_load_scr(ui_ScreenAdjustmentPage);
    is_lastest_offset_z = false;
    is_lastest_flow_percent = false;
    is_lastest_speed_percent = false;
    // send_get_z_offset_cmd();
    // send_get_print_flow_cmd();
    // send_get_print_speed_cmd();
    // send_get_print_status();

}

void AdjPageHomeBtnClicked(lv_event_t * e)
{
	// Your code here
    if ( home_printing_is_printing_finished() )
        LoadHomeNormalScreen();
    else
        LoadHomePrintingScreen();
}

void AdjPageFileManageBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadFileManageScreen();
}

void AdjPageSettingBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadSettingsScreen();
}

void AdjPageReserveBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadCustomerServiceScreen();
}

void MoveBtnClicked(lv_event_t * e)
{
	// Your code here
    LoadAxisMoveScreen();
}

void FilamentBtnClicked(lv_event_t * e)
{
	// Your code here
    // LoadFilamentScreen();
}

void CoolBtnClicked(lv_event_t * e)
{
	// Your code here
    // LoadCoolScreen();
}

void SmallOffsetUnitBtnClicked(lv_event_t * e)
{
	// Your code here
    small_offset_unit = true;
    show_offset_z_unit();
}

void LargeOffsetUnitBtnClicked(lv_event_t * e)
{
	// Your code here
    small_offset_unit = false;
    show_offset_z_unit();
}

float get_offset_z_unit_value()
{
    float offset = 0.0f;
    if ( small_offset_unit )
    {
        offset = (SMALL_OFFSET_UNIT);
    }
    else
    {
        offset = (LARGE_OFFSET_UNIT);
    }

    return offset;
}

void save_offset_callback(struct _lv_timer_t *timer)
{
    timer_offset = NULL;
    send_set_save_param();
    CrLogI("send save param--------------------");
}

void OffsetAddClicked(lv_event_t * e)
{
    if ( !timer_offset )
    {
        timer_offset = lv_timer_create(save_offset_callback, 30 * 1000, NULL);
        lv_timer_set_repeat_count(timer_offset, 1);
    }

    float offset_z = Z_OFFSET_INCREASE_UNIT; //get_offset_z_unit_value();
    send_set_z_offset_cmd(offset_z);
}

void OffsetSubClicked(lv_event_t * e)
{
    if ( !timer_offset )
    {
        timer_offset = lv_timer_create(save_offset_callback, 30 * 1000, NULL);
        lv_timer_set_repeat_count(timer_offset, 1);
    }

    float offset_z = 0 - Z_OFFSET_INCREASE_UNIT;//get_offset_z_unit_value();
    send_set_z_offset_cmd(offset_z);
}

void PercentOneBtnClicked(lv_event_t * e)
{
	// Your code here
    percent_unit = 0;
    show_percent_unit();
}

void PercentFiveBtnClicked(lv_event_t * e)
{
	// Your code here
    percent_unit = 1;
    show_percent_unit();
}

void PercentTenBtnClicked(lv_event_t * e)
{
	// Your code here
    percent_unit = 2;
    show_percent_unit();
}

void PercentTwentyFiveBtnClicked(lv_event_t * e)
{
	// Your code here
    percent_unit = 3;
    show_percent_unit();
}

int get_percent_unit_value()
{
    int unit = SMALL_PERCENT_UNIT;
    switch (percent_unit)
    {
    case 0:
        {
            unit = SMALL_PERCENT_UNIT;
        }
        break;
    case 1:
        {
            unit = MID_PERCENT_UNIT;
        }
        break;
    case 2:
        {
            unit = LARGE_PERCENT_UNIT;
        }
        break;
    case 3:
        {
            unit = LARGEST_PERCENT_UNIT;
        }
        break;
    default:
        break;
    }

    return unit;
}

void adjust_offset_edit_callback(void *param)
{
    char *number_buff = (char*)param;
    if ( number_buff )
    {
        send_set_z_offset_cmd(atof(number_buff));
    }
        
}

void adjust_speed_edit_callback(void *param)
{
    char *number_buff = (char*)param;
    if ( number_buff )
    {
        char *ch = strchr(number_buff, '.');
        if ( ch )
            *ch = '\0';

        send_set_print_speed_cmd(atoi(number_buff));
    }
        
}

void adjust_flow_edit_callback(void *param)
{
    char *number_buff = (char*)param;
    if ( number_buff )
    {
        char *ch = strchr(number_buff, '.');
        if ( ch )
            *ch = '\0';

        send_set_print_flow_cmd(atoi(number_buff));
    }
        
}

void PanelOffsetClicked(lv_event_t * e)
{
    char buff[50] = {0};
    sprintf(buff, "%s #42BDD8 %d~%d#", "Z轴相对补偿输入范围", -1, 1);
    numberskeyboardinput(buff, 1, -1,
                    adjust_offset_edit_callback, key_reminder_callback, 0, 0);
}

void PanelSpeedClicked(lv_event_t * e)
{
    char buff[50] = {0};
    sprintf(buff, "%s #42BDD8 %d~%d#", "速度百分比输入范围", 0, 1000);
    numberskeyboardinput(buff, 1000, 0,
                    adjust_speed_edit_callback, key_reminder_callback, 0, 0);
}

void PanelFlowClicked(lv_event_t * e)
{
    char buff[50] = {0};
    sprintf(buff, "%s #42BDD8 %d~%d#", "流量百分比输入范围", 0, 150);
    numberskeyboardinput(buff, 150, 0,
                    adjust_flow_edit_callback, key_reminder_callback, 0, 0);
}


void show_offset_z(void)
{
    char buff[10] = {0};
    sprintf(buff, "%.2f", adjust_offset_z);
    if(ui_ScreenAdjustmentLabelOffsetValue != NULL)
        lv_label_set_text(ui_ScreenAdjustmentLabelOffsetValue, buff);
}

void show_speed_percent(void)
{
    char buff[10] = {0};
    sprintf(buff, "%d", speed_percent);
    if(ui_ScreenAdjustmentLabelSpeedValue != NULL)
    lv_label_set_text(ui_ScreenAdjustmentLabelSpeedValue, buff);
}

void show_flow_percent(void)
{
    char buff[10] = {0};
    sprintf(buff, "%d", flow_percent);
    if(ui_ScreenAdjustmentLabelFlowValue != NULL)
    lv_label_set_text(ui_ScreenAdjustmentLabelFlowValue, buff);
}

void show_offset_z_unit(void)
{
#if 0    
    if ( small_offset_unit )
    {
        lv_obj_set_style_border_color(ui_ButtonSmallOffset, lv_color_hex(0x42BDD8),LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(ui_ButtonSmallOffset, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(ui_ButtonSmallOffset, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_ButtonSmallOffset, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ButtonSmallOffset, 0x1A, LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_set_style_bg_color(ui_ButtonLargeOffset, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ButtonLargeOffset, 0xFF, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(ui_ButtonLargeOffset, lv_color_hex(0x434549),LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(ui_ButtonLargeOffset, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(ui_ButtonLargeOffset, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
    else
    {
        lv_obj_set_style_border_color(ui_ButtonLargeOffset, lv_color_hex(0x42BDD8),LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(ui_ButtonLargeOffset, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(ui_ButtonLargeOffset, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_ButtonLargeOffset, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ButtonLargeOffset, 0x1A, LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_set_style_bg_color(ui_ButtonSmallOffset, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ButtonSmallOffset, 0xFF, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(ui_ButtonSmallOffset, lv_color_hex(0x434549),LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_opa(ui_ButtonSmallOffset, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(ui_ButtonSmallOffset, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
#endif

}

void show_percent_unit(void)
{
#if 0    
    lv_obj_set_style_bg_color(ui_ButtonPercentOne, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPercentOne, 0xFF, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonPercentOne, lv_color_hex(0x434549),LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ButtonPercentOne, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonPercentOne, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonPercentFive, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPercentFive, 0xFF, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonPercentFive, lv_color_hex(0x434549),LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ButtonPercentFive, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonPercentFive, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonPercentTen, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPercentTen, 0xFF, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonPercentTen, lv_color_hex(0x434549),LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ButtonPercentTen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonPercentTen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonPercentTwentyFive, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonPercentTwentyFive, 0xFF, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonPercentTwentyFive, lv_color_hex(0x434549),LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ButtonPercentTwentyFive, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonPercentTwentyFive, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    struct _lv_obj_t * obj = ui_ButtonPercentOne;
    switch (percent_unit)
    {
    case 0:
        {
            obj = ui_ButtonPercentOne;
        }
        break;
    case 1:
        {
            obj = ui_ButtonPercentFive;
        }
        break;
    case 2:
        {
            obj = ui_ButtonPercentTen;
        }
        break;
    case 3:
        {
            obj = ui_ButtonPercentTwentyFive;
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
#endif

}

void adjustment_set_offset_z(float offset_z)
{
    adjust_offset_z = offset_z;
    is_lastest_offset_z = true;
    show_offset_z();
}

void adjustment_set_speed_percent(int percent)
{
    speed_percent = percent;
    is_lastest_speed_percent = true;
    show_speed_percent();
}

void adjustment_set_flow_percent(int percent)
{
    flow_percent = percent;
    is_lastest_flow_percent = true;
    show_flow_percent();
}

void adjustment_set_print_status(int8_t print_status)
{
    // 0: finished, 1:stoped, 2:paused, 3:printing  依赖于协议
    if ( (print_status == 0) || (print_status == 1) )  
    {
        //if ( !lv_obj_has_flag(ui_ScreenAxisMovePage, LV_OBJ_FLAG_HIDDEN) )
        // if ( lv_obj_is_visible(ui_ScreenAdjustmentPage) )
        //     LoadAxisMoveScreen();
    }
}

void adjustment_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();
    if ( ui_LabelAdjustmentScreenAdjust )
        lv_label_set_text(ui_LabelAdjustmentScreenAdjust, Adjustment[language_index]);

    if ( ui_LabelFilamentScreenAdjust )
        lv_label_set_text(ui_LabelFilamentScreenAdjust, Extrude_Retract[language_index]);

    if ( ui_LabelCoolScreenAdjust )
        lv_label_set_text(ui_LabelCoolScreenAdjust, Cooling[language_index]);
   
    if ( ui_LabelMoveScreenAdjust )
        lv_label_set_text(ui_LabelMoveScreenAdjust, MovePageTitle[language_index]);
    if ( ui_AdjustmentNormalMode )
        lv_checkbox_set_text(ui_AdjustmentNormalMode, NormalMode[language_index]);
    if ( ui_AdjustmentSilentMode )
        lv_checkbox_set_text(ui_AdjustmentSilentMode, SlicenMode[language_index]);
    if ( ui_ScreenAdjustmentLabelSpeed )
        lv_checkbox_set_text(ui_ScreenAdjustmentLabelSpeed, SprintSpeed[language_index]);
   
}