#include "ui_custom_reminderbox.h"
#include "ui.h"
#include "ui_helpers.h"
#include "lvgl/src/misc/lv_timer.h"

static lv_obj_t * ui_PanelReminder = NULL;
static lv_obj_t * ui_LabelReminder = NULL;
static lv_obj_t * ui_ImageReminder = NULL;
static bool top_desk_click_opened = false;
static void (*reminder_display_timeout_opt)(void) = NULL;
//static lv_timer_t *reminder_display_timeout_timer = NULL; // 定时方案1
static uint32_t max_period = 0xFFFFFFFF;

static void reminderbox_close_event_handler(lv_event_t * e);
static void display_timeout_callback(struct _lv_timer_t *);

void reminderbox_close_event_handler(lv_event_t * e)
{
    static char input_str[15] = {'\0'};
    static int len = 0;
    int tint = 0;
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            if ( !lv_obj_has_flag(ui_PanelReminder, LV_OBJ_FLAG_HIDDEN) )   //
                close_custom_reminderbox();
        }
        break;
        default:
		break;
	}
}


void display_timeout_callback(struct _lv_timer_t *timer)
{
    if ( lv_obj_has_flag(ui_PanelReminder, LV_OBJ_FLAG_HIDDEN) )  
        return;

    close_custom_reminderbox();

    if ( reminder_display_timeout_opt )
    {
        reminder_display_timeout_opt();
    }
}

void create_custom_reminderbox(char *reminder_msg, bool show_Image)
{
    ///////////////////// VARIABLES ////////////////////
    
    if( ui_PanelReminder == NULL)
    {
        ui_PanelReminder = lv_obj_create(lv_layer_top());
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        lv_obj_set_width(ui_PanelReminder, 340);
        lv_obj_set_height(ui_PanelReminder, 50);
        // lv_obj_set_x(ui_PanelReminder, -85);
        // lv_obj_set_y(ui_PanelReminder, -34);
        lv_obj_set_align(ui_PanelReminder, LV_ALIGN_CENTER);
        lv_obj_clear_flag(ui_PanelReminder, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        lv_obj_set_style_radius(ui_PanelReminder, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        //lv_obj_set_style_bg_color(ui_PanelReminder, lv_color_hex(0x434549), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_PanelReminder, lv_color_hex(0x36383C), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(ui_PanelReminder, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_color(ui_PanelReminder, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_opa(ui_PanelReminder, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_border_side(ui_PanelReminder, LV_BORDER_SIDE_NONE, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_ImageReminder = lv_img_create(ui_PanelReminder);
        lv_obj_set_width(ui_ImageReminder, 30);
        lv_obj_set_height(ui_ImageReminder, 30);
        lv_obj_set_x(ui_ImageReminder, -12);
        lv_obj_set_y(ui_ImageReminder, -12);
        lv_obj_add_flag(ui_ImageReminder, LV_OBJ_FLAG_ADV_HITTEST | LV_OBJ_FLAG_CLICKABLE);     /// Flags
        lv_obj_clear_flag(ui_ImageReminder, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
        //lv_obj_set_style_bg_img_src(ui_ImageReminder, &ui_img_hook_png, LV_PART_MAIN | LV_STATE_DEFAULT);

        ui_LabelReminder = lv_label_create(ui_PanelReminder);
        lv_obj_set_width(ui_LabelReminder, LV_SIZE_CONTENT);
        lv_obj_set_height(ui_LabelReminder, LV_SIZE_CONTENT);
        lv_obj_set_x(ui_LabelReminder, 21);
        lv_obj_set_y(ui_LabelReminder, 0);
        lv_obj_set_align(ui_LabelReminder, LV_ALIGN_CENTER);
        lv_label_set_long_mode(ui_LabelReminder, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_style_text_font(ui_LabelReminder, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

        lv_obj_add_event_cb(ui_PanelReminder, reminderbox_close_event_handler, LV_EVENT_ALL, NULL);
        // 定时方案1
        //reminder_display_timeout_timer = lv_timer_create(display_timeout_callback, max_period, NULL);
        //lv_timer_pause(reminder_display_timeout_timer);
    }
    else
    {
        lv_obj_clear_flag(ui_PanelReminder, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    }
    
    if ( ui_LabelReminder )
    {
        if ( reminder_msg )
            lv_label_set_text(ui_LabelReminder, reminder_msg);
        else
            lv_label_set_text(ui_LabelReminder, "");
    }

    if ( show_Image )
    {
        lv_obj_clear_flag(ui_ImageReminder, LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_x(ui_LabelReminder, 21);  //21 is 
    } 
    else
    {
        lv_obj_add_flag(ui_ImageReminder, LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_x(ui_LabelReminder, (340 - 290) / 2 - 22 ); // 340 is reminderbox width, 290 is ui_LabelReminder width, -22 is ui_LabelReminder left pos
    }
    
    reminder_display_timeout_opt = NULL;
    lv_obj_clear_flag(ui_PanelReminder, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_bg_color(lv_layer_top(), lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(lv_layer_top(), 204, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void update_custom_reminderbox_image(const lv_img_dsc_t * img_png)
{
    if ( img_png &&  ui_ImageReminder )
        lv_obj_set_style_bg_img_src(ui_ImageReminder, img_png, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void close_custom_reminderbox()
{
    if ( ui_PanelReminder )
        lv_obj_add_flag(ui_PanelReminder, LV_OBJ_FLAG_HIDDEN);
        
    lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
    lv_obj_set_style_bg_opa(lv_layer_top(), 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // // 定时方案1
    // if ( reminder_display_timeout_timer )
    //     //lv_timer_set_period(reminder_display_timeout_timer, max_period);
    //     lv_timer_pause(reminder_display_timeout_timer);
}

void set_custom_reminderbox_clickable(bool enable)
{
    if ( enable )
        lv_obj_add_flag(ui_PanelReminder, LV_OBJ_FLAG_CLICKABLE);
    else
        lv_obj_clear_flag(ui_PanelReminder, LV_OBJ_FLAG_CLICKABLE);
}

void set_custom_reminderbox_display_timeout(uint16_t timeout_second , void (*timeout_opt)(void))
{
    reminder_display_timeout_opt = timeout_opt;

    // 定时方案1
    //if ( reminder_display_timeout_timer )
    //{
        // lv_timer_pause(reminder_display_timeout_timer);
        // lv_timer_reset(reminder_display_timeout_timer);
        // lv_timer_set_period(reminder_display_timeout_timer, timeout_second * 1000);
        // lv_timer_resume(reminder_display_timeout_timer);  
    //}
    
    // 定时方案2 timer repeat_count is zero, it will be delete
    lv_timer_t *reminder_display_timer = lv_timer_create(display_timeout_callback, timeout_second * 1000, NULL);
    lv_timer_set_repeat_count(reminder_display_timer, 1);
}