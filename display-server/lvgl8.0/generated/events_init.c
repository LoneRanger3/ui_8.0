/*
 * Copyright 2022 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lvgl/lvgl.h"
#include "../custom/custom.h"
#include "../custom/commu_thread.h"
#include "../custom/CrlogDef.h"
#include "../custom/mystyle.h"

void events_init(lv_ui *ui)
{
}

static void homepage_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            keyboardinput("输入范围是0-300",guider_ui.homepage_btn_1_label,300,0,0);
        }
            break;
        default:
            break;
	}
}

static void homepage_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            keyboardinput("输入范围是0-100",guider_ui.homepage_btn_2_label,100,0,1);
        }
            break;
        default:
            break;
	}
}

static void homepage_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            keyboardinput("输入范围是100-999",guider_ui.homepage_btn_3_label,999,100,2);
        }
            break;
        default:
            break;
	}
}

static void homepage_img_7_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(light_state)
            {
                set_printer_data(0x06,2,"10");
            }
            else
            {
                set_printer_data(0x06,2,"11");
            }
        }
            break;
        default:
            break;
	}
}

static void homepage_img_9_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(fan_state)
            {
                set_printer_data(0x06,2,"00");
            }
            else
            {
                set_printer_data(0x06,2,"01");
            }
        }
            break;
        default:
            break;
	}
}

static void homepage_btn_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_FILES_PAGE);
        }
            break;
        default:
            break;
	}
}

static void homepage_img_11_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_HOME_PAGE);
        }
            break;
        default:
            break;
	}
}

static void homepage_img_12_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_MOVE_PAGE);
        }
            break;
        default:
            break;
	}
}

static void homepage_img_13_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_FILES_PAGE);
        }
            break;
        default:
            break;
	}
}

static void homepage_img_14_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_SETINGS_PAGE);
        }
            break;
        default:
            break;
	}
}

static void homepage_img_15_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_FAQ_PAGE);
        }
            break;
        default:
            break;
	}
}

static void homepage_img_17_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(print_state == 3)
            {
                lv_label_set_text(guider_ui.change_printstate_btn_1_label,"暂停");
            }
            if(print_state == 2)
            {
                lv_label_set_text(guider_ui.change_printstate_btn_1_label,"继续");
            }
            lv_obj_clear_flag(guider_ui.change_printstate_cont_1,LV_OBJ_FLAG_HIDDEN);
        }
            break;
        default:
            break;
	}
}

static void homepage_img_16_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_obj_clear_flag(guider_ui.fullscreen_mode_cont_1,LV_OBJ_FLAG_HIDDEN);
        }
            break;
        default:
            break;
	}
}

void events_init_homepage(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->homepage_btn_1, homepage_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->homepage_btn_2, homepage_btn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->homepage_btn_3, homepage_btn_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->homepage_img_7, homepage_img_7_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->homepage_img_9, homepage_img_9_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->homepage_btn_4, homepage_btn_4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->homepage_img_17, homepage_img_17_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->homepage_img_10, homepage_btn_4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->homepage_img_16, homepage_img_16_event_handler, LV_EVENT_ALL, NULL);

	lv_obj_add_event_cb(ui->homepage_img_11, homepage_img_11_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->homepage_img_12, homepage_img_12_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->homepage_img_13, homepage_img_13_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->homepage_img_14, homepage_img_14_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->homepage_img_15, homepage_img_15_event_handler, LV_EVENT_ALL, NULL);
}

static void axismove_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            material_in_length[0] = '1';
            material_in_length[1] = '\t';
            material_out_length[0] = '1';
            material_out_length[1] = '\t';
            movelenthtype = '0';
            lv_obj_add_style(guider_ui.axismove_btn_3,&btnstyle_check_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.axismove_btn_4,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.axismove_btn_5,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
        }
            break;
        default:
            break;
	}
}

static void axismove_btn_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            material_in_length[0] = '1';
            material_in_length[1] = '0';
            material_in_length[2] = '\t';
            material_out_length[0] = '1';
            material_out_length[1] = '0';
            material_out_length[2] = '\t';
            movelenthtype = '1';
            lv_obj_add_style(guider_ui.axismove_btn_3,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.axismove_btn_4,&btnstyle_check_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.axismove_btn_5,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
        }
            break;
        default:
            break;
	}
}

static void axismove_btn_5_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            material_in_length[0] = '5';
            material_in_length[1] = '0';
            material_in_length[2] = '\t';
            material_out_length[0] = '5';
            material_out_length[1] = '0';
            material_out_length[2] = '\t';
            movelenthtype = '2';
            lv_obj_add_style(guider_ui.axismove_btn_3,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.axismove_btn_4,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.axismove_btn_5,&btnstyle_check_default,LV_PART_MAIN|LV_STATE_DEFAULT);
        }
            break;
        default:
            break;
	}
}

static void axismove_btn_6_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if((print_state != 0) && (print_state != 1))
            {
                break;
            }
            if(movelenthtype == '0')
                set_printer_data(0x04,3,"Z10");
            if(movelenthtype == '1')
                set_printer_data(0x04,3,"Z11");
            if(movelenthtype == '2')
                set_printer_data(0x04,3,"Z12");
        }
            break;
        default:
            break;
	}
}

static void axismove_btn_7_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if((print_state != 0) && (print_state != 1))
            {
                break;
            }
            if(movelenthtype == '0')
                set_printer_data(0x04,3,"Z00");
                CrLogI("tt%c",movelenthtype);
            if(movelenthtype == '1')
                set_printer_data(0x04,3,"Z01");
                CrLogI("tt%c",movelenthtype);
            if(movelenthtype == '2')
                set_printer_data(0x04,3,"Z02");
        }
            break;
        default:
            break;
	}
}

static void axismove_btn_8_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if((print_state != 0) && (print_state != 1))
            {
                break;
            }
            if(movelenthtype == '0')
                set_printer_data(0x04,3,"Y10");
            if(movelenthtype == '1')
                set_printer_data(0x04,3,"Y11");
            if(movelenthtype == '2')
                set_printer_data(0x04,3,"Y12");
        }
            break;
        default:
            break;
	}
}

static void axismove_btn_9_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if((print_state != 0) && (print_state != 1))
            {
                break;
            }
            if(movelenthtype == '0')
                set_printer_data(0x04,3,"Y00");
            if(movelenthtype == '1')
                set_printer_data(0x04,3,"Y01");
            if(movelenthtype == '2')
                set_printer_data(0x04,3,"Y02");

        }
            break;
        default:
            break;
	}
}

static void axismove_btn_10_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if((print_state != 0) && (print_state != 1))
            {
                break;
            }
            if(movelenthtype == '0')
                set_printer_data(0x04,3,"X10");
            if(movelenthtype == '1')
                set_printer_data(0x04,3,"X11");
            if(movelenthtype == '2')
                set_printer_data(0x04,3,"X12");
        }
            break;
        default:
            break;
	}
}

static void axismove_btn_11_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if((print_state != 0) && (print_state != 1))
            {
                break;
            }
            if(movelenthtype == '0')
                set_printer_data(0x04,3,"X00");
            if(movelenthtype == '1')
                set_printer_data(0x04,3,"X01");
            if(movelenthtype == '2')
                set_printer_data(0x04,3,"X02");
        }
            break;
        default:
            break;
	}
}

static void axismove_btn_12_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if((print_state != 0) && (print_state != 1))
            {
                break;
            }
            set_printer_data(0x04,3,"E00");
        }
            break;
        default:
            break;
	}
}

static void axismove_btn_13_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if((print_state != 0) && (print_state != 1))
            {
                break;
            }
            int num = atoi(hotend_cur_temp);
            if(num < 180)
            {
                send_buzzer(0x02);
                mymsgbox("喷头温度过低请加热喷头！");
            }
            else
            {
                send_buzzer(0x01);
                char buf[MATERIAL_LEN+2] = "2";
                for(unsigned char i=0;i<MATERIAL_LEN;i++)
                {
                    if(material_out_length[i] == '\t')
                    {
                        buf[i+1] = material_out_length[i];
                        buf[i+2] = extruderspeed;
                        break;
                    }
                    buf[i+1] = material_out_length[i];
                }
                set_printer_data(0x08,strlen(buf),buf);
            }
        }
            break;
        default:
            break;
	}
}

static void axismove_btn_14_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if((print_state != 0) && (print_state != 1))
            {
                break;
            }
            int num = atoi(hotend_cur_temp);
            if(num < 180)
            {
                send_buzzer(0x02);
                mymsgbox("喷头温度过低请加热喷头！");
            }
            else
            {
                send_buzzer(0x01);
                char buf[MATERIAL_LEN+2] = "1";
                CrLogI("%s",material_in_length);
                for(unsigned char i=0;i<MATERIAL_LEN;i++)
                {
                    if(material_in_length[i] == '\t')
                    {
                        buf[i+1] = material_in_length[i];
                        buf[i+2] = extruderspeed;
                        break;
                    }
                    buf[i+1] = material_in_length[i];
                }
                set_printer_data(0x08,strlen(buf),buf);
            }
        }
            break;
        default:
            break;
	}
}

static void axismove_btn_15_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_PRINTADJUST_PAGE);
        }
            break;
        default:
            break;
	}
}

static void axismove_img_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_HOME_PAGE);
        }
            break;
        default:
            break;
	}
}

static void axismove_img_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
//            guider_load_screen(SCR_MOVE_PAGE);
        }
            break;
        default:
            break;
	}
}

static void axismove_img_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_FILES_PAGE);
        }
            break;
        default:
            break;
	}
}

static void axismove_img_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_SETINGS_PAGE);
        }
            break;
        default:
            break;
	}
}

static void axismove_img_5_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_FAQ_PAGE);
        }
            break;
        default:
            break;
	}
}

static void axismove_label_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            keyboardinput("输入范围是0-300",guider_ui.axismove_label_3,300,0,0);
        }
            break;
        default:
            break;
	}
}

static void axismove_label_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            keyboardinput("输入范围是0-100",guider_ui.axismove_label_4,100,0,1);
        }
            break;
        default:
            break;
	}
}

static void axismove_label_5_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            keyboardinput("输入范围是100-999",guider_ui.axismove_label_5,999,100,2);
        }
            break;
        default:
            break;
	}
}

static void axismove_img_15_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(fan_state)
            {
                set_printer_data(0x06,2,"00");
            }
            else
            {
                set_printer_data(0x06,2,"01");
            }
        }
            break;
        default:
            break;
	}
}

void events_init_axismove(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->axismove_btn_3, axismove_btn_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_btn_4, axismove_btn_4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_btn_5, axismove_btn_5_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_btn_6, axismove_btn_6_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_btn_7, axismove_btn_7_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_btn_8, axismove_btn_8_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_btn_9, axismove_btn_9_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_btn_10, axismove_btn_10_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_btn_11, axismove_btn_11_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_btn_12, axismove_btn_12_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_btn_13, axismove_btn_13_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_btn_14, axismove_btn_14_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_btn_15, axismove_btn_15_event_handler, LV_EVENT_ALL, NULL);

    lv_obj_add_event_cb(ui->axismove_img_1, axismove_img_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_img_2, axismove_img_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_img_3, axismove_img_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_img_4, axismove_img_4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_img_5, axismove_img_5_event_handler, LV_EVENT_ALL, NULL);

	lv_obj_add_event_cb(ui->axismove_label_3, axismove_label_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_img_6, axismove_label_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_img_7, axismove_label_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_label_4, axismove_label_4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_img_8, axismove_label_4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_img_10, axismove_label_4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_label_5, axismove_label_5_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_img_13, axismove_label_5_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_img_14, axismove_label_5_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_img_15, axismove_img_15_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->axismove_label_6, axismove_img_15_event_handler, LV_EVENT_ALL, NULL);
}

static void file_information_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if((print_state != 0) && (print_state != 1))
            {
                mymsgbox("正在打印中");
                break;
            }
            if(lv_obj_get_state(guider_ui.file_information_cb_1) & LV_STATE_CHECKED)
            {
                set_printer_data(0x09,2,"21");
            }
            char file_num[10];
            snprintf(file_num, sizeof(file_num), "11\t%d", (current_page * FILE_NUM_PRE_PAGE + clicked_file_num + 1));
            lv_label_set_text(guider_ui.homepage_label_7,dis_file_info[clicked_file_num].name);
            set_printer_data(0x01,strlen(file_num),file_num);
        }

            break;
        default:
            break;
	}
}

static void file_information_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_FILES_PAGE);
        }
            break;
        default:
            break;
	}
}

static void file_information_cb_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {

        }
            break;
        default:
            break;
	}
}

void events_init_file_information(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->file_information_btn_2, file_information_btn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->file_information_btn_1, file_information_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->file_information_cb_1, file_information_cb_1_event_handler, LV_EVENT_ALL, NULL);
}

static void keytone_setting_ddlist_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_VALUE_CHANGED:
        {
            send_buzzer(0x01);
            uint16_t index;
            index = lv_dropdown_get_selected(guider_ui.keytone_setting_ddlist_1);
            CrLogI("keytone_setting_ddlist_1 value is %d\n",index);
            switch(index)
            {
                case 0: set_printer_data(0x06,2,"i1");break;
                case 1: set_printer_data(0x06,2,"i2");break;
                case 2: set_printer_data(0x06,2,"i3");break;
                case 3: set_printer_data(0x06,2,"i4");break;
                default:break;
            }
            break;
        }
        default:
            break;
	}
}

static void keytone_setting_slider_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_VALUE_CHANGED:
        {
            send_buzzer(0x01);
            int volumevalue = 0;
            volumevalue = lv_slider_get_value(guider_ui.keytone_setting_slider_1);
            char temp[5] = {0};
            snprintf(temp,5,"h%d",volumevalue);
            set_printer_data(0x06,strlen(temp),temp);
        }
            break;
        default:
            break;
	}
}

static void keytone_setting_sw_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(lv_obj_has_state(guider_ui.keytone_setting_sw_1,LV_STATE_CHECKED))
            {
                set_printer_data(0x06,2,"a1");
            }
            else
            {
                set_printer_data(0x06,2,"a0");
            }
            break;
        }
        default:
            break;
	}
}

static void keytone_setting_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_SETINGS_PAGE);
            break;
        }
        default:
            break;
	}
}

void events_init_keytone_setting(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->keytone_setting_ddlist_1, keytone_setting_ddlist_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->keytone_setting_slider_1, keytone_setting_slider_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->keytone_setting_sw_1, keytone_setting_sw_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->keytone_setting_btn_1, keytone_setting_btn_1_event_handler, LV_EVENT_ALL, NULL);
}

static void device_binding_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_SETINGS_PAGE);
        }
            break;
        default:
            break;
	}
}

void events_init_device_binding(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->device_binding_btn_1, device_binding_btn_1_event_handler, LV_EVENT_ALL, NULL);
}

static void about_device_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_SETINGS_PAGE);
            break;
        }
        default:
            break;
	}
}

void events_init_about_device(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->about_device_btn_1, about_device_btn_1_event_handler, LV_EVENT_ALL, NULL);
}

static void export_log_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_SETINGS_PAGE);
            break;
        }
        default:
            break;
	}
}

static void export_log_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            set_printer_data(0x1c,2,"1");
            break;
        }
        default:
            break;
	}
}

void events_init_export_log(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->export_log_btn_1, export_log_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->export_log_btn_2, export_log_btn_2_event_handler, LV_EVENT_ALL, NULL);
}

static void resetdevide_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            int state[4] = {0};
            state[3] = lv_obj_get_state(guider_ui.resetdevide_cb_4) & LV_STATE_CHECKED ? 1 : 0;
            state[2] = lv_obj_get_state(guider_ui.resetdevide_cb_3) & LV_STATE_CHECKED ? 1 : 0;
            state[1] = lv_obj_get_state(guider_ui.resetdevide_cb_2) & LV_STATE_CHECKED ? 1 : 0;
            state[0] = lv_obj_get_state(guider_ui.resetdevide_cb_1) & LV_STATE_CHECKED ? 1 : 0;
            CrLogI("%d%d%d%d",state[0],state[1],state[2],state[3]);
            char temp[6]= {0};
            snprintf(temp,6,"6%d%d%d%d",state[0],state[1],state[2],state[3]);
            set_printer_data(0x06,6,temp);
            set_printer_data(0x06,2,"91");
        }
            break;
        default:
            break;
	}
}

static void resetdevide_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_SETINGS_PAGE);
            break;
        }
        default:
            break;
	}
}

void events_init_resetdevide(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->resetdevide_btn_2, resetdevide_btn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->resetdevide_btn_1, resetdevide_btn_1_event_handler, LV_EVENT_ALL, NULL);
}

static void netwowork_information_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_SETINGS_PAGE);
        }
            break;
        default:
            break;
	}
}

void events_init_netwowork_information(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->netwowork_information_btn_1, netwowork_information_btn_1_event_handler, LV_EVENT_ALL, NULL);
}

static void camera_seting_ddlist_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_VALUE_CHANGED:
        {
            send_buzzer(0x01);
            uint16_t index;
            index = lv_dropdown_get_selected(guider_ui.camera_seting_ddlist_1);
            CrLogI("camera_seting_ddlist_1 value is %d\n",index);
            switch(index)
            {
                case 0: set_printer_data(0x1d,3,"415");break;
                case 1: set_printer_data(0x1d,3,"425");break;
                default:break;
            }
            break;
        }
        default:
            break;
	}
}

static void camera_seting_sw_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            if(lv_obj_has_state(guider_ui.camera_seting_sw_1,LV_STATE_CHECKED))
            {
                set_printer_data(0x1d,2,"11");
            }
            else
            {
                set_printer_data(0x1d,2,"10");
            }
            break;
        }
		break;
	default:
		break;
	}
}

static void camera_seting_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_SETINGS_PAGE);
        }
		break;
	default:
		break;
	}
}

static void camera_seting_kb_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t * obj = lv_event_get_target(e);
	switch (code)
	{
		case LV_EVENT_READY:
        case LV_EVENT_CANCEL:
        {
            send_buzzer(0x01);
            char i=0;
            const char *textdata = lv_textarea_get_text(guider_ui.camera_seting_ta_1);
            if(textdata != NULL )
            {
                for(i=0;i<strlen(textdata);i++)
                {
                    if(*(textdata + i) > '9' || *(textdata + i) < '0')
                        return;
                }
            }
            char temp[20];
            snprintf(temp,20,"3%s",textdata);
            set_printer_data(0x1d,strlen(temp),temp);
		    lv_obj_add_flag(guider_ui.camera_seting_kb_1, LV_OBJ_FLAG_HIDDEN);
        }
		break;
	default:
		break;
	}
}

void events_init_camera_seting(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->camera_seting_ddlist_1, camera_seting_ddlist_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->camera_seting_sw_1, camera_seting_sw_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->camera_seting_btn_1, camera_seting_btn_1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->camera_seting_kb_1, camera_seting_kb_1_event_handler, LV_EVENT_ALL, NULL);
}

static void video_information_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {

        }
            break;
        default:
            break;
	}
}

static void video_information_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            break;
        }
        default:
            break;
	}
}

static void video_information_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_VIDEOLIST_PAGE);
        }
            break;
        default:
            break;
	}
}

void events_init_video_information(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->video_information_btn_2, video_information_btn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->video_information_btn_3, video_information_btn_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->video_information_btn_1, video_information_btn_1_event_handler, LV_EVENT_ALL, NULL);
}

static void file_management_img_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_HOME_PAGE);
            break;
        }
        default:
            break;
	}
}

static void file_management_img_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_MOVE_PAGE);
        }
            break;
        default:
            break;
	}
}

static void file_management_img_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {

        }
            break;
        default:
            break;
	}
}

static void file_management_img_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_SETINGS_PAGE);
        }
            break;
        default:
            break;
	}
}

static void file_management_img_5_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_FAQ_PAGE);
        }
            break;
        default:
            break;
	}
}

static void file_management_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            if(print_total_files)
            {
                if((current_page+1) < print_file_pages)
                {
                    if((current_page+1) < print_file_pages)
                    {
                        current_page++;
                        handle_file();
                    }
                }
            }
        }
            break;
        default:
            break;
	}

}

static void file_management_label_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            char dat = lv_event_get_user_data(e);
            clicked_file_num = (int)(dat - '0');
            if(dis_file_info[clicked_file_num].filetype[0] == '0')
            {
                 //文件夹类型发送请求文件命令
                 char buf[12] = {'0'};
                 int len = 0;
                 snprintf(&buf[1],10,"%d",(current_page * FILE_NUM_PRE_PAGE + clicked_file_num + 1));
                 len = strlen(buf);
                 buf[len++]='\t';
                 buf[len] = filesort_type;
//                 get_printer_data(0x01,strlen(buf),buf);
            }
            else
            {
                guider_load_screen(SCR_FILEINFOMATION_PAGE);
            }

        }
            break;
        default:
            break;
	}
}

static void file_management_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            if(current_page > 0)
            {
                if(current_page > 0)
                {
                    current_page--;
                    handle_file();
                }
            }
        }
            break;
        default:
            break;
	}
}

static void file_management_tabview_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            int i = lv_tabview_get_tab_act(guider_ui.file_management_tabview_1);
            if(i == 0)
            {
                CrLogI("load localfile page.");
                char buf[7] = {0};
                snprintf(buf, sizeof(buf), "10\t%c\t0", 'A');
                get_printer_data(0x01,strlen(buf),buf);
            }
            if(i == 1)
            {
                CrLogI("load usbfile page.");
                char buf[7] = {0};
                snprintf(buf, sizeof(buf), "10\t%c\t0", 'B');
                get_printer_data(0x01,strlen(buf),buf);
            }
            if(i == 2)
            {
                CrLogI("load history page.");
                get_printer_data(0x01,2,"20");   //请求历史打印记录列表
            }
            break;
        }
        default:
            break;
	}
}

static void file_management_history_btn_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            char dat = lv_event_get_user_data(e);
            history_clientnum = (int)(dat - '0');
            if((print_state != 0) && (print_state != 1))
            {
                mymsgbox("正在打印中");
                break;
            }
            char file_num[10];
            snprintf(file_num,10, "21\t%d", (history_current_page * HISTORY_NUM_PRE_PAGE + history_clientnum));
            set_printer_data(0x01,strlen(file_num),file_num);
            break;
        }
        default:
            break;
	}
}

static void file_management_history_btn_1_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            if(history_current_page > 0)
            {
                if(history_current_page > 0)
                {
                    history_current_page--;
                    handle_history_file();
                    CrLogI("history page up.");
                }
            }
            break;
        }
        default:
            break;
	}
}

static void file_management_history_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            if(history_total_files)
            {
                if((history_current_page+1) < historyfile_pages)
                {
                    if((history_current_page+1) < historyfile_pages)
                    {
                        history_current_page++;
                        handle_history_file();
                        CrLogI("history page down.");
                    }
                }
            }
        }
            break;
        default:
            break;
	}
}

void events_init_file_management(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->file_management_img_1, file_management_img_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->file_management_img_2, file_management_img_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->file_management_img_3, file_management_img_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->file_management_img_4, file_management_img_4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->file_management_img_5, file_management_img_5_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->file_management_btn_2, file_management_btn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->file_management_img_25, file_management_btn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->file_management_btn_1, file_management_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->file_management_img_24, file_management_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->file_management_tabview_1, file_management_tabview_1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->file_management_label_2, file_management_label_event_handler, LV_EVENT_ALL, '0');
	lv_obj_add_event_cb(ui->file_management_label_6, file_management_label_event_handler, LV_EVENT_ALL, '1');
	lv_obj_add_event_cb(ui->file_management_label_10, file_management_label_event_handler, LV_EVENT_ALL,'2');
	lv_obj_add_event_cb(ui->file_management_label_11, file_management_label_event_handler, LV_EVENT_ALL, '3');
	lv_obj_add_event_cb(ui->file_management_label_12, file_management_label_event_handler, LV_EVENT_ALL, '4');
	lv_obj_add_event_cb(ui->file_management_label_13, file_management_label_event_handler, LV_EVENT_ALL, '5');
	lv_obj_add_event_cb(ui->file_management_sd_btn_2, file_management_btn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->file_management_sd_img_25, file_management_btn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->file_management_sd_btn_1, file_management_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->file_management_sd_img_24, file_management_btn_1_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->file_management_sd_label_2, file_management_label_event_handler, LV_EVENT_ALL, '0');
	lv_obj_add_event_cb(ui->file_management_sd_label_6, file_management_label_event_handler, LV_EVENT_ALL, '1');
	lv_obj_add_event_cb(ui->file_management_sd_label_10, file_management_label_event_handler, LV_EVENT_ALL,'2');
	lv_obj_add_event_cb(ui->file_management_sd_label_11, file_management_label_event_handler, LV_EVENT_ALL, '3');
	lv_obj_add_event_cb(ui->file_management_sd_label_12, file_management_label_event_handler, LV_EVENT_ALL, '4');
	lv_obj_add_event_cb(ui->file_management_sd_label_13, file_management_label_event_handler, LV_EVENT_ALL, '5');
	lv_obj_add_event_cb(ui->file_management_history_btn_3, file_management_history_btn_event_handler, LV_EVENT_ALL, '1');
	lv_obj_add_event_cb(ui->file_management_history_btn_4, file_management_history_btn_event_handler, LV_EVENT_ALL, '2');
	lv_obj_add_event_cb(ui->file_management_history_btn_5, file_management_history_btn_event_handler, LV_EVENT_ALL, '3');
	lv_obj_add_event_cb(ui->file_management_history_btn_6, file_management_history_btn_event_handler, LV_EVENT_ALL, '4');
	lv_obj_add_event_cb(ui->file_management_history_btn_7, file_management_history_btn_event_handler, LV_EVENT_ALL, '5');
	lv_obj_add_event_cb(ui->file_management_history_btn_1, file_management_history_btn_1_event_handler, LV_EVENT_ALL,NULL);
	lv_obj_add_event_cb(ui->file_management_history_img_6, file_management_history_btn_1_event_handler, LV_EVENT_ALL,NULL);
	lv_obj_add_event_cb(ui->file_management_history_btn_2, file_management_history_btn_2_event_handler, LV_EVENT_ALL,NULL);
	lv_obj_add_event_cb(ui->file_management_history_img_7, file_management_history_btn_2_event_handler, LV_EVENT_ALL,NULL);
}

static void video_list_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            if(videolist_current_page > 0)
            {
                videolist_current_page--;
                handle_video_file();
            }
        }
            break;
        default:
            break;
	}
}

static void video_list_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            if(videolist_total_files)
            {
                if((videolist_current_page+1) < videolist_pages)
                {
                    videolist_current_page++;
                    handle_video_file();
                }
            }
        }
            break;
        default:
            break;
	}
}

static void video_list_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_SETINGS_PAGE);
        }
            break;
        default:
            break;
	}
}

static void video_list_img_9_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            char dat = lv_event_get_user_data(e);
            videolist_clientnum = (int)(dat - '0');
            guider_load_screen(SCR_VIDEOINFO_PAGE);
        }
            break;
        default:
            break;
	}
}

void events_init_video_list(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->video_list_btn_1, video_list_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->video_list_btn_2, video_list_btn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->video_list_img_7, video_list_btn_2_event_handler, LV_EVENT_ALL, '0');
	lv_obj_add_event_cb(ui->video_list_btn_3, video_list_btn_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->video_list_img_8, video_list_btn_3_event_handler, LV_EVENT_ALL, '0');
	lv_obj_add_event_cb(ui->video_list_img_9, video_list_img_9_event_handler, LV_EVENT_ALL, '0');
	lv_obj_add_event_cb(ui->video_list_img_10, video_list_img_9_event_handler, LV_EVENT_ALL, '1');
	lv_obj_add_event_cb(ui->video_list_img_11, video_list_img_9_event_handler, LV_EVENT_ALL, '2');
	lv_obj_add_event_cb(ui->video_list_img_12, video_list_img_9_event_handler, LV_EVENT_ALL, '3');
	lv_obj_add_event_cb(ui->video_list_img_13, video_list_img_9_event_handler, LV_EVENT_ALL, '4');
}

static void settings_cb_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            break;
        }
        default:
            break;
	}
}

static void settings_cb_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            break;
        }
        default:
            break;
	}
}

static void settings_cb_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            break;
        }
        default:
            break;
	}
}

static void settings_cb_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            break;

        }
        default:
            break;
	}
}

static void settings_cb_5_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            break;

        }
        default:
            break;
	}
}

static void settings_cb_6_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            break;

        }
        default:
            break;
	}
}

static void settings_cb_7_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            break;

        }
        default:
            break;
	}
}

static void settings_cb_8_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            break;

        }
        default:
            break;
	}
}

static void settings_cb_9_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            break;

        }
        default:
            break;
	}
}

static void settings_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(strcmp(lv_label_get_text(guider_ui.settings_btn_1_label),"全选") == 0)
            {
                lv_obj_add_state(guider_ui.settings_cb_1, LV_STATE_CHECKED);
                lv_obj_add_state(guider_ui.settings_cb_2, LV_STATE_CHECKED);
                lv_obj_add_state(guider_ui.settings_cb_3, LV_STATE_CHECKED);
                lv_obj_add_state(guider_ui.settings_cb_4, LV_STATE_CHECKED);
                lv_obj_add_state(guider_ui.settings_cb_5, LV_STATE_CHECKED);
                lv_obj_add_state(guider_ui.settings_cb_6, LV_STATE_CHECKED);
                lv_obj_add_state(guider_ui.settings_cb_7, LV_STATE_CHECKED);
                lv_obj_add_state(guider_ui.settings_cb_8, LV_STATE_CHECKED);
                lv_obj_add_state(guider_ui.settings_cb_9, LV_STATE_CHECKED);
                lv_label_set_text(guider_ui.settings_btn_1_label,"取消全选");
                break;
            }
            if(strcmp(lv_label_get_text(guider_ui.settings_btn_1_label),"取消全选") == 0)
            {
                lv_obj_clear_state(guider_ui.settings_cb_1, LV_STATE_CHECKED);
                lv_obj_clear_state(guider_ui.settings_cb_2, LV_STATE_CHECKED);
                lv_obj_clear_state(guider_ui.settings_cb_3, LV_STATE_CHECKED);
                lv_obj_clear_state(guider_ui.settings_cb_4, LV_STATE_CHECKED);
                lv_obj_clear_state(guider_ui.settings_cb_5, LV_STATE_CHECKED);
                lv_obj_clear_state(guider_ui.settings_cb_6, LV_STATE_CHECKED);
                lv_obj_clear_state(guider_ui.settings_cb_7, LV_STATE_CHECKED);
                lv_obj_clear_state(guider_ui.settings_cb_8, LV_STATE_CHECKED);
                lv_obj_clear_state(guider_ui.settings_cb_9, LV_STATE_CHECKED);
                lv_label_set_text(guider_ui.settings_btn_1_label,"全选");
                break;
            }
            break;
        }
        default:
            break;
	}
}

static void settings_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            int i = 0;
            if(lv_obj_has_state(guider_ui.settings_cb_1,LV_STATE_CHECKED))  //喉管风扇
                manualtest[i++] = 6;
//            else
//                manualtest[i++] = 0;
            if(lv_obj_has_state(guider_ui.settings_cb_2,LV_STATE_CHECKED))  //模型风扇
                manualtest[i++] = 7;
//            else
//                manualtest[i++] = 0;
            if(lv_obj_has_state(guider_ui.settings_cb_3,LV_STATE_CHECKED))  //喷头PID
                manualtest[i++] = 14;
//            else
//                manualtest[i++] = 0;
            if(lv_obj_has_state(guider_ui.settings_cb_4,LV_STATE_CHECKED))  //热床PID
                manualtest[i++] = 15;
//            else
//                manualtest[i++] = 0;
            if(lv_obj_has_state(guider_ui.settings_cb_5,LV_STATE_CHECKED))  //振动补偿
                manualtest[i++] = 12;
//            else
//                manualtest[i++] = 0;
            if(lv_obj_has_state(guider_ui.settings_cb_6,LV_STATE_CHECKED))  //归位检测
                manualtest[i++] = 8;
//            else
//                manualtest[i++] = 0;
//            if(lv_obj_has_state(guider_ui.settings_cb_7,LV_STATE_CHECKED))  //探头检测
//                manualtest[i++] = 6;
//            else
//                manualtest[i++] = 0;
            if(lv_obj_has_state(guider_ui.settings_cb_8,LV_STATE_CHECKED))  //断料检测
                manualtest[i++] = 9;
//            else
//                manualtest[i++] = 0;
            if(lv_obj_has_state(guider_ui.settings_cb_9,LV_STATE_CHECKED))  //自动调平
            {
                manualtest[i++] = 16;
                manualtest[i++] = 11;
            }
            manualtest[i] = '\0';
            manualtestlength = i;
            //决定跳转页面
            if(manualtestlength > 0)
            {
                manualtest_curpage = 0;
                lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[0],LV_ANIM_OFF);
                guider_load_screen(SCR_SELFTEST_PAGE);
            }
            break;
        }
        default:
            break;
	}
}

static void settings_ddlist_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_VALUE_CHANGED:
        {
            send_buzzer(0x01);
            uint16_t index;
            index = lv_dropdown_get_selected(guider_ui.settings_ddlist_1);
            CrLogI("screen_save_value set %d",index);
            switch(index)
            {
                case 0: set_printer_data(0x06,2,"b3");break;
                case 1: set_printer_data(0x06,2,"b5");break;
                case 2: set_printer_data(0x06,3,"b15");break;
                case 3: set_printer_data(0x06,2,"b0");break;
                default:break;
            }
            break;
        }
        default:
            break;
	}
}

static void settings_ddlist_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            uint16_t index;
            index = lv_dropdown_get_selected(guider_ui.settings_ddlist_2);
            lv_dropdown_close(guider_ui.settings_ddlist_2);
            CrLogI("%d",index);
            lv_obj_clear_flag(guider_ui.select_language_cont_1,LV_OBJ_FLAG_HIDDEN);
            break;
        }
        default:
            break;
	}
}

static void settings_ddlist_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_VALUE_CHANGED:
        {
            send_buzzer(0x01);
            uint16_t index;
            index = lv_dropdown_get_selected(guider_ui.settings_ddlist_3);
            CrLogI("%d",index);
            break;
        }
        default:
            break;
	}
}

static void settings_sw_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_VALUE_CHANGED:
        {
            send_buzzer(0x01);
            if(lv_obj_has_state(guider_ui.settings_sw_1,LV_STATE_CHECKED))
            {
                set_printer_data(0x06,2,"j1");
            }
            else
            {
                set_printer_data(0x06,2,"j0");
            }
            break;
        }
        default:
            break;
	}
}

static void settings_slider_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_VALUE_CHANGED:
        {
            send_buzzer(0x01);
            int lightvalue = 0;
            lightvalue = lv_slider_get_value(guider_ui.settings_slider_1);
            char temp[5] = {0};
            snprintf(temp,5,"e%d",lightvalue);
            set_printer_data(0x06,strlen(temp),temp);
            break;
        }
        default:
            break;
	}
}

static void settings_img_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            CrLogI("11111");
            break;
        }
        default:
            break;
	}
}

static void settings_img_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_KEYTONE_PAGE);
            break;
        }
        default:
            break;
	}
}

static void settings_img_5_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_DEVICE_PAGE);
            break;
        }
        default:
            break;
	}
}

static void settings_img_6_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_EXPORTLOG_PAGE);
            break;
        }
        default:
            break;
	}
}

static void settings_img_7_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_obj_clear_flag(guider_ui.update_version_cont_1, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.update_version_label_11, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.update_version_btn_3, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.update_version_bar_1, LV_OBJ_FLAG_HIDDEN);
            get_printer_data(0x1a,1,"2");

            break;
        }
        default:
            break;
	}
}

static void settings_img_8_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_ABOUTDEVICE_PAGE);
            break;
        }
        default:
            break;
	}
}

static void settings_img_20_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_RESET_PAGE);
            break;
        }
        default:
            break;
	}
}

static void settings_list_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);

            break;
        }
        default:
            break;
	}
}

static void settings_tabview_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_VALUE_CHANGED:
        {
            send_buzzer(0x01);
            int i = lv_tabview_get_tab_act(guider_ui.settings_tabview_1);
            if(i == 0)
            {
                CrLogI("tabel page is setting.");
                get_printer_data(0x06,1,"b");       //屏幕保护状态
                get_printer_data(0x06,1,"c");       //主题模式
                get_printer_data(0x06,1,"e");       //屏幕亮度值
                get_printer_data(0x06,1,"j");       //全屏模式
            }
            if(i == 1)
            {
                CrLogI("tabel page is wifipage.");
                get_printer_data(0x07,1,"1");
                get_printer_data(0x07,1,"2");
                //进入等待状态
                wait_timer = lv_timer_create(waittimer_handler, 10000, NULL);
                lv_obj_clear_flag(guider_ui.wait_cont_1,LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(guider_ui.wait_spinner_1,LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(guider_ui.wait_label_1,LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(guider_ui.wait_label_2,LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(guider_ui.wait_label_3,LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(guider_ui.wait_btn_3,LV_OBJ_FLAG_HIDDEN);
//                lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
                CrLogI("wifi page init,wait wifi refresh....");
//                char te[100];
//                snprintf(te,100,"%s\t%s\t%s","2MW315R:2","CXSW-guest:1","CXSW:0");
//                get_response_printer_data(0x07,30,te);
            }
            break;
        }
        default:
            break;
	}
}

static void settings_img_12_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_VIDEOLIST_PAGE);
            break;
        }
        default:
            break;
	}
}

static void settings_img_13_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_CAMERASETING_PAGE);
            break;
        }
        default:
            break;
	}
}

static void settings_img_15_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_HOME_PAGE);
            break;
        }
        default:
            break;
	}
}

static void settings_img_16_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_MOVE_PAGE);
            break;
        }
        default:
            break;
	}
}

static void settings_img_17_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_FILES_PAGE);
            break;
        }
        default:
            break;
	}
}

static void settings_img_18_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            break;
        }
        default:
            break;
	}
}

static void settings_img_19_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_FAQ_PAGE);
            break;
        }
        default:
            break;
	}
}

void events_init_settings(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->settings_cb_1, settings_cb_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_cb_2, settings_cb_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_cb_3, settings_cb_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_cb_4, settings_cb_4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_cb_5, settings_cb_5_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_cb_6, settings_cb_6_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_cb_7, settings_cb_7_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_cb_8, settings_cb_8_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_cb_9, settings_cb_9_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_btn_1, settings_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_btn_2, settings_btn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_ddlist_1, settings_ddlist_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_ddlist_2, settings_ddlist_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_ddlist_3, settings_ddlist_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_sw_1, settings_sw_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_slider_1, settings_slider_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_img_3, settings_img_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_img_4, settings_img_4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_img_5, settings_img_5_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_img_6, settings_img_6_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_img_7, settings_img_7_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_img_7_btn, settings_img_7_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_img_8, settings_img_8_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_img_20, settings_img_20_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_list_1, settings_list_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_img_12, settings_img_12_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_label_26, settings_img_12_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_img_13, settings_img_13_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_label_27, settings_img_13_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_tabview_1, settings_tabview_1_event_handler, LV_EVENT_ALL, NULL);

	lv_obj_add_event_cb(ui->settings_img_15, settings_img_15_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_img_16, settings_img_16_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_img_17, settings_img_17_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_img_18, settings_img_18_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->settings_img_19, settings_img_19_event_handler, LV_EVENT_ALL, NULL);
}

static void inputboard_wifi_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_obj_add_flag(guider_ui.inputboard_wifi_cont_1, LV_OBJ_FLAG_HIDDEN);
        }
            break;
        default:
            break;
	}
}

static void wifi_seting_pwd_hidden_img_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{
	    send_buzzer(0x01);
	    if(lv_textarea_get_password_mode(guider_ui.wifi_seting_ta))
        {
            lv_textarea_set_password_mode(guider_ui.wifi_seting_ta,false);
            lv_img_set_src(guider_ui.wifi_seting_pwd_hidden_img, &_pwm_img1_40x40);
        }
        else
        {
            lv_textarea_set_password_mode(guider_ui.wifi_seting_ta,true);
            lv_img_set_src(guider_ui.wifi_seting_pwd_hidden_img, &_pwm_img2_40x40);
        }
	}
		break;
	default:
		break;
	}
}

static void wifi_seting_kb_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t * obj = lv_event_get_target(e);
	switch (code)
	{
        case LV_EVENT_VALUE_CHANGED:
        {
            send_buzzer(0x01);
            uint32_t id = lv_btnmatrix_get_selected_btn(obj);
            lv_keyboard_mode_t mode = lv_keyboard_get_mode(obj);
            if(((mode < 2) && (id == 39)) || ((mode == 2) && (id == 38)))
            {
                char ctemp[WIFI_NAME_LEN+4+63] = "0\t";
                unsigned char i,j;
                for(i=0;i<strlen(exchange_wifi_name);i++)
                {
                    ctemp[i+2] = exchange_wifi_name[i];
                }
                ctemp[i+2] = '\t';
                j = i + 3;
                const char *passw = lv_textarea_get_text(guider_ui.wifi_seting_ta);
                if(passw != NULL)
                {
                    for(i=0;i<strlen(passw);i++)
                    {
                        ctemp[j++] = *(passw + i);
                    }
                    ctemp[j] = '\0';
                    set_printer_data(0x07,strlen(ctemp),ctemp);
                    connectwifi_state = true;
                    //进入等待状态
                    wait_timer = lv_timer_create(waittimer_handler, 10000, NULL);
                    lv_obj_clear_flag(guider_ui.wait_cont_1,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(guider_ui.wait_spinner_1,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.wait_label_1,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.wait_label_2,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.wait_label_3,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.wait_btn_3,LV_OBJ_FLAG_HIDDEN);
    //                lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
                    CrLogI("connect new wifi,wait wifi refresh....");
                }
                lv_obj_add_flag(guider_ui.inputboard_wifi_cont_1, LV_OBJ_FLAG_HIDDEN);
            }
        }
		break;
	default:
		break;
	}
}

void events_init_inputboard_wifi(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->inputboard_wifi_btn_1, inputboard_wifi_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->wifi_seting_pwd_hidden_img, wifi_seting_pwd_hidden_img_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->wifi_seting_kb, wifi_seting_kb_event_handler, LV_EVENT_ALL, NULL);

}

static void select_language_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            refreshflag_settingpage = true;
            cur_language = 0;
            lv_obj_add_flag(guider_ui.select_language_cont_1,LV_OBJ_FLAG_HIDDEN);
        }
            break;
        default:
            break;
	}
}

static void select_language_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            refreshflag_settingpage = true;
            cur_language = 1;
            lv_obj_add_flag(guider_ui.select_language_cont_1,LV_OBJ_FLAG_HIDDEN);

        }
            break;
        default:
            break;
	}
}

void events_init_select_language(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->select_language_btn_1, select_language_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->select_language_btn_2, select_language_btn_2_event_handler, LV_EVENT_ALL, NULL);
}

static void FAQ_img_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_HOME_PAGE);
        }
            break;
        default:
            break;
	}
}

static void FAQ_img_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_MOVE_PAGE);
        }
            break;
        default:
            break;
	}
}

static void FAQ_img_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_FILES_PAGE);
        }
            break;
        default:
            break;
	}
}

static void FAQ_img_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_SETINGS_PAGE);
        }
            break;
        default:
            break;
	}
}

static void FAQ_img_5_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_FAQ_PAGE);
        }
            break;
        default:
            break;
	}
}

void events_init_FAQ(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->FAQ_img_1, FAQ_img_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->FAQ_img_2, FAQ_img_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->FAQ_img_3, FAQ_img_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->FAQ_img_4, FAQ_img_4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->FAQ_img_5, FAQ_img_5_event_handler, LV_EVENT_ALL, NULL);
}
//继续或暂停
static void change_printstate_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            CrLogI("printdate change %d.",print_state);
            if(material_seneor == '4' && print_state != 0 && print_state != 1)
            {
                lv_label_set_text(guider_ui.printmessage_label_3,"已检测到耗材使用完，请检查并更换耗材后点击按钮重新开始打印.");
                lv_obj_clear_flag(guider_ui.printmessage_cont_1,LV_OBJ_FLAG_HIDDEN);
                break;
            }
            if(print_state == 2)
                set_printer_data(0x0f,1,"3");
            if(print_state == 3)
                set_printer_data(0x0f,1,"2");
            lv_obj_add_flag(guider_ui.change_printstate_cont_1,LV_OBJ_FLAG_HIDDEN);
        }
            break;
        default:
            break;
	}
}
//停止
static void change_printstate_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            set_printer_data(0x0f,1,"1");
            lv_obj_add_flag(guider_ui.change_printstate_cont_1,LV_OBJ_FLAG_HIDDEN);
        }
            break;
        default:
            break;
	}
}
//返回
static void change_printstate_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_obj_add_flag(guider_ui.change_printstate_cont_1,LV_OBJ_FLAG_HIDDEN);
        }
            break;
        default:
            break;
	}
}

void events_init_change_printstate(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->change_printstate_btn_1, change_printstate_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->change_printstate_btn_2, change_printstate_btn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->change_printstate_btn_3, change_printstate_btn_3_event_handler, LV_EVENT_ALL, NULL);
}

static void update_version_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_obj_add_flag(guider_ui.update_version_cont_1,LV_OBJ_FLAG_HIDDEN);
        }
            break;
        default:
            break;
	}
}

static void update_version_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            const char * text = lv_label_get_text(guider_ui.update_version_btn_2_label);
            if(strcmp(text, "升级") == 0)
            {
                set_printer_data(0x1a,1,"2");
//                lv_obj_add_flag(guider_ui.update_version_cont_1,LV_OBJ_FLAG_HIDDEN);
            }
            if(strcmp(text, "确定") == 0)
            {
                lv_obj_add_flag(guider_ui.update_version_cont_1,LV_OBJ_FLAG_HIDDEN);
            }
        }
            break;
        default:
            break;
	}
}

static void update_version_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
        }
            break;
        default:
            break;
	}
}

void events_init_update_version(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->update_version_btn_1, update_version_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->update_version_btn_2, update_version_btn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->update_version_btn_3, update_version_btn_3_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui->update_version_cont_1, update_version_btn_1_event_handler, LV_EVENT_ALL, NULL);
}

static void printing_adjust_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_MOVE_PAGE);
        }
            break;
        default:
            break;
	}
}

static void printing_adjust_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_CLICKED:
	{

	}
		break;
	default:
		break;
	}
}

static void printing_adjust_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_obj_add_style(guider_ui.printing_adjust_btn_3,&btnstyle_check_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.printing_adjust_btn_4,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            zoffsetmovelen = '0';
        }
            break;
        default:
            break;
	}
}

static void printing_adjust_btn_5_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            speedchangetype = '0';
            speedflowchangetype = '0';
            lv_obj_add_style(guider_ui.printing_adjust_btn_5,&btnstyle_check_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.printing_adjust_btn_6,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.printing_adjust_btn_7,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.printing_adjust_btn_8,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
        }
            break;
        default:
            break;
	}
}

static void printing_adjust_btn_6_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            speedchangetype = '1';
            speedflowchangetype = '1';
            lv_obj_add_style(guider_ui.printing_adjust_btn_5,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.printing_adjust_btn_6,&btnstyle_check_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.printing_adjust_btn_7,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.printing_adjust_btn_8,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
        }
            break;
        default:
            break;
	}
}

static void printing_adjust_btn_7_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            speedchangetype = '2';
            speedflowchangetype = '2';
            lv_obj_add_style(guider_ui.printing_adjust_btn_5,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.printing_adjust_btn_6,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.printing_adjust_btn_7,&btnstyle_check_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.printing_adjust_btn_8,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
        }
            break;
        default:
            break;
	}
}

static void printing_adjust_btn_8_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            speedchangetype = '3';
            speedflowchangetype = '3';
            lv_obj_add_style(guider_ui.printing_adjust_btn_5,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.printing_adjust_btn_6,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.printing_adjust_btn_7,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.printing_adjust_btn_8,&btnstyle_check_default,LV_PART_MAIN|LV_STATE_DEFAULT);
        }
            break;
        default:
            break;
	}
}

static void printing_adjust_btn_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            lv_obj_add_style(guider_ui.printing_adjust_btn_4,&btnstyle_check_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            lv_obj_add_style(guider_ui.printing_adjust_btn_3,&btnstyle_uncheck_default,LV_PART_MAIN|LV_STATE_DEFAULT);
            zoffsetmovelen = '1';
        }
            break;
        default:
            break;
	}
}

static void printing_adjust_img_6_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            float temp = atof(zoffset_value);
            if(zoffsetmovelen == '0')
            {
                temp -= 0.01;
            }
            if(zoffsetmovelen == '1')
            {
                temp -= 0.05;
            }
            char tempchar[OFFSET_LEN+3] = {'\0'};
            snprintf(tempchar,OFFSET_LEN+3,"%.2f",temp);
            set_printer_data(0x02,strlen(tempchar),tempchar);
            break;
        }
        default:
            break;
	}
}

static void printing_adjust_img_7_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            float temp = atof(zoffset_value);
            if(zoffsetmovelen == '0')
            {
                temp += 0.01;
            }
            if(zoffsetmovelen == '1')
            {
                temp += 0.05;
            }
            char tempchar[OFFSET_LEN+3] = {'\0'};
            snprintf(tempchar,OFFSET_LEN+3,"%.2f",temp);
            set_printer_data(0x02,strlen(tempchar),tempchar);
            break;
        }
        default:
            break;
	}
}

static void printing_adjust_img_8_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            int temp = atoi(cur_speed);
            if(speedchangetype == '0')
            {
                temp -= 1;
            }
            if(speedchangetype == '1')
            {
                temp -= 5;
            }
            if(speedchangetype == '2')
            {
                temp -= 10;
            }
            if(speedchangetype == '3')
            {
                temp -= 25;
            }
            char tempchar[CUR_SPEED_LEN+2] = {'\0'};
            snprintf(tempchar,CUR_SPEED_LEN+2,"%d",temp);
            set_printer_data(0x10,strlen(tempchar),tempchar);
            break;
        }
        default:
            break;
	}
}

static void printing_adjust_img_9_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            int temp = atoi(cur_speed);
            if(speedchangetype == '0')
            {
                temp += 1;
            }
            if(speedchangetype == '1')
            {
                temp += 5;
            }
            if(speedchangetype == '2')
            {
                temp += 10;
            }
            if(speedchangetype == '3')
            {
                temp += 25;
            }
            char tempchar[CUR_SPEED_LEN+2] = {'\0'};
            snprintf(tempchar,CUR_SPEED_LEN+2,"%d",temp);
            set_printer_data(0x10,strlen(tempchar),tempchar);
            break;
        }
        default:
            break;
	}
}

static void printing_adjust_img_10_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            int temp = atoi(cur_printflow);
            if(speedflowchangetype == '0')
            {
                temp -= 1;
            }
            if(speedflowchangetype == '1')
            {
                temp -= 5;
            }
            if(speedflowchangetype == '2')
            {
                temp -= 10;
            }
            if(speedflowchangetype == '3')
            {
                temp -= 25;
            }
            char tempchar[CUR_SPEED_LEN+2] = {'\0'};
            snprintf(tempchar,CUR_SPEED_LEN+2,"%d",temp);
            set_printer_data(0x16,strlen(tempchar),tempchar);
            break;
        }
        default:
            break;
	}
}

static void printing_adjust_img_11_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            int temp = atoi(cur_printflow);
            if(speedflowchangetype == '0')
            {
                temp += 1;
            }
            if(speedflowchangetype == '1')
            {
                temp += 5;
            }
            if(speedflowchangetype == '2')
            {
                temp += 10;
            }
            if(speedflowchangetype == '3')
            {
                temp += 25;
            }
            char tempchar[CUR_SPEED_LEN+2] = {'\0'};
            snprintf(tempchar,CUR_SPEED_LEN+2,"%d",temp);
            set_printer_data(0x16,strlen(tempchar),tempchar);
            break;
        }
	default:
		break;
	}
}

static void printing_adjust_img_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_HOME_PAGE);
        }
            break;
        default:
            break;
	}
}

static void printing_adjust_img_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
//            guider_load_screen(SCR_MOVE_PAGE);
        }
            break;
        default:
            break;
	}
}

static void printing_adjust_img_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_FILES_PAGE);
        }
            break;
        default:
            break;
	}
}

static void printing_adjust_img_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_SETINGS_PAGE);
        }
            break;
        default:
            break;
	}
}

static void printing_adjust_img_5_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_FAQ_PAGE);
        }
            break;
        default:
            break;
	}
}

void events_init_printing_adjust(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->printing_adjust_btn_1, printing_adjust_btn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->printing_adjust_btn_2, printing_adjust_btn_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->printing_adjust_btn_3, printing_adjust_btn_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->printing_adjust_btn_5, printing_adjust_btn_5_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->printing_adjust_btn_6, printing_adjust_btn_6_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->printing_adjust_btn_7, printing_adjust_btn_7_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->printing_adjust_btn_8, printing_adjust_btn_8_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->printing_adjust_btn_4, printing_adjust_btn_4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->printing_adjust_img_6, printing_adjust_img_6_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->printing_adjust_img_7, printing_adjust_img_7_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->printing_adjust_img_8, printing_adjust_img_8_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->printing_adjust_img_9, printing_adjust_img_9_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->printing_adjust_img_10, printing_adjust_img_10_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->printing_adjust_img_11, printing_adjust_img_11_event_handler, LV_EVENT_ALL, NULL);

	lv_obj_add_event_cb(ui->printing_adjust_img_1, printing_adjust_img_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->printing_adjust_img_2, printing_adjust_img_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->printing_adjust_img_3, printing_adjust_img_3_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->printing_adjust_img_4, printing_adjust_img_4_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->printing_adjust_img_5, printing_adjust_img_5_event_handler, LV_EVENT_ALL, NULL);

}

static void selftest_bar_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_VALUE_CHANGED:
        {
//            if(lv_bar_get_value(guider_ui.selftest_bar_1) == 100)
//            {
//                lv_tabview_set_act(guider_ui.selftest_tabview_1,1,LV_ANIM_ON);
//            }
        }
            break;
        default:
            break;
	}
}
void send_data(lv_timer_t * timer)
{
    uint32_t * user_data = timer->user_data;
    CrLogI("enter the timer,userdate is %d",*user_data);
    if(*user_data == 0)
        set_printer_data(0x03,4,"260"); //设置喷头温度以检测喉管风扇
    if(*user_data == 1)
        set_printer_data(0x06,2,"01");  //开启模型风扇
    if(*user_data == 2)
    {
        set_printer_data(0x04,3,"E00"); //轴归位
        lv_label_set_text(guider_ui.messagebox_label_3,"正在归零中，请观察设备xyz轴是否回归到原点。");
        lv_obj_clear_flag(guider_ui.messagebox_cont_1,LV_OBJ_FLAG_HIDDEN);
    }
    if(*user_data == 3)                 //超时未检测
    {
        lv_label_set_text(guider_ui.messagebox_label_3,"长时间未检测到耗材，请检查传感器");
        lv_label_set_text(guider_ui.messagebox_btn_2_label,"确定");
        lv_obj_add_flag(guider_ui.messagebox_btn_1,LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(guider_ui.messagebox_cont_1,LV_OBJ_FLAG_HIDDEN);
    }
}

static void obj_bar_anim_exec_callback(void * bar, int32_t value)
{
    if (bar != NULL)
    {
        lv_bar_set_value((lv_obj_t *)bar, value, LV_ANIM_ON); // 设置进度条对象的值
        if(value == 100)
        {
            lv_tabview_set_act(guider_ui.selftest_tabview_1,1,LV_ANIM_ON);
            lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
        }
    }
}

static void selftest_tabview_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_VALUE_CHANGED:
        {
            int i = lv_tabview_get_tab_act(guider_ui.selftest_tabview_1);
            switch(i)
            {
                case 0: //开机动画
                {
                    CrLogI("selftest tab 0.");
                    lv_anim_t anim;
                    lv_anim_init(&anim); // 初始化动画
                    lv_anim_set_exec_cb(&anim, obj_bar_anim_exec_callback); // 添加回调函数
                    lv_anim_set_time(&anim, 5000); // 设置动画时长
                    lv_anim_set_var(&anim, guider_ui.selftest_bar_1); // 动画绑定对象
                    lv_anim_set_values(&anim, 0, 100); // 设置开始值和结束值
                    lv_anim_set_repeat_count(&anim, 1); // 重复次数，默认值为1 LV_ANIM_REPEAT_INFINIT用于无限重复
                    lv_anim_start(&anim); // 应用动画效果
                    lv_obj_clear_flag(guider_ui.selftest_img_2,LV_OBJ_FLAG_HIDDEN);
                    break;
                }
                case 1: //语言选择
                {
                    CrLogI("selftest tab 1.");
                    lv_obj_clear_flag(guider_ui.selftest_img_2,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_3,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_4,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_5,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_6,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_7,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_8,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_9,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_10,LV_OBJ_FLAG_HIDDEN);
                    break;
                }
                case 2: //选择时区
                {
                    CrLogI("selftest tab 2.");
                    break;
                }
                case 3: //隐私协议
                {
                    CrLogI("selftest tab 3.");
                    break;
                }
                case 4: //网络设置
                {
                    CrLogI("selftest tab 4.");
                    get_printer_data(0x07,1,"1");
                    get_printer_data(0x07,1,"2");
                    //进入等待状态
                    wait_timer = lv_timer_create(waittimer_handler, 10000, NULL);
                    lv_obj_clear_flag(guider_ui.wait_cont_1,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(guider_ui.wait_spinner_1,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.wait_label_1,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.wait_label_2,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.wait_label_3,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.wait_btn_3,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
                    CrLogI("selftestpage,wait wifi refresh....");
                    break;
                }
                case 5: //开始自检提示
                {
                    CrLogI("selftest tab 5.");
                    break;
                }
                case 6: //喉管散热风扇
                {
                    CrLogI("selftest tab 6.");
                    timer_user_data = 0;
                    selftest_result[0] = 3;
                    mytimer = lv_timer_create(send_data,5000,&timer_user_data);
                    lv_timer_set_repeat_count(mytimer,1);
                    break;
                }
                case 7: //模型散热风扇
                {
                    CrLogI("selftest tab 7.");
                    timer_user_data = 1;
                    mytimer_1 = lv_timer_create(send_data,5000,&timer_user_data);
                    lv_timer_set_repeat_count(mytimer_1,1);
                    break;
                }
                case 8: //轴移动
                {
                    CrLogI("selftest tab 8.");
                    timer_user_data = 2;
                    mytimer_2 = lv_timer_create(send_data,5000,&timer_user_data);
                    lv_timer_set_repeat_count(mytimer_2,1);
                    break;
                }
                case 9: //断料检测
                {
                    CrLogI("selftest tab 9.");
                    get_printer_data(0x06,1,"7");
                    usleep(1000*100);       //等待传感器状态刷新
                    lv_label_set_text(guider_ui.selftest_btn_21_label,"开始校准");
                    selftest_flag = false;
                    if(material_seneor == 1)    //有耗材
                    {
                        lv_label_set_text(guider_ui.selftest_label_71,"已检测到耗材，开始校准后请拔出耗材");
                    }
                    if(material_seneor == 2)    //无耗材
                    {
                        lv_label_set_text(guider_ui.selftest_label_71,"未检测到耗材，开始校准后请插入耗材");
                    }
                    break;
                }
                case 10://手动调平
                {
                    CrLogI("selftest tab 10.");
                    manuallevel_count = 0;
                    lv_obj_add_flag(guider_ui.selftest_btn_23,LV_OBJ_FLAG_HIDDEN);
                    break;
                }
                case 11://自动调平
                {
                    CrLogI("selftest tab 11.");
                    set_printer_data(0x09,2,"42");
                    autolevelingflag = 0;
                    break;
                }
                case 12://振纹优化
                {
                    CrLogI("selftest tab 12.");
                    get_printer_data(0x17,0,"");
                    lv_obj_add_flag(guider_ui.selftest_btn_53,LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_add_flag(guider_ui.selftest_btn_54,LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_add_flag(guider_ui.selftest_btn_55,LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_clear_flag(guider_ui.selftest_btn_53,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(guider_ui.selftest_btn_54,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(guider_ui.selftest_btn_55,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(guider_ui.selftest_label_97,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(guider_ui.selftest_label_98,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(guider_ui.selftest_label_99,LV_OBJ_FLAG_HIDDEN);

                    lv_label_set_text(guider_ui.selftest_btn_55_label,"开始校准");
                    lv_label_set_text(guider_ui.selftest_label_97,"传感器状态正常!");
                    lv_label_set_text(guider_ui.selftest_label_98,"1.振动补偿可以更好使打印机发挥性能;");
                    lv_label_set_text(guider_ui.selftest_label_99,"2.整个过程预计需要5分钟。");
                    break;
                }
                case 13://自检结果
                {
                    CrLogI("selftest tab 13.");
                    //根据自检结果刷新图片
                    for(int i=0;i < 7;i++)
                    {
                        switch(selftest_result[i])
                        {
                            case 0:
                            {
                                if(i==0) lv_img_set_src(guider_ui.selftest_img_21,&_teststate2_26x26);
                                if(i==1) lv_img_set_src(guider_ui.selftest_img_22,&_teststate2_26x26);
                                if(i==2) lv_img_set_src(guider_ui.selftest_img_23,&_teststate2_26x26);
                                if(i==3) lv_img_set_src(guider_ui.selftest_img_24,&_teststate2_26x26);
                                if(i==4) lv_img_set_src(guider_ui.selftest_img_25,&_teststate2_26x26);
                                if(i==5) lv_img_set_src(guider_ui.selftest_img_26,&_teststate2_26x26);
                                if(i==6) lv_img_set_src(guider_ui.selftest_img_27,&_teststate2_26x26);
                                break;
                            }
                            case 1:
                            {
                                if(i==0) lv_img_set_src(guider_ui.selftest_img_21,&_teststate1_26x26);
                                if(i==1) lv_img_set_src(guider_ui.selftest_img_22,&_teststate1_26x26);
                                if(i==2) lv_img_set_src(guider_ui.selftest_img_23,&_teststate1_26x26);
                                if(i==3) lv_img_set_src(guider_ui.selftest_img_24,&_teststate1_26x26);
                                if(i==4) lv_img_set_src(guider_ui.selftest_img_25,&_teststate1_26x26);
                                if(i==5) lv_img_set_src(guider_ui.selftest_img_26,&_teststate1_26x26);
                                if(i==6) lv_img_set_src(guider_ui.selftest_img_27,&_teststate1_26x26);
                                break;
                            }
                            case 2:
                            {
                                if(i==0) lv_img_set_src(guider_ui.selftest_img_21,&_teststate3_26x26);
                                if(i==1) lv_img_set_src(guider_ui.selftest_img_22,&_teststate3_26x26);
                                if(i==2) lv_img_set_src(guider_ui.selftest_img_23,&_teststate3_26x26);
                                if(i==3) lv_img_set_src(guider_ui.selftest_img_24,&_teststate3_26x26);
                                if(i==4) lv_img_set_src(guider_ui.selftest_img_25,&_teststate3_26x26);
                                if(i==5) lv_img_set_src(guider_ui.selftest_img_26,&_teststate3_26x26);
                                if(i==6) lv_img_set_src(guider_ui.selftest_img_27,&_teststate3_26x26);
                                break;
                            }
                            default:
                                break;
                        }
                    }
                    break;
                }
                case 14://喷头PID
                {
                    CrLogI("selftest tab 14.");
                    get_printer_data(0x0d,1,"0");
                    lv_obj_add_flag(guider_ui.selftest_label_118,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_label_119,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_30,LV_OBJ_FLAG_HIDDEN);

                    lv_obj_clear_flag(guider_ui.selftest_label_113,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(guider_ui.selftest_img_29,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_btn_59,LV_OBJ_FLAG_CLICKABLE);
                    lv_img_set_src(guider_ui.selftest_img_28,&_hotend_big_62x72);
                    lv_label_set_text(guider_ui.selftest_btn_59_label,"开始校准");
                    break;
                }
                case 15://热床PID
                {
                    CrLogI("selftest tab 15.");
                    get_printer_data(0x0d,1,"1");
                    lv_obj_add_flag(guider_ui.selftest_label_126,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_label_127,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_33,LV_OBJ_FLAG_HIDDEN);

                    lv_obj_clear_flag(guider_ui.selftest_label_124,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(guider_ui.selftest_img_32,LV_OBJ_FLAG_HIDDEN);
                    lv_img_set_src(guider_ui.selftest_img_31,&_bedtemp_78x76);
                    lv_obj_add_flag(guider_ui.selftest_btn_62,LV_OBJ_FLAG_CLICKABLE);
                    lv_obj_clear_flag(guider_ui.selftest_btn_62,LV_OBJ_FLAG_HIDDEN);
                    lv_label_set_text(guider_ui.selftest_btn_62_label,"开始校准");
                    break;
                }
                case 16://选择调平
                {
                    CrLogI("selftest tab 16.");
                    //默认5x5
                    lv_img_set_src(guider_ui.selftest_img_34,&_level_3_black_136x136);
                    lv_img_set_src(guider_ui.selftest_img_35,&_level_4_black_136x136);
                    lv_img_set_src(guider_ui.selftest_img_36,&_level_5_blue_136x136);
                    set_printer_data(0x09,2,"42");
                    break;
                }
                case 17://探头测试
                {
                    CrLogI("selftest tab 17.");
                    break;
                }
            }
        }
            break;
        default:
            break;
	}
}

static void selftest_label_12_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
    char dat = lv_event_get_user_data(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            switch(dat)
            {
                case '0':
                {
                    lv_obj_add_style(guider_ui.selftest_label_3, &labelstyle_check_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_4, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_5, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_6, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_7, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_8, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_9, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_10,&labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_11,&labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);

                    lv_obj_clear_flag(guider_ui.selftest_img_2,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_3,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_4,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_5,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_6,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_7,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_8,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_9,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_10,LV_OBJ_FLAG_HIDDEN);
                    break;
                }
                case '1':
                {
                    lv_obj_add_style(guider_ui.selftest_label_3, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_4, &labelstyle_check_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_5, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_6, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_7, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_8, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_9, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_10,&labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_11,&labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);

                    lv_obj_add_flag(guider_ui.selftest_img_2,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(guider_ui.selftest_img_3,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_4,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_5,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_6,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_7,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_8,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_9,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_10,LV_OBJ_FLAG_HIDDEN);
                    break;
                }
                case '2':
                {
                    lv_obj_add_style(guider_ui.selftest_label_3, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_4, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_5, &labelstyle_check_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_6, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_7, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_8, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_9, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_10,&labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_11,&labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);

                    lv_obj_add_flag(guider_ui.selftest_img_2,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_3,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(guider_ui.selftest_img_4,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_5,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_6,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_7,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_8,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_9,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_10,LV_OBJ_FLAG_HIDDEN);
                    break;
                }
                case '3':
                {
                    lv_obj_add_style(guider_ui.selftest_label_3, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_4, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_5, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_6, &labelstyle_check_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_7, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_8, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_9, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_10,&labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_11,&labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);

                    lv_obj_add_flag(guider_ui.selftest_img_2,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_3,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_4,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(guider_ui.selftest_img_5,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_6,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_7,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_8,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_9,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_10,LV_OBJ_FLAG_HIDDEN);
                    break;
                }
                case '4':
                {
                    lv_obj_add_style(guider_ui.selftest_label_3, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_4, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_5, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_6, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_7, &labelstyle_check_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_8, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_9, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_10,&labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_11,&labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);

                    lv_obj_add_flag(guider_ui.selftest_img_2,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_3,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_4,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_5,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(guider_ui.selftest_img_6,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_7,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_8,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_9,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_10,LV_OBJ_FLAG_HIDDEN);
                    break;
                }
                case '5':
                {
                    lv_obj_add_style(guider_ui.selftest_label_3, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_4, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_5, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_6, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_7, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_8, &labelstyle_check_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_9, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_10,&labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_11,&labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);

                    lv_obj_add_flag(guider_ui.selftest_img_2,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_3,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_4,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_5,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_6,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(guider_ui.selftest_img_7,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_8,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_9,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_10,LV_OBJ_FLAG_HIDDEN);
                    break;
                }
                case '6':
                {
                    lv_obj_add_style(guider_ui.selftest_label_3, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_4, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_5, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_6, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_7, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_8, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_9, &labelstyle_check_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_10,&labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_11,&labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);

                    lv_obj_add_flag(guider_ui.selftest_img_2,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_3,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_4,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_5,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_6,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_7,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(guider_ui.selftest_img_8,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_9,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_10,LV_OBJ_FLAG_HIDDEN);
                    break;
                }
                case '7':
                {
                    lv_obj_add_style(guider_ui.selftest_label_3, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_4, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_5, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_6, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_7, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_8, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_9, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_10,&labelstyle_check_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_11,&labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);

                    lv_obj_add_flag(guider_ui.selftest_img_2,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_3,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_4,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_5,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_6,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_7,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_8,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(guider_ui.selftest_img_9,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_10,LV_OBJ_FLAG_HIDDEN);
                    break;
                }
                case '8':
                {
                    lv_obj_add_style(guider_ui.selftest_label_3, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_4, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_5, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_6, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_7, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_8, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_9, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_10, &labelstyle_uncheck_default, LV_PART_MAIN|LV_STATE_DEFAULT);
                    lv_obj_add_style(guider_ui.selftest_label_11, &labelstyle_check_default, LV_PART_MAIN|LV_STATE_DEFAULT);

                    lv_obj_add_flag(guider_ui.selftest_img_2,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_3,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_4,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_5,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_6,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_7,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_8,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(guider_ui.selftest_img_9,LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(guider_ui.selftest_img_10,LV_OBJ_FLAG_HIDDEN);
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

static void selftest_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_tabview_set_act(guider_ui.selftest_tabview_1,2,LV_ANIM_ON);
            lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_tabview_set_act(guider_ui.selftest_tabview_1,1,LV_ANIM_ON);
            lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_tabview_set_act(guider_ui.selftest_tabview_1,3,LV_ANIM_OFF);
            lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_4_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_tabview_set_act(guider_ui.selftest_tabview_1,2,LV_ANIM_OFF);
            lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_5_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(lv_obj_has_state(guider_ui.selftest_cb_1,LV_STATE_CHECKED))
            {
                CrLogI("User Consent Agreement!");
                lv_tabview_set_act(guider_ui.selftest_tabview_1,4,LV_ANIM_ON);
                lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_6_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_tabview_set_act(guider_ui.selftest_tabview_1,5,LV_ANIM_ON);
            lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_7_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_tabview_set_act(guider_ui.selftest_tabview_1,3,LV_ANIM_ON);
            lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_8_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_tabview_set_act(guider_ui.selftest_tabview_1,5,LV_ANIM_ON);
            lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_9_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_tabview_set_act(guider_ui.selftest_tabview_1,13,LV_ANIM_ON);
            lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_10_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_tabview_set_act(guider_ui.selftest_tabview_1,4,LV_ANIM_ON);
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_11_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_tabview_set_act(guider_ui.selftest_tabview_1,6,LV_ANIM_ON);
            lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_12_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(manualtestlength == 0)
            {
                lv_tabview_set_act(guider_ui.selftest_tabview_1,7,LV_ANIM_ON);
                lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                if(mytimer != NULL)
                    lv_timer_set_repeat_count(mytimer,0);   //如果定时器未触发则取消
                set_printer_data(0x03,3,"20");
            }
            else
            {
                if(manualtest_curpage+1 < manualtestlength)
                {
                    if(mytimer != NULL)
                        lv_timer_set_repeat_count(mytimer,0);   //如果定时器未触发则取消
                    set_printer_data(0x03,3,"20");
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
                else
                {
                    manualtest_curpage = 0;
                    manualtestlength = 0;
                    guider_load_screen(SCR_SETINGS_PAGE);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_13_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(manualtestlength == 0)
            {
                lv_tabview_set_act(guider_ui.selftest_tabview_1,5,LV_ANIM_ON);
                lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                if(mytimer != NULL)
                    lv_timer_set_repeat_count(mytimer,0);   //如果定时器未触发则取消
                set_printer_data(0x03,3,"20");
            }
            else
            {
                if(manualtest_curpage-1 >= 0)
                {
                    if(mytimer != NULL)
                        lv_timer_set_repeat_count(mytimer,0);   //如果定时器未触发则取消
                    set_printer_data(0x03,3,"20");
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[--manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_14_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(mytimer_1 != NULL)
                lv_timer_set_repeat_count(mytimer_1,0);   //如果定时器未触发则取消
            if(manualtestlength == 0)
            {
                lv_tabview_set_act(guider_ui.selftest_tabview_1,8,LV_ANIM_ON);
                lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            }
            else
            {
                if(manualtest_curpage+1 < manualtestlength)
                {

                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
                else
                {
                    manualtest_curpage = 0;
                    manualtestlength = 0;
                    guider_load_screen(SCR_SETINGS_PAGE);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_15_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(mytimer_1 != NULL)
                lv_timer_set_repeat_count(mytimer_1,0);   //如果定时器未触发则取消
            if(manualtestlength == 0)
            {
                lv_tabview_set_act(guider_ui.selftest_tabview_1,6,LV_ANIM_ON);
                lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            }
            else
            {
                if(manualtest_curpage-1 >= 0)
                {
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[--manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_16_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(mytimer_2 != NULL)
                lv_timer_set_repeat_count(mytimer_2,0);   //如果定时器未触发则取消
            if(manualtestlength == 0)
            {
                lv_tabview_set_act(guider_ui.selftest_tabview_1,9,LV_ANIM_ON);
                lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            }
            else
            {
                if(manualtest_curpage+1 < manualtestlength)
                {

                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
                else
                {
                    manualtest_curpage = 0;
                    manualtestlength = 0;
                    guider_load_screen(SCR_SETINGS_PAGE);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_17_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(mytimer_2 != NULL)
                lv_timer_set_repeat_count(mytimer_2,0);   //如果定时器未触发则取消
            if(manualtestlength == 0)
            {
                lv_tabview_set_act(guider_ui.selftest_tabview_1,7,LV_ANIM_ON);
                lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            }
            else
            {
                if(manualtest_curpage-1 >= 0)
                {
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[--manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_18_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(mytimer_2 != NULL)
                lv_timer_set_repeat_count(mytimer_2,0);   //如果定时器未触发则取消
            if(manualtestlength == 0)
            {
                lv_tabview_set_act(guider_ui.selftest_tabview_1,9,LV_ANIM_ON);
                lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            }
            else
            {
                if(manualtest_curpage+1 < manualtestlength)
                {

                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
                else
                {
                    manualtest_curpage = 0;
                    manualtestlength = 0;
                    guider_load_screen(SCR_SETINGS_PAGE);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_19_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(mytimer_3 != NULL)
                lv_timer_set_repeat_count(mytimer_3,0);
            if(manualtestlength == 0)
            {
                selftest_result[3] = 0;
                lv_tabview_set_act(guider_ui.selftest_tabview_1,10,LV_ANIM_ON);
                lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            }
            else
            {
                if(manualtest_curpage+1 < manualtestlength)
                {
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
                else
                {
                    manualtest_curpage = 0;
                    manualtestlength = 0;
                    guider_load_screen(SCR_SETINGS_PAGE);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_20_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(mytimer_3 != NULL)
                lv_timer_set_repeat_count(mytimer_3,0);
            if(manualtestlength == 0)
            {
                lv_tabview_set_act(guider_ui.selftest_tabview_1,8,LV_ANIM_ON);
                lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            }
            else
            {
                if(manualtest_curpage-1 >= 0)
                {
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[--manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_21_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(strcmp(lv_label_get_text(guider_ui.selftest_btn_21_label),"开始校准")== 0)
            {
                timer_user_data = 3;
                selftest_flag = true;
                lv_timer_t * mytimer_3;
                mytimer_3 = lv_timer_create(send_data,10000,&timer_user_data);  //长时间无检测报错弹窗
                lv_timer_set_repeat_count(mytimer_3,1);
                lv_obj_clear_flag(guider_ui.selftest_btn_21,LV_OBJ_FLAG_CLICKABLE);
                lv_label_set_text(guider_ui.selftest_btn_21_label,"下一步");
                break;
            }
            if(strcmp(lv_label_get_text(guider_ui.selftest_btn_21_label),"下一步")== 0)
            {
                if(mytimer_3 != NULL)
                    lv_timer_set_repeat_count(mytimer_3,0);
                if(manualtestlength == 0)
                {
                    if(selftest_flag)
                        selftest_result[3] = 2;
                    else
                        selftest_result[3] = 1;
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,10,LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
                else
                {
                    if(manualtest_curpage+1 < manualtestlength)
                    {
                        lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                        lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                    }
                    else
                    {
                        manualtest_curpage = 0;
                        manualtestlength = 0;
                        guider_load_screen(SCR_SETINGS_PAGE);
                    }
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_22_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(manualtestlength == 0)
            {
                lv_tabview_set_act(guider_ui.selftest_tabview_1,9,LV_ANIM_ON);
                lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            }
            else
            {
                if(manualtest_curpage-1 >= 0)
                {
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[--manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_23_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(manualtestlength == 0)
            {
                selftest_result[4] = 1;
                lv_tabview_set_act(guider_ui.selftest_tabview_1,11,LV_ANIM_ON);
                lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            }
            else
            {
                if(manualtest_curpage+1 < manualtestlength)
                {
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
                else
                {
                    manualtest_curpage = 0;
                    manualtestlength = 0;
                    guider_load_screen(SCR_SETINGS_PAGE);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_72_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            set_printer_data(0x09,2,"11");
            manuallevel_count |= 0x01;
            CrLogI("manuallevel_count is %x",manuallevel_count);
            if(manuallevel_count == 0x0f)
            {
                lv_obj_clear_flag(guider_ui.selftest_btn_23,LV_OBJ_FLAG_HIDDEN);
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_73_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            set_printer_data(0x09,2,"12");
            manuallevel_count |= 0x02;
            CrLogI("manuallevel_count is %x",manuallevel_count);
            if(manuallevel_count == 0x0f)
            {
                lv_obj_clear_flag(guider_ui.selftest_btn_23,LV_OBJ_FLAG_HIDDEN);
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_74_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            set_printer_data(0x09,2,"13");
            manuallevel_count |= 0x04;
            CrLogI("manuallevel_count is %x",manuallevel_count);
            if(manuallevel_count == 0x0f)
            {
                lv_obj_clear_flag(guider_ui.selftest_btn_23,LV_OBJ_FLAG_HIDDEN);
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_75_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            set_printer_data(0x09,2,"14");
            manuallevel_count |= 0x08;
            CrLogI("manuallevel_count is %x",manuallevel_count);
            if(manuallevel_count == 0x0f)
            {
                lv_obj_clear_flag(guider_ui.selftest_btn_23,LV_OBJ_FLAG_HIDDEN);
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_24_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(manualtestlength == 0)
            {
                selftest_result[5] = 2;
                lv_tabview_set_act(guider_ui.selftest_tabview_1,12,LV_ANIM_ON);
                lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            }
            else
            {
                if(manualtest_curpage+1 < manualtestlength)
                {
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
                else
                {
                    manualtest_curpage = 0;
                    manualtestlength = 0;
                    guider_load_screen(SCR_SETINGS_PAGE);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_50_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            autolevelingflag = 1;
            lv_obj_add_flag(guider_ui.selftest_btn_24,LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.selftest_btn_50,LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.selftest_btn_51,LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.selftest_btn_52,LV_OBJ_FLAG_HIDDEN);
            set_printer_data(0x09,2,"21");
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_51_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(manualtestlength == 0)
            {
                lv_tabview_set_act(guider_ui.selftest_tabview_1,10,LV_ANIM_ON);
                lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            }
            else
            {
                if(manualtest_curpage-1 >= 0)
                {
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[--manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_52_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(manualtestlength == 0)
            {
                selftest_result[5] = 1;
                lv_tabview_set_act(guider_ui.selftest_tabview_1,12,LV_ANIM_ON);
                lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            }
            else
            {
                if(manualtest_curpage+1 < manualtestlength)
                {
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
                else
                {
                    manualtest_curpage = 0;
                    manualtestlength = 0;
                    guider_load_screen(SCR_SETINGS_PAGE);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_53_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(manualtestlength == 0)
            {
                selftest_result[6] = 0;
                lv_tabview_set_act(guider_ui.selftest_tabview_1,13,LV_ANIM_ON);
                lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            }
            else
            {
                if(manualtest_curpage+1 < manualtestlength)
                {
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
                else
                {
                    manualtest_curpage = 0;
                    manualtestlength = 0;
                    guider_load_screen(SCR_SETINGS_PAGE);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_54_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(manualtestlength == 0)
            {
                lv_tabview_set_act(guider_ui.selftest_tabview_1,11,LV_ANIM_ON);
                lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            }
            else
            {
                if(manualtest_curpage-1 >= 0)
                {
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[--manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_55_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(strcmp(lv_label_get_text(guider_ui.selftest_btn_55_label),"开始校准")== 0)
            {
                if(!x_state || !y_state || !z_state)
                {
                    mymsgbox("请先进行归零操作！");
                    break;
                }
                set_printer_data(0x1b,1,"3");
                lv_obj_add_flag(guider_ui.selftest_label_99, LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(guider_ui.selftest_btn_55, LV_OBJ_FLAG_CLICKABLE);

                lv_label_set_text(guider_ui.selftest_btn_55_label,"下一步");
                break;
            }
            if(strcmp(lv_label_get_text(guider_ui.selftest_btn_55_label),"下一步")== 0)
            {
                if(manualtestlength == 0)
                {
                    selftest_result[6] = 1;
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,13,LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
                else
                {
                    if(manualtest_curpage+1 < manualtestlength)
                    {
                        lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                        lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                    }
                    else
                    {
                        manualtest_curpage = 0;
                        manualtestlength = 0;
                        guider_load_screen(SCR_SETINGS_PAGE);
                    }
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_56_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_tabview_set_act(guider_ui.selftest_tabview_1,12,LV_ANIM_ON);
            lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_57_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            guider_load_screen(SCR_HOME_PAGE);
            set_printer_data(0x06,2,"90");
            break;
        }
        default:
            break;
	}
}

static void selftest_img_29_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            keyboardinput("输入范围是0-300",guider_ui.selftest_label_113,300,0,3);
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_58_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
           if(manualtestlength == 0)
           {

           }
           else
           {
               if(manualtest_curpage-1 > 0)
               {
                   lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[--manualtest_curpage],LV_ANIM_ON);
                   lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
               }
           }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_59_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(strcmp(lv_label_get_text(guider_ui.selftest_btn_59_label),"开始校准")== 0)
            {
                set_printer_data(0x0d,1,"5");
                lv_label_set_text(guider_ui.selftest_btn_59_label,"下一步");

                lv_obj_clear_flag(guider_ui.selftest_label_118,LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(guider_ui.selftest_label_119,LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(guider_ui.selftest_img_30,LV_OBJ_FLAG_HIDDEN);

                lv_obj_add_flag(guider_ui.selftest_img_29,LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(guider_ui.selftest_label_113,LV_OBJ_FLAG_HIDDEN);
                lv_img_set_src(guider_ui.selftest_img_28,&_hotend_big_orange_62x72);
                lv_obj_clear_flag(guider_ui.selftest_btn_59, LV_OBJ_FLAG_CLICKABLE);
                break;
            }
            if(strcmp(lv_label_get_text(guider_ui.selftest_btn_59_label),"下一步")== 0)
            {
                if(manualtestlength == 0)
                {

                }
                else
                {
                    if(manualtest_curpage+1 < manualtestlength)
                    {
                        lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                        lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                    }
                    else
                    {
                        manualtest_curpage = 0;
                        manualtestlength = 0;
                        guider_load_screen(SCR_SETINGS_PAGE);
                    }
                }
            }
        }
        default:
            break;
	}
}

static void selftest_img_32_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            keyboardinput("输入范围是0-110",guider_ui.selftest_label_124,110,0,4);
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_60_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(manualtestlength == 0)
            {

            }
            else
            {
                if(manualtest_curpage+1 < manualtestlength)
                {
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
                else
                {
                    manualtest_curpage = 0;
                    manualtestlength = 0;
                    guider_load_screen(SCR_SETINGS_PAGE);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_61_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(manualtestlength == 0)
            {

            }
            else
            {
                if(manualtest_curpage-1 > 0)
                {
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[--manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_62_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(strcmp(lv_label_get_text(guider_ui.selftest_btn_62_label),"开始校准")== 0)
            {
                set_printer_data(0x0d,1,"7");
                lv_label_set_text(guider_ui.selftest_btn_62_label,"下一步");

                lv_obj_clear_flag(guider_ui.selftest_label_126,LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(guider_ui.selftest_label_127,LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(guider_ui.selftest_img_33,LV_OBJ_FLAG_HIDDEN);

                lv_obj_add_flag(guider_ui.selftest_img_32,LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(guider_ui.selftest_label_124,LV_OBJ_FLAG_HIDDEN);
                lv_img_set_src(guider_ui.selftest_img_31,&_bedtemp_orange_78x76);
                lv_obj_clear_flag(guider_ui.selftest_btn_62, LV_OBJ_FLAG_CLICKABLE);
                break;
            }
            if(strcmp(lv_label_get_text(guider_ui.selftest_btn_62_label),"下一步")== 0)
            {
                if(manualtestlength == 0)
                {

                }
                else
                {
                    if(manualtest_curpage+1 < manualtestlength)
                    {
                        lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                        lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                    }
                    else
                    {
                        manualtest_curpage = 0;
                        manualtestlength = 0;
                        guider_load_screen(SCR_SETINGS_PAGE);
                    }
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_img_34_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            char dat = lv_event_get_user_data(e);
            switch(dat)
            {
                case '1':
                {
                    CrLogI("levelvalue is 1.\n");
                    lv_img_set_src(guider_ui.selftest_img_34,&_level_3_blue_136x136);
                    lv_img_set_src(guider_ui.selftest_img_35,&_level_4_black_136x136);
                    lv_img_set_src(guider_ui.selftest_img_36,&_level_5_black_136x136);
                    set_printer_data(0x09,2,"40");
                    break;
                }
                case '2':
                {
                    CrLogI("levelvalue is 2.\n");
                    lv_img_set_src(guider_ui.selftest_img_34,&_level_3_black_136x136);
                    lv_img_set_src(guider_ui.selftest_img_35,&_level_4_blue_136x136);
                    lv_img_set_src(guider_ui.selftest_img_36,&_level_5_black_136x136);
                    set_printer_data(0x09,2,"41");
                    break;

                }
                case '3':
                {
                    CrLogI("levelvalue is 3.\n");
                    lv_img_set_src(guider_ui.selftest_img_34,&_level_3_black_136x136);
                    lv_img_set_src(guider_ui.selftest_img_35,&_level_4_black_136x136);
                    lv_img_set_src(guider_ui.selftest_img_36,&_level_5_blue_136x136);
                    set_printer_data(0x09,2,"42");
                    break;
                }
                default:break;
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_64_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(manualtestlength == 0)
            {

            }
            else
            {
                if(manualtest_curpage-1 > 0)
                {
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[--manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
            }
            break;
        }
        default:
            break;
	}
}

static void selftest_btn_65_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            if(manualtestlength == 0)
            {

            }
            else
            {
                if(manualtest_curpage+1 < manualtestlength)
                {
                    lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                    lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                }
                else
                {
                    manualtest_curpage = 0;
                    manualtestlength = 0;
                    guider_load_screen(SCR_SETINGS_PAGE);
                }
            }
            break;
        }
        default:
            break;
	}
}

void events_init_selftest(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->selftest_bar_1, selftest_bar_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->selftest_tabview_1, selftest_tabview_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->selftest_label_3, selftest_label_12_event_handler, LV_EVENT_ALL, '0');
	lv_obj_add_event_cb(ui->selftest_label_4, selftest_label_12_event_handler, LV_EVENT_ALL, '1');
	lv_obj_add_event_cb(ui->selftest_label_5, selftest_label_12_event_handler, LV_EVENT_ALL, '2');
	lv_obj_add_event_cb(ui->selftest_label_6, selftest_label_12_event_handler, LV_EVENT_ALL, '3');
	lv_obj_add_event_cb(ui->selftest_label_7, selftest_label_12_event_handler, LV_EVENT_ALL, '4');
	lv_obj_add_event_cb(ui->selftest_label_8, selftest_label_12_event_handler, LV_EVENT_ALL, '5');
	lv_obj_add_event_cb(ui->selftest_label_9, selftest_label_12_event_handler, LV_EVENT_ALL, '6');
	lv_obj_add_event_cb(ui->selftest_label_10,selftest_label_12_event_handler, LV_EVENT_ALL, '7');
	lv_obj_add_event_cb(ui->selftest_label_11,selftest_label_12_event_handler, LV_EVENT_ALL, '8');
	lv_obj_add_event_cb(ui->selftest_label_12, selftest_label_12_event_handler, LV_EVENT_ALL, '0');
	lv_obj_add_event_cb(ui->selftest_label_13, selftest_label_12_event_handler, LV_EVENT_ALL, '1');
	lv_obj_add_event_cb(ui->selftest_label_14, selftest_label_12_event_handler, LV_EVENT_ALL, '2');
	lv_obj_add_event_cb(ui->selftest_label_15, selftest_label_12_event_handler, LV_EVENT_ALL, '3');
	lv_obj_add_event_cb(ui->selftest_label_16, selftest_label_12_event_handler, LV_EVENT_ALL, '4');
	lv_obj_add_event_cb(ui->selftest_label_17, selftest_label_12_event_handler, LV_EVENT_ALL, '5');
	lv_obj_add_event_cb(ui->selftest_label_18, selftest_label_12_event_handler, LV_EVENT_ALL, '6');
	lv_obj_add_event_cb(ui->selftest_label_19,selftest_label_12_event_handler, LV_EVENT_ALL, '7');
	lv_obj_add_event_cb(ui->selftest_label_20,selftest_label_12_event_handler, LV_EVENT_ALL, '8');
    lv_obj_add_event_cb(ui->selftest_btn_1,selftest_btn_1_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_2,selftest_btn_2_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_3,selftest_btn_3_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_4,selftest_btn_4_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_5,selftest_btn_5_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_6,selftest_btn_6_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_7,selftest_btn_7_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_8,selftest_btn_8_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_9,selftest_btn_9_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_10,selftest_btn_10_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_11,selftest_btn_11_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_12,selftest_btn_12_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_13,selftest_btn_13_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_14,selftest_btn_14_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_15,selftest_btn_15_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_16,selftest_btn_16_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_17,selftest_btn_17_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_18,selftest_btn_18_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_19,selftest_btn_19_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_20,selftest_btn_20_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_21,selftest_btn_21_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_22,selftest_btn_22_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_23,selftest_btn_23_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_72,selftest_btn_72_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_73,selftest_btn_73_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_74,selftest_btn_74_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_75,selftest_btn_75_event_handler, LV_EVENT_ALL,NULL);

    lv_obj_add_event_cb(ui->selftest_btn_24,selftest_btn_24_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_50,selftest_btn_50_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_51,selftest_btn_51_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_52,selftest_btn_52_event_handler, LV_EVENT_ALL,NULL);
    //振纹优化
    lv_obj_add_event_cb(ui->selftest_btn_53,selftest_btn_53_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_54,selftest_btn_54_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_55,selftest_btn_55_event_handler, LV_EVENT_ALL,NULL);

    lv_obj_add_event_cb(ui->selftest_btn_56,selftest_btn_56_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_57,selftest_btn_57_event_handler, LV_EVENT_ALL,NULL);
    //喷头PID校准
    lv_obj_add_event_cb(ui->selftest_img_29,selftest_img_29_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_58,selftest_btn_58_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_59,selftest_btn_59_event_handler, LV_EVENT_ALL,NULL);

    //热床PID校准
    lv_obj_add_event_cb(ui->selftest_img_32,selftest_img_32_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_60,selftest_btn_60_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_61,selftest_btn_61_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_62,selftest_btn_62_event_handler, LV_EVENT_ALL,NULL);

    //调平选择
    lv_obj_add_flag(ui->selftest_btn_62,LV_OBJ_FLAG_HIDDEN);    //暂时将跳过按钮隐藏等待讨论
    lv_obj_add_event_cb(ui->selftest_img_34,selftest_img_34_event_handler, LV_EVENT_ALL,'1');
    lv_obj_add_event_cb(ui->selftest_img_35,selftest_img_34_event_handler, LV_EVENT_ALL,'2');
    lv_obj_add_event_cb(ui->selftest_img_36,selftest_img_34_event_handler, LV_EVENT_ALL,'3');
    lv_obj_add_event_cb(ui->selftest_btn_64,selftest_btn_64_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->selftest_btn_65,selftest_btn_65_event_handler, LV_EVENT_ALL,NULL);
}

static void fullscreen_mode_cont_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_obj_add_flag(guider_ui.fullscreen_mode_cont_1,LV_OBJ_FLAG_HIDDEN);
            break;
        }
        default:
            break;
	}
}

void events_init_fullscreen_mode(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->fullscreen_mode_cont_1,fullscreen_mode_cont_1_event_handler, LV_EVENT_ALL,NULL);
}

static void messagebox_btn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            uint16_t i = lv_tabview_get_tab_act(guider_ui.selftest_tabview_1);
            switch(i)
            {
                case 6: //喉管风扇
                {
                    if(manualtestlength == 0)   //正常自检
                    {
                        selftest_result[0] = 2;
                        CrLogI("reslut is %d",selftest_result[0]);
                        set_printer_data(0x03,3,"20");
                        lv_tabview_set_act(guider_ui.selftest_tabview_1,7,LV_ANIM_ON);
                        lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                    }
                    else                        //手动自检
                    {
                        if(manualtest_curpage+1 < manualtestlength)
                        {
                            set_printer_data(0x03,3,"20");
                            lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                            lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                        }
                        else
                        {
                            set_printer_data(0x03,3,"20");
                            manualtestlength = 0;
                            manualtest_curpage = 0;
                            guider_load_screen(SCR_SETINGS_PAGE);
                        }
                    }
                    break;
                }
                case 7: //模型风扇
                {
                    if(manualtestlength == 0)   //正常自检
                    {
                        selftest_result[1] = 2;
                        CrLogI("reslut is %d",selftest_result[1]);
                        lv_tabview_set_act(guider_ui.selftest_tabview_1,8,LV_ANIM_ON);
                        lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                    }
                    else                        //手动自检
                    {
                        if(manualtest_curpage+1 < manualtestlength)
                        {
                            lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                            lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                        }
                        else
                        {
                            manualtestlength = 0;
                            manualtest_curpage = 0;
                            guider_load_screen(SCR_SETINGS_PAGE);
                        }
                    }
                    break;
                }
                case 8: //轴移动
                {
                    if(manualtestlength == 0)   //正常自检
                    {
                        selftest_result[2] = 2;
                        lv_tabview_set_act(guider_ui.selftest_tabview_1,9,LV_ANIM_ON);
                        lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                        lv_timer_set_repeat_count(mytimer,0);
                    }
                    else                        //手动自检
                    {
                        if(manualtest_curpage+1 < manualtestlength)
                        {
                            lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                            lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                        }
                        else
                        {
                            manualtestlength = 0;
                            manualtest_curpage = 0;
                            guider_load_screen(SCR_SETINGS_PAGE);
                        }
                    }
                    break;
                }
                case 9: //断料检测
                {
                    break;
                }
                case 10: //手动调平
                {
                    break;
                }
                case 11: //自动调平
                {
                    break;
                }
                case 12: //振纹优化
                {
                    break;
                }
            }
            lv_obj_add_flag(guider_ui.messagebox_cont_1,LV_OBJ_FLAG_HIDDEN);
            break;
        }
        default:
            break;
	}
}

static void messagebox_btn_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            uint16_t i = lv_tabview_get_tab_act(guider_ui.selftest_tabview_1);
            switch(i)
            {
                case 6: //喉管风扇
                {
                    if(manualtestlength == 0)   //正常自检
                    {
                        selftest_result[0] = 1;
                        CrLogI("reslut is %d",selftest_result[0]);
                        lv_tabview_set_act(guider_ui.selftest_tabview_1,7,LV_ANIM_ON);
                        lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                        set_printer_data(0x03,3,"20");
                    }
                    else                        //手动自检
                    {
                        if(manualtest_curpage+1 < manualtestlength)
                        {
                            set_printer_data(0x03,3,"20");
                            lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                            lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                        }
                        else
                        {
                            set_printer_data(0x03,3,"20");
                            manualtestlength = 0;
                            manualtest_curpage = 0;
                            guider_load_screen(SCR_SETINGS_PAGE);
                        }
                    }
                    break;
                }
                case 7: //模型风扇
                {
                    if(manualtestlength == 0)   //正常自检
                    {
                        selftest_result[1] = 1;
                        CrLogI("reslut is %d",selftest_result[1]);
                        lv_tabview_set_act(guider_ui.selftest_tabview_1,8,LV_ANIM_ON);
                        lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                    }
                    else                        //手动自检
                    {
                        if(manualtest_curpage+1 < manualtestlength)
                        {
                            lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                            lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                        }
                        else
                        {
                            manualtestlength = 0;
                            manualtest_curpage = 0;
                            guider_load_screen(SCR_SETINGS_PAGE);
                        }
                    }
                    break;
                }
                case 8: //轴移动
                {
                    if(manualtestlength == 0)   //正常自检
                    {
                        selftest_result[2] = 1;
                        lv_tabview_set_act(guider_ui.selftest_tabview_1,9,LV_ANIM_ON);
                        lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                    }
                    else                        //手动自检
                    {
                        if(manualtest_curpage+1 < manualtestlength)
                        {
                            lv_tabview_set_act(guider_ui.selftest_tabview_1,manualtest[++manualtest_curpage],LV_ANIM_ON);
                            lv_event_send(guider_ui.selftest_tabview_1,LV_EVENT_VALUE_CHANGED,NULL);
                        }
                        else
                        {
                            manualtestlength = 0;
                            manualtest_curpage = 0;
                            guider_load_screen(SCR_SETINGS_PAGE);
                        }
                    }
                    break;
                }
                case 9: //断料检测
                {
                    lv_label_set_text(guider_ui.selftest_btn_21_label,"下一步");
                    break;
                }
                case 10: //手动调平
                {
                    break;
                }
                case 11: //自动调平
                {
                    break;
                }
                case 12: //振纹优化
                {
                    break;
                }
            }
            lv_obj_add_flag(guider_ui.messagebox_cont_1,LV_OBJ_FLAG_HIDDEN);
            break;
        }
        default:
            break;
	}
}

void events_init_messagebox(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->messagebox_btn_1,messagebox_btn_1_event_handler, LV_EVENT_ALL,NULL);
    lv_obj_add_event_cb(ui->messagebox_btn_2,messagebox_btn_2_event_handler, LV_EVENT_ALL,NULL);
}

static void sleep_mode_cont_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            set_printer_data(0x1b,1,"2");
            lv_obj_add_flag(guider_ui.sleep_mode_cont_1,LV_OBJ_FLAG_HIDDEN);
            break;
        }
        default:
            break;
	}
}

void events_init_sleep_mode(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->sleep_mode_cont_1,sleep_mode_cont_1_event_handler, LV_EVENT_ALL,NULL);
}

static void printmessage_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            lv_obj_add_flag(guider_ui.printmessage_cont_1,LV_OBJ_FLAG_HIDDEN);
            break;
        }
        default:
            break;
	}
}

void events_init_printmessage(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->printmessage_btn_3, printmessage_btn_3_event_handler, LV_EVENT_ALL, NULL);
}

static void wait_btn_3_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
        case LV_EVENT_CLICKED:
        {
            send_buzzer(0x01);
            if(strcmp(lv_label_get_text(guider_ui.wait_label_3),"网络连接异常") == 0)
            {
                CrLogI("Network status is abnormal.");
                lv_obj_add_flag(guider_ui.wait_cont_1,LV_OBJ_FLAG_HIDDEN);
            }
            else
            {
                get_printer_data(0x07, 1, "2");
                //进入等待状态
                wait_timer = lv_timer_create(waittimer_handler, 10000, NULL);
                lv_obj_clear_flag(guider_ui.wait_cont_1,LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(guider_ui.wait_spinner_1,LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(guider_ui.wait_label_1,LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(guider_ui.wait_label_2,LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(guider_ui.wait_label_3,LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(guider_ui.wait_btn_3,LV_OBJ_FLAG_HIDDEN);
    //            lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
                CrLogI("connect error,wait wifi refresh....");
            }
            connectwifi_state = false;
            break;
        }
        default:
            break;
	}
}

void events_init_wait(lv_ui *ui)
{
    lv_obj_add_event_cb(ui->wait_btn_3, wait_btn_3_event_handler, LV_EVENT_ALL, NULL);
}
