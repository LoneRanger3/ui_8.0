/*
 * @Author: Fang JinLun 
 * @Date: 2023-04-19 18:15:23 
 * @Last Modified by: Fang JinLun
 * @Last Modified time: 2023-06-01 20:03:35
 */


#include "ui_Screen_LaserTest.h"
#include "src/core/lv_obj.h"
#include "src/core/lv_obj_pos.h"

static char* startText="开始";
static char* step1Text="步骤1";
static char* step2Text="步骤2";
static char* nextText="下一步";
static char* prevText="上一步";
static char* bedTempText="热床:";
static char* nozzleTempText="喷嘴:";
static char* caliText="标定";
static char* returnText="返回";
static char* laserOepnText="激光开关";

static lv_obj_t* laser_obj;
static lv_obj_t* laser_step1_img;
static lv_obj_t* laser_step1_start_btn;
static lv_obj_t* laser_step1_start_label;
static lv_obj_t* laser_step1_NG_obj;
static lv_obj_t* laser_step2_NG_obj;
static lv_obj_t* laser_nextStep_btn;
static lv_obj_t* laser_nextStep_lable;
static lv_obj_t* laser_step2_img;
static lv_obj_t* laser_step2_start_btn;
static lv_obj_t* laser_step2_start_label;
static lv_obj_t* laser_cali_start_btn;
static lv_obj_t* laser_cali_start_label;
static lv_obj_t* laser_prevStep_btn;
static lv_obj_t* laser_prevStep_lable;
static lv_obj_t* laser_step_label;
static lv_obj_t* hotend_label ;
static lv_obj_t* bed_label ;
static lv_obj_t* hotend_temp_label ;
static lv_obj_t* bed_temp_label ;
static lv_obj_t* return_btn ;
static lv_obj_t* return_label ;
static lv_obj_t* laser_sw_btn;
static lv_obj_t* laser_open_label;
static lv_obj_t* step1_NG_label;
static lv_obj_t* step2_NG_label;
static lv_timer_t* set_image_timer;
//S:/tmp/creality/humbnail/image_file_7.png
static bool laser_open=false;
static char IR_image[512]={0};
static bool set_image_flag=false;

void image_timer(struct lv_timer_t *timer)
{
    if(set_image_flag){
        set_image_flag=false;
        if(laser_obj){
            CrLogI("set IR image %s\n",IR_image);
            if(strstr(IR_image,"LaserIrImage2")){
                lv_img_set_src(laser_step2_img,IR_image);
            }else{
                lv_img_set_src(laser_step1_img,IR_image);
            }
        }
        
    }
}
void refresh_laser_test_temp(int hotend_temp, int bed_temp)
{
    if(!laser_obj){
        return ;
    }
    lv_label_set_text_fmt(hotend_temp_label,"%d°C",hotend_temp);
    lv_label_set_text_fmt(bed_temp_label,"%d°C",bed_temp);
}

void set_step1_image(char* image_path)
{   
    char buf[256]={0};
    // if(laser_obj){
    //     snprintf(buf,sizeof(buf),"%s:%s",PNG_DRV_LETTER,image_path);
    //     CrLogI("set laser step1 image %s\n",buf);
    //     lv_img_set_src(laser_step1_img,buf);
    // }
    snprintf(IR_image,sizeof(IR_image),"%s:%s",PNG_DRV_LETTER,image_path);
    set_image_flag=true;
}
void set_step2_image(char* image_path)
{   
    char buf[256]={0};
    // if(laser_obj){
    //     snprintf(buf,sizeof(buf),"%s:%s",PNG_DRV_LETTER,image_path);
    //     CrLogI("set laser step2 img %s\n",buf);
    //     lv_img_set_src(laser_step2_img,buf);
    // }
    snprintf(IR_image,sizeof(IR_image),"%s:%s",PNG_DRV_LETTER,image_path);
    set_image_flag=true;
}
void set_step1_laser_cali_status(char* status)
{   
    char buf[64]={0};
    if(laser_obj){
        snprintf(buf,sizeof(buf),"%s",status);
        CrLogI("set laser calibration %s\n",buf);
        if(0==strncmp(buf,"OK",2)){
            lv_label_set_text(step1_NG_label,"OK");
            lv_obj_align_to(step1_NG_label,laser_step1_NG_obj,LV_ALIGN_CENTER,0,20);
            lv_obj_set_style_bg_color(laser_step1_NG_obj, lv_color_hex(0x00FF00), LV_PART_MAIN | LV_STATE_DEFAULT);
        }else{
            lv_label_set_text(step1_NG_label,"NG");
            lv_obj_align_to(step1_NG_label,laser_step1_NG_obj,LV_ALIGN_CENTER,0,20);
            lv_obj_set_style_bg_color(laser_step1_NG_obj, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}
void set_step2_laser_cali_status(char* status)
{   
    char buf[64]={0};
    if(laser_obj){
        snprintf(buf,sizeof(buf),"%s",status);
        CrLogI("set laser xy calibration result %s\n",buf);
        if(0==strncmp(buf,"OK",2)){
            lv_label_set_text(step2_NG_label,"OK");
            lv_obj_align_to(step2_NG_label,laser_step2_NG_obj,LV_ALIGN_CENTER,0,20);
            lv_obj_set_style_bg_color(laser_step2_NG_obj, lv_color_hex(0x00FF00), LV_PART_MAIN | LV_STATE_DEFAULT);
        }else{
            lv_label_set_text(step2_NG_label,"NG");
            lv_obj_align_to(step2_NG_label,laser_step2_NG_obj,LV_ALIGN_CENTER,0,20);
            lv_obj_set_style_bg_color(laser_step2_NG_obj, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}
void start_laser_test_step1_cmd(int step)
{   
    DisStartLaserTest(step);
}



static lv_obj_t *add_label(lv_obj_t *parents, char *text, lv_font_t *font, lv_color_t color, lv_align_t align,
                                      lv_obj_t *align_to_obj, lv_coord_t x_ofs, lv_coord_t y_ofs)
{
    lv_obj_t *label = lv_label_create(parents);
    lv_label_set_text(label, text);
    lv_obj_set_style_text_font(label, font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_color(label, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align_to(label, align_to_obj, align, x_ofs, y_ofs);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    return label;
}

static void laser_cali_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        set_printer_data(0x1b, 1, "a");
    }
}

static void laser_nextStep_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(laser_step1_img,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(laser_step2_img,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(laser_nextStep_btn,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(laser_prevStep_btn,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(laser_step1_start_btn,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(laser_step2_start_btn,LV_OBJ_FLAG_HIDDEN);
        lv_label_set_text(laser_step_label,step2Text);
        lv_obj_add_flag(laser_step1_NG_obj,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(laser_step2_NG_obj,LV_OBJ_FLAG_HIDDEN);
        LaserTestAddObjToGroup();
    }
}
static void laser_prevStep_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        lv_obj_add_flag(laser_step2_img,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(laser_step1_img,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(laser_prevStep_btn,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(laser_nextStep_btn,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(laser_step2_start_btn,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(laser_step1_start_btn,LV_OBJ_FLAG_HIDDEN);
        lv_label_set_text(laser_step_label,step1Text);
        lv_obj_clear_flag(laser_step1_NG_obj,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(laser_step2_NG_obj,LV_OBJ_FLAG_HIDDEN);
        LaserTestAddObjToGroup();
    }
}
static void laser_step1Start_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
#ifdef CROSS_COMPILE
        if(system_state.Laser_state == 0)
        {
            create_msgbox(NoLaser[get_cur_language_index()], NULL, 1000 * 1, lv_scr_act());
            return;
        }
#endif 
        CrLogI("laser test step 1 start\n");
        lv_label_set_text(step1_NG_label," ");
        lv_obj_set_style_bg_color(laser_step1_NG_obj, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
        start_laser_test_step1_cmd(1);
    }
}
static void laser_step2Start_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
#ifdef CROSS_COMPILE
        if(system_state.Laser_state == 0)
        {
            create_msgbox(NoLaser[get_cur_language_index()], NULL, 1000 * 1, lv_scr_act());
            return;
        }
#endif
        CrLogI("laser test step 2 start\n");
        start_laser_test_step1_cmd(2);
    }
}

static void return_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        CrLogI("return\n");
        if(laser_obj){
            laser_open=false;
            lv_timer_del(set_image_timer);
            set_image_timer=NULL;
            CrLogI("laser test close laser\n");
            start_laser_test_step1_cmd(4);
            lv_obj_del_async(laser_obj);
            laser_obj=NULL;
            LoadMachinetestScreen();
        }
    }
}

static void laser_open_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
#ifdef CROSS_COMPILE
        if(system_state.Laser_state == 0)
        {
            create_msgbox(NoLaser[get_cur_language_index()], NULL, 1000 * 1, lv_scr_act());
            return;
        }
#endif
        if(!laser_open){
            laser_open=true;
            CrLogI("laser test open laser\n");
            start_laser_test_step1_cmd(3);
        }else{
            laser_open=false;
            CrLogI("laser test close laser\n");
            start_laser_test_step1_cmd(4);
        }    
    }
}


void ui_laser_test_init(lv_obj_t* parents) 
{
    CrLogI("ui_laser_test_init\n");

    get_printer_data(CONTROL_MACHINE_STATE, 2, "a");    //获取轮廓仪状态

    laser_obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(laser_obj, 640, 360);
    lv_obj_set_pos(laser_obj, 0, 60);
    lv_obj_clear_flag(laser_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(laser_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(laser_obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(laser_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(laser_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(laser_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);  
    //第一步抓拍的IR图片
    laser_step1_img = lv_img_create(laser_obj);
    lv_obj_set_size(laser_step1_img,800,600);
    lv_obj_clear_flag(laser_step1_img, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(laser_step1_img, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(laser_step1_img, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(laser_step1_img, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(laser_step1_img, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(laser_step1_img, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(laser_step1_img, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(laser_step1_img, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align_to(laser_step1_img,laser_obj,LV_ALIGN_CENTER,0,0);
    //第二步抓拍的IR图片
    laser_step2_img = lv_img_create(laser_obj);
    lv_obj_set_size(laser_step2_img,800,600);
    lv_obj_clear_flag(laser_step2_img, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(laser_step2_img, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(laser_step2_img, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(laser_step2_img, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(laser_step2_img, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(laser_step2_img, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(laser_step2_img, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(laser_step2_img, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align_to(laser_step2_img,laser_obj,LV_ALIGN_CENTER,0,0);
    lv_obj_add_flag(laser_step2_img,LV_OBJ_FLAG_HIDDEN);

    //下一步按钮
    laser_nextStep_btn = lv_btn_create(laser_obj);
    lv_obj_set_size(laser_nextStep_btn, 130, 50);
    lv_obj_align_to(laser_nextStep_btn, laser_obj, LV_ALIGN_BOTTOM_RIGHT, -10, -40);
    lv_obj_add_flag(laser_nextStep_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(laser_nextStep_btn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(laser_nextStep_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(laser_nextStep_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(laser_nextStep_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(laser_nextStep_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(laser_nextStep_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(laser_nextStep_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(laser_nextStep_btn, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(laser_nextStep_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(laser_nextStep_btn, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(laser_nextStep_btn, lv_color_hex(0xB0F1FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_opa(laser_nextStep_btn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(laser_nextStep_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(laser_nextStep_btn, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_spread(laser_nextStep_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(laser_nextStep_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(laser_nextStep_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(laser_nextStep_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    laser_nextStep_lable = add_label(laser_nextStep_btn, nextText, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, laser_nextStep_btn, 0, 0);
    //上一步按钮
    laser_prevStep_btn = lv_btn_create(laser_obj);
    lv_obj_set_size(laser_prevStep_btn, 130, 50);
    lv_obj_align_to(laser_prevStep_btn, laser_obj, LV_ALIGN_RIGHT_MID, -10, 30);
    lv_obj_add_flag(laser_prevStep_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(laser_prevStep_btn, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_radius(laser_prevStep_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(laser_prevStep_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(laser_prevStep_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(laser_prevStep_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(laser_prevStep_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(laser_prevStep_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(laser_prevStep_btn, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(laser_prevStep_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(laser_prevStep_btn, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(laser_prevStep_btn, lv_color_hex(0xB0F1FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_opa(laser_prevStep_btn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(laser_prevStep_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(laser_prevStep_btn, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_spread(laser_prevStep_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(laser_prevStep_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(laser_prevStep_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(laser_prevStep_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    
    laser_prevStep_lable = add_label(laser_prevStep_btn, prevText, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, laser_prevStep_btn, 0, 0);
    lv_obj_add_flag(laser_prevStep_btn,LV_OBJ_FLAG_HIDDEN);

    //第一步开始按钮
    laser_step1_start_btn = lv_btn_create(laser_obj);
    lv_obj_set_size(laser_step1_start_btn, 130, 50);
    lv_obj_align_to(laser_step1_start_btn, laser_obj, LV_ALIGN_BOTTOM_MID, -80, -40);
    lv_obj_add_flag(laser_step1_start_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_set_style_radius(laser_step1_start_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(laser_step1_start_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(laser_step1_start_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(laser_step1_start_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(laser_step1_start_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(laser_step1_start_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(laser_step1_start_btn, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(laser_step1_start_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(laser_step1_start_btn, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(laser_step1_start_btn, lv_color_hex(0xB0F1FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_opa(laser_step1_start_btn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(laser_step1_start_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(laser_step1_start_btn, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_spread(laser_step1_start_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(laser_step1_start_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(laser_step1_start_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(laser_step1_start_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    
    laser_step1_start_label = add_label(laser_step1_start_btn, startText, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, laser_step1_start_btn, 0, 0);
    
    //第二步开始按钮
    laser_step2_start_btn = lv_btn_create(laser_obj);
    lv_obj_set_size(laser_step2_start_btn, 130, 50);
    lv_obj_align_to(laser_step2_start_btn, laser_obj, LV_ALIGN_BOTTOM_MID, -80, -40);
    lv_obj_add_flag(laser_step2_start_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_set_style_radius(laser_step2_start_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(laser_step2_start_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(laser_step2_start_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(laser_step2_start_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(laser_step2_start_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(laser_step2_start_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(laser_step2_start_btn, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(laser_step2_start_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(laser_step2_start_btn, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(laser_step2_start_btn, lv_color_hex(0xB0F1FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_opa(laser_step2_start_btn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(laser_step2_start_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(laser_step2_start_btn, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_spread(laser_step2_start_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(laser_step2_start_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(laser_step2_start_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(laser_step2_start_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    laser_step2_start_label = add_label(laser_step2_start_btn, startText, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, laser_step2_start_btn, 0, 0);

    laser_step_label = add_label(laser_obj, step1Text, lv_font25.font, lv_color_white(),
                                    LV_ALIGN_BOTTOM_MID, laser_obj, -100, -140);
    lv_obj_add_flag(laser_step2_start_btn,LV_OBJ_FLAG_HIDDEN);

    
    
    //标定按钮
    // laser_cali_start_btn = lv_btn_create(laser_obj);
    // lv_obj_set_size(laser_cali_start_btn, 130, 50);
    // lv_obj_align_to(laser_cali_start_btn, laser_obj, LV_ALIGN_BOTTOM_MID, 160, -60);
    // lv_obj_add_flag(laser_cali_start_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    // lv_obj_set_style_radius(laser_cali_start_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(laser_cali_start_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(laser_cali_start_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_width(laser_cali_start_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_shadow_spread(laser_cali_start_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_side(laser_cali_start_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_color(laser_cali_start_btn, lv_color_hex(0x4190A2),
    //                               LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_opa(laser_cali_start_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_border_width(laser_cali_start_btn, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    // laser_cali_start_label = add_label(laser_cali_start_btn, caliText, lv_font25.font, lv_color_white(),
    //                                     LV_ALIGN_CENTER, laser_cali_start_btn, 0, 0);

    //返回按钮
    return_btn = lv_btn_create(laser_obj);
    lv_obj_set_size(return_btn, 130, 50);
    lv_obj_align_to(return_btn, laser_obj, LV_ALIGN_LEFT_MID, 10, 30);
    lv_obj_add_flag(return_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_set_style_radius(return_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(return_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(return_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(return_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(return_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(return_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(return_btn, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(return_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(return_btn, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(return_btn, lv_color_hex(0xB0F1FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_opa(return_btn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(return_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(return_btn, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_spread(return_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(return_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(return_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(return_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    return_label = add_label(return_btn, returnText, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, return_btn, 0, 0);

    //激光开关
    laser_sw_btn = lv_btn_create(laser_obj);
    lv_obj_set_size(laser_sw_btn, 130, 50);
    lv_obj_align_to(laser_sw_btn, laser_obj, LV_ALIGN_RIGHT_MID, -170, 30);
    lv_obj_add_flag(laser_sw_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_set_style_radius(laser_sw_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(laser_sw_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(laser_sw_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(laser_sw_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(laser_sw_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(laser_sw_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(laser_sw_btn, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(laser_sw_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(laser_sw_btn, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(laser_sw_btn, lv_color_hex(0xB0F1FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_opa(laser_sw_btn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(laser_sw_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(laser_sw_btn, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_spread(laser_sw_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(laser_sw_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(laser_sw_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(laser_sw_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    laser_open_label = add_label(laser_sw_btn, laserOepnText, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, laser_sw_btn, 0, 0);

    lv_obj_add_event_cb(laser_nextStep_btn,laser_nextStep_btn_event_cb,LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(laser_prevStep_btn,laser_prevStep_btn_event_cb,LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(laser_step1_start_btn,laser_step1Start_btn_event_cb,LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(laser_step2_start_btn,laser_step2Start_btn_event_cb,LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(return_btn,return_btn_event_cb,LV_EVENT_CLICKED,NULL);
    lv_obj_add_event_cb(laser_sw_btn,laser_open_btn_event_cb,LV_EVENT_CLICKED,NULL);


    hotend_label = add_label(laser_obj, nozzleTempText, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_BOTTOM_LEFT, laser_obj, 10, -60);
    bed_label = add_label(laser_obj, bedTempText, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_OUT_BOTTOM_MID, hotend_label, 0, 10);
    hotend_temp_label = add_label(laser_obj, "0°C", lv_font25.font, lv_color_hex(0x42BDD8),
                                        LV_ALIGN_OUT_RIGHT_MID, hotend_label, 15, 0);
    bed_temp_label = add_label(laser_obj, "0°C", lv_font25.font, lv_color_hex(0x3DE4AA),
                                        LV_ALIGN_OUT_RIGHT_MID, bed_label, 15, 0);

    laser_step1_NG_obj = lv_obj_create(laser_obj);
    lv_obj_set_size(laser_step1_NG_obj,80,80);
    lv_obj_clear_flag(laser_step1_NG_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(laser_step1_NG_obj, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(laser_step1_NG_obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(laser_step1_NG_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(laser_step1_NG_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(laser_step1_NG_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_align_to(laser_step1_NG_obj,laser_sw_btn,LV_ALIGN_OUT_BOTTOM_MID,0,20); 
    step1_NG_label = add_label(laser_step1_NG_obj, " ", lv_font28.font, lv_color_white(),
                                        LV_ALIGN_CENTER, laser_step1_NG_obj, 0, 20);
    lv_obj_set_size(step1_NG_label,80,80);     

    laser_step2_NG_obj = lv_obj_create(laser_obj);
    lv_obj_set_size(laser_step2_NG_obj,80,80);
    lv_obj_clear_flag(laser_step2_NG_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(laser_step2_NG_obj, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(laser_step2_NG_obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(laser_step2_NG_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(laser_step2_NG_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(laser_step2_NG_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT); 
    lv_obj_align_to(laser_step2_NG_obj,laser_sw_btn,LV_ALIGN_OUT_BOTTOM_MID,0,20); 
    step2_NG_label = add_label(laser_step2_NG_obj, " ", lv_font28.font, lv_color_white(),
                                        LV_ALIGN_CENTER, laser_step2_NG_obj, 0, 20);
    lv_obj_set_size(step2_NG_label,80,80);     
                                    
    lv_obj_add_flag(laser_step2_NG_obj,LV_OBJ_FLAG_HIDDEN);
    set_image_timer = lv_timer_create(image_timer,200,NULL);
    set_image_flag=false;
}

void LaserTestAddObjToGroup(void)
{
    lv_group_add_obj(encoder_group, return_btn);
    lv_group_add_obj(encoder_group, laser_sw_btn);
    if (!lv_obj_has_flag(laser_step1_start_btn, LV_OBJ_FLAG_HIDDEN))
    {
        lv_group_add_obj(encoder_group, laser_step1_start_btn);
    }
    if (!lv_obj_has_flag(laser_step2_start_btn, LV_OBJ_FLAG_HIDDEN))
    {
        lv_group_add_obj(encoder_group, laser_step2_start_btn);
    }
    if (!lv_obj_has_flag(laser_nextStep_btn, LV_OBJ_FLAG_HIDDEN))
    {
        lv_group_add_obj(encoder_group, laser_nextStep_btn);
    }
    if (!lv_obj_has_flag(laser_prevStep_btn, LV_OBJ_FLAG_HIDDEN))
    {
        lv_group_add_obj(encoder_group, laser_prevStep_btn);
    }
}