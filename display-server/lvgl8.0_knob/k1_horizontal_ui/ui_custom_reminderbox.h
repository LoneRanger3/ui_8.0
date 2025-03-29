#ifndef _UI_CUSTOM_REMINDERBOX_H
#define _UI_CUSTOM_REMINDERBOX_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl/lvgl.h"
#include "ui.h"

/*********reminderbox Cannot be clicked by default, need manual open***********/
void create_custom_reminderbox(char *reminder_msg, bool show_Image);

//set reminder show png image (size (30*30)),need create_custom_reminderbox param show_image is true
void update_custom_reminderbox_image(const lv_img_dsc_t * img_png); 
void close_custom_reminderbox();  //manual close reminderbox
void set_custom_reminderbox_clickable(bool enable);  //set reminderbox clickable
/*reminderbox will auto close after timeout_second seconds ,and you can do some thing int timeout_opt fun.
 if timeout_opt is NULL, it will do noting */
void set_custom_reminderbox_display_timeout(uint16_t timeout_second, void (*timeout_opt)(void));  

#ifdef __cplusplus
}
#endif

#endif