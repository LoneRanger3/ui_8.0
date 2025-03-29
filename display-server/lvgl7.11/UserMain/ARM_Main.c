/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-01-15 14:46:03
 * @LastEditTime: 2022-09-30 16:31:28
 */

/*********************
 *      INCLUDES
 *********************/
#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/evdev.h"
#include "lv_examples/lv_examples.h"

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

#include "Base/DisplayMsgBase.h"
#include "Message/ServerMessage.h"

#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void hal_init(void);
static void memory_monitor(lv_task_t *param);
lv_ui guider_ui;

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
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

    /*Initialize LVGL*/
    lv_init();

    /*Initialize the HAL (display, input devices, tick) for LVGL*/
    hal_init();

    FileManagerInit();
    CrLogOpen(GetUserDataLogDirPtah(), (char *)"display-server");
    ServerMessageInit(NULL);

    setup_ui(&guider_ui);
    events_init(&guider_ui);
    custom_init(&guider_ui);
    
    while (1) {
        /* Periodically call the lv_task handler.
        * It could be done in a timer interrupt or an OS task too.*/
        lv_tick_inc(5);
        lv_task_handler();
        usleep(5 * 1000);
    }

    return 0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/**
 * Initialize the Hardware Abstraction Layer (HAL) for the Littlev graphics
 * library
 */
static void hal_init(void) {
    /*Linux frame buffer device init*/
    fbdev_init();

    /*A small buffer for LittlevGL to draw the screen's content*/
    static lv_color_t buf[LV_HOR_RES_MAX * 80] = {0};

    /*Initialize a descriptor for the buffer*/
    static lv_disp_buf_t disp_buf;
    lv_disp_buf_init(&disp_buf, buf, NULL, LV_HOR_RES_MAX * 80);

    /*Initialize and register a display driver*/
    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.buffer   = &disp_buf;
    disp_drv.flush_cb = fbdev_flush;
    lv_disp_t *disp = lv_disp_drv_register(&disp_drv);

    lv_indev_t *  indev_test ; 
    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);/*Basic initialization*/
    evdev_init();
    indev_drv.type=LV_INDEV_TYPE_POINTER;/*See below.*/
    indev_drv.read_cb=evdev_read;/*See below.*/
    indev_drv.disp = disp;
    indev_test = lv_indev_drv_register(&indev_drv);/*Register the driver in LittlevGL*/

    /* Optional:
    * Create a memory monitor task which prints the memory usage in
    * periodically.*/
    lv_task_create(memory_monitor, 60 * 1000, LV_TASK_PRIO_MID, NULL);
}

/**
 * Print the memory usage periodically
 * @param param
 */
static void memory_monitor(lv_task_t *param) {
  (void)param; /*Unused*/

    lv_mem_monitor_t mon;
    lv_mem_monitor(&mon);
    CrLogI("used: %6d (%3d %%), max_used: %6d, biggest free: %6d, free size: %6d\n",
        (int)mon.total_size - mon.free_size, mon.used_pct, mon.max_used,
        (int)mon.free_biggest_size, (int)mon.free_size);
}
