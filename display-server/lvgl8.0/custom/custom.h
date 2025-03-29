// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/*
 * custom.h
 *
 *  Created on: July 29, 2020
 *      Author: nxf53801
 */

#ifndef __CUSTOM_H_
#define __CUSTOM_H_

#include "../generated/gui_guider.h"
#include "Base/DisplayMsgBase.h"
#include "Message/ServerMessage.h"

// 工厂生产步骤枚举
enum FACTORY_STEPS {
	FACTORY_STEPS_PCBA_DETECT = 101,
};

enum SCR_ID {
	SCR_HOME_PAGE = 0,                  //主页面
	SCR_MOVE_PAGE = 1,                  //移动页面
	SCR_FILES_PAGE = 2,                 //文件页面
	SCR_SETINGS_PAGE = 3,               //设置页面
	SCR_FAQ_PAGE = 4,                   //FAQ页面
    SCR_KEYTONE_PAGE =5,                //按键音设置页面
	SCR_DEVICE_PAGE = 6,                //进退料页面
	SCR_VIDEOLIST_PAGE = 7,             //视频列表界面
	SCR_VIDEOINFO_PAGE = 8,             //视频详情界面
	SCR_EXPORTLOG_PAGE = 9,             //震动补偿界面
	SCR_ABOUTDEVICE_PAGE = 10,          //PID设置页面
	SCR_RESET_PAGE = 11,                //预热设置
	SCR_FILEINFOMATION_PAGE = 12,       //文件详情页面
	SCR_CHANGEPRINTSTATE_PAGE = 13,     //摄像头设置
	SCR_NETINFOMATION_PAGE = 14,        //设备自检
	SCR_PRINTADJUST_PAGE = 15,          //其他设置
	SCR_SELFTEST_PAGE = 16,             //输入页面
	SCR_CAMERASETING_PAGE = 17,            //探头测试页面
//	SCR_MANUALEVELING_PAGE = 18,        //手动调平页面
//	SCR_AUTOLEVELING_PAGE = 19,         //自动调平页面
//	SCR_PROBE_OFFSET_PAGE = 20,         //Z轴补偿页面
//	SCR_PROBETEST_1_PAGE = 21,          //探头伸出、收回、自动测试页面
//	SCR_AUTOLEVELING_1_PAGE = 22,       //自动调平显示页面
//	SCR_SHAKE_OFFSET_1_PAGE = 23,       //震动补偿检测页面
//	SCR_FILEINFOMATION_PAGE = 24,       //文件详细页面
//	SCR_PRINT_PAGE = 25,                //打印页面
//	SCR_PIDSETING_1_PAGE = 26,          //PID自动设置页面
//	SCR_WIFISETING_1_PAGE = 27,         //本地网络详情页面
//	SCR_WIFISETING_2_PAGE = 28,         //无线网络详情页面
//	SCR_STEPS_SETTING_PAGE = 29,
//	SCR_AUTO_LEVEL_POINT_PAGE = 30,
//	SCR_AUTO_LEVEL_DIALOG_PAGE = 31,
//	SCR_AUTO_LEVEL_DATA_PAGE = 32,
//	SCR_ORIGIN_DEVIATION_PAGE = 34,
//	SCR_NETWORK_INFO_PAGE = 35,
//	SCR_WIFI_SELECT_PAGE = 36,
//	SCR_CLOUD_QRCODE_PAGE = 37,
//	SCR_LANGUAGE_PAGE = 38,
//	SCR_SCREEN_SETTING_PAGE = 39,
//	SCR_THEME_COLOR_PAGE = 40,
//	SCR_PRINTER_RELEVANT_PAGE = 41,
//	SCR_SELF_TEST_DIALOG_PAGE = 42,
//	SCR_SELF_TEST_FINDIALOG_PAGE = 43,
//	SCR_ABOUT_PAGE = 44,
};

enum MSG_ID {
	PRINT_FILE = 0,
	PRINTING_PAUSE = 1,
	PRINTING_STOP = 2,
	PRINTING_RESUME = 3,
	PRINT_FINISHED = 4,
	PRINT_NORMAL = 5
};

typedef struct
{
    bool SelftestFlag;      
    bool direction;         //true:Vertical;false:Horizontal
    int  MachineType;
    int  ZAxisForwardMoveDir;//0:正方向 1：负方向
    int  CheckUpdateFlag;    //0:不检查 1：检查
    int  AgreePrivacyPolicy; //0:未同意 1:已同意
    int  ServerOption;       //1:国内   2:国外
}UIInit_t;

#define LV_DEMO_PRINTER_ANIM_TIME  (150)
#define LV_DEMO_PRINTER_ANIM_DELAY  (200)

#define PID_LEN 8

#define MOTION_TEMP_LEN 6   //这个数值必须不小于下面的四个数值
#define STEPS_LEN 6         //最大是999，带两位小数
#define MACC_LEN 5          //最大20000，不带小数
#define MJERK_LEN 5         //最大两位数，带两位小数
#define MSPEED_LEN 4        //四位数，不带小数
#define INPUT_LEN 10        //输入位数限制

#define EDIT_TEMP_LEN 4     //这个数值必须不小于下面的三个数值
#define HOTEND_TEMP_LEN 3
#define BED_TEMP_LEN 3
#define CUR_SPEED_LEN 3
#define REPEAT_TIMES_LEN 2
#define BED_SIZE_LEN 3
#define CAMERA_SIZE_LEN 3

#define OFFSET_LEN 7
#define CUR_POSITION 7
#define MATERIAL_LEN 3
#define PERCENT_LEN 3
#define PRINT_TIME_LEN 6
#define AUTO_POWEROFF_LEN 3
#define ABOUT_INFO_LEN 20
//#define FILE_NAME_LEN 50
#define INPUT_WINDOW_LEN 20

#define FILE_NUM_PRE_PAGE 6
#define HISTORY_NUM_PRE_PAGE 5
#define VIDEO_NUM_PRE_PAGE 5
#define FILE_NUM_SIZE 3

#define FILE_PHOTO_SIZE 256
#define FILE_SIZE 30
#define ESTIME_SIZE 9
#define FILAMENT_SIZE 9
#define LAYER_HEIGHT_SIZE 6
#define VOLUME_SIZE 20
#define FILE_TYPE 1
#define FILESIZE 10
#define FILEDATE 20
#define VERSION_LEN 20

#define AUTO_LEVEL_POINTA "3*3"
#define AUTO_LEVEL_POINTB "4*4"
#define AUTO_LEVEL_POINTC "5*5"
#define AUTO_LEVEL_POINTA_TIME "4min"
#define AUTO_LEVEL_POINTB_TIME "6min"
#define AUTO_LEVEL_POINTC_TIME "12min"
#define AUTO_LEVEL_POINTA_LEN 3
#define AUTO_LEVEL_POINTB_LEN 4
#define AUTO_LEVEL_POINTC_LEN 5

#define REPEAT_TIMES_MIN 0
#define REPEAT_TIMES_MAX 99
#define HOTEND_TEMP_MIN 0
#define HOTEND_TEMP_MAX 260
#define BED_TEMP_MIN 0
#define BED_TEMP_MAX 100
#define BED_SIZE_X_MIN 0
#define BED_SIZE_X_MAX 200
#define BED_SIZE_Y_MIN 0
#define BED_SIZE_Y_MAX 200
#define STEPS_PER_MM_MIN 0
#define STEPS_PER_MM_MAX 999
#define STEPS_JERK_MIN 0
#define STEPS_JERK_MAX 99
#define STEPS_SPEED_MIN 0
#define STEPS_SPEED_MAX 9999
#define STEPS_ACC_MIN 0
#define STEPS_ACC_MAX 20000
#define TEMP_PID_MIN -9999
#define TEMP_PID_MAX 9999
#define MATERIAL_MIN 0
#define MATERIAL_MAX 999
#define PRINT_SPEED_MIN 10
#define PRINT_SPEED_MAX 500
#define SLEFTEST_COUNT 7

#define WIFI_NAME_LEN 32

struct display_file_info
{
    char name[FILE_SIZE+1];
    char photo[FILE_PHOTO_SIZE+1];
    char estime[ESTIME_SIZE+1];
    char filament[FILAMENT_SIZE+1];
    char layer_heigh[LAYER_HEIGHT_SIZE+1];
    char volume[VOLUME_SIZE+1];
    char filetype[FILE_TYPE+1];
    char filesize[FILESIZE+1];
    char filedate[FILEDATE+1];
};

struct history_file_info
{
    char name[FILE_SIZE+1];
    char photo[FILE_PHOTO_SIZE+1];
    char history_printtime[FILE_SIZE];
    char length_of_time[FILAMENT_SIZE+1];
    char print_result[FILE_TYPE+1];
    char file_state[FILE_TYPE+1];
};

struct video_info
{
    char name[FILE_PHOTO_SIZE+1];
    char print_time[FILE_SIZE];
    char length_of_time[FILE_SIZE];
    char length_of_video[FILE_SIZE];
    char photo_position[FILAMENT_SIZE];
    char photo_freq[FILAMENT_SIZE];
    char render_mode[FILAMENT_SIZE];
    char photo[FILE_PHOTO_SIZE+1];
};
typedef struct HistoryInfo{
    char filename[64];
    char bedtemp[10];
    char nozzletemp[10];
    char timecost[64];
    char consumables[32];
    char preview[256];
    char index[10];
    char filamenttype[32];
}HistoryInfo_t;
typedef struct AIConfigState{
    int AI_state;
    int FaultDetection_state;
    int FaultToPause_state;
    int FirstLayerDetection_state;
    int FlowCalibrationState;
    AiModeType AiMode;
    int AiCheckTime;
}AIConfigState_t;
typedef struct SysConInfo{
    bool Udisk_state;
    bool PreStartprint_state;
    int Camera_model_state;
    int Camera_nozzle_state;
    int light_value;
    int Klipper_state;
    int throat_fan_speed;
    int board_fan_speed;
    int Fanfeedback;
    int CxyUserInfoState;
    int Laser_state;
    int Mqtt_state;
    int X_Axis_Min;
    int X_Axis_Max;
    int Y_Axis_Min;
    int Y_Axis_Max;
    int Z_Axis_Min;
    int Z_Axis_Max;
    int FilamentSensor_state;
    bool IsAgreeSharePicture;
}SysConInfo_t;

typedef struct MachineInfo{
    char MachineType[32];
    char HardwareVersion[32];
    char FirmwareVersion[32];
    char ScreenVersion[32];
    char PrintedTime[64];
    char MacValue[64];
    char CrealityUrl[64];
    char TotalDiskCapacity[64];
    char UsedDiskCapacity[64];
    char MachineName[64];
}MachineInfo_t;

typedef struct CloudUserInfo{
    char UserName[64];
    char UserID[64];
    char UserImg[256];
}CloudUserInfo_t;

extern int cur_scr;
extern int pre_scr;
extern bool refreshflag_settingpage;
//extern char *file_names;
extern lv_anim_t ani_en_btn_click;
extern unsigned int tick_start;
extern unsigned int print_file_pages;
extern unsigned int historyfile_pages;
extern unsigned int print_total_files;
extern unsigned int history_total_files;
extern int input_min;
extern int input_max;
extern lv_obj_t *input_label;
extern int input_type;

extern char edit_temp[EDIT_TEMP_LEN];
extern char edit_pid_temp[PID_LEN];
extern char edit_motion[MOTION_TEMP_LEN];
extern char hotend_max_temp[HOTEND_TEMP_LEN+1];
extern char hotend_cur_temp[HOTEND_TEMP_LEN+1];
extern char bed_max_temp[BED_TEMP_LEN+1];
extern char bed_cur_temp[BED_TEMP_LEN+1];
extern char chassis_temp[BED_TEMP_LEN+1];
extern char origin_xoffset_value[OFFSET_LEN+1];
extern char origin_yoffset_value[OFFSET_LEN+1];
extern char origin_zoffset_value[OFFSET_LEN+1];
extern char zoffset_value[OFFSET_LEN+1];
extern char zoffsetmovelen;
extern char cur_speed[CUR_SPEED_LEN+1];
extern char speedchangetype;
extern char speedflowchangetype;
extern char cur_printflow[CUR_SPEED_LEN+1];
extern char cur_xposition[CUR_POSITION+1];
extern char cur_yposition[CUR_POSITION+1];
extern char cur_zposition[CUR_POSITION+1];
extern bool fan_state;
extern bool light_state;
extern unsigned int cur_language;
extern char xSTEPS[STEPS_LEN+1];
extern char ySTEPS[STEPS_LEN+1];
extern char zSTEPS[STEPS_LEN+1];
extern char eSTEPS[STEPS_LEN+1];
extern char xmacc[MACC_LEN+1];
extern char ymacc[MACC_LEN+1];
extern char zmacc[MACC_LEN+1];
extern char emacc[MACC_LEN+1];
extern char xjerk[MJERK_LEN+1];
extern char yjerk[MJERK_LEN+1];
extern char zjerk[MJERK_LEN+1];
extern char ejerk[MJERK_LEN+1];
extern char xmspeed[MSPEED_LEN+1];
extern char ymspeed[MSPEED_LEN+1];
extern char zmspeed[MSPEED_LEN+1];
extern char emspeed[MSPEED_LEN+1];
extern char hotend_pid_p[PID_LEN+1];
extern char hotend_pid_i[PID_LEN+1];
extern char hotend_pid_d[PID_LEN+1];
extern char bed_pid_p[PID_LEN+1];
extern char bed_pid_i[PID_LEN+1];
extern char bed_pid_d[PID_LEN+1];
extern char PLA_preheat_hotend[HOTEND_TEMP_LEN+1];
extern char PLA_preheat_bed[BED_TEMP_LEN+1];
extern char ABS_preheat_hotend[HOTEND_TEMP_LEN+1];
extern char ABS_preheat_bed[BED_TEMP_LEN+1];
extern char self_preheat_hotend[HOTEND_TEMP_LEN+1];
extern char self_preheat_bed[BED_TEMP_LEN+1];
//extern char auto_poweroff[AUTO_POWEROFF_LEN+1];
extern char machine_type_value[ABOUT_INFO_LEN+1];
extern char hardware_ver_value[ABOUT_INFO_LEN+1];
extern char fireware_ver_value[ABOUT_INFO_LEN+1];
extern char screen_ver_value[ABOUT_INFO_LEN+1];
extern char total_time_value[ABOUT_INFO_LEN+1];
extern char mac_value[ABOUT_INFO_LEN+1];
extern char official_web_value[ABOUT_INFO_LEN+1];
extern char bed_size_x[BED_SIZE_LEN+1];
extern char bed_size_y[BED_SIZE_LEN+1];
extern char pid_hotend_tar[HOTEND_TEMP_LEN+1];
extern char pid_hotend_times[REPEAT_TIMES_LEN+1];
extern char pid_bed_tar[BED_TEMP_LEN+1];
extern char pid_bed_times[REPEAT_TIMES_LEN+1];
extern bool post_state;
extern bool powerloss_state;
extern unsigned char repeat_print_times;
extern char repeat_times[REPEAT_TIMES_LEN+1];
extern bool sound_state;
extern char sound_value[3];
extern char sound_type;
extern bool fullscreen_mode_state;
extern char screen_save_value[3];
extern char bright_value[3];
extern bool level_high_speed_level;
extern char level_point_value;
extern char point_num;
extern char level_auto_model_value;
extern bool auto_poweroff;
extern char material_seneor;
extern unsigned char theme_model_id;
extern char manuallevel_count;
extern char errorcode[10];
extern char k1_errorcode[10];
extern bool current_error;
extern bool current_tips;

extern unsigned int current_page;
extern unsigned int history_current_page;
extern unsigned int videolist_pages;
extern unsigned int videolist_total_files;
extern unsigned int videolist_current_page;
extern int videolist_clientnum;
extern char axis_move_uint;
extern char offset_move_uint;
extern bool motor_loss_state;
extern char material_in_length[MATERIAL_LEN+1];
extern char material_out_length[MATERIAL_LEN+1];
extern char extruderspeed;
extern char movelenthtype;
extern char material_temp[MATERIAL_LEN+1];
extern char input_bed_temp[MATERIAL_LEN+1];
extern char input_hotend_temp[MATERIAL_LEN+1];
extern char input_feed_temp[MATERIAL_LEN+1];
extern char input_flow_temp[MATERIAL_LEN+1];
extern char input_pretemphot_temp[MATERIAL_LEN+1];
extern char current_version[VERSION_LEN+1];
extern char version_flag;                       //升级状态
extern char upgrade_progress[MATERIAL_LEN];     //升级进度
extern char new_version[VERSION_LEN+1];
extern char version_size[VERSION_LEN+1];
extern bool input_hotendtemp_flag;
extern bool input_bedtemp_flag;
extern char input_pidseting[6];
extern char input_piddate[6];
extern bool input_pidhot_p_flag;
extern bool input_pidhot_i_flag;
extern bool input_pidhot_d_flag;
extern bool input_pidbed_p_flag;
extern bool input_pidbed_i_flag;
extern bool input_pidbed_d_flag;
extern bool autopidtype_flag;
extern bool input_printhottemp_flag;
extern bool input_printbedtemp_flag;
extern bool input_printfeed_flag;
extern bool input_printzoffset_flag;
extern bool input_printflow_flag;
extern int input_autopidhottemp_flag;
extern int input_autopidhotcount_flag;
extern int input_autopidbedtemp_flag;
extern int input_autopidbedcount_flag;
extern bool printpage_pause_flag;
extern bool input_pretemphot_flag;

extern char changeflag_probetest;
extern char autolevelingflag;
extern char probe_offsetlenth;
extern bool shake_sensor_state;
extern char filesort_type;

extern char printing_file_name[FILE_SIZE+1];
extern int clicked_file_num;
extern int history_clientnum;
extern char print_percent[PERCENT_LEN+2];
extern char print_remain_time[PRINT_TIME_LEN+1];
extern char print_printed_time[PRINT_TIME_LEN+1];

extern unsigned char led_on_r_color;
extern unsigned char led_on_g_color;
extern unsigned char led_on_b_color;
extern unsigned char led_off_r_color;
extern unsigned char led_off_g_color;
extern unsigned char led_off_b_color;

extern int model_start_pix;
extern int model_end_pix;
extern char big_photo_name[FILE_PHOTO_SIZE+1];
extern struct display_file_info dis_file_info[FILE_NUM_PRE_PAGE];
extern struct history_file_info history_file_list[HISTORY_NUM_PRE_PAGE];
extern struct video_info video_file_list[VIDEO_NUM_PRE_PAGE];

extern char qrcode_name[FILE_PHOTO_SIZE+1];     //创想云二维码

extern bool refresh_hotend_temp;
extern bool refresh_bed_temp;
extern bool refresh_pla_hotend_temp;
extern bool refresh_pla_bed_temp;
extern bool refresh_petg_hotend_temp;
extern bool refresh_petg_bed_temp;
extern bool refresh_self_hotend_temp;
extern bool refresh_self_bed_temp;
extern bool refresh_zoffset;
extern bool refresh_preheat_hotend;
extern bool refresh_preheat_bed;
extern bool refresh_pid_hotend_p;
extern bool refresh_pid_hotend_i;
extern bool refresh_pid_hotend_d;
extern bool refresh_pid_bed_p;
extern bool refresh_pid_bed_i;
extern bool refresh_pid_bed_d;
extern bool refresh_steps_x;
extern bool refresh_steps_y;
extern bool refresh_steps_z;
extern bool refresh_steps_e;
extern bool refresh_macc_x;
extern bool refresh_macc_y;
extern bool refresh_macc_z;
extern bool refresh_macc_e;
extern bool refresh_jerk_x;
extern bool refresh_jerk_y;
extern bool refresh_jerk_z;
extern bool refresh_jerk_e;
extern bool refresh_mspeed_x;
extern bool refresh_mspeed_y;
extern bool refresh_mspeed_z;
extern bool refresh_mspeed_e;
extern bool refresh_print_speed;
extern bool print_file_ok;
extern bool refresh_repeat_times;
extern bool refresh_bed_size_x;
extern bool refresh_bed_size_y;
extern bool refresh_pid_hotend_tar;
extern bool refresh_pid_hotend_times;
extern bool refresh_pid_bed_tar;
extern bool refresh_pid_bed_times;
extern bool refresh_material_in;
extern bool refresh_material_out;
extern bool rebootflag;

extern int msg_id;
extern int print_state;
extern int auto_pid_progress;
extern int auto_level_progress;

extern lv_chart_series_t * ser_h_hotend;
extern lv_chart_series_t * ser_h_bed;
extern lv_chart_series_t * pid_temp;
extern char selftest_result[SLEFTEST_COUNT];
extern bool selftest_flag;
extern lv_timer_t * mytimer;
extern lv_timer_t * mytimer_1;
extern lv_timer_t * mytimer_2;
extern lv_timer_t * mytimer_3;
extern lv_timer_t * wait_timer;
extern bool connectwifi_state;
extern uint32_t timer_user_data;
extern char level_point_value_flag;

extern char wifi_state;
extern char wifi_name[WIFI_NAME_LEN+1];
extern char wifi_ip[16];
extern char wifi_signal_level[16];
extern char wire_net_state;
extern char wire_net_ip[16];
extern char wire_gateway[20];
extern char wire_subnet_mask[20];
extern char wire_dns[20];
extern char exchange_wifi_name[WIFI_NAME_LEN+1];        //用于弹出窗口做数据交换和判断的数据
extern unsigned char exchange_wifi_state;              //用于弹出窗口做数据交换和判断的数据

extern lv_timer_t * plugin_material_task;               //插入耗材的动画任务
extern char manualtest[11];
extern char manualtestlength;
extern char manualtest_curpage;

extern bool screen_rotate;                              //false是横屏，true是竖屏
extern bool selftestflag;                               //是否开机自检，false不自检
extern int manualtestcount;
extern int UIType;
extern bool IsK1MaxSe;
extern bool IsK1C;
extern int CheckUpdataFlag;
extern lv_obj_t *list_btn;
/******延时摄影参数设置*********/
extern bool isopencamera;   //是否开启延时摄影1：打开0：关闭
extern bool cameraposition; //喷嘴位置1：移开0：不移开
extern char picturelayers[CAMERA_SIZE_LEN+1];  //拍照频率
extern char Render_mode[CAMERA_SIZE_LEN+1];    //渲染帧数数值
/******延时摄影参数设置*********/

/*****运动轴状态*********/
extern bool x_state;
extern bool y_state;
extern bool z_state;
/******运动轴状态*********/
extern SysConInfo_t system_state;
extern AIConfigState_t ai_state;
extern MachineInfo_t machineinfo;
extern CloudUserInfo_t cxyUserinfo;
extern UIInit_t init_uiconfiginfo;
void msgbox(char *msg);
void print_main_init(void);
void print_file_init(void);
void print_preview_init(void);
void print_printing_init(void);
void print_dialog_init(void);
void print_setting_init(void);
void msgbox_init(void);
void zoffset_init();
void prepare_main_init();
void prepare_axis_init();
void prepare_material_init();
void prepare_manual_temp_init();
void level_auto_init();
void level_manual_init();
void manual_pid_init();
void auto_pid_hotend_init();
void auto_pid_bed_init();
void temp_curve_init();
void max_acc_setting_init();
void max_speed_setting_init();
void max_jerk_setting_init();
void steps_setting_init();
void language_init();
void self_test_dialog_init();
void auto_level_point_init();
void auto_level_dialog_init();
void auto_level_data_init();
void auto_level_test_init();
void bed_size_init();
void material_useless_init();
void material_changed_init();
void plugin_u_init();
void screen_setting_init();
void theme_color_init();
void origin_deviation_init();
void pla_setting_init();
void self_setting_init();
void petg_setting_init();
void about_init();
void feedback_init();
void undeveloping_init();
void temp_abnormal_init();
void plugin_material_init();
void factory_dialog_init();
void self_test_findialog_init();
void self_testing_init();
void self_test_result_init();
void inputboard_init();
void network_info_init();
void wifi_select_init();
void cloud_qrcode_init();
void setting_main_init();
void printer_relevant_init();

void custom_init(lv_ui *ui);
void guider_load_screen(int scr_id);
void lv_demo_printer_anim_in_all(lv_obj_t * obj, uint32_t delay);
void file_list_btn_event_handler(lv_obj_t * obj, lv_event_t event);
void set_print_file_nums(void);
void handle_file();
void handle_video_file();

bool check_time(void);
void ReportMESQrcode(int id, json_object *result, char *describe);
void mymsgbox(char *msg);
void mymsgbox_two(char *msg);
void keyboardinput(char *msg,lv_obj_t *label_text,int *inputmax,int *inputmin,int type);
void stack_preheating(unsigned char preheating);
void stack_input(int scr_id,unsigned char shield,unsigned char nums,char *cur_dt,int nmin,int nmax);
void handle_input(char chr);
void set_screen_vertical(bool flag);
void UI_Init(UIInit_t init_ui);
bool isFactoryTest(void);
bool isMachineTest(void);
#endif /* EVENT_CB_H_ */
