#include "ui_Screen_ExcludeObject.h"

lv_obj_t * ui_ExcludeObject;
lv_obj_t * ui_ExcludeObjectPanel1;
lv_obj_t * ui_ExcludeObjectImage1;
lv_obj_t * ui_ExcludeObjectImage2;
lv_obj_t * ui_ExcludeObjectImage3;
lv_obj_t * ui_ExcludeObjectImage4;
lv_obj_t * ui_ExcludeObjectImage5;
lv_obj_t * ui_ExcludeObjectPanel2;
lv_obj_t * ui_ExcludeObjectPanel3;
lv_obj_t * ui_ExcludeObjectBtnBg;
lv_obj_t * ui_LabelTitle;
lv_obj_t * ui_PanelLine;
lv_obj_t * ui_ExcludeObjectCanvas;
lv_obj_t * ui_LayersBg;
lv_obj_t * ui_LabelFilename;
lv_obj_t * ui_Labellayers;
lv_obj_t * ui_LayersImg;
lv_obj_t * ui_LabelBack;
lv_obj_t * ui_ButtonBack;
lv_obj_t * ui_LabelCancel;
lv_obj_t * ui_ButtonCancel;


lv_draw_line_dsc_t line_dsc_normal;
lv_draw_line_dsc_t line_dsc_cancel;
lv_draw_line_dsc_t line_dsc_printing;
lv_draw_line_dsc_t line_dsc_fcous;

lv_draw_img_dsc_t img_dsc_normal;

CurrentExclueObject_t currentExclueObject = {0};
Exclueobject_t * exclueObjects = NULL;  //用于保存从后台解析的数据

void refresh_excludeobject(Exclueobject_t * points, int point_count);
void excludeobjcet_handle(lv_event_t * e);
void ui_event_ExcludePageBtn_Handle(lv_event_t * e);
void ui_event_PageChange(lv_event_t * e);
void ui_event_PageLoad(lv_event_t * e);

Exclueobject_t * analyze_objectdata(char * data);

#define IMGOFFSET 22

void ui_ExcludeObject_screen_init(void)
{
    ui_ExcludeObject = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ExcludeObject, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ExcludeObjectPanel1 = lv_obj_create(ui_ExcludeObject);
    lv_obj_set_width(ui_ExcludeObjectPanel1, 80);
    lv_obj_set_height(ui_ExcludeObjectPanel1, 480);
    lv_obj_clear_flag(ui_ExcludeObjectPanel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExcludeObjectPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ExcludeObjectPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExcludeObjectPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ExcludeObjectPanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ExcludeObjectPanel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExcludeObjectPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ExcludeObjectPanel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExcludeObjectImage1 = lv_img_create(ui_ExcludeObjectPanel1);
    lv_img_set_src(ui_ExcludeObjectImage1, &ui_img_pagehomeselected_png);
    lv_obj_set_width(ui_ExcludeObjectImage1, 80);
    lv_obj_set_height(ui_ExcludeObjectImage1, 96);
    lv_obj_add_flag(ui_ExcludeObjectImage1, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_ExcludeObjectImage2 = lv_img_create(ui_ExcludeObjectPanel1);
    lv_img_set_src(ui_ExcludeObjectImage2, &ui_img_pagemove_png);
    lv_obj_set_width(ui_ExcludeObjectImage2, 80);
    lv_obj_set_height(ui_ExcludeObjectImage2, 96);
    lv_obj_set_x(ui_ExcludeObjectImage2, 0);
    lv_obj_set_y(ui_ExcludeObjectImage2, 96);
    lv_obj_add_flag(ui_ExcludeObjectImage2, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_ExcludeObjectImage3 = lv_img_create(ui_ExcludeObjectPanel1);
    lv_img_set_src(ui_ExcludeObjectImage3, &ui_img_pagefilemanage_png);
    lv_obj_set_width(ui_ExcludeObjectImage3, 80);
    lv_obj_set_height(ui_ExcludeObjectImage3, 96);
    lv_obj_set_x(ui_ExcludeObjectImage3, 0);
    lv_obj_set_y(ui_ExcludeObjectImage3, 192);
    lv_obj_add_flag(ui_ExcludeObjectImage3, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_ExcludeObjectImage4 = lv_img_create(ui_ExcludeObjectPanel1);
    lv_img_set_src(ui_ExcludeObjectImage4, &ui_img_pagesetting_png);
    lv_obj_set_width(ui_ExcludeObjectImage4, 80);
    lv_obj_set_height(ui_ExcludeObjectImage4, 96);
    lv_obj_set_x(ui_ExcludeObjectImage4, 0);
    lv_obj_set_y(ui_ExcludeObjectImage4, 288);
    lv_obj_add_flag(ui_ExcludeObjectImage4, LV_OBJ_FLAG_CLICKABLE);     /// Flags
    lv_obj_clear_flag(ui_ExcludeObjectImage4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ExcludeObjectImage5 = lv_img_create(ui_ExcludeObjectPanel1);
    lv_img_set_src(ui_ExcludeObjectImage5, &ui_img_pagereserve_png);
    lv_obj_set_width(ui_ExcludeObjectImage5, 80);
    lv_obj_set_height(ui_ExcludeObjectImage5, 96);
    lv_obj_set_x(ui_ExcludeObjectImage5, 0);
    lv_obj_set_y(ui_ExcludeObjectImage5, 384);
    lv_obj_add_flag(ui_ExcludeObjectImage5, LV_OBJ_FLAG_CLICKABLE);     /// Flags

    ui_ExcludeObjectPanel2 = lv_obj_create(ui_ExcludeObject);
    lv_obj_set_width(ui_ExcludeObjectPanel2, 720);
    lv_obj_set_height(ui_ExcludeObjectPanel2, 480);
    lv_obj_align(ui_ExcludeObjectPanel2, LV_ALIGN_TOP_LEFT, 80, 0);
    lv_obj_clear_flag(ui_ExcludeObjectPanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExcludeObjectPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ExcludeObjectPanel2, lv_color_hex(0x232426), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExcludeObjectPanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExcludeObjectPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ExcludeObjectPanel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ExcludeObjectPanel3 = lv_obj_create(ui_ExcludeObjectPanel2);
    lv_obj_set_width(ui_ExcludeObjectPanel3, 696);
    lv_obj_set_height(ui_ExcludeObjectPanel3, 456);
    lv_obj_center(ui_ExcludeObjectPanel3);
    lv_obj_clear_flag(ui_ExcludeObjectPanel3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExcludeObjectPanel3, 6 , LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ExcludeObjectPanel3, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExcludeObjectPanel3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExcludeObjectPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ExcludeObjectPanel3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelTitle = lv_label_create(ui_ExcludeObjectPanel3);
    lv_obj_set_width(ui_LabelTitle, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTitle, LV_SIZE_CONTENT);
    lv_obj_align(ui_LabelTitle, LV_ALIGN_TOP_LEFT, 26, 26);
    lv_label_set_text(ui_LabelTitle, ExcludeObjects[get_cur_language_index()]);
    lv_obj_set_style_text_color(ui_LabelTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PanelLine = lv_obj_create(ui_ExcludeObjectPanel3);
    lv_obj_set_width(ui_PanelLine, 665);
    lv_obj_set_height(ui_PanelLine, 1);
    lv_obj_align(ui_PanelLine, LV_ALIGN_TOP_LEFT, 18, 67);
    lv_obj_set_style_radius(ui_PanelLine, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_PanelLine, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_PanelLine, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_PanelLine, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    static lv_color_t cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(CANVAS_WIDTH, CANVAS_HEIGHT)];

    ui_ExcludeObjectCanvas = lv_canvas_create(ui_ExcludeObjectPanel3);
    lv_canvas_set_buffer(ui_ExcludeObjectCanvas, cbuf, CANVAS_WIDTH, CANVAS_HEIGHT, LV_IMG_CF_TRUE_COLOR);
    lv_obj_align(ui_ExcludeObjectCanvas, LV_ALIGN_TOP_LEFT, 26, 90);
    lv_canvas_fill_bg(ui_ExcludeObjectCanvas, lv_color_hex(0x58595C), LV_OPA_COVER);

    ui_ExcludeObjectBtnBg = lv_obj_create(ui_ExcludeObjectPanel3);
    lv_obj_set_width(ui_ExcludeObjectBtnBg, 300);
    lv_obj_set_height(ui_ExcludeObjectBtnBg, 300);
    lv_obj_align(ui_ExcludeObjectBtnBg, LV_ALIGN_TOP_LEFT, 26, 90);
    lv_obj_clear_flag(ui_ExcludeObjectBtnBg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ExcludeObjectBtnBg, 0 , LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ExcludeObjectBtnBg, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ExcludeObjectBtnBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ExcludeObjectBtnBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ExcludeObjectBtnBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFilename = lv_label_create(ui_ExcludeObjectPanel3);
    lv_obj_set_width(ui_LabelFilename, 270);
    lv_obj_set_height(ui_LabelFilename, LV_SIZE_CONTENT);
    lv_obj_align(ui_LabelFilename, LV_ALIGN_TOP_LEFT, 412, 85);
    lv_label_set_text(ui_LabelFilename, "");
    lv_obj_set_style_text_color(ui_LabelFilename, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelFilename, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LayersBg = lv_obj_create(ui_ExcludeObjectPanel3);
    lv_obj_set_width(ui_LayersBg, 270);
    lv_obj_set_height(ui_LayersBg, 100);
    lv_obj_align(ui_LayersBg, LV_ALIGN_TOP_LEFT, 412, 127);
    lv_obj_clear_flag(ui_LayersBg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_LayersBg, 0 , LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_LayersBg, lv_color_hex(0x2D2E31), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_LayersBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_LayersBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_LayersBg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LayersImg = lv_img_create(ui_LayersBg);
    lv_obj_set_width(ui_LayersImg, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LayersImg, LV_SIZE_CONTENT);
    lv_obj_align(ui_LayersImg, LV_ALIGN_TOP_LEFT, 0, 0);
    char imgsrc[256] = {0};
    snprintf(imgsrc, 256, "S:%s/%s", GetK1ImageResourcePtah(), "layers.png");
    lv_img_set_src(ui_LayersImg, imgsrc);

    ui_Labellayers = lv_label_create(ui_LayersBg);
    lv_obj_set_width(ui_Labellayers, 270);
    lv_obj_set_height(ui_Labellayers, LV_SIZE_CONTENT);
    lv_obj_align_to(ui_Labellayers, ui_LayersImg, LV_ALIGN_OUT_RIGHT_MID, 10, -10);
    lv_label_set_text(ui_Labellayers, "");
    lv_obj_set_style_text_color(ui_Labellayers, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Labellayers, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonBack = lv_btn_create(ui_ExcludeObjectPanel3);
    lv_obj_set_width(ui_ButtonBack, 116);
    lv_obj_set_height(ui_ButtonBack, 60);
    lv_obj_set_x(ui_ButtonBack, 406);
    lv_obj_set_y(ui_ButtonBack, 381);
    lv_obj_clear_flag(ui_ButtonBack, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonBack, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonBack, lv_color_hex(0x28292D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonBack, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonBack, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ButtonBack, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ButtonBack, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelBack = lv_label_create(ui_ButtonBack);
    lv_obj_set_width(ui_LabelBack, 116);
    lv_obj_set_height(ui_LabelBack, 30);
    lv_obj_set_align(ui_LabelBack, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelBack, Back[get_cur_language_index()]);
    lv_obj_set_style_text_align(ui_LabelBack, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBack, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonCancel = lv_btn_create(ui_ExcludeObjectPanel3);
    lv_obj_set_width(ui_ButtonCancel, 146);
    lv_obj_set_height(ui_ButtonCancel, 60);
    lv_obj_set_x(ui_ButtonCancel, 536);
    lv_obj_set_y(ui_ButtonCancel, 381);
    lv_obj_clear_flag(ui_ButtonCancel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ButtonCancel, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonCancel, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_ButtonCancel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_ButtonCancel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelCancel = lv_label_create(ui_ButtonCancel);
    lv_obj_set_width(ui_LabelCancel, 116);
    lv_obj_set_height(ui_LabelCancel, 30);
    lv_obj_set_align(ui_LabelCancel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelCancel, Delete[get_cur_language_index()]);
    lv_obj_set_style_text_align(ui_LabelCancel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelCancel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    //绑定事件
    lv_obj_add_event_cb(ui_ButtonCancel, ui_event_ExcludePageBtn_Handle, LV_EVENT_ALL, "1");
    lv_obj_add_event_cb(ui_ButtonBack, ui_event_ExcludePageBtn_Handle, LV_EVENT_ALL, "2");
    lv_obj_add_event_cb(ui_ExcludeObjectImage2, ui_event_PageChange, LV_EVENT_ALL, "2");
    lv_obj_add_event_cb(ui_ExcludeObjectImage3, ui_event_PageChange, LV_EVENT_ALL, "3");
    lv_obj_add_event_cb(ui_ExcludeObjectImage4, ui_event_PageChange, LV_EVENT_ALL, "4");
    lv_obj_add_event_cb(ui_ExcludeObjectImage5, ui_event_PageChange, LV_EVENT_ALL, "5");
    lv_obj_add_event_cb(ui_ExcludeObjectImage5, ui_event_PageLoad, LV_EVENT_ALL, NULL);

    lv_draw_line_dsc_init(&line_dsc_normal);
    line_dsc_normal.color = lv_color_hex(0xC9C9C9);
    line_dsc_normal.width = 2;

    lv_draw_line_dsc_init(&line_dsc_cancel);
    line_dsc_cancel.color = lv_color_hex(0xFF6163);
    line_dsc_cancel.width = 2;

    lv_draw_line_dsc_init(&line_dsc_printing);
    line_dsc_printing.color = lv_color_hex(0x49FABE);
    line_dsc_printing.width = 2;

    lv_draw_line_dsc_init(&line_dsc_fcous);
    line_dsc_fcous.color = lv_color_hex(0x4CD2EF);
    line_dsc_fcous.width = 2;

    lv_draw_img_dsc_init(&img_dsc_normal);

    for(int i = 0; i < 10; i++)
    {
        lv_point_t points[2] = {{30*i, 0}, {30*i, 300}};
        lv_canvas_draw_line(ui_ExcludeObjectCanvas, points, 2, &line_dsc_normal);

        lv_point_t points1[2] = {{0, 30*i}, {300, 30*i}};
        lv_canvas_draw_line(ui_ExcludeObjectCanvas, points1, 2, &line_dsc_normal);
    }
}

void refresh_excludeobject(Exclueobject_t * points, int point_count)
{
    //清除上一次的按钮控件及事件
    lv_obj_clean(ui_ExcludeObjectBtnBg);
    currentExclueObject.ObjectCount = point_count;
    currentExclueObject.CurrentObject = -1;

    //重置删除键状态
    lv_obj_clear_flag(ui_ButtonCancel, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_bg_color(ui_ButtonCancel, lv_color_hex(0x58595C), LV_PART_MAIN | LV_STATE_DEFAULT);

    //画布初始化
    lv_canvas_fill_bg(ui_ExcludeObjectCanvas, lv_color_hex(0x58595C), LV_OPA_COVER);
    for(int i = 0; i < 10; i++)
    {
        lv_point_t points[2] = {{30*i, 0}, {30*i, 300}};
        lv_canvas_draw_line(ui_ExcludeObjectCanvas, points, 2, &line_dsc_normal);

        lv_point_t points1[2] = {{0, 30*i}, {300, 30*i}};
        lv_canvas_draw_line(ui_ExcludeObjectCanvas, points1, 2, &line_dsc_normal);
    }

    for(int i = 0; i < point_count; i++)
    {
        lv_draw_line_dsc_t line_mode;
        lv_draw_line_dsc_init(&line_mode);

        char imgsrc[256] = {0};
        if(points[i].state == NormalState)
        {
            line_mode = line_dsc_normal;
            snprintf(imgsrc, 256, "S:%s/%s", GetK1ImageResourcePtah(), "objectStateNormal.png");
        }
        else if(points[i].state == CancelState)
        {
            line_mode = line_dsc_cancel;
            snprintf(imgsrc, 256, "S:%s/%s", GetK1ImageResourcePtah(), "objectStateCancle.png");
        }
        else if(points[i].state == PrintingState)
        {
            line_mode = line_dsc_printing;
            snprintf(imgsrc, 256, "S:%s/%s", GetK1ImageResourcePtah(), "objectStatePrinting.png");
        }
        else if(points[i].state == FocusState)
        {
            line_mode = line_dsc_fcous;
            snprintf(imgsrc, 256, "S:%s/%s", GetK1ImageResourcePtah(), "objectStateFocus.png");
        }

        //画单个点的矩形边框(根据点的状态)
        lv_canvas_draw_line(ui_ExcludeObjectCanvas, points[i].point, POINTSCOUNT, &line_mode);

        //绘制中心的图标(根据点的状态)
        CrLogI("%s %d %d", imgsrc, points[i].center.x, points[i].center.y);
        lv_canvas_draw_img(ui_ExcludeObjectCanvas, points[i].center.x - IMGOFFSET, points[i].center.y - IMGOFFSET, imgsrc, &img_dsc_normal);

        //增加一个透明的btn按钮
        lv_obj_t * canvasBtn = lv_btn_create(ui_ExcludeObjectBtnBg);
        lv_obj_set_width(canvasBtn, 50);
        lv_obj_set_height(canvasBtn, 50);
        lv_obj_align(canvasBtn, LV_ALIGN_TOP_LEFT, points[i].center.x - IMGOFFSET , points[i].center.y - IMGOFFSET);
        lv_obj_clear_flag(canvasBtn, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(canvasBtn, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(canvasBtn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(canvasBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(canvasBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_color(canvasBtn, lv_color_hex(0x60FF8B), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_opa(canvasBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(canvasBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(canvasBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        points[i].currentNumber = i;
        
        //绑定按钮的事件
        lv_obj_add_event_cb(canvasBtn, excludeobjcet_handle, LV_EVENT_ALL, &points[i]);
    }

    // //之前在解析时申请内存,刷新完数据需要回收
    // lv_mem_free(points);
}

void excludeobjcet_handle(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    Exclueobject_t * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED)
    {
        if(userdata->state == PrintingState || userdata->state == CancelState)
        {
            return;
        }
        //记录当前选中的点
        currentExclueObject.CurrentObject = userdata->currentNumber;
        //更改删除键状态
        lv_obj_add_flag(ui_ButtonCancel, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_style_bg_color(ui_ButtonCancel, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);

        //更新状态
        userdata->state = FocusState;

        //画单个点的矩形边框(根据点的状态)
        lv_canvas_draw_line(ui_ExcludeObjectCanvas, (*userdata).point, POINTSCOUNT, &line_dsc_fcous);  

        //绘制中心的图标(根据点的状态)
        char imgsrc[256] = {0};
        snprintf(imgsrc, 256, "S:%s/%s", GetK1ImageResourcePtah(), "objectStateFocus.png");
        lv_canvas_draw_img(ui_ExcludeObjectCanvas, userdata->center.x - IMGOFFSET, userdata->center.y - IMGOFFSET, imgsrc, &img_dsc_normal);
    }
}

Exclueobject_t * analyze_objectdata(char * data)
{
    //判断数据是否有效
    if(data == NULL)return;

    //取json数据
    json_object * objectInfo = json_tokener_parse(data);
    if (objectInfo == NULL ) {
        CrLogW("get file info obj fail\n");
        json_object_put(objectInfo);
        return;
    }

    //获取所有对象
    // json_object *objects = GetJsonObject(objectInfo, "objects", json_type_array);
    json_object *objects = json_object_object_get(objectInfo, "objects");
    if (objects == NULL ) {
        CrLogW("get file id obj fail\n");
        json_object_put(objectInfo);
        return;
    }

    //获取对象总数
    int count = 0;
    if(json_object_is_type(objects, json_type_array))
    {
        count = json_object_array_length(objects);
        CrLogI("exclueObjects count%d\n", count);
    }
    else
    {
        change_exclueobject_state(false);
        json_object_put(objectInfo);
        return;
    }

    change_exclueobject_state(true);
    if(exclueObjects == NULL)
        exclueObjects = (Exclueobject_t *)lv_mem_alloc(sizeof(Exclueobject_t) * count);
    else
        exclueObjects = (Exclueobject_t *)lv_mem_realloc(exclueObjects, sizeof(Exclueobject_t) * count);

    //循环获取每个对象的具体数据
    //循环提取记录
    for (int i = 0; i < count; i++)
    {
        json_object *singleObject = json_object_array_get_idx(objects, i);
        //模型名
        const char *objectName = json_object_get_string(json_object_object_get(singleObject, "name"));
        if (!objectName) {
            CrLogW("get objectName object fail\n");
            json_object_put(objects);
            return -1;
        }

        if(strlen(objectName) < 64)
            strcpy(exclueObjects[i].singeObjectName, objectName);
        else
            CrLogW("singeObjectName lenth is too long:%s",objectName);

        //中心点坐标
        json_object *objectCenter  = json_object_object_get(singleObject, "center");
        if (!objectCenter) {
            CrLogW("get objectCenter object fail\n");
            json_object_put(objects);
            return -1;
        }

        exclueObjects[i].center.x = json_object_get_int(json_object_array_get_idx(objectCenter, 0));
        exclueObjects[i].center.y = json_object_get_int(json_object_array_get_idx(objectCenter, 1));
        CrLogI("singeObjectName centerX:%d, singeObjectName centerY:%d", exclueObjects[i].center.x, exclueObjects[i].center.y);

        //各个坐标点
        json_object *objectPolygon = json_object_object_get(singleObject, "polygon");
        if (!objectPolygon) {
            CrLogW("get objectPolygon object fail\n");
            json_object_put(objects);
            return -1;
        }

        for(int j = 0; j < json_object_array_length(objects); j++)
        {
            exclueObjects[i].point[j].x = json_object_get_int(json_object_array_get_idx(json_object_array_get_idx(objectPolygon, j), 0));
            exclueObjects[i].point[j].y = json_object_get_int(json_object_array_get_idx(json_object_array_get_idx(objectPolygon, j), 1));
            CrLogI("polygonx:%d, polygony:%d", exclueObjects[i].point[j].x, exclueObjects[i].point[j].y);
        }

        //状态赋初值
        exclueObjects[i].state = NormalState;
    }

    //获取已被排除的对象名称
    json_object *disableObject = json_object_object_get(objectInfo, "excluded_objects");
    if (!disableObject) {
        CrLogW("get disableObject object fail\n");
        json_object_put(objectInfo);
        return -1;
    }

    int disablecount = 0;
    if(json_object_is_type(disableObject, json_type_array))
    {
        disablecount = json_object_array_length(disableObject);
    }
    for (int i = 0; i < disablecount; i++)
    {
        const char * tempName = json_object_get_string(json_object_array_get_idx(disableObject, i));
        CrLogI("disableObject Name:%s", tempName);
        for(int j = 0; j < count; j++)
        {
            if(strcmp(exclueObjects[j].singeObjectName, tempName) == 0)
            {
                exclueObjects[j].state = CancelState;
                break;
            }
        }
    }

    //获取当前执行的对象名称
    json_object *currentObject = json_object_object_get(objectInfo, "current_object");
    if (!currentObject) {
        CrLogW("get currentObject object fail\n");
        json_object_put(objectInfo);
        return -1;
    }

    const char * currentObjectName = json_object_get_string(currentObject);
    for(int j = 0; j < count; j++)
    {
        if(strcmp(exclueObjects[j].singeObjectName, currentObjectName) == 0)
        {
            exclueObjects[j].state = PrintingState;
            CrLogI("current_object Name:%s", currentObjectName);
            break;
        }
    }

    // 完成解析，刷新状态退出
    refresh_excludeobject(exclueObjects, count);
    json_object_put(objectInfo);
}

void ui_event_ExcludePageBtn_Handle(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    char * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        switch (userdata[0])
        {
            case '1':
            {
                //发送指令
                if(currentExclueObject.CurrentObject != -1 && exclueObjects != NULL)
                {
                    char tempbuff[256] = {0};
                    snprintf(tempbuff, 256, "c%s", exclueObjects[currentExclueObject.CurrentObject].singeObjectName);
                    set_printer_data(CONTROL_MACHINE_STATE, strlen(tempbuff), tempbuff);
                }
                break;
            }
            case '2':
            {
                home_printing_is_printing_finished() ? ui_change(PAGE_HOME) : ui_change(PAGE_HOME_PRINT);
                break;
            }
            default:break;
        }
    }

}

void ui_event_PageChange(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    char * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        switch(atoi(userdata))
        {
            case PAGE_HOME:home_printing_is_printing_finished() ? ui_change(PAGE_HOME) : ui_change(PAGE_HOME_PRINT);break;
            case PAGE_AXIS:ui_change(PAGE_AXIS);break;
            case PAGE_FILEMANAGE:ui_change(PAGE_FILEMANAGE);break;
            case PAGE_SETING:ui_change(PAGE_SETING);break;
            case PAGE_HELP:ui_change(PAGE_HELP);break;
            default:
                break;
        }
    }
}

void ui_event_PageLoad(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    char * userdata = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        CrLogI("load ExcludeObject page");
    }
}

void refreshExcludeObjectPage(char * data)
{
    if(data == NULL)
    {
        CrLogW("excluedeobject data is null");
        return;
    }
    CrLogW("excluedeobject data is null:%s",data);

    //解析排除对象数据
    analyze_objectdata(data);

    //层数数据刷新
    char tempbuff[256] = {0};
    snprintf(tempbuff, 256, "%s %d/%d", Layers[get_cur_language_index()], print_job.currentlayer, print_job.layercount);
    lv_label_set_text(ui_Labellayers, tempbuff);

    //任务数据刷新
    lv_label_set_text(ui_LabelFilename, print_job.printfile_name);

}