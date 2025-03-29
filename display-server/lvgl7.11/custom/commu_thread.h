/*
 * commu_thread.h
 *
 *  Created on: December 16, 2021
 *      Author: liuxinchao
 */

#ifndef __COMMU_THREAD_H_
#define __COMMU_THREAD_H_

#include "gui_guider.h"

void set_refresh_data(unsigned char flag);
void get_printer_data(unsigned char flag, unsigned int len, char *data);
void get_response_printer_data(unsigned char flag, unsigned int len, char *data);
void set_printer_data(unsigned char flag, unsigned int len, char *data);
void set_response_printer_data(unsigned char flag, unsigned int len, char *data);
void send_buzzer(unsigned char flag);

//void save_file_names(char *data,int len);
//void handle_file(char *data,int len, unsigned char cpage);

#endif /* EVENT_CB_H_ */
