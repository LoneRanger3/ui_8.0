#include "ui_custom_dirent_info_part.h"
#include "src/core/lv_obj_pos.h"
#include "src/core/lv_obj_scroll.h"
#include "src/misc/lv_area.h"
#include "ui.h"
#include "ui_helpers.h"
#include <stdio.h>



dirent_info_part_t *create_custom_dirent_info_part(lv_obj_t *parent, void (*part_event_callback)(lv_event_t *))
{
    dirent_info_part_t *part = (dirent_info_part_t *)lv_mem_alloc(sizeof(dirent_info_part_t));
    if ( !part )
        return NULL;
    
    lv_obj_t * ui_PanelFileInfo = lv_obj_create(parent);
    lv_obj_set_width(ui_PanelFileInfo, 545);
    lv_obj_set_height(ui_PanelFileInfo, 90);
    // lv_obj_set_x(ui_PanelFileInfo, pos_x);
    // lv_obj_set_y(ui_PanelFileInfo, pos_y);
    lv_obj_add_flag(ui_PanelFileInfo, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
   // lv_obj_set_flex_align(ui_PanelFileInfo, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PanelFileInfo, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_PanelFileInfo, lv_color_hex(0x18181B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelFileInfo, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
   // lv_obj_set_style_border_side(ui_PanelFileInfo, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_border_side(ui_PanelFileInfo, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(ui_PanelFileInfo, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_PanelFileInfo, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelFileInfo, lv_color_hex(0x383838), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_PanelFileInfo, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //选中后样式                              
    lv_obj_set_style_bg_color(ui_PanelFileInfo, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_color(ui_PanelFileInfo, lv_color_hex(0xCDF6FF), LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_radius(ui_PanelFileInfo, 4, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_opa(ui_PanelFileInfo, 255, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_border_width(ui_PanelFileInfo, 2, LV_PART_MAIN | LV_STATE_FOCUSED);
    lv_obj_set_style_pad_all(ui_PanelFileInfo, 0, LV_PART_MAIN | LV_STATE_FOCUSED);
    
    part->part_panel = ui_PanelFileInfo;

    lv_obj_t * ui_CheckboxFile = lv_checkbox_create(ui_PanelFileInfo);
    lv_checkbox_set_text(ui_CheckboxFile, "");
    lv_obj_set_width(ui_CheckboxFile, 26);
    lv_obj_set_height(ui_CheckboxFile, 26);
    lv_obj_set_x(ui_CheckboxFile, -14);
    lv_obj_set_y(ui_CheckboxFile, -14);
    lv_obj_add_flag(ui_CheckboxFile, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    part->checkbox_file = ui_CheckboxFile;

    lv_obj_set_style_radius(ui_CheckboxFile, 21, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_CheckboxFile, lv_color_hex(0x0D0D0D), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_CheckboxFile, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_CheckboxFile, lv_color_hex(0x484848), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_CheckboxFile, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_CheckboxFile, 1, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_CheckboxFile, 21, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(ui_CheckboxFile, lv_color_hex(0x484848), LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_CheckboxFile, 255, LV_PART_INDICATOR | LV_STATE_CHECKED);
    
    //预览页缩略图
    lv_obj_t * ui_ImageThumbnail = lv_img_create(ui_PanelFileInfo);
    lv_obj_set_width(ui_ImageThumbnail, LV_SIZE_CONTENT);//76
    lv_obj_set_height(ui_ImageThumbnail, LV_SIZE_CONTENT);
    lv_obj_set_x(ui_ImageThumbnail, 9);
    lv_obj_set_y(ui_ImageThumbnail, -6);
  //  lv_obj_align_to(ui_ImageThumbnail, ui_PanelFileInfo, LV_ALIGN_LEFT_MID, 0, -20);
    //lv_obj_add_flag(ui_ImageThumbnail, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageThumbnail, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_src(ui_ImageThumbnail, &ui_img_crealitylogo96_png);
   // lv_obj_set_style_pad_all(ui_ImageThumbnail, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_img_set_zoom(ui_ImageThumbnail, 220);
    part->img_file_png = ui_ImageThumbnail;
    
    //文件名
    lv_obj_t * ui_LabelFileName = lv_label_create(ui_PanelFileInfo);
    lv_obj_set_width(ui_LabelFileName, 261);
    //lv_obj_set_height(ui_LabelFileName, LV_SIZE_CONTENT);    /// 34
    lv_obj_set_height(ui_LabelFileName, 34);    /// 34
    lv_obj_set_x(ui_LabelFileName, 101);
    lv_obj_set_y(ui_LabelFileName, 7);
    lv_label_set_long_mode(ui_LabelFileName, LV_LABEL_LONG_DOT);
    lv_obj_set_style_text_color(ui_LabelFileName, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelFileName, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelFileName, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFileName, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_LabelFileName, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->label_dirent_name = ui_LabelFileName;
    
    //打印总时间图标
    lv_obj_t * ui_ImageTime = lv_img_create(ui_PanelFileInfo);
    lv_img_set_src(ui_ImageTime, &ui_img_totaltime_png);
    lv_obj_set_width(ui_ImageTime, 22);
    lv_obj_set_height(ui_ImageTime, 22);
    lv_obj_set_x(ui_ImageTime, 287);
    lv_obj_set_y(ui_ImageTime, 57);
    lv_obj_add_flag(ui_ImageTime, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageTime, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_all(ui_ImageTime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->img_time_png = ui_ImageTime;
    
     //打印材料长度图标
    lv_obj_t * ui_ImageMaterial = lv_img_create(ui_PanelFileInfo);
    lv_img_set_src(ui_ImageMaterial, &ui_img_materialusage_png);
    lv_obj_set_width(ui_ImageMaterial, 20);
    lv_obj_set_height(ui_ImageMaterial, 20);
    lv_obj_set_x(ui_ImageMaterial, 409);
    lv_obj_set_y(ui_ImageMaterial, 58);
    lv_obj_add_flag(ui_ImageMaterial, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageMaterial, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_all(ui_ImageMaterial, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->img_mater_png = ui_ImageMaterial;
    
    //u盘图标
    lv_obj_t * ui_Imageudisk = lv_img_create(ui_PanelFileInfo);
    lv_img_set_src(ui_Imageudisk, &ui_img_udisk_png);
    lv_obj_set_width(ui_Imageudisk, 30);
    lv_obj_set_height(ui_Imageudisk, 30);
    lv_obj_set_x(ui_Imageudisk, 498);
    lv_obj_set_y(ui_Imageudisk, 10);
    lv_obj_add_flag(ui_Imageudisk, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Imageudisk, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_all(ui_Imageudisk, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_Imageudisk, LV_OBJ_FLAG_HIDDEN);
    part->img_udik_png = ui_Imageudisk;

    //打印总时间
    lv_obj_t * ui_LabelTime = lv_label_create(ui_PanelFileInfo);
    lv_obj_set_width(ui_LabelTime, 71);
    lv_obj_set_height(ui_LabelTime, 32);    
    lv_obj_set_x(ui_LabelTime, 318);
    lv_obj_set_y(ui_LabelTime, 50);
    lv_label_set_text(ui_LabelTime, "");
    lv_obj_set_style_text_color(ui_LabelTime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTime, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTime, lv_font18.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_LabelTime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->label_totle_time = ui_LabelTime;
    
    //材料使用长度
    lv_obj_t * ui_LabelMaterial = lv_label_create(ui_PanelFileInfo);
    lv_obj_set_width(ui_LabelMaterial, 76);
    lv_obj_set_height(ui_LabelMaterial, 32);    
    lv_obj_set_x(ui_LabelMaterial, 438);
    lv_obj_set_y(ui_LabelMaterial, 50);
    lv_label_set_text(ui_LabelMaterial, "");
    lv_obj_set_style_text_color(ui_LabelMaterial, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelMaterial, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelMaterial, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelMaterial, lv_font18.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_LabelMaterial, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->label_mater_used = ui_LabelMaterial;

    /*****************create dir info controls**********************/
    lv_obj_t *ui_ImageDir = lv_img_create(ui_PanelFileInfo);
    lv_img_set_src(ui_ImageDir, &ui_img_dirmini2_png);
    lv_obj_set_width(ui_ImageDir, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageDir, LV_SIZE_CONTENT);
    // lv_obj_set_x(ui_ImageDir, 25);
    // lv_obj_set_y(ui_ImageDir, 19);
    lv_obj_align(ui_ImageDir, LV_ALIGN_LEFT_MID, 25, 0);
    lv_obj_add_flag(ui_ImageDir, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ImageDir, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_all(ui_ImageDir, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_img_set_zoom(ui_ImageDir, 300);
    part->img_dir_png = ui_ImageDir;

    /***************dir name share with file name label******************************/
    lv_obj_t *ui_LabelDirCreateTime = lv_label_create(ui_PanelFileInfo);
    lv_obj_set_width(ui_LabelDirCreateTime, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelDirCreateTime, LV_SIZE_CONTENT);    /// 34
    lv_obj_set_x(ui_LabelDirCreateTime, 100);
    lv_obj_set_y(ui_LabelDirCreateTime, 54);
   // lv_label_set_long_mode(ui_LabelDirCreateTime, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_label_set_text(ui_LabelDirCreateTime, "");
    lv_obj_set_style_text_color(ui_LabelDirCreateTime, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelDirCreateTime, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelDirCreateTime, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelDirCreateTime, lv_font18.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_LabelDirCreateTime, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    part->label_dir_time = ui_LabelDirCreateTime;

    part->is_dir = false;
    part->totle_time = 0;
    part->mater_used = 0;
    part->is_local_disk = 0;
    part->dirent_index = 0;

    hidden_dir_controls(part);

    lv_obj_add_event_cb(ui_PanelFileInfo, part_event_callback, LV_EVENT_ALL, part);

    return part;
}

void destory_custom_dirent_info_part(dirent_info_part_t *part)
{
    if ( !part )
        return ;

    if ( part->part_panel )
        lv_obj_del(part->part_panel);
    
    lv_memset_00(part, sizeof(dirent_info_part_t));

    lv_mem_free(part);
    
}

void clear_custom_dirent_info_part_contents(dirent_info_part_t *part)
{
    if ( !part )
        return ;

    if ( part->img_file_png )
    {
        lv_img_set_src(part->img_file_png, &ui_img_crealitylogo96_png);
    }
    
    if ( part->label_dir_time )
    {
        lv_label_set_text(part->label_dir_time, "");
    }
    
    if ( part->label_dirent_name )
    {
        lv_label_set_text(part->label_dirent_name, "");
    }

    if ( part->label_mater_used )
    {
        lv_label_set_text(part->label_mater_used, "");
    }
    
    if ( part->label_totle_time )
    {
        lv_label_set_text(part->label_totle_time, "");
    }

    if ( part->checkbox_file )
        lv_obj_clear_state(part->checkbox_file, LV_STATE_CHECKED);
}

/**
 * @description: 显示gcode面板信息
 * @return {*}
 * @param {dirent_info_part_t} *part
 */
void ShowPartGcodefileInfo(dirent_info_part_t *part, Dirent_Info_t*ginfo)
{
    if ( !part || !(part->label_dirent_name) )
    {
        return;
    }

    if ( !ginfo->name )
    {
        lv_label_set_text(part->label_dirent_name, "");
        strcpy(part->dirent_name, "");
    }
    else
    {
        char *ch = strrchr(ginfo->name, '.');
        if ( ch )
            *ch = '\0';
        memset(part->dirent_name, 0, sizeof(part->dirent_name));
        strncpy(part->dirent_name, ginfo->name, sizeof(part->dirent_name));
        lv_label_set_text(part->label_dirent_name, part->dirent_name);
    }
   
    
    part->dirent_index = ginfo->dirent_index;
   // part->is_local_disk = local_disk;
    part->is_dir = false;
    memset(part->filament_type, 0, sizeof(part->filament_type));
    strncpy(part->filament_type, ginfo->filament_type, sizeof(ginfo->filament_type));
    part->nozzle_temp = ginfo->nozzle_temp;
    part->bed_temp = ginfo->bed_temp;
    part->is_udisk = ginfo->is_udisk; 
    part->subdir_part_index = ginfo->subdir_part_index; //有子目录时此用于记录json数组的一级索引

    if ( part->label_totle_time )
    {
        char buff[20] = {0};
        uint32_t time = ginfo->totle_time / 60;  // trans to minter
        sprintf(buff, "%0dh%02dm", time / 60, time % 60);
        lv_label_set_text(part->label_totle_time, buff);
        part->totle_time = ginfo->totle_time;
    }
   // printf("part->label_totle_time\n");

    if ( part->label_mater_used )
    {
        char buff[20] = {0};
        uint16_t meter = ginfo->mater_used / 1000;
        if ( meter >= 100 )
        {
            sprintf(buff, "%dm", meter);
        }
        else
        {
            uint8_t cmeter = ginfo->mater_used % 100;
            float fmeter = ginfo->mater_used / 1000.0f;

            sprintf(buff, "%.1fm", fmeter + 0.05);
        }
        
        lv_label_set_text(part->label_mater_used, buff);
        part->mater_used = ginfo->mater_used;
    }
      // printf("part->mater_used\n");

    if ( part->img_file_png )
    {
        if ( ginfo->mode_thumbnail && (strlen(ginfo->mode_thumbnail) > 0) )
        {
            char buff[258] = {0};
            snprintf(buff, 258, "%s:%s", PNG_DRV_LETTER, ginfo->mode_thumbnail);
            lv_img_set_src(part->img_file_png, buff);
        }
        else
        {
            lv_img_set_src(part->img_file_png, &ui_img_crealitylogo96_png);
            lv_img_cache_invalidate_src(&ui_img_crealitylogo96_png);
        }
        if (part->img_udik_png && part->is_udisk) { //显示u盘图标
            lv_obj_clear_flag(part->img_udik_png, LV_OBJ_FLAG_HIDDEN);
            part->is_local_disk = false;
        }
        else
        {
            part->is_local_disk = true;
            lv_obj_add_flag(part->img_udik_png, LV_OBJ_FLAG_HIDDEN);
        }
    }
   // printf("part->mode_thumbnail\n");

    display_file_controls(part);
    hidden_dir_controls(part);
}

void ShowPartDirInfo(dirent_info_part_t *part, char *dir_name, char *create_time, 
                    uint32_t dirent_sort_index, bool isUdisk)
{
    if ( !part || !(part->label_dirent_name) )
    {
        return;
    }

    if ( !dir_name )
    {
        lv_label_set_text(part->label_dirent_name, "");
        strcpy(part->dirent_name, "");
    }
    else
    {
        lv_label_set_text(part->label_dirent_name, dir_name);
        strncpy(part->dirent_name, dir_name, sizeof(part->dirent_name) - 1);
    }

    part->dirent_index = dirent_sort_index;
    part->is_dir = true;
    part->is_udisk = isUdisk;

    if ( part->label_dir_time )
    {
        if (create_time )
            lv_label_set_text(part->label_dir_time, create_time);
        else
            lv_label_set_text(part->label_dir_time, "");
    }
    if (part->img_udik_png && part->is_udisk == true) { //显示u盘图标
        lv_obj_clear_flag(part->img_udik_png, LV_OBJ_FLAG_HIDDEN);
    }
    else
    {
        //part->is_local_disk = true;
        lv_obj_add_flag(part->img_udik_png, LV_OBJ_FLAG_HIDDEN);
    }

    hidden_file_controls(part);
    display_dir_controls(part);
}


char *part_get_dirent_info_name(dirent_info_part_t *part)
{
    if ( !part )
        return NULL;
    
    return part->dirent_name;
}

bool part_dirent_is_local_desk(dirent_info_part_t *part)
{
    if ( !part )
        return true;
    
    return part->is_local_disk;
}

int32_t part_dirent_index(dirent_info_part_t *part)
{
    if ( !part )
        return -1;
    
    char *file_name = part_get_dirent_info_name(part);
    if ( !file_name || strlen(file_name) <= 0 )
        return -1;
    
    return part->dirent_index;
}

void hidden_file_controls(dirent_info_part_t *part)
{
    if ( !part )
        return ;

    if ( part->img_file_png )
        lv_obj_add_flag(part->img_file_png, LV_OBJ_FLAG_HIDDEN);
    
    if ( part->img_mater_png )
        lv_obj_add_flag(part->img_mater_png, LV_OBJ_FLAG_HIDDEN);
    
    if ( part->img_time_png )
        lv_obj_add_flag(part->img_time_png, LV_OBJ_FLAG_HIDDEN);
    
    if ( part->label_totle_time )
        lv_obj_add_flag(part->label_totle_time, LV_OBJ_FLAG_HIDDEN);
    
    if ( part->label_mater_used )
        lv_obj_add_flag(part->label_mater_used, LV_OBJ_FLAG_HIDDEN);

    if ( part->checkbox_file )
        lv_obj_add_flag(part->checkbox_file, LV_OBJ_FLAG_HIDDEN);
}

void hidden_dir_controls(dirent_info_part_t *part)
{
    if ( !part )
        return ;
    
    if ( part->img_dir_png )
        lv_obj_add_flag(part->img_dir_png, LV_OBJ_FLAG_HIDDEN);
    
    if ( part->label_dir_time )
        lv_obj_add_flag(part->label_dir_time, LV_OBJ_FLAG_HIDDEN);
}

void display_file_controls(dirent_info_part_t *part)
{
    if ( !part )
        return ;

    if ( part->img_file_png )
        lv_obj_clear_flag(part->img_file_png, LV_OBJ_FLAG_HIDDEN);
    
    if ( part->img_mater_png )
        lv_obj_clear_flag(part->img_mater_png, LV_OBJ_FLAG_HIDDEN);
    
    if ( part->img_time_png )
        lv_obj_clear_flag(part->img_time_png, LV_OBJ_FLAG_HIDDEN);
    
    if ( part->label_totle_time )
        lv_obj_clear_flag(part->label_totle_time, LV_OBJ_FLAG_HIDDEN);
    
    if ( part->label_mater_used )
        lv_obj_clear_flag(part->label_mater_used, LV_OBJ_FLAG_HIDDEN);
    
    // if ( part->checkbox_file )
    //     lv_obj_clear_flag(part->checkbox_file, LV_OBJ_FLAG_HIDDEN);
}

void display_dir_controls(dirent_info_part_t *part)
{
    if ( !part )
        return ;
    
    if ( part->img_dir_png )
        lv_obj_clear_flag(part->img_dir_png, LV_OBJ_FLAG_HIDDEN);
    
    if ( part->label_dir_time )
        lv_obj_clear_flag(part->label_dir_time, LV_OBJ_FLAG_HIDDEN);
}

// void display_part_control(dirent_info_part_t *part, bool display)
// {
//     if ( !part || !part->parent )
//         return;
    
//     if ( display )
//     {
//         lv_obj_clear_flag(part->parent, LV_OBJ_FLAG_HIDDEN);
//     }
//     else
//     {
//         lv_obj_add_flag(part->parent, LV_OBJ_FLAG_HIDDEN);
//     }
// }

void part_set_file_checkbox_state(dirent_info_part_t *part, bool checked)
{
    if ( !part || !(part->checkbox_file) || part->is_dir )
        return ;

    if ( checked )
        lv_obj_add_state(part->checkbox_file, LV_STATE_CHECKED);
    else
        lv_obj_clear_state(part->checkbox_file, LV_STATE_CHECKED);
}

void part_set_file_checkbox_dispaly(dirent_info_part_t *part, bool display)
{
    if ( !part || !(part->checkbox_file) || part->is_dir )
        return ;

    if ( display )
        lv_obj_clear_flag(part->checkbox_file, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(part->checkbox_file, LV_OBJ_FLAG_HIDDEN);
}

bool part_get_file_checkbox_checkedstate(dirent_info_part_t *part)
{
    if ( !part || !(part->checkbox_file) || part->is_dir )
        return false;
    
    return lv_obj_has_state(part->checkbox_file, LV_STATE_CHECKED);
}

void part_display_controls(dirent_info_part_t *part, bool display)
{
    if ( !part || !(part->part_panel) )
        return ;

    if ( display )
        lv_obj_clear_flag(part->part_panel, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(part->part_panel, LV_OBJ_FLAG_HIDDEN);
}