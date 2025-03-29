/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-02 17:27:51
 * @LastEditTime: 2023-10-15 22:58:33
 */
/*
 * commu_thread.h
 *
 *  Created on: December 16, 2021
 *      Author: liuxinchao
 */

#ifndef __COMMU_THREAD_H_
#define __COMMU_THREAD_H_

// #include "../generated/gui_guider.h"

#define IS_SYSTEM_USE

// typedef enum{
//     CREALITY = 1001,
//     CR_10_H1 = 1002,
//     CR_K1 = 1003,
// }DeviceModel;

typedef enum {
    CONTROL_FILE =              0x01,
    CONTROL_Z_AXIS_OFFSET =     0x02,
    CONTROL_HOT_BED_TEMP =      0x03,
    CONTROL_XYZ_AXIS =          0x04,
    CONTROL_PREPARATEMP =       0x05,
    CONTROL_PARAMETERS =        0x06,
    CONTROL_NETWORKS =          0x07,
    CONTROL_FILAMENT =          0x08,
    CONTROL_LEVEL =             0x09,
    CONTROL_MOTION_PARAMETERS = 0x0a,
    CONTROL_HOME_OFFSET =       0x0b,
    CONTROL_START_PREPARATEMP = 0x0c,
    CONTROL_AUTOPIDSETTINGS =   0x0d,
    CONTROL_PID_PARAMETERS =    0x0e,
    CONTROL_PRINT_STATE =       0x0f,
    CONTROL_PRINT_SPEED =       0x10,
    CONTROL_LANGUAGE =          0x11,
    CONTROL_BED_SIZE =          0x12,
    CONTROL_REPEAT_PRINT_COUNT =0x13,
    CONTROL_MACHINE_PARAMETERS =0x14,
    CONTROL_IOT_QRCODE =        0x15,
    CONTROL_PRINT_FLOW =        0x16,
    CONTROL_AXIS_STATE =        0x17,
    CONTROL_ERROR_MSG =         0x18,
    CONTROL_REBOOT =            0x19,
    CONTROL_UPDATE_MSG =        0x1a,
    CONTROL_MACHINE_STATE =     0x1b,
    CONTROL_MACHINE_LOG =       0x1c,
    CONTROL_CAMERA_OPTIONS =    0x1d,
    CONTROL_POWERLOSS_CMD =     0x1e,
    CONTROL_AI_OPTIONS =        0x1f,
    CONTROL_XYZ_AXIS_RANGE =    0x21
}MessageState;
#define H1_VERTICAL_UI
void set_refresh_data(unsigned char flag);
void get_printer_data(unsigned char flag, unsigned int len, char *data);
void get_response_printer_data(MessageState flag, unsigned int len, char *data);
void set_printer_data(unsigned char flag, unsigned int len, char *data);
void set_response_printer_data(MessageState flag, unsigned int len, char *data);
void send_buzzer(unsigned char flag);
void refresh_zoffset_value();
void refresh_origin_offset_value(unsigned char flag);
void refresh_bright();
void refresh_repeattimes();
void refresh_pla_setting(unsigned char flag);
void refresh_petg_setting(unsigned char flag);
void refresh_self_setting(unsigned char flag);
void refresh_led_powerloss();
void refresh_led_selt_test();
void refresh_led_sound();
void refresh_led_screensave();
void refresh_bed_size(unsigned char flag);
void refresh_auto_level_point();
void refresh_auto_level_model();
void refresh_auto_level_hspeed();
void refresh_language();
void refresh_steps_setting(unsigned char flag);
void refresh_jerk_setting(unsigned char flag);
void refresh_speed_setting(unsigned char flag);
void refresh_acc_setting(unsigned char flag);
void refresh_temp_pid_setting(unsigned char flag);
void refresh_pid_hotend_setting(unsigned char flag);
void refresh_pid_bed_setting(unsigned char flag);
void refresh_axis_motor(unsigned char flag);
void refresh_material();
void refresh_temp(unsigned char flag);
// void refresh_fan();
void refresh_printing_speed();
// void refresh_big_photo();
// void refresh_light();
void refresh_auto_poweroff();
void refresh_material_seneor();
void refresh_printing_time_percent();
void refresh_theme();
// void waittimer_handler(lv_timer_t * timer);

#endif /* EVENT_CB_H_ */
