/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "lvgl/lvgl.h"
#include <stdio.h>
#include "lv_lib_png/lv_png.h"
#include "gui_guider.h"
#include "commu_thread.h"

void setup_ui(lv_ui *ui){
    lv_png_init();
	LV_THEME_DEFAULT_INIT(LV_THEME_DEFAULT_COLOR_PRIMARY, LV_THEME_DEFAULT_COLOR_SECONDARY,
		LV_THEME_MATERIAL_FLAG_LIGHT, LV_THEME_DEFAULT_FONT_SMALL,  LV_THEME_DEFAULT_FONT_NORMAL,
		LV_THEME_DEFAULT_FONT_SUBTITLE, LV_THEME_DEFAULT_FONT_TITLE);
//	setup_scr_home(ui);
    get_printer_data(0x09, 1, "0");
    ui->home = lv_obj_create(NULL, NULL);
	lv_scr_load(ui->home);
}
