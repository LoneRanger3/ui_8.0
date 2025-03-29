/*
 * @Description : 文件管理
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-28 14:52:06
 * @LastEditTime: 2023-10-18 10:59:54
 */

#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/stat.h> 

#include "CrLog.h"
#include "../SystemCmd/SystemCmd.h"
#include "FileManager.h"

#define BUFFER_SIZE     1024
static pthread_mutex_t fielLock; /* 互斥锁定义 */

/**
 * @description: 用户配置文件路径定义
 * @param  {*}
 * @return {*}
 */
static char defaultSystemConfigFilePtah[DEF_PATH_LEN] = {0};
static char defaultSystemVersionFilePtah[DEF_PATH_LEN] = {0};
static char defaultIotConfigFilePtah[DEF_PATH_LEN] = {0};
static char defaultPrintReferFilePtah[DEF_PATH_LEN] = {0};
static char defaultFileIconPtah[DEF_PATH_LEN] = {0};
static char defaultFilePreviewPtah[DEF_PATH_LEN] = {0};
static char defaultFilePrintPhotoPtah[DEF_PATH_LEN] = {0};
static char defaultFolderIconPtah[DEF_PATH_LEN] = {0};
static char defaultErrorCodeMapPtah[DEF_PATH_LEN] = {0};
static char defaultLanguagePtah[DEF_PATH_LEN] = {0};
static char defaultSystemKernelLogPtah[DEF_PATH_LEN] = {0};
static char defaultOverlayUpperPtah[DEF_PATH_LEN] = {0};

/**
 * @description: 用户配置文件路径定义
 * @param  {*}
 * @return {*}
 */
static char userSystemConfigFilePtah[DEF_PATH_LEN] = {0};
static char userSystemVersionFilePtah[DEF_PATH_LEN] = {0};
static char userDataNotDeleteFilePtah[DEF_PATH_LEN] = {0};
static char userIotConfigFilePtah[DEF_PATH_LEN] = {0};
static char userIotTbInfoFilePtah[DEF_PATH_LEN] = {0};
static char userPrintReferFilePtah[DEF_PATH_LEN] = {0};
static char userHttpdConfigFilePath[DEF_PATH_LEN] = {0};
static char userPrintHistoryPtah[DEF_PATH_LEN] = {0};
static char userPrintHistoryRecordPtah[DEF_PATH_LEN] = {0};
static char userPrintHistoryImagePtah[DEF_PATH_LEN] = {0};
static char userDataConfigDirPtah[DEF_PATH_LEN] = {0};
static char userDataLogDirPtah[DEF_PATH_LEN] = {0};
static char userDataLogConfigPtah[DEF_PATH_LEN] = {0};
static char userDataKlipperLogDirPtah[DEF_PATH_LEN] = {0};
static char userAiImageDirPtah[DEF_PATH_LEN] = {0};
static char userAiImageCapturePtah[DEF_PATH_LEN] = {0};
static char userUpgradeDirPtah[DEF_PATH_LEN] = {0};
static char userUpgradeInfoPtah[DEF_PATH_LEN] = {0};
static char userDelayImageH264Ptah[DEF_PATH_LEN] = {0};
static char userDelayImageDirPtah[DEF_PATH_LEN] = {0};
static char userDelayImageInfoPtah[DEF_PATH_LEN] = {0};
static char userDelayImageCoverPtah[DEF_PATH_LEN] = {0};
static char userDelayImageVideoPtah[DEF_PATH_LEN] = {0};
static char userFaultCodeDirPtah[DEF_PATH_LEN] = {0};
static char userFaultCodeInfoPtah[DEF_PATH_LEN] = {0};

static char userTempDirPtah[DEF_PATH_LEN] = {0};
static char userGcodeFileInfoFilePtah[DEF_PATH_LEN] = {0};
static char userMonitorExecuteRunPtah[DEF_PATH_LEN] = {0};
static char userTempThumbnailDirPtah[DEF_PATH_LEN] = {0};
static char userTempOriginalDirPtah[DEF_PATH_LEN] = {0};
static char tempSaveSystemInfoPath[DEF_PATH_LEN] = {0};
static char userTempOriginalPtah[DEF_PATH_LEN] = {0};
static char userCurrentPrintImagePath[DEF_PATH_LEN] = {0};

static char userLocalGcodeInfoDirPtah[DEF_PATH_LEN] = {0};
static char userLocalGcodeFileInfoPtah[DEF_PATH_LEN] = {0};
static char userLocalThumbnailDirPtah[DEF_PATH_LEN] = {0};
static char userLocalOriginalDirPtah[DEF_PATH_LEN] = {0};
static char userUdiskGcodeInfoDirPtah[DEF_PATH_LEN] = {0};
static char userUdiskGcodeFileInfoPtah[DEF_PATH_LEN] = {0};
static char userUdiskThumbnailDirPtah[DEF_PATH_LEN] = {0};
static char userUdiskOriginalDirPtah[DEF_PATH_LEN] = {0};

static char userLocalUdiskPtah[DEF_PATH_LEN] = {0};
static char userLocalSdCardPtah[DEF_PATH_LEN] = {0};
static char cxyDeviceBindingQrCodePtah[DEF_PATH_LEN] = {0};
static char cxyUserServiceQrCodePtah[DEF_PATH_LEN] = {0};
static char deviceCrealityDirPtah[DEF_PATH_LEN] = {0};
static char deviceUserdataDirPtah[DEF_PATH_LEN] = {0};
static char developDebugModePtah[DEF_PATH_LEN] = {0};
static char developStopErrorPtah[DEF_PATH_LEN] = {0};
static char userAgreeRootPolicyPath[DEF_PATH_LEN] = {0};
static char developFactoryTestPtah[DEF_PATH_LEN] = {0};
static char developMachineTestPtah[DEF_PATH_LEN] = {0};
static char savePrinterInfoPtah[DEF_PATH_LEN] = {0};
static char savePrintFileNamePtah[DEF_PATH_LEN] = {0};
static char userPrinterConfigPath[DEF_PATH_LEN] = {0};
static char userPrinterConfigFilePath[DEF_PATH_LEN] = {0};
static char userFactoryConfigFilePath[DEF_PATH_LEN] = {0};
static char userPrinterGcodesFilePath[DEF_PATH_LEN] = {0};
static char mcuSwdUpgradeFilePath[DEF_PATH_LEN] = {0};
static char flowDetectGcodeFilePath[DEF_PATH_LEN] = {0};
static char userAvatarPngPath[DEF_PATH_LEN] = {0};
static char currentWorkInfo[DEF_PATH_LEN] = {0};
static char laserOffsetInfo[DEF_PATH_LEN] = {0};
static char saveZaxisHeight[DEF_PATH_LEN] = {0};
static char deviceStructureConfig[DEF_PATH_LEN] = {0};
static char devicePrintParaConfig[DEF_PATH_LEN] = {0};
static char userDataPath[DEF_PATH_LEN] = {0};
static char machineProductionInfo[DEF_PATH_LEN] = {0};

/**
 * @description: 临时文件
 * @return {*}
 */
static char tempExportLog7z[DEF_PATH_LEN] = {0};
static char tempUserDataDir[DEF_PATH_LEN] = {0};
static char tempUserPointCloudDir[DEF_PATH_LEN] = {0};
static char tempScanTablePoint[DEF_PATH_LEN] = {0};
static char tempScanFirstLayerPoint[DEF_PATH_LEN] = {0};
static char tempGcodeReductionPoint[DEF_PATH_LEN] = {0};
static char tempOffsetCorrectionPoint[DEF_PATH_LEN] = {0};
static char tempOffsetCorrectTablePc[DEF_PATH_LEN] = {0};
static char tempOffsetCorrectScanPc[DEF_PATH_LEN] = {0};
static char tempOffsetCorrectionPointExp1000[DEF_PATH_LEN] = {0};
static char tempOffsetCorrectionPointExp2000[DEF_PATH_LEN] = {0};
static char tempOffsetTablePoint[DEF_PATH_LEN] = {0};
static char tempScanFlowLinePoint[DEF_PATH_LEN] = {0};
static char tempScanFlowTablePoint[DEF_PATH_LEN] = {0};
static char tempScanLinePoint[DEF_PATH_LEN] = {0};
static char tempAutoTestScanLinePoint[DEF_PATH_LEN] = {0};
static char tempAutoTestScanTablePoint[DEF_PATH_LEN] = {0};
static char tempLineHightTablePoint[DEF_PATH_LEN] = {0};
static char tempLineHightLinePoint[DEF_PATH_LEN] = {0};

/**
 * @description: 脚本、管道、本地socket
 * @return {*}
 */
static char defaultGetSysVersionScript[DEF_PATH_LEN] = {0};
static char defaultStartUpgradeScript[DEF_PATH_LEN] = {0};
static char defaultOtaBoardNameScript[DEF_PATH_LEN] = {0};
static char defaultGetCertifiedSnScript[DEF_PATH_LEN] = {0};
static char defaultGetCertifiedMacScript[DEF_PATH_LEN] = {0};
static char defaultGetDeviceModelScript[DEF_PATH_LEN] = {0};
static char defaultGetSoundSizeScript[DEF_PATH_LEN] = {0};
static char defaultGetScreenValueScript[DEF_PATH_LEN] = {0};
static char defaultSystemTimeZoneScript[DEF_PATH_LEN] = {0};
static char defaultplaySoundScript[DEF_PATH_LEN] = {0};
static char defaultH264ConvertMp4Script[DEF_PATH_LEN] = {0};
static char defaultRestartWebrtcScript[DEF_PATH_LEN] = {0};
static char defaultRestartReportScript[DEF_PATH_LEN] = {0};
static char defaultLog7zCompressionScript[DEF_PATH_LEN] = {0};
static char defaultLog7zNoPasswordScript[DEF_PATH_LEN] = {0};
static char defaultGetMachineSnScript[DEF_PATH_LEN] = {0};
static char defaultSetMachineSnScript[DEF_PATH_LEN] = {0};

static char defaultWebrtcPipe[DEF_PATH_LEN] = {0};
static char defaultKlipperClientSock[DEF_PATH_LEN] = {0};
static char defaultKlipperServerSock[DEF_PATH_LEN] = {0};
static char defaultAiClientSock[DEF_PATH_LEN] = {0};
static char defaultAiServerSock[DEF_PATH_LEN] = {0};
static char defaultMcuSwdUpgradeCmd[DEF_PATH_LEN] = {0};
static char defaultMcuSwdUpgradeProgress[DEF_PATH_LEN] = {0};
static char defaultRestartKlipperServer[DEF_PATH_LEN] = {0};

static char defaultSystemRestartPart[DEF_PATH_LEN] = {0};
static char defaultSystemRestartAll[DEF_PATH_LEN] = {0};
static char defaultScreenDisplayOff[DEF_PATH_LEN] = {0};
static char defaultScreenDisplayOn[DEF_PATH_LEN] = {0};

static char laserTestGcodeFilePath[DEF_PATH_LEN] = {0};
static char laserAutoTestGcodeFilePath[DEF_PATH_LEN] = {0};
static char laserCorrectionGcodeFilePath[DEF_PATH_LEN] = {0};
static char laserCorrectionNewGcodePath[DEF_PATH_LEN] = {0};
static char lineHeightGcodePath[DEF_PATH_LEN] = {0};
static char sourceHanSansFilePath[DEF_PATH_LEN] = {0};
static char uiResourceK1Path[DEF_PATH_LEN] = {0};
static char uiResourceK1MaxPath[DEF_PATH_LEN] = {0};

static char defaultHttpKeyFile[DEF_PATH_LEN] = {0};
static char defaultHttpCrtFile[DEF_PATH_LEN] = {0};
static char defaultHttpPemFile[DEF_PATH_LEN] = {0};
/**
 * @description: 
 * @param  {*}
 * @return {*}
 */
int FileManagerInit(void)
{
    pthread_mutex_init(&fielLock, NULL);

    // 初始化路径
    snprintf(defaultSystemConfigFilePtah, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, SYSTEM_COMFIG_FILE);
    snprintf(defaultSystemVersionFilePtah, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, SYSTEM_VERSION_FILE);
    snprintf(defaultIotConfigFilePtah, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, IOT_CONFIG_FILE);
    snprintf(defaultPrintReferFilePtah, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, USER_PRINT_REFER_FILE);
    snprintf(defaultFileIconPtah, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, DEF_DATA_FILE_ICON);
    snprintf(defaultFilePreviewPtah, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, DEF_DATA_FILE_PREVIEW);
    snprintf(defaultFilePrintPhotoPtah, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, DEF_DATA_FILE_PRINT_PHOTO);
    snprintf(defaultFolderIconPtah, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, DEF_DATA_FOLDER_ICON);
    snprintf(defaultErrorCodeMapPtah, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, DEF_DATA_ERROR_CODE_MAP);
    snprintf(defaultLanguagePtah, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, USER_DATA_LANGUAGE);
    snprintf(flowDetectGcodeFilePath, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, FLOW_DETECT_GCODE_FILE);
    snprintf(laserTestGcodeFilePath, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, LASER_TEST_GCODE_FILE);
    snprintf(laserAutoTestGcodeFilePath, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, AUTO_LASER_TEST_GCODE_FILE);
    snprintf(laserCorrectionGcodeFilePath, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, LASER_CORRECTION_GCODE_FILE);
    snprintf(laserCorrectionNewGcodePath, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, LASER_CORRECTION_0_2MM_GCODE);
    snprintf(lineHeightGcodePath, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, LINE_HEIGHT_GCODE_FILE);
    snprintf(sourceHanSansFilePath, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, FONT_SOURCE_HAN_SANS_FILE);
    snprintf(uiResourceK1Path, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, K1_IMAGE_SOURCE_PATH);
    snprintf(uiResourceK1MaxPath, DEF_PATH_LEN, "%s/%s", DEF_CONGFIG_DIR, K1MAX_IMAGE_SOURCE_PATH);
    snprintf(defaultSystemKernelLogPtah, DEF_PATH_LEN, "%s", SYSTEM_KERNEL_LOG_DIR);
    snprintf(defaultOverlayUpperPtah, DEF_PATH_LEN, "%s", SYSTEM_OVERLAY_UPPER_DIR);

    snprintf(userDataConfigDirPtah, DEF_PATH_LEN, "%s/%s", USER_DATA_DIR, USER_DATA_CONFIG_DIR);
    snprintf(userDataLogDirPtah, DEF_PATH_LEN, "%s/%s/", USER_DATA_DIR, USER_DATA_LOG_DIR);
    snprintf(userDataLogConfigPtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_LOG_DIR, USER_DATA_LOG_CONFIG);
    snprintf(userDataKlipperLogDirPtah, DEF_PATH_LEN, "%s/%s/", USER_DATA_DIR, USER_DATA_KLIPPER_LOG_DIR);
    snprintf(userAiImageDirPtah, DEF_PATH_LEN, "%s/%s", USER_DATA_DIR, AI_DETECT_IMAGE_DIR);
    snprintf(userAiImageCapturePtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, AI_DETECT_IMAGE_DIR, AI_MAIN_CAPTURE_JPG);
    snprintf(userUpgradeDirPtah, DEF_PATH_LEN, "%s/%s/", USER_DATA_DIR, USER_UPGRADE_FILE_DIR);
    snprintf(userUpgradeInfoPtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_UPGRADE_FILE_DIR, USER_UPGRADE_INFO_FILE);
    snprintf(userDelayImageH264Ptah, DEF_PATH_LEN, "%s/%s", USER_DATA_DIR, USER_DELAY_IMAGE_H264);
    snprintf(userDelayImageDirPtah, DEF_PATH_LEN, "%s/%s", USER_DATA_DIR, USER_DELAY_IMAGE_DIR);
    snprintf(userDelayImageInfoPtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DELAY_IMAGE_DIR, DELAY_IMAGE_INFO);
    snprintf(userDelayImageCoverPtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DELAY_IMAGE_DIR, USER_TEMP_COVER_DIR);
    snprintf(userDelayImageVideoPtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DELAY_IMAGE_DIR, USER_TEMP_VIDEO_DIR);
    snprintf(userFaultCodeDirPtah, DEF_PATH_LEN, "%s/%s", USER_DATA_DIR, USER_FAULT_CODE_DIR);
    snprintf(userFaultCodeInfoPtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_FAULT_CODE_DIR, FAULT_CODE_INFO);

    snprintf(userSystemConfigFilePtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_CONFIG_DIR, SYSTEM_COMFIG_FILE);
    snprintf(userSystemVersionFilePtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_CONFIG_DIR, SYSTEM_VERSION_FILE);
    snprintf(userDataNotDeleteFilePtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_CONFIG_DIR, USER_DATA_NOT_DELETED);
    snprintf(userIotConfigFilePtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_CONFIG_DIR, IOT_CONFIG_FILE);
    snprintf(userIotTbInfoFilePtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_CONFIG_DIR, IOT_TB_INFO_FILE);
    snprintf(userPrintReferFilePtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_CONFIG_DIR, USER_PRINT_REFER_FILE);
    snprintf(userHttpdConfigFilePath, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_CONFIG_DIR, HTTPD_CONFIG_FILE);
    snprintf(userPrintHistoryPtah, DEF_PATH_LEN, "%s/%s", USER_DATA_DIR, USER_DATA_HISTORY_DIR);
    snprintf(userPrintHistoryRecordPtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_HISTORY_DIR, PRINT_HISTORY_RECORD);
    snprintf(userPrintHistoryImagePtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_HISTORY_DIR, USER_TEMP_THUMBNAIL_DIR);

    snprintf(userTempDirPtah, DEF_PATH_LEN, "%s", USER_TEMP_DIR);
    snprintf(userMonitorExecuteRunPtah, DEF_PATH_LEN, "%s/%s", USER_TEMP_DIR, MONITOR_EXECUTE_RUN);
    snprintf(developFactoryTestPtah, DEF_PATH_LEN, "%s/%s", USER_TEMP_DIR, FACTORY_TEST_FILE);
    snprintf(developMachineTestPtah, DEF_PATH_LEN, "%s/%s", USER_TEMP_DIR, MACHINE_TEST_FILE);
    snprintf(userGcodeFileInfoFilePtah, DEF_PATH_LEN, "%s/%s", USER_TEMP_DIR, GCODE_FILE_INFO_FILE);
    snprintf(userTempThumbnailDirPtah, DEF_PATH_LEN, "%s/%s", USER_TEMP_DIR, USER_TEMP_THUMBNAIL_DIR);
    snprintf(userTempOriginalDirPtah, DEF_PATH_LEN, "%s/%s", USER_TEMP_DIR, USER_TEMP_ORIGINAL_DIR);
    snprintf(tempSaveSystemInfoPath, DEF_PATH_LEN, "%s/%s", USER_TEMP_DIR, TEMP_SAVE_SYSTEM_INFO_FILE);
    snprintf(userTempOriginalPtah, DEF_PATH_LEN, "%s/%s/%s", USER_TEMP_DIR, USER_TEMP_ORIGINAL_DIR, USER_TEMP_IMAGE_FILE);
    snprintf(userCurrentPrintImagePath, DEF_PATH_LEN, "%s/%s/%s", USER_TEMP_DIR, USER_TEMP_ORIGINAL_DIR, CUR_PRINT_IMAGE_FILE);

    snprintf(userLocalGcodeInfoDirPtah, DEF_PATH_LEN, "%s/%s", USER_TEMP_DIR, USER_LOCAL_GCODE_DIR);
    snprintf(userLocalGcodeFileInfoPtah, DEF_PATH_LEN, "%s/%s/%s", USER_TEMP_DIR, USER_LOCAL_GCODE_DIR, LOCAL_GCODE_FILE_INFO);
    snprintf(userLocalThumbnailDirPtah, DEF_PATH_LEN, "%s/%s/%s", USER_TEMP_DIR, USER_LOCAL_GCODE_DIR, USER_TEMP_THUMBNAIL_DIR);
    snprintf(userLocalOriginalDirPtah, DEF_PATH_LEN, "%s/%s/%s", USER_TEMP_DIR, USER_LOCAL_GCODE_DIR, USER_TEMP_ORIGINAL_DIR);

    snprintf(userUdiskGcodeInfoDirPtah, DEF_PATH_LEN, "%s/%s", USER_TEMP_DIR, USER_UDISK_GCODE_DIR);
    snprintf(userUdiskGcodeFileInfoPtah, DEF_PATH_LEN, "%s/%s/%s", USER_TEMP_DIR, USER_UDISK_GCODE_DIR, UDISK_GCODE_FILE_INFO);
    snprintf(userUdiskThumbnailDirPtah, DEF_PATH_LEN, "%s/%s/%s", USER_TEMP_DIR, USER_UDISK_GCODE_DIR, USER_TEMP_THUMBNAIL_DIR);
    snprintf(userUdiskOriginalDirPtah, DEF_PATH_LEN, "%s/%s/%s", USER_TEMP_DIR, USER_UDISK_GCODE_DIR, USER_TEMP_ORIGINAL_DIR);

    snprintf(userLocalUdiskPtah, DEF_PATH_LEN, "%s", USER_LOCAL_U_DISK_PATH);
    snprintf(userLocalSdCardPtah, DEF_PATH_LEN, "%s", USER_LOCAL_SD_CARD_PATH);
    snprintf(cxyDeviceBindingQrCodePtah, DEF_PATH_LEN, "%s/%s", USER_TEMP_DIR, USER_BIND_DEV_QRCODE);
    snprintf(cxyUserServiceQrCodePtah, DEF_PATH_LEN, "%s/%s", USER_TEMP_DIR, USER_SERVICE_QRCODE);
    snprintf(deviceCrealityDirPtah, DEF_PATH_LEN, "%s/%s/", USER_DATA_DIR, DEVICE_CREALITY_DIR);
    snprintf(deviceUserdataDirPtah, DEF_PATH_LEN, "%s/%s/", USER_DATA_DIR, USER_DATA_CREALITY_DIR);
    snprintf(developDebugModePtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_CREALITY_DIR, DEVELOP_DEBUG_MODE_FILE);
    snprintf(developStopErrorPtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_CREALITY_DIR, DEVELOP_STOP_ERROR_FILE);
    snprintf(userAgreeRootPolicyPath, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_CREALITY_DIR, AGREE_ROOT_POLICY);
    snprintf(savePrinterInfoPtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_CONFIG_DIR, PRINTER_INFO_FILE);
    snprintf(savePrintFileNamePtah, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_CONFIG_DIR, PRINTER_FILE_NAME);
    snprintf(userPrinterConfigPath, DEF_PATH_LEN, "%s/%s", USER_DATA_DIR, USER_DATA_KLIPPER_CONFIG_DIR);
    snprintf(userPrinterConfigFilePath, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_KLIPPER_CONFIG_DIR, PRINTER_CONFIG_FILE);
    snprintf(userFactoryConfigFilePath, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_KLIPPER_CONFIG_DIR, FACTORY_CONFIG_FILE);
    snprintf(userPrinterGcodesFilePath, DEF_PATH_LEN, "%s/%s", USER_DATA_DIR, USER_DATA_KLIPPER_GCODES_DIR);
    snprintf(mcuSwdUpgradeFilePath, DEF_PATH_LEN, "%s/%s", USER_DATA_DIR, MCU_SWD_UPGRADE_FILE);
    snprintf(userAvatarPngPath, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_CONFIG_DIR, USER_AVATAR_PNG);
    snprintf(currentWorkInfo, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_CONFIG_DIR, CURRENT_WORK_INFO);
    snprintf(laserOffsetInfo, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_CONFIG_DIR, LASER_OFFSET_INFO);
    snprintf(saveZaxisHeight, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_CONFIG_DIR, SAVE_Z_AXIS_HEIGHT);
    snprintf(deviceStructureConfig, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_CONFIG_DIR, DEVICE_STRUCTURE_CONFIG);
    snprintf(devicePrintParaConfig, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_CONFIG_DIR, PRINT_PARA_CONFIG);
    snprintf(userDataPath, DEF_PATH_LEN, "%s", USER_DATA_DIR);
    snprintf(machineProductionInfo, DEF_PATH_LEN, "%s/%s", USER_DATA_DIR, MACHINE_PRODUCTION_INFO);

    // 临时文件
    snprintf(tempExportLog7z, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_DATA_LOG_DIR, EXPORT_LOG_7Z);
    snprintf(tempUserDataDir, DEF_PATH_LEN, "%s/%s/", USER_DATA_DIR, USER_TMP_FILE_DIR);
    snprintf(tempUserPointCloudDir, DEF_PATH_LEN, "%s/%s/", USER_DATA_DIR, USER_TMP_POINT_CLOUD_DIR);
    snprintf(tempScanTablePoint, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_TMP_POINT_CLOUD_DIR, SCAN_TABLE_POINT_TEMP);
    snprintf(tempScanFirstLayerPoint, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_TMP_POINT_CLOUD_DIR, SCAN_FIRST_LAYER_POINT_TEMP);
    snprintf(tempGcodeReductionPoint, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_TMP_POINT_CLOUD_DIR, GCODE_REDUCTION_POINT_TEMP);
    snprintf(tempOffsetCorrectionPoint, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_TMP_POINT_CLOUD_DIR, OFFSET_CORRECTION_POINT_TEMP);
    snprintf(tempOffsetCorrectTablePc, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_TMP_POINT_CLOUD_DIR, OFFSET_CORRECTION_02MM_TABLE_PC_TEMP);
    snprintf(tempOffsetCorrectScanPc, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_TMP_POINT_CLOUD_DIR, OFFSET_CORRECTION_02MM_SCAN_PC_TEMP);
    snprintf(tempOffsetCorrectionPointExp1000, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_TMP_POINT_CLOUD_DIR, OFFSET_CORRECTION_EXP1000_POINT_TEMP);
    snprintf(tempOffsetCorrectionPointExp2000, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_TMP_POINT_CLOUD_DIR, OFFSET_CORRECTION_EXP2000_POINT_TEMP);
    snprintf(tempOffsetTablePoint, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_TMP_POINT_CLOUD_DIR, OFFSET_TABLE_POINT_TEMP);
    snprintf(tempScanFlowTablePoint, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_TMP_POINT_CLOUD_DIR, SCAN_FLOW_TABLE_POINT_TEMP);
    snprintf(tempScanFlowLinePoint, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_TMP_POINT_CLOUD_DIR, SCAN_FLOW_LINE_POINT_TEMP);
    snprintf(tempScanLinePoint, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_TMP_POINT_CLOUD_DIR, SCAN_LINE_POINT_TEMP);
    snprintf(tempAutoTestScanTablePoint, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_TMP_POINT_CLOUD_DIR, AUTO_TEST_SCAN_TABLE_POINT_TEMP);
    snprintf(tempAutoTestScanLinePoint, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_TMP_POINT_CLOUD_DIR, AUTO_TEST_SCAN_LINE_POINT_TEMP);
    snprintf(tempLineHightTablePoint, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_TMP_POINT_CLOUD_DIR, LINE_HIGHT_TABLE_POINT_CLOUD_TEMP);
    snprintf(tempLineHightLinePoint, DEF_PATH_LEN, "%s/%s/%s", USER_DATA_DIR, USER_TMP_POINT_CLOUD_DIR, LINE_HIGHT_LINE_POINT_CLOUD_TEMP);
    // 脚本、管道、本地socket
    snprintf(defaultGetSysVersionScript, DEF_PATH_LEN, "%s/%s", DEF_OTA_DIR, USER_GET_SYSTEM_VERSION);
    snprintf(defaultStartUpgradeScript, DEF_PATH_LEN, "%s/%s", DEF_OTA_DIR, USER_START_UPGRADE);
    snprintf(defaultOtaBoardNameScript, DEF_PATH_LEN, "%s/%s", DEF_OTA_DIR, GET_OTA_BOARD_NAME);
    snprintf(defaultGetSoundSizeScript, DEF_PATH_LEN, "%s", GET_SYSTEN_SOUND_SIZE);
    snprintf(defaultGetScreenValueScript, DEF_PATH_LEN, "%s", GET_SYSTEN_SCREEN_VALUE);
    snprintf(defaultH264ConvertMp4Script, DEF_PATH_LEN, "%s", H264_CONVERT_MP4_CMD);
    snprintf(defaultGetCertifiedSnScript, DEF_PATH_LEN, "%s", GET_SYS_CERTIFIED_SN);
    snprintf(defaultGetCertifiedMacScript, DEF_PATH_LEN, "%s", GET_SYS_CERTIFIED_MAC);
    snprintf(defaultGetDeviceModelScript, DEF_PATH_LEN, "%s", GET_SYS_DEVICE_MODEL);
    snprintf(defaultGetSoundSizeScript, DEF_PATH_LEN, "%s", GET_SYSTEN_SOUND_SIZE);
    snprintf(defaultGetScreenValueScript, DEF_PATH_LEN, "%s", GET_SYSTEN_SCREEN_VALUE);
    snprintf(defaultSystemTimeZoneScript, DEF_PATH_LEN, "%s", SYSTEN_TIME_ZONE);
    snprintf(defaultplaySoundScript, DEF_PATH_LEN, "%s", PLAY_SOUND_CMD);
    snprintf(defaultH264ConvertMp4Script, DEF_PATH_LEN, "%s", H264_CONVERT_MP4_CMD);
    snprintf(defaultRestartWebrtcScript, DEF_PATH_LEN, "%s", RESTART_WEBRTC);
    snprintf(defaultRestartReportScript, DEF_PATH_LEN, "%s", RESTART_REPORT);
    snprintf(defaultLog7zCompressionScript, DEF_PATH_LEN, "%s", LOG_7Z_COMPRESSION);
    snprintf(defaultLog7zNoPasswordScript, DEF_PATH_LEN, "%s", LOG_7Z_NO_PASSWORD);
    snprintf(defaultGetMachineSnScript, DEF_PATH_LEN, "%s", GET_MACHINE_SN);
    snprintf(defaultSetMachineSnScript, DEF_PATH_LEN, "%s", SET_MACHINE_SN);

    snprintf(defaultWebrtcPipe, DEF_PATH_LEN, "%s", WEBRTC_PIPE_FILE);
    snprintf(defaultKlipperClientSock, DEF_PATH_LEN, "%s", KLIPPER_CLIENT_SOCK);
    snprintf(defaultKlipperServerSock, DEF_PATH_LEN, "%s", KLIPPER_SERVER_SOCK);
    snprintf(defaultAiClientSock, DEF_PATH_LEN, "%s", AI_CLIENT_SOCKET);
    snprintf(defaultAiServerSock, DEF_PATH_LEN, "%s", AI_SERVER_SOCKET);
    snprintf(defaultMcuSwdUpgradeCmd, DEF_PATH_LEN, "%s", MCU_SWD_UPGRADE_CMD);
    snprintf(defaultMcuSwdUpgradeProgress, DEF_PATH_LEN, "%s", MCU_SWD_UPGRADE_PROGRESS);
    snprintf(defaultRestartKlipperServer, DEF_PATH_LEN, "%s", RESTART_KLIPPER_SERVER);

    snprintf(defaultSystemRestartPart, DEF_PATH_LEN, "%s", SYSTEM_RESTART_PART);
    snprintf(defaultSystemRestartAll, DEF_PATH_LEN, "%s", SYSTEM_RESTART_ALL);
    snprintf(defaultScreenDisplayOff, DEF_PATH_LEN, "%s", SCREEN_DISPLAY_OFF);
    snprintf(defaultScreenDisplayOn, DEF_PATH_LEN, "%s", SCREEN_DISPLAY_ON);

    snprintf(defaultHttpKeyFile, DEF_PATH_LEN, "%s/%s", USER_SHARE_HTTPS_CERT_DIR, USER_HTTP_CERT_KEY);
    snprintf(defaultHttpCrtFile, DEF_PATH_LEN, "%s/%s", USER_SHARE_HTTPS_CERT_DIR, USER_HTTP_CERT_CRT);
    snprintf(defaultHttpPemFile, DEF_PATH_LEN, "%s/%s", USER_SHARE_HTTPS_CERT_DIR, USER_HTTP_CERT_PEM);

    // 创建文件夹
    if (access(GetTempUserPointCloudDir(), F_OK) != 0) {
        char cmd[254] = {0};
        snprintf(cmd, 254, "mkdir -p %s", GetTempUserPointCloudDir());

        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
    }
    if (access(GetUserTempDirPtah(), F_OK) != 0)
    {
        char cmd[254] = {0};
        snprintf(cmd, 254, "mkdir -p %s", GetUserTempDirPtah());
        
        // 调用系统命令
        char sysRes[1024] = {0};
        if (!PopenSystem(cmd, sysRes, sizeof(sysRes)))
            CrLogW("system fail! res = %s\n", sysRes);
    }

    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *filePath
 * @param {char} *data
 * @param {int} len
 */
unsigned int SaveConfigToFile(char *filePath, char *data, int len)
{
    pthread_mutex_lock(&fielLock);

    // 打开文件
    FILE* file = fopen(filePath, "wb");
    if (file == NULL) {
        CrLogW("open '%s' file fail\n", filePath);
        goto SET_FILE_ERR;
    }
    
    size_t writeTotal = 0;
    size_t writeBytes = 0;
    size_t readyWriteBytes = len < BUFFER_SIZE ? len : BUFFER_SIZE;

    // 开始循环写入数据
    while ((writeBytes = fwrite(&data[writeTotal], 1, readyWriteBytes, file)) > 0) {
        writeTotal += writeBytes;
        if (writeTotal >= len) break;
        readyWriteBytes = (len - writeTotal) < BUFFER_SIZE ? (len - writeTotal) : BUFFER_SIZE;
    }
    
    // 写入结束，释放资源
    fflush(file);
    fsync(fileno(file));
    fclose(file);
    pthread_mutex_unlock(&fielLock);
    return writeTotal;

SET_FILE_ERR:
    if (file) fclose(file);
    pthread_mutex_unlock(&fielLock);
    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *filePath
 * @param {char} *data
 * @param {int} len
 */
unsigned int GetConfigFromFile(char *filePath, char *data, int len)
{
    pthread_mutex_lock(&fielLock);

    // 打开文件
    FILE* file = fopen(filePath, "rb");
    if (file == NULL) {
        CrLogW("open '%s' file fail\n", filePath);
        goto GET_FILE_ERR;
    }
    
    char buffer[BUFFER_SIZE];
    size_t readTotal = 0;
    size_t readBytes = 0;
    
    // 开始循环读取数据
    while ((readBytes = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        if ((readTotal + readBytes) >= len)
        {
            int cpySize = len - 1 - readTotal;
            memcpy(&data[readTotal], buffer, cpySize);
            readTotal += cpySize;
            break;
        }

        memcpy(&data[readTotal], buffer, readBytes);
        bzero(buffer, BUFFER_SIZE);
        readTotal += readBytes;
    }
    data[readTotal] = '\0';

    // 读取结束，释放资源
    fclose(file);
    pthread_mutex_unlock(&fielLock);
    return readTotal;

GET_FILE_ERR:
    if (file) fclose(file);
    pthread_mutex_unlock(&fielLock);
    return -1;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *fileName
 */
size_t GetUserFileSize(const char *fileName)
{
    // 判断路径是否为空
	if (fileName == NULL) return 0;

	// 这是一个存储文件(夹)信息的结构体，其中有文件大小和创建时间、访问时间、修改时间等
	struct stat statbuf;
	stat(fileName, &statbuf);
	
	// 获取文件大小
	size_t filesize = statbuf.st_size;
	return filesize;
}

/**
 * @description: 获取默认配置文件路径
 * @param  {*}
 * @return {*}
 */
char *GetDefaultSystemConfigFilePath(void) { return defaultSystemConfigFilePtah; }
char *GetDefaultSystemVersionFilePath(void) { return defaultSystemVersionFilePtah; }
char *GetDefaultIotConfigPath(void) { return defaultIotConfigFilePtah; }
char *GetDefaultPrintReferFilePath(void) { return defaultPrintReferFilePtah; }
char *GetDefaultFileIconPtah(void) { return defaultFileIconPtah; }
char *GetDefaultFilePreviewPtah(void) { return defaultFilePreviewPtah; }
char *GetDefaultFilePrintPhotoPtah(void) { return defaultFilePrintPhotoPtah; }
char *GetDefaultFolderIconPtah(void) { return defaultFolderIconPtah; }
char *GetDefaultErrorCodeMapPtah(void) { return defaultErrorCodeMapPtah; }
char *GetDefaultLanguagePtah(void) { return defaultLanguagePtah; }
char *GetDefaultSystemKernelLogPtah(void) { return defaultSystemKernelLogPtah; }
char *GetDefaultOverlayUpperPtah(void) { return defaultOverlayUpperPtah; }

/**
 * @description: 获取用户配置文件路径
 * @param  {*}
 * @return {*}
 */
char *GetUserSystemConfigFilePath(void) { return userSystemConfigFilePtah; }
char *GetUserSystemVersionFilePath(void) { return userSystemVersionFilePtah; }
char *GetUserDataNotDeleteFilePtah(void) { return userDataNotDeleteFilePtah; }
char *GetUserIotConfigPath(void) { return userIotConfigFilePtah; }
char *GetUserIotTbInfoFilePtah(void) { return userIotTbInfoFilePtah; }
char *GetUserPrintReferFilePath(void) { return userPrintReferFilePtah; }
char *GetUserHttpdConfigFilePath(void) { return userHttpdConfigFilePath; }
char *GetuserPrintHistoryPtah(void) { return userPrintHistoryPtah; }
char *GetuserPrintHistoryRecordPtah(void) { return userPrintHistoryRecordPtah; }
char *GetuserPrintHistoryImagePtah(void) { return userPrintHistoryImagePtah; }
char *GetUserDataConfigDirPtah(void) { return userDataConfigDirPtah; }
char *GetUserDataLogDirPtah(void) { return userDataLogDirPtah; }
char *GetUserDataLogConfigPtah(void) { return userDataLogConfigPtah; }
char *GetUserDataKlipperLogDirPtah(void) { return userDataKlipperLogDirPtah; }
char *GetUserAiImageDirPtah(void) { return userAiImageDirPtah; }
char *GetUserAiImageCapturePtah(void) { return userAiImageCapturePtah; }
char *GetUserUpgradeDirPtah(void) { return userUpgradeDirPtah; }
char *GetUserUpgradeInfoPtah(void) { return userUpgradeInfoPtah; }
char *GetUserDelayImageH264Ptah(void) { return userDelayImageH264Ptah; }
char *GetUserDelayImageDirPtah(void) { return userDelayImageDirPtah; }
char *GetUserDelayImageInfoPtah(void) { return userDelayImageInfoPtah; }
char *GetUserDelayImageCoverPtah(void) { return userDelayImageCoverPtah; }
char *GetUserDelayImageVideoPtah(void) { return userDelayImageVideoPtah; }
char *GetUserFaultCodeDirPtah(void) { return userFaultCodeDirPtah; }
char *GetUserFaultCodeInfoPtah(void) { return userFaultCodeInfoPtah; }

char *GetUserTempDirPtah(void) { return userTempDirPtah; }
char *GetUserMonitorExecuteRunPtah(void) { return userMonitorExecuteRunPtah; }
char *GetUserGcodeFileInfoFilePath(void) { return userGcodeFileInfoFilePtah; }
char *GetUserTempThumbnailDirPtah(void) { return userTempThumbnailDirPtah; }
char *GetUserTempOriginalDirPtah(void) { return userTempOriginalDirPtah; }
char *GetTempSaveSystemInfoPath(void) { return tempSaveSystemInfoPath; }
char *GetUserTempOriginalPtah(void) { return userTempOriginalPtah; }
char *GetUserCurrentPrintImagePath(void) { return userCurrentPrintImagePath; }

char *GetUserLocalGcodeInfoDirPtah(void) { return userLocalGcodeInfoDirPtah; }
char *GetUserLocalGcodeFileInfoPtah(void) { return userLocalGcodeFileInfoPtah; }
char *GetUserLocalThumbnailDirPtah(void) { return userLocalThumbnailDirPtah; }
char *GetUserLocalOriginalDirPtah(void) { return userLocalOriginalDirPtah; }
char *GetUserUdiskGcodeInfoDirPtah(void) { return userUdiskGcodeInfoDirPtah; }
char *GetUserUdiskGcodeFileInfoPtah(void) { return userUdiskGcodeFileInfoPtah; }
char *GetUserUdiskThumbnailDirPtah(void) { return userUdiskThumbnailDirPtah; }
char *GetUserUdiskOriginalDirPtah(void) { return userUdiskOriginalDirPtah; }

char *GetUserLocalUdiskPtah(void) { return userLocalUdiskPtah; }
char *GetUserLocalSdCardPtah(void) { return userLocalSdCardPtah; }
char *GetCxyDeviceBindingQrCodePtah(void) { return cxyDeviceBindingQrCodePtah; }
char *GetCxyUserServiceQrCodePtah(void) { return cxyUserServiceQrCodePtah; }
char *GetDeviceCrealityDirPtah(void) { return deviceCrealityDirPtah; }
char *GetDeviceUserdataDirPtah(void) { return deviceUserdataDirPtah; }
char *GetDevelopDebugModePtah(void) { return developDebugModePtah; }
char *GetDevelopStopErrorPtah(void) { return developStopErrorPtah; }
char *GetUserAgreeRootPolicyPath(void) { return userAgreeRootPolicyPath; }
char *GetDevelopFactoryTestPtah(void) { return developFactoryTestPtah; }
char *GetDevelopMachineTestPtah(void) { return developMachineTestPtah; }
char *GetSavePrinterInfoPtah(void) { return savePrinterInfoPtah; }
char *GetSavePrintFileNamePtah(void) { return savePrintFileNamePtah; }
char *GetUserPrinterConfigPath(void) { return userPrinterConfigPath; }
char *GetUserPrinterConfigFilePath(void) { return userPrinterConfigFilePath; }
char *GetUserFactoryConfigFilePath(void) { return userFactoryConfigFilePath; }
char *GetUserPrinterGcodesFilePath(void) { return userPrinterGcodesFilePath; }
char *GetMcuSwdUpgradeFilePath(void) { return mcuSwdUpgradeFilePath; }
char *GetFlowDetectGcodeFilePath(void) { return flowDetectGcodeFilePath; }
char *GetUserAvatarPngPath(void) { return userAvatarPngPath; }
char *GetCurrentWorkInfo(void) { return currentWorkInfo; }
char *GetLaserOffsetInfo(void) { return laserOffsetInfo; }
char *GetSaveZaxisHeight(void) { return saveZaxisHeight; }
char *GetDeviceStructureConfig(void) { return deviceStructureConfig; }
char *GetDevicePrintParaConfig(void) { return devicePrintParaConfig; }
char *GetUserDataPath(void) { return userDataPath; }
char *GetMachineProductionInfo(void) { return machineProductionInfo; }
char *GetLaserTestGcodeFilePath(void) { return laserTestGcodeFilePath; }
char *GetLaserAutoTestGcodeFilePath(void) { return laserAutoTestGcodeFilePath; }
char *GetLaserCorrectionGcodeFilePath(void) { return laserCorrectionGcodeFilePath; }
char *GetLaserCorrectionNewGcodePath(void) { return laserCorrectionNewGcodePath; }
char *GetLineHeightGcodeFilePath(void) { return lineHeightGcodePath; }
char *GetSourceHanSansFilePath(void) { return sourceHanSansFilePath; }
char *GetK1ImageResourcePtah(void) { return uiResourceK1Path; }
char *GetK1MaxImageResourcePtah(void) { return uiResourceK1MaxPath; }


/**
 * @description: 临时文件
 * @return {*}
 */
char *GetTempExportLog7z(void) { return tempExportLog7z; }
char *GetTempUserDataDir(void) { return tempUserDataDir; }
char *GetTempUserPointCloudDir(void) { return tempUserPointCloudDir; }
char *GetTempScanTablePoint(void) { return tempScanTablePoint; }
char *GetTempScanFirstLayerPoint(void) { return tempScanFirstLayerPoint; }
char *GetTempGcodeReductionPoint(void) { return tempGcodeReductionPoint; }
char *GetTempOffsetCorrectionPoint(void) { return tempOffsetCorrectionPoint; }
char *GetTempOffsetCorrect02mmTablePc(void) { return tempOffsetCorrectTablePc; }
char *GetTempOffsetCorrect02mmScanPc(void) { return tempOffsetCorrectScanPc; }
char *GetTempOffsetCorrectionPointExp1000(void) { return tempOffsetCorrectionPointExp1000; }
char *GetTempOffsetCorrectionPointExp2000(void) { return tempOffsetCorrectionPointExp2000; }
char *GetTempOffsetTablePoint(void) { return tempOffsetTablePoint; }
char *GetTempScanFlowTbalePoint(void) { return tempScanFlowTablePoint; }
char *GetTempScanFlowLinePoint(void) { return tempScanFlowLinePoint; }
char *GetTempScanLinePoint(void) { return tempScanLinePoint; }
char *GetTempAutoTestScanTablePoint(void) { return tempAutoTestScanTablePoint; }
char *GetTempAutoTestScanLinePoint(void) { return tempAutoTestScanLinePoint; }
char *GetTempLineHeightTablePoint(void) { return tempLineHightTablePoint; }
char *GetTempLineHeightLinePoint(void) { return tempLineHightLinePoint; }
/**
 * @description: 脚本、管道、本地socket
 * @return {*}
 */
char *GetDefaultGetSystemVersionPath(void) {return defaultGetSysVersionScript;}
char *GetDefaultStartUpgradeScript(void) {return defaultStartUpgradeScript;}
char *GetDefaultOtaBoardNameScript(void) {return defaultOtaBoardNameScript;}
char *GetDefaultCertifiedSnScript(void) {return defaultGetCertifiedSnScript;}
char *GetDefaultCertifiedMacScript(void) {return defaultGetCertifiedMacScript;}
char *GetDefaultDeviceModelScript(void) {return defaultGetDeviceModelScript;}
char *GetDefaultGetSoundSizeScript(void) {return defaultGetSoundSizeScript;}
char *GetDefaultGetScreenValueScript(void) {return defaultGetScreenValueScript;}
char *GetDefaultSystemTimeZoneScript(void) {return defaultSystemTimeZoneScript;}
char *GetDefaultplaySoundScript(void) {return defaultplaySoundScript;}
char *GetDefaultH264ConvertMp4Script(void) {return defaultH264ConvertMp4Script;}
char *GetDefaultRestartWebrtcScript(void) {return defaultRestartWebrtcScript;}
char *GetDefaultRestartReportScript(void) {return defaultRestartReportScript;}
char *GetDefaultLog7zCompressionScript(void) {return defaultLog7zCompressionScript;}
char *GetDefaultLog7zNoPasswordScript(void) {return defaultLog7zNoPasswordScript;}
char *GetDefaultGetMachineSnScript(void) {return defaultGetMachineSnScript;}
char *GetDefaultSetMachineSnScript(void) {return defaultSetMachineSnScript;}

char *GetDefaultWebrtcPipePath(void) {return defaultWebrtcPipe;}
char *GetDefaultKlipperClientSock(void) {return defaultKlipperClientSock;}
char *GetDefaultKlipperServerSock(void) {return defaultKlipperServerSock;}
char *GetDefaultAiClientSock(void) {return defaultAiClientSock;}
char *GetDefaultAiServerSock(void) {return defaultAiServerSock;}
char *GetDefaultMcuSwdUpgradeCmd(void) {return defaultMcuSwdUpgradeCmd;}
char *GetDefaultMcuSwdUpgradeProgress(void) {return defaultMcuSwdUpgradeProgress;}
char *GetDefaultRestartKlipperServer(void) {return defaultRestartKlipperServer;}

char *GetDefaultSystemRestartPart(void) {return defaultSystemRestartPart;}
char *GetDefaultSystemRestartAll(void) {return defaultSystemRestartAll;}
char *GetDefaultScreenDisplayOff(void) {return defaultScreenDisplayOff;}
char *GetDefaultScreenDisplayOn(void) {return defaultScreenDisplayOn;}

char *GetHttpKeyFile(void){return defaultHttpKeyFile;}
char *GetHttpCrtFile(void){return defaultHttpCrtFile;}
char *GetHttpPemFile(void){return defaultHttpPemFile;}
