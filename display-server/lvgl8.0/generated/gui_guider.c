/*
 * @Description : 
 * @Author      : lisiqin
 * @Date: 2022-10-21 12:10:58
 * @LastEditTime: 2023-01-06 18:10:28
 */


#include "lvgl/lvgl.h"
#include <stdio.h>
#include "gui_guider.h"


void setup_ui(lv_ui *ui){
	// lv_png_init();
    get_printer_data(0x11, 1, "0");
    get_printer_data(0x06, 1, "9");
    get_printer_data(0x06, 1, "c");
    ui->home = lv_obj_create(NULL);
	lv_scr_load(ui->home);
}
