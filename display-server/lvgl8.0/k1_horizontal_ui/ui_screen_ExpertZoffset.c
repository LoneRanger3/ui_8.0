#include "ui_screen_ExpertZoffset.h"
#include <stdio.h>
#include "../custom/lvgl_cmd.h"
#include "mult_language.h"
#include "ui_screen_HomeNormal.h"
#include "ui_screen_FileManage.h"
#include "ui_custom_messagebox.h"
#include "ui_custom_reminderbox.h"



/********axis Move Page***********/
static lv_obj_t * ui_Screen_ZoffsetPage;
static lv_obj_t * ui_ZoffsetBg;
static lv_obj_t * ui_Screen_ZoffsetTitle;   // 标题

static lv_obj_t * ui_LabelZoffsetCurVal;




// checkbox
static lv_obj_t * ui_ZoffsetCheckbox[5];
static lv_obj_t * ui_ZoffsetCheckboxBg[5];
static uint32_t checkbox_index = 0;
static lv_obj_t * ui_VerLineX[4];


static lv_obj_t * ui_ImageZUpperZffset;
static lv_obj_t * ui_ImageZDownZffset;


double curZoffsetVal = 0;    // 记录当前z轴补偿值
int zoffsetStepGear = 0;   // 记录当前z轴补偿步档位
static float zoffsetGear[5] = {0.1, 0.05, 0.01, 0.005, 0.001};
// 画直线
/*
x：线的起点
y：线的终点
width：线宽
height：线长
color：线颜色
*/
static void ui_DrawStraightLine(lv_obj_t * parent, lv_obj_t * line, uint16_t x, uint16_t y, uint16_t width, uint16_t height, lv_color_t color)
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
parent              父对象
x                   x坐标          
y                   y坐标
txt                 显示文本
*/
lv_obj_t * ui_AddZoffsetCheckbox(lv_obj_t * parent, uint16_t x, uint16_t y, const char * txt)
{
    lv_obj_t * Checkbox = lv_checkbox_create(parent);
    lv_obj_set_pos(Checkbox,x,y);
    lv_obj_add_flag(Checkbox, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_set_style_radius(Checkbox, LV_RADIUS_CIRCLE, LV_PART_INDICATOR);
    lv_checkbox_set_text(Checkbox, txt);
    lv_obj_set_style_text_font(Checkbox, lv_font18.font,LV_PART_MAIN);
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
lv_obj_t * ui_AddZoffsetCheckboxBg(lv_obj_t * parent)
{
    lv_obj_t * CheckboxPointBg = lv_obj_create(parent);
    lv_obj_set_style_radius(CheckboxPointBg, LV_RADIUS_CIRCLE, LV_PART_INDICATOR);
    lv_obj_set_style_border_width(CheckboxPointBg,0,LV_PART_MAIN);
    lv_obj_set_size(CheckboxPointBg, 12, 12);
    lv_obj_set_pos(CheckboxPointBg, 8, 8);
    lv_obj_set_style_bg_color(CheckboxPointBg, lv_color_hex(0x42BDD8), LV_PART_MAIN);
    lv_obj_add_flag(CheckboxPointBg,LV_OBJ_FLAG_HIDDEN);

    return CheckboxPointBg;
}


/* 
parent              父对象
Checkbox            checkbox对象
CheckboxPointBg     圆圈内实心点对象
x                   x坐标          
y                   y坐标
txt                 显示文本
*/
void ui_AddLabel(lv_obj_t * parent, lv_obj_t * label, uint16_t size_x, uint16_t size_y, const char * txt, lv_font_t * font, lv_color_t color)
{
    label = lv_label_create(parent);
    lv_obj_set_size(label, size_x, size_y);
    lv_obj_set_width(label, 240);
    lv_obj_set_height(label, LV_SIZE_CONTENT);
    lv_obj_set_align(label, LV_ALIGN_CENTER);
    //lv_label_set_long_mode(ui_LabelMoveAndTemperTitle, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(label, txt);
    //lv_label_set_recolor(ui_LabelMoveAndTemperTitle, "true");
    lv_obj_set_style_text_color(label, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(label, font, LV_PART_MAIN | LV_STATE_DEFAULT);
}

static void zoffset_mode_checkbox_event_handler(lv_event_t * e)
{
    uint32_t * active_id = lv_event_get_user_data(e);
    lv_obj_t * cont = lv_event_get_current_target(e);
    lv_obj_t * act_cb = lv_event_get_target(e);
    lv_obj_t * old_cb = lv_obj_get_child(cont, *active_id);

    /*Do nothing if the container was clicked*/
    if(act_cb == cont) return;
    
    lv_obj_clear_state(old_cb, LV_STATE_CHECKED);   /*Uncheck the previous radio button*/
    lv_obj_add_state(act_cb, LV_STATE_CHECKED);     /*Uncheck the current radio button*/

    *active_id = lv_obj_get_index(act_cb);

    printf("Selected radio buttons: %d\n", (int)checkbox_index);

    lv_obj_add_flag(lv_obj_get_child(old_cb,0), LV_OBJ_FLAG_HIDDEN);   /*Uncheck the previous radio button*/
    lv_obj_clear_flag(lv_obj_get_child(act_cb,0), LV_OBJ_FLAG_HIDDEN); 
    // lv_obj_set_user_data

    zoffsetStepGear = checkbox_index;
}

void ExpertOffsetAdd(lv_event_t * e)
{
    float offset_z = zoffsetGear[zoffsetStepGear]; //get_offset_z_unit_value();
    printf("ExpertOffsetAdd offset_z = %f !!\n", offset_z);
    send_set_z_offset_cmd(offset_z);
}

void ExpertOffsetSub(lv_event_t * e)
{
    float offset_z = 0 - zoffsetGear[zoffsetStepGear];//get_offset_z_unit_value();
    printf("ExpertOffsetSub offset_z = %f !!\n", offset_z);
    send_set_z_offset_cmd(offset_z);
}

void expert_send_zoffset_to_dsip(void)
{
    char buff[10] = {0};
    sprintf(buff, "%.2f", curZoffsetVal);
    if(ui_LabelZoffsetCurVal != NULL)
        lv_label_set_text(ui_LabelZoffsetCurVal, buff);
}

void expert_set_offset_z(double offset_z)
{
    curZoffsetVal = offset_z;
    printf("expert_set_offset_z offset_z = %f !!\n", offset_z);
    // is_lastest_offset_z = true;
    expert_send_zoffset_to_dsip();
}

/**
 * @description: z轴补偿增加按键回调
 * @param  {*}
 * @return {*}
 */
static void item_zoffset_up_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);
    char buf[32];
    if (code == LV_EVENT_CLICKED)
    {
        printf("item_zoffset_up_event_cb \n");

        ExpertOffsetAdd(e);
    }
}

/**
 * @description: z轴补偿减按键回调
 * @param  {*}
 * @return {*}
 */
static void item_zoffset_down_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);
    char buf[32];
    if (code == LV_EVENT_CLICKED)
    {
        printf("item_zoffset_down_event_cb \n");

        ExpertOffsetSub(e);
    }
}

void zoffset_return_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);
    if (code == LV_EVENT_CLICKED)
    {
        ui_HideScreenZoffsetPage();
    }
}


void ui_ScreenZoffsetPage_screen_init(void)
{
    char buf[64];

    ui_Screen_ZoffsetPage = lv_obj_create(lv_layer_top());
    lv_obj_set_size(ui_Screen_ZoffsetPage, 800, 480);
    lv_obj_clear_flag(ui_Screen_ZoffsetPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen_ZoffsetPage, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen_ZoffsetPage, LV_OPA_80, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_Screen_ZoffsetPage, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Screen_ZoffsetPage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(ui_Screen_ZoffsetPage, zoffset_return_event_cb, LV_EVENT_CLICKED, ui_Screen_ZoffsetPage);

    // 显示背景框
    ui_ZoffsetBg = lv_obj_create(ui_Screen_ZoffsetPage);
    lv_obj_set_width(ui_ZoffsetBg, 405);
    lv_obj_set_height(ui_ZoffsetBg, 438);
    lv_obj_clear_flag(ui_ZoffsetBg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ZoffsetBg, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ZoffsetBg, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ZoffsetBg, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ZoffsetBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_ZoffsetBg,LV_ALIGN_CENTER,0,0);

    // 显示标题
    // ui_AddLabel(ui_ZoffsetBg, ui_Screen_ZoffsetTitle, );

    ui_Screen_ZoffsetTitle = lv_label_create(ui_ZoffsetBg);
    lv_obj_set_width(ui_Screen_ZoffsetTitle, 100);
    lv_obj_set_height(ui_Screen_ZoffsetTitle, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_Screen_ZoffsetTitle, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Screen_ZoffsetTitle, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_label_set_long_mode(ui_Screen_ZoffsetTitle, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_Screen_ZoffsetTitle, Zoffset[get_cur_language_index()]);     //冷却
    lv_obj_set_style_text_color(ui_Screen_ZoffsetTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen_ZoffsetTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Screen_ZoffsetTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen_ZoffsetTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    // 给checkbox 和画线 作的一个obj
    lv_obj_t* ui_checkboxBg = lv_obj_create(ui_ZoffsetBg);
    lv_obj_set_size(ui_checkboxBg, 130, 380);
    lv_obj_set_pos(ui_checkboxBg, 10, 10);
    lv_obj_set_style_radius(ui_checkboxBg, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_checkboxBg, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_event_cb(ui_checkboxBg, zoffset_mode_checkbox_event_handler, LV_EVENT_CLICKED, &checkbox_index);
    lv_obj_set_style_border_width(ui_checkboxBg, 0, LV_PART_MAIN);              // 设置线宽
    lv_obj_set_style_bg_opa(ui_checkboxBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT); // 透明度设置
    // checkbox 
    for (int i = 0; i < 5; i++)
    {
        memset(buf, 0, sizeof(buf));
        CrLogI("number:%d",sizeof(buf));
        if (i == 0)
            snprintf(buf, 64, "%.1f", zoffsetGear[i]);
        else if (i <= 2)
            snprintf(buf, 64, "%.2f", zoffsetGear[i]);
        else 
            snprintf(buf, 64, "%.3f", zoffsetGear[i]);

        ui_ZoffsetCheckbox[i] = ui_AddZoffsetCheckbox(ui_checkboxBg, 0, 75*i, buf);
        ui_ZoffsetCheckboxBg[i] = ui_AddZoffsetCheckboxBg(ui_ZoffsetCheckbox[i]);
    } 

    lv_obj_add_state(ui_ZoffsetCheckbox[0], LV_STATE_CHECKED);     /*Uncheck the current radio button*/
    lv_obj_clear_flag(ui_ZoffsetCheckboxBg[0], LV_OBJ_FLAG_HIDDEN);   /*Uncheck the previous radio button*/
    
    // 画线
    for (int i = 0; i < 4; i++)
    {
        // ui_DrawStraightLine(ui_checkboxBg, ui_VerLineX[i], 52, 73 + 75*i, 2, 48, lv_color_hex(0x9B9FA5));
        ui_DrawStraightLine(ui_checkboxBg, ui_VerLineX[i], 13, 28 + 75*i, 2, 48, lv_color_hex(0x9B9FA5));
    }


    // 显示箭头上
    ui_ImageZUpperZffset = lv_img_create(ui_ZoffsetBg);
    char imgsrc[256] = {0};
    memset(imgsrc, 0, sizeof(imgsrc));
    snprintf(imgsrc, 256, "S:%s/%s", GetK1ImageResourcePtah(), "Add.png");
    lv_img_set_src(ui_ImageZUpperZffset, imgsrc);
    lv_obj_set_size(ui_ImageZUpperZffset, 96, 68);
    lv_obj_set_pos(ui_ImageZUpperZffset, 240, 90);
    lv_obj_add_flag(ui_ImageZUpperZffset, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_ImageZUpperZffset, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_event_cb(ui_ImageZUpperZffset, item_zoffset_up_event_cb, LV_EVENT_CLICKED, ui_ImageZUpperZffset);
    
    // 显示箭头下
    ui_ImageZDownZffset = lv_img_create(ui_ZoffsetBg);
    memset(imgsrc, 0, sizeof(imgsrc));
    snprintf(imgsrc, 256, "S:%s/%s", GetK1ImageResourcePtah(), "Subtract.png");
    lv_img_set_src(ui_ImageZDownZffset, imgsrc);
    lv_obj_set_size(ui_ImageZDownZffset, 96, 68);
    lv_obj_set_pos(ui_ImageZDownZffset, 240, 240);
    lv_obj_add_flag(ui_ImageZDownZffset, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_ImageZDownZffset, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_event_cb(ui_ImageZDownZffset, item_zoffset_down_event_cb, LV_EVENT_CLICKED, ui_ImageZUpperZffset);


    // 显示Z轴补偿当前值
    memset(buf, 0, sizeof(buf));
    snprintf(buf, 64, "%.3f", curZoffsetVal);
    ui_LabelZoffsetCurVal = lv_label_create(ui_ZoffsetBg);
    lv_obj_set_width(ui_LabelZoffsetCurVal, 100);
    lv_obj_set_height(ui_LabelZoffsetCurVal, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_LabelZoffsetCurVal, LV_ALIGN_TOP_MID);
    lv_obj_set_pos(ui_LabelZoffsetCurVal, 110, 185);
    lv_obj_clear_flag(ui_LabelZoffsetCurVal, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_label_set_long_mode(ui_LabelZoffsetCurVal, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelZoffsetCurVal, buf);     //冷却
    lv_obj_set_style_text_color(ui_LabelZoffsetCurVal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelZoffsetCurVal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelZoffsetCurVal, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelZoffsetCurVal, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_flag(ui_Screen_ZoffsetPage, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(lv_layer_top(),LV_OBJ_FLAG_CLICKABLE);
    get_printer_data(0x02,1,"\0");  //获取Z轴补偿
}

void ui_DiapScreenZoffsetPage(void)
{
    lv_obj_clear_flag(ui_Screen_ZoffsetPage, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(lv_layer_top(),LV_OBJ_FLAG_CLICKABLE);
    get_printer_data(0x02,1,"\0");  //获取Z轴补偿
}

void ui_HideScreenZoffsetPage(void)
{
    lv_obj_add_flag(ui_Screen_ZoffsetPage, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(lv_layer_top(),LV_OBJ_FLAG_CLICKABLE);
}

void ui_LoadZoffsetScreen(void)
{
    //CrLogI("load the axismove page");
    lv_disp_load_scr(ui_Screen_ZoffsetPage);
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









