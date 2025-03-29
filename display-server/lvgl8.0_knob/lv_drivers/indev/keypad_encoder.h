/*
 * @Description: 
 * @Author: sunhui
 * @Date: 2023-05-09 03:09:51
 * @LastEditTime: 2023-05-09 23:49:01
 */

#ifndef KEYPAD_ENCODER_H
#define KEYPAD_ENCODER_H

/*********************
 *      INCLUDES
 *********************/
#ifndef LV_DRV_NO_CONF
#ifdef LV_CONF_INCLUDE_SIMPLE
#include "lv_drv_conf.h"
#else
#include "../../lv_drv_conf.h"
#endif
#endif

#if USE_EVDEV || USE_BSD_EVDEV

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

typedef enum {
    ENCODER_LEFT_FAST = 0x11,   
    ENCODER_LEFT_SLOW = 0x10,
    ENCODER_RIGHT_FAST = 0x21,
    ENCODER_RIGHT_SLOW = 0x20
}EncodeDirSpeed_t;

void encoder_init(void);
void encoder_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
EncodeDirSpeed_t GetEncoderDirSpeed(lv_event_t * e);
#endif

#endif /*KEYPAD_ENCODER_H*/
