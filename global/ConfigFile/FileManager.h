/*
 * @Description : FileManager.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-28 14:52:51
 * @LastEditTime: 2023-10-18 11:03:06
 */
#ifndef __FILE_MANAGER_H__
#define __FILE_MANAGER_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

#define DEF_PATH_LEN                256

#define DEF_CONGFIG_DIR             SYS_CONFIG
#define DEF_OTA_DIR                 "/etc/ota_bin"
#define USER_DATA_DIR               USER_DATA_PATH
#define USER_TEMP_DIR               "/tmp/creality"
#define USER_LOCAL_U_DISK_PATH      U_DISK_PATH
#define USER_LOCAL_SD_CARD_PATH     SD_CARD_PATH
#define USER_SHARE_FRONTEND_DIR     "/usr/share/frontend"
#define USER_SHARE_HTTPS_CERT_DIR   "/usr/share/cert"
#define SYSTEM_KERNEL_LOG_DIR       "/var/log/messages"
#define SYSTEM_OVERLAY_UPPER_DIR    "/overlay/upper"
#define SYSTEM_HOSTNAME_DIR         "/etc/hostname"

#define DEF_DATA_FILE_ICON          "defData/file_icon.png"
#define DEF_DATA_FILE_PREVIEW       "defData/file_preview.png"
#define DEF_DATA_FILE_PRINT_PHOTO   "defData/file_print_photo.png"
#define DEF_DATA_FOLDER_ICON        "defData/folder_icon.png"
#define DEF_DATA_ERROR_CODE_MAP     "defData/error_code_map.json"
#define FLOW_DETECT_GCODE_FILE      "defData/Auto_pressure_advance_testpadvance.gcode"
#define LASER_TEST_GCODE_FILE       "defData/laser_test_line.gcode"
#define LINE_HEIGHT_GCODE_FILE      "defData/line_width_height.gcode"
#define AUTO_LASER_TEST_GCODE_FILE  "defData/auto_laser_test.gcode"
#define LASER_CORRECTION_GCODE_FILE "defData/laser_offset_correction.gcode"
#define LASER_CORRECTION_0_2MM_GCODE "defData/laser_offset_correction_0.2mm.gcode"
#define FONT_SOURCE_HAN_SANS_FILE   "defData/SourceHanSansCN-Normal.otf"
#define K1_IMAGE_SOURCE_PATH        "UIResource/K1/"
#define K1MAX_IMAGE_SOURCE_PATH     "UIResource/K1_Max/"
#define USER_DATA_LANGUAGE          "audio"
#define DEVICE_CREALITY_DIR         "creality"
#define USER_DATA_CREALITY_DIR      "creality/userdata"
#define USER_DATA_CONFIG_DIR        "creality/userdata/config"
#define USER_DATA_HISTORY_DIR       "creality/userdata/history"
#define USER_DELAY_IMAGE_DIR        "creality/userdata/delay_image"
#define USER_FAULT_CODE_DIR         "creality/userdata/fault_code"
#define USER_DATA_LOG_DIR           "creality/userdata/log"
#define USER_UPGRADE_FILE_DIR       "creality/upgrade"
#define USER_TMP_FILE_DIR           "creality/tmp"
#define USER_TMP_POINT_CLOUD_DIR    "creality/tmp/pointCloud"
#define USER_DATA_KLIPPER_LOG_DIR   "printer_data/logs"
#define USER_DELAY_IMAGE_H264       "timelapse/main_output.h264"
#define USER_TEMP_THUMBNAIL_DIR     "humbnail"
#define USER_TEMP_ORIGINAL_DIR      "original"
#define USER_TEMP_VIDEO_DIR         "video"
#define USER_TEMP_COVER_DIR         "cover"
#define USER_HTTP_CERT_KEY          "server.key"
#define USER_HTTP_CERT_CRT          "server.crt"
#define USER_HTTP_CERT_PEM          "cacert.pem"
#define FRONTEND_DOWNLOADS_DIR      "/downloads/"
#define USER_DATA_KLIPPER_CONFIG_DIR "printer_data/config"
#define USER_DATA_KLIPPER_GCODES_DIR "printer_data/gcodes"
#define AI_DETECT_IMAGE_DIR         "ai_image"
#define USER_LOCAL_GCODE_DIR        "local_gcode"
#define USER_UDISK_GCODE_DIR        "udisk_gcode"

#define SYSTEM_COMFIG_FILE          "system_config.json"
#define SYSTEM_VERSION_FILE         "system_version.json"
#define USER_DATA_NOT_DELETED       "user_data_not_deleted.json"
#define IOT_CONFIG_FILE             "cxsw_params.json"
#define IOT_TB_INFO_FILE            "cxsw_tb_info.json"
#define USER_PRINT_REFER_FILE       "user_print_refer.json"
#define PRINT_HISTORY_RECORD        "print_history_record.json"
#define DELAY_IMAGE_INFO            "delay_image_info.json"
#define FAULT_CODE_INFO             "fault_code_info.json"
#define GCODE_FILE_INFO_FILE        "gcode_file_info.json"
#define USER_UPGRADE_INFO_FILE      "upgrade_info.json"
#define USER_BIND_DEV_QRCODE        "bind_qrcode.png"
#define USER_SERVICE_QRCODE         "user_service_qrcode.png"
#define USER_TEMP_IMAGE_FILE        "temp_image.png"
#define CUR_PRINT_IMAGE_FILE        "current_print_image.png"
#define TEMP_SAVE_SYSTEM_INFO_FILE  "readme_system_info.json"
#define DEVELOP_DEBUG_MODE_FILE     "debug_mode"
#define DEVELOP_STOP_ERROR_FILE     "stop_error"
#define AGREE_ROOT_POLICY           "user_agree_root"
#define FACTORY_TEST_FILE           "factory_test"
#define MACHINE_TEST_FILE           "machine_test"
#define MONITOR_EXECUTE_RUN         "monitor_execute_run"
#define PRINTER_INFO_FILE           "printer_info.json"
#define PRINTER_FILE_NAME           "print_file_name.json"
#define HTTPD_CONFIG_FILE           "httpd.conf"
#define PRINTER_CONFIG_FILE         "printer.cfg"
#define FACTORY_CONFIG_FILE         "factory_printer.cfg"
#define MCU_SWD_UPGRADE_FILE        "mcu.bin"
#define AI_MAIN_CAPTURE_JPG         "main_capture.jpg"
#define AI_MAIN_PROCESSED_JPG       "main_processed.jpg"
#define AI_SUB_CAPTURE_JPG          "sub_capture.jpg"
#define AI_SUB_PROCESSED_JPG        "sub_processed.jpg"
#define LOCAL_GCODE_FILE_INFO       "local_gcode_file_info.json"
#define UDISK_GCODE_FILE_INFO       "udisk_gcode_file_info.json"
#define USER_AVATAR_PNG             "user_avatar.png"
#define USER_DATA_LOG_CONFIG        "log_config.json"
#define CURRENT_WORK_INFO           "current_work_info.json"
#define LASER_OFFSET_INFO           "laser_offset_info.json"
#define SAVE_Z_AXIS_HEIGHT          "z_pos.json"
#define DEVICE_STRUCTURE_CONFIG     "device_structure_config.json"
#define PRINT_PARA_CONFIG           "print_para_config.json"
#define MACHINE_PRODUCTION_INFO     "machine_production_info"

// 临时文件
#define EXPORT_LOG_7Z               "export_log_7z.temp"
#define SCAN_TABLE_POINT_TEMP       "scan_table_point.temp"
#define SCAN_FIRST_LAYER_POINT_TEMP "scan_first_layer_point.temp"
#define GCODE_REDUCTION_POINT_TEMP  "gcode_reduction_point.temp"
#define OFFSET_CORRECTION_POINT_TEMP    "laser_offset_correction_point.temp"
#define OFFSET_CORRECTION_02MM_TABLE_PC_TEMP    "laser_offset_correction_table_pc.temp"
#define OFFSET_CORRECTION_02MM_SCAN_PC_TEMP     "laser_offset_correction_scan_pc.temp"
#define OFFSET_CORRECTION_EXP1000_POINT_TEMP    "laser_offset_correction_point_exp1000.temp"
#define OFFSET_CORRECTION_EXP2000_POINT_TEMP    "laser_offset_correction_point_exp2000.temp"
#define OFFSET_TABLE_POINT_TEMP     "laser_offset_table_point.temp"
#define SCAN_FLOW_LINE_POINT_TEMP   "scan_flow_line_point.temp"
#define SCAN_FLOW_TABLE_POINT_TEMP  "scan_flow_table_point.temp"
#define SCAN_LINE_POINT_TEMP        "scan_line_point.temp"
#define AUTO_TEST_SCAN_LINE_POINT_TEMP        "laser_auto_test_line_point.temp"
#define AUTO_TEST_SCAN_TABLE_POINT_TEMP       "laser_auto_test_table_point.temp"
#define LINE_HIGHT_LINE_POINT_CLOUD_TEMP      "line_hight_line_pc.tmp"
#define LINE_HIGHT_TABLE_POINT_CLOUD_TEMP     "line_hight_table_pc.tmp"

// 脚本、管道、本地socket
#define USER_GET_SYSTEM_VERSION     "get_ota_current_version.sh"
#define USER_START_UPGRADE          "local_ota_update.sh"
#define GET_OTA_BOARD_NAME          "get_ota_board_name.sh"
#define GET_SYS_CERTIFIED_SN        "/usr/bin/get_sn_mac.sh sn"
#define GET_SYS_CERTIFIED_MAC       "/usr/bin/get_sn_mac.sh mac"
#define GET_SYS_DEVICE_MODEL        "/usr/bin/get_sn_mac.sh model"
#define GET_SYSTEN_SOUND_SIZE       "audio_setting.sh"
#define GET_SYSTEN_SCREEN_VALUE     "brightness.sh"
#define SYSTEN_TIME_ZONE            "timezone.sh"
#define PLAY_SOUND_CMD              "aplay"
#define H264_CONVERT_MP4_CMD        "/usr/bin/ffmpeg -framerate %d -i %s -vcodec copy -y -f mp4 %s"
#define RESTART_WEBRTC              "SERVER_NUM=%d /etc/init.d/S97webrtc restart"
#define RESTART_REPORT              "/usr/bin/report.sh %s"
#define LOG_7Z_COMPRESSION          "/usr/bin/7z a -mmt1 -mx=1 -mhe=on -p\'%s\' %s %s %s %s %s %s"
#define LOG_7Z_NO_PASSWORD          "/usr/bin/7z a -mmt1 -mx=1 -mhe=on %s %s %s %s %s %s"
#define GET_MACHINE_SN              "/usr/bin/get_sn_mac.sh machine_sn"
#define SET_MACHINE_SN              "/usr/bin/clear_sn_mac.sh machine_sn %s"

#define WEBRTC_PIPE_FILE            "/tmp/uvc_fifo"
#define KLIPPER_CLIENT_SOCK         "/tmp/klippy_client"
#define KLIPPER_SERVER_SOCK         "/tmp/klippy_uds"
#define AI_CLIENT_SOCKET            "/tmp/ai_clent_uds"
#define AI_SERVER_SOCKET            "/tmp/ai_server_uds"
#define MCU_SWD_UPGRADE_CMD         "echo 1 > /sys/devices/platform/swd/swd_update"
#define MCU_SWD_UPGRADE_PROGRESS    "cat /sys/devices/platform/swd/update_progress"
#define RESTART_KLIPPER_SERVER      "/etc/init.d/S55klipper_service restart"
#define RESTART_HOSTNAME            "/etc/init.d/S01hostname start"
#define RESTART_MDNS                "/etc/init.d/S99mdns restart"

#define SYSTEM_RESTART_PART         "echo \"part\" | nc -U /var/run/wipe.sock"
#define SYSTEM_RESTART_ALL          "echo \"all\" | nc -U /var/run/wipe.sock"
#define SCREEN_DISPLAY_OFF          "cmd_fb disable /dev/fb0"
#define SCREEN_DISPLAY_ON           "cmd_fb enable /dev/fb0 && cmd_fb display /dev/fb0"

int FileManagerInit(void);
unsigned int SaveConfigToFile(char *filePath, char *data, int len);
unsigned int GetConfigFromFile(char *filePath, char *data, int len);
size_t GetUserFileSize(const char *fileName);

char *GetDefaultSystemConfigFilePath(void);
char *GetDefaultSystemVersionFilePath(void);
char *GetDefaultIotConfigPath(void);
char *GetDefaultPrintReferFilePath(void);
char *GetDefaultFileIconPtah(void);
char *GetDefaultFilePreviewPtah(void);
char *GetDefaultFilePrintPhotoPtah(void);
char *GetDefaultFolderIconPtah(void);
char *GetDefaultErrorCodeMapPtah(void);
char *GetDefaultLanguagePtah(void);
char *GetDefaultSystemKernelLogPtah(void);
char *GetDefaultOverlayUpperPtah(void);

char *GetUserSystemConfigFilePath(void);
char *GetUserSystemVersionFilePath(void);
char *GetUserDataNotDeleteFilePtah(void);
char *GetUserPrintReferFilePath(void);
char *GetUserHttpdConfigFilePath(void);
char *GetuserPrintHistoryPtah(void);
char *GetuserPrintHistoryRecordPtah(void);
char *GetuserPrintHistoryImagePtah(void);
char *GetUserIotConfigPath(void);
char *GetUserIotTbInfoFilePtah(void);
char *GetUserDataConfigDirPtah(void);
char *GetUserDataLogDirPtah(void);
char *GetUserDataLogConfigPtah(void);
char *GetUserDataKlipperLogDirPtah(void);
char *GetUserAiImageDirPtah(void);
char *GetUserAiImageCapturePtah(void);
char *GetUserUpgradeDirPtah(void);
char *GetUserUpgradeInfoPtah(void);
char *GetUserDelayImageH264Ptah(void);
char *GetUserDelayImageDirPtah(void);
char *GetUserDelayImageInfoPtah(void);
char *GetUserDelayImageCoverPtah(void);
char *GetUserDelayImageVideoPtah(void);
char *GetUserFaultCodeDirPtah(void);
char *GetUserFaultCodeInfoPtah(void);
char *GetK1ImageResourcePtah(void);
char *GetK1MaxImageResourcePtah(void);

char *GetUserTempDirPtah(void);
char *GetUserMonitorExecuteRunPtah(void);
char *GetUserGcodeFileInfoFilePath(void);
char *GetUserTempThumbnailDirPtah(void);
char *GetUserTempOriginalDirPtah(void);
char *GetTempSaveSystemInfoPath(void);
char *GetUserTempOriginalPtah(void);
char *GetUserCurrentPrintImagePath(void);

char *GetUserLocalGcodeInfoDirPtah(void);
char *GetUserLocalGcodeFileInfoPtah(void);
char *GetUserLocalThumbnailDirPtah(void);
char *GetUserLocalOriginalDirPtah(void);
char *GetUserUdiskGcodeInfoDirPtah(void);
char *GetUserUdiskGcodeFileInfoPtah(void);
char *GetUserUdiskThumbnailDirPtah(void);
char *GetUserUdiskOriginalDirPtah(void);

char *GetUserLocalUdiskPtah(void);
char *GetUserLocalSdCardPtah(void);
char *GetCxyDeviceBindingQrCodePtah(void);
char *GetCxyUserServiceQrCodePtah(void);
char *GetDeviceCrealityDirPtah(void);
char *GetDeviceUserdataDirPtah(void);
char *GetDevelopDebugModePtah(void);
char *GetDevelopStopErrorPtah(void);
char *GetUserAgreeRootPolicyPath(void);
char *GetDevelopFactoryTestPtah(void);
char *GetDevelopMachineTestPtah(void);
char *GetSavePrinterInfoPtah(void);
char *GetSavePrintFileNamePtah(void);
char *GetUserPrinterConfigPath(void);
char *GetUserPrinterConfigFilePath(void);
char *GetUserFactoryConfigFilePath(void);
char *GetUserPrinterGcodesFilePath(void);
char *GetMcuSwdUpgradeFilePath(void);
char *GetFlowDetectGcodeFilePath(void);
char *GetUserAvatarPngPath(void);
char *GetCurrentWorkInfo(void);
char *GetLaserOffsetInfo(void);
char *GetSaveZaxisHeight(void);
char *GetDeviceStructureConfig(void);
char *GetDevicePrintParaConfig(void);
char *GetUserDataPath(void);
char *GetMachineProductionInfo(void);

// 临时文件
char *GetTempExportLog7z(void);
char *GetTempUserDataDir(void);
char *GetTempUserPointCloudDir(void);
char *GetTempScanTablePoint(void);
char *GetTempScanFirstLayerPoint(void);
char *GetTempGcodeReductionPoint(void);
char *GetTempOffsetCorrectionPoint(void);
char *GetTempOffsetCorrect02mmTablePc(void);
char *GetTempOffsetCorrect02mmScanPc(void);
char *GetTempOffsetCorrectionPointExp1000(void);
char *GetTempOffsetCorrectionPointExp2000(void);
char *GetTempOffsetTablePoint(void);
char *GetTempScanFlowTbalePoint(void);
char *GetTempScanFlowLinePoint(void);
char *GetTempScanLinePoint(void);
char *GetTempAutoTestScanTablePoint(void);
char *GetTempAutoTestScanLinePoint(void);
char *GetTempLineHeightTablePoint(void);
char *GetTempLineHeightLinePoint(void);
// 脚本、管道、本地socket
char *GetDefaultGetSystemVersionPath(void);
char *GetDefaultStartUpgradeScript(void);
char *GetDefaultOtaBoardNameScript(void);
char *GetDefaultCertifiedSnScript(void);
char *GetDefaultCertifiedMacScript(void);
char *GetDefaultDeviceModelScript(void);
char *GetDefaultGetSoundSizeScript(void);
char *GetDefaultGetScreenValueScript(void);
char *GetDefaultSystemTimeZoneScript(void);
char *GetDefaultplaySoundScript(void);
char *GetDefaultH264ConvertMp4Script(void);
char *GetDefaultRestartWebrtcScript(void);
char *GetDefaultRestartReportScript(void);
char *GetDefaultLog7zCompressionScript(void);
char *GetDefaultLog7zNoPasswordScript(void);
char *GetDefaultGetMachineSnScript(void);
char *GetDefaultSetMachineSnScript(void);

char *GetDefaultWebrtcPipePath(void);
char *GetDefaultKlipperClientSock(void);
char *GetDefaultKlipperServerSock(void);
char *GetDefaultAiClientSock(void);
char *GetDefaultAiServerSock(void);
char *GetDefaultMcuSwdUpgradeCmd(void);
char *GetDefaultMcuSwdUpgradeProgress(void);
char *GetDefaultRestartKlipperServer(void);

char *GetDefaultSystemRestartPart(void);
char *GetDefaultSystemRestartAll(void);
char *GetDefaultScreenDisplayOff(void);
char *GetDefaultScreenDisplayOn(void);
char *GetLaserTestGcodeFilePath(void);
char *GetLineHeightGcodeFilePath(void);
char *GetLaserAutoTestGcodeFilePath(void);
char *GetLaserCorrectionGcodeFilePath(void);
char *GetLaserCorrectionNewGcodePath(void);
char *GetSourceHanSansFilePath(void);
char *GetHttpKeyFile(void);
char *GetHttpCrtFile(void);
char *GetHttpPemFile(void);
#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif
