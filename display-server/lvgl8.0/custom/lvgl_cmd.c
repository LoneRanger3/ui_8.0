#include "lvgl_cmd.h"
#include <stdio.h>
#include <string.h>
#include "CrlogDef.h"

/*
flag是一个十六进制数，最多可以表示256个类型，对于目前来说足够
0x01：获取打印机的Gcode文件名称和目录
0x02：获取打印机的Z轴偏移数据
0x03：获取当前喷头和热床温度
0x04：获取当前XYZ位置
0x05：获取PLA、ABS预热的温度参数
0x06：获取当前风扇状态
0x07：获取当前照明状态
0x08：获取当前WIFI状态
0x09：获取当前语言
0x0a：获取运动参数，包括：传动比参数、最大加速度参数、最大拐角参数、最大速度参数
0x0b：获取温度PID参数，包括喷头和热床的PID参数
0x0c：获取关于本机页面的所有参数
0x0d：获取打印时间和打印进度
0x0e：获取是否开启断电续打
0x0f：获取是否进行开机自检
*/

void send_get_printer_data(unsigned char flag, unsigned int len, char *data)
{
#ifdef IS_SYSTEM_USE
	GetPrinterDataFromManager(flag, len, data);
#endif
}

/*
flag是一个十六进制数，最多可以表示256个类型，对于目前来说足够
0x01：设置喷头最高温度
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
0x0c：设置预热参数，包括PLA、ABS的喷头和热床参数
0x0d：设置当前语言
0x0e：设置调平操作参数
0x0f：设置运动参数，包括传动比参数、最大加速度参数、最大拐角速度参数、最大速度参数
0x10：设置温度PID参数
*/
void send_set_printer_data(unsigned char flag, unsigned int len, char *data)
{
#ifdef IS_SYSTEM_USE
	SetPrinterDataToManager(flag, len, data);
#else

#if 0
    CrLogI("flag = 0x%x",flag);
    CrLogI(data);
    switch(flag)
    {
        case 0x01:
            set_response_printer_data(0x01,1,"1");
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
            set_response_printer_data(0x05,len,data);
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
        case 0x09:
            set_response_printer_data(0x09,len,data);
            break;
        case 0x0a:
            set_response_printer_data(0x0a,len,data);
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
        case 0x11:
            set_response_printer_data(0x11,len,data);
            break;
        case 0x12:
            set_response_printer_data(0x12,len,data);
            break;
        case 0x13:
            set_response_printer_data(0x13,len,data);
            break;
        case 0x14:
            set_response_printer_data(0x14,len,data);
            break;
        case 0x15:
            set_response_printer_data(0x15,len,data);
            break;
        default:
            break;
    }
#endif

#endif
}

void send_set_buzzer_cmd(void)
{
#ifdef IS_SYSTEM_USE
	SetPrinterBuzzerToManager(0x01);
#endif
}


int send_lvgl_cmd(uint8_t cmd_flag, char *cmd_content, int content_len,bool is_set_cmd)
{
    CrLogI("-----------cmd flag %0x, data %s, len %d, is set %d", cmd_flag, cmd_content, content_len, is_set_cmd);
    if ( is_set_cmd )
        send_set_printer_data(cmd_flag, content_len, cmd_content);
    else
        send_get_printer_data(cmd_flag, content_len, cmd_content);
}



void send_set_target_temper_cmd(uint16_t target, bool is_hotend)
{
    char buff[10] = {0};
    sprintf(buff, "%c%d", is_hotend ? '2' : '1', target);
    send_lvgl_cmd(CMD_SET_TEMPER, buff, strlen(buff) + 1, true);
}

void send_set_model_fan_opt_cmd(uint8_t duty_percent)
{
    if ( duty_percent > 100 )
        duty_percent = 100;

    char buff[10] = {0};
    sprintf(buff, "00\t%d", duty_percent);
    send_lvgl_cmd(CMD_SET_PARAM_STATUS, buff, strlen(buff) + 1, true);
}

void send_set_chassis_fan_opt_cmd(uint8_t duty_percent)
{
    if ( duty_percent > 100 )
        duty_percent = 100;
    char buff[10] = {0};
    sprintf(buff, "01\t%d", duty_percent);
    send_lvgl_cmd(CMD_SET_PARAM_STATUS, buff, strlen(buff) + 1, true);
}

void send_set_auxiliary_fan_opt_cmd(uint8_t duty_percent)
{
    if ( duty_percent > 100 )
        duty_percent = 100;

    char buff[10] = {0};
    sprintf(buff, "02\t%d", duty_percent);
    send_lvgl_cmd(CMD_SET_PARAM_STATUS, buff, strlen(buff) + 1, true);
}

void send_set_light_opt_cmd(bool open)
{
    char buff[3] = {0};
    sprintf(buff, "1%c", open ? '1' : '0');
    send_lvgl_cmd(CMD_SET_PARAM_STATUS, buff, strlen(buff) + 1, true);
}

void send_set_axis_move_opt_cmd(axis_type_t axis, bool dir_positive, float dis, int feedrate)
{
    if ( axis <  AXIS_X || axis > AXIS_E )
        return ;
        
    char buff[20] = {0};
    if ( axis == AXIS_E )
    {
        sprintf(buff, "E%c%.3f F%d", dir_positive ? '+' : '-', dis, feedrate);
        send_lvgl_cmd(CMD_SET_FILAMENT_OPT, buff, strlen(buff) + 1, true);

        return ;
    }
    else if ( axis == AXIS_X )
    {
        sprintf(buff, "X%c%.3f F%d", dir_positive ? '+' : '-', dis, feedrate);
    }
    else if ( axis == AXIS_Y )
    {
        sprintf(buff, "Y%c%.3f F%d", dir_positive ? '+' : '-', dis, feedrate);
    }
    else if ( axis == AXIS_Z )
    {
        sprintf(buff, "Z%.3f F%d", dis, feedrate);   //在外部进行拼接好，因为Z轴的喷头有可能能上升，也有可能不能上升。
    }

    send_lvgl_cmd(CMD_SET_AXIS_MOVE, buff, strlen(buff) + 1, true);
}

void send_set_axis_home_cmd(bool home_x, bool home_y, bool home_z)
{
    if ( !home_x && !home_y && !home_z )
        return ;

    char buff[2] = {0};
    if ( home_x && home_y && home_z )
    {
        buff[0] = 'E';
    }
    else if ( home_x && home_y )
    {
        buff[0] = 'A';
    }
    else  //
    {
        if ( home_x )
        {
            buff[0] = 'C';
        }
        else if ( home_y )
        {
            buff[0] = 'D';
        }
        else
        {
            buff[0] = 'B';
        }
    }

    send_lvgl_cmd(CMD_SET_AXIS_MOVE, buff, strlen(buff) + 1, true);
}

void send_set_print_start_cmd(uint16_t model_file_index, int printfrom, bool IsPrintCalibration)
{
    char buff[100] = {0};
    switch (printfrom)  //1：from local 2:from udisk 3:from history
    {
        case 1: sprintf(buff, "11\t%d\t%c", model_file_index, IsPrintCalibration ? '1':'0');break;
        case 2: sprintf(buff, "11\t%d\t%c", model_file_index, IsPrintCalibration ? '1':'0');break;
        case 3: sprintf(buff, "21\t%d\t%c", model_file_index, IsPrintCalibration ? '1':'0');break; 
        default:
            break;
    }
    send_lvgl_cmd(CMD_SET_START_PRINT, buff, strlen(buff) + 1, true);
}

void send_set_pause_print_cmd(void)
{
    char buff[2] = "2";
    send_lvgl_cmd(CMD_SET_PRINT_OPT, buff, sizeof(buff), true);
}

void send_set_stop_print_cmd(void)
{
    char buff[2] = "1";
    send_lvgl_cmd(CMD_SET_PRINT_OPT, buff, sizeof(buff), true);
}

void send_set_resume_print_cmd(void)
{
    char buff[2] = "3";
    send_lvgl_cmd(CMD_SET_PRINT_OPT, buff, sizeof(buff), true);
}

void send_set_start_print_recovery_file(void)
{
    char buff[2] = "4";
    send_lvgl_cmd(CMD_SET_PRINT_OPT, buff, sizeof(buff), true);
}

void send_set_stop_print_recovery_file(void)
{
    char buff[2] = "5";
    send_lvgl_cmd(CMD_SET_PRINT_OPT, buff, sizeof(buff), true);
}

int  send_set_z_offset_cmd(float z_offset)
{
    char buff[10] = {0};
    sprintf(buff, "%.3f", z_offset);
    send_lvgl_cmd(CMD_SET_Z_OFFSET, buff, strlen(buff) + 1, true);

    return 1;
}

void send_set_start_auto_level_cmd(void)
{
    char buff[2] = "2";
    send_lvgl_cmd(CMD_SET_LEVEL_OPT, buff, strlen(buff) + 1, true);
}


void send_set_print_speed_cmd(uint16_t speed_percent)
{
    char buff[10] = {0};
    sprintf(buff, "%d", speed_percent);
    send_lvgl_cmd(CMD_SET_PRINT_SPEED_PERCENT, buff, strlen(buff) + 1, true);
}

void send_set_print_flow_cmd(uint16_t flow_percent)
{
    char buff[10] = {0};
    sprintf(buff, "%d", flow_percent);
    send_lvgl_cmd(CMD_SET_PRINT_FLOW, buff, strlen(buff) + 1, true);
}

void send_set_stop_fullscreen_cmd(void)
{
    char buff[2] = "1";
    send_lvgl_cmd(CMD_SET_DEV_STATUS_PARAM, buff, sizeof(buff), true);
}

void send_set_camera_shoot_freq(uint8_t freq)
{
    char buff[8] = {0};
    sprintf(buff, "3%d", freq);
    send_lvgl_cmd(CMD_SET_CAMERA_OPT, buff, strlen(buff) + 1, true);
}

void send_set_camera_render_method_photoes(int photoes_count)
{
    char buff[8] = {0};
    sprintf(buff, "4%d", photoes_count);
    send_lvgl_cmd(CMD_SET_CAMERA_OPT, buff, strlen(buff) + 1, true);
}

void send_set_camera_delayed_photography(bool open)
{
    char buff[3] = {0};
    sprintf(buff, "1%c", open ? '1' : '0');
    send_lvgl_cmd(CMD_SET_CAMERA_OPT, buff, strlen(buff) + 1, true);
}

void send_set_camera_shoot_pos(uint8_t pos)
{
    char buff[3] = {0};
    sprintf(buff, "2%c", pos);
    send_lvgl_cmd(CMD_SET_CAMERA_OPT, buff, strlen(buff) + 1, true);
}

void send_set_save_param(void)
{
    char buff[2] = "f";
    send_lvgl_cmd(CMD_SET_PARAM_STATUS, buff, sizeof(buff), true);
}

void send_set_language_cmd(int cur_language)
{
    char buff[256] = {0};
    snprintf(buff, 256, "%d", cur_language);
    send_lvgl_cmd(CMD_SET_LANGUAGE, buff, strlen(buff), true);
}

void send_set_disable_stepper_cmd(void)
{
    char buff[3] = "d0";
    send_lvgl_cmd(CMD_SET_PARAM_STATUS, buff, sizeof(buff), true);
}


void send_set_ai_detection_switch_cmd(bool opened)
{
    if(opened)
    {
        char buff[3] = "11";
        send_lvgl_cmd(CMD_SET_AI_OPT, buff, sizeof(buff), true);
    }
    else
    {
        char buff[3] = "10";
        send_lvgl_cmd(CMD_SET_AI_OPT, buff, sizeof(buff), true);
    }
}

void send_set_ai_flowcalibration_switch_cmd(bool opened)
{
    if(opened)
    {
        char buff[3] = "51";
        send_lvgl_cmd(CMD_SET_AI_OPT, buff, sizeof(buff), true);
    }
    else
    {
        char buff[3] = "50";
        send_lvgl_cmd(CMD_SET_AI_OPT, buff, sizeof(buff), true);
    }
}

void send_set_fault_action_cmd(bool is_detection_in_printing)
{
    if(is_detection_in_printing)
    {
        char buff[3] = "31";
        send_lvgl_cmd(CMD_SET_AI_OPT, buff, sizeof(buff), true);
    }
    else
    {
        char buff[3] = "30";
        send_lvgl_cmd(CMD_SET_AI_OPT, buff, sizeof(buff), true);
    }
}

void send_set_first_layer_detection_cmd(bool opened)
{
    if(opened)
    {
        char buff[3] = "41";
        send_lvgl_cmd(CMD_SET_AI_OPT, buff, sizeof(buff), true);
    }
    else
    {
        char buff[3] = "40";
        send_lvgl_cmd(CMD_SET_AI_OPT, buff, sizeof(buff), true);
    }
}




void send_get_tempers_cmd(void)
{
    send_lvgl_cmd(CMD_GET_TEMPER, NULL, 0, false);
}

void send_get_fans_status_cmd(void)
{
    char buff[1] = "0";
    send_lvgl_cmd(CMD_GET_PARAM_STATUS, buff, sizeof(buff), false);
}

void send_get_light_status_cmd(void)
{
    char buff[1] = "1";
    send_lvgl_cmd(CMD_GET_PARAM_STATUS, buff, sizeof(buff), false);
}

void send_get_wifi_status_cmd(void)
{
    char buff[1] = "1";
    send_lvgl_cmd(CMD_GET_WIFI_INFO, buff, sizeof(buff), false);
}

void send_get_power_loss_recovery_info_cmd(void)
{

}

void send_get_print_status(void)
{
    char buff[2] = "0";
    send_lvgl_cmd(CMD_GET_PRINT_STATUS, buff, sizeof(buff), false);
}

void send_get_print_proccess(void)
{
    char buff[2] = "1";
    send_lvgl_cmd(CMD_GET_PRINT_STATUS, buff, sizeof(buff), false);
}

void send_get_root_dir_file_count_cmd(bool is_local)
{
    char buff[10] = {0};
    sprintf(buff, "10\t%c\t2", is_local ? 'A' : 'B');
    send_lvgl_cmd(CMD_GET_PRINT_FILE_INFO, buff, strlen(buff) + 1, false);
}

void send_get_parent_dir_file_count_cmd(void)
{
    char buff[10] = "10\tC\t2";
    send_lvgl_cmd(CMD_GET_PRINT_FILE_INFO, buff, strlen(buff) + 1, false);
}

void send_get_cur_dir_file_count_cmd(uint16_t dir_sort_index)
{
    char buff[15] = {0};
    sprintf(buff, "10\t%d\t2", dir_sort_index);
    send_lvgl_cmd(CMD_GET_PRINT_FILE_INFO, buff, strlen(buff) + 1, false);
}

int  send_get_cur_dir_dirent_infos_cmd(uint16_t start_index, uint8_t count)
{
    if ( !count )
        return ;

    if ( !start_index )
        start_index = 1;

    char buff[15] = {0};
    sprintf(buff , "11\t%03d\t%03d", start_index, start_index + count - 1);
    send_lvgl_cmd(CMD_GET_PRINT_FILE_INFO, buff, strlen(buff) + 1, false);
}

void send_get_print_record_count_cmd(void)
{
    char buff[3] = "20";
    send_lvgl_cmd(CMD_GET_PRINT_FILE_INFO, buff, sizeof(buff), false);
}

void send_get_records_cmd(uint16_t start_index, uint8_t count)
{
    if ( !count )
        return ;

    if ( !start_index )
        start_index = 1;

    char buff[10] = "21";
    sprintf(buff + 2, "\t%03d\t%03d", start_index, start_index + count - 1);
    send_lvgl_cmd(CMD_GET_PRINT_FILE_INFO, buff, strlen(buff) + 1, false);
}

void send_get_filling_chart_info_cmd(uint16_t model_file_index)
{
   if ( !model_file_index )
      return ;
    
    char buff[10] = {0};
    sprintf(buff, "12\t%d", model_file_index);
    send_lvgl_cmd(CMD_GET_PRINT_FILE_INFO, buff, strlen(buff) + 1, false);
}

int  send_get_z_offset_cmd(void)
{
    send_lvgl_cmd(CMD_GET_Z_OFFSET, NULL, 0, false);
}

void send_get_print_flow_cmd(void)
{
    send_lvgl_cmd(CMD_GET_PRINT_FLOW, NULL, 0, false);
}

void send_get_print_speed_cmd(void)
{
    send_lvgl_cmd(CMD_GET_PRINT_SPEED_PERCENT, NULL, 0, false);
}


void send_get_vedioes_count_cmd(void)
{
    char buff[3] = "30";
    send_lvgl_cmd(CMD_GET_PRINT_FILE_INFO, buff, sizeof(buff), false);
}

void send_get_vedio_infos_cmd(uint16_t start_index, uint8_t count)
{
    if ( !count )
        return ;

    if ( !start_index )
        start_index = 1;

    char buff[10] = "31";
    sprintf(buff + 2, "\t%03d\t%03d", start_index, start_index + count - 1);
    send_lvgl_cmd(CMD_GET_PRINT_FILE_INFO, buff, strlen(buff) + 1, false);
}

void send_get_camera_shoot_freq(void)
{
    char buff[2] = "3";
    send_lvgl_cmd(CMD_GET_CAMERA_STATUS, buff, sizeof(buff), false);
}

void send_get_camera_render_method_photoes(void)
{
    char buff[2] = "4";
    send_lvgl_cmd(CMD_GET_CAMERA_STATUS, buff, sizeof(buff), false);
}

void send_get_camera_delayed_photography(void)
{
    char buff[2] = "1";
    send_lvgl_cmd(CMD_GET_CAMERA_STATUS, buff, sizeof(buff), false);
}

void send_get_camera_shoot_pos(void)
{
    char buff[2] = "2";
    send_lvgl_cmd(CMD_GET_CAMERA_STATUS, buff, sizeof(buff), false);
}

void send_get_axis_home_status_cmd(void)
{
    send_lvgl_cmd(CMD_GET_HOME_STATUS_INFO, NULL, 0, false);
}

void send_get_cur_print_gcode_info_cmd(void)
{
    char buff[3] = "15";
    send_lvgl_cmd(CMD_GET_PRINT_FILE_INFO, buff, sizeof(buff), false);
}

void send_get_cur_language_cmd(void)
{
    send_lvgl_cmd(CMD_GET_CUR_LANGUAGE, NULL, 0, false);
}

void send_get_faq_qrcode_cmd(void)
{
    char buff[2] = "2";
    send_lvgl_cmd(CMD_GET_QRCODE, buff, sizeof(buff), false);
}

void send_get_creality_cloud_qrcode_cmd(void)
{
    char buff[2] = "1";
    send_lvgl_cmd(CMD_GET_QRCODE, buff, sizeof(buff), false);
}

void send_get_ai_detection_switch_cmd(void)
{
    char buff[2] = "1";
    send_lvgl_cmd(CMD_GET_AI_OPT, buff, sizeof(buff), false);
}

void send_get_fault_action_cmd(void)
{

}

void send_get_first_layer_detection_cmd(void)
{

}
