/*
 * @Date: 2023-08-16 19:46:52
 * @LastEditors: fangjinlun fangjinlun@creality.com
 * @LastEditTime: 2023-08-17 16:24:07
 */
#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "./custom/CrlogDef.h"
#include "ui_screen_CameraList.h"
#include "custom/lvgl_cmd.h"
#include "ui_Screen_BedMeshAdjust.h"
#include "ui_screen_ExpertTraffic.h"
#include "mult_language.h"

#define MAX_PROBE_POINT      49
#define BED_MESH_CONT_SIZE   390
///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_BedMeshBg;
lv_obj_t * ui_BedMeshIcon;
lv_obj_t * ui_BedMeshPageImage1;
lv_obj_t * ui_BedMeshPageImage2;
lv_obj_t * ui_BedMeshPageImage3;
lv_obj_t * ui_BedMeshPageImage4;
lv_obj_t * ui_BedMeshPageImage5;
lv_obj_t * ui_BedMesh;
lv_obj_t * ui_BedMesh_bg;
lv_obj_t * ui_BedMesh_return_btn;
lv_obj_t * ui_BedMesh_return_label;
lv_obj_t * ui_BedMesh_return2_btn;
lv_obj_t * ui_BedMesh_return2_label;
lv_obj_t * ui_BedMesh_cont_obj;
lv_obj_t * ui_BedMesh_point_obj[MAX_PROBE_POINT];
lv_obj_t * ui_BedMesh_point_label[MAX_PROBE_POINT];
lv_obj_t * ui_BedMesh_dropDownList;
lv_obj_t * ui_BedMesh_title_label;
lv_obj_t * ui_BedMesh_start_btn;
lv_obj_t * ui_BedMesh_start_label;
lv_obj_t * ui_ImageUpLevel;
lv_obj_t * ui_ImageDownLevel;
lv_obj_t * ui_LabelLevelValue;
///////////////////// VARIABLES ////////////////////
static bool start_leveling=false;
static int levelcount = 5;

float CurrentPointNumber = 0;       // 记录当前调平值
float LevelStepValue[3] = {0.1, 0.05, 0.01};// 步进数组
int   CurrentStep = 0;              // 记录当前调平档位
lv_obj_t * ui_LevelCheckbox[3] = {0};
lv_obj_t * ui_LevelCheckboxBg[3] = {0};
uint32_t checkbox_index = 0;
lv_obj_t * ui_LevelLine[2];


void create_bed_mesh(unsigned int count);
static void checkbox_event_handler(lv_event_t * e);
void ui_event_changelevelvalue_handle(lv_event_t * e);

///////////////////// FUNCTIONS ////////////////////


static void ui_event_PageChange(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    char * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED)
    {
        switch(atoi(userdata))
        {
            case PAGE_HOME:home_printing_is_printing_finished() ? ui_change(PAGE_HOME) : ui_change(PAGE_HOME_PRINT);break;
            case PAGE_AXIS:ui_change(PAGE_AXIS);break;
            case PAGE_FILEMANAGE:ui_change(PAGE_FILEMANAGE);break;
            case PAGE_SETING:ui_change(PAGE_SETING);break;
            case PAGE_HELP:ui_change(PAGE_HELP);break;
            default:break;
        }
    }
}

void ui_event_BedMesh_return_btn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        CrLogI("exit bed mesh");
        ui_change(PAGE_SETING);
    }
}

void ui_event_BedMeshStart_btn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SHORT_CLICKED) {
        send_buzzer(0x01);
        set_printer_data(0x09,2,"21");
        lv_obj_add_state(ui_BedMesh_return_btn,LV_STATE_DISABLED);
        lv_obj_add_state(ui_BedMesh_start_btn,LV_STATE_DISABLED);
        lv_obj_add_state(ui_BedMesh_dropDownList,LV_STATE_DISABLED);

        for(int i=0;i<MAX_PROBE_POINT;i++){
            if(ui_BedMesh_point_label[i]!=NULL){
                if(i/levelcount%2){
                    int num = i+levelcount-2*(i%levelcount)-1;
                    lv_label_set_text_fmt(ui_BedMesh_point_label[i], "%d",num);
			        
                }else{
                    lv_label_set_text_fmt(ui_BedMesh_point_label[i], "%d",i);
                   
                }
                lv_obj_set_style_text_color(ui_BedMesh_point_label[i],lv_color_hex(0x6D7382),LV_PART_MAIN | LV_STATE_DEFAULT);   
            }   
        }
    }
}


void ui_event_points_obj(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    int index = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        send_buzzer(0x01);
        CrLogI("exit bed mesh111111111");

    }
}

void ui_event_BedMesh_DropdownList(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        send_buzzer(0x01);
        uint16_t index;
        index = lv_dropdown_get_selected(ui_BedMesh_dropDownList);
        CrLogI("bed mesh method select %d",index);
        switch(index)
        {
            case 0:
                CrLogI("auto level\n");
                lv_obj_clear_flag(ui_BedMesh_return_btn,LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(ui_BedMesh_start_btn,LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_BedMesh_return2_btn,LV_OBJ_FLAG_HIDDEN);
                for(int i=0;i<MAX_PROBE_POINT;i++){
                    if(ui_BedMesh_point_obj[i]!=NULL){
                        lv_obj_add_state(ui_BedMesh_point_obj[i],LV_STATE_DISABLED);
                    }   
                }
                break;
            case 1:
                lv_obj_add_flag(ui_BedMesh_return_btn,LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_BedMesh_start_btn,LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(ui_BedMesh_return2_btn,LV_OBJ_FLAG_HIDDEN);
                for(int i=0;i<MAX_PROBE_POINT;i++){
                    if(ui_BedMesh_point_obj[i]!=NULL){
                        lv_obj_clear_state(ui_BedMesh_point_obj[i],LV_STATE_DISABLED);
                    }
                }
                CrLogI("manuel level\n");
                break;
            default:break;
        }
    }
    if(event_code == LV_EVENT_READY) {
        static lv_style_t list_selected_default;
        if (list_selected_default.prop_cnt > 1)
            lv_style_reset(&list_selected_default);
        else
            lv_style_init(&list_selected_default);
        lv_style_set_radius(&list_selected_default, 0);
        lv_style_set_bg_color(&list_selected_default, lv_color_hex(0x42BDD8));
        // lv_style_set_bg_grad_color(&list_selected_default, lv_color_hex(0x42BDD8));
        lv_style_set_bg_grad_dir(&list_selected_default, LV_GRAD_DIR_NONE);
        lv_style_set_bg_opa(&list_selected_default, 255);
        lv_style_set_border_color(&list_selected_default, lv_color_make(0xe1, 0xe6, 0xee));
        lv_style_set_border_width(&list_selected_default, 0);
        lv_style_set_text_color(&list_selected_default, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_text_font(&list_selected_default, lv_font25.font);
        lv_obj_add_style(lv_dropdown_get_list(target), &list_selected_default, LV_PART_SELECTED|LV_STATE_FOCUSED);
        lv_obj_add_style(lv_dropdown_get_list(target), &list_selected_default, LV_PART_SELECTED|LV_STATE_PRESSED);

        static lv_style_t list_main_default;
        if (list_main_default.prop_cnt > 1)
            lv_style_reset(&list_main_default);
        else
            lv_style_init(&list_main_default);
        lv_style_set_radius(&list_main_default, 0);
        lv_style_set_bg_color(&list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
        lv_style_set_bg_grad_color(&list_main_default, lv_color_make(0x3c, 0x3e, 0x42));
        lv_style_set_bg_grad_dir(&list_main_default, LV_GRAD_DIR_VER);
        lv_style_set_bg_opa(&list_main_default, 255);
        lv_style_set_border_color(&list_main_default, lv_color_make(0xe1, 0xe6, 0xee));
        lv_style_set_border_width(&list_main_default, 0);
        lv_style_set_text_color(&list_main_default, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_text_font(&list_main_default, lv_font25.font);
        lv_style_set_max_height(&list_main_default, 150);
        lv_obj_add_style(lv_dropdown_get_list(target), &list_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

        static lv_style_t scrollbar_default;
        if (scrollbar_default.prop_cnt > 1)
            lv_style_reset(&scrollbar_default);
        else
            lv_style_init(&scrollbar_default);
        lv_style_set_radius(&scrollbar_default, 3);
        lv_style_set_bg_grad_color(&scrollbar_default, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_bg_grad_dir(&scrollbar_default, LV_GRAD_DIR_VER);
        lv_style_set_bg_opa(&scrollbar_default, 0);
        lv_obj_add_style(lv_dropdown_get_list(target), &scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);
    }
}
///////////////////// FUNCTIONS ////////////////////

void create_bed_mesh(unsigned int count)
{
   
    //暂时支持最大49个点
    if(count <=0 ||count>MAX_PROBE_POINT || ui_BedMesh_cont_obj==NULL){
        CrLogW("create_bed_mesh fail!!! count=%d\n",count);
        return;
    }
    //先清除床网容器里面的控件，根据床网个数创建obj控件
    lv_obj_clean(ui_BedMesh_cont_obj);
    for(int i=0;i<MAX_PROBE_POINT;i++){
        ui_BedMesh_point_obj[i]=NULL;
        ui_BedMesh_point_label[i]=NULL;
    }

    switch (count)
    {
        case 9: levelcount = 3;
                break;
        case 16:levelcount = 4;
                break;
        case 25:levelcount = 5;
                break;
        case 36:levelcount = 6;
                break;
        case 49:levelcount = 7;
                break;
        default:CrLogW("level point count error:%d",count);
            break;
    }
    CrLogI("levelcount=%d \n",levelcount);
    int index = lv_dropdown_get_selected(ui_BedMesh_dropDownList);
    for(int i=0;i<count;i++){
        float obj_width = BED_MESH_CONT_SIZE/levelcount;
        float obj_height = BED_MESH_CONT_SIZE/levelcount;
        ui_BedMesh_point_obj[i] = lv_obj_create(ui_BedMesh_cont_obj);
        lv_obj_set_size(ui_BedMesh_point_obj[i], obj_width, obj_height);
        lv_obj_clear_flag(ui_BedMesh_point_obj[i], LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_bg_color(ui_BedMesh_point_obj[i], lv_color_hex(0x2F3238), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_BedMesh_point_obj[i], lv_color_hex(0x181A1E), LV_PART_MAIN | LV_STATE_DISABLED);
        lv_obj_set_style_bg_color(ui_BedMesh_point_obj[i], lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_CHECKED);
        lv_obj_set_style_border_width(ui_BedMesh_point_obj[i], 1, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_color(ui_BedMesh_point_obj[i], lv_color_hex(0x6D7382), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_radius(ui_BedMesh_point_obj[i], 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_add_flag(ui_BedMesh_point_obj[i],LV_OBJ_FLAG_CHECKABLE);
        lv_obj_add_event_cb(ui_BedMesh_point_obj[i], ui_event_points_obj, LV_EVENT_ALL, i);


        ui_BedMesh_point_label[i] = lv_label_create(ui_BedMesh_point_obj[i]);
        lv_label_set_text_fmt(ui_BedMesh_point_label[i], "0.00");
        lv_obj_set_style_text_color(ui_BedMesh_point_label[i],lv_color_hex(0xFFD15B),LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_add_flag(ui_BedMesh_point_label[i],LV_OBJ_FLAG_CHECKABLE);
        lv_obj_center(ui_BedMesh_point_label[i]);
        if(count>25){
            lv_obj_set_style_text_font(ui_BedMesh_point_label[i],lv_font22.font,LV_PART_MAIN | LV_STATE_DEFAULT);
        }else{
            lv_obj_set_style_text_font(ui_BedMesh_point_label[i],lv_font22.font,LV_PART_MAIN | LV_STATE_DEFAULT);
        }

        
        if(index==0){
            //自动
            lv_obj_add_state(ui_BedMesh_point_obj[i],LV_STATE_DISABLED);
        }else{
            //手动
            lv_obj_clear_state(ui_BedMesh_point_obj[i],LV_STATE_DISABLED);
        }
    }
    if(index==0){
        //自动
        lv_obj_clear_flag(ui_BedMesh_return_btn,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_BedMesh_start_btn,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_BedMesh_return2_btn,LV_OBJ_FLAG_HIDDEN);
    }else{
        //手动
        lv_obj_add_flag(ui_BedMesh_return_btn,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_BedMesh_start_btn,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_BedMesh_return2_btn,LV_OBJ_FLAG_HIDDEN);
    }
  
} 
void ui_add_creality_style_btn(lv_obj_t* parent,const char* text,lv_color_t bg_color,
                            lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs,
                            lv_obj_t** p_btn,lv_obj_t** p_label)
{
    *p_btn = lv_btn_create(parent);
    lv_obj_set_size(*p_btn, 116, 60);
    lv_obj_set_style_pad_all(*p_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(*p_btn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(*p_btn, bg_color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(*p_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(*p_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(*p_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(*p_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(*p_btn, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(*p_btn, LV_OBJ_FLAG_FLOATING);
    lv_obj_align(*p_btn,align,x_ofs,y_ofs);
    
    *p_label = lv_label_create(*p_btn);
    lv_label_set_text(*p_label, text);
    lv_obj_set_size(*p_label,110,60);
    lv_obj_set_style_text_align(*p_label,LV_TEXT_ALIGN_CENTER,LV_PART_MAIN);
    lv_label_set_long_mode(*p_label,LV_LABEL_LONG_DOT);
    lv_obj_align_to(*p_label,*p_btn,LV_ALIGN_CENTER,0,15);
    lv_obj_set_style_text_color(*p_label, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(*p_label, lv_color_hex(0x8b8c8e), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_text_font(*p_label, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

}
void ui_BedMesh_screen_init(void)
{   
    
    uint8_t language_index = get_cur_language_index();
    if(!ui_Settings)
        return;
    //获取床网数据
    CrLogI("get level data");
    get_printer_data(0x09, 2, "7");

    ui_BedMeshBg = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_BedMeshBg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_BedMeshIcon = lv_obj_create(ui_BedMeshBg);
    lv_obj_set_size(ui_BedMeshIcon, 80,480);
    lv_obj_align(ui_BedMeshIcon,LV_ALIGN_TOP_LEFT,0,0);
    lv_obj_clear_flag(ui_BedMeshIcon, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_BedMeshIcon, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BedMeshIcon, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_BedMeshIcon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_BedMeshIcon, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_BedMeshIcon, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_BedMeshIcon, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_BedMeshIcon, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_SPACE_BETWEEN);
    lv_obj_set_style_pad_column(ui_BedMeshIcon, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BedMeshPageImage1 = lv_img_create(ui_BedMeshIcon);
    lv_img_set_src(ui_BedMeshPageImage1, &ui_img_pagehome_png);
    lv_obj_set_width(ui_BedMeshPageImage1, 80);
    lv_obj_set_height(ui_BedMeshPageImage1, 96);
    lv_obj_add_flag(ui_BedMeshPageImage1, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_BedMeshPageImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BedMeshPageImage1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BedMeshPageImage2 = lv_img_create(ui_BedMeshIcon);
    lv_img_set_src(ui_BedMeshPageImage2, &ui_img_pagemove_png);
    lv_obj_set_width(ui_BedMeshPageImage2, 80);
    lv_obj_set_height(ui_BedMeshPageImage2, 96);
    lv_obj_add_flag(ui_BedMeshPageImage2, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_BedMeshPageImage2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BedMeshPageImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BedMeshPageImage2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BedMeshPageImage3 = lv_img_create(ui_BedMeshIcon);
    lv_img_set_src(ui_BedMeshPageImage3, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_BedMeshPageImage3, 80);
    lv_obj_set_height(ui_BedMeshPageImage3, 96);
    lv_obj_add_flag(ui_BedMeshPageImage3, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_BedMeshPageImage3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BedMeshPageImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BedMeshPageImage3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BedMeshPageImage4 = lv_img_create(ui_BedMeshIcon);
    lv_img_set_src(ui_BedMeshPageImage4, &ui_img_pagesettingselected_png);
    lv_obj_set_width(ui_BedMeshPageImage4, 80);
    lv_obj_set_height(ui_BedMeshPageImage4, 96);
    lv_obj_add_flag(ui_BedMeshPageImage4, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_BedMeshPageImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BedMeshPageImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BedMeshPageImage4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BedMeshPageImage5 = lv_img_create(ui_BedMeshIcon);
    lv_img_set_src(ui_BedMeshPageImage5, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_BedMeshPageImage5, 80);
    lv_obj_set_height(ui_BedMeshPageImage5, 96);
    lv_obj_add_flag(ui_BedMeshPageImage5, LV_OBJ_FLAG_CLICKABLE );     /// Flags
    lv_obj_clear_flag(ui_BedMeshPageImage5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_BedMeshPageImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BedMeshPageImage5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_BedMeshPageImage1, ui_event_PageChange, LV_EVENT_CLICKED, "0");
    lv_obj_add_event_cb(ui_BedMeshPageImage2, ui_event_PageChange, LV_EVENT_CLICKED, "2");
    lv_obj_add_event_cb(ui_BedMeshPageImage3, ui_event_PageChange, LV_EVENT_CLICKED, "3");
    lv_obj_add_event_cb(ui_BedMeshPageImage4, ui_event_PageChange, LV_EVENT_CLICKED, "4");
    lv_obj_add_event_cb(ui_BedMeshPageImage5, ui_event_PageChange, LV_EVENT_CLICKED, "5");

    ui_BedMesh = lv_obj_create(ui_BedMeshBg);
    lv_obj_set_size(ui_BedMesh, 720,480);
    lv_obj_align(ui_BedMesh,LV_ALIGN_RIGHT_MID,0,0);
    lv_obj_clear_flag(ui_BedMesh, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_BedMesh, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BedMesh, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BedMesh, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_BedMesh, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_BedMesh, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_BedMesh, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BedMesh_bg = lv_obj_create(ui_BedMesh);
    lv_obj_set_size(ui_BedMesh_bg, 696,456);
    lv_obj_align(ui_BedMesh_bg,LV_ALIGN_CENTER,0,0);
    lv_obj_clear_flag(ui_BedMesh_bg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_BedMesh_bg, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BedMesh_bg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BedMesh_bg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_BedMesh_bg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_BedMesh_bg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_BedMesh_bg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BedMesh_cont_obj = lv_obj_create(ui_BedMesh_bg);
    lv_obj_set_style_pad_row(ui_BedMesh_cont_obj, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_column(ui_BedMesh_cont_obj, 0, LV_PART_MAIN);
    lv_obj_set_size(ui_BedMesh_cont_obj, BED_MESH_CONT_SIZE, BED_MESH_CONT_SIZE);
    lv_obj_clear_flag(ui_BedMesh_cont_obj, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_BedMesh_cont_obj, lv_color_hex(0x2F3238), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BedMesh_cont_obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BedMesh_cont_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_BedMesh_cont_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(ui_BedMesh_cont_obj,LV_ALIGN_DEFAULT,15,15);
    lv_obj_set_flex_flow(ui_BedMesh_cont_obj, LV_FLEX_FLOW_ROW_WRAP_REVERSE);
    lv_obj_set_style_base_dir(ui_BedMesh_cont_obj, LV_BASE_DIR_RTL, 0);

    ui_BedMesh_title_label = lv_label_create(ui_BedMesh_bg);
    lv_label_set_text(ui_BedMesh_title_label, LevelingMethod[language_index]);
    lv_obj_set_size(ui_BedMesh_title_label,LV_SIZE_CONTENT,60);
    lv_obj_set_style_text_align(ui_BedMesh_title_label,LV_TEXT_ALIGN_LEFT,LV_PART_MAIN);
    lv_label_set_long_mode(ui_BedMesh_title_label,LV_LABEL_LONG_WRAP);
    lv_obj_align_to(ui_BedMesh_title_label,ui_BedMesh_cont_obj,LV_ALIGN_OUT_RIGHT_TOP,5,0);
    lv_obj_set_style_text_color(ui_BedMesh_title_label, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_BedMesh_title_label, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    char buff[150] = {0};
    // sprintf(buff, "%s\n%s", Automatic[language_index], Manual[language_index]);
    sprintf(buff, "%s", Automatic[language_index]);

    ui_BedMesh_dropDownList = lv_dropdown_create(ui_BedMesh_bg);
    lv_dropdown_set_options(ui_BedMesh_dropDownList, buff);
    lv_obj_set_width(ui_BedMesh_dropDownList, 250);
    lv_obj_set_height(ui_BedMesh_dropDownList, 50);
    lv_obj_align_to(ui_BedMesh_dropDownList,ui_BedMesh_bg,LV_ALIGN_TOP_RIGHT,-30,63);
    lv_obj_add_flag(ui_BedMesh_dropDownList, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_set_style_text_color(ui_BedMesh_dropDownList, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_BedMesh_dropDownList, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_BedMesh_dropDownList, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_BedMesh_dropDownList, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_BedMesh_dropDownList, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_BedMesh_dropDownList, lv_color_hex(0x252729), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BedMesh_dropDownList, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_BedMesh_dropDownList, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_BedMesh_dropDownList, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_BedMesh_dropDownList, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_text_color(ui_BedMesh_dropDownList, lv_color_hex(0xFFFFFF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_BedMesh_dropDownList, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_BedMesh_dropDownList, lv_font25.font, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_clear_flag(ui_BedMesh_dropDownList, LV_OBJ_FLAG_SCROLLABLE);
    lv_dropdown_set_symbol(ui_BedMesh_dropDownList, &ui_img_expand_down_png);
    // if(UIType == F001 || UIType == F002){
    //     lv_obj_t* List1 = lv_dropdown_get_list(ui_BedMesh_dropDownList);
    //     lv_obj_set_style_bg_color(List1, lv_color_hex(0x42BDD8), LV_PART_SELECTED | LV_STATE_CHECKED);
    // }  

    ui_add_creality_style_btn(ui_BedMesh_bg,Back[language_index],lv_color_hex(0x28292D),
                                LV_ALIGN_BOTTOM_RIGHT,-154,-15,
                                &ui_BedMesh_return_btn,&ui_BedMesh_return_label);
    lv_obj_remove_style(ui_BedMesh_return_btn,NULL,LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui_BedMesh_return_btn, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui_BedMesh_return_btn, 1, LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui_BedMesh_return_btn, lv_color_hex(0x2c2d30), LV_PART_MAIN | LV_STATE_DISABLED);
                                
    ui_add_creality_style_btn(ui_BedMesh_bg,Start[language_index],lv_color_hex(0x42BDD8),
                                LV_ALIGN_BOTTOM_RIGHT,-14,-15,
                                &ui_BedMesh_start_btn,&ui_BedMesh_start_label);
    lv_obj_remove_style(ui_BedMesh_start_btn,NULL,LV_STATE_DISABLED);
    lv_obj_set_style_border_color(ui_BedMesh_start_btn, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_border_width(ui_BedMesh_start_btn, 1, LV_PART_MAIN | LV_STATE_DISABLED);
    lv_obj_set_style_bg_color(ui_BedMesh_start_btn, lv_color_hex(0x366e7c), LV_PART_MAIN | LV_STATE_DISABLED);
    
    ui_add_creality_style_btn(ui_BedMesh_bg,Back[language_index],lv_color_hex(0x42BDD8),
                                LV_ALIGN_BOTTOM_RIGHT,-14,-15,
                                &ui_BedMesh_return2_btn,&ui_BedMesh_return2_label);
    //隐藏按钮
    int index = lv_dropdown_get_selected(ui_BedMesh_dropDownList);
    if(index==0){
        lv_obj_add_flag(ui_BedMesh_return2_btn,LV_OBJ_FLAG_HIDDEN);
    }else{
        lv_obj_add_flag(ui_BedMesh_return_btn,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_BedMesh_start_btn,LV_OBJ_FLAG_HIDDEN);
    }

    lv_obj_add_event_cb(ui_BedMesh_dropDownList, ui_event_BedMesh_DropdownList, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_BedMesh_return_btn, ui_event_BedMesh_return_btn, LV_EVENT_SHORT_CLICKED, NULL);
    lv_obj_add_event_cb(ui_BedMesh_return2_btn, ui_event_BedMesh_return_btn, LV_EVENT_SHORT_CLICKED, NULL);
    lv_obj_add_event_cb(ui_BedMesh_start_btn, ui_event_BedMeshStart_btn, LV_EVENT_SHORT_CLICKED, NULL);

    if(UIType == CR_K1 || UIType == CR_K1_Max)
        create_bed_mesh(36);

    // //手动操作按钮部分控件
    // char tempbuff[256] = {0};

    // // checkbox 
    // for (int i = 0; i < 3; i++)
    // {
    //     snprintf(tempbuff, 64, "%.2f", LevelStepValue[i]);

    //     ui_LevelCheckbox[i] = ui_AddTrafficCheckbox(ui_BedMesh_bg, 424, 137 + 81*i, tempbuff);
    //     ui_LevelCheckboxBg[i] = ui_AddTrafficCheckboxBg(ui_LevelCheckbox[i]);
    // } 
    // lv_obj_add_state(ui_LevelCheckbox[0], LV_STATE_CHECKED);     /*Uncheck the current radio button*/
    // lv_obj_clear_flag(ui_LevelCheckboxBg[0], LV_OBJ_FLAG_HIDDEN);   /*Uncheck the previous radio button*/

    // // 画线
    // for (int i = 0; i < 2; i++)
    // {
    //     ui_TrafficDrawStraightLine(ui_BedMesh_bg, ui_LevelLine[i], 438, 165 + 81*i, 2, 53, lv_color_hex(0x9B9FA5));
    // }

    // // 显示箭头上
    // ui_ImageUpLevel = lv_img_create(ui_BedMesh_bg);
    // char imgsrc[256] = {0};
    // memset(imgsrc, 0, sizeof(imgsrc));
    // snprintf(imgsrc, 256, "S:%s/%s", GetK1ImageResourcePtah(), "Add.png");
    // lv_img_set_src(ui_ImageUpLevel, imgsrc);
    // lv_obj_set_size(ui_ImageUpLevel, 96, 68);
    // lv_obj_set_pos(ui_ImageUpLevel, 559, 137);
    // lv_obj_add_flag(ui_ImageUpLevel, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_CLICKABLE);     /// Flags
    // lv_obj_clear_flag(ui_ImageUpLevel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_add_event_cb(ui_ImageUpLevel, ui_event_changelevelvalue_handle, LV_EVENT_CLICKED, ui_ImageUpLevel);
    
    // // 显示箭头下
    // ui_ImageDownLevel = lv_img_create(ui_BedMesh_bg);
    // memset(imgsrc, 0, sizeof(imgsrc));
    // snprintf(imgsrc, 256, "S:%s/%s", GetK1ImageResourcePtah(), "Subtract.png");
    // lv_img_set_src(ui_ImageDownLevel, imgsrc);
    // lv_obj_set_size(ui_ImageDownLevel, 96, 68);
    // lv_obj_set_pos(ui_ImageDownLevel, 559, 260);
    // lv_obj_add_flag(ui_ImageDownLevel, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_CLICKABLE);     /// Flags
    // lv_obj_clear_flag(ui_ImageDownLevel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_add_event_cb(ui_ImageDownLevel, ui_event_changelevelvalue_handle, LV_EVENT_CLICKED, ui_ImageDownLevel);


    // // 显示Z轴补偿当前值
    // memset(tempbuff, 0, sizeof(tempbuff));
    // snprintf(tempbuff, 64, "%d", 0);
    // ui_LabelLevelValue = lv_label_create(ui_BedMesh_bg);
    // lv_obj_set_width(ui_LabelLevelValue, 96);
    // lv_obj_set_height(ui_LabelLevelValue, LV_SIZE_CONTENT);
    // lv_obj_set_align(ui_LabelLevelValue, LV_ALIGN_TOP_LEFT);
    // lv_obj_set_pos(ui_LabelLevelValue, 559, 220);
    // lv_obj_clear_flag(ui_LabelLevelValue, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_label_set_long_mode(ui_LabelLevelValue, LV_LABEL_LONG_SCROLL_CIRCULAR);
    // lv_label_set_text(ui_LabelLevelValue, tempbuff);     //冷却
    // lv_obj_set_style_text_color(ui_LabelLevelValue, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_LabelLevelValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_LabelLevelValue, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_LabelLevelValue, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

}

void refresh_BedMesh_data(int len,char * data)
{
    CrLogI("refresh the bed mesh data:%s",data);
    if(!ui_BedMesh_cont_obj)
        return;
    data++;
    char tempBuff[1024] = {0};
    if (data) {
        memcpy(tempBuff, data, strlen(data));
    }
    char *tempsingle = strtok(tempBuff, "\t");
    int count = 0;
    //先获取调平点总数
    while(tempsingle)
    {
        CrLogI("single level data : %s,count: %d",tempsingle, count);
        count++;
        tempsingle = strtok(NULL,"\t");
    }

    switch (count)
    {
        case 9: levelcount = 3;
                break;
        case 16:levelcount = 4;
                break;
        case 25:levelcount = 5;
                break;
        case 36:levelcount = 6;
                break;
        case 49:levelcount = 7;
                break;
        default:CrLogW("level point count:%d",count);
            break;
    }
    CrLogI("bed mesh count=%d\n",count);
    create_bed_mesh(count);

    char *single = strtok(data, "\t");
    int i = 0;
    while(single)
    {
        char tmp[64]={0};
        CrLogI("single level data : %s,count: %d\n",single, i);
        snprintf(tmp,sizeof(tmp),"%s",single);
        if(ui_BedMesh_point_label[i]){
            lv_label_set_text_fmt(ui_BedMesh_point_label[i],tmp);
        }
        
        i++;
        single = strtok(NULL,"\t");
    }
}

void refresh_BedMesh_point(unsigned int len, char *data)
{
    char singlepoint[32] = {0};

    unsigned char i,j;
    j = 0;
    int point = 0;
    for(i = 0; i < len; i++)
    {
        if(*(data+1+i) == '\0')
        {
            singlepoint[j++] = '\0';
            break;
        }
        if(*(data+1+i) == '\t')
        {
            singlepoint[j++] = '\0';
            point = atoi(singlepoint);
            j = 0;
        }
        else
        {
            singlepoint[j++] = *(data+1+i);
        }
    }
    int index = point-1;
    CrLogI("singlepoint:%s,point:%d", singlepoint, point);
    if(index<MAX_PROBE_POINT){
        if(index/levelcount%2){
            int a = index+levelcount-2*(index%levelcount)-1;
            lv_label_set_text_fmt(ui_BedMesh_point_label[a], "%s",singlepoint);
            lv_obj_set_style_text_color(ui_BedMesh_point_label[a],lv_color_hex(0xFFD15B),LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_state(ui_BedMesh_point_obj[a],LV_STATE_DISABLED);
            
        }else{
            lv_label_set_text_fmt(ui_BedMesh_point_label[index], "%s",singlepoint);
            lv_obj_set_style_text_color(ui_BedMesh_point_label[index],lv_color_hex(0xFFD15B),LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_state(ui_BedMesh_point_obj[index],LV_STATE_DISABLED);

        }    
    }
    
    
    CrLogI("data=%s len=%d\n",data,len);
    CrLogI("index=%d\n",point);
    CrLogI("point=%s\n",singlepoint);
}

void BedMesh_AutoLeveling_completed(void)
{
    lv_obj_clear_state(ui_BedMesh_return_btn,LV_STATE_DISABLED);
    lv_obj_clear_state(ui_BedMesh_start_btn,LV_STATE_DISABLED);
    lv_obj_clear_state(ui_BedMesh_dropDownList,LV_STATE_DISABLED);
}

void ui_DiapScreenAutoLevelPage(void)
{   
    ui_change(PAGE_BEDLEVEL);
}

static void checkbox_event_handler(lv_event_t * e)
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

}

void ui_event_changelevelvalue_handle(lv_event_t * e)
{

}
