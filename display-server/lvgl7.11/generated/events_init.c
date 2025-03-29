/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 */

#include "events_init.h"
#include <stdio.h>
#include <stdlib.h>
#include "lvgl/lvgl.h"


#include "custom.h"
#include "clanguage.h"
#include "commu_thread.h"

void events_init(lv_ui *ui)
{
}

static void home_btn_printingevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		guider_load_screen(SCR_PRINTINGSET_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.PrintingSet_cont_printing_set, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

void events_init_home(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->home_btn_printing, home_btn_printingevent_handler);
}

static void menu_btn_homeevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
		  return;
        send_buzzer(0x01);
		lv_btn_set_state(guider_ui.menu_btn_home,LV_BTN_STATE_PRESSED);
		lv_btn_set_state(guider_ui.menu_btn_print,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.menu_btn_prepare,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.menu_btn_setting,LV_BTN_STATE_RELEASED);
		lv_obj_set_click(guider_ui.menu_btn_home, false);
		lv_obj_set_click(guider_ui.menu_btn_print, true);
		lv_obj_set_click(guider_ui.menu_btn_prepare, true);
		lv_obj_set_click(guider_ui.menu_btn_setting, true);
		lv_obj_set_click(guider_ui.menu_img_home, false);
		lv_obj_set_click(guider_ui.menu_img_print, true);
		lv_obj_set_click(guider_ui.menu_img_prepare, true);
		lv_obj_set_click(guider_ui.menu_img_setting, true);
		guider_load_screen(SCR_HOME_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.home_cont_home, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

static void menu_btn_printevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
		  return;
        send_buzzer(0x01);
		lv_btn_set_state(guider_ui.menu_btn_home,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.menu_btn_print,LV_BTN_STATE_PRESSED);
		lv_btn_set_state(guider_ui.menu_btn_prepare,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.menu_btn_setting,LV_BTN_STATE_RELEASED);
		lv_obj_set_click(guider_ui.menu_btn_home, true);
		lv_obj_set_click(guider_ui.menu_btn_print, false);
		lv_obj_set_click(guider_ui.menu_btn_prepare, true);
		lv_obj_set_click(guider_ui.menu_btn_setting, true);
		lv_obj_set_click(guider_ui.menu_img_home, true);
		lv_obj_set_click(guider_ui.menu_img_print, false);
		lv_obj_set_click(guider_ui.menu_img_prepare, true);
		lv_obj_set_click(guider_ui.menu_img_setting, true);
		msg_id = PRINT_NORMAL;
		current_page = 0;
		guider_load_screen(SCR_PRINT_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.print_cont_print, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

static void menu_btn_prepareevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
		  return;
        send_buzzer(0x01);
		lv_btn_set_state(guider_ui.menu_btn_home,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.menu_btn_print,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.menu_btn_prepare,LV_BTN_STATE_PRESSED);
		lv_btn_set_state(guider_ui.menu_btn_setting,LV_BTN_STATE_RELEASED);
		lv_obj_set_click(guider_ui.menu_btn_home, true);
		lv_obj_set_click(guider_ui.menu_btn_print, true);
		lv_obj_set_click(guider_ui.menu_btn_prepare, false);
		lv_obj_set_click(guider_ui.menu_btn_setting, true);
		lv_obj_set_click(guider_ui.menu_img_home, true);
		lv_obj_set_click(guider_ui.menu_img_print, true);
		lv_obj_set_click(guider_ui.menu_img_prepare, false);
		lv_obj_set_click(guider_ui.menu_img_setting, true);
		guider_load_screen(SCR_PREPARE_MOVE_AXIS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.prepare_move_axis_cont_prepare_move_axis, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

static void menu_btn_settingevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
		  return;
        send_buzzer(0x01);
		lv_btn_set_state(guider_ui.menu_btn_home,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.menu_btn_print,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.menu_btn_prepare,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.menu_btn_setting,LV_BTN_STATE_PRESSED);
		lv_obj_set_click(guider_ui.menu_btn_home, true);
		lv_obj_set_click(guider_ui.menu_btn_print, true);
		lv_obj_set_click(guider_ui.menu_btn_prepare, true);
		lv_obj_set_click(guider_ui.menu_btn_setting, false);
		lv_obj_set_click(guider_ui.menu_img_home, true);
		lv_obj_set_click(guider_ui.menu_img_print, true);
		lv_obj_set_click(guider_ui.menu_img_prepare, true);
		lv_obj_set_click(guider_ui.menu_img_setting, false);
		guider_load_screen(SCR_SETTING_DEVICE_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.setting_device_cont_seting_device, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

static void menu_img_homeevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
		  return;
        send_buzzer(0x01);
		lv_btn_set_state(guider_ui.menu_btn_home,LV_BTN_STATE_PRESSED);
		lv_btn_set_state(guider_ui.menu_btn_print,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.menu_btn_prepare,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.menu_btn_setting,LV_BTN_STATE_RELEASED);
		lv_obj_set_click(guider_ui.menu_btn_home, false);
		lv_obj_set_click(guider_ui.menu_btn_print, true);
		lv_obj_set_click(guider_ui.menu_btn_prepare, true);
		lv_obj_set_click(guider_ui.menu_btn_setting, true);
		lv_obj_set_click(guider_ui.menu_img_home, false);
		lv_obj_set_click(guider_ui.menu_img_print, true);
		lv_obj_set_click(guider_ui.menu_img_prepare, true);
		lv_obj_set_click(guider_ui.menu_img_setting, true);
		guider_load_screen(SCR_HOME_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.home_cont_home, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

static void menu_img_printevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
		  return;
        send_buzzer(0x01);
		lv_btn_set_state(guider_ui.menu_btn_home,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.menu_btn_print,LV_BTN_STATE_PRESSED);
		lv_btn_set_state(guider_ui.menu_btn_prepare,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.menu_btn_setting,LV_BTN_STATE_RELEASED);
		lv_obj_set_click(guider_ui.menu_btn_home, true);
		lv_obj_set_click(guider_ui.menu_btn_print, false);
		lv_obj_set_click(guider_ui.menu_btn_prepare, true);
		lv_obj_set_click(guider_ui.menu_btn_setting, true);
		lv_obj_set_click(guider_ui.menu_img_home, true);
		lv_obj_set_click(guider_ui.menu_img_print, false);
		lv_obj_set_click(guider_ui.menu_img_prepare, true);
		lv_obj_set_click(guider_ui.menu_img_setting, true);
		msg_id = PRINT_NORMAL;
		current_page = 0;
		guider_load_screen(SCR_PRINT_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.print_cont_print, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

static void menu_img_prepareevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
		  return;
        send_buzzer(0x01);
		lv_btn_set_state(guider_ui.menu_btn_home,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.menu_btn_print,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.menu_btn_prepare,LV_BTN_STATE_PRESSED);
		lv_btn_set_state(guider_ui.menu_btn_setting,LV_BTN_STATE_RELEASED);
		lv_obj_set_click(guider_ui.menu_btn_home, true);
		lv_obj_set_click(guider_ui.menu_btn_print, true);
		lv_obj_set_click(guider_ui.menu_btn_prepare, false);
		lv_obj_set_click(guider_ui.menu_btn_setting, true);
		lv_obj_set_click(guider_ui.menu_img_home, true);
		lv_obj_set_click(guider_ui.menu_img_print, true);
		lv_obj_set_click(guider_ui.menu_img_prepare, false);
		lv_obj_set_click(guider_ui.menu_img_setting, true);
		guider_load_screen(SCR_PREPARE_MOVE_AXIS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.prepare_move_axis_cont_prepare_move_axis, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

static void menu_img_settingevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
		  return;
        send_buzzer(0x01);
		lv_btn_set_state(guider_ui.menu_btn_home,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.menu_btn_print,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.menu_btn_prepare,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.menu_btn_setting,LV_BTN_STATE_PRESSED);
		lv_obj_set_click(guider_ui.menu_btn_home, true);
		lv_obj_set_click(guider_ui.menu_btn_print, true);
		lv_obj_set_click(guider_ui.menu_btn_prepare, true);
		lv_obj_set_click(guider_ui.menu_btn_setting, false);
		lv_obj_set_click(guider_ui.menu_img_home, true);
		lv_obj_set_click(guider_ui.menu_img_print, true);
		lv_obj_set_click(guider_ui.menu_img_prepare, true);
		lv_obj_set_click(guider_ui.menu_img_setting, false);
		guider_load_screen(SCR_SETTING_DEVICE_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.setting_device_cont_seting_device, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

void events_init_menu(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->menu_btn_home, menu_btn_homeevent_handler);
	lv_obj_set_event_cb(ui->menu_btn_print, menu_btn_printevent_handler);
	lv_obj_set_event_cb(ui->menu_btn_prepare, menu_btn_prepareevent_handler);
	lv_obj_set_event_cb(ui->menu_btn_setting, menu_btn_settingevent_handler);
	lv_obj_set_event_cb(ui->menu_img_home, menu_img_homeevent_handler);
	lv_obj_set_event_cb(ui->menu_img_print, menu_img_printevent_handler);
	lv_obj_set_event_cb(ui->menu_img_prepare, menu_img_prepareevent_handler);
	lv_obj_set_event_cb(ui->menu_img_setting, menu_img_settingevent_handler);
}

static void print_btn_page_endevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
	    send_buzzer(0x01);
        if((current_page+1) != print_file_pages)
        {
            lv_list_clean(guider_ui.print_list_1);
            current_page = print_file_pages - 1;
            handle_file();
        }
	}
		break;
	default:
		break;
	}
}

static void print_btn_page_nextevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
	    send_buzzer(0x01);
	    if((current_page+1) < print_file_pages)
        {
            lv_list_clean(guider_ui.print_list_1);
            current_page++;
            if(current_page > (print_file_pages - 1))
            {
                current_page = print_file_pages - 1;
            }
            handle_file();
        }
	}
		break;
	default:
		break;
	}
}

static void print_img_page_nextevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		send_buzzer(0x01);
		lv_btn_set_state(guider_ui.print_btn_page_next,LV_BTN_STATE_RELEASED);
        if((current_page+1) < print_file_pages)
        {
            lv_list_clean(guider_ui.print_list_1);
            current_page++;
            if(current_page > (print_file_pages - 1))
            {
                current_page = print_file_pages - 1;
            }
            handle_file();
        }
	}
		break;
    case LV_EVENT_PRESSED:
        lv_btn_set_state(guider_ui.print_btn_page_next,LV_BTN_STATE_PRESSED);
        break;
	default:
		break;
	}
}

static void print_btn_page_preevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
	    send_buzzer(0x01);
	    if(current_page > 0)
        {
            lv_list_clean(guider_ui.print_list_1);
            if(current_page > 0)
            {
                current_page--;
            }
            handle_file();
        }
	}
		break;
	default:
		break;
	}
}

static void print_img_page_preevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		send_buzzer(0x01);
		lv_btn_set_state(guider_ui.print_btn_page_pre,LV_BTN_STATE_RELEASED);
        if(current_page > 0)
        {
            lv_list_clean(guider_ui.print_list_1);
            if(current_page > 0)
            {
                current_page--;
            }
            handle_file();
        }
	}
		break;
    case LV_EVENT_PRESSED:
        lv_btn_set_state(guider_ui.print_btn_page_pre,LV_BTN_STATE_PRESSED);
        break;
	default:
		break;
	}
}

static void print_img_page_endevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		send_buzzer(0x01);
		lv_btn_set_state(guider_ui.print_btn_page_end,LV_BTN_STATE_RELEASED);
        if((current_page+1) != print_file_pages)
        {
            lv_list_clean(guider_ui.print_list_1);
            current_page = print_file_pages - 1;
            handle_file();
        }
	}
		break;
    case LV_EVENT_PRESSED:
        lv_btn_set_state(guider_ui.print_btn_page_end,LV_BTN_STATE_PRESSED);
        break;
	default:
		break;
	}
}

static void print_btn_page_homeevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
	    send_buzzer(0x01);
        if(current_page > 0)
        {
            lv_list_clean(guider_ui.print_list_1);
            current_page = 0;
            handle_file();
        }
	}
		break;
	default:
		break;
	}
}

static void print_img_page_homeevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		send_buzzer(0x01);
		lv_btn_set_state(guider_ui.print_btn_page_home,LV_BTN_STATE_RELEASED);
        if(current_page > 0)
        {
            lv_list_clean(guider_ui.print_list_1);
            current_page = 0;
            handle_file();
        }
	}
		break;
    case LV_EVENT_PRESSED:
        lv_btn_set_state(guider_ui.print_btn_page_home,LV_BTN_STATE_PRESSED);
        break;
	default:
		break;
	}
}

void events_init_print(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->print_btn_page_end, print_btn_page_endevent_handler);
	lv_obj_set_event_cb(ui->print_btn_page_next, print_btn_page_nextevent_handler);
	lv_obj_set_event_cb(ui->print_img_page_next, print_img_page_nextevent_handler);
	lv_obj_set_event_cb(ui->print_btn_page_pre, print_btn_page_preevent_handler);
	lv_obj_set_event_cb(ui->print_img_page_pre, print_img_page_preevent_handler);
	lv_obj_set_event_cb(ui->print_img_page_end, print_img_page_endevent_handler);
	lv_obj_set_event_cb(ui->print_btn_page_home, print_btn_page_homeevent_handler);
	lv_obj_set_event_cb(ui->print_img_page_home, print_img_page_homeevent_handler);
}

static void prepare_menu_btn_move_axisevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
		  return;
        send_buzzer(0x01);
		lv_btn_set_state(guider_ui.prepare_menu_btn_manual_temp,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.prepare_menu_btn_move_e,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.prepare_menu_btn_move_axis,LV_BTN_STATE_PRESSED);
		lv_obj_set_click(guider_ui.prepare_menu_btn_manual_temp, true);
		lv_obj_set_click(guider_ui.prepare_menu_btn_move_e, true);
		lv_obj_set_click(guider_ui.prepare_menu_btn_move_axis, false);
		guider_load_screen(SCR_PREPARE_MOVE_AXIS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.prepare_move_axis_cont_prepare_move_axis, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

static void prepare_menu_btn_move_eevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
		  return;
        send_buzzer(0x01);
		lv_btn_set_state(guider_ui.prepare_menu_btn_manual_temp,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.prepare_menu_btn_move_e,LV_BTN_STATE_PRESSED);
		lv_btn_set_state(guider_ui.prepare_menu_btn_move_axis,LV_BTN_STATE_RELEASED);
		lv_obj_set_click(guider_ui.prepare_menu_btn_manual_temp, true);
		lv_obj_set_click(guider_ui.prepare_menu_btn_move_e, false);
		lv_obj_set_click(guider_ui.prepare_menu_btn_move_axis, true);
		guider_load_screen(SCR_PREPARE_MATERIAL_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.prepare_material_cont_prepare_material, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

static void prepare_menu_btn_manual_tempevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
		  return;
        send_buzzer(0x01);
		lv_btn_set_state(guider_ui.prepare_menu_btn_manual_temp,LV_BTN_STATE_PRESSED);
		lv_btn_set_state(guider_ui.prepare_menu_btn_move_e,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.prepare_menu_btn_move_axis,LV_BTN_STATE_RELEASED);
		lv_obj_set_click(guider_ui.prepare_menu_btn_manual_temp, false);
		lv_obj_set_click(guider_ui.prepare_menu_btn_move_e, true);
		lv_obj_set_click(guider_ui.prepare_menu_btn_move_axis, true);
		guider_load_screen(SCR_PREPARE_MANUAL_TEMP_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.prepare_manual_temp_cont_prepare_manual_temp, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

void events_init_prepare_menu(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->prepare_menu_btn_move_axis, prepare_menu_btn_move_axisevent_handler);
	lv_obj_set_event_cb(ui->prepare_menu_btn_move_e, prepare_menu_btn_move_eevent_handler);
	lv_obj_set_event_cb(ui->prepare_menu_btn_manual_temp, prepare_menu_btn_manual_tempevent_handler);
}

static void prepare_move_axis_btn_13event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
        //z home
        send_buzzer(0x01);
        set_printer_data(0x07,3,"B00");
	}
		break;
	default:
		break;
	}
}

static void prepare_move_axis_btn_12event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		// XY home
		send_buzzer(0x01);
		set_printer_data(0x07,3,"A00");
	}
		break;
	default:
		break;
	}
}

static void prepare_move_axis_btn_move_uintcevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		lv_btn_set_state(guider_ui.prepare_move_axis_btn_move_uinta,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.prepare_move_axis_btn_move_uintb,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.prepare_move_axis_btn_move_uintc,LV_BTN_STATE_PRESSED);
		lv_obj_set_click(guider_ui.prepare_move_axis_btn_move_uinta, true);
		lv_obj_set_click(guider_ui.prepare_move_axis_btn_move_uintb, true);
		lv_obj_set_click(guider_ui.prepare_move_axis_btn_move_uintc, false);
		axis_move_uint = '2';
	}
		break;
	default:
		break;
	}
}

static void prepare_move_axis_btn_move_uintbevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		lv_btn_set_state(guider_ui.prepare_move_axis_btn_move_uinta,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.prepare_move_axis_btn_move_uintb,LV_BTN_STATE_PRESSED);
		lv_btn_set_state(guider_ui.prepare_move_axis_btn_move_uintc,LV_BTN_STATE_RELEASED);
		lv_obj_set_click(guider_ui.prepare_move_axis_btn_move_uinta, true);
		lv_obj_set_click(guider_ui.prepare_move_axis_btn_move_uintb, false);
		lv_obj_set_click(guider_ui.prepare_move_axis_btn_move_uintc, true);
		axis_move_uint = '1';
	}
		break;
	default:
		break;
	}
}

static void prepare_move_axis_btn_move_uintaevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		lv_btn_set_state(guider_ui.prepare_move_axis_btn_move_uinta,LV_BTN_STATE_PRESSED);
		lv_btn_set_state(guider_ui.prepare_move_axis_btn_move_uintb,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.prepare_move_axis_btn_move_uintc,LV_BTN_STATE_RELEASED);
		lv_obj_set_click(guider_ui.prepare_move_axis_btn_move_uinta, false);
		lv_obj_set_click(guider_ui.prepare_move_axis_btn_move_uintb, true);
		lv_obj_set_click(guider_ui.prepare_move_axis_btn_move_uintc, true);
		axis_move_uint = '0';
	}
		break;
	default:
		break;
	}
}

static void prepare_move_axis_imgbtn_motor_z_downevent_handler(lv_obj_t * obj, lv_event_t event)
{
    static lv_style_t style_prepare_move_axis_imgbtn_motor_z_down_main;

	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		//down z
		send_buzzer(0x01);
        lv_style_reset(&style_prepare_move_axis_imgbtn_motor_z_down_main);

        //Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_z_down_main
        lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_z_down_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
        lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_z_down_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_z_down_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_z_down_main, LV_STATE_DEFAULT, 255);
        lv_obj_add_style(guider_ui.prepare_move_axis_imgbtn_motor_z_down, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_z_down_main);
        char buf[4] = "Z0";
        buf[2] = axis_move_uint;
        set_printer_data(0x07,3,buf);
	}
		break;
    case LV_EVENT_PRESSED:
        lv_style_reset(&style_prepare_move_axis_imgbtn_motor_z_down_main);

        //Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_z_down_main
        lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_z_down_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
        lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_z_down_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_z_down_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_z_down_main, LV_STATE_DEFAULT, 50);
        lv_obj_add_style(guider_ui.prepare_move_axis_imgbtn_motor_z_down, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_z_down_main);
        break;
	default:
		break;
	}
}

static void prepare_move_axis_imgbtn_motor_z_upevent_handler(lv_obj_t * obj, lv_event_t event)
{
    static lv_style_t style_prepare_move_axis_imgbtn_motor_z_up_main;

	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		//up z
		send_buzzer(0x01);
        lv_style_reset(&style_prepare_move_axis_imgbtn_motor_z_up_main);

        //Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_z_up_main
        lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_z_up_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
        lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_z_up_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_z_up_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_z_up_main, LV_STATE_DEFAULT, 255);
        lv_obj_add_style(guider_ui.prepare_move_axis_imgbtn_motor_z_up, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_z_up_main);
        char buf[4] = "Z1";
        buf[2] = axis_move_uint;
        set_printer_data(0x07,3,buf);
	}
		break;
	case LV_EVENT_PRESSED:
        lv_style_reset(&style_prepare_move_axis_imgbtn_motor_z_up_main);

        //Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_z_up_main
        lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_z_up_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
        lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_z_up_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_z_up_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_z_up_main, LV_STATE_DEFAULT, 50);
        lv_obj_add_style(guider_ui.prepare_move_axis_imgbtn_motor_z_up, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_z_up_main);
        break;
	default:
		break;
	}
}

static void prepare_move_axis_imgbtn_motor_x_rightevent_handler(lv_obj_t * obj, lv_event_t event)
{
    static lv_style_t style_prepare_move_axis_imgbtn_motor_x_right_main;

	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		//right x
		send_buzzer(0x01);
        lv_style_reset(&style_prepare_move_axis_imgbtn_motor_x_right_main);

        //Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_x_right_main
        lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_x_right_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
        lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_x_right_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_x_right_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_x_right_main, LV_STATE_DEFAULT, 255);
        lv_obj_add_style(guider_ui.prepare_move_axis_imgbtn_motor_x_right, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_x_right_main);
        char buf[4] = "X1";
        buf[2] = axis_move_uint;
        set_printer_data(0x07,3,buf);
	}
		break;
    case LV_EVENT_PRESSED:
         lv_style_reset(&style_prepare_move_axis_imgbtn_motor_x_right_main);

        //Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_x_right_main
        lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_x_right_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
        lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_x_right_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_x_right_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_x_right_main, LV_STATE_DEFAULT, 50);
        lv_obj_add_style(guider_ui.prepare_move_axis_imgbtn_motor_x_right, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_x_right_main);
        break;
	default:
		break;
	}
}

static void prepare_move_axis_imgbtn_motor_x_leftevent_handler(lv_obj_t * obj, lv_event_t event)
{
    static lv_style_t style_prepare_move_axis_imgbtn_motor_x_left_main;

	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		//left x
		send_buzzer(0x01);
        lv_style_reset(&style_prepare_move_axis_imgbtn_motor_x_left_main);

        //Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_x_left_main
        lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_x_left_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
        lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_x_left_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_x_left_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_x_left_main, LV_STATE_DEFAULT, 255);
        lv_obj_add_style(guider_ui.prepare_move_axis_imgbtn_motor_x_left, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_x_left_main);
        char buf[4] = "X0";
        buf[2] = axis_move_uint;
        set_printer_data(0x07,3,buf);
	}
		break;
    case LV_EVENT_PRESSED:
        lv_style_reset(&style_prepare_move_axis_imgbtn_motor_x_left_main);

        //Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_x_left_main
        lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_x_left_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
        lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_x_left_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_x_left_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_x_left_main, LV_STATE_DEFAULT, 50);
        lv_obj_add_style(guider_ui.prepare_move_axis_imgbtn_motor_x_left, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_x_left_main);
        break;
	default:
		break;
	}
}

static void prepare_move_axis_imgbtn_motor_y_downevent_handler(lv_obj_t * obj, lv_event_t event)
{
    static lv_style_t style_prepare_move_axis_imgbtn_motor_y_down_main;

	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		//down y
		send_buzzer(0x01);
        lv_style_reset(&style_prepare_move_axis_imgbtn_motor_y_down_main);

        //Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_y_down_main
        lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_y_down_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
        lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_y_down_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_y_down_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_y_down_main, LV_STATE_DEFAULT, 255);
        lv_obj_add_style(guider_ui.prepare_move_axis_imgbtn_motor_y_down, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_y_down_main);
        char buf[4] = "Y0";
        buf[2] = axis_move_uint;
        set_printer_data(0x07,3,buf);
	}
        break;
	case LV_EVENT_PRESSED:
        lv_style_reset(&style_prepare_move_axis_imgbtn_motor_y_down_main);

        //Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_y_down_main
        lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_y_down_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
        lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_y_down_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_y_down_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_y_down_main, LV_STATE_DEFAULT, 50);
        lv_obj_add_style(guider_ui.prepare_move_axis_imgbtn_motor_y_down, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_y_down_main);
		break;
	default:
		break;
	}
}

static void prepare_move_axis_imgbtn_motor_y_upevent_handler(lv_obj_t * obj, lv_event_t event)
{
    static lv_style_t style_prepare_move_axis_imgbtn_motor_y_up_main;

	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
	    send_buzzer(0x01);
        lv_style_reset(&style_prepare_move_axis_imgbtn_motor_y_up_main);

        //Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_y_up_main
        lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_y_up_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
        lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_y_up_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_y_up_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_y_up_main, LV_STATE_DEFAULT, 255);
        lv_obj_add_style(guider_ui.prepare_move_axis_imgbtn_motor_y_up, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_y_up_main);
        char buf[4] = "Y1";
        buf[2] = axis_move_uint;
        set_printer_data(0x07,3,buf);
	}
		break;
    case LV_EVENT_PRESSED:
        lv_style_reset(&style_prepare_move_axis_imgbtn_motor_y_up_main);

        //Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_y_up_main
        lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_y_up_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
        lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_y_up_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_y_up_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_y_up_main, LV_STATE_DEFAULT, 50);
        lv_obj_add_style(guider_ui.prepare_move_axis_imgbtn_motor_y_up, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_y_up_main);
        break;
	default:
		break;
	}
}

static void prepare_move_axis_imgbtn_motor_z_homeevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		// z home
		send_buzzer(0x01);
        lv_btn_set_state(guider_ui.prepare_move_axis_btn_13,LV_BTN_STATE_RELEASED);
        set_printer_data(0x07,3,"B00");
	}
		break;
    case LV_EVENT_PRESSED:
        lv_btn_set_state(guider_ui.prepare_move_axis_btn_13,LV_BTN_STATE_PRESSED);
        break;
	default:
		break;
	}
}

static void prepare_move_axis_imgbtn_motor_xy_homeevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		//xy home
		send_buzzer(0x01);
		lv_btn_set_state(guider_ui.prepare_move_axis_btn_12,LV_BTN_STATE_RELEASED);
		set_printer_data(0x07,3,"A00");
	}
		break;
    case LV_EVENT_PRESSED:
        lv_btn_set_state(guider_ui.prepare_move_axis_btn_12,LV_BTN_STATE_PRESSED);
        break;
	default:
		break;
	}
}

static void prepare_move_axis_imgbtn_motor_lossevent_handler(lv_obj_t * obj, lv_event_t event)
{
    static lv_style_t style_prepare_move_axis_imgbtn_motor_loss_main;

	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
		//motor
		send_buzzer(0x01);
        lv_style_reset(&style_prepare_move_axis_imgbtn_motor_loss_main);

        //Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_loss_main
        lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_loss_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
        lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_loss_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_loss_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_loss_main, LV_STATE_DEFAULT, 255);
        lv_obj_add_style(guider_ui.prepare_move_axis_imgbtn_motor_loss, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_loss_main);
        if(motor_loss_state)
        {
            set_printer_data(0x08,1,"1");
        }
        else
        {
            set_printer_data(0x08,1,"2");
        }
	}
		break;
    case LV_EVENT_PRESSED:
        lv_style_reset(&style_prepare_move_axis_imgbtn_motor_loss_main);

        //Write style state: LV_STATE_DEFAULT for style_prepare_move_axis_imgbtn_motor_loss_main
        lv_style_set_text_color(&style_prepare_move_axis_imgbtn_motor_loss_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
        lv_style_set_image_recolor(&style_prepare_move_axis_imgbtn_motor_loss_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_prepare_move_axis_imgbtn_motor_loss_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_prepare_move_axis_imgbtn_motor_loss_main, LV_STATE_DEFAULT, 50);
        lv_obj_add_style(guider_ui.prepare_move_axis_imgbtn_motor_loss, LV_IMGBTN_PART_MAIN, &style_prepare_move_axis_imgbtn_motor_loss_main);
        break;
	default:
		break;
	}
}

void events_init_prepare_move_axis(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->prepare_move_axis_btn_13, prepare_move_axis_btn_13event_handler);
	lv_obj_set_event_cb(ui->prepare_move_axis_btn_12, prepare_move_axis_btn_12event_handler);
	lv_obj_set_event_cb(ui->prepare_move_axis_btn_move_uintc, prepare_move_axis_btn_move_uintcevent_handler);
	lv_obj_set_event_cb(ui->prepare_move_axis_btn_move_uintb, prepare_move_axis_btn_move_uintbevent_handler);
	lv_obj_set_event_cb(ui->prepare_move_axis_btn_move_uinta, prepare_move_axis_btn_move_uintaevent_handler);
	lv_obj_set_event_cb(ui->prepare_move_axis_imgbtn_motor_z_down, prepare_move_axis_imgbtn_motor_z_downevent_handler);
	lv_obj_set_event_cb(ui->prepare_move_axis_imgbtn_motor_z_up, prepare_move_axis_imgbtn_motor_z_upevent_handler);
	lv_obj_set_event_cb(ui->prepare_move_axis_imgbtn_motor_x_right, prepare_move_axis_imgbtn_motor_x_rightevent_handler);
	lv_obj_set_event_cb(ui->prepare_move_axis_imgbtn_motor_x_left, prepare_move_axis_imgbtn_motor_x_leftevent_handler);
	lv_obj_set_event_cb(ui->prepare_move_axis_imgbtn_motor_y_down, prepare_move_axis_imgbtn_motor_y_downevent_handler);
	lv_obj_set_event_cb(ui->prepare_move_axis_imgbtn_motor_y_up, prepare_move_axis_imgbtn_motor_y_upevent_handler);
	lv_obj_set_event_cb(ui->prepare_move_axis_imgbtn_motor_z_home, prepare_move_axis_imgbtn_motor_z_homeevent_handler);
	lv_obj_set_event_cb(ui->prepare_move_axis_imgbtn_motor_xy_home, prepare_move_axis_imgbtn_motor_xy_homeevent_handler);
	lv_obj_set_event_cb(ui->prepare_move_axis_imgbtn_motor_loss, prepare_move_axis_imgbtn_motor_lossevent_handler);
}

static void prepare_material_slider_1event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_VALUE_CHANGED:
	{
		if(check_time())
		{
		  return;
		}
		snprintf(material_length, MATERIAL_LEN+1, "%u", lv_slider_get_value(guider_ui.prepare_material_slider_1));
		if(material_length[0] != '\0')
        {
            lv_label_set_text(guider_ui.prepare_material_label_material_length, material_length);
        }
	}
		break;
	default:
		break;
	}
}

static void prepare_material_btn_hotend_tempevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
	    for(unsigned char i=0;i<EDIT_TEMP_LEN;i++)
        {
            edit_temp[i] = '\0';
        }
		stack_input(SCR_PREPARE_MATERIAL_PAGE,0x3,HOTEND_TEMP_LEN,&edit_temp[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_hotend_temp = true;
	}
		break;
	default:
		break;
	}
}

static void prepare_material_btn_material_outevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    int num = atoi(hotend_cur_temp);
	    if(num < 180)
        {
            send_buzzer(0x02);
            msgbox("温度过低！");
        }
        else
        {
            send_buzzer(0x01);
            char buf[MATERIAL_LEN+1] = "2";
            for(unsigned char i=0;i<MATERIAL_LEN;i++)
            {
                if(material_length[i] == '\0')
                {
                    break;
                }
                buf[i+1] = material_length[i];
            }
            set_printer_data(0x09,strlen(buf),buf);
        }
	}
		break;
	default:
		break;
	}
}

static void prepare_material_btn_material_inevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    int num = atoi(hotend_cur_temp);
	    if(num < 180)
        {
            send_buzzer(0x02);
            msgbox("温度过低！");
        }
        else
        {
            send_buzzer(0x01);
            char buf[MATERIAL_LEN+1] = "1";
            for(unsigned char i=0;i<MATERIAL_LEN;i++)
            {
                if(material_length[i] == '\0')
                {
                    break;
                }
                buf[i+1] = material_length[i];
            }
            set_printer_data(0x09,strlen(buf),buf);
        }
	}
		break;
	default:
		break;
	}
}

void events_init_prepare_material(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->prepare_material_slider_1, prepare_material_slider_1event_handler);
	lv_obj_set_event_cb(ui->prepare_material_btn_hotend_temp, prepare_material_btn_hotend_tempevent_handler);
	lv_obj_set_event_cb(ui->prepare_material_btn_material_out, prepare_material_btn_material_outevent_handler);
	lv_obj_set_event_cb(ui->prepare_material_btn_material_in, prepare_material_btn_material_inevent_handler);
}

static void prepare_manual_temp_btn_set_hotendevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
	    for(unsigned char i=0;i<EDIT_TEMP_LEN;i++)
        {
            edit_temp[i] = '\0';
        }
		stack_input(SCR_PREPARE_MANUAL_TEMP_PAGE,0x3,HOTEND_TEMP_LEN,&edit_temp[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_hotend_temp = true;
	}
		break;
	default:
		break;
	}
}

static void prepare_manual_temp_btn_coldevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
		set_printer_data(0x0b,2,"31");
	}
		break;
	default:
		break;
	}
}

static void prepare_manual_temp_btn_fan_controlevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
        char buf[3] = "0";
        if(fan_state)
        {
            buf[1] = '0';
        }
        else
        {
            buf[1] = '1';
        }
        set_printer_data(0x0b,2,buf);
	}
		break;
	default:
		break;
	}
}

static void prepare_manual_temp_btn_set_bedevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
	    for(unsigned char i=0;i<EDIT_TEMP_LEN;i++)
        {
            edit_temp[i] = '\0';
        }
		stack_input(SCR_PREPARE_MANUAL_TEMP_PAGE,0x3,BED_TEMP_LEN,&edit_temp[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_bed_temp = true;
	}
		break;
	default:
		break;
	}
}

static void prepare_manual_temp_btn_preheat_PLAevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		set_printer_data(0x0a,1,"1");
	}
		break;
	default:
		break;
	}
}

static void prepare_manual_temp_btn_preheat_ABSevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
		set_printer_data(0x0a,1,"2");
	}
		break;
	default:
		break;
	}
}

void events_init_prepare_manual_temp(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->prepare_manual_temp_btn_set_hotend, prepare_manual_temp_btn_set_hotendevent_handler);
	lv_obj_set_event_cb(ui->prepare_manual_temp_btn_cold, prepare_manual_temp_btn_coldevent_handler);
	lv_obj_set_event_cb(ui->prepare_manual_temp_btn_fan_control, prepare_manual_temp_btn_fan_controlevent_handler);
	lv_obj_set_event_cb(ui->prepare_manual_temp_btn_set_bed, prepare_manual_temp_btn_set_bedevent_handler);
	lv_obj_set_event_cb(ui->prepare_manual_temp_btn_preheat_PLA, prepare_manual_temp_btn_preheat_PLAevent_handler);
	lv_obj_set_event_cb(ui->prepare_manual_temp_btn_preheat_ABS, prepare_manual_temp_btn_preheat_ABSevent_handler);
}

static void setting_menu_btn_aboutevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
		  return;
        send_buzzer(0x01);
		lv_btn_set_state(guider_ui.setting_menu_btn_about,LV_BTN_STATE_PRESSED);
		lv_btn_set_state(guider_ui.setting_menu_btn_ad_setting,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.setting_menu_btn_device,LV_BTN_STATE_RELEASED);
		lv_obj_set_click(guider_ui.setting_menu_btn_about, false);
		lv_obj_set_click(guider_ui.setting_menu_btn_ad_setting, true);
		lv_obj_set_click(guider_ui.setting_menu_btn_device, true);
		guider_load_screen(SCR_SETTING_ABOUT_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.setting_about_cont_setting_about, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

static void setting_menu_btn_ad_settingevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
		  return;
        send_buzzer(0x01);
		lv_btn_set_state(guider_ui.setting_menu_btn_about,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.setting_menu_btn_ad_setting,LV_BTN_STATE_PRESSED);
		lv_btn_set_state(guider_ui.setting_menu_btn_device,LV_BTN_STATE_RELEASED);
		lv_obj_set_click(guider_ui.setting_menu_btn_about, true);
		lv_obj_set_click(guider_ui.setting_menu_btn_ad_setting, false);
		lv_obj_set_click(guider_ui.setting_menu_btn_device, true);
		guider_load_screen(SCR_SETTING_AD_SETTING_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.setting_ad_setting_cont_setting_ad_setting, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

static void setting_menu_btn_deviceevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
		  return;
        send_buzzer(0x01);
		lv_btn_set_state(guider_ui.setting_menu_btn_about,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.setting_menu_btn_ad_setting,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.setting_menu_btn_device,LV_BTN_STATE_PRESSED);
		lv_obj_set_click(guider_ui.setting_menu_btn_about, true);
		lv_obj_set_click(guider_ui.setting_menu_btn_ad_setting, true);
		lv_obj_set_click(guider_ui.setting_menu_btn_device, false);
		guider_load_screen(SCR_SETTING_DEVICE_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.setting_device_cont_seting_device, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

void events_init_setting_menu(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->setting_menu_btn_about, setting_menu_btn_aboutevent_handler);
	lv_obj_set_event_cb(ui->setting_menu_btn_ad_setting, setting_menu_btn_ad_settingevent_handler);
	lv_obj_set_event_cb(ui->setting_menu_btn_device, setting_menu_btn_deviceevent_handler);
}

static void setting_device_btn_poweroffevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
		set_printer_data(0x0b,2,"41");
	}
		break;
	default:
		break;
	}
}

static void setting_device_btn_23event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		stack_preheating(0);
		guider_load_screen(SCR_PREHEATING_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Preheating_cont_preheating, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

static void setting_device_btn_light_controlevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
        char buf[3] = "1";
        if(light_state)
        {
            buf[1] = '0';
        }
        else
        {
            buf[1] = '1';
        }
        set_printer_data(0x0b,2,buf);
	}
		break;
	default:
		break;
	}
}

static void setting_device_btn_26event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
		guider_load_screen(SCR_LANGUAGE_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Language_cont_language, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

static void setting_device_btn_25event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		guider_load_screen(SCR_LEVEL_MANUAL_PAGE);
		lv_obj_set_click(guider_ui.Level_menu_btn_manual_level, false);
		lv_btn_set_state(guider_ui.Level_menu_btn_manual_level,LV_BTN_STATE_CHECKED_RELEASED);
		lv_demo_printer_anim_in_all(guider_ui.Level_manual_cont_level_manual, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

static void setting_device_btn_24event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		stack_preheating(1);
		guider_load_screen(SCR_PREHEATING_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Preheating_cont_preheating, LV_DEMO_PRINTER_ANIM_DELAY);
		lv_label_set_text(guider_ui.Preheating_label_preheat_title, abs_setting[cur_language]);
	}
		break;
	default:
		break;
	}
}

void events_init_setting_device(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->setting_device_btn_poweroff, setting_device_btn_poweroffevent_handler);
	lv_obj_set_event_cb(ui->setting_device_btn_23, setting_device_btn_23event_handler);
	lv_obj_set_event_cb(ui->setting_device_btn_light_control, setting_device_btn_light_controlevent_handler);
	lv_obj_set_event_cb(ui->setting_device_btn_26, setting_device_btn_26event_handler);
	lv_obj_set_event_cb(ui->setting_device_btn_25, setting_device_btn_25event_handler);
	lv_obj_set_event_cb(ui->setting_device_btn_24, setting_device_btn_24event_handler);
}

static void setting_ad_setting_btn_restore_netevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		set_printer_data(0x0b,2,"51");
	}
		break;
	default:
		break;
	}
}

static void setting_ad_setting_btn_set_wifievent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
        char buf[3] = "2";
        if(wifi_state)
        {
            buf[1] = '0';
        }
        else
        {
            buf[1] = '1';
        }
        set_printer_data(0x0b,2,buf);
	}
		break;
	default:
		break;
	}
}

static void setting_ad_setting_btn_factoryevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		set_printer_data(0x0b,2,"61");
	}
		break;
	default:
		break;
	}
}

static void setting_ad_setting_btn_PID_setevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		guider_load_screen(SCR_TEMPPIDSET_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.TempPIDSet_cont_temppid_set, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

static void setting_ad_setting_btn_motion_setevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		guider_load_screen(SCR_MOTIONSET_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.MotionSet_cont_motion_set, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

void events_init_setting_ad_setting(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->setting_ad_setting_btn_restore_net, setting_ad_setting_btn_restore_netevent_handler);
	lv_obj_set_event_cb(ui->setting_ad_setting_btn_set_wifi, setting_ad_setting_btn_set_wifievent_handler);
	lv_obj_set_event_cb(ui->setting_ad_setting_btn_factory, setting_ad_setting_btn_factoryevent_handler);
	lv_obj_set_event_cb(ui->setting_ad_setting_btn_PID_set, setting_ad_setting_btn_PID_setevent_handler);
	lv_obj_set_event_cb(ui->setting_ad_setting_btn_motion_set, setting_ad_setting_btn_motion_setevent_handler);
}

static void Language_btn_chinaevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		set_printer_data(0x0d,1,"0");
	}
		break;
	default:
		break;
	}
}

static void Language_btn_englishevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		set_printer_data(0x0d,1,"1");
	}
		break;
	default:
		break;
	}
}

static void Language_btn_deutschevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		set_printer_data(0x0d,1,"2");
	}
		break;
	default:
		break;
	}
}

static void Language_btn_espanolevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
		set_printer_data(0x0d,1,"3");
	}
		break;
	default:
		break;
	}
}

static void Language_btn_franceevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		set_printer_data(0x0d,1,"4");
	}
		break;
	default:
		break;
	}
}

static void Language_btn_italyevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
		set_printer_data(0x0d,1,"5");
	}
		break;
	default:
		break;
	}
}

static void Language_btn_portuguesevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		set_printer_data(0x0d,1,"6");
	}
		break;
	default:
		break;
	}
}

static void Language_btn_russianevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		set_printer_data(0x0d,1,"7");
	}
		break;
	default:
		break;
	}
}

static void Language_btn_turkishevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		set_printer_data(0x0d,1,"8");
	}
		break;
	default:
		break;
	}
}

void events_init_Language(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->Language_btn_china, Language_btn_chinaevent_handler);
	lv_obj_set_event_cb(ui->Language_btn_english, Language_btn_englishevent_handler);
	lv_obj_set_event_cb(ui->Language_btn_deutsch, Language_btn_deutschevent_handler);
	lv_obj_set_event_cb(ui->Language_btn_espanol, Language_btn_espanolevent_handler);
	lv_obj_set_event_cb(ui->Language_btn_france, Language_btn_franceevent_handler);
	lv_obj_set_event_cb(ui->Language_btn_italy, Language_btn_italyevent_handler);
	lv_obj_set_event_cb(ui->Language_btn_portugues, Language_btn_portuguesevent_handler);
	lv_obj_set_event_cb(ui->Language_btn_russian, Language_btn_russianevent_handler);
	lv_obj_set_event_cb(ui->Language_btn_turkish, Language_btn_turkishevent_handler);
}

static void Level_menu_btn_manual_levelevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
		  return;
        send_buzzer(0x01);
		lv_btn_set_state(guider_ui.Level_menu_btn_auto_level,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.Level_menu_btn_manual_level,LV_BTN_STATE_CHECKED_RELEASED);
		lv_obj_set_click(guider_ui.Level_menu_btn_auto_level, true);
		lv_obj_set_click(guider_ui.Level_menu_btn_manual_level, false);
		guider_load_screen(SCR_LEVEL_MANUAL_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Level_manual_cont_level_manual, LV_DEMO_PRINTER_ANIM_DELAY);

	}
		break;
	default:
		break;
	}
}

static void Level_menu_btn_auto_levelevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
		  return;
        send_buzzer(0x01);
		lv_btn_set_state(guider_ui.Level_menu_btn_manual_level,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.Level_menu_btn_auto_level,LV_BTN_STATE_CHECKED_RELEASED);
		lv_obj_set_click(guider_ui.Level_menu_btn_auto_level, false);
		lv_obj_set_click(guider_ui.Level_menu_btn_manual_level, true);
		guider_load_screen(SCR_LEVEL_AUTO_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Level_auto_cont_level_auto, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

void events_init_Level_menu(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->Level_menu_btn_manual_level, Level_menu_btn_manual_levelevent_handler);
	lv_obj_set_event_cb(ui->Level_menu_btn_auto_level, Level_menu_btn_auto_levelevent_handler);
}

static void Level_auto_btn_zauto_startevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		//test...
//		static unsigned char percent=0;
//		if(percent < 100)
//            percent = percent + 5;
//        else
//            percent = 0;
//        unsigned char a = percent * 4 / 5;
//        lv_obj_set_size(guider_ui.Level_auto_btn_mask, 300, 90 - a);
//        char myper[5];
//        snprintf(myper, 4, "%u", percent);
//        if(percent<10)
//            myper[1] = '%';
//        else if(percent<100)
//            myper[2] = '%';
//        else
//            myper[3] = '%';
//        lv_label_set_text(guider_ui.Level_auto_label_zauto_progress, myper);
        send_buzzer(0x01);
        set_printer_data(0x0e,2,"21");
	}
		break;
	default:
		break;
	}
}

void events_init_Level_auto(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->Level_auto_btn_zauto_start, Level_auto_btn_zauto_startevent_handler);
}

static void Level_manual_btn_zoffset_unitaevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		lv_btn_set_state(guider_ui.Level_manual_btn_zoffset_unita,LV_BTN_STATE_PRESSED);
		lv_btn_set_state(guider_ui.Level_manual_btn_zoffset_unitb,LV_BTN_STATE_RELEASED);
		lv_obj_set_click(guider_ui.Level_manual_btn_zoffset_unita, false);
		lv_obj_set_click(guider_ui.Level_manual_btn_zoffset_unitb, true);
		zoffset_move_uint = '0';
	}
		break;
	default:
		break;
	}
}

static void Level_manual_btn_zoffset_unitbevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		lv_btn_set_state(guider_ui.Level_manual_btn_zoffset_unita,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.Level_manual_btn_zoffset_unitb,LV_BTN_STATE_PRESSED);
		lv_obj_set_click(guider_ui.Level_manual_btn_zoffset_unita, true);
		lv_obj_set_click(guider_ui.Level_manual_btn_zoffset_unitb, false);
		zoffset_move_uint = '1';
	}
		break;
	default:
		break;
	}
}

static void Level_manual_btn_zoneevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		//number one
	}
		break;
	default:
		break;
	}
}

static void Level_manual_btn_zfourevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		//number four
	}
		break;
	default:
		break;
	}
}

static void Level_manual_btn_zfiveevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		//number five
	}
		break;
	default:
		break;
	}
}

static void Level_manual_btn_zthreeevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		//number three
	}
		break;
	default:
		break;
	}
}

static void Level_manual_btn_ztwoevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		//number two
	}
		break;
	default:
		break;
	}
}

static void Level_manual_img_zoffset_downevent_handler(lv_obj_t * obj, lv_event_t event)
{
    static lv_style_t style_Level_manual_img_zoffset_down_main;

	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
	    send_buzzer(0x01);
        lv_style_reset(&style_Level_manual_img_zoffset_down_main);
        //Write style state: LV_STATE_DEFAULT for style_Level_manual_img_zoffset_down_main
        lv_style_set_image_recolor(&style_Level_manual_img_zoffset_down_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_Level_manual_img_zoffset_down_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_Level_manual_img_zoffset_down_main, LV_STATE_DEFAULT, 255);
        lv_obj_add_style(guider_ui.Level_manual_img_zoffset_down, LV_IMG_PART_MAIN, &style_Level_manual_img_zoffset_down_main);

        float ftemp = 0.00;
        char ctemp[ZOFFSET_LEN+1];
        if(zoffset_value[0] != '\0')
        {
            ftemp = atof(zoffset_value);
        }
        if(zoffset_move_uint == '0')
        {
            ftemp = ftemp - 0.01;
        }
        else
        {
            ftemp = ftemp - 0.1;
        }
        snprintf(ctemp,ZOFFSET_LEN+1,"%.2f",ftemp);
        set_printer_data(0x04,strlen(ctemp),ctemp);
	}
		break;
    case LV_EVENT_PRESSED:
        lv_style_reset(&style_Level_manual_img_zoffset_down_main);
        //Write style state: LV_STATE_DEFAULT for style_Level_manual_img_zoffset_down_main
        lv_style_set_image_recolor(&style_Level_manual_img_zoffset_down_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_Level_manual_img_zoffset_down_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_Level_manual_img_zoffset_down_main, LV_STATE_DEFAULT, 50);
        lv_obj_add_style(guider_ui.Level_manual_img_zoffset_down, LV_IMG_PART_MAIN, &style_Level_manual_img_zoffset_down_main);
        break;
	default:
		break;
	}
}

static void Level_manual_img_zoffset_upevent_handler(lv_obj_t * obj, lv_event_t event)
{
    static lv_style_t style_Level_manual_img_zoffset_up_main;

	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
	    send_buzzer(0x01);
        lv_style_reset(&style_Level_manual_img_zoffset_up_main);
        //Write style state: LV_STATE_DEFAULT for style_Level_manual_img_zoffset_up_main
        lv_style_set_image_recolor(&style_Level_manual_img_zoffset_up_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_Level_manual_img_zoffset_up_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_Level_manual_img_zoffset_up_main, LV_STATE_DEFAULT, 255);
        lv_obj_add_style(guider_ui.Level_manual_img_zoffset_up, LV_IMG_PART_MAIN, &style_Level_manual_img_zoffset_up_main);

        float ftemp = 0.00;
        char ctemp[ZOFFSET_LEN+1];
        if(zoffset_value[0] != '\0')
        {
            ftemp = atof(zoffset_value);
        }
        if(zoffset_move_uint == '0')
        {
            ftemp = ftemp + 0.01;
        }
        else
        {
            ftemp = ftemp + 0.1;
        }
        snprintf(ctemp,ZOFFSET_LEN+1,"%.2f",ftemp);
        set_printer_data(0x04,strlen(ctemp),ctemp);
	}
		break;
    case LV_EVENT_PRESSED:
        lv_style_reset(&style_Level_manual_img_zoffset_up_main);
        //Write style state: LV_STATE_DEFAULT for style_Level_manual_img_zoffset_up_main
        lv_style_set_image_recolor(&style_Level_manual_img_zoffset_up_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_Level_manual_img_zoffset_up_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_Level_manual_img_zoffset_up_main, LV_STATE_DEFAULT, 50);
        lv_obj_add_style(guider_ui.Level_manual_img_zoffset_up, LV_IMG_PART_MAIN, &style_Level_manual_img_zoffset_up_main);
        break;
	default:
		break;
	}
}

static void Level_manual_imgbtn_zoffset_upevent_handler(lv_obj_t * obj, lv_event_t event)
{
    static lv_style_t style_Level_manual_img_zoffset_up_main;

	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
	    send_buzzer(0x01);
        lv_style_reset(&style_Level_manual_img_zoffset_up_main);
        //Write style state: LV_STATE_DEFAULT for style_Level_manual_img_zoffset_up_main
        lv_style_set_image_recolor(&style_Level_manual_img_zoffset_up_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_Level_manual_img_zoffset_up_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_Level_manual_img_zoffset_up_main, LV_STATE_DEFAULT, 255);
        lv_obj_add_style(guider_ui.Level_manual_img_zoffset_up, LV_IMG_PART_MAIN, &style_Level_manual_img_zoffset_up_main);

        float ftemp = 0.00;
        char ctemp[ZOFFSET_LEN+1];
        if(zoffset_value[0] != '\0')
        {
            ftemp = atof(zoffset_value);
        }
        if(zoffset_move_uint == '0')
        {
            ftemp = ftemp + 0.01;
        }
        else
        {
            ftemp = ftemp + 0.1;
        }
        snprintf(ctemp,ZOFFSET_LEN+1,"%.2f",ftemp);
        set_printer_data(0x04,strlen(ctemp),ctemp);
	}
		break;
    case LV_EVENT_PRESSED:
        lv_style_reset(&style_Level_manual_img_zoffset_up_main);
        //Write style state: LV_STATE_DEFAULT for style_Level_manual_img_zoffset_up_main
        lv_style_set_image_recolor(&style_Level_manual_img_zoffset_up_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_Level_manual_img_zoffset_up_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_Level_manual_img_zoffset_up_main, LV_STATE_DEFAULT, 50);
        lv_obj_add_style(guider_ui.Level_manual_img_zoffset_up, LV_IMG_PART_MAIN, &style_Level_manual_img_zoffset_up_main);
        break;
	default:
		break;
	}
}

static void Level_manual_imgbtn_zoffset_downevent_handler(lv_obj_t * obj, lv_event_t event)
{
    static lv_style_t style_Level_manual_img_zoffset_down_main;

	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
	    send_buzzer(0x01);
        lv_style_reset(&style_Level_manual_img_zoffset_down_main);
        //Write style state: LV_STATE_DEFAULT for style_Level_manual_img_zoffset_down_main
        lv_style_set_image_recolor(&style_Level_manual_img_zoffset_down_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_Level_manual_img_zoffset_down_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_Level_manual_img_zoffset_down_main, LV_STATE_DEFAULT, 255);
        lv_obj_add_style(guider_ui.Level_manual_img_zoffset_down, LV_IMG_PART_MAIN, &style_Level_manual_img_zoffset_down_main);

        float ftemp = 0.00;
        char ctemp[ZOFFSET_LEN+1];
        if(zoffset_value[0] != '\0')
        {
            ftemp = atof(zoffset_value);
        }
        if(zoffset_move_uint == '0')
        {
            ftemp = ftemp - 0.01;
        }
        else
        {
            ftemp = ftemp - 0.1;
        }
        snprintf(ctemp,ZOFFSET_LEN+1,"%.2f",ftemp);
        set_printer_data(0x04,strlen(ctemp),ctemp);
	}
		break;
    case LV_EVENT_PRESSED:
        lv_style_reset(&style_Level_manual_img_zoffset_down_main);
        //Write style state: LV_STATE_DEFAULT for style_Level_manual_img_zoffset_down_main
        lv_style_set_image_recolor(&style_Level_manual_img_zoffset_down_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_image_recolor_opa(&style_Level_manual_img_zoffset_down_main, LV_STATE_DEFAULT, 0);
        lv_style_set_image_opa(&style_Level_manual_img_zoffset_down_main, LV_STATE_DEFAULT, 50);
        lv_obj_add_style(guider_ui.Level_manual_img_zoffset_down, LV_IMG_PART_MAIN, &style_Level_manual_img_zoffset_down_main);
        break;
	default:
		break;
	}
}

static void Level_manual_btn_zoffset_homeevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
        case LV_EVENT_RELEASED:
        {
            send_buzzer(0x01);
            float ftemp = 0.00;
            char ctemp[ZOFFSET_LEN+1];
            snprintf(ctemp,ZOFFSET_LEN+1,"%.2f",ftemp);
            set_printer_data(0x04,strlen(ctemp),ctemp);
        }
		break;
	default:
		break;
	}
}

static void Level_manual_imgbtn_zoffset_homeevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
        case LV_EVENT_RELEASED:
        {
            send_buzzer(0x01);
            lv_btn_set_state(guider_ui.Level_manual_btn_zoffset_home,LV_BTN_STATE_RELEASED);
            float ftemp = 0.00;
            char ctemp[ZOFFSET_LEN+1];
            snprintf(ctemp,ZOFFSET_LEN+1,"%.2f",ftemp);
            set_printer_data(0x04,strlen(ctemp),ctemp);
        }
		break;
    case LV_EVENT_PRESSED:
        lv_btn_set_state(guider_ui.Level_manual_btn_zoffset_home,LV_BTN_STATE_PRESSED);
        break;
	default:
		break;
	}
}

static void Level_manual_arc_num1event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
        {
        //number one
        send_buzzer(0x01);
        lv_btn_set_state(guider_ui.Level_manual_btn_zone,LV_BTN_STATE_PRESSED);
        set_printer_data(0x0e,2,"11");
        lv_obj_set_click(guider_ui.Level_manual_img_zoffset_down, true);
        lv_obj_set_click(guider_ui.Level_manual_img_zoffset_up, true);
        lv_obj_set_click(guider_ui.Level_manual_imgbtn_zoffset_up, true);
        lv_obj_set_click(guider_ui.Level_manual_imgbtn_zoffset_down, true);
        lv_obj_set_click(guider_ui.Level_manual_btn_zoffset_home, true);
        lv_obj_set_click(guider_ui.Level_manual_imgbtn_zoffset_home, true);
        }
		break;
    case LV_EVENT_RELEASED:
        lv_btn_set_state(guider_ui.Level_manual_btn_zone,LV_BTN_STATE_RELEASED);
        break;
	default:
		break;
	}
}

static void Level_manual_arc_num2event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
        {
        //number two
        send_buzzer(0x01);
        lv_btn_set_state(guider_ui.Level_manual_btn_ztwo,LV_BTN_STATE_PRESSED);
        set_printer_data(0x0e,2,"12");
        lv_obj_set_click(guider_ui.Level_manual_img_zoffset_down, false);
        lv_obj_set_click(guider_ui.Level_manual_img_zoffset_up, false);
        lv_obj_set_click(guider_ui.Level_manual_imgbtn_zoffset_up, false);
        lv_obj_set_click(guider_ui.Level_manual_imgbtn_zoffset_down, false);
        lv_obj_set_click(guider_ui.Level_manual_btn_zoffset_home, false);
        lv_obj_set_click(guider_ui.Level_manual_imgbtn_zoffset_home, false);
        }
		break;
    case LV_EVENT_RELEASED:
        lv_btn_set_state(guider_ui.Level_manual_btn_ztwo,LV_BTN_STATE_RELEASED);
        break;
	default:
		break;
	}
}

static void Level_manual_arc_num3event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
        {
        //number three
        send_buzzer(0x01);
        lv_btn_set_state(guider_ui.Level_manual_btn_zthree,LV_BTN_STATE_PRESSED);
        set_printer_data(0x0e,2,"13");
        lv_obj_set_click(guider_ui.Level_manual_img_zoffset_down, false);
        lv_obj_set_click(guider_ui.Level_manual_img_zoffset_up, false);
        lv_obj_set_click(guider_ui.Level_manual_imgbtn_zoffset_up, false);
        lv_obj_set_click(guider_ui.Level_manual_imgbtn_zoffset_down, false);
        lv_obj_set_click(guider_ui.Level_manual_btn_zoffset_home, false);
        lv_obj_set_click(guider_ui.Level_manual_imgbtn_zoffset_home, false);
        }
		break;
    case LV_EVENT_RELEASED:
        lv_btn_set_state(guider_ui.Level_manual_btn_zthree,LV_BTN_STATE_RELEASED);
        break;
	default:
		break;
	}
}

static void Level_manual_arc_num4event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
        {
        //number four
        send_buzzer(0x01);
        lv_btn_set_state(guider_ui.Level_manual_btn_zfour,LV_BTN_STATE_PRESSED);
        set_printer_data(0x0e,2,"14");
        lv_obj_set_click(guider_ui.Level_manual_img_zoffset_down, false);
        lv_obj_set_click(guider_ui.Level_manual_img_zoffset_up, false);
        lv_obj_set_click(guider_ui.Level_manual_imgbtn_zoffset_up, false);
        lv_obj_set_click(guider_ui.Level_manual_imgbtn_zoffset_down, false);
        lv_obj_set_click(guider_ui.Level_manual_btn_zoffset_home, false);
        lv_obj_set_click(guider_ui.Level_manual_imgbtn_zoffset_home, false);
        }
		break;
    case LV_EVENT_RELEASED:
        lv_btn_set_state(guider_ui.Level_manual_btn_zfour,LV_BTN_STATE_RELEASED);
        break;
	default:
		break;
	}
}

static void Level_manual_arc_num5event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
        {
        //number five
        send_buzzer(0x01);
        lv_btn_set_state(guider_ui.Level_manual_btn_zfive,LV_BTN_STATE_PRESSED);
        set_printer_data(0x0e,2,"15");
        lv_obj_set_click(guider_ui.Level_manual_img_zoffset_down, false);
        lv_obj_set_click(guider_ui.Level_manual_img_zoffset_up, false);
        lv_obj_set_click(guider_ui.Level_manual_imgbtn_zoffset_up, false);
        lv_obj_set_click(guider_ui.Level_manual_imgbtn_zoffset_down, false);
        lv_obj_set_click(guider_ui.Level_manual_btn_zoffset_home, false);
        lv_obj_set_click(guider_ui.Level_manual_imgbtn_zoffset_home, false);
        }
		break;
    case LV_EVENT_RELEASED:
        lv_btn_set_state(guider_ui.Level_manual_btn_zfive,LV_BTN_STATE_RELEASED);
        break;
	default:
		break;
	}
}

void events_init_Level_manual(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->Level_manual_btn_zone, Level_manual_btn_zoneevent_handler);
	lv_obj_set_event_cb(ui->Level_manual_btn_zoffset_unita, Level_manual_btn_zoffset_unitaevent_handler);
	lv_obj_set_event_cb(ui->Level_manual_btn_zoffset_unitb, Level_manual_btn_zoffset_unitbevent_handler);
	lv_obj_set_event_cb(ui->Level_manual_btn_zfour, Level_manual_btn_zfourevent_handler);
	lv_obj_set_event_cb(ui->Level_manual_btn_zfive, Level_manual_btn_zfiveevent_handler);
	lv_obj_set_event_cb(ui->Level_manual_btn_zthree, Level_manual_btn_zthreeevent_handler);
	lv_obj_set_event_cb(ui->Level_manual_btn_ztwo, Level_manual_btn_ztwoevent_handler);
	lv_obj_set_event_cb(ui->Level_manual_img_zoffset_down, Level_manual_img_zoffset_downevent_handler);
	lv_obj_set_event_cb(ui->Level_manual_img_zoffset_up, Level_manual_img_zoffset_upevent_handler);
	lv_obj_set_event_cb(ui->Level_manual_imgbtn_zoffset_up, Level_manual_imgbtn_zoffset_upevent_handler);
	lv_obj_set_event_cb(ui->Level_manual_imgbtn_zoffset_down, Level_manual_imgbtn_zoffset_downevent_handler);
	lv_obj_set_event_cb(ui->Level_manual_btn_zoffset_home, Level_manual_btn_zoffset_homeevent_handler);
	lv_obj_set_event_cb(ui->Level_manual_imgbtn_zoffset_home, Level_manual_imgbtn_zoffset_homeevent_handler);
	lv_obj_set_event_cb(ui->Level_manual_arc_num1, Level_manual_arc_num1event_handler);
	lv_obj_set_event_cb(ui->Level_manual_arc_num2, Level_manual_arc_num2event_handler);
	lv_obj_set_event_cb(ui->Level_manual_arc_num3, Level_manual_arc_num3event_handler);
	lv_obj_set_event_cb(ui->Level_manual_arc_num4, Level_manual_arc_num4event_handler);
	lv_obj_set_event_cb(ui->Level_manual_arc_num5, Level_manual_arc_num5event_handler);
}

static void Level_title_img_backevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		lv_btn_set_state(guider_ui.setting_menu_btn_about,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.setting_menu_btn_ad_setting,LV_BTN_STATE_RELEASED);
		lv_btn_set_state(guider_ui.setting_menu_btn_device,LV_BTN_STATE_CHECKED_RELEASED);
		lv_obj_set_click(guider_ui.setting_menu_btn_about, true);
		lv_obj_set_click(guider_ui.setting_menu_btn_ad_setting, true);
		lv_obj_set_click(guider_ui.setting_menu_btn_device, false);
		guider_load_screen(SCR_SETTING_DEVICE_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.setting_device_cont_seting_device, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

void events_init_Level_title(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->Level_title_img_back, Level_title_img_backevent_handler);
}

static void MotionSet_btn_RTOSetevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
		guider_load_screen(SCR_RTOSET_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.RTOSet_cont_rto_set, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

static void MotionSet_btn_MaxAccevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
		guider_load_screen(SCR_MAXACCSET_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.MaxAccSet_cont_max_acc_set, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

static void MotionSet_btn_MaxConcorevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		guider_load_screen(SCR_MAXCONCORSET_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.MaxConcorSet_cont_max_concor_set, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

static void MotionSet_btn_MaxSpeedevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		guider_load_screen(SCR_MAXSPEEDSET_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.MaxSpeedSet_cont_max_speed_set, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

void events_init_MotionSet(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->MotionSet_btn_RTOSet, MotionSet_btn_RTOSetevent_handler);
	lv_obj_set_event_cb(ui->MotionSet_btn_MaxAcc, MotionSet_btn_MaxAccevent_handler);
	lv_obj_set_event_cb(ui->MotionSet_btn_MaxConcor, MotionSet_btn_MaxConcorevent_handler);
	lv_obj_set_event_cb(ui->MotionSet_btn_MaxSpeed, MotionSet_btn_MaxSpeedevent_handler);
}

static void RTOSet_btn_xrtoevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
        for(unsigned char i=0;i<MOTION_TEMP_LEN;i++)
        {
            edit_motion[i] = '\0';
        }
		stack_input(SCR_RTOSET_PAGE,0x1,RTO_LEN,&edit_motion[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_rto_x = true;
	}
		break;
	default:
		break;
	}
}

static void RTOSet_btn_yrtoevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
        for(unsigned char i=0;i<MOTION_TEMP_LEN;i++)
        {
            edit_motion[i] = '\0';
        }
		stack_input(SCR_RTOSET_PAGE,0x1,RTO_LEN,&edit_motion[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_rto_y = true;
	}
		break;
	default:
		break;
	}
}

static void RTOSet_btn_zrtoevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
	    for(unsigned char i=0;i<MOTION_TEMP_LEN;i++)
        {
            edit_motion[i] = '\0';
        }
		stack_input(SCR_RTOSET_PAGE,0x1,RTO_LEN,&edit_motion[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_rto_z = true;
	}
		break;
	default:
		break;
	}
}

static void RTOSet_btn_ertoevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
	    for(unsigned char i=0;i<MOTION_TEMP_LEN;i++)
        {
            edit_motion[i] = '\0';
        }
		stack_input(SCR_RTOSET_PAGE,0x1,RTO_LEN,&edit_motion[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_rto_e = true;
	}
		break;
	default:
		break;
	}
}

void events_init_RTOSet(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->RTOSet_btn_xrto, RTOSet_btn_xrtoevent_handler);
	lv_obj_set_event_cb(ui->RTOSet_btn_yrto, RTOSet_btn_yrtoevent_handler);
	lv_obj_set_event_cb(ui->RTOSet_btn_zrto, RTOSet_btn_zrtoevent_handler);
	lv_obj_set_event_cb(ui->RTOSet_btn_erto, RTOSet_btn_ertoevent_handler);
}

static void MaxAccSet_btn_xmaccevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
        for(unsigned char i=0;i<MOTION_TEMP_LEN;i++)
        {
            edit_motion[i] = '\0';
        }
		stack_input(SCR_MAXACCSET_PAGE,0x3,MACC_LEN,&edit_motion[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_macc_x = true;
	}
		break;
	default:
		break;
	}
}

static void MaxAccSet_btn_ymaccevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
        for(unsigned char i=0;i<MOTION_TEMP_LEN;i++)
        {
            edit_motion[i] = '\0';
        }
		stack_input(SCR_MAXACCSET_PAGE,0x3,MACC_LEN,&edit_motion[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_macc_y = true;
	}
		break;
	default:
		break;
	}
}

static void MaxAccSet_btn_zmaccevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
        for(unsigned char i=0;i<MOTION_TEMP_LEN;i++)
        {
            edit_motion[i] = '\0';
        }
		stack_input(SCR_MAXACCSET_PAGE,0x3,MACC_LEN,&edit_motion[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_macc_z = true;
	}
		break;
	default:
		break;
	}
}

static void MaxAccSet_btn_emaccevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
        for(unsigned char i=0;i<MOTION_TEMP_LEN;i++)
        {
            edit_motion[i] = '\0';
        }
		stack_input(SCR_MAXACCSET_PAGE,0x3,MACC_LEN,&edit_motion[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_macc_e = true;
	}
		break;
	default:
		break;
	}
}

void events_init_MaxAccSet(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->MaxAccSet_btn_xmacc, MaxAccSet_btn_xmaccevent_handler);
	lv_obj_set_event_cb(ui->MaxAccSet_btn_ymacc, MaxAccSet_btn_ymaccevent_handler);
	lv_obj_set_event_cb(ui->MaxAccSet_btn_zmacc, MaxAccSet_btn_zmaccevent_handler);
	lv_obj_set_event_cb(ui->MaxAccSet_btn_emacc, MaxAccSet_btn_emaccevent_handler);
}

static void MaxConcorSet_btn_xmconevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
	    for(unsigned char i=0;i<MOTION_TEMP_LEN;i++)
        {
            edit_motion[i] = '\0';
        }
		stack_input(SCR_MAXCONCORSET_PAGE,0x1,MCONCOR_LEN,&edit_motion[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_mcon_x = true;
	}
		break;
	default:
		break;
	}
}

static void MaxConcorSet_btn_ymconevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
	    for(unsigned char i=0;i<MOTION_TEMP_LEN;i++)
        {
            edit_motion[i] = '\0';
        }
		stack_input(SCR_MAXCONCORSET_PAGE,0x1,MCONCOR_LEN,&edit_motion[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_mcon_y = true;
	}
		break;
	default:
		break;
	}
}

static void MaxConcorSet_btn_zmconevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
        for(unsigned char i=0;i<MOTION_TEMP_LEN;i++)
        {
            edit_motion[i] = '\0';
        }
		stack_input(SCR_MAXCONCORSET_PAGE,0x1,MCONCOR_LEN,&edit_motion[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_mcon_z = true;
	}
		break;
	default:
		break;
	}
}

static void MaxConcorSet_btn_emconevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
        for(unsigned char i=0;i<MOTION_TEMP_LEN;i++)
        {
            edit_motion[i] = '\0';
        }
		stack_input(SCR_MAXCONCORSET_PAGE,0x1,MCONCOR_LEN,&edit_motion[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_mcon_e = true;
	}
		break;
	default:
		break;
	}
}

void events_init_MaxConcorSet(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->MaxConcorSet_btn_xmcon, MaxConcorSet_btn_xmconevent_handler);
	lv_obj_set_event_cb(ui->MaxConcorSet_btn_ymcon, MaxConcorSet_btn_ymconevent_handler);
	lv_obj_set_event_cb(ui->MaxConcorSet_btn_zmcon, MaxConcorSet_btn_zmconevent_handler);
	lv_obj_set_event_cb(ui->MaxConcorSet_btn_emcon, MaxConcorSet_btn_emconevent_handler);
}

static void MaxSpeedSet_btn_xmspeedevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
	    for(unsigned char i=0;i<MOTION_TEMP_LEN;i++)
        {
            edit_motion[i] = '\0';
        }
		stack_input(SCR_MAXSPEEDSET_PAGE,0x3,MSPEED_LEN,&edit_motion[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_mspeed_x = true;
	}
		break;
	default:
		break;
	}
}

static void MaxSpeedSet_btn_ymspeedevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
	    for(unsigned char i=0;i<MOTION_TEMP_LEN;i++)
        {
            edit_motion[i] = '\0';
        }
		stack_input(SCR_MAXSPEEDSET_PAGE,0x3,MSPEED_LEN,&edit_motion[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_mspeed_y = true;
	}
		break;
	default:
		break;
	}
}

static void MaxSpeedSet_btn_zmspeedevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
        for(unsigned char i=0;i<MOTION_TEMP_LEN;i++)
        {
            edit_motion[i] = '\0';
        }
		stack_input(SCR_MAXSPEEDSET_PAGE,0x3,MSPEED_LEN,&edit_motion[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_mspeed_z = true;
	}
		break;
	default:
		break;
	}
}

static void MaxSpeedSet_btn_emspeedevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
        for(unsigned char i=0;i<MOTION_TEMP_LEN;i++)
        {
            edit_motion[i] = '\0';
        }
		stack_input(SCR_MAXSPEEDSET_PAGE,0x3,MSPEED_LEN,&edit_motion[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_mspeed_e = true;
	}
		break;
	default:
		break;
	}
}

void events_init_MaxSpeedSet(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->MaxSpeedSet_btn_xmspeed, MaxSpeedSet_btn_xmspeedevent_handler);
	lv_obj_set_event_cb(ui->MaxSpeedSet_btn_ymspeed, MaxSpeedSet_btn_ymspeedevent_handler);
	lv_obj_set_event_cb(ui->MaxSpeedSet_btn_zmspeed, MaxSpeedSet_btn_zmspeedevent_handler);
	lv_obj_set_event_cb(ui->MaxSpeedSet_btn_emspeed, MaxSpeedSet_btn_emspeedevent_handler);
}

static void TempPIDSet_btn_hotend_pid_pevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
	    for(unsigned char i=0;i<PID_LEN;i++)
        {
            edit_pid_temp[i] = '\0';
        }
		stack_input(SCR_TEMPPIDSET_PAGE,0,PID_LEN,&edit_pid_temp[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_pid_hotend_p = true;
	}
		break;
	default:
		break;
	}
}

static void TempPIDSet_btn_bed_pid_pevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
        for(unsigned char i=0;i<PID_LEN;i++)
        {
            edit_pid_temp[i] = '\0';
        }
		stack_input(SCR_TEMPPIDSET_PAGE,0,PID_LEN,&edit_pid_temp[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_pid_bed_p = true;
	}
		break;
	default:
		break;
	}
}

static void TempPIDSet_btn_hotend_pid_ievent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
	    for(unsigned char i=0;i<PID_LEN;i++)
        {
            edit_pid_temp[i] = '\0';
        }
		stack_input(SCR_TEMPPIDSET_PAGE,0,PID_LEN,&edit_pid_temp[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_pid_hotend_i = true;
	}
		break;
	default:
		break;
	}
}

static void TempPIDSet_btn_bed_pid_ievent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
	    for(unsigned char i=0;i<PID_LEN;i++)
        {
            edit_pid_temp[i] = '\0';
        }
		stack_input(SCR_TEMPPIDSET_PAGE,0,PID_LEN,&edit_pid_temp[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_pid_bed_i = true;
	}
		break;
	default:
		break;
	}
}

static void TempPIDSet_btn_hotend_pid_devent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
        for(unsigned char i=0;i<PID_LEN;i++)
        {
            edit_pid_temp[i] = '\0';
        }
		stack_input(SCR_TEMPPIDSET_PAGE,0,PID_LEN,&edit_pid_temp[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_pid_hotend_d = true;
	}
		break;
	default:
		break;
	}
}

static void TempPIDSet_btn_bed_pid_devent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
		  return;
        send_buzzer(0x01);
        for(unsigned char i=0;i<PID_LEN;i++)
        {
            edit_pid_temp[i] = '\0';
        }
		stack_input(SCR_TEMPPIDSET_PAGE,0,PID_LEN,&edit_pid_temp[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_pid_bed_d = true;
	}
		break;
	default:
		break;
	}
}

void events_init_TempPIDSet(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->TempPIDSet_btn_hotend_pid_p, TempPIDSet_btn_hotend_pid_pevent_handler);
	lv_obj_set_event_cb(ui->TempPIDSet_btn_bed_pid_p, TempPIDSet_btn_bed_pid_pevent_handler);
	lv_obj_set_event_cb(ui->TempPIDSet_btn_hotend_pid_i, TempPIDSet_btn_hotend_pid_ievent_handler);
	lv_obj_set_event_cb(ui->TempPIDSet_btn_bed_pid_i, TempPIDSet_btn_bed_pid_ievent_handler);
	lv_obj_set_event_cb(ui->TempPIDSet_btn_hotend_pid_d, TempPIDSet_btn_hotend_pid_devent_handler);
	lv_obj_set_event_cb(ui->TempPIDSet_btn_bed_pid_d, TempPIDSet_btn_bed_pid_devent_handler);
}

static void PrintingSet_btn_hotendevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
	    for(unsigned char i=0;i<EDIT_TEMP_LEN;i++)
        {
            edit_temp[i] = '\0';
        }
		stack_input(SCR_PRINTINGSET_PAGE,0x3,HOTEND_TEMP_LEN,&edit_temp[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_hotend_temp = true;
	}
		break;
	default:
		break;
	}
}

static void PrintingSet_btn_bedevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
	    for(unsigned char i=0;i<EDIT_TEMP_LEN;i++)
        {
            edit_temp[i] = '\0';
        }
		stack_input(SCR_PRINTINGSET_PAGE,0x3,BED_TEMP_LEN,&edit_temp[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_bed_temp = true;
	}
		break;
	default:
		break;
	}
}

static void PrintingSet_btn_speedevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
        for(unsigned char i=0;i<EDIT_TEMP_LEN;i++)
        {
          edit_temp[i] = '\0';
        }
        stack_input(SCR_PRINTINGSET_PAGE,0x3,CUR_SPEED_LEN,&edit_temp[0]);
        guider_load_screen(SCR_INPUTBOXS_PAGE);
        lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
        refresh_print_speed = true;
	}
		break;
	default:
		break;
	}
}

static void PrintingSet_btn_fanevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
        char buf[3] = "0";
        if(fan_state)
        {
            buf[1] = '0';
        }
        else
        {
            buf[1] = '1';
        }
        set_printer_data(0x0b,2,buf);
	}
		break;
	default:
		break;
	}
}

static void PrintingSet_btn_lightevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		char buf[3] = "1";
        if(light_state)
        {
          buf[1] = '0';
        }
        else
        {
          buf[1] = '1';
        }
        set_printer_data(0x0b,2,buf);
	}
		break;
	default:
		break;
	}
}

static void PrintingSet_btn_poweroffevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		set_printer_data(0x0b,2,"71");
	}
		break;
	default:
		break;
	}
}

static void PrintingSet_btn_zoffsetevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		guider_load_screen(SCR_ZOFFSETSET_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.ZoffsetSet_cont_zoffset_set, LV_DEMO_PRINTER_ANIM_DELAY);
	}
		break;
	default:
		break;
	}
}

void events_init_PrintingSet(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->PrintingSet_btn_hotend, PrintingSet_btn_hotendevent_handler);
	lv_obj_set_event_cb(ui->PrintingSet_btn_bed, PrintingSet_btn_bedevent_handler);
	lv_obj_set_event_cb(ui->PrintingSet_btn_speed, PrintingSet_btn_speedevent_handler);
	lv_obj_set_event_cb(ui->PrintingSet_btn_fan, PrintingSet_btn_fanevent_handler);
	lv_obj_set_event_cb(ui->PrintingSet_btn_light, PrintingSet_btn_lightevent_handler);
	lv_obj_set_event_cb(ui->PrintingSet_btn_poweroff, PrintingSet_btn_poweroffevent_handler);
	lv_obj_set_event_cb(ui->PrintingSet_btn_zoffset, PrintingSet_btn_zoffsetevent_handler);
}

static void ZoffsetSet_btn_zoffset_upevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
	    send_buzzer(0x01);
        float ftemp = 0.00;
        char ctemp[ZOFFSET_LEN+1];
        if(zoffset_value[0] != '\0')
        {
            ftemp = atof(zoffset_value);
        }
        ftemp = ftemp + 0.01;
        snprintf(ctemp,ZOFFSET_LEN+1,"%.2f",ftemp);
        set_printer_data(0x04,strlen(ctemp),ctemp);
	}
		break;
	default:
		break;
	}
}

static void ZoffsetSet_img_zoffset_upevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
	    send_buzzer(0x01);
	    lv_btn_set_state(guider_ui.ZoffsetSet_btn_zoffset_up,LV_BTN_STATE_RELEASED);
        float ftemp = 0.00;
        char ctemp[ZOFFSET_LEN+1];
        if(zoffset_value[0] != '\0')
        {
            ftemp = atof(zoffset_value);
        }
        ftemp = ftemp + 0.01;
        snprintf(ctemp,ZOFFSET_LEN+1,"%.2f",ftemp);
        set_printer_data(0x04,strlen(ctemp),ctemp);

	}
		break;
    case LV_EVENT_PRESSED:
        lv_btn_set_state(guider_ui.ZoffsetSet_btn_zoffset_up,LV_BTN_STATE_PRESSED);
        break;
	default:
		break;
	}
}

static void ZoffsetSet_btn_zoffset_downevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
	    send_buzzer(0x01);
        float ftemp = 0.00;
        char ctemp[ZOFFSET_LEN+1];
        if(zoffset_value[0] != '\0')
        {
            ftemp = atof(zoffset_value);
        }
        ftemp = ftemp - 0.01;
        snprintf(ctemp,ZOFFSET_LEN+1,"%.2f",ftemp);
        set_printer_data(0x04,strlen(ctemp),ctemp);
	}
		break;
	default:
		break;
	}
}

static void ZoffsetSet_img_zoffset_downevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_RELEASED:
	{
	    send_buzzer(0x01);
	    lv_btn_set_state(guider_ui.ZoffsetSet_btn_zoffset_down,LV_BTN_STATE_RELEASED);
		float ftemp = 0.00;
        char ctemp[ZOFFSET_LEN+1];
        if(zoffset_value[0] != '\0')
        {
            ftemp = atof(zoffset_value);
        }
        ftemp = ftemp - 0.01;
        snprintf(ctemp,ZOFFSET_LEN+1,"%.2f",ftemp);
        set_printer_data(0x04,strlen(ctemp),ctemp);
	}
		break;
    case LV_EVENT_PRESSED:
        lv_btn_set_state(guider_ui.ZoffsetSet_btn_zoffset_down,LV_BTN_STATE_PRESSED);
        break;
	default:
		break;
	}
}

void events_init_ZoffsetSet(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->ZoffsetSet_btn_zoffset_up, ZoffsetSet_btn_zoffset_upevent_handler);
	lv_obj_set_event_cb(ui->ZoffsetSet_img_zoffset_up, ZoffsetSet_img_zoffset_upevent_handler);
	lv_obj_set_event_cb(ui->ZoffsetSet_btn_zoffset_down, ZoffsetSet_btn_zoffset_downevent_handler);
	lv_obj_set_event_cb(ui->ZoffsetSet_img_zoffset_down, ZoffsetSet_img_zoffset_downevent_handler);
}

static void Preheating_btn_preheat_hotendevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
		stack_input(SCR_PREHEATING_PAGE,0x3,HOTEND_TEMP_LEN,&edit_temp[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_preheat_hotend = true;
	}
		break;
	default:
		break;
	}
}

static void Preheating_btn_preheat_bedevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
		if(check_time())
			return;
        send_buzzer(0x01);
		stack_input(SCR_PREHEATING_PAGE,0x3,BED_TEMP_LEN,&edit_temp[0]);
		guider_load_screen(SCR_INPUTBOXS_PAGE);
		lv_demo_printer_anim_in_all(guider_ui.Inputboxs_cont_inputboxs, LV_DEMO_PRINTER_ANIM_DELAY);
		refresh_preheat_bed = true;
	}
		break;
	default:
		break;
	}
}

void events_init_Preheating(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->Preheating_btn_preheat_hotend, Preheating_btn_preheat_hotendevent_handler);
	lv_obj_set_event_cb(ui->Preheating_btn_preheat_bed, Preheating_btn_preheat_bedevent_handler);
}

static void Inputboxs_btn_backspaceevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		handle_input('b');
	}
		break;
	default:
		break;
	}
}

static void Inputboxs_img_2event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		handle_input('b');
	}
		break;
	default:
		break;
	}
}

static void Inputboxs_btn_confirmevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		handle_input('s');
	}
		break;
	default:
		break;
	}
}

static void Inputboxs_btn_escevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		handle_input('c');
	}
		break;
	default:
		break;
	}
}

static void Inputboxs_btn_num3event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		handle_input('3');
	}
		break;
	default:
		break;
	}
}

static void Inputboxs_btn_num2event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		handle_input('2');
	}
		break;
	default:
		break;
	}
}

static void Inputboxs_btn_num1event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		handle_input('1');
	}
		break;
	default:
		break;
	}
}

static void Inputboxs_btn_num6event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		handle_input('6');
	}
		break;
	default:
		break;
	}
}

static void Inputboxs_btn_num5event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		handle_input('5');
	}
		break;
	default:
		break;
	}
}

static void Inputboxs_btn_num4event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		handle_input('4');
	}
		break;
	default:
		break;
	}
}

static void Inputboxs_btn_num8event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		handle_input('8');
	}
		break;
	default:
		break;
	}
}

static void Inputboxs_btn_num9event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		handle_input('9');
	}
		break;
	default:
		break;
	}
}

static void Inputboxs_btn_num7event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		handle_input('7');
	}
		break;
	default:
		break;
	}
}

static void Inputboxs_btn_dotevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		handle_input('.');
	}
		break;
	default:
		break;
	}
}

static void Inputboxs_btn_num0event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		handle_input('0');
	}
		break;
	default:
		break;
	}
}

static void Inputboxs_btn_negevent_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
		handle_input('-');
	}
		break;
	default:
		break;
	}
}

void events_init_Inputboxs(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->Inputboxs_btn_backspace, Inputboxs_btn_backspaceevent_handler);
	lv_obj_set_event_cb(ui->Inputboxs_img_2, Inputboxs_img_2event_handler);
	lv_obj_set_event_cb(ui->Inputboxs_btn_confirm, Inputboxs_btn_confirmevent_handler);
	lv_obj_set_event_cb(ui->Inputboxs_btn_esc, Inputboxs_btn_escevent_handler);
	lv_obj_set_event_cb(ui->Inputboxs_btn_num3, Inputboxs_btn_num3event_handler);
	lv_obj_set_event_cb(ui->Inputboxs_btn_num2, Inputboxs_btn_num2event_handler);
	lv_obj_set_event_cb(ui->Inputboxs_btn_num1, Inputboxs_btn_num1event_handler);
	lv_obj_set_event_cb(ui->Inputboxs_btn_num6, Inputboxs_btn_num6event_handler);
	lv_obj_set_event_cb(ui->Inputboxs_btn_num5, Inputboxs_btn_num5event_handler);
	lv_obj_set_event_cb(ui->Inputboxs_btn_num4, Inputboxs_btn_num4event_handler);
	lv_obj_set_event_cb(ui->Inputboxs_btn_num8, Inputboxs_btn_num8event_handler);
	lv_obj_set_event_cb(ui->Inputboxs_btn_num9, Inputboxs_btn_num9event_handler);
	lv_obj_set_event_cb(ui->Inputboxs_btn_num7, Inputboxs_btn_num7event_handler);
	lv_obj_set_event_cb(ui->Inputboxs_btn_dot, Inputboxs_btn_dotevent_handler);
	lv_obj_set_event_cb(ui->Inputboxs_btn_num0, Inputboxs_btn_num0event_handler);
	lv_obj_set_event_cb(ui->Inputboxs_btn_neg, Inputboxs_btn_negevent_handler);
}
