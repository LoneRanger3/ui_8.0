/*
 * @Author: Fang JinLun 
 * @Date: 2023-06-01 20:00:14 
 * @Last Modified by: Fang JinLun
 * @Last Modified time: 2023-06-08 16:18:18
 */

#include "ui_Screen_MachineMcuVersion.h"
#include "src/core/lv_obj_pos.h"

#define MCU_VERSION_CMD "cat tmp/.mcu_version | jq"

static char* return_text="返回";

static lv_obj_t *m_version_obj;
static lv_obj_t *mcu0_label;
static lv_obj_t *bed0_label;
static lv_obj_t *noz0_label;
static lv_obj_t *laser_label;
static lv_obj_t *mcu0_ver_label;
static lv_obj_t *bed0_ver_label;
static lv_obj_t *noz0_ver_label;
static lv_obj_t *laser_ver_label;
static lv_obj_t *return_label;
static lv_obj_t *return_btn;

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
static void inquire_laser_version(void)
{
    DisStartLaserTest(9);
}
void set_laser_version_label(char* ver)
{
    if(!m_version_obj || !ver)
        return;
    CrLogI("laser version=%s\n",ver);
    lv_label_set_text_fmt(laser_ver_label,"%s",ver);
}


static void inquire_mcu_version(void)
{
    char resBuf[1024]={0};
    if(!m_version_obj)
        return;

    if (!PopenSystem(MCU_VERSION_CMD, resBuf, sizeof(resBuf))){
        CrLogW("cmd mcu_version fail !!\n");
        return;
    }
    json_object * versionObj= json_tokener_parse(resBuf);
    if(versionObj){
       json_object* mcuObj= json_object_object_get(versionObj,"mcu0");
       if(mcuObj){
            char* mcuVerStr={0};
            json_object* mcuVerObj= json_object_object_get(mcuObj,"version");
            mcuVerStr = json_object_get_string(mcuVerObj);
            if(mcuVerStr){
                CrLogI("mcu0 version=%s\n",mcuVerStr);
                lv_label_set_text_fmt(mcu0_ver_label,"%s",mcuVerStr);
            }
            
       }
       json_object* bedObj= json_object_object_get(versionObj,"bed0");
       if(bedObj){
            char* bedVerStr={0};
            json_object* bedVerObj= json_object_object_get(bedObj,"version");
            bedVerStr = json_object_get_string(bedVerObj);
            if(bedVerStr){
                CrLogI("bed0 version=%s\n",bedVerStr);
                lv_label_set_text_fmt(bed0_ver_label,"%s",bedVerStr);
            }
            
       }
       json_object* nozObj= json_object_object_get(versionObj,"noz0");
       if(nozObj){
            char* nozVerStr={0};
            json_object* nozVerObj= json_object_object_get(nozObj,"version");
            nozVerStr = json_object_get_string(nozVerObj);
            if(nozVerStr){
                CrLogI("noz0 version=%s\n",nozVerStr);
                lv_label_set_text_fmt(noz0_ver_label,"%s",nozVerStr);
            }
       }
    }
}

static void return_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        CrLogI("return\n");
        if(m_version_obj){
            lv_obj_del_async(m_version_obj);
            m_version_obj=NULL;
            LoadMachinetestScreen();
        }
    }
}


void ui_machine_mcu_version_init(lv_obj_t* parents) 
{
    CrLogI("ui_machine_mcu_version_init\n");

    get_printer_data(CONTROL_MACHINE_STATE, 2, "a");    //获取轮廓仪状态

    m_version_obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(m_version_obj, 640, 360);
    lv_obj_set_pos(m_version_obj, 0, 60);
    lv_obj_clear_flag(m_version_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(m_version_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(m_version_obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(m_version_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(m_version_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(m_version_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);  

    mcu0_label = add_label(m_version_obj,"mcu0版本:",lv_font25.font,lv_color_white(),LV_ALIGN_CENTER,m_version_obj,-210,-80);
    bed0_label = add_label(m_version_obj,"bed0版本:",lv_font25.font,lv_color_white(),LV_ALIGN_OUT_BOTTOM_MID,mcu0_label,0,40);
    noz0_label = add_label(m_version_obj,"noz0版本:",lv_font25.font,lv_color_white(),LV_ALIGN_OUT_BOTTOM_MID,bed0_label,0,40);
    laser_label = add_label(m_version_obj,"激光版本:",lv_font25.font,lv_color_white(),LV_ALIGN_OUT_BOTTOM_MID,noz0_label,0,40);

    mcu0_ver_label = add_label(m_version_obj," ",lv_font25.font,lv_color_white(),LV_ALIGN_OUT_RIGHT_MID,mcu0_label,10,0);
    lv_obj_set_size(mcu0_ver_label,450,50);
    bed0_ver_label = add_label(m_version_obj," ",lv_font25.font,lv_color_white(),LV_ALIGN_OUT_RIGHT_MID,bed0_label,10,0);
    lv_obj_set_size(bed0_ver_label,450,50);
    noz0_ver_label = add_label(m_version_obj," ",lv_font25.font,lv_color_white(),LV_ALIGN_OUT_RIGHT_MID,noz0_label,10,0);
    lv_obj_set_size(noz0_ver_label,450,50);
    laser_ver_label = add_label(m_version_obj," ",lv_font25.font,lv_color_white(),LV_ALIGN_OUT_RIGHT_MID,laser_label,10,0);
    lv_obj_set_size(laser_ver_label,450,50);

    //返回按钮
    return_btn = lv_btn_create(m_version_obj);
    lv_obj_set_size(return_btn, 130, 50);
    lv_obj_align_to(return_btn, m_version_obj, LV_ALIGN_TOP_LEFT, 20, 20);
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

    return_label = add_label(return_btn, return_text, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, return_btn, 0, 0);

    lv_obj_add_event_cb(return_btn,return_btn_event_cb,LV_EVENT_CLICKED,NULL);
    
    inquire_laser_version();
    inquire_mcu_version();
    
}


void MachineMcuVersionAddObjToGroup(void)
{
    lv_group_add_obj(encoder_group, return_btn);
}