#include "ui_custom_messagebox.h"
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
        
        lv_obj_set_style_bg_color(btn_array[i],btn_default_bk_color, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(btn_array[i],btn_default_text_color, LV_PART_MAIN|LV_STATE_DEFAULT);
    }

    if ( btn_vailed_count == 2 && dir_hor )
    {
        lv_obj_set_x(btn_array[0], 30 - 22 );
        lv_obj_set_x(btn_array[1], MSG_BOX_WIDTH - BTN_WIDTH - 30 -22 );
    }
}

void messagebox_close()
{
    lv_obj_add_flag(messagebox_panel, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_bg_opa(lv_layer_top(), 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(messagebox_panel, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(messagebox_panel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void create_custom_messagebox(char *title, char *message, char *btns[3], void(*btns_callback_array[3])(void), int btn_count, bool arrangement_method_hor, bool show_close_btn)
{
    ///////////////////// VARIABLES ////////////////////
    if ( messagebox_panel == NULL )
    {
        /**************************************************/
        btn_default_bk_color = lv_color_hex(0x50535A);
        btn_default_text_color = lv_color_hex(0xFFFFFF);

        /*********************create ctrls******************************/
        lv_obj_t * ui_PanelMessageBox;
        lv_obj_t * ui_LabelTitle;
        lv_obj_t * ui_LabelMessage;
        lv_obj_t * ui_Button1;
        lv_obj_t * ui_Label1;
        lv_obj_t * ui_Button2;
        lv_obj_t * ui_Label2;
        lv_obj_t * ui_Button3;
        lv_obj_t * ui_Label3;

        ui_PanelMessageBox = lv_obj_create(lv_layer_top());
        messagebox_panel = ui_PanelMessageBox;
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_width(ui_PanelMessageBox, MSG_BOX_WIDTH);
        lv_obj_set_height(ui_PanelMessageBox, MSG_BOX_HEIGHT);
        // lv_obj_set_x(ui_PanelMessageBox, -10);
        // lv_obj_set_y(ui_PanelMessageBox, -24);
        lv_obj_set_align(ui_PanelMessageBox, LV_ALIGN_CENTER);
        lv_obj_clear_flag(ui_PanelMessageBox, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_PanelMessageBox, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_PanelMessageBox, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_PanelMessageBox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_side(ui_PanelMessageBox, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

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
        lv_obj_set_style_bg_img_src(ui_ButtonClose, &_group_1453_23x23, LV_PART_MAIN | LV_STATE_DEFAULT);
        messagebox_close_btn = ui_ButtonClose;

        ui_LabelTitle = lv_label_create(ui_PanelMessageBox);
        messagebox_title = ui_LabelTitle;
        lv_obj_set_width(ui_LabelTitle, MSG_BOX_WIDTH - 60);
        lv_obj_set_height(ui_LabelTitle, 35);
        lv_obj_set_x(ui_LabelTitle, 8);
        lv_obj_set_y(ui_LabelTitle, -2);
        lv_obj_set_style_text_color(ui_LabelTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_LabelTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_LabelTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_LabelTitle, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_long_mode(ui_LabelTitle, LV_LABEL_LONG_SCROLL_CIRCULAR);

        ui_LabelMessage = lv_label_create(ui_PanelMessageBox);
        messagebox_text = ui_LabelMessage;
        lv_obj_set_width(ui_LabelMessage, MSG_BOX_WIDTH - 20);
        lv_obj_set_height(ui_LabelMessage, 90);
        lv_obj_set_x(ui_LabelMessage, -12);
        lv_obj_set_y(ui_LabelMessage, 48);
        lv_obj_set_style_text_color(ui_LabelMessage, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_LabelMessage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_align(ui_LabelMessage, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_LabelMessage, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_Button1 = lv_btn_create(ui_PanelMessageBox);
        lv_obj_set_width(ui_Button1, BTN_WIDTH);
        lv_obj_set_height(ui_Button1, BTN_HEIGHT);
        lv_obj_set_x(ui_Button1, -17);
        lv_obj_set_y(ui_Button1, 206);
        lv_obj_add_flag(ui_Button1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_Button1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_Button1, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_Button1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_Button1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_side(ui_Button1, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_border_color(ui_Button1, lv_color_hex(0x4190A2),
                                    LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_border_opa(ui_Button1, 255, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_border_width(ui_Button1, 2, LV_PART_MAIN | LV_STATE_PRESSED);
        btn_array[0] = ui_Button1;

        ui_Label1 = lv_label_create(ui_Button1);
        // lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
        // lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_width(ui_Label1, 110);
        lv_obj_set_height(ui_Label1, 35);
        lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
        lv_label_set_long_mode(ui_Label1, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_font(ui_Label1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_long_mode(ui_Label1, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_align(ui_Label1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        btn_text_array[0] = ui_Label1;

        ui_Button2 = lv_btn_create(ui_PanelMessageBox);
        lv_obj_set_width(ui_Button2, BTN_WIDTH);
        lv_obj_set_height(ui_Button2, BTN_HEIGHT);
        lv_obj_set_x(ui_Button2, 108);
        lv_obj_set_y(ui_Button2, 206);
        lv_obj_add_flag(ui_Button2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_Button2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_Button2, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_Button2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_Button2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_side(ui_Button2, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_border_color(ui_Button2, lv_color_hex(0x4190A2),
                                    LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_border_opa(ui_Button2, 255, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_border_width(ui_Button2, 2, LV_PART_MAIN | LV_STATE_PRESSED);
        btn_array[1] = ui_Button2;

        ui_Label2 = lv_label_create(ui_Button2);
        // lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
        // lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_width(ui_Label2, 110);
        lv_obj_set_height(ui_Label2, 35);
        lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
        lv_label_set_long_mode(ui_Label2, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_font(ui_Label2, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_long_mode(ui_Label2, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_align(ui_Label2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
        btn_text_array[1] = ui_Label2;

        ui_Button3 = lv_btn_create(ui_PanelMessageBox);
        lv_obj_set_width(ui_Button3, BTN_WIDTH);
        lv_obj_set_height(ui_Button3, BTN_HEIGHT);
        lv_obj_set_x(ui_Button3, 233);
        lv_obj_set_y(ui_Button3, 206);
        lv_obj_add_flag(ui_Button3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_Button3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_Button3, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_Button3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_Button3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_side(ui_Button3, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_border_color(ui_Button3, lv_color_hex(0x4190A2),
                                    LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_border_opa(ui_Button3, 255, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_border_width(ui_Button3, 2, LV_PART_MAIN | LV_STATE_PRESSED);
        btn_array[2] = ui_Button3;

        ui_Label3 = lv_label_create(ui_Button3);
        // lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
        // lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_width(ui_Label3, 110);
        lv_obj_set_height(ui_Label3, 35);
        lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
        lv_label_set_long_mode(ui_Label3, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_font(ui_Label3, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_long_mode(ui_Label3, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_align(ui_Label3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
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
                    lv_label_set_text(btn_text_array[i], btns[i]); 
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
