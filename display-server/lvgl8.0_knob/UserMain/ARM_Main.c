/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:20:06
 * @LastEditTime: 2023-10-09 22:17:11
 */

/*********************
 *      INCLUDES
 *********************/
#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"
#include "lv_examples/lv_demo.h"
#include "lv_drivers/indev/keypad_encoder.h"

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#include "Base/DisplayMsgBase.h"
#include "Message/ServerMessage.h"
#include "custom.h"
#include "page_switch.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void hal_init(int direction);
static void memory_monitor(lv_timer_t *param);

/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t * enc_indev;
lv_group_t * encoder_group;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *      VARIABLES
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {int} sig_no
 */
static void Terminate(int sig_no)
{
    CrLogI("Enter blackbox_handler: ");
    CrLogI("Got signal name %s, num %d; exiting ...", strsignal(sig_no), sig_no);

    if (SIGHUP == sig_no || SIGPIPE == sig_no || SIGUSR2 == sig_no || SIGUSR1 == sig_no)
    {
        CrLogD("ignore signal :%d\r\n", sig_no);
        return;
    }
    ExceptionHandleSemPost();

    CrLogE("EXIT:!!!\n\n");
    exit(1);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
static void InstallSignalHandler(void)
{
    signal(SIGBUS, Terminate);
    signal(SIGFPE, Terminate);
    signal(SIGHUP, Terminate);
    signal(SIGILL, Terminate);
    signal(SIGINT, Terminate);
    signal(SIGIOT, Terminate);
    signal(SIGPIPE, Terminate);
    signal(SIGQUIT, Terminate);
    signal(SIGSEGV, Terminate);
    signal(SIGSYS, Terminate);
    signal(SIGTERM, Terminate);
    signal(SIGTRAP, Terminate);
    signal(SIGUSR1, Terminate);
    signal(SIGUSR2, Terminate);
}

/**
 * @description: 
 * @return {*}
 * @param {SystemConfig_t} config
 */
static int GetUiDirection(SystemConfig_t config)
{
    switch (config.ui_direction) {
        case UI_DIRECTION_NONE:
        case UI_DIRECTION_180:
            return 0;
        case UI_DIRECTION_90:
        case UI_DIRECTION_270:
            return 1;
        default:
            return 0;
    }
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {int} argc
 * @param {char} *
 */
int main(int argc, char **argv)
{
    (void)argc; /*Unused*/
    (void)argv; /*Unused*/
    InstallSignalHandler();

    FileManagerInit();
    CrLogOpen(GetUserDataLogDirPtah(), (char *)"display-server");
    SetLogFileNum(10);
    ServerMessageInit(NULL);
    DelayGetSystemConfig();

    // Get System Config
    SystemConfig_t config = GetSystemConfig();
    CrLogI("device model = %d", config.model);
    CrLogI("ui direction = %d", config.ui_direction);
    CrLogI("self test = %d", config.self_test_sw);
    CrLogI("z axis direction = %d", config.z_direction);

    /*Initialize LVGL*/
    lv_init();

    /*Initialize the HAL (display, input devices, tick) for LVGL*/
    hal_init(config.ui_direction);

    // 初始化UI界面
    UIInit_t uiInit = {0};
    uiInit.MachineType = config.model;
    uiInit.direction = GetUiDirection(config);
    uiInit.SelftestFlag = config.self_test_sw;
    uiInit.ZAxisForwardMoveDir = config.z_direction;
    uiInit.CheckUpdateFlag = config.upgrade_remind;
    uiInit.AgreePrivacyPolicy = config.agree_privacy;
    uiInit.ServerOption = config.server_local;
    UI_Init(uiInit);

    
#if 0
    // lv_group_set_default(encoder_group); //默认组

    lv_indev_set_group(enc_indev, encoder_group); //关联组

    // /* 创建一个btn部件(对象) */
    lv_obj_t * btn1 = lv_btn_create(lv_scr_act());       // 创建一个btn部件(对象),他的父对象是活动屏幕对象
    lv_obj_set_size(btn1, 100, 50);
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -100);

    lv_obj_t * btn2 = lv_btn_create(lv_scr_act());       // 创建一个btn部件(对象),他的父对象是活动屏幕对象
    lv_obj_set_size(btn2, 100, 50);
    lv_obj_align_to(btn2, btn1, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    lv_obj_t * btn3 = lv_btn_create(lv_scr_act());       // 创建一个btn部件(对象),他的父对象是活动屏幕对象
    lv_obj_set_size(btn3, 100, 50);
    lv_obj_align_to(btn3, btn2, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    lv_obj_t * btn4 = lv_btn_create(lv_scr_act());       // 创建一个btn部件(对象),他的父对象是活动屏幕对象
    lv_obj_set_size(btn4, 100, 50);
    lv_obj_align_to(btn4, btn3, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    lv_obj_t * slider = lv_slider_create(lv_scr_act());
    lv_obj_align_to(slider, btn4, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    lv_group_add_obj(encoder_group, btn1);
    lv_group_add_obj(encoder_group, btn2);
    lv_group_add_obj(encoder_group, btn3);
    lv_group_add_obj(encoder_group, btn4);
    lv_group_add_obj(encoder_group, slider);
#endif    
    
    CrLogI("UI init finish !!!\n");
    SyncUiInitFinish();

    while(1) {
        /* Periodically call the lv_task handler.
        * It could be done in a timer interrupt or an OS task too.*/
        ui_pthread_mutex_lock();
        lv_tick_inc(5);
        lv_timer_handler();
        ui_pthread_mutex_unlock();
        usleep(5 * 1000);
    }

    return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#define DISP_BUF_SIZE (128 * 1024)
/**
 * Initialize the Hardware Abstraction Layer (HAL) for the LVGL graphics
 * library
 */
static void hal_init(int direction)
{
    /*Linux frame buffer device init*/
    fbdev_init();

#ifdef USE_FBDEV_DOUBLE_BUFFER
    uint32_t width, height = 0;

    fbdev_get_sizes(&width, &height);

    static lv_color_t *buf;
    buf = (lv_color_t*)lv_mem_alloc(width * height * sizeof(lv_color_t));
    static lv_disp_draw_buf_t disp_buf;

    lv_disp_draw_buf_init(&disp_buf, buf, NULL, width * height);
#else
    /*A small buffer for LittlevGL to draw the screen's content*/
    static lv_color_t buf1[DISP_BUF_SIZE];
    static lv_color_t buf2[DISP_BUF_SIZE];

    /*Initialize a descriptor for the buffer*/
    static lv_disp_draw_buf_t disp_buf;
    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, DISP_BUF_SIZE);
#endif // USE_FBDEV_DOUBLE_BUFFER

    /*Initialize and register a display driver*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf   = &disp_buf;
    disp_drv.flush_cb   = fbdev_flush;
    disp_drv.hor_res    = 480;
    disp_drv.ver_res    = 640;
    disp_drv.sw_rotate  = 1;
    // 设置屏幕方向
    switch (direction) {
        case UI_DIRECTION_NONE: disp_drv.sw_rotate  = 0; break;
        case UI_DIRECTION_90:   disp_drv.rotated = LV_DISP_ROT_90; break;
        case UI_DIRECTION_180:  disp_drv.rotated = LV_DISP_ROT_180; break;
        case UI_DIRECTION_270:  disp_drv.rotated = LV_DISP_ROT_270; break;
    }
    disp_drv.antialiasing = 1;
    lv_disp_t *disp     = lv_disp_drv_register(&disp_drv);

# if 0
    //evdev_init();
    
    // static lv_indev_drv_t indev_drv;
    // lv_indev_drv_init(&indev_drv); /*Basic initialization*/
    // indev_drv.type = LV_INDEV_TYPE_POINTER;
    // indev_drv.read_cb = evdev_read;
    // indev_drv.disp = disp;
    // lv_indev_drv_register(&indev_drv);
# endif 

    encoder_init();
    /*Register a encoder input device*/
    static lv_indev_drv_t encoder_driver;
    lv_indev_drv_init(&encoder_driver);
    encoder_driver.type = LV_INDEV_TYPE_ENCODER;
    encoder_driver.read_cb = encoder_read;
    encoder_driver.long_press_time = 800;
    enc_indev = lv_indev_drv_register(&encoder_driver);
   
    encoder_group = lv_group_create();
    lv_indev_set_group(enc_indev, encoder_group); //关联组
    /* Optional:
     * Create a memory monitor task which prints the memory usage in
     * periodically.*/
    lv_timer_create(memory_monitor, 60*1000, NULL);
}

/**
 * Print the memory usage periodically
 * @param param
 */
static void memory_monitor(lv_timer_t *param) {
  (void)param; /*Unused*/
//   与键盘创建冲突暂时屏蔽,后续解决了再开放
//   lv_mem_monitor_t mon;
//   lv_mem_monitor(&mon);
//   CrLogI("used: %6d (%3d %%), max_used: %6d, biggest free: %6d, free size: %6d\n",
//         (int)mon.total_size - mon.free_size, mon.used_pct, mon.max_used,
//         (int)mon.free_biggest_size, (int)mon.free_size);
}

/*Set in lv_conf.h as `LV_TICK_CUSTOM_SYS_TIME_EXPR`*/
uint32_t custom_tick_get(void)
{
    static uint64_t start_ms = 0;
    if(start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}
