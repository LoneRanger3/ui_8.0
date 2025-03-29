/*
 * @Description : 定义gcode命令字符串
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-16 14:55:01
 * @LastEditTime: 2023-10-26 14:14:01
 */

// 定义gcode命令编号
typedef enum {
    /**
     * @description: 收发异步指令；响应结果异步统一处理
     * @return {*}
     */
    CMD_NUM_NULL = 0,
    SERIAL_PORT_HANDSHAKE_NUM = 1,

    GET_CUR_HOTEND_BED_TEMP_NUM = 100,
    GET_DEV_GCODE_FILE_PATH_NUM,
    GET_DEV_GCODE_FILE_IMAGE_NUM,
    GET_DEV_GCODE_FILE_PHOTO_NUM,
    GET_DEV_CUR_XYZ_LOCAL_NUM,
    GET_DEVICE_ADVANCE_SET_NUM,
    GET_DEVICE_PRINT_SPEED_NUM,
    GET_DEVICE_PRINT_PROGRESS_NUM,

    SET_SELECT_PRINT_FILE_NUM = 1001,
    SET_START_PRINT_FILE_NUM,
    SET_PAUSE_PRINT_FILE_NUM,
    SET_RESUME_PRINT_FILE_NUM,
    SET_STOP_PRINT_FILE_NUM,
    SET_PRINT_FIRST_LAYER_NUM,
    SET_CHECK_CONTINUE_PRINT_NUM,
    SET_CANCEL_CONTINUE_PRINT_NUM,
    SET_PARK_HEAD_PRINT_NUM,
    SET_BREAK_CONTINUE_PEINR_NUM,
    SET_STOP_TEMP_HEATING_NUM,
    SET_DEVICE_RETURN_HOME_NUM,
    SET_ABSOLUTE_POSITIONING_NUM,
    SET_RELATIVE_POSITIONING_NUM,
    SET_CONTROL_DEV_MOVE_NUM,
    SET_Z_AXIS_OFFSET_PARA_NUM,
    SET_Z_AXIS_OFFSET_PARA_SECTION_NUM,
    SET_HOME_OFFSET_PARA_NUM,
    SET_DEVICE_MOTOR_LOCK_NUM,
    SET_DEVICE_MOTOR_UNLOCK_NUM,
    SET_NOZZLE_TARGET_TEMP_NUM,
    SET_BED_TARGET_TEMP_NUM,
    SET_CONTROL_OPEN_FAN_NUM,
    SET_CONTROL_STOP_FAN_NUM,
    SET_CONTROL_LIGHT_VALUE_NUM,
    SET_STOP_ALL_HEATING_NUM,
    SET_DEVICE_AUTO_LEVEL_NUM,
    SET_HOTEND_TEMP_PID_NUM,
    SET_BED_TEMP_PID_NUM,
    SET_DEVICE_RESET_NUM,
    SET_DEV_RESET_AFTER_SAVE_NUM,
    SET_STEP_VALUE_NUM,
    SET_MAX_ACCELERATION_NUM,
    SET_MAX_SPEED_NUM,
    SET_MAX_JERK_NUM,
    SET_MAX_CORNER_NUM,
    SET_PRESSURE_ADVANCE_NUM,
    SET_SMOOTH_TIME_NUM,
    SET_MATERIAL_DELECT_NUM,
    SET_POWER_LOSS_SW_NUM,
    SET_DEVICE_PRINT_SPEED_NUM,
    SET_DEVICE_PRINT_FLOW_NUM,
    SET_CR_TOUCH_CONTROL_NUM,
    SET_START_HOT_END_TEMP_AUTO_PID_NUM,
    SET_START_HOT_BED_TEMP_AUTO_PID_NUM,
    SET_PARA_SAVE_CONFIG_NUM,
    SET_INSERT_FILAMENT_NUM,
    SET_RUN_GCODE_MACRO_NUM,
    SET_CONSOLE_CONTRIL_NUM,
    START_POWER_OFF_CONTINUES_NUM,
    SET_PRINT_CALIBRATION,

    // 公司自定义指令
    CXSW_GET_PRINT_STATUS_NUM,
    CXSW_GET_PRINT_DEV_INFO_NUM,
    CXSW_SET_OFFSET_AND_TIME_NUM,
    CXSW_SET_PRINT_FILE_INFO_NUM,
    CXSW_GET_POWER_LOSS_INFO_NUM,
    CXSW_SET_STOP_PRINTING_NUM,
    CXSW_SET_PAUE_RESUME_NUM,
    CXSW_START_AUTO_RECOUP_NUM,
    CXSW_GET_LEVEL_POINTS_NUM,
    CXSW_SET_LEVEL_POINTS_NUM,
    CXSW_SET_ACTIVELY_ACQUIRE_NUM,

    // 自动打印
    AUTO_PRINT_SEND_GCODE_NUM = 2000,
    AUTO_PRINT_REQUEST_GCODE_NUM,

    // klipper指令编号
    KLIPPER_READY_HANDSHAKE_NUM,
    KLIPPER_GET_DEVICR_INFO,
    KLIPPER_GET_OBJECT_LIST,
    KLIPPER_GET_OBJECT_CONFIG,

    KLIPPER_SET_DEVICR_INFO,
    KLIPPER_SET_SAVE_CONFIG,
    KLIPPER_SUBSCRIBE_OBJECTS,
    KLIPPER_REGISTER_REMOTE_METHOD,
    KLIPPER_RESTART_KLIPPER_NUM,
    KLIPPER_FIRMWARE_RESTART_NUM,
    KLIPPER_RESONANCE_TEST_NUM,
    KLIPPER_GET_MCU_VERSION_NUM,
    KLIPPER_SET_QUIET_MODE,
    KLIPPER_SDCARD_RESET_FILE_NUM,
    KLIPPER_END_PRINT_POINT_NUM,
    KLIPPER_GET_GSENSOR_EXIST_NUM,
    KLIPPER_SET_EXCLUDE_OBJECT_NUM,
    KLIPPER_GET_MESH_INFO_NUM,
    KLIPPER_SET_MESH_INFO_NUM,

    /**
     * @description: 收发同步指令，非异步操作；响应结果在指令发送位置同步处理
     * @return {*}
     */
    KLIPPER_CMD_SYNC_RECV_START_NUM = 5000,
    KLIPPER_FUNCTION_MODULE_NUM,
    KLIPPER_SELF_CALIBRATION_NUM,
    KLIPPER_CMD_SYNC_RECV_END_NUM = 6000,
}GcodeCmdNum_t;

// 定义gcode命令
#define GET_CUR_HOTEND_BED_TEMP         "M105"  // 获取热床和喷嘴温度
#define GET_DEV_GCODE_FILE_PATH         "M20"   // 获取 SD 卡打印文件列表
#define GET_DEV_GCODE_FILE_IMAGE        "M35"   // 获取 SD 卡打印文件缩略图
#define GET_DEV_GCODE_FILE_PHOTO        "M36"   // 获取 SD 卡打印文件注水图
#define GET_DEV_CUR_XYZ_LOCAL           "M114"  // 获取 XYZ 轴位置
#define GET_DEVICE_ADVANCE_SET          "M503"  // 获取设置（最大速度、最大加速度、最大拐角速度）
#define GET_DEVICE_PRINT_SPEED          "M220"  // 获取打印倍速
#define GET_DEVICE_PRINT_PROGRESS       "M31"   // 获取打印进度

#define SET_SELECT_PRINT_FILE           "M23"   // 设置打印文件
#define SET_START_PRINT_FILE            "M24"   // 开始打印
#define SET_PAUSE_PRINT_FILE            "M25"   // 暂停打印
#define SET_STOP_PRINT_FILE             "M524"  // 停止打印
#define SET_PARK_HEAD_PRINT             "M125"  // 临时中断
#define SET_BREAK_AND_CONTINUE          "M108"  // 中断并继续后面操作
#define SET_DEVICE_RETURN_HOME          "G28"   // 设备归零
#define SET_ABSOLUTE_POSITIONING        "G90"   // 设置使用绝对坐标
#define SET_RELATIVE_POSITIONING        "G91"   // 设置使用相对坐标
#define SET_CONTROL_DEV_MOVE            "G0"    // 设置轴移动
#define SET_Z_AXIS_OFFSET_PARA          "M851"  // 设置 Z 轴补偿
#define SET_HOME_OFFSET_PARA            "M206"  // 设置原点偏移
#define SET_BABYSTEPS_PARA              "M290"  // 获取 babysteps 参数
#define SET_DEVICE_MOTOR_LOCK           "M17"   // 锁定电机
#define SET_DEVICE_MOTOR_UNLOCK         "M18"   // 解锁电机
#define SET_NOZZLE_TARGET_TEMP          "M104"  // 设置喷嘴目标温度
#define SET_BED_TARGET_TEMP             "M140"  // 设置热床目标温度
#define SET_CONTROL_OPEN_FAN            "M106"  // 打开风扇
#define SET_CONTROL_STOP_FAN            "M107"  // 关闭风扇
#define SET_DEVICE_AUTO_LEVEL           "G29"   // 开始自动调平
#define SET_HOTEND_TEMP_PID             "M301"  // 设置喷嘴温度 PID
#define SET_BED_TEMP_PID                "M304"  // 设置热床温度 PID
#define CONTROL_DEVICE_RESET            "M502"  // 设备恢复出厂设置
#define SET_STEP_VALUE                  "M92"   // 设置步进值
#define SET_MAX_ACCELERATION            "M201"  // 设置最大加速度
#define SET_MAX_SPEED                   "M203"  // 设置最大速度
#define SET_MAX_JERK                    "M205"  // 设置最大拐角速度
#define SET_MATERIAL_DELECT             "M412"  // 设置断料检测
#define SET_POWER_OFF_CONTINUE          "M413"  // 设置断电续打
#define SET_DEVICE_PRINT_SPEED          "M220"  // 设置打印倍速
#define SET_DEVICE_PRINT_FLOW           "M221"  // 设置打印流量
#define SET_CR_TOUCH_CONTROL            "M280"  // 设置CrTouch
#define SET_START_TEMP_AUTO_PID         "M303"  // 开启温度自动PID
#define SET_PARA_SAVE_EEPROM            "M500"  // 保存设置到 EEPROM
#define START_POWER_OFF_CONTINUES       "M1000" // 开始断电续打

// 公司自定义指令
#define CXSW_GET_PRINT_STATUS           "M8002" // 查询打印机状态
#define CXSW_GET_PRINT_DEV_INFO         "M8004" // 查询打印机信息
#define CXSW_SET_OFFSET_AND_TIME        "M8005" // 设置读取gcode文件偏移量和打印消耗时间
#define CXSW_SET_PRINT_FILE_INFO        "M8006" // 设置打印文件信息
#define CXSW_GET_POWER_OFF_CONTINUES    "M8007" // 获取断电续打信息
#define CXSW_SET_STOP_PRINTING          "M8009" // 设置下位机停止打印
#define CXSW_SET_PAUE_RESUME            "M8013" // 设置工作状态；暂停、继续
#define CXSW_START_AUTO_RECOUP          "M8015" // 启动一键自动补偿
#define CXSW_SET_LEVEL_POINTS           "M8016" // 设置调平点数
#define CXSW_SET_ACTIVELY_ACQUIRE       "M8100" // 设置下位机自动获取指令


// gcode 串口应答字符串协议定义
#define BEGIN_FILE_LIST         "Begin file list\n"
#define END_FILE_LIST           "End file list"
#define SD_CARD_NO_MEDIA        "No media"

#define BEGIN_SMALL_IMAGE       "Begin small photo list\n"
#define END_SMALL_IMAGE         "End small photo list\nok\n"
#define BEGIN_BIG_IMAGE         "Begin big photo list\n"
#define END_BIG_IMAGE           "End big photo list\nok\n"
#define NO_SMALL_IMAGE          "no photo\n"
#define GCODE_FILE_OPEN_FAIL    "open failed"

#define PTINT_WORK_BUSY         "busy"
#define DONE_PRINTING_FILE      "Done printing file"
#define UPDATA_PRINT_TIME       "Print time:"
#define UPDATA_PRINT_STATUS     "Printer status:"
#define UPDATA_PRINT_PROGRESS   "Print percentDone:"
#define AUTO_LEVEL_PROGRESS     "Probing mesh point "
#define USER_SET_PARK_HEAD      "Send M108 to resume"
#define DETECT_MATARIAL_BREAK   "Insert filament and send M108"
#define DEV_ACTIVE_COOLING      "Send M108 to heat nozzle"

#define TEMP_AUTO_PID_START     "PID Autotune start"
#define TEMP_AUTO_PID_FLAG      "bias:"
#define TEMP_AUTO_PID_END       "PID Autotune finished!"
#define TEMP_AUTO_PID_KP        "#define DEFAULT_Kp "
#define TEMP_AUTO_PID_KI        "#define DEFAULT_Ki "
#define TEMP_AUTO_PID_KD        "#define DEFAULT_Kd "
#define TEMP_AUTO_PID_BED_KP    "#define DEFAULT_bedKp "
#define TEMP_AUTO_PID_BED_KI    "#define DEFAULT_bedKi "
#define TEMP_AUTO_PID_BED_KD    "#define DEFAULT_bedKd "

#define UNDEFINED_COMMAND       "Unknown command"
#define LOWER_COMPUTER_STARTS   "start"
#define PRINTER_HALTED          "Printer halted"

// 下位机自动获取gcode指令
#define ACTIVELY_HEADER         "$"

// klipper 应答字符串协议定义
#define GCODE_RES_KLIPPER_STATE "// Klipper state:"
#define TEMP_AUTO_PID_RESULT    "PID parameters: "
#define AUTO_LEVEL_RESULT       "// probe at "
#define GCODE_MACRO_GET         "gcode_macro "
#define GCODE_MENU              "menu"
