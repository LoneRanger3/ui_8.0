/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2021-11-30 17:20:06
 * @LastEditTime: 2023-07-24 05:52:37
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdbool.h>
#define _DEFAULT_SOURCE /* needed for usleep() */
#include <stdlib.h>
#include <unistd.h>
#define SDL_MAIN_HANDLED /*To fix SDL's "undefined reference to WinMain" issue*/
#include <SDL2/SDL.h>
#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lv_examples/lv_demo.h"
#include "lv_drivers/display/monitor.h"
#include "lv_drivers/indev/mouse.h"
#include "lv_drivers/indev/keyboard.h"
#include "lv_drivers/indev/mousewheel.h"

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
static int tick_thread(void *data);
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
    
    init_page_manager();

    // 初始化UI界面
    UIInit_t uiInit = {0};
    uiInit.MachineType = 1003;//config.model;
    uiInit.direction = GetUiDirection(config);
    uiInit.SelftestFlag = false;//config.self_test_sw;
    uiInit.ZAxisForwardMoveDir = 1; //config.z_direction;
    uiInit.CheckUpdateFlag = config.upgrade_remind;
    uiInit.AgreePrivacyPolicy = config.agree_privacy;
    uiInit.ServerOption = config.server_local;
    //CrLogI("z axis direction = %d", config.z_direction);
    UI_Init(uiInit);
    
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

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the LVGL graphics
 * library
 */
static void hal_init(int direction)
{
  /* Use the 'monitor' driver which creates window on PC's monitor to simulate a display*/
  monitor_init();
  /* Tick init.
   * You have to call 'lv_tick_inc()' in periodically to inform LittelvGL about
   * how much time were elapsed Create an SDL thread to do this*/
  SDL_CreateThread(tick_thread, "tick", NULL);

  /*Create a display buffer*/
  static lv_disp_draw_buf_t disp_buf1;
  static lv_color_t buf1_1[MONITOR_HOR_RES * 100];
  static lv_color_t buf1_2[MONITOR_HOR_RES * 100];
  lv_disp_draw_buf_init(&disp_buf1, buf1_1, buf1_2, MONITOR_HOR_RES * 100);

  /*Create a display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv); /*Basic initialization*/
  disp_drv.draw_buf = &disp_buf1;
  disp_drv.flush_cb = monitor_flush;
  disp_drv.hor_res = MONITOR_HOR_RES;
  disp_drv.ver_res = MONITOR_VER_RES;
  disp_drv.sw_rotate  = 1;
  // 设置屏幕方向
  switch (direction) {
    case UI_DIRECTION_NONE: disp_drv.sw_rotate  = 0; break;
    case UI_DIRECTION_90:   disp_drv.rotated = LV_DISP_ROT_90; break;
    case UI_DIRECTION_180:  disp_drv.rotated = LV_DISP_ROT_180; break;
    case UI_DIRECTION_270:  disp_drv.rotated = LV_DISP_ROT_270; break;
  }
  disp_drv.antialiasing = 1;
  lv_disp_t * disp = lv_disp_drv_register(&disp_drv);

  lv_theme_t * th = lv_theme_default_init(disp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), LV_THEME_DEFAULT_DARK, LV_FONT_DEFAULT);
  lv_disp_set_theme(disp, th);

  encoder_group = lv_group_create();
  //lv_group_set_default(g);

  /* Add the mouse as input device
   * Use the 'mouse' driver which reads the PC's mouse*/
  mouse_init();
  static lv_indev_drv_t indev_drv_1;
  lv_indev_drv_init(&indev_drv_1); /*Basic initialization*/
  indev_drv_1.type = LV_INDEV_TYPE_POINTER;

  /*This function will be called periodically (by the library) to get the mouse position and state*/
  indev_drv_1.read_cb = mouse_read;
  lv_indev_t *mouse_indev = lv_indev_drv_register(&indev_drv_1);

  keyboard_init();
  static lv_indev_drv_t indev_drv_2;
  lv_indev_drv_init(&indev_drv_2); /*Basic initialization*/
  indev_drv_2.type = LV_INDEV_TYPE_KEYPAD;
  indev_drv_2.read_cb = keyboard_read;
  lv_indev_t *kb_indev = lv_indev_drv_register(&indev_drv_2);
  lv_indev_set_group(kb_indev, encoder_group);

  mousewheel_init();
  static lv_indev_drv_t indev_drv_3;
  lv_indev_drv_init(&indev_drv_3); /*Basic initialization*/
  indev_drv_3.type = LV_INDEV_TYPE_ENCODER;
  indev_drv_3.read_cb = mousewheel_read;
  indev_drv_3.long_press_time = 800;
  enc_indev = lv_indev_drv_register(&indev_drv_3);
  lv_indev_set_group(enc_indev, encoder_group);

  /*Set a cursor for the mouse*/
  LV_IMG_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
  lv_obj_t * cursor_obj = lv_img_create(lv_scr_act()); /*Create an image object for the cursor */
  lv_img_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
  lv_indev_set_cursor(mouse_indev, cursor_obj);             /*Connect the image  object to the driver*/

  /* Optional:
   * Create a memory monitor task which prints the memory usage in
   * periodically.*/
  lv_timer_create(memory_monitor, 60*1000, NULL);
}

/**
 * A task to measure the elapsed time for LVGL
 * @param data unused
 * @return never return
 */
static int tick_thread(void *data) {
  (void)data;

  while(1) {
    SDL_Delay(5);
  }

  return 0;
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
//   CrLogI("used: %6d (%3d %%), frag: %3d %%, biggest free: %6d\n",
//          (int)mon.total_size - mon.free_size, mon.used_pct, mon.frag_pct,
//          (int)mon.free_biggest_size);
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
