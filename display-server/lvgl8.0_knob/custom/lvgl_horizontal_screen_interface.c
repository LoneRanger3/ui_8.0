#include "lvgl_horizontal_screen_interface.h"
#include "k1_horizontal_ui/ui_screen_AxisMove.h"
#include "k1_horizontal_ui/ui_screen_Adjustment.h"
#include "k1_horizontal_ui/ui_screen_HomeNormal.h"
#include "k1_horizontal_ui/ui_screen_HomePrinting.h"
#include "k1_horizontal_ui/ui_screen_FullScreen.h"
#include "k1_horizontal_ui/ui_screen_FileManage.h"
#include "k1_horizontal_ui/ui_screen_Preview.h"
#include "CrlogDef.h"
#include "k1_horizontal_ui/ui_screen_camera_settings.h"
#include "k1_horizontal_ui/ui_Screen_CustomerService.h"
#include "k1_horizontal_ui/mult_language.h"
#include "k1_horizontal_ui/ui_Screen_SelftestTips.h"
#include "k1_horizontal_ui/ui_screen_cool.h"
#include "k1_horizontal_ui/ui_screen_DetectionAI.h"

/*********************home page******************/
void set_hotend_temper(int16_t curTemper, int16_t targetTemper)
{
    //CrLogI("start set_hotend_temper %d, target %d", curTemper, targetTemper);
    home_printing_set_hotend_temper(curTemper, targetTemper);
    home_normal_set_hotend_temper(curTemper, targetTemper);
    axis_move_set_hotend_temper(curTemper, targetTemper);
    // filament_set_hotend_temper(curTemper, targetTemper);
    // axis_move_filament_set_hotend_temper(curTemper, targetTemper);
    //CrLogI("end set_hotend_temper");
}

void set_bed_temper(int16_t curTemper, int16_t targetTemper)
{
    //CrLogI("start set_bed_temper %d, target temper %d", curTemper, targetTemper);
    home_printing_set_bed_temper(curTemper, targetTemper);
    home_normal_set_bed_temper(curTemper, targetTemper);
    axis_move_set_bed_temper(curTemper, targetTemper);
    //CrLogI("start set_bed_temper %d", targetTemper);
}

void set_chassis_temper(int16_t curTemper)
{
    axis_move_set_chassis_temper(curTemper);
}

void set_fans_status(uint8_t model_fan_duty_percent, 
        uint8_t auxiliary_fan_duty_percent,uint8_t chassis_fan_duty_percent)
{
    bool open = false;
    if ( model_fan_duty_percent > 0 || auxiliary_fan_duty_percent > 0 || chassis_fan_duty_percent > 0)
        open = true;

    CrLogI("start set_fan_status %d", open);
    home_printing_set_fan_status(open);
    home_normal_set_fan_status(open);
    //axis_move_set_fan_status(open);
    CrLogI("end set_fan_status");
    // cool_set_model_fan_duty_percent(model_fan_duty_percent);
    // cool_set_cool_fan_duty_percent(auxiliary_fan_duty_percent);
    // cool_set_Chassis_fan_duty_percent(chassis_fan_duty_percent);
    // CoolSubPage_set_model_fan_duty_percent(model_fan_duty_percent);
    axis_move_set_model_fan_duty_percent(model_fan_duty_percent);
    //refresh_fan_value(model_fan_duty_percent);
 


}

void set_light_status(bool open)
{
    CrLogI("start set_light_status %d", open);
    home_printing_set_light_status(open);
    home_normal_set_light_status(open);
    CrLogI("end set_light_status");
}

void set_wifi_status(int intensity)
{
    CrLogI("start set_wifi_status %d", intensity);
    home_printing_set_wifi_status(intensity);
    home_normal_set_wifi_status(intensity);
    axismove_page_set_wifi_status(intensity);
    settings_page_set_wifi_status(intensity);
    filemanage_page_set_wifi_status(intensity);
    service_page_set_wifi_status(intensity);
    CrLogI("end set_wifi_status");
}

void set_print_proccess_info(int32_t used_time, int32_t left_time, int8_t proccess)
{
    CrLogI("start set_print_proccess_info %d", used_time);
    home_printing_set_print_proccess_info(used_time, left_time, proccess);
    full_screen_set_print_proccess(proccess);
    CrLogI("end set_print_proccess_info");
}

void set_print_proccess_layers_info(uint32_t layer_count, uint32_t cur_layer_index)
{
    home_printing_set_gcode_layers_count(layer_count);
    full_screen_set_gcode_layers_count(layer_count);

    home_printing_set_gcode_cur_layer_index(cur_layer_index);
    full_screen_set_gcode_cur_layer_index(cur_layer_index);   
}

void set_print_file_name(char *file_name)
{
    CrLogI("start set_print_file_name %p", file_name);
    home_printing_set_print_file_name(file_name);
    CrLogI("ebd set_print_file_name");
}

void set_filling_chart_info(char *chart_name, uint16_t pixel_start, 
                                          uint16_t pixel_end, float model_height,float model_layer_height)
{
    CrLogI("start set_filling_chart_info %p", chart_name);
    // home_printing_set_filling_chart_name(chart_name, pixel_start, pixel_end, model_height, model_layer_height);
    preview_set_filling_chart_info(chart_name, pixel_start, pixel_end, model_height, model_layer_height);
    full_screen_set_Filling_chart(chart_name);
    CrLogI("end set_filling_chart_info ");
}

// 0: normal, 1:printing, 2:paused, 3:stoped,4:finished.
void set_printing_status(int status)
{
    CrLogI("start set_printing_status %d", status);
    home_printing_set_printing_status(status);
    axis_move_set_print_status(status);
    adjustment_set_print_status(status);
    // home_normal_set_print_status(status);
    // filament_set_print_status(status);
    axis_move_filament_set_print_status(status);
    CrLogI("end set_printing_status");
}

void set_powerloss_recovery_info(int state)
{
    CrLogI("start set_powerloss_recovery_info");
    home_printing_set_powerloss_recovery_info(state);
    CrLogI("end set_powerloss_recovery_info ");
}

void set_filament_runout(bool filamen_runout)
{
    home_printing_set_filament_runout(filamen_runout);
    //change_filamentsensor_state(filamen_runout); //TODO:主页增加断料检测图标和静音图标预留
   // change_filamentsensor_normalpage(filamen_runout);
}

void set_home_status(bool x_home_flag, bool y_home_flag, bool z_home_flag)
{
    if ( x_home_flag && y_home_flag && z_home_flag )
        home_printing_set_home_status(false);
    else
        home_printing_set_home_status(true);

    axis_move_set_home_status(x_home_flag, y_home_flag, z_home_flag);
}

void set_homing_status(uint8_t homing_status)
{
    axis_move_set_homing_status(homing_status);
}

/*****************move and adjust**********************/
void set_offset_z(float offset_z)
{
    adjustment_set_offset_z(offset_z);
}

void set_speed_percent(int percent)
{
    adjustment_set_speed_percent(percent);
}

void set_flow_percent(int percent)
{
    adjustment_set_flow_percent(percent);
}

void set_in_or_out_filamnet_state(enum FILAMENT_ACTION_STATE state)
{
    //filament_set_filament_action_state(state);
    axis_move_filament_set_filament_action_state(state);
}


/*****************file manage , sub dir , preview and history**************************************/
void set_files_count(int count)
{
    file_manage_set_files_count(count);
}

void set_file_infos(Dirent_Info_t dirent_array[8], int real_count)
{
    file_manage_set_file_infos(dirent_array, real_count);
}

void set_print_record_info(print_record_info_t record_arry[3], int real_record_count)
{
    file_manage_set_print_record_info(record_arry, real_record_count);
}

void set_print_record_count(int count)
{
     file_manage_set_print_record_count(count);
}

void set_u_disk_status(bool inserted)
{
    file_manage_set_u_disk_status(inserted);
}


/************************full screen*****************************/
void set_full_screen_display_status(bool open_full_screen)
{
    full_screen_set_display_status(open_full_screen);
}


void set_screen_off_status(bool screen_off)
{
    enter_screenoff_mode(lv_scr_act());
}

/**********************************************/

#define HORIZONTAL_SCREEN_PAGE_MAX_FILE_COUNT 8
void analyze_files_info_respone(char *data, uint16_t data_len)
{
    print_file_ok = true;
    if ( data_len == 0 || !data )
    {
        set_file_infos(NULL, 0);

        return ;
    }

    char file_num = 0;
    unsigned char cnt  = 0;
    unsigned char data_flag;

    // data++;
    char *temp = strtok(data,"\t");
    //struct display_file_info dis_file_info[HORIZONTAL_SCREEN_PAGE_MAX_FILE_COUNT] = {0};
    char buff[257] = {0};
    Dirent_Info_t  dirent_array[HORIZONTAL_SCREEN_PAGE_MAX_FILE_COUNT] = {0};
    while(temp)
    {
        file_num++;
        if(file_num > HORIZONTAL_SCREEN_PAGE_MAX_FILE_COUNT)
        {
            break;
        }

        cnt = 0;
        data_flag = 0;
        memset(buff, 0, sizeof(buff));

        while(*temp)
        {
            if(*temp == '\0')
            {
                break;
            }

            if(*temp == ':')
            {
                switch(data_flag)
                {
                    case 0:
                        strncpy(dirent_array[file_num - 1].name, buff, sizeof(dirent_array[file_num - 1].name) - 1);
                        break;
                    case 1:
                        strncpy(dirent_array[file_num - 1].mode_thumbnail, buff, sizeof(dirent_array[file_num - 1].mode_thumbnail) - 1);
                        break;
                    case 2:
                        dirent_array[file_num - 1].totle_time = atoi(buff);
                        break;
                    case 3:
                        dirent_array[file_num - 1].mater_used = atoi(buff);

                        break;
                    case 4:
                        //dirent_array[file_num - 1].layer_heigh[cnt] = '\0';
                        break;
                    case 5:
                        //dis_file_info[file_num - 1].volume[cnt] = '\0';
                        break;
                    case 6:
                        //dis_file_info[file_num - 1].filetype[cnt] = '\0';
                        dirent_array[file_num - 1].is_dir = buff[0] == '0' ? true : false;
                        break;
                    case 7:
                        //dis_file_info[file_num - 1].filesize[cnt] = '\0';
                        break;
                    case 8:
                        //dis_file_info[file_num - 1].filedate[cnt] = '\0';
                        dirent_array[file_num - 1].dir_create_time = atol(buff);
                        break;
                    case 9:
                        strncpy(dirent_array[file_num - 1].filament_type, buff, sizeof(dirent_array[file_num - 1].filament_type) - 1);
                        break;
                    case 10:
                        dirent_array[file_num - 1].nozzle_temp = atoi(buff);
                        break;
                    case 11:
                        dirent_array[file_num - 1].bed_temp = atoi(buff);
                        break;
                }
                data_flag++;
                temp++;
                cnt = 0;
                memset(buff, 0, sizeof(buff));
                continue;
            }

            buff[cnt++] = *temp;
            temp++;
        }
        temp = strtok(NULL,"\t");
    }

    if ( file_num >  PAGE_MAX_DIRENT_COUNT)
        file_num = PAGE_MAX_DIRENT_COUNT;
    for(int i = 0; i < PAGE_MAX_DIRENT_COUNT; i++)
    {
        CrLogI("the %d file content: hottemp:%d, bedtemp:%d, totletime:%d, filename:%s, imgsrc:%s, used:%d, filetype:%d, filamenttype:%s, dir_create_time:%d",
        i, dirent_array[i].nozzle_temp, dirent_array[i].bed_temp, dirent_array[i].totle_time,dirent_array[i].name,
        dirent_array[i].mode_thumbnail, dirent_array[i].mater_used, dirent_array[i].is_dir, dirent_array[i].filament_type,
        dirent_array[i].dir_create_time);
    }
    set_file_infos(dirent_array, file_num);
}

void analyze_filling_chart_info_respone(char *data, uint16_t data_len)
{
    unsigned char data_flag = 0,i=0,lenth = 0;
    char tempdataa[10] = {'\0'};
    char tempdatab[10] = {'\0'};
    char tempdatac[10] = {'\0'};
    char tempdatad[10] = {'\0'};

    char filling_chart_name[257] = {0};

    if ( data_len < 3  || !data )
    {
        model_start_pix = 2;
        model_end_pix = 298;
        //filling_chart_name[0] = '\0';

        set_filling_chart_info(filling_chart_name, model_start_pix, model_end_pix, 0.0f, 0.0f);
        return ;
    }

    char *temp = data;
    while(*temp)
    {
        lenth++;
        if(*temp == '\0' || lenth > data_len)
        {
            break;
        }
        if(*temp == '\t')
        {
            data_flag++;
            temp++;
            i = 0;
            continue;
        }

        switch(data_flag)
        {
            case 0:
            {
                if ( (sizeof(tempdataa) - 1 ) > i )
                    tempdataa[i++] = *temp++;
                
                break;
            }
            case 1:
            {
                if ( (sizeof(tempdatab) - 1 ) > i )
                    tempdatab[i++] = *temp++;
                    
                break;
            }
            case 2:
            {
                if ( (sizeof(tempdatac) - 1 ) > i )
                    tempdatac[i++] = *temp++;
                
                break;
            }
            case 3:
            {
                if ( (sizeof(tempdatad) - 1 ) > i )
                    tempdatad[i++] = *temp++;
                
                break;
            }
            case 4:
            {
                if ( (sizeof(filling_chart_name) - 1 ) > i )
                    filling_chart_name[i++] = *temp++;
                
                break;
            }
        }
    }
    filling_chart_name[i] = '\0';
    // CrLogI("(big_photo_name %s)",big_photo_name);
    // CrLogI("(tempdataa is %s)",tempdataa);
    // CrLogI("(tempdatab is %s)",tempdatab);
    // CrLogI("(tempdatac is %s)",tempdatac);
    // CrLogI("(tempdatad is %s)",tempdatad);

    model_start_pix = atof(tempdataa);
    model_end_pix   = atof(tempdatab);

    set_filling_chart_info(filling_chart_name, model_start_pix, model_end_pix, atof(tempdatac), atof(tempdatad));
}

#define HOR_SCREEN_HISTORY_NUM_PRE_PAGE 3
void analyze_print_records_info_respone(char *data, uint16_t data_len)
{
    if ( data_len == 0 || !data)
    {
        set_print_record_info(NULL, 0);
        return ;
    }

    char histtory_filecount = 0;    //打印历史记录数量
    unsigned char cnt  = 0;
    unsigned char data_flag;       //当前解析的数据标志(第几个什么内容)


    // CrLogI("history list is :%s.",data);
    char *temp = strtok(data,"\t");
    char buff[257] = {0};
    print_record_info_t records_array[HOR_SCREEN_HISTORY_NUM_PRE_PAGE] = {0};
    //memset(history_file_list,'\0',sizeof(history_file_list));
    while(temp)
    {
        histtory_filecount++;
        if(histtory_filecount > HOR_SCREEN_HISTORY_NUM_PRE_PAGE)
        {
            break;
        }

        cnt = 0;
        data_flag = 0;

        while(*temp)
        {
            if(*temp == '\0')
                break;

            if(*temp == ':')
            {
                switch(data_flag)
                {
                        case 0:
                            {
                                strncpy(records_array[histtory_filecount - 1].file_name, buff, sizeof(records_array[histtory_filecount - 1].file_name) - 1);
                            }
                            break;
                        case 1:
                            {
                                strncpy(records_array[histtory_filecount - 1].thumbnail_name, buff, sizeof(records_array[histtory_filecount - 1].thumbnail_name) -1);
                            }
                            break;
                        case 2:records_array[histtory_filecount - 1].start_time = atol(buff);break;
                        case 3:records_array[histtory_filecount - 1].print_used_time  = atoi(buff);break;
                        case 4:records_array[histtory_filecount - 1].state_ok = buff[0] == '1' ? true : false;break;
                        case 5:records_array[histtory_filecount - 1].file_exsit = buff[0] == '1' ? true : false;break;
                }
                data_flag++;
                temp++;
                cnt = 0;
                memset(buff, 0, sizeof(buff));
                continue;
            }
#if 0
            switch(data_flag)
            {
                    case 0:if(cnt < FILE_SIZE)history_file_list[histtory_filecount - 1].name[cnt++] = *temp;break;
                    case 1:if(cnt < FILE_PHOTO_SIZE)history_file_list[histtory_filecount - 1].photo[cnt++] = *temp;break;
                    case 2:if(cnt < FILE_SIZE)history_file_list[histtory_filecount - 1].history_printtime[cnt++] = *temp;break;
                    case 3:if(cnt < FILAMENT_SIZE)history_file_list[histtory_filecount - 1].length_of_time[cnt++] = *temp;break;
                    case 4:if(cnt < FILE_TYPE)history_file_list[histtory_filecount - 1].print_result[cnt++] = *temp;break;
                    case 5:if(cnt < FILE_TYPE)history_file_list[histtory_filecount - 1].file_state[cnt++] = *temp;break;
            }
#else
            if(cnt < FILE_PHOTO_SIZE)
                buff[cnt++] = *temp;
#endif
            temp++;
        }

        temp = strtok(NULL,"\t");
    }

    if ( histtory_filecount >  HOR_SCREEN_HISTORY_NUM_PRE_PAGE )
        histtory_filecount =  HOR_SCREEN_HISTORY_NUM_PRE_PAGE;

    set_print_record_info(records_array, histtory_filecount);
}

void set_vedioes_count(int count)
{
    cameralist_set_vedio_count(count);
}

void set_vedioes_info(print_vedio_info_t info_array[3], int real_count)
{
    cameralist_set_vedioes_info(info_array, real_count);
}

void analyze_vedioes_info_respone(char *data, uint16_t data_len)
{
//    print_file_ok = true;
    int count = 0;
    print_vedio_info_t info_array[VIDEO_NUM_PRE_PAGE] = {0};
    if(data_len == 0)
    {
        count = 0;
    }
    else
    {
        char videolist_filecount = 0;    //打印历史记录数量
        unsigned char cnt  = 0;
        unsigned char data_flag;       //当前解析的数据标志(第几个什么内容)

        CrLogI("video list is :%s.",data);
        char *temp = strtok(data,"\t");
        while(temp)
        {
            count++;
            if(count > VIDEO_NUM_PRE_PAGE)
            {
                break;
            }

            cnt = 0;
            data_flag = 0;
            char buff[256] = {0};

            while(*temp)
            {
                if(*temp == '\0')
                    break;

                if(*temp == ':')
                {
                    switch(data_flag)
                    {
                        case 0:strcpy(info_array[count - 1].vedio_name, buff );break;
                        case 1:info_array[count - 1].print_datetime = atol(buff);break;
                        case 2:info_array[count - 1].used_time = atoi(buff);break;
                        case 3:info_array[count - 1].vedio_total_time = atoi(buff);break;
                        case 4:info_array[count - 1].shoot_pos = buff[0] - '0';break;
                        case 5:info_array[count - 1].shoot_freq = atoi(buff);break;
                        case 6:info_array[count - 1].render_photoes = atoi(buff);break;
                        case 7:strcpy(info_array[count - 1].vedio_img_name, buff);break;
                    }
                    data_flag++;
                    temp++;
                    cnt = 0;
                    memset(buff, 0, sizeof(buff));
                    continue;
                }

                if ( cnt < (sizeof(buff) - 1) )
                    buff[cnt++] = *temp;

                temp++;
            }
            temp = strtok(NULL,"\t");
        }
    }
    for(int i = 0; i < 3; i++)
    {
        CrLogI("vedio_name :%s",info_array[i].vedio_name);
        CrLogI("vedio_img_name :%s",info_array[i].vedio_img_name);
        CrLogI("print_datetime :%d",info_array[i].print_datetime);
        CrLogI("render_photoes :%d",info_array[i].render_photoes);
        CrLogI("shoot_freq :%d",info_array[i].shoot_freq);
        CrLogI("shoot_pos :%d",info_array[i].shoot_pos);
        CrLogI("used_time :%d",info_array[i].used_time);
        CrLogI("vedio_total_time :%d",info_array[i].vedio_total_time);        
    }

    if ( count >  VIDEO_NUM_PRE_PAGE )
        count = VIDEO_NUM_PRE_PAGE;

    set_vedioes_info(info_array, count);
}

void set_camera_shoot_pos(uint8_t pos)
{
    camera_settings_set_shoot_pos(pos);
}

void set_camera_shoot_freq(uint8_t freq)
{
    camera_settings_set_shoot_freq(freq);
}

void set_camera_delayed_photography(bool opened)
{
    camera_settings_set_delayed_photography(opened);
}

void set_camera_rendering_method(uint8_t photoes)
{
    camera_settings_set_rendering_method(photoes);
}

void set_cur_language(uint8_t language)
{
    if ( language > MAX_LANGUAGE || language < 0 )
        return;

    settings_set_cur_language(language);
    set_cur_language_index(language);
    //页面切换语言显示
    settings_change_language_text();
    axis_move_change_language_text();
    //filament_infor_change_language_text();
    cool_change_language_text();
    adjustment_change_language_text();
    file_manage_change_language_text();
    service_change_language_text();
    self_test_tip_change_language_text();
    selftest_network_change_language_text();
    privacy_policy_change_language_text();
    timezone_change_language_text();
    selftest_bind_change_language_text();
    self_test_all_change_language_text();
    selftest_complete_change_language_text();
    CustomerFaq_change_language_text();
    Customerwiki_change_language_text();
    DetectionAI_change_language_text();
    
}

void set_faq_qrcode(char * qrcode_name)
{
    service_set_feedback_QRcode_png(qrcode_name);
}

void set_ai_detection_state(AIConfigState_t aistate)
{
    ai_set_detection_state(aistate);
}

void set_fault_action(bool is_detection_in_printing)
{
    ai_set_fault_action(is_detection_in_printing);
}

void set_first_layer_detection_state(bool opened)
{
    ai_set_first_layer_detection(opened);
}

/**
 * @description: 刷新摄像头状态
 * @return {*}
 * @param {int} model_camera_state
 */
void set_camera_model_status(int model_camera_state)
{
    home_normal_refresh_camerastate(model_camera_state);
    print_page_refresh_camerastate(model_camera_state);
    axismove_page_refresh_camerastate(model_camera_state);
    filemanage_page_refresh_camerastate(model_camera_state);
    settings_page_refresh_camerastate(model_camera_state);
    service_page_refresh_camerastate(model_camera_state);
    
    refresh_camera_detecte_state(model_camera_state);
}

/**
 * @description: 刷新激光雷达状态
 * @return {*}
 * @param {int} laser_state
 */
void set_laser_state(int laser_state)
{
    home_normal_refresh_laserstate(laser_state);
    print_page_refresh_laserstate(laser_state);
    axismove_page_refresh_laserstate(laser_state);
    filemanage_page_refresh_laserstate(laser_state);
    settings_page_refresh_laserstate(laser_state);
    service_page_refresh_laserstate(laser_state);

    refresh_laser_detecte_state(laser_state);
}