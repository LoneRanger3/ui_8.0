#include "ui_custom_numbers_keys.h"
#include "ui.h"
#include <stdio.h>
#include <stdlib.h>

static int32_t numbers_input_max = 9;
static int32_t numbers_input_min = 0;
static lv_obj_t *numbers_keys_panel = NULL;
static lv_obj_t *keyboardinput_label_title = NULL;
static lv_obj_t *ui_ScreenNumberKeysBtnSub = NULL;
static void (*confirm_call_back)(void *) = NULL;
static void (*input_key_reminder)(int) = NULL;

static void numberskey_inputboard_event_handler(lv_event_t * e);
static bool is_input_in_valid_rangle(char *input_str, uint16_t min, uint16_t max);



void numberskey_inputboard_event_handler(lv_event_t * e)
{
    static char input_str[15] = {'\0'};
    static int len = 0;
    //int tint = 0;
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            if ( input_key_reminder )
                input_key_reminder(0);

            uint16_t input_char = lv_event_get_user_data(e);
            switch(input_char)
            {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                {
                    if(len < 10)
                    {
                        char *ch = strchr(input_str, '.');
                        if ( ch )
                        {
                            char *temp_ptr = &input_str[len];
                            if ( (temp_ptr - ch) < 4  )  //小数点后转换只有4位是有效的
                            {
                                input_str[len++] = input_char;
                            }
                        }
                        else
                            input_str[len++] = input_char;
                        
                        float ftemp = atof(input_str);
                        if ( numbers_input_min < 0 )
                        {
                            CrLogI("-----------min is %d, input %f ", numbers_input_min, ftemp);
                            if ( ftemp < numbers_input_min )
                            {
                                len--;
                                input_str[len] = '\0';
                            }
                            else
                            {
                                if ( numbers_input_max > 0 )
                                {
                                    if ( input_str[0] != '-' )
                                    {
                                        if ( !is_input_in_valid_rangle(input_str, 0, numbers_input_max) )
                                        {
                                            len--;
                                            input_str[len] = '\0';
                                        }                                        
                                    }
                                }
                            }
                        }
                        else
                        {
                            if ( !is_input_in_valid_rangle(input_str, numbers_input_min, numbers_input_max) )
                            {
                                len--;
                                input_str[len] = '\0';
                            }
                        }
                        
                        
                        lv_label_set_text(keyboardinput_label_title,input_str);
                    }
                    break;
                }
                case '.':
                {
                    if(len > 0)
                    {
                        if ( (len == 1) && (input_str[0] == '-') )  //只有一个字符且是负号
                        {

                        }
                        else
                        {
                            char *ch = strchr(input_str, '.');
                            if ( !ch )
                                input_str[len++] = input_char;
                        }

                        lv_label_set_text(keyboardinput_label_title,input_str);
                    }
                    break;
                }
                case '-':
                {
                    if(len == 0)
                    {   
                        if ( numbers_input_min < 0 )
                        {
                            input_str[len++] = input_char;
                            lv_label_set_text(keyboardinput_label_title,input_str);
                        }
                    }
                    break;
                }
                case 'B':
                {
                    if(len > 0)
                    {
                        input_str[--len] = '\0';
                        lv_label_set_text(keyboardinput_label_title,input_str);
                    }
                    break;
                }
                case 'E':
                {
                    if ( input_key_reminder )
                        input_key_reminder(0);
                    memset(input_str,0,sizeof(input_str));
                    len = 0;
                    lv_obj_add_flag(numbers_keys_panel, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
                    break;
                }
                case 'O':
                {
                    //tint = atof(input_str);
                    float ftemp = atof(input_str);
                    // tint = (int)ftemp;
                    // if ( fabs(ftemp - tint) > 0.000001 )  
                    // {
                    //     if ( tint < ftemp )
                    //         tint += 1;
                    // }
                    // CrLogI("----------input %s, float = %f, int %d", input_str, ftemp, tint);
                    //if((tint > numbers_input_max) || (tint < numbers_input_min))
                    if((ftemp > numbers_input_max) || (ftemp < numbers_input_min))
                    {
                        if ( input_key_reminder )
                            input_key_reminder(1);

                        //mymsgbox("输入的数据超出范围,请重新输入");
                        memset(input_str,0,sizeof(input_str));
                        lv_label_set_text(keyboardinput_label_title,"0");
                        len = 0;
                        break;
                    }
                    else if(input_str[0] != '\0' && confirm_call_back != NULL)
                    {
                        confirm_call_back(input_str);
                    }
                    memset(input_str,0,sizeof(input_str));
                    len = 0;
                    lv_obj_add_flag(numbers_keys_panel, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
                    break;
                  }
                default:
                    break;
            }
        }
        break;
        default:
		break;
	}
}

bool is_input_in_valid_rangle(char *str_input, uint16_t min, uint16_t max)
{
    if ( !str_input || (min >= max) )
        return false;
    
    char Buff[10] = {0};
    char Buff_Max[10] = {0};
    sprintf(Buff, "%d", min);
    sprintf(Buff_Max, "%d", max);
    int length = strlen(str_input);
    float ftemp = atof(str_input);
    //if ( (strncmp(str_input, Buff, length) < 0) || (strcmp(str_input, Buff_Max) > 0)  )  //输入的字符要比
    if ( (strncmp(str_input, Buff, length) < 0) )  //输入的字符要比
    {
        return false;
    }
    else
    {
        if((ftemp > numbers_input_max))
        {
            return false;
        }
    }

    return true;
}

// static lv_style_t style_cont_msgbox;
// static lv_style_t style_img_default;
// static lv_style_t style_white24_text_creality;
// static lv_style_t style_normal_btn_default;

void numberskeyboardinput(char *msg, int *inputmax, int *inputmin, void (*confirm_btn_call_back)(void *), void (*key_reminder)(int), uint16_t pos_x, uint16_t pos_y)
{
    /*******************init style*******************************/
    if( numbers_keys_panel == NULL )
    {
        /*****************************create number keys************************/
        lv_obj_t * ui_ScreenNumberKeysPanel;
        lv_obj_t * ui_ScreenNumberKeysLabelInput;
        lv_obj_t * ui_ScreenNumberKeysBtn7;
        lv_obj_t * ui_ScreenNumberKeysLabelNum7;
        lv_obj_t * ui_ScreenNumberKeysBtn8;
        lv_obj_t * ui_ScreenNumberKeysLabelNum8;
        lv_obj_t * ui_ScreenNumberKeysBtn9;
        lv_obj_t * ui_ScreenNumberKeysLabelNum9;
        lv_obj_t * ui_ScreenNumberKeysBtnDel;
        lv_obj_t * ui_ScreenNumberKeysImageDel;
        lv_obj_t * ui_ScreenNumberKeysBtn4;
        lv_obj_t * ui_ScreenNumberKeysLabelNum4;
        lv_obj_t * ui_ScreenNumberKeysBtn5;
        lv_obj_t * ui_ScreenNumberKeysLabelNum5;
        lv_obj_t * ui_ScreenNumberKeysBtn6;
        lv_obj_t * ui_ScreenNumberKeysLabelNum6;
        lv_obj_t * ui_ScreenNumberKeysBtnEsc;
        lv_obj_t * ui_ScreenNumberKeysLabelEsc;
        lv_obj_t * ui_ScreenNumberKeysBtn1;
        lv_obj_t * ui_ScreenNumberKeysLabelNum1;
        lv_obj_t * ui_ScreenNumberKeysBtn2;
        lv_obj_t * ui_ScreenNumberKeysLabelNum2;
        lv_obj_t * ui_ScreenNumberKeysBtn3;
        lv_obj_t * ui_ScreenNumberKeysLabelNum3;
        lv_obj_t * ui_ScreenNumberKeysBtnPoint;
        lv_obj_t * ui_ScreenNumberKeysLabelPoint;
        lv_obj_t * ui_ScreenNumberKeysBtn0;
        lv_obj_t * ui_ScreenNumberKeysLabelNum0;
        //lv_obj_t * ui_ScreenNumberKeysBtnSub;  //设置为静态全局变量了
        lv_obj_t * ui_ScreenNumberKeysImageSub;
        lv_obj_t * ui_ScreenNumberKeysBtnOk;
        lv_obj_t * ui_ScreenNumberKeysLabelOk;
            
        ui_ScreenNumberKeysPanel = lv_obj_create(lv_layer_top());
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_style_bg_opa(lv_layer_top(), 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_width(ui_ScreenNumberKeysPanel, 480);
        lv_obj_set_height(ui_ScreenNumberKeysPanel, 480);
        lv_obj_clear_flag(ui_ScreenNumberKeysPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_ScreenNumberKeysPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_ScreenNumberKeysPanel, lv_color_hex(0x050505), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ScreenNumberKeysPanel, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_width(ui_ScreenNumberKeysPanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        numbers_keys_panel = ui_ScreenNumberKeysPanel;

        ui_ScreenNumberKeysLabelInput = lv_label_create(ui_ScreenNumberKeysPanel);
        lv_obj_set_width(ui_ScreenNumberKeysLabelInput, 420);
        lv_obj_set_height(ui_ScreenNumberKeysLabelInput, 30);
        lv_obj_set_x(ui_ScreenNumberKeysLabelInput, 8);
        lv_obj_set_y(ui_ScreenNumberKeysLabelInput, 4);
        lv_obj_set_style_text_color(ui_ScreenNumberKeysLabelInput, lv_color_hex(0x83868B), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_ScreenNumberKeysLabelInput, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_ScreenNumberKeysLabelInput, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_recolor(ui_ScreenNumberKeysLabelInput, true);
        keyboardinput_label_title = ui_ScreenNumberKeysLabelInput;

        ui_ScreenNumberKeysBtn7 = lv_btn_create(ui_ScreenNumberKeysPanel);
        lv_obj_set_width(ui_ScreenNumberKeysBtn7, 90);
        lv_obj_set_height(ui_ScreenNumberKeysBtn7, 80);
        lv_obj_set_x(ui_ScreenNumberKeysBtn7, 12);
        lv_obj_set_y(ui_ScreenNumberKeysBtn7, 55);
        lv_obj_add_flag(ui_ScreenNumberKeysBtn7, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ScreenNumberKeysBtn7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_bg_color(ui_ScreenNumberKeysBtn7, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ScreenNumberKeysBtn7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_ScreenNumberKeysBtn7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_ScreenNumberKeysBtn7, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysLabelNum7 = lv_label_create(ui_ScreenNumberKeysBtn7);
        lv_obj_set_width(ui_ScreenNumberKeysLabelNum7, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_ScreenNumberKeysLabelNum7, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_align(ui_ScreenNumberKeysLabelNum7, LV_ALIGN_CENTER);
        lv_label_set_text(ui_ScreenNumberKeysLabelNum7, "7");
        lv_obj_set_style_text_font(ui_ScreenNumberKeysLabelNum7, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysBtn8 = lv_btn_create(ui_ScreenNumberKeysPanel);
        lv_obj_set_width(ui_ScreenNumberKeysBtn8, 90);
        lv_obj_set_height(ui_ScreenNumberKeysBtn8, 80);
        lv_obj_set_x(ui_ScreenNumberKeysBtn8, 117);
        lv_obj_set_y(ui_ScreenNumberKeysBtn8, 55);
        lv_obj_add_flag(ui_ScreenNumberKeysBtn8, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ScreenNumberKeysBtn8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_bg_color(ui_ScreenNumberKeysBtn8, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ScreenNumberKeysBtn8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_ScreenNumberKeysBtn8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_ScreenNumberKeysBtn8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysLabelNum8 = lv_label_create(ui_ScreenNumberKeysBtn8);
        lv_obj_set_width(ui_ScreenNumberKeysLabelNum8, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_ScreenNumberKeysLabelNum8, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_align(ui_ScreenNumberKeysLabelNum8, LV_ALIGN_CENTER);
        lv_label_set_text(ui_ScreenNumberKeysLabelNum8, "8");
        lv_obj_set_style_text_font(ui_ScreenNumberKeysLabelNum8, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysBtn9 = lv_btn_create(ui_ScreenNumberKeysPanel);
        lv_obj_set_width(ui_ScreenNumberKeysBtn9, 90);
        lv_obj_set_height(ui_ScreenNumberKeysBtn9, 80);
        lv_obj_set_x(ui_ScreenNumberKeysBtn9, 222);
        lv_obj_set_y(ui_ScreenNumberKeysBtn9, 55);
        lv_obj_add_flag(ui_ScreenNumberKeysBtn9, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ScreenNumberKeysBtn9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_bg_color(ui_ScreenNumberKeysBtn9, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ScreenNumberKeysBtn9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_ScreenNumberKeysBtn9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_ScreenNumberKeysBtn9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysLabelNum9 = lv_label_create(ui_ScreenNumberKeysBtn9);
        lv_obj_set_width(ui_ScreenNumberKeysLabelNum9, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_ScreenNumberKeysLabelNum9, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_align(ui_ScreenNumberKeysLabelNum9, LV_ALIGN_CENTER);
        lv_label_set_text(ui_ScreenNumberKeysLabelNum9, "9");
        lv_obj_set_style_text_font(ui_ScreenNumberKeysLabelNum9, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysBtnDel = lv_btn_create(ui_ScreenNumberKeysPanel);
        lv_obj_set_width(ui_ScreenNumberKeysBtnDel, 90);
        lv_obj_set_height(ui_ScreenNumberKeysBtnDel, 80);
        lv_obj_set_x(ui_ScreenNumberKeysBtnDel, 327);
        lv_obj_set_y(ui_ScreenNumberKeysBtnDel, 55);
        lv_obj_add_flag(ui_ScreenNumberKeysBtnDel, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ScreenNumberKeysBtnDel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_bg_color(ui_ScreenNumberKeysBtnDel, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ScreenNumberKeysBtnDel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_ScreenNumberKeysBtnDel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_ScreenNumberKeysBtnDel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysImageDel = lv_img_create(ui_ScreenNumberKeysBtnDel);
        lv_img_set_src(ui_ScreenNumberKeysImageDel, &ui_img_arrow_png);
        lv_obj_set_width(ui_ScreenNumberKeysImageDel, 39);
        lv_obj_set_height(ui_ScreenNumberKeysImageDel, 26);
        lv_obj_set_align(ui_ScreenNumberKeysImageDel, LV_ALIGN_CENTER);
        lv_obj_add_flag(ui_ScreenNumberKeysImageDel, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
        lv_obj_clear_flag(ui_ScreenNumberKeysImageDel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

        ui_ScreenNumberKeysBtn4 = lv_btn_create(ui_ScreenNumberKeysPanel);
        lv_obj_set_width(ui_ScreenNumberKeysBtn4, 90);
        lv_obj_set_height(ui_ScreenNumberKeysBtn4, 80);
        lv_obj_set_x(ui_ScreenNumberKeysBtn4, 12);
        lv_obj_set_y(ui_ScreenNumberKeysBtn4, 150);
        lv_obj_add_flag(ui_ScreenNumberKeysBtn4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ScreenNumberKeysBtn4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_bg_color(ui_ScreenNumberKeysBtn4, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ScreenNumberKeysBtn4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_ScreenNumberKeysBtn4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_ScreenNumberKeysBtn4, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysLabelNum4 = lv_label_create(ui_ScreenNumberKeysBtn4);
        lv_obj_set_width(ui_ScreenNumberKeysLabelNum4, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_ScreenNumberKeysLabelNum4, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_align(ui_ScreenNumberKeysLabelNum4, LV_ALIGN_CENTER);
        lv_label_set_text(ui_ScreenNumberKeysLabelNum4, "4");
        lv_obj_set_style_text_font(ui_ScreenNumberKeysLabelNum4, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysBtn5 = lv_btn_create(ui_ScreenNumberKeysPanel);
        lv_obj_set_width(ui_ScreenNumberKeysBtn5, 90);
        lv_obj_set_height(ui_ScreenNumberKeysBtn5, 80);
        lv_obj_set_x(ui_ScreenNumberKeysBtn5, 117);
        lv_obj_set_y(ui_ScreenNumberKeysBtn5, 150);
        lv_obj_add_flag(ui_ScreenNumberKeysBtn5, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ScreenNumberKeysBtn5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_bg_color(ui_ScreenNumberKeysBtn5, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ScreenNumberKeysBtn5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_ScreenNumberKeysBtn5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_ScreenNumberKeysBtn5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysLabelNum5 = lv_label_create(ui_ScreenNumberKeysBtn5);
        lv_obj_set_width(ui_ScreenNumberKeysLabelNum5, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_ScreenNumberKeysLabelNum5, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_align(ui_ScreenNumberKeysLabelNum5, LV_ALIGN_CENTER);
        lv_label_set_text(ui_ScreenNumberKeysLabelNum5, "5");
        lv_obj_set_style_text_font(ui_ScreenNumberKeysLabelNum5, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysBtn6 = lv_btn_create(ui_ScreenNumberKeysPanel);
        lv_obj_set_width(ui_ScreenNumberKeysBtn6, 90);
        lv_obj_set_height(ui_ScreenNumberKeysBtn6, 80);
        lv_obj_set_x(ui_ScreenNumberKeysBtn6, 222);
        lv_obj_set_y(ui_ScreenNumberKeysBtn6, 150);
        lv_obj_add_flag(ui_ScreenNumberKeysBtn6, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ScreenNumberKeysBtn6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_bg_color(ui_ScreenNumberKeysBtn6, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ScreenNumberKeysBtn6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_ScreenNumberKeysBtn6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_ScreenNumberKeysBtn6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysLabelNum6 = lv_label_create(ui_ScreenNumberKeysBtn6);
        lv_obj_set_width(ui_ScreenNumberKeysLabelNum6, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_ScreenNumberKeysLabelNum6, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_align(ui_ScreenNumberKeysLabelNum6, LV_ALIGN_CENTER);
        lv_label_set_text(ui_ScreenNumberKeysLabelNum6, "6");
        lv_obj_set_style_text_font(ui_ScreenNumberKeysLabelNum6, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysBtnEsc = lv_btn_create(ui_ScreenNumberKeysPanel);
        lv_obj_set_width(ui_ScreenNumberKeysBtnEsc, 90);
        lv_obj_set_height(ui_ScreenNumberKeysBtnEsc, 80);
        lv_obj_set_x(ui_ScreenNumberKeysBtnEsc, 327);
        lv_obj_set_y(ui_ScreenNumberKeysBtnEsc, 150);
        lv_obj_add_flag(ui_ScreenNumberKeysBtnEsc, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ScreenNumberKeysBtnEsc, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_bg_color(ui_ScreenNumberKeysBtnEsc, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ScreenNumberKeysBtnEsc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_ScreenNumberKeysBtnEsc, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_ScreenNumberKeysBtnEsc, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysLabelEsc = lv_label_create(ui_ScreenNumberKeysBtnEsc);
        lv_obj_set_width(ui_ScreenNumberKeysLabelEsc, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_ScreenNumberKeysLabelEsc, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_align(ui_ScreenNumberKeysLabelEsc, LV_ALIGN_CENTER);
        lv_label_set_text(ui_ScreenNumberKeysLabelEsc, "ESC");
        lv_obj_set_style_text_font(ui_ScreenNumberKeysLabelEsc, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysBtn1 = lv_btn_create(ui_ScreenNumberKeysPanel);
        lv_obj_set_width(ui_ScreenNumberKeysBtn1, 90);
        lv_obj_set_height(ui_ScreenNumberKeysBtn1, 80);
        lv_obj_set_x(ui_ScreenNumberKeysBtn1, 12);
        lv_obj_set_y(ui_ScreenNumberKeysBtn1, 245);
        lv_obj_add_flag(ui_ScreenNumberKeysBtn1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ScreenNumberKeysBtn1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_bg_color(ui_ScreenNumberKeysBtn1, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ScreenNumberKeysBtn1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_ScreenNumberKeysBtn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_ScreenNumberKeysBtn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysLabelNum1 = lv_label_create(ui_ScreenNumberKeysBtn1);
        lv_obj_set_width(ui_ScreenNumberKeysLabelNum1, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_ScreenNumberKeysLabelNum1, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_align(ui_ScreenNumberKeysLabelNum1, LV_ALIGN_CENTER);
        lv_label_set_text(ui_ScreenNumberKeysLabelNum1, "1");
        lv_obj_set_style_text_font(ui_ScreenNumberKeysLabelNum1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysBtn2 = lv_btn_create(ui_ScreenNumberKeysPanel);
        lv_obj_set_width(ui_ScreenNumberKeysBtn2, 90);
        lv_obj_set_height(ui_ScreenNumberKeysBtn2, 80);
        lv_obj_set_x(ui_ScreenNumberKeysBtn2, 117);
        lv_obj_set_y(ui_ScreenNumberKeysBtn2, 245);
        lv_obj_add_flag(ui_ScreenNumberKeysBtn2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ScreenNumberKeysBtn2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_bg_color(ui_ScreenNumberKeysBtn2, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ScreenNumberKeysBtn2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_ScreenNumberKeysBtn2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_ScreenNumberKeysBtn2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysLabelNum2 = lv_label_create(ui_ScreenNumberKeysBtn2);
        lv_obj_set_width(ui_ScreenNumberKeysLabelNum2, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_ScreenNumberKeysLabelNum2, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_align(ui_ScreenNumberKeysLabelNum2, LV_ALIGN_CENTER);
        lv_label_set_text(ui_ScreenNumberKeysLabelNum2, "2");
        lv_obj_set_style_text_font(ui_ScreenNumberKeysLabelNum2, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysBtn3 = lv_btn_create(ui_ScreenNumberKeysPanel);
        lv_obj_set_width(ui_ScreenNumberKeysBtn3, 90);
        lv_obj_set_height(ui_ScreenNumberKeysBtn3, 80);
        lv_obj_set_x(ui_ScreenNumberKeysBtn3, 222);
        lv_obj_set_y(ui_ScreenNumberKeysBtn3, 245);
        lv_obj_add_flag(ui_ScreenNumberKeysBtn3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ScreenNumberKeysBtn3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_bg_color(ui_ScreenNumberKeysBtn3, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ScreenNumberKeysBtn3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_ScreenNumberKeysBtn3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_ScreenNumberKeysBtn3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysLabelNum3 = lv_label_create(ui_ScreenNumberKeysBtn3);
        lv_obj_set_width(ui_ScreenNumberKeysLabelNum3, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_ScreenNumberKeysLabelNum3, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_align(ui_ScreenNumberKeysLabelNum3, LV_ALIGN_CENTER);
        lv_label_set_text(ui_ScreenNumberKeysLabelNum3, "3");
        lv_obj_set_style_text_font(ui_ScreenNumberKeysLabelNum3, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysBtnPoint = lv_btn_create(ui_ScreenNumberKeysPanel);
        lv_obj_set_width(ui_ScreenNumberKeysBtnPoint, 90);
        lv_obj_set_height(ui_ScreenNumberKeysBtnPoint, 80);
        lv_obj_set_x(ui_ScreenNumberKeysBtnPoint, 117);
        lv_obj_set_y(ui_ScreenNumberKeysBtnPoint, 340);
        lv_obj_add_flag(ui_ScreenNumberKeysBtnPoint, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ScreenNumberKeysBtnPoint, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_bg_color(ui_ScreenNumberKeysBtnPoint, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ScreenNumberKeysBtnPoint, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_ScreenNumberKeysBtnPoint, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_ScreenNumberKeysBtnPoint, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysLabelPoint = lv_label_create(ui_ScreenNumberKeysBtnPoint);
        lv_obj_set_width(ui_ScreenNumberKeysLabelPoint, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_ScreenNumberKeysLabelPoint, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_x(ui_ScreenNumberKeysLabelPoint, 0);
        lv_obj_set_y(ui_ScreenNumberKeysLabelPoint, -9);
        lv_obj_set_align(ui_ScreenNumberKeysLabelPoint, LV_ALIGN_CENTER);
        lv_label_set_text(ui_ScreenNumberKeysLabelPoint, ".");
        lv_obj_set_style_text_font(ui_ScreenNumberKeysLabelPoint, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysBtn0 = lv_btn_create(ui_ScreenNumberKeysPanel);
        lv_obj_set_width(ui_ScreenNumberKeysBtn0, 90);
        lv_obj_set_height(ui_ScreenNumberKeysBtn0, 80);
        lv_obj_set_x(ui_ScreenNumberKeysBtn0, 12);
        lv_obj_set_y(ui_ScreenNumberKeysBtn0, 340);
        lv_obj_add_flag(ui_ScreenNumberKeysBtn0, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ScreenNumberKeysBtn0, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_bg_color(ui_ScreenNumberKeysBtn0, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ScreenNumberKeysBtn0, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_ScreenNumberKeysBtn0, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_ScreenNumberKeysBtn0, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysLabelNum0 = lv_label_create(ui_ScreenNumberKeysBtn0);
        lv_obj_set_width(ui_ScreenNumberKeysLabelNum0, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_ScreenNumberKeysLabelNum0, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_align(ui_ScreenNumberKeysLabelNum0, LV_ALIGN_CENTER);
        lv_label_set_text(ui_ScreenNumberKeysLabelNum0, "0");
        lv_obj_set_style_text_font(ui_ScreenNumberKeysLabelNum0, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysBtnSub = lv_btn_create(ui_ScreenNumberKeysPanel);
        lv_obj_set_width(ui_ScreenNumberKeysBtnSub, 90);
        lv_obj_set_height(ui_ScreenNumberKeysBtnSub, 80);
        lv_obj_set_x(ui_ScreenNumberKeysBtnSub, 222);
        lv_obj_set_y(ui_ScreenNumberKeysBtnSub, 340);
        lv_obj_add_flag(ui_ScreenNumberKeysBtnSub, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ScreenNumberKeysBtnSub, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_bg_color(ui_ScreenNumberKeysBtnSub, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ScreenNumberKeysBtnSub, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_ScreenNumberKeysBtnSub, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_ScreenNumberKeysBtnSub, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysImageSub = lv_img_create(ui_ScreenNumberKeysBtnSub);
        lv_img_set_src(ui_ScreenNumberKeysImageSub, &ui_img_sub_sign_png);
        lv_obj_set_width(ui_ScreenNumberKeysImageSub, LV_SIZE_CONTENT);
        lv_obj_set_height(ui_ScreenNumberKeysImageSub, LV_SIZE_CONTENT);
        lv_obj_set_align(ui_ScreenNumberKeysImageSub, LV_ALIGN_CENTER);
        lv_obj_add_flag(ui_ScreenNumberKeysImageSub, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
        lv_obj_clear_flag(ui_ScreenNumberKeysImageSub, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

        // ui_ScreenNumberKeysLabelSub = lv_label_create(ui_ScreenNumberKeysBtnSub);
        // lv_obj_set_width(ui_ScreenNumberKeysLabelSub, LV_SIZE_CONTENT);   /// 1
        // lv_obj_set_height(ui_ScreenNumberKeysLabelSub, LV_SIZE_CONTENT);    /// 1
        // lv_obj_set_x(ui_ScreenNumberKeysLabelSub, 0);
        // lv_obj_set_y(ui_ScreenNumberKeysLabelSub, -9);
        // lv_obj_set_align(ui_ScreenNumberKeysLabelSub, LV_ALIGN_CENTER);
        // lv_label_set_text(ui_ScreenNumberKeysLabelSub, "-");
        // lv_obj_set_style_text_font(ui_ScreenNumberKeysLabelSub, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);


        ui_ScreenNumberKeysBtnOk = lv_btn_create(ui_ScreenNumberKeysPanel);
        lv_obj_set_width(ui_ScreenNumberKeysBtnOk, 90);
        lv_obj_set_height(ui_ScreenNumberKeysBtnOk, 175);
        lv_obj_set_x(ui_ScreenNumberKeysBtnOk, 327);
        lv_obj_set_y(ui_ScreenNumberKeysBtnOk, 245);
        lv_obj_add_flag(ui_ScreenNumberKeysBtnOk, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
        lv_obj_clear_flag(ui_ScreenNumberKeysBtnOk, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_bg_color(ui_ScreenNumberKeysBtnOk, lv_color_hex(0x4C5057), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_ScreenNumberKeysBtnOk, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_width(ui_ScreenNumberKeysBtnOk, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_shadow_spread(ui_ScreenNumberKeysBtnOk, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ScreenNumberKeysLabelOk = lv_label_create(ui_ScreenNumberKeysBtnOk);
        lv_obj_set_width(ui_ScreenNumberKeysLabelOk, LV_SIZE_CONTENT);   /// 1
        lv_obj_set_height(ui_ScreenNumberKeysLabelOk, LV_SIZE_CONTENT);    /// 1
        lv_obj_set_align(ui_ScreenNumberKeysLabelOk, LV_ALIGN_CENTER);
        lv_label_set_text(ui_ScreenNumberKeysLabelOk, "OK");
        lv_obj_set_style_text_color(ui_ScreenNumberKeysLabelOk, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_ScreenNumberKeysLabelOk, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(ui_ScreenNumberKeysLabelOk, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_add_event_cb(ui_ScreenNumberKeysBtn0, numberskey_inputboard_event_handler, LV_EVENT_ALL, '0');
        lv_obj_add_event_cb(ui_ScreenNumberKeysBtn1, numberskey_inputboard_event_handler, LV_EVENT_ALL, '1');
        lv_obj_add_event_cb(ui_ScreenNumberKeysBtn2, numberskey_inputboard_event_handler, LV_EVENT_ALL, '2');
        lv_obj_add_event_cb(ui_ScreenNumberKeysBtn3, numberskey_inputboard_event_handler, LV_EVENT_ALL, '3');
        lv_obj_add_event_cb(ui_ScreenNumberKeysBtn4, numberskey_inputboard_event_handler, LV_EVENT_ALL, '4');
        lv_obj_add_event_cb(ui_ScreenNumberKeysBtn5, numberskey_inputboard_event_handler, LV_EVENT_ALL, '5');
        lv_obj_add_event_cb(ui_ScreenNumberKeysBtn6, numberskey_inputboard_event_handler, LV_EVENT_ALL, '6');
        lv_obj_add_event_cb(ui_ScreenNumberKeysBtn7, numberskey_inputboard_event_handler, LV_EVENT_ALL, '7');
        lv_obj_add_event_cb(ui_ScreenNumberKeysBtn8, numberskey_inputboard_event_handler, LV_EVENT_ALL, '8');
        lv_obj_add_event_cb(ui_ScreenNumberKeysBtn9, numberskey_inputboard_event_handler, LV_EVENT_ALL, '9');
        lv_obj_add_event_cb(ui_ScreenNumberKeysBtnDel, numberskey_inputboard_event_handler, LV_EVENT_ALL, 'B');
        lv_obj_add_event_cb(ui_ScreenNumberKeysBtnPoint, numberskey_inputboard_event_handler, LV_EVENT_ALL, '.');
        lv_obj_add_event_cb(ui_ScreenNumberKeysBtnSub, numberskey_inputboard_event_handler, LV_EVENT_ALL, '-');
        lv_obj_add_event_cb(ui_ScreenNumberKeysBtnOk, numberskey_inputboard_event_handler, LV_EVENT_ALL, 'O');
        lv_obj_add_event_cb(ui_ScreenNumberKeysBtnEsc, numberskey_inputboard_event_handler, LV_EVENT_ALL, 'E');
    }

    /****************************************************/

    if (lv_obj_has_flag(numbers_keys_panel,LV_OBJ_FLAG_HIDDEN))
    {
        lv_obj_clear_flag(numbers_keys_panel,LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    }

    lv_obj_set_x(numbers_keys_panel, pos_x);
    lv_obj_set_y(numbers_keys_panel, pos_y);

    //lv_obj_add_state(ui_ScreenNumberKeysBtnSub, LV_STATE_DISABLED);
    lv_label_set_text(keyboardinput_label_title, msg);
    numbers_input_max = inputmax;
    numbers_input_min = inputmin;
    confirm_call_back = confirm_btn_call_back;
    input_key_reminder = key_reminder;
}

// void numberskey_enable_sub_sign()
// {
//     lv_obj_clear_state(ui_ScreenNumberKeysBtnSub, LV_STATE_DISABLED);
// }
