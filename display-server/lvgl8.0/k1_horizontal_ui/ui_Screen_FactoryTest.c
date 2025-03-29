/*
 * @Author: Fang JinLun
 * @Date: 2023-02-14 13:37:43
 * @Last Modified by: Fang JinLun
 * @Last Modified time: 2023-02-20 20:13:14
 */

#include "ui_Screen_FactoryTest.h"

static void lv_sketchpad_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void lv_sketchpad_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void lv_sketchpad_event(const lv_obj_class_t * class_p, lv_event_t * e);

#define MES_GY_NAME   "ZB-GY1" //代表当前工位是主板房的工艺一

#define ITEM_NUM 12
#define COLOR_INCOMPELED lv_color_hex(0x50535A)
#define COLOR_FAIL lv_color_hex(0xFF1030)
#define COLOR_PASS lv_color_hex(0x108020)

#define COLOR_BTN_RETURN lv_color_hex(0xFF0010)
#define COLOR_BTN_PASS lv_color_hex(0x42BDD8)
#define COLOR_BTN_RETEST lv_color_hex(0x3000FF)

#define LCD_TEST_DELAY      2500 //LCD测试项中每个颜色刷新的延迟时间

#define CMD_READ_HX711      "READ_HX711\0"
#define CMD_FORCE_MOVE_X    "FORCE_MOVE STEPPER=stepper_x DISTANCE=150 VELOCITY=100\0"
#define CMD_FORCE_MOVE_Y    "FORCE_MOVE STEPPER=stepper_y DISTANCE=150 VELOCITY=100\0"
#define CMD_FORCE_MOVE_Z    "FORCE_MOVE STEPPER=stepper_z DISTANCE=13 VELOCITY=10\0"
#define CMD_FORCE_MOVE_E    "FORCE_MOVE STEPPER=extruder DISTANCE=50 VELOCITY=100\0"

#define GET_NET_IP_CMD      "ifconfig eth0 | grep 'inet ' | sed s/^.*addr//g | sed s/Bcast.*$//g"
#define GET_NET_MODEL_CMD   "cat /sys/class/net/eth0/speed"
#define GET_UDISK_CMD       "df -h | grep '/dev/sd' | awk '{print $2}'"
#define EEPROM_WRITE_CMD    "cmd_i2c write_reg 2 0x57 0x00 0x77"
#define EEPROM_READ_CMD     "cmd_i2c read_reg 2 0x57 0x00 0X01"
#define EEPROM_ERASE_CMD    "cmd_i2c write_reg 2 0x57 0x00 0x00"
typedef enum
{
    ITEM_LCD = 0,
    ITEM_TOUCH,
 //   ITEM_BRIGHTNESS,
    ITEM_EEPROM,
    ITEM_GPIO,
    ITEM_ADC,
    ITEM_USB,
    ITEM_MCU_COM,
    ITEM_MOTOR,
    ITEM_WIFI,
    ITEM_NET_PORT,
    ITEM_BUZZER,
    ITEM_VERSION,
    ITEM_MAX,

} ITEM_TYPE;
typedef enum
{
    TEST_INCOMPLETE = 0,
    TEST_FAIL,
    TEST_PASS,

} TEST_STATUS;

const char *item_text[ITEM_NUM] = {"屏幕显示测试", 
                                   "触摸屏测试",
                                  // "屏幕亮度测试",
                                   "EEPROM测试",
                                   "GPIO接口测试",
                                   "ADC接口测试",
                                   "USB接口测试",
                                   "MCU通讯测试",
                                   "电机接口测试",
                                   "WIFI测试",
                                   "有线网口测试",
                                   "蜂鸣器测试",
                                   "系统版本信息"};
const char *lcd_brightness_text = "亮度测试";
const char *gpio_text[] = {"风扇1",
                            "FAN",
                            "COOLFAN",
                            "LED",
                            "风扇2",
                            "热床加热",
                            //"喷头加热",
                            };
const char *gpio_cmd[] = { "SET_PIN PIN=PA0 VALUE=",
                            "SET_PIN PIN=fan2 VALUE=",
                            "SET_PIN PIN=PB2 VALUE=",
                            "SET_PIN PIN=LED VALUE=",
                            "SET_PIN PIN=fan1 VALUE=",
                            "SET_PIN PIN=PB10 VALUE=",
                            "SET_PIN PIN=PC8 VALUE=",
                            "SET_PIN PIN=PC9 VALUE=",
                            //"SET_PIN PIN=PC7 VALUE=",
                            };
const char *title_text = "工厂测试";
const char *auto_test_text = "自动测试";
const char *btn_text[4] = {"失败",
                           "通过",
                           "重新测试",
                           " "};
const char *play_text = {"播放"};
const char *return_text="返回";
const char *clean_text={"清除"};
const char *gpio_filament_text = "断料检测";
const char *adc_bed_text = "热床温度";
const char *adc_case_text = "腔体温度";
const char *nuzzle_text = "喷嘴温度";
const char *udisk_uninsert_text = "未检测到U盘";
const char *udisk_size_text = "容量";
const char *udisk_insert_text = "U盘已插入";
const char *usb_status_text[2] = {"异常",
                                  "正常"};
const char *motor_x_text = "X轴电机";
const char *motor_y_text = "Y轴电机";
const char *motor_z_text = "Z轴电机";
const char *motor_e_text = "E轴电机";
const char *read_HX711_text = "读取HX711";
const char *wifi_testing_text = "WIFI检测中......";
const char *wifi_test_fail_text = "WIFI检测超时,检测失败!";
const char *net_testing_text = "网口检测中......";
const char *net_test_fail_text = "网口检测失败";
const char *net_test_net_ip_text = "IP: ";
const char *net_test_net_model_text = "宽带模式: ";
const char *eeprom_testing_text = "EEPROM测试中......";
const char *eeprom_pass_text = "EEPROM测试成功";
const char *eeprom_fail_text = "EEPROM测试失败";
const char *version_text[5] = {"固件版本:",
                               "硬件版本:",
                               "设备型号:",
                               "SN号:",
                               "MAC:"};

static TEST_STATUS item_status_flag[ITEM_NUM] = {0}; // 测试是否通过的标志
static lv_obj_t *ui_ScreenFactoryTestScreen;
static lv_obj_t *ui_factory_title_label;
static lv_obj_t *auto_test_label;
static lv_obj_t *ui_factory_auto_test_sw; // 自动测试开关
static lv_obj_t *ui_factory_return_btn;
static lv_obj_t *return_label;
static lv_obj_t *ui_ItemCont;
static lv_obj_t *ui_ItemObj[ITEM_NUM];
static lv_timer_t *auto_test_timer;
// LCD
static lv_obj_t *item_lcd_obj;
static lv_obj_t *item_lcd_return_btn;
static lv_obj_t *item_lcd_pass_btn;
static lv_obj_t *item_lcd_retest_btn;
//static lv_timer_t *item_lcd_timer;
static int lcd_count = 0;
static lv_obj_t *item_lcd_next_btn;



// touch
static lv_obj_t *item_touch_obj;

static lv_obj_t *item_touch_return_btn;
static lv_obj_t *item_touch_test_btn0;
static lv_obj_t *item_touch_test_btn1;
static lv_obj_t *item_touch_test_btn2;
static lv_obj_t *item_touch_test_btn3;
static lv_obj_t *item_touch_test_btn4;
static lv_obj_t *item_touch_title_label;
static lv_obj_t *item_touch_pass_btn;
static lv_obj_t *item_touch_clean_btn;
// touch2
#define MY_CLASS &lv_sketchpad_class
const lv_obj_class_t lv_sketchpad_class = {
    .constructor_cb = lv_sketchpad_constructor,
    .destructor_cb = lv_sketchpad_destructor,
    .event_cb = lv_sketchpad_event,
    .instance_size = sizeof(lv_sketchpad_t),
    .base_class = &lv_canvas_class
};

// brightness
// static lv_obj_t *item_bright_obj;
// static lv_obj_t *item_bright_return_btn;
// static lv_obj_t *item_bright_pass_btn;
// static lv_obj_t *item_bright_label;
// static lv_obj_t *item_bright_slider;

// eeprom
static lv_obj_t *item_eeprom_obj;
static lv_obj_t *item_eeprom_label;
static lv_timer_t* eeprom_timer;
static unsigned char eeprom_timer_count = 0;
// GPIO
static lv_obj_t *item_gpio_obj;
static lv_obj_t *item_gpio_title_label;
static lv_obj_t *item_gpio_return_btn;
static lv_obj_t *item_gpio_pass_btn;
static lv_obj_t *item_gpio_btn0;
static lv_obj_t *item_gpio_btn1;
static lv_obj_t *item_gpio_btn2;
static lv_obj_t *item_gpio_btn3;
static lv_obj_t *item_gpio_btn4;
static lv_obj_t *item_gpio_btn5;
static lv_obj_t *item_gpio_btn6;
static lv_obj_t *item_gpio_filament_label;
static lv_obj_t *item_gpio_filament_led;
// ADC
static lv_obj_t *item_adc_obj;
static lv_obj_t *item_adc_title_label;
static lv_obj_t *item_adc_return_btn;
static lv_obj_t *item_adc_pass_btn;
static lv_obj_t *item_adc_bed_label;
static lv_obj_t *item_adc_case_label;
static lv_obj_t *item_adc_bed_templabel;
static lv_obj_t *item_adc_bed_unitlabel;
static lv_obj_t *item_adc_case_tmeplabel;
static lv_obj_t *item_adc_case_unitlabel;
// USB
static lv_obj_t *item_usb_obj;
static lv_obj_t *item_usb_title_label;
static lv_obj_t *item_usb_return_btn;
static lv_obj_t *item_usb_retest_btn;
static lv_obj_t *item_usb_pass_btn;
static lv_obj_t *item_usb_status_label;
static lv_obj_t *item_usb_size_label;
static lv_obj_t *item_usb_size_text_label;
// MCU
static lv_obj_t *item_mcu_obj;
static lv_obj_t *item_mcu_title_label;
static lv_obj_t *item_mcu_return_btn;
static lv_obj_t *item_mcu_pass_btn;
static lv_obj_t *item_mcu_nuzzle_label;
static lv_obj_t *item_mcu_nuzzle_temp_label;
static lv_obj_t *item_mcu_temp_unit_label;
static lv_obj_t *item_mcu_read_hx711_btn;
// MOTOR
static lv_obj_t *item_motor_obj;
static lv_obj_t *item_motor_title_label;
static lv_obj_t *item_motor_return_btn;
static lv_obj_t *item_motor_pass_btn;
static lv_obj_t *item_motor_y_btn;
static lv_obj_t *item_motor_x_btn;
static lv_obj_t *item_motor_z_btn;
static lv_obj_t *item_motor_e_btn;
// WIFI
static lv_obj_t *item_wifi_obj;
static lv_obj_t *item_wifi_testing_label;
static lv_timer_t *item_wifi_timer;
static lv_obj_t *item_wifi_list;
static lv_timer_t *item_wifi_show_timer;
// NET
static lv_obj_t *item_net_obj;
static lv_obj_t *item_net_testing_label;
static lv_obj_t *item_net_model_label;
static lv_timer_t *item_net_timer;

static lv_obj_t *item_touch_return_net;
static lv_obj_t *item_touch_pass_net;
// 凤鸣器
static lv_obj_t *item_buzzer_obj;
static lv_obj_t *item_touch_return_buzzer;
static lv_obj_t *item_touch_pass_buzzer;
static lv_obj_t *item_paly_buzzer;
//version
static lv_obj_t *item_version_obj;
static lv_obj_t *item_touch_return_version;
static lv_obj_t *item_touch_pass_version;

static lv_obj_t *item_ersion_fw_text;
static lv_obj_t *item_ersion_hw_text;
static lv_obj_t *item_ersion_model_text;
static lv_obj_t *item_ersion_sn_text;
static lv_obj_t *item_ersion_mac_text;

static void factory_ReportMESQrcodeExitEventHandler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *reportCont = lv_event_get_user_data(e);
	switch (code) {
        case LV_EVENT_CLICKED: lv_obj_del(reportCont); break;
        default: break;
	}
}
static void factory_ReportMESQrcode(int uid,int result, json_object* gy, json_object *detail,char *describe)
{
    char productionSn[100] = {0};
    if (!describe) describe = "";

    // 从文件获取生产信息
    json_object *productionInfoObj = json_object_from_file(GetMachineProductionInfo());
    if (productionInfoObj) {
        json_object *snObj = GetJsonObject(productionInfoObj, "productionSn", json_type_string);
        if (snObj) strcat(productionSn, json_object_get_string(snObj));
        json_object_put(productionInfoObj);
    }
    else CrLogW("no production info\n");

    // 生成二维码信息
    json_object *report = json_object_new_object();
    //json_object_object_add(report, "sn", json_object_new_string(productionSn));
    json_object_object_add(report, "dn", json_object_new_string(GetSystemConfig().device_sn));
    json_object_object_add(report, "uid", gy);
    //json_object_object_add(report, "gy", gy);
    json_object_object_add(report, "ok", json_object_new_int(result));
    json_object_object_add(report, "data", detail);

    int jsonFlag = JSON_C_TO_STRING_PLAIN | JSON_C_TO_STRING_PRETTY_TAB | JSON_C_TO_STRING_NOZERO | JSON_C_TO_STRING_NOSLASHESCAPE;
    char *reportStr = json_object_to_json_string_ext(report, jsonFlag);
    CrLogI("reportStr; len = %d, str = %s", strlen(reportStr), reportStr);

    // 创建容器
	lv_obj_t *reportCont = lv_obj_create(lv_layer_top());
    lv_obj_set_align(reportCont, LV_ALIGN_LEFT_MID);
    lv_obj_set_style_pad_all(reportCont, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(reportCont, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(reportCont, lv_obj_get_width(lv_layer_top()), lv_obj_get_height(lv_layer_top()));
    lv_obj_set_style_border_width(reportCont,0,0);
    // 创建二维码
    lv_obj_t *reportQrcode = lv_qrcode_create(reportCont, lv_obj_get_height(lv_layer_top()), lv_color_hex(0xFFFFFF), lv_color_hex(0x000000));
    // 返回按键
	lv_obj_t *returnBtn = lv_btn_create(reportCont);
    lv_obj_align(returnBtn, LV_ALIGN_BOTTOM_RIGHT, -30, -30);
    lv_obj_add_event_cb(returnBtn, factory_ReportMESQrcodeExitEventHandler, LV_EVENT_ALL, reportCont);
    lv_obj_t *returnBtnName = lv_label_create(returnBtn);
    lv_label_set_text(returnBtnName, "返回");
    lv_obj_set_style_text_font(returnBtnName, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    // 二维码描述
    lv_obj_t *describeTotal = lv_label_create(reportCont);
    lv_obj_align_to(describeTotal, reportQrcode, LV_ALIGN_OUT_RIGHT_TOP, 30, 50);
    lv_label_set_text(describeTotal, "检测项目：");
    lv_obj_set_style_text_font(describeTotal, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(describeTotal, lv_color_hex(0xFFFFFF), 0);

    lv_obj_t *describeLabel = lv_label_create(reportCont);
    lv_obj_align_to(describeLabel, describeTotal, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 0);
    lv_obj_set_size(describeLabel, 250, 200);
    lv_label_set_text(describeLabel, describe);
    lv_obj_set_style_text_font(describeLabel, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(describeLabel, lv_color_hex(0xFFFFFF), 0);

    // 显示二维码
    lv_qrcode_update(reportQrcode, reportStr, strlen(reportStr));
    json_object_put(report);
}


void set_klipper_cmd(char* cmd)
{   
    int len = strlen(cmd);
    CrLogI("cmd=%s len=%d\n",cmd,len);
    set_printer_data(0x20,len,cmd);
}

// 前一个测试项目结束1秒后进入下一个测试项目
static uint32_t lastticks;
static void auto_next_test_timer_cb(lv_timer_t *timer)
{
    int index = timer->user_data;
    if (timer->last_run - lastticks >= 200)
    {
        lv_timer_del(timer);
        auto_test_timer = NULL;
        if (index + 1 < ITEM_MAX)
        {
            lv_event_send(ui_ItemObj[index + 1], LV_EVENT_CLICKED, NULL);
        }
        else if (index + 1 >= ITEM_MAX)
        {
            bool ng_flag=false;//测试NG标志位
            for(int i=0;i<ITEM_MAX;i++){
                if(item_status_flag[i]==TEST_FAIL || item_status_flag[i]==TEST_INCOMPLETE){
                    ng_flag = true;    
                }
            }

            // 工艺，区分当前测试是在哪个工位   格式："gy":"ZB-GY1", 
            json_object *gy_obj = json_object_new_string(MES_GY_NAME);

            int result = 0;
            if(ng_flag)
                result = 0;
            else    
                result = 1;
                
            // 生成结果二维码
            json_object *detail_obj = json_object_new_object();
            json_object_object_add(detail_obj, "lcd", json_object_new_int((item_status_flag[ITEM_LCD] == TEST_PASS) ? 1 : 0));
            json_object_object_add(detail_obj, "tp", json_object_new_int((item_status_flag[ITEM_TOUCH] == TEST_PASS) ? 1 : 0));
            json_object_object_add(detail_obj, "e2", json_object_new_int((item_status_flag[ITEM_EEPROM] == TEST_PASS) ? 1 : 0));
            json_object_object_add(detail_obj, "io", json_object_new_int((item_status_flag[ITEM_GPIO] == TEST_PASS) ? 1 : 0));
            json_object_object_add(detail_obj, "adc", json_object_new_int((item_status_flag[ITEM_ADC] == TEST_PASS) ? 1 : 0));
            json_object_object_add(detail_obj, "usb", json_object_new_int((item_status_flag[ITEM_USB] == TEST_PASS) ? 1 : 0));
            json_object_object_add(detail_obj, "mcu", json_object_new_int((item_status_flag[ITEM_MCU_COM] == TEST_PASS) ? 1 : 0));
            json_object_object_add(detail_obj, "motor", json_object_new_int((item_status_flag[ITEM_MOTOR] == TEST_PASS) ? 1 : 0));
            json_object_object_add(detail_obj, "wifi", json_object_new_int((item_status_flag[ITEM_WIFI] == TEST_PASS) ? 1 : 0));
            json_object_object_add(detail_obj, "eth", json_object_new_int((item_status_flag[ITEM_NET_PORT] == TEST_PASS) ? 1 : 0));
            json_object_object_add(detail_obj, "buz", json_object_new_int((item_status_flag[ITEM_BUZZER] == TEST_PASS) ? 1 : 0));
            json_object_object_add(detail_obj, "sys", json_object_new_int((item_status_flag[ITEM_VERSION] == TEST_PASS) ? 1 : 0));
            

            factory_ReportMESQrcode(FACTORY_STEPS_PCBA_DETECT,result, gy_obj ,detail_obj, "PCBA硬件检测");
          
        }

    }
}

static void auto_next_test(int index)
{
    if (!auto_test_timer && lv_obj_has_state(ui_factory_auto_test_sw, LV_STATE_CHECKED))
    {
        auto_test_timer = lv_timer_create(auto_next_test_timer_cb, 200, index);
        lastticks = lv_tick_get();
    }
}

static void factorySetScreenBrightness(int value)
{
    CrLogI("set screen brightness = %d", value);
#ifdef CROSS_COMPILE
    char resBuf[32] = {0};
    char setCmd[256] = {0};
    snprintf(setCmd, sizeof(setCmd), "%s %d", GetDefaultGetScreenValueScript(), value);
    CrLogI("set screen brightness = %s", setCmd);
    // 设置
    if (!PopenSystem(setCmd, resBuf, sizeof(resBuf)))
        CrLogW("set screen value fail !!\n");
#endif
}

static lv_obj_t *ui_factory_add_label(lv_obj_t *parents, char *text, lv_font_t *font, lv_color_t color, lv_align_t align,
                                      lv_obj_t *align_to_obj, lv_coord_t x_ofs, lv_coord_t y_ofs)
{
    lv_obj_t *label = lv_label_create(parents);
    lv_label_set_text(label, text);
    lv_obj_set_style_text_font(label, font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
    lv_obj_set_style_text_color(label, color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align_to(label, align_to_obj, align, x_ofs, y_ofs);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    return label;
}
/**
 * @description: ui增加一个按钮
 * @param  {*}
 * @return {*}
 */
static lv_obj_t *ui_factory_add_btn(lv_obj_t *parents, lv_coord_t w, lv_coord_t h, lv_color_t btn_color,
                                    char *text, lv_color_t text_color, lv_font_t *font, lv_event_cb_t cb, void *userdata)
{
    lv_obj_t *btn = lv_btn_create(parents);
    lv_obj_set_size(btn, w, h);
    lv_obj_set_style_bg_color(btn, btn_color, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(btn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(btn, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(btn, cb, LV_EVENT_ALL, userdata);
    if (text)
    {
        lv_obj_t *label = lv_label_create(btn);
        lv_obj_center(label);
        lv_label_set_text(label, text);
        lv_obj_set_style_text_color(label, text_color, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_text_font(label, font, LV_PART_MAIN | LV_STATE_DEFAULT);
    }

    return btn;
}
/**
 * @description: 根据flag更新每个测试项的背景颜色
 * @param  {*}
 * @return {*}
 */
static void update_item_status(void)
{
    int i = 0;
    for (i; i < ITEM_NUM; i++)
    {
        if (item_status_flag[i] == TEST_INCOMPLETE)
        {
            lv_obj_set_style_bg_color(ui_ItemObj[i], COLOR_INCOMPELED, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else if (item_status_flag[i] == TEST_PASS)
        {
            lv_obj_set_style_bg_color(ui_ItemObj[i], COLOR_PASS, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        else
        {
            lv_obj_set_style_bg_color(ui_ItemObj[i], COLOR_FAIL, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

//========屏幕测试相关==========
static int lightvalue = 0;
static void brightness_timer_cb(lv_timer_t *timer)
{
    
    // char value[5] = {0};
    // snprintf(value,5,"e%d",lightvalue);
    // set_printer_data(0x06,strlen(temp),temp);
    lightvalue+=20;
    factorySetScreenBrightness(lightvalue);
    
    if(lightvalue>=100)
    {
        lightvalue = 0;
        lcd_count = 0;
        /// 测试结束显示按钮
        lv_obj_set_style_bg_color(item_lcd_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_clear_flag(item_lcd_pass_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(item_lcd_return_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(item_lcd_retest_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(item_lcd_next_btn, LV_OBJ_FLAG_HIDDEN);

        lv_obj_add_flag(item_lcd_next_btn,LV_OBJ_FLAG_CLICKABLE);
        lv_timer_del(timer);
    }
}




/**
 * @description: lcd显示颜色切换计时器回调
 * @param  {*}
 * @return {*}
 */
/*
static void item_lcd_timer_cb(struct _lv_timer_t *timer)
{
    
    switch (lcd_count)
    {
    case 0:
        lv_obj_set_style_bg_color(item_lcd_obj, lv_color_make(0xFF, 0x00, 0x00), LV_PART_MAIN | LV_STATE_DEFAULT);
        // lv_obj_set_style_bg_color(item_lcd_obj, lv_color_make(0xC7, 0xED, 0xCC), LV_PART_MAIN | LV_STATE_DEFAULT);
        break;
    case 1:
        lv_obj_set_style_bg_color(item_lcd_obj, lv_color_make(0x00, 0xFF, 0x00), LV_PART_MAIN | LV_STATE_DEFAULT);
        break;
    case 2:
        lv_obj_set_style_bg_color(item_lcd_obj, lv_color_make(0x00, 0x00, 0xFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        break;
    case 3:
        lv_obj_set_style_bg_color(item_lcd_obj, lv_color_make(0xFF, 0xFF, 0xFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        break;
    case 4:
        lv_obj_set_style_bg_color(item_lcd_obj, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN | LV_STATE_DEFAULT);
        break;
    case 5:
        lv_obj_set_style_bg_color(item_lcd_obj, lv_color_make(0xFF, 0xFF, 0xFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_timer_create(brightness_timer_cb, 1000 ,(void*)timer);
        lv_timer_pause(timer);
        break;
    default:
        lcd_count = 0;
        /// 测试结束显示按钮
        lv_obj_set_style_bg_color(item_lcd_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_clear_flag(item_lcd_pass_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(item_lcd_return_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(item_lcd_retest_btn, LV_OBJ_FLAG_HIDDEN);
        lv_timer_del(timer);
        break;
    }
    lcd_count++;
}
*/
static void item_lcd_page_next_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);
    if (code != LV_EVENT_CLICKED)  return;

    switch (lcd_count)
    {
    // case 0:
        // lv_obj_set_style_bg_color(item_lcd_obj, lv_color_make(0xFF, 0x00, 0x00), LV_PART_MAIN | LV_STATE_DEFAULT);
        // break;
    case 0:
        lv_obj_set_style_bg_color(item_lcd_obj, lv_color_make(0x00, 0xFF, 0x00), LV_PART_MAIN | LV_STATE_DEFAULT);
        break;
    case 1:
        lv_obj_set_style_bg_color(item_lcd_obj, lv_color_make(0x00, 0x00, 0xFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        break;
    case 2:
        lv_obj_set_style_bg_color(item_lcd_obj, lv_color_make(0xFF, 0xFF, 0xFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        break;
    case 3:
        lv_obj_set_style_bg_color(item_lcd_obj, lv_color_make(0x00, 0x00, 0x00), LV_PART_MAIN | LV_STATE_DEFAULT);
        break;
    case 4:
        lv_obj_set_style_bg_color(item_lcd_obj, lv_color_make(0xFF, 0xFF, 0xFF), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_timer_create(brightness_timer_cb, 500 ,NULL);
        lv_obj_clear_flag(item_lcd_next_btn,LV_OBJ_FLAG_CLICKABLE);
        break;
    default:
        // lcd_count = 0;
        // /// 测试结束显示按钮
        // lv_obj_set_style_bg_color(item_lcd_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
        // lv_obj_clear_flag(item_lcd_pass_btn, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_clear_flag(item_lcd_return_btn, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_clear_flag(item_lcd_retest_btn, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_add_flag(item_lcd_next_btn, LV_OBJ_FLAG_HIDDEN);
        break;
    }
    lcd_count++;

}

/**
 * @description: 屏幕测试项目返回按钮事件回调
 * @param  {*}
 * @return {*}
 */
static void item_lcd_return_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        //printf("item return clicked\n");

        item_status_flag[ITEM_LCD] = TEST_FAIL;
        update_item_status();
        lv_obj_del_async(parents);
        auto_next_test(ITEM_LCD);
    }
}
/**
 * @description: 屏幕测试项目通过按钮事件回调
 * @param  {*}
 * @return {*}
 */
static void item_lcd_pass_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        //printf("lcd item pass clicked\n");
        item_status_flag[ITEM_LCD] = TEST_PASS;
        update_item_status();
        lv_obj_del_async(parents);
   
        auto_next_test(ITEM_LCD);
    }
}
/**
 * @description: 屏幕测试项目重新测试按钮事件回调
 * @param  {*}
 * @return {*}
 */
static void item_lcd_retest_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_CLICKED)
    {
        //printf("lcd item retest clicked\n");
        // 测试开始隐藏按钮
        lv_obj_add_flag(item_lcd_pass_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(item_lcd_return_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(item_lcd_retest_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(item_lcd_next_btn, LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_style_bg_color(item_lcd_obj, lv_color_make(0xFF, 0x00, 0x00), LV_PART_MAIN | LV_STATE_DEFAULT);
        // item_lcd_timer = lv_timer_create(item_lcd_timer_cb, 1000, item_lcd_obj);
        lcd_count = 0;
        //lv_timer_ready(item_lcd_timer);
    }
}

/**
 * @description: 屏幕测试项初始化
 * @param  {*}
 * @return {*}
 */
static void factory_item_lcd_test_init(void)
{
    lcd_count = 0;
    lightvalue = 0;
    lightvalue = 0;
    item_lcd_obj = lv_obj_create(lv_scr_act());
    lv_obj_set_style_radius(item_lcd_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(item_lcd_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(item_lcd_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(item_lcd_obj, 800, 480);
    lv_obj_clear_flag(item_lcd_obj,LV_OBJ_FLAG_SCROLLABLE);

    item_lcd_pass_btn = ui_factory_add_btn(item_lcd_obj, 130, 50, COLOR_BTN_PASS,
                                           btn_text[1], lv_color_white(), lv_font25.font, item_lcd_pass_event_cb, (void *)item_lcd_obj);
    // lv_obj_center(item_lcd_pass_btn);
    lv_obj_align_to(item_lcd_pass_btn, item_lcd_obj, LV_ALIGN_BOTTOM_MID, 0, -20);
    item_lcd_return_btn = ui_factory_add_btn(item_lcd_obj, 130, 50, COLOR_BTN_RETURN,
                                             btn_text[0], lv_color_white(), lv_font25.font, item_lcd_return_event_cb, (void *)item_lcd_obj);
    lv_obj_align_to(item_lcd_return_btn, item_lcd_pass_btn, LV_ALIGN_OUT_LEFT_MID, -20, 0);
    item_lcd_retest_btn = ui_factory_add_btn(item_lcd_obj, 130, 50, COLOR_BTN_RETEST,
                                             btn_text[2], lv_color_white(), lv_font25.font, item_lcd_retest_event_cb, (void *)item_lcd_obj);
    lv_obj_align_to(item_lcd_retest_btn, item_lcd_pass_btn, LV_ALIGN_OUT_RIGHT_MID, 20, 0);
    
    
    // 测试开始隐藏按钮
    lv_obj_add_flag(item_lcd_pass_btn, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(item_lcd_return_btn, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(item_lcd_retest_btn, LV_OBJ_FLAG_HIDDEN);


    // “亮度测试”标签
    // item_lcd_Brightness_test_label = ui_factory_add_label(item_lcd_obj, lcd_brightness_text, lv_font25.font,
    //                                               lv_color_white(), LV_ALIGN_CENTER, item_lcd_obj, 0, -200);
    // lv_obj_set_style_text_color(item_lcd_Brightness_test_label, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_size(item_lcd_Brightness_test_label, LV_SIZE_CONTENT, 50);
    // // 测试开始隐藏 “亮度测试” 文字
    // lv_obj_add_flag(item_lcd_Brightness_test_label, LV_OBJ_FLAG_HIDDEN);

    // 下一页 按键
    item_lcd_next_btn = ui_factory_add_btn(item_lcd_obj, 790, 470, COLOR_BTN_RETEST,
                                             btn_text[3], lv_color_white(), lv_font25.font, item_lcd_page_next_cb, (void *)item_lcd_obj);
    lv_obj_center(item_lcd_next_btn);
    lv_obj_set_style_bg_opa(item_lcd_next_btn, LV_OPA_0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // 显示红色：第一张颜色测试
    lv_obj_set_style_bg_color(item_lcd_obj, lv_color_make(0xFF, 0x00, 0x00), LV_PART_MAIN | LV_STATE_DEFAULT);

}

//==========触摸测试相关==========
static unsigned char touch_btn_status[5] = {0};

/**
 * @description: 触摸测试项返回按钮事件回调
 * @param  {*}
 * @return {*}
 */
static void item_touch_return_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        //printf("item return clicked\n");

        item_status_flag[ITEM_TOUCH] = TEST_FAIL;
        update_item_status();
        lv_obj_del_async(parents);
        auto_next_test(ITEM_TOUCH);
    }
}
/**
 * @description: 触摸测试通过按钮事件回调
 * @param  {*}
 * @return {*}
 */
static void item_touch_pass_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *btn = lv_event_get_target(e);
    int index = lv_event_get_user_data(e);
    bool pass_flag = false;
    if (code == LV_EVENT_CLICKED)
    {
        //printf("touch item pass clicked\n");

        lv_obj_set_style_bg_color(btn, COLOR_BTN_PASS, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_opa(btn, LV_OPA_COVER, LV_PART_MAIN | LV_STATE_DEFAULT);
        touch_btn_status[index] = 1;

        if (touch_btn_status[0] && touch_btn_status[1] &&
            touch_btn_status[2] && touch_btn_status[3] &&
            touch_btn_status[4])
        {
            item_status_flag[ITEM_TOUCH] = TEST_PASS;
            update_item_status();
            lv_obj_del_async(item_touch_obj);
            auto_next_test(ITEM_TOUCH);
        }
    }
}
/**
 * @description: 触摸测试项初始化
 * @param  {*}
 * @return {*}
 */
static void factory_item_touch_test_init(void)
{
    bzero(touch_btn_status, 5);
    item_touch_obj = lv_obj_create(lv_scr_act());
    lv_obj_set_style_radius(item_touch_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(item_touch_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(item_touch_obj, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(item_touch_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(item_touch_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(item_touch_obj, 800, 480);

    item_touch_return_btn = ui_factory_add_btn(item_touch_obj, 130, 50, COLOR_BTN_RETURN,
                                               btn_text[0], lv_color_white(), lv_font25.font, item_touch_return_event_cb, (void *)item_touch_obj);
    lv_obj_align(item_touch_return_btn, LV_ALIGN_BOTTOM_MID, 0, -10);

    // 5个测试按钮
    item_touch_test_btn0 = ui_factory_add_btn(item_touch_obj, 70, 70, COLOR_BTN_RETURN,
                                              NULL, lv_color_white(), lv_font25.font, item_touch_pass_event_cb, 0);
    lv_obj_set_style_radius(item_touch_test_btn0, LV_RADIUS_CIRCLE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(item_touch_test_btn0, LV_OPA_0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(item_touch_test_btn0, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(item_touch_test_btn0, COLOR_BTN_PASS, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(item_touch_test_btn0, LV_ALIGN_TOP_LEFT, 5, 5);

    item_touch_test_btn1 = ui_factory_add_btn(item_touch_obj, 70, 70, COLOR_BTN_RETURN,
                                              NULL, lv_color_white(), lv_font25.font, item_touch_pass_event_cb, 1);
    lv_obj_set_style_radius(item_touch_test_btn1, LV_RADIUS_CIRCLE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(item_touch_test_btn1, LV_OPA_0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(item_touch_test_btn1, COLOR_BTN_PASS, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(item_touch_test_btn1, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(item_touch_test_btn1, LV_ALIGN_TOP_RIGHT, -5, 5);

    item_touch_test_btn2 = ui_factory_add_btn(item_touch_obj, 70, 70, COLOR_BTN_RETURN,
                                              NULL, lv_color_white(), lv_font25.font, item_touch_pass_event_cb, 2);
    lv_obj_set_style_radius(item_touch_test_btn2, LV_RADIUS_CIRCLE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(item_touch_test_btn2, LV_OPA_0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(item_touch_test_btn2, COLOR_BTN_PASS, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(item_touch_test_btn2, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(item_touch_test_btn2, LV_ALIGN_BOTTOM_RIGHT, -5, -5);

    item_touch_test_btn3 = ui_factory_add_btn(item_touch_obj, 70, 70, COLOR_BTN_RETURN,
                                              NULL, lv_color_white(), lv_font25.font, item_touch_pass_event_cb, 3);
    lv_obj_set_style_radius(item_touch_test_btn3, LV_RADIUS_CIRCLE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(item_touch_test_btn3, LV_OPA_0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(item_touch_test_btn3, COLOR_BTN_PASS, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(item_touch_test_btn3, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(item_touch_test_btn3, LV_ALIGN_BOTTOM_LEFT, 5, -5);

    item_touch_test_btn4 = ui_factory_add_btn(item_touch_obj, 70, 70, COLOR_BTN_RETURN,
                                              NULL, lv_color_white(), lv_font25.font, item_touch_pass_event_cb, 4);
    lv_obj_set_style_radius(item_touch_test_btn4, LV_RADIUS_CIRCLE, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(item_touch_test_btn4, LV_OPA_0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(item_touch_test_btn4, COLOR_BTN_PASS, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(item_touch_test_btn4, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align(item_touch_test_btn4, LV_ALIGN_CENTER, 0, 0);
}
#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 480

static void lv_sketchpad_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    lv_sketchpad_t * sketchpad = (lv_sketchpad_t *)obj;

    sketchpad->dsc.header.always_zero = 0;
    sketchpad->dsc.header.cf          = LV_IMG_CF_TRUE_COLOR;
    sketchpad->dsc.header.h           = 0;
    sketchpad->dsc.header.w           = 0;
    sketchpad->dsc.data_size          = 0;
    sketchpad->dsc.data               = NULL;

    lv_draw_line_dsc_init(&sketchpad->line_rect_dsc);
    sketchpad->line_rect_dsc.width = 3;
    sketchpad->line_rect_dsc.round_start = true;
    sketchpad->line_rect_dsc.round_end = true;
    sketchpad->line_rect_dsc.color = lv_color_black();
    sketchpad->line_rect_dsc.opa = LV_OPA_80;

    lv_img_set_src(obj, &sketchpad->dsc);

    lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);

    sketchpad->circle = lv_obj_create(obj);
    lv_obj_set_size(sketchpad->circle,40,40);
    lv_obj_set_style_bg_color(sketchpad->circle,lv_color_hex(0x1F1F20),LV_PART_MAIN);
    lv_obj_set_style_bg_opa(sketchpad->circle,LV_OPA_50,LV_PART_MAIN);
    lv_obj_set_style_radius(sketchpad->circle,LV_RADIUS_CIRCLE,LV_PART_MAIN);
    lv_obj_add_flag(sketchpad->circle,LV_OBJ_FLAG_HIDDEN);
    /*toolbar*/
    // lv_obj_t * toolbar = lv_obj_class_create_obj(&lv_sketchpad_toolbar_class, obj);
    // lv_obj_class_init_obj(toolbar);

}

static void lv_sketchpad_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    lv_canvas_t * canvas = (lv_canvas_t *)obj;
    lv_img_cache_invalidate_src(&canvas->dsc);
}

static void lv_sketchpad_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_res_t res;

    /*Call the ancestor's event handler*/
    res = lv_obj_event_base(MY_CLASS, e);
    if(res != LV_RES_OK) return;

    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    lv_sketchpad_t * sketchpad = (lv_sketchpad_t *)obj;
    lv_obj_t* circle = sketchpad->circle;
    static lv_coord_t last_x, last_y = -32768;

    if (code == LV_EVENT_PRESSING)
    {
        lv_indev_t * indev = lv_indev_get_act();
        if(indev == NULL)  return;

        lv_point_t point;
        lv_indev_get_point(indev, &point);
        // printf("point = %d,%d \n", point.x, point.y);
        lv_color_t c0;
        c0.full = 10;

        lv_point_t points[2];
        lv_obj_clear_flag(circle,LV_OBJ_FLAG_HIDDEN);
        lv_obj_set_pos(circle,point.x-15,point.y-15);
        /*Release or first use*/
        if ((last_x == -32768) || (last_y == -32768))
        {
            last_x = point.x;
            last_y = point.y;
        }
        else
        {
            points[0].x = last_x;
            points[0].y = last_y;
            points[1].x = point.x;
            points[1].y = point.y;
            
            last_x = point.x;
            last_y = point.y;

            lv_canvas_draw_line(obj, points, 2, &sketchpad->line_rect_dsc);
        }
    }

    /*Loosen the brush*/
    else if(code == LV_EVENT_RELEASED)
    {
        last_x = -32768;
        last_y = -32768;
        lv_canvas_fill_bg(sketchpad,lv_color_white(),LV_OPA_100);
        lv_obj_add_flag(circle,LV_OBJ_FLAG_HIDDEN);
        
    }
}

lv_obj_t * lv_sketchpad_create(lv_obj_t * parent)
{
    lv_obj_t * obj = lv_obj_class_create_obj(MY_CLASS, parent);
    lv_obj_class_init_obj(obj);
    return obj;
}

/**
 * @description: USB测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_touch_return_event_cb2(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        item_status_flag[ITEM_TOUCH] = TEST_FAIL;
        update_item_status();
        lv_obj_del_async(parents);
        item_usb_obj = NULL;
        auto_next_test(ITEM_TOUCH);
    }
}
/**
 * @description: USB测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_touch_pass_event_cb2(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        item_status_flag[ITEM_TOUCH] = TEST_PASS;
        update_item_status();
        lv_obj_del_async(parents);
        item_usb_obj = NULL;
        auto_next_test(ITEM_TOUCH);
    }
}
static void item_touch_clean_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *canvas = lv_event_get_user_data(e);
    if (code == LV_EVENT_CLICKED)
    {
        lv_canvas_fill_bg(canvas,lv_color_white(),LV_OPA_100);
    }
}
void factory_item_touch_test_init2(void)
{
    static lv_color_t cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(DEFAULT_WIDTH, DEFAULT_HEIGHT)];
    lv_obj_t * sketchpad = lv_sketchpad_create(lv_scr_act());
    lv_canvas_set_buffer(sketchpad, cbuf, DEFAULT_WIDTH, DEFAULT_HEIGHT, LV_IMG_CF_TRUE_COLOR);
    // lv_obj_center(sketchpad);
    lv_canvas_fill_bg(sketchpad, lv_color_white(), LV_OPA_COVER);

    item_touch_obj = sketchpad; // 
    // item_touch_obj = lv_obj_create(lv_scr_act());
    lv_obj_set_style_radius(item_touch_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(item_touch_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(item_touch_obj, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(item_touch_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(item_touch_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(item_touch_obj, 800, 480);
    item_touch_title_label = ui_factory_add_label(item_touch_obj, item_text[ITEM_TOUCH], lv_font25.font, lv_color_black(),
                                             LV_ALIGN_TOP_MID, item_touch_obj, 0, 25);

    // item_touch_clean_btn = ui_factory_add_btn(item_touch_obj, 130, 50, COLOR_BTN_RETEST,
    //                                         clean_text, lv_color_white(), lv_font25.font, item_touch_clean_event_cb, (void *)item_touch_obj);
    // lv_obj_align_to(item_touch_clean_btn, item_touch_obj, LV_ALIGN_BOTTOM_MID, 0,-10);

    item_touch_return_btn = ui_factory_add_btn(item_touch_obj, 130, 50, COLOR_BTN_RETURN,
                                              btn_text[0], lv_color_white(), lv_font25.font, item_touch_return_event_cb2, (void *)item_touch_obj);
    lv_obj_align_to(item_touch_return_btn, item_touch_clean_btn, LV_ALIGN_BOTTOM_MID, -75, -10);

    item_touch_pass_btn = ui_factory_add_btn(item_touch_obj, 130, 50, COLOR_BTN_PASS,
                                            btn_text[1], lv_color_white(), lv_font25.font, item_touch_pass_event_cb2, (void *)item_touch_obj);
    lv_obj_align_to(item_touch_pass_btn, item_touch_clean_btn, LV_ALIGN_BOTTOM_MID, 75, -10);

    


}

//==========亮度测试相关==========
/**
 * @description: 亮度测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
// static void item_bright_return_event_cb(lv_event_t *e)
// {
//     lv_event_code_t code = lv_event_get_code(e);
//     lv_obj_t *parents = lv_event_get_user_data(e);

//     if (code == LV_EVENT_CLICKED)
//     {
//         item_status_flag[ITEM_BRIGHTNESS] = TEST_FAIL;
//         update_item_status();
//         lv_obj_del_async(parents);
//         factorySetScreenBrightness(100);
//         auto_next_test(ITEM_BRIGHTNESS);
//     }
// }
/**
 * @description: 亮度测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
// static void item_bright_pass_event_cb(lv_event_t *e)
// {
//     lv_event_code_t code = lv_event_get_code(e);
//     lv_obj_t *parents = lv_event_get_user_data(e);

//     if (code == LV_EVENT_CLICKED)
//     {
//         item_status_flag[ITEM_BRIGHTNESS] = TEST_PASS;
//         update_item_status();
//         lv_obj_del_async(parents);
//         factorySetScreenBrightness(100);
//         auto_next_test(ITEM_BRIGHTNESS);
//     }
// }
/**
 * @description: 亮度进度条回调
 * @param  {*}
 * @return {*}
 */
// static void brightness_slider_event_cb(lv_event_t *e)
// {
//     lv_obj_t *slider = lv_event_get_target(e);

//     int lightvalue = 0;
//     lightvalue = lv_slider_get_value(slider);
//     // char value[5] = {0};
//     // snprintf(value,5,"e%d",lightvalue);
//     // set_printer_data(0x06,strlen(temp),temp);
//     factorySetScreenBrightness(lightvalue);
// }
/**
 * @description: 亮度测试项初始化
 * @param  {*}
 * @return {*}
 */
// static void factory_item_brightness_test_init(void)
// {
//     item_bright_obj = lv_obj_create(lv_scr_act());
//     lv_obj_set_style_radius(item_bright_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_clear_flag(item_bright_obj, LV_OBJ_FLAG_SCROLLABLE);
//     lv_obj_set_style_border_width(item_bright_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(item_bright_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_size(item_bright_obj, 800, 480);

//     item_bright_return_btn = ui_factory_add_btn(item_bright_obj, 130, 50, COLOR_BTN_RETURN,
//                                                 btn_text[0], lv_color_white(), lv_font25.font, item_bright_return_event_cb, (void *)item_bright_obj);
//     lv_obj_align_to(item_bright_return_btn, item_bright_obj, LV_ALIGN_CENTER, -75, 100);

//     item_bright_pass_btn = ui_factory_add_btn(item_bright_obj, 130, 50, COLOR_BTN_PASS,
//                                               btn_text[1], lv_color_white(), lv_font25.font, item_bright_pass_event_cb, (void *)item_bright_obj);
//     lv_obj_align_to(item_bright_pass_btn, item_bright_return_btn, LV_ALIGN_OUT_RIGHT_MID, 20, 0);

//     item_bright_label = ui_factory_add_label(item_bright_obj, item_text[ITEM_BRIGHTNESS], lv_font25.font, lv_color_white(),
//                                              LV_ALIGN_CENTER, item_bright_obj, 0, -70);
//     lv_obj_set_size(item_bright_label, 400, 80);
//     lv_obj_align_to(item_bright_label, item_bright_obj, LV_ALIGN_CENTER, 0, -70);

//     item_bright_slider = lv_slider_create(item_bright_obj);
//     lv_obj_align(item_bright_slider, LV_ALIGN_CENTER, 0, -10);
//     lv_slider_set_value(item_bright_slider, 100, LV_ANIM_OFF);
//     lv_slider_set_range(item_bright_slider, 10, 100);
//     lv_obj_set_width(item_bright_slider, 500);
//     lv_obj_set_height(item_bright_slider, 20);
//     lv_obj_set_style_radius(item_bright_slider, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(item_bright_slider, lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(item_bright_slider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//     lv_obj_set_style_radius(item_bright_slider, 0, LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(item_bright_slider, lv_color_hex(0x42BDD8), LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(item_bright_slider, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
//     lv_obj_set_style_radius(item_bright_slider, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_color(item_bright_slider, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_set_style_bg_opa(item_bright_slider, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
//     lv_obj_add_event_cb(item_bright_slider, brightness_slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
// }

//==========EEPROM==========

bool eeprom_test_cmd(void)
{
    
    char resBuf[128] = {0};
    CrLogI("eeprom wirte cmd = %s", EEPROM_WRITE_CMD);
    // 设置
    if (!PopenSystem(EEPROM_WRITE_CMD, resBuf, sizeof(resBuf)))
    {
        CrLogW("eeprom write fail !!\n");
        return false;
    }
    bzero(resBuf,sizeof(resBuf));
    CrLogI("eeprom read cmd = %s", EEPROM_READ_CMD);
    if (!PopenSystem(EEPROM_READ_CMD, resBuf, sizeof(resBuf)))
    {
        CrLogW("eeprom read fail !!\n");
        return false;
    }
    CrLogI("resBuf=%s\n",resBuf);
    if(!strstr(resBuf,"77"))
        return false;
    bzero(resBuf,sizeof(resBuf));
    if (!PopenSystem(EEPROM_ERASE_CMD, resBuf, sizeof(resBuf)))
    {
        CrLogW("eeprom erase fail !!\n");
        return false;
    }
    if(!strstr(resBuf,"00"))
        return false;
    
    return true;
}

void *eeprom_timer_cb(lv_timer_t* timer)
{
    lv_obj_t* obj = (lv_obj_t*)timer->user_data;
    if(eeprom_timer_count<=0)
    {
        bool ret = eeprom_test_cmd();
        if(ret)
        {
            lv_label_set_text(item_eeprom_label,eeprom_pass_text);
            lv_obj_set_size(item_eeprom_label, LV_SIZE_CONTENT, 50);
            item_status_flag[ITEM_EEPROM] = TEST_PASS;
            update_item_status();

        }
        else
        {
            lv_label_set_text(item_eeprom_label,eeprom_fail_text);
            lv_obj_set_size(item_eeprom_label, LV_SIZE_CONTENT, 50);
            item_status_flag[ITEM_EEPROM] = TEST_FAIL;
            update_item_status();
           
        }
    }
    else if(eeprom_timer_count>=2)
    {
        lv_obj_del_async(obj);
        lv_timer_del(timer);
        auto_next_test(ITEM_EEPROM);
    }

    eeprom_timer_count+=1;
}

void factory_item_eeprom_test_init(void)
{
    eeprom_timer_count = 0;
    item_eeprom_obj = lv_obj_create(lv_layer_top());
    lv_obj_set_style_radius(item_eeprom_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(item_eeprom_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_border_width(item_eeprom_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(item_eeprom_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(item_eeprom_obj, 800, 480);
    lv_obj_set_style_bg_opa(item_eeprom_obj, LV_OPA_80, LV_PART_MAIN | LV_STATE_DEFAULT);

    item_eeprom_label = ui_factory_add_label(item_eeprom_obj, eeprom_testing_text, lv_font25.font,
                                                  lv_color_white(), LV_ALIGN_CENTER, item_eeprom_obj, 0, 0);
    lv_obj_set_size(item_eeprom_label, LV_SIZE_CONTENT, 50);
    eeprom_timer = lv_timer_create(eeprom_timer_cb,1000,item_eeprom_obj);
   

}

//==========GPIO测试相关==========
void refresh_factory_gpio_filament(char status)
{
    //printf("filament status=%c\n",status);
    if (!item_gpio_obj)
        return;
    //printf("refresh_factory_gpio_filament=%c\n",status);
    if (status == '1')
        lv_led_on(item_gpio_filament_led);
    if (status == '4' || status == '3')
        lv_led_off(item_gpio_filament_led);
}
/**
 * @description: gpio测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_gpio_return_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        item_status_flag[ITEM_GPIO] = TEST_FAIL;
        update_item_status();
        lv_obj_del_async(parents);
        item_gpio_obj = NULL;
        auto_next_test(ITEM_GPIO);
        
    }
}
/**
 * @description: gpio测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_gpio_pass_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        item_status_flag[ITEM_GPIO] = TEST_PASS;
        update_item_status();
        lv_obj_del_async(parents);
        item_gpio_obj = NULL;
        auto_next_test(ITEM_GPIO);
    }
}
/**
 * @description: gpio测试按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_gpio_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    int index = lv_event_get_user_data(e);
    lv_obj_t *btn = lv_event_get_target(e);
    char cmd[64]={0};
    if (code == LV_EVENT_CLICKED)
    {
        // send_buzzer(0x01);
    }
    else if (code == LV_EVENT_VALUE_CHANGED)
    {
        if (lv_obj_has_state(btn, LV_STATE_CHECKED))
        {
            //printf("Btn %d Checked\n", index);
            if(index==1 || index==4)
            {
                snprintf(cmd,64,"%s255\0",gpio_cmd[index]);
                set_klipper_cmd(cmd);
            }
            else  if(index==5){
                snprintf(cmd,64,"%s1\0",gpio_cmd[5]);
                set_klipper_cmd(cmd);
                snprintf(cmd,64,"%s1\0",gpio_cmd[6]);
                set_klipper_cmd(cmd);
                snprintf(cmd,64,"%s1\0",gpio_cmd[7]);
                set_klipper_cmd(cmd);
            }
            else
            {
                snprintf(cmd,64,"%s1\0",gpio_cmd[index]);
                set_klipper_cmd(cmd);
            }
            

        }
        else
        {
            if(index==5){
                snprintf(cmd,64,"%s0\0",gpio_cmd[5]);
                set_klipper_cmd(cmd);
                snprintf(cmd,64,"%s0\0",gpio_cmd[6]);
                set_klipper_cmd(cmd);
                snprintf(cmd,64,"%s0\0",gpio_cmd[7]);
                set_klipper_cmd(cmd);
            }else{
                //printf("Btn %d Unchecked\n", index);
                snprintf(cmd,64,"%s0\0",gpio_cmd[index]);
                set_klipper_cmd(cmd);
            }
            
        }
    }
}

/**
 * @description: GPIO测试项初始化
 * @param  {*}
 * @return {*}
 */
static void factory_item_gpio_test_init(void)
{
    item_gpio_obj = lv_obj_create(lv_scr_act());
    lv_obj_set_style_radius(item_gpio_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(item_gpio_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_border_width(item_gpio_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(item_gpio_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(item_gpio_obj, 800, 480);

    item_gpio_title_label = ui_factory_add_label(item_gpio_obj, item_text[ITEM_GPIO], lv_font25.font, lv_color_white(),
                                                 LV_ALIGN_TOP_MID, item_gpio_obj, 0, 25);

    item_gpio_return_btn = ui_factory_add_btn(item_gpio_obj, 130, 50, COLOR_BTN_RETURN,
                                              btn_text[0], lv_color_white(), lv_font25.font, item_gpio_return_event_cb, (void *)item_gpio_obj);
    lv_obj_align_to(item_gpio_return_btn, item_gpio_obj, LV_ALIGN_BOTTOM_MID, -75, -20);
    item_gpio_pass_btn = ui_factory_add_btn(item_gpio_obj, 130, 50, COLOR_BTN_PASS,
                                            btn_text[1], lv_color_white(), lv_font25.font, item_gpio_pass_event_cb, (void *)item_gpio_obj);
    lv_obj_align_to(item_gpio_pass_btn, item_gpio_return_btn, LV_ALIGN_OUT_RIGHT_MID, 20, 0);

    // 测试GPIO按钮
    item_gpio_btn0 = ui_factory_add_btn(item_gpio_obj, 130, 50, lv_color_hex(0x50535A),
                                        gpio_text[0], lv_color_white(), lv_font25.font, item_gpio_btn_event_cb, 0);
    lv_obj_align_to(item_gpio_btn0, item_gpio_obj, LV_ALIGN_TOP_LEFT, 130, 80);
    lv_obj_set_style_bg_color(item_gpio_btn0, COLOR_PASS, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_add_flag(item_gpio_btn0, LV_OBJ_FLAG_CHECKABLE);

    item_gpio_btn1 = ui_factory_add_btn(item_gpio_obj, 130, 50, lv_color_hex(0x50535A),
                                        gpio_text[1], lv_color_white(), lv_font25.font, item_gpio_btn_event_cb, 1);
    lv_obj_align_to(item_gpio_btn1, item_gpio_btn0, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
    lv_obj_set_style_bg_color(item_gpio_btn1, COLOR_PASS, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_add_flag(item_gpio_btn1, LV_OBJ_FLAG_CHECKABLE);

    item_gpio_btn2 = ui_factory_add_btn(item_gpio_obj, 130, 50, lv_color_hex(0x50535A),
                                        gpio_text[2], lv_color_white(), lv_font25.font, item_gpio_btn_event_cb, 2);
    lv_obj_align_to(item_gpio_btn2, item_gpio_btn1, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
    lv_obj_set_style_bg_color(item_gpio_btn2, COLOR_PASS, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_add_flag(item_gpio_btn2, LV_OBJ_FLAG_CHECKABLE);

    item_gpio_btn3 = ui_factory_add_btn(item_gpio_obj, 130, 50, lv_color_hex(0x50535A),
                                        gpio_text[3], lv_color_white(), lv_font25.font, item_gpio_btn_event_cb, 3);
    lv_obj_align_to(item_gpio_btn3, item_gpio_btn2, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
    lv_obj_set_style_bg_color(item_gpio_btn3, COLOR_PASS, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_add_flag(item_gpio_btn3, LV_OBJ_FLAG_CHECKABLE);

    item_gpio_btn4 = ui_factory_add_btn(item_gpio_obj, 130, 50, lv_color_hex(0x50535A),
                                        gpio_text[4], lv_color_white(), lv_font25.font, item_gpio_btn_event_cb, 4);
    lv_obj_align_to(item_gpio_btn4, item_gpio_btn0, LV_ALIGN_OUT_RIGHT_MID, 20, 0);
    lv_obj_set_style_bg_color(item_gpio_btn4, COLOR_PASS, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_add_flag(item_gpio_btn4, LV_OBJ_FLAG_CHECKABLE);

    item_gpio_btn5 = ui_factory_add_btn(item_gpio_obj, 130, 50, lv_color_hex(0x50535A),
                                        gpio_text[5], lv_color_white(), lv_font25.font, item_gpio_btn_event_cb, 5);
    lv_obj_align_to(item_gpio_btn5, item_gpio_btn1, LV_ALIGN_OUT_RIGHT_MID, 20, 0);
    lv_obj_set_style_bg_color(item_gpio_btn5, COLOR_PASS, LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_add_flag(item_gpio_btn5, LV_OBJ_FLAG_CHECKABLE);

    // item_gpio_btn6 = ui_factory_add_btn(item_gpio_obj, 130, 50, lv_color_hex(0x50535A),
    //                                     gpio_text[6], lv_color_white(), lv_font25.font, item_gpio_btn_event_cb, 6);
    // lv_obj_align_to(item_gpio_btn6, item_gpio_btn2, LV_ALIGN_OUT_RIGHT_MID, 20, 0);
    // lv_obj_set_style_bg_color(item_gpio_btn6, COLOR_PASS, LV_PART_MAIN | LV_STATE_CHECKED);
    // lv_obj_add_flag(item_gpio_btn6, LV_OBJ_FLAG_CHECKABLE);

    item_gpio_filament_label = ui_factory_add_label(item_gpio_obj, gpio_filament_text, lv_font25.font, lv_color_white(),
                                                    LV_ALIGN_CENTER, item_gpio_obj, 120, 0);

    item_gpio_filament_led = lv_led_create(item_gpio_obj);
    lv_obj_align_to(item_gpio_filament_led, item_gpio_filament_label, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
    lv_led_off(item_gpio_filament_led);

    get_printer_data(0x06, 1, "7");
}
//==========ADC测试相关==========
/**
 * @description: ADC测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_adc_return_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        item_status_flag[ITEM_ADC] = TEST_FAIL;
        update_item_status();
        lv_obj_del_async(parents);
        item_adc_obj = NULL;
        auto_next_test(ITEM_ADC);
    }
}
/**
 * @description: ADC测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_adc_pass_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        item_status_flag[ITEM_ADC] = TEST_PASS;
        update_item_status();
        lv_obj_del_async(parents);
        item_adc_obj = NULL;
        auto_next_test(ITEM_ADC);
    }
}
void refresh_factory_bed_temp(int temp)
{
    if (!item_adc_obj)
        return;
    char buf[32] = {0};
    snprintf(buf, 32, "%d", temp);
    lv_label_set_text(item_adc_bed_templabel, buf);
    lv_obj_align_to(item_adc_bed_unitlabel, item_adc_bed_templabel, LV_ALIGN_OUT_RIGHT_MID, 10, -10);
}

void refresh_factory_case_temp(int temp)
{
    if (!item_adc_obj)
        return;
    char buf[32] = {0};
    snprintf(buf, 32, "%d", temp);
    lv_label_set_text(item_adc_case_tmeplabel, buf);
    lv_obj_align_to(item_adc_case_unitlabel, item_adc_case_tmeplabel, LV_ALIGN_OUT_RIGHT_MID, 10, -10);
}

static void factory_item_adc_test_init(void)
{
    item_adc_obj = lv_obj_create(lv_scr_act());
    lv_obj_set_style_radius(item_adc_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(item_adc_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_border_width(item_adc_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(item_adc_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(item_adc_obj, 800, 480);

    item_adc_title_label = ui_factory_add_label(item_adc_obj, item_text[ITEM_ADC], lv_font25.font,
                                                lv_color_white(), LV_ALIGN_TOP_MID, item_adc_obj, 0, 25);
    lv_obj_set_size(item_adc_title_label, 400, 50);
    lv_obj_align_to(item_adc_title_label, item_adc_obj, LV_ALIGN_TOP_MID, 0, 25);
    lv_obj_set_style_text_align(item_adc_title_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    item_adc_return_btn = ui_factory_add_btn(item_adc_obj, 130, 50, COLOR_BTN_RETURN,
                                             btn_text[0], lv_color_white(), lv_font25.font, item_adc_return_event_cb, (void *)item_adc_obj);
    lv_obj_align_to(item_adc_return_btn, item_adc_obj, LV_ALIGN_BOTTOM_MID, -75, -20);
    item_adc_pass_btn = ui_factory_add_btn(item_adc_obj, 130, 50, COLOR_BTN_PASS,
                                           btn_text[1], lv_color_white(), lv_font25.font, item_adc_pass_event_cb, (void *)item_adc_obj);
    lv_obj_align_to(item_adc_pass_btn, item_adc_return_btn, LV_ALIGN_OUT_RIGHT_MID, 20, 0);

    item_adc_bed_label = ui_factory_add_label(item_adc_obj, adc_bed_text, lv_font25.font,
                                              lv_color_white(), LV_ALIGN_CENTER, item_adc_obj, 0, 0);
    lv_obj_set_size(item_adc_bed_label, 200, 50);
    lv_obj_align_to(item_adc_bed_label, item_adc_obj, LV_ALIGN_CENTER, -60, -70);
    item_adc_case_label = ui_factory_add_label(item_adc_obj, adc_case_text, lv_font25.font,
                                               lv_color_white(), LV_ALIGN_OUT_BOTTOM_MID, item_adc_bed_label, 0, 50);
    lv_obj_set_size(item_adc_case_label, 200, 50);
    lv_obj_align_to(item_adc_case_label, item_adc_bed_label, LV_ALIGN_OUT_BOTTOM_MID, 0, 50);
    item_adc_bed_templabel = ui_factory_add_label(item_adc_obj, "0", lv_font28.font,
                                                  lv_color_white(), LV_ALIGN_OUT_RIGHT_MID, item_adc_bed_label, 40, -10);
    lv_obj_set_style_text_color(item_adc_bed_templabel, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(item_adc_bed_templabel, LV_SIZE_CONTENT, 50);
    item_adc_bed_unitlabel = ui_factory_add_label(item_adc_obj, "°C", lv_font22.font,
                                                  lv_color_white(), LV_ALIGN_OUT_RIGHT_MID, item_adc_bed_templabel, 10, -10);

    item_adc_case_tmeplabel = ui_factory_add_label(item_adc_obj, "0", lv_font28.font,
                                                   lv_color_white(), LV_ALIGN_OUT_RIGHT_MID, item_adc_case_label, 40, -10);
    lv_obj_set_style_text_color(item_adc_case_tmeplabel, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(item_adc_case_tmeplabel, LV_SIZE_CONTENT, 50);
    item_adc_case_unitlabel = ui_factory_add_label(item_adc_obj, "°C", lv_font22.font,
                                                   lv_color_white(), LV_ALIGN_OUT_RIGHT_MID, item_adc_case_tmeplabel, 10, -10);
    get_printer_data(0x03, 1, "\0");    //温度更新
}
//==========USB测试相关==========
/**
 * @description: USB测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_usb_return_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        item_status_flag[ITEM_USB] = TEST_FAIL;
        update_item_status();
        lv_obj_del_async(parents);
        item_usb_obj = NULL;
        auto_next_test(ITEM_USB);
    }
}
/**
 * @description: USB测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_usb_pass_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        item_status_flag[ITEM_USB] = TEST_PASS;
        update_item_status();
        lv_obj_del_async(parents);
        item_usb_obj = NULL;
        auto_next_test(ITEM_USB);
    }
}
void refresh_factory_usb_status(void)
{
    if (!item_usb_obj)
    return;

    bool ret = false;
    char buf[64] = {0};
    ret = PopenSystem(GET_UDISK_CMD, buf, sizeof(buf));
    if (ret)
    {
        if (buf[0]=='\0')
        {
            lv_label_set_text(item_usb_status_label, udisk_uninsert_text);
            lv_obj_align_to(item_usb_status_label, item_usb_obj, LV_ALIGN_CENTER, 0, -60);
            lv_label_set_text(item_usb_size_label, "0");
            lv_obj_align_to(item_usb_size_label, item_usb_size_text_label, LV_ALIGN_OUT_RIGHT_MID, 25, 0);
        }
        else 
        {
            lv_label_set_text(item_usb_status_label, udisk_insert_text);
            lv_obj_align_to(item_usb_status_label, item_usb_obj, LV_ALIGN_CENTER, 0, -60);
            lv_label_set_text(item_usb_size_label, buf);
            lv_obj_align_to(item_usb_size_label, item_usb_size_text_label, LV_ALIGN_OUT_RIGHT_MID, 25, 0);
            
        }
    }
    else
    {
        lv_label_set_text(item_usb_status_label, udisk_uninsert_text);
        lv_obj_align_to(item_usb_status_label, item_usb_obj, LV_ALIGN_CENTER, 0, -60);
        lv_label_set_text(item_usb_size_label, "0");
        lv_obj_align_to(item_usb_size_label, item_usb_size_text_label, LV_ALIGN_OUT_RIGHT_MID, 25, 0);
    }
}
/**
 * @description: USB测试重新测试按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_usb_retest_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        refresh_factory_usb_status();
    }
}

static void factory_item_usb_test_init(void)
{
    item_usb_obj = lv_obj_create(lv_scr_act());
    lv_obj_set_style_radius(item_usb_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(item_usb_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_border_width(item_usb_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(item_usb_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(item_usb_obj, 800, 480);

    item_usb_title_label = ui_factory_add_label(item_usb_obj, item_text[ITEM_USB], lv_font25.font,
                                                lv_color_white(), LV_ALIGN_TOP_MID, item_usb_obj, 0, 25);
    lv_obj_set_size(item_usb_title_label, 300, 50);
    lv_obj_align_to(item_usb_title_label, item_usb_obj, LV_ALIGN_TOP_MID, 0, 25);
    lv_obj_set_style_text_align(item_usb_title_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    item_usb_return_btn = ui_factory_add_btn(item_usb_obj, 130, 50, COLOR_BTN_RETURN,
                                             btn_text[0], lv_color_white(), lv_font25.font, item_usb_return_event_cb, (void *)item_usb_obj);
    lv_obj_align_to(item_usb_return_btn, item_usb_obj, LV_ALIGN_BOTTOM_MID, -130, -20);
    item_usb_retest_btn = ui_factory_add_btn(item_usb_obj, 130, 50, COLOR_BTN_RETEST,
                                             btn_text[2], lv_color_white(), lv_font25.font, item_usb_retest_event_cb, (void *)item_mcu_obj);
    lv_obj_align_to(item_usb_retest_btn, item_usb_return_btn, LV_ALIGN_OUT_RIGHT_MID, 20, 0);
    item_usb_pass_btn = ui_factory_add_btn(item_usb_obj, 130, 50, COLOR_BTN_PASS,
                                           btn_text[1], lv_color_white(), lv_font25.font, item_usb_pass_event_cb, (void *)item_usb_obj);
    lv_obj_align_to(item_usb_pass_btn, item_usb_retest_btn, LV_ALIGN_OUT_RIGHT_MID, 20, 0);

    item_usb_status_label = ui_factory_add_label(item_usb_obj, udisk_uninsert_text, lv_font25.font,
                                                 lv_color_white(), LV_ALIGN_CENTER, item_usb_obj, 0, -60);
    item_usb_size_text_label = ui_factory_add_label(item_usb_obj, udisk_size_text, lv_font25.font,
                                                    lv_color_white(), LV_ALIGN_CENTER, item_usb_obj, -40, 0);
    item_usb_size_label = ui_factory_add_label(item_usb_obj, "0", lv_font25.font,
                                               lv_color_white(), LV_ALIGN_OUT_RIGHT_MID, item_usb_obj, 25, 0);
    lv_obj_align_to(item_usb_size_label, item_usb_size_text_label, LV_ALIGN_OUT_RIGHT_MID, 25, 0);
    refresh_factory_usb_status();
}

//==========MCU测试相关==========
void refresh_factory_nuzzle_temp(int temp)
{
    if (!item_mcu_obj)
        return;
    char buf[32] = {0};
    snprintf(buf, 32, "%d", temp);
    lv_label_set_text(item_mcu_nuzzle_temp_label, buf);
    lv_obj_align_to(item_mcu_nuzzle_temp_label, item_mcu_nuzzle_label, LV_ALIGN_OUT_RIGHT_MID, 20, 0);
}
/**
 * @description: MCU通讯测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_mcu_return_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        item_status_flag[ITEM_MCU_COM] = TEST_FAIL;
        update_item_status();
        lv_obj_del_async(parents);
        item_mcu_obj = NULL;
        auto_next_test(ITEM_MCU_COM);
    }
}
/**
 * @description: MCU通讯测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_mcu_pass_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        item_status_flag[ITEM_MCU_COM] = TEST_PASS;
        update_item_status();
        lv_obj_del_async(parents);
        item_mcu_obj = NULL;
        auto_next_test(ITEM_MCU_COM);
    }
}
/**
 * @description: MCU通讯测试HX711
 * @param  {*}
 * @return {*}
 */
static void item_mcu_read_hx711_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);
    if(code == LV_EVENT_CLICKED)
    {
        set_klipper_cmd(CMD_READ_HX711);
    }
}

static void factory_item_mcu_test_init(void)
{
    item_mcu_obj = lv_obj_create(lv_scr_act());
    lv_obj_set_style_radius(item_mcu_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(item_mcu_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_border_width(item_mcu_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(item_mcu_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(item_mcu_obj, 800, 480);

    item_mcu_title_label = ui_factory_add_label(item_mcu_obj, item_text[ITEM_MCU_COM], lv_font25.font,
                                                lv_color_white(), LV_ALIGN_TOP_MID, item_mcu_obj, 0, 25);
    lv_obj_set_size(item_mcu_title_label, 400, 50);
    lv_obj_set_style_text_align(item_mcu_title_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align_to(item_mcu_title_label, item_mcu_obj, LV_ALIGN_TOP_MID, 0, 25);

    item_mcu_return_btn = ui_factory_add_btn(item_mcu_obj, 130, 50, COLOR_BTN_RETURN,
                                             btn_text[0], lv_color_white(), lv_font25.font, item_mcu_return_event_cb, (void *)item_mcu_obj);
    lv_obj_align_to(item_mcu_return_btn, item_mcu_obj, LV_ALIGN_BOTTOM_MID, -75, -20);
    item_mcu_pass_btn = ui_factory_add_btn(item_mcu_obj, 130, 50, COLOR_BTN_PASS,
                                           btn_text[1], lv_color_white(), lv_font25.font, item_mcu_pass_event_cb, (void *)item_mcu_obj);
    lv_obj_align_to(item_mcu_pass_btn, item_mcu_return_btn, LV_ALIGN_OUT_RIGHT_MID, 20, 0);

    item_mcu_nuzzle_label = ui_factory_add_label(item_mcu_obj, nuzzle_text, lv_font25.font,
                                                 lv_color_white(), LV_ALIGN_CENTER, item_mcu_obj, -50, -50);
    lv_obj_set_size(item_mcu_nuzzle_label, 200, 50);
    lv_obj_align_to(item_mcu_nuzzle_label, item_mcu_obj, LV_ALIGN_CENTER, -80, -50);
    lv_obj_set_style_text_align(item_mcu_nuzzle_label, LV_TEXT_ALIGN_RIGHT, LV_PART_MAIN | LV_STATE_DEFAULT);

    item_mcu_nuzzle_temp_label = ui_factory_add_label(item_mcu_obj, "0", lv_font28.font,
                                                      lv_color_white(), LV_ALIGN_OUT_RIGHT_MID, item_mcu_obj, 40, 0);
    lv_obj_set_size(item_mcu_nuzzle_temp_label, 30, 50);
    lv_obj_set_style_text_color(item_mcu_nuzzle_temp_label, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align_to(item_mcu_nuzzle_temp_label, item_mcu_nuzzle_label, LV_ALIGN_OUT_RIGHT_MID, 40, 0);
    lv_obj_set_style_text_align(item_mcu_nuzzle_temp_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);

    item_mcu_temp_unit_label = ui_factory_add_label(item_mcu_obj, "°C", lv_font22.font,
                                                    lv_color_white(), LV_ALIGN_OUT_RIGHT_MID, item_mcu_obj, -10, 0);
    lv_obj_set_size(item_mcu_temp_unit_label, 30, 50);
    lv_obj_align_to(item_mcu_temp_unit_label, item_mcu_nuzzle_temp_label, LV_ALIGN_OUT_RIGHT_MID, -10, 0);
    lv_obj_set_style_text_align(item_mcu_temp_unit_label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);

    // item_mcu_read_hx711_btn = ui_factory_add_btn(item_mcu_obj, 150, 50, COLOR_BTN_PASS,
    //                                       read_HX711_text, lv_color_white(), lv_font25.font, item_mcu_read_hx711_event_cb, (void *)item_mcu_obj);
    // lv_obj_align_to(item_mcu_read_hx711_btn, item_mcu_obj, LV_ALIGN_CENTER, 0, 20);
    
    get_printer_data(0x03, 1, "\0");    //温度更新
}
//==========电机测试相关==========
/**
 * @description: 电机测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_motor_return_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        item_status_flag[ITEM_MOTOR] = TEST_FAIL;
        update_item_status();
        lv_obj_del_async(parents);
        item_motor_obj = NULL;
        auto_next_test(ITEM_MOTOR);
    }
}
/**
 * @description: 电机测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_motor_pass_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        item_status_flag[ITEM_MOTOR] = TEST_PASS;
        update_item_status();
        lv_obj_del_async(parents);
        item_motor_obj = NULL;
        auto_next_test(ITEM_MOTOR);
    }
}

/**
 * @description: 电机测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_motor_btn_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    char *buf = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        if (*buf == 'x')
        {
            set_klipper_cmd(CMD_FORCE_MOVE_X);
        }
        else if (*buf == 'y')
        {
            set_klipper_cmd(CMD_FORCE_MOVE_Y);
        }
        else if (*buf == 'z')
        {
            set_klipper_cmd(CMD_FORCE_MOVE_Z);
        }
        else if (*buf == 'e')
        {
            set_klipper_cmd(CMD_FORCE_MOVE_E);
        }
    }
}
static void factory_item_motor_test_init(void)
{
    item_motor_obj = lv_obj_create(lv_scr_act());
    lv_obj_set_style_radius(item_motor_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(item_motor_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_border_width(item_motor_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(item_motor_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(item_motor_obj, 800, 480);

    item_motor_title_label = ui_factory_add_label(item_motor_obj, item_text[ITEM_MCU_COM], lv_font25.font,
                                                  lv_color_white(), LV_ALIGN_TOP_MID, item_motor_obj, 0, 25);
    lv_obj_set_size(item_motor_title_label, 400, 50);
    lv_obj_align_to(item_motor_title_label, item_motor_obj, LV_ALIGN_TOP_MID, 0, 25);
    lv_obj_set_style_text_align(item_motor_title_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    item_motor_return_btn = ui_factory_add_btn(item_motor_obj, 130, 50, COLOR_BTN_RETURN,
                                               btn_text[0], lv_color_white(), lv_font25.font, item_motor_return_event_cb, (void *)item_motor_obj);
    lv_obj_align_to(item_motor_return_btn, item_motor_obj, LV_ALIGN_BOTTOM_MID, -75, -20);
    item_motor_pass_btn = ui_factory_add_btn(item_motor_obj, 130, 50, COLOR_BTN_PASS,
                                             btn_text[1], lv_color_white(), lv_font25.font, item_motor_pass_event_cb, (void *)item_motor_obj);
    lv_obj_align_to(item_motor_pass_btn, item_motor_return_btn, LV_ALIGN_OUT_RIGHT_MID, 20, 0);

    item_motor_y_btn = ui_factory_add_btn(item_motor_obj, 130, 50, COLOR_BTN_PASS,
                                          motor_y_text, lv_color_white(), lv_font25.font, item_motor_btn_event_cb, (void *)"y");
    lv_obj_align_to(item_motor_y_btn, item_motor_obj, LV_ALIGN_CENTER, 0, -10);

    item_motor_x_btn = ui_factory_add_btn(item_motor_obj, 130, 50, COLOR_BTN_PASS,
                                          motor_x_text, lv_color_white(), lv_font25.font, item_motor_btn_event_cb, (void *)"x");
    lv_obj_align_to(item_motor_x_btn, item_motor_y_btn, LV_ALIGN_OUT_LEFT_MID, -40, 0);

    item_motor_z_btn = ui_factory_add_btn(item_motor_obj, 130, 50, COLOR_BTN_PASS,
                                          motor_z_text, lv_color_white(), lv_font25.font, item_motor_btn_event_cb, (void *)"z");
    lv_obj_align_to(item_motor_z_btn, item_motor_y_btn, LV_ALIGN_OUT_RIGHT_MID, 40, 0);

    // item_motor_e_btn = ui_factory_add_btn(item_motor_obj, 130, 50, COLOR_BTN_PASS,
    //                                       motor_e_text, lv_color_white(), lv_font25.font, item_motor_btn_event_cb, (void *)"e");
    // lv_obj_align_to(item_motor_e_btn, item_motor_y_btn, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);
}

//==========WIFI测试相关==========
static unsigned int wifi_timer_count = 0;
static unsigned int wifi_show_timer_count = 0;
/**
 * @description: wifi列表显示计时器回调
 * @param  {*}
 * @return {*}
 */
static void item_wifi_show_timer_cb(lv_timer_t *timer)
{
    wifi_show_timer_count++;
    lv_obj_t *parents = timer->user_data;
    
    if (wifi_show_timer_count > 4) // 显示1.5s后删除wifi列表退出WIFI测试
    {
        lv_obj_del_async(parents);
        item_wifi_obj = NULL;
        wifi_show_timer_count = 0;
        lv_timer_del(timer);
        auto_next_test(ITEM_WIFI);
    }
}
/**
 * @description: wifi测试超时计时器回调
 * @param  {*}
 * @return {*}
 */
static void item_wifi_timer_cb(lv_timer_t *timer)
{
    wifi_timer_count++;

    lv_obj_t *parents = (lv_obj_t *)timer->user_data;
    if (wifi_timer_count > 13)
    {
        lv_obj_del_async(parents);
        item_wifi_obj = NULL;
        wifi_timer_count = 0;
        lv_timer_del(timer);
        auto_next_test(ITEM_WIFI);
    }
    else if (wifi_timer_count > 10) // 查询WIFI超过10x500ms为超时
    {
        lv_label_set_text(item_wifi_testing_label, wifi_test_fail_text);
        lv_obj_align(item_wifi_testing_label, LV_ALIGN_CENTER, 0, 0);
        item_status_flag[ITEM_WIFI] = TEST_FAIL;
        update_item_status();
    }
}

lv_obj_t *wifi_list_add_item(lv_obj_t *list, char *ssid)
{
    if (!item_wifi_obj)
        return NULL;

    lv_obj_t *cont = lv_obj_create(list);
    lv_obj_set_style_radius(cont, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(cont, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_border_width(cont, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(cont, lv_color_black(), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(cont, lv_pct(100), 50);
    lv_obj_set_style_bg_opa(cont, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(cont, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *img2 = lv_img_create(cont);
    lv_img_set_src(img2, &ui_img_wifi_state_png);
    lv_obj_set_width(img2, LV_SIZE_CONTENT);
    lv_obj_set_height(img2, LV_SIZE_CONTENT);
    lv_obj_add_flag(img2, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(img2, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_align(img2, LV_ALIGN_RIGHT_MID, -28, 0);

    lv_obj_t *label = ui_factory_add_label(cont, ssid, lv_font25.font,
                                           lv_color_white(), LV_ALIGN_TOP_MID, cont, 0, 0);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(label, lv_pct(80), 50);
    lv_obj_align(label, LV_ALIGN_LEFT_MID, 15, 10);

    return cont;
}
void ui_factory_show_wifi_list(char *data, int len)
{
    if (!item_wifi_obj || len <= 0)
        return;
    char dis_wifi_name[60];
    char wifi_type[10] = {0};
    char wifi_dis[10] = {0};
    bool flag;
    unsigned char i = 0,k = 0;

    CrLogI("factory test wifi get data : %s",data);
    char *temp = strtok(data,"\t");
    memset(list_array, 0, 100 * sizeof(wifi_list_t));
    k = 0;
    while(temp)
    {
        CrLogI("factory test wifi single wifi data : %s,%d",temp,k);
        flag = false;
        int result = sscanf(temp, "%[^:]:%[^:]:%[^:]",dis_wifi_name, wifi_type, wifi_dis);
        if( result < 3)
        {
            CrLogE("factory test wifi explain the wifi data error,result count:%d",result);
            return;
        }
        CrLogI("factory test wifi single wifi name : %s",dis_wifi_name);
        CrLogI("factory test wifi single wifi type : %s",wifi_type);
        CrLogI("factory test wifi single wifi dis : %s",wifi_dis);

        if(k >= WIFI_MAX_NUMBER) return;

        switch(wifi_type[0]){
            case '2':{
                wifi_list_add_item(item_wifi_list, dis_wifi_name);
                k++;
                break;                    
            }
            case '1':{
                wifi_list_add_item(item_wifi_list, dis_wifi_name);
                k++;
                break;
            }
            case '0':{
               
                wifi_list_add_item(item_wifi_list, dis_wifi_name);
                k++;
                break;
            }
            default:
                break;
        }
        temp = strtok(NULL,"\t");
    }
    lv_obj_clear_flag(item_wifi_list, LV_OBJ_FLAG_HIDDEN);
    item_wifi_show_timer = lv_timer_create(item_wifi_show_timer_cb, 500, item_wifi_obj);
    lv_timer_ready(item_wifi_show_timer);
    lv_timer_pause(item_wifi_timer);
    lv_timer_del(item_wifi_timer);
    item_status_flag[ITEM_WIFI] = TEST_PASS;
    update_item_status();
}

static void factory_item_wifi_test_init(void)
{
    int i = 0;
    wifi_timer_count = 0;
    item_wifi_obj = lv_obj_create(lv_layer_top());
    lv_obj_set_style_radius(item_wifi_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(item_wifi_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_border_width(item_wifi_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(item_wifi_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(item_wifi_obj, 800, 480);
    lv_obj_set_style_bg_opa(item_wifi_obj, LV_OPA_80, LV_PART_MAIN | LV_STATE_DEFAULT);

    item_wifi_testing_label = ui_factory_add_label(item_wifi_obj, wifi_testing_text, lv_font25.font,
                                                   lv_color_white(), LV_ALIGN_CENTER, item_wifi_obj, 0, 0);
    item_wifi_timer = lv_timer_create(item_wifi_timer_cb, 500, item_wifi_obj);

    item_wifi_list = lv_list_create(item_wifi_obj);
    lv_obj_set_style_bg_color(item_wifi_list, lv_color_hex(0x42BDFA), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(item_wifi_list, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(item_wifi_list, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(item_wifi_list, lv_pct(85), lv_pct(80));
    lv_obj_set_style_pad_row(item_wifi_list, 5, 0);
    lv_obj_align(item_wifi_list, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_flag(item_wifi_list, LV_OBJ_FLAG_HIDDEN);
    // WIFI扫描指令
    get_printer_data(0x07, 1, "2");
}
//==========网口测试相关==========
static unsigned int net_timer_count = 0;


/**
 * @description: 网口测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_motor_return_net_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        item_status_flag[ITEM_NET_PORT] = TEST_FAIL;
        update_item_status();
        lv_obj_del_async(parents);
        item_net_obj = NULL;
        lv_timer_del(item_net_timer);
        auto_next_test(ITEM_NET_PORT);
    }
}
/**
 * @description: 网口测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_motor_pass_net_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        item_status_flag[ITEM_NET_PORT] = TEST_PASS;
        update_item_status();
        lv_obj_del_async(parents);
        item_net_obj = NULL;
        lv_timer_del(item_net_timer);
        auto_next_test(ITEM_NET_PORT);
    }
}

void refresh_factory_net_status(void)
{
    if (item_net_obj == NULL)
        return;
    
    bool ret = 0;
    char ip[128] = {0};
    char speed[128] = {0};

    ret = PopenSystem(GET_NET_IP_CMD, ip, sizeof(ip));
    // if (ret)
    {
        char *chr = strchr(ip, ':');
        if (chr != NULL)
        {
            // printf("ip=%s\n",chr+1);//+1为了去掉冒号
            lv_label_set_text_fmt(item_net_testing_label, "IP:%s", chr + 1);
            lv_obj_align_to(item_net_testing_label,item_net_obj ,LV_ALIGN_CENTER, 0, -30);
            item_status_flag[ITEM_NET_PORT] = TEST_PASS;
            // update_item_status();
            // auto_next_test(ITEM_NET_PORT);
        }
        else
        {
            lv_label_set_text_fmt(item_net_testing_label, "IP:");
            lv_obj_align_to(item_net_testing_label, item_net_obj, LV_ALIGN_CENTER, 0, -30);
        }

        // else
        // {
            // lv_label_set_text(item_net_testing_label, net_test_fail_text);
            // lv_obj_align(item_net_testing_label, LV_ALIGN_CENTER, 0, 0);
            // item_status_flag[ITEM_NET_PORT] = TEST_FAIL;
            // update_item_status();
            // auto_next_test(ITEM_NET_PORT);
        // }
    }
    // else
    // {
        // lv_label_set_text(item_net_testing_label, net_test_fail_text);
        // lv_obj_align(item_net_testing_label, LV_ALIGN_CENTER, 0, 0);
        // item_status_flag[ITEM_NET_PORT] = TEST_FAIL;
        // update_item_status();
        // auto_next_test(ITEM_NET_PORT);
    // }
    ret = PopenSystem(GET_NET_MODEL_CMD, speed, sizeof(speed));
    // if (ret)
    {
        lv_label_set_text_fmt(item_net_model_label, "%s %s", net_test_net_model_text, speed);
        lv_obj_align_to(item_net_model_label, item_net_testing_label, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    }
    // else
    {

    }
    
}
/**
 * @description: 网口测试超时计时器回调
 * @param  {*}
 * @return {*}
 */
static void item_net_timer_cb(lv_timer_t *timer)
{
    net_timer_count++;

    lv_obj_t *parents = (lv_obj_t *)timer->user_data;
    refresh_factory_net_status();
    // if (net_timer_count > 3) // 显示结果2秒后关闭
    // {
        // lv_obj_del_async(parents);
        // item_net_obj = NULL;
        // net_timer_count = 0;
        // lv_timer_del(timer);
    // }
}
static void factory_item_net_test_init(void)
{
    int i = 0;
    bool ret = 0;
    char ip[128] = {0};

    net_timer_count = 0;
    item_net_obj = lv_obj_create(lv_layer_top());
    lv_obj_set_style_radius(item_net_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(item_net_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_border_width(item_net_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(item_net_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(item_net_obj, 800, 480);
    lv_obj_set_style_bg_opa(item_net_obj, LV_OPA_100, LV_PART_MAIN | LV_STATE_DEFAULT);

    item_net_testing_label = ui_factory_add_label(item_net_obj, net_test_net_ip_text, lv_font25.font,
                                                  lv_color_white(), LV_ALIGN_CENTER, item_net_obj, 0, -30);
    lv_obj_set_size(item_net_testing_label, LV_SIZE_CONTENT, 50);

    item_net_model_label = ui_factory_add_label(item_net_obj, net_test_net_model_text, lv_font25.font,
                                                  lv_color_white(), LV_ALIGN_CENTER, item_net_obj, 0, 0);
    lv_obj_align_to(item_net_model_label, item_net_testing_label, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);

    

    item_touch_return_net = ui_factory_add_btn(item_net_obj, 130, 50, COLOR_BTN_RETURN,
                                              btn_text[0], lv_color_white(), lv_font25.font, item_motor_return_net_cb, (void *)item_net_obj);
    lv_obj_align_to(item_touch_return_net, item_net_obj, LV_ALIGN_BOTTOM_MID, -75, -20);
    item_touch_pass_net = ui_factory_add_btn(item_net_obj, 130, 50, COLOR_BTN_PASS,
                                            btn_text[1], lv_color_white(), lv_font25.font, item_motor_pass_net_cb, (void *)item_net_obj);
    lv_obj_align_to(item_touch_pass_net, item_touch_return_net, LV_ALIGN_OUT_RIGHT_MID, 20, 0);


    // refresh_factory_usb_status();
    item_net_timer = lv_timer_create(item_net_timer_cb, 500, item_net_obj);
}

//==========蜂鸣器测试相关==========

/**
 * @description: 蜂鸣器测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_motor_return_buzzer_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        item_status_flag[ITEM_BUZZER] = TEST_FAIL;
        update_item_status();
        lv_obj_del_async(parents);
        item_buzzer_obj = NULL;
        auto_next_test(ITEM_BUZZER);
    }
}
/**
 * @description: ；蜂鸣器测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_motor_pass_buzzer_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        item_status_flag[ITEM_BUZZER] = TEST_PASS;
        update_item_status();
        lv_obj_del_async(parents);
        item_buzzer_obj = NULL;
        auto_next_test(ITEM_BUZZER);
    }
}
/**
 * @description: ；蜂鸣器测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_play_buzzer_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        char audioPlay[256]={0};
        snprintf(audioPlay, 256, "aplay %s/%s/%s", \
            GetDefaultLanguagePtah(), "chinese", "1.button_beep.wav");

        system(audioPlay);
        //send_buzzer(0x01);
    }
}

static void factory_item_buzzer_test_init()
{
    int i = 0;
    bool ret = 0;
    char ip[128] = {0};

    item_buzzer_obj = lv_obj_create(lv_layer_top());
    lv_obj_set_style_radius(item_buzzer_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(item_buzzer_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_border_width(item_buzzer_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(item_buzzer_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(item_buzzer_obj, 800, 480);
    lv_obj_set_style_bg_opa(item_buzzer_obj, LV_OPA_100, LV_PART_MAIN | LV_STATE_DEFAULT);
    

    item_touch_return_buzzer = ui_factory_add_btn(item_buzzer_obj, 130, 50, COLOR_BTN_RETURN,
                                              btn_text[0], lv_color_white(), lv_font25.font, item_motor_return_buzzer_cb, (void *)item_buzzer_obj);
    lv_obj_align_to(item_touch_return_buzzer, item_buzzer_obj, LV_ALIGN_BOTTOM_MID, -75, -20);
    item_touch_pass_buzzer = ui_factory_add_btn(item_buzzer_obj, 130, 50, COLOR_BTN_PASS,
                                            btn_text[1], lv_color_white(), lv_font25.font, item_motor_pass_buzzer_cb, (void *)item_buzzer_obj);
    lv_obj_align_to(item_touch_pass_buzzer, item_touch_return_buzzer, LV_ALIGN_OUT_RIGHT_MID, 20, 0);

    item_paly_buzzer = ui_factory_add_btn(item_buzzer_obj, 130, 50, COLOR_BTN_PASS,
                                            play_text, lv_color_white(), lv_font25.font, item_play_buzzer_cb, (void *)item_buzzer_obj);
    lv_obj_align_to(item_paly_buzzer, item_buzzer_obj, LV_ALIGN_CENTER, 0, 0);
    // refresh_factory_usb_status();
    // item_net_timer = lv_timer_create(item_net_timer_cb, 500, item_buzzer_obj);
}

//==========version测试相关==========

/**
 * @description: version测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_motor_return_version_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        item_status_flag[ITEM_VERSION] = TEST_FAIL;
        update_item_status();
        lv_obj_del_async(parents);
        item_version_obj = NULL;
        auto_next_test(ITEM_VERSION);
    }
}
/**
 * @description: ；version测试返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void item_motor_pass_version_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *parents = lv_event_get_user_data(e);

    if (code == LV_EVENT_CLICKED)
    {
        item_status_flag[ITEM_VERSION] = TEST_PASS;
        update_item_status();
        lv_obj_del_async(parents);
        item_version_obj = NULL;
        auto_next_test(ITEM_VERSION);
    }
}

static void factory_item_version_test_init()
{
    char cmd[128]={0};
    item_version_obj = lv_obj_create(lv_layer_top());
    lv_obj_set_style_radius(item_version_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_clear_flag(item_version_obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_border_width(item_version_obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(item_version_obj, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(item_version_obj, 800, 480);
    lv_obj_set_style_bg_opa(item_version_obj, LV_OPA_100, LV_PART_MAIN | LV_STATE_DEFAULT);

    item_touch_return_version = ui_factory_add_btn(item_version_obj, 130, 50, COLOR_BTN_RETURN,
                                              btn_text[0], lv_color_white(), lv_font25.font, item_motor_return_version_cb, (void *)item_version_obj);
    lv_obj_align_to(item_touch_return_version, item_version_obj, LV_ALIGN_BOTTOM_MID, -75, -20);
    item_touch_pass_version = ui_factory_add_btn(item_version_obj, 130, 50, COLOR_BTN_PASS,
                                            btn_text[1], lv_color_white(), lv_font25.font, item_motor_pass_version_cb, (void *)item_version_obj);
    lv_obj_align_to(item_touch_pass_version, item_touch_return_version, LV_ALIGN_OUT_RIGHT_MID, 20, 0);

    // Get System Config
    SystemConfig_t config = GetSystemConfig();
    // CrLogI("device model = %d", config.model);
    CrLogI("fw_version = %s\n", config.fw_version);
    CrLogI("hw_version = %s\n", config.hw_version);
    CrLogI("model = %d\n", config.model);
    CrLogI("device_sn = %d\n", config.device_sn);
    CrLogI("device_mac = %d\n", config.device_mac);
    // 软件版本
    memset(cmd, 0, sizeof(cmd));
    sprintf(cmd, "%s %s",version_text[0], config.fw_version);
    item_ersion_fw_text = ui_factory_add_label(item_version_obj, cmd, lv_font25.font,
                                                  lv_color_white(), LV_ALIGN_LEFT_MID, item_net_obj, 0, 0);
    lv_obj_align_to(item_ersion_fw_text, item_version_obj, LV_ALIGN_TOP_MID, -70, 50);
    // 硬件版本
    memset(cmd, 0, sizeof(cmd));
    sprintf(cmd, "%s %s",version_text[1], config.hw_version);
    item_ersion_hw_text = ui_factory_add_label(item_version_obj, cmd, lv_font25.font,
                                                  lv_color_white(), LV_ALIGN_LEFT_MID, item_net_obj, 0, 0);
    lv_obj_align_to(item_ersion_hw_text, item_ersion_fw_text, LV_ALIGN_LEFT_MID, 0, 50);
    // label
    memset(cmd, 0, sizeof(cmd));
    sprintf(cmd, "%s %d",version_text[2], config.model);
    item_ersion_model_text = ui_factory_add_label(item_version_obj, cmd, lv_font25.font,
                                                  lv_color_white(), LV_ALIGN_LEFT_MID, item_net_obj, 0, 0);
    lv_obj_align_to(item_ersion_model_text, item_ersion_hw_text, LV_ALIGN_LEFT_MID, 0, 50);
    // sn号
    memset(cmd, 0, sizeof(cmd));
    sprintf(cmd, "%s %s",version_text[3], config.device_sn);
    item_ersion_sn_text = ui_factory_add_label(item_version_obj, cmd, lv_font25.font,
                                                  lv_color_white(), LV_ALIGN_LEFT_MID, item_net_obj, 0, 0);
    lv_obj_align_to(item_ersion_sn_text, item_ersion_model_text, LV_ALIGN_LEFT_MID, 0, 50);
    // mac
    memset(cmd, 0, sizeof(cmd));
    sprintf(cmd, "%s %s",version_text[4], config.device_mac);
    item_ersion_mac_text = ui_factory_add_label(item_version_obj, cmd, lv_font25.font,
                                                  lv_color_white(), LV_ALIGN_LEFT_MID, item_net_obj, 0, 0);
    lv_obj_align_to(item_ersion_mac_text, item_ersion_sn_text, LV_ALIGN_LEFT_MID, 0, 50);

    

    // static lv_obj_t *item_ersion_fw_text;
    // static lv_obj_t *item_ersion_hw_text;
    // static lv_obj_t *item_ersion_model_text;
    // static lv_obj_t *item_ersion_sn_text;
    // static lv_obj_t *item_ersion_mac_text;

}   

//======================================================================
/**
 * @description: 工厂测试项事件处理函数
 * @param  {*}
 * @return {*}
 */
static void item_event_handler(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    int index = lv_event_get_user_data(e);
    if (code == LV_EVENT_CLICKED)
    {
        switch (index)
        {
        case ITEM_LCD:
            factory_item_lcd_test_init();
            break;
        case ITEM_TOUCH:
            // factory_item_touch_test_init();
            factory_item_touch_test_init2();
            // lv_100ask_sketchpad_simple_test();
            break;
        // case ITEM_BRIGHTNESS:
        //     factory_item_brightness_test_init();
        case ITEM_EEPROM:
            factory_item_eeprom_test_init();
            break;
        case ITEM_GPIO:
            factory_item_gpio_test_init();
            break;
        case ITEM_ADC:
            factory_item_adc_test_init();
            break;
        case ITEM_USB:
            factory_item_usb_test_init();
            break;
        case ITEM_MCU_COM:
            factory_item_mcu_test_init();
            break;
        case ITEM_MOTOR:
            factory_item_motor_test_init();
            break;
        case ITEM_WIFI:
            factory_item_wifi_test_init();
            break;
        case ITEM_NET_PORT:
            factory_item_net_test_init();
            break;
        case ITEM_BUZZER:
            factory_item_buzzer_test_init();
            break;
        case ITEM_VERSION:
            factory_item_version_test_init();
            break;
        }
    }
}

void ui_load_FactotytestScreen(void)
{
    if (ui_ScreenFactoryTestScreen)
        lv_disp_load_scr(ui_ScreenFactoryTestScreen);
    send_get_fans_status_cmd();
    send_get_light_status_cmd();
    send_get_wifi_status_cmd();
    send_get_print_status();
}

/**
 * @description: ；产测结束返回按钮回调
 * @param  {*}
 * @return {*}
 */
static void factory_test_finish_return_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_CLICKED)
    {
        DisFactoryTestControl(FACTORY_TEST_STOP);
    }
}

void ui_ScreenFactoryTest_screen_init(void)
{
    int i = 0;
    ui_ScreenFactoryTestScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_ScreenFactoryTestScreen, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(ui_ScreenFactoryTestScreen, lv_color_hex(0x1F1F20), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ScreenFactoryTestScreen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ScreenFactoryTestScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(ui_ScreenFactoryTestScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_factory_title_label = ui_factory_add_label(ui_ScreenFactoryTestScreen, title_text, lv_font25.font,
                                                  lv_color_white(), LV_ALIGN_TOP_MID, ui_ScreenFactoryTestScreen, 0, 25);

    ui_factory_return_btn = ui_factory_add_btn(ui_ScreenFactoryTestScreen, 130, 50, lv_color_hex(0x4190A2), return_text, 
                                                   lv_color_white(), lv_font25.font, factory_test_finish_return_cb, NULL);

    ui_factory_auto_test_sw = lv_switch_create(ui_ScreenFactoryTestScreen);
    lv_obj_add_state(ui_factory_auto_test_sw, LV_STATE_CHECKED);
    lv_obj_set_size(ui_factory_auto_test_sw, 80, 40);
    lv_obj_set_style_bg_color(ui_factory_auto_test_sw, COLOR_BTN_PASS, LV_PART_INDICATOR | LV_STATE_CHECKED);
    lv_obj_align_to(ui_factory_auto_test_sw, ui_ScreenFactoryTestScreen, LV_ALIGN_TOP_RIGHT, -20, 25);

    auto_test_label = ui_factory_add_label(ui_ScreenFactoryTestScreen, auto_test_text, lv_font25.font, lv_color_white(),
                                        LV_ALIGN_OUT_LEFT_MID, ui_factory_auto_test_sw, -10, 0);
    lv_obj_set_style_text_align(auto_test_label,LV_TEXT_ALIGN_RIGHT,LV_PART_MAIN | LV_STATE_DEFAULT);
    
    ui_ItemCont = lv_obj_create(ui_ScreenFactoryTestScreen);
    lv_obj_set_style_pad_top(ui_ItemCont, 50, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ItemCont, LV_OPA_0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_ItemCont, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ItemCont, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_size(ui_ItemCont, 800, 400);
    lv_obj_set_flex_flow(ui_ItemCont, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_style_flex_main_place(ui_ItemCont, LV_FLEX_ALIGN_SPACE_EVENLY, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_ItemCont, 40, 0);
    lv_obj_set_style_pad_column(ui_ItemCont, 15, 0);
    lv_obj_set_style_layout(ui_ItemCont, LV_LAYOUT_FLEX, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_align_to(ui_ItemCont, ui_ScreenFactoryTestScreen, LV_ALIGN_BOTTOM_MID, 0, 0);
    // lv_obj_set_style_base_dir(ui_ItemCont, LV_BASE_DIR_NEUTRAL, 0);

    for (i = 0; i < ITEM_NUM; i++)
    {
        uint8_t col = i % 3;
        uint8_t row = i / 3;

        ui_ItemObj[i] = lv_obj_create(ui_ItemCont);
        lv_obj_set_style_border_color(ui_ItemObj[i], lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_size(ui_ItemObj[i], 110, 120);
        lv_obj_set_style_pad_all(ui_ItemObj[i], 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_clear_flag(ui_ItemObj[i], LV_OBJ_FLAG_SCROLLABLE);
        lv_obj_set_style_radius(ui_ItemObj[i], 5, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_style_bg_color(ui_ItemObj[i], lv_color_hex(0x50535A), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_set_grid_cell(ui_ItemObj[i], LV_GRID_ALIGN_CENTER, col, 1, LV_GRID_ALIGN_CENTER, row, 1);
        lv_obj_set_style_border_side(ui_ItemObj[i], LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_set_style_border_color(ui_ItemObj[i], lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_PRESSED);
        lv_obj_add_event_cb(ui_ItemObj[i], item_event_handler, LV_EVENT_CLICKED, i);

        lv_obj_t *label = lv_label_create(ui_ItemObj[i]);
        lv_label_set_text_fmt(label, "%s", item_text[i]);
        lv_obj_set_size(label, 110, LV_SIZE_CONTENT);
        lv_obj_set_style_text_font(label, lv_font22.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
        lv_obj_set_style_text_color(label, lv_color_white(), LV_PART_MAIN | LV_STATE_DEFAULT);
        lv_obj_center(label);
        lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    }
}