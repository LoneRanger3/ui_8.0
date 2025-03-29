/*
 * commu_thread.c
 *
 *  Created on: December 10, 2021
 *      Author: liuxinchao
 */
#define IS_SYSTEM_USE

#include "lvgl/lvgl.h"
#include "commu_thread.h"
#include "custom.h"
#include <stdlib.h>
#include<string.h>
#include "gui_guider.h"
#include "clanguage.h"
#include <stdio.h>

#ifdef IS_SYSTEM_USE
	#include "Message/ServerMessage.h"
#endif


 /*
flag是一个按位表示的数据，相应的位为0表示该数据停止自动刷新，为1表示该数据开启自动刷新
其中：
0位表示温度的刷新，包括当前的喷嘴温度和热床温度
1位表示当前位置的刷新，包括XYZ的当前位置
2位表示打印中打印进度百分比和已打印时间的刷新
目前暂时用到这三位，其余的需要的再补充
*/
void set_refresh_data(unsigned char flag)
{
#ifdef IS_SYSTEM_USE
	SetPrinterRefreshToManager(flag);
#endif
}

void send_buzzer(unsigned char flag)
{
#ifdef IS_SYSTEM_USE
	SetPrinterBuzzerToManager(flag);
#endif
}
//
//static bool file_name_null = false;
//void save_file_names(char *data,int len)
//{
//    if(len == 0)
//    {
//        file_name_null = true;
//        print_file_pages = 0;
//    }
//    else
//    {
//        file_name_null = false;
//        free((void *)file_names);
//        file_names = malloc(len);
//        memcpy(file_names,data,len);
//        print_file_ok = true;
//
//        char *temp = strtok(data,"\n");
//        int file_num = 0;
//        while(temp)
//        {
//            file_num++;
//            temp = strtok(NULL,"\n");
//        }
//        print_file_pages = file_num / FILE_NUM_PRE_PAGE;
//        if((file_num % FILE_NUM_PRE_PAGE) != 0)
//            print_file_pages++;
//    }
//}
//
//void handle_file(char *data,int len, unsigned char cpage)
//{
//    if(file_name_null)
//    {
//        return;
//    }
//
//    lv_obj_t * list_btn;
//    unsigned char flag_num;
//    bool name_flag = false;
//
//    int file_start_num = cpage * FILE_NUM_PRE_PAGE;
//    int file_end_num = cpage * FILE_NUM_PRE_PAGE + FILE_NUM_PRE_PAGE;
//    int file_num = 0;
//
//    char *file_copy = malloc(len);
//    memcpy(file_copy,data,len);
//
//    //Write style LV_BTN_PART_MAIN for print_list_1
//    static lv_style_t style_print_list_1_main_child;
//    lv_style_reset(&style_print_list_1_main_child);
//
//    //Write style state: LV_STATE_DEFAULT for style_print_list_1_main_child
//    lv_style_set_radius(&style_print_list_1_main_child, LV_STATE_DEFAULT, 3);
//    lv_style_set_bg_color(&style_print_list_1_main_child, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
////	lv_style_set_bg_grad_color(&style_print_list_1_main_child, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
////	lv_style_set_bg_grad_dir(&style_print_list_1_main_child, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
//    lv_style_set_bg_opa(&style_print_list_1_main_child, LV_STATE_DEFAULT, 255);
//    lv_style_set_text_color(&style_print_list_1_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
//    lv_style_set_text_font(&style_print_list_1_main_child, LV_STATE_DEFAULT, &lv_font_simsun_36);
//
//    char *temp = strtok(file_copy,"\n");
//    while(temp)
//    {
//        file_num++;
//        if(file_num > file_end_num)
//        {
//            break;
//        }
//        name_flag = false;
//        if((file_num > file_start_num) && (file_num <= file_end_num))
//        {
//            flag_num = 0;
//            for(unsigned char i=0;i<strlen(temp);i++)
//            {
//                if(temp[i] == '/')
//                {
//                    flag_num = i+1;
//                }
//                if(temp[i] == 0x20)
//                {
//                    temp[i] = '\0';
//                    break;
//                }
//            }
//    //        list_btn = lv_list_add_btn(guider_ui.print_list_1, LV_SYMBOL_FILE, &temp[flag_num]);
//            list_btn = lv_list_add_btn(guider_ui.print_list_1, "lv_lib_png/file_png.png", &temp[flag_num]);
//            lv_obj_add_style(list_btn, LV_BTN_PART_MAIN, &style_print_list_1_main_child);
//            lv_obj_set_event_cb(list_btn, file_list_btn_event_handler);
//        }
//        temp = strtok(NULL,"\n");
//        if(file_num <= file_start_num)
//        {
//            continue;
//        }
//        if(temp != NULL)
//        {
//            for(unsigned char j=0;j<strlen(temp);j++)
//            {
//                if(*(temp+j) == '.')
//                {
//                    if(*(temp+j+1) == 'G')
//                    {
//                        if(*(temp+j+2) == 'C')
//                        {
//                            if(*(temp+j+3) == 'O')
//                            {
//                                name_flag = true;
//                                break;
//                            }
//                        }
//                    }
//                }
//            }
//            if(!name_flag)
//            {
//                break;
//            }
//        }
//    }
//    free((void *)file_copy);
//}

void showfile(char *data,int len)
{
    print_file_ok = true;
    if(len == 0)
    {
        print_file_pages = 0;
    }
    else
    {
        char file_num = 0;
        char tfile_name[FILE_SIZE+1];
        char tphoto_name[FILE_PHOTO_SIZE];
        char cnt  = 0;
        bool file_photo_flag = false;

        lv_obj_t * list_btn;

        //Write style LV_BTN_PART_MAIN for print_list_1
        static lv_style_t style_print_list_1_main_child;
        lv_style_reset(&style_print_list_1_main_child);

        //Write style state: LV_STATE_DEFAULT for style_print_list_1_main_child
        lv_style_set_radius(&style_print_list_1_main_child, LV_STATE_DEFAULT, 3);
        lv_style_set_bg_color(&style_print_list_1_main_child, LV_STATE_DEFAULT, lv_color_make(0x24, 0x27, 0x2c));
        lv_style_set_bg_opa(&style_print_list_1_main_child, LV_STATE_DEFAULT, 255);
        lv_style_set_text_color(&style_print_list_1_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
        lv_style_set_text_font(&style_print_list_1_main_child, LV_STATE_DEFAULT, &lv_font_simsun_36);

        data++;
        char *temp = strtok(data,"\t");
        while(temp)
        {
            file_num++;
            if(file_num > FILE_NUM_PRE_PAGE)
            {
                break;
            }

            cnt = 0;
            file_photo_flag = false;
            tphoto_name[0] = '\0';
            while(*temp)
            {
                if(*temp == '\n')
                {
                    break;
                }
                if(*temp == ':')
                {
                    file_photo_flag = true;
                    tfile_name[cnt] = '\0';
                    temp++;
                    cnt = 0;
                    continue;
                }
                if(!file_photo_flag)
                {
                    if(cnt > (FILE_SIZE - 1))
                        break;
                    tfile_name[cnt++] = *temp;
                }
                else
                {
                    tphoto_name[cnt++] = *temp;
                }
                temp++;
            }
            tphoto_name[cnt] = '\0';

            if(guider_ui.print_cont_print != NULL)
            {
                if(tphoto_name[0] == '\0')
                {
                    list_btn = lv_list_add_btn(guider_ui.print_list_1, "lv_lib_png/file_png.png", tfile_name);
                }
                else
                {
                    list_btn = lv_list_add_btn(guider_ui.print_list_1, tphoto_name, tfile_name);
                }
                lv_obj_add_style(list_btn, LV_BTN_PART_MAIN, &style_print_list_1_main_child);
                lv_obj_set_event_cb(list_btn, file_list_btn_event_handler);
            }
            if(*temp == '\n')
            {
                break;
            }
            temp = strtok(NULL,"\t");
        }
    }
    set_print_file_nums();
}

void readbigfile(char *data,int len)
{
    unsigned char data_flag = 0,cnt;
    char tdata[5];

    if(len < 2)
    {
        print_file_pages = 0;
        big_photo_name[0] = '\0';
    }
    else
    {
        data++;
        char *temp = strtok(data,"\t");
        while(temp)
        {
            cnt = 0;
            while(*temp)
            {
                if(*temp == '\n')
                {
                    break;
                }
                if(data_flag != 4)
                {
                    if(cnt > 3)
                        break;
                    tdata[cnt++] = *temp;
                }
                else
                {
                    big_photo_name[cnt++] = *temp;
                }
                temp++;
            }
            tdata[cnt] = '\0';
            if(data_flag == 0)
            {
                model_start_pix = atoi(tdata);
            }
            else if(data_flag == 1)
            {
                model_end_pix = atoi(tdata);
            }
            else if(data_flag == 4)
            {
                big_photo_name[cnt] = '\0';
            }

            if(*temp == '\n')
            {
                break;
            }
            data_flag++;
            temp = strtok(NULL,"\t");
        }
        if(guider_ui.home_cont_home != NULL)
        {
            lv_obj_set_hidden(guider_ui.home_img_model,false);
            lv_obj_set_hidden(guider_ui.home_btn_mask,false);
            lv_obj_set_hidden(guider_ui.home_arc_progress,true);
            lv_img_set_src(guider_ui.home_img_model,big_photo_name);
        }
    }
}

/*
flag是一个十六进制数，最多可以表示256个类型，对于目前来说足够
0x01：获取打印机的Gcode文件名称和目录
0x02：获取打印机的Z轴偏移数据
0x03：获取当前喷嘴和热床温度
0x04：获取当前XYZ位置
0x05：获取PLA、ABS预热的温度参数
0x06：获取当前风扇状态
0x07：获取当前照明状态
0x08：获取当前WIFI状态
0x09：获取当前语言
0x0a：获取运动参数，包括：传动比参数、最大加速度参数、最大拐角参数、最大速度参数
0x0b：获取温度PID参数，包括喷嘴和热床的PID参数
0x0c：获取关于本机页面的所有参数
0x0d：获取打印时间和打印进度
*/
void get_printer_data(unsigned char flag, unsigned int len, char *data)
{
#ifdef IS_SYSTEM_USE
	GetPrinterDataFromManager(flag, len, data);
#endif
}

/*
回传的参数结束字符固定为：'\0'
如果有多个参数，则参数间使用的间隔符为：'\t'
*/
void get_response_printer_data(unsigned char flag, unsigned int len, char *data)
{
    unsigned char i,j;
    int num;
    char file_total[FILE_NUM_SIZE+1];

    switch(flag)
    {
        case 0x01:
//            save_file_names(data,len);
            if(*data == '0')
            {
                for(i=0;i<len;i++)
                {
                    if(i>(FILE_NUM_SIZE-1))
                    {
                        break;
                    }
                    file_total[i] = *(data+i+1);
                }
                file_total[i] = '\0';
                print_total_files = atoi(file_total);
                print_file_pages = print_total_files / FILE_NUM_PRE_PAGE;
                if((print_total_files % FILE_NUM_PRE_PAGE) != 0)
                {
                    print_file_pages++;
                }
                handle_file();
            }
            else if(*data == '1')
            {
                showfile(data,len);
            }
            else if(*data == '2')
            {
                readbigfile(data,len);
            }
            break;
        case 0x02:  //0x02：获取打印机的Z轴偏移数据
            for(i=0;i<len;i++)
            {
                if(i>(ZOFFSET_LEN-1))
                {
                    break;
                }
                zoffset_value[i] = *(data+i);
                if(*(data+i) == '\0')
                {
                    break;
                }
            }
            zoffset_value[i] =  '\0';
            if(guider_ui.home_cont_home != NULL)
            {
                if(zoffset_value[0] != '\0')
                {
                    lv_label_set_text(guider_ui.home_label_cur_zoffset, &zoffset_value[0]);
                }
            }

            else if(guider_ui.Level_manual_cont_level_manual != NULL)
            {
                if(zoffset_value[0] != '\0')
                {
                    lv_label_set_text(guider_ui.Level_manual_btn_zoffset_value_label, &zoffset_value[0]);
                }
            }
            else if(guider_ui.PrintingSet_cont_printing_set != NULL)
            {
                if(zoffset_value[0] != '\0')
                {
                    lv_label_set_text(guider_ui.PrintingSet_label_zoffset_value, &zoffset_value[0]);
                }
            }
            else if(guider_ui.ZoffsetSet_cont_zoffset_set != NULL)
            {
                if(zoffset_value[0] != '\0')
                {
                    lv_label_set_text(guider_ui.ZoffsetSet_label_zoffset_value, &zoffset_value[0]);
                }
            }
            break;
        case 0x03:  //0x03：获取当前喷嘴和热床温度
            j = 0;
            for(i=0;i<len;i++)
            {
                if(i>(HOTEND_TEMP_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    hotend_cur_temp[i] = *(data+i);
            }
            hotend_cur_temp[i] = '\0';
//            printf("hotend_cur_temp = %s\n", hotend_cur_temp);
            i++;
            j = i;
            for(;i<len;i++)
            {
                if((i-j)>(BED_TEMP_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    bed_cur_temp[i-j] = *(data+i);
            }
            bed_cur_temp[i-j] = '\0';
//            printf("bed_cur_temp = %s\n", bed_cur_temp);
            i++;
            j = i;
            for(;i<len;i++)
            {
                if((i-j)>(HOTEND_TEMP_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    hotend_max_temp[i-j] = *(data+i);
            }
            hotend_max_temp[i-j] = '\0';
//            printf("hotend_max_temp = %s\n", hotend_max_temp);
            i++;
            j = i;
            for(;i<len;i++)
            {
                if((i-j)>(BED_TEMP_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\0')
                    break;
                else
                    bed_max_temp[i-j] = *(data+i);
            }
            bed_max_temp[i-j] = '\0';
//            printf("bed_max_temp = %s\n", bed_max_temp);
            if(guider_ui.home_cont_home != NULL)
            {
                if(hotend_cur_temp[0] != '\0')
                {
                    lv_label_set_text(guider_ui.home_label_cur_ht_temp, &hotend_cur_temp[0]);
                }
                if(bed_cur_temp[0] != '\0')
                {
                    lv_label_set_text(guider_ui.home_label_cur_bed_temp, &bed_cur_temp[0]);
                }
                if(hotend_max_temp[0] != '\0')
                {
                    lv_label_set_text(guider_ui.home_label_max_ht_temp, &hotend_max_temp[0]);
                }
                if(bed_max_temp[0] != '\0')
                {
                    lv_label_set_text(guider_ui.home_label_max_bed_temp, &bed_max_temp[0]);
                }
            }
            else if(guider_ui.prepare_manual_temp_cont_prepare_manual_temp != NULL)
            {
                if(hotend_max_temp[0] != '\0')
                {
                    lv_label_set_text(guider_ui.prepare_manual_temp_label_hot_mtemp, &hotend_max_temp[0]);
                }
                if(bed_max_temp[0] != '\0')
                {
                    lv_label_set_text(guider_ui.prepare_manual_temp_label_bed_mtemp, &bed_max_temp[0]);
                }
            }
            else if(guider_ui.prepare_material_cont_prepare_material != NULL)
            {
                if(hotend_cur_temp[0] != '\0')
                {
                    lv_label_set_text(guider_ui.prepare_material_label_hotend_cur_temp, &hotend_cur_temp[0]);
                }
            }
            break;
        case 0x04:  //0x04：获取当前XYZ位置
            j = 0;
            for(i=0;i<len;i++)
            {
                if(i>(CUR_POSITION-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    cur_xposition[i] = *(data+i);
            }
            cur_xposition[i] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if((i-j)>(CUR_POSITION-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    cur_yposition[i-j] = *(data+i);
            }
            cur_yposition[i-j] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if((i-j)>(CUR_POSITION-1))
                {
                    break;
                }
                if(*(data+i) == '\0')
                    break;
                else
                    cur_zposition[i-j] = *(data+i);
            }
            cur_zposition[i-j] = '\0';
            if(guider_ui.prepare_move_axis_cont_prepare_move_axis != NULL)
            {
                if(cur_xposition[0] != '\0')
                {
                    lv_label_set_text(guider_ui.prepare_move_axis_btn_cur_xposition_label, &cur_xposition[0]);
                }
                if(cur_yposition[0] != '\0')
                {
                    lv_label_set_text(guider_ui.prepare_move_axis_btn_cur_yposition_label, &cur_yposition[0]);
                }
                if(cur_zposition[0] != '\0')
                {
                    lv_label_set_text(guider_ui.prepare_move_axis_btn_cur_zposition_label, &cur_zposition[0]);
                }
            }
            break;
        case 0x05:  //0x05：获取PLA、ABS预热的温度参数
            if(*data == '0')
            {
                j = 0;
                for(i=0;i<len;i++)
                {
                    if(i>(HOTEND_TEMP_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        PLA_preheat_hotend[i] = *(data+i+1);
                }
                PLA_preheat_hotend[i] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(BED_TEMP_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\0')
                        break;
                    else
                        PLA_preheat_bed[i-j] = *(data+i+1);
                }
                PLA_preheat_bed[i-j] = '\0';
                if(guider_ui.Preheating_cont_preheating != NULL)
                {
                    if(PLA_preheat_hotend[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.Preheating_label_preheat_hotend, &PLA_preheat_hotend[0]);
                    }
                    if(PLA_preheat_bed[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.Preheating_label_preheat_bed, &PLA_preheat_bed[0]);
                    }
                }
            }
            else if(*data == '1')
            {
                j = 0;
                for(i=0;i<len;i++)
                {
                    if(i>(HOTEND_TEMP_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        ABS_preheat_hotend[i] = *(data+i+1);
                }
                ABS_preheat_hotend[i] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(BED_TEMP_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\0')
                        break;
                    else
                        ABS_preheat_bed[i-j] = *(data+i+1);
                }
                ABS_preheat_bed[i-j] = '\0';
                if(guider_ui.Preheating_cont_preheating != NULL)
                {
                    if(ABS_preheat_hotend[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.Preheating_label_preheat_hotend, &ABS_preheat_hotend[0]);
                    }
                    if(ABS_preheat_bed[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.Preheating_label_preheat_bed, &ABS_preheat_bed[0]);
                    }
                }
            }
            break;
        case 0x06:  //0x06：获取当前风扇状态
            if(len)
            {
                if(*data == '1')
                    fan_state = true;
                else
                    fan_state = false;
            }
            if(guider_ui.prepare_manual_temp_cont_prepare_manual_temp != NULL)
            {
                if(fan_state)
                    lv_label_set_text(guider_ui.prepare_manual_temp_label_fan_state, "ON");
                else
                    lv_label_set_text(guider_ui.prepare_manual_temp_label_fan_state, "OFF");
            }
            if(guider_ui.PrintingSet_cont_printing_set != NULL)
            {
                if(fan_state)
                    lv_label_set_text(guider_ui.PrintingSet_label_fan_state_value, "ON");
                else
                    lv_label_set_text(guider_ui.PrintingSet_label_fan_state_value, "OFF");
            }
            break;
        case 0x07:  //0x07：获取当前照明状态
            if(len)
            {
                if(*data == '1')
                    light_state = true;
                else
                    light_state = false;
            }
            if(guider_ui.setting_device_cont_seting_device != NULL)
            {
                if(light_state)
                    lv_label_set_text(guider_ui.setting_device_label_light_state, "ON");
                else
                    lv_label_set_text(guider_ui.setting_device_label_light_state, "OFF");
            }
            else if(guider_ui.PrintingSet_cont_printing_set != NULL)
            {
                if(light_state)
                    lv_label_set_text(guider_ui.PrintingSet_label_light_state_value, "ON");
                else
                    lv_label_set_text(guider_ui.PrintingSet_label_light_state_value, "OFF");
            }
            break;
        case 0x08:  //0x08：获取当前WIFI状态
            if(len)
            {
                if(*data == '1')
                    wifi_state = true;
                else
                    wifi_state = false;
            }
            if(guider_ui.setting_ad_setting_cont_setting_ad_setting != NULL)
            {
                if(wifi_state)
                    lv_label_set_text(guider_ui.setting_ad_setting_label_wifi_state, "ON");
                else
                    lv_label_set_text(guider_ui.setting_ad_setting_label_wifi_state, "OFF");
            }
            break;
        case 0x09:  //0x08：获取当前语言
            if(len)
            {
                if((*data >= '0') && (*data <= '9'))
                    cur_language = *data - 0x30;
            }
            break;
        case 0x0a:  //0x0a：获取运动参数，包括：传动比参数、最大加速度参数、最大拐角参数、最大速度参数
            if(*data == '1')
            {
                j = 0;
                for(i=0;i<len;i++)
                {
                    if(i>(RTO_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        xRTO[i] = *(data+i+1);
                }
                xRTO[i] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(RTO_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        yRTO[i-j] = *(data+i+1);
                }
                yRTO[i-j] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(RTO_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        zRTO[i-j] = *(data+i+1);
                }
                zRTO[i-j] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(RTO_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\0')
                        break;
                    else
                        eRTO[i-j] = *(data+i+1);
                }
                eRTO[i-j] = '\0';
                if(guider_ui.RTOSet_cont_rto_set != NULL)
                {
                    if(xRTO[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.RTOSet_label_xRTO, &xRTO[0]);
                    }
                    if(yRTO[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.RTOSet_label_yRTO, &yRTO[0]);
                    }
                    if(zRTO[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.RTOSet_label_zRTO, &zRTO[0]);
                    }
                    if(eRTO[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.RTOSet_label_eRTO, &eRTO[0]);
                    }
                }
            }
            else if(*data == '2')
            {
                j = 0;
                for(i=0;i<len;i++)
                {
                    if(i>(MACC_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        xmacc[i] = *(data+i+1);
                }
                xmacc[i] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(MACC_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        ymacc[i-j] = *(data+i+1);
                }
                ymacc[i-j] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(MACC_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        zmacc[i-j] = *(data+i+1);
                }
                zmacc[i-j] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(MACC_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\0')
                        break;
                    else
                        emacc[i-j] = *(data+i+1);
                }
                emacc[i-j] = '\0';
                if(guider_ui.MaxAccSet_cont_max_acc_set != NULL)
                {
                    if(xmacc[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.MaxAccSet_label_xmacc, &xmacc[0]);
                    }
                    if(ymacc[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.MaxAccSet_label_ymacc, &ymacc[0]);
                    }
                    if(zmacc[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.MaxAccSet_label_zmacc, &zmacc[0]);
                    }
                    if(emacc[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.MaxAccSet_label_emacc, &emacc[0]);
                    }
                }
            }
            else if(*data == '3')
            {
                j = 0;
                for(i=0;i<len;i++)
                {
                    if(i>(MCONCOR_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        xmconcor[i] = *(data+i+1);
                }
                xmconcor[i] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(MCONCOR_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        ymconcor[i-j] = *(data+i+1);
                }
                ymconcor[i-j] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(MCONCOR_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        zmconcor[i-j] = *(data+i+1);
                }
                zmconcor[i-j] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(MCONCOR_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\0')
                        break;
                    else
                        emconcor[i-j] = *(data+i+1);
                }
                emconcor[i-j] = '\0';
                if(guider_ui.MaxConcorSet_cont_max_concor_set != NULL)
                {
                    if(xmconcor[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.MaxConcorSet_label_xmconcor, &xmconcor[0]);
                    }
                    if(ymconcor[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.MaxConcorSet_label_ymconcor, &ymconcor[0]);
                    }
                    if(zmconcor[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.MaxConcorSet_label_zmconcor, &zmconcor[0]);
                    }
                    if(emconcor[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.MaxConcorSet_label_emconcor, &emconcor[0]);
                    }
                }
            }
            else if(*data == '4')
            {
                j = 0;
                for(i=0;i<len;i++)
                {
                    if(i>(MSPEED_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        xmspeed[i] = *(data+i+1);
                }
                xmspeed[i] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(MSPEED_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        ymspeed[i-j] = *(data+i+1);
                }
                ymspeed[i-j] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(MSPEED_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        zmspeed[i-j] = *(data+i+1);
                }
                zmspeed[i-j] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(MSPEED_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\0')
                        break;
                    else
                        emspeed[i-j] = *(data+i+1);
                }
                emspeed[i-j] = '\0';
                if(guider_ui.MaxSpeedSet_cont_max_speed_set != NULL)
                {
                    if(xmspeed[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.MaxSpeedSet_label_xmspeed, &xmspeed[0]);
                    }
                    if(ymspeed[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.MaxSpeedSet_label_ymspeed, &ymspeed[0]);
                    }
                    if(zmspeed[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.MaxSpeedSet_label_zmspeed, &zmspeed[0]);
                    }
                    if(emspeed[0] != '\0')
                    {
                        lv_label_set_text(guider_ui.MaxSpeedSet_label_emspeed, &emspeed[0]);
                    }
                }
            }
            break;
        case 0x0b:  //0x0b：获取温度PID参数，包括喷嘴和热床的PID参数
            j = 0;
            for(i=0;i<len;i++)
            {
                if(i>(PID_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    hotend_pid_p[i] = *(data+i);
            }
            hotend_pid_p[i] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if((i-j)>(PID_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    hotend_pid_i[i-j] = *(data+i);
            }
            hotend_pid_i[i-j] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if((i-j)>(PID_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    hotend_pid_d[i-j] = *(data+i);
            }
            hotend_pid_d[i-j] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if((i-j)>(PID_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    bed_pid_p[i-j] = *(data+i);
            }
            bed_pid_p[i-j] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if((i-j)>(PID_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    bed_pid_i[i-j] = *(data+i);
            }
            bed_pid_i[i-j] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if((i-j)>(PID_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\0')
                    break;
                else
                    bed_pid_d[i-j] = *(data+i);
            }
            bed_pid_d[i-j] = '\0';
            if(guider_ui.TempPIDSet_cont_temppid_set != NULL)
            {
                if(hotend_pid_p[0] != '\0')
                {
                    lv_label_set_text(guider_ui.TempPIDSet_label_hotend_pid_p, &hotend_pid_p[0]);
                }
                if(hotend_pid_i[0] != '\0')
                {
                    lv_label_set_text(guider_ui.TempPIDSet_label_hotend_pid_i, &hotend_pid_i[0]);
                }
                if(hotend_pid_d[0] != '\0')
                {
                    lv_label_set_text(guider_ui.TempPIDSet_label_hotend_pid_d, &hotend_pid_d[0]);
                }
                if(bed_pid_p[0] != '\0')
                {
                    lv_label_set_text(guider_ui.TempPIDSet_label_bed_pid_p, &bed_pid_p[0]);
                }
                if(bed_pid_i[0] != '\0')
                {
                    lv_label_set_text(guider_ui.TempPIDSet_label_bed_pid_i, &bed_pid_i[0]);
                }
                if(bed_pid_d[0] != '\0')
                {
                    lv_label_set_text(guider_ui.TempPIDSet_label_bed_pid_d, &bed_pid_d[0]);
                }
            }
            break;
        case 0x0c:  //0x0c：获取关于本机页面的所有参数
            j = 0;
            for(i=0;i<len;i++)
            {
                if(*(data+i) == '\t')
                    break;
                else
                    machine_type_value[i] = *(data+i);
            }
            machine_type_value[i] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if(*(data+i) == '\t')
                    break;
                else
                    fireware_ver_value[i-j] = *(data+i);
            }
            fireware_ver_value[i-j] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if(*(data+i) == '\t')
                    break;
                else
                    screen_ver_value[i-j] = *(data+i);
            }
            screen_ver_value[i-j] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if(*(data+i) == '\t')
                    break;
                else
                    hardware_ver_value[i-j] = *(data+i);
            }
            hardware_ver_value[i-j] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if(*(data+i) == '\t')
                    break;
                else
                    print_size_value[i-j] = *(data+i);
            }
            print_size_value[i-j] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if(*(data+i) == '\0')
                    break;
                else
                    official_web_value[i-j] = *(data+i);
            }
            official_web_value[i-j] = '\0';
            if(guider_ui.setting_about_cont_setting_about != NULL)
            {
                if(machine_type_value[0] != '\0')
                {
                    lv_label_set_text(guider_ui.setting_about_label_machine_type, &machine_type_value[0]);
                }
                if(fireware_ver_value[0] != '\0')
                {
                    lv_label_set_text(guider_ui.setting_about_label_fireware_ver, &fireware_ver_value[0]);
                }
                if(screen_ver_value[0] != '\0')
                {
                    lv_label_set_text(guider_ui.setting_about_label_screen_ver, &screen_ver_value[0]);
                }
                if(hardware_ver_value[0] != '\0')
                {
                    lv_label_set_text(guider_ui.setting_about_label_hardware_ver, &hardware_ver_value[0]);
                }
                if(print_size_value[0] != '\0')
                {
                    lv_label_set_text(guider_ui.setting_about_label_print_size, &print_size_value[0]);
                }
                if(official_web_value[0] != '\0')
                {
                    lv_label_set_text(guider_ui.setting_about_label_official_web, &official_web_value[0]);
                }
            }
            break;
        case 0x0d:  //0x0d：获取打印时间和打印进度
            j = 0;
            for(i=0;i<len;i++)
            {
                if(i>(PRINT_TIME_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    print_remain_time[i] = *(data+i);
            }
            print_remain_time[i] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if((i-j)>PERCENT_LEN)
                {
                    break;
                }
                if(*(data+i) == '\0')
                    break;
                else
                    print_percent[i-j] = *(data+i);
            }
            print_percent[i-j] = '\0';
            if(guider_ui.home_cont_home != NULL)
            {
                num = 0;
                if(print_percent[0] != '\0')
                {
                    char temp[PERCENT_LEN+2];
                    for(i=0;i<PERCENT_LEN;i++)
                    {
                        if(print_percent[i] == '\0')
                        {
                            break;
                        }
                        temp[i] = print_percent[i];
                    }
                    num = atoi(print_percent);
                    if(big_photo_name[0] == '\0')
                    {
                        lv_arc_set_value(guider_ui.home_arc_progress,num);
                    }
                    else
                    {
//                        unsigned int hg = num * (model_end_pix - model_start_pix) / 100 + model_start_pix;
//                        lv_obj_set_pos(guider_ui.home_btn_mask, 90, 558 - hg);
                        unsigned int hg = 300 - num * (model_end_pix - model_start_pix) / 100 - model_start_pix;
                        lv_obj_set_size(guider_ui.home_btn_mask, 300, hg);
                    }
                    temp[i] = '%';
                    temp[i+1] = '\0';
                    lv_label_set_text(guider_ui.home_label_fin_percent, &temp[0]);
                }
                if(print_remain_time[0] != '\0')
                {
                    lv_label_set_text(guider_ui.home_label_remain_time, &print_remain_time[0]);
                }
                if(num >= 100)
                {
                    if(guider_ui.home_cont_home != NULL)
                    {
                        set_refresh_data(0x01);
                        lv_obj_set_click(guider_ui.home_img_finish, true);
                        lv_obj_set_click(guider_ui.home_btn_background, true);
                        lv_obj_set_click(guider_ui.home_img_start, false);
                        lv_obj_set_click(guider_ui.home_img_pause, false);
                        lv_obj_set_click(guider_ui.home_btn_stop, false);
                        lv_obj_set_click(guider_ui.home_btn_printing, false);
                        lv_obj_set_hidden(guider_ui.home_btn_background,false);
                        lv_obj_set_hidden(guider_ui.home_img_finish,false);
                        lv_obj_set_hidden(guider_ui.home_img_start,true);
                        lv_obj_set_hidden(guider_ui.home_img_pause,true);
                        lv_obj_set_hidden(guider_ui.home_btn_stop,true);
                        lv_obj_set_hidden(guider_ui.home_line_fenge,true);
                        lv_obj_set_hidden(guider_ui.home_btn_mask,true);

                        lv_obj_set_event_cb(guider_ui.home_img_finish, print_finsh_event_cb);
                        lv_obj_set_event_cb(guider_ui.home_btn_background, print_finsh_event_cb);
                    }
                }
            }
            break;
            case 0x0e:  //0x0e：获取模型灌水图片
                show_model_image(data);
            break;
        default:
            break;
    }
}
/*
flag是一个十六进制数，最多可以表示256个类型，对于目前来说足够
0x01：设置喷嘴最高温度
0x02：设置热床最高温度
0x03：设置打印速度倍数
0x04：设置Z轴偏移数据
0x05：开始打印指定的文件
0x06：打印控制，包括：停止打印，暂停打印，继续打印
0x07：移动XYZ轴，包括移动方向和距离
0x08：释放和锁定电机
0x09：进料和退料操作
0x0a：开始预热：包括PLA预热和ABS预热
0x0b：设置风扇状态、照明状态、WIFI状态、一键冷却、一键关机、恢复网络、恢复出厂
0x0c：设置预热参数，包括PLA、ABS的喷嘴和热床参数
0x0d：设置当前语言
0x0e：设置调平操作参数
0x0f：设置运动参数，包括传动比参数、最大加速度参数、最大拐角速度参数、最大速度参数
0x10：设置温度PID参数
*/
void set_printer_data(unsigned char flag, unsigned int len, char *data)
{
#ifdef IS_SYSTEM_USE
	SetPrinterDataToManager(flag, len, data);
#else
    switch(flag)
    {
        case 0x01:
            set_response_printer_data(0x01,len,data);
            break;
        case 0x02:
            set_response_printer_data(0x02,len,data);
            break;
        case 0x03:
            set_response_printer_data(0x03,len,data);
            break;
        case 0x04:
            set_response_printer_data(0x04,len,data);
            break;
        case 0x05:
            set_response_printer_data(0x05,1,"1");
            break;
        case 0x06:
            set_response_printer_data(0x06,len,data);
            break;
        case 0x07:
            set_response_printer_data(0x07,len,data);
            break;
        case 0x08:
            set_response_printer_data(0x08,len,data);
            break;
        case 0x0b:
            set_response_printer_data(0x0b,len,data);
            break;
        case 0x0c:
            set_response_printer_data(0x0c,len,data);
            break;
        case 0x0d:
            set_response_printer_data(0x0d,len,data);
            break;
        case 0x0e:
            set_response_printer_data(0x0e,len,data);
            break;
        case 0x0f:
            set_response_printer_data(0x0f,len,data);
            break;
        case 0x10:
            set_response_printer_data(0x10,len,data);
            break;
        default:
            break;
    }
#endif
}

void set_response_printer_data(unsigned char flag, unsigned int len, char *data)
{
    unsigned int i;

    switch(flag)
    {
        case 0x01:  //
            for(i=0;i<len;i++)
            {
                if(i>(HOTEND_TEMP_LEN-1))
                {
                    break;
                }
                hotend_max_temp[i] = *(data+i);
                if(*(data+i) == '\0')
                {
                    break;
                }
            }
            hotend_max_temp[i] = '\0';
            if(guider_ui.prepare_manual_temp_cont_prepare_manual_temp != NULL)
            {
                if(hotend_max_temp[0] != '\0')
                {
                    lv_label_set_text(guider_ui.prepare_manual_temp_label_hot_mtemp, &hotend_max_temp[0]);
                }
            }
            if(guider_ui.PrintingSet_cont_printing_set != NULL)
            {
                if(hotend_max_temp[0] != '\0')
                {
                    lv_label_set_text(guider_ui.PrintingSet_label_hotend_mtemp_value, &hotend_max_temp[0]);
                }
            }
            break;
        case 0x02:  //
            for(i=0;i<len;i++)
            {
                if(i>(BED_TEMP_LEN-1))
                {
                    break;
                }
                bed_max_temp[i] = *(data+i);
                if(*(data+i) == '\0')
                {
                    break;
                }
            }
            bed_max_temp[i] = '\0';
            if(guider_ui.prepare_manual_temp_cont_prepare_manual_temp != NULL)
            {
                if(bed_max_temp[0] != '\0')
                {
                    lv_label_set_text(guider_ui.prepare_manual_temp_label_bed_mtemp, &bed_max_temp[0]);
                }
            }
            if(guider_ui.PrintingSet_cont_printing_set != NULL)
            {
                if(bed_max_temp[0] != '\0')
                {
                    lv_label_set_text(guider_ui.PrintingSet_label_bed_mtemp_value, &bed_max_temp[0]);
                }
            }
            break;
        case 0x03:
            for(i=0;i<len;i++)
            {
                if(i>(CUR_SPEED_LEN-1))
                {
                    break;
                }
                cur_speed[i] = *(data+i);
                if(*(data+i) == '\0')
                {
                    break;
                }
            }
            cur_speed[i] = '\0';
            if(guider_ui.PrintingSet_cont_printing_set != NULL)
            {
                if(cur_speed[0] != '\0')
                {
                    char temp[CUR_SPEED_LEN+2];
                    for(i=0;i<CUR_SPEED_LEN;i++)
                    {
                        if(cur_speed[i] == '\0')
                        {
                            break;
                        }
                        temp[i] = cur_speed[i];
                    }
                    temp[i] = '%';
                    temp[i+1] = '\0';
                    lv_label_set_text(guider_ui.PrintingSet_label_cur_speed_value, &temp[0]);
                }
            }
            break;
        case 0x04:
            for(i=0;i<len;i++)
            {
                if(i>(ZOFFSET_LEN-1))
                {
                    break;
                }
                zoffset_value[i] = *(data+i);
                if(*(data+i) == '\0')
                {
                    break;
                }
            }
            zoffset_value[i] = '\0';
            if(guider_ui.Level_manual_cont_level_manual != NULL)
            {
                if(zoffset_value[0] != '\0')
                {
                    lv_label_set_text(guider_ui.Level_manual_btn_zoffset_value_label, &zoffset_value[0]);
                }
            }
            else if(guider_ui.ZoffsetSet_cont_zoffset_set != NULL)
            {
                if(zoffset_value[0] != '\0')
                {
                    lv_label_set_text(guider_ui.ZoffsetSet_label_zoffset_value, &zoffset_value[0]);
                }
            }
            break;
        case 0x05:
            if(len != 1)
            {
                break;
            }
            if(*data == '1')
            {
                print_state = 1;
                guider_load_screen(SCR_HOME_PAGE);
                if(guider_ui.menu_cont_menu != NULL)
                {
                    lv_btn_set_state(guider_ui.menu_btn_home,LV_BTN_STATE_PRESSED);
                    lv_obj_set_click(guider_ui.menu_btn_home, false);
                    lv_obj_set_click(guider_ui.menu_img_home, false);
                    lv_obj_set_click(guider_ui.menu_btn_print, false);
                    lv_obj_set_click(guider_ui.menu_img_print, false);
                    lv_obj_set_click(guider_ui.menu_btn_prepare, false);
                    lv_obj_set_click(guider_ui.menu_img_prepare, false);
                    lv_obj_set_click(guider_ui.menu_btn_setting, false);
                    lv_obj_set_click(guider_ui.menu_img_setting, false);
                }
                lv_demo_printer_anim_in_all(guider_ui.home_cont_home, LV_DEMO_PRINTER_ANIM_DELAY);
//                if(big_photo_name[0] == '\0')
//                {
//                    lv_obj_set_hidden(guider_ui.home_img_model,true);
//                    lv_obj_set_hidden(guider_ui.home_arc_progress,false);
//                }
//                else
//                {
//                    lv_obj_set_hidden(guider_ui.home_img_model,false);
//                    lv_obj_set_hidden(guider_ui.home_arc_progress,true);
//                    //设置灌水效果
//                }
            }
            else
            {
                msgbox("失败");
            }
            break;
        case 0x06:
            if(len != 1)
            {
                break;
            }
            if(*data == '1')
            {
                print_state = 0;
                guider_load_screen(SCR_HOME_PAGE);
                if(guider_ui.menu_cont_menu != NULL)
                {
                    lv_btn_set_state(guider_ui.menu_btn_home,LV_BTN_STATE_PRESSED);
                    lv_obj_set_click(guider_ui.menu_btn_home, false);
                    lv_obj_set_click(guider_ui.menu_img_home, false);
                    lv_obj_set_click(guider_ui.menu_btn_print, true);
                    lv_obj_set_click(guider_ui.menu_img_print, true);
                    lv_obj_set_click(guider_ui.menu_btn_prepare, true);
                    lv_obj_set_click(guider_ui.menu_img_prepare, true);
                    lv_obj_set_click(guider_ui.menu_btn_setting, true);
                    lv_obj_set_click(guider_ui.menu_img_setting, true);
                }
                lv_demo_printer_anim_in_all(guider_ui.home_cont_home, LV_DEMO_PRINTER_ANIM_DELAY);
            }
            else if(*data == '2')
            {
                print_state = 2;
                guider_load_screen(SCR_HOME_PAGE);
                if(guider_ui.menu_cont_menu != NULL)
                {
                    lv_btn_set_state(guider_ui.menu_btn_home,LV_BTN_STATE_PRESSED);
                    lv_obj_set_click(guider_ui.menu_btn_home, false);
                    lv_obj_set_click(guider_ui.menu_img_home, false);
                    lv_obj_set_click(guider_ui.menu_btn_print, false);
                    lv_obj_set_click(guider_ui.menu_img_print, false);
                    lv_obj_set_click(guider_ui.menu_btn_prepare, false);
                    lv_obj_set_click(guider_ui.menu_img_prepare, false);
                    lv_obj_set_click(guider_ui.menu_btn_setting, false);
                    lv_obj_set_click(guider_ui.menu_img_setting, false);
                }
                lv_demo_printer_anim_in_all(guider_ui.home_cont_home, LV_DEMO_PRINTER_ANIM_DELAY);
            }
            else if(*data == '3')
            {
                print_state = 1;
                guider_load_screen(SCR_HOME_PAGE);
                if(guider_ui.menu_cont_menu != NULL)
                {
                    lv_btn_set_state(guider_ui.menu_btn_home,LV_BTN_STATE_PRESSED);
                    lv_obj_set_click(guider_ui.menu_btn_home, false);
                    lv_obj_set_click(guider_ui.menu_img_home, false);
                    lv_obj_set_click(guider_ui.menu_btn_print, false);
                    lv_obj_set_click(guider_ui.menu_img_print, false);
                    lv_obj_set_click(guider_ui.menu_btn_prepare, false);
                    lv_obj_set_click(guider_ui.menu_img_prepare, false);
                    lv_obj_set_click(guider_ui.menu_btn_setting, false);
                    lv_obj_set_click(guider_ui.menu_img_setting, false);
                }
                lv_demo_printer_anim_in_all(guider_ui.home_cont_home, LV_DEMO_PRINTER_ANIM_DELAY);
            }
            break;
        case 0x07:
            {
//                char btemp[12];
//                if((*data == 'X') || (*data == 'Y') || (*data == 'Z'))
//                {
//                    btemp[0] = *data;
//                    btemp[1] = '=';
//                    if(*(data+1) == '0')
//                    {
//                        btemp[2] = 'N';
//                    }
//                    else if(*(data+1) == '1')
//                    {
//                        btemp[2] = 'P';
//                    }
//                    btemp[3] = '-';
//                    if(*(data+2) == '0')
//                    {
//                        btemp[4] = '0';
//                        btemp[5] = '.';
//                        btemp[6] = '1';
//                        btemp[7] = 'm';
//                        btemp[8] = 'm';
//                        btemp[9] = '\0';
//                    }
//                    else if(*(data+2) == '1')
//                    {
//                        btemp[4] = '1';
//                        btemp[5] = 'm';
//                        btemp[6] = 'm';
//                        btemp[7] = '\0';
//                    }
//                    else if(*(data+2) == '2')
//                    {
//                        btemp[4] = '1';
//                        btemp[5] = '0';
//                        btemp[6] = 'm';
//                        btemp[7] = 'm';
//                        btemp[8] = '\0';
//                    }
//                }
//                else if(*data == 'A')
//                {
//                    btemp[0] = 'X';
//                    btemp[1] = 'Y';
//                    btemp[2] = '-';
//                    btemp[3] = 'H';
//                    btemp[4] = 'O';
//                    btemp[5] = 'M';
//                    btemp[6] = 'E';
//                    btemp[7] = '\0';
//                }
//                else if(*data == 'B')
//                {
//                    btemp[0] = 'Z';
//                    btemp[1] = '-';
//                    btemp[2] = 'H';
//                    btemp[3] = 'O';
//                    btemp[4] = 'M';
//                    btemp[5] = 'E';
//                    btemp[6] = '\0';
//                }
//                msgbox(btemp);
            }
            break;
        case 0x08:
            if(len != 1)
            {
                break;
            }
            if(*data == '1')
            {
                if(guider_ui.prepare_move_axis_cont_prepare_move_axis != NULL)
                {
                    motor_loss_state = false;
                    lv_btn_set_state(guider_ui.prepare_move_axis_imgbtn_motor_loss,LV_BTN_STATE_PRESSED);
                }
            }
            else if(*data == '2')
            {
                if(guider_ui.prepare_move_axis_cont_prepare_move_axis != NULL)
                {
                    motor_loss_state = true;
                    lv_btn_set_state(guider_ui.prepare_move_axis_imgbtn_motor_loss,LV_BTN_STATE_CHECKED_PRESSED);
                }
            }
            break;
        case 0x09:
            msgbox("设置成功");
            break;
        case 0x0a:
            msgbox("设置成功");
            break;
        case 0x0b:
            if(len != 2)
            {
                break;
            }
            switch(*data)
            {
                case '0':
                    if(*(data+1) == '1')
                        fan_state = true;
                    else
                        fan_state = false;
                    if(guider_ui.prepare_manual_temp_cont_prepare_manual_temp != NULL)
                    {
                        if(fan_state)
                            lv_label_set_text(guider_ui.prepare_manual_temp_label_fan_state, "ON");
                        else
                            lv_label_set_text(guider_ui.prepare_manual_temp_label_fan_state, "OFF");
                    }
                    if(guider_ui.PrintingSet_cont_printing_set != NULL)
                    {
                        if(fan_state)
                            lv_label_set_text(guider_ui.PrintingSet_label_fan_state_value, "ON");
                        else
                            lv_label_set_text(guider_ui.PrintingSet_label_fan_state_value, "OFF");
                    }
                    break;
                case '1':
                    if(*(data+1) == '1')
                        light_state = true;
                    else
                        light_state = false;
                    if(guider_ui.setting_device_cont_seting_device != NULL)
                    {
                        if(light_state)
                            lv_label_set_text(guider_ui.setting_device_label_light_state, "ON");
                        else
                            lv_label_set_text(guider_ui.setting_device_label_light_state, "OFF");
                    }
                    if(guider_ui.PrintingSet_cont_printing_set != NULL)
                    {
                        if(light_state)
                            lv_label_set_text(guider_ui.PrintingSet_label_light_state_value, "ON");
                        else
                            lv_label_set_text(guider_ui.PrintingSet_label_light_state_value, "OFF");
                    }
                    break;
                case '2':
                    if(*(data+1) == '1')
                        wifi_state = true;
                    else
                        wifi_state = false;
                    if(guider_ui.setting_ad_setting_cont_setting_ad_setting != NULL)
                    {
                        if(wifi_state)
                            lv_label_set_text(guider_ui.setting_ad_setting_label_wifi_state, "ON");
                        else
                            lv_label_set_text(guider_ui.setting_ad_setting_label_wifi_state, "OFF");
                    }
                    break;
                case '3':
                    if(*(data+1) == '1')
                    {
                        hotend_max_temp[0] = '0';
                        hotend_max_temp[1] = '\0';
                        bed_max_temp[0] = '0';
                        bed_max_temp[1] = '\0';
                        if(guider_ui.prepare_manual_temp_cont_prepare_manual_temp != NULL)
                        {
                            if(bed_max_temp[0] != '\0')
                            {
                                lv_label_set_text(guider_ui.prepare_manual_temp_label_bed_mtemp, &bed_max_temp[0]);
                            }
                            if(hotend_max_temp[0] != '\0')
                            {
                                lv_label_set_text(guider_ui.prepare_manual_temp_label_hot_mtemp, &hotend_max_temp[0]);
                            }
                        }
                    }
                    break;
                case '4':
                    if(*(data+1) == '1')
                    {
                        msgbox("关机");
                    }
                    break;
                case '5':
                    if(*(data+1) == '1')
                    {
                        msgbox("设置成功");
                    }
                    break;
                case '6':
                    if(*(data+1) == '1')
                    {
                        msgbox("设置成功");
                    }
                    break;
                case '7':
                    if(*(data+1) == '1')
                    {
                        msgbox("设置成功");
                    }
                    break;
                default:
                    break;
            }
            break;
        case 0x0c:
            if(*data == '1')    //PLA
            {
                if(*(data+1) == '1')        //hotend
                {
                    for(i=0;i<(len-2);i++)
                    {
                        if(i>(HOTEND_TEMP_LEN-1))
                        {
                            break;
                        }
                        PLA_preheat_hotend[i] = *(data+i+2);
                        if(*(data+i+2) == '\0')
                        {
                            break;
                        }
                    }
                    PLA_preheat_hotend[i] = '\0';
                    if(guider_ui.Preheating_cont_preheating != NULL)
                    {
                        if(PLA_preheat_hotend[0] != '\0')
                        {
                            lv_label_set_text(guider_ui.Preheating_label_preheat_hotend, &PLA_preheat_hotend[0]);
                        }
                    }
                }
                else if(*(data+1) == '2')   //bed
                {
                    for(i=0;i<(len-2);i++)
                    {
                        if(i>(BED_TEMP_LEN-1))
                        {
                            break;
                        }
                        PLA_preheat_bed[i] = *(data+i+2);
                        if(*(data+i+2) == '\0')
                        {
                            break;
                        }
                    }
                    PLA_preheat_bed[i] = '\0';
                    if(guider_ui.Preheating_cont_preheating != NULL)
                    {
                        if(PLA_preheat_bed[0] != '\0')
                        {
                            lv_label_set_text(guider_ui.Preheating_label_preheat_bed, &PLA_preheat_bed[0]);
                        }
                    }
                }
            }
            else if(*data == '2')   //abs
            {
                if(*(data+1) == '1')        //hotend
                {
                    for(i=0;i<(len-2);i++)
                    {
                        if(i>(HOTEND_TEMP_LEN-1))
                        {
                            break;
                        }
                        ABS_preheat_hotend[i] = *(data+i+2);
                        if(*(data+i+2) == '\0')
                        {
                            break;
                        }
                    }
                    ABS_preheat_hotend[i] = '\0';
                    if(guider_ui.Preheating_cont_preheating != NULL)
                    {
                        if(ABS_preheat_hotend[0] != '\0')
                        {
                            lv_label_set_text(guider_ui.Preheating_label_preheat_hotend, &ABS_preheat_hotend[0]);
                        }
                    }
                }
                else if(*(data+1) == '2')   //bed
                {
                    for(i=0;i<(len-2);i++)
                    {
                        if(i>(BED_TEMP_LEN-1))
                        {
                            break;
                        }
                        ABS_preheat_bed[i] = *(data+i+2);
                        if(*(data+i+2) == '\0')
                        {
                            break;
                        }
                    }
                    ABS_preheat_bed[i] = '\0';
                    if(guider_ui.Preheating_cont_preheating != NULL)
                    {
                        if(ABS_preheat_bed[0] != '\0')
                        {
                            lv_label_set_text(guider_ui.Preheating_label_preheat_bed, &ABS_preheat_bed[0]);
                        }
                    }
                }
            }
            break;
        case 0x0d:
            if(len != 1)
            {
                break;
            }
            switch(*data)
            {
                case '0':
                    cur_language = 0;
                    if(guider_ui.Language_cont_language != NULL)
                    {
                        lv_label_set_text(guider_ui.Language_label_1, &language[cur_language][0]);
                        lv_btn_set_state(guider_ui.Language_btn_china,LV_BTN_STATE_PRESSED);
                        lv_btn_set_state(guider_ui.Language_btn_english,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_deutsch,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_espanol,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_france,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_italy,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_portugues,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_russian,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_turkish,LV_BTN_STATE_RELEASED);
                        lv_obj_set_click(guider_ui.Language_btn_china, false);
                        lv_obj_set_click(guider_ui.Language_btn_english, true);
                        lv_obj_set_click(guider_ui.Language_btn_deutsch, true);
                        lv_obj_set_click(guider_ui.Language_btn_espanol, true);
                        lv_obj_set_click(guider_ui.Language_btn_france, true);
                        lv_obj_set_click(guider_ui.Language_btn_italy, true);
                        lv_obj_set_click(guider_ui.Language_btn_portugues, true);
                        lv_obj_set_click(guider_ui.Language_btn_russian, true);
                        lv_obj_set_click(guider_ui.Language_btn_turkish, true);
                    }
                    break;
                case '1':
                    cur_language = 1;
                    if(guider_ui.Language_cont_language != NULL)
                    {
                        lv_label_set_text(guider_ui.Language_label_1, &language[cur_language][0]);
                        lv_btn_set_state(guider_ui.Language_btn_china,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_english,LV_BTN_STATE_PRESSED);
                        lv_btn_set_state(guider_ui.Language_btn_deutsch,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_espanol,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_france,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_italy,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_portugues,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_russian,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_turkish,LV_BTN_STATE_RELEASED);
                        lv_obj_set_click(guider_ui.Language_btn_china, true);
                        lv_obj_set_click(guider_ui.Language_btn_english, false);
                        lv_obj_set_click(guider_ui.Language_btn_deutsch, true);
                        lv_obj_set_click(guider_ui.Language_btn_espanol, true);
                        lv_obj_set_click(guider_ui.Language_btn_france, true);
                        lv_obj_set_click(guider_ui.Language_btn_italy, true);
                        lv_obj_set_click(guider_ui.Language_btn_portugues, true);
                        lv_obj_set_click(guider_ui.Language_btn_russian, true);
                        lv_obj_set_click(guider_ui.Language_btn_turkish, true);
                    }
                    break;
                case '2':
                    cur_language = 2;
                    if(guider_ui.Language_cont_language != NULL)
                    {
                        lv_label_set_text(guider_ui.Language_label_1, &language[cur_language][0]);
                        lv_btn_set_state(guider_ui.Language_btn_china,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_english,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_deutsch,LV_BTN_STATE_PRESSED);
                        lv_btn_set_state(guider_ui.Language_btn_espanol,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_france,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_italy,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_portugues,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_russian,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_turkish,LV_BTN_STATE_RELEASED);
                        lv_obj_set_click(guider_ui.Language_btn_china, true);
                        lv_obj_set_click(guider_ui.Language_btn_english, true);
                        lv_obj_set_click(guider_ui.Language_btn_deutsch, false);
                        lv_obj_set_click(guider_ui.Language_btn_espanol, true);
                        lv_obj_set_click(guider_ui.Language_btn_france, true);
                        lv_obj_set_click(guider_ui.Language_btn_italy, true);
                        lv_obj_set_click(guider_ui.Language_btn_portugues, true);
                        lv_obj_set_click(guider_ui.Language_btn_russian, true);
                        lv_obj_set_click(guider_ui.Language_btn_turkish, true);
                    }
                    break;
                case '3':
                    cur_language = 3;
                    if(guider_ui.Language_cont_language != NULL)
                    {
                        lv_label_set_text(guider_ui.Language_label_1, &language[cur_language][0]);
                        lv_btn_set_state(guider_ui.Language_btn_china,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_english,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_deutsch,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_espanol,LV_BTN_STATE_PRESSED);
                        lv_btn_set_state(guider_ui.Language_btn_france,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_italy,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_portugues,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_russian,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_turkish,LV_BTN_STATE_RELEASED);
                        lv_obj_set_click(guider_ui.Language_btn_china, true);
                        lv_obj_set_click(guider_ui.Language_btn_english, true);
                        lv_obj_set_click(guider_ui.Language_btn_deutsch, true);
                        lv_obj_set_click(guider_ui.Language_btn_espanol, false);
                        lv_obj_set_click(guider_ui.Language_btn_france, true);
                        lv_obj_set_click(guider_ui.Language_btn_italy, true);
                        lv_obj_set_click(guider_ui.Language_btn_portugues, true);
                        lv_obj_set_click(guider_ui.Language_btn_russian, true);
                        lv_obj_set_click(guider_ui.Language_btn_turkish, true);
                    }
                    break;
                case '4':
                    cur_language = 4;
                    if(guider_ui.Language_cont_language != NULL)
                    {
                        lv_label_set_text(guider_ui.Language_label_1, &language[cur_language][0]);
                        lv_btn_set_state(guider_ui.Language_btn_china,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_english,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_deutsch,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_espanol,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_france,LV_BTN_STATE_PRESSED);
                        lv_btn_set_state(guider_ui.Language_btn_italy,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_portugues,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_russian,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_turkish,LV_BTN_STATE_RELEASED);
                        lv_obj_set_click(guider_ui.Language_btn_china, true);
                        lv_obj_set_click(guider_ui.Language_btn_english, true);
                        lv_obj_set_click(guider_ui.Language_btn_deutsch, true);
                        lv_obj_set_click(guider_ui.Language_btn_espanol, true);
                        lv_obj_set_click(guider_ui.Language_btn_france, false);
                        lv_obj_set_click(guider_ui.Language_btn_italy, true);
                        lv_obj_set_click(guider_ui.Language_btn_portugues, true);
                        lv_obj_set_click(guider_ui.Language_btn_russian, true);
                        lv_obj_set_click(guider_ui.Language_btn_turkish, true);
                    }
                    break;
                case '5':
                    cur_language = 5;
                    if(guider_ui.Language_cont_language != NULL)
                    {
                        lv_label_set_text(guider_ui.Language_label_1, &language[cur_language][0]);
                        lv_btn_set_state(guider_ui.Language_btn_china,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_english,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_deutsch,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_espanol,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_france,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_italy,LV_BTN_STATE_PRESSED);
                        lv_btn_set_state(guider_ui.Language_btn_portugues,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_russian,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_turkish,LV_BTN_STATE_RELEASED);
                        lv_obj_set_click(guider_ui.Language_btn_china, true);
                        lv_obj_set_click(guider_ui.Language_btn_english, true);
                        lv_obj_set_click(guider_ui.Language_btn_deutsch, true);
                        lv_obj_set_click(guider_ui.Language_btn_espanol, true);
                        lv_obj_set_click(guider_ui.Language_btn_france, true);
                        lv_obj_set_click(guider_ui.Language_btn_italy, false);
                        lv_obj_set_click(guider_ui.Language_btn_portugues, true);
                        lv_obj_set_click(guider_ui.Language_btn_russian, true);
                        lv_obj_set_click(guider_ui.Language_btn_turkish, true);
                    }
                    break;
                case '6':
                    cur_language = 6;
                    if(guider_ui.Language_cont_language != NULL)
                    {
                        lv_label_set_text(guider_ui.Language_label_1, &language[cur_language][0]);
                        lv_btn_set_state(guider_ui.Language_btn_china,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_english,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_deutsch,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_espanol,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_france,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_italy,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_portugues,LV_BTN_STATE_PRESSED);
                        lv_btn_set_state(guider_ui.Language_btn_russian,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_turkish,LV_BTN_STATE_RELEASED);
                        lv_obj_set_click(guider_ui.Language_btn_china, true);
                        lv_obj_set_click(guider_ui.Language_btn_english, true);
                        lv_obj_set_click(guider_ui.Language_btn_deutsch, true);
                        lv_obj_set_click(guider_ui.Language_btn_espanol, true);
                        lv_obj_set_click(guider_ui.Language_btn_france, true);
                        lv_obj_set_click(guider_ui.Language_btn_italy, true);
                        lv_obj_set_click(guider_ui.Language_btn_portugues, false);
                        lv_obj_set_click(guider_ui.Language_btn_russian, true);
                        lv_obj_set_click(guider_ui.Language_btn_turkish, true);
                    }
                    break;
                case '7':
                    cur_language = 7;
                    if(guider_ui.Language_cont_language != NULL)
                    {
                        lv_label_set_text(guider_ui.Language_label_1, &language[cur_language][0]);
                        lv_btn_set_state(guider_ui.Language_btn_china,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_english,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_deutsch,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_espanol,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_france,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_italy,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_portugues,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_russian,LV_BTN_STATE_PRESSED);
                        lv_btn_set_state(guider_ui.Language_btn_turkish,LV_BTN_STATE_RELEASED);
                        lv_obj_set_click(guider_ui.Language_btn_china, true);
                        lv_obj_set_click(guider_ui.Language_btn_english, true);
                        lv_obj_set_click(guider_ui.Language_btn_deutsch, true);
                        lv_obj_set_click(guider_ui.Language_btn_espanol, true);
                        lv_obj_set_click(guider_ui.Language_btn_france, true);
                        lv_obj_set_click(guider_ui.Language_btn_italy, true);
                        lv_obj_set_click(guider_ui.Language_btn_portugues, true);
                        lv_obj_set_click(guider_ui.Language_btn_russian, false);
                        lv_obj_set_click(guider_ui.Language_btn_turkish, true);
                    }
                    break;
                case '8':
                    cur_language = 8;
                    if(guider_ui.Language_cont_language != NULL)
                    {
                        lv_label_set_text(guider_ui.Language_label_1, &language[cur_language][0]);
                        lv_btn_set_state(guider_ui.Language_btn_china,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_english,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_deutsch,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_espanol,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_france,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_italy,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_portugues,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_russian,LV_BTN_STATE_RELEASED);
                        lv_btn_set_state(guider_ui.Language_btn_turkish,LV_BTN_STATE_PRESSED);
                        lv_obj_set_click(guider_ui.Language_btn_china, true);
                        lv_obj_set_click(guider_ui.Language_btn_english, true);
                        lv_obj_set_click(guider_ui.Language_btn_deutsch, true);
                        lv_obj_set_click(guider_ui.Language_btn_espanol, true);
                        lv_obj_set_click(guider_ui.Language_btn_france, true);
                        lv_obj_set_click(guider_ui.Language_btn_italy, true);
                        lv_obj_set_click(guider_ui.Language_btn_portugues, true);
                        lv_obj_set_click(guider_ui.Language_btn_russian, true);
                        lv_obj_set_click(guider_ui.Language_btn_turkish, false);
                    }
                    break;
                default:
                    break;
            }
            break;
        case 0x0e:
            if(*data == '1')
            {
                switch(*(data+1))
                {
                    case '1':
                        msgbox("设置成功1");
                        break;
                    case '2':
                        msgbox("设置成功2");
                        break;
                    case '3':
                        msgbox("设置成功3");
                        break;
                    case '4':
                        msgbox("设置成功4");
                        break;
                    case '5':
                        msgbox("设置成功5");
                        break;
                    default:
                        break;
                }
            }
            else if(*data == '2')
            {
                if(*(data+1) == '1')
                {
                    if(guider_ui.Level_auto_cont_level_auto != NULL)
                    {
                        lv_obj_set_click(guider_ui.Level_auto_btn_zauto_start, false);
                        lv_label_set_text(guider_ui.Level_auto_label_13, leveling[cur_language]);
                        lv_label_set_text(guider_ui.Level_auto_label_14, waiting[cur_language]);
                    }
                    if(guider_ui.Level_menu_cont_level_menu != NULL)
                    {
                        lv_obj_set_click(guider_ui.Level_menu_btn_manual_level, false);
                    }
                    if(guider_ui.Level_title_cont_level_title != NULL)
                    {
                        lv_obj_set_click(guider_ui.Level_title_img_back, false);
                    }
                    msgbox("设置成功");
                }
            }
            else if(*data == '3')
            {
                char temp[5];
                for(i=0;i<(len-1);i++)
                {
                    if(i>2)
                    {
                        break;
                    }
                    temp[i] = *(data+i+1);
                    if(*(data+i+1) == '\0')
                    {
                        break;
                    }
                }
                int num = atoi(temp);
                temp[i] = '%';
                temp[i+1] = '\0';
                unsigned char pos = num * 4 / 5;
                if(guider_ui.Level_auto_cont_level_auto != NULL)
                {
                    lv_obj_set_size(guider_ui.Level_auto_btn_mask, 300, 90 - pos);
                    lv_label_set_text(guider_ui.Level_auto_label_zauto_progress, temp);
                }
                if(num == 100)
                {
                    if(guider_ui.Level_auto_cont_level_auto != NULL)
                    {
                        lv_obj_set_click(guider_ui.Level_auto_btn_zauto_start, true);
                        lv_label_set_text(guider_ui.Level_auto_label_13, auto_level_finish[cur_language]);
                        lv_label_set_text(guider_ui.Level_auto_label_14, "");
                    }
                    if(guider_ui.Level_menu_cont_level_menu != NULL)
                    {
                        lv_obj_set_click(guider_ui.Level_menu_btn_manual_level, true);
                    }
                    if(guider_ui.Level_title_cont_level_title != NULL)
                    {
                        lv_obj_set_click(guider_ui.Level_title_img_back, true);
                    }
                }
            }
            break;
        case 0x0f:
            switch(*data)
            {
                case '1':
                    if(*(data+1) == '1')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(RTO_LEN-1))
                            {
                                break;
                            }
                            xRTO[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        xRTO[i] = '\0';
                        if(guider_ui.RTOSet_cont_rto_set != NULL)
                        {
                            if(xRTO[0] != '\0')
                            {
                                lv_label_set_text(guider_ui.RTOSet_label_xRTO, &xRTO[0]);
                            }
                        }
                    }
                    else if(*(data+1) == '2')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(RTO_LEN-1))
                            {
                                break;
                            }
                            yRTO[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        yRTO[i] = '\0';
                        if(guider_ui.RTOSet_cont_rto_set != NULL)
                        {
                            if(yRTO[0] != '\0')
                            {
                                lv_label_set_text(guider_ui.RTOSet_label_yRTO, &yRTO[0]);
                            }
                        }
                    }
                    else if(*(data+1) == '3')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(RTO_LEN-1))
                            {
                                break;
                            }
                            zRTO[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        zRTO[i] = '\0';
                        if(guider_ui.RTOSet_cont_rto_set != NULL)
                        {
                            if(zRTO[0] != '\0')
                            {
                                lv_label_set_text(guider_ui.RTOSet_label_zRTO, &zRTO[0]);
                            }
                        }
                    }
                    else if(*(data+1) == '4')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(RTO_LEN-1))
                            {
                                break;
                            }
                            eRTO[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        eRTO[i] = '\0';
                        if(guider_ui.RTOSet_cont_rto_set != NULL)
                        {
                            if(eRTO[0] != '\0')
                            {
                                lv_label_set_text(guider_ui.RTOSet_label_eRTO, &eRTO[0]);
                            }
                        }
                    }
                    break;
                case '2':
                    if(*(data+1) == '1')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MACC_LEN-1))
                            {
                                break;
                            }
                            xmacc[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        xmacc[i] = '\0';
                        if(guider_ui.MaxAccSet_cont_max_acc_set != NULL)
                        {
                            if(xmacc[0] != '\0')
                            {
                                lv_label_set_text(guider_ui.MaxAccSet_label_xmacc, &xmacc[0]);
                            }
                        }
                    }
                    else if(*(data+1) == '2')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MACC_LEN-1))
                            {
                                break;
                            }
                            ymacc[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        ymacc[i] = '\0';
                        if(guider_ui.MaxAccSet_cont_max_acc_set != NULL)
                        {
                            if(ymacc[0] != '\0')
                            {
                                lv_label_set_text(guider_ui.MaxAccSet_label_ymacc, &ymacc[0]);
                            }
                        }
                    }
                    else if(*(data+1) == '3')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MACC_LEN-1))
                            {
                                break;
                            }
                            zmacc[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        zmacc[i] = '\0';
                        if(guider_ui.MaxAccSet_cont_max_acc_set != NULL)
                        {
                            if(zmacc[0] != '\0')
                            {
                                lv_label_set_text(guider_ui.MaxAccSet_label_zmacc, &zmacc[0]);
                            }
                        }
                    }
                    else if(*(data+1) == '4')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MACC_LEN-1))
                            {
                                break;
                            }
                            emacc[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        emacc[i] = '\0';
                        if(guider_ui.MaxAccSet_cont_max_acc_set != NULL)
                        {
                            if(emacc[0] != '\0')
                            {
                                lv_label_set_text(guider_ui.MaxAccSet_label_emacc, &emacc[0]);
                            }
                        }
                    }
                    break;
                case '3':
                    if(*(data+1) == '1')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MCONCOR_LEN-1))
                            {
                                break;
                            }
                            xmconcor[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        xmconcor[i] = '\0';
                        if(guider_ui.MaxConcorSet_cont_max_concor_set != NULL)
                        {
                            if(xmconcor[0] != '\0')
                            {
                                lv_label_set_text(guider_ui.MaxConcorSet_label_xmconcor, &xmconcor[0]);
                            }
                        }
                    }
                    else if(*(data+1) == '2')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MCONCOR_LEN-1))
                            {
                                break;
                            }
                            ymconcor[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        ymconcor[i] = '\0';
                        if(guider_ui.MaxConcorSet_cont_max_concor_set != NULL)
                        {
                            if(ymconcor[0] != '\0')
                            {
                                lv_label_set_text(guider_ui.MaxConcorSet_label_ymconcor, &ymconcor[0]);
                            }
                        }
                    }
                    else if(*(data+1) == '3')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MCONCOR_LEN-1))
                            {
                                break;
                            }
                            zmconcor[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        zmconcor[i] = '\0';
                        if(guider_ui.MaxConcorSet_cont_max_concor_set != NULL)
                        {
                            if(zmconcor[0] != '\0')
                            {
                                lv_label_set_text(guider_ui.MaxConcorSet_label_zmconcor, &zmconcor[0]);
                            }
                        }
                    }
                    else if(*(data+1) == '4')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MCONCOR_LEN-1))
                            {
                                break;
                            }
                            emconcor[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        emconcor[i] = '\0';
                        if(guider_ui.MaxConcorSet_cont_max_concor_set != NULL)
                        {
                            if(emconcor[0] != '\0')
                            {
                                lv_label_set_text(guider_ui.MaxConcorSet_label_emconcor, &emconcor[0]);
                            }
                        }
                    }
                    break;
                case '4':
                    if(*(data+1) == '1')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MSPEED_LEN-1))
                            {
                                break;
                            }
                            xmspeed[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        xmspeed[i] = '\0';
                        if(guider_ui.MaxSpeedSet_cont_max_speed_set != NULL)
                        {
                            if(xmspeed[0] != '\0')
                            {
                                lv_label_set_text(guider_ui.MaxSpeedSet_label_xmspeed, &xmspeed[0]);
                            }
                        }
                    }
                    else if(*(data+1) == '2')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MSPEED_LEN-1))
                            {
                                break;
                            }
                            ymspeed[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        ymspeed[i] = '\0';
                        if(guider_ui.MaxSpeedSet_cont_max_speed_set != NULL)
                        {
                            if(ymspeed[0] != '\0')
                            {
                                lv_label_set_text(guider_ui.MaxSpeedSet_label_ymspeed, &ymspeed[0]);
                            }
                        }
                    }
                    else if(*(data+1) == '3')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MSPEED_LEN-1))
                            {
                                break;
                            }
                            zmspeed[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        zmspeed[i] = '\0';
                        if(guider_ui.MaxSpeedSet_cont_max_speed_set != NULL)
                        {
                            if(zmspeed[0] != '\0')
                            {
                                lv_label_set_text(guider_ui.MaxSpeedSet_label_zmspeed, &zmspeed[0]);
                            }
                        }
                    }
                    else if(*(data+1) == '4')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MSPEED_LEN-1))
                            {
                                break;
                            }
                            emspeed[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        emspeed[i] = '\0';
                        if(guider_ui.MaxSpeedSet_cont_max_speed_set != NULL)
                        {
                            if(emspeed[0] != '\0')
                            {
                                lv_label_set_text(guider_ui.MaxSpeedSet_label_emspeed, &emspeed[0]);
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
            break;
        case 0x10:
            switch(*data)
            {
                case '1':
                    for(i=0;i<(len-1);i++)
                    {
                        if(i>(PID_LEN-1))
                        {
                            break;
                        }
                        hotend_pid_p[i] = *(data+i+1);
                        if(*(data+i+1) == '\0')
                        {
                            break;
                        }
                    }
                    hotend_pid_p[i] = '\0';
                    if(guider_ui.TempPIDSet_cont_temppid_set != NULL)
                    {
                        if(hotend_pid_p[0] != '\0')
                        {
                            lv_label_set_text(guider_ui.TempPIDSet_label_hotend_pid_p, &hotend_pid_p[0]);
                        }
                    }
                    break;
                case '2':
                    for(i=0;i<(len-1);i++)
                    {
                        if(i>(PID_LEN-1))
                        {
                            break;
                        }
                        hotend_pid_i[i] = *(data+i+1);
                        if(*(data+i+1) == '\0')
                        {
                            break;
                        }
                    }
                    hotend_pid_i[i] = '\0';
                    if(guider_ui.TempPIDSet_cont_temppid_set != NULL)
                    {
                        if(hotend_pid_i[0] != '\0')
                        {
                            lv_label_set_text(guider_ui.TempPIDSet_label_hotend_pid_i, &hotend_pid_i[0]);
                        }
                    }
                    break;
                case '3':
                    for(i=0;i<(len-1);i++)
                    {
                        if(i>(PID_LEN-1))
                        {
                            break;
                        }
                        hotend_pid_d[i] = *(data+i+1);
                        if(*(data+i+1) == '\0')
                        {
                            break;
                        }
                    }
                    hotend_pid_d[i] = '\0';
                    if(guider_ui.TempPIDSet_cont_temppid_set != NULL)
                    {
                        if(hotend_pid_d[0] != '\0')
                        {
                            lv_label_set_text(guider_ui.TempPIDSet_label_hotend_pid_d, &hotend_pid_d[0]);
                        }
                    }
                    break;
                case '4':
                    for(i=0;i<(len-1);i++)
                    {
                        if(i>(PID_LEN-1))
                        {
                            break;
                        }
                        bed_pid_p[i] = *(data+i+1);
                        if(*(data+i+1) == '\0')
                        {
                            break;
                        }
                    }
                    bed_pid_p[i] = '\0';
                    if(guider_ui.TempPIDSet_cont_temppid_set != NULL)
                    {
                        if(bed_pid_p[0] != '\0')
                        {
                            lv_label_set_text(guider_ui.TempPIDSet_label_bed_pid_p, &bed_pid_p[0]);
                        }
                    }
                    break;
                case '5':
                    for(i=0;i<(len-1);i++)
                    {
                        if(i>(PID_LEN-1))
                        {
                            break;
                        }
                        bed_pid_i[i] = *(data+i+1);
                        if(*(data+i+1) == '\0')
                        {
                            break;
                        }
                    }
                    bed_pid_i[i] = '\0';
                    if(guider_ui.TempPIDSet_cont_temppid_set != NULL)
                    {
                        if(bed_pid_i[0] != '\0')
                        {
                            lv_label_set_text(guider_ui.TempPIDSet_label_bed_pid_i, &bed_pid_i[0]);
                        }
                    }
                    break;
                case '6':
                    for(i=0;i<(len-1);i++)
                    {
                        if(i>(PID_LEN-1))
                        {
                            break;
                        }
                        bed_pid_d[i] = *(data+i+1);
                        if(*(data+i+1) == '\0')
                        {
                            break;
                        }
                    }
                    bed_pid_d[i] = '\0';
                    if(guider_ui.TempPIDSet_cont_temppid_set != NULL)
                    {
                        if(bed_pid_d[0] != '\0')
                        {
                            lv_label_set_text(guider_ui.TempPIDSet_label_bed_pid_d, &bed_pid_d[0]);
                        }
                    }
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}
