/*
 * @Description: 
 * @Author: chenwenke
 * @Date: 2023-09-17 22:08:51
 * @LastEditTime: 2023-10-15 23:10:49
 */
/*
 * mystyle.h
 *
 *  Created on: April 11, 2022
 *      Author: liuxinchao
 */

#ifndef __MYSTYLE_H_
#define __MYSTYLE_H_

#include "../lvgl/lvgl.h"
#include "../lvgl/src/extra/libs/freetype/lv_freetype.h"
// #include "../generated/gui_guider.h"
#include "CrlogDef.h"
#include "../k1_horizontal_ui/ui.h"

extern lv_style_t style_cont_default;               //容器的格式
extern lv_style_t style_cont_msgbox;                //弹窗容器格式
extern lv_style_t style_img_pressed;                //图片按下格式
extern lv_style_t style_img_default;                //图片按下格式
extern lv_style_t style_white24_text_creality;       //label格式 创想蓝 24号字体


extern lv_style_t style_main_menu_btn_default;      //导航按钮的默认格式
extern lv_style_t style_main_menu_btn_disable;      //导航按钮的禁用格式
extern lv_style_t style_background_btn_default;     //背景按钮格式
extern lv_style_t style_background2_btn_default;    //背景上的背景按钮格式
extern lv_style_t style_background3_btn_default;    //专用于移动轴的背景按钮格式
extern lv_style_t style_normal_btn_default;         //通用按钮的默认格式
extern lv_style_t style_normal_btn_pressed;         //通用按钮的禁用格式
extern lv_style_t style_fillet_btn_default;         //圆角按钮的默认格式
extern lv_style_t style_fillet_btn_pressed;         //圆角按钮的禁用格式
extern lv_style_t style_btn_as_text_default;        //按钮带显示文本的格式
extern lv_style_t style_hidden_btn_default;         //隐藏按钮格式
extern lv_style_t style_unit_btn_default;           //轴移动单位按钮默认格式
extern lv_style_t style_unit_btn_pressed;           //轴移动单位按钮选中格式

extern lv_style_t style_white32_text_default;       //label格式 白色 32号字体
extern lv_style_t style_color32_text_default;       //温度显示的彩色字体，32号字体
extern lv_style_t style_white28_text_default;       //label格式 白色 28号字体
extern lv_style_t style_color28_text_default;       //label格式 彩色 28号字体
extern lv_style_t style_white24_text_default;       //label格式 白色 24号字体

extern lv_style_t style_black24_text_default;       //label格式 黑色 24号字体
extern lv_style_t style_grey24_text_default;        //label格式 灰色 24号字体

extern lv_style_t style_bar_progress_default;       //进度条格式
extern lv_style_t style_bar_progress_indicator_default;

extern lv_style_t style_cb_default;                 //复选框格式
extern lv_style_t style_cb_indicator_default;

extern lv_style_t btnstyle_check_default;           //btn被选中
extern lv_style_t btnstyle_uncheck_default;         //btn未被选中
extern lv_style_t labelstyle_check_default;         //label灰色被选中
extern lv_style_t labelstyle_uncheck_default;       //label灰色未被选中
extern lv_style_t labelstyle_opa_default;           //label透明格式

/*************************字体文件******************************/

extern lv_ft_info_t lv_font14;
extern lv_ft_info_t lv_font18;
extern lv_ft_info_t lv_font22;
extern lv_ft_info_t lv_font24;
extern lv_ft_info_t lv_font25;
extern lv_ft_info_t lv_font26;
extern lv_ft_info_t lv_font28;
extern lv_ft_info_t lv_font30;
extern lv_ft_info_t lv_font32;

/*************************字体文件******************************/

void mystyle_init();

#endif /* _ */
