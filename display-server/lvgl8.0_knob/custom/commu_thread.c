/*
 * commu_thread.c
 *
 *  Created on: December 10, 2021
 *      Author: liuxinchao
 */


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "lvgl/lvgl.h"
#include "commu_thread.h"
#include "custom.h"
// #include "../generated/gui_guider.h"
#include "clanguage.h"
#include "CrlogDef.h"
#include "mystyle.h"
#include "../k1_horizontal_ui/ui.h"

#ifdef IS_SYSTEM_USE
	#include "Message/ServerMessage.h"
#endif

#include "custom/lvgl_horizontal_screen_interface.h"

 /*
flag是一个按位表示的数据，相应的位为0表示该数据停止自动刷新，为1表示该数据开启自动刷新
其中：
0位表示温度的刷新，包括当前的喷头温度和热床温度
1位表示当前位置的刷新，包括XYZ的当前位置
2位表示打印中打印进度百分比和已打印时间的刷新
目前暂时用到这三位，其余的需要的再补充
*/
void set_refresh_data(unsigned char flag)
{
#ifdef IS_SYSTEM_USE
	SetPrinterRefreshToManager(flag);
#endif
}

void send_buzzer(unsigned char flag)
{
#ifdef IS_SYSTEM_USE
	SetPrinterBuzzerToManager(flag);
#endif
}

// void waittimer_handler(lv_timer_t * timer)
// {
// //    lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
//     lv_obj_add_flag(guider_ui.wait_spinner_1, LV_OBJ_FLAG_HIDDEN);

//     lv_obj_clear_flag(guider_ui.wait_label_1, LV_OBJ_FLAG_HIDDEN);
//     lv_obj_clear_flag(guider_ui.wait_label_2, LV_OBJ_FLAG_HIDDEN);
//     lv_obj_clear_flag(guider_ui.wait_label_3, LV_OBJ_FLAG_HIDDEN);
//     lv_obj_clear_flag(guider_ui.wait_btn_3, LV_OBJ_FLAG_HIDDEN);
//     lv_obj_add_flag(guider_ui.wait_btn_3, LV_OBJ_FLAG_CLICKABLE);
//     lv_label_set_text(guider_ui.wait_label_3,"网络连接异常");
//     lv_label_set_text(guider_ui.wait_btn_3_label,"确定");
// }

// void showfile(char *data,int len)
// {
//     print_file_ok = true;
//     if(len == 0)
//     {
//         print_file_pages = 0;
//     }
//     else
//     {
//         char file_num = 0;
//         unsigned char cnt  = 0;
//         unsigned char data_flag;

//         data++;
//         char *temp = strtok(data,"\t");
//         memset(dis_file_info,'\0',sizeof(dis_file_info));
//         int i = 0;
//         if(guider_ui.file_management_tabview_1 != NULL)
//         {
//             i = lv_tabview_get_tab_act(guider_ui.file_management_tabview_1);
//         }
//         else
//         {
//             CrLogE("file tabview is NULL");
//             return NULL;
//         }
//         //每次展示前都将文件控件隐藏
//         if( i == 0)
//         {
//             lv_obj_add_flag(guider_ui.file_management_label_2, LV_OBJ_FLAG_HIDDEN);     //文件1
//             lv_obj_add_flag(guider_ui.file_management_label_6, LV_OBJ_FLAG_HIDDEN);     //文件2
//             lv_obj_add_flag(guider_ui.file_management_label_10, LV_OBJ_FLAG_HIDDEN);    //文件3
//             lv_obj_add_flag(guider_ui.file_management_label_11, LV_OBJ_FLAG_HIDDEN);    //文件4
//             lv_obj_add_flag(guider_ui.file_management_label_12, LV_OBJ_FLAG_HIDDEN);    //文件5
//             lv_obj_add_flag(guider_ui.file_management_label_13, LV_OBJ_FLAG_HIDDEN);    //文件6
//         }
//         else
//         {
//             lv_obj_add_flag(guider_ui.file_management_sd_label_2,LV_OBJ_FLAG_HIDDEN);  //隐藏文件信息栏
//             lv_obj_add_flag(guider_ui.file_management_sd_label_6,LV_OBJ_FLAG_HIDDEN);  //隐藏文件信息栏
//             lv_obj_add_flag(guider_ui.file_management_sd_label_10,LV_OBJ_FLAG_HIDDEN); //隐藏文件信息栏
//             lv_obj_add_flag(guider_ui.file_management_sd_label_11,LV_OBJ_FLAG_HIDDEN); //隐藏文件信息栏
//             lv_obj_add_flag(guider_ui.file_management_sd_label_12,LV_OBJ_FLAG_HIDDEN); //隐藏文件信息栏
//             lv_obj_add_flag(guider_ui.file_management_sd_label_13,LV_OBJ_FLAG_HIDDEN); //隐藏文件信息栏
//         }
//         while(temp)
//         {
//             file_num++;
//             if(file_num > FILE_NUM_PRE_PAGE)
//             {
//                 break;
//             }

//             cnt = 0;
//             data_flag = 0;

//             while(*temp)
//             {
//                 if(*temp == '\0')
//                 {
//                     break;
//                 }

//                 if(*temp == ':')
//                 {
//                     switch(data_flag)
//                     {
//                     case 0:
//                         dis_file_info[file_num - 1].name[cnt] = '\0';
//                         break;
//                     case 1:
//                         dis_file_info[file_num - 1].photo[cnt] = '\0';
//                         break;
//                     case 2:
//                         dis_file_info[file_num - 1].estime[cnt] = '\0';
//                         break;
//                     case 3:
//                         dis_file_info[file_num - 1].filament[cnt] = '\0';
//                         break;
//                     case 4:
//                         dis_file_info[file_num - 1].layer_heigh[cnt] = '\0';
//                         break;
//                     case 5:
//                         dis_file_info[file_num - 1].volume[cnt] = '\0';
//                         break;
//                     case 6:
//                         dis_file_info[file_num - 1].filetype[cnt] = '\0';
//                         break;
//                     case 7:
//                         dis_file_info[file_num - 1].filesize[cnt] = '\0';
//                         break;
//                     case 8:
//                         dis_file_info[file_num - 1].filedate[cnt] = '\0';
//                         break;
//                     }
//                     data_flag++;
//                     temp++;
//                     cnt = 0;
//                     continue;
//                 }
//                 switch(data_flag)
//                 {
//                 case 0:
//                     if(cnt < FILE_SIZE)
//                         dis_file_info[file_num - 1].name[cnt++] = *temp;
//                     break;
//                 case 1:
//                     if(cnt < FILE_PHOTO_SIZE)
//                         dis_file_info[file_num - 1].photo[cnt++] = *temp;
//                     break;
//                 case 2:
//                     if(cnt < ESTIME_SIZE)
//                         dis_file_info[file_num - 1].estime[cnt++] = *temp;
//                     break;
//                 case 3:
//                     if(cnt < FILAMENT_SIZE)
//                         dis_file_info[file_num - 1].filament[cnt++] = *temp;
//                     break;
//                 case 4:
//                     if(cnt < LAYER_HEIGHT_SIZE)
//                         dis_file_info[file_num - 1].layer_heigh[cnt++] = *temp;
//                     break;
//                 case 5:
//                     if(cnt < VOLUME_SIZE)
//                         dis_file_info[file_num - 1].volume[cnt++] = *temp;
//                     break;
//                 case 6:
//                     if(cnt < FILE_TYPE)
//                         dis_file_info[file_num - 1].filetype[cnt++] = *temp;
//                     break;
//                 case 7:
//                     if(cnt < FILESIZE)
//                         dis_file_info[file_num - 1].filesize[cnt++] = *temp;
//                     break;
//                 case 8:
//                     if(cnt < FILEDATE)
//                         dis_file_info[file_num - 1].filedate[cnt++] = *temp;
//                     break;
//                 }
//                 temp++;
//             }
//             dis_file_info[file_num - 1].filedate[cnt] = '\0';

//             switch(file_num)
//             {
//             case 1:
//                 {
//                     if(i == 0)
//                     {
//                         lv_obj_clear_flag(guider_ui.file_management_label_2, LV_OBJ_FLAG_HIDDEN);        //文件1
//                         lv_label_set_text(guider_ui.file_management_label_3, dis_file_info[0].name);     //文件名
//                         lv_label_set_text(guider_ui.file_management_label_4, dis_file_info[0].estime);   //预计时间
//                         lv_label_set_text(guider_ui.file_management_label_5, dis_file_info[0].filament); //所需耗材
//                         if(dis_file_info[0].photo[0] == '\0')
//                         {
//     //                    lv_img_set_src(guider_ui.file_management_img_6, &xiaowei96);
//                         }
//                         else
//                         {
//                             lv_img_set_src(guider_ui.file_management_img_6, dis_file_info[0].photo);
//                         }
//                     }
//                     if(i == 1)
//                     {
//                         lv_obj_clear_flag(guider_ui.file_management_sd_label_2, LV_OBJ_FLAG_HIDDEN);        //文件1
//                         lv_label_set_text(guider_ui.file_management_sd_label_3, dis_file_info[0].name);     //文件名
//                         lv_label_set_text(guider_ui.file_management_sd_label_4, dis_file_info[0].estime);   //预计时间
//                         lv_label_set_text(guider_ui.file_management_sd_label_5, dis_file_info[0].filament); //所需耗材
//                         if(dis_file_info[0].photo[0] == '\0')
//                         {
//     //                    lv_img_set_src(guider_ui.file_management_img_6, &xiaowei96);
//                         }
//                         else
//                         {
//                             lv_img_set_src(guider_ui.file_management_sd_img_6, dis_file_info[0].photo);
//                         }
//                     }

//                 }
//                 break;
//             case 2:
//                 {
//                     if(i == 0)
//                     {
//                         lv_obj_clear_flag(guider_ui.file_management_label_6, LV_OBJ_FLAG_HIDDEN);        //文件2
//                         lv_label_set_text(guider_ui.file_management_label_7, dis_file_info[1].name);     //文件名
//                         lv_label_set_text(guider_ui.file_management_label_8, dis_file_info[1].estime);   //预计时间
//                         lv_label_set_text(guider_ui.file_management_label_9, dis_file_info[1].filament); //所需耗材
//                         if(dis_file_info[1].photo[0] == '\0')
//                         {
//         //                    lv_img_set_src(guider_ui.file_management_img_9, &xiaowei96);
//                         }
//                         else
//                         {
//                             lv_img_set_src(guider_ui.file_management_img_9, dis_file_info[1].photo);
//                         }
//                     }
//                     if(i == 1)
//                     {
//                         lv_obj_clear_flag(guider_ui.file_management_sd_label_6, LV_OBJ_FLAG_HIDDEN);        //文件2
//                         lv_label_set_text(guider_ui.file_management_sd_label_7, dis_file_info[1].name);     //文件名
//                         lv_label_set_text(guider_ui.file_management_sd_label_8, dis_file_info[1].estime);   //预计时间
//                         lv_label_set_text(guider_ui.file_management_sd_label_9, dis_file_info[1].filament); //所需耗材
//                         if(dis_file_info[1].photo[0] == '\0')
//                         {
//         //                    lv_img_set_src(guider_ui.file_management_img_9, &xiaowei96);
//                         }
//                         else
//                         {
//                             lv_img_set_src(guider_ui.file_management_sd_img_9, dis_file_info[1].photo);
//                         }
//                     }
//                 }
//                 break;
//             case 3:
//                 {
//                     if(i == 0)
//                     {
//                         lv_obj_clear_flag(guider_ui.file_management_label_10, LV_OBJ_FLAG_HIDDEN);       //文件3
//                         lv_label_set_text(guider_ui.file_management_label_14, dis_file_info[2].name);     //文件名
//                         lv_label_set_text(guider_ui.file_management_label_15, dis_file_info[2].estime);   //预计时间
//                         lv_label_set_text(guider_ui.file_management_label_16, dis_file_info[2].filament); //所需耗材
//                         if(dis_file_info[2].photo[0] == '\0')
//                         {
//         //                    lv_img_set_src(guider_ui.file_management_img_12, &xiaowei96);
//                         }
//                         else
//                         {
//                             lv_img_set_src(guider_ui.file_management_img_12, dis_file_info[2].photo);
//                         }
//                     }
//                     if(i == 1)
//                     {
//                         lv_obj_clear_flag(guider_ui.file_management_sd_label_10, LV_OBJ_FLAG_HIDDEN);       //文件3
//                         lv_label_set_text(guider_ui.file_management_sd_label_14, dis_file_info[2].name);     //文件名
//                         lv_label_set_text(guider_ui.file_management_sd_label_15, dis_file_info[2].estime);   //预计时间
//                         lv_label_set_text(guider_ui.file_management_sd_label_16, dis_file_info[2].filament); //所需耗材
//                         if(dis_file_info[2].photo[0] == '\0')
//                         {
//         //                    lv_img_set_src(guider_ui.file_management_img_12, &xiaowei96);
//                         }
//                         else
//                         {
//                             lv_img_set_src(guider_ui.file_management_sd_img_12, dis_file_info[2].photo);
//                         }
//                     }
//                 }
//                 break;
//             case 4:
//                 {
//                     if(i == 0)
//                     {
//                         lv_obj_clear_flag(guider_ui.file_management_label_11, LV_OBJ_FLAG_HIDDEN);        //文件1
//                         lv_label_set_text(guider_ui.file_management_label_17, dis_file_info[3].name);     //文件名
//                         lv_label_set_text(guider_ui.file_management_label_18, dis_file_info[3].estime);   //预计时间
//                         lv_label_set_text(guider_ui.file_management_label_19, dis_file_info[3].filament); //所需耗材
//                         if(dis_file_info[3].photo[0] == '\0')
//                         {
//     //                    lv_img_set_src(guider_ui.file_management_img_15, &xiaowei96);
//                         }
//                         else
//                         {
//                             lv_img_set_src(guider_ui.file_management_img_15, dis_file_info[3].photo);
//                         }
//                     }
//                     if(i == 1)
//                     {
//                         lv_obj_clear_flag(guider_ui.file_management_sd_label_11, LV_OBJ_FLAG_HIDDEN);        //文件1
//                         lv_label_set_text(guider_ui.file_management_sd_label_17, dis_file_info[3].name);     //文件名
//                         lv_label_set_text(guider_ui.file_management_sd_label_18, dis_file_info[3].estime);   //预计时间
//                         lv_label_set_text(guider_ui.file_management_sd_label_19, dis_file_info[3].filament); //所需耗材
//                         if(dis_file_info[3].photo[0] == '\0')
//                         {
//     //                    lv_img_set_src(guider_ui.file_management_img_15, &xiaowei96);
//                         }
//                         else
//                         {
//                             lv_img_set_src(guider_ui.file_management_sd_img_15, dis_file_info[3].photo);
//                         }
//                     }
//                 }
//                 break;
//             case 5:
//                 {
//                     if(i == 0)
//                     {
//                         lv_obj_clear_flag(guider_ui.file_management_label_12, LV_OBJ_FLAG_HIDDEN);        //文件5
//                         lv_label_set_text(guider_ui.file_management_label_20, dis_file_info[4].name);
//                         lv_label_set_text(guider_ui.file_management_label_21, dis_file_info[4].estime);
//                         lv_label_set_text(guider_ui.file_management_label_22, dis_file_info[4].filesize);
//                         if(dis_file_info[4].photo[0] == '\0')
//                         {
//     //                    lv_img_set_src(guider_ui.file_management_img_18, &xiaowei96);
//                         }
//                         else
//                         {
//                             lv_img_set_src(guider_ui.file_management_img_18, dis_file_info[4].photo);
//                         }
//                     }
//                     if(i == 1)
//                     {
//                         lv_obj_clear_flag(guider_ui.file_management_sd_label_12, LV_OBJ_FLAG_HIDDEN);        //文件5
//                         lv_label_set_text(guider_ui.file_management_sd_label_20, dis_file_info[4].name);
//                         lv_label_set_text(guider_ui.file_management_sd_label_21, dis_file_info[4].estime);
//                         lv_label_set_text(guider_ui.file_management_sd_label_22, dis_file_info[4].filesize);
//                         if(dis_file_info[4].photo[0] == '\0')
//                         {
//     //                    lv_img_set_src(guider_ui.file_management_img_18, &xiaowei96);
//                         }
//                         else
//                         {
//                             lv_img_set_src(guider_ui.file_management_sd_img_18, dis_file_info[4].photo);
//                         }
//                     }
//                 }
//                 break;
//             case 6:
//                 {
//                     if(i == 0)
//                     {
//                         lv_obj_clear_flag(guider_ui.file_management_label_13, LV_OBJ_FLAG_HIDDEN);        //文件4缩略图
//                         lv_label_set_text(guider_ui.file_management_label_23, dis_file_info[5].name);
//                         lv_label_set_text(guider_ui.file_management_label_24, dis_file_info[5].estime);
//                         lv_label_set_text(guider_ui.file_management_label_25, dis_file_info[5].filesize);
//                         if(dis_file_info[5].photo[0] == '\0')
//                         {
//     //                    lv_img_set_src(guider_ui.file_management_img_21, &xiaowei96);
//                         }
//                         else
//                         {
//                             lv_img_set_src(guider_ui.file_management_img_21, dis_file_info[5].photo);
//                         }
//                     }
//                     if(i == 1)
//                     {
//                         lv_obj_clear_flag(guider_ui.file_management_sd_label_13, LV_OBJ_FLAG_HIDDEN);        //文件4缩略图
//                         lv_label_set_text(guider_ui.file_management_sd_label_23, dis_file_info[5].name);
//                         lv_label_set_text(guider_ui.file_management_sd_label_24, dis_file_info[5].estime);
//                         lv_label_set_text(guider_ui.file_management_sd_label_25, dis_file_info[5].filesize);
//                         if(dis_file_info[5].photo[0] == '\0')
//                         {
//     //                    lv_img_set_src(guider_ui.file_management_img_21, &xiaowei96);
//                         }
//                         else
//                         {
//                             lv_img_set_src(guider_ui.file_management_sd_img_21, dis_file_info[5].photo);
//                         }
//                     }
//                 }
//                 break;
//             default:
//                 break;
//             }
//             temp = strtok(NULL,"\t");
//         }
//     }
// //    set_print_file_nums();
// }

// void showhistoryfile(char *data,int len)
// {
// //    print_file_ok = true;
//     if(len == 0)
//     {
//           historyfile_pages = 0;
//     }
//     else
//     {
//         char histtory_filecount = 0;    //打印历史记录数量
//         unsigned char cnt  = 0;
//         unsigned char data_flag;       //当前解析的数据标志(第几个什么内容)

//         //每次展示前都将文件控件隐藏
//         lv_obj_add_flag(guider_ui.file_management_history_label_3, LV_OBJ_FLAG_HIDDEN);      //文件1
//         lv_obj_add_flag(guider_ui.file_management_history_label_4, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.file_management_history_label_5, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.file_management_history_btn_3, LV_OBJ_FLAG_HIDDEN);       //
//         lv_obj_add_flag(guider_ui.file_management_history_img_8, LV_OBJ_FLAG_HIDDEN);       //

//         lv_obj_add_flag(guider_ui.file_management_history_label_11, LV_OBJ_FLAG_HIDDEN);      //文件2
//         lv_obj_add_flag(guider_ui.file_management_history_label_15, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.file_management_history_label_19, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.file_management_history_btn_4, LV_OBJ_FLAG_HIDDEN);        //
//         lv_obj_add_flag(guider_ui.file_management_history_img_9, LV_OBJ_FLAG_HIDDEN);       //

//         lv_obj_add_flag(guider_ui.file_management_history_label_12,LV_OBJ_FLAG_HIDDEN);      //文件3
//         lv_obj_add_flag(guider_ui.file_management_history_label_16, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.file_management_history_label_20, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.file_management_history_btn_5, LV_OBJ_FLAG_HIDDEN);        //
//         lv_obj_add_flag(guider_ui.file_management_history_img_10, LV_OBJ_FLAG_HIDDEN);       //

//         lv_obj_add_flag(guider_ui.file_management_history_label_13, LV_OBJ_FLAG_HIDDEN);      //文件4
//         lv_obj_add_flag(guider_ui.file_management_history_label_17, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.file_management_history_label_21, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.file_management_history_btn_6, LV_OBJ_FLAG_HIDDEN);        //
//         lv_obj_add_flag(guider_ui.file_management_history_img_11, LV_OBJ_FLAG_HIDDEN);       //

//         lv_obj_add_flag(guider_ui.file_management_history_label_14, LV_OBJ_FLAG_HIDDEN);      //文件5
//         lv_obj_add_flag(guider_ui.file_management_history_label_18, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.file_management_history_label_22, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.file_management_history_btn_7, LV_OBJ_FLAG_HIDDEN);        //
//         lv_obj_add_flag(guider_ui.file_management_history_img_12, LV_OBJ_FLAG_HIDDEN);       //

//         CrLogI("history list is :%s.",data);
//         char *temp = strtok(data,"\t");
//         memset(history_file_list,'\0',sizeof(history_file_list));
//         while(temp)
//         {
//             histtory_filecount++;
//             if(histtory_filecount > HISTORY_NUM_PRE_PAGE)
//             {
//                 break;
//             }

//             cnt = 0;
//             data_flag = 0;

//             while(*temp)
//             {
//                 if(*temp == '\0')
//                     break;

//                 if(*temp == ':')
//                 {
//                     switch(data_flag)
//                     {
//                         case 0:history_file_list[histtory_filecount - 1].name[cnt] = '\0';break;
//                         case 1:history_file_list[histtory_filecount - 1].photo[cnt] = '\0';break;
//                         case 2:history_file_list[histtory_filecount - 1].history_printtime[cnt] = '\0';break;
//                         case 3:history_file_list[histtory_filecount - 1].length_of_time[cnt] = '\0';break;
//                         case 4:history_file_list[histtory_filecount - 1].print_result[cnt] = '\0';break;
//                         case 5:history_file_list[histtory_filecount - 1].file_state[cnt] = '\0';break;
//                     }
//                     data_flag++;
//                     temp++;
//                     cnt = 0;
//                     continue;
//                 }
//                 switch(data_flag)
//                 {
//                     case 0:if(cnt < FILE_SIZE)history_file_list[histtory_filecount - 1].name[cnt++] = *temp;break;
//                     case 1:if(cnt < FILE_PHOTO_SIZE)history_file_list[histtory_filecount - 1].photo[cnt++] = *temp;break;
//                     case 2:if(cnt < FILE_SIZE)history_file_list[histtory_filecount - 1].history_printtime[cnt++] = *temp;break;
//                     case 3:if(cnt < FILAMENT_SIZE)history_file_list[histtory_filecount - 1].length_of_time[cnt++] = *temp;break;
//                     case 4:if(cnt < FILE_TYPE)history_file_list[histtory_filecount - 1].print_result[cnt++] = *temp;break;
//                     case 5:if(cnt < FILE_TYPE)history_file_list[histtory_filecount - 1].file_state[cnt++] = *temp;break;
//                 }
//                 temp++;
//             }
//             history_file_list[histtory_filecount - 1].file_state[cnt] = '\0';
//             CrLogI("history name:%s.",history_file_list[histtory_filecount - 1].name);
//             CrLogI("photosrc:%s.",history_file_list[histtory_filecount - 1].photo);
//             CrLogI("history_printtime:%s.",history_file_list[histtory_filecount - 1].history_printtime);
//             CrLogI("length_of_time:%s.",history_file_list[histtory_filecount - 1].length_of_time);
//             CrLogI("print_result:%s.",history_file_list[histtory_filecount - 1].print_result);
//             CrLogI("file_state:%s.",history_file_list[histtory_filecount - 1].file_state);

//             switch(histtory_filecount)
//             {
//                 case 1:
//                 {
//                     lv_obj_clear_flag(guider_ui.file_management_history_label_3, LV_OBJ_FLAG_HIDDEN);      //文件1
//                     lv_obj_clear_flag(guider_ui.file_management_history_label_4, LV_OBJ_FLAG_HIDDEN);     //
//                     lv_obj_clear_flag(guider_ui.file_management_history_label_5, LV_OBJ_FLAG_HIDDEN);     //
//                     lv_obj_clear_flag(guider_ui.file_management_history_btn_3, LV_OBJ_FLAG_HIDDEN);       //
//                     lv_obj_clear_flag(guider_ui.file_management_history_img_8, LV_OBJ_FLAG_HIDDEN);       //
//                     lv_label_set_text(guider_ui.file_management_history_label_3, history_file_list[0].name);     //文件名
//                     time_t timesteamp = atol(history_file_list[0].history_printtime);
//                     struct tm *CurTime = localtime(&timesteamp);
//                     char timepath[512] = {0};
//                     snprintf(timepath , sizeof(timepath) ,"%d-%02d-%02d_%02d:%02d",
//                                 CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
//                                 CurTime->tm_hour, CurTime->tm_min);
//                     lv_label_set_text(guider_ui.file_management_history_label_4, timepath);   //打印时间
//                     lv_label_set_text(guider_ui.file_management_history_label_5, history_file_list[0].length_of_time);      //打印时长
//                     if(history_file_list[0].photo[0] == '\0')
//                     {
//     //                  lv_img_set_src(guider_ui.file_management_history_img_8, &xiaowei96);
//                     }
//                     else
//                         lv_img_set_src(guider_ui.file_management_history_img_8, history_file_list[0].photo);
//                     if(history_file_list[0].file_state[0] != '1')
//                         lv_obj_set_style_text_color(guider_ui.file_management_history_btn_3_label, lv_color_make(0x83, 0x86, 0x8B), LV_STATE_DEFAULT);
//                     else
//                         lv_obj_set_style_text_color(guider_ui.file_management_history_btn_3_label, lv_color_make(0x42, 0xBD, 0xD8), LV_STATE_DEFAULT);
//                     break;
//                 }
//                 case 2:
//                 {
//                     lv_obj_clear_flag(guider_ui.file_management_history_label_11, LV_OBJ_FLAG_HIDDEN);      //文件2
//                     lv_obj_clear_flag(guider_ui.file_management_history_label_15, LV_OBJ_FLAG_HIDDEN);     //
//                     lv_obj_clear_flag(guider_ui.file_management_history_label_19, LV_OBJ_FLAG_HIDDEN);     //
//                     lv_obj_clear_flag(guider_ui.file_management_history_btn_4, LV_OBJ_FLAG_HIDDEN);        //
//                     lv_obj_clear_flag(guider_ui.file_management_history_img_9, LV_OBJ_FLAG_HIDDEN);        //
//                     lv_label_set_text(guider_ui.file_management_history_label_11, history_file_list[1].name);     //文件名
//                     time_t timesteamp = atol(history_file_list[1].history_printtime);
//                     struct tm *CurTime = localtime(&timesteamp);
//                     char timepath[512] = {0};
//                     snprintf(timepath , sizeof(timepath) ,"%d-%02d-%02d_%02d:%02d",
//                                 CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
//                                 CurTime->tm_hour, CurTime->tm_min);
//                     lv_label_set_text(guider_ui.file_management_history_label_15, timepath);   //打印时间
//                     lv_label_set_text(guider_ui.file_management_history_label_19, history_file_list[1].length_of_time); //打印时长
//                     if(history_file_list[1].photo[0] == '\0')
//                     {
//             //            lv_img_set_src(guider_ui.file_management_img_9, &xiaowei96);
//                     }
//                     else
//                         lv_img_set_src(guider_ui.file_management_history_img_9, history_file_list[1].photo);
//                     if(history_file_list[1].file_state[0] != '1')
//                         lv_obj_add_style(guider_ui.file_management_history_btn_4_label,&style_grey24_text_default,LV_PART_MAIN|LV_STATE_DEFAULT);
//                     break;
//                 }
//                 case 3:
//                 {
//                     lv_obj_clear_flag(guider_ui.file_management_history_label_12, LV_OBJ_FLAG_HIDDEN);      //文件3
//                     lv_obj_clear_flag(guider_ui.file_management_history_label_16, LV_OBJ_FLAG_HIDDEN);     //
//                     lv_obj_clear_flag(guider_ui.file_management_history_label_20, LV_OBJ_FLAG_HIDDEN);     //
//                     lv_obj_clear_flag(guider_ui.file_management_history_btn_5, LV_OBJ_FLAG_HIDDEN);        //
//                     lv_obj_clear_flag(guider_ui.file_management_history_img_10, LV_OBJ_FLAG_HIDDEN);       //
//                     lv_label_set_text(guider_ui.file_management_history_label_12, history_file_list[2].name);     //文件名
//                     time_t timesteamp = atol(history_file_list[2].history_printtime);
//                     struct tm *CurTime = localtime(&timesteamp);
//                     char timepath[512] = {0};
//                     snprintf(timepath , sizeof(timepath) ,"%d-%02d-%02d_%02d:%02d",
//                                 CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
//                                 CurTime->tm_hour, CurTime->tm_min);
//                     lv_label_set_text(guider_ui.file_management_history_label_16, timepath);   //打印时间
//                     lv_label_set_text(guider_ui.file_management_history_label_20, history_file_list[2].length_of_time); //所需耗材
//                     if(history_file_list[2].photo[0] == '\0')
//                     {
//             //            lv_img_set_src(guider_ui.file_management_img_12, &xiaowei96);
//                     }
//                     else
//                         lv_img_set_src(guider_ui.file_management_history_img_10, history_file_list[2].photo);
//                     if(history_file_list[2].file_state[0] != '1')
//                         lv_obj_add_style(guider_ui.file_management_history_btn_5_label,&style_grey24_text_default,LV_PART_MAIN|LV_STATE_DEFAULT);
//                     break;
//                 }
//                 case 4:
//                 {
//                     lv_obj_clear_flag(guider_ui.file_management_history_label_13, LV_OBJ_FLAG_HIDDEN);      //文件4
//                     lv_obj_clear_flag(guider_ui.file_management_history_label_17, LV_OBJ_FLAG_HIDDEN);     //
//                     lv_obj_clear_flag(guider_ui.file_management_history_label_21, LV_OBJ_FLAG_HIDDEN);     //
//                     lv_obj_clear_flag(guider_ui.file_management_history_btn_6, LV_OBJ_FLAG_HIDDEN);        //
//                     lv_obj_clear_flag(guider_ui.file_management_history_img_11, LV_OBJ_FLAG_HIDDEN);       //
//                     lv_label_set_text(guider_ui.file_management_history_label_13, history_file_list[3].name);     //文件名
//                     time_t timesteamp = atol(history_file_list[3].history_printtime);
//                     struct tm *CurTime = localtime(&timesteamp);
//                     char timepath[512] = {0};
//                     snprintf(timepath , sizeof(timepath) ,"%d-%02d-%02d_%02d:%02d",
//                                 CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
//                                 CurTime->tm_hour, CurTime->tm_min);
//                     lv_label_set_text(guider_ui.file_management_history_label_17, timepath);   //打印时间
//                     lv_label_set_text(guider_ui.file_management_history_label_21, history_file_list[3].length_of_time); //所需耗材
//                     if(history_file_list[3].photo[0] == '\0')
//                     {
// //                        lv_img_set_src(guider_ui.file_management_img_15, &xiaowei96);
//                     }
//                     else
//                         lv_img_set_src(guider_ui.file_management_history_img_11, history_file_list[3].photo);
//                     if(history_file_list[3].file_state[0] != '1')
//                         lv_obj_add_style(guider_ui.file_management_history_btn_6_label,&style_grey24_text_default,LV_PART_MAIN|LV_STATE_DEFAULT);
//                     break;
//                 }
//                 case 5:
//                 {
//                     lv_obj_clear_flag(guider_ui.file_management_history_label_14, LV_OBJ_FLAG_HIDDEN);      //文件5
//                     lv_obj_clear_flag(guider_ui.file_management_history_label_18, LV_OBJ_FLAG_HIDDEN);     //
//                     lv_obj_clear_flag(guider_ui.file_management_history_label_22, LV_OBJ_FLAG_HIDDEN);     //
//                     lv_obj_clear_flag(guider_ui.file_management_history_btn_7, LV_OBJ_FLAG_HIDDEN);        //
//                     lv_obj_clear_flag(guider_ui.file_management_history_img_12, LV_OBJ_FLAG_HIDDEN);       //
//                     lv_label_set_text(guider_ui.file_management_history_label_14, history_file_list[4].name);
//                     time_t timesteamp = atol(history_file_list[4].history_printtime);
//                     struct tm *CurTime = localtime(&timesteamp);
//                     char timepath[512] = {0};
//                     snprintf(timepath , sizeof(timepath) ,"%d-%02d-%02d_%02d:%02d",
//                                 CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
//                                 CurTime->tm_hour, CurTime->tm_min);
//                     lv_label_set_text(guider_ui.file_management_history_label_18, timepath);   //打印时间
//                     lv_label_set_text(guider_ui.file_management_history_label_22, history_file_list[4].length_of_time);
//                     if(history_file_list[4].photo[0] == '\0')
//                     {
//         //            lv_img_set_src(guider_ui.file_management_img_18, &xiaowei96);
//                     }
//                     else
//                         lv_img_set_src(guider_ui.file_management_history_img_12, history_file_list[4].photo);
//                     if(history_file_list[4].file_state[0] != '1')
//                         lv_obj_add_style(guider_ui.file_management_history_btn_7_label,&style_grey24_text_default,LV_PART_MAIN|LV_STATE_DEFAULT);
//                     break;
//                 }
//                 default:
//                     break;
//             }
//             temp = strtok(NULL,"\t");
//         }
//     }
// }

// void showvideolistfile(char *data,int len)
// {
// //    print_file_ok = true;
//     if(len == 0)
//     {
//           videolist_pages = 0;
//     }
//     else
//     {
//         char videolist_filecount = 0;    //打印历史记录数量
//         unsigned char cnt  = 0;
//         unsigned char data_flag;       //当前解析的数据标志(第几个什么内容)

//         //每次展示前都将文件控件隐藏
//         lv_obj_add_flag(guider_ui.video_list_img_2, LV_OBJ_FLAG_HIDDEN);        //文件1
//         lv_obj_add_flag(guider_ui.video_list_label_4, LV_OBJ_FLAG_HIDDEN);      //
//         lv_obj_add_flag(guider_ui.video_list_label_5, LV_OBJ_FLAG_HIDDEN);      //
//         lv_obj_add_flag(guider_ui.video_list_label_6, LV_OBJ_FLAG_HIDDEN);      //
//         lv_obj_add_flag(guider_ui.video_list_img_9, LV_OBJ_FLAG_HIDDEN);        //

//         lv_obj_add_flag(guider_ui.video_list_img_3, LV_OBJ_FLAG_HIDDEN);        //文件2
//         lv_obj_add_flag(guider_ui.video_list_label_7, LV_OBJ_FLAG_HIDDEN);      //
//         lv_obj_add_flag(guider_ui.video_list_label_8, LV_OBJ_FLAG_HIDDEN);      //
//         lv_obj_add_flag(guider_ui.video_list_label_9, LV_OBJ_FLAG_HIDDEN);      //
//         lv_obj_add_flag(guider_ui.video_list_img_10, LV_OBJ_FLAG_HIDDEN);       //

//         lv_obj_add_flag(guider_ui.video_list_img_4, LV_OBJ_FLAG_HIDDEN);        //文件3
//         lv_obj_add_flag(guider_ui.video_list_label_10, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.video_list_label_11, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.video_list_label_12, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.video_list_img_11, LV_OBJ_FLAG_HIDDEN);       //

//         lv_obj_add_flag(guider_ui.video_list_img_5, LV_OBJ_FLAG_HIDDEN);        //文件4
//         lv_obj_add_flag(guider_ui.video_list_label_13, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.video_list_label_14, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.video_list_label_15, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.video_list_img_12, LV_OBJ_FLAG_HIDDEN);       //

//         lv_obj_add_flag(guider_ui.video_list_img_6, LV_OBJ_FLAG_HIDDEN);        //文件5
//         lv_obj_add_flag(guider_ui.video_list_label_16, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.video_list_label_17, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.video_list_label_18, LV_OBJ_FLAG_HIDDEN);     //
//         lv_obj_add_flag(guider_ui.video_list_img_13, LV_OBJ_FLAG_HIDDEN);       //

//         CrLogI("video list is :%s.",data);
//         char *temp = strtok(data,"\t");
//         memset(video_file_list,'\0',sizeof(video_file_list));
//         while(temp)
//         {
//             videolist_filecount++;
//             if(videolist_filecount > VIDEO_NUM_PRE_PAGE)
//             {
//                 break;
//             }

//             cnt = 0;
//             data_flag = 0;

//             while(*temp)
//             {
//                 if(*temp == '\0')
//                     break;

//                 if(*temp == ':')
//                 {
//                     switch(data_flag)
//                     {
//                         case 0:video_file_list[videolist_filecount - 1].name[cnt] = '\0';break;
//                         case 1:video_file_list[videolist_filecount - 1].print_time[cnt] = '\0';break;
//                         case 2:video_file_list[videolist_filecount - 1].length_of_time[cnt] = '\0';break;
//                         case 3:video_file_list[videolist_filecount - 1].length_of_video[cnt] = '\0';break;
//                         case 4:video_file_list[videolist_filecount - 1].photo_position[cnt] = '\0';break;
//                         case 5:video_file_list[videolist_filecount - 1].photo_freq[cnt] = '\0';break;
//                         case 6:video_file_list[videolist_filecount - 1].render_mode[cnt] = '\0';break;
//                         case 7:video_file_list[videolist_filecount - 1].photo[cnt] = '\0';break;
//                     }
//                     data_flag++;
//                     temp++;
//                     cnt = 0;
//                     continue;
//                 }
//                 switch(data_flag)
//                 {
//                     case 0:if(cnt < FILE_PHOTO_SIZE)video_file_list[videolist_filecount - 1].name[cnt++] = *temp;break;
//                     case 1:if(cnt < FILE_SIZE)video_file_list[videolist_filecount - 1].print_time[cnt++] = *temp;break;
//                     case 2:if(cnt < FILE_SIZE)video_file_list[videolist_filecount - 1].length_of_time[cnt++] = *temp;break;
//                     case 3:if(cnt < FILE_SIZE)video_file_list[videolist_filecount - 1].length_of_video[cnt++] = *temp;break;
//                     case 4:if(cnt < FILAMENT_SIZE)video_file_list[videolist_filecount - 1].photo_position[cnt++] = *temp;break;
//                     case 5:if(cnt < FILAMENT_SIZE)video_file_list[videolist_filecount - 1].photo_freq[cnt++] = *temp;break;
//                     case 6:if(cnt < FILAMENT_SIZE)video_file_list[videolist_filecount - 1].render_mode[cnt++] = *temp;break;
//                     case 7:if(cnt < FILE_PHOTO_SIZE)video_file_list[videolist_filecount - 1].photo[cnt++] = *temp;break;
//                 }
//                 temp++;
//             }
//             video_file_list[videolist_filecount - 1].photo[cnt] = '\0';
//             CrLogI("video name:%s.",video_file_list[videolist_filecount - 1].name);
//             CrLogI("print_time:%s.",video_file_list[videolist_filecount - 1].print_time);
//             CrLogI("length_of_time:%s.",video_file_list[videolist_filecount - 1].length_of_time);
//             CrLogI("length_of_video:%s.",video_file_list[videolist_filecount - 1].length_of_video);
//             CrLogI("photo_position:%s.",video_file_list[videolist_filecount - 1].photo_position);
//             CrLogI("photo_freq:%s.",video_file_list[videolist_filecount - 1].photo_freq);
//             CrLogI("render_mode:%s.",video_file_list[videolist_filecount - 1].render_mode);
//             CrLogI("photo:%s.",video_file_list[videolist_filecount - 1].photo);

//             switch(videolist_filecount)
//             {
//                 case 1:
//                 {
//                     lv_obj_clear_flag(guider_ui.video_list_img_2, LV_OBJ_FLAG_HIDDEN);        //文件1
//                     lv_obj_clear_flag(guider_ui.video_list_label_4, LV_OBJ_FLAG_HIDDEN);      //
//                     lv_obj_clear_flag(guider_ui.video_list_label_5, LV_OBJ_FLAG_HIDDEN);      //
//                     lv_obj_clear_flag(guider_ui.video_list_label_6, LV_OBJ_FLAG_HIDDEN);      //
//                     lv_obj_clear_flag(guider_ui.video_list_img_9, LV_OBJ_FLAG_HIDDEN);        //
//                     //视频名
//                     lv_label_set_text(guider_ui.video_list_label_4, video_file_list[0].name);
//                     //打印时长
//                     char temp[30] = {0};
//                     snprintf(temp,30,"打印时长:%.1fh",atoi(video_file_list[0].length_of_time)/3600.0);
//                     CrLogI("log:%s",temp);
//                     lv_label_set_text(guider_ui.video_list_label_5, temp);
//                     //开始时间
//                     time_t timesteamp = atol(video_file_list[0].print_time);
//                     struct tm *CurTime = localtime(&timesteamp);
//                     char timepath[512] = {0};
//                     snprintf(timepath , sizeof(timepath) ,"%d-%02d-%02d_%02d:%02d",
//                                 CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
//                                 CurTime->tm_hour, CurTime->tm_min);
//                     lv_label_set_text(guider_ui.video_list_label_6, timepath);
//                     //视频图片
//                     if(video_file_list[0].photo[0] == '\0')
//                     {
//     //                  lv_img_set_src(guider_ui.video_list_img_2, &xiaowei96);
//                     }
//                     else
//                         lv_img_set_src(guider_ui.video_list_img_2, video_file_list[0].photo);
//                     break;
//                 }
//                 case 2:
//                 {
//                     lv_obj_clear_flag(guider_ui.video_list_img_3, LV_OBJ_FLAG_HIDDEN);        //文件2
//                     lv_obj_clear_flag(guider_ui.video_list_label_7, LV_OBJ_FLAG_HIDDEN);      //
//                     lv_obj_clear_flag(guider_ui.video_list_label_8, LV_OBJ_FLAG_HIDDEN);      //
//                     lv_obj_clear_flag(guider_ui.video_list_label_9, LV_OBJ_FLAG_HIDDEN);      //
//                     lv_obj_clear_flag(guider_ui.video_list_img_10, LV_OBJ_FLAG_HIDDEN);       //

//                     //视频名
//                     lv_label_set_text(guider_ui.video_list_label_7, video_file_list[1].name);
//                     //打印时长
//                     char temp[30] = {0};
//                     snprintf(temp,30,"打印时长:%.1fh",atoi(video_file_list[1].length_of_time)/3600.0);
//                     CrLogI("log:%s",temp);
//                     lv_label_set_text(guider_ui.video_list_label_8, temp);
//                     //开始时间
//                     time_t timesteamp = atol(video_file_list[1].print_time);
//                     struct tm *CurTime = localtime(&timesteamp);
//                     char timepath[512] = {0};
//                     snprintf(timepath , sizeof(timepath) ,"%d-%02d-%02d_%02d:%02d",
//                                 CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
//                                 CurTime->tm_hour, CurTime->tm_min);
//                     lv_label_set_text(guider_ui.video_list_label_9, timepath);
//                     //视频图片
//                     if(video_file_list[1].photo[0] == '\0')
//                     {
//     //                  lv_img_set_src(guider_ui.video_list_img_3, &xiaowei96);
//                     }
//                     else
//                         lv_img_set_src(guider_ui.video_list_img_3, video_file_list[1].photo);
//                     break;
//                 }
//                 case 3:
//                 {
//                     lv_obj_clear_flag(guider_ui.video_list_img_4, LV_OBJ_FLAG_HIDDEN);        //文件3
//                     lv_obj_clear_flag(guider_ui.video_list_label_10, LV_OBJ_FLAG_HIDDEN);      //
//                     lv_obj_clear_flag(guider_ui.video_list_label_11, LV_OBJ_FLAG_HIDDEN);      //
//                     lv_obj_clear_flag(guider_ui.video_list_label_12, LV_OBJ_FLAG_HIDDEN);      //
//                     lv_obj_clear_flag(guider_ui.video_list_img_11, LV_OBJ_FLAG_HIDDEN);       //

//                     //视频名
//                     lv_label_set_text(guider_ui.video_list_label_10, video_file_list[2].name);
//                     //打印时长
//                     char temp[30] = {0};
//                     snprintf(temp,30,"打印时长:%.1fh",atoi(video_file_list[2].length_of_time)/3600.0);
//                     CrLogI("log:%s",temp);
//                     lv_label_set_text(guider_ui.video_list_label_11, temp);
//                     //开始时间
//                     time_t timesteamp = atol(video_file_list[2].print_time);
//                     struct tm *CurTime = localtime(&timesteamp);
//                     char timepath[512] = {0};
//                     snprintf(timepath , sizeof(timepath) ,"%d-%02d-%02d_%02d:%02d",
//                                 CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
//                                 CurTime->tm_hour, CurTime->tm_min);
//                     lv_label_set_text(guider_ui.video_list_label_12, timepath);
//                     //视频图片
//                     if(video_file_list[2].photo[0] == '\0')
//                     {
//     //                  lv_img_set_src(guider_ui.video_list_img_4, &xiaowei96);
//                     }
//                     else
//                         lv_img_set_src(guider_ui.video_list_img_4, video_file_list[2].photo);
//                     break;
//                 }
//                 case 4:
//                 {
//                     lv_obj_clear_flag(guider_ui.video_list_img_5, LV_OBJ_FLAG_HIDDEN);        //文件3
//                     lv_obj_clear_flag(guider_ui.video_list_label_13, LV_OBJ_FLAG_HIDDEN);      //
//                     lv_obj_clear_flag(guider_ui.video_list_label_14, LV_OBJ_FLAG_HIDDEN);      //
//                     lv_obj_clear_flag(guider_ui.video_list_label_15, LV_OBJ_FLAG_HIDDEN);      //
//                     lv_obj_clear_flag(guider_ui.video_list_img_12, LV_OBJ_FLAG_HIDDEN);       //

//                     //视频名
//                     lv_label_set_text(guider_ui.video_list_label_13, video_file_list[3].name);
//                     //打印时长
//                     char temp[30] = {0};
//                     snprintf(temp,30,"打印时长:%.1fh",atoi(video_file_list[3].length_of_time)/3600.0);
//                     CrLogI("log:%s",temp);
//                     lv_label_set_text(guider_ui.video_list_label_14, temp);
//                     //开始时间
//                     time_t timesteamp = atol(video_file_list[3].print_time);
//                     struct tm *CurTime = localtime(&timesteamp);
//                     char timepath[512] = {0};
//                     snprintf(timepath , sizeof(timepath) ,"%d-%02d-%02d_%02d:%02d",
//                                 CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
//                                 CurTime->tm_hour, CurTime->tm_min);
//                     lv_label_set_text(guider_ui.video_list_label_15, timepath);
//                     //视频图片
//                     if(video_file_list[3].photo[0] == '\0')
//                     {
//     //                  lv_img_set_src(guider_ui.video_list_img_5, &xiaowei96);
//                     }
//                     else
//                         lv_img_set_src(guider_ui.video_list_img_5, video_file_list[3].photo);
//                     break;
//                 }
//                 case 5:
//                 {
//                     lv_obj_clear_flag(guider_ui.video_list_img_6, LV_OBJ_FLAG_HIDDEN);        //文件3
//                     lv_obj_clear_flag(guider_ui.video_list_label_16, LV_OBJ_FLAG_HIDDEN);      //
//                     lv_obj_clear_flag(guider_ui.video_list_label_17, LV_OBJ_FLAG_HIDDEN);      //
//                     lv_obj_clear_flag(guider_ui.video_list_label_18, LV_OBJ_FLAG_HIDDEN);      //
//                     lv_obj_clear_flag(guider_ui.video_list_img_13, LV_OBJ_FLAG_HIDDEN);       //

//                     //视频名
//                     lv_label_set_text(guider_ui.video_list_label_16, video_file_list[4].name);
//                     //打印时长
//                     char temp[30] = {0};
//                     snprintf(temp,30,"打印时长:%.1fh",atoi(video_file_list[4].length_of_time)/3600.0);
//                     CrLogI("log:%s",temp);
//                     lv_label_set_text(guider_ui.video_list_label_17, temp);
//                     //开始时间
//                     time_t timesteamp = atol(video_file_list[4].print_time);
//                     struct tm *CurTime = localtime(&timesteamp);
//                     char timepath[512] = {0};
//                     snprintf(timepath , sizeof(timepath) ,"%d-%02d-%02d_%02d:%02d",
//                                 CurTime->tm_year + 1900, CurTime->tm_mon + 1, CurTime->tm_mday,
//                                 CurTime->tm_hour, CurTime->tm_min);
//                     lv_label_set_text(guider_ui.video_list_label_18, timepath);
//                     //视频图片
//                     if(video_file_list[4].photo[0] == '\0')
//                     {
//     //                  lv_img_set_src(guider_ui.video_list_img_6, &xiaowei96);
//                     }
//                     else
//                         lv_img_set_src(guider_ui.video_list_img_6, video_file_list[4].photo);
//                     break;
//                 }
//                 default:
//                     break;
//             }
//             temp = strtok(NULL,"\t");
//         }
//     }
// }

// void readbigfile(char *data,int len)
// {
//     unsigned char data_flag = 0,i=0,lenth = 0;
//     char tempdataa[10] = {'\0'};
//     char tempdatab[10] = {'\0'};
//     char tempdatac[10] = {'\0'};
//     char tempdatad[10] = {'\0'};

//     if(len < 3)
//     {
//         model_start_pix = 2;
//         model_end_pix = 298;
//         big_photo_name[0] = '\0';
//     }
//     else
//     {
//         CrLogI("(log date %s)",data);
//         char *temp = data;
//         CrLogI("(log temp %s)",temp);
//         while(*temp)
//         {
//             lenth++;
//             if(*temp == '\0' || lenth >len)
//             {
//                 break;
//             }
//             if(*temp == '\t')
//             {
//                 data_flag++;
//                 temp++;
//                 i = 0;
//                 continue;
//             }
//             switch(data_flag)
//             {
//                 case 0:
//                 {
//                     tempdataa[i++] = *temp++;
//                     break;
//                 }
//                 case 1:
//                 {
//                     tempdatab[i++] = *temp++;
//                     break;
//                 }
//                 case 2:
//                 {
//                     tempdatac[i++] = *temp++;
//                     break;
//                 }
//                 case 3:
//                 {
//                     tempdatad[i++] = *temp++;
//                     break;
//                 }
//                 case 4:
//                 {
//                     big_photo_name[i++] = *temp++;
//                     break;
//                 }
//             }
//         }
//         big_photo_name[i] = '\0';
//         CrLogI("(big_photo_name %s)",big_photo_name);
//         CrLogI("(tempdataa is %s)",tempdataa);
//         CrLogI("(tempdatab is %s)",tempdatab);
//         CrLogI("(tempdatac is %s)",tempdatac);
//         CrLogI("(tempdatad is %s)",tempdatad);

//         model_start_pix = atof(tempdataa);
//         model_end_pix   = atof(tempdatab);
//     }
//     refresh_big_photo();
// }

char auto_level_data[57][6];    //4*4的map数据，4*5=20个数据，每个数据最大6个字符
const char *text_map[57];

void refresh_level_data(unsigned char num,unsigned int len, char *data)
{
//    unsigned char i,j,k;
//
//    j = 0;k = 0;
//    for(i=0;i<len;i++)
//    {
//        if(*(data+i+1) == '\0')
//        {
//            auto_level_data[j][k] = '\0';
//            text_map[j] = auto_level_data[j];
//            break;
//        }
//        if(*(data+i+1) == '\t')
//        {
//            auto_level_data[j][k] = '\0';
//            text_map[j] = auto_level_data[j];
//            j++;
//            k = 0;
//            if(((j+1) % (num + 1)) == 0)
//            {
//                auto_level_data[j][0] = '\n';
//                auto_level_data[j][1] = '\0';
//                text_map[j] = auto_level_data[j];
//                j++;
//            }
//        }
//        else
//        {
//            if(k < (num + 1))
//                auto_level_data[j][k++] = *(data+i+1);
//        }
//    }
//    j++;
//    auto_level_data[j][0] = 0;
//    text_map[j] = auto_level_data[j];
//    lv_btnmatrix_set_map(guider_ui.auto_level_data_btnm_data, text_map);
//    lv_btnmatrix_set_btn_ctrl_all(guider_ui.auto_level_data_btnm_data,LV_BTNMATRIX_CTRL_DISABLED);
}

// char singlepoint[6];
// void refresh_autolevel_singlepoint(unsigned char num,unsigned int len, char *data)
// {
//     unsigned char i,j;
//     j = 0;
//     int point=0;
//     for(i=0;i<len;i++)
//     {
//         if(*(data+1+i) == '\0')
//         {
//             singlepoint[j++] = '\0';
//             break;
//         }
//         if(*(data+1+i) == '\t')
//         {
//             singlepoint[j++] = '\0';
//             point = atoi(singlepoint);
//             j = 0;
//         }
//         else
//         {
//             singlepoint[j++] = *(data+1+i);
//         }
//     }
//     CrLogI("point is %d,datat is %s",point,singlepoint);
//     //根据点数对相应的按钮文本进行修改
//     if(num == '0')//3X3
//     {
//         switch(point)
//         {
//             case 1: lv_label_set_text(guider_ui.selftest_btn_41_label,singlepoint);break;
//             case 2: lv_label_set_text(guider_ui.selftest_btn_42_label,singlepoint);break;
//             case 3: lv_label_set_text(guider_ui.selftest_btn_43_label,singlepoint);break;
//             case 4: lv_label_set_text(guider_ui.selftest_btn_38_label,singlepoint);break;
//             case 5: lv_label_set_text(guider_ui.selftest_btn_37_label,singlepoint);break;
//             case 6: lv_label_set_text(guider_ui.selftest_btn_36_label,singlepoint);break;
//             case 7: lv_label_set_text(guider_ui.selftest_btn_31_label,singlepoint);break;
//             case 8: lv_label_set_text(guider_ui.selftest_btn_32_label,singlepoint);break;
//             case 9:
//                 {
//                     lv_label_set_text(guider_ui.selftest_btn_33_label,singlepoint);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_24,LV_OBJ_FLAG_HIDDEN);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_50,LV_OBJ_FLAG_HIDDEN);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_51,LV_OBJ_FLAG_HIDDEN);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_52,LV_OBJ_FLAG_HIDDEN);
//                     break;
//                 }
//             default: break;
//         }
//     }
//     if(num == '1')//4X4
//     {
//         switch(point)
//         {
//             case 1: lv_label_set_text(guider_ui.selftest_btn_40_label,singlepoint);break;
//             case 2: lv_label_set_text(guider_ui.selftest_btn_41_label,singlepoint);break;
//             case 3: lv_label_set_text(guider_ui.selftest_btn_42_label,singlepoint);break;
//             case 4: lv_label_set_text(guider_ui.selftest_btn_43_label,singlepoint);break;
//             case 5: lv_label_set_text(guider_ui.selftest_btn_38_label,singlepoint);break;
//             case 6: lv_label_set_text(guider_ui.selftest_btn_37_label,singlepoint);break;
//             case 7: lv_label_set_text(guider_ui.selftest_btn_36_label,singlepoint);break;
//             case 8: lv_label_set_text(guider_ui.selftest_btn_35_label,singlepoint);break;
//             case 9: lv_label_set_text(guider_ui.selftest_btn_30_label,singlepoint);break;
//             case 10:lv_label_set_text(guider_ui.selftest_btn_31_label,singlepoint);break;
//             case 11:lv_label_set_text(guider_ui.selftest_btn_32_label,singlepoint);break;
//             case 12:lv_label_set_text(guider_ui.selftest_btn_33_label,singlepoint);break;
//             case 13:lv_label_set_text(guider_ui.selftest_btn_28_label,singlepoint);break;
//             case 14:lv_label_set_text(guider_ui.selftest_btn_27_label,singlepoint);break;
//             case 15:lv_label_set_text(guider_ui.selftest_btn_26_label,singlepoint);break;
//             case 16:
//             {
//                 lv_label_set_text(guider_ui.selftest_btn_25_label,singlepoint);
//                 lv_obj_clear_flag(guider_ui.selftest_btn_24,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_clear_flag(guider_ui.selftest_btn_50,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_clear_flag(guider_ui.selftest_btn_51,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_clear_flag(guider_ui.selftest_btn_52,LV_OBJ_FLAG_HIDDEN);
//                 break;
//             }
//             default: break;
//         }
//     }
//     if(num == '2')//5X5
//     {
//         switch(point)
//         {
//             case 1: lv_label_set_text(guider_ui.selftest_btn_45_label,singlepoint);break;
//             case 2: lv_label_set_text(guider_ui.selftest_btn_46_label,singlepoint);break;
//             case 3: lv_label_set_text(guider_ui.selftest_btn_47_label,singlepoint);break;
//             case 4: lv_label_set_text(guider_ui.selftest_btn_48_label,singlepoint);break;
//             case 5: lv_label_set_text(guider_ui.selftest_btn_49_label,singlepoint);break;
//             case 6: lv_label_set_text(guider_ui.selftest_btn_44_label,singlepoint);break;
//             case 7: lv_label_set_text(guider_ui.selftest_btn_43_label,singlepoint);break;
//             case 8: lv_label_set_text(guider_ui.selftest_btn_42_label,singlepoint);break;
//             case 9: lv_label_set_text(guider_ui.selftest_btn_41_label,singlepoint);break;
//             case 10:lv_label_set_text(guider_ui.selftest_btn_40_label,singlepoint);break;
//             case 11:lv_label_set_text(guider_ui.selftest_btn_35_label,singlepoint);break;
//             case 12:lv_label_set_text(guider_ui.selftest_btn_36_label,singlepoint);break;
//             case 13:lv_label_set_text(guider_ui.selftest_btn_37_label,singlepoint);break;
//             case 14:lv_label_set_text(guider_ui.selftest_btn_38_label,singlepoint);break;
//             case 15:lv_label_set_text(guider_ui.selftest_btn_39_label,singlepoint);break;
//             case 16:lv_label_set_text(guider_ui.selftest_btn_34_label,singlepoint);break;
//             case 17:lv_label_set_text(guider_ui.selftest_btn_33_label,singlepoint);break;
//             case 18:lv_label_set_text(guider_ui.selftest_btn_32_label,singlepoint);break;
//             case 19:lv_label_set_text(guider_ui.selftest_btn_31_label,singlepoint);break;
//             case 20:lv_label_set_text(guider_ui.selftest_btn_30_label,singlepoint);break;
//             case 21:lv_label_set_text(guider_ui.selftest_btn_25_label,singlepoint);break;
//             case 22:lv_label_set_text(guider_ui.selftest_btn_26_label,singlepoint);break;
//             case 23:lv_label_set_text(guider_ui.selftest_btn_27_label,singlepoint);break;
//             case 24:lv_label_set_text(guider_ui.selftest_btn_28_label,singlepoint);break;
//             case 25:
//             {
//                 lv_label_set_text(guider_ui.selftest_btn_29_label,singlepoint);
//                 lv_obj_clear_flag(guider_ui.selftest_btn_24,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_clear_flag(guider_ui.selftest_btn_50,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_clear_flag(guider_ui.selftest_btn_51,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_clear_flag(guider_ui.selftest_btn_52,LV_OBJ_FLAG_HIDDEN);
//                 break;
//             }
//             default:break;
//         }
//     }
// }

// void refresh_zoffset_value()
// {
//     if(zoffset_value[0] != '\0')
//     {
//         if (lv_obj_is_valid(guider_ui.printing_adjust_cont_1))
//         {
//             if (!lv_obj_has_flag(guider_ui.printing_adjust_cont_1,LV_OBJ_FLAG_HIDDEN))
//             {
//                 if(guider_ui.printing_adjust_label_7 != NULL && zoffset_value[0] != '\0')
//                 {
//                     char temp[OFFSET_LEN+3] = {'\0'};
//                     int i;
//                     for(i=0; i < strlen(zoffset_value); i++)
//                     {
//                         if(zoffset_value[i] == '\0')
//                         {

//                             break;
//                         }
//                         temp[i] = zoffset_value[i];
//                     }
//                     temp[i] = 'm';
//                     temp[i+1] = 'm';
//                     lv_label_set_text(guider_ui.printing_adjust_label_7, temp);
//                 }
//             }
//         }
//     }
// }

void refresh_origin_offset_value(unsigned char flag)
{
//    if (lv_obj_is_valid(guider_ui.origin_deviation_cont_1))
//    {
//        if (!lv_obj_has_flag(guider_ui.origin_deviation_cont_1,LV_OBJ_FLAG_HIDDEN))
//        {
//            if(flag & 0x01)
//            {
//                if(origin_xoffset_value[0] != '\0')
//                {
//                    if(guider_ui.origin_deviation_btn_x_offset != NULL)
//                    {
//                        lv_label_set_text(guider_ui.origin_deviation_btn_x_offset_label, origin_xoffset_value);
//                    }
//                }
//            }
//            if(flag & 0x02)
//            {
//                if(origin_yoffset_value[0] != '\0')
//                {
//                    if(guider_ui.origin_deviation_btn_y_offse != NULL)
//                    {
//                        lv_label_set_text(guider_ui.origin_deviation_btn_y_offse_label, origin_yoffset_value);
//                    }
//                }
//            }
//            if(flag & 0x04)
//            {
//                if(origin_zoffset_value[0] != '\0')
//                {
//                    if(guider_ui.origin_deviation_btn_z_offse != NULL)
//                    {
//                        lv_label_set_text(guider_ui.origin_deviation_btn_z_offse_label, origin_zoffset_value);
//                    }
//                }
//            }
//        }
//    }
}

// void refresh_bright()
// {
//     if (lv_obj_is_valid(guider_ui.settings_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.settings_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(guider_ui.settings_slider_1 != NULL && bright_value[0] != '\0')
//             {
//                 lv_slider_set_value(guider_ui.settings_slider_1,atoi(bright_value),LV_ANIM_ON);
//             }
//         }
//     }
// }

void refresh_repeattimes()
{
//    if (lv_obj_is_valid(guider_ui.printer_relevant_cont_1))
//    {
//        if (!lv_obj_has_flag(guider_ui.printer_relevant_cont_1,LV_OBJ_FLAG_HIDDEN))
//        {
//            if(guider_ui.printer_relevant_label_repeat_times != NULL)
//            {
//                if(repeat_times[0] != '\0')
//                {
//                    lv_label_set_text(guider_ui.printer_relevant_label_repeat_times, repeat_times);
//                }
//            }
//        }
//    }
}

void refresh_pla_setting(unsigned char flag)
{
//    if (lv_obj_is_valid(guider_ui.pretemp_cont_1))
//    {
//        if (!lv_obj_has_flag(guider_ui.pretemp_cont_1,LV_OBJ_FLAG_HIDDEN))
//        {
//            if(flag & 0x01)
//            {
//                if(guider_ui.pretemp_label_11 != NULL)
//                {
//                    if(PLA_preheat_hotend[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.pretemp_label_11, PLA_preheat_hotend);
//                    }
//                }
//            }
//            if(flag & 0x02)
//            {
//                if(guider_ui.pretemp_label_12 != NULL)
//                {
//                    if(PLA_preheat_bed[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.pretemp_label_12, PLA_preheat_bed);
//                    }
//                }
//            }
//        }
//    }
}

void refresh_petg_setting(unsigned char flag)
{
//    if (lv_obj_is_valid(guider_ui.pretemp_cont_1))
//    {
//        if (!lv_obj_has_flag(guider_ui.pretemp_cont_1,LV_OBJ_FLAG_HIDDEN))
//        {
//            if(flag & 0x01)
//            {
//                if(guider_ui.pretemp_label_14 != NULL)
//                {
//                    if(ABS_preheat_hotend[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.pretemp_label_14, ABS_preheat_hotend);
//                    }
//                }
//            }
//            if(flag & 0x02)
//            {
//                if(guider_ui.pretemp_label_15 != NULL)
//                {
//                    if(ABS_preheat_bed[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.pretemp_label_15, ABS_preheat_bed);
//                    }
//                }
//            }
//        }
//    }
}

void refresh_self_setting(unsigned char flag)
{
//    if (lv_obj_is_valid(guider_ui.pretemp_cont_1))
//    {
//        if (!lv_obj_has_flag(guider_ui.pretemp_cont_1,LV_OBJ_FLAG_HIDDEN))
//        {
//            if(flag & 0x01)
//            {
//                if(guider_ui.pretemp_label_25 != NULL)
//                {
//                    if(self_preheat_hotend[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.pretemp_label_25, self_preheat_hotend);
//                    }
//                }
//            }
//            if(flag & 0x02)
//            {
//                if(guider_ui.pretemp_label_26 != NULL)
//                {
//                    if(self_preheat_bed[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.pretemp_label_26, self_preheat_bed);
//                    }
//                }
//            }
//        }
//    }
}

void refresh_led_powerloss()
{
}

// void refresh_led_sound()
// {
//     if (lv_obj_is_valid(guider_ui.keytone_setting_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.keytone_setting_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(guider_ui.keytone_setting_sw_1 != NULL)
//             {
//                 CrLogI("refresh the sound_state %d.",sound_state);
//                 if(sound_state)
//                     lv_obj_add_state(guider_ui.keytone_setting_sw_1, LV_STATE_CHECKED);
//                 else
//                     lv_obj_clear_state(guider_ui.keytone_setting_sw_1, LV_STATE_CHECKED);
//             }
//         }
//     }
// }

// void refresh_sound_value()
// {
//     CrLogI("refresh_sound_value");
//     if (lv_obj_is_valid(guider_ui.keytone_setting_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.keytone_setting_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(guider_ui.keytone_setting_slider_1 != NULL && sound_value[0] != '\0')
//             {
//                 CrLogI("sound_value is %s.",sound_value);
//                 lv_slider_set_value(guider_ui.keytone_setting_slider_1,atoi(sound_value),LV_ANIM_ON);
//             }
//         }
//     }
// }

// void refresh_sound_type()
// {
//     CrLogI("refresh_sound_type");
//     if (lv_obj_is_valid(guider_ui.keytone_setting_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.keytone_setting_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(guider_ui.keytone_setting_ddlist_1 != NULL)
//             {
//                 CrLogI("sound_type is %c",sound_type);
//                 switch(sound_type)
//                 {
//                     case '1':lv_dropdown_set_selected(guider_ui.keytone_setting_ddlist_1,0);break;
//                     case '2':lv_dropdown_set_selected(guider_ui.keytone_setting_ddlist_1,1);break;
//                     case '3':lv_dropdown_set_selected(guider_ui.keytone_setting_ddlist_1,2);break;
//                     case '4':lv_dropdown_set_selected(guider_ui.keytone_setting_ddlist_1,3);break;
//                     default:break;
//                 }
//             }
//         }
//     }
// }

// void refresh_fullscreen()
// {
//     if (lv_obj_is_valid(guider_ui.settings_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.settings_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(guider_ui.settings_sw_1 != NULL)
//             {
//                 if(fullscreen_mode_state)
//                     lv_obj_add_state(guider_ui.settings_sw_1, LV_STATE_CHECKED);
//                 else
//                     lv_obj_clear_state(guider_ui.settings_sw_1, LV_STATE_CHECKED);
//             }
//         }
//     }
// }

// void refresh_led_screensave()
// {
//     if (lv_obj_is_valid(guider_ui.settings_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.settings_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(guider_ui.settings_ddlist_1 != NULL && screen_save_value[0] != NULL)
//             {
//                 switch(screen_save_value[0])
//                 {
//                     case '0':lv_dropdown_set_selected(guider_ui.settings_ddlist_1,3);break;
//                     case '1':lv_dropdown_set_selected(guider_ui.settings_ddlist_1,2);break;
//                     case '3':lv_dropdown_set_selected(guider_ui.settings_ddlist_1,0);break;
//                     case '5':lv_dropdown_set_selected(guider_ui.settings_ddlist_1,1);break;
//                     default:
//                         break;
//                 }
//             }
//         }
//     }
// }

// void refresh_camerasetting()
// {
//     CrLogI("refresh_camerasetting.");
//     if (lv_obj_is_valid(guider_ui.camera_seting_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.camera_seting_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(guider_ui.camera_seting_sw_1 != NULL)
//             {
//                 CrLogI("isopencamera:%c.",isopencamera);
//                 if(isopencamera)
//                     lv_obj_add_state(guider_ui.camera_seting_sw_1, LV_STATE_CHECKED);
//                 else
//                     lv_obj_clear_state(guider_ui.camera_seting_sw_1, LV_STATE_CHECKED);
//             }
//             CrLogI("cameraposition:%c.",cameraposition);
//             if(guider_ui.camera_seting_ta_1 != NULL && picturelayers[0] != '\0')
//             {
//                 CrLogI("picturelayers:%s.",picturelayers);
//                 lv_textarea_set_text(guider_ui.camera_seting_ta_1,picturelayers);
//             }
//             if(guider_ui.camera_seting_ddlist_1 != NULL && Render_mode[0] != '\0')
//             {
//                 CrLogI("Render_mode:%s.",Render_mode);
//                 switch(Render_mode[0])
//                 {
//                     case '1':lv_dropdown_set_selected(guider_ui.camera_seting_ddlist_1,0);break;
//                     case '2':lv_dropdown_set_selected(guider_ui.camera_seting_ddlist_1,1);break;
//                     default:lv_dropdown_set_selected(guider_ui.camera_seting_ddlist_1,0);break;
//                 }
//             }
//         }
//     }
// }

// void refresh_bed_size(unsigned char flag)
// {
// }

// void refresh_auto_level_point()
// {
//     if (lv_obj_is_valid(guider_ui.selftest_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.selftest_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(level_point_value == '0')//3x3
//             {
//                 lv_obj_add_flag(guider_ui.selftest_btn_25,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_26,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_27,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_28,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_29,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_30,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_34,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_35,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_39,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_40,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_44,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_45,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_46,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_47,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_48,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_49,LV_OBJ_FLAG_HIDDEN);

//                 lv_label_set_text(guider_ui.selftest_btn_41_label,"1");
//                 lv_label_set_text(guider_ui.selftest_btn_42_label,"2");
//                 lv_label_set_text(guider_ui.selftest_btn_43_label,"3");
//                 lv_label_set_text(guider_ui.selftest_btn_38_label,"4");
//                 lv_label_set_text(guider_ui.selftest_btn_37_label,"5");
//                 lv_label_set_text(guider_ui.selftest_btn_36_label,"6");
//                 lv_label_set_text(guider_ui.selftest_btn_31_label,"7");
//                 lv_label_set_text(guider_ui.selftest_btn_32_label,"8");
//                 lv_label_set_text(guider_ui.selftest_btn_33_label,"9");
//             }
//             if(level_point_value == '1')//4x4
//             {
//                 lv_obj_clear_flag(guider_ui.selftest_btn_25,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_clear_flag(guider_ui.selftest_btn_26,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_clear_flag(guider_ui.selftest_btn_27,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_clear_flag(guider_ui.selftest_btn_28,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_clear_flag(guider_ui.selftest_btn_30,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_clear_flag(guider_ui.selftest_btn_35,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_clear_flag(guider_ui.selftest_btn_40,LV_OBJ_FLAG_HIDDEN);

//                 lv_obj_add_flag(guider_ui.selftest_btn_29,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_34,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_39,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_44,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_45,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_46,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_47,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_48,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.selftest_btn_49,LV_OBJ_FLAG_HIDDEN);

//                 lv_label_set_text(guider_ui.selftest_btn_40_label,"1");
//                 lv_label_set_text(guider_ui.selftest_btn_41_label,"2");
//                 lv_label_set_text(guider_ui.selftest_btn_42_label,"3");
//                 lv_label_set_text(guider_ui.selftest_btn_43_label,"4");
//                 lv_label_set_text(guider_ui.selftest_btn_38_label,"5");
//                 lv_label_set_text(guider_ui.selftest_btn_37_label,"6");
//                 lv_label_set_text(guider_ui.selftest_btn_36_label,"7");
//                 lv_label_set_text(guider_ui.selftest_btn_35_label,"8");
//                 lv_label_set_text(guider_ui.selftest_btn_30_label,"9");
//                 lv_label_set_text(guider_ui.selftest_btn_31_label,"10");
//                 lv_label_set_text(guider_ui.selftest_btn_32_label,"11");
//                 lv_label_set_text(guider_ui.selftest_btn_33_label,"12");
//                 lv_label_set_text(guider_ui.selftest_btn_28_label,"13");
//                 lv_label_set_text(guider_ui.selftest_btn_27_label,"14");
//                 lv_label_set_text(guider_ui.selftest_btn_26_label,"15");
//                 lv_label_set_text(guider_ui.selftest_btn_25_label,"16");
//             }
//             if(level_point_value == '2')//5x5
//             {
//                     lv_obj_clear_flag(guider_ui.selftest_btn_25,LV_OBJ_FLAG_HIDDEN);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_26,LV_OBJ_FLAG_HIDDEN);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_27,LV_OBJ_FLAG_HIDDEN);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_28,LV_OBJ_FLAG_HIDDEN);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_30,LV_OBJ_FLAG_HIDDEN);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_35,LV_OBJ_FLAG_HIDDEN);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_40,LV_OBJ_FLAG_HIDDEN);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_29,LV_OBJ_FLAG_HIDDEN);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_34,LV_OBJ_FLAG_HIDDEN);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_39,LV_OBJ_FLAG_HIDDEN);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_44,LV_OBJ_FLAG_HIDDEN);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_45,LV_OBJ_FLAG_HIDDEN);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_46,LV_OBJ_FLAG_HIDDEN);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_47,LV_OBJ_FLAG_HIDDEN);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_48,LV_OBJ_FLAG_HIDDEN);
//                     lv_obj_clear_flag(guider_ui.selftest_btn_49,LV_OBJ_FLAG_HIDDEN);

//                     lv_label_set_text(guider_ui.selftest_btn_45_label,"1");
//                     lv_label_set_text(guider_ui.selftest_btn_46_label,"2");
//                     lv_label_set_text(guider_ui.selftest_btn_47_label,"3");
//                     lv_label_set_text(guider_ui.selftest_btn_48_label,"4");
//                     lv_label_set_text(guider_ui.selftest_btn_49_label,"5");
//                     lv_label_set_text(guider_ui.selftest_btn_44_label,"6");
//                     lv_label_set_text(guider_ui.selftest_btn_43_label,"7");
//                     lv_label_set_text(guider_ui.selftest_btn_42_label,"8");
//                     lv_label_set_text(guider_ui.selftest_btn_41_label,"9");
//                     lv_label_set_text(guider_ui.selftest_btn_40_label,"10");
//                     lv_label_set_text(guider_ui.selftest_btn_35_label,"11");
//                     lv_label_set_text(guider_ui.selftest_btn_36_label,"12");
//                     lv_label_set_text(guider_ui.selftest_btn_37_label,"13");
//                     lv_label_set_text(guider_ui.selftest_btn_38_label,"14");
//                     lv_label_set_text(guider_ui.selftest_btn_39_label,"15");
//                     lv_label_set_text(guider_ui.selftest_btn_34_label,"16");
//                     lv_label_set_text(guider_ui.selftest_btn_33_label,"17");
//                     lv_label_set_text(guider_ui.selftest_btn_32_label,"18");
//                     lv_label_set_text(guider_ui.selftest_btn_31_label,"19");
//                     lv_label_set_text(guider_ui.selftest_btn_30_label,"20");
//                     lv_label_set_text(guider_ui.selftest_btn_25_label,"21");
//                     lv_label_set_text(guider_ui.selftest_btn_26_label,"22");
//                     lv_label_set_text(guider_ui.selftest_btn_27_label,"23");
//                     lv_label_set_text(guider_ui.selftest_btn_28_label,"24");
//                     lv_label_set_text(guider_ui.selftest_btn_29_label,"25");
//                 }
//         }
//     }
// }

// void refresh_auto_level_model()
// {
// }
// void refresh_auto_level_hspeed()
// {
// }

// void refresh_about()
// {
//     if (lv_obj_is_valid(guider_ui.about_device_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.about_device_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(guider_ui.about_device_label_13 != NULL)
//             {
//                 if(machine_type_value[0] != '\0')
//                     lv_label_set_text(guider_ui.about_device_label_13, machine_type_value);
//                 if(screen_ver_value[0] != '\0')
//                     lv_label_set_text(guider_ui.about_device_label_15, screen_ver_value);
//                 if(mac_value[0] != '\0')
//                     lv_label_set_text(guider_ui.about_device_label_16, mac_value);
//                 if(total_time_value[0] != '\0')
//                     lv_label_set_text(guider_ui.about_device_label_17, total_time_value);
// //                if(hardware_ver_value[0] != '\0')
// //                    lv_label_set_text(guider_ui.about_device_label_14, hardware_ver_value);
// //                if(screen_ver_value[0] != '\0')
// //                    lv_label_set_text(guider_ui.about_label_screen, screen_ver_value);
// //                if(official_web_value[0] != '\0')
// //                    lv_label_set_text(guider_ui.about_label_website, official_web_value);
//             }
//         }
//     }
// }

void refresh_language()
{
//    if (lv_obj_is_valid(guider_ui.language_cont_1))
//    {
//        if (!lv_obj_has_flag(guider_ui.language_cont_1,LV_OBJ_FLAG_HIDDEN))
//        {
//            if(guider_ui.language_cb_cn != NULL)
//            {
//                lv_label_set_text(guider_ui.language_label_title, &language[cur_language][0]);

//                lv_obj_add_flag(guider_ui.language_cb_cn, LV_OBJ_FLAG_HIDDEN);
//                lv_obj_add_flag(guider_ui.language_cb_en, LV_OBJ_FLAG_HIDDEN);
//                lv_obj_add_flag(guider_ui.language_cb_de, LV_OBJ_FLAG_HIDDEN);
//                lv_obj_add_flag(guider_ui.language_cb_es, LV_OBJ_FLAG_HIDDEN);
//                lv_obj_add_flag(guider_ui.language_cb_fr, LV_OBJ_FLAG_HIDDEN);
//                lv_obj_add_flag(guider_ui.language_cb_it, LV_OBJ_FLAG_HIDDEN);
//                lv_obj_add_flag(guider_ui.language_cb_ptbr, LV_OBJ_FLAG_HIDDEN);
//                lv_obj_add_flag(guider_ui.language_cb_pyc, LV_OBJ_FLAG_HIDDEN);
//                lv_obj_add_flag(guider_ui.language_cb_tr, LV_OBJ_FLAG_HIDDEN);

//                switch(cur_language)
//                {
//                case 0:
//                    lv_obj_clear_flag(guider_ui.language_cb_cn, LV_OBJ_FLAG_HIDDEN);
//                    break;
//                case 1:
//                    lv_obj_clear_flag(guider_ui.language_cb_en, LV_OBJ_FLAG_HIDDEN);
//                    break;
//                case 2:
//                    lv_obj_clear_flag(guider_ui.language_cb_de, LV_OBJ_FLAG_HIDDEN);
//                    break;
//                case 3:
//                    lv_obj_clear_flag(guider_ui.language_cb_es, LV_OBJ_FLAG_HIDDEN);
//                    break;
//                case 4:
//                    lv_obj_clear_flag(guider_ui.language_cb_fr, LV_OBJ_FLAG_HIDDEN);
//                    break;
//                case 5:
//                    lv_obj_clear_flag(guider_ui.language_cb_it, LV_OBJ_FLAG_HIDDEN);
//                    break;
//                case 6:
//                    lv_obj_clear_flag(guider_ui.language_cb_ptbr, LV_OBJ_FLAG_HIDDEN);
//                    break;
//                case 7:
//                    lv_obj_clear_flag(guider_ui.language_cb_pyc, LV_OBJ_FLAG_HIDDEN);
//                    break;
//                case 8:
//                    lv_obj_clear_flag(guider_ui.language_cb_tr, LV_OBJ_FLAG_HIDDEN);
//                    break;
//                default:
//                    break;
//                }
//            }
//        }
//    }
}

void refresh_steps_setting(unsigned char flag)
{
//    if (lv_obj_is_valid(guider_ui.steps_setting_cont_1))
//    {
//        if (!lv_obj_has_flag(guider_ui.steps_setting_cont_1,LV_OBJ_FLAG_HIDDEN))
//        {
//            if(flag & 0x01)
//            {
//                if(guider_ui.steps_setting_label_x_steps != NULL)
//                {
//                    if(xSTEPS[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.steps_setting_label_x_steps, xSTEPS);
//                    }
//                }
//            }
//            if(flag & 0x02)
//            {
//                if(guider_ui.steps_setting_label_y_steps != NULL)
//                {
//                    if(ySTEPS[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.steps_setting_label_y_steps, ySTEPS);
//                    }
//                }
//            }
//            if(flag & 0x04)
//            {
//                if(guider_ui.steps_setting_label_z_steps != NULL)
//                {
//                    if(zSTEPS[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.steps_setting_label_z_steps, zSTEPS);
//                    }
//                }
//            }
//            if(flag & 0x08)
//            {
//                if(guider_ui.steps_setting_label_e_steps != NULL)
//                {
//                    if(eSTEPS[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.steps_setting_label_e_steps, eSTEPS);
//                    }
//                }
//            }
//        }
//    }
}

void refresh_jerk_setting(unsigned char flag)
{
//    if (lv_obj_is_valid(guider_ui.max_jerk_setting_cont_1))
//    {
//        if (!lv_obj_has_flag(guider_ui.max_jerk_setting_cont_1,LV_OBJ_FLAG_HIDDEN))
//        {
//            if(flag & 0x01)
//            {
//                if(guider_ui.max_jerk_setting_label_x_jerk != NULL)
//                {
//                    if(xjerk[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.max_jerk_setting_label_x_jerk, xjerk);
//                    }
//                }
//            }
//            if(flag & 0x02)
//            {
//                if(guider_ui.max_jerk_setting_label_y_jerk != NULL)
//                {
//                    if(yjerk[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.max_jerk_setting_label_y_jerk, yjerk);
//                    }
//                }
//            }
//            if(flag & 0x04)
//            {
//                if(guider_ui.max_jerk_setting_label_z_jerk != NULL)
//                {
//                    if(zjerk[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.max_jerk_setting_label_z_jerk, zjerk);
//                    }
//                }
//            }
//            if(flag & 0x08)
//            {
//                if(guider_ui.max_jerk_setting_label_e_jerk != NULL)
//                {
//                    if(ejerk[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.max_jerk_setting_label_e_jerk, ejerk);
//                    }
//                }
//            }
//        }
//    }
}

void refresh_speed_setting(unsigned char flag)
{
//    if (lv_obj_is_valid(guider_ui.max_speed_setting_cont_1))
//    {
//        if (!lv_obj_has_flag(guider_ui.max_speed_setting_cont_1,LV_OBJ_FLAG_HIDDEN))
//        {
//            if(flag & 0x01)
//            {
//                if(guider_ui.max_speed_setting_label_x_speed != NULL)
//                {
//                    if(xmspeed[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.max_speed_setting_label_x_speed, xmspeed);
//                    }
//                }
//            }
//            if(flag & 0x02)
//            {
//                if(guider_ui.max_speed_setting_label_y_speed != NULL)
//                {
//                    if(ymspeed[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.max_speed_setting_label_y_speed, ymspeed);
//                    }
//                }
//            }
//            if(flag & 0x04)
//            {
//                if(guider_ui.max_speed_setting_label_z_speed != NULL)
//                {
//                    if(zmspeed[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.max_speed_setting_label_z_speed, zmspeed);
//                    }
//                }
//            }
//            if(flag & 0x08)
//            {
//                if(guider_ui.max_speed_setting_label_e_speed != NULL)
//                {
//                    if(emspeed[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.max_speed_setting_label_e_speed, emspeed);
//                    }
//                }
//            }
//        }
//    }
}

void refresh_acc_setting(unsigned char flag)
{
//    if (lv_obj_is_valid(guider_ui.max_acc_setting_cont_1))
//    {
//        if (!lv_obj_has_flag(guider_ui.max_acc_setting_cont_1,LV_OBJ_FLAG_HIDDEN))
//        {
//            if(flag & 0x01)
//            {
//                if(guider_ui.max_acc_setting_label_x_acc != NULL)
//                {
//                    if(xmacc[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.max_acc_setting_label_x_acc, xmacc);
//                    }
//                }
//            }
//            if(flag & 0x02)
//            {
//                if(guider_ui.max_acc_setting_label_y_acc != NULL)
//                {
//                    if(ymacc[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.max_acc_setting_label_y_acc, ymacc);
//                    }
//                }
//            }
//            if(flag & 0x04)
//            {
//                if(guider_ui.max_acc_setting_label_z_acc != NULL)
//                {
//                    if(zmacc[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.max_acc_setting_label_z_acc, zmacc);
//                    }
//                }
//            }
//            if(flag & 0x08)
//            {
//                if(guider_ui.max_acc_setting_label_e_acc != NULL)
//                {
//                    if(emacc[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.max_acc_setting_label_e_acc, emacc);
//                    }
//                }
//            }
//        }
//    }
}

void refresh_temp_pid_setting(unsigned char flag)
{
//    if (lv_obj_is_valid(guider_ui.manual_PID_cont_1))
//    {
//        if (!lv_obj_has_flag(guider_ui.manual_PID_cont_1,LV_OBJ_FLAG_HIDDEN))
//        {
//            if(flag & 0x01)
//            {
//                if(guider_ui.manual_PID_label_hotendp != NULL)
//                {
//                    if(hotend_pid_p[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.manual_PID_label_hotendp, hotend_pid_p);
//                    }
//                }
//            }
//            if(flag & 0x02)
//            {
//                if(guider_ui.manual_PID_label_hotendi != NULL)
//                {
//                    if(hotend_pid_i[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.manual_PID_label_hotendi, hotend_pid_i);
//                    }
//                }
//            }
//            if(flag & 0x04)
//            {
//                if(guider_ui.manual_PID_label_hotendd != NULL)
//                {
//                    if(hotend_pid_d[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.manual_PID_label_hotendd, hotend_pid_d);
//                    }
//                }
//            }
//            if(flag & 0x08)
//            {
//                if(guider_ui.manual_PID_label_bedp != NULL)
//                {
//                    if(bed_pid_p[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.manual_PID_label_bedp, bed_pid_p);
//                    }
//                }
//            }
//            if(flag & 0x10)
//            {
//                if(guider_ui.manual_PID_label_bedi != NULL)
//                {
//                    if(bed_pid_i[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.manual_PID_label_bedi, bed_pid_i);
//                    }
//                }
//            }
//            if(flag & 0x20)
//            {
//                if(guider_ui.manual_PID_label_bedd != NULL)
//                {
//                    if(bed_pid_d[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.manual_PID_label_bedd, bed_pid_d);
//                    }
//                }
//            }
//        }
//    }
}

// void refresh_pid_hotend_setting(unsigned char flag)
// {
//     if (lv_obj_is_valid(guider_ui.selftest_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.selftest_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(guider_ui.selftest_label_113!= NULL && pid_hotend_tar[0] != '\0')
//             {
//                 char ctemp[10] = {0};
//                 snprintf(ctemp,10,"%s℃",pid_hotend_tar);
//                 lv_label_set_text(guider_ui.selftest_label_113, ctemp);
//             }
//         }
//     }
// }

// void refresh_pid_bed_setting(unsigned char flag)
// {
//     if (lv_obj_is_valid(guider_ui.selftest_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.selftest_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(guider_ui.selftest_label_124!= NULL && pid_bed_tar[0] != '\0')
//             {
//                 char ctemp[10] = {0};
//                 snprintf(ctemp,10,"%s℃",pid_bed_tar);
//                 lv_label_set_text(guider_ui.selftest_label_124, ctemp);
//             }
//         }
//     }
// }

void refresh_axis_motor(unsigned char flag)
{
//    if (lv_obj_is_valid(guider_ui.move_cont_1))
//    {
//        if (!lv_obj_has_flag(guider_ui.move_cont_1,LV_OBJ_FLAG_HIDDEN))
//        {
//            if(flag & 0x01)
//            {
//                if(guider_ui.move_btn_5_label != NULL)
//                {
//                    if(cur_xposition[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.move_btn_5_label, cur_xposition);
//                    }
//                }
//                if(guider_ui.move_btn_6_label != NULL)
//                {
//                    if(cur_yposition[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.move_btn_6_label, cur_yposition);
//                    }
//                }
//                if(guider_ui.move_btn_7_label != NULL)
//                {
//                    if(cur_zposition[0] != '\0')
//                    {
//                        lv_label_set_text(guider_ui.move_btn_7_label, cur_zposition);
//                    }
//                }
//            }
//            if(flag & 0x02)
//            {
//                if(guider_ui.move_label_3 != NULL)
//                {
//                    if(motor_loss_state)
//                    {
//                        lv_label_set_text(guider_ui.move_label_3, "ON");
////                        lv_obj_clear_flag(guider_ui.prepare_axis_img_motor, LV_OBJ_FLAG_HIDDEN);
////                        lv_obj_add_flag(guider_ui.prepare_axis_img_motors, LV_OBJ_FLAG_HIDDEN);
//                    }
//                    else
//                    {
//                        lv_label_set_text(guider_ui.move_label_3, "OFF");
////                        lv_obj_add_flag(guider_ui.prepare_axis_img_motor, LV_OBJ_FLAG_HIDDEN);
////                        lv_obj_clear_flag(guider_ui.prepare_axis_img_motors, LV_OBJ_FLAG_HIDDEN);
//                    }
//                }
//            }
//        }
//    }
}

//void refresh_material()
//{
//    if (lv_obj_is_valid(guider_ui.prepare_material_cont_1))
//    {
//        if (!lv_obj_has_flag(guider_ui.prepare_material_cont_1,LV_OBJ_FLAG_HIDDEN))
//        {
//            if(guider_ui.prepare_material_btn_in_value != NULL)
//            {
//                if(material_in_length[0] != '\0')
//                {
//                    lv_label_set_text(guider_ui.prepare_material_btn_in_value_label, material_in_length);
//                }
//            }
//
//            if(guider_ui.prepare_material_btn_out_value != NULL)
//            {
//                if(material_out_length[0] != '\0')
//                {
//                    lv_label_set_text(guider_ui.prepare_material_btn_out_value_label, material_out_length);
//                }
//            }
//        }
//    }
//}

// void refresh_temp(unsigned char flag)
// {
//     //首页温度曲线图需要一直刷新数据
//     if(hotend_cur_temp[0] != '\0')
//     {
//         lv_chart_set_next_value((guider_ui.stacked_area_chart).obj, guider_ui.stacked_area_chart.series_list[1], atoi(hotend_cur_temp));
//         lv_chart_refresh((guider_ui.stacked_area_chart).obj);
//     }
//     if(bed_cur_temp[0] != '\0')
//     {
//         lv_chart_set_next_value((guider_ui.stacked_area_chart).obj, guider_ui.stacked_area_chart.series_list[2], atoi(bed_cur_temp));
//         lv_chart_refresh((guider_ui.stacked_area_chart).obj);
//     }
//     if (lv_obj_is_valid(guider_ui.homepage_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.homepage_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(flag & 0x02)
//             {
//                 if(guider_ui.homepage_btn_1_label!= NULL)
//                 {
//                     if(hotend_cur_temp[0] != '\0')
//                     {
//                         int tint;
//                         tint = atoi(hotend_cur_temp);
//                         lv_label_set_text(guider_ui.homepage_btn_1_label, hotend_cur_temp);
//                     }
//                 }
//             }
//             if(flag & 0x08)
//             {
//                 if(guider_ui.homepage_btn_2_label != NULL)
//                 {
//                     if(bed_cur_temp[0] != '\0')
//                     {
//                         int tint;
//                         tint = atoi(bed_cur_temp);
//                         lv_label_set_text(guider_ui.homepage_btn_2_label, bed_cur_temp);
//                     }
//                 }
//             }
//         }
//     }
//     if (lv_obj_is_valid(guider_ui.axismove_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.axismove_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
// //            if(flag & 0x01)
// //            {
// //                if(guider_ui.print_label_7 != NULL)
// //                {
// //                    if(hotend_max_temp[0] != '\0')
// //                    {
// //                        lv_label_set_text(guider_ui.print_label_7, hotend_max_temp);
// //                    }
// //                }
// //            }
//             if(flag & 0x02)
//             {
//                 if(guider_ui.axismove_label_3 != NULL)
//                 {
//                     if(hotend_cur_temp[0] != '\0')
//                     {
//                         lv_label_set_text(guider_ui.axismove_label_3, hotend_cur_temp);
//                     }
//                 }
//             }
// //            if(flag & 0x04)
// //            {
// //                if(guider_ui.print_label_15 != NULL)
// //                {
// //                    if(bed_max_temp[0] != '\0')
// //                    {
// //                        lv_label_set_text(guider_ui.print_label_15, bed_max_temp);
// //                    }
// //                }
// //            }
//             if(flag & 0x08)
//             {
//                 if(guider_ui.axismove_label_4 != NULL)
//                 {
//                     if(bed_cur_temp[0] != '\0')
//                     {
//                         lv_label_set_text(guider_ui.axismove_label_4, bed_cur_temp);
//                     }
//                 }
//             }
//         }
//     }
//     if(lv_obj_is_valid(guider_ui.selftest_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.selftest_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(hotend_cur_temp[0] != '\0')
//             {
//                 if(atoi(hotend_cur_temp) > 50)
//                 {
//                     if(selftest_result[0] == 3)
//                     {
//                         lv_label_set_text(guider_ui.messagebox_label_3,"喉管散热风扇已启动，请查看风扇是否正常转动...");
//                         lv_obj_clear_flag(guider_ui.messagebox_cont_1,LV_OBJ_FLAG_HIDDEN);
//                         selftest_result[0] = 0;
//                     }
//                 }
//             }
//             if(hotend_cur_temp[0] != '\0' && guider_ui.selftest_label_118 != NULL)
//             {
//                 char ctemp[10] = {0};
//                 snprintf(ctemp,10,"%s℃",hotend_cur_temp);
//                 lv_label_set_text(guider_ui.selftest_label_118,ctemp);
//             }
//             if(hotend_max_temp[0] != '\0' && guider_ui.selftest_label_119 != NULL)
//             {
//                 char ctemp[10] = {0};
//                 snprintf(ctemp,10,"%s℃",hotend_max_temp);
//                 lv_label_set_text(guider_ui.selftest_label_119,ctemp);
//             }
//             if(bed_cur_temp[0] != '\0' && guider_ui.selftest_label_126 != NULL)
//             {
//                 char ctemp[10] = {0};
//                 snprintf(ctemp,10,"%s℃",bed_cur_temp);
//                 lv_label_set_text(guider_ui.selftest_label_126,ctemp);
//             }
//             if(bed_max_temp[0] != '\0' && guider_ui.selftest_label_127 != NULL)
//             {
//                 char ctemp[10] = {0};
//                 snprintf(ctemp,10,"%s℃",bed_max_temp);
//                 lv_label_set_text(guider_ui.selftest_label_127,ctemp);
//             }
//         }
//     }
// }

// void refresh_fan()
// {
//     if (lv_obj_is_valid(guider_ui.homepage_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.homepage_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(fan_state)
//             {
//                 lv_img_set_src(guider_ui.homepage_img_9,&_fan2_48x48);
//             }
//             else
//             {
//                 lv_img_set_src(guider_ui.homepage_img_9,&_fan_48x48);
//             }
//         }
//     }
//     if (lv_obj_is_valid(guider_ui.axismove_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.axismove_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(guider_ui.axismove_img_15 != NULL)
//             {
//                 if(fan_state)
//                 {
//                     lv_img_set_src(guider_ui.axismove_img_15,&_fan2_48x48);
//                 }
//                 else
//                 {
//                     lv_img_set_src(guider_ui.axismove_img_15,&_fan_48x48);
//                 }
//             }
//         }
//     }
//     if(lv_obj_is_valid(guider_ui.selftest_cont_1))
//     {
//         if(!lv_obj_has_flag(guider_ui.selftest_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             char temp[100] = "模型冷却风扇已启动，请查看风扇是否正常转动...";
//             lv_label_set_text(guider_ui.messagebox_label_3,temp);
//             lv_obj_clear_flag(guider_ui.messagebox_cont_1,LV_OBJ_FLAG_HIDDEN);
//         }
//     }

// }

// void refresh_printing_speed()
// {
//     if(lv_obj_is_valid(guider_ui.homepage_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.homepage_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(guider_ui.homepage_btn_3_label != NULL)
//             {
//                 if(cur_speed[0] != '\0')
//                 {
//                     CrLogI("homepage set print_speed.");
//                     lv_label_set_text(guider_ui.homepage_btn_3_label, cur_speed);
//                 }
//             }
//         }
//     }
//     if (lv_obj_is_valid(guider_ui.axismove_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.axismove_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(guider_ui.axismove_label_5 != NULL)
//             {
//                 if(cur_speed[0] != '\0')
//                 {
//                     CrLogI("axismove set print_speed.");
//                     lv_label_set_text(guider_ui.axismove_label_5, cur_speed);
//                 }
//             }
//         }
//     }
//     if (lv_obj_is_valid(guider_ui.printing_adjust_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.printing_adjust_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(guider_ui.printing_adjust_label_13 != NULL && cur_speed[0] != '\0')
//             {
//                 char temp[CUR_SPEED_LEN+2] = {'\0'};
//                 int i;
//                 for(i=0; i < strlen(cur_speed); i++)
//                 {
//                     if(cur_speed[i] == '\0')
//                     {
//                         break;
//                     }
//                     temp[i] = cur_speed[i];
//                 }
//                 temp[i] = '%';
//                 lv_img_set_src(guider_ui.printing_adjust_label_13, temp);
//             }
//         }
//     }
// }

// void refresh_printing_flow()
// {
//     if (lv_obj_is_valid(guider_ui.printing_adjust_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.printing_adjust_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(guider_ui.printing_adjust_label_15 != NULL && cur_printflow[0] != '\0')
//             {
//                 char temp[CUR_SPEED_LEN+2] = {'\0'};
//                 int i=0;
//                 for(i=0; i < strlen(cur_printflow); i++)
//                 {
//                     if(cur_printflow[i] == '\0')
//                     {
//                         break;
//                     }
//                     temp[i] = cur_printflow[i];
//                 }
//                 temp[i] = '%';
//                 lv_img_set_src(guider_ui.printing_adjust_label_15, temp);
//             }
//         }
//     }
// }

// void refresh_big_photo()
// {
//     if(big_photo_name[0] != '\0')
//     {
//         if (lv_obj_is_valid(guider_ui.file_information_cont_1))
//         {
//             if (!lv_obj_has_flag(guider_ui.file_information_cont_1,LV_OBJ_FLAG_HIDDEN))
//             {
//                 if(guider_ui.file_information_img_2 != NULL)
//                 {
//                     lv_img_set_src(guider_ui.file_information_img_2, big_photo_name);
//                 }
//             }
//         }
// //        if (lv_obj_is_valid(guider_ui.homepage_cont_1))
// //        {
// //            if (!lv_obj_has_flag(guider_ui.homepage_cont_1,LV_OBJ_FLAG_HIDDEN))
// //            {
//                 if(guider_ui.homepage_img_16 != NULL)
//                 {
//                     lv_img_set_src(guider_ui.homepage_img_16, big_photo_name);
// //                    lv_img_set_src(guider_ui.print_printing_img_mask, big_photo_name);
//                 }
// //                lv_obj_clear_flag(guider_ui.print_printing_img_mask, LV_OBJ_FLAG_HIDDEN);
// //            }
// //        }
//         if(guider_ui.fullscreen_mode_img_1 != NULL)
//         {
//             lv_img_set_src(guider_ui.fullscreen_mode_img_1, big_photo_name);
//             lv_img_set_src(guider_ui.fullscreen_mode_img_mask, big_photo_name);
//         }
//     }
//     else
//     {
//         if (lv_obj_is_valid(guider_ui.file_information_cont_1))
//         {
//             if (!lv_obj_has_flag(guider_ui.file_information_cont_1,LV_OBJ_FLAG_HIDDEN))
//             {
//                 if(guider_ui.file_information_img_2 != NULL)
//                 {
//                     lv_img_set_src(guider_ui.file_information_img_2, &_crealitylogo_300x300);
//                 }
//             }
//         }
// //        if (lv_obj_is_valid(guider_ui.homepage_cont_1))
// //        {
// //            if (!lv_obj_has_flag(guider_ui.homepage_cont_1,LV_OBJ_FLAG_HIDDEN))
// //            {
//                 if(guider_ui.homepage_img_16 != NULL)
//                 {
//                     lv_img_set_src(guider_ui.homepage_img_16, &_crealitylogo_300x300);
// //                    lv_img_set_src(guider_ui.print_printing_img_mask, &_xiaowei300_300x300);
//                 }
// //                lv_obj_clear_flag(guider_ui.print_printing_img_mask, LV_OBJ_FLAG_HIDDEN);
// //            }
// //        }
//         if(guider_ui.fullscreen_mode_img_1 != NULL)
//         {
//             lv_img_set_src(guider_ui.fullscreen_mode_img_1, &_crealitylogo_300x300);
//             lv_img_set_src(guider_ui.fullscreen_mode_img_mask, &_crealitylogo_300x300);
//         }
//     }
// }

// void refresh_light()
// {
//     if (lv_obj_is_valid(guider_ui.homepage_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.homepage_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(light_state)
//             {
//                 lv_img_set_src(guider_ui.homepage_img_7,&_LED_48x48);
//             }
//             else
//             {
//                 lv_img_set_src(guider_ui.homepage_img_7,&_LED2_48x48);
//             }
//         }
//     }
// }

//void refresh_auto_poweroff()
//{
//    if (lv_obj_is_valid(guider_ui.print_setting_cont_1))
//    {
//        if (!lv_obj_has_flag(guider_ui.print_setting_cont_1,LV_OBJ_FLAG_HIDDEN))
//        {
//            if(guider_ui.print_setting_label_auto_poweroff != NULL)
//            {
//                if(auto_poweroff)
//                {
//                    lv_led_set_color(guider_ui.print_setting_led_auto_poweroff, lv_color_make(led_on_r_color, led_on_g_color, led_on_b_color));
//                    lv_label_set_text(guider_ui.print_setting_label_auto_poweroff, "ON");
//                }
//                else
//                {
//                    lv_led_set_color(guider_ui.print_setting_led_auto_poweroff, lv_color_make(led_off_r_color, led_off_g_color, led_off_b_color));
//                    lv_label_set_text(guider_ui.print_setting_label_auto_poweroff, "OFF");
//                }
//            }
//        }
//    }
//}

// void refresh_material_seneor()
// {
//     if (lv_obj_is_valid(guider_ui.selftest_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.selftest_cont_1,LV_OBJ_FLAG_HIDDEN) && selftest_flag)
//         {
//             if(material_seneor == '1')
//             {
//                 lv_label_set_text(guider_ui.messagebox_label_3,"耗材已插入");
//             }
//             if(material_seneor == '4')
//             {
//                 lv_label_set_text(guider_ui.messagebox_label_3,"耗材已拔出");
//             }
//             lv_obj_clear_flag(guider_ui.messagebox_cont_1,LV_OBJ_FLAG_HIDDEN);
//             selftest_flag = false;
//             lv_obj_add_flag(guider_ui.selftest_btn_21,LV_OBJ_FLAG_CLICKABLE);
//             if(mytimer_3 != NULL)
//                 lv_timer_set_repeat_count(mytimer_3,0);
//         }
//     }
//     if (lv_obj_is_valid(guider_ui.printmessage_cont_1))
//     {
//         if(material_seneor == '4' && print_state != 0 && print_state != 1)
//         {
//             lv_label_set_text(guider_ui.printmessage_label_3,"已检测到耗材使用完，请检查并更换耗材后点击按钮重新开始打印.");
//             lv_obj_clear_flag(guider_ui.printmessage_cont_1,LV_OBJ_FLAG_HIDDEN);
//         }
//     }
// }

// void refresh_printing_time_percent()
// {
//     int num = 0;
//     if (lv_obj_is_valid(guider_ui.homepage_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.homepage_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             if(print_printed_time[0] != '\0')
//             {
//                 if(guider_ui.homepage_label_8 != NULL)
//                 {
//                     lv_label_set_text(guider_ui.homepage_label_8, print_printed_time);
//                 }
//             }
//             if(print_remain_time[0] != '\0')
//             {
//                 if(guider_ui.homepage_label_11 != NULL)
//                 {
//                     lv_label_set_text(guider_ui.homepage_label_11, print_remain_time);
//                 }
//             }
//             if(print_percent[0] != '\0')
//             {
//                 num = atoi(print_percent);
//                 if(guider_ui.homepage_label_9 != NULL)
//                 {
//                     lv_label_set_text(guider_ui.homepage_label_9, print_percent);
//                     if(guider_ui.homepage_bar_1 != NULL)
//                     {
//                         lv_bar_set_value(guider_ui.homepage_bar_1, num, LV_ANIM_OFF);
//                     }
//                 }
//                 if(num >= 100)
//                 {
//                     CrLogI("print percent num = %d",num);
//                     print_state = 0;
//                 }
//             }
//         }
//     }
//     if(guider_ui.fullscreen_mode_label_1 != NULL)
//     {
//         char temp[PERCENT_LEN+2];
//         unsigned char i;
//         for(i=0;i<PERCENT_LEN;i++)
//         {
//             if(print_percent[i] == '\0')
//             {
//                 break;
//             }
//             temp[i] = print_percent[i];
//         }
//         temp[i] = '%';
//         temp[i+1] = '\0';
//         lv_label_set_text(guider_ui.fullscreen_mode_label_1, temp);
//     }
//     if(guider_ui.fullscreen_mode_img_mask != NULL)
//     {
//         unsigned int hg = 0;
//         if(num < 100)
//         {
//             hg = 3 * (100 - num);
//         }
//         else
//         {
//             hg = 0;
//         }
//         lv_obj_set_size(guider_ui.fullscreen_mode_img_mask, 300, hg);
//     }
// }

// void refresh_net_info()
// {
//     if(wifi_state == '1')
//     {
//         if(wifi_ip[0] != '\0')
//         {
//             if(guider_ui.netwowork_information_label_8 != NULL)
//             {
//                 lv_label_set_text(guider_ui.netwowork_information_label_8, wifi_ip);
//             }
//         }
//         if(wifi_name[0] != '\0')
//         {
//             if(guider_ui.netwowork_information_label_2 != NULL)
//             {
//                 lv_label_set_text(guider_ui.netwowork_information_label_2, wifi_name);
//             }
//         }
//     }
//     else
//     {
//         if(guider_ui.netwowork_information_label_2 != NULL)
//         {
//             lv_label_set_text(guider_ui.netwowork_information_label_2, "网络");
//         }
//         if(guider_ui.netwowork_information_label_8 != NULL)
//         {
//             lv_label_set_text(guider_ui.netwowork_information_label_8, "");
//         }
//     }
// }

// void refresh_print_state()
// {
//     switch(print_state)
//     {

//         case 0:         //完成打印
//         case 1:         //停止打印
//         case 2:         //暂停打印
//         case 3:         //继续打印
//         {
//             if(!selftestflag)
//             guider_load_screen(SCR_HOME_PAGE);
//             break;
//         }
//         //继续上次的断电续打
//         case 4:
//         {
//             break;
//         }
//         //表示停止断电续打
//         case 5:
//         {
//             break;
//         }
//         //温度升温中
//         case 6:
//     //        if(cur_scr != SCR_MSGBOX_PAGE)
//     //        {
//     //            guider_load_screen(SCR_MSGBOX_PAGE);
//     //            lv_demo_printer_anim_in_all(guider_ui.msgbox_cont_1, LV_DEMO_PRINTER_ANIM_DELAY);
//     //            lv_label_set_text(guider_ui.msgbox_label_msg, "喷头加热中，请耐心等待");
//     //        }
//             break;
//         default:
//             break;
//     }
// }

// static void wifi_select_btn_ok_event_handler(lv_event_t *e)
// {
// 	lv_event_code_t code = lv_event_get_code(e);
// 	switch (code)
// 	{
//         case LV_EVENT_CLICKED:
//         {
//             send_buzzer(0x01);
//             if(exchange_wifi_state == '2')
//             {
//                 char ctemp[WIFI_NAME_LEN+4] = "2\t";
//                 unsigned char i = 0;
//                 for(i=0;i<strlen(exchange_wifi_name);i++)
//                 {
//                     ctemp[i+2] = exchange_wifi_name[i];
//                 }
//                 set_printer_data(0x07,strlen(ctemp),ctemp);
//                 connectwifi_state = true;
//                 get_printer_data(0x07, 1, "2");
//                 //进入等待状态
//                 wait_timer = lv_timer_create(waittimer_handler, 10000, NULL);
//                 lv_obj_clear_flag(guider_ui.wait_cont_1,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_clear_flag(guider_ui.wait_spinner_1,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.wait_label_1,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.wait_label_2,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.wait_label_3,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.wait_btn_3,LV_OBJ_FLAG_HIDDEN);
//     //            lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
//                 CrLogI("disconnect wifi,wait wifi refresh....");
//             }
//             else if(exchange_wifi_state == '1')
//             {
//                 char ctemp[WIFI_NAME_LEN+4] = "1\t";
//                 unsigned char i = 0;
//                 for(i=0;i<strlen(exchange_wifi_name);i++)
//                 {
//                     ctemp[i+2] = exchange_wifi_name[i];
//                 }
//                 set_printer_data(0x07,strlen(ctemp),ctemp);
//                 connectwifi_state = true;
//                 //进入等待状态
//                 wait_timer = lv_timer_create(waittimer_handler, 10000, NULL);
//                 lv_obj_clear_flag(guider_ui.wait_cont_1,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_clear_flag(guider_ui.wait_spinner_1,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.wait_label_1,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.wait_label_2,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.wait_label_3,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.wait_btn_3,LV_OBJ_FLAG_HIDDEN);
//     //            lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
//                 CrLogI("connect the save wifi,wait wifi refresh....");
//             }
//             lv_obj_add_flag(guider_ui.my_msgbox_cont_1, LV_OBJ_FLAG_HIDDEN);
//             lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
//         }
//             break;
//         default:
//             break;
// 	}
// }

// static void wifi_select_btn_cancel_event_handler(lv_event_t *e)
// {
// 	lv_event_code_t code = lv_event_get_code(e);
// 	switch (code)
// 	{
//         case LV_EVENT_CLICKED:
//         {
//             send_buzzer(0x01);
//             if(exchange_wifi_state == '1' || exchange_wifi_state == '2')
//             {
//                 char ctemp[WIFI_NAME_LEN+4] = "3\t";
//                 unsigned char i = 0;
//                 for(i=0; i<strlen(exchange_wifi_name); i++)
//                 {
//                     ctemp[i+2] = exchange_wifi_name[i];
//                 }
//                 set_printer_data(0x07,strlen(ctemp),ctemp);
//                 connectwifi_state = true;
//             }
//             lv_obj_add_flag(guider_ui.my_msgbox_cont_1, LV_OBJ_FLAG_HIDDEN);
//             lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
//             get_printer_data(0x07, 1, "2");
//             //进入等待状态
//             wait_timer = lv_timer_create(waittimer_handler, 10000, NULL);
//             lv_obj_clear_flag(guider_ui.wait_cont_1,LV_OBJ_FLAG_HIDDEN);
//             lv_obj_clear_flag(guider_ui.wait_spinner_1,LV_OBJ_FLAG_HIDDEN);
//             lv_obj_add_flag(guider_ui.wait_label_1,LV_OBJ_FLAG_HIDDEN);
//             lv_obj_add_flag(guider_ui.wait_label_2,LV_OBJ_FLAG_HIDDEN);
//             lv_obj_add_flag(guider_ui.wait_label_3,LV_OBJ_FLAG_HIDDEN);
//             lv_obj_add_flag(guider_ui.wait_btn_3,LV_OBJ_FLAG_HIDDEN);
//     //        lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
//             CrLogI("forget wifi,wait wifi refresh....");
//         }
//             break;
//         default:
//             break;
// 	}
// }

// static void wifi_select_btn_infomation_event_handler(lv_event_t *e)
// {
// 	lv_event_code_t code = lv_event_get_code(e);
// 	switch (code)
// 	{
//         case LV_EVENT_CLICKED:
//         {
//             send_buzzer(0x01);
//             lv_obj_add_flag(guider_ui.my_msgbox_cont_1, LV_OBJ_FLAG_HIDDEN);
//             lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
//             guider_load_screen(SCR_NETINFOMATION_PAGE);
//         }
//             break;
//         default:
//             break;
// 	}
// }

// static void wifi_dialog(unsigned char flag,lv_obj_t * obj)
// {
//     guider_ui.my_msgbox_cont_1 = lv_obj_create(lv_layer_top());
//     lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
//     lv_obj_add_flag(guider_ui.my_msgbox_cont_1, LV_OBJ_FLAG_CLICKABLE);
//     lv_obj_set_size(guider_ui.my_msgbox_cont_1, 480, 800);
// 	lv_obj_add_style(guider_ui.my_msgbox_cont_1, &style_cont_msgbox, LV_PART_MAIN|LV_STATE_DEFAULT);
//     lv_obj_t * label = lv_label_create(guider_ui.my_msgbox_cont_1);
//     if(flag == 0)
//         lv_obj_set_size(label, 160, 186);
//     else
//         lv_obj_set_size(label, 160, 124);
//     lv_obj_align_to(label,obj,LV_ALIGN_OUT_BOTTOM_MID,0,0);

// 	//btn_1
// 	lv_obj_t * btn_1 = lv_btn_create(guider_ui.my_msgbox_cont_1);
//     lv_obj_set_size(btn_1, 160, 62);
//     lv_obj_align_to(btn_1,label,LV_ALIGN_TOP_MID,0,0);
// 	lv_obj_add_style(btn_1, &style_background_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
// 	lv_obj_t * label_1 = lv_label_create(btn_1);
//     if(flag == 0)
//     {
//         lv_label_set_text(label_1, "断开");
//     }
//     else
//     {
//         lv_label_set_text(label_1, "连接");
//     }

// 	lv_obj_set_style_text_color(label_1, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
// 	lv_obj_set_style_text_font(label_1, &lv_font_simsun_24, LV_STATE_DEFAULT);
// 	lv_obj_set_style_pad_all(btn_1, 0, LV_STATE_DEFAULT);
// 	lv_obj_align(label_1, LV_ALIGN_CENTER, 0, 0);

// 	//btn_2
// 	lv_obj_t * btn_2 = lv_btn_create(guider_ui.my_msgbox_cont_1);
//     lv_obj_set_size(btn_2, 160, 62);
//     lv_obj_align_to(btn_2,btn_1,LV_ALIGN_OUT_BOTTOM_MID,0,0);
// 	lv_obj_add_style(btn_2, &style_background_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
// 	lv_obj_t * label_2 = lv_label_create(btn_2);
// 	lv_label_set_text(label_2, "忘记密码");
// 	lv_obj_set_style_text_color(label_2, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
// 	lv_obj_set_style_text_font(label_2, &lv_font_simsun_24, LV_STATE_DEFAULT);
// 	lv_obj_set_style_pad_all(btn_2, 0, LV_STATE_DEFAULT);
// 	lv_obj_align(label_2, LV_ALIGN_CENTER, 0, 0);

// 	if(flag == 0)
//     {
//         //btn_3
//         lv_obj_t * btn_3 = lv_btn_create(guider_ui.my_msgbox_cont_1);
//         lv_obj_set_size(btn_3, 160, 62);
//         lv_obj_align_to(btn_3,btn_2,LV_ALIGN_OUT_BOTTOM_MID,0,0);
//         lv_obj_add_style(btn_3, &style_background_btn_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//         lv_obj_t * label_3 = lv_label_create(btn_3);
//         lv_label_set_text(label_3, "IP信息");
//         lv_obj_set_style_text_color(label_3, lv_color_make(0xff, 0xff, 0xff), LV_STATE_DEFAULT);
//         lv_obj_set_style_text_font(label_3, &lv_font_simsun_24, LV_STATE_DEFAULT);
//         lv_obj_set_style_pad_all(btn_3, 0, LV_STATE_DEFAULT);
//         lv_obj_align(label_3, LV_ALIGN_CENTER, 0, 0);
//         lv_obj_add_event_cb(btn_3, wifi_select_btn_infomation_event_handler, LV_EVENT_ALL, NULL);
//     }

// 	lv_obj_add_event_cb(btn_1, wifi_select_btn_ok_event_handler, LV_EVENT_ALL, NULL);
// 	lv_obj_add_event_cb(btn_2, wifi_select_btn_cancel_event_handler, LV_EVENT_ALL, NULL);
// 	lv_obj_add_event_cb(guider_ui.my_msgbox_cont_1, wifi_select_btn_cancel_event_handler, LV_EVENT_ALL, NULL);
// }

// static void wifi_list_event_handler(lv_event_t *e)
// {
// 	lv_event_code_t code = lv_event_get_code(e);
// 	lv_obj_t * obj = lv_event_get_target(e);
// 	unsigned char i = 0;
// 	if (lv_obj_is_valid(guider_ui.settings_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.settings_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             switch (code)
//             {
//                 case LV_EVENT_CLICKED:
//                 {
//                     uint8_t *dat = lv_event_get_user_data(e);
//                     exchange_wifi_state = *dat;
//                     const char * src = lv_list_get_btn_text(guider_ui.settings_list_1, obj);
//                     if (src == NULL)
//                         return;
//                     for(i=0;i<sizeof(exchange_wifi_name);i++)
//                         exchange_wifi_name[i] = '\0';
//                     i = 0;
//                     while (*src)
//                     {
//                         exchange_wifi_name[i++] = *src++;
//                     }
//                     switch(exchange_wifi_state)
//                     {
//                         case '2':
//                             wifi_dialog(0,obj);
//                             break;
//                         case '1':
//                             wifi_dialog(1,obj);
//                             break;
//                         case '0':
//                         {
//                             lv_obj_clear_flag(guider_ui.inputboard_wifi_cont_1, LV_OBJ_FLAG_HIDDEN);
//                             lv_obj_add_state(guider_ui.wifi_seting_ta, LV_STATE_FOCUSED);
//                             lv_textarea_set_text(guider_ui.wifi_seting_ta,"");
//                             break;
//                         }
//                         default:
//                             break;
//                     }
//                 break;
//                 }
//                 default:
//                     break;
//             }
//         }
//     }
// 	if (lv_obj_is_valid(guider_ui.selftest_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.selftest_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             switch (code)
//             {
//                 case LV_EVENT_CLICKED:
//                 {
//                     uint8_t *dat = lv_event_get_user_data(e);
//                     exchange_wifi_state = *dat;
//                     const char * src = lv_list_get_btn_text(guider_ui.selftest_list_1, obj);
//                     if (src == NULL)
//                         return;
//                     for(i=0;i<sizeof(exchange_wifi_name);i++)
//                         exchange_wifi_name[i] = '\0';
//                     i = 0;
//                     while (*src)
//                     {
//                         exchange_wifi_name[i++] = *src++;
//                     }
//                     switch(exchange_wifi_state)
//                     {
//                         case '2':
//                             wifi_dialog(0,obj);
//                             break;
//                         case '1':
//                             wifi_dialog(1,obj);
//                             break;
//                         case '0':
//                         {
//                             CrLogI("msgbox");
//                             lv_obj_clear_flag(guider_ui.inputboard_wifi_cont_1, LV_OBJ_FLAG_HIDDEN);
//                             lv_obj_add_state(guider_ui.wifi_seting_ta, LV_STATE_FOCUSED);
//                             lv_textarea_set_text(guider_ui.wifi_seting_ta,"");
//                             break;
//                         }
//                         default:
//                             break;
//                     }
//                 break;
//                 }
//                 default:
//                     break;
//             }
//         }
//     }
// }

// void showupdateinfo(char *data,int flag)
// {
//     if(flag == 1)
//     {
//         if (lv_obj_is_valid(guider_ui.update_version_cont_1))
//         {
//             if (!lv_obj_has_flag(guider_ui.update_version_cont_1,LV_OBJ_FLAG_HIDDEN))
//             {
//                 if(guider_ui.update_version_label_7 != NULL)
//                 {
//                     lv_label_set_text(guider_ui.update_version_label_7,"");
//                     lv_obj_set_style_text_align(guider_ui.update_version_label_7, LV_TEXT_ALIGN_LEFT, 0);
//                 }
//                 if(guider_ui.update_version_label_2 != NULL)
//                 {
//                     lv_label_set_text(guider_ui.update_version_label_2,"发现新版本");
//                 }
//                 lv_label_set_text(guider_ui.update_version_btn_2_label,"升级");
//                 lv_obj_clear_flag(guider_ui.update_version_label_3,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_clear_flag(guider_ui.update_version_label_4,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_clear_flag(guider_ui.update_version_label_5,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_clear_flag(guider_ui.update_version_label_6,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_clear_flag(guider_ui.update_version_label_10,LV_OBJ_FLAG_HIDDEN);

//                 if(guider_ui.update_version_label_7 != NULL)
//                 {
//                     lv_label_set_text(guider_ui.update_version_label_7,data);
//                 }
//                 if(guider_ui.update_version_label_4 != NULL && current_version[0] != '\0')
//                 {
//                     lv_label_set_text(guider_ui.update_version_label_4,current_version);
//                 }
//                 if(guider_ui.update_version_label_6 != NULL && new_version[0] != '\0')
//                 {
//                     lv_label_set_text(guider_ui.update_version_label_6,new_version);
//                 }
//                 if(guider_ui.update_version_label_10 != NULL && version_size[0] != '\0')
//                 {
//                     float temp = atoi(version_size);
//                     temp = temp / 1024.0 / 1024.0;
//                     char tempchar[10];
//                     snprintf(tempchar,10,"%.2fMB",temp);
//                     lv_label_set_text(guider_ui.update_version_label_10,tempchar);
//                 }
//             }
//         }
//     }
//     else
//     {
//         if (lv_obj_is_valid(guider_ui.update_version_cont_1))
//         {
//             if (!lv_obj_has_flag(guider_ui.update_version_cont_1,LV_OBJ_FLAG_HIDDEN))
//             {
//                 if(guider_ui.update_version_label_7 != NULL)
//                 {
//                     lv_label_set_text(guider_ui.update_version_label_7,"当前已是最新版本");
//                     lv_obj_set_style_text_align(guider_ui.update_version_label_7, LV_TEXT_ALIGN_CENTER, 0);
//                 }
//                 if(guider_ui.update_version_label_2 != NULL)
//                 {
//                     lv_label_set_text(guider_ui.update_version_label_2,"温馨提示");
//                 }
//                 lv_label_set_text(guider_ui.update_version_btn_2_label,"确定");
//                 lv_obj_add_flag(guider_ui.update_version_label_3,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.update_version_label_4,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.update_version_label_5,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.update_version_label_6,LV_OBJ_FLAG_HIDDEN);
//                 lv_obj_add_flag(guider_ui.update_version_label_10,LV_OBJ_FLAG_HIDDEN);
//             }
//         }
//     }
// }

// void refresh_upgrade_progress()
// {
//     if (lv_obj_is_valid(guider_ui.update_version_cont_1))
//     {
//         if (!lv_obj_has_flag(guider_ui.update_version_cont_1,LV_OBJ_FLAG_HIDDEN))
//         {
//             CrLogI("upgrade_progress is %s,version_flag is %c",upgrade_progress,version_flag);
//             if(guider_ui.update_version_bar_1 != NULL && upgrade_progress[0] != '\0')
//             {
//                 lv_obj_clear_flag(guider_ui.update_version_bar_1,LV_OBJ_FLAG_HIDDEN);
//                 lv_bar_set_value(guider_ui.update_version_bar_1, atoi(upgrade_progress), LV_ANIM_ON);
//             }
//             if(guider_ui.update_version_label_11 != NULL && version_flag != '\0')
//             {
//                 lv_obj_clear_flag(guider_ui.update_version_label_11,LV_OBJ_FLAG_HIDDEN);
//                 switch(version_flag)
//                 {
//                     //0：下载成功
//                     case '0':lv_label_set_text(guider_ui.update_version_label_11,"下载成功");break;
//                     //1：下载中
//                     case '1':lv_label_set_text(guider_ui.update_version_label_11,"下载中");break;
//                     //2：下载失败
//                     case '2':lv_label_set_text(guider_ui.update_version_label_11,"下载失败");break;
//                     //3：解压完成
//                     case '3':lv_label_set_text(guider_ui.update_version_label_11,"解压完成");break;
//                     //4、解压中
//                     case '4':lv_label_set_text(guider_ui.update_version_label_11,"解压中");break;
//                     //5、解压失败
//                     case '5':lv_label_set_text(guider_ui.update_version_label_11,"解压失败");break;
//                     //6：安装完成
//                     case '6':lv_label_set_text(guider_ui.update_version_label_11,"安装完成,设备即将重启");break;
//                     //7：安装中
//                     case '7':lv_label_set_text(guider_ui.update_version_label_11,"安装中");break;
//                     //8：安装失败
//                     case '8':lv_label_set_text(guider_ui.update_version_label_11,"安装失败,设备即将重启");break;
//                     default:break;
//                 }
//             }
//         }
//     }
// }


// void showerrormsg(char *data,bool flag)
// {
//     mymsgbox(data);
// }

// void show_wifi_name(char *data,int len)
// {
//     char dis_wifi_name[WIFI_NAME_LEN+1];
//     bool flag;
//     unsigned char i,j;

//     static lv_style_t style_list_btns_default;
// 	lv_style_reset(&style_list_btns_default);
// 	lv_style_set_radius(&style_list_btns_default, 3);
// 	lv_style_set_bg_color(&style_list_btns_default, lv_color_make(0x3e, 0x3e, 0x3e));
// 	lv_style_set_bg_grad_color(&style_list_btns_default, lv_color_make(0x3e, 0x3e, 0x3e));
// 	lv_style_set_bg_grad_dir(&style_list_btns_default, LV_GRAD_DIR_VER);
// 	lv_style_set_bg_opa(&style_list_btns_default, 255);
// 	lv_style_set_text_color(&style_list_btns_default, lv_color_make(0xff, 0xff, 0xff));
// 	lv_style_set_text_font(&style_list_btns_default, &lv_font_simsun_24);

//     char *temp = strtok(data,"\t");
//     while(temp)
//     {
//         flag = false;
//         j = 0;
//         for(i=0;i<strlen(temp);i++)
//         {
//             if(flag == false)
//             {
//                 if(*(temp + i) == ':')
//                 {
//                     flag = true;
//                     dis_wifi_name[j] = '\0';
//                     j = 0;
//                 }
//                 else
//                     dis_wifi_name[j++] = *(temp + i);
//             }
//             else
//             {
//                 if (lv_obj_is_valid(guider_ui.settings_cont_1))
//                 {
//                     if (!lv_obj_has_flag(guider_ui.settings_cont_1,LV_OBJ_FLAG_HIDDEN))
//                     {
//                         switch(*(temp + i))
//                         {
//                         case '2':
//                             list_btn = lv_list_add_btn(guider_ui.settings_list_1, LV_SYMBOL_WIFI, dis_wifi_name);
//                             lv_obj_add_style(list_btn, &style_list_btns_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//                             lv_obj_add_event_cb(list_btn, wifi_list_event_handler, LV_EVENT_CLICKED, "2");
//                             lv_obj_set_style_pad_all(list_btn,20,LV_STATE_DEFAULT);
//                             break;
//                         case '1':
//                             list_btn = lv_list_add_btn(guider_ui.settings_list_1, LV_SYMBOL_UPLOAD,dis_wifi_name);
//                             lv_obj_add_style(list_btn, &style_list_btns_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//                             lv_obj_add_event_cb(list_btn, wifi_list_event_handler, LV_EVENT_CLICKED, "1");
//                             lv_obj_set_style_pad_all(list_btn,20,LV_STATE_DEFAULT);
//                             break;
//                         case '0':
//                             list_btn = lv_list_add_btn(guider_ui.settings_list_1, LV_SYMBOL_MINUS, dis_wifi_name);
//                             lv_obj_add_style(list_btn, &style_list_btns_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//                             lv_obj_add_event_cb(list_btn, wifi_list_event_handler, LV_EVENT_CLICKED, "0");
//                             lv_obj_set_style_pad_all(list_btn,20,LV_STATE_DEFAULT);
//                             break;
//                         default:
//                             break;
//                         }
//                     }
//                 }
//                 if (lv_obj_is_valid(guider_ui.selftest_cont_1))
//                 {
//                     if (!lv_obj_has_flag(guider_ui.selftest_cont_1,LV_OBJ_FLAG_HIDDEN))
//                     {
//                         switch(*(temp + i))
//                         {
//                         case '2':
//                             list_btn = lv_list_add_btn(guider_ui.selftest_list_1, LV_SYMBOL_WIFI, dis_wifi_name);
//                             lv_obj_add_style(list_btn, &style_list_btns_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//                             lv_obj_add_event_cb(list_btn, wifi_list_event_handler, LV_EVENT_CLICKED, "2");
//                             lv_obj_set_style_pad_all(list_btn,20,LV_STATE_DEFAULT);
//                             break;
//                         case '1':
//                             list_btn = lv_list_add_btn(guider_ui.selftest_list_1, LV_SYMBOL_UPLOAD,dis_wifi_name);
//                             lv_obj_add_style(list_btn, &style_list_btns_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//                             lv_obj_add_event_cb(list_btn, wifi_list_event_handler, LV_EVENT_CLICKED, "1");
//                             lv_obj_set_style_pad_all(list_btn,20,LV_STATE_DEFAULT);
//                             break;
//                         case '0':
//                             list_btn = lv_list_add_btn(guider_ui.selftest_list_1, LV_SYMBOL_MINUS, dis_wifi_name);
//                             lv_obj_add_style(list_btn, &style_list_btns_default, LV_PART_MAIN|LV_STATE_DEFAULT);
//                             lv_obj_add_event_cb(list_btn, wifi_list_event_handler, LV_EVENT_CLICKED, "0");
//                             lv_obj_set_style_pad_all(list_btn,20,LV_STATE_DEFAULT);
//                             break;
//                         default:
//                             break;
//                         }
//                     }
//                 }
//                 flag = false;
//             }
//         }
//         temp = strtok(NULL,"\t");
//     }
// }

//void refresh_theme()
//{
//    if (lv_obj_is_valid(guider_ui.screen_setting_cont_1))
//    {
//        if (!lv_obj_has_flag(guider_ui.screen_setting_cont_1,LV_OBJ_FLAG_HIDDEN))
//        {
//    //        if(guider_ui.screen_setting_btn_theme_color != NULL)
//            {
//                //待实现，根据不同的主题色设置这个按钮的颜色
//            }
//        }
//    }
//    if (lv_obj_is_valid(guider_ui.theme_color_cont_1))
//    {
//        if (!lv_obj_has_flag(guider_ui.theme_color_cont_1,LV_OBJ_FLAG_HIDDEN))
//        {
//            //待实现，根据不同的主题色设置这个按钮的颜色
//            //ref refresh_auto_level_point();
//        }
//    }
//}
//
/*
flag是一个十六进制数，最多可以表示256个类型，对于目前来说足够
0x01：获取打印机的Gcode文件名称和目录
0x02：获取打印机的Z轴偏移数据
0x03：获取当前喷头和热床温度
0x04：获取当前XYZ位置
0x05：获取PLA、ABS预热的温度参数
0x06：获取当前风扇状态
0x07：获取当前照明状态
0x08：获取当前WIFI状态
0x09：获取当前语言
0x0a：获取运动参数，包括：传动比参数、最大加速度参数、最大拐角参数、最大速度参数
0x0b：获取温度PID参数，包括喷头和热床的PID参数
0x0c：获取关于本机页面的所有参数
0x0d：获取打印时间和打印进度
0x0e：获取是否开启断电续打
0x0f：获取是否进行开机自检
*/
void get_printer_data(unsigned char flag, unsigned int len, char *data)
{
#ifdef IS_SYSTEM_USE
	GetPrinterDataFromManager(flag, len, data);
#endif
}

char ctemp[100];
//void recory_file_ok_event_handler(lv_event_t * e)
//{
//    lv_event_code_t code = lv_event_get_code(e);
//	switch (code)
//	{
//        case LV_EVENT_CLICKED:
//        {
//            send_buzzer(0x01);
////            lv_obj_clean(guider_ui.my_msgbox_cont_1);
////            lv_obj_del(guider_ui.my_msgbox_cont_1);
//            lv_obj_add_flag(guider_ui.my_msgbox_two_cont_1, LV_OBJ_FLAG_HIDDEN);
//            lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
//            set_printer_data(0x0f,2,"4");
//            print_state = 1;
//            guider_load_screen(SCR_PRINT_PRINTING_PAGE);
//            lv_demo_printer_anim_in_all(guider_ui.print_printing_cont_1, LV_DEMO_PRINTER_ANIM_DELAY);
//        }
//		break;
//        default:
//		break;
//	}
//}
//void recory_file_cancel_event_handler(lv_event_t * e)
//{
//    lv_event_code_t code = lv_event_get_code(e);
//	switch (code)
//	{
//        case LV_EVENT_CLICKED:
//        {
//            send_buzzer(0x01);
//            set_printer_data(0x0f,2,"5");
//            print_state = 0;
////            lv_obj_clean(guider_ui.my_msgbox_cont_1);
////            lv_obj_del(guider_ui.my_msgbox_cont_1);
//            lv_obj_add_flag(guider_ui.my_msgbox_two_cont_1, LV_OBJ_FLAG_HIDDEN);
//            lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
//        }
//		break;
//        default:
//		break;
//	}
//}
//
/*
回传的参数结束字符固定为：'\0'
如果有多个参数，则参数间使用的间隔符为：'\t'
*/
void get_response_printer_data(MessageState flag, unsigned int len, char *data)
{
    unsigned char i,j;
    char file_total[FILE_NUM_SIZE+1];
    CrLogI("get_response_data is:%s\n.",data);
    switch(flag)
    {
        case CONTROL_FILE:
        {
            if(*data == '1')      //本地文件
            {
                data++;
                if(*data == '0')
                {
                    for(i=0; i<len; i++)
                    {
                        if(i>(FILE_NUM_SIZE-1))
                        {
                            break;
                        }
                        file_total[i] = *(data+i+2);
                    }
                    file_total[i] = '\0';
                    print_total_files = atoi(file_total);
                    if(print_total_files)
                    {
                        print_file_pages = print_total_files / FILE_NUM_PRE_PAGE;
                        if((print_total_files % FILE_NUM_PRE_PAGE) != 0)
                        {
                            print_file_pages++;
                        }
                        current_page = 0;
                        clicked_file_num = 0;
                        switch(UIType)
                        {
                            // case CR_10_H1:handle_file();break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:set_files_count(print_total_files);break;
                        }
                    }
                    else
                    {
                        print_file_pages = print_total_files / FILE_NUM_PRE_PAGE;
                        switch(UIType)
                        {
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:set_files_count(0);break;
                        }
                    }

                }
                else if(*data == '1')
                {
                    if(*(data+1) == '\t')
                    {
                        data = data + 2;
                        switch(UIType)
                        {
                            // case CR_10_H1:showfile(data,len);break;
                            case CR_K1: 
                            case CR_K1_Max:
                            case PF_05:analyze_files_info_respone(data, len); break;
                        }                        
                    }
                }
                else if(*data == '2')
                {
                    data = data + 2;
                    switch(UIType)
                    {
                        // case CR_10_H1:readbigfile(data,len-3);break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:analyze_filling_chart_info_respone(data,len-3); break;
                    }      
                }
                else if(*data == '3')
                {
                    strcpy(ctemp,"检测到意外停止的打印文件:");
                    char file[256] = {0};
                    // for(i=0; i<len-1; i++)
                    // {
                    //     if(i>19)
                    //     {
                    //         break;
                    //     }
                    //     if(*(data+i+2) == '\0')
                    //     {
                    //         break;
                    //     }
                    //     file[i] = *(data+i+2);
                    // }
                    char state[20] = {0};
                    sscanf(data+1, "\t%s\t%s", state, file);
                    CrLogI("powerloss filename:%s,state:%d", file, atoi(state));
                    switch(UIType)
                    {
                        // case CR_10_H1:{
                        //     strcpy(printing_file_name,file);
                        //     strcat(ctemp,file);
                        //     mymsgbox_two(ctemp);
                        //     break;
                        // }
                        case CR_K1: 
                        case CR_K1_Max:
                        case PF_05:set_powerloss_recovery_info(atoi(state)); break;
                    }      
                }
                else if(*data == '5')
                {
                    data++;
                    char *temp = strtok(data,"\t");
                    int data_flag = 0;
                    memset(&print_job, 0, sizeof(PrintJobInfo_t));
                    while(temp)
                    {
                        switch(data_flag)
                        {
                            case 0:strcpy(print_job.printfile_name, temp);  CrLogI("%d:%s", data_flag, print_job.printfile_name);break;
                            case 1:print_job.start_px = atoi(temp);         CrLogI("%d:%d", data_flag, print_job.start_px);break;
                            case 2:print_job.end_px = atoi(temp);           CrLogI("%d:%d", data_flag, print_job.end_px);break;
                            case 3:print_job.model_height = atof(temp);     CrLogI("%d:%f", data_flag, print_job.model_height);break;
                            case 4:print_job.model_layerheight = atof(temp);CrLogI("%d:%f", data_flag, print_job.model_layerheight);break;
                            case 5:strcpy(print_job.printimg_src, temp);    CrLogI("%d:%s", data_flag, print_job.printimg_src);break;
                            case 6:strcpy(print_job.gcode_type, temp);      CrLogI("%d:%s", data_flag, print_job.gcode_type);break;
                        }
                        data_flag++;
                        temp = strtok(NULL,"\t");
                    }

                    switch(UIType)
                    {
                        // case CR_10_H1:break;
                        case CR_K1: 
                        case CR_K1_Max:
                        case PF_05:
                            home_printing_set_print_file_name(print_job.printfile_name);
                            home_printing_set_filling_chart_name(print_job.printimg_src, print_job.start_px, print_job.end_px, print_job.model_height, print_job.model_layerheight);
                            break;
                    }      
                }
                else if(*data == '6')
                {
                    char *temp = strtok(data, "\t");
                    CrLogI("analyze the PreparePrint flag:%s",temp);
                    temp = strtok(NULL, "\t");
                    CrLogI("analyze the PreparePrint content:%s",temp);
                    int process = atoi(temp);
                    if(process < 100)
                    {
                        system_state.PreStartprint_state = true;
                    }
                    else
                    {
                        system_state.PreStartprint_state = false;
                    }
                    switch(UIType)
                    {  
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:refresh_prepare_process(process);break;
                    } 
                    
                }
            }
            else if(*data == '2')      //打印历史记录
            {
                data++;
                if(*data == '0')
                {
                    data = data + 2;
                    history_total_files = atoi(data);
                    if(history_total_files)
                    {
                        historyfile_pages = history_total_files / HISTORY_NUM_PRE_PAGE;
                        if((history_total_files % HISTORY_NUM_PRE_PAGE) != 0)
                        {
                            historyfile_pages++;
                        }
                        history_current_page = 0;
                        history_clientnum = 0;
                        switch(UIType)
                        {
                            // case CR_10_H1:handle_history_file();break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:set_print_record_count(history_total_files); break;
                        }  
                    }
                    else
                    {
                        historyfile_pages = history_total_files / HISTORY_NUM_PRE_PAGE;
                        switch(UIType)
                        {
                            case CR_K1: 
                            case CR_K1_Max:
                            case PF_05:set_print_record_count(0); break;
                        }
                    }
                }
                else if(*data == '1')
                {
                    data = data + 2;
                    switch(UIType)
                    {
                        // case CR_10_H1:showhistoryfile(data,len);break;
                        case CR_K1: 
                        case CR_K1_Max:
                        case PF_05:analyze_print_records_info_respone(data, len); break;
                    }
                }
                else if(*data == '2')
                {
                    char temp[2048] = {0};
                    if (data) {
                        memcpy(temp, data, len);
                    }
                    char * tempbuff = strtok(temp, "\t");
                    if(!tempbuff)
                    {
                        CrLogW("Analytical data Error");
                        return;
                    }
                    tempbuff = strtok(NULL, "\t");  //过滤第一个字段为参数控制
                    int i = 0;
                    HistoryInfo_t history_info = {0};
                    while(tempbuff)
                    {
                        
                        switch (i)
                        {
                            case 0:strcpy(history_info.filename, tempbuff);     break;
                            case 1:strcpy(history_info.bedtemp, tempbuff);      break;
                            case 2:strcpy(history_info.nozzletemp, tempbuff);   break;
                            case 3:strcpy(history_info.timecost, tempbuff);     break;
                            case 4:strcpy(history_info.consumables, tempbuff);  break;
                            case 5:strcpy(history_info.preview, tempbuff);      break;
                            case 6:strcpy(history_info.index, tempbuff);        break;
                            case 7:strcpy(history_info.filamenttype, tempbuff); break;
                            default:CrLogW("data error, i:%d", i); break;
                        }
                        i++;
                        tempbuff = strtok(NULL, "\t");
                    }

                    // int result = sscanf(data, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s",history_info.filename, \
                    // history_info.bedtemp, history_info.nozzletemp, history_info.timecost, \
                    // history_info.consumables, history_info.preview, history_info.index, history_info.filamenttype);

                    CrLogI("result %s,%s,%s,%s,%s,%s,%s,%s.",history_info.filename, \
                    history_info.bedtemp, history_info.nozzletemp, history_info.timecost, \
                    history_info.consumables, history_info.preview, history_info.index, history_info.filamenttype);
                    if(history_info.filename)
                    {
                        switch(UIType)
                        {
                            // case CR_10_H1:break;
                            case CR_K1: 
                            case CR_K1_Max:
                            case PF_05:FromHistoryToPreview(true,history_info); break;
                        }
                    }
                    else
                    {
                        switch(UIType)
                        {
                            // case CR_10_H1:break;
                            case CR_K1: 
                            case CR_K1_Max:
                            case PF_05:FromHistoryToPreview(false,history_info); break;
                        }
                    }
                }
            }
            else if(*data == '3')      //视频列表
            {
                data++;
                if(*data == '0')
                {
                    data = data + 2;
                    videolist_total_files = atoi(data);
                    if(videolist_total_files)
                    {
                        videolist_pages = videolist_total_files / VIDEO_NUM_PRE_PAGE;
                        if((videolist_total_files % VIDEO_NUM_PRE_PAGE) != 0)
                        {
                            videolist_pages++;
                        }
                        videolist_current_page = 0;
                        videolist_clientnum = 0;
                        switch(UIType)
                        {
                            // case CR_10_H1:handle_video_file();break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:set_vedioes_count(videolist_total_files); break;
                        }
                    }
                    else
                    {
                        videolist_pages = videolist_total_files / VIDEO_NUM_PRE_PAGE;
                        switch(UIType)
                        {
                            case CR_K1: 
                            case CR_K1_Max:
                            case PF_05:set_vedioes_count(videolist_total_files);break;
                        }
                    }
                }
                else if(*data == '1')
                {
                    data = data + 2;
                    switch(UIType)
                    {
                        // case CR_10_H1:showvideolistfile(data,len);break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:analyze_vedioes_info_respone(data, len);break;
                    }
                }
            }
            break; 
        }
        case CONTROL_Z_AXIS_OFFSET:  //0x02：获取打印机的Z轴偏移数据
        {
            for(i=0;i<len;i++)
            {
                if(i>(OFFSET_LEN-1))
                {
                    break;
                }
                zoffset_value[i] = *(data+i);
                if(*(data+i) == '\0')
                {
                    break;
                }
            }
            zoffset_value[i] =  '\0';
            switch(UIType)
            {
                // case CR_10_H1:refresh_zoffset_value();break;
                case CR_K1: 
                case CR_K1_Max:
                case PF_05:set_offset_z(atof(zoffset_value)); break;
            }
            break;            
        }
        case CONTROL_HOT_BED_TEMP:  //0x03：获取当前喷头和热床温度
        {
            // j = 0;
            // for(i=0;i<len;i++)
            // {
            //     if(i>(HOTEND_TEMP_LEN-1))
            //     {
            //         break;
            //     }
            //     if(*(data+i) == '\t')
            //         break;
            //     else
            //         hotend_cur_temp[i] = *(data+i);
            // }
            // hotend_cur_temp[i] = '\0';
            // i++;
            // j = i;
            // for(;i<len;i++)
            // {
            //     if((i-j)>(BED_TEMP_LEN-1))
            //     {
            //         break;
            //     }
            //     if(*(data+i) == '\t')
            //         break;
            //     else
            //         bed_cur_temp[i-j] = *(data+i);
            // }
            // bed_cur_temp[i-j] = '\0';
            // i++;
            // j = i;
            // for(;i<len;i++)
            // {
            //     if((i-j)>(HOTEND_TEMP_LEN-1))
            //     {
            //         break;
            //     }
            //     if(*(data+i) == '\t')
            //         break;
            //     else
            //         hotend_max_temp[i-j] = *(data+i);
            // }
            // hotend_max_temp[i-j] = '\0';
            // i++;
            // j = i;
            // for(;i<len;i++)
            // {
            //     if((i-j)>(BED_TEMP_LEN-1))
            //     {
            //         break;
            //     }
            //     //if(*(data+i) == '\t')
            //     if(*(data+i) == '\0')
            //         break;
            //     else
            //         bed_max_temp[i-j] = *(data+i);
            // }
            // bed_max_temp[i-j] = '\0';


            sscanf(data, "%s\t%s\t%s\t%s\t%s", hotend_cur_temp, bed_cur_temp, hotend_max_temp, bed_max_temp, chassis_temp);
            CrLogI("hotcur:%s, bedcur:%s, hottag:%s, bedtag:%s, chassis_temp:%s",hotend_cur_temp, bed_cur_temp, hotend_max_temp, bed_max_temp, chassis_temp);
            switch(UIType)
            {
                // case CR_10_H1:refresh_temp(0x0f);break;
                case CR_K1: 
                case CR_K1_Max:
                case PF_05:{
                    set_hotend_temper(atoi(hotend_cur_temp), atoi(hotend_max_temp));
                    set_bed_temper(atoi(bed_cur_temp), atoi(bed_max_temp));
                    home_printing_set_chamber_temper(atoi(chassis_temp));
                    home_normal_set_chamber_temper(atoi(chassis_temp));
                    set_chassis_temper(atoi(chassis_temp));
                    // set_hotend_temper_filament(hotend_cur_temp, hotend_max_temp);
                    axis_move_set_hotend_temper_filament(hotend_cur_temp, hotend_max_temp);
                    JudgeHeatingIsNormal(atoi(hotend_cur_temp), atoi(bed_cur_temp));

                    // 刷新产测数据
                    if (isFactoryTest()) {
                        refresh_factory_bed_temp(atoi(bed_cur_temp));
                        refresh_factory_case_temp(atoi(chassis_temp));
                        refresh_factory_nuzzle_temp(atoi(hotend_cur_temp));
                    }
                    if(isMachineTest()) {
						refresh_laser_test_temp(atoi(hotend_cur_temp),atoi(bed_cur_temp));
                    }
                    
                    break;
                }
            }
            break;            
        }

        case CONTROL_XYZ_AXIS:  //0x04：获取当前XYZ位置
        {
            j = 0;
            for(i=0;i<len;i++)
            {
                if(i>(CUR_POSITION-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    cur_xposition[i] = *(data+i);
            }
            cur_xposition[i] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if((i-j)>(CUR_POSITION-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    cur_yposition[i-j] = *(data+i);
            }
            cur_yposition[i-j] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if((i-j)>(CUR_POSITION-1))
                {
                    break;
                }
                if(*(data+i) == '\0')
                    break;
                else
                    cur_zposition[i-j] = *(data+i);
            }
            cur_zposition[i-j] = '\0';
            CrLogI("x position:%s,y position:%s,z position:%s",cur_xposition, cur_yposition, cur_zposition);
            //printf("x position:%s,y position:%s,z position:%s\n",cur_xposition, cur_yposition, cur_zposition);
            switch(UIType)
            {
                // case CR_10_H1:refresh_axis_motor(1);break;
                case CR_K1:
                case CR_K1_Max:
                case PF_05:refresh_xyz_value(atoi(cur_xposition), atoi(cur_yposition), atoi(cur_zposition));break;
            }
            break;            
        }

        case CONTROL_PREPARATEMP:  //0x05：获取PLA、ABS、自定义预热的温度参数
        {
            if(*data == '0')
            {
                j = 0;
                for(i=0;i<len;i++)
                {
                    if(i>(HOTEND_TEMP_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        PLA_preheat_hotend[i] = *(data+i+1);
                }
                PLA_preheat_hotend[i] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(BED_TEMP_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\0')
                        break;
                    else
                        PLA_preheat_bed[i-j] = *(data+i+1);
                }
                PLA_preheat_bed[i-j] = '\0';
                switch(UIType)
                {
                    // case CR_10_H1:refresh_pla_setting(3);break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*data == '1')
            {
                j = 0;
                for(i=0;i<len;i++)
                {
                    if(i>(HOTEND_TEMP_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        ABS_preheat_hotend[i] = *(data+i+1);
                }
                ABS_preheat_hotend[i] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(BED_TEMP_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\0')
                        break;
                    else
                        ABS_preheat_bed[i-j] = *(data+i+1);
                }
                ABS_preheat_bed[i-j] = '\0';
                switch(UIType)
                {
                    // case CR_10_H1:refresh_petg_setting(3);break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*data == '2')
            {
                j = 0;
                for(i=0;i<len;i++)
                {
                    if(i>(HOTEND_TEMP_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        self_preheat_hotend[i] = *(data+i+1);
                }
                self_preheat_hotend[i] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(BED_TEMP_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\0')
                        break;
                    else
                        self_preheat_bed[i-j] = *(data+i+1);
                }
                self_preheat_bed[i-j] = '\0';
                switch(UIType)
                {
                    // case CR_10_H1:refresh_self_setting(3);break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            break;            
        }

        case CONTROL_PARAMETERS:
        {
            if(*data == '0')    //获取当前风扇状态
            {
                char *ch_m = strchr(data, '\t');
                char *ch_c = NULL;
                uint8_t model_percent = 0, chassis_percent = 0, auxi_percent = 0;
                if ( ch_m )  //第一个是模型风扇
                {
                    if ( (ch_m - data) < len )
                    {
                        *ch_m = '\0';
                        model_percent = atoi(data + 1);
                        // 第二个是机箱风扇
                        ch_c = strchr(ch_m + 1, '\t');
                    }

                }

                if ( ch_c )
                {
                    if ( (ch_m - data) < len )
                    {
                        *ch_c = '\0';
                        chassis_percent = atoi(ch_m + 1);
                        auxi_percent = atoi(ch_c + 1);
                    }
                }

                if ( model_percent > 0 )
                    fan_state = true;
                else
                    fan_state = false;

                switch(UIType)
                {
                    // case CR_10_H1:refresh_fan();break;
                    case CR_K1: 
                    case CR_K1_Max:
                    case PF_05:{
                        set_fans_status(model_percent, auxi_percent, chassis_percent);
                        break;
                    }
                }
            }
            else if(*data == '1')   //获取当前照明状态
            {
                if(*(data+1) == '1')
                    light_state = true;
                else
                    light_state = false;
                switch(UIType)
                {
                    // case CR_10_H1:refresh_light();break;
                    case CR_K1: 
                    case CR_K1_Max:
                    case PF_05:set_light_status(light_state); break;
                }
            }
            else if(*data == '4')   //获取自动关机状态
            {
                if(*(data+1) == '1')
                    auto_poweroff = true;
                else
                    auto_poweroff = false;
                switch(UIType)
                {
                    // case CR_10_H1://refresh_auto_poweroff();
                    // break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*data == '7')   //获取断料检测状态
            {
                material_seneor = *(data+1);
                if((print_state == 1) || (print_state == 2))
                {
                    if(material_seneor == '2')
                    {
                        if(plugin_material_task != NULL)
                        {
                            lv_timer_del(plugin_material_task);
                            plugin_material_task = NULL;
                        }
                    }
                    else if(material_seneor == '3')
                    {
                        if(plugin_material_task != NULL)
                        {
                            lv_timer_del(plugin_material_task);
                            plugin_material_task = NULL;
                        }
                    }
                    else if(material_seneor == '4')
                    {
                    }
                }
                CrLogI("refresh material_seneor");
                switch(UIType)
                {
                    // case CR_10_H1:refresh_material_seneor();break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:{
                        if ( material_seneor == '4' )  // filament runout
                        {
                            set_filament_runout(true);
                        }
                        else if ( material_seneor == '1' || material_seneor == '3' )
                        {
                            set_filament_runout(false);
                        }

                        // 刷新产测数据
                        if (isFactoryTest()) {
                            refresh_factory_gpio_filament(material_seneor);
                        }
                        break;
                    }
                }
            }
            else if(*data == '8')   //获取是否开启断电续打功能
            {
                if(*(data+1) == '1')
                    powerloss_state = true;
                else
                    powerloss_state = false;
                switch(UIType)
                {
                    // case CR_10_H1:refresh_led_powerloss();break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*data == '9')   //获取开机自检状态
            {
                if(*(data+1) == '1')
                    post_state = true;
                else
                    post_state = false;
            }
            else if(*data == 'a')   //获取声音状态
            {
                if(*(data+1) == '1')
                    sound_state = true;
                else
                    sound_state = false;
                switch(UIType)
                {
                    // case CR_10_H1:refresh_led_sound();break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*data == 'b')   //获取屏幕保护状态
            {
                data++;
                for(i=0;i<len;i++)
                {
                    if(i>(3))
                    {
                        break;
                    }
                    if(*(data+i) == '\0')
                        break;
                    else
                        screen_save_value[i] = *(data+i);
                }
                screen_save_value[i] = '\0';
                switch(UIType)
                {
                    // case CR_10_H1:refresh_led_screensave();break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:refresh_screenoff_setting(atoi(screen_save_value));break;
                }
            }
            else if(*data == 'c')   //获取当前主题模式
            {
                theme_model_id = *(data+1);
                switch(UIType)
                {
                    // case CR_10_H1://refresh_theme();
                    // break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }

            }
            else if(*data == 'd')   //获取当前电机状态
            {
                if(*(data+1) == '0')
                {
                    motor_loss_state = false;

                }
                else if(*(data+1) == '1')
                {
                    motor_loss_state = true;
                }
                switch(UIType)
                {
                    // case CR_10_H1:refresh_axis_motor(2);break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
                
            }
            else if(*data == 'e')   //获取屏幕亮度值
            {
                data++;
                for(i=0;i<len;i++)
                {
                    if(i>(3))
                    {
                        break;
                    }
                    if(*(data+i) == '\0')
                        break;
                    else
                        bright_value[i] = *(data+i);
                }
                bright_value[i] = '\0';
                system_state.light_value = atoi(data);
                CrLogI("light value:%d",system_state.light_value);
                switch(UIType)
                {
                    // case CR_10_H1:refresh_bright();break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:refresh_light_value(system_state.light_value);break;
                }
            }
            else if(*data == 'h')   //获取音量大小
            {
                data++;
                for(i=0;i<len;i++)
                {
                    if(i>(3))
                    {
                        break;
                    }
                    if(*(data+i) == '\0')
                        break;
                    else
                        sound_value[i] = *(data+i);
                }
                sound_value[i] = '\0';
                switch(UIType)
                {
                    // case CR_10_H1:refresh_sound_value();break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*data == 'i')   //获取音效设置
            {
                sound_type = *(data+1);
                switch(UIType)
                {
                    // case CR_10_H1:refresh_sound_type();break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*data == 'j')   //获取全屏设置
            {
                fullscreen_mode_state = *(data+1);
                switch(UIType)
                {
                    // case CR_10_H1:refresh_fullscreen();break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*data == 'l')   //TODO:获取静音模式状态 接口目前预留待后期添加具体页面功能
            {
                data++;
                system_state.FilamentSensor_state = atoi(data);
                CrLogI("FilamentSensor state:%d",system_state.FilamentSensor_state);
                switch(UIType)
                {
                    case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05://change_silentmode_print(system_state.FilamentSensor_state);//预留
                               //change_silentmode_normal(system_state.FilamentSensor_state); //预留
                               break;
                }
            }
            else if(*data == 'm')
            {
                switch(UIType)
                {
                    // case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:refresh_timezoneseting(data+1);break;
                }
            }
            else if(*data == 'n')
            {
                switch(UIType)
                {
                    // case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:refresh_serverinfo_page(atoi(data+1));break;
                }
            }
            else if(*data == 'o')
            {
                if(*(data+1) == '1')
                    CheckUpdataFlag = 1;
                else
                    CheckUpdataFlag = 0;
                CrLogI("refresh the CheckUpdataFlag state:%d",CheckUpdataFlag);
                switch(UIType)
                {
                    // case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:refresh_checkupdateflag_state(atoi(data+1));break;
                }
            }
            else if(*data == 'p')
            {
                init_uiconfiginfo.ServerOption = atoi(data+1);
                CrLogI("the ServerOption value:%d",init_uiconfiginfo.ServerOption);
                switch(UIType)
                {
                    // case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05: ChangeServerOption(init_uiconfiginfo.ServerOption);
                                SelftsetChangeServerOption(init_uiconfiginfo.ServerOption);break;
                }
            }
            else if(*data == 'q') // 项隐私政策状态更新
            {
                init_uiconfiginfo.AgreePrivacyPolicy = atoi(data+1);
                CrLogI("the AgreePrivacyPolicy value:%d",init_uiconfiginfo.AgreePrivacyPolicy);
                switch(UIType)
                {
                    // case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:break;
                }
            }
            else if(*data == 's') // TODO:增加分享图片接口，具体功能页面待后期添加
            {
                system_state.IsAgreeSharePicture = atoi(data+1);
                CrLogI("the IsAgreeSharePicture value:%d",system_state.IsAgreeSharePicture);
                switch(UIType)
                {

                    case CR_K1:
                    case CR_K1_Max: 
                    case PF_05: break;//refreshSharePictrueState(system_state.IsAgreeSharePicture);break;
                }
            }
            break;            
        }

        case CONTROL_NETWORKS:  //0x07：获取当前WIFI状态
        {
            if(*data == '1')
            {
                j = *data++;
                if(len > 5)
                {
                    char tempflag = '\0';
                    tempflag = wifi_state;
                    wifi_state  = *data++;
                    if(*data == '\t')
                        j = *data++;
                    for(i=0;i<WIFI_NAME_LEN;i++)
                    {
                        if(*data == '\t')
                        {
                            j = *data++;
                            break;
                        }
                        else
                        {
                            if(i < WIFI_NAME_LEN)
                                wifi_name[i] = *data;
                        }
                        j = *data++;
                    }
                    wifi_name[i] = '\0';
                    for(i=0;i<16;i++)
                    {
                        if(*data == '\t')
                        {
                            j = *data++;
                            break;
                        }
                        else
                        {
                            if(i < 16)
                                wifi_ip[i] = *data;
                        }
                        j = *data++;
                    }
                    wifi_ip[i] = '\0';
                    for(i=0;i<16;i++)
                    {
                        if(*data == '\t')
                        {
                            j = *data++;
                            break;
                        }
                        else
                        {
                            if(i < 16)
                                wifi_signal_level[i] = *data;
                        }
                        j = *data++;
                    }
                    wifi_signal_level[i] = '\0';
                    wire_net_state  = *data++;
                    if(*data == '\t')
                        j = *data++;
                    for(i=0;i<16;i++)
                    {
                        if(*data == '\t')
                        {
                            j = *data++;
                            break;
                        }
                        else
                        {
                            if(i < 16)
                                wire_net_ip[i] = *data;
                        }
                        j = *data++;
                    }
                    wire_net_ip[i] = '\0';
                    for(i=0;i<16;i++)
                    {
                        if(*data == '\t')
                        {
                            j = *data++;
                            break;
                        }
                        else
                        {
                            if(i < 16)
                                wire_gateway[i] = *data;
                        }
                        j = *data++;
                    }
                    wire_gateway[i] = '\0';

                    for(i=0;i<16;i++)
                    {
                        if(*data == '\t')
                        {
                            j = *data++;
                            break;
                        }
                        else
                        {
                            if(i < 16)
                                wire_subnet_mask[i] = *data;
                        }
                        j = *data++;
                    }
                    wire_subnet_mask[i] = '\0';

                    for(i=0;i<16;i++)
                    {
                        if(*data == '\0')
                        {
                            break;
                        }
                        else
                        {
                            if(i < 16)
                                wire_dns[i] = *data;
                        }
                        j = *data++;
                    }
                    wire_dns[i] = '\0';
                    CrLogI("wifi_state:%c.",wifi_state);
                    CrLogI("wifi_name:%s.",wifi_name);
                    CrLogI("wifi_ip:%s.",wifi_ip);
                    CrLogI("wifi_signal_level:%s.",wifi_signal_level);
                    CrLogI("wire_net_state:%c.",wire_net_state);
                    CrLogI("wire_net_ip:%s.",wire_net_ip);
                    CrLogI("wire_gateway:%s.",wire_gateway);
                    CrLogI("wire_subnet_mask:%s.",wire_subnet_mask);
                    CrLogI("wire_dns:%s.",wire_dns);
                    switch(UIType)
                    {
                //         case CR_10_H1:{
                //             if(tempflag != wifi_state && !connectwifi_state)
                //             {
                //                 get_printer_data(0x07,1,"2");
                //                 //进入等待状态
                //                 wait_timer = lv_timer_create(waittimer_handler, 10000, NULL);
                //                 lv_obj_clear_flag(guider_ui.wait_cont_1,LV_OBJ_FLAG_HIDDEN);
                //                 lv_obj_clear_flag(guider_ui.wait_spinner_1,LV_OBJ_FLAG_HIDDEN);
                //                 lv_obj_add_flag(guider_ui.wait_label_1,LV_OBJ_FLAG_HIDDEN);
                //                 lv_obj_add_flag(guider_ui.wait_label_2,LV_OBJ_FLAG_HIDDEN);
                //                 lv_obj_add_flag(guider_ui.wait_label_3,LV_OBJ_FLAG_HIDDEN);
                //                 lv_obj_add_flag(guider_ui.wait_btn_3,LV_OBJ_FLAG_HIDDEN);
                // //                lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
                //                 CrLogI("wifi state change,wait wifi refresh....");
                //                 refresh_net_info();
                //             }
                //             break;
                //         }
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:{
                            if ( wifi_state == '1' ) //connect
                            {
                                set_wifi_status(atoi(wifi_signal_level));
                            }
                            else
                            {
                                set_wifi_status(MIN_RSSI);
                            }
                            if ( wire_net_state == '1' ) //connect
                            {
                                refresh_networkstate(true);
                                refresh_selftestnetworkstate(true);
                            }
                            else
                            {
                                refresh_networkstate(false);
                                refresh_selftestnetworkstate(false);
                            }
                            refresh_networkinfo_page();
                            refresh_wifilist_page(wifi_ip,NULL);
                            refresh_selftestwifilist_page(wifi_ip,NULL);
                            break;
                        }
                    }
                }
            }
            else if(*data++ == '2')
            {
                switch(UIType)
                {
                    // case CR_10_H1:{
                    //     lv_obj_del(guider_ui.settings_list_1);
                    //     guider_ui.settings_list_1 = lv_list_create(guider_ui.settings_tabview_1_title2);
                    //     lv_obj_set_pos(guider_ui.settings_list_1, 25, 23);
                    //     lv_obj_set_size(guider_ui.settings_list_1, 435, 620);
                    //     lv_obj_set_style_bg_color(guider_ui.settings_list_1, lv_color_make(0x2d, 0x2e, 0x31),LV_PART_MAIN | LV_STATE_DEFAULT);
                    //     lv_obj_set_style_bg_grad_color(guider_ui.settings_list_1, lv_color_make(0x2d, 0x2e, 0x31),LV_PART_MAIN | LV_STATE_DEFAULT);
                    //     lv_obj_set_style_border_width(guider_ui.settings_list_1,0,LV_PART_MAIN | LV_STATE_DEFAULT);
                    //     if(selftestflag)
                    //         lv_obj_clean(guider_ui.selftest_list_1);
                    //     show_wifi_name(data,len-1);
                    //     //取消等待状态
                    //     CrLogI("cancel the wait_timmer");
                    //     lv_obj_add_flag(guider_ui.wait_cont_1,LV_OBJ_FLAG_HIDDEN);
                    //     lv_timer_set_repeat_count(wait_timer,0);
                    //     break;
                    // }
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:
                       
                        // 刷新产测数据
                        if (isFactoryTest()) {
                            ui_factory_show_wifi_list(data,len-1);
                        }
                        else
                        {
                            selftest_show_wifi_list(data, len-1);
                            show_wifi_list(data,len-1);
                            //wait_animmotion(0);
                        }
                        break;
                }
            }
            break;            
        }
        case CONTROL_FILAMENT:
        {
            int flag = 0;
            int process = 0;
            if(*data == '1')
            {
                flag = 1;
                process = atoi(data+1);
            }
            else if(*data == '2')
            {
                flag = 2;
                process = atoi(data+1);
            }
            switch(UIType)
            {
                // case CR_10_H1:{
                //     break;
                // }
                case CR_K1:
                case CR_K1_Max:
                case PF_05:axis_move_refresh_filament_process(flag, process);//refresh_filament_process(flag, process);
                    break;
            }
            break;
        }

        case CONTROL_LEVEL:  //获取自动调平参数
        {
            if(*data == '4')
            {
                level_point_value = *(data+1);
                switch(UIType)
                {
                    // case CR_10_H1:refresh_auto_level_point();break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*data == '5')
            {
//                level_auto_model_value = *(data+1);
//                refresh_auto_level_model();
            }
            else if(*data == '6')
            {
//                level_high_speed_level = *(data+1);
//                refresh_auto_level_hspeed();
            }
            else if(*data == '7')   //按照设置动态分配位置并写入点位值
            {
                refresh_factoryleveldata(len, data, level_point_value);
            }
            else if(*data == '8')
            {
                switch(UIType)
                {
                    // case CR_10_H1:refresh_autolevel_singlepoint(level_point_value,len,data);break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            break;            
        }

//        case 0x0a:  //0x0a：获取运动参数，包括：传动比参数、最大加速度参数、最大拐角参数、最大速度参数
//            if(*data == '1')
//            {
//                j = 0;
//                for(i=0;i<len;i++)
//                {
//                    if(i>(STEPS_LEN-1))
//                    {
//                        break;
//                    }
//                    if(*(data+i+1) == '\t')
//                        break;
//                    else
//                        xSTEPS[i] = *(data+i+1);
//                }
//                xSTEPS[i] = '\0';
//                i++;
//                j = i;
//                for(;i<len;i++)
//                {
//                    if((i-j)>(STEPS_LEN-1))
//                    {
//                        break;
//                    }
//                    if(*(data+i+1) == '\t')
//                        break;
//                    else
//                        ySTEPS[i-j] = *(data+i+1);
//                }
//                ySTEPS[i-j] = '\0';
//                i++;
//                j = i;
//                for(;i<len;i++)
//                {
//                    if((i-j)>(STEPS_LEN-1))
//                    {
//                        break;
//                    }
//                    if(*(data+i+1) == '\t')
//                        break;
//                    else
//                        zSTEPS[i-j] = *(data+i+1);
//                }
//                zSTEPS[i-j] = '\0';
//                i++;
//                j = i;
//                for(;i<len;i++)
//                {
//                    if((i-j)>(STEPS_LEN-1))
//                    {
//                        break;
//                    }
//                    if(*(data+i+1) == '\0')
//                        break;
//                    else
//                        eSTEPS[i-j] = *(data+i+1);
//                }
//                eSTEPS[i-j] = '\0';
//                refresh_steps_setting(0x0f);
//            }
//            else if(*data == '2')
//            {
//                j = 0;
//                for(i=0;i<len;i++)
//                {
//                    if(i>(MACC_LEN-1))
//                    {
//                        break;
//                    }
//                    if(*(data+i+1) == '\t')
//                        break;
//                    else
//                        xmacc[i] = *(data+i+1);
//                }
//                xmacc[i] = '\0';
//                i++;
//                j = i;
//                for(;i<len;i++)
//                {
//                    if((i-j)>(MACC_LEN-1))
//                    {
//                        break;
//                    }
//                    if(*(data+i+1) == '\t')
//                        break;
//                    else
//                        ymacc[i-j] = *(data+i+1);
//                }
//                ymacc[i-j] = '\0';
//                i++;
//                j = i;
//                for(;i<len;i++)
//                {
//                    if((i-j)>(MACC_LEN-1))
//                    {
//                        break;
//                    }
//                    if(*(data+i+1) == '\t')
//                        break;
//                    else
//                        zmacc[i-j] = *(data+i+1);
//                }
//                zmacc[i-j] = '\0';
//                i++;
//                j = i;
//                for(;i<len;i++)
//                {
//                    if((i-j)>(MACC_LEN-1))
//                    {
//                        break;
//                    }
//                    if(*(data+i+1) == '\0')
//                        break;
//                    else
//                        emacc[i-j] = *(data+i+1);
//                }
//                emacc[i-j] = '\0';
//                refresh_acc_setting(0x0f);
//            }
//            else if(*data == '3')
//            {
//                j = 0;
//                for(i=0;i<len;i++)
//                {
//                    if(i>(MJERK_LEN-1))
//                    {
//                        break;
//                    }
//                    if(*(data+i+1) == '\t')
//                        break;
//                    else
//                        xjerk[i] = *(data+i+1);
//                }
//                xjerk[i] = '\0';
//                i++;
//                j = i;
//                for(;i<len;i++)
//                {
//                    if((i-j)>(MJERK_LEN-1))
//                    {
//                        break;
//                    }
//                    if(*(data+i+1) == '\t')
//                        break;
//                    else
//                        yjerk[i-j] = *(data+i+1);
//                }
//                yjerk[i-j] = '\0';
//                i++;
//                j = i;
//                for(;i<len;i++)
//                {
//                    if((i-j)>(MJERK_LEN-1))
//                    {
//                        break;
//                    }
//                    if(*(data+i+1) == '\t')
//                        break;
//                    else
//                        zjerk[i-j] = *(data+i+1);
//                }
//                zjerk[i-j] = '\0';
//                i++;
//                j = i;
//                for(;i<len;i++)
//                {
//                    if((i-j)>(MJERK_LEN-1))
//                    {
//                        break;
//                    }
//                    if(*(data+i+1) == '\0')
//                        break;
//                    else
//                        ejerk[i-j] = *(data+i+1);
//                }
//                ejerk[i-j] = '\0';
//                refresh_jerk_setting(0x0f);
//            }
//            else if(*data == '4')
//            {
//                j = 0;
//                for(i=0;i<len;i++)
//                {
//                    if(i>(MSPEED_LEN-1))
//                    {
//                        break;
//                    }
//                    if(*(data+i+1) == '\t')
//                        break;
//                    else
//                        xmspeed[i] = *(data+i+1);
//                }
//                xmspeed[i] = '\0';
//                i++;
//                j = i;
//                for(;i<len;i++)
//                {
//                    if((i-j)>(MSPEED_LEN-1))
//                    {
//                        break;
//                    }
//                    if(*(data+i+1) == '\t')
//                        break;
//                    else
//                        ymspeed[i-j] = *(data+i+1);
//                }
//                ymspeed[i-j] = '\0';
//                i++;
//                j = i;
//                for(;i<len;i++)
//                {
//                    if((i-j)>(MSPEED_LEN-1))
//                    {
//                        break;
//                    }
//                    if(*(data+i+1) == '\t')
//                        break;
//                    else
//                        zmspeed[i-j] = *(data+i+1);
//                }
//                zmspeed[i-j] = '\0';
//                i++;
//                j = i;
//                for(;i<len;i++)
//                {
//                    if((i-j)>(MSPEED_LEN-1))
//                    {
//                        break;
//                    }
//                    if(*(data+i+1) == '\0')
//                        break;
//                    else
//                        emspeed[i-j] = *(data+i+1);
//                }
//                emspeed[i-j] = '\0';
//                refresh_speed_setting(0x0f);
//            }
//            break;
//        case 0x0b:  //0x0b：获取XYZ轴偏移数据
//            for(i=0;i<len;i++)
//            {
//                if(i>(OFFSET_LEN-1))
//                {
//                    break;
//                }
//                if(*(data+i) == '\t')
//                {
//                    break;
//                }
//                else
//                    origin_xoffset_value[i] = *(data+i);
//            }
//            origin_xoffset_value[i] = '\0';
//            i++;
//            j = i;
//            for(;i<len;i++)
//            {
//                if((i-j)>(OFFSET_LEN-1))
//                {
//                    break;
//                }
//                if(*(data+i) == '\t')
//                    break;
//                else
//                    origin_yoffset_value[i-j] = *(data+i);
//            }
//            origin_yoffset_value[i-j] = '\0';
//             i++;
//            j = i;
//            for(;i<len;i++)
//            {
//                if((i-j)>(OFFSET_LEN-1))
//                {
//                    break;
//                }
//                if(*(data+i) == '\0')
//                    break;
//                else
//                    origin_zoffset_value[i-j] = *(data+i);
//            }
//            origin_zoffset_value[i-j] = '\0';
//            refresh_origin_offset_value(0x07);
//            break;
        case CONTROL_AUTOPIDSETTINGS:  //0x0d：获取喷头和热床自动PID参数
        {
            if(*data == '0')
            {
                j = 0;
                for(i=0;i<len;i++)
                {
                    if(i>(HOTEND_TEMP_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        pid_hotend_tar[i] = *(data+i+1);
                }
                pid_hotend_tar[i] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(REPEAT_TIMES_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\0')
                        break;
                    else
                        pid_hotend_times[i-j] = *(data+i+1);
                }
                pid_hotend_times[i-j] = '\0';
                switch(UIType)
                {
                    // case CR_10_H1:refresh_pid_hotend_setting(3);break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*data == '1')
            {
                j = 0;
                for(i=0;i<len;i++)
                {
                    if(i>(BED_TEMP_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\t')
                        break;
                    else
                        pid_bed_tar[i] = *(data+i+1);
                }
                pid_bed_tar[i] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(REPEAT_TIMES_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i+1) == '\0')
                        break;
                    else
                        pid_bed_times[i-j] = *(data+i+1);
                }
                pid_bed_times[i-j] = '\0';
                switch(UIType)
                {
                    // case CR_10_H1:refresh_pid_bed_setting(3);break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            break;            
        }

        case CONTROL_PID_PARAMETERS:  //0x0e：获取温度PID参数，包括喷头和热床的PID参数
        {
            j = 0;
            for(i=0;i<len;i++)
            {
                if(i>(PID_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    hotend_pid_p[i] = *(data+i);
            }
            hotend_pid_p[i] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if((i-j)>(PID_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    hotend_pid_i[i-j] = *(data+i);
            }
            hotend_pid_i[i-j] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if((i-j)>(PID_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    hotend_pid_d[i-j] = *(data+i);
            }
            hotend_pid_d[i-j] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if((i-j)>(PID_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    bed_pid_p[i-j] = *(data+i);
            }
            bed_pid_p[i-j] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if((i-j)>(PID_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    bed_pid_i[i-j] = *(data+i);
            }
            bed_pid_i[i-j] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if((i-j)>(PID_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\0')
                    break;
                else
                    bed_pid_d[i-j] = *(data+i);
            }
            bed_pid_d[i-j] = '\0';
            switch(UIType)
            {
                // case CR_10_H1:refresh_temp_pid_setting(0x3f);break;
                case CR_K1:
                case CR_K1_Max:
                case PF_05:break;
            }
            break;            
        }

        case CONTROL_PRINT_STATE:  //0x0f：获取打印时间和打印进度
        {
            if(*data == '0')  // PRINT STATE
            {
                data++;
                if(*data == '0')
                {
                    print_state = 0;
                }
                else if(*data == '1')
                {
                    print_state = 1;
                }
                else if(*data == '2')
                {
                    print_state = 2;
                }
                else if(*data == '3')
                {
                    print_state = 3;
                }
                else if(*data == '4')
                {
                    print_state = 4;
                }
                else if(*data == '5')
                {
                    print_state = 5;
                }
                else if(*data == '6')
                {
                    print_state = 6;
                }
                switch(UIType)
                {
                    // case CR_10_H1:refresh_print_state();break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:{
                        unsigned char state = print_state;
                        
                        set_printing_status(state);
                        break;
                    }
                }
                break;
            }
            else if(*data == '1')  // print proccess
            {
                data++;
                j = 0;
                for(i=0;i<len;i++)
                {
                    if(i>(PRINT_TIME_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i) == '\t')
                        break;
                    else
                        print_printed_time[i] = *(data+i);
                }
                print_printed_time[i] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>(PRINT_TIME_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i) == '\t')
                        break;
                    else
                        print_remain_time[i-j] = *(data+i);
                }
                print_remain_time[i-j] = '\0';
                i++;
                j = i;
                for(;i<len;i++)
                {
                    if((i-j)>PERCENT_LEN)
                    {
                        break;
                    }
                    if(*(data+i) == '\t')
                        break;
                    else
                        print_percent[i-j] = *(data+i);
                }
                print_percent[i-j] = '\0';
                uint32_t layer_count = 0, cur_layer = 0;
                if ( (i + 1) < len )
                {
                    char *temp = strchr(data + i + 1, '\t');

                    if ( temp )
                    {
                        *temp = '\0';
                        cur_layer = atoi(temp + 1);
                        layer_count = atoi(data + i + 1);
                    }
                    else
                        layer_count = atoi(data + i + 1);
                    
                }
                print_job.currentlayer = cur_layer;
                print_job.layercount = layer_count;
                CrLogI("%s,%s,%s,%d,%d",print_printed_time, print_remain_time, print_percent,layer_count,cur_layer);
                switch(UIType)
                {
                    // case CR_10_H1:refresh_printing_time_percent();break;
                    case CR_K1: 
                    case CR_K1_Max:
                    case PF_05:{
                        set_print_proccess_layers_info(layer_count, cur_layer);  //因为设置进度注水要用到总层数控制互斥
                        set_print_proccess_info(atoi(print_printed_time), atoi(print_remain_time), atoi(print_percent));
                        break;
                    }
                }
            }
            break;            
        }

        case CONTROL_PRINT_SPEED:  //0x10：获取打印速度
        {
            for(i=0;i<len;i++)
            {
                if(i>(CUR_SPEED_LEN-1))
                {
                    break;
                }
                cur_speed[i] = *(data+i);
                if(*(data+i) == '\0')
                {
                    break;
                }
            }
            cur_speed[i] = '\0';
            switch(UIType)
            {
                // case CR_10_H1:refresh_printing_speed();break;
                case CR_K1:
                case CR_K1_Max:
                case PF_05:set_speed_percent(atoi(cur_speed)); break;
            }
            break;
        }
       case CONTROL_LANGUAGE:  //0x11：获取当前语言
           if(len)
           {
                cur_language = atoi(data);
               //refresh_language();

                switch(UIType)
                {
                    // case CR_10_H1:
                    //     {
                    //         refresh_language();
                    //         break;
                    //     }
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:set_cur_language(cur_language); break;
                }
           }
           break;
//        case CONTROL_BED_SIZE:  //0x12：获取热床尺寸值
//            j = 0;
//            for(i=0;i<len;i++)
//            {
//                if(i>(BED_SIZE_LEN-1))
//                {
//                    break;
//                }
//                if(*(data+i) == '\t')
//                    break;
//                else
//                    bed_size_x[i] = *(data+i);
//            }
//            bed_size_x[i] = '\0';
//            i++;
//            j = i;
//            for(;i<len;i++)
//            {
//                if((i-j)>BED_SIZE_LEN)
//                {
//                    break;
//                }
//                if(*(data+i) == '\0')
//                    break;
//                else
//                    bed_size_y[i-j] = *(data+i);
//            }
//            bed_size_y[i-j] = '\0';
////            refresh_bed_size(3);
//            break;
//        case CONTROL_REPEAT_PRINT_COUNT:  //0x13：获取重复打印次数
//            for(i=0;i<len;i++)
//            {
//                if(i>(REPEAT_TIMES_LEN-1))
//                {
//                    break;
//                }
//                repeat_times[i] = *(data+i);
//                if(*(data+i) == '\0')
//                {
//                    break;
//                }
//            }
//            repeat_times[i] = '\0';
//            refresh_repeattimes();
//            break;
        case CONTROL_MACHINE_PARAMETERS:  //0x14：获取关于本机页面的所有参数
        {
            j = 0;
            for(i=0;i<len;i++)
            {
                if(*(data+i) == '\t')
                    break;
                else
                    machine_type_value[i] = *(data+i);
            }
            machine_type_value[i] = '\0';
            CrLogI("machine_type_value is %s",machine_type_value);
            i++;
            j = i;
            for(;i<len;i++)
            {
                if(*(data+i) == '\t')
                    break;
                else
                    hardware_ver_value[i-j] = *(data+i);
            }
            hardware_ver_value[i-j] = '\0';
            CrLogI("hardware_ver_value is %s",hardware_ver_value);
            i++;
            j = i;
            for(;i<len;i++)
            {
                if(*(data+i) == '\t')
                    break;
                else
                    fireware_ver_value[i-j] = *(data+i);
            }
            fireware_ver_value[i-j] = '\0';
            CrLogI("fireware_ver_value is %s",fireware_ver_value);
            i++;
            j = i;
            for(;i<len;i++)
            {
                if(*(data+i) == '\t')
                    break;
                else
                    screen_ver_value[i-j] = *(data+i);
            }
            screen_ver_value[i-j] = '\0';
            CrLogI("screen_ver_value is %s",screen_ver_value);
            i++;
            j = i;
            for(;i<len;i++)
            {
                if(*(data+i) == '\t')
                    break;
                else
                    total_time_value[i-j] = *(data+i);
            }
            total_time_value[i-j] = '\0';
            CrLogI("total_time_value is %s",total_time_value);
            i++;
            j = i;
            for(;i<len;i++)
            {
                if(*(data+i) == '\t')
                    break;
                else
                    mac_value[i-j] = *(data+i);
            }
            mac_value[i-j] = '\0';
            CrLogI("mac_value is %s",mac_value);
            i++;
            j = i;
            for(;i<len;i++)
            {
                if(*(data+i) == '\t')
                    break;
                else
                    official_web_value[i-j] = *(data+i);
            }
            official_web_value[i-j] = '\0';
            CrLogI("official_web_value is %s",official_web_value);
            i++;
            j = i;
            for(;i<len;i++)
            {
                if(*(data+i) == '\t')
                    break;
                else
                    machineinfo.TotalDiskCapacity[i-j] = *(data+i);
            }
            machineinfo.TotalDiskCapacity[i-j] = '\0';
            CrLogI("TotalDiskCapacity is %s",machineinfo.TotalDiskCapacity);
            i++;
            j = i;
            for(;i<len;i++)
            {
                if(*(data+i) == '\t')
                    break;
                else
                    machineinfo.UsedDiskCapacity[i-j] = *(data+i);
            }
            machineinfo.UsedDiskCapacity[i-j] = '\0';
            CrLogI("UsedDiskCapacity is %s",machineinfo.UsedDiskCapacity);

            i++;
            j = i;
            for(;i<len;i++)
            {
                if(*(data+i) == '\0')
                    break;
                else
                    machineinfo.MachineName[i-j] = *(data+i);
            }

            strcpy(machineinfo.MachineType, machine_type_value);
            strcpy(machineinfo.HardwareVersion, hardware_ver_value);
            strcpy(machineinfo.FirmwareVersion, fireware_ver_value);
            strcpy(machineinfo.ScreenVersion, screen_ver_value);
            strcpy(machineinfo.PrintedTime, total_time_value);
            strcpy(machineinfo.MacValue, mac_value);
            strcpy(machineinfo.CrealityUrl, official_web_value);
            CrLogI("MachineType is %s",machineinfo.MachineType);
            CrLogI("HardwareVersion is %s",machineinfo.HardwareVersion);
            CrLogI("FirmwareVersion is %s",machineinfo.FirmwareVersion);
            CrLogI("ScreenVersion is %s",machineinfo.ScreenVersion);
            CrLogI("PrintedTime is %s",machineinfo.PrintedTime);
            CrLogI("MacValue is %s",machineinfo.MacValue);
            CrLogI("CrealityUrl is %s",machineinfo.CrealityUrl);
            CrLogI("MachineName is %s",machineinfo.MachineName);

            switch(UIType)
            {
                // case CR_10_H1:refresh_about();break;
                case CR_K1:
                case CR_K1_Max:
                case PF_05:refresh_aboutdevice_page(machineinfo);set_versioninfo_settingpage(screen_ver_value);break;
            }
            break;            
        }

        case CONTROL_IOT_QRCODE:  //获取创想云二维码
        {
            if(len > 2)  //新的二维码命令改变了
            {
                if ( *data == '1' )  // 创想云二维码
                {
                    data++;
                    i = 0;
                    while(*data)
                    {
                        if(*data == '\0')
                        {
                            break;
                        }
                        qrcode_name[i++] = *data;
                        data++;
                    }
                    qrcode_name[i] = '\0';
                    switch(UIType)
                    {
                        // case CR_10_H1:{
                        //     if(qrcode_name[0] != '\0')
                        //     {
                        //         if (lv_obj_is_valid(guider_ui.device_binding_cont_1))
                        //         {
                        //             if (!lv_obj_has_flag(guider_ui.device_binding_cont_1,LV_OBJ_FLAG_HIDDEN))
                        //             {
                        //                 if(guider_ui.device_binding_img_2 != NULL)
                        //                 {
                        //                     CrLogI("device_binding_img_2 src is %s.",qrcode_name);
                        //                     lv_img_set_src(guider_ui.device_binding_img_2, qrcode_name);
                        //                 }
                        //             }
                        //         }
                        //     }
                        //     break;
                        // }
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05: //TODO:二维码图片刷新暂时改为静态方式，此处不需要刷新显示
                            // refresh_devicebingding_page(qrcode_name);
                            // refresh_CustomerFaq_page(qrcode_name);
                            // refresh_CustomerWiki_page(qrcode_name);
                            // refresh_selftestbinding_page(qrcode_name);
                            break;
                    }
                }
                else if ( *data == '2' )  //客服意见反馈二维码
                {
                    data++;
                    int j = 0;
                    char faq_qrcode[256] = {0};
                    while(*data)
                    {
                        if(*data == '\0')
                        {
                            break;
                        }
                        if ( j < (sizeof(faq_qrcode) - 1) )
                            faq_qrcode[j++] = *data;
                        data++;
                    }
                    faq_qrcode[j] = '\0';
                    switch(UIType)
                    {
                        // case CR_10_H1:break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:set_faq_qrcode(faq_qrcode);break;
                    }
                }
                
            }
            break;            
        }

        case CONTROL_PRINT_FLOW:
        {
            for(i=0;i<len;i++)
            {
                if(i>(CUR_SPEED_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\0')
                {
                    break;
                }
                cur_printflow[i] = *(data+i);
            }
            cur_printflow[i] = '\0';
            switch(UIType)
            {
                // case CR_10_H1:refresh_printing_flow();break;
                case CR_K1:
                case CR_K1_Max:
                case PF_05:set_flow_percent(atoi(cur_printflow)); break;
            }
            
            break;
        }
        case CONTROL_AXIS_STATE:
        {
            if(*data == '0')
                x_state = false;
            else
                x_state = true;
            if(*(data+1) == '0')
                y_state = false;
            else
                y_state = true;
            if(*(data+2) == '0')
                z_state = false;
            else
                z_state = true;
            switch(UIType)
            {
                // case CR_10_H1:break;
                case CR_K1:
                case CR_K1_Max:
                case PF_05:{
                    set_home_status(x_state, y_state, z_state);
                    break;
                }
            }
            break;
        }
        case CONTROL_ERROR_MSG:
        {
            j = 0;
            for(i=0;i<len;i++)
            {
                if(i>(PRINT_TIME_LEN-1))
                {
                    break;
                }
                if(*(data+i) == '\t')
                    break;
                else
                    errorcode[i] = *(data+i);
            }
            errorcode[i] = '\0';
            i++;
            j = i;
            for(;i<len;i++)
            {
                if(*(data+i) == '\t')
                    break;
                else
                    k1_errorcode[i-j] = *(data+i);
            }
            k1_errorcode[i-j] = '\0';
            CrLogI("errorcode:%s,k1_errorcode:%s,error msg:%s",errorcode, k1_errorcode, (data+i+1));
            switch(UIType)
            {
                // case CR_10_H1:showerrormsg(++data,rebootflag);break;
                case CR_K1:
                case CR_K1_Max:
                case PF_05:set_error_msg(atoi(errorcode), atoi(k1_errorcode), (data+i+1));break;
            }
            break;
        }
        case CONTROL_UPDATE_MSG:
        {
            if(*data == '0')    //升级进度及升级状态解析
            {
                data++;
                if(*(data+1) == '\t' )
                {
                    version_flag = *data;
                    data = data + 2;
                }
                for(i = 0;i < len;i++)
                {
                    if(*(data+i) == '\0')
                        break;
                    else
                        upgrade_progress[i] = *(data+i);
                }
                upgrade_progress[i] = '\0';
                switch(UIType)
                {
                    // case CR_10_H1:refresh_upgrade_progress();break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:RefreshUpdateVersionProgress(version_flag,upgrade_progress);break;
                }
            }
            else //版本信息查询
            {
                int type = *data - '0';
                data++;
                int i,j;
                char current_version[64] = {0};
                char new_version[64] = {0};
                char version_size[64] = {0};
                char updata_content[1024] = {0};
                bool hasnewversion = false;
                if(len > 4)
                {
                    hasnewversion = true;
                    char *temp = strtok(data,"\t");
                    int data_flag = 0;
                    while(temp)
                    {
                        switch(data_flag)
                        {
                            case 0:strcpy(current_version, temp);   CrLogI("%d:%s", data_flag, current_version);break;
                            case 1:strcpy(new_version, temp);       CrLogI("%d:%s", data_flag, new_version);break;
                            case 2:strcpy(version_size, temp);      CrLogI("%d:%s", data_flag, version_size);break;
                            case 3:strcpy(updata_content, temp);    CrLogI("%d:%s", data_flag, updata_content);break;
                            default:CrLogW("analyze data flag is not exist");break;
                        }
                        data_flag++;
                        temp = strtok(NULL,"\t");
                    }
                }
                
                switch(UIType)
                {
                    // case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:
                    {
                        if( type == 1 && systemsettingflag )//是OTA设置页面升级查询
                        {
                            refresh_versioninfo(hasnewversion);
                        }
                        else if( type == 1 && DotCheckVersion == 1 )//是打印完成或开机后升级查询OTA不显示
                        {
                            DotCheckVersion = 0;
                            if(hasnewversion)
                                refresh_updatepage(type, current_version, new_version, version_size, updata_content, hasnewversion);
                        }
                        else if(type == 2)    //如果是U盘升级查询
                        {
                            if(hasnewversion)
                                refresh_updatepage(type, current_version, new_version, version_size, updata_content, hasnewversion);
                        }
                        else if(type == 1)    //如果是OTA升级查询
                        {
                            refresh_updatepage(type, current_version, new_version, version_size, updata_content, hasnewversion);
                        }

                        break;
                    }
                }
                break;
            }
            break;
        }
        case CONTROL_MACHINE_STATE:  //启用全屏或者息屏
        {
            if(*data == '1') //启动全屏
            {
                switch(UIType)
                {
                    // case CR_10_H1:lv_obj_clear_flag(guider_ui.fullscreen_mode_cont_1,LV_OBJ_FLAG_HIDDEN);break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;//set_full_screen_display_status(true); 
                }
            }
            else if(*data == '2') //启动熄屏
            {
                switch(UIType)
                {
                    // case CR_10_H1:lv_obj_clear_flag(guider_ui.sleep_mode_cont_1,LV_OBJ_FLAG_HIDDEN);break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:set_screen_off_status(true); break;
                }
            }
            else if(*data == '4') //U盘状态
            {
                data++;
                bool temp_state;
                bool change_flag = false;
                if(*data == '1'){   //U盘存在或者挂载成功
                    CrLogI("udisk exist.");
                    temp_state = true;
                }
                if(*data == '0'){   //U盘不存在或者弹出
                    CrLogI("udisk pop up.");
                    temp_state = false;
                }
                if(temp_state != system_state.Udisk_state){
                    change_flag = true;
                    system_state.Udisk_state = temp_state; 
                    set_u_disk_status(system_state.Udisk_state);
                    if(system_state.Udisk_state)
                        EnterUpdatepage(2);

                    // 刷新产测数据
                    if (isFactoryTest()) {
                        refresh_factory_usb_status();
                    }
                }
                switch(UIType)
                {
                    // case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*data == '5') //摄像头状态
            {
                data++;
                int camera_model_state = 0;
                int camera_nozzle_state = 0;
                camera_model_state = *data - '0';
                camera_nozzle_state = *(data + 2) - '0';
                CrLogI("take camera state:model camer%d,nozzle camera%d.",camera_model_state, camera_nozzle_state);
     
                system_state.Camera_model_state = camera_model_state;
                system_state.Camera_nozzle_state = camera_nozzle_state;
                switch(UIType)
                {
                    // case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05: //hoem_page_refresh_camerastate(system_state.Camera_model_state);
                                set_camera_model_status(system_state.Camera_model_state);
                                JudgeCameraIsNormal(system_state.Camera_model_state);
                    break;
                }
            }
            else if(*data == '6') //创想云绑定状态
            {
                bool result = false;
                system_state.CxyUserInfoState = 0;
                if(*(data + 1) != '\0')//有用户信息
                {
                    sscanf(data+1, "%s\t%s\t%s", cxyUserinfo.UserName, cxyUserinfo.UserID, cxyUserinfo.UserImg);
                    CrLogI("cxyusername:%s, userid:%s, imgsrc:%s",cxyUserinfo.UserName, cxyUserinfo.UserID, cxyUserinfo.UserImg);
                    result = true;
                    system_state.CxyUserInfoState = 1;
                }
                switch(UIType)
                {
                    // case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05: refresh_UserBoundDeviceInfo(result, cxyUserinfo);//refresh_DeviceUserInfo(result, cxyUserinfo);
                                selftest_check_cxyuserinfo(result);
                                refresh_SelftestDeviceUserInfo(cxyUserinfo);
                                break;
                    default:break;
                }
            }
            else if(*data == '7') //Klipper状态
            {
                data++;
                bool temp_state;
                bool change_flag = false;
                if(*data == '1'){   //连接
                    CrLogI("klipper connect success.");
                    system_state.Klipper_state = 1;
                }
                if(*data == '0'){   //断开
                    CrLogI("klipper connect disconnect.");
                    system_state.Klipper_state = 0;
                }
                switch(UIType)
                {
                    // case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05: //暂时未定义断开后的重连流程，目前只在开机检查状态
                    {
                        // if(CheckKlipperState == 1 && system_state.Klipper_state == 1)
                        // {
                        //     CrLogI("klipper connect state normal");
                        //     create_msgbox(Error801Content[get_cur_language_index()], NULL,  1000 * 1, lv_layer_top());
                        //     CheckKlipperState = 0;
                        // }
                        break;
                    }
                }
            }
            else if(*data == '8') //主板风扇和喉管风扇状态
            {
                data++;
                char temp1[20] = {0};   //喉管风扇
                char temp2[20] = {0};   //主板风扇
                sscanf(data, "%s\t%s", temp1, temp2);
                system_state.throat_fan_speed = atoi(temp1);
                system_state.board_fan_speed  = atoi(temp2);
                CrLogI("throat fan speed:%d,board fan speed:%d", system_state.throat_fan_speed, system_state.board_fan_speed);
                switch(UIType)
                {
                    // case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:
                    {
                        if(system_state.throat_fan_speed > 0)
                            check_singleprocess_completed(3, true);
                        if(system_state.board_fan_speed > 0)
                            check_singleprocess_completed(4, true);                    
                        break;
                    }
                }
            }
            else if(*data == '9') //风扇反馈开启状态
            {
                data++;
                if(*data == '1')system_state.Fanfeedback = 1;
                if(*data == '0')system_state.Fanfeedback = 0;
                CrLogI("system_state Fanfeedback:%d", system_state.Fanfeedback);
                switch(UIType)
                {
                    // case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:
                    {                 
                        break;
                    }
                }
            }
            else if(*data == 'a') //轮廓仪状态
            {
                data++;
                if(*data == '1')system_state.Laser_state = 1;
                if(*data == '0')system_state.Laser_state = 0;
                CrLogI("system_state Laser_state:%d", system_state.Laser_state);
                switch(UIType)
                {
                    // case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:
                    {      
                        set_laser_state(system_state.Laser_state);           
                        break;
                    }
                }
            }
            else if(*data == 'b') //IOT状态
            {
                data++;
                if(*data == '1')system_state.Mqtt_state = 1;
                if(*data == '0')system_state.Mqtt_state = 0;
                CrLogI("system_state Mqtt_state:%d", system_state.Mqtt_state);
                switch(UIType)
                {
                    // case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    {                 
                        break;
                    }
                }
            }
            else if(*data == 'c') //对象排除 //TODO:对象排除待后期添加
            {
                data++;
                switch(UIType)
                {
                    case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;//refreshExcludeObjectPage(data);break;
                }
            } 
            break;
        }
        case CONTROL_MACHINE_LOG:
        {
            break;
        }
        case CONTROL_CAMERA_OPTIONS:
        {
            if(*data == '1') //延时摄影状态
            {
                data++;
                isopencamera = *(data++) - '0';
                switch(UIType)
                {
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:set_camera_delayed_photography(isopencamera); break;
                }
            }
            else if(*data == '2') //延时摄影喷嘴位置
            {
                data++;
                uint8_t pos = *data;
                cameraposition = *(data++) - '0';
                switch(UIType)
                {
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:set_camera_shoot_pos(pos); break;
                }
            }
            else if(*data == '3') //拍照层数
            {
                data++;
                for(i=0;i<len;i++)
                {
                    if(i>(CAMERA_SIZE_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i) == '\0')
                    {
                        break;
                    }
                    picturelayers[i] = *(data+i);
                }
                picturelayers[i] = '\0';
                switch(UIType)
                {
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:set_camera_shoot_freq(atoi(picturelayers)); break;
                }
            }
            else if(*data == '4') //渲染方式
            {
                data++;
                for(i=0;i<len;i++)
                {
                    if(i>(CAMERA_SIZE_LEN-1))
                    {
                        break;
                    }
                    if(*(data+i) == '\0')
                    {
                        break;
                    }
                    Render_mode[i] = *(data+i);
                }
                Render_mode[i] = '\0';
                switch(UIType)
                {
                    case CR_K1: 
                    case CR_K1_Max:
                    case PF_05:set_camera_rendering_method(atoi(Render_mode)); break;
                }
            }
            switch(UIType)
            {
                // case CR_10_H1:refresh_camerasetting();break;
                case CR_K1:
                case CR_K1_Max:
                case PF_05:break;
            }
            break;
        }
        case CONTROL_AI_OPTIONS:
        {
            if(*data == '1') //AI参数设置
            {
                data++;
                char *AISwitchState = strtok(data, "\t");
                if (!AISwitchState) {
                    CrLogW("no find AISwitch \n");
                    return -1;
                }
                char *IsFaultState = strtok(NULL, "\t");
                if (!IsFaultState) {
                    CrLogW("no find IsFaultState \n");
                    break;
                }
                char *FaultEndstopState = strtok(NULL, "\t");
                if (!FaultEndstopState) {
                    CrLogW("no find FaultEndstopState id\n");
                    break;
                }
                char *FirstLayerDetState = strtok(NULL, "\t");
                if (!FirstLayerDetState) {
                    CrLogW("no find FirstLayerDetState id\n");
                    break;
                }
                char *FlowCalibrationState = strtok(NULL, "\t");
                if (!FlowCalibrationState) {
                    CrLogW("no find FlowCalibrationState id\n");
                    break;
                }
                char *AiModeState = strtok(NULL, "\t");
                if (!FlowCalibrationState) {
                    CrLogW("no find FlowCalibrationState id\n");
                    break;
                }
                char *AiCheckTime = strtok(NULL, "\t");
                if (!AiCheckTime) {
                    CrLogW("no find AiModeState id\n");
                    break;
                }
                ai_state.AI_state = atoi(AISwitchState);
                ai_state.FaultDetection_state = atoi(IsFaultState);
                ai_state.FaultToPause_state = atoi(FaultEndstopState);
                ai_state.FirstLayerDetection_state = atoi(FirstLayerDetState);
                ai_state.FlowCalibrationState = atoi(FlowCalibrationState);
                ai_state.AiMode = atoi(AiModeState);
                ai_state.AiCheckTime = atoi(AiCheckTime);
                CrLogI("AI_state:%d, %d, %d, %d, %d, %d, %d",ai_state.AI_state, ai_state.FaultDetection_state, ai_state.FaultToPause_state, 
                ai_state.FirstLayerDetection_state, ai_state.FlowCalibrationState, ai_state.AiMode, ai_state.AiCheckTime);
                switch(UIType)
                {
                    // case CR_10_H1:
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:set_ai_detection_state(ai_state); break;
                }
            }
            break;
        }
        case CONTROL_XYZ_AXIS_RANGE:
        {
            if(*data == '1') //xyz轴最大移动范围
            {
                data++;
                char *xmin = strtok(data, "\t");
                if (!xmin) {
                    CrLogW("no find xmin \n");
                    break;
                }
                char *xmax = strtok(NULL, "\t");
                if (!xmax) {
                    CrLogW("no find xmax \n");
                    break;
                }
                char *ymin = strtok(NULL, "\t");
                if (!ymin) {
                    CrLogW("no find ymin \n");
                    break;
                }
                char *ymax = strtok(NULL, "\t");
                if (!ymax) {
                    CrLogW("no find ymax \n");
                    break;
                }
                char *zmin = strtok(NULL, "\t");
                if (!zmin) {
                    CrLogW("no find zmin\n");
                    break;
                }
                char *zmax = strtok(NULL, "\t");
                if (!zmax) {
                    CrLogW("no find zmax\n");
                    break;
                }
                system_state.X_Axis_Min = atoi(xmin);
                system_state.X_Axis_Max = atoi(xmax);
                system_state.Y_Axis_Min = atoi(ymin); //knob
                system_state.Y_Axis_Max = atoi(ymax);
                system_state.Z_Axis_Min = atoi(zmin); //knob
                system_state.Z_Axis_Max = atoi(zmax);
                CrLogI("xyz axis range:%d, %d, %d, %d, %d, %d",system_state.X_Axis_Min,system_state.X_Axis_Max,
                system_state.Y_Axis_Min,system_state.Y_Axis_Max,system_state.Z_Axis_Min,system_state.Z_Axis_Max);
                switch(UIType)
                {
                    // case CR_10_H1:
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05: break;
                }
            }
        }
        default:
            break;
    }
}
/*
flag是一个十六进制数，最多可以表示256个类型，对于目前来说足够
0x01：设置喷头最高温度
0x02：设置热床最高温度
0x03：设置打印速度倍数
0x04：设置Z轴偏移数据
0x05：开始打印指定的文件
0x06：打印控制，包括：停止打印，暂停打印，继续打印
0x07：移动XYZ轴，包括移动方向和距离
0x08：释放和锁定电机
0x09：进料和退料操作
0x0a：开始预热：包括PLA预热和ABS预热
0x0b：设置风扇状态、照明状态、WIFI状态、一键冷却、一键关机、恢复网络、恢复出厂
0x0c：设置预热参数，包括PLA、ABS的喷头和热床参数
0x0d：设置当前语言
0x0e：设置调平操作参数
0x0f：设置运动参数，包括传动比参数、最大加速度参数、最大拐角速度参数、最大速度参数
0x10：设置温度PID参数
*/
void set_printer_data(unsigned char flag, unsigned int len, char *data)
{
#ifdef IS_SYSTEM_USE
	SetPrinterDataToManager(flag, len, data);
#else
    CrLogI("flag = 0x%x",flag);
    CrLogI(data);
    switch(flag)
    {
        case 0x01:
            set_response_printer_data(0x01,1,"1");
            break;
        case 0x02:
            set_response_printer_data(0x02,len,data);
            break;
        case 0x03:
            set_response_printer_data(0x03,len,data);
            break;
        case 0x04:
            set_response_printer_data(0x04,len,data);
            break;
        case 0x05:
            set_response_printer_data(0x05,len,data);
            break;
        case 0x06:
            set_response_printer_data(0x06,len,data);
            break;
        case 0x07:
            set_response_printer_data(0x07,len,data);
            break;
        case 0x08:
            set_response_printer_data(0x08,len,data);
            break;
        case 0x09:
            set_response_printer_data(0x09,len,data);
            break;
        case 0x0a:
            set_response_printer_data(0x0a,len,data);
            break;
        case 0x0b:
            set_response_printer_data(0x0b,len,data);
            break;
        case 0x0c:
            set_response_printer_data(0x0c,len,data);
            break;
        case 0x0d:
            set_response_printer_data(0x0d,len,data);
            break;
        case 0x0e:
            set_response_printer_data(0x0e,len,data);
            break;
        case 0x0f:
            set_response_printer_data(0x0f,len,data);
            break;
        case 0x10:
            set_response_printer_data(0x10,len,data);
            break;
        case 0x11:
            set_response_printer_data(0x11,len,data);
            break;
        case 0x12:
            set_response_printer_data(0x12,len,data);
            break;
        case 0x13:
            set_response_printer_data(0x13,len,data);
            break;
        case 0x14:
            set_response_printer_data(0x14,len,data);
            break;
        case 0x15:
            set_response_printer_data(0x15,len,data);
            break;
        default:
            break;
    }
#endif
}

//static void ofs_y_anim(void * img, int32_t v)
//{
//    lv_img_set_offset_y(img, v);
//}

void set_response_printer_data(MessageState flag, unsigned int len, char *data)
{
    unsigned int i;

    switch(flag)
    {
        case CONTROL_FILE:{
            // if(len != 1)
            // {
            //     break;
            // }
            if(*data == '1')
            {
                char num[10] = {0};
                char process[10] = {0};
                int result = sscanf(data+1, "%s\t%s", num, process);
                CrLogI("result:%d,num:%s,process:%s",result, num, process);
                switch(UIType)
                {
                    // case CR_10_H1:{
                    //     print_state = 1;
                    //     guider_load_screen(SCR_HOME_PAGE);                        
                    //     break;
                    // }
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:refresh_copyprocess(atoi(process),atoi(num));break;
                }
            }
            if(*data == '2')
            {
                char *option= strtok(data, "\t");
                CrLogI("option :%s",option);
                uint32_t percent = 0;
                char *message = NULL;
                switch(option[0])
                {
                    case '1':break;
                    case '2':message = strtok(NULL, "\t");
                             CrLogI("message :%s",message);
                             break;
                    case '3':break;
                    case '4':break;
                    default:break;
                }
                switch(UIType)
                {
                    // case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:create_tips(atoi(message));
                    break;
                }
            }
            if(*data == '3')
            {
                char num[256] = {0};
                char process[256] = {0};
                int result = sscanf(data+1, "%s\t%s", num, process);
                CrLogI("result:%d,num:%s,process:%s",result, num, process);
                switch(UIType)
                {
                    // case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:refresh_export_video_process(atoi(process));break;
                }
            }
            break;            
        }   
        case CONTROL_Z_AXIS_OFFSET:{
            for(i=0;i<len;i++)
            {
                if(i>(OFFSET_LEN-1))
                {
                    break;
                }
                zoffset_value[i] = *(data+i);
                if(*(data+i) == '\0')
                {
                    break;
                }
            }
            zoffset_value[i] = '\0';
            switch(UIType)
            {
                // case CR_10_H1:refresh_zoffset_value();break;
                case CR_K1:
                case CR_K1_Max:
                case PF_05:break;
            }
            break;            
        }
        case CONTROL_HOT_BED_TEMP:{
            if(*data == '1')
            {
                for(i=0;i<len;i++)
                {
                    if(i>(BED_TEMP_LEN-1))
                    {
                        break;
                    }
                    bed_max_temp[i] = *(data+i+1);
                    if(*(data+i+1) == '\0')
                    {
                        break;
                    }
                }
                bed_max_temp[i] = '\0';
                switch(UIType)
                {
                    // case CR_10_H1:refresh_temp(4);break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*data == '2')
            {
                for(i=0;i<len;i++)
                {
                    if(i>(HOTEND_TEMP_LEN-1))
                    {
                        break;
                    }
                    hotend_max_temp[i] = *(data+i+1);
                    if(*(data+i+1) == '\0')
                    {
                        break;
                    }
                }
                hotend_max_temp[i] = '\0';
                switch(UIType)
                {
                    // case CR_10_H1:refresh_temp(1);break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            break;            
        }
        case CONTROL_XYZ_AXIS:{
            //‘A’表示XY轴回HOME,‘B’表示Z回HOME,‘C’表示X轴回HOME, ‘D’表示Y回HOME,‘E’表示XYZ回HOME
            switch(UIType)
            {
                //case CR_10_H1:;break;
                case CR_K1:
                case CR_K1_Max:
                case PF_05:set_homing_status(*(data + 1));
                                if(*data == 'E' && *(data + 1) == '1')judgeEnterCheckFireware(1);
                                if(*data == 'Z' && *(data + 1) == '1')judgeEnterCheckFireware(2);
                                break;
            }
            break;
        }
        case CONTROL_PREPARATEMP:{
            if(*data == '1')    //PLA
            {
                if(*(data+1) == '1')        //hotend
                {
                    for(i=0;i<(len-2);i++)
                    {
                        if(i>(HOTEND_TEMP_LEN-1))
                        {
                            break;
                        }
                        PLA_preheat_hotend[i] = *(data+i+2);
                        if(*(data+i+2) == '\0')
                        {
                            break;
                        }
                    }
                    PLA_preheat_hotend[i] = '\0';
                    switch(UIType)
                    {
                        // case CR_10_H1:refresh_pla_setting(1);break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                }
                else if(*(data+1) == '2')   //bed
                {
                    for(i=0;i<(len-2);i++)
                    {
                        if(i>(BED_TEMP_LEN-1))
                        {
                            break;
                        }
                        PLA_preheat_bed[i] = *(data+i+2);
                        if(*(data+i+2) == '\0')
                        {
                            break;
                        }
                    }
                    PLA_preheat_bed[i] = '\0';
                    switch(UIType)
                    {
                        // case CR_10_H1:refresh_pla_setting(2);break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                }
            }
            else if(*data == '2')   //abs
            {
                if(*(data+1) == '1')        //hotend
                {
                    for(i=0;i<(len-2);i++)
                    {
                        if(i>(HOTEND_TEMP_LEN-1))
                        {
                            break;
                        }
                        ABS_preheat_hotend[i] = *(data+i+2);
                        if(*(data+i+2) == '\0')
                        {
                            break;
                        }
                    }
                    ABS_preheat_hotend[i] = '\0';
                    switch(UIType)
                    {
                        // case CR_10_H1:refresh_petg_setting(1);break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                }
                else if(*(data+1) == '2')   //bed
                {
                    for(i=0;i<(len-2);i++)
                    {
                        if(i>(BED_TEMP_LEN-1))
                        {
                            break;
                        }
                        ABS_preheat_bed[i] = *(data+i+2);
                        if(*(data+i+2) == '\0')
                        {
                            break;
                        }
                    }
                    ABS_preheat_bed[i] = '\0';
                    switch(UIType)
                    {
                        // case CR_10_H1:refresh_petg_setting(2);break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                }
            }
            else if(*data == '3')   //self
            {
                if(*(data+1) == '1')        //hotend
                {
                    for(i=0;i<(len-2);i++)
                    {
                        if(i>(HOTEND_TEMP_LEN-1))
                        {
                            break;
                        }
                        self_preheat_hotend[i] = *(data+i+2);
                        if(*(data+i+2) == '\0')
                        {
                            break;
                        }
                    }
                    self_preheat_hotend[i] = '\0';
                    switch(UIType)
                    {
                        // case CR_10_H1:refresh_self_setting(1);break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                }
                else if(*(data+1) == '2')   //bed
                {
                    for(i=0;i<(len-2);i++)
                    {
                        if(i>(BED_TEMP_LEN-1))
                        {
                            break;
                        }
                        self_preheat_bed[i] = *(data+i+2);
                        if(*(data+i+2) == '\0')
                        {
                            break;
                        }
                    }
                    self_preheat_bed[i] = '\0';
                    switch(UIType)
                    {
                        // case CR_10_H1:refresh_self_setting(2);break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                }
            }
            break;            
        }
        case CONTROL_PARAMETERS:{
            switch(*data)
            {
                case '0':   //风扇
                    if(*(data+1) == '1')
                        fan_state = true;
                    else
                        fan_state = false;
                    switch(UIType)
                    {
                        // case CR_10_H1:refresh_fan();break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                    break;
                case '1':   //照明
                    if(*(data+1) == '1')
                        light_state = true;
                    else
                        light_state = false;
                    switch(UIType)
                    {
                        // case CR_10_H1://refresh_light();
                        // break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                    break;
                case '2':   //wifi
                    if(*(data+1) == '1')
                        wifi_state = true;
                    else
                        wifi_state = false;
                    break;
                case '3':   //一键冷却
                    if(*(data+1) == '1')
                    {
                        hotend_max_temp[0] = '0';
                        hotend_max_temp[1] = '\0';
                        bed_max_temp[0] = '0';
                        bed_max_temp[1] = '\0';
                        switch(UIType)
                        {
                            // case CR_10_H1:refresh_temp(5);break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:break;
                        }
                    }
                    break;
                case '4':   //自动关机
                    if(*(data+1) == '1')
                        auto_poweroff = true;
                    else
                        auto_poweroff = false;
                    switch(UIType)
                    {
                        // case CR_10_H1://refresh_auto_poweroff();
                        // break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                    break;
                case '5':   //恢复网络
                    if(*(data+1) == '1')
                    {
                    }
                    break;
                case '6':   //恢复出厂
                    if(*(data+1) == '1')
                    {
                    }
                    break;
                case '7':   //断料检测
                    material_seneor = *(data+1);
                    switch(UIType)
                    {
                        // case CR_10_H1:refresh_material_seneor();break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                    break;
                case '8':   //断电续打
                    if(*(data+1) == '1')
                        powerloss_state = true;
                    else
                        powerloss_state = false;
                    switch(UIType)
                    {
                        // case CR_10_H1://refresh_led_powerloss();
                        // break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                    break;
                case '9':   //开机自检
                    if(*(data+1) == '1')
                        post_state = true;
                    else
                        post_state = false;
                    switch(UIType)
                    {
                        // case CR_10_H1://refresh_led_selt_test();
                        // break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                    break;
                case 'a':   //按键声音
                    if(*(data+1) == '1')
                        sound_state = true;
                    else
                        sound_state = false;
                    switch(UIType)
                    {
                        // case CR_10_H1://refresh_led_sound();
                        // break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                    break;
                case 'b':   //屏幕保护
//                    if(*(data+1) == '1')
//                        screen_save_state = true;
//                    else
//                        screen_save_state = false;
//                    refresh_led_screensave();
                    break;
                case 'c':   //主题色
                    theme_model_id = *(data+1);
//                    refresh_theme();
                    break;
                case 'd':   //电机状态
                    if(*(data+1) == '0')
                    {
                        motor_loss_state = false;

                    }
                    else if(*(data+1) == '1')
                    {
                        motor_loss_state = true;
                    }
//                    refresh_axis_motor(2);
                    break;
                case 'e':   //屏幕亮度
//                    if(len)
//                    {
//                        bright_value= *(data+1);
//                    }
//                    refresh_bright();
                    break;
                default:
                    break;
            }
           break;            
        }
        case CONTROL_NETWORKS:{
            switch(UIType)
            {
        //         case CR_10_H1:{
        //             if(*data == '0')//连接失败：报错弹窗
        //             {
        //                 lv_obj_add_flag(guider_ui.wait_spinner_1, LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_clear_flag(guider_ui.wait_label_1, LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_clear_flag(guider_ui.wait_label_2, LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_clear_flag(guider_ui.wait_label_3, LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_clear_flag(guider_ui.wait_btn_3, LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_add_flag(guider_ui.wait_btn_3, LV_OBJ_FLAG_CLICKABLE);
        //                 lv_label_set_text(guider_ui.wait_label_3,"连接失败");
        //                 lv_label_set_text(guider_ui.wait_btn_3_label,"确定");
        //                 lv_timer_set_repeat_count(wait_timer,0);
        //                 CrLogI("wifi connect faild.");
        //             }
        //             if(*data == '1')//连接成功
        //             {
        //                 lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        //                 lv_obj_add_flag(guider_ui.wait_cont_1, LV_OBJ_FLAG_HIDDEN);
        //                 CrLogI("wifi connect success.");
        //                 connectwifi_state = false;
        //                 get_printer_data(0x07, 1, "2");
        //                 //进入等待状态
        //                 wait_timer = lv_timer_create(waittimer_handler, 10000, NULL);
        //                 lv_obj_clear_flag(guider_ui.wait_cont_1,LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_clear_flag(guider_ui.wait_spinner_1,LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_add_flag(guider_ui.wait_label_1,LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_add_flag(guider_ui.wait_label_2,LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_add_flag(guider_ui.wait_label_3,LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_add_flag(guider_ui.wait_btn_3,LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        //                 CrLogI("wifi connect success,wait wifi refresh....");
        //             }
        //             if(*data == '2')//连接中
        //             {
        // //                lv_obj_clear_flag(guider_ui.wait_cont_1, LV_OBJ_FLAG_HIDDEN);
        // //                lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        // //                lv_obj_add_flag(guider_ui.wait_spinner_1, LV_OBJ_FLAG_HIDDEN);
        // //
        // //                lv_obj_clear_flag(guider_ui.wait_label_1, LV_OBJ_FLAG_HIDDEN);
        // //                lv_obj_clear_flag(guider_ui.wait_label_2, LV_OBJ_FLAG_HIDDEN);
        // //                lv_obj_clear_flag(guider_ui.wait_label_3, LV_OBJ_FLAG_HIDDEN);
        // //                lv_obj_clear_flag(guider_ui.wait_btn_3, LV_OBJ_FLAG_HIDDEN);
        // //                lv_label_set_text(guider_ui.wait_label_3,"");
        // //                CrLogI("wifi password error.");
        //             }
        //             if(*data == '3')//密码错误
        //             {
        //                 lv_obj_add_flag(guider_ui.wait_spinner_1, LV_OBJ_FLAG_HIDDEN);

        //                 lv_obj_clear_flag(guider_ui.wait_label_1, LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_clear_flag(guider_ui.wait_label_2, LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_clear_flag(guider_ui.wait_label_3, LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_clear_flag(guider_ui.wait_btn_3, LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_add_flag(guider_ui.wait_btn_3, LV_OBJ_FLAG_CLICKABLE);
        //                 lv_label_set_text(guider_ui.wait_label_3,"密码错误");
        //                 lv_label_set_text(guider_ui.wait_btn_3_label,"确定");
        //                 lv_timer_set_repeat_count(wait_timer,0);
        //                 CrLogI("wifi password error.");
        //             }
        //             if(*data == '4')//连接超时
        //             {
        //                 lv_obj_add_flag(guider_ui.wait_spinner_1, LV_OBJ_FLAG_HIDDEN);

        //                 lv_obj_clear_flag(guider_ui.wait_label_1, LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_clear_flag(guider_ui.wait_label_2, LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_clear_flag(guider_ui.wait_label_3, LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_clear_flag(guider_ui.wait_btn_3, LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_add_flag(guider_ui.wait_btn_3, LV_OBJ_FLAG_CLICKABLE);
        //                 lv_label_set_text(guider_ui.wait_label_3,"连接超时");
        //                 lv_label_set_text(guider_ui.wait_btn_3_label,"确定");
        //                 lv_timer_set_repeat_count(wait_timer,0);
        //                 CrLogI("wifi connect timeout.");
        //             }
        //             if(*data == '5')//找不到热点
        //             {
        //                 lv_obj_add_flag(guider_ui.wait_spinner_1, LV_OBJ_FLAG_HIDDEN);

        //                 lv_obj_clear_flag(guider_ui.wait_label_1, LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_clear_flag(guider_ui.wait_label_2, LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_clear_flag(guider_ui.wait_label_3, LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_clear_flag(guider_ui.wait_btn_3, LV_OBJ_FLAG_HIDDEN);
        //                 lv_obj_add_flag(guider_ui.wait_btn_3, LV_OBJ_FLAG_CLICKABLE);
        //                 lv_label_set_text(guider_ui.wait_label_3,"找不到热点");
        //                 lv_label_set_text(guider_ui.wait_btn_3_label,"确定");
        //                 lv_timer_set_repeat_count(wait_timer,0);
        //                 CrLogI("wifi connect miss.");
        //             }
        //             break;
        //         }
                case CR_K1:
                case CR_K1_Max:
                case PF_05:{
                    if(*data == '0')//连接失败：报错弹窗
                    {
                        CrLogI("wifi connect faild.");
                        create_msgbox(PasswordError[get_cur_language_index()], NULL, 1000, lv_scr_act());
                       // wait_animmotion(0);
                    }
                    if(*data == '1')//连接成功
                    {
                        CrLogI("wifi connect success.");
                        CrLogI("wifi connect success,wait wifi refresh....");
                       // wait_animmotion(0);
                    }
                    if(*data == '2')//连接中
                    {
                    }
                    if(*data == '3')//密码错误
                    {
                        CrLogI("wifi password error.");
                       // create_msgbox(PasswordError[get_cur_language_index()], NULL, 1000, lv_scr_act());
                       // wait_animmotion(0);
                    }
                    if(*data == '4')//连接超时
                    {
                        CrLogI("wifi connect timeout.");
                        create_msgbox(PasswordError[get_cur_language_index()], NULL, 1000, lv_scr_act());
                       // wait_animmotion(0);
                    }
                    if(*data == '5')//找不到热点
                    {
                        CrLogI("wifi connect miss.");
                        create_msgbox(PasswordError[get_cur_language_index()], NULL, 1000, lv_scr_act());
                       // wait_animmotion(0);
                    }
                    break;
                }
            }
            break;
        }
        case CONTROL_FILAMENT:{
                switch(UIType)
                {
                    // case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:
                    {
                        if ( *data == '0' )
                        {
                            set_in_or_out_filamnet_state(FILAMENT_ACTION_FAILED);
                        }
                        else if ( *data == '1'  )
                        {
                            set_in_or_out_filamnet_state(FILAMENT_ACTION_SUCCESS);
                        }
                        else
                        {
                            set_in_or_out_filamnet_state(FILAMENT_ACTION_PROCCESSING);
                        }
                        break;
                    }
                }
            break;            
        }
        case CONTROL_LEVEL:{
            if(*data == '1')
            {
                switch(*(data+1))
                {
                    case '1':
                        break;
                    case '2':
                        break;
                    case '3':
                        break;
                    case '4':
                        break;
                    case '5':
                        break;
                    default:
                        break;
                }
            }
            else if(*data == '2')
            {
//                if(*(data+1) == '1')
//                {
//                    if (lv_obj_is_valid(guider_ui.level_auto_cont_1))
//                    {
//                        if (!lv_obj_has_flag(guider_ui.level_auto_cont_1,LV_OBJ_FLAG_HIDDEN))
//                        {
////                            auto_level_progress = 0;
//                            lv_label_set_text(guider_ui.selftest_label_88, "自动调平中....");
//                        }
//                    }
//                }
            }
            else if(*data == '3')
            {
               char temp[5];
               for(i=0;i<(len-1);i++)
               {
                   if(i>2)
                   {
                       break;
                   }
                   temp[i] = *(data+i+1);
                   if(*(data+i+1) == '\0')
                   {
                       break;
                   }
               }
               auto_level_progress = atoi(temp);
               temp[i] = '%';
               temp[i+1] = '\0';

               if(auto_level_progress >= 100)
               {
                    check_singleprocess_completed(6, true);
                    manual_test_completed(2, true);
               }
               else if(auto_level_progress == -1)
               {
                    check_singleprocess_completed(6, false);
                    manual_test_completed(2, false);
               }
            }
            else if(*data == '4')
            {
                if(len)
                {
                    level_point_value = *(data+1);
                }
                switch(UIType)
                {
                    // case CR_10_H1:refresh_auto_level_point();break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*data == '5')
            {
//                if(len)
//                {
//                    level_auto_model_value = *(data+1);
//                }
//                refresh_auto_level_model();
            }
            else if(*data == '6')
            {
//                if(len)
//                {
//                    if(*(data+1) == '1')
//                        level_high_speed_level = true;
//                    else
//                        level_high_speed_level = false;
//                }
//                refresh_auto_level_hspeed();
            }
            break;            
        }
        case CONTROL_MOTION_PARAMETERS:{
            switch(*data)
            {
                case '1':
                    if(*(data+1) == '1')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(STEPS_LEN-1))
                            {
                                break;
                            }
                            xSTEPS[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        xSTEPS[i] = '\0';
                        switch(UIType)
                        {
                            // case CR_10_H1:refresh_steps_setting(0x01);
                            // break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:break;
                        }
                    }
                    else if(*(data+1) == '2')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(STEPS_LEN-1))
                            {
                                break;
                            }
                            ySTEPS[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        ySTEPS[i] = '\0';
                        switch(UIType)
                        {
                            // case CR_10_H1:refresh_steps_setting(0x02);
                            // break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:break;
                        }
                    }
                    else if(*(data+1) == '3')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(STEPS_LEN-1))
                            {
                                break;
                            }
                            zSTEPS[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        zSTEPS[i] = '\0';
                        switch(UIType)
                        {
                            // case CR_10_H1:refresh_steps_setting(0x04);
                            // break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:break;
                        }
                    }
                    else if(*(data+1) == '4')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(STEPS_LEN-1))
                            {
                                break;
                            }
                            eSTEPS[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        eSTEPS[i] = '\0';
                        switch(UIType)
                        {
                            // case CR_10_H1:refresh_steps_setting(0x08);
                            // break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:break;
                        }
                    }
                    break;
                case '2':
                    if(*(data+1) == '1')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MACC_LEN-1))
                            {
                                break;
                            }
                            xmacc[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        xmacc[i] = '\0';
                        switch(UIType)
                        {
                            // case CR_10_H1:refresh_acc_setting(0x01);
                            // break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:break;
                        }
                    }
                    else if(*(data+1) == '2')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MACC_LEN-1))
                            {
                                break;
                            }
                            ymacc[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        ymacc[i] = '\0';
                        switch(UIType)
                        {
                            // case CR_10_H1:refresh_acc_setting(0x02);
                            // break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:break;
                        }
                    }
                    else if(*(data+1) == '3')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MACC_LEN-1))
                            {
                                break;
                            }
                            zmacc[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        zmacc[i] = '\0';
                        switch(UIType)
                        {
                            // case CR_10_H1:refresh_acc_setting(0x04);
                            // break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:break;
                        }
                    }
                    else if(*(data+1) == '4')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MACC_LEN-1))
                            {
                                break;
                            }
                            emacc[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        emacc[i] = '\0';
                        switch(UIType)
                        {
                            // case CR_10_H1:refresh_acc_setting(0x08);
                            // break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:break;
                        }
                    }
                    break;
                case '3':
                    if(*(data+1) == '1')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MJERK_LEN-1))
                            {
                                break;
                            }
                            xjerk[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        xjerk[i] = '\0';
                        switch(UIType)
                        {
                            // case CR_10_H1:refresh_jerk_setting(0x01);
                            // break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:break;
                        }
                    }
                    else if(*(data+1) == '2')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MJERK_LEN-1))
                            {
                                break;
                            }
                            yjerk[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        yjerk[i] = '\0';
                        switch(UIType)
                        {
                            // case CR_10_H1:refresh_jerk_setting(0x02);
                            // break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:break;
                        }
                    }
                    else if(*(data+1) == '3')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MJERK_LEN-1))
                            {
                                break;
                            }
                            zjerk[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        zjerk[i] = '\0';
                        switch(UIType)
                        {
                            // case CR_10_H1:refresh_jerk_setting(0x04);
                            // break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:break;
                        }
                    }
                    else if(*(data+1) == '4')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MJERK_LEN-1))
                            {
                                break;
                            }
                            ejerk[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        ejerk[i] = '\0';
                        switch(UIType)
                        {
                            // case CR_10_H1:refresh_jerk_setting(0x08);
                            // break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:break;
                        }
                    }
                    break;
                case '4':
                    if(*(data+1) == '1')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MSPEED_LEN-1))
                            {
                                break;
                            }
                            xmspeed[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        xmspeed[i] = '\0';
                        switch(UIType)
                        {
                            // case CR_10_H1:refresh_speed_setting(0x01);
                            // break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:break;
                        }
                    }
                    else if(*(data+1) == '2')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MSPEED_LEN-1))
                            {
                                break;
                            }
                            ymspeed[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        ymspeed[i] = '\0';
                        switch(UIType)
                        {
                            // case CR_10_H1:refresh_speed_setting(0x02);
                            // break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:break;
                        }
                    }
                    else if(*(data+1) == '3')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MSPEED_LEN-1))
                            {
                                break;
                            }
                            zmspeed[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        zmspeed[i] = '\0';
                        switch(UIType)
                        {
                            // case CR_10_H1:refresh_speed_setting(0x04);
                            // break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:break;
                        }
                    }
                    else if(*(data+1) == '4')
                    {
                        for(i=0;i<(len-2);i++)
                        {
                            if(i>(MSPEED_LEN-1))
                            {
                                break;
                            }
                            emspeed[i] = *(data+i+2);
                            if(*(data+i+2) == '\0')
                            {
                                break;
                            }
                        }
                        emspeed[i] = '\0';
                        switch(UIType)
                        {
                            // case CR_10_H1:refresh_speed_setting(0x08);
                            // break;
                            case CR_K1:
                            case CR_K1_Max:
                            case PF_05:break;
                        }
                    }
                    break;
                default:
                    break;
            }
            break;        
        }
        case CONTROL_HOME_OFFSET:{
            if(*data == '1')
            {
                for(i=0;i<len;i++)
                {
                    if(i>(OFFSET_LEN-1))
                    {
                        break;
                    }
                    origin_xoffset_value[i] = *(data+i+1);
                    if(*(data+i+1) == '\0')
                    {
                        break;
                    }
                }
                origin_xoffset_value[i] = '\0';
                switch(UIType)
                {
                    // case CR_10_H1:refresh_origin_offset_value(0x01);break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*data == '2')
            {
                for(i=0;i<len;i++)
                {
                    if(i>(OFFSET_LEN-1))
                    {
                        break;
                    }
                    origin_yoffset_value[i] = *(data+i+1);
                    if(*(data+i+1) == '\0')
                    {
                        break;
                    }
                }
                origin_yoffset_value[i] = '\0';
                switch(UIType)
                {
                    // case CR_10_H1:refresh_origin_offset_value(0x02);break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*data == '3')
            {
                for(i=0;i<len;i++)
                {
                    if(i>(OFFSET_LEN-1))
                    {
                        break;
                    }
                    origin_zoffset_value[i] = *(data+i+1);
                    if(*(data+i+1) == '\0')
                    {
                        break;
                    }
                }
                origin_zoffset_value[i] = '\0';
                switch(UIType)
                {
                    // case CR_10_H1:refresh_origin_offset_value(0x04);break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            break;            
        }
        case CONTROL_START_PREPARATEMP:{
            break;            
        }
        case CONTROL_AUTOPIDSETTINGS:{//设置喷头和热床自动PID参数
            if(*(data) == '1')        //hotend target temp
            {
                for(i=0;i<(len-1);i++)
                {
                    if(i>(HOTEND_TEMP_LEN-1))
                    {
                        break;
                    }
                    pid_hotend_tar[i] = *(data+i+1);
                    if(*(data+i+1) == '\0')
                    {
                        break;
                    }
                }
                pid_hotend_tar[i] = '\0';
                switch(UIType)
                {
                    // case CR_10_H1:refresh_pid_hotend_setting(1);break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*(data) == '2')   //hotend times
            {
                for(i=0;i<(len-1);i++)
                {
                    if(i>(REPEAT_TIMES_LEN-1))
                    {
                        break;
                    }
                    pid_hotend_times[i] = *(data+i+1);
                    if(*(data+i+1) == '\0')
                    {
                        break;
                    }
                }
                pid_hotend_times[i] = '\0';
                switch(UIType)
                {
                    // case CR_10_H1:refresh_pid_hotend_setting(2);break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*(data) == '3')        //bed target temp
            {
                for(i=0;i<(len-1);i++)
                {
                    if(i>(BED_TEMP_LEN-1))
                    {
                        break;
                    }
                    pid_bed_tar[i] = *(data+i+1);
                    if(*(data+i+1) == '\0')
                    {
                        break;
                    }
                }
                pid_bed_tar[i] = '\0';
                switch(UIType)
                {
                    // case CR_10_H1:refresh_pid_hotend_setting(1);break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*(data) == '4')   //bed times
            {
                for(i=0;i<(len-1);i++)
                {
                    if(i>(REPEAT_TIMES_LEN-1))
                    {
                        break;
                    }
                    pid_bed_times[i] = *(data+i+1);
                    if(*(data+i+1) == '\0')
                    {
                        break;
                    }
                }
                pid_bed_times[i] = '\0';
                switch(UIType)
                {
                    // case CR_10_H1:refresh_pid_hotend_setting(2);break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:break;
                }
            }
            else if(*(data) == '5')   //开始喷头PID
            {
//                auto_pid_progress = 0;
//                if (lv_obj_is_valid(guider_ui.pidseting_1_cont_1))
//                {
//                    if (!lv_obj_has_flag(guider_ui.pidseting_1_cont_1,LV_OBJ_FLAG_HIDDEN))
//                    {
//                        lv_obj_clear_flag(guider_ui.pidseting_1_btn_2, LV_OBJ_FLAG_CLICKABLE);
//                    }
//                }
            }
            else if(*(data) == '6')   //接收喷头或热床PID返回的进度数据
            {
                char ctemp[5];
                for(i=0;i<(len-1);i++)
                {
                    if(i>2)
                    {
                        break;
                    }
                    ctemp[i] = *(data+i+1);
                    if(*(data+i+1) == '\0')
                    {
                        break;
                    }
                }
                ctemp[i] = '\0';
                auto_pid_progress = atoi(ctemp);
                ctemp[i] = '%';
                ctemp[i+1] = '\0';
                switch(UIType)
                {
                    // case CR_10_H1:{
                    //     if(auto_pid_progress >= 100)
                    //     {
                    //         if (lv_obj_is_valid(guider_ui.selftest_cont_1))
                    //         {
                    //             if (!lv_obj_has_flag(guider_ui.selftest_cont_1,LV_OBJ_FLAG_HIDDEN))
                    //             {
                    //                 lv_obj_add_flag(guider_ui.selftest_btn_59, LV_OBJ_FLAG_CLICKABLE);
                    //                 lv_obj_add_flag(guider_ui.selftest_btn_62, LV_OBJ_FLAG_CLICKABLE);
                    //             }
                    //         }
                    //     }
                    //     break;
                    // }
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:{
                        break;
                    }
                }
            }
            else if(*(data) == '7')   //开始热床PID
            {
                auto_pid_progress = 0;
//                if (lv_obj_is_valid(guider_ui.pidseting_1_cont_1))
//                {
//                    if (!lv_obj_has_flag(guider_ui.pidseting_1_cont_1,LV_OBJ_FLAG_HIDDEN))
//                    {
//                        lv_obj_clear_flag(guider_ui.pidseting_1_btn_2, LV_OBJ_FLAG_CLICKABLE);
//                   }
//                }
            }
            break;
        }          

        case CONTROL_PID_PARAMETERS:{
            switch(*data)
            {
                case '1':
                    for(i=0;i<(len-1);i++)
                    {
                        if(i>(PID_LEN-1))
                        {
                            break;
                        }
                        hotend_pid_p[i] = *(data+i+1);
                        if(*(data+i+1) == '\0')
                        {
                            break;
                        }
                    }
                    hotend_pid_p[i] = '\0';
                    switch(UIType)
                    {
                        // case CR_10_H1:refresh_temp_pid_setting(0x01);break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                    break;
                case '2':
                    for(i=0;i<(len-1);i++)
                    {
                        if(i>(PID_LEN-1))
                        {
                            break;
                        }
                        hotend_pid_i[i] = *(data+i+1);
                        if(*(data+i+1) == '\0')
                        {
                            break;
                        }
                    }
                    hotend_pid_i[i] = '\0';
                    switch(UIType)
                    {
                        // case CR_10_H1:refresh_temp_pid_setting(0x02);break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                    break;
                case '3':
                    for(i=0;i<(len-1);i++)
                    {
                        if(i>(PID_LEN-1))
                        {
                            break;
                        }
                        hotend_pid_d[i] = *(data+i+1);
                        if(*(data+i+1) == '\0')
                        {
                            break;
                        }
                    }
                    hotend_pid_d[i] = '\0';
                    switch(UIType)
                    {
                        // case CR_10_H1:refresh_temp_pid_setting(0x04);break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                    break;
                case '4':
                    for(i=0;i<(len-1);i++)
                    {
                        if(i>(PID_LEN-1))
                        {
                            break;
                        }
                        bed_pid_p[i] = *(data+i+1);
                        if(*(data+i+1) == '\0')
                        {
                            break;
                        }
                    }
                    bed_pid_p[i] = '\0';
                    switch(UIType)
                    {
                        // case CR_10_H1:refresh_temp_pid_setting(0x08);break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                    break;
                case '5':
                    for(i=0;i<(len-1);i++)
                    {
                        if(i>(PID_LEN-1))
                        {
                            break;
                        }
                        bed_pid_i[i] = *(data+i+1);
                        if(*(data+i+1) == '\0')
                        {
                            break;
                        }
                    }
                    bed_pid_i[i] = '\0';
                    switch(UIType)
                    {
                        // case CR_10_H1:refresh_temp_pid_setting(0x10);break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                    break;
                case '6':
                    for(i=0;i<(len-1);i++)
                    {
                        if(i>(PID_LEN-1))
                        {
                            break;
                        }
                        bed_pid_d[i] = *(data+i+1);
                        if(*(data+i+1) == '\0')
                        {
                            break;
                        }
                    }
                    bed_pid_d[i] = '\0';
                    switch(UIType)
                    {
                        // case CR_10_H1:refresh_temp_pid_setting(0x20);break;
                        case CR_K1:
                        case CR_K1_Max:
                        case PF_05:break;
                    }
                    break;
                default:
                    break;
            }
            break;
        }

        case CONTROL_PRINT_STATE:{
//            if(len != 1)
//            {
//                break;
//            }
            // if(*data == '0')
            // {
            //     print_state = 0;
            // }
            // else if(*data == '1')
            // {
            //     print_state = 1;
            // }
            // else if(*data == '2')
            // {
            //     print_state = 2;
            // }
            // else if(*data == '3')
            // {
            //     print_state = 3;
            // }
            // else if(*data == '4')
            // {
            //     print_state = 4;
            // }
            // else if(*data == '5')
            // {
            //     print_state = 5;
            // }
            // else if(*data == '6')
            // {
            //     print_state = 6;
            // }
            // switch(UIType)
            // {
            //     case CR_10_H1:refresh_print_state();break;
            //     case CR_K1:
            //     case CR_K1_Max:case PF_05:break;
            // }
            break;            
        }

        case CONTROL_PRINT_SPEED:{
            for(i=0;i<len;i++)
            {
                if(i>(CUR_SPEED_LEN-1))
                {
                    break;
                }
                cur_speed[i] = *(data+i);
                if(*(data+i) == '\0')
                {
                    break;
                }
            }
            cur_speed[i] = '\0';
            switch(UIType)
            {
                // case CR_10_H1:refresh_printing_speed();break;
                case CR_K1:
                case CR_K1_Max:
                case PF_05:break;
            }
            break;
        }
        case CONTROL_LANGUAGE:{
                cur_language = atoi(data);
            switch(UIType)
            {
                // case CR_10_H1:refresh_language();break;
                case CR_K1:
                case CR_K1_Max:
                case PF_05:change_language_end(cur_language);break;
            }
            break;        
        }
        case CONTROL_BED_SIZE:{
            if(*data == '1')
            {
                for(i=0;i<len;i++)
                {
                    if(i>(BED_SIZE_LEN-1))
                    {
                        break;
                    }
                    bed_size_x[i] = *(data+i+1);
                    if(*(data+i+1) == '\0')
                    {
                        break;
                    }
                }
                bed_size_x[i] = '\0';
    //                refresh_bed_size(1);
            }
            else if(*data == '2')
            {
                for(i=0;i<len;i++)
                {
                    if(i>(BED_SIZE_LEN-1))
                    {
                        break;
                    }
                    bed_size_y[i] = *(data+i+1);
                    if(*(data+i+1) == '\0')
                    {
                        break;
                    }
                }
                bed_size_y[i] = '\0';
    //                refresh_bed_size(2);
            }
            break;        
        }

        case CONTROL_REPEAT_PRINT_COUNT:{
            for(i=0;i<len;i++)
            {
                if(i>(REPEAT_TIMES_LEN-1))
                {
                    break;
                }
                repeat_times[i] = *(data+i);
                if(*(data+i) == '\0')
                {
                    break;
                }
            }
            repeat_times[i] = '\0';
            switch(UIType)
            {
                // case CR_10_H1:refresh_repeattimes();break;
                case CR_K1:
                case CR_K1_Max:
                case PF_05:break;
            }
            break;            
        }

        case CONTROL_MACHINE_PARAMETERS:{
            break;            
        }

        case CONTROL_IOT_QRCODE:{
            break;            
        }

        case CONTROL_PRINT_FLOW:{
            for(i=0;i<len;i++)
            {
                if(i>(CUR_SPEED_LEN-1))
                {
                    break;
                }
                cur_printflow[i] = *(data+i);
                if(*(data+i) == '\0')
                {
                    break;
                }
            }
            cur_printflow[i] = '\0';
            switch(UIType)
            {
                // case CR_10_H1:refresh_printing_flow();break;
                case CR_K1:
                case CR_K1_Max:
                case PF_05:break;
            }
            break;
        }
        case CONTROL_MACHINE_STATE:{
            if(*data == '3')
            {
                switch(UIType)
                {
                    // case CR_10_H1:{
                    //     if(*(data+1) == '0')
                    //     {
                    //         lv_obj_clear_flag(guider_ui.selftest_btn_53,LV_OBJ_FLAG_HIDDEN);
                    //         lv_obj_clear_flag(guider_ui.selftest_btn_54,LV_OBJ_FLAG_HIDDEN);
                    //         lv_obj_clear_flag(guider_ui.selftest_btn_55,LV_OBJ_FLAG_HIDDEN);
                    //         lv_obj_add_flag(guider_ui.selftest_btn_53,LV_OBJ_FLAG_CLICKABLE);
                    //         lv_obj_add_flag(guider_ui.selftest_btn_54,LV_OBJ_FLAG_CLICKABLE);
                    //         lv_obj_add_flag(guider_ui.selftest_btn_55,LV_OBJ_FLAG_CLICKABLE);
                    //         lv_label_set_text(guider_ui.selftest_label_97,"检测失败");
                    //         lv_label_set_text(guider_ui.selftest_label_98,"振动补偿检测未完成，检测失败。");
                    //     }
                    //     if(*(data+1) == '1')
                    //     {
                    //         lv_obj_clear_flag(guider_ui.selftest_btn_53,LV_OBJ_FLAG_HIDDEN);
                    //         lv_obj_clear_flag(guider_ui.selftest_btn_54,LV_OBJ_FLAG_HIDDEN);
                    //         lv_obj_clear_flag(guider_ui.selftest_btn_55,LV_OBJ_FLAG_HIDDEN);
                    //         lv_obj_add_flag(guider_ui.selftest_btn_53,LV_OBJ_FLAG_CLICKABLE);
                    //         lv_obj_add_flag(guider_ui.selftest_btn_54,LV_OBJ_FLAG_CLICKABLE);
                    //         lv_obj_add_flag(guider_ui.selftest_btn_55,LV_OBJ_FLAG_CLICKABLE);
                    //         lv_label_set_text(guider_ui.selftest_label_97,"检测已完成");
                    //         lv_label_set_text(guider_ui.selftest_label_98,"振动补偿检测已完成，状态正常。");
                    //     }
                    //     if(*(data+1) == '2')
                    //     {
                    //         lv_obj_add_flag(guider_ui.selftest_btn_53,LV_OBJ_FLAG_HIDDEN);
                    //         lv_obj_add_flag(guider_ui.selftest_btn_54,LV_OBJ_FLAG_HIDDEN);
                    //         lv_obj_add_flag(guider_ui.selftest_btn_55,LV_OBJ_FLAG_HIDDEN);
                    //         lv_label_set_text(guider_ui.selftest_label_97,"正在检测中");
                    //         lv_label_set_text(guider_ui.selftest_label_98,"检测过程中请勿触碰到打印机。");
                    //     }
                    //     break;
                    // }
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:
                        if(*(data+1) == '0')
                        {
                            check_singleprocess_completed(5,false);
                            manual_test_completed(1, false);
                        }
                        if(*(data+1) == '1')
                        {
                            check_singleprocess_completed(5,true);
                            manual_test_completed(1, true);
                        }
                        break;
                }
            }
            else if(*data == '6')//解绑创想云
            {
                bool result = false;
                if(*(data+1) == '1')//解绑成功
                {
                    CrLogI("log out success");
                    result = true;
                    system_state.CxyUserInfoState = 0;
                }
                else
                {
                    CrLogI("log out fail");
                    result = false;
                }
                
                switch(UIType)
                {
                    // case CR_10_H1:{
                    //     break;
                    // }
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:get_printer_data(CONTROL_MACHINE_STATE, 2, "6"); //无论成功失败都再查询一次用户信息
                        break;
                }
            }
            else if(*data == 'a')//AI轮廓仪标定
            {
                CrLogI("AI check result:%d",*(data+1) - '0');
                switch(UIType)
                {
                    // case CR_10_H1:{
                    //     break;
                    // }
                    case CR_K1:break;
                    case CR_K1_Max:
                    case PF_05:JudgeAILiDARIsNormal(*(data+1) - '0');break;
                }
            }
            break;
        }
        case CONTROL_MACHINE_LOG:{
            if(*data == '1')
            {
                int type = 0;
                int process = 0;
                char temp[255] = {0};

                int count = 0;
                for(i=0; i<(len-1); i++)
                {
                    temp[count++] = *(data+i+1);
                    if(*(data+1+i) == '\t')
                    {
                        type = atoi(temp);
                        count = 0;
                        memset(temp, 0, sizeof(temp));
                        continue;
                    }
                    if(*(data+1+i) == '\0')
                    {
                        process = atoi(temp);
                        count = 0;
                        memset(temp, 0, sizeof(temp));
                        break;
                    }
                }
                CrLogI("export lot the state:%d, the process:%d", type, process);
                switch(UIType)
                {
                    // case CR_10_H1:{
                    //     if(*(data+1) == '0')
                    //     {
                    //         lv_label_set_text(guider_ui.printmessage_label_3,"日志导出中");
                    //         lv_obj_clear_flag(guider_ui.printmessage_cont_1,LV_OBJ_FLAG_HIDDEN);
                    //         lv_obj_clear_flag(guider_ui.printmessage_btn_3,LV_OBJ_FLAG_CLICKABLE);
                    //     }
                    //     if(*(data+1) == '1')
                    //     {
                    //         lv_label_set_text(guider_ui.printmessage_label_3,"日志导出成功");
                    //         lv_obj_add_flag(guider_ui.printmessage_btn_3,LV_OBJ_FLAG_CLICKABLE);
                    //     }
                    //     if(*(data+1) == '2')
                    //     {
                    //         lv_label_set_text(guider_ui.printmessage_label_3,"日志导出失败");
                    //         lv_obj_add_flag(guider_ui.printmessage_btn_3,LV_OBJ_FLAG_CLICKABLE);
                    //     }
                    //     if(*(data+1) == '3')
                    //     {
                    //         lv_label_set_text(guider_ui.printmessage_label_3,"U盘不存在");
                    //         lv_obj_add_flag(guider_ui.printmessage_btn_3,LV_OBJ_FLAG_CLICKABLE);
                    //     }
                    //     break;
                    // }
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:refreshmsgbox(type, process);break;
                }
            }
            else if(*data == '2')//上传日志
            {
                data++;
                
                int state = 0;
                int process = 0;
                char SN[256] = {0};

                char *temp = strtok(data,"\t");
                int data_flag = 0;
                while(temp)
                {
                    switch(data_flag)
                    {
                        case 0:state = atoi(temp);break;
                        case 1:process = atoi(temp);break;
                        case 2:snprintf(SN, 256, "%s", temp);break;
                        default:CrLogW("analyze data flag is not exist");break;
                    }
                    data_flag++;
                    temp = strtok(NULL,"\t");
                }   
                CrLogI("upload log state:%d,the peocess:%d, the SN:%s", state, process, SN);
                switch (UIType)
                {
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:refresh_uploadlog_process(state, process, SN);
                               selftest_refresh_upload_process(state, process, SN);
                        break;
                }
            }
            else if(*data == '3')//上传延时摄影视频
            {
                int result = 0;
                switch (*(data+1))
                {
                    case '0':result = 0;break;
                    case '1':result = 1;break;
                    case '2':result = 2;break;
                    default:CrLogW("don't have result");break;
                }

                switch(UIType)
                {
                    // case CR_10_H1:{break;}
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:
                        break;
                }

            }
            else if(*data == '4')//压缩状态
            {
                data++;
                int process = atoi(data);
                CrLogI("Compressed process:%d", process);
                switch(UIType)
                {
                    // case CR_10_H1:break;
                    case CR_K1:
                    case CR_K1_Max:
                    case PF_05:refresh_compressed_process(process);break;
                }

            }
            break;
        }
        default:
            break;
    }
}
