// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: SquareLine_Project

#ifndef _SQUARELINE_PROJECT_UI_H
#define _SQUARELINE_PROJECT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#define PNG_DRV_LETTER "S"  //此处的驱动字符需要和lv_conf文件中驱动字符一致.
// #define BRAZIL_CUSTOM_ORDER //巴西定制订单宏，用于屏蔽wifi相关页面

#include "../custom/CrlogDef.h"
#include "../custom/commu_thread.h"
#include "../custom/custom.h"
#include "../custom/mystyle.h"
#include "ui_Screen_Touchtone.h"
#include "ui_Screen_Changelanguage.h"
#include "ui_Screen_Settings.h"
#include "ui_Screen_Devicebinding.h"
#include "ui_Screen_Exportlog.h"
#include "ui_Screen_Updateversion.h"
#include "ui_Screen_ResetMachine.h"
#include "ui_Screen_AboutDevice.h"
#include "ui_Screen_NetworkInfo.h"
#include "ui_screen_HomePrinting.h"
#include "ui_Screen_SelftestPrivacyPolicy.h"
#include "ui_Screen_SelftestNetwork.h"
#include "ui_Screen_SelftestTips.h"
#include "ui_Screen_Manualtest.h"
#include "ui_Screen_OFF.h"
#include "ui_Screen_TimezoneSettings.h"
#include "ui_Screen_SelftestCompleted.h"
#include "ui_Screen_SelftestDevicebinding.h"
#include "ui_Screen_SelftestDevicebinding.h"
#include "ui_Screen_SelftestAll.h"
#include "ui_Screen_CustomerFaq.h"
#include "ui_Screen_CustomerWiki.h"
#include "ui_Screen_Widgets.h"
#include "ui_Screen_Boot0.h"
#include "ui_Screen_Boot3.h"
#include "ui_screen_Preview.h"
#include "mult_language.h"
#include "ui_screen_HomeNormal.h"
#include "ui_screen_filament_Infor.h"
#include "ui_screen_AxisMove.h"
#include "ui_Screen_ExcludeObject.h"
#include "ui_Screen_ExpertMode.h"
#include "ui_Screen_BedMeshAdjust.h"

#include "./Message/ServerMessage.h"
#include "Base/DisplayMsgBase.h"

extern int CheckKlipperState;
extern int DotCheckVersion;
extern bool FirstInitFlag;
// LV_IMG_DECLARE(ui_img_home_png);    // assets\home.png
// LV_IMG_DECLARE(ui_img_axismove_png);    // assets\axismove.png
// LV_IMG_DECLARE(ui_img_file_png);    // assets\file.png
// LV_IMG_DECLARE(ui_img_setting_blue_png);    // assets\setting_blue.png
// LV_IMG_DECLARE(ui_img_faq_png);    // assets\faq.png
LV_IMG_DECLARE(ui_img_light_down_png);    // assets\light_down.png
LV_IMG_DECLARE(ui_img_light_up_png);    // assets\light_up.png
LV_IMG_DECLARE(ui_img_vector_24_png);    // assets\Vector_24.png
LV_IMG_DECLARE(ui_img_network_png);    // assets\network.png
LV_IMG_DECLARE(ui_img_group_12_png);    // assets/Group 12.png
LV_IMG_DECLARE(ui_img_camera_png);    // assets\camera.png
LV_IMG_DECLARE(ui_img_video_png);    // assets\video.png
LV_IMG_DECLARE(ui_img_seting_1_png);    // assets\seting_1.png
LV_IMG_DECLARE(ui_img_ai_logo_png);    // assets\ai_logo.png
LV_IMG_DECLARE(ui_img_group_246_png);    // assets\group_246.png
LV_IMG_DECLARE(ui_img_group_245_png);    // assets\group_245.png
LV_IMG_DECLARE(ui_img_machine_png);    // assets\machine.png
LV_IMG_DECLARE(ui_img_logo_png);    // assets\logo.png
LV_IMG_DECLARE(ui_img_hotfan_png);    // assets\hotfan.png
LV_IMG_DECLARE(ui_img_modfan_png);    // assets\modfan.png
LV_IMG_DECLARE(ui_img_axishome_png);    // assets\axishome.png
LV_IMG_DECLARE(ui_img_sensor_out_png);    // assets\sensor_out.png
LV_IMG_DECLARE(ui_img_sensor_in_png);    // assets/sensor_in.png
LV_IMG_DECLARE(ui_img_manuallevel_png);    // assets\manuallevel.png
LV_IMG_DECLARE(ui_img_exchange_png);    // assets\exchange.png
LV_IMG_DECLARE(ui_img_sensor_state_png);    // assets\sensor_state.png
LV_IMG_DECLARE(ui_img_state_normal_png);    // assets\state_normal.png
LV_IMG_DECLARE(ui_img_state_ignore_png);    // assets\state_ignore.png
LV_IMG_DECLARE(ui_img_state_error_png);    // assets\state_error.png
LV_IMG_DECLARE(ui_img_level_3_black_png);    // assets\level_3_black.png
LV_IMG_DECLARE(ui_img_level_3_blue_png);    // assets/level_3_blue.png
LV_IMG_DECLARE(ui_img_level_4_blcak_png);    // assets\level_4_blcak.png
LV_IMG_DECLARE(ui_img_level_4_blue_png);    // assets/level_4_blue.png
LV_IMG_DECLARE(ui_img_level_5_black_png);    // assets/level_5_black.png
LV_IMG_DECLARE(ui_img_level_5_blue_png);    // assets\level_5_blue.png
LV_IMG_DECLARE(ui_img_hotend_big_png);    // assets\hotend_big.png
LV_IMG_DECLARE(ui_img_change_png);    // assets\change.png
LV_IMG_DECLARE(ui_img_group_1419_png);    // assets\Group_1419.png
LV_IMG_DECLARE(ui_img_close_png);    // assets\close.png
LV_IMG_DECLARE(ui_img_back_png);    // assets\back.png
LV_IMG_DECLARE(ui_img_bedtemp_png);    // assets\bedtemp.png
LV_IMG_DECLARE(ui_img_settingtitleimg_png);    // assets/SettingTitleImg.png
LV_IMG_DECLARE(ui_img_wifi_info_png);    // assets/wifi_info.png
LV_IMG_DECLARE(ui_img_wifi_state_png);    // assets/wifi_state.png
LV_IMG_DECLARE(ui_img_wifi_state_1_png);    // assets/wifi_state_1.png
LV_IMG_DECLARE(ui_img_pagehomeselected_png);    // assets/pageHomeSelected.png
LV_IMG_DECLARE(ui_img_pagemove_png);    // assets/pageMove.png
LV_IMG_DECLARE(ui_img_pagefilemanage_png);    // assets/pageFileManage.png
LV_IMG_DECLARE(ui_img_pagesetting_png);    // assets/pageSetting.png
LV_IMG_DECLARE(ui_img_pagereserve_png);    // assets/pageReserve.png
LV_IMG_DECLARE(ui_img_wifinosignel_png);    // assets/wifiNoSignel.png
LV_IMG_DECLARE(ui_img_crealitylogo_png);    // assets/crealitylogo.png
LV_IMG_DECLARE(ui_img_company_png);    // assets/Company.png
LV_IMG_DECLARE(ui_img_hotend_png);    // assets/hotend.png
LV_IMG_DECLARE(ui_img_bed_png);    // assets/bed.png
LV_IMG_DECLARE(ui_img_lightclosed_png);    // assets/lightclosed.png
LV_IMG_DECLARE(ui_img_start_png);    // assets/start.png
LV_IMG_DECLARE(ui_img_toprint_png);    // assets/toPrint.png
LV_IMG_DECLARE(ui_img_hotendheating_png);    // assets/HotendHeating.png
LV_IMG_DECLARE(ui_img_totarget_png);    // assets/ToTarget.png
LV_IMG_DECLARE(ui_img_bedheating_png);    // assets/BedHeating.png
LV_IMG_DECLARE(ui_img_pause_png);    // assets/pause.png
LV_IMG_DECLARE(ui_img_pagehome_png);    // assets/pageHome.png
LV_IMG_DECLARE(ui_img_pagemoveselected_png);    // assets/pageMoveSelected.png
LV_IMG_DECLARE(ui_img_blackmovexy_png);    // assets/BlackMoveXY.png
LV_IMG_DECLARE(ui_img_up_png);    // assets/up.png
LV_IMG_DECLARE(ui_img_homez_png);    // assets/homeZ.png
LV_IMG_DECLARE(ui_img_down_png);    // assets/down.png
LV_IMG_DECLARE(ui_img_enterfila_png);    // assets/enterFila.png
LV_IMG_DECLARE(ui_img_uppery_png);    // assets/UpperY.png
LV_IMG_DECLARE(ui_img_downy_png);    // assets/DownY.png
LV_IMG_DECLARE(ui_img_downx_png);    // assets/DownX.png
LV_IMG_DECLARE(ui_img_upperx_png);    // assets/UpperX.png
LV_IMG_DECLARE(ui_img_homexy_png);    // assets/homeXY.png
LV_IMG_DECLARE(ui_img_offsetup_png);    // assets/OffsetUp.png
LV_IMG_DECLARE(ui_img_offsetdown_png);    // assets/OffsetDown.png
LV_IMG_DECLARE(ui_img_addprintspeed_png);    // assets/AddPrintSpeed.png
LV_IMG_DECLARE(ui_img_subprintspeed_png);    // assets/SubPrintSpeed.png
LV_IMG_DECLARE(ui_img_addflow_png);    // assets/AddFlow.png
LV_IMG_DECLARE(ui_img_subflow_png);    // assets/SubFlow.png
LV_IMG_DECLARE(ui_img_whitehomez_png);    // assets/WhiteHomeZ.png
LV_IMG_DECLARE(ui_img_wifimid_png);    // assets/WifiMid.png
LV_IMG_DECLARE(ui_img_wifismall_png);    // assets/WifiSmall.png
LV_IMG_DECLARE(ui_img_lightopened_png);    // assets/lightopened.png
LV_IMG_DECLARE(ui_img_outfila_png);    // assets/outFila.png
//LV_IMG_DECLARE(ui_img_pagefilemanageselected_png);    // assets/pageFileManageSelected.png
LV_IMG_DECLARE(ui_img_pagereserveselected_png);    // assets/pageReserveSelected.png
LV_IMG_DECLARE(ui_img_pagesettingselected_png);    // assets/pageSettingSelected.png
LV_IMG_DECLARE(ui_img_wififull_png);    // assets/wifiFull.png
LV_IMG_DECLARE(ui_img_wifimid_png);    // assets/wifiMid.png
LV_IMG_DECLARE(ui_img_wifismall_png);    // assets/wifiSmall.png

LV_IMG_DECLARE(ui_img_pagehome_png);    // assets/pageHome.png
LV_IMG_DECLARE(ui_img_pagemove_png);    // assets/pageMove.png
LV_IMG_DECLARE(ui_img_pagefilemanageselected_png);    // assets/pageFileManageSelected.png
LV_IMG_DECLARE(ui_img_pagesetting_png);    // assets/pageSetting.png
LV_IMG_DECLARE(ui_img_pagereserve_png);    // assets/pageReserve.png
LV_IMG_DECLARE(ui_img_totaltime_png);    // assets/totalTime.png
LV_IMG_DECLARE(ui_img_materialusage_png);    // assets/materialUsage.png
LV_IMG_DECLARE(ui_img_dirmini_png);    // assets/DirMini.png
LV_IMG_DECLARE(ui_img_newprev_png);    // assets/newPrev.png
LV_IMG_DECLARE(ui_img_newnext_png);    // assets/newNext.png
LV_IMG_DECLARE(ui_img_cross_png);    // assets/cross.png
LV_IMG_DECLARE(ui_img_hook_png);    // assets/hook.png
LV_IMG_DECLARE(ui_img_pagefilemanage_png);    // assets/pageFileManage.png
LV_IMG_DECLARE(ui_img_slash_png);    // assets/slash.png

LV_IMG_DECLARE(_back_36x24);    // assets/slash.png
LV_IMG_DECLARE(_group_1453_23x23);    // assets/slash.png
LV_IMG_DECLARE(ui_img_crealitylogo96_png);    // assets/slash.png

LV_IMG_DECLARE(ui_img_stop_fan_png);
LV_IMG_DECLARE(ui_img_move_fan);
LV_IMG_DECLARE(ui_img_HomeFan);
LV_IMG_DECLARE(ui_img_move_stop_fan_png);
LV_IMG_DECLARE(ui_img_home_used_png);
LV_IMG_DECLARE(ui_img_home_remainder_png);
LV_IMG_DECLARE(ui_img_proccess_png);
LV_IMG_DECLARE(ui_img_expand_down_png);

LV_IMG_DECLARE(ui_img_disable_stepper_png);    // assets\disable_stepper.png
LV_IMG_DECLARE(ui_img_preview_bed_png);    // assets\preview_bed.png
LV_IMG_DECLARE(ui_img_preview_hotend_png);    // assets\preview_hotend.png
LV_IMG_DECLARE(ui_img_temper_chassis_png);    // assets\temper_chassis.png
LV_IMG_DECLARE(ui_img_arrow_png);    // assets\arrow.png
LV_IMG_DECLARE(ui_img_add_png);    // assets\add.png
LV_IMG_DECLARE(ui_img_sub_png);    // assets\sub.png
LV_IMG_DECLARE(ui_img_cool_stop_fan_png);    // assets\cool_stop_fan.png
LV_IMG_DECLARE(ui_img_filament_hotend_normal_png);    // assets\filament_hotend_normal.png
LV_IMG_DECLARE(ui_img_filament_hotend_heat_png);    // assets\filament_hotend_heat.png
LV_IMG_DECLARE(ui_img_filament_to_png);    // assets\filament_to.png
LV_IMG_DECLARE(ui_img_sub_sign_png);    // assets\sub_sign.png
LV_IMG_DECLARE(ui_img_vector_19_png);    // assets/Vector 19.png
LV_IMG_DECLARE(ui_img_mask_png);    // assets/mask.png
LV_IMG_DECLARE(ui_img_881581767);    // assets/勾.png

LV_IMG_DECLARE(ui_img_boot0_png);    // assets/boot1.png
LV_IMG_DECLARE(ui_img_boot1_png);    // assets/boot1.png
LV_IMG_DECLARE(ui_img_boot2_png);    // assets/boot2.png
LV_IMG_DECLARE(ui_img_boot3_png);    // assets/boot3.png
LV_IMG_DECLARE(ui_img_boot4_png);    // assets/boot4.png
LV_IMG_DECLARE(ui_img_mask2_png);    // assets/mask2.png

LV_IMG_DECLARE(ui_img_down_grey_png);    // assets/boot2.png
LV_IMG_DECLARE(ui_img_down_white_png);    // assets/boot3.png
LV_IMG_DECLARE(ui_img_up_grey_png);    // assets/boot4.png
LV_IMG_DECLARE(ui_img_up_white_png);    // assets/mask2.png
LV_IMG_DECLARE(ui_img_wait_gif);    // assets/mask2.png
LV_IMG_DECLARE(ui_img_wait_png);    // assets/mask2.png
LV_IMG_DECLARE(ui_img_k1max_about_png);    // assets/mask2.png
LV_IMG_DECLARE(ui_img_k1max_selftest_png);    // assets/mask2.png

LV_FONT_DECLARE(ui_font_lvfontsimsun24);
LV_FONT_DECLARE(ui_font_lvfontsimsun28);
LV_FONT_DECLARE(ui_font_lvfontsimsun32);
LV_FONT_DECLARE(ui_font_lvfontsimsun25);
LV_FONT_DECLARE(ui_font_lvfontsimsun18);
LV_FONT_DECLARE(ui_font_lvfontsimsun14);
LV_FONT_DECLARE(ui_font_lvfontsimsun22);
LV_FONT_DECLARE(ui_font_lvfontsimsun26);
LV_FONT_DECLARE(ui_font_lvfontsimsun30);
LV_FONT_DECLARE(ui_font_lvfontsimsun36);
LV_FONT_DECLARE(ui_font_PrivacyPolicy);

typedef struct PrintJobInfo{
    char printfile_name[256];
    char printimg_src[256];
    char gcode_type[256];
    int start_px;
    int end_px;
    double model_height;
    double model_layerheight;
    int layercount;
    int currentlayer;
}PrintJobInfo_t;

//页面定义
enum {
    PAGE_HOME = 0,
    PAGE_HOME_PRINT,
    PAGE_AXIS,
    PAGE_FILEMANAGE,
    PAGE_SETING,
    PAGE_HELP,
    PAGE_ADVANCEDMODE,
    PAGE_BEDLEVEL,
    PAGE_COUNT//页面总数
};

extern PrintJobInfo_t print_job;
void ui_init(UIInit_t init_ui);
void ui_change(int pagenumber);

#if LV_USE_LOG
    void lvgl_log_print(char * buff);
#endif
#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
