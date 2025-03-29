#include "ui_screen_ExpertTraffic.h"
#include <stdio.h>
#include "../custom/lvgl_cmd.h"
#include "mult_language.h"
#include "ui_screen_HomeNormal.h"
#include "ui_screen_FileManage.h"
#include "ui_custom_messagebox.h"
#include "ui_custom_reminderbox.h"



/********axis Move Page***********/
static lv_obj_t * ui_Screen_TrafficPage;

static lv_obj_t * ui_Screen_TrafficTitle;   // 标题

static lv_obj_t * ui_LabelTrafficCurVal;




// checkbox
static lv_obj_t * ui_TrafficCheckbox[5];
static lv_obj_t * ui_TrafficCheckboxBg[5];
static uint32_t checkbox_index = 0;
static lv_obj_t * ui_VerLineX[4];


static lv_obj_t * ui_ImageUpperTraffic;
static lv_obj_t * ui_ImageDownTraffic;


int curTrafficVal = 0;    // 记录当前流量值
int TrafficStepGear = 0;   // 记录当前流量步档位
int TrafficGear[3] = {5, 1, 1};
// 画直线
/*
x：线的起点
y：线的终点
width：线宽
height：线长
color：线颜色
*/
void ui_TrafficDrawStraightLine(lv_obj_t * parent, lv_obj_t * line, uint16_t x, uint16_t y, uint16_t width, uint16_t height, lv_color_t color)
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
lv_obj_t * ui_AddTrafficCheckbox(lv_obj_t * parent, uint16_t x, uint16_t y, const char * txt)
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

lv_obj_t * ui_AddTrafficCheckboxBg(lv_obj_t * parent)
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
void ui_TrafficAddLabel(lv_obj_t * parent, lv_obj_t * label, uint16_t size_x, uint16_t size_y, const char * txt, lv_font_t * font, lv_color_t color)
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

static void traffic_mode_checkbox_event_handler(lv_event_t * e)
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

    // CrLogI("Selected radio buttons: %d\n", (int)checkbox_index);

    lv_obj_add_flag(lv_obj_get_child(old_cb,0), LV_OBJ_FLAG_HIDDEN);   /*Uncheck the previous radio button*/
    lv_obj_clear_flag(lv_obj_get_child(act_cb,0), LV_OBJ_FLAG_HIDDEN); 
    // lv_obj_set_user_data

    TrafficStepGear = checkbox_index;
}

void ExpertTrafficAdd(lv_event_t * e)
{
    int traffic = curTrafficVal + TrafficGear[TrafficStepGear]; //get_offset_z_unit_value();
    CrLogI("ExpertTrafficAdd offset_z = %d !!\n", traffic);
    send_set_print_flow_cmd(traffic);
}

void ExpertTrafficSub(lv_event_t * e)
{
    int traffic = curTrafficVal - TrafficGear[TrafficStepGear];//get_offset_z_unit_value();
    if (traffic < 0) 
        traffic = 0;
    CrLogI("ExpertTrafficSub traffic = %f !!\n", traffic);
    send_set_print_flow_cmd(traffic);
}

void expert_send_traffic_to_dsip(void)
{
    char buff[10] = {0};
    sprintf(buff, "%d%%", curTrafficVal);
    if(ui_LabelTrafficCurVal != NULL)
        lv_label_set_text(ui_LabelTrafficCurVal, buff);
}

void expert_set_traffic_percent(int traffic)
{
    curTrafficVal = traffic;
    CrLogI("expert_set_traffic_percent traffic = %d !!\n", traffic);

    expert_send_traffic_to_dsip();
}

/**
 * @description: z轴补偿增加按键回调
 * @param  {*}
 * @return {*}
 */
static void item_traffic_up_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);
    char buf[32];
    if (code == LV_EVENT_CLICKED)
    {
        CrLogI("item_traffic_up_event_cb \n");

        ExpertTrafficAdd(e);
        get_printer_data(0x16,1,"\0");  //获取流量
    }
}

/**
 * @description: z轴补偿减按键回调
 * @param  {*}
 * @return {*}
 */
static void item_traffic_down_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);
    char buf[32];
    if (code == LV_EVENT_CLICKED)
    {
        CrLogI("item_traffic_down_event_cb \n");

        ExpertTrafficSub(e);
        get_printer_data(0x16,1,"\0");  //获取流量

    }
}

void traffic_return_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);
    if (code == LV_EVENT_CLICKED)
    {
        ui_HideScreenTrafficPage();
    }
}

void ui_ScreenTrafficPage_screen_init(void)
{
    char buf[64];

    ui_Screen_TrafficPage = lv_obj_create(lv_layer_top());
    lv_obj_set_size(ui_Screen_TrafficPage, 800, 480);
    lv_obj_clear_flag(ui_Screen_TrafficPage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen_TrafficPage, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen_TrafficPage, LV_OPA_80, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_blend_mode(ui_Screen_TrafficPage, LV_BLEND_MODE_NORMAL, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(ui_Screen_TrafficPage, traffic_return_event_cb, LV_EVENT_CLICKED, ui_Screen_TrafficPage);
    lv_obj_set_style_border_width(ui_Screen_TrafficPage, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // 显示背景框
    lv_obj_t* ui_ZoffsetBg = lv_obj_create(ui_Screen_TrafficPage);
    lv_obj_set_width(ui_ZoffsetBg, 405);
    lv_obj_set_height(ui_ZoffsetBg, 438);
    lv_obj_clear_flag(ui_ZoffsetBg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ZoffsetBg, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ZoffsetBg, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ZoffsetBg, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ZoffsetBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_add_event_cb(ui_ZoffsetBg, traffic_mode_checkbox_event_handler, LV_EVENT_CLICKED, &checkbox_index);
    lv_obj_align(ui_ZoffsetBg,LV_ALIGN_CENTER,0,0);
    

    // 显示标题
    // ui_TrafficAddLabel(ui_ZoffsetBg, ui_Screen_TrafficTitle, );

    ui_Screen_TrafficTitle = lv_label_create(ui_ZoffsetBg);
    lv_obj_set_width(ui_Screen_TrafficTitle, 100);
    lv_obj_set_height(ui_Screen_TrafficTitle, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_Screen_TrafficTitle, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Screen_TrafficTitle, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_label_set_long_mode(ui_Screen_TrafficTitle, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_Screen_TrafficTitle, Flow[get_cur_language_index()]);     //冷却
    lv_obj_set_style_text_color(ui_Screen_TrafficTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Screen_TrafficTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Screen_TrafficTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Screen_TrafficTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    

    // 给checkbox 和画线 作的一个obj
    lv_obj_t* ui_checkboxBg = lv_obj_create(ui_ZoffsetBg);
    lv_obj_set_size(ui_checkboxBg, 130, 380);
    lv_obj_set_pos(ui_checkboxBg, 10, 10);
    lv_obj_set_style_radius(ui_checkboxBg, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_checkboxBg, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_event_cb(ui_checkboxBg, traffic_mode_checkbox_event_handler, LV_EVENT_CLICKED, &checkbox_index);
    lv_obj_set_style_border_width(ui_checkboxBg, 0, LV_PART_MAIN);              // 设置线宽
    lv_obj_set_style_bg_opa(ui_checkboxBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT); // 透明度设置
    // checkbox 
    for (int i = 0; i < 2; i++)
    {
        memset(buf, 0, sizeof(buf));
        snprintf(buf, 64, "%d%c", TrafficGear[i], '%');

        ui_TrafficCheckbox[i] = ui_AddTrafficCheckbox(ui_checkboxBg, 0, 102 + 104*i, buf);
        ui_TrafficCheckboxBg[i] = ui_AddTrafficCheckboxBg(ui_TrafficCheckbox[i]);
    } 

    lv_obj_add_state(ui_TrafficCheckbox[0], LV_STATE_CHECKED);     /*Uncheck the current radio button*/
    lv_obj_clear_flag(ui_TrafficCheckboxBg[0], LV_OBJ_FLAG_HIDDEN);   /*Uncheck the previous radio button*/
    
    // 画线
    for (int i = 0; i < 1; i++)
    {
        ui_TrafficDrawStraightLine(ui_checkboxBg, ui_VerLineX[i], 13, 130 + 105*i, 2, 76, lv_color_hex(0x9B9FA5));
    }


    // 显示箭头上
    ui_ImageUpperTraffic = lv_img_create(ui_ZoffsetBg);
    char imgsrc[256] = {0};
    memset(imgsrc, 0, sizeof(imgsrc));
    snprintf(imgsrc, 256, "S:%s/%s", GetK1ImageResourcePtah(), "Add.png");
    lv_img_set_src(ui_ImageUpperTraffic, imgsrc);
    lv_obj_set_size(ui_ImageUpperTraffic, 96, 68);
    lv_obj_set_pos(ui_ImageUpperTraffic, 240, 90);
    lv_obj_add_flag(ui_ImageUpperTraffic, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_ImageUpperTraffic, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_event_cb(ui_ImageUpperTraffic, item_traffic_up_event_cb, LV_EVENT_CLICKED, ui_ImageUpperTraffic);
    
    // 显示箭头下
    ui_ImageDownTraffic = lv_img_create(ui_ZoffsetBg);
    memset(imgsrc, 0, sizeof(imgsrc));
    snprintf(imgsrc, 256, "S:%s/%s", GetK1ImageResourcePtah(), "Subtract.png");
    lv_img_set_src(ui_ImageDownTraffic, imgsrc);
    lv_obj_set_size(ui_ImageDownTraffic, 96, 68);
    lv_obj_set_pos(ui_ImageDownTraffic, 240, 240);
    lv_obj_add_flag(ui_ImageDownTraffic, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_ImageDownTraffic, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_event_cb(ui_ImageDownTraffic, item_traffic_down_event_cb, LV_EVENT_CLICKED, ui_ImageUpperTraffic);


    // 显示Z轴补偿当前值
    memset(buf, 0, sizeof(buf));
    snprintf(buf, 64, "%d", curTrafficVal);
    ui_LabelTrafficCurVal = lv_label_create(ui_ZoffsetBg);
    lv_obj_set_width(ui_LabelTrafficCurVal, 100);
    lv_obj_set_height(ui_LabelTrafficCurVal, LV_SIZE_CONTENT);
    lv_obj_set_align(ui_LabelTrafficCurVal, LV_ALIGN_TOP_MID);
    lv_obj_set_pos(ui_LabelTrafficCurVal, 110, 185);
    lv_obj_clear_flag(ui_LabelTrafficCurVal, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_label_set_long_mode(ui_LabelTrafficCurVal, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelTrafficCurVal, buf);     //冷却
    lv_obj_set_style_text_color(ui_LabelTrafficCurVal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTrafficCurVal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTrafficCurVal, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTrafficCurVal, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);


    lv_obj_add_flag(ui_Screen_TrafficPage, LV_OBJ_FLAG_HIDDEN);
    

}

void ui_DiapScreenTrafficPage(void)
{
    lv_obj_clear_flag(ui_Screen_TrafficPage, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(lv_layer_top(),LV_OBJ_FLAG_CLICKABLE);
    get_printer_data(0x16,1,"\0");  //获取流量
}

void ui_HideScreenTrafficPage(void)
{
    lv_obj_add_flag(ui_Screen_TrafficPage, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(lv_layer_top(),LV_OBJ_FLAG_CLICKABLE);
}

//void LoadAxisMoveScreen(void)
void ui_LoadTrafficScreen(void)
{
    //CrLogI("load the axismove page");
    lv_disp_load_scr(ui_Screen_TrafficPage);
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









