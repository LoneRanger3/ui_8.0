#ifndef _UI_SCREEN_FACTORYTEST_H
#define _UI_SCREEN_FACTORYTEST_H
#ifdef __cplusplus
extern "C" {
#endif


#include "ui.h"
#include "ui_helpers.h"
#include <stdio.h>
#include <string.h>
#include "ui_custom_numbers_keys.h"
#include "ui_custom_messagebox.h"
#include "../custom/lvgl_cmd.h"
#include "ui_Screen_Settings.h"
#include "ui_Screen_CustomerService.h"
#include "mult_language.h"
#include "Base/DisplayMsgBase.h"
#include "custom/commu_thread.h"
#include "../lvgl/src/widgets/lv_canvas.h"
#include "../Message/ServerMessage.h"


/*Data of canvas*/
typedef struct {
    lv_img_t img;
    lv_img_dsc_t dsc;
    lv_draw_line_dsc_t line_rect_dsc;
    lv_obj_t* circle;
} lv_sketchpad_t;

void ui_ScreenFactoryTest_screen_init(void);
void ui_load_FactotytestScreen(void);
void refresh_factory_gpio_filament(char status);
void refresh_factory_bed_temp(int temp);
void refresh_factory_case_temp(int temp);
void ui_factory_show_wifi_list(char *data,int len);
void refresh_factory_usb_status(void);

#ifdef __cplusplus
}
#endif

#endif