/*
 * @Author: Fang JinLun 
 * @Date: 2023-06-01 20:00:14 
 * @Last Modified by: Fang JinLun
 * @Last Modified time: 2023-06-08 16:18:18
 */

#include "ui_Screen_MachineScanGunSnNum.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>
#include <errno.h>
#include "json-c/json_object.h"
#include "json-c/json_tokener.h"
#include "json-c/json_util.h"

#ifdef CROSS_COMPILE
    #define SCANNER_DEV   "/dev/input/by-id/usb_keyboard"
#else
    #define SCANNER_DEV   "/dev/input/event6"
#endif

#define SN_LEN   19

static struct input_event input_ev;
static int gun_fd;
static char sn_number[128] = {0};
static char sn_temp[128] = {0};
static int thread_cancel = 0;
static pthread_t handle = 0;
static unsigned char key_val[255] = {
    [KEY_A] = 'A',
    [KEY_B] = 'B',
    [KEY_C] = 'C',
    [KEY_D] = 'D',
    [KEY_E] = 'E',
    [KEY_F] = 'F',
    [KEY_G] = 'G',
    [KEY_H] = 'H',
    [KEY_I] = 'I',
    [KEY_J] = 'J',
    [KEY_K] = 'K',
    [KEY_L] = 'L',
    [KEY_M] = 'M',
    [KEY_N] = 'N',
    [KEY_O] = 'O',
    [KEY_P] = 'P',
    [KEY_Q] = 'Q',
    [KEY_R] = 'R',
    [KEY_S] = 'S',
    [KEY_T] = 'T',
    [KEY_U] = 'U',
    [KEY_V] = 'V',
    [KEY_W] = 'W',
    [KEY_X] = 'X',
    [KEY_Y] = 'Y',
    [KEY_Z] = 'Z',

    [KEY_1] = '1',
    [KEY_2] = '2',
    [KEY_3] = '3',
    [KEY_4] = '4',
    [KEY_5] = '5',
    [KEY_6] = '6',
    [KEY_7] = '7',
    [KEY_8] = '8',
    [KEY_9] = '9',
    [KEY_0] = '0',

};

static bool has_ev=false;
static lv_timer_t *ev_timer;
static char* return_text="返回";
static char* sn_number_text="SN号:";
static char* sn_enter_text="SN号录入";
static char* scanner_no_exist_text="未检测到扫码枪";
static char* scanner_enter_text="扫码枪已插入";
static char* qrcode_number_error_text="二维码错误";
static lv_obj_t *m_scan_gun_obj;
static lv_obj_t *return_label;
static lv_obj_t *return_btn;
static lv_obj_t *sn_label;
static lv_obj_t *sn_enter_label;
static lv_obj_t *sn_num_label;
static unsigned char p_index = 0;
static int scannerStatus=0;


static void key_process(struct input_event *buff)
{
    
    if (buff->type == 1 && buff->value == 0) {
        if (key_val[buff->code]) {
            sn_temp[p_index] = key_val[buff->code];
            p_index++;
        }
    }
}

static void* scan_gun_thread(void* arg)
{
    fd_set fs_read;

    CrLogI("scan gun thread start\n");
    gun_fd = open(SCANNER_DEV, O_RDONLY);//打开usb扫描枪设备
    if (gun_fd < 0) { 
        CrLogI("can not open device usbscanner! error: %s(errno: %d)\n",strerror(errno),errno);
        return NULL;
    }
    
    while(!thread_cancel)
    {
        
        FD_ZERO(&fs_read); //每次循环都要清空集合，否则不能检测描述符变化
        FD_SET(gun_fd, &fs_read); //添加描述符

        int fs_sel = select(gun_fd + 1, &fs_read, NULL, NULL, NULL);
        if(fs_sel>0 && FD_ISSET(gun_fd, &fs_read)){
            int len = read(gun_fd,&input_ev,sizeof(struct input_event));
            if(len>0) {
                if (input_ev.code == KEY_ENTER && input_ev.value == 1){
                    memcpy(sn_number,sn_temp,sizeof(sn_temp));
                    bzero(sn_temp,sizeof(sn_temp));
                    CrLogI("SN: %s\n", sn_number);
                    has_ev=true;
                    p_index=0;
                }else{
                    key_process(&input_ev);
                }
            }
        }   
    }
 
    if(gun_fd)close(gun_fd);
    gun_fd=0;
    CrLogI("scan gun thread exit!\n");
    return NULL;
}

static int scan_gun_dev_init(void)
{
    int res = 0;
    CrLogI("scan gun pthread create\n");
    res = pthread_create(&handle, NULL, scan_gun_thread, NULL);
    if (res != 0){
        CrLogW("pthread create fail!!!,error: %s(errno: %d)\n",strerror(errno),errno);
        return -1;
    }
    pthread_detach(handle);

    return 0;
} 

static int create_sn_save_file(char* sn)
{
    json_object *saveObj = json_object_new_object();
    if(saveObj){
        json_object_object_add(saveObj, "productionSn", json_object_new_string(sn));
        json_object_to_file_ext(GetMachineProductionInfo(), saveObj, JSON_C_TO_STRING_PLAIN);
    }
    if(saveObj)
        json_object_put(saveObj);
}

static int save_sn_number_to_file(char* sn)
{
    int ret=0;

    // 把生产SN更新到写号分区
    char resBuf[64] = {0};
    char setCmd[256] = {0};
    snprintf(setCmd, sizeof(setCmd), GetDefaultSetMachineSnScript(), sn);
    // 设置
    if (!PopenSystem(setCmd, resBuf, sizeof(resBuf)))
        CrLogW("set screen value fail !!\n");

    // 把生产SN更新到文件
    json_object* machineInfoObj = json_object_from_file(GetMachineProductionInfo());
    if(machineInfoObj){
        json_object* snObj = json_object_object_get(machineInfoObj,"productionSn");
        if(snObj){
            json_object_set_string(snObj,sn);
        }else{
            json_object_object_add(machineInfoObj, "productionSn", json_object_new_string(sn));
        }
        json_object_to_file_ext(GetMachineProductionInfo(), machineInfoObj, JSON_C_TO_STRING_PLAIN);
    }else{
        create_sn_save_file(sn);
    }
    if(machineInfoObj)
        json_object_put(machineInfoObj);
    system("sync");
    return ret;
}


static lv_obj_t *add_label(lv_obj_t *parents, const char *text, lv_font_t *font, lv_color_t color, lv_align_t align,
                                      lv_obj_t *align_to_obj, lv_coord_t x_ofs, lv_coord_t y_ofs)
{
    lv_obj_t *label = lv_label_create(parents);
    lv_label_set_text(label, text);
    lv_obj_set_style_text_font(label, font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_color(label, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align_to(label, align_to_obj, align, x_ofs, y_ofs);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    return label;
}

static void return_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_CLICKED)
    {
        CrLogI("return\n");
        CrLogI("handle=%d\n",handle);
        if(handle > 0){
            pthread_cancel(handle);
            handle=0;
        }
        CrLogI("pthread_cancel\n");
        if(gun_fd){
            close(gun_fd);
            gun_fd=0;
        }
        CrLogI("close gun_fd\n");
        if(m_scan_gun_obj){
            lv_timer_pause(ev_timer);
            lv_timer_del(ev_timer);
            CrLogI("delete timer\n");
            lv_obj_del_async(m_scan_gun_obj);
            m_scan_gun_obj = NULL;
            
        }
        CrLogI("return_btn_event_cb end\n");
        LoadMachinetestScreen();
    }
}

static void get_scan_ev_timer_cb(lv_timer_t *timer)
{
    char sn_num[256]={0};
    //检查扫码枪是否有事件输入
    if(has_ev){
        has_ev=false;
        CrLogI("sn_number len = %d\n",strlen(sn_number));
        if(strlen(sn_number)!=SN_LEN || (sn_number[16]>'Z'&& sn_number[16]<'A') || \
            (sn_number[17]>'Z'&& sn_number[17]<'A') || \
            (sn_number[18]>'Z'&& sn_number[18]<'A') || \
            (sn_number[15]>'L'&& sn_number[15]<'A') || \
            (sn_number[14]>'9'&& sn_number[14]<'0') || \
            (sn_number[13]>'9'&& sn_number[13]<'0') || \
            (sn_number[11]>'9'&& sn_number[11]<'0')){
            create_msgbox(qrcode_number_error_text, NULL, 2000 * 1, lv_scr_act());
            return;
        }
        
        save_sn_number_to_file(sn_number);

        if(m_scan_gun_obj){
            json_object* machineInfoObj = json_object_from_file(GetMachineProductionInfo());
            if(machineInfoObj){
                json_object* snObj = json_object_object_get(machineInfoObj,"productionSn");
                if(snObj){
                    char *sn_tmp = json_object_get_string(snObj);
                    int sn_len = json_object_get_string_len(snObj);
                    CrLogI("read sn number: %s",sn_tmp);
                    if(sn_len>SN_LEN){
                        create_msgbox(qrcode_number_error_text, NULL, 2000 * 1, lv_scr_act());
                        return;
                    }
                    memcpy(sn_num,sn_tmp,sn_len);
                }
            }
            lv_label_set_text(sn_num_label,sn_num);
            lv_obj_align_to(sn_num_label,sn_label,LV_ALIGN_OUT_RIGHT_MID,30,0);
        }
    }

    //检查扫码枪插拔状态
    if(scannerStatus != GetPrintRunState().scannerExists){
        scannerStatus = GetPrintRunState().scannerExists;
        if(scannerStatus == 0){
            create_msgbox(scanner_no_exist_text, NULL, 1000 * 1, lv_scr_act());
            if(handle>0){
                pthread_cancel(handle);
                handle=0;
            }
            if(gun_fd){
                close(gun_fd);
                gun_fd=0;
            }
            
        }else{
            create_msgbox(scanner_enter_text, NULL, 1000 * 1, lv_scr_act());
            scan_gun_dev_init();
        }
    }
    
}

void ui_machine_scan_gun_sn_screen_init(lv_obj_t* parents) 
{
    char* sn_tmp = NULL;
    char sn[64] = {0};

    CrLogI("ui_machine_scan_gun_sn_screen_init\n");

    scannerStatus = GetPrintRunState().scannerExists;

    json_object* machineInfoObj = json_object_from_file(GetMachineProductionInfo());
    if(machineInfoObj){
        json_object* snObj = json_object_object_get(machineInfoObj,"productionSn");
        if(snObj){
            sn_tmp = json_object_get_string(snObj);
            int sn_len = json_object_get_string_len(snObj);
            CrLogI("read sn number: %s",sn_tmp);
            memcpy(sn,sn_tmp,sn_len);
        }else{
            CrLogW("key [productionSn] no exist!!\n");
        }
    }else{
        CrLogW("productionInfo file no exist!!\n");
    }
 

    m_scan_gun_obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(m_scan_gun_obj, 640, 360);
    lv_obj_set_pos(m_scan_gun_obj, 0, 60);
    lv_obj_clear_flag(m_scan_gun_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(m_scan_gun_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(m_scan_gun_obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(m_scan_gun_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(m_scan_gun_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(m_scan_gun_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);  

    sn_enter_label = add_label(m_scan_gun_obj,sn_enter_text,lv_font28.font,lv_color_white(),\
        LV_ALIGN_TOP_MID,m_scan_gun_obj,0,25);

    sn_label = add_label(m_scan_gun_obj,sn_number_text,lv_font32.font,lv_color_white(),\
        LV_ALIGN_CENTER,m_scan_gun_obj,-170,0);
    sn_num_label = add_label(m_scan_gun_obj," ",lv_font32.font,lv_color_white(),\
        LV_ALIGN_OUT_RIGHT_MID,sn_label,30,0);
    
    lv_label_set_text(sn_num_label,sn);
    lv_obj_align_to(sn_num_label,sn_label,LV_ALIGN_OUT_RIGHT_MID,30,0);
    
    //返回按钮
    return_btn = lv_btn_create(m_scan_gun_obj);
    lv_obj_set_size(return_btn, 130, 50);
    lv_obj_align_to(return_btn, m_scan_gun_obj, LV_ALIGN_TOP_LEFT, 20, 20);
    lv_obj_add_flag(return_btn, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_set_style_radius(return_btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(return_btn, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(return_btn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(return_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(return_btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(return_btn, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(return_btn, lv_color_hex(0x4190A2),
                                  LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(return_btn, 255, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(return_btn, 2, LV_PART_MAIN | LV_STATE_PRESSED);
    lv_obj_set_style_border_color(return_btn, lv_color_hex(0xB0F1FF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY); 
    lv_obj_set_style_border_opa(return_btn, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(return_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_radius(return_btn, 5, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_spread(return_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(return_btn, 2, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_shadow_color(return_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(return_btn, lv_color_hex(0xB0F1FF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);

    return_label = add_label(return_btn, return_text, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_CENTER, return_btn, 0, 0);

    ev_timer = lv_timer_create(get_scan_ev_timer_cb, 200, NULL);
    lv_obj_add_event_cb(return_btn,return_btn_event_cb,LV_EVENT_CLICKED,NULL);
    

    //释放Json object
    if(machineInfoObj)
        json_object_put(machineInfoObj);

#ifdef CROSS_COMPILE
    if(GetPrintRunState().scannerExists == 0)
    {
        create_msgbox(scanner_no_exist_text, NULL, 1000 * 1, lv_scr_act());
    }else
#endif
    {
        //初始化扫描枪输入设备
        scan_gun_dev_init();
    }
}


void MachineScanGunSnNumAddObjToGroup(void)
{
    lv_group_add_obj(encoder_group, return_btn);
}