/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-12-22 17:39:34
 * @LastEditTime: 2022-12-28 09:55:23
 */
#ifndef _UI_SCREEN_CUSTOMERSERVICE_H
#define _UI_SCREEN_CUSTOMERSERVICE_H

#ifdef __cplusplus
extern "C" {
#endif



void ui_ScreenCustomerService_screen_init(void);
void LoadCustomerServiceScreen(void);

void service_set_feedback_QRcode_png(char *QRcode_png_name);
void service_change_language_text(void);
void refresh_uploadlog_process(int state, int process, char * SN);
void refresh_compressed_process(int process);

#ifdef __cplusplus
}
#endif

#endif