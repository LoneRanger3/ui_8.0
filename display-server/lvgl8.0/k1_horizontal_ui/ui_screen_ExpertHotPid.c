#include "ui_screen_ExpertHotPid.h"
#include <stdio.h>
#include "../custom/lvgl_cmd.h"
#include "mult_language.h"
#include "ui_screen_HomeNormal.h"
#include "ui_screen_FileManage.h"
#include "ui_custom_messagebox.h"
#include "ui_custom_reminderbox.h"

#define HOTEND_PID_TEMP_STEP    10//温度加减的值
#define HOTEND_PID_TEMP_MAX     300//PID设定最大温度
#define HOTEND_PID_TEMP_MIN     180//PID设定最小温度
/********axis Move Page***********/
static lv_obj_t * ui_Screen_HotPidPage;
static lv_obj_t * ui_Screen_HotPidTitle;   // 标题

static lv_obj_t * ui_LabelHoyPidCurVal;

static lv_obj_t* ui_Screen_HotPidLine;         // 线条
static lv_obj_t * ui_Imagehotend;       // 加热图标
static lv_obj_t * ui_ImageZUpperTemp;   // + 符号
static lv_obj_t * ui_ImageZDownTemp;    // - 符号

/********准备界面***********/
static lv_obj_t * ui_Screen_HotPidPrepareLayer;     // 准备图层
static lv_obj_t * ui_Label_HotPidPrepareTip;        // 准备提示
static lv_obj_t * ui_ButtonStartCheckPid;           // "启动"按键
static lv_obj_t * ui_ButtonLabelStartCheckPid;      // "启动"按键
static lv_obj_t * ui_ButtonReturnCheckPid;          // "返回"按键
static lv_obj_t * ui_ButtonLabelReturnCheckPid;     // "返回"按键
static lv_obj_t * ui_PanelTemperValueHotePid;       
static lv_obj_t * ui_LabelTargetTempVal;
static lv_obj_t * ui_LabelTargetTempUnit;
static lv_obj_t * ui_LabelCurrentTempVal;

/********pid调节中界面***********/
static lv_obj_t * ui_Screen_HotPidCheakingLayer;    // pid检测中图层
static lv_obj_t * ui_Label_HotPidCheakingTip;       // 检查中提示
static lv_obj_t * ui_Label_HotPidCheakTimeTip;      // 检查中提示
static lv_obj_t * ui_Image_TempIncreaseArrow;       // 温度升高箭头
static lv_obj_t * ui_Label_CheakingTargetTempVal;   // 检测中目标温度
static lv_obj_t * ui_Label_CheakingCurTempVal;      // 检测中当前温度
static lv_obj_t * ui_Button_FinishCheckingPid;      // 结束检测按键
static lv_obj_t * ui_Button_LabelFinishChecking;    // 结束检测按键文字
static lv_obj_t * ui_Button_ReturnCheckingPid;      // 返回按键
static lv_obj_t * ui_Button_LabelReturnChecking;    // 返回按键文字
static lv_obj_t * ui_Image_InProcess;               // 进行中图标


/********pid完成中界面***********/
static lv_obj_t * ui_Screen_HotPidFinishLayer;      //  pid检测完成图层
static lv_obj_t * ui_Label_HotPidFinishTip;       // 检查中提示
static lv_obj_t * ui_Label_HotPidFinishTip1;      // 检查中提示
static lv_obj_t * ui_Button_FinishFinishPid;      // 结束检测按键
static lv_obj_t * ui_Image_Finish;      // 结束检测按键



static bool hotpid_start_flag = false;
// void ui_DiapScreenTrafficPage(HotProcess_t process);

int curTargetTempVal = 240;    // 记录当前温度

// 画直线
/*
x：线的起点
y：线的终点
width：线宽
height：线长
color：线颜色
*/
lv_obj_t * ui_HotPidDrawStraightLine(lv_obj_t * parent, uint16_t x, uint16_t y, uint16_t width, uint16_t height, lv_color_t color)
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
lv_obj_t *  ui_HotPidAddLabel(lv_obj_t * parent, lv_align_t align, uint16_t size_x, uint16_t size_y, uint16_t pos_x, uint16_t pos_y,
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
lv_obj_t *  ui_HotPidAddPanel_padAllZero(lv_obj_t * parent, uint16_t size_x, uint16_t size_y, uint16_t pos_x, uint16_t pos_y,
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

lv_obj_t *  ui_HotPidAddBtn(lv_obj_t * parent, lv_align_t align, uint16_t size_x, uint16_t size_y, uint16_t pos_x, uint16_t pos_y,
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
    lv_obj_t *parents = lv_event_get_user_data(e);
    char buf[32];
    if (code == LV_EVENT_CLICKED)
    {
        CrLogI("item_hot_temp_up_event_cb ");
        if (curTargetTempVal+HOTEND_PID_TEMP_STEP > HOTEND_PID_TEMP_MAX )
        {
            create_msgbox(FilamentTempTips1[get_cur_language_index()], NULL, 2000, lv_scr_act());
            return ;
        }
        curTargetTempVal+=HOTEND_PID_TEMP_STEP;
        sprintf(buf, "%d", curTargetTempVal);
        lv_label_set_text(ui_LabelTargetTempVal,buf);
        CrLogI("curTargetTempVal = %d",curTargetTempVal);
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
    lv_obj_t *parents = lv_event_get_user_data(e);
    char buf[32];
    if (code == LV_EVENT_CLICKED)
    {
        CrLogI("item_hot_temp_down_event_cb ");
        if ( curTargetTempVal-HOTEND_PID_TEMP_STEP < HOTEND_PID_TEMP_MIN )
        {
            create_msgbox(FilamentTempTips2[get_cur_language_index()], NULL, 2000, lv_scr_act());
            return ;
        }
        curTargetTempVal-=HOTEND_PID_TEMP_STEP;
        sprintf(buf, "%d", curTargetTempVal);
        lv_label_set_text(ui_LabelTargetTempVal,buf);
        CrLogI("curTargetTempVal = %d",curTargetTempVal);
    }
}

/**
 * @description: 准备界面-返回
 * @param  {*}
 * @return {*}
 */
static void item_prepare_return_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        ui_DiapScreenHotPidPage(HOT_RETURN);
        
    }
}
static void ui_ButtonStartCheckPid_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        char buf[64]={0};
        snprintf(buf,sizeof(buf),"1%d",curTargetTempVal);
        set_printer_data(0x0d,strlen(buf),buf);

        lv_label_set_text_fmt(ui_Label_CheakingTargetTempVal,"%s℃",buf);
        ui_DiapScreenHotPidPage(HOT_CHECKING);

        CrLogI("start the HotPIDtest.");
        set_printer_data(0x0d,2,"5");       //启动喷头PID校准
        hotpid_start_flag = true;
        lv_obj_add_state(ui_Button_ReturnCheckingPid,LV_STATE_DISABLED);
    }
}

static void ui_Screen_HitPidPage_Load_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);
    char buf[32]={0};
    if (code == LV_EVENT_SCREEN_LOADED)
    {   
        sprintf(buf, "%d", curTargetTempVal);
        lv_label_set_text(ui_LabelTargetTempVal,buf);
        
    }
}


void ui_ScreenHotPidPage_screen_init(void)
{
    char buf[64];
    uint8_t language_index = get_cur_language_index();

    ui_Screen_HotPidPage = lv_obj_create(ui_ExpertMode);
    lv_obj_clear_flag(ui_Screen_HotPidPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_size(ui_Screen_HotPidPage, 720, 480);
    lv_obj_set_style_bg_color(ui_Screen_HotPidPage, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen_HotPidPage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_Screen_HotPidPage, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen_HotPidPage, 150, LV_PART_MAIN | LV_STATE_DEFAULT); // 透明度设置
    lv_obj_align(ui_Screen_HotPidPage,LV_ALIGN_TOP_RIGHT,0,0);
    lv_obj_set_style_border_width(ui_Screen_HotPidPage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // 显示背景框
    lv_obj_t* ui_HotPidBg = lv_obj_create(ui_Screen_HotPidPage);
    lv_obj_set_size(ui_HotPidBg, 696, 456);
    lv_obj_clear_flag(ui_HotPidBg, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_radius(ui_HotPidBg, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_HotPidBg, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_HotPidBg, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_HotPidBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_HotPidBg,LV_ALIGN_CENTER,0,0);
    lv_obj_set_style_pad_all(ui_HotPidBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen_HotPidPrepareLayer = lv_obj_create(ui_Screen_HotPidPage);
    lv_obj_set_size(ui_Screen_HotPidPrepareLayer, 696, 456);
    lv_obj_clear_flag(ui_Screen_HotPidPrepareLayer, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen_HotPidPrepareLayer, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen_HotPidPrepareLayer, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen_HotPidPrepareLayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen_HotPidPrepareLayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_Screen_HotPidPrepareLayer,LV_ALIGN_CENTER,0,0);
    lv_obj_set_style_pad_all(ui_Screen_HotPidPrepareLayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen_HotPidCheakingLayer = lv_obj_create(ui_Screen_HotPidPage);
    lv_obj_set_size(ui_Screen_HotPidCheakingLayer, 696, 456);
    lv_obj_clear_flag(ui_Screen_HotPidCheakingLayer, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen_HotPidCheakingLayer, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen_HotPidCheakingLayer, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen_HotPidCheakingLayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen_HotPidCheakingLayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_Screen_HotPidCheakingLayer,LV_ALIGN_CENTER,0,0);
    lv_obj_set_style_pad_all(ui_Screen_HotPidCheakingLayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Screen_HotPidFinishLayer = lv_obj_create(ui_Screen_HotPidPage);
    lv_obj_set_size(ui_Screen_HotPidFinishLayer, 696, 456);
    lv_obj_clear_flag(ui_Screen_HotPidFinishLayer, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_radius(ui_Screen_HotPidFinishLayer, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Screen_HotPidFinishLayer, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen_HotPidFinishLayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen_HotPidFinishLayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_Screen_HotPidFinishLayer,LV_ALIGN_CENTER,0,0);
    lv_obj_set_style_pad_all(ui_Screen_HotPidFinishLayer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);


    // 显示标题
    ui_Screen_HotPidTitle = ui_HotPidAddLabel(ui_HotPidBg, LV_ALIGN_TOP_LEFT, 150, LV_SIZE_CONTENT, 25, 20,
                                                   NozzlePidDetect[get_cur_language_index()], 
                                                   lv_font22.font, lv_color_hex(0xFFFFFF), 255);
    // 画线条
    ui_Screen_HotPidLine = ui_HotPidDrawStraightLine(ui_HotPidBg, 18, 66, 660, 1, lv_color_hex(0x42BDD8));
    // 显示喷头图标
    ui_Imagehotend = lv_img_create(ui_HotPidBg);
    char imgsrc[256] = {0};
    snprintf(imgsrc, 256, "S:%s/%s", GetK1ImageResourcePtah(), "nuzzle.png");
    lv_img_set_src(ui_Imagehotend, imgsrc);
    lv_obj_set_size(ui_Imagehotend, 48, 48);
    lv_obj_align(ui_Imagehotend, LV_ALIGN_TOP_MID, 0, 258);
    lv_obj_add_flag(ui_Imagehotend, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Imagehotend, LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_CLICKABLE);      /// Flags

    // 显示准备界面提示信息
    ui_Label_HotPidPrepareTip = ui_HotPidAddLabel(ui_Screen_HotPidPrepareLayer, LV_ALIGN_TOP_LEFT, 660, LV_SIZE_CONTENT, 32, 90,
                                                   PIDNozzleCheckPrepareTip[get_cur_language_index()], 
                                                   lv_font25.font, lv_color_hex(0xFFFFFF), 255);

    // 显示加号
    ui_ImageZUpperTemp = lv_img_create(ui_Screen_HotPidPrepareLayer);
    lv_img_set_src(ui_ImageZUpperTemp, &ui_img_add_png);
    lv_obj_set_size(ui_ImageZUpperTemp, 52, 52);
    lv_obj_set_pos(ui_ImageZUpperTemp, 448, 189);
    lv_obj_add_flag(ui_ImageZUpperTemp, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_ImageZUpperTemp, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_event_cb(ui_ImageZUpperTemp, item_hot_temp_up_event_cb, LV_EVENT_CLICKED, ui_ImageZUpperTemp);

    // 显示减号
    ui_ImageZDownTemp = lv_img_create(ui_Screen_HotPidPrepareLayer);
    lv_img_set_src(ui_ImageZDownTemp, &ui_img_sub_png);
    lv_obj_set_size(ui_ImageZDownTemp, 52, 52);
    lv_obj_set_pos(ui_ImageZDownTemp, 196, 189);
    lv_obj_add_flag(ui_ImageZDownTemp, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_ImageZDownTemp, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_event_cb(ui_ImageZDownTemp, item_hot_temp_down_event_cb, LV_EVENT_CLICKED, ui_ImageZUpperTemp);

    //显示温度面板
    ui_PanelTemperValueHotePid = ui_HotPidAddPanel_padAllZero(ui_Screen_HotPidPrepareLayer, 146, 54, 275, 188, 
                                                              lv_color_hex(0x3A3D42), 128, lv_color_hex(0x5E6166), 256, 2);
    // 温度显示
    sprintf(buf, "%d", curTargetTempVal);
    ui_LabelTargetTempVal = ui_HotPidAddLabel(ui_PanelTemperValueHotePid, LV_ALIGN_TOP_LEFT, 62, 30, 34, 4,
                                                   buf, lv_font28.font, lv_color_hex(0xFFFFFF), 255);
    // 温度单位显示
    ui_LabelTargetTempUnit = ui_HotPidAddLabel(ui_PanelTemperValueHotePid, LV_ALIGN_TOP_LEFT, 24, 22, 98, 11,
                                                   "°C", lv_font22.font, lv_color_hex(0xFFFFFF), 255);

    sprintf(buf, "%d%s", 121, "°C");
    ui_LabelCurrentTempVal = ui_HotPidAddLabel(ui_Screen_HotPidPage, LV_ALIGN_CENTER, 80, 22, 0, 100,
                                                   buf, lv_font22.font, lv_color_hex(0xFFFFFF), 255);
    
    // 开始按键
    ui_ButtonStartCheckPid = ui_HotPidAddBtn(ui_Screen_HotPidPrepareLayer, LV_ALIGN_TOP_LEFT, 116, 60, 566, 381, 255, lv_color_hex(0x42BDD8));
    ui_ButtonLabelStartCheckPid = ui_HotPidAddLabel(ui_ButtonStartCheckPid, LV_ALIGN_CENTER, 116, 30, 0, 0, 
                                                    Start[language_index], lv_font25.font, lv_color_hex(0xFFFFFF), 255);

    ui_ButtonReturnCheckPid = ui_HotPidAddBtn(ui_Screen_HotPidPrepareLayer, LV_ALIGN_TOP_LEFT, 116, 60, 426, 381, 255, lv_color_hex(0x42BDD8));
    ui_ButtonLabelReturnCheckPid = ui_HotPidAddLabel(ui_ButtonReturnCheckPid, LV_ALIGN_CENTER, 116, 30, 0, 0, 
                                                    Back[language_index], lv_font25.font, lv_color_hex(0xFFFFFF), 255);

    



    // 显示检测中界面提示信息
    ui_Label_HotPidCheakingTip = ui_HotPidAddLabel(ui_Screen_HotPidCheakingLayer, LV_ALIGN_TOP_MID, 331, LV_SIZE_CONTENT, 0, 130,
                                                   PIDNozzleCheckingTip[get_cur_language_index()], 
                                                   lv_font25.font, lv_color_hex(0xFFFFFF), 255);

    ui_Label_HotPidCheakTimeTip = ui_HotPidAddLabel(ui_Screen_HotPidCheakingLayer, LV_ALIGN_TOP_MID, 211, LV_SIZE_CONTENT, 0, 180,
                                                   PIDNozzleCheckingTimeTip[get_cur_language_index()], 
                                                   lv_font22.font, lv_color_hex(0xFFFFFF), 255);


    // // 显示箭头
    ui_Image_TempIncreaseArrow = lv_img_create(ui_Screen_HotPidCheakingLayer);
    lv_img_set_src(ui_Image_TempIncreaseArrow, &ui_img_filament_to_png);
    lv_obj_set_size(ui_Image_TempIncreaseArrow, LV_SIZE_CONTENT, LV_SIZE_CONTENT);

    lv_obj_align(ui_Image_TempIncreaseArrow, LV_ALIGN_TOP_MID, 0, 324);
    lv_obj_add_flag(ui_Image_TempIncreaseArrow,  LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_Image_TempIncreaseArrow, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    // 温度显示
    sprintf(buf, "%d%s", 112, "°C");
    ui_Label_CheakingCurTempVal = ui_HotPidAddLabel(ui_Screen_HotPidCheakingLayer, LV_ALIGN_DEFAULT, LV_SIZE_CONTENT, LV_SIZE_CONTENT, 170, 244,
                                                   buf, lv_font22.font, lv_color_hex(0xFFFFFF), 255); 
    lv_obj_align_to(ui_Label_CheakingCurTempVal, ui_Image_TempIncreaseArrow, LV_ALIGN_OUT_LEFT_MID, -20, 0);

    sprintf(buf, "%d%s", 121, "°C"); 
    ui_Label_CheakingTargetTempVal = ui_HotPidAddLabel(ui_Screen_HotPidCheakingLayer, LV_ALIGN_DEFAULT, LV_SIZE_CONTENT, LV_SIZE_CONTENT, 318, 244,
                                                   buf, lv_font22.font, lv_color_hex(0xFFFFFF), 255);
    lv_obj_align_to(ui_Label_CheakingTargetTempVal, ui_Image_TempIncreaseArrow, LV_ALIGN_OUT_RIGHT_MID, 20, 0);

    // 返回按键
    ui_Button_ReturnCheckingPid = ui_HotPidAddBtn(ui_Screen_HotPidCheakingLayer, LV_ALIGN_TOP_LEFT, 116, 60, 566, 381, 100, lv_color_hex(0x42BDD8));
    ui_Button_LabelFinishChecking = ui_HotPidAddLabel(ui_Button_ReturnCheckingPid, LV_ALIGN_CENTER, 116, 30, 0, 0, 
                                                    Back[language_index], lv_font25.font, lv_color_hex(0xFFFFFF), 100);

    // 显示圆圈
    ui_Image_InProcess = lv_img_create(ui_Screen_HotPidCheakingLayer);
    memset(imgsrc, 0, sizeof(imgsrc));
    snprintf(imgsrc, 256, "S:%s/%s", GetK1ImageResourcePtah(), "wait.png");
    lv_img_set_src(ui_Image_InProcess, imgsrc);
    lv_obj_set_size(ui_Image_InProcess, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_Image_InProcess, LV_ALIGN_TOP_MID, 0, 92);
    lv_obj_add_flag(ui_Image_InProcess,  LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_Image_InProcess, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLLABLE);      /// Flags



    /******************************************显示检测完成界面提示信息****************************************************/ 
    // 显示打勾
    ui_Image_Finish = lv_img_create(ui_Screen_HotPidFinishLayer);
    lv_img_set_src(ui_Image_Finish, &ui_img_state_normal_png);
    lv_obj_set_size(ui_Image_Finish, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_align(ui_Image_Finish, LV_ALIGN_TOP_MID, 0, 92);
    lv_obj_add_flag(ui_Image_Finish,  LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_Image_Finish, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label_HotPidFinishTip = ui_HotPidAddLabel(ui_Screen_HotPidFinishLayer, LV_ALIGN_TOP_MID, 331, LV_SIZE_CONTENT, 0, 130,
                                                   PIDNozzleCheckedTip[get_cur_language_index()], 
                                                   lv_font25.font, lv_color_hex(0xFFFFFF), 255);

    ui_Label_HotPidFinishTip1 = ui_HotPidAddLabel(ui_Screen_HotPidFinishLayer, LV_ALIGN_TOP_MID, 211, LV_SIZE_CONTENT, 0, 180,
                                                   PIDNozzleCheckedTip1[get_cur_language_index()], 
                                                   lv_font22.font, lv_color_hex(0xFFFFFF), 255);

    ui_Button_FinishFinishPid = ui_HotPidAddBtn(ui_Screen_HotPidFinishLayer, LV_ALIGN_TOP_LEFT, 116, 60, 566, 381, 255, lv_color_hex(0x42BDD8));
    ui_Button_LabelFinishChecking = ui_HotPidAddLabel(ui_Button_FinishFinishPid, LV_ALIGN_CENTER, 116, 30, 0, 0, 
                                                    Back[language_index], lv_font25.font, lv_color_hex(0xFFFFFF), 255);

    lv_obj_add_flag(ui_Screen_HotPidPrepareLayer, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Screen_HotPidCheakingLayer, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Screen_HotPidFinishLayer, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_LabelCurrentTempVal, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_Screen_HotPidPage, LV_OBJ_FLAG_HIDDEN);
    
    /***++++++++++++++++++++++++++++Prompt panel+++++++++++++++++++++++++++++*****/

    lv_obj_add_event_cb(ui_ButtonStartCheckPid, ui_ButtonStartCheckPid_event_cb , LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ButtonReturnCheckPid, item_prepare_return_event_cb, LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_Button_FinishCheckingPid, , LV_EVENT_ALL, NULL);
    // lv_obj_add_event_cb(ui_Button_ReturnCheckingPid, , LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button_FinishFinishPid, item_prepare_return_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Screen_HotPidPage, ui_Screen_HitPidPage_Load_event_cb, LV_EVENT_ALL, NULL);

}

void ui_DiapScreenHotPidPage(HotProcess_t process)
{
    switch(process)
    {
        case HOT_PREPARE:
            lv_obj_clear_flag(ui_Screen_HotPidPrepareLayer,LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_Screen_HotPidCheakingLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_Screen_HotPidFinishLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_LabelCurrentTempVal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_Screen_HotPidPage, LV_OBJ_FLAG_HIDDEN);
            break;
        case HOT_CHECKING:
            lv_obj_add_flag(ui_Screen_HotPidPrepareLayer,LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_Screen_HotPidCheakingLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_Screen_HotPidFinishLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LabelCurrentTempVal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_Screen_HotPidPage, LV_OBJ_FLAG_HIDDEN);
            break;
        case HOT_FINISH:
            lv_obj_add_flag(ui_Screen_HotPidPrepareLayer,LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_Screen_HotPidCheakingLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_Screen_HotPidFinishLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LabelCurrentTempVal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_Screen_HotPidPage, LV_OBJ_FLAG_HIDDEN);
            break;
        default:
            lv_obj_add_flag(ui_Screen_HotPidPrepareLayer,LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_Screen_HotPidCheakingLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_Screen_HotPidFinishLayer, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_LabelCurrentTempVal, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_Screen_HotPidPage, LV_OBJ_FLAG_HIDDEN);
            break;
    }
}

//void LoadAxisMoveScreen(void)
void ui_LoadHotPidScreen(void)
{
    //CrLogI("load the axismove page");
    lv_disp_load_scr(ui_Screen_HotPidPage);
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


void expert_hot_set_hotend_temper(int16_t curTemper, int16_t targetTemper)
{
    if(!ui_Screen_HotPidPage)
        return;
    lv_label_set_text_fmt(ui_LabelCurrentTempVal,"%d℃",curTemper);
    lv_label_set_text_fmt(ui_Label_CheakingCurTempVal,"%d",curTemper);
    
}

void refresh_expert_hotpid_page(void)
{
    if(hotpid_start_flag)
    {
        uint8_t language_index = get_cur_language_index();
        if(hotend_cur_temp[0] != '\0')
        {
            char ctemp[10] = {0};
            snprintf(ctemp,10,"%s℃",hotend_cur_temp);
            lv_label_set_text(ui_Label_CheakingCurTempVal,ctemp);
        }
        if(hotend_max_temp[0] != '\0')
        {
            char ctemp[10] = {0};
            snprintf(ctemp,10,"%s℃",hotend_max_temp);
            lv_label_set_text(ui_Label_CheakingTargetTempVal,ctemp);
        }

        if(auto_pid_progress >= 100)
        {
            hotpid_start_flag = false;
            lv_obj_clear_state(ui_Button_ReturnCheckingPid,LV_STATE_DISABLED);
            ui_DiapScreenHotPidPage(HOT_FINISH);
        }
    }
}





