#include "src/misc/lv_area.h"
#include "ui.h"
#include "mult_language.h"

lv_obj_t *ui_SelftestAll;
lv_obj_t *ui_SelftestAlltitle;
lv_obj_t *ui_SelftestAll_Panel1;
lv_obj_t *ui_SelftestAllImage1;
lv_obj_t *ui_SelftestAlllabel1;
lv_obj_t *ui_SelftestAll_Panel2;
lv_obj_t *ui_SelftestAll_test1;
lv_obj_t *ui_test1_name;  //项目1--喷嘴加热
lv_obj_t *ui_test1_resultimg;
lv_obj_t *ui_test1_checking;
lv_obj_t *ui_test1_wait_gif;

lv_obj_t *ui_SelftestAll_test2;
lv_obj_t *ui_test2_name;  //项目2-热床加热
lv_obj_t *ui_test2_resultimg;
lv_obj_t *ui_test2_checking;
lv_obj_t *ui_test2_wait_gif;

lv_obj_t *ui_SelftestAll_test3;
lv_obj_t *ui_test3_name;  //项目3-喉管散热风扇
lv_obj_t *ui_test3_resultimg;
lv_obj_t *ui_test3_checking;
lv_obj_t *ui_test3_wait_gif;

lv_obj_t *ui_SelftestAll_test4;
lv_obj_t *ui_test4_name;  //项目4-主板散热风扇
lv_obj_t *ui_test4_resultimg;
lv_obj_t *ui_test4_checking;
lv_obj_t *ui_test4_wait_gif;

lv_obj_t *ui_SelftestAll_test5;
lv_obj_t *ui_test5_name;  //项目5-振纹优化
lv_obj_t *ui_test5_resultimg;
lv_obj_t *ui_test5_checking;
lv_obj_t *ui_test5_wait_gif;

lv_obj_t *ui_SelftestAll_test6;
lv_obj_t *ui_test6_name;  //项目6-自动调平
lv_obj_t *ui_test6_resultimg;
lv_obj_t *ui_test6_checking;
lv_obj_t *ui_test6_wait_gif;

lv_obj_t *ui_SelftestAll_test7;
lv_obj_t *ui_test7_name;
lv_obj_t *ui_test7_resultimg;
lv_obj_t *ui_test7_checking;
lv_obj_t *ui_test7_wait_gif;

lv_obj_t *ui_SelftestAll_test8;
lv_obj_t *ui_test8_name;
lv_obj_t *ui_test8_resultimg;
lv_obj_t *ui_test8_checking;
lv_obj_t *ui_test8_wait_gif;

lv_style_t test_panle_default;
lv_style_t test_label_default;
lv_style_t test_img_default;

lv_obj_t *Msgbox1Bg;
lv_obj_t *Msgbox1;
lv_obj_t *MsgBoxTitle;
lv_obj_t *MsgBoxContent;
lv_obj_t *MsgboxBtn1;
lv_obj_t *MsgboxBtn2;
lv_obj_t *MsgboxBtnlabel1;
lv_obj_t *MsgboxBtnlabel2;

bool startcheck_flag = false; //开始自检的标志，避免错误响应
int  errorcheck_flag = 0;     //错误项标志，用于错误弹窗显示
int process_flag = 0;        //进度标志，避免重复执行某一个项目
int currentcheck = 0;
int HotendTargetTemp = 0;
int BedTargetTemp = 0;
bool start_selftest_upload = false; //上传日志的标志量
bool check_CxyUserinfo_flag = false;//检查创想云状态标志量

lv_timer_t * hotendcheck;
lv_timer_t * bedcheck;
lv_timer_t * hotfancheck;
lv_timer_t * boardfancheck;
lv_timer_t * ringingcheck;
lv_timer_t * autolevelcheck;
lv_timer_t * aiLiDARcheck;

// #define SELFCHECK_COUNT 8
// typedef struct {
//     lv_obj_t *panle;
//     lv_obj_t *test_name;
//     lv_obj_t *test_resultimg;
//     lv_obj_t *test_checkinglabel;
// }SingleCheckPanel_t;

// SingleCheckPanel_t checklist[SELFCHECK_COUNT];
// SingleCheckPanel_t create_single_panle(lv_obj_t *parent, lv_align_t mode, lv_coord_t x, lv_coord_t y)
// {

// }
void ui_event_SelftestAll(lv_event_t * e);
void ui_event_Msgbox1(lv_event_t * e);
void LoadSelftestScreen(void);
void SelfTestAllPageChangeObjs(uint8_t index);

void style_init(void)
{
    lv_style_init(&test_panle_default);
	lv_style_reset(&test_panle_default);
	lv_style_set_radius(&test_panle_default, 8);
	lv_style_set_bg_color(&test_panle_default, lv_color_make(0x29, 0x29, 0x2C));
	lv_style_set_bg_opa(&test_panle_default, 0);
	lv_style_set_border_color(&test_panle_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&test_panle_default, 0);
	lv_style_set_pad_all(&test_panle_default, 0);

    lv_style_init(&test_label_default);
	lv_style_reset(&test_label_default);
	lv_style_set_radius(&test_label_default, 0);
	lv_style_set_bg_color(&test_label_default, lv_color_make(0x29, 0x29, 0x2C));
	lv_style_set_bg_opa(&test_label_default, 0);
	lv_style_set_border_color(&test_label_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&test_label_default, 0);
	lv_style_set_pad_all(&test_label_default, 0);
	lv_style_set_text_color(&test_label_default, lv_color_make(0x6a, 0x70, 0x7d));
	lv_style_set_text_letter_space(&test_label_default, 0);
    lv_style_set_text_font(&test_label_default, lv_font30.font);

	lv_style_init(&test_img_default);
    lv_style_reset(&test_img_default);
    lv_style_set_img_recolor(&test_img_default, lv_color_make(0xff, 0xff, 0xff));
    lv_style_set_img_recolor_opa(&test_img_default, 0);
    lv_style_set_img_opa(&test_img_default, 255);
}

void ui_SelftestAll_screen_init(void)
{
    uint8_t language_index = get_cur_language_index();
    ui_SelftestAll = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_SelftestAll, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_SelftestAll, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestAll, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestAll, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    init_pages(ui_SelftestAll, SelfTestAllPageChangeObjs, LoadSelftestScreen);

    ui_SelftestAlltitle = lv_label_create(ui_SelftestAll);
    lv_obj_set_width(ui_SelftestAlltitle, 600);
    lv_obj_set_height(ui_SelftestAlltitle, 34);
    // lv_obj_set_x(ui_SelftestAlltitle, 0);
    // lv_obj_set_y(ui_SelftestAlltitle, 20);
    lv_obj_align(ui_SelftestAlltitle, LV_ALIGN_TOP_MID, 0, 74);

    lv_label_set_text(ui_SelftestAlltitle, PrinterSelfTest[language_index]);
    lv_obj_set_style_text_color(ui_SelftestAlltitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SelftestAlltitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_SelftestAlltitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_SelftestAlltitle, lv_font32.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    //左侧检测图片示意栏
    // ui_SelftestAll_Panel1 = lv_obj_create(ui_SelftestAll);
    // lv_obj_set_width(ui_SelftestAll_Panel1, 302);
    // lv_obj_set_height(ui_SelftestAll_Panel1, 398);
    // lv_obj_set_x(ui_SelftestAll_Panel1, 14);
    // lv_obj_set_y(ui_SelftestAll_Panel1, 64);
    // lv_obj_clear_flag(ui_SelftestAll_Panel1, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    // lv_obj_set_style_radius(ui_SelftestAll_Panel1, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_SelftestAll_Panel1, lv_color_hex(0x1C1C1D), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_SelftestAll_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_grad_color(ui_SelftestAll_Panel1, lv_color_hex(0x080809), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_main_stop(ui_SelftestAll_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_grad_stop(ui_SelftestAll_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_grad_dir(ui_SelftestAll_Panel1, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ui_SelftestAll_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_all(ui_SelftestAll_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_SelftestAllImage1 = lv_img_create(ui_SelftestAll_Panel1);
    // lv_img_set_src(ui_SelftestAllImage1, &ui_img_sensor_state_png);
    // lv_obj_set_width(ui_SelftestAllImage1, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_SelftestAllImage1, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ui_SelftestAllImage1, 14);
    // lv_obj_set_y(ui_SelftestAllImage1, 64);
    // lv_obj_set_align(ui_SelftestAllImage1, LV_ALIGN_TOP_MID);
    // lv_obj_add_flag(ui_SelftestAllImage1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_SelftestAllImage1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    // ui_SelftestAlllabel1 = lv_label_create(ui_SelftestAll_Panel1);
    // lv_obj_set_width(ui_SelftestAlllabel1, 278);   /// 1
    // lv_obj_set_height(ui_SelftestAlllabel1, 100);    /// 1
    // lv_obj_align(ui_SelftestAlllabel1, LV_ALIGN_TOP_MID, 0, 237);
    // lv_label_set_long_mode(ui_SelftestAlllabel1, LV_LABEL_LONG_WRAP);
    // lv_label_set_text(ui_SelftestAlllabel1, RingingTipMsg[language_index]);
    // lv_obj_set_style_text_color(ui_SelftestAlllabel1, lv_color_hex(0xFFD158), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_SelftestAlllabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_align(ui_SelftestAlllabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_SelftestAlllabel1, lv_font25.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_SelftestAll_Panel2 = lv_obj_create(ui_SelftestAll);
    lv_obj_set_width(ui_SelftestAll_Panel2, 640);
    lv_obj_set_height(ui_SelftestAll_Panel2, 300);
    lv_obj_set_x(ui_SelftestAll_Panel2, 0);
    lv_obj_set_y(ui_SelftestAll_Panel2, 120);
    lv_obj_set_style_pad_all(ui_SelftestAll_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SelftestAll_Panel2, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(ui_SelftestAll_Panel2, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_SelftestAll_Panel2, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_style_pad_row(ui_SelftestAll_Panel2, 5,  LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(ui_SelftestAll_Panel2, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(ui_SelftestAll_Panel2, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_SelftestAll_Panel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SelftestAll_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_SelftestAll_Panel2, lv_color_hex(0x080808), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_main_stop(ui_SelftestAll_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_stop(ui_SelftestAll_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_SelftestAll_Panel2, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_SelftestAll_Panel2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    style_init();
    //创建六个检测项目样式
    ui_SelftestAll_test1 = lv_obj_create(ui_SelftestAll_Panel2);
    ui_SelftestAll_test2 = lv_obj_create(ui_SelftestAll_Panel2);
    ui_SelftestAll_test3 = lv_obj_create(ui_SelftestAll_Panel2);
    ui_SelftestAll_test4 = lv_obj_create(ui_SelftestAll_Panel2);
    ui_SelftestAll_test5 = lv_obj_create(ui_SelftestAll_Panel2);
    ui_SelftestAll_test6 = lv_obj_create(ui_SelftestAll_Panel2);
    // ui_SelftestAll_test7 = lv_obj_create(ui_SelftestAll_Panel2);
    // ui_SelftestAll_test8 = lv_obj_create(ui_SelftestAll_Panel2);

    lv_obj_set_width(ui_SelftestAll_test1, 640);
    lv_obj_set_height(ui_SelftestAll_test1, 56);
    // lv_obj_set_align(ui_SelftestAll_test1, LV_ALIGN_TOP_MID);
    // lv_obj_set_x(ui_SelftestAll_test1, 0);
    // lv_obj_set_y(ui_SelftestAll_test1, 20);

    lv_obj_set_width(ui_SelftestAll_test2, 640);
    lv_obj_set_height(ui_SelftestAll_test2, 56);
    // lv_obj_align_to(ui_SelftestAll_test2, ui_SelftestAll_test1, LV_ALIGN_OUT_BOTTOM_MID, 0, 17);

    lv_obj_set_width(ui_SelftestAll_test3, 640);
    lv_obj_set_height(ui_SelftestAll_test3, 56);
    // lv_obj_align_to(ui_SelftestAll_test3, ui_SelftestAll_test2, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);

    lv_obj_set_width(ui_SelftestAll_test4, 640);
    lv_obj_set_height(ui_SelftestAll_test4, 56);
    // lv_obj_align_to(ui_SelftestAll_test4, ui_SelftestAll_test3, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);

    lv_obj_set_width(ui_SelftestAll_test5, 640);
    lv_obj_set_height(ui_SelftestAll_test5, 56);
    // lv_obj_align_to(ui_SelftestAll_test5, ui_SelftestAll_test4, LV_ALIGN_OUT_BOTTOM_MID, 0, 17);

    lv_obj_set_width(ui_SelftestAll_test6, 640);
    lv_obj_set_height(ui_SelftestAll_test6, 56);
    // lv_obj_align_to(ui_SelftestAll_test6, ui_SelftestAll_test5, LV_ALIGN_OUT_BOTTOM_MID, 0, 17);
    
    // lv_obj_set_width(ui_SelftestAll_test7, 455);
    // lv_obj_set_height(ui_SelftestAll_test7, 40);
    // lv_obj_align_to(ui_SelftestAll_test7, ui_SelftestAll_test6, LV_ALIGN_OUT_BOTTOM_MID, 0, 17);

    // lv_obj_set_width(ui_SelftestAll_test8, 455);
    // lv_obj_set_height(ui_SelftestAll_test8, 40);
    // lv_obj_align_to(ui_SelftestAll_test8, ui_SelftestAll_test7, LV_ALIGN_OUT_BOTTOM_MID, 0, 17);

    lv_obj_add_style(ui_SelftestAll_test1, &test_panle_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui_SelftestAll_test2, &test_panle_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui_SelftestAll_test3, &test_panle_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui_SelftestAll_test4, &test_panle_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui_SelftestAll_test5, &test_panle_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(ui_SelftestAll_test6, &test_panle_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    // lv_obj_add_style(ui_SelftestAll_test7, &test_panle_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    // lv_obj_add_style(ui_SelftestAll_test8, &test_panle_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //创建6个项目名称、状态提示、图片
    ui_test1_name       = lv_label_create(ui_SelftestAll_test1);
    ui_test1_resultimg  = lv_img_create(ui_SelftestAll_test1);
    ui_test1_checking   = lv_label_create(ui_SelftestAll_test1);
    ui_test1_wait_gif   = lv_gif_create(ui_SelftestAll_test1);

    ui_test2_name       = lv_label_create(ui_SelftestAll_test2);
    ui_test2_resultimg  = lv_img_create(ui_SelftestAll_test2);
    ui_test2_checking   = lv_label_create(ui_SelftestAll_test2);
    ui_test2_wait_gif   = lv_gif_create(ui_SelftestAll_test2);

    ui_test3_name       = lv_label_create(ui_SelftestAll_test3);
    ui_test3_resultimg  = lv_img_create(ui_SelftestAll_test3);
    ui_test3_checking   = lv_label_create(ui_SelftestAll_test3);
    ui_test3_wait_gif   = lv_gif_create(ui_SelftestAll_test3);

    ui_test4_name       = lv_label_create(ui_SelftestAll_test4);
    ui_test4_resultimg  = lv_img_create(ui_SelftestAll_test4);
    ui_test4_checking   = lv_label_create(ui_SelftestAll_test4);
    ui_test4_wait_gif   = lv_gif_create(ui_SelftestAll_test4);

    ui_test5_name       = lv_label_create(ui_SelftestAll_test5);
    ui_test5_resultimg  = lv_img_create(ui_SelftestAll_test5);
    ui_test5_checking   = lv_label_create(ui_SelftestAll_test5);
    ui_test5_wait_gif   = lv_gif_create(ui_SelftestAll_test5);

    ui_test6_name       = lv_label_create(ui_SelftestAll_test6);
    ui_test6_resultimg  = lv_img_create(ui_SelftestAll_test6);
    ui_test6_checking   = lv_label_create(ui_SelftestAll_test6);
    ui_test6_wait_gif   = lv_gif_create(ui_SelftestAll_test6);

    // ui_test7_name       = lv_label_create(ui_SelftestAll_test7);
    // ui_test7_resultimg  = lv_img_create(ui_SelftestAll_test7);
    // ui_test7_checking   = lv_label_create(ui_SelftestAll_test7);

    // ui_test8_name       = lv_label_create(ui_SelftestAll_test8);
    // ui_test8_resultimg  = lv_img_create(ui_SelftestAll_test8);
    // ui_test8_checking   = lv_label_create(ui_SelftestAll_test8);
    //设置样式及名称
    //项目1--喷嘴加热
    lv_obj_set_width(ui_test1_name, 400);
    lv_obj_set_height(ui_test1_name, LV_SIZE_CONTENT);
    lv_obj_align(ui_test1_name, LV_ALIGN_LEFT_MID, 20, 0);
    lv_label_set_text(ui_test1_name, NozzleHeating[language_index]);
    lv_obj_add_style(ui_test1_name, &test_label_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_test1_name, -10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_test1_name, LV_LABEL_LONG_WRAP);

    lv_obj_set_width(ui_test1_checking, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_test1_checking, LV_SIZE_CONTENT);
    lv_obj_align(ui_test1_checking, LV_ALIGN_RIGHT_MID, -45, 0);
    lv_label_set_text(ui_test1_checking, Checking[language_index]);
    lv_obj_add_style(ui_test1_checking, &test_label_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    //char buff[258] = {0};
    //snprintf(buff, 258, "%s:%s", PNG_DRV_LETTER, "/home/jaylen/work/kl-3.0-64360-ui-source/global/sysConfig/defData/waiting_point.gif");
    lv_obj_set_size(ui_test1_wait_gif, 22, 22);
    lv_obj_align(ui_test1_wait_gif, LV_ALIGN_RIGHT_MID, -20, 0);
    lv_gif_set_src(ui_test1_wait_gif, &ui_img_wait_point_gif);


    lv_obj_set_width(ui_test1_resultimg, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_test1_resultimg, LV_SIZE_CONTENT);
    lv_obj_align(ui_test1_resultimg, LV_ALIGN_RIGHT_MID, -30, 0);
    lv_obj_add_style(ui_test1_resultimg, &test_img_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_img_set_src(ui_test1_resultimg, &ui_img_state_normal_png);

    //项目2-热床加热
    lv_obj_set_width(ui_test2_name, 400);
    lv_obj_set_height(ui_test2_name, LV_SIZE_CONTENT);
    lv_obj_align(ui_test2_name, LV_ALIGN_LEFT_MID, 20, 0);
    lv_label_set_text(ui_test2_name, BedHeating[language_index]);
    lv_obj_add_style(ui_test2_name, &test_label_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_test2_name, -10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_test2_name, LV_LABEL_LONG_WRAP);

    lv_obj_set_width(ui_test2_checking, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_test2_checking, LV_SIZE_CONTENT);
    lv_obj_align(ui_test2_checking, LV_ALIGN_RIGHT_MID, -45, 0);
    lv_label_set_text(ui_test2_checking, Checking[language_index]);
    lv_obj_add_style(ui_test2_checking, &test_label_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    lv_obj_set_size(ui_test2_wait_gif, 22, 22);
    lv_obj_align(ui_test2_wait_gif, LV_ALIGN_RIGHT_MID, -20, 0);
    lv_gif_set_src(ui_test2_wait_gif, &ui_img_wait_point_gif);

    lv_obj_set_width(ui_test2_resultimg, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_test2_resultimg, LV_SIZE_CONTENT);
    lv_obj_align(ui_test2_resultimg, LV_ALIGN_RIGHT_MID, -30, 0);
    lv_obj_add_style(ui_test2_resultimg, &test_img_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_img_set_src(ui_test2_resultimg, &ui_img_state_normal_png);

    //项目3-喉管散热风扇
    lv_obj_set_width(ui_test3_name, 400);
    lv_obj_set_height(ui_test3_name, LV_SIZE_CONTENT);
    lv_obj_align(ui_test3_name, LV_ALIGN_LEFT_MID, 20, 0);
    lv_label_set_text(ui_test3_name, ThroatCoolFan[language_index]);
    lv_obj_add_style(ui_test3_name, &test_label_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_test3_name, -10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_test3_name, LV_LABEL_LONG_WRAP);

    lv_obj_set_width(ui_test3_checking, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_test3_checking, LV_SIZE_CONTENT);
    lv_obj_align(ui_test3_checking, LV_ALIGN_RIGHT_MID, -45, 0);
    lv_label_set_text(ui_test3_checking, Checking[language_index]);
    lv_obj_add_style(ui_test3_checking, &test_label_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    lv_obj_set_size(ui_test3_wait_gif, 22, 22);
    lv_obj_align(ui_test3_wait_gif, LV_ALIGN_RIGHT_MID, -20, 0);
    lv_gif_set_src(ui_test3_wait_gif, &ui_img_wait_point_gif);

    lv_obj_set_width(ui_test3_resultimg, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_test3_resultimg, LV_SIZE_CONTENT);
    lv_obj_align(ui_test3_resultimg, LV_ALIGN_RIGHT_MID, -30, 0);
    lv_obj_add_style(ui_test3_resultimg, &test_img_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_img_set_src(ui_test3_resultimg, &ui_img_state_normal_png);

    //项目4-主板散热风扇
    lv_obj_set_width(ui_test4_name, 400);
    lv_obj_set_height(ui_test4_name, LV_SIZE_CONTENT);
    lv_obj_align(ui_test4_name, LV_ALIGN_LEFT_MID, 20, 0);
    lv_label_set_text(ui_test4_name, BoardCoolFan[language_index]);
    lv_obj_add_style(ui_test4_name, &test_label_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui_test4_name, -2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_test4_name, -10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_test4_name, LV_LABEL_LONG_WRAP);

    lv_obj_set_width(ui_test4_checking, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_test4_checking, LV_SIZE_CONTENT);
    lv_obj_align(ui_test4_checking, LV_ALIGN_RIGHT_MID, -45, 0);
    lv_label_set_text(ui_test4_checking, Checking[language_index]);
    lv_obj_add_style(ui_test4_checking, &test_label_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    lv_obj_set_size(ui_test4_wait_gif, 22, 22);
    lv_obj_align(ui_test4_wait_gif, LV_ALIGN_RIGHT_MID, -20, 0);
    lv_gif_set_src(ui_test4_wait_gif, &ui_img_wait_point_gif);

    lv_obj_set_width(ui_test4_resultimg, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_test4_resultimg, LV_SIZE_CONTENT);
    lv_obj_align(ui_test4_resultimg, LV_ALIGN_RIGHT_MID, -30, 0);
    lv_obj_add_style(ui_test4_resultimg, &test_img_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_img_set_src(ui_test4_resultimg, &ui_img_state_normal_png);
    
    //项目5-振纹优化
    lv_obj_set_width(ui_test5_name, 400);
    lv_obj_set_height(ui_test5_name, LV_SIZE_CONTENT);
    lv_obj_align(ui_test5_name, LV_ALIGN_LEFT_MID, 20, 0);
    lv_label_set_text(ui_test5_name, VibrationOptimization[language_index]);
    lv_obj_add_style(ui_test5_name, &test_label_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_test5_name, -10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_test5_name, LV_LABEL_LONG_WRAP);

    lv_obj_set_width(ui_test5_checking, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_test5_checking, LV_SIZE_CONTENT);
    lv_obj_align(ui_test5_checking, LV_ALIGN_RIGHT_MID, -45, 0);
    lv_label_set_text(ui_test5_checking, Checking[language_index]);
    lv_obj_add_style(ui_test5_checking, &test_label_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    lv_obj_set_size(ui_test5_wait_gif, 22, 22);
    lv_obj_align(ui_test5_wait_gif, LV_ALIGN_RIGHT_MID, -20, 0);
    lv_gif_set_src(ui_test5_wait_gif, &ui_img_wait_point_gif);

    lv_obj_set_width(ui_test5_resultimg, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_test5_resultimg, LV_SIZE_CONTENT);
    lv_obj_align(ui_test5_resultimg, LV_ALIGN_RIGHT_MID, -30, 0);
    lv_obj_add_style(ui_test5_resultimg, &test_img_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_img_set_src(ui_test5_resultimg, &ui_img_state_normal_png);
    
    //项目6-自动调平
    lv_obj_set_width(ui_test6_name, 400);
    lv_obj_set_height(ui_test6_name, LV_SIZE_CONTENT);
    lv_obj_align(ui_test6_name, LV_ALIGN_LEFT_MID, 20, 0);
    lv_label_set_text(ui_test6_name, AutoLevel[language_index]);
    lv_obj_add_style(ui_test6_name, &test_label_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_test6_name, -10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_label_set_long_mode(ui_test6_name, LV_LABEL_LONG_WRAP);

    lv_obj_set_width(ui_test6_checking, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_test6_checking, LV_SIZE_CONTENT);
    lv_obj_align(ui_test6_checking, LV_ALIGN_RIGHT_MID, -45, 0);
    lv_label_set_text(ui_test6_checking, Checking[language_index]);
    lv_obj_add_style(ui_test6_checking, &test_label_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    lv_obj_set_size(ui_test6_wait_gif, 22, 22);
    lv_obj_align(ui_test6_wait_gif, LV_ALIGN_RIGHT_MID, -20, 0);
    lv_gif_set_src(ui_test6_wait_gif, &ui_img_wait_point_gif);

    lv_obj_set_width(ui_test6_resultimg, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_test6_resultimg, LV_SIZE_CONTENT);
    lv_obj_align(ui_test6_resultimg, LV_ALIGN_RIGHT_MID, -30, 0);
    lv_obj_add_style(ui_test6_resultimg, &test_img_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_img_set_src(ui_test6_resultimg, &ui_img_state_normal_png);

    // lv_obj_set_width(ui_test7_name, LV_SIZE_CONTENT);
    // lv_obj_set_height(ui_test7_name, LV_SIZE_CONTENT);
    // lv_obj_align(ui_test7_name, LV_ALIGN_LEFT_MID, 27, 0);
    // lv_label_set_text(ui_test7_name, AILIDAR[language_index]);
    // lv_obj_add_style(ui_test7_name, &test_label_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    // lv_obj_set_width(ui_test7_checking, LV_SIZE_CONTENT);
    // lv_obj_set_height(ui_test7_checking, LV_SIZE_CONTENT);
    // lv_obj_align(ui_test7_checking, LV_ALIGN_RIGHT_MID, -27, 0);
    // lv_label_set_text(ui_test7_checking, Checking[language_index]);
    // lv_obj_add_style(ui_test7_checking, &test_label_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    // lv_obj_set_width(ui_test7_resultimg, LV_SIZE_CONTENT);
    // lv_obj_set_height(ui_test7_resultimg, LV_SIZE_CONTENT);
    // lv_obj_align(ui_test7_resultimg, LV_ALIGN_RIGHT_MID, -35, 0);
    // lv_obj_add_style(ui_test7_resultimg, &test_img_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    // lv_img_set_src(ui_test7_resultimg, &ui_img_state_normal_png);

    // lv_obj_set_width(ui_test8_name, LV_SIZE_CONTENT);
    // lv_obj_set_height(ui_test8_name, LV_SIZE_CONTENT);
    // lv_obj_align(ui_test8_name, LV_ALIGN_LEFT_MID, 27, 0);
    // lv_label_set_text(ui_test8_name, CameraArray[language_index]);
    // lv_obj_add_style(ui_test8_name, &test_label_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    // lv_obj_set_width(ui_test8_checking, LV_SIZE_CONTENT);
    // lv_obj_set_height(ui_test8_checking, LV_SIZE_CONTENT);
    // lv_obj_align(ui_test8_checking, LV_ALIGN_RIGHT_MID, -27, 0);
    // lv_label_set_text(ui_test8_checking, Checking[language_index]);
    // lv_obj_add_style(ui_test8_checking, &test_label_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    // lv_obj_set_width(ui_test8_resultimg, LV_SIZE_CONTENT);
    // lv_obj_set_height(ui_test8_resultimg, LV_SIZE_CONTENT);
    // lv_obj_align(ui_test8_resultimg, LV_ALIGN_RIGHT_MID, -35, 0);
    // lv_obj_add_style(ui_test8_resultimg, &test_img_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    // lv_img_set_src(ui_test8_resultimg, &ui_img_state_normal_png);

    //创建报错弹窗
    Msgbox1Bg = lv_obj_create(ui_SelftestAll);
    lv_obj_set_width(Msgbox1Bg, 640);
    lv_obj_set_height(Msgbox1Bg, 360);
    lv_obj_set_pos(Msgbox1Bg, 0, 60);
    lv_obj_clear_flag(Msgbox1Bg, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(Msgbox1Bg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(Msgbox1Bg, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(Msgbox1Bg, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(Msgbox1Bg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(Msgbox1Bg, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    Msgbox1 = lv_obj_create(Msgbox1Bg);
    lv_obj_set_width(Msgbox1, 371);
    lv_obj_set_height(Msgbox1, 285);
    lv_obj_set_x(Msgbox1, 132);
    lv_obj_set_y(Msgbox1, 36);
    lv_obj_clear_flag(Msgbox1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(Msgbox1, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(Msgbox1, lv_color_hex(0x29292C), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(Msgbox1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(Msgbox1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_all(Msgbox1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    MsgBoxTitle = lv_label_create(Msgbox1);
    lv_obj_set_width(MsgBoxTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(MsgBoxTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(MsgBoxTitle, 0);
    lv_obj_set_y(MsgBoxTitle, 20);
    lv_obj_set_align(MsgBoxTitle, LV_ALIGN_TOP_MID);
    lv_label_set_long_mode(MsgBoxTitle, LV_LABEL_LONG_SCROLL);
    lv_label_set_text(MsgBoxTitle, KindTips[language_index]);
    lv_obj_set_style_text_color(MsgBoxTitle, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(MsgBoxTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(MsgBoxTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(MsgBoxTitle, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    MsgBoxContent = lv_label_create(Msgbox1);
    lv_obj_set_width(MsgBoxContent, 338);
    lv_obj_set_height(MsgBoxContent, LV_SIZE_CONTENT);
    lv_obj_align(MsgBoxContent, LV_ALIGN_TOP_MID, 0, 100);
    lv_label_set_long_mode(MsgBoxContent, LV_LABEL_LONG_WRAP);
    lv_label_set_text(MsgBoxContent, "");
    lv_obj_set_style_text_color(MsgBoxContent, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(MsgBoxContent, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(MsgBoxContent, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(MsgBoxContent, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);

    MsgboxBtn1 = lv_btn_create(Msgbox1);
    lv_obj_set_width(MsgboxBtn1, 140);
    lv_obj_set_height(MsgboxBtn1, 52);
    lv_obj_set_x(MsgboxBtn1, 30);
    lv_obj_set_y(MsgboxBtn1, 221);
    lv_obj_add_flag(MsgboxBtn1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(MsgboxBtn1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(MsgboxBtn1, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(MsgboxBtn1, lv_color_hex(0xD84242), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(MsgboxBtn1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(MsgboxBtn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(MsgboxBtn1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(MsgboxBtn1, lv_color_hex(0xFFFFFF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(MsgboxBtn1, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(MsgboxBtn1, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(MsgboxBtn1, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(MsgboxBtn1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    MsgboxBtnlabel1 = lv_label_create(MsgboxBtn1);
    lv_obj_set_width(MsgboxBtnlabel1, 120);   /// 1
    lv_obj_set_height(MsgboxBtnlabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(MsgboxBtnlabel1, LV_ALIGN_CENTER);
    lv_label_set_long_mode(MsgboxBtnlabel1, LV_LABEL_LONG_WRAP);
    lv_label_set_text(MsgboxBtnlabel1, UploadErrorTips2[get_cur_language_index()]);//Cancel[language_index]
    lv_obj_set_style_text_color(MsgboxBtnlabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(MsgboxBtnlabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(MsgboxBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(MsgboxBtnlabel1, LV_ALIGN_CENTER,LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(MsgboxBtnlabel1, -10, LV_PART_MAIN | LV_STATE_DEFAULT);

    MsgboxBtn2 = lv_btn_create(Msgbox1);
    lv_obj_set_width(MsgboxBtn2, 140);
    lv_obj_set_height(MsgboxBtn2, 52);
    lv_obj_set_x(MsgboxBtn2, 202);
    lv_obj_set_y(MsgboxBtn2, 221);
    lv_obj_add_flag(MsgboxBtn2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(MsgboxBtn2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(MsgboxBtn2, 6, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(MsgboxBtn2, lv_color_hex(0x42BDD8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(MsgboxBtn2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(MsgboxBtn2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(MsgboxBtn2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    //聚焦样式
    lv_obj_set_style_border_color(MsgboxBtn2, lv_color_hex(0xFFFFFF),
                                  LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_opa(MsgboxBtn2, 255, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_border_width(MsgboxBtn2, 4, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_pad(MsgboxBtn2, 0, LV_PART_MAIN | LV_STATE_FOCUS_KEY);
    lv_obj_set_style_outline_color(MsgboxBtn2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_FOCUS_KEY);


    MsgboxBtnlabel2 = lv_label_create(MsgboxBtn2);
    lv_obj_set_width(MsgboxBtnlabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(MsgboxBtnlabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(MsgboxBtnlabel2, LV_ALIGN_CENTER);
    lv_label_set_text(MsgboxBtnlabel2, ErrorBtnConfirm[language_index]);
    lv_obj_set_style_text_color(MsgboxBtnlabel2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(MsgboxBtnlabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(MsgboxBtnlabel2, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
    
    lv_obj_add_event_cb(MsgboxBtn1, ui_event_Msgbox1, LV_EVENT_ALL, "1");
    lv_obj_add_event_cb(MsgboxBtn2, ui_event_Msgbox1, LV_EVENT_ALL, "2");


    lv_obj_add_event_cb(ui_SelftestAll, ui_event_SelftestAll, LV_EVENT_ALL, NULL);
}

void show_msgbox1(int flag)
{
    CrLogI("selfcheck timeout,%d",flag);
    switch (flag)
    {
    case 1:lv_label_set_text(MsgBoxContent, Error1[get_cur_language_index()]);break;
    case 2:lv_label_set_text(MsgBoxContent, Error2[get_cur_language_index()]);break;
    case 3:lv_label_set_text(MsgBoxContent, Error3[get_cur_language_index()]);break;
    case 4:lv_label_set_text(MsgBoxContent, Error4[get_cur_language_index()]);break;
    case 5:lv_label_set_text(MsgBoxContent, Error5[get_cur_language_index()]);break;
    case 6:lv_label_set_text(MsgBoxContent, Error6[get_cur_language_index()]);break;
    case 7:lv_label_set_text(MsgBoxContent, Error7[get_cur_language_index()]);break;
    case 8:lv_label_set_text(MsgBoxContent, Error8[get_cur_language_index()]);break;
    default:
        break;
    }
    lv_obj_clear_flag(Msgbox1Bg, LV_OBJ_FLAG_HIDDEN); /// Flags
    SelfTestAllPageChangeObjs(2);


}

void TimeoutHandle(lv_timer_t *timer)
{
    char *user_data = timer->user_data;
    CrLogI("checkself timer userdata:%s",user_data);
    if(strcmp(user_data, "0")== 0)
    {
        //开始检测任务
        CrLogI("start checkself all");
        startcheck_flag = true;
        currentcheck = 1;
        refresh_checking_process(0);

        char sendbuff[30] = {0};
        if(HotendTargetTemp + 50 < HOTEND_MAX_EDIT_TEMPER)
        {
            snprintf(sendbuff, 30, "2%d", HotendTargetTemp + 50);
        }
        else
        {
            snprintf(sendbuff, 30, "2%d", HOTEND_MAX_EDIT_TEMPER);
        }
        set_printer_data(0x03, strlen(sendbuff), sendbuff);     //设置喷头升温50度检测加热是否正常
        hotendcheck = lv_timer_create(TimeoutHandle, 1000 * 60, "1");
        lv_timer_set_repeat_count(hotendcheck, 1);
        return;
    }
    if(strcmp(user_data, "1")== 0)
    {
        //喷头长时间未升温
        CrLogE("hotend checkself error");
        set_printer_data(0x03,2,"20");     //喷头降温
        startcheck_flag = false;           //自检结束

        errorcheck_flag = 1;               //错误标志置1
    }
    else if(strcmp(user_data, "2")== 0)
    {
        //热床长时间未升温
        CrLogE("bed checkself error");
        set_printer_data(0x03,2,"10");     //热床降温
        startcheck_flag = false;           //自检结束

        errorcheck_flag = 2;               //错误标志置2
    }
    else if(strcmp(user_data, "3")== 0)
    {
        //喉管风扇异常
        CrLogE("throadfan checkself error");
        set_printer_data(0x03,2,"20");     //喷头降温
        startcheck_flag = false;           //自检结束

        errorcheck_flag = 3;               //错误标志置3
    }
    else if(strcmp(user_data, "4")== 0)
    {
        //主板风扇异常
        CrLogE("borderfan checkself error");
        startcheck_flag = false;           //自检结束

        errorcheck_flag = 4;               //错误标志置4
    }
    else if(strcmp(user_data, "5")== 0)
    {
        //振纹优化时间过长
        CrLogE("ringing checkself timeout");
        startcheck_flag = false;           //自检结束

        errorcheck_flag = 5;               //错误标志置5
    }
    else if(strcmp(user_data, "6")== 0)
    {
        //自动调平时间过长
        CrLogE("autolevel checkself timeout");
        startcheck_flag = false;           //自检结束

        errorcheck_flag = 6;               //错误标志置6
    }
    else if(strcmp(user_data, "7")== 0)
    {
        //自动调平时间过长
        CrLogE("AI LiDAR checkself timeout");
        startcheck_flag = false;           //自检结束
        errorcheck_flag = 7;               //错误标志置7
    }
    else if(strcmp(user_data, "8")== 0)
    {
        //自动调平时间过长
        CrLogE("camera checkself timeout");
        startcheck_flag = false;           //自检结束
        errorcheck_flag = 8;               //错误标志置8
    }

    process_flag = 63;  //后六位都置为1
    currentcheck = 7;
    HotendTargetTemp = 0;
    BedTargetTemp = 0;

    if(hotendcheck != NULL)
    {
        lv_timer_set_repeat_count(hotendcheck, 0);
        CrLogI("hotendcheck timer exist");
    }    
    if(bedcheck != NULL)
    {
        lv_timer_set_repeat_count(bedcheck, 0);
        CrLogI("bedcheck timer exist");
    }       
    if(hotfancheck != NULL)
    {
        lv_timer_set_repeat_count(hotfancheck, 0);
        CrLogI("hotfancheck timer exist");
    }     
    if(boardfancheck != NULL)
    {
        lv_timer_set_repeat_count(boardfancheck, 0);
        CrLogI("boardfancheck timer exist");
    }   
    if(ringingcheck != NULL)
    {
        lv_timer_set_repeat_count(ringingcheck, 0);
        CrLogI("ringingcheck timer exist");
    }   
    if(autolevelcheck != NULL)
    {
        lv_timer_set_repeat_count(autolevelcheck, 0);
        CrLogI("autolevelcheck timer exist");
    }

    hotendcheck = NULL;
    bedcheck = NULL;
    hotfancheck = NULL;
    boardfancheck = NULL;
    ringingcheck = NULL;
    autolevelcheck = NULL;

    show_msgbox1(errorcheck_flag);
}

void ui_event_SelftestAll(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) { 
        char tempbuff[256] = {0};
        // switch (UIType)//TODO: GetK1ImageResourcePtah针对机型源文件路径处理
        // {
        //     case CR_10_H1:break;
        //     case CR_K1:{
        //         snprintf(tempbuff, 256, "S:%s/%s", GetK1ImageResourcePtah(), "K1_CheckTips.png");
        //         lv_img_set_src(ui_SelftestAllImage1, tempbuff);break;
        //     }
        //     case CR_K1_Max:{
        //         snprintf(tempbuff, 256, "S:%s/%s", GetK1MaxImageResourcePtah(), "K1Max_Checktips.png");
        //         lv_img_set_src(ui_SelftestAllImage1, tempbuff);break;
        //     }
        // }
        
        if(selftestflag)
        {
            CrLogI("load page selftestall");
            //刷新检测项位置
            lv_obj_clear_flag(ui_SelftestAll_test1, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_SelftestAll_test2, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_SelftestAll_test3, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_SelftestAll_test4, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_SelftestAll_test5, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_SelftestAll_test6, LV_OBJ_FLAG_HIDDEN);

            lv_obj_set_x(ui_SelftestAll_test1, 0);
            lv_obj_set_y(ui_SelftestAll_test1, 20);
            lv_obj_align_to(ui_SelftestAll_test2, ui_SelftestAll_test1, LV_ALIGN_OUT_BOTTOM_MID, 0, 17);
            lv_obj_align_to(ui_SelftestAll_test3, ui_SelftestAll_test2, LV_ALIGN_OUT_BOTTOM_MID, 0, 17);
            lv_obj_align_to(ui_SelftestAll_test4, ui_SelftestAll_test3, LV_ALIGN_OUT_BOTTOM_MID, 0, 17);
            lv_obj_align_to(ui_SelftestAll_test5, ui_SelftestAll_test4, LV_ALIGN_OUT_BOTTOM_MID, 0, 17);
            lv_obj_align_to(ui_SelftestAll_test6, ui_SelftestAll_test5, LV_ALIGN_OUT_BOTTOM_MID, 0, 17);

            //隐藏检查结果图片、检查中状态
            lv_obj_add_flag(ui_test1_resultimg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test2_resultimg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test3_resultimg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test4_resultimg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test5_resultimg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test6_resultimg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test1_checking, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test2_checking, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test3_checking, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test4_checking, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test5_checking, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test6_checking, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test1_wait_gif, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test2_wait_gif, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test3_wait_gif, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test4_wait_gif, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test5_wait_gif, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test6_wait_gif, LV_OBJ_FLAG_HIDDEN);

            //检测项文字颜色变回默认颜色
            lv_obj_set_style_text_color(ui_test1_name, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_test2_name, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_test3_name, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_test4_name, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_test5_name, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_test6_name, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
            // if(UIType == CR_K1_Max)
            // {
            //     lv_obj_clear_flag(ui_SelftestAll_test7, LV_OBJ_FLAG_HIDDEN);
            //     lv_obj_clear_flag(ui_SelftestAll_test8, LV_OBJ_FLAG_HIDDEN);
            //     lv_obj_align_to(ui_SelftestAll_test7, ui_SelftestAll_test6, LV_ALIGN_OUT_BOTTOM_MID, 0, 17);
            //     lv_obj_align_to(ui_SelftestAll_test8, ui_SelftestAll_test7, LV_ALIGN_OUT_BOTTOM_MID, 0, 17);
            //     lv_obj_add_flag(ui_test7_resultimg, LV_OBJ_FLAG_HIDDEN);
            //     lv_obj_add_flag(ui_test8_resultimg, LV_OBJ_FLAG_HIDDEN);
            //     lv_obj_add_flag(ui_test7_checking, LV_OBJ_FLAG_HIDDEN);
            //     lv_obj_add_flag(ui_test8_checking, LV_OBJ_FLAG_HIDDEN);
            //     lv_obj_set_style_text_color(ui_test7_name, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
            //     lv_obj_set_style_text_color(ui_test8_name, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
            // }
            // else
            // {
            //     lv_obj_add_flag(ui_SelftestAll_test7, LV_OBJ_FLAG_HIDDEN);
            //     lv_obj_add_flag(ui_SelftestAll_test8, LV_OBJ_FLAG_HIDDEN);
            // }

            //获取当前的喷头温度、热床温度
            HotendTargetTemp = atoi(hotend_cur_temp);
            BedTargetTemp = atoi(bed_cur_temp);

            //将所有检测项先置为正常状态
            set_printer_data(0x03, 2, "10");     //热床降温
            set_printer_data(0x03, 2, "20");     //喷头降温
            get_printer_data(0x1b, 2, "9");      //检查是否有风扇反馈功能
            // set_printer_data(0x06, 5, "01\t0");     //关闭模型风扇
            // set_printer_data(0x06, 5, "02\t0");     //关闭辅助风扇

            //创建定时器一秒后开始自检
            lv_timer_t * startcheck = lv_timer_create(TimeoutHandle, 1000, "0");
            lv_timer_set_repeat_count(startcheck, 1);
            startcheck_flag = false;
            process_flag = 0;

            //错误弹窗隐藏
            lv_obj_add_flag(Msgbox1Bg, LV_OBJ_FLAG_HIDDEN); /// Flags
            SelfTestAllPageChangeObjs(1);
            // lv_obj_add_flag(Msgbox2Bg, LV_OBJ_FLAG_HIDDEN); /// Flags

            currentcheck = 0;//当前检测项为0
            // currentcheck = 6;
            // process_flag = 0;
            // startcheck_flag = true;
            // lv_obj_add_flag(Msgbox1Bg, LV_OBJ_FLAG_HIDDEN); /// Flags
            // lv_obj_add_flag(Msgbox2Bg, LV_OBJ_FLAG_HIDDEN); /// Flags
            // check_singleprocess_completed(6, true);
        }
        else
        {
            //错误弹窗隐藏
            lv_obj_add_flag(Msgbox1Bg, LV_OBJ_FLAG_HIDDEN); /// Flags
            // lv_obj_add_flag(Msgbox2Bg, LV_OBJ_FLAG_HIDDEN); /// Flags
            SelfTestAllPageChangeObjs(1);

            lv_obj_add_flag(ui_test5_resultimg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test5_checking, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test5_wait_gif, LV_OBJ_FLAG_HIDDEN);

            lv_obj_add_flag(ui_test6_resultimg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test6_checking, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test6_wait_gif, LV_OBJ_FLAG_HIDDEN);

            lv_obj_set_style_text_color(ui_test5_name, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_test6_name, lv_color_hex(0x6A707D), LV_PART_MAIN | LV_STATE_DEFAULT);

            //手动自检页面暂时屏蔽AI检测和摄像头检测
            // lv_obj_add_flag(ui_SelftestAll_test7, LV_OBJ_FLAG_HIDDEN);
            // lv_obj_add_flag(ui_SelftestAll_test8, LV_OBJ_FLAG_HIDDEN);

            switch (manualtestcount)//1代表手动自检，后续每一位数字代表需要自检的项目
            {
                case 101:{//只有自动调平
                    lv_obj_set_x(ui_SelftestAll_test6, 0);
                    lv_obj_set_y(ui_SelftestAll_test6, 20);

                    lv_obj_add_flag(ui_SelftestAll_test1, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_SelftestAll_test2, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_SelftestAll_test3, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_SelftestAll_test4, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_SelftestAll_test5, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(ui_SelftestAll_test6, LV_OBJ_FLAG_HIDDEN);
                    
                    set_printer_data(0x09, 1, "2");//发送自动调平命令

                    lv_obj_set_style_text_color(ui_test6_name, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(ui_test6_checking, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_clear_flag(ui_test6_checking, LV_OBJ_FLAG_HIDDEN);
                    lv_label_set_text(ui_test6_checking, Checking[get_cur_language_index()]);
                    lv_obj_clear_flag(ui_test6_wait_gif, LV_OBJ_FLAG_HIDDEN);
                    break;
                }
                case 110:{//只有振纹优化
                    lv_obj_set_x(ui_SelftestAll_test5, 0);
                    lv_obj_set_y(ui_SelftestAll_test5, 20);

                    lv_obj_add_flag(ui_SelftestAll_test1, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_SelftestAll_test2, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_SelftestAll_test3, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_SelftestAll_test4, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(ui_SelftestAll_test5, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_SelftestAll_test6, LV_OBJ_FLAG_HIDDEN);
                    
                    set_printer_data(0x1b, 1, "3"); //发送振纹优化命令

                    lv_obj_set_style_text_color(ui_test5_name, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(ui_test5_checking, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_clear_flag(ui_test5_checking, LV_OBJ_FLAG_HIDDEN);
                    lv_label_set_text(ui_test5_checking, Checking[get_cur_language_index()]);
                    lv_obj_clear_flag(ui_test5_wait_gif, LV_OBJ_FLAG_HIDDEN);
                    break;
                }
                case 111:{//振纹优化+自动调平
                    lv_obj_set_x(ui_SelftestAll_test5, 0);
                    lv_obj_set_y(ui_SelftestAll_test5, 20);
                    lv_obj_align_to(ui_SelftestAll_test6, ui_SelftestAll_test5, LV_ALIGN_OUT_BOTTOM_MID, 0, 17);

                    lv_obj_add_flag(ui_SelftestAll_test1, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_SelftestAll_test2, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_SelftestAll_test3, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_SelftestAll_test4, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(ui_SelftestAll_test5, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(ui_SelftestAll_test6, LV_OBJ_FLAG_HIDDEN);

                    set_printer_data(0x1b, 1, "3"); //发送振纹优化命令

                    lv_obj_set_style_text_color(ui_test5_name, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(ui_test5_checking, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_clear_flag(ui_test5_checking, LV_OBJ_FLAG_HIDDEN);
                    lv_label_set_text(ui_test5_checking, Checking[get_cur_language_index()]);
                    lv_obj_clear_flag(ui_test5_wait_gif, LV_OBJ_FLAG_HIDDEN);
                    break;
                }
                default:CrLogI("page init has error.");break;
            }
        }

    }
    if(event_code == LV_EVENT_SCREEN_UNLOADED) {
        startcheck_flag = false;
        process_flag = 0;
    }


}

void selftest_check_cxyuserinfo(bool result)
{
    if (!selftestflag)return;

    if(!check_CxyUserinfo_flag)return;//不是上传前检查则不处理
    check_CxyUserinfo_flag = false;
    if(result)
    {
        CrLogI("has the cxyuserinfo,upload log.");
        set_printer_data(0x1c, 2, "2");//上传日志
        start_selftest_upload = true;
    }
    else
    {
        CrLogI("don't have the cxyuserinfo,change screen page.");
        create_msgbox(DontCXYUserInfo[get_cur_language_index()], NULL, 2000, lv_scr_act());
        _ui_screen_change(ui_SelfTestPageDeviceBinding, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
    }
}

void ui_event_Msgbox1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    char * user_data = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        if(strcmp(user_data, "1") == 0)
        {
            check_CxyUserinfo_flag = true;
            get_printer_data(CONTROL_MACHINE_STATE, 2, "6");//查询创想云绑定状态
            // _ui_screen_change(ui_SelftestTips, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        }
        if(strcmp(user_data, "2") == 0)
        {
            LoadPage(ui_SelftestTips, 1);
            //_ui_screen_change(ui_SelftestTips, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        }
        if(strcmp(user_data, "3") == 0)
        {
            LoadPage(ui_SelftestTips, 1);
            //_ui_screen_change(ui_SelftestTips, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
        }
    }

}

void check_singleprocess_completed(int SeqNumber, bool result)
{
    if(!startcheck_flag)
        return;
    switch(SeqNumber)
    {
        //喷头加热
        case 1:{
            if( (process_flag & 0x01) == 0x01 )break;   //如果已完成该项检测，退出
            if(result && currentcheck == 1)
            {
                process_flag |= 0x01; 
                CrLogI("check the hotend completed,%x",process_flag);
                refresh_checking_process(1);
                //超时错误定时器关闭
                lv_timer_del(hotendcheck);
                set_printer_data(0x03,2,"20");     //喷头降温

                //进行下一项
                char sendbuff[30] = {0};
                if(BedTargetTemp + 20 < BED_MAX_EDIT_TEMPER)
                {
                    snprintf(sendbuff, 30, "1%d", BedTargetTemp + 20);
                }
                else
                {
                    snprintf(sendbuff, 30, "1%d", BED_MAX_EDIT_TEMPER);
                }
                set_printer_data(0x03, strlen(sendbuff), sendbuff);     //设置热床升温20度检测加热是否正常
                bedcheck = lv_timer_create(TimeoutHandle, 1000 * 60 * 5, "2");
                lv_timer_set_repeat_count(bedcheck, 1);
                currentcheck = 2;
            }
            else
            {
                CrLogI("selftest illegal call,%d",currentcheck);
            }
            break;
        }
        //热床加热
        case 2:{
            if( (process_flag & 0x02) == 0x02 )break;   //如果已完成该项检测，退出
            if(result && currentcheck == 2)
            {
                process_flag |= 0x02; 
                CrLogI("check the bed completed");
                refresh_checking_process(2);
                //超时错误定时器关闭
                lv_timer_set_repeat_count(bedcheck, 0);
                set_printer_data(0x03,2,"10");     //热床降温

                //进行下一项喉管风扇检测
                // 区分不同机型硬件情况不同
                switch (GetSystemConfig().model)
                {
                case PF_05:
                    {
                        hotfancheck = lv_timer_create(TimeoutHandle, 1000 * 60, "3");
                        lv_timer_set_repeat_count(hotfancheck, 1);
                        currentcheck = 3;
                        check_singleprocess_completed(3, true);
                    }
                    break;
                case CR_K1:
                case CR_K1_Max:
                    if(system_state.Fanfeedback)
                    {
                        char buff[10] = {0};
                        sprintf(buff, "2%d", 100);
                        set_printer_data(0x03, strlen(buff), buff);     //设置喷嘴温度到100度，检测喉管风扇转速
                        hotfancheck = lv_timer_create(TimeoutHandle, 1000 * 60, "3");
                        lv_timer_set_repeat_count(hotfancheck, 1);
                        currentcheck = 3;
                        get_printer_data(0x1b,1,"8");
                    }
                    else
                    {
                        hotfancheck = lv_timer_create(TimeoutHandle, 1000 * 60, "3");
                        lv_timer_set_repeat_count(hotfancheck, 1);
                        currentcheck = 3;
                        check_singleprocess_completed(3, true);
                    }
                    break;
                default:
                    {
                        break;
                    }
                }
            }
            else
            {
                CrLogI("selftest illegal call,%d",currentcheck);
            }
            break;
        }
        //喉管风扇
        case 3:{
            if( (process_flag & 0x04) == 0x04 )return;   //如果已完成该项检测，退出
            if(result && currentcheck == 3)
            {
                process_flag |= 0x04; 
                CrLogI("check the throadfan completed");
                refresh_checking_process(3);
                //超时错误定时器关闭
                lv_timer_set_repeat_count(hotfancheck, 0);
                set_printer_data(0x03,2,"20");     //喷头降温

                //进行下一项开启主板风扇
                if(system_state.Fanfeedback)
                {
                    boardfancheck = lv_timer_create(TimeoutHandle, 1000 * 60, "4");
                    lv_timer_set_repeat_count(boardfancheck, 1);
                    currentcheck = 4;
                    get_printer_data(0x1b,1,"8");
                }
                else
                {
                    boardfancheck = lv_timer_create(TimeoutHandle, 1000 * 60, "4");
                    lv_timer_set_repeat_count(boardfancheck, 1);
                    currentcheck = 4;
                    check_singleprocess_completed(4, true);
                }
            }
            else
            {
                CrLogI("selftest illegal call,%d",currentcheck);
            }
            break;
        }
        //主板散热风扇
        case 4:{
            if( (process_flag & 0x08) == 0x08 )return;   //如果已完成该项检测，退出
            if(result && currentcheck == 4)
            {
                process_flag |= 0x08; 
                CrLogI("check the borderfan completed");
                refresh_checking_process(4);
                //超时错误定时器、主板散热风扇关闭
                lv_timer_set_repeat_count(boardfancheck, 0);
                // char buff[10];
                // sprintf(buff, "02\t%d", 0);
                // set_printer_data(0x06,strlen(buff), buff);

                //进行下一项开启振纹优化
                set_printer_data(0x1b, 1, "3");
                ringingcheck = lv_timer_create(TimeoutHandle, 1000 * 60 * 15, "5");
                lv_timer_set_repeat_count(ringingcheck, 1);
                currentcheck = 5;
            }
            else
            {
                CrLogI("selftest illegal call,%d",currentcheck);
            }
            break;
        }
        //振纹优化
        case 5:{
            if( (process_flag & 0x10) == 0x10 )return;   //如果已完成该项检测，退出
            if(result && currentcheck == 5)
            {
                process_flag |= 0x10; 
                CrLogI("check the ringing completed");
                refresh_checking_process(5);
                //超时错误定时器关闭
                lv_timer_set_repeat_count(ringingcheck, 0);

                //进行下一项开启自动调平
                set_printer_data(0x09, 1, "2");
                autolevelcheck = lv_timer_create(TimeoutHandle, 1000 * 60 * 20, "6");
                lv_timer_set_repeat_count(autolevelcheck, 1);
                currentcheck =6;
            }
            else
            {
                CrLogI("selftest illegal call,%d",currentcheck);
            }
            break;
        }
        //自动调平
        case 6:{
            if( (process_flag & 0x20) == 0x20 )return;   //如果已完成该项检测，退出
            if(result && currentcheck == 6)
            {
                process_flag |= 0x20; 
                CrLogI("check the autolevel completed");
                refresh_checking_process(6);
                //超时错误定时器关闭
                lv_timer_set_repeat_count(autolevelcheck, 0);
                // if(UIType == CR_K1_Max)//进行下一项开启AI轮廓仪自检
                // {
                //     currentcheck = 7;
                //     set_printer_data(0x1b, 1, "a");
                //     aiLiDARcheck = lv_timer_create(TimeoutHandle, 1000 * 60 * 5, "7");
                //     lv_timer_set_repeat_count(aiLiDARcheck, 1);
                // }
            }
            else
            {
                CrLogI("selftest illegal call,%d",currentcheck);
                process_flag |= 0x20; 
                refresh_checking_process(6);
                //超时错误定时器关闭
                lv_timer_set_repeat_count(autolevelcheck, 0);
            }
            break;
        }
        case 7:
        {
            if( (process_flag & 0x40) == 0x40 )return;   //如果已完成该项检测，退出
            if(currentcheck == 7)
            {
                if(result)
                {
                    process_flag |= 0x40; 
                    CrLogI("check the AI completed");
                    refresh_checking_process(7);
                    //超时错误定时器关闭
                    lv_timer_set_repeat_count(aiLiDARcheck, 0);

                    //进行下一项摄像头自检
                    currentcheck = 8;
                    get_printer_data(0x1b, 2, "5");
                }
                else
                {
                    startcheck_flag = false;           //自检结束
                    errorcheck_flag = 7;               //错误标志置7
                    show_msgbox1(errorcheck_flag);
                }
            }
            else
            {
                CrLogI("selftest illegal call,%d",currentcheck);
            }
            break;
        }
        case 8:
        {
            if( (process_flag & 0x80) == 0x80 )return;   //如果已完成该项检测，退出
            if(currentcheck == 8)
            {
                if(result)
                {
                    process_flag |= 0x80; 
                    CrLogI("check the Camera completed");
                    refresh_checking_process(8);
                    currentcheck = 9;
                }
                else
                {
                    startcheck_flag = false;           //自检结束
                    errorcheck_flag = 8;               //错误标志置8
                    show_msgbox1(errorcheck_flag);
                }
            }
            else
            {
                CrLogI("selftest illegal call,%d",currentcheck);
            }
            break;
        }
        default:
            CrLogE("selfcheck process error");
            break;
    }


}

void refresh_checking_process(int SeqNumber)
{
    char c = LV_KEY_RIGHT;
    if(!startcheck_flag)
        return;
    uint8_t language_index = get_cur_language_index();
    CrLogI("refresh the checking process,Seq:%d",SeqNumber);
    switch(SeqNumber)
    {
        case 0:{//项目1开始检测
            lv_obj_set_style_text_color(ui_test1_name, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_test1_checking, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(ui_test1_checking, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_test1_wait_gif, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(ui_test1_checking, Checking[get_cur_language_index()]);
            break;
        }
        case 1:{//项目1完成，开始项目2
            lv_obj_add_flag(ui_test1_checking, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test1_wait_gif, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_test1_resultimg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_text_color(ui_test1_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

            lv_obj_set_style_text_color(ui_test2_name, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_test2_checking, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(ui_test2_checking, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(ui_test2_checking, Checking[get_cur_language_index()]);
            lv_obj_clear_flag(ui_test2_wait_gif, LV_OBJ_FLAG_HIDDEN);
            break;
        }
        //热床加热
        case 2:{
            lv_obj_add_flag(ui_test2_checking, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test2_wait_gif, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_test2_resultimg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_text_color(ui_test2_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

            lv_obj_set_style_text_color(ui_test3_name, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_test3_checking, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(ui_test3_checking, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(ui_test3_checking, Checking[get_cur_language_index()]);
            lv_obj_clear_flag(ui_test3_wait_gif, LV_OBJ_FLAG_HIDDEN);
            break;
        }
        //喉管风扇
        case 3:{
            lv_obj_add_flag(ui_test3_checking, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test3_wait_gif, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_test3_resultimg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_text_color(ui_test3_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

            lv_obj_set_style_text_color(ui_test4_name, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_test4_checking, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(ui_test4_checking, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(ui_test4_checking, Checking[get_cur_language_index()]);
            lv_obj_clear_flag(ui_test4_wait_gif, LV_OBJ_FLAG_HIDDEN);
            break;
        }
        //主板散热风扇
        case 4:{
            lv_obj_add_flag(ui_test4_checking, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test4_wait_gif, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_test4_resultimg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_text_color(ui_test4_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

            lv_obj_set_style_text_color(ui_test5_name, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_test5_checking, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(ui_test5_checking, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(ui_test5_checking, Checking[get_cur_language_index()]);
            lv_obj_clear_flag(ui_test5_wait_gif, LV_OBJ_FLAG_HIDDEN);
            break;
        }
        //振纹优化
        case 5:{
            lv_obj_add_flag(ui_test5_checking, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test5_wait_gif, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_test5_resultimg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_text_color(ui_test5_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

            lv_obj_set_style_text_color(ui_test6_name, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_test6_checking, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(ui_test6_checking, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(ui_test6_checking, Checking[get_cur_language_index()]);
            lv_obj_clear_flag(ui_test6_wait_gif, LV_OBJ_FLAG_HIDDEN);
            lv_event_send(ui_SelftestAll_Panel2, LV_EVENT_KEY, &c);
            break;
        }
        //自动调平
        case 6:{
            lv_obj_add_flag(ui_test6_checking, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_test6_wait_gif, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_test6_resultimg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_text_color(ui_test6_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            startcheck_flag = false;

            LoadPage(ui_SelftestCompleted, 1);
            //_ui_screen_change(ui_SelftestCompleted, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
            // switch (UIType)
            // {
            //     case CR_K1:
            //     {
            //         lv_obj_add_flag(ui_test6_checking, LV_OBJ_FLAG_HIDDEN);
            //         lv_obj_clear_flag(ui_test6_resultimg, LV_OBJ_FLAG_HIDDEN);
            //         lv_obj_set_style_text_color(ui_test6_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            //         startcheck_flag = false;

            //         _ui_screen_change(ui_SelftestCompleted, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
            //         break;
            //     }
            //     case CR_K1_Max:
            //     {
            //         lv_obj_add_flag(ui_test6_checking, LV_OBJ_FLAG_HIDDEN);
            //         lv_obj_clear_flag(ui_test6_resultimg, LV_OBJ_FLAG_HIDDEN);
            //         lv_obj_set_style_text_color(ui_test6_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

            //         lv_obj_set_style_text_color(ui_test7_name, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
            //         lv_obj_set_style_text_color(ui_test7_checking, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
            //         lv_obj_clear_flag(ui_test7_checking, LV_OBJ_FLAG_HIDDEN);
            //         lv_label_set_text(ui_test7_checking, Checking[get_cur_language_index()]);
            //         break;            
            //     }
            //     default:
            //         break;
            // }
            break;
        }
        case 7:{
            lv_obj_add_flag(ui_test7_checking, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_test7_resultimg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_text_color(ui_test7_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);

            lv_obj_set_style_text_color(ui_test8_name, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(ui_test8_checking, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_clear_flag(ui_test8_checking, LV_OBJ_FLAG_HIDDEN);
            lv_label_set_text(ui_test8_checking, Checking[get_cur_language_index()]);
            break;
        }
        case 8:{
            lv_obj_add_flag(ui_test8_checking, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(ui_test8_resultimg, LV_OBJ_FLAG_HIDDEN);
            lv_obj_set_style_text_color(ui_test8_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
            startcheck_flag = false;

            //_ui_screen_change(ui_SelftestCompleted, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
            LoadPage(ui_SelftestCompleted, 1);
            break;
        }
        default:
            CrLogE("refresh_checking_process Error,case:%d",SeqNumber);
            break;
    }

}

void self_test_all_change_language_text(void)
{
    uint8_t language_index = get_cur_language_index();

    lv_label_set_text(ui_SelftestAlltitle, PrinterSelfTest[language_index]);
   // lv_label_set_text(ui_SelftestAlllabel1, RingingTipMsg[language_index]);

    lv_label_set_text(ui_test1_name, NozzleHeating[language_index]);
    lv_label_set_text(ui_test1_checking, Checking[language_index]);
    lv_label_set_text(ui_test2_name, BedHeating[language_index]);
    lv_label_set_text(ui_test2_checking, Checking[language_index]);
    if(ui_test3_name)
    {
        lv_label_set_text(ui_test3_name, ThroatCoolFan[language_index]);
        //redefine_label_size(ui_test3_name, lv_obj_get_style_text_font(ui_test3_name, LV_PART_MAIN), 0, -6, 300, 0);
    }
    lv_label_set_text(ui_test3_checking, Checking[language_index]);
    if(ui_test4_name)
    {
        lv_label_set_text(ui_test4_name, BoardCoolFan[language_index]);
        //redefine_label_size(ui_test4_name, lv_obj_get_style_text_font(ui_test4_name, LV_PART_MAIN), -2, -6, 280, 0);
    }
    lv_label_set_text(ui_test4_checking, Checking[language_index]);
    lv_label_set_text(ui_test5_name, VibrationOptimization[language_index]);
    lv_label_set_text(ui_test5_checking, Checking[language_index]);
    lv_label_set_text(ui_test6_name, AutoLevel[language_index]);
    lv_label_set_text(ui_test6_checking, Checking[language_index]);
    // lv_label_set_text(ui_test7_name, AILIDAR[language_index]);
    // lv_label_set_text(ui_test7_checking, Checking[language_index]);
    // lv_label_set_text(ui_test8_name, CameraArray[language_index]);
    // lv_label_set_text(ui_test8_checking, Checking[language_index]);


    lv_label_set_text(MsgBoxTitle, KindTips[language_index]);
    lv_label_set_text(MsgboxBtnlabel1, UploadErrorTips2[language_index]);//Cancel[language_index]
    if(language_index == 5)
    {
        //lv_obj_set_style_text_font(MsgboxBtnlabel1, lv_font18.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        redefine_label_size(MsgboxBtnlabel1, lv_font18.font, 0, 0, 140, 0);
    }
    else {
        //lv_obj_set_style_text_font(MsgboxBtnlabel1, lv_font24.font, LV_PART_MAIN | LV_STATE_DEFAULT);
        redefine_label_size(MsgboxBtnlabel1, lv_font24.font, 0, 0, 140, 0);
    }
    

    

    lv_obj_update_layout(MsgboxBtn1);
    redefine_widgets_size(MsgboxBtn1, MsgboxBtnlabel1, 5, 0, 160, 52);
    lv_label_set_text(MsgboxBtnlabel2, ErrorBtnConfirm[language_index]);
}

void JudgeHeatingIsNormal(int hotendtemp, int bedtemp)
{
    if(!startcheck_flag)return;
    if(hotendtemp - HotendTargetTemp > 10)
    {
        if (HotendTargetTemp == 0)
        {
            HotendTargetTemp = hotendtemp;
            return;
        }
        check_singleprocess_completed(1, true);
    }
    if(bedtemp - BedTargetTemp > 5)
    {
        if (BedTargetTemp == 0)
        {
            BedTargetTemp = hotendtemp;
            return;
        }
        check_singleprocess_completed(2, true);
    }
}

void confrim_close()
{
    CrLogI("close the messagebox and confrim the selftest completed");
    selftest_messagebox_close();
    //TODO: 要调用有聚焦功能的函数
    BackPrepage(false);
    //LoadPage(ui_Manualtest, 1);
    //_ui_screen_change(ui_Manualtest, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}

void ConfirmTheSelftest()
{
    void (*btns_callback[2])(void) = {NULL, &confrim_close};
    uint8_t language_index = get_cur_language_index();
    create_selftest_messagebox(KindTips[language_index], SelftestCompletedTips[get_cur_language_index()],NULL, Confirm[language_index], btns_callback);
}

void manual_test_completed(int num, bool result)
{
    if(manualtestcount == 0)return;
    CrLogI("manual test completed single test,num:%d, result:%d", num, result);
    switch (manualtestcount)
    {
        case 101:{//只进行自动调平
            if(num == 2)
            {
                CrLogI("autolevel test is completed,result:%d",result);
                if(result)
                {
                    lv_obj_add_flag(ui_test6_checking, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_test6_wait_gif, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(ui_test6_resultimg, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_set_style_text_color(ui_test6_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                manualtestcount = 0;
                ConfirmTheSelftest();
                break;
            }
        }
        case 110:{//只进行振纹优化
            if(num == 1)
            {
                CrLogI("ringing test is completed,result:%d",result);
                if(result)
                {
                    lv_obj_add_flag(ui_test5_checking, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_test5_wait_gif, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(ui_test5_resultimg, LV_OBJ_FLAG_HIDDEN);
                    lv_img_set_src(ui_test5_resultimg, &ui_img_state_normal_png);
                    lv_obj_set_style_text_color(ui_test5_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                else
                {
                    lv_obj_add_flag(ui_test5_checking, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_test5_wait_gif, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(ui_test5_resultimg, LV_OBJ_FLAG_HIDDEN);
                    lv_img_set_src(ui_test5_resultimg, &ui_img_state_error_png);
                    lv_obj_set_style_text_color(ui_test5_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                manualtestcount = 0;
                ConfirmTheSelftest();
                break;
            }
            break;
        }
        case 111:{//进行振纹优化+自动调平
            if(num == 1)
            {
                CrLogI("ringing test is completed,result:%d",result);
                if(result)
                {
                    lv_obj_add_flag(ui_test5_checking, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_test5_wait_gif, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(ui_test5_resultimg, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_set_style_text_color(ui_test5_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                else
                {
                    lv_obj_add_flag(ui_test5_checking, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_test5_wait_gif, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(ui_test5_resultimg, LV_OBJ_FLAG_HIDDEN);
                    lv_img_set_src(ui_test5_resultimg, &ui_img_state_error_png);
                    lv_obj_set_style_text_color(ui_test5_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                }

                set_printer_data(0x09, 1, "2");//发送自动调平命令
                lv_obj_set_style_text_color(ui_test6_name, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_set_style_text_color(ui_test6_checking, lv_color_hex(0x42bdd8), LV_PART_MAIN | LV_STATE_DEFAULT);
                lv_obj_clear_flag(ui_test6_checking, LV_OBJ_FLAG_HIDDEN);
                lv_label_set_text(ui_test6_checking, Checking[get_cur_language_index()]);
                lv_obj_clear_flag(ui_test6_wait_gif, LV_OBJ_FLAG_HIDDEN);
                break;
            }

            if(num == 2)
            {
                CrLogI("autolevel test is completed,result:%d",result);
                if(result)
                {
                    lv_obj_add_flag(ui_test6_checking, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_add_flag(ui_test6_wait_gif, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_clear_flag(ui_test6_resultimg, LV_OBJ_FLAG_HIDDEN);
                    lv_obj_set_style_text_color(ui_test6_name, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
                }
                manualtestcount = 0;
                ConfirmTheSelftest();
                break;
            }
            break;
        }
        default:
            break;
    }
}

void JudgeCameraIsNormal(int state)
{
    if(!startcheck_flag)return;
    if(UIType != CR_K1_Max)return;
    if(state == 0)//0:无摄像头 1:有摄像头
    {
        check_singleprocess_completed(8, false);
    }
    else if(state == 1)
    {
        check_singleprocess_completed(8, true);
    }

}

void JudgeAILiDARIsNormal(int state)
{
    if(!startcheck_flag)return;
    if(UIType != CR_K1_Max)return;
    switch (state)//0:标定中 1：标定成功 2：标定失败
    {
        case 0:break;
        case 1:check_singleprocess_completed(7, true);break;
        case 2:check_singleprocess_completed(7, false);break;
        default:
            break;
    }
}

void LoadSelftestScreen(void)
{
    _ui_screen_change(ui_SelftestAll, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}

void SelfTestAllPageChangeObjs(uint8_t index)
{
    lv_group_remove_all_objs(encoder_group);
    PageNode *SelfTestAllPage_node = find_page(ui_SelftestAll);
    SelfTestAllPage_node->nav_level = index;
    switch (index) 
    {
    case 1:
        lv_group_add_obj(encoder_group, ui_SelftestAll_Panel2);
        break;
    case 2:
        lv_group_add_obj(encoder_group, MsgboxBtn1);
        lv_group_add_obj(encoder_group, MsgboxBtn2);
        break;
    default:
        break;
    }
    
}
