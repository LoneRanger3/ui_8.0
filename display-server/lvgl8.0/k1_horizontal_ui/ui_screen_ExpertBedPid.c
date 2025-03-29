#include "ui_screen_ExpertBedPid.h"
#include <stdio.h>
#include "../custom/lvgl_cmd.h"
#include "mult_language.h"
#include "ui_screen_HomeNormal.h"
#include "ui_screen_FileManage.h"
#include "ui_custom_messagebox.h"
#include "ui_custom_reminderbox.h"

#define BEDEND_PID_TEMP_STEP    10//温度加减的值
#define BEDEND_PID_TEMP_MAX     120//PID设定最大温度
#define BEDEND_PID_TEMP_MIN     20//PID设定最小温度
/********axis Move Page***********/
static lv_obj_t * ui_Screen_BedPidPage;
static lv_obj_t * ui_Screen_BedPidTitle;   // 标题

static lv_obj_t * ui_LabelBedPidCurVal;

static lv_obj_t * ui_Screen_BedPidLine;         // 线条
static lv_obj_t * ui_ImageBed;       // 加热图标
static lv_obj_t * ui_ImageZUpperTemp;   // + 符号
static lv_obj_t * ui_ImageZDownTemp;    // - 符号

/********准备界面***********/
static lv_obj_t * ui_Screen_BedPidPrepareLayer;     // 准备图层
static lv_obj_t * ui_Label_BedPidPrepareTip;        // 准备提示
static lv_obj_t * ui_ButtonStartCheckPid;           // "启动"按键
static lv_obj_t * ui_ButtonLabelStartCheckPid;      // "启动"按键
static lv_obj_t * ui_ButtonReturnCheckPid;          // "返回"按键
static lv_obj_t * ui_ButtonLabelReturnCheckPid;     // "返回"按键
static lv_obj_t * ui_PanelTemperValueBedPid;       
static lv_obj_t * ui_LabelTargetTempVal;
static lv_obj_t * ui_LabelTargetTempUnit;
static lv_obj_t * ui_LabelCurrentTempVal;

/********pid调节中界面***********/
static lv_obj_t * ui_Screen_bedPidCheakingLayer;    // pid检测中图层
static lv_obj_t * ui_Label_BedPidCheakingTip;       // 检查中提示
static lv_obj_t * ui_Label_BedPidCheakTimeTip;      // 检查中提示
static lv_obj_t * ui_Image_TempIncreaseArrow;       // 温度升高箭头
static lv_obj_t * ui_Label_CheakingTargetTempVal;   // 检测中目标温度
static lv_obj_t * ui_Label_CheakingCurTempVal;      // 检测中当前温度
static lv_obj_t * ui_Button_FinishCheckingPid;      // 结束检测按键
static lv_obj_t * ui_Button_LabelFinishChecking;    // 结束检测按键文字
static lv_obj_t * ui_Button_ReturnCheckingPid;      // 返回按键
static lv_obj_t * ui_Image_InProcess;               // 进行中图标

/********pid完成中界面***********/
static lv_obj_t * ui_Screen_BedPidFinishLayer;      //  pid检测完成图层
static lv_obj_t * ui_Label_BedPidFinishTip;       // 检查中提示
static lv_obj_t * ui_Label_BedPidFinishTip1;      // 检查中提示
static lv_obj_t * ui_Button_FinishFinishPid;      // 结束检测按键
static lv_obj_t * ui_Image_Finish;      // 结束检测按键



static bool bedpid_start_flag = false;
// void ui_DiapScreenTrafficPage(HotProcess_t process);

int curBedTargetTempVal = 60;    // 记录当前温度

// 画直线
/*
x：线的起点
y：线的终点
width：线宽
height：线长
color：线颜色
*/
static lv_obj_t * ui_DrawStraightLine(lv_obj_t * parent, uint16_t x, uint16_t y, uint16_t width, uint16_t height, lv_color_t color)
{

    lv_obj_t * line = lv_obj_create(parent);
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

    return line;
}



/* 
*/
static lv_obj_t *  ui_AddLabel(lv_obj_t * parent, lv_align_t align, uint16_t size_x, uint16_t size_y, uint16_t pos_x, uint16_t pos_y,
                       const char * txt, lv_font_t * font, lv_color_t color, lv_opa_t opa_value)
{
    lv_obj_t * label = lv_label_create(parent);
    // lv_obj_set_size(label, size_x, size_y);
    // lv_obj_align(label, align, pos_x, pos_y);
    // if (txt != NULL)
    //     lv_label_set_text(label, txt);
    // lv_obj_set_style_text_color(label, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(label, opa_value, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(label, font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_width(label, size_x);
    lv_obj_set_height(label, size_y);
    lv_obj_align(label, align, pos_x, pos_y);
    if (txt != NULL)
        lv_label_set_text(label, txt);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(label, font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(label, opa_value, LV_PART_MAIN | LV_STATE_DEFAULT);
    return label;
}

/* 
*/
static lv_obj_t *  ui_AddPanel_padAllZero(lv_obj_t * parent, uint16_t size_x, uint16_t size_y, uint16_t pos_x, uint16_t pos_y,
                       lv_color_t bg_color, lv_opa_t bg_opa, lv_color_t border_color, lv_opa_t border_opa,
                       lv_coord_t border_width)
{
    lv_obj_t * label = lv_obj_create(parent);

    lv_obj_set_size(label, size_x, size_y);
    lv_obj_set_pos(label, pos_x, pos_y);
    lv_obj_clear_flag(label, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(label, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(label, bg_color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(label, bg_opa, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(label, border_color,
                                  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(label, border_opa, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(label, border_width, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    return label;
}

lv_obj_t *  ui_AddBtn(lv_obj_t * parent, lv_align_t align, uint16_t size_x, uint16_t size_y, uint16_t pos_x, uint16_t pos_y,
                       lv_opa_t bg_opa, lv_color_t bg_color)
{
    lv_obj_t * label = lv_btn_create(parent);
    lv_obj_set_size(label, size_x, size_y);
    lv_obj_align(label, align, pos_x, pos_y);
    lv_obj_set_pos(label, pos_x, pos_y);
    lv_obj_add_flag(label, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(label, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(label, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(label, bg_color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(label, bg_opa, LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_style_shadow_width(label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_all(label, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(label, 0, LV_STATE_DISABLED);
    return label;
}





/**
 * @description: z轴补偿增加按键回调
 * @param  {*}
 * @return {*}
 */
static void item_hot_temp_up_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    char buf[32];
    if (code == LV_EVENT_CLICKED)
    {
        CrLogI("item_hot_temp_up_event_cb ");
        if (curBedTargetTempVal+BEDEND_PID_TEMP_STEP > BEDEND_PID_TEMP_MAX )
        {
            create_msgbox(FilamentTempTips1[get_cur_language_index()], NULL, 2000, lv_scr_act());
            return ;
        }
        curBedTargetTempVal+=BEDEND_PID_TEMP_STEP;
        sprintf(buf, "%d", curBedTargetTempVal);
        lv_label_set_text(ui_LabelTargetTempVal,buf);
        CrLogI("curBedTargetTempVal = %d",curBedTargetTempVal);
    }
}

/**
 * @description: z轴补偿减按键回调
 * @param  {*}
 * @return {*}
 */
static void item_hot_temp_down_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    char buf[32];
    if (code == LV_EVENT_CLICKED)
    {
        CrLogI("item_hot_temp_down_event_cb ");
        if ( curBedTargetTempVal-BEDEND_PID_TEMP_STEP < BEDEND_PID_TEMP_MIN )
        {
            create_msgbox(FilamentTempTips2[get_cur_language_index()], NULL, 2000, lv_scr_act());
            return ;
        }
        curBedTargetTempVal-=BEDEND_PID_TEMP_STEP;
        sprintf(buf, "%d", curBedTargetTempVal);
        lv_label_set_text(ui_LabelTargetTempVal,buf);
        CrLogI("curBedTargetTempVal = %d",curBedTargetTempVal);
    }
}

/**
 * @description: 准备界面-返回
 * @param  {*}
 * @return {*}
 */
static void item_bedpid_return_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_CLICKED)
    {
        ui_DiapScreenBedPidPage(BED_RETURN);
    }
}
static void ui_ButtonStartCheckPid_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_CLICKED)
    {
        char buf[64]={0};
        snprintf(buf,sizeof(buf),"3%d",curBedTargetTempVal);
        set_printer_data(0x0d,strlen(buf),buf);

        lv_label_set_text_fmt(ui_Label_CheakingTargetTempVal,"%s℃",buf);
        ui_DiapScreenBedPidPage(BED_CHECKING);

        CrLogI("start the HotPIDtest.");
        set_printer_data(0x0d,2,"7");       //启动喷头PID校准
        bedpid_start_flag = true;
        lv_obj_add_state(ui_Button_ReturnCheckingPid,LV_STATE_DISABLED);
    }
}

static void ui_Screen_HitPidPage_Load_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    char buf[32]={0};
    if (code == LV_EVENT_SCREEN_LOADED)
    {   
        sprintf(buf, "%d", curBedTargetTempVal);
        lv_label_set_text(ui_LabelTargetTempVal,buf);
        
    }
}


void ui_ScreenBedPidPage_screen_init(void)
{
    char buf[64];
    uint8_t language_index = get_cur_language_index();

    ui_Screen_BedPidPage = lv_obj_create(ui_ExpertMode);
    lv_obj_clear_flag(ui_Screen_BedPidPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_size(ui_Screen_BedPidPage, 720, 480);
    lv_obj_set_style_bg_color(ui_Screen_BedPidPage, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_Screen_BedPidPage, lv_color_hex(0x00FFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen_BedPidPage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_Screen_BedPidPage, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen_BedPidPage, 150, LV_PART_MAIN | LV_STATE_DEFAULT); // 透明度设置
    lv_obj_align(ui_Screen_BedPidPage,LV_ALIGN_TOP_RIGHT,0,0);
    lv_obj_set_style_border_width(ui_Screen_BedPidPage, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

    // 显示背景框
    lv_obj_t* ui_HotPidBg = lv_obj_create(ui_Screen_BedPidPage);
    lv_obj_set_size(ui_HotPidBg, 696, 456);
    lv_obj_clear_flag(ui_HotPidBg, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_radius(ui_HotPidBg, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_HotPidBg, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_HotPidBg, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_HotPidBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_HotPidBg,LV_ALIGN_CENTER,0,0);
    lv_obj_set_style_pad_all(ui_HotPidBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen_BedPidPrepareLayer = lv_obj_create(ui_Screen_BedPidPage);
    lv_obj_set_size(ui_Screen_BedPidPrepareLayer, 696, 456);
    lv_obj_clear_flag(ui_Screen_BedPidPrepareLayer, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen_BedPidPrepareLayer, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen_BedPidPrepareLayer, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen_BedPidPrepareLayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen_BedPidPrepareLayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_Screen_BedPidPrepareLayer,LV_ALIGN_CENTER,0,0);
    lv_obj_set_style_pad_all(ui_Screen_BedPidPrepareLayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen_bedPidCheakingLayer = lv_obj_create(ui_Screen_BedPidPage);
    lv_obj_set_size(ui_Screen_bedPidCheakingLayer, 696, 456);
    lv_obj_clear_flag(ui_Screen_bedPidCheakingLayer, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen_bedPidCheakingLayer, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen_bedPidCheakingLayer, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen_bedPidCheakingLayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen_bedPidCheakingLayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_Screen_bedPidCheakingLayer,LV_ALIGN_CENTER,0,0);
    lv_obj_set_style_pad_all(ui_Screen_bedPidCheakingLayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen_BedPidFinishLayer = lv_obj_create(ui_Screen_BedPidPage);
    lv_obj_set_size(ui_Screen_BedPidFinishLayer, 696, 456);
    lv_obj_clear_flag(ui_Screen_BedPidFinishLayer, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen_BedPidFinishLayer, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen_BedPidFinishLayer, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen_BedPidFinishLayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen_BedPidFinishLayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_Screen_BedPidFinishLayer,LV_ALIGN_CENTER,0,0);
    lv_obj_set_style_pad_all(ui_Screen_BedPidFinishLayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);


    // 显示标题
    ui_Screen_BedPidTitle = ui_AddLabel(ui_HotPidBg, LV_ALIGN_TOP_LEFT, 150, LV_SIZE_CONTENT, 25, 20,
                                                   BedPidDetect[get_cur_language_index()], 
                                                   lv_font22.font, lv_color_hex(0xFFFFFF), 255);
    // 画线条
    ui_Screen_BedPidLine = ui_DrawStraightLine(ui_HotPidBg, 18, 66, 660, 1, lv_color_hex(0x42BDD8));
    // 显示喷头图标
    ui_ImageBed = lv_img_create(ui_HotPidBg);
    char imgsrc[256] = {0};
    snprintf(imgsrc, 256, "S:%s/%s", GetK1ImageResourcePtah(), "bed.png");
    lv_img_set_src(ui_ImageBed, imgsrc);
    lv_obj_set_size(ui_ImageBed, 48, 48);
    lv_obj_align(ui_ImageBed, LV_ALIGN_TOP_MID, 0, 258);
    lv_obj_add_flag(ui_ImageBed, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageBed, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_CLICKABLE);      /// Flags

    // 显示准备界面提示信息
    ui_Label_BedPidPrepareTip = ui_AddLabel(ui_Screen_BedPidPrepareLayer, LV_ALIGN_TOP_LEFT, 660, LV_SIZE_CONTENT, 32, 90,
                                                   PIDBedCheckPrepareTip[get_cur_language_index()], 
                                                   lv_font25.font, lv_color_hex(0xFFFFFF), 255);

    // 显示加号
    ui_ImageZUpperTemp = lv_img_create(ui_Screen_BedPidPrepareLayer);
    lv_img_set_src(ui_ImageZUpperTemp, &ui_img_add_png);
    lv_obj_set_size(ui_ImageZUpperTemp, 52, 52);
    lv_obj_set_pos(ui_ImageZUpperTemp, 448, 189);
    lv_obj_add_flag(ui_ImageZUpperTemp, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_ImageZUpperTemp, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_event_cb(ui_ImageZUpperTemp, item_hot_temp_up_event_cb, LV_EVENT_CLICKED, ui_ImageZUpperTemp);

    // 显示减号
    ui_ImageZDownTemp = lv_img_create(ui_Screen_BedPidPrepareLayer);
    lv_img_set_src(ui_ImageZDownTemp, &ui_img_sub_png);
    lv_obj_set_size(ui_ImageZDownTemp, 52, 52);
    lv_obj_set_pos(ui_ImageZDownTemp, 196, 189);
    lv_obj_add_flag(ui_ImageZDownTemp, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_ImageZDownTemp, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_event_cb(ui_ImageZDownTemp, item_hot_temp_down_event_cb, LV_EVENT_CLICKED, ui_ImageZUpperTemp);

    //显示温度面板
    ui_PanelTemperValueBedPid = ui_AddPanel_padAllZero(ui_Screen_BedPidPrepareLayer, 146, 54, 275, 188, 
                                                              lv_color_hex(0x3A3D42), 128, lv_color_hex(0x5E6166), 256, 2);
    // 温度显示
    sprintf(buf, "%d", curBedTargetTempVal);
    ui_LabelTargetTempVal = ui_AddLabel(ui_PanelTemperValueBedPid, LV_ALIGN_TOP_LEFT, 62, 30, 34, 4,
                                                   buf, lv_font28.font, lv_color_hex(0xFFFFFF), 255);
    // 温度单位显示
    ui_LabelTargetTempUnit = ui_AddLabel(ui_PanelTemperValueBedPid, LV_ALIGN_TOP_LEFT, 24, 22, 98, 11,
                                                   "°C", lv_font22.font, lv_color_hex(0xFFFFFF), 255);

    sprintf(buf, "%d%s", 121, "°C");
    ui_LabelCurrentTempVal = ui_AddLabel(ui_Screen_BedPidPage, LV_ALIGN_CENTER, 80, 22, 0, 100,
                                                   buf, lv_font22.font, lv_color_hex(0xFFFFFF), 255);
    
    // 开始按键
    ui_ButtonStartCheckPid = ui_AddBtn(ui_Screen_BedPidPrepareLayer, LV_ALIGN_TOP_LEFT, 116, 60, 566, 381, 255, lv_color_hex(0x42BDD8));
    ui_ButtonLabelStartCheckPid = ui_AddLabel(ui_ButtonStartCheckPid, LV_ALIGN_CENTER, 116, 30, 0, 0, 
                                                    Start[language_index], lv_font25.font, lv_color_hex(0xFFFFFF), 255);

    ui_ButtonReturnCheckPid = ui_AddBtn(ui_Screen_BedPidPrepareLayer, LV_ALIGN_TOP_LEFT, 116, 60, 426, 381, 255, lv_color_hex(0x42BDD8));
    ui_ButtonLabelReturnCheckPid = ui_AddLabel(ui_ButtonReturnCheckPid, LV_ALIGN_CENTER, 116, 30, 0, 0, 
                                                    Back[language_index], lv_font25.font, lv_color_hex(0xFFFFFF), 255);

    

    // 显示检测中界面提示信息
    ui_Label_BedPidCheakingTip = ui_AddLabel(ui_Screen_bedPidCheakingLayer, LV_ALIGN_TOP_MID, 331, LV_SIZE_CONTENT, 0, 130,
                                                   PIDBedCheckingTip[get_cur_language_index()], 
                                                   lv_font25.font, lv_color_hex(0xFFFFFF), 255);

    ui_Label_BedPidCheakTimeTip = ui_AddLabel(ui_Screen_bedPidCheakingLayer, LV_ALIGN_TOP_MID, 331, LV_SIZE_CONTENT, 0, 180,
                                                   PIDBedCheckingTimeTip[get_cur_language_index()], 
                                                   lv_font22.font, lv_color_hex(0xFFFFFF), 255);


    // // 显示箭头
    ui_Image_TempIncreaseArrow = lv_img_create(ui_Screen_bedPidCheakingLayer);
    lv_img_set_src(ui_Image_TempIncreaseArrow, &ui_img_filament_to_png);
    lv_obj_set_size(ui_Image_TempIncreaseArrow, LV_SIZE_CONTENT, LV_SIZE_CONTENT);

    lv_obj_align(ui_Image_TempIncreaseArrow, LV_ALIGN_TOP_MID, 0, 324);
    lv_obj_add_flag(ui_Image_TempIncreaseArrow,  LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_Image_TempIncreaseArrow, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    // 温度显示
    sprintf(buf, "%d%s", 12, "°C");
    ui_Label_CheakingCurTempVal = ui_AddLabel(ui_Screen_bedPidCheakingLayer, LV_ALIGN_DEFAULT, LV_SIZE_CONTENT, LV_SIZE_CONTENT, 170, 244,
                                                   buf, lv_font22.font, lv_color_hex(0xFFFFFF), 255); 
    lv_obj_align_to(ui_Label_CheakingCurTempVal, ui_Image_TempIncreaseArrow, LV_ALIGN_OUT_LEFT_MID, -20, 0);

    sprintf(buf, "%d%s", 12, "°C"); 
    ui_Label_CheakingTargetTempVal = ui_AddLabel(ui_Screen_bedPidCheakingLayer, LV_ALIGN_DEFAULT, LV_SIZE_CONTENT, LV_SIZE_CONTENT, 318, 244,
                                                   buf, lv_font22.font, lv_color_hex(0xFFFFFF), 255);
    lv_obj_align_to(ui_Label_CheakingTargetTempVal, ui_Image_TempIncreaseArrow, LV_ALIGN_OUT_RIGHT_MID, 20, 0);

    // 开始按键
    ui_Button_ReturnCheckingPid = ui_AddBtn(ui_Screen_bedPidCheakingLayer, LV_ALIGN_TOP_LEFT, 116, 60, 566, 381, 100, lv_color_hex(0x42BDD8));
    ui_Button_LabelFinishChecking = ui_AddLabel(ui_Button_ReturnCheckingPid, LV_ALIGN_CENTER, 116, 30, 0, 0, 
                                                    Back[language_index], lv_font25.font, lv_color_hex(0xFFFFFF), 100);

    // 显示圆圈
    ui_Image_InProcess = lv_img_create(ui_Screen_bedPidCheakingLayer);
    memset(imgsrc, 0, sizeof(imgsrc));
    snprintf(imgsrc, 256, "S:%s/%s", GetK1ImageResourcePtah(), "wait.png");
    lv_img_set_src(ui_Image_InProcess, imgsrc);
    lv_obj_set_size(ui_Image_InProcess, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_Image_InProcess, LV_ALIGN_TOP_MID, 0, 92);
    // lv_obj_set_pos(ui_Image_InProcess, 243, 10);
    lv_obj_add_flag(ui_Image_InProcess,  LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_Image_InProcess, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    // /******************************************显示检测完成界面提示信息****************************************************/ 

    // 显示打勾
    ui_Image_Finish = lv_img_create(ui_Screen_BedPidFinishLayer);
    lv_img_set_src(ui_Image_Finish, &ui_img_state_normal_png);
    lv_obj_set_size(ui_Image_Finish, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_Image_Finish, LV_ALIGN_TOP_MID, 0, 92);
    lv_obj_add_flag(ui_Image_Finish,  LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_Image_Finish, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_flag(ui_Screen_bedPidCheakingLayer, LV_OBJ_FLAG_HIDDEN);

    ui_Label_BedPidFinishTip = ui_AddLabel(ui_Screen_BedPidFinishLayer, LV_ALIGN_TOP_MID, 331, LV_SIZE_CONTENT, 0, 130,
                                                   PIDBedCheckedTip[get_cur_language_index()], 
                                                   lv_font25.font, lv_color_hex(0xFFFFFF), 255);

    ui_Label_BedPidFinishTip1 = ui_AddLabel(ui_Screen_BedPidFinishLayer, LV_ALIGN_TOP_MID, 211, LV_SIZE_CONTENT, 0, 180,
                                                   PIDBedCheckedTip1[get_cur_language_index()], 
                                                   lv_font22.font, lv_color_hex(0xFFFFFF), 255);

    ui_Button_FinishFinishPid = ui_AddBtn(ui_Screen_BedPidFinishLayer, LV_ALIGN_TOP_LEFT, 116, 60, 566, 381, 255, lv_color_hex(0x42BDD8));
    ui_Button_LabelFinishChecking = ui_AddLabel(ui_Button_FinishFinishPid, LV_ALIGN_CENTER, 116, 30, 0, 0, 
                                                    Back[language_index], lv_font25.font, lv_color_hex(0xFFFFFF), 255);


    lv_obj_add_flag(ui_Screen_BedPidPrepareLayer, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Screen_bedPidCheakingLayer, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Screen_BedPidFinishLayer, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Screen_BedPidPage, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_LabelCurrentTempVal, LV_OBJ_FLAG_HIDDEN);
    // lv_obj_add_flag(ui_LabelCurrentTempVal, LV_OBJ_FLAG_HIDDEN);
    
    /***++++++++++++++++++++++++++++Prompt panel+++++++++++++++++++++++++++++*****/

    lv_obj_add_event_cb(ui_ButtonStartCheckPid, ui_ButtonStartCheckPid_event_cb , LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonReturnCheckPid, item_bedpid_return_event_cb, LV_EVENT_ALL, NULL);


    // lv_obj_add_event_cb(ui_Button_FinishCheckingPid, , LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_Button_ReturnCheckingPid, , LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button_FinishFinishPid, item_bedpid_return_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Screen_BedPidPage, ui_Screen_HitPidPage_Load_event_cb, LV_EVENT_ALL, NULL);

}

void ui_DiapScreenBedPidPage(BedProcess_t process)
{
    switch(process)
    {
        case BED_PREPARE:
            lv_obj_clear_flag(ui_Screen_BedPidPrepareLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_Screen_bedPidCheakingLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_Screen_BedPidFinishLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_LabelCurrentTempVal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_Screen_BedPidPage, LV_OBJ_FLAG_HIDDEN);
            break;
        case BED_CHECKING:
            lv_obj_add_flag(ui_Screen_BedPidPrepareLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_Screen_bedPidCheakingLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_Screen_BedPidFinishLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LabelCurrentTempVal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_Screen_BedPidPage, LV_OBJ_FLAG_HIDDEN);
            break;
        case BED_FINISH:
            lv_obj_add_flag(ui_Screen_BedPidPrepareLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_Screen_bedPidCheakingLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_Screen_BedPidFinishLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LabelCurrentTempVal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_Screen_BedPidPage, LV_OBJ_FLAG_HIDDEN);
            break;
        default:
            lv_obj_add_flag(ui_Screen_BedPidPrepareLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_Screen_bedPidCheakingLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_Screen_BedPidFinishLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LabelCurrentTempVal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_Screen_BedPidPage, LV_OBJ_FLAG_HIDDEN);
            break;
    }
}


//void LoadAxisMoveScreen(void)
void ui_LoadBedPidScreen(void)
{
    //CrLogI("load the axismove page");
    lv_disp_load_scr(ui_Screen_BedPidPage);
    /******************************************************************/
    send_get_fans_status_cmd();
    // send_get_light_status_cmd();
    send_get_axis_home_status_cmd();
    send_get_print_status();

    // get_printer_data(CONTROL_HOT_BED_TEMP, 2, "\0");    //获取温度
    // get_printer_data(CONTROL_XYZ_AXIS_RANGE, 2, "1");    //获取xyz轴的移动范围
    //show_dis_unit();
    // axis_move_set_bed_temper(bed_temper_move, bed_target_temper_move);
    // axis_move_set_hotend_temper(hotend_temper_move, hotend_target_temper_move);
}


void expert_bed_set_bed_temper(int16_t curTemper, int16_t targetTemper)
{
    if(!ui_Screen_BedPidPage)
        return;
    lv_label_set_text_fmt(ui_LabelCurrentTempVal,"%d℃",curTemper);
    lv_label_set_text_fmt(ui_Label_CheakingCurTempVal,"%d",curTemper);
    
}

void refresh_expert_bedpid_page(void)
{
    if(bedpid_start_flag)
    {
        if(bed_cur_temp[0] != '\0')
        {
            char ctemp[10] = {0};
            snprintf(ctemp,10,"%s℃",bed_cur_temp);
            lv_label_set_text(ui_Label_CheakingCurTempVal,ctemp);
        }
        if(bed_max_temp[0] != '\0')
        {
            char ctemp[10] = {0};
            snprintf(ctemp,10,"%s℃",bed_max_temp);
            lv_label_set_text(ui_Label_CheakingTargetTempVal,ctemp);
        }

        if(auto_pid_progress >= 100)
        {
            bedpid_start_flag = false;
            lv_obj_clear_state(ui_Button_ReturnCheckingPid,LV_STATE_DISABLED);
            ui_DiapScreenBedPidPage(BED_FINISH);
        }

    }
}
