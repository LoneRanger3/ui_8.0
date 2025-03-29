/*
 * @Description: 
 * @Author: sunhui
 * @Date: 2023-05-09 03:09:51
 * @LastEditTime: 2023-09-11 21:37:15
 */

#include "evdev.h"
#include "keypad_encoder.h"
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "custom.h"
#include <linux/input.h>
static lv_indev_state_t state = LV_INDEV_STATE_RELEASED;

// 编码器相关

static int16_t enc_diff = 0;
static int16_t last_enc_diff = 0;
int encoder_fd;
uint32_t encoder_last_tick = 0;  // 上次采样时间戳

void encoder_init(void)
{ 
    //encoder_fd = open(EVDEV_NAME, O_RDWR | O_NOCTTY | O_NDELAY);
    encoder_fd = open("/dev/input/event0", O_RDWR | O_NOCTTY | O_NDELAY);

    if(encoder_fd == -1) {
        perror("unable open evdev interface:/dev/input/event0");
        return;
    }

#if USE_BSD_EVDEV
    fcntl(encoder_fd, F_SETFL, O_NONBLOCK);
#else
    fcntl(encoder_fd, F_SETFL, O_ASYNC | O_NONBLOCK);
#endif
}

/*Will be called by the library to read the encoder*/
void encoder_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    struct input_event in;
    while(read(encoder_fd, &in, sizeof(struct input_event)) > 0) {
        printf("type:%d code:%d value:%d\n", in.type, in.code, in.value);
        system_state.ScreenSaverCount = 0;
        system_state.HasEncoderEvent = true;
        if(in.type == EV_REL) {
             if(in.code == REL_X) {
                if (in.value == 1)
                {
                    enc_diff--;
                    data->enc_diff = enc_diff;
                }
                else {
                    enc_diff++;
                    data->enc_diff = enc_diff;
                }
                enc_diff = 0;
                printf("REL_X.\n");
            }

        }
        if(in.type == EV_KEY)
        {
            if (in.code == KEY_ENTER)
            {
                if(in.value == 0) {
                    state = LV_INDEV_STATE_RELEASED;
                     printf("LV_INDEV_STATE_REL.\n");
                    
                }
                else if(in.value == 1) {
                    
                     state = LV_INDEV_STATE_PRESSED;
                     printf("LV_INDEV_STATE_PR.\n");
                }
            }
        }   
    }
    data->state=state;
    //printf("data->state :%d\n", data->state);

}


EncodeDirSpeed_t GetEncoderDirSpeed(lv_event_t * e)
{
    static uint8_t value = 0;
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    uint32_t encoder_cur_tick = 0;

    if(event_code == LV_EVENT_KEY) 
    {
        char c = *((char *)lv_event_get_param(e));
        if (c==LV_KEY_LEFT)
        {
            value = 0x10;

        }
        if (c==LV_KEY_RIGHT)
        {
            value = 0x20;
        }
        
        int diff = lv_tick_get() - encoder_last_tick;
        encoder_last_tick = lv_tick_get();
        if(diff < 100)
        {
            value |= 0x1; //快
        }
        return value;
      
    }

    return 0;
}