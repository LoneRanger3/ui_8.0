#include "ui_custom_messagebox.h"
#include "src/core/lv_obj_pos.h"
#include "src/core/lv_obj_tree.h"
#include "src/widgets/lv_label.h"
#include "ui.h"
#include "ui_helpers.h"
#include <stdio.h>
#include <string.h>

static lv_obj_t     *messagebox_panel = NULL;
static lv_style_t   style_cont_msgbox1;
static lv_obj_t     *btn_array[3] = {NULL, NULL, NULL};
static lv_obj_t     *btn_text_array[3] = {NULL, NULL, NULL};
static lv_obj_t     *messagebox_title = NULL;
static lv_obj_t     *messagebox_text = NULL;
static lv_obj_t     *messagebox_close_btn = NULL;
static void (*messagebox_btn_callback_array[3])(void) = {NULL, NULL, NULL};

#define BTN_WIDTH  130
#define BTN_HEIGHT 50 //50
#define MSG_BOX_WIDTH 390
#define MSG_BOX_HEIGHT 300

// static lv_style_t style_cont_msgbox;
// static lv_style_t style_img_default;
// static lv_style_t style_white24_text_creality;
// static lv_style_t style_normal_btn_default;

static lv_color_t btn_default_bk_color;
static lv_color_t btn_default_text_color;


static void messagebox_close_event_handler(lv_event_t * e);
static void messagebox_btn1_click_event_handler(lv_event_t * e);
static void messagebox_btn2_click_event_handler(lv_event_t * e);
static void messagebox_btn3_click_event_handler(lv_event_t * e);

void messagebox_close_event_handler(lv_event_t * e)
{
    static char input_str[15] = {'\0'};
    static int len = 0;
    int tint = 0;
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            messagebox_close();
        }
        break;
        default:
		break;
	}
}

void messagebox_btn1_click_event_handler(lv_event_t * e)
{
    static char input_str[15] = {'\0'};
    static int len = 0;
    int tint = 0;
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            messagebox_close();

            if ( messagebox_btn_callback_array[0] )
                messagebox_btn_callback_array[0]();
        }
        break;
        default:
		break;
	}
}

void messagebox_btn2_click_event_handler(lv_event_t * e)
{
    static char input_str[15] = {'\0'};
    static int len = 0;
    int tint = 0;
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            messagebox_close();
            if ( messagebox_btn_callback_array[1] )
                messagebox_btn_callback_array[1]();
        }
        break;
        default:
		break;
	}
}

void messagebox_btn3_click_event_handler(lv_event_t * e)
{
    static char input_str[15] = {'\0'};
    static int len = 0;
    int tint = 0;
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            messagebox_close();

            if ( messagebox_btn_callback_array[2] )
                messagebox_btn_callback_array[2]();
        }
        break;
        default:
		break;
	}
}


void layout_btns(bool dir_hor, int btn_vailed_count, bool show_message)
{
    if ( btn_vailed_count > 3 )
        btn_vailed_count = 3;

    if ( btn_vailed_count < 0 )
        btn_vailed_count = 0;

    int space = 0;
    int hor_start_offset, ver_start_offset;
    if ( dir_hor )  //横向
    {
        space = (MSG_BOX_WIDTH - btn_vailed_count * BTN_WIDTH) / (btn_vailed_count + 1);  // 360 is message width, 100 is btn width
        if ( space < 0 )
            space = 0;

        hor_start_offset = space - 22;  // -22 is messagebox hor start pos
        if ( btn_vailed_count == 1 )
            ver_start_offset = 200 - 22;    // btn special pos
        else
            ver_start_offset = 228 - 22;    // this offset is default pos
    }
    else  // 纵向
    {
        if ( show_message )
        {
            // 300 is messagebox height, 150 is message lebel bottom offset to messagebox top , 50 is btn height
            space = (MSG_BOX_HEIGHT -150 - btn_vailed_count * BTN_HEIGHT ) / (btn_vailed_count + 1);
            ver_start_offset = 150 + space - 22;  // this offset is default pos
        }
        else
        {
            // 300 is messagebox height, 70 is message lebel top offset to messagebox top , 50 is btn height
            space = (MSG_BOX_HEIGHT -70 - btn_vailed_count * BTN_HEIGHT ) / (btn_vailed_count + 1); 
            ver_start_offset = 70 + space - 22;  // this offset is default pos 
        }

        hor_start_offset = (MSG_BOX_WIDTH -  BTN_WIDTH) / 2 - 22;  // this offset is default pos of mid button
        //ver_start_offset = 150 + space - 22;  // this offset is default pos
    }
    

    for(int i = 0; i < 3; i++)
    {
        if ( i < btn_vailed_count )
        {
            lv_obj_clear_flag(btn_array[i], LV_OBJ_FLAG_HIDDEN);     /// Flags
            lv_obj_add_flag(btn_array[i], LV_OBJ_FLAG_CLICKABLE);     /// Flags

            if ( dir_hor )
            {
                lv_obj_set_y(btn_array[i], ver_start_offset);
                lv_obj_set_x(btn_array[i], hor_start_offset + (BTN_WIDTH + space) * i );
            }
            else
            {
                lv_obj_set_y(btn_array[i], ver_start_offset + (BTN_HEIGHT + space) * i);
                lv_obj_set_x(btn_array[i], hor_start_offset );
            }
        }
        else
        {
            lv_obj_add_flag(btn_array[i], LV_OBJ_FLAG_HIDDEN);     /// Flags
            lv_obj_clear_flag(btn_array[i], LV_OBJ_FLAG_CLICKABLE);     /// Flags
        }
        
        // lv_obj_set_style_bg_color(btn_array[i],btn_default_bk_color, LV_PART_MAIN|LV_STATE_DEFAULT);
        // lv_obj_set_style_text_color(btn_array[i],btn_default_text_color, LV_PART_MAIN|LV_STATE_DEFAULT);
    }

    if ( btn_vailed_count == 2 && dir_hor )
    {
        lv_obj_set_x(btn_array[0], 30 - 22 );
        lv_obj_set_x(btn_array[1], MSG_BOX_WIDTH - BTN_WIDTH - 30 -22 );
    }
}

void messagebox_close()
{
    DeinitPopoutManager(&BtnDialogPopout);
    lv_obj_add_flag(messagebox_panel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_bg_opa(lv_layer_top(), 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(messagebox_panel, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(messagebox_panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    if (IsThereAnyPopout())
    {
        ManagePopoutFocus();
    }
    // else
    // {
    //     BackPrepage(true);
    // }
}

void CustomMessageboxAddObjsToGroup(void)
{
    lv_group_focus_freeze(encoder_group, false); //用于解决导航按钮加冻结后解冻前，错误弹框无法聚焦的情况
    lv_group_remove_all_objs(encoder_group);

    if (BtnDialogPopout.obj1_flag)
        lv_group_add_obj(encoder_group, btn_array[0]);
    if (BtnDialogPopout.obj2_flag)
        lv_group_add_obj(encoder_group, btn_array[1]);
    if (BtnDialogPopout.obj3_flag)
        lv_group_add_obj(encoder_group, btn_array[2]);
}

void create_custom_messagebox(char *title, char *message, char *btns[3], void(*btns_callback_array[3])(void), int btn_count, bool arrangement_method_hor, bool show_close_btn)
{
    ///////////////////// VARIABLES ////////////////////
    if (messagebox_panel && !lv_obj_has_flag(messagebox_panel, LV_OBJ_FLAG_HIDDEN))
    {
        return;
    }
    //创建前记录之前的聚焦对象，如果前面有弹框，那么就不用记录
    if (!IsThereAnyPopout())
    {
        RecordObjBeforePopup();
    }

    
    if ( messagebox_panel == NULL )
    {
        /**************************************************/
        btn_default_bk_color = lv_color_hex(0x50535A);
        btn_default_text_color = lv_color_hex(0xFFFFFF);

        /*********************create ctrls******************************/
        lv_obj_t * ui_PanelMessageBox;
        lv_obj_t * ui_LabelTitle;
        lv_obj_t * ui_LabelMessage;
        lv_obj_t * ui_BtnAreaPanel; 
        lv_obj_t * ui_Button1;
        lv_obj_t * ui_Label1;
        lv_obj_t * ui_Button2;
        lv_obj_t * ui_Label2;
        lv_obj_t * ui_Button3;
        lv_obj_t * ui_Label3;

        ui_PanelMessageBox = lv_obj_create(lv_layer_top());
        messagebox_panel = ui_PanelMessageBox;
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_width(ui_PanelMessageBox, 371);
        lv_obj_set_height(ui_PanelMessageBox, 285);
        lv_obj_set_align(ui_PanelMessageBox, LV_ALIGN_CENTER);
        lv_obj_clear_flag(ui_PanelMessageBox, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_PanelMessageBox, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_PanelMessageBox, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_PanelMessageBox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_side(ui_PanelMessageBox, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_PanelMessageBox, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        //关闭按钮
        lv_obj_t *ui_ButtonClose = lv_btn_create(ui_PanelMessageBox);
        lv_obj_set_width(ui_ButtonClose, 23);
        lv_obj_set_height(ui_ButtonClose, 23);
        lv_obj_set_x(ui_ButtonClose, -20);
        lv_obj_set_y(ui_ButtonClose, -2);
        lv_obj_add_flag(ui_ButtonClose, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ButtonClose, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_ButtonClose, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_ButtonClose, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ButtonClose, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        // lv_obj_set_style_bg_img_src(ui_ButtonClose, &_group_1453_23x23, LV_PART_MAIN | LV_STATE_DEFAULT);
        messagebox_close_btn = ui_ButtonClose;

        //弹框标题
        ui_LabelTitle = lv_label_create(ui_PanelMessageBox);
        messagebox_title = ui_LabelTitle;
        lv_obj_set_width(ui_LabelTitle, LV_SIZE_CONTENT);
        lv_obj_set_height(ui_LabelTitle, LV_SIZE_CONTENT);
        lv_obj_align(ui_LabelTitle, LV_ALIGN_TOP_MID, 0, 8);
        lv_obj_set_style_text_color(ui_LabelTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_LabelTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_LabelTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_LabelTitle, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_long_mode(ui_LabelTitle, LV_LABEL_LONG_SCROLL_CIRCULAR);

        //弹框内容
        ui_LabelMessage = lv_label_create(ui_PanelMessageBox);
        messagebox_text = ui_LabelMessage;
        lv_obj_set_width(ui_LabelMessage, 327);
        lv_obj_set_height(ui_LabelMessage, 78);
        lv_obj_align(ui_LabelMessage, LV_ALIGN_TOP_MID, 0, 80);
        lv_label_set_recolor(ui_LabelMessage, true);
        lv_obj_set_style_text_color(ui_LabelMessage, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_LabelMessage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_LabelMessage, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_LabelMessage, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        //按钮区域面板
        ui_BtnAreaPanel = lv_obj_create(ui_PanelMessageBox);
        lv_obj_set_width(ui_BtnAreaPanel, 371);
        lv_obj_set_height(ui_BtnAreaPanel, 104);
        lv_obj_align(ui_BtnAreaPanel, LV_ALIGN_BOTTOM_MID, 0, 3);
        lv_obj_clear_flag(ui_BtnAreaPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_BtnAreaPanel, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_BtnAreaPanel, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_BtnAreaPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_side(ui_BtnAreaPanel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_pad_all(ui_BtnAreaPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_flex_flow(ui_BtnAreaPanel, LV_FLEX_FLOW_ROW);
        lv_obj_set_flex_align(ui_BtnAreaPanel, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER);

        ui_Button1 = lv_btn_create(ui_BtnAreaPanel);
        lv_obj_set_width(ui_Button1, 144);
        lv_obj_set_height(ui_Button1, 56);
        lv_obj_set_x(ui_Button1, 26);
        lv_obj_set_y(ui_Button1, 220);
        lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_Button1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_Button1, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        //聚焦样式
        lv_obj_set_style_border_color(ui_Button1, lv_color_hex(0xFFFFFF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_border_opa(ui_Button1, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_border_width(ui_Button1, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_outline_pad(ui_Button1, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_outline_color(ui_Button1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        btn_array[0] = ui_Button1;

        ui_Label1 = lv_label_create(ui_Button1);
        lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
        lv_obj_align(ui_Label1, LV_ALIGN_CENTER, 0, -6);
        lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_Label1, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_long_mode(ui_Label1, LV_LABEL_LONG_WRAP);
        lv_obj_set_style_text_align(ui_Label1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        btn_text_array[0] = ui_Label1;

        ui_Button2 = lv_btn_create(ui_BtnAreaPanel);
        lv_obj_set_width(ui_Button2, 144);
        lv_obj_set_height(ui_Button2, 56);
        lv_obj_set_x(ui_Button2, 202);
        lv_obj_set_y(ui_Button2, 220);
        lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_Button2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_Button2, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_Button2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        //聚焦样式
        lv_obj_set_style_border_color(ui_Button2, lv_color_hex(0xFFFFFF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_border_opa(ui_Button2, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_border_width(ui_Button2, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_outline_pad(ui_Button2, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_outline_color(ui_Button2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        btn_array[1] = ui_Button2;

        ui_Label2 = lv_label_create(ui_Button2);
        lv_obj_set_width(ui_Label2, 140);   /// 1
        lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
        lv_obj_align(ui_Label2, LV_ALIGN_CENTER, 0, -6);
        lv_obj_set_style_text_color(ui_Label2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_Label2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_Label2, lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_long_mode(ui_Label2, LV_LABEL_LONG_WRAP);
        lv_obj_set_style_text_align(ui_Label2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_line_space(ui_Label2, -5, LV_PART_MAIN | LV_STATE_DEFAULT);
        btn_text_array[1] = ui_Label2;

        ui_Button3 = lv_btn_create(ui_PanelMessageBox);
        lv_obj_set_width(ui_Button3, BTN_WIDTH);
        lv_obj_set_height(ui_Button3, BTN_HEIGHT);
        lv_obj_set_x(ui_Button3, 233);
        lv_obj_set_y(ui_Button3, 206);
        lv_obj_add_flag(ui_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_Button3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_add_flag(ui_Button3, LV_OBJ_FLAG_HIDDEN);    /// Flags
        lv_obj_set_style_radius(ui_Button3, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        //聚焦样式
        lv_obj_set_style_border_color(ui_Button3, lv_color_hex(0xFFFFFF),
                                    LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_border_opa(ui_Button3, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_border_width(ui_Button3, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_outline_pad(ui_Button3, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        lv_obj_set_style_outline_color(ui_Button3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
        btn_array[2] = ui_Button3;

        ui_Label3 = lv_label_create(ui_Button3);
        lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
        lv_obj_set_style_text_color(ui_Label3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_Label3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_Label3, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        btn_text_array[2] = ui_Label3;
        
        lv_obj_add_event_cb(messagebox_close_btn, messagebox_close_event_handler, LV_EVENT_ALL, NULL);
        lv_obj_add_event_cb(ui_Button1, messagebox_btn1_click_event_handler, LV_EVENT_ALL, NULL);
        lv_obj_add_event_cb(ui_Button2, messagebox_btn2_click_event_handler, LV_EVENT_ALL, NULL);
        lv_obj_add_event_cb(ui_Button3, messagebox_btn3_click_event_handler, LV_EVENT_ALL, NULL);

    }
    else
    {
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_clear_flag(messagebox_panel, LV_OBJ_FLAG_HIDDEN);     /// Flags
    }

    lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);


    /*******************personalise***********************/
    if ( messagebox_title )
    {
        if ( title && strlen(title) )
            lv_label_set_text(messagebox_title, title);
        else
            lv_label_set_text(messagebox_title, "");
    }   

    if ( messagebox_title )
    {
        if ( message && strlen(message) )
        {
            lv_obj_clear_flag(messagebox_text, LV_OBJ_FLAG_HIDDEN);     /// Flags
            lv_label_set_text(messagebox_text, message);  
        }
        else 
            lv_obj_add_flag(messagebox_text, LV_OBJ_FLAG_HIDDEN);     /// Flags
    }
        

    for(int i = 0; i < 3; i++)
    {
        if ( i < btn_count )
        {
            if ( btn_text_array[i] )
            {
                if ( btns && btns[i] )
                {
                    lv_point_t label_size;
                    lv_label_set_text(btn_text_array[i], btns[i]);
                    lv_txt_get_size(&label_size, lv_label_get_text(btn_text_array[i]), lv_font26.font, 0, 0, 280, 0);
                    if (label_size.x > 140)
                    {
                        lv_obj_align(btn_text_array[i], LV_ALIGN_CENTER, 0, 0);
                        lv_obj_set_style_text_font(btn_text_array[i], lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
                    }
                    else
                    {
                        lv_obj_align(btn_text_array[i], LV_ALIGN_CENTER, 0, -6);
                        lv_obj_set_style_text_font(btn_text_array[i], lv_font26.font, LV_PART_MAIN | LV_STATE_DEFAULT);
                    }
                    //redefine_label_size(btn_text_array[i], lv_font26.font, 0, 0, 170, 0);
                    // lv_obj_update_layout(btn_array[i]);
                    // redefine_widgets_size(btn_array[i], btn_text_array[i], 2, 2, 144, 56);
                    // lv_obj_update_layout(btn_array[i]);
                    // if (lv_obj_get_height(btn_array[i]) > 56)
                    // {
                    //     lv_obj_set_y(btn_array[i], 190);
                    // }
                }
                else
                    lv_label_set_text(btn_text_array[i], ""); 
            }

            if ( btns_callback_array && btns_callback_array[i] )
                messagebox_btn_callback_array[i] = btns_callback_array[i];
            else
                messagebox_btn_callback_array[i] = NULL;
        }
        else
        {
            messagebox_btn_callback_array[i] = NULL;
        }
    }

    bool has_message = false;
    if ( message && strlen(message) )
        has_message = true;

    layout_btns(arrangement_method_hor, btn_count, has_message);

    
    if ( (btns_callback_array == NULL) || (btn_count <= 0) )
    {
        show_close_btn = true;
    }
    // else
    // {
    //     bool empty = true;
    //     for(int i = 0; i < btn_count; i++)
    //         if ( btns_callback_array[i] )
    //         {
    //             empty = false;
    //             break;
    //         }
        
    //     if ( empty )
    //         show_close_btn = true;
    // }

    if ( show_close_btn )
        lv_obj_clear_flag(messagebox_close_btn, LV_OBJ_FLAG_HIDDEN);     /// Flags
    else
        lv_obj_add_flag(messagebox_close_btn, LV_OBJ_FLAG_HIDDEN);     /// Flags

    lv_obj_set_style_bg_color(lv_layer_top(), lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(lv_layer_top(), 204, LV_PART_MAIN | LV_STATE_DEFAULT);

    InitPopoutManager(&BtnDialogPopout, messagebox_panel, CustomMessageboxAddObjsToGroup);
    if ( btns && btns[0] )
    {
        BtnDialogPopout.obj1_flag = true;
        BtnDialogPopout.popout_focus_obj1 = btn_array[0];
    }
    if ( btns && btns[1] )
    {
        BtnDialogPopout.obj2_flag = true;
        BtnDialogPopout.popout_focus_obj2 = btn_array[1];
    }
    if ( btns && btns[2] )
    {
        BtnDialogPopout.obj3_flag = true;
        BtnDialogPopout.popout_focus_obj3 = btn_array[2];
    }

    //弹框聚焦对象处理
    ManagePopoutFocus();
}

void set_custom_messagebox_bg_color(lv_color_t bk_color, uint8_t arp)
{
    lv_obj_set_style_bg_color(messagebox_panel, bk_color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(messagebox_panel, arp, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void set_custom_messagebox_label_text_color(lv_color_t color)
{
    if ( messagebox_title )
        lv_obj_set_style_text_color(messagebox_title, color, LV_PART_MAIN|LV_STATE_DEFAULT);
    if ( messagebox_text )
        lv_obj_set_style_text_color(messagebox_text, color, LV_PART_MAIN|LV_STATE_DEFAULT);
}
void set_custom_messagebox_label_bg_color(lv_color_t color)
{
    if ( messagebox_title )
        lv_obj_set_style_bg_color(messagebox_title, color, LV_PART_MAIN|LV_STATE_DEFAULT);
    if ( messagebox_text )
        lv_obj_set_style_bg_color(messagebox_text, color, LV_PART_MAIN|LV_STATE_DEFAULT);
}

void set_custom_messagebox_btn_bg_color(int btn_index, lv_color_t color)
{
    lv_obj_set_style_bg_color(btn_array[btn_index], color, LV_PART_MAIN|LV_STATE_DEFAULT);
}

void set_custom_messagebox_btn_text_color(int btn_index, lv_color_t color)
{
    lv_obj_set_style_text_color(btn_array[btn_index], color, LV_PART_MAIN|LV_STATE_DEFAULT);
}

void clear_custom_messagebox_bg_color()
{
    if ( messagebox_panel )
    {
        lv_obj_set_style_bg_color(messagebox_panel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(messagebox_panel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}

/**
 * @description: 对话框初始化
 * @return {*}
 * @param {DialogMsgbox_t} *dialog
 */
void InitDialogMessagebox(DialogMsgbox_t *dialog)
{
    static lv_obj_t * ui_SubPanel = NULL;
    static lv_obj_t * ui_DialogTitle = NULL;
    static lv_obj_t * ui_DialogContent = NULL;
    
    //透明面板
    lv_obj_t * ui_DialogPanel = lv_obj_create(lv_scr_act());
    // lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_width(ui_DialogPanel, 640);
    lv_obj_set_height(ui_DialogPanel, 480);
    lv_obj_set_align(ui_DialogPanel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_DialogPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_DialogPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_DialogPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DialogPanel, 205, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_DialogPanel, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_DialogPanel, LV_OBJ_FLAG_HIDDEN);  //默认隐藏透明面板 
    dialog->panel = ui_DialogPanel;
    
    //子面板
    lv_obj_t * ui_DialogSubPanel = lv_obj_create(dialog->panel);
    lv_obj_set_size(ui_DialogSubPanel, dialog->subPanelAttr.w, dialog->subPanelAttr.h);
    //lv_obj_set_pos(ui_DialogSubPanel, ScreenOffMessage->msg_attr.x, ScreenOffMessage->msg_attr.y);
    lv_obj_set_align(ui_DialogSubPanel, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(ui_DialogSubPanel, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DialogSubPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_DialogSubPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //lv_obj_set_style_border_color(ui_DialogSubPanel, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_opa(ui_DialogSubPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_DialogSubPanel, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_DialogSubPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_DialogSubPanel, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_DialogSubPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //dialog->subPanel = ui_DialogSubPanel;
    lv_obj_add_flag(ui_DialogSubPanel, LV_OBJ_FLAG_HIDDEN);
    
    if (dialog->hasSubPanel)
    {
        lv_obj_clear_flag(ui_DialogSubPanel, LV_OBJ_FLAG_HIDDEN);   
        ui_SubPanel = ui_DialogSubPanel;
    }
    else
    {
        lv_obj_add_flag(ui_DialogSubPanel, LV_OBJ_FLAG_HIDDEN);   
        ui_SubPanel = ui_DialogPanel;
    }
    
    //对话框标题
    ui_DialogTitle = lv_label_create(ui_SubPanel);
    lv_obj_set_width(ui_DialogTitle, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_DialogTitle, LV_SIZE_CONTENT);
    // if(msgbox->hasSubPanel)
    //     lv_obj_align(ui_DialogTitle, LV_ALIGN_TOP_MID, 0, 11);
    // else
    //     lv_obj_align(ui_DialogTitle, LV_ALIGN_TOP_MID, 0, 71);
    lv_obj_set_style_text_color(ui_DialogTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DialogTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_DialogTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DialogTitle, lv_font28.font, LV_PART_MAIN | LV_STATE_DEFAULT); 
    dialog->titleLabel = ui_DialogTitle;
    
    //对话框内容
    ui_DialogContent = lv_label_create(ui_SubPanel);
    lv_obj_align(ui_DialogContent, LV_ALIGN_TOP_MID, 0, 70);
    lv_obj_set_size(ui_DialogContent, 327, 117);
    lv_label_set_text(ui_DialogContent, "");
    lv_label_set_recolor(ui_DialogContent, true);
    lv_label_set_long_mode(ui_DialogContent, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_color(ui_DialogContent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_DialogContent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_DialogContent, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_DialogContent, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT); 
    
    dialog->contentLabel = ui_DialogContent;
    
    //创建指定数量的按键和文本标签
    for (int i = 0; i < dialog->btnNumber; i++)
    {
        lv_obj_t * ui_DialogButton = lv_btn_create(ui_SubPanel);
        // lv_obj_align(ui_DialogButton, LV_ALIGN_TOP_MID, 0, 266);
        lv_obj_add_flag(ui_DialogButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_DialogButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        if(dialog->customStyle != NULL) // 自定义样式
        {
            lv_obj_add_style(ui_DialogButton, dialog->customStyle, LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(ui_DialogButton, dialog->customFocusStyle, LV_PART_MAIN|LV_STATE_FOCUS_KEY);
           // printf("customStyle\n");
        }
        else //默认样式---未定义定义样式选用默认样式
        {
             //printf("default customStyle\n");
            lv_obj_set_flex_align(ui_DialogButton, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
            lv_obj_set_style_radius(ui_DialogButton, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(ui_DialogButton, lv_color_hex(0x28292D), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(ui_DialogButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_width(ui_DialogButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_shadow_spread(ui_DialogButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(ui_DialogButton, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(ui_DialogButton, lv_color_hex(0x4A4E57), LV_PART_MAIN | LV_STATE_DEFAULT);
            // 选中后样式
            lv_obj_set_style_bg_color(ui_DialogButton, lv_color_hex(0x2A2A2A), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_border_side(ui_DialogButton, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_border_color(ui_DialogButton, lv_color_hex(0xCDF6FF),
                                        LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_radius(ui_DialogButton, 6, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_border_opa(ui_DialogButton, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
            lv_obj_set_style_border_width(ui_DialogButton, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);  
            
        }
        dialog->btn[i].btn = ui_DialogButton;
          
        lv_obj_t *ui_DialogButtonLabel = lv_label_create(ui_DialogButton);
        lv_obj_set_width(ui_DialogButtonLabel, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_DialogButtonLabel, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_align(ui_DialogButtonLabel, LV_ALIGN_CENTER);
        lv_label_set_long_mode(ui_DialogButtonLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_font(ui_DialogButtonLabel, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_long_mode(ui_DialogButtonLabel, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_align(ui_DialogButtonLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        dialog->btn[i].label = ui_DialogButtonLabel;

        lv_obj_add_event_cb(dialog->btn[i].btn, dialog->btn[i].btnsCallbackArray, LV_EVENT_ALL, i);        
    }
}

/**
 * @description: 显示对话框
 * @return {*}
 * @param {DialogMsgbox_t} *dialog
 */
void ShowDialogMessagebox(DialogMsgbox_t *dialog, void (*change_group_objs_cb)(void))
{
    if (!IsThereAnyPopout())
    {
        RecordObjBeforePopup();
    }
 //   lv_obj_set_parent(dialog->panel, lv_scr_act());
   // lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
   // lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(dialog->panel, LV_OBJ_FLAG_HIDDEN);     /// Flags
    lv_obj_set_parent(dialog->panel, lv_scr_act());
    uint8_t language_index = get_cur_language_index();
    if (dialog->titleLabel)
    {
        if (dialog->title[language_index] && strlen(dialog->title[language_index]))
            lv_label_set_text(dialog->titleLabel, dialog->title[language_index]);
        else
            lv_label_set_text(dialog->titleLabel, "");
    }   
    for (size_t i = 0; i < dialog->btnNumber; i++)
    {
        dialog->btn[i].SetLabelText(dialog->btn[i].label, i, language_index);
    }

    InitPopoutManager(&BtnDialogPopout, dialog->panel, change_group_objs_cb);

    for (size_t i = 0; i < dialog->btnNumber; i++)
    {
        if (0 == i)
        {
            BtnDialogPopout.obj1_flag = true;
            BtnDialogPopout.popout_focus_obj1 = dialog->btn[i].btn;
        }
        if (1 == i)
        {
            BtnDialogPopout.obj2_flag = true;
            BtnDialogPopout.popout_focus_obj2 = dialog->btn[i].btn;
        }
        if (2 == i)
        {
            BtnDialogPopout.obj3_flag = true;
            BtnDialogPopout.popout_focus_obj3 = dialog->btn[i].btn;
        }
    }

    ManagePopoutFocus();
}

/**
 * @description: 隐藏对话框
 * @return {*}
 * @param {DialogMsgbox_t} *dialog
 */
void HiddenDialogMessagebox(DialogMsgbox_t *dialog)
{
   // lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
   // lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(dialog->panel, LV_OBJ_FLAG_HIDDEN);
}
       