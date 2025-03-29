# Copyright 2022 NXP
# SPDX-License-Identifier: MIT
# The auto-generated can only be used on NXP devices

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct

lv.init()
SDL.init(w=800,h=800)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(800*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 800
disp_drv.ver_res = 800
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init() 
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def ta_event_cb(e,kb):
    code = e.get_code()
    ta = e.get_target()
    if code == lv.EVENT.FOCUSED:
        kb.set_textarea(ta)
        kb.clear_flag(lv.obj.FLAG.HIDDEN)

    if code == lv.EVENT.DEFOCUSED:
        kb.set_textarea(None)
        kb.add_flag(lv.obj.FLAG.HIDDEN)


homepapage = lv.obj()
# create style style_homepapage_main_main_default
style_homepapage_main_main_default = lv.style_t()
style_homepapage_main_main_default.init()
style_homepapage_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_homepapage_main_main_default.set_bg_opa(0)

# add style for homepapage
homepapage.add_style(style_homepapage_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_cont_1 = lv.obj(homepapage)
homepapage_cont_1.set_pos(0,0)
homepapage_cont_1.set_size(480,800)
homepapage_chart_1 = lv.chart(homepapage_cont_1)
homepapage_chart_1.set_pos(10,152)
homepapage_chart_1.set_size(460,460)
homepapage_chart_1.set_type(lv.chart.TYPE.LINE)
homepapage_chart_1.set_range(lv.chart.AXIS.PRIMARY_Y, 0, 250)
homepapage_chart_1.set_div_line_count(6, 20)
homepapage_chart_1.set_point_count(50)
chart_series_0 = lv.chart.add_series(homepapage_chart_1, lv.color_make(0x00,0x00,0x00), lv.chart.AXIS.PRIMARY_Y);
homepapage_chart_1.set_next_value(chart_series_0, 0)
chart_series_1 = lv.chart.add_series(homepapage_chart_1, lv.color_make(0x00,0x00,0x00), lv.chart.AXIS.PRIMARY_Y);
homepapage_chart_1.set_next_value(chart_series_1, 0)
# create style style_homepapage_chart_1_main_main_default
style_homepapage_chart_1_main_main_default = lv.style_t()
style_homepapage_chart_1_main_main_default.init()
style_homepapage_chart_1_main_main_default.set_bg_color(lv.color_make(0x21,0x21,0x22))
style_homepapage_chart_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x21,0x22))
style_homepapage_chart_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_homepapage_chart_1_main_main_default.set_bg_opa(255)
style_homepapage_chart_1_main_main_default.set_pad_left(0)
style_homepapage_chart_1_main_main_default.set_pad_right(0)
style_homepapage_chart_1_main_main_default.set_pad_top(0)
style_homepapage_chart_1_main_main_default.set_pad_bottom(0)
style_homepapage_chart_1_main_main_default.set_line_color(lv.color_make(0xff,0xff,0xff))
style_homepapage_chart_1_main_main_default.set_line_width(1)
style_homepapage_chart_1_main_main_default.set_line_opa(255)

# add style for homepapage_chart_1
homepapage_chart_1.add_style(style_homepapage_chart_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_label_6 = lv.label(homepapage_cont_1)
homepapage_label_6.set_pos(9,153)
homepapage_label_6.set_size(460,460)
# create style style_homepapage_label_6_main_main_default
style_homepapage_label_6_main_main_default = lv.style_t()
style_homepapage_label_6_main_main_default.init()
style_homepapage_label_6_main_main_default.set_radius(6)
style_homepapage_label_6_main_main_default.set_bg_color(lv.color_make(0x21,0x21,0x22))
style_homepapage_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x21,0x22))
style_homepapage_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_homepapage_label_6_main_main_default.set_bg_opa(255)
style_homepapage_label_6_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_homepapage_label_6_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_homepapage_label_6_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_homepapage_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_homepapage_label_6_main_main_default.set_text_letter_space(0)
style_homepapage_label_6_main_main_default.set_pad_left(0)
style_homepapage_label_6_main_main_default.set_pad_right(0)
style_homepapage_label_6_main_main_default.set_pad_top(0)
style_homepapage_label_6_main_main_default.set_pad_bottom(0)

# add style for homepapage_label_6
homepapage_label_6.add_style(style_homepapage_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_bar_1 = lv.bar(homepapage_cont_1)
homepapage_bar_1.set_pos(52,568)
homepapage_bar_1.set_size(377,24)
homepapage_bar_1.set_style_anim_time(1000, 0)
homepapage_bar_1.set_mode(lv.bar.MODE.NORMAL)
homepapage_bar_1.set_value(50, lv.ANIM.ON)
# create style style_homepapage_bar_1_main_main_default
style_homepapage_bar_1_main_main_default = lv.style_t()
style_homepapage_bar_1_main_main_default.init()
style_homepapage_bar_1_main_main_default.set_radius(16)
style_homepapage_bar_1_main_main_default.set_bg_color(lv.color_make(0x3a,0x3d,0x42))
style_homepapage_bar_1_main_main_default.set_bg_grad_color(lv.color_make(0x3a,0x3d,0x42))
style_homepapage_bar_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_homepapage_bar_1_main_main_default.set_bg_opa(255)
style_homepapage_bar_1_main_main_default.set_pad_left(0)
style_homepapage_bar_1_main_main_default.set_pad_right(0)
style_homepapage_bar_1_main_main_default.set_pad_top(0)
style_homepapage_bar_1_main_main_default.set_pad_bottom(0)

# add style for homepapage_bar_1
homepapage_bar_1.add_style(style_homepapage_bar_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_homepapage_bar_1_main_indicator_default
style_homepapage_bar_1_main_indicator_default = lv.style_t()
style_homepapage_bar_1_main_indicator_default.init()
style_homepapage_bar_1_main_indicator_default.set_radius(16)
style_homepapage_bar_1_main_indicator_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_homepapage_bar_1_main_indicator_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_homepapage_bar_1_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_homepapage_bar_1_main_indicator_default.set_bg_opa(255)

# add style for homepapage_bar_1
homepapage_bar_1.add_style(style_homepapage_bar_1_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

homepapage_img_16 = lv.img(homepapage_cont_1)
homepapage_img_16.set_pos(90,205)
homepapage_img_16.set_size(300,300)
# create style style_homepapage_img_16_main_main_default
style_homepapage_img_16_main_main_default = lv.style_t()
style_homepapage_img_16_main_main_default.init()
style_homepapage_img_16_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_16_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_16_main_main_default.set_img_opa(255)

# add style for homepapage_img_16
homepapage_img_16.add_style(style_homepapage_img_16_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_label_7 = lv.label(homepapage_cont_1)
homepapage_label_7.set_pos(40,166)
homepapage_label_7.set_size(400,32)
homepapage_label_7.set_text("test")
homepapage_label_7.set_long_mode(lv.label.LONG.WRAP)
homepapage_label_7.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_homepapage_label_7_main_main_default
style_homepapage_label_7_main_main_default = lv.style_t()
style_homepapage_label_7_main_main_default.init()
style_homepapage_label_7_main_main_default.set_radius(0)
style_homepapage_label_7_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_homepapage_label_7_main_main_default.set_bg_opa(0)
style_homepapage_label_7_main_main_default.set_text_color(lv.color_make(0x6a,0x70,0x7d))
try:
    style_homepapage_label_7_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_homepapage_label_7_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_homepapage_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_homepapage_label_7_main_main_default.set_text_letter_space(0)
style_homepapage_label_7_main_main_default.set_pad_left(0)
style_homepapage_label_7_main_main_default.set_pad_right(0)
style_homepapage_label_7_main_main_default.set_pad_top(0)
style_homepapage_label_7_main_main_default.set_pad_bottom(0)

# add style for homepapage_label_7
homepapage_label_7.add_style(style_homepapage_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_label_8 = lv.label(homepapage_cont_1)
homepapage_label_8.set_pos(53,529)
homepapage_label_8.set_size(79,24)
homepapage_label_8.set_text("0h0m")
homepapage_label_8.set_long_mode(lv.label.LONG.WRAP)
homepapage_label_8.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_homepapage_label_8_main_main_default
style_homepapage_label_8_main_main_default = lv.style_t()
style_homepapage_label_8_main_main_default.init()
style_homepapage_label_8_main_main_default.set_radius(0)
style_homepapage_label_8_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_homepapage_label_8_main_main_default.set_bg_opa(0)
style_homepapage_label_8_main_main_default.set_text_color(lv.color_make(0x50,0x53,0x5b))
try:
    style_homepapage_label_8_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_homepapage_label_8_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_homepapage_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_homepapage_label_8_main_main_default.set_text_letter_space(0)
style_homepapage_label_8_main_main_default.set_pad_left(0)
style_homepapage_label_8_main_main_default.set_pad_right(0)
style_homepapage_label_8_main_main_default.set_pad_top(0)
style_homepapage_label_8_main_main_default.set_pad_bottom(0)

# add style for homepapage_label_8
homepapage_label_8.add_style(style_homepapage_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_label_11 = lv.label(homepapage_cont_1)
homepapage_label_11.set_pos(341,529)
homepapage_label_11.set_size(79,24)
homepapage_label_11.set_text("0h0m")
homepapage_label_11.set_long_mode(lv.label.LONG.WRAP)
homepapage_label_11.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_homepapage_label_11_main_main_default
style_homepapage_label_11_main_main_default = lv.style_t()
style_homepapage_label_11_main_main_default.init()
style_homepapage_label_11_main_main_default.set_radius(0)
style_homepapage_label_11_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_label_11_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_label_11_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_homepapage_label_11_main_main_default.set_bg_opa(0)
style_homepapage_label_11_main_main_default.set_text_color(lv.color_make(0x50,0x53,0x5b))
try:
    style_homepapage_label_11_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_homepapage_label_11_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_homepapage_label_11_main_main_default.set_text_font(lv.font_montserrat_16)
style_homepapage_label_11_main_main_default.set_text_letter_space(0)
style_homepapage_label_11_main_main_default.set_pad_left(0)
style_homepapage_label_11_main_main_default.set_pad_right(0)
style_homepapage_label_11_main_main_default.set_pad_top(0)
style_homepapage_label_11_main_main_default.set_pad_bottom(0)

# add style for homepapage_label_11
homepapage_label_11.add_style(style_homepapage_label_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_label_9 = lv.label(homepapage_cont_1)
homepapage_label_9.set_pos(219,526)
homepapage_label_9.set_size(42,28)
homepapage_label_9.set_text("100")
homepapage_label_9.set_long_mode(lv.label.LONG.WRAP)
homepapage_label_9.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_homepapage_label_9_main_main_default
style_homepapage_label_9_main_main_default = lv.style_t()
style_homepapage_label_9_main_main_default.init()
style_homepapage_label_9_main_main_default.set_radius(0)
style_homepapage_label_9_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_label_9_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_homepapage_label_9_main_main_default.set_bg_opa(0)
style_homepapage_label_9_main_main_default.set_text_color(lv.color_make(0x42,0xbd,0xd8))
try:
    style_homepapage_label_9_main_main_default.set_text_font(lv.font_simsun_28)
except AttributeError:
    try:
        style_homepapage_label_9_main_main_default.set_text_font(lv.font_montserrat_28)
    except AttributeError:
        style_homepapage_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_homepapage_label_9_main_main_default.set_text_letter_space(0)
style_homepapage_label_9_main_main_default.set_pad_left(0)
style_homepapage_label_9_main_main_default.set_pad_right(0)
style_homepapage_label_9_main_main_default.set_pad_top(0)
style_homepapage_label_9_main_main_default.set_pad_bottom(0)

# add style for homepapage_label_9
homepapage_label_9.add_style(style_homepapage_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_label_10 = lv.label(homepapage_cont_1)
homepapage_label_10.set_pos(267,529)
homepapage_label_10.set_size(17,24)
homepapage_label_10.set_text("%")
homepapage_label_10.set_long_mode(lv.label.LONG.WRAP)
homepapage_label_10.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_homepapage_label_10_main_main_default
style_homepapage_label_10_main_main_default = lv.style_t()
style_homepapage_label_10_main_main_default.init()
style_homepapage_label_10_main_main_default.set_radius(0)
style_homepapage_label_10_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_label_10_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_label_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_homepapage_label_10_main_main_default.set_bg_opa(0)
style_homepapage_label_10_main_main_default.set_text_color(lv.color_make(0x42,0xbd,0xd8))
try:
    style_homepapage_label_10_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_homepapage_label_10_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_homepapage_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_homepapage_label_10_main_main_default.set_text_letter_space(0)
style_homepapage_label_10_main_main_default.set_pad_left(0)
style_homepapage_label_10_main_main_default.set_pad_right(0)
style_homepapage_label_10_main_main_default.set_pad_top(0)
style_homepapage_label_10_main_main_default.set_pad_bottom(0)

# add style for homepapage_label_10
homepapage_label_10.add_style(style_homepapage_label_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_label_5 = lv.label(homepapage_cont_1)
homepapage_label_5.set_pos(0,720)
homepapage_label_5.set_size(480,80)
# create style style_homepapage_label_5_main_main_default
style_homepapage_label_5_main_main_default = lv.style_t()
style_homepapage_label_5_main_main_default.init()
style_homepapage_label_5_main_main_default.set_radius(0)
style_homepapage_label_5_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_homepapage_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_homepapage_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_homepapage_label_5_main_main_default.set_bg_opa(255)
style_homepapage_label_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_homepapage_label_5_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_homepapage_label_5_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_homepapage_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_homepapage_label_5_main_main_default.set_text_letter_space(0)
style_homepapage_label_5_main_main_default.set_pad_left(0)
style_homepapage_label_5_main_main_default.set_pad_right(0)
style_homepapage_label_5_main_main_default.set_pad_top(0)
style_homepapage_label_5_main_main_default.set_pad_bottom(0)

# add style for homepapage_label_5
homepapage_label_5.add_style(style_homepapage_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_11 = lv.img(homepapage_cont_1)
homepapage_img_11.set_pos(30,742)
homepapage_img_11.set_size(48,48)
homepapage_img_11.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png','rb') as f:
        homepapage_img_11_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png')
    sys.exit()

homepapage_img_11_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_11_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_11_img_data
})

homepapage_img_11.set_src(homepapage_img_11_img)
homepapage_img_11.set_pivot(0,0)
homepapage_img_11.set_angle(0)
# create style style_homepapage_img_11_main_main_default
style_homepapage_img_11_main_main_default = lv.style_t()
style_homepapage_img_11_main_main_default.init()
style_homepapage_img_11_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_11_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_11_main_main_default.set_img_opa(255)

# add style for homepapage_img_11
homepapage_img_11.add_style(style_homepapage_img_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_12 = lv.img(homepapage_cont_1)
homepapage_img_12.set_pos(128,742)
homepapage_img_12.set_size(48,48)
homepapage_img_12.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png','rb') as f:
        homepapage_img_12_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png')
    sys.exit()

homepapage_img_12_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_12_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_12_img_data
})

homepapage_img_12.set_src(homepapage_img_12_img)
homepapage_img_12.set_pivot(0,0)
homepapage_img_12.set_angle(0)
# create style style_homepapage_img_12_main_main_default
style_homepapage_img_12_main_main_default = lv.style_t()
style_homepapage_img_12_main_main_default.init()
style_homepapage_img_12_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_12_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_12_main_main_default.set_img_opa(255)

# add style for homepapage_img_12
homepapage_img_12.add_style(style_homepapage_img_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_13 = lv.img(homepapage_cont_1)
homepapage_img_13.set_pos(224,742)
homepapage_img_13.set_size(48,48)
homepapage_img_13.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png','rb') as f:
        homepapage_img_13_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png')
    sys.exit()

homepapage_img_13_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_13_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_13_img_data
})

homepapage_img_13.set_src(homepapage_img_13_img)
homepapage_img_13.set_pivot(0,0)
homepapage_img_13.set_angle(0)
# create style style_homepapage_img_13_main_main_default
style_homepapage_img_13_main_main_default = lv.style_t()
style_homepapage_img_13_main_main_default.init()
style_homepapage_img_13_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_13_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_13_main_main_default.set_img_opa(255)

# add style for homepapage_img_13
homepapage_img_13.add_style(style_homepapage_img_13_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_14 = lv.img(homepapage_cont_1)
homepapage_img_14.set_pos(318,742)
homepapage_img_14.set_size(48,48)
homepapage_img_14.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png','rb') as f:
        homepapage_img_14_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png')
    sys.exit()

homepapage_img_14_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_14_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_14_img_data
})

homepapage_img_14.set_src(homepapage_img_14_img)
homepapage_img_14.set_pivot(0,0)
homepapage_img_14.set_angle(0)
# create style style_homepapage_img_14_main_main_default
style_homepapage_img_14_main_main_default = lv.style_t()
style_homepapage_img_14_main_main_default.init()
style_homepapage_img_14_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_14_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_14_main_main_default.set_img_opa(255)

# add style for homepapage_img_14
homepapage_img_14.add_style(style_homepapage_img_14_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_15 = lv.img(homepapage_cont_1)
homepapage_img_15.set_pos(414,742)
homepapage_img_15.set_size(48,48)
homepapage_img_15.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png','rb') as f:
        homepapage_img_15_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png')
    sys.exit()

homepapage_img_15_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_15_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_15_img_data
})

homepapage_img_15.set_src(homepapage_img_15_img)
homepapage_img_15.set_pivot(0,0)
homepapage_img_15.set_angle(0)
# create style style_homepapage_img_15_main_main_default
style_homepapage_img_15_main_main_default = lv.style_t()
style_homepapage_img_15_main_main_default.init()
style_homepapage_img_15_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_15_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_15_main_main_default.set_img_opa(255)

# add style for homepapage_img_15
homepapage_img_15.add_style(style_homepapage_img_15_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_btn_4 = lv.btn(homepapage_cont_1)
homepapage_btn_4.set_pos(222,623)
homepapage_btn_4.set_size(248,82)
# create style style_homepapage_btn_4_main_main_default
style_homepapage_btn_4_main_main_default = lv.style_t()
style_homepapage_btn_4_main_main_default.init()
style_homepapage_btn_4_main_main_default.set_radius(8)
style_homepapage_btn_4_main_main_default.set_bg_color(lv.color_make(0x1c,0x1c,0x1e))
style_homepapage_btn_4_main_main_default.set_bg_grad_color(lv.color_make(0x1c,0x1c,0x1e))
style_homepapage_btn_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_homepapage_btn_4_main_main_default.set_bg_opa(255)
style_homepapage_btn_4_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_btn_4_main_main_default.set_shadow_opa(0)
style_homepapage_btn_4_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_btn_4_main_main_default.set_border_width(0)
style_homepapage_btn_4_main_main_default.set_border_opa(255)

# add style for homepapage_btn_4
homepapage_btn_4.add_style(style_homepapage_btn_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_10 = lv.img(homepapage_cont_1)
homepapage_img_10.set_pos(328,646)
homepapage_img_10.set_size(36,36)
homepapage_img_10.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1158951209.png','rb') as f:
        homepapage_img_10_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1158951209.png')
    sys.exit()

homepapage_img_10_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_10_img_data),
  'header': {'always_zero': 0, 'w': 36, 'h': 36, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_10_img_data
})

homepapage_img_10.set_src(homepapage_img_10_img)
homepapage_img_10.set_pivot(0,0)
homepapage_img_10.set_angle(0)
# create style style_homepapage_img_10_main_main_default
style_homepapage_img_10_main_main_default = lv.style_t()
style_homepapage_img_10_main_main_default.init()
style_homepapage_img_10_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_10_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_10_main_main_default.set_img_opa(255)

# add style for homepapage_img_10
homepapage_img_10.add_style(style_homepapage_img_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_17 = lv.img(homepapage_cont_1)
homepapage_img_17.set_pos(295,638)
homepapage_img_17.set_size(102,53)
homepapage_img_17.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp461152756.png','rb') as f:
        homepapage_img_17_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp461152756.png')
    sys.exit()

homepapage_img_17_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_17_img_data),
  'header': {'always_zero': 0, 'w': 102, 'h': 53, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_17_img_data
})

homepapage_img_17.set_src(homepapage_img_17_img)
homepapage_img_17.set_pivot(0,0)
homepapage_img_17.set_angle(0)
# create style style_homepapage_img_17_main_main_default
style_homepapage_img_17_main_main_default = lv.style_t()
style_homepapage_img_17_main_main_default.init()
style_homepapage_img_17_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_17_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_17_main_main_default.set_img_opa(255)

# add style for homepapage_img_17
homepapage_img_17.add_style(style_homepapage_img_17_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_3 = lv.img(homepapage_cont_1)
homepapage_img_3.set_pos(10,61)
homepapage_img_3.set_size(460,82)
homepapage_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-513632982.png','rb') as f:
        homepapage_img_3_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-513632982.png')
    sys.exit()

homepapage_img_3_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_3_img_data),
  'header': {'always_zero': 0, 'w': 460, 'h': 82, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_3_img_data
})

homepapage_img_3.set_src(homepapage_img_3_img)
homepapage_img_3.set_pivot(0,0)
homepapage_img_3.set_angle(0)
# create style style_homepapage_img_3_main_main_default
style_homepapage_img_3_main_main_default = lv.style_t()
style_homepapage_img_3_main_main_default.init()
style_homepapage_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_3_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_3_main_main_default.set_img_opa(255)

# add style for homepapage_img_3
homepapage_img_3.add_style(style_homepapage_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_label_4 = lv.label(homepapage_cont_1)
homepapage_label_4.set_pos(10,623)
homepapage_label_4.set_size(202,82)
# create style style_homepapage_label_4_main_main_default
style_homepapage_label_4_main_main_default = lv.style_t()
style_homepapage_label_4_main_main_default.init()
style_homepapage_label_4_main_main_default.set_radius(8)
style_homepapage_label_4_main_main_default.set_bg_color(lv.color_make(0x1c,0x1c,0x1e))
style_homepapage_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x1c,0x1c,0x1e))
style_homepapage_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_homepapage_label_4_main_main_default.set_bg_opa(255)
style_homepapage_label_4_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_homepapage_label_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_homepapage_label_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_homepapage_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_homepapage_label_4_main_main_default.set_text_letter_space(0)
style_homepapage_label_4_main_main_default.set_pad_left(0)
style_homepapage_label_4_main_main_default.set_pad_right(0)
style_homepapage_label_4_main_main_default.set_pad_top(0)
style_homepapage_label_4_main_main_default.set_pad_bottom(0)

# add style for homepapage_label_4
homepapage_label_4.add_style(style_homepapage_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_9 = lv.img(homepapage_cont_1)
homepapage_img_9.set_pos(141,639)
homepapage_img_9.set_size(48,48)
homepapage_img_9.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1672713748.png','rb') as f:
        homepapage_img_9_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1672713748.png')
    sys.exit()

homepapage_img_9_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_9_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_9_img_data
})

homepapage_img_9.set_src(homepapage_img_9_img)
homepapage_img_9.set_pivot(0,0)
homepapage_img_9.set_angle(0)
# create style style_homepapage_img_9_main_main_default
style_homepapage_img_9_main_main_default = lv.style_t()
style_homepapage_img_9_main_main_default.init()
style_homepapage_img_9_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_9_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_9_main_main_default.set_img_opa(255)

# add style for homepapage_img_9
homepapage_img_9.add_style(style_homepapage_img_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_8 = lv.img(homepapage_cont_1)
homepapage_img_8.set_pos(111,628)
homepapage_img_8.set_size(1,70)
homepapage_img_8.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1924290132.png','rb') as f:
        homepapage_img_8_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1924290132.png')
    sys.exit()

homepapage_img_8_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_8_img_data),
  'header': {'always_zero': 0, 'w': 1, 'h': 70, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_8_img_data
})

homepapage_img_8.set_src(homepapage_img_8_img)
homepapage_img_8.set_pivot(0,0)
homepapage_img_8.set_angle(0)
# create style style_homepapage_img_8_main_main_default
style_homepapage_img_8_main_main_default = lv.style_t()
style_homepapage_img_8_main_main_default.init()
style_homepapage_img_8_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_8_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_8_main_main_default.set_img_opa(255)

# add style for homepapage_img_8
homepapage_img_8.add_style(style_homepapage_img_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_7 = lv.img(homepapage_cont_1)
homepapage_img_7.set_pos(40,639)
homepapage_img_7.set_size(48,48)
homepapage_img_7.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1754214434.png','rb') as f:
        homepapage_img_7_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1754214434.png')
    sys.exit()

homepapage_img_7_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_7_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_7_img_data
})

homepapage_img_7.set_src(homepapage_img_7_img)
homepapage_img_7.set_pivot(0,0)
homepapage_img_7.set_angle(0)
# create style style_homepapage_img_7_main_main_default
style_homepapage_img_7_main_main_default = lv.style_t()
style_homepapage_img_7_main_main_default.init()
style_homepapage_img_7_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_7_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_7_main_main_default.set_img_opa(255)

# add style for homepapage_img_7
homepapage_img_7.add_style(style_homepapage_img_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_btn_1 = lv.btn(homepapage_cont_1)
homepapage_btn_1.set_pos(17,77)
homepapage_btn_1.set_size(142,50)
homepapage_btn_1_label = lv.label(homepapage_btn_1)
homepapage_btn_1_label.set_text("210")
homepapage_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
homepapage_btn_1_label.align(lv.ALIGN.CENTER,0,0)
homepapage_btn_1_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    homepapage_btn_1_label.set_style_text_font(lv.font_simsun_24, lv.STATE.DEFAULT)
except AttributeError:
    try:
        homepapage_btn_1_label.set_style_text_font(lv.font_montserrat_24, lv.STATE.DEFAULT)
    except AttributeError:
        homepapage_btn_1_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_homepapage_btn_1_main_main_default
style_homepapage_btn_1_main_main_default = lv.style_t()
style_homepapage_btn_1_main_main_default.init()
style_homepapage_btn_1_main_main_default.set_radius(35)
style_homepapage_btn_1_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_homepapage_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_homepapage_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_homepapage_btn_1_main_main_default.set_bg_opa(255)
style_homepapage_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_btn_1_main_main_default.set_shadow_opa(0)
style_homepapage_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_btn_1_main_main_default.set_border_width(0)
style_homepapage_btn_1_main_main_default.set_border_opa(255)

# add style for homepapage_btn_1
homepapage_btn_1.add_style(style_homepapage_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_18 = lv.img(homepapage_cont_1)
homepapage_img_18.set_pos(109,96)
homepapage_img_18.set_size(18,15)
homepapage_img_18.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1216195953.png','rb') as f:
        homepapage_img_18_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1216195953.png')
    sys.exit()

homepapage_img_18_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_18_img_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 15, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_18_img_data
})

homepapage_img_18.set_src(homepapage_img_18_img)
homepapage_img_18.set_pivot(0,0)
homepapage_img_18.set_angle(0)
# create style style_homepapage_img_18_main_main_default
style_homepapage_img_18_main_main_default = lv.style_t()
style_homepapage_img_18_main_main_default.init()
style_homepapage_img_18_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_18_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_18_main_main_default.set_img_opa(255)

# add style for homepapage_img_18
homepapage_img_18.add_style(style_homepapage_img_18_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_btn_2 = lv.btn(homepapage_cont_1)
homepapage_btn_2.set_pos(169,77)
homepapage_btn_2.set_size(142,50)
homepapage_btn_2_label = lv.label(homepapage_btn_2)
homepapage_btn_2_label.set_text("60")
homepapage_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
homepapage_btn_2_label.align(lv.ALIGN.CENTER,0,0)
homepapage_btn_2_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    homepapage_btn_2_label.set_style_text_font(lv.font_simsun_24, lv.STATE.DEFAULT)
except AttributeError:
    try:
        homepapage_btn_2_label.set_style_text_font(lv.font_montserrat_24, lv.STATE.DEFAULT)
    except AttributeError:
        homepapage_btn_2_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_homepapage_btn_2_main_main_default
style_homepapage_btn_2_main_main_default = lv.style_t()
style_homepapage_btn_2_main_main_default.init()
style_homepapage_btn_2_main_main_default.set_radius(35)
style_homepapage_btn_2_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_homepapage_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_homepapage_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_homepapage_btn_2_main_main_default.set_bg_opa(255)
style_homepapage_btn_2_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_btn_2_main_main_default.set_shadow_opa(0)
style_homepapage_btn_2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_btn_2_main_main_default.set_border_width(0)
style_homepapage_btn_2_main_main_default.set_border_opa(255)

# add style for homepapage_btn_2
homepapage_btn_2.add_style(style_homepapage_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_19 = lv.img(homepapage_cont_1)
homepapage_img_19.set_pos(255,96)
homepapage_img_19.set_size(18,15)
homepapage_img_19.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1216195953.png','rb') as f:
        homepapage_img_19_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1216195953.png')
    sys.exit()

homepapage_img_19_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_19_img_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 15, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_19_img_data
})

homepapage_img_19.set_src(homepapage_img_19_img)
homepapage_img_19.set_pivot(0,0)
homepapage_img_19.set_angle(0)
# create style style_homepapage_img_19_main_main_default
style_homepapage_img_19_main_main_default = lv.style_t()
style_homepapage_img_19_main_main_default.init()
style_homepapage_img_19_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_19_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_19_main_main_default.set_img_opa(255)

# add style for homepapage_img_19
homepapage_img_19.add_style(style_homepapage_img_19_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_btn_3 = lv.btn(homepapage_cont_1)
homepapage_btn_3.set_pos(321,77)
homepapage_btn_3.set_size(142,50)
homepapage_btn_3_label = lv.label(homepapage_btn_3)
homepapage_btn_3_label.set_text("100")
homepapage_btn_3.set_style_pad_all(0, lv.STATE.DEFAULT)
homepapage_btn_3_label.align(lv.ALIGN.CENTER,0,0)
homepapage_btn_3_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    homepapage_btn_3_label.set_style_text_font(lv.font_simsun_24, lv.STATE.DEFAULT)
except AttributeError:
    try:
        homepapage_btn_3_label.set_style_text_font(lv.font_montserrat_24, lv.STATE.DEFAULT)
    except AttributeError:
        homepapage_btn_3_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_homepapage_btn_3_main_main_default
style_homepapage_btn_3_main_main_default = lv.style_t()
style_homepapage_btn_3_main_main_default.init()
style_homepapage_btn_3_main_main_default.set_radius(35)
style_homepapage_btn_3_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_homepapage_btn_3_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_homepapage_btn_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_homepapage_btn_3_main_main_default.set_bg_opa(255)
style_homepapage_btn_3_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_btn_3_main_main_default.set_shadow_opa(0)
style_homepapage_btn_3_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_btn_3_main_main_default.set_border_width(0)
style_homepapage_btn_3_main_main_default.set_border_opa(255)

# add style for homepapage_btn_3
homepapage_btn_3.add_style(style_homepapage_btn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_20 = lv.img(homepapage_cont_1)
homepapage_img_20.set_pos(415,96)
homepapage_img_20.set_size(17,15)
homepapage_img_20.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp985501536.png','rb') as f:
        homepapage_img_20_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp985501536.png')
    sys.exit()

homepapage_img_20_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_20_img_data),
  'header': {'always_zero': 0, 'w': 17, 'h': 15, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_20_img_data
})

homepapage_img_20.set_src(homepapage_img_20_img)
homepapage_img_20.set_pivot(0,0)
homepapage_img_20.set_angle(0)
# create style style_homepapage_img_20_main_main_default
style_homepapage_img_20_main_main_default = lv.style_t()
style_homepapage_img_20_main_main_default.init()
style_homepapage_img_20_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_20_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_20_main_main_default.set_img_opa(255)

# add style for homepapage_img_20
homepapage_img_20.add_style(style_homepapage_img_20_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_4 = lv.img(homepapage_cont_1)
homepapage_img_4.set_pos(37,89)
homepapage_img_4.set_size(28,28)
homepapage_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp282059753.png','rb') as f:
        homepapage_img_4_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp282059753.png')
    sys.exit()

homepapage_img_4_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_4_img_data),
  'header': {'always_zero': 0, 'w': 28, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_4_img_data
})

homepapage_img_4.set_src(homepapage_img_4_img)
homepapage_img_4.set_pivot(0,0)
homepapage_img_4.set_angle(0)
# create style style_homepapage_img_4_main_main_default
style_homepapage_img_4_main_main_default = lv.style_t()
style_homepapage_img_4_main_main_default.init()
style_homepapage_img_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_4_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_4_main_main_default.set_img_opa(255)

# add style for homepapage_img_4
homepapage_img_4.add_style(style_homepapage_img_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_5 = lv.img(homepapage_cont_1)
homepapage_img_5.set_pos(191,89)
homepapage_img_5.set_size(28,28)
homepapage_img_5.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1008926814.png','rb') as f:
        homepapage_img_5_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1008926814.png')
    sys.exit()

homepapage_img_5_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_5_img_data),
  'header': {'always_zero': 0, 'w': 28, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_5_img_data
})

homepapage_img_5.set_src(homepapage_img_5_img)
homepapage_img_5.set_pivot(0,0)
homepapage_img_5.set_angle(0)
# create style style_homepapage_img_5_main_main_default
style_homepapage_img_5_main_main_default = lv.style_t()
style_homepapage_img_5_main_main_default.init()
style_homepapage_img_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_5_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_5_main_main_default.set_img_opa(255)

# add style for homepapage_img_5
homepapage_img_5.add_style(style_homepapage_img_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_6 = lv.img(homepapage_cont_1)
homepapage_img_6.set_pos(340,89)
homepapage_img_6.set_size(28,28)
homepapage_img_6.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp27770340.png','rb') as f:
        homepapage_img_6_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp27770340.png')
    sys.exit()

homepapage_img_6_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_6_img_data),
  'header': {'always_zero': 0, 'w': 28, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_6_img_data
})

homepapage_img_6.set_src(homepapage_img_6_img)
homepapage_img_6.set_pivot(0,0)
homepapage_img_6.set_angle(0)
# create style style_homepapage_img_6_main_main_default
style_homepapage_img_6_main_main_default = lv.style_t()
style_homepapage_img_6_main_main_default.init()
style_homepapage_img_6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_6_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_6_main_main_default.set_img_opa(255)

# add style for homepapage_img_6
homepapage_img_6.add_style(style_homepapage_img_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_2 = lv.img(homepapage_cont_1)
homepapage_img_2.set_pos(432,13)
homepapage_img_2.set_size(36,36)
homepapage_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1936798387.png','rb') as f:
        homepapage_img_2_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1936798387.png')
    sys.exit()

homepapage_img_2_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_2_img_data),
  'header': {'always_zero': 0, 'w': 36, 'h': 36, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_2_img_data
})

homepapage_img_2.set_src(homepapage_img_2_img)
homepapage_img_2.set_pivot(0,0)
homepapage_img_2.set_angle(0)
# create style style_homepapage_img_2_main_main_default
style_homepapage_img_2_main_main_default = lv.style_t()
style_homepapage_img_2_main_main_default.init()
style_homepapage_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_2_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_2_main_main_default.set_img_opa(255)

# add style for homepapage_img_2
homepapage_img_2.add_style(style_homepapage_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

homepapage_img_1 = lv.img(homepapage_cont_1)
homepapage_img_1.set_pos(12,20)
homepapage_img_1.set_size(156,21)
homepapage_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp344806701.png','rb') as f:
        homepapage_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp344806701.png')
    sys.exit()

homepapage_img_1_img = lv.img_dsc_t({
  'data_size': len(homepapage_img_1_img_data),
  'header': {'always_zero': 0, 'w': 156, 'h': 21, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': homepapage_img_1_img_data
})

homepapage_img_1.set_src(homepapage_img_1_img)
homepapage_img_1.set_pivot(0,0)
homepapage_img_1.set_angle(0)
# create style style_homepapage_img_1_main_main_default
style_homepapage_img_1_main_main_default = lv.style_t()
style_homepapage_img_1_main_main_default.init()
style_homepapage_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_homepapage_img_1_main_main_default.set_img_recolor_opa(0)
style_homepapage_img_1_main_main_default.set_img_opa(255)

# add style for homepapage_img_1
homepapage_img_1.add_style(style_homepapage_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_homepapage_cont_1_main_main_default
style_homepapage_cont_1_main_main_default = lv.style_t()
style_homepapage_cont_1_main_main_default.init()
style_homepapage_cont_1_main_main_default.set_radius(0)
style_homepapage_cont_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_homepapage_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_homepapage_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_homepapage_cont_1_main_main_default.set_bg_opa(255)
style_homepapage_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_homepapage_cont_1_main_main_default.set_border_width(0)
style_homepapage_cont_1_main_main_default.set_border_opa(255)
style_homepapage_cont_1_main_main_default.set_pad_left(0)
style_homepapage_cont_1_main_main_default.set_pad_right(0)
style_homepapage_cont_1_main_main_default.set_pad_top(0)
style_homepapage_cont_1_main_main_default.set_pad_bottom(0)

# add style for homepapage_cont_1
homepapage_cont_1.add_style(style_homepapage_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove = lv.obj()
# create style style_axismove_main_main_default
style_axismove_main_main_default = lv.style_t()
style_axismove_main_main_default.init()
style_axismove_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_axismove_main_main_default.set_bg_opa(255)

# add style for axismove
axismove.add_style(style_axismove_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_cont_1 = lv.obj(axismove)
axismove_cont_1.set_pos(0,0)
axismove_cont_1.set_size(480,800)
axismove_label_2 = lv.label(axismove_cont_1)
axismove_label_2.set_pos(0,47)
axismove_label_2.set_size(480,670)
# create style style_axismove_label_2_main_main_default
style_axismove_label_2_main_main_default = lv.style_t()
style_axismove_label_2_main_main_default.init()
style_axismove_label_2_main_main_default.set_radius(0)
style_axismove_label_2_main_main_default.set_bg_color(lv.color_make(0x23,0x24,0x26))
style_axismove_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x23,0x24,0x26))
style_axismove_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_axismove_label_2_main_main_default.set_bg_opa(255)
style_axismove_label_2_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_axismove_label_2_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_axismove_label_2_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_axismove_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_axismove_label_2_main_main_default.set_text_letter_space(2)
style_axismove_label_2_main_main_default.set_pad_left(0)
style_axismove_label_2_main_main_default.set_pad_right(0)
style_axismove_label_2_main_main_default.set_pad_top(0)
style_axismove_label_2_main_main_default.set_pad_bottom(0)

# add style for axismove_label_2
axismove_label_2.add_style(style_axismove_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_btn_2 = lv.btn(axismove_cont_1)
axismove_btn_2.set_pos(12,79)
axismove_btn_2.set_size(450,100)
# create style style_axismove_btn_2_main_main_default
style_axismove_btn_2_main_main_default = lv.style_t()
style_axismove_btn_2_main_main_default.init()
style_axismove_btn_2_main_main_default.set_radius(8)
style_axismove_btn_2_main_main_default.set_bg_color(lv.color_make(0x3a,0x3d,0x42))
style_axismove_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x3a,0x3d,0x42))
style_axismove_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_axismove_btn_2_main_main_default.set_bg_opa(255)
style_axismove_btn_2_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_btn_2_main_main_default.set_shadow_opa(0)
style_axismove_btn_2_main_main_default.set_border_color(lv.color_make(0x43,0x45,0x49))
style_axismove_btn_2_main_main_default.set_border_width(1)
style_axismove_btn_2_main_main_default.set_border_opa(255)

# add style for axismove_btn_2
axismove_btn_2.add_style(style_axismove_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_label_3 = lv.label(axismove_cont_1)
axismove_label_3.set_pos(37,130)
axismove_label_3.set_size(44,24)
axismove_label_3.set_text("220")
axismove_label_3.set_long_mode(lv.label.LONG.WRAP)
axismove_label_3.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_axismove_label_3_main_main_default
style_axismove_label_3_main_main_default = lv.style_t()
style_axismove_label_3_main_main_default.init()
style_axismove_label_3_main_main_default.set_radius(0)
style_axismove_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_axismove_label_3_main_main_default.set_bg_opa(0)
style_axismove_label_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_axismove_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_axismove_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_axismove_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_axismove_label_3_main_main_default.set_text_letter_space(1)
style_axismove_label_3_main_main_default.set_pad_left(0)
style_axismove_label_3_main_main_default.set_pad_right(0)
style_axismove_label_3_main_main_default.set_pad_top(0)
style_axismove_label_3_main_main_default.set_pad_bottom(0)

# add style for axismove_label_3
axismove_label_3.add_style(style_axismove_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_label_8 = lv.label(axismove_cont_1)
axismove_label_8.set_pos(390,312)
axismove_label_8.set_size(80,24)
axismove_label_8.set_text("进退料")
axismove_label_8.set_long_mode(lv.label.LONG.WRAP)
axismove_label_8.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_axismove_label_8_main_main_default
style_axismove_label_8_main_main_default = lv.style_t()
style_axismove_label_8_main_main_default.init()
style_axismove_label_8_main_main_default.set_radius(0)
style_axismove_label_8_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_axismove_label_8_main_main_default.set_bg_opa(0)
style_axismove_label_8_main_main_default.set_text_color(lv.color_make(0x6a,0x70,0x7d))
try:
    style_axismove_label_8_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_axismove_label_8_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_axismove_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_axismove_label_8_main_main_default.set_text_letter_space(0)
style_axismove_label_8_main_main_default.set_pad_left(0)
style_axismove_label_8_main_main_default.set_pad_right(0)
style_axismove_label_8_main_main_default.set_pad_top(0)
style_axismove_label_8_main_main_default.set_pad_bottom(0)

# add style for axismove_label_8
axismove_label_8.add_style(style_axismove_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_label_4 = lv.label(axismove_cont_1)
axismove_label_4.set_pos(154,130)
axismove_label_4.set_size(44,24)
axismove_label_4.set_text("60")
axismove_label_4.set_long_mode(lv.label.LONG.WRAP)
axismove_label_4.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_axismove_label_4_main_main_default
style_axismove_label_4_main_main_default = lv.style_t()
style_axismove_label_4_main_main_default.init()
style_axismove_label_4_main_main_default.set_radius(0)
style_axismove_label_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_axismove_label_4_main_main_default.set_bg_opa(0)
style_axismove_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_axismove_label_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_axismove_label_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_axismove_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_axismove_label_4_main_main_default.set_text_letter_space(1)
style_axismove_label_4_main_main_default.set_pad_left(0)
style_axismove_label_4_main_main_default.set_pad_right(0)
style_axismove_label_4_main_main_default.set_pad_top(0)
style_axismove_label_4_main_main_default.set_pad_bottom(0)

# add style for axismove_label_4
axismove_label_4.add_style(style_axismove_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_label_5 = lv.label(axismove_cont_1)
axismove_label_5.set_pos(262,130)
axismove_label_5.set_size(44,24)
axismove_label_5.set_text("100")
axismove_label_5.set_long_mode(lv.label.LONG.WRAP)
axismove_label_5.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_axismove_label_5_main_main_default
style_axismove_label_5_main_main_default = lv.style_t()
style_axismove_label_5_main_main_default.init()
style_axismove_label_5_main_main_default.set_radius(0)
style_axismove_label_5_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_axismove_label_5_main_main_default.set_bg_opa(0)
style_axismove_label_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_axismove_label_5_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_axismove_label_5_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_axismove_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_axismove_label_5_main_main_default.set_text_letter_space(1)
style_axismove_label_5_main_main_default.set_pad_left(0)
style_axismove_label_5_main_main_default.set_pad_right(0)
style_axismove_label_5_main_main_default.set_pad_top(0)
style_axismove_label_5_main_main_default.set_pad_bottom(0)

# add style for axismove_label_5
axismove_label_5.add_style(style_axismove_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_label_6 = lv.label(axismove_cont_1)
axismove_label_6.set_pos(356,136)
axismove_label_6.set_size(100,24)
axismove_label_6.set_text("模型风扇")
axismove_label_6.set_long_mode(lv.label.LONG.WRAP)
axismove_label_6.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_axismove_label_6_main_main_default
style_axismove_label_6_main_main_default = lv.style_t()
style_axismove_label_6_main_main_default.init()
style_axismove_label_6_main_main_default.set_radius(0)
style_axismove_label_6_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_axismove_label_6_main_main_default.set_bg_opa(0)
style_axismove_label_6_main_main_default.set_text_color(lv.color_make(0x83,0x86,0x8b))
try:
    style_axismove_label_6_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_axismove_label_6_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_axismove_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_axismove_label_6_main_main_default.set_text_letter_space(0)
style_axismove_label_6_main_main_default.set_pad_left(0)
style_axismove_label_6_main_main_default.set_pad_right(0)
style_axismove_label_6_main_main_default.set_pad_top(0)
style_axismove_label_6_main_main_default.set_pad_bottom(0)

# add style for axismove_label_6
axismove_label_6.add_style(style_axismove_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_label_7 = lv.label(axismove_cont_1)
axismove_label_7.set_pos(15,217)
axismove_label_7.set_size(456,56)
# create style style_axismove_label_7_main_main_default
style_axismove_label_7_main_main_default = lv.style_t()
style_axismove_label_7_main_main_default.init()
style_axismove_label_7_main_main_default.set_radius(40)
style_axismove_label_7_main_main_default.set_bg_color(lv.color_make(0x43,0x45,0x49))
style_axismove_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x43,0x45,0x49))
style_axismove_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_axismove_label_7_main_main_default.set_bg_opa(255)
style_axismove_label_7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_axismove_label_7_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_axismove_label_7_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_axismove_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_axismove_label_7_main_main_default.set_text_letter_space(0)
style_axismove_label_7_main_main_default.set_pad_left(0)
style_axismove_label_7_main_main_default.set_pad_right(0)
style_axismove_label_7_main_main_default.set_pad_top(0)
style_axismove_label_7_main_main_default.set_pad_bottom(0)

# add style for axismove_label_7
axismove_label_7.add_style(style_axismove_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_btn_3 = lv.btn(axismove_cont_1)
axismove_btn_3.set_pos(15,217)
axismove_btn_3.set_size(152,56)
axismove_btn_3_label = lv.label(axismove_btn_3)
axismove_btn_3_label.set_text("0.1mm")
axismove_btn_3.set_style_pad_all(0, lv.STATE.DEFAULT)
axismove_btn_3_label.align(lv.ALIGN.CENTER,0,0)
axismove_btn_3_label.set_style_text_color(lv.color_make(0x00,0x00,0x00), lv.STATE.DEFAULT)
try:
    axismove_btn_3_label.set_style_text_font(lv.font_simsun_24, lv.STATE.DEFAULT)
except AttributeError:
    try:
        axismove_btn_3_label.set_style_text_font(lv.font_montserrat_24, lv.STATE.DEFAULT)
    except AttributeError:
        axismove_btn_3_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_axismove_btn_3_main_main_default
style_axismove_btn_3_main_main_default = lv.style_t()
style_axismove_btn_3_main_main_default.init()
style_axismove_btn_3_main_main_default.set_radius(32)
style_axismove_btn_3_main_main_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_axismove_btn_3_main_main_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_axismove_btn_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_axismove_btn_3_main_main_default.set_bg_opa(120)
style_axismove_btn_3_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_btn_3_main_main_default.set_shadow_opa(0)
style_axismove_btn_3_main_main_default.set_border_color(lv.color_make(0x42,0xbd,0xd8))
style_axismove_btn_3_main_main_default.set_border_width(2)
style_axismove_btn_3_main_main_default.set_border_opa(255)

# add style for axismove_btn_3
axismove_btn_3.add_style(style_axismove_btn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_btn_4 = lv.btn(axismove_cont_1)
axismove_btn_4.set_pos(167,217)
axismove_btn_4.set_size(152,56)
axismove_btn_4_label = lv.label(axismove_btn_4)
axismove_btn_4_label.set_text("1mm")
axismove_btn_4.set_style_pad_all(0, lv.STATE.DEFAULT)
axismove_btn_4_label.align(lv.ALIGN.CENTER,0,0)
axismove_btn_4_label.set_style_text_color(lv.color_make(0x00,0x00,0x00), lv.STATE.DEFAULT)
try:
    axismove_btn_4_label.set_style_text_font(lv.font_simsun_24, lv.STATE.DEFAULT)
except AttributeError:
    try:
        axismove_btn_4_label.set_style_text_font(lv.font_montserrat_24, lv.STATE.DEFAULT)
    except AttributeError:
        axismove_btn_4_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_axismove_btn_4_main_main_default
style_axismove_btn_4_main_main_default = lv.style_t()
style_axismove_btn_4_main_main_default.init()
style_axismove_btn_4_main_main_default.set_radius(32)
style_axismove_btn_4_main_main_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_axismove_btn_4_main_main_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_axismove_btn_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_axismove_btn_4_main_main_default.set_bg_opa(120)
style_axismove_btn_4_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_btn_4_main_main_default.set_shadow_opa(0)
style_axismove_btn_4_main_main_default.set_border_color(lv.color_make(0x42,0xbd,0xd8))
style_axismove_btn_4_main_main_default.set_border_width(2)
style_axismove_btn_4_main_main_default.set_border_opa(255)

# add style for axismove_btn_4
axismove_btn_4.add_style(style_axismove_btn_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_btn_5 = lv.btn(axismove_cont_1)
axismove_btn_5.set_pos(319,217)
axismove_btn_5.set_size(152,56)
axismove_btn_5_label = lv.label(axismove_btn_5)
axismove_btn_5_label.set_text("1mm")
axismove_btn_5.set_style_pad_all(0, lv.STATE.DEFAULT)
axismove_btn_5_label.align(lv.ALIGN.CENTER,0,0)
axismove_btn_5_label.set_style_text_color(lv.color_make(0x00,0x00,0x00), lv.STATE.DEFAULT)
try:
    axismove_btn_5_label.set_style_text_font(lv.font_simsun_24, lv.STATE.DEFAULT)
except AttributeError:
    try:
        axismove_btn_5_label.set_style_text_font(lv.font_montserrat_24, lv.STATE.DEFAULT)
    except AttributeError:
        axismove_btn_5_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_axismove_btn_5_main_main_default
style_axismove_btn_5_main_main_default = lv.style_t()
style_axismove_btn_5_main_main_default.init()
style_axismove_btn_5_main_main_default.set_radius(32)
style_axismove_btn_5_main_main_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_axismove_btn_5_main_main_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_axismove_btn_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_axismove_btn_5_main_main_default.set_bg_opa(120)
style_axismove_btn_5_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_btn_5_main_main_default.set_shadow_opa(0)
style_axismove_btn_5_main_main_default.set_border_color(lv.color_make(0x42,0xbd,0xd8))
style_axismove_btn_5_main_main_default.set_border_width(2)
style_axismove_btn_5_main_main_default.set_border_opa(255)

# add style for axismove_btn_5
axismove_btn_5.add_style(style_axismove_btn_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_img_6 = lv.img(axismove_cont_1)
axismove_img_6.set_pos(55,97)
axismove_img_6.set_size(28,28)
axismove_img_6.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1025961811.png','rb') as f:
        axismove_img_6_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1025961811.png')
    sys.exit()

axismove_img_6_img = lv.img_dsc_t({
  'data_size': len(axismove_img_6_img_data),
  'header': {'always_zero': 0, 'w': 28, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': axismove_img_6_img_data
})

axismove_img_6.set_src(axismove_img_6_img)
axismove_img_6.set_pivot(0,0)
axismove_img_6.set_angle(0)
# create style style_axismove_img_6_main_main_default
style_axismove_img_6_main_main_default = lv.style_t()
style_axismove_img_6_main_main_default.init()
style_axismove_img_6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_axismove_img_6_main_main_default.set_img_recolor_opa(0)
style_axismove_img_6_main_main_default.set_img_opa(255)

# add style for axismove_img_6
axismove_img_6.add_style(style_axismove_img_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_img_8 = lv.img(axismove_cont_1)
axismove_img_8.set_pos(164,97)
axismove_img_8.set_size(32,26)
axismove_img_8.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp775811039.png','rb') as f:
        axismove_img_8_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp775811039.png')
    sys.exit()

axismove_img_8_img = lv.img_dsc_t({
  'data_size': len(axismove_img_8_img_data),
  'header': {'always_zero': 0, 'w': 32, 'h': 26, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': axismove_img_8_img_data
})

axismove_img_8.set_src(axismove_img_8_img)
axismove_img_8.set_pivot(0,0)
axismove_img_8.set_angle(0)
# create style style_axismove_img_8_main_main_default
style_axismove_img_8_main_main_default = lv.style_t()
style_axismove_img_8_main_main_default.init()
style_axismove_img_8_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_axismove_img_8_main_main_default.set_img_recolor_opa(0)
style_axismove_img_8_main_main_default.set_img_opa(255)

# add style for axismove_img_8
axismove_img_8.add_style(style_axismove_img_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_img_13 = lv.img(axismove_cont_1)
axismove_img_13.set_pos(274,100)
axismove_img_13.set_size(32,21)
axismove_img_13.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-676160800.png','rb') as f:
        axismove_img_13_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-676160800.png')
    sys.exit()

axismove_img_13_img = lv.img_dsc_t({
  'data_size': len(axismove_img_13_img_data),
  'header': {'always_zero': 0, 'w': 32, 'h': 21, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': axismove_img_13_img_data
})

axismove_img_13.set_src(axismove_img_13_img)
axismove_img_13.set_pivot(0,0)
axismove_img_13.set_angle(0)
# create style style_axismove_img_13_main_main_default
style_axismove_img_13_main_main_default = lv.style_t()
style_axismove_img_13_main_main_default.init()
style_axismove_img_13_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_axismove_img_13_main_main_default.set_img_recolor_opa(0)
style_axismove_img_13_main_main_default.set_img_opa(255)

# add style for axismove_img_13
axismove_img_13.add_style(style_axismove_img_13_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_img_15 = lv.img(axismove_cont_1)
axismove_img_15.set_pos(387,95)
axismove_img_15.set_size(41,41)
axismove_img_15.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-440560184.png','rb') as f:
        axismove_img_15_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-440560184.png')
    sys.exit()

axismove_img_15_img = lv.img_dsc_t({
  'data_size': len(axismove_img_15_img_data),
  'header': {'always_zero': 0, 'w': 41, 'h': 41, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': axismove_img_15_img_data
})

axismove_img_15.set_src(axismove_img_15_img)
axismove_img_15.set_pivot(0,0)
axismove_img_15.set_angle(0)
# create style style_axismove_img_15_main_main_default
style_axismove_img_15_main_main_default = lv.style_t()
style_axismove_img_15_main_main_default.init()
style_axismove_img_15_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_axismove_img_15_main_main_default.set_img_recolor_opa(0)
style_axismove_img_15_main_main_default.set_img_opa(255)

# add style for axismove_img_15
axismove_img_15.add_style(style_axismove_img_15_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_img_16 = lv.img(axismove_cont_1)
axismove_img_16.set_pos(16,351)
axismove_img_16.set_size(453,304)
axismove_img_16.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp308217242.png','rb') as f:
        axismove_img_16_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp308217242.png')
    sys.exit()

axismove_img_16_img = lv.img_dsc_t({
  'data_size': len(axismove_img_16_img_data),
  'header': {'always_zero': 0, 'w': 453, 'h': 304, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': axismove_img_16_img_data
})

axismove_img_16.set_src(axismove_img_16_img)
axismove_img_16.set_pivot(0,0)
axismove_img_16.set_angle(0)
# create style style_axismove_img_16_main_main_default
style_axismove_img_16_main_main_default = lv.style_t()
style_axismove_img_16_main_main_default.init()
style_axismove_img_16_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_axismove_img_16_main_main_default.set_img_recolor_opa(0)
style_axismove_img_16_main_main_default.set_img_opa(255)

# add style for axismove_img_16
axismove_img_16.add_style(style_axismove_img_16_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_btn_6 = lv.btn(axismove_cont_1)
axismove_btn_6.set_pos(18,411)
axismove_btn_6.set_size(64,81)
# create style style_axismove_btn_6_main_main_default
style_axismove_btn_6_main_main_default = lv.style_t()
style_axismove_btn_6_main_main_default.init()
style_axismove_btn_6_main_main_default.set_radius(0)
style_axismove_btn_6_main_main_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_axismove_btn_6_main_main_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_axismove_btn_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_axismove_btn_6_main_main_default.set_bg_opa(0)
style_axismove_btn_6_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_btn_6_main_main_default.set_shadow_opa(0)
style_axismove_btn_6_main_main_default.set_border_color(lv.color_make(0x42,0xbd,0xd8))
style_axismove_btn_6_main_main_default.set_border_width(0)
style_axismove_btn_6_main_main_default.set_border_opa(255)

# add style for axismove_btn_6
axismove_btn_6.add_style(style_axismove_btn_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_btn_7 = lv.btn(axismove_cont_1)
axismove_btn_7.set_pos(18,493)
axismove_btn_7.set_size(64,81)
# create style style_axismove_btn_7_main_main_default
style_axismove_btn_7_main_main_default = lv.style_t()
style_axismove_btn_7_main_main_default.init()
style_axismove_btn_7_main_main_default.set_radius(0)
style_axismove_btn_7_main_main_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_axismove_btn_7_main_main_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_axismove_btn_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_axismove_btn_7_main_main_default.set_bg_opa(0)
style_axismove_btn_7_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_btn_7_main_main_default.set_shadow_opa(0)
style_axismove_btn_7_main_main_default.set_border_color(lv.color_make(0x42,0xbd,0xd8))
style_axismove_btn_7_main_main_default.set_border_width(0)
style_axismove_btn_7_main_main_default.set_border_opa(255)

# add style for axismove_btn_7
axismove_btn_7.add_style(style_axismove_btn_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_img_9 = lv.img(axismove_cont_1)
axismove_img_9.set_pos(124,91)
axismove_img_9.set_size(1,80)
axismove_img_9.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1617147120.png','rb') as f:
        axismove_img_9_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1617147120.png')
    sys.exit()

axismove_img_9_img = lv.img_dsc_t({
  'data_size': len(axismove_img_9_img_data),
  'header': {'always_zero': 0, 'w': 1, 'h': 80, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': axismove_img_9_img_data
})

axismove_img_9.set_src(axismove_img_9_img)
axismove_img_9.set_pivot(0,0)
axismove_img_9.set_angle(0)
# create style style_axismove_img_9_main_main_default
style_axismove_img_9_main_main_default = lv.style_t()
style_axismove_img_9_main_main_default.init()
style_axismove_img_9_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_axismove_img_9_main_main_default.set_img_recolor_opa(0)
style_axismove_img_9_main_main_default.set_img_opa(255)

# add style for axismove_img_9
axismove_img_9.add_style(style_axismove_img_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_img_11 = lv.img(axismove_cont_1)
axismove_img_11.set_pos(234,91)
axismove_img_11.set_size(1,80)
axismove_img_11.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1617147120.png','rb') as f:
        axismove_img_11_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1617147120.png')
    sys.exit()

axismove_img_11_img = lv.img_dsc_t({
  'data_size': len(axismove_img_11_img_data),
  'header': {'always_zero': 0, 'w': 1, 'h': 80, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': axismove_img_11_img_data
})

axismove_img_11.set_src(axismove_img_11_img)
axismove_img_11.set_pivot(0,0)
axismove_img_11.set_angle(0)
# create style style_axismove_img_11_main_main_default
style_axismove_img_11_main_main_default = lv.style_t()
style_axismove_img_11_main_main_default.init()
style_axismove_img_11_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_axismove_img_11_main_main_default.set_img_recolor_opa(0)
style_axismove_img_11_main_main_default.set_img_opa(255)

# add style for axismove_img_11
axismove_img_11.add_style(style_axismove_img_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_img_12 = lv.img(axismove_cont_1)
axismove_img_12.set_pos(344,91)
axismove_img_12.set_size(1,80)
axismove_img_12.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1617147120.png','rb') as f:
        axismove_img_12_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1617147120.png')
    sys.exit()

axismove_img_12_img = lv.img_dsc_t({
  'data_size': len(axismove_img_12_img_data),
  'header': {'always_zero': 0, 'w': 1, 'h': 80, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': axismove_img_12_img_data
})

axismove_img_12.set_src(axismove_img_12_img)
axismove_img_12.set_pivot(0,0)
axismove_img_12.set_angle(0)
# create style style_axismove_img_12_main_main_default
style_axismove_img_12_main_main_default = lv.style_t()
style_axismove_img_12_main_main_default.init()
style_axismove_img_12_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_axismove_img_12_main_main_default.set_img_recolor_opa(0)
style_axismove_img_12_main_main_default.set_img_opa(255)

# add style for axismove_img_12
axismove_img_12.add_style(style_axismove_img_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_img_7 = lv.img(axismove_cont_1)
axismove_img_7.set_pos(85,136)
axismove_img_7.set_size(18,15)
axismove_img_7.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1155251826.png','rb') as f:
        axismove_img_7_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1155251826.png')
    sys.exit()

axismove_img_7_img = lv.img_dsc_t({
  'data_size': len(axismove_img_7_img_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 15, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': axismove_img_7_img_data
})

axismove_img_7.set_src(axismove_img_7_img)
axismove_img_7.set_pivot(0,0)
axismove_img_7.set_angle(0)
# create style style_axismove_img_7_main_main_default
style_axismove_img_7_main_main_default = lv.style_t()
style_axismove_img_7_main_main_default.init()
style_axismove_img_7_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_axismove_img_7_main_main_default.set_img_recolor_opa(0)
style_axismove_img_7_main_main_default.set_img_opa(255)

# add style for axismove_img_7
axismove_img_7.add_style(style_axismove_img_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_img_10 = lv.img(axismove_cont_1)
axismove_img_10.set_pos(189,136)
axismove_img_10.set_size(18,15)
axismove_img_10.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1155251826.png','rb') as f:
        axismove_img_10_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1155251826.png')
    sys.exit()

axismove_img_10_img = lv.img_dsc_t({
  'data_size': len(axismove_img_10_img_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 15, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': axismove_img_10_img_data
})

axismove_img_10.set_src(axismove_img_10_img)
axismove_img_10.set_pivot(0,0)
axismove_img_10.set_angle(0)
# create style style_axismove_img_10_main_main_default
style_axismove_img_10_main_main_default = lv.style_t()
style_axismove_img_10_main_main_default.init()
style_axismove_img_10_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_axismove_img_10_main_main_default.set_img_recolor_opa(0)
style_axismove_img_10_main_main_default.set_img_opa(255)

# add style for axismove_img_10
axismove_img_10.add_style(style_axismove_img_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_img_14 = lv.img(axismove_cont_1)
axismove_img_14.set_pos(307,136)
axismove_img_14.set_size(18,15)
axismove_img_14.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp141029665.png','rb') as f:
        axismove_img_14_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp141029665.png')
    sys.exit()

axismove_img_14_img = lv.img_dsc_t({
  'data_size': len(axismove_img_14_img_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 15, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': axismove_img_14_img_data
})

axismove_img_14.set_src(axismove_img_14_img)
axismove_img_14.set_pivot(0,0)
axismove_img_14.set_angle(0)
# create style style_axismove_img_14_main_main_default
style_axismove_img_14_main_main_default = lv.style_t()
style_axismove_img_14_main_main_default.init()
style_axismove_img_14_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_axismove_img_14_main_main_default.set_img_recolor_opa(0)
style_axismove_img_14_main_main_default.set_img_opa(255)

# add style for axismove_img_14
axismove_img_14.add_style(style_axismove_img_14_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_btn_1 = lv.btn(axismove_cont_1)
axismove_btn_1.set_pos(25,5)
axismove_btn_1.set_size(194,46)
axismove_btn_1_label = lv.label(axismove_btn_1)
axismove_btn_1_label.set_text("轴移动/温度")
axismove_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
axismove_btn_1_label.align(lv.ALIGN.CENTER,0,0)
axismove_btn_1_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    axismove_btn_1_label.set_style_text_font(lv.font_simsun_28, lv.STATE.DEFAULT)
except AttributeError:
    try:
        axismove_btn_1_label.set_style_text_font(lv.font_montserrat_28, lv.STATE.DEFAULT)
    except AttributeError:
        axismove_btn_1_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_axismove_btn_1_main_main_default
style_axismove_btn_1_main_main_default = lv.style_t()
style_axismove_btn_1_main_main_default.init()
style_axismove_btn_1_main_main_default.set_radius(0)
style_axismove_btn_1_main_main_default.set_bg_color(lv.color_make(0x23,0x24,0x26))
style_axismove_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x23,0x24,0x26))
style_axismove_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_axismove_btn_1_main_main_default.set_bg_opa(255)
style_axismove_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_btn_1_main_main_default.set_shadow_opa(0)
style_axismove_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_btn_1_main_main_default.set_border_width(0)
style_axismove_btn_1_main_main_default.set_border_opa(255)

# add style for axismove_btn_1
axismove_btn_1.add_style(style_axismove_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_label_1 = lv.label(axismove_cont_1)
axismove_label_1.set_pos(0,720)
axismove_label_1.set_size(480,80)
# create style style_axismove_label_1_main_main_default
style_axismove_label_1_main_main_default = lv.style_t()
style_axismove_label_1_main_main_default.init()
style_axismove_label_1_main_main_default.set_radius(0)
style_axismove_label_1_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_axismove_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_axismove_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_axismove_label_1_main_main_default.set_bg_opa(255)
style_axismove_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_axismove_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_axismove_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_axismove_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_axismove_label_1_main_main_default.set_text_letter_space(0)
style_axismove_label_1_main_main_default.set_pad_left(0)
style_axismove_label_1_main_main_default.set_pad_right(0)
style_axismove_label_1_main_main_default.set_pad_top(0)
style_axismove_label_1_main_main_default.set_pad_bottom(0)

# add style for axismove_label_1
axismove_label_1.add_style(style_axismove_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_img_1 = lv.img(axismove_cont_1)
axismove_img_1.set_pos(30,742)
axismove_img_1.set_size(48,48)
axismove_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png','rb') as f:
        axismove_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png')
    sys.exit()

axismove_img_1_img = lv.img_dsc_t({
  'data_size': len(axismove_img_1_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': axismove_img_1_img_data
})

axismove_img_1.set_src(axismove_img_1_img)
axismove_img_1.set_pivot(0,0)
axismove_img_1.set_angle(0)
# create style style_axismove_img_1_main_main_default
style_axismove_img_1_main_main_default = lv.style_t()
style_axismove_img_1_main_main_default.init()
style_axismove_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_axismove_img_1_main_main_default.set_img_recolor_opa(0)
style_axismove_img_1_main_main_default.set_img_opa(255)

# add style for axismove_img_1
axismove_img_1.add_style(style_axismove_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_img_2 = lv.img(axismove_cont_1)
axismove_img_2.set_pos(128,742)
axismove_img_2.set_size(48,48)
axismove_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png','rb') as f:
        axismove_img_2_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png')
    sys.exit()

axismove_img_2_img = lv.img_dsc_t({
  'data_size': len(axismove_img_2_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': axismove_img_2_img_data
})

axismove_img_2.set_src(axismove_img_2_img)
axismove_img_2.set_pivot(0,0)
axismove_img_2.set_angle(0)
# create style style_axismove_img_2_main_main_default
style_axismove_img_2_main_main_default = lv.style_t()
style_axismove_img_2_main_main_default.init()
style_axismove_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_axismove_img_2_main_main_default.set_img_recolor_opa(0)
style_axismove_img_2_main_main_default.set_img_opa(255)

# add style for axismove_img_2
axismove_img_2.add_style(style_axismove_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_img_3 = lv.img(axismove_cont_1)
axismove_img_3.set_pos(224,742)
axismove_img_3.set_size(48,48)
axismove_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png','rb') as f:
        axismove_img_3_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png')
    sys.exit()

axismove_img_3_img = lv.img_dsc_t({
  'data_size': len(axismove_img_3_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': axismove_img_3_img_data
})

axismove_img_3.set_src(axismove_img_3_img)
axismove_img_3.set_pivot(0,0)
axismove_img_3.set_angle(0)
# create style style_axismove_img_3_main_main_default
style_axismove_img_3_main_main_default = lv.style_t()
style_axismove_img_3_main_main_default.init()
style_axismove_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_axismove_img_3_main_main_default.set_img_recolor_opa(0)
style_axismove_img_3_main_main_default.set_img_opa(255)

# add style for axismove_img_3
axismove_img_3.add_style(style_axismove_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_img_4 = lv.img(axismove_cont_1)
axismove_img_4.set_pos(318,742)
axismove_img_4.set_size(48,48)
axismove_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png','rb') as f:
        axismove_img_4_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png')
    sys.exit()

axismove_img_4_img = lv.img_dsc_t({
  'data_size': len(axismove_img_4_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': axismove_img_4_img_data
})

axismove_img_4.set_src(axismove_img_4_img)
axismove_img_4.set_pivot(0,0)
axismove_img_4.set_angle(0)
# create style style_axismove_img_4_main_main_default
style_axismove_img_4_main_main_default = lv.style_t()
style_axismove_img_4_main_main_default.init()
style_axismove_img_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_axismove_img_4_main_main_default.set_img_recolor_opa(0)
style_axismove_img_4_main_main_default.set_img_opa(255)

# add style for axismove_img_4
axismove_img_4.add_style(style_axismove_img_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

axismove_img_5 = lv.img(axismove_cont_1)
axismove_img_5.set_pos(414,742)
axismove_img_5.set_size(48,48)
axismove_img_5.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png','rb') as f:
        axismove_img_5_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png')
    sys.exit()

axismove_img_5_img = lv.img_dsc_t({
  'data_size': len(axismove_img_5_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': axismove_img_5_img_data
})

axismove_img_5.set_src(axismove_img_5_img)
axismove_img_5.set_pivot(0,0)
axismove_img_5.set_angle(0)
# create style style_axismove_img_5_main_main_default
style_axismove_img_5_main_main_default = lv.style_t()
style_axismove_img_5_main_main_default.init()
style_axismove_img_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_axismove_img_5_main_main_default.set_img_recolor_opa(0)
style_axismove_img_5_main_main_default.set_img_opa(255)

# add style for axismove_img_5
axismove_img_5.add_style(style_axismove_img_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_axismove_cont_1_main_main_default
style_axismove_cont_1_main_main_default = lv.style_t()
style_axismove_cont_1_main_main_default.init()
style_axismove_cont_1_main_main_default.set_radius(0)
style_axismove_cont_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_axismove_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_axismove_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_axismove_cont_1_main_main_default.set_bg_opa(255)
style_axismove_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_axismove_cont_1_main_main_default.set_border_width(0)
style_axismove_cont_1_main_main_default.set_border_opa(255)
style_axismove_cont_1_main_main_default.set_pad_left(0)
style_axismove_cont_1_main_main_default.set_pad_right(0)
style_axismove_cont_1_main_main_default.set_pad_top(0)
style_axismove_cont_1_main_main_default.set_pad_bottom(0)

# add style for axismove_cont_1
axismove_cont_1.add_style(style_axismove_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management = lv.obj()
# create style style_file_management_main_main_default
style_file_management_main_main_default = lv.style_t()
style_file_management_main_main_default.init()
style_file_management_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_file_management_main_main_default.set_bg_opa(0)

# add style for file_management
file_management.add_style(style_file_management_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_tabview_1 = lv.tabview(file_management, lv.DIR.TOP, 47)
file_management_tabview_1_tab_btns = file_management_tabview_1.get_tab_btns()
# create style style_file_management_tabview_1_extra_btnm_main_default
style_file_management_tabview_1_extra_btnm_main_default = lv.style_t()
style_file_management_tabview_1_extra_btnm_main_default.init()
style_file_management_tabview_1_extra_btnm_main_default.set_bg_color(lv.color_make(0x23,0x24,0x26))
style_file_management_tabview_1_extra_btnm_main_default.set_bg_grad_color(lv.color_make(0x23,0x24,0x26))
style_file_management_tabview_1_extra_btnm_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_tabview_1_extra_btnm_main_default.set_bg_opa(255)
style_file_management_tabview_1_extra_btnm_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_file_management_tabview_1_extra_btnm_main_default.set_border_width(0)
style_file_management_tabview_1_extra_btnm_main_default.set_border_opa(100)
style_file_management_tabview_1_extra_btnm_main_default.set_pad_left(0)
style_file_management_tabview_1_extra_btnm_main_default.set_pad_right(0)
style_file_management_tabview_1_extra_btnm_main_default.set_pad_top(0)
style_file_management_tabview_1_extra_btnm_main_default.set_pad_bottom(0)

# add style for file_management_tabview_1_tab_btns
file_management_tabview_1_tab_btns.add_style(style_file_management_tabview_1_extra_btnm_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_file_management_tabview_1_extra_btnm_items_default
style_file_management_tabview_1_extra_btnm_items_default = lv.style_t()
style_file_management_tabview_1_extra_btnm_items_default.init()
style_file_management_tabview_1_extra_btnm_items_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_file_management_tabview_1_extra_btnm_items_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_file_management_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_file_management_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_16)

# add style for file_management_tabview_1_tab_btns
file_management_tabview_1_tab_btns.add_style(style_file_management_tabview_1_extra_btnm_items_default, lv.PART.ITEMS|lv.STATE.DEFAULT)

# create style style_file_management_tabview_1_extra_btnm_items_checked
style_file_management_tabview_1_extra_btnm_items_checked = lv.style_t()
style_file_management_tabview_1_extra_btnm_items_checked.init()
style_file_management_tabview_1_extra_btnm_items_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_file_management_tabview_1_extra_btnm_items_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_file_management_tabview_1_extra_btnm_items_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_tabview_1_extra_btnm_items_checked.set_bg_opa(60)
style_file_management_tabview_1_extra_btnm_items_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_file_management_tabview_1_extra_btnm_items_checked.set_border_width(4)
style_file_management_tabview_1_extra_btnm_items_checked.set_border_opa(255)
style_file_management_tabview_1_extra_btnm_items_checked.set_border_side(lv.BORDER_SIDE.BOTTOM)
style_file_management_tabview_1_extra_btnm_items_checked.set_text_color(lv.color_make(0x21,0x95,0xf6))
try:
    style_file_management_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_file_management_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_file_management_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_16)

# add style for file_management_tabview_1_tab_btns
file_management_tabview_1_tab_btns.add_style(style_file_management_tabview_1_extra_btnm_items_checked, lv.PART.ITEMS|lv.STATE.CHECKED)

file_management_tabview_1_title1 = file_management_tabview_1.add_tab("title1")
file_management_tabview_1_title2 = file_management_tabview_1.add_tab("title2")
file_management_tabview_1_title3 = file_management_tabview_1.add_tab("title3")
file_management_tabview_1.set_pos(0,0)
file_management_tabview_1.set_size(480,720)
# create style style_file_management_tabview_1_main_main_default
style_file_management_tabview_1_main_main_default = lv.style_t()
style_file_management_tabview_1_main_main_default.init()
style_file_management_tabview_1_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_file_management_tabview_1_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_file_management_tabview_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_tabview_1_main_main_default.set_bg_opa(255)
style_file_management_tabview_1_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_file_management_tabview_1_main_main_default.set_border_width(0)
style_file_management_tabview_1_main_main_default.set_border_opa(100)
style_file_management_tabview_1_main_main_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_file_management_tabview_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_tabview_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_tabview_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_tabview_1_main_main_default.set_text_letter_space(0)
style_file_management_tabview_1_main_main_default.set_text_line_space(16)

# add style for file_management_tabview_1
file_management_tabview_1.add_style(style_file_management_tabview_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_cont_1 = lv.obj(file_management)
file_management_cont_1.set_pos(0,0)
file_management_cont_1.set_size(480,800)
file_management_label_1 = lv.label(file_management_cont_1)
file_management_label_1.set_pos(0,720)
file_management_label_1.set_size(480,80)
# create style style_file_management_label_1_main_main_default
style_file_management_label_1_main_main_default = lv.style_t()
style_file_management_label_1_main_main_default.init()
style_file_management_label_1_main_main_default.set_radius(0)
style_file_management_label_1_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_management_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_management_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_1_main_main_default.set_bg_opa(255)
style_file_management_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_1_main_main_default.set_text_letter_space(0)
style_file_management_label_1_main_main_default.set_pad_left(0)
style_file_management_label_1_main_main_default.set_pad_right(0)
style_file_management_label_1_main_main_default.set_pad_top(0)
style_file_management_label_1_main_main_default.set_pad_bottom(0)

# add style for file_management_label_1
file_management_label_1.add_style(style_file_management_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_2 = lv.label(file_management_cont_1)
file_management_label_2.set_pos(20,72)
file_management_label_2.set_size(215,203)
# create style style_file_management_label_2_main_main_default
style_file_management_label_2_main_main_default = lv.style_t()
style_file_management_label_2_main_main_default.init()
style_file_management_label_2_main_main_default.set_radius(8)
style_file_management_label_2_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_2_main_main_default.set_bg_opa(255)
style_file_management_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_2_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_2_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_2_main_main_default.set_text_letter_space(0)
style_file_management_label_2_main_main_default.set_pad_left(0)
style_file_management_label_2_main_main_default.set_pad_right(0)
style_file_management_label_2_main_main_default.set_pad_top(0)
style_file_management_label_2_main_main_default.set_pad_bottom(0)

# add style for file_management_label_2
file_management_label_2.add_style(style_file_management_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_6 = lv.label(file_management_cont_1)
file_management_label_6.set_pos(245,72)
file_management_label_6.set_size(215,203)
# create style style_file_management_label_6_main_main_default
style_file_management_label_6_main_main_default = lv.style_t()
style_file_management_label_6_main_main_default.init()
style_file_management_label_6_main_main_default.set_radius(8)
style_file_management_label_6_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_6_main_main_default.set_bg_opa(255)
style_file_management_label_6_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_6_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_6_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_6_main_main_default.set_text_letter_space(0)
style_file_management_label_6_main_main_default.set_pad_left(0)
style_file_management_label_6_main_main_default.set_pad_right(0)
style_file_management_label_6_main_main_default.set_pad_top(0)
style_file_management_label_6_main_main_default.set_pad_bottom(0)

# add style for file_management_label_6
file_management_label_6.add_style(style_file_management_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_10 = lv.label(file_management_cont_1)
file_management_label_10.set_pos(20,285)
file_management_label_10.set_size(215,203)
# create style style_file_management_label_10_main_main_default
style_file_management_label_10_main_main_default = lv.style_t()
style_file_management_label_10_main_main_default.init()
style_file_management_label_10_main_main_default.set_radius(8)
style_file_management_label_10_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_10_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_10_main_main_default.set_bg_opa(255)
style_file_management_label_10_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_10_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_10_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_10_main_main_default.set_text_letter_space(0)
style_file_management_label_10_main_main_default.set_pad_left(0)
style_file_management_label_10_main_main_default.set_pad_right(0)
style_file_management_label_10_main_main_default.set_pad_top(0)
style_file_management_label_10_main_main_default.set_pad_bottom(0)

# add style for file_management_label_10
file_management_label_10.add_style(style_file_management_label_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_11 = lv.label(file_management_cont_1)
file_management_label_11.set_pos(245,285)
file_management_label_11.set_size(215,203)
# create style style_file_management_label_11_main_main_default
style_file_management_label_11_main_main_default = lv.style_t()
style_file_management_label_11_main_main_default.init()
style_file_management_label_11_main_main_default.set_radius(8)
style_file_management_label_11_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_11_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_11_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_11_main_main_default.set_bg_opa(255)
style_file_management_label_11_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_11_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_11_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_11_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_11_main_main_default.set_text_letter_space(0)
style_file_management_label_11_main_main_default.set_pad_left(0)
style_file_management_label_11_main_main_default.set_pad_right(0)
style_file_management_label_11_main_main_default.set_pad_top(0)
style_file_management_label_11_main_main_default.set_pad_bottom(0)

# add style for file_management_label_11
file_management_label_11.add_style(style_file_management_label_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_12 = lv.label(file_management_cont_1)
file_management_label_12.set_pos(20,498)
file_management_label_12.set_size(215,203)
# create style style_file_management_label_12_main_main_default
style_file_management_label_12_main_main_default = lv.style_t()
style_file_management_label_12_main_main_default.init()
style_file_management_label_12_main_main_default.set_radius(8)
style_file_management_label_12_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_12_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_12_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_12_main_main_default.set_bg_opa(255)
style_file_management_label_12_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_12_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_12_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_12_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_12_main_main_default.set_text_letter_space(0)
style_file_management_label_12_main_main_default.set_pad_left(0)
style_file_management_label_12_main_main_default.set_pad_right(0)
style_file_management_label_12_main_main_default.set_pad_top(0)
style_file_management_label_12_main_main_default.set_pad_bottom(0)

# add style for file_management_label_12
file_management_label_12.add_style(style_file_management_label_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_13 = lv.label(file_management_cont_1)
file_management_label_13.set_pos(245,498)
file_management_label_13.set_size(215,203)
# create style style_file_management_label_13_main_main_default
style_file_management_label_13_main_main_default = lv.style_t()
style_file_management_label_13_main_main_default.init()
style_file_management_label_13_main_main_default.set_radius(8)
style_file_management_label_13_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_13_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_13_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_13_main_main_default.set_bg_opa(255)
style_file_management_label_13_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_13_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_13_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_13_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_13_main_main_default.set_text_letter_space(0)
style_file_management_label_13_main_main_default.set_pad_left(0)
style_file_management_label_13_main_main_default.set_pad_right(0)
style_file_management_label_13_main_main_default.set_pad_top(0)
style_file_management_label_13_main_main_default.set_pad_bottom(0)

# add style for file_management_label_13
file_management_label_13.add_style(style_file_management_label_13_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_3 = lv.label(file_management_cont_1)
file_management_label_3.set_pos(30,190)
file_management_label_3.set_size(199,42)
file_management_label_3.set_text("test.gcode")
file_management_label_3.set_long_mode(lv.label.LONG.WRAP)
file_management_label_3.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_management_label_3_main_main_default
style_file_management_label_3_main_main_default = lv.style_t()
style_file_management_label_3_main_main_default.init()
style_file_management_label_3_main_main_default.set_radius(0)
style_file_management_label_3_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_3_main_main_default.set_bg_opa(255)
style_file_management_label_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_3_main_main_default.set_text_letter_space(0)
style_file_management_label_3_main_main_default.set_pad_left(0)
style_file_management_label_3_main_main_default.set_pad_right(0)
style_file_management_label_3_main_main_default.set_pad_top(0)
style_file_management_label_3_main_main_default.set_pad_bottom(0)

# add style for file_management_label_3
file_management_label_3.add_style(style_file_management_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_btn_1 = lv.btn(file_management_cont_1)
file_management_btn_1.set_pos(418,592)
file_management_btn_1.set_size(60,60)
# create style style_file_management_btn_1_main_main_default
style_file_management_btn_1_main_main_default = lv.style_t()
style_file_management_btn_1_main_main_default.init()
style_file_management_btn_1_main_main_default.set_radius(30)
style_file_management_btn_1_main_main_default.set_bg_color(lv.color_make(0x26,0x28,0x2a))
style_file_management_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x26,0x28,0x2a))
style_file_management_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_btn_1_main_main_default.set_bg_opa(227)
style_file_management_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_file_management_btn_1_main_main_default.set_shadow_opa(0)
style_file_management_btn_1_main_main_default.set_border_color(lv.color_make(0x4d,0x4d,0x4d))
style_file_management_btn_1_main_main_default.set_border_width(1)
style_file_management_btn_1_main_main_default.set_border_opa(255)

# add style for file_management_btn_1
file_management_btn_1.add_style(style_file_management_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_btn_2 = lv.btn(file_management_cont_1)
file_management_btn_2.set_pos(418,666)
file_management_btn_2.set_size(60,60)
# create style style_file_management_btn_2_main_main_default
style_file_management_btn_2_main_main_default = lv.style_t()
style_file_management_btn_2_main_main_default.init()
style_file_management_btn_2_main_main_default.set_radius(30)
style_file_management_btn_2_main_main_default.set_bg_color(lv.color_make(0x26,0x28,0x2a))
style_file_management_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x26,0x28,0x2a))
style_file_management_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_btn_2_main_main_default.set_bg_opa(227)
style_file_management_btn_2_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_file_management_btn_2_main_main_default.set_shadow_opa(0)
style_file_management_btn_2_main_main_default.set_border_color(lv.color_make(0x4d,0x4d,0x4d))
style_file_management_btn_2_main_main_default.set_border_width(1)
style_file_management_btn_2_main_main_default.set_border_opa(255)

# add style for file_management_btn_2
file_management_btn_2.add_style(style_file_management_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_14 = lv.label(file_management_cont_1)
file_management_label_14.set_pos(30,403)
file_management_label_14.set_size(199,42)
file_management_label_14.set_text("test.gcode")
file_management_label_14.set_long_mode(lv.label.LONG.WRAP)
file_management_label_14.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_management_label_14_main_main_default
style_file_management_label_14_main_main_default = lv.style_t()
style_file_management_label_14_main_main_default.init()
style_file_management_label_14_main_main_default.set_radius(0)
style_file_management_label_14_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_14_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_14_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_14_main_main_default.set_bg_opa(255)
style_file_management_label_14_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_14_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_14_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_14_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_14_main_main_default.set_text_letter_space(0)
style_file_management_label_14_main_main_default.set_pad_left(0)
style_file_management_label_14_main_main_default.set_pad_right(0)
style_file_management_label_14_main_main_default.set_pad_top(0)
style_file_management_label_14_main_main_default.set_pad_bottom(0)

# add style for file_management_label_14
file_management_label_14.add_style(style_file_management_label_14_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_17 = lv.label(file_management_cont_1)
file_management_label_17.set_pos(255,403)
file_management_label_17.set_size(199,42)
file_management_label_17.set_text("test.gcode")
file_management_label_17.set_long_mode(lv.label.LONG.WRAP)
file_management_label_17.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_management_label_17_main_main_default
style_file_management_label_17_main_main_default = lv.style_t()
style_file_management_label_17_main_main_default.init()
style_file_management_label_17_main_main_default.set_radius(0)
style_file_management_label_17_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_17_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_17_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_17_main_main_default.set_bg_opa(255)
style_file_management_label_17_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_17_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_17_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_17_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_17_main_main_default.set_text_letter_space(0)
style_file_management_label_17_main_main_default.set_pad_left(0)
style_file_management_label_17_main_main_default.set_pad_right(0)
style_file_management_label_17_main_main_default.set_pad_top(0)
style_file_management_label_17_main_main_default.set_pad_bottom(0)

# add style for file_management_label_17
file_management_label_17.add_style(style_file_management_label_17_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_20 = lv.label(file_management_cont_1)
file_management_label_20.set_pos(30,616)
file_management_label_20.set_size(199,42)
file_management_label_20.set_text("test.gcode")
file_management_label_20.set_long_mode(lv.label.LONG.WRAP)
file_management_label_20.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_management_label_20_main_main_default
style_file_management_label_20_main_main_default = lv.style_t()
style_file_management_label_20_main_main_default.init()
style_file_management_label_20_main_main_default.set_radius(0)
style_file_management_label_20_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_20_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_20_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_20_main_main_default.set_bg_opa(255)
style_file_management_label_20_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_20_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_20_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_20_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_20_main_main_default.set_text_letter_space(0)
style_file_management_label_20_main_main_default.set_pad_left(0)
style_file_management_label_20_main_main_default.set_pad_right(0)
style_file_management_label_20_main_main_default.set_pad_top(0)
style_file_management_label_20_main_main_default.set_pad_bottom(0)

# add style for file_management_label_20
file_management_label_20.add_style(style_file_management_label_20_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_23 = lv.label(file_management_cont_1)
file_management_label_23.set_pos(255,616)
file_management_label_23.set_size(199,42)
file_management_label_23.set_text("test.gcode")
file_management_label_23.set_long_mode(lv.label.LONG.WRAP)
file_management_label_23.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_management_label_23_main_main_default
style_file_management_label_23_main_main_default = lv.style_t()
style_file_management_label_23_main_main_default.init()
style_file_management_label_23_main_main_default.set_radius(0)
style_file_management_label_23_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_23_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_23_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_23_main_main_default.set_bg_opa(0)
style_file_management_label_23_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_23_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_23_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_23_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_23_main_main_default.set_text_letter_space(0)
style_file_management_label_23_main_main_default.set_pad_left(0)
style_file_management_label_23_main_main_default.set_pad_right(0)
style_file_management_label_23_main_main_default.set_pad_top(0)
style_file_management_label_23_main_main_default.set_pad_bottom(0)

# add style for file_management_label_23
file_management_label_23.add_style(style_file_management_label_23_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_7 = lv.label(file_management_cont_1)
file_management_label_7.set_pos(255,190)
file_management_label_7.set_size(199,42)
file_management_label_7.set_text("test.gcode")
file_management_label_7.set_long_mode(lv.label.LONG.WRAP)
file_management_label_7.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_management_label_7_main_main_default
style_file_management_label_7_main_main_default = lv.style_t()
style_file_management_label_7_main_main_default.init()
style_file_management_label_7_main_main_default.set_radius(0)
style_file_management_label_7_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_7_main_main_default.set_bg_opa(255)
style_file_management_label_7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_7_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_7_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_7_main_main_default.set_text_letter_space(0)
style_file_management_label_7_main_main_default.set_pad_left(0)
style_file_management_label_7_main_main_default.set_pad_right(0)
style_file_management_label_7_main_main_default.set_pad_top(0)
style_file_management_label_7_main_main_default.set_pad_bottom(0)

# add style for file_management_label_7
file_management_label_7.add_style(style_file_management_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_4 = lv.label(file_management_cont_1)
file_management_label_4.set_pos(49,240)
file_management_label_4.set_size(57,24)
file_management_label_4.set_text("test.gcode")
file_management_label_4.set_long_mode(lv.label.LONG.WRAP)
file_management_label_4.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_management_label_4_main_main_default
style_file_management_label_4_main_main_default = lv.style_t()
style_file_management_label_4_main_main_default.init()
style_file_management_label_4_main_main_default.set_radius(0)
style_file_management_label_4_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_4_main_main_default.set_bg_opa(0)
style_file_management_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_4_main_main_default.set_text_letter_space(0)
style_file_management_label_4_main_main_default.set_pad_left(0)
style_file_management_label_4_main_main_default.set_pad_right(0)
style_file_management_label_4_main_main_default.set_pad_top(0)
style_file_management_label_4_main_main_default.set_pad_bottom(0)

# add style for file_management_label_4
file_management_label_4.add_style(style_file_management_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_15 = lv.label(file_management_cont_1)
file_management_label_15.set_pos(49,452)
file_management_label_15.set_size(57,24)
file_management_label_15.set_text("test.gcode")
file_management_label_15.set_long_mode(lv.label.LONG.WRAP)
file_management_label_15.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_management_label_15_main_main_default
style_file_management_label_15_main_main_default = lv.style_t()
style_file_management_label_15_main_main_default.init()
style_file_management_label_15_main_main_default.set_radius(0)
style_file_management_label_15_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_15_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_15_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_15_main_main_default.set_bg_opa(0)
style_file_management_label_15_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_15_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_15_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_15_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_15_main_main_default.set_text_letter_space(0)
style_file_management_label_15_main_main_default.set_pad_left(0)
style_file_management_label_15_main_main_default.set_pad_right(0)
style_file_management_label_15_main_main_default.set_pad_top(0)
style_file_management_label_15_main_main_default.set_pad_bottom(0)

# add style for file_management_label_15
file_management_label_15.add_style(style_file_management_label_15_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_21 = lv.label(file_management_cont_1)
file_management_label_21.set_pos(49,665)
file_management_label_21.set_size(57,24)
file_management_label_21.set_text("test.gcode")
file_management_label_21.set_long_mode(lv.label.LONG.WRAP)
file_management_label_21.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_management_label_21_main_main_default
style_file_management_label_21_main_main_default = lv.style_t()
style_file_management_label_21_main_main_default.init()
style_file_management_label_21_main_main_default.set_radius(0)
style_file_management_label_21_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_21_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_21_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_21_main_main_default.set_bg_opa(0)
style_file_management_label_21_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_21_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_21_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_21_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_21_main_main_default.set_text_letter_space(0)
style_file_management_label_21_main_main_default.set_pad_left(0)
style_file_management_label_21_main_main_default.set_pad_right(0)
style_file_management_label_21_main_main_default.set_pad_top(0)
style_file_management_label_21_main_main_default.set_pad_bottom(0)

# add style for file_management_label_21
file_management_label_21.add_style(style_file_management_label_21_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_24 = lv.label(file_management_cont_1)
file_management_label_24.set_pos(275,665)
file_management_label_24.set_size(57,24)
file_management_label_24.set_text("test.gcode")
file_management_label_24.set_long_mode(lv.label.LONG.WRAP)
file_management_label_24.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_management_label_24_main_main_default
style_file_management_label_24_main_main_default = lv.style_t()
style_file_management_label_24_main_main_default.init()
style_file_management_label_24_main_main_default.set_radius(0)
style_file_management_label_24_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_24_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_24_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_24_main_main_default.set_bg_opa(0)
style_file_management_label_24_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_24_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_24_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_24_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_24_main_main_default.set_text_letter_space(0)
style_file_management_label_24_main_main_default.set_pad_left(0)
style_file_management_label_24_main_main_default.set_pad_right(0)
style_file_management_label_24_main_main_default.set_pad_top(0)
style_file_management_label_24_main_main_default.set_pad_bottom(0)

# add style for file_management_label_24
file_management_label_24.add_style(style_file_management_label_24_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_25 = lv.label(file_management_cont_1)
file_management_label_25.set_pos(369,665)
file_management_label_25.set_size(57,24)
file_management_label_25.set_text("test.gcode")
file_management_label_25.set_long_mode(lv.label.LONG.WRAP)
file_management_label_25.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_management_label_25_main_main_default
style_file_management_label_25_main_main_default = lv.style_t()
style_file_management_label_25_main_main_default.init()
style_file_management_label_25_main_main_default.set_radius(0)
style_file_management_label_25_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_25_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_25_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_25_main_main_default.set_bg_opa(0)
style_file_management_label_25_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_25_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_25_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_25_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_25_main_main_default.set_text_letter_space(0)
style_file_management_label_25_main_main_default.set_pad_left(0)
style_file_management_label_25_main_main_default.set_pad_right(0)
style_file_management_label_25_main_main_default.set_pad_top(0)
style_file_management_label_25_main_main_default.set_pad_bottom(0)

# add style for file_management_label_25
file_management_label_25.add_style(style_file_management_label_25_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_22 = lv.label(file_management_cont_1)
file_management_label_22.set_pos(143,665)
file_management_label_22.set_size(57,24)
file_management_label_22.set_text("test.gcode")
file_management_label_22.set_long_mode(lv.label.LONG.WRAP)
file_management_label_22.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_management_label_22_main_main_default
style_file_management_label_22_main_main_default = lv.style_t()
style_file_management_label_22_main_main_default.init()
style_file_management_label_22_main_main_default.set_radius(0)
style_file_management_label_22_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_22_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_22_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_22_main_main_default.set_bg_opa(0)
style_file_management_label_22_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_22_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_22_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_22_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_22_main_main_default.set_text_letter_space(0)
style_file_management_label_22_main_main_default.set_pad_left(0)
style_file_management_label_22_main_main_default.set_pad_right(0)
style_file_management_label_22_main_main_default.set_pad_top(0)
style_file_management_label_22_main_main_default.set_pad_bottom(0)

# add style for file_management_label_22
file_management_label_22.add_style(style_file_management_label_22_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_18 = lv.label(file_management_cont_1)
file_management_label_18.set_pos(275,452)
file_management_label_18.set_size(57,24)
file_management_label_18.set_text("test.gcode")
file_management_label_18.set_long_mode(lv.label.LONG.WRAP)
file_management_label_18.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_management_label_18_main_main_default
style_file_management_label_18_main_main_default = lv.style_t()
style_file_management_label_18_main_main_default.init()
style_file_management_label_18_main_main_default.set_radius(0)
style_file_management_label_18_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_18_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_18_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_18_main_main_default.set_bg_opa(0)
style_file_management_label_18_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_18_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_18_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_18_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_18_main_main_default.set_text_letter_space(0)
style_file_management_label_18_main_main_default.set_pad_left(0)
style_file_management_label_18_main_main_default.set_pad_right(0)
style_file_management_label_18_main_main_default.set_pad_top(0)
style_file_management_label_18_main_main_default.set_pad_bottom(0)

# add style for file_management_label_18
file_management_label_18.add_style(style_file_management_label_18_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_19 = lv.label(file_management_cont_1)
file_management_label_19.set_pos(369,452)
file_management_label_19.set_size(57,24)
file_management_label_19.set_text("test.gcode")
file_management_label_19.set_long_mode(lv.label.LONG.WRAP)
file_management_label_19.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_management_label_19_main_main_default
style_file_management_label_19_main_main_default = lv.style_t()
style_file_management_label_19_main_main_default.init()
style_file_management_label_19_main_main_default.set_radius(0)
style_file_management_label_19_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_19_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_19_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_19_main_main_default.set_bg_opa(0)
style_file_management_label_19_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_19_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_19_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_19_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_19_main_main_default.set_text_letter_space(0)
style_file_management_label_19_main_main_default.set_pad_left(0)
style_file_management_label_19_main_main_default.set_pad_right(0)
style_file_management_label_19_main_main_default.set_pad_top(0)
style_file_management_label_19_main_main_default.set_pad_bottom(0)

# add style for file_management_label_19
file_management_label_19.add_style(style_file_management_label_19_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_16 = lv.label(file_management_cont_1)
file_management_label_16.set_pos(143,452)
file_management_label_16.set_size(57,24)
file_management_label_16.set_text("test.gcode")
file_management_label_16.set_long_mode(lv.label.LONG.WRAP)
file_management_label_16.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_management_label_16_main_main_default
style_file_management_label_16_main_main_default = lv.style_t()
style_file_management_label_16_main_main_default.init()
style_file_management_label_16_main_main_default.set_radius(0)
style_file_management_label_16_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_16_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_16_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_16_main_main_default.set_bg_opa(0)
style_file_management_label_16_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_16_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_16_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_16_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_16_main_main_default.set_text_letter_space(0)
style_file_management_label_16_main_main_default.set_pad_left(0)
style_file_management_label_16_main_main_default.set_pad_right(0)
style_file_management_label_16_main_main_default.set_pad_top(0)
style_file_management_label_16_main_main_default.set_pad_bottom(0)

# add style for file_management_label_16
file_management_label_16.add_style(style_file_management_label_16_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_8 = lv.label(file_management_cont_1)
file_management_label_8.set_pos(275,240)
file_management_label_8.set_size(57,24)
file_management_label_8.set_text("test.gcode")
file_management_label_8.set_long_mode(lv.label.LONG.WRAP)
file_management_label_8.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_management_label_8_main_main_default
style_file_management_label_8_main_main_default = lv.style_t()
style_file_management_label_8_main_main_default.init()
style_file_management_label_8_main_main_default.set_radius(0)
style_file_management_label_8_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_8_main_main_default.set_bg_opa(0)
style_file_management_label_8_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_8_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_8_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_8_main_main_default.set_text_letter_space(0)
style_file_management_label_8_main_main_default.set_pad_left(0)
style_file_management_label_8_main_main_default.set_pad_right(0)
style_file_management_label_8_main_main_default.set_pad_top(0)
style_file_management_label_8_main_main_default.set_pad_bottom(0)

# add style for file_management_label_8
file_management_label_8.add_style(style_file_management_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_5 = lv.label(file_management_cont_1)
file_management_label_5.set_pos(143,240)
file_management_label_5.set_size(57,24)
file_management_label_5.set_text("test.gcode")
file_management_label_5.set_long_mode(lv.label.LONG.WRAP)
file_management_label_5.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_management_label_5_main_main_default
style_file_management_label_5_main_main_default = lv.style_t()
style_file_management_label_5_main_main_default.init()
style_file_management_label_5_main_main_default.set_radius(0)
style_file_management_label_5_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_5_main_main_default.set_bg_opa(0)
style_file_management_label_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_5_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_5_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_5_main_main_default.set_text_letter_space(0)
style_file_management_label_5_main_main_default.set_pad_left(0)
style_file_management_label_5_main_main_default.set_pad_right(0)
style_file_management_label_5_main_main_default.set_pad_top(0)
style_file_management_label_5_main_main_default.set_pad_bottom(0)

# add style for file_management_label_5
file_management_label_5.add_style(style_file_management_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_label_9 = lv.label(file_management_cont_1)
file_management_label_9.set_pos(369,240)
file_management_label_9.set_size(57,24)
file_management_label_9.set_text("test.gcode")
file_management_label_9.set_long_mode(lv.label.LONG.WRAP)
file_management_label_9.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_management_label_9_main_main_default
style_file_management_label_9_main_main_default = lv.style_t()
style_file_management_label_9_main_main_default.init()
style_file_management_label_9_main_main_default.set_radius(0)
style_file_management_label_9_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_9_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_management_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_label_9_main_main_default.set_bg_opa(0)
style_file_management_label_9_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_management_label_9_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_management_label_9_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_management_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_management_label_9_main_main_default.set_text_letter_space(0)
style_file_management_label_9_main_main_default.set_pad_left(0)
style_file_management_label_9_main_main_default.set_pad_right(0)
style_file_management_label_9_main_main_default.set_pad_top(0)
style_file_management_label_9_main_main_default.set_pad_bottom(0)

# add style for file_management_label_9
file_management_label_9.add_style(style_file_management_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_6 = lv.img(file_management_cont_1)
file_management_img_6.set_pos(80,82)
file_management_img_6.set_size(96,96)
# create style style_file_management_img_6_main_main_default
style_file_management_img_6_main_main_default = lv.style_t()
style_file_management_img_6_main_main_default.init()
style_file_management_img_6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_6_main_main_default.set_img_recolor_opa(0)
style_file_management_img_6_main_main_default.set_img_opa(255)

# add style for file_management_img_6
file_management_img_6.add_style(style_file_management_img_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_9 = lv.img(file_management_cont_1)
file_management_img_9.set_pos(304,82)
file_management_img_9.set_size(96,96)
# create style style_file_management_img_9_main_main_default
style_file_management_img_9_main_main_default = lv.style_t()
style_file_management_img_9_main_main_default.init()
style_file_management_img_9_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_9_main_main_default.set_img_recolor_opa(0)
style_file_management_img_9_main_main_default.set_img_opa(255)

# add style for file_management_img_9
file_management_img_9.add_style(style_file_management_img_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_15 = lv.img(file_management_cont_1)
file_management_img_15.set_pos(304,295)
file_management_img_15.set_size(96,96)
# create style style_file_management_img_15_main_main_default
style_file_management_img_15_main_main_default = lv.style_t()
style_file_management_img_15_main_main_default.init()
style_file_management_img_15_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_15_main_main_default.set_img_recolor_opa(0)
style_file_management_img_15_main_main_default.set_img_opa(255)

# add style for file_management_img_15
file_management_img_15.add_style(style_file_management_img_15_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_18 = lv.img(file_management_cont_1)
file_management_img_18.set_pos(80,508)
file_management_img_18.set_size(96,96)
# create style style_file_management_img_18_main_main_default
style_file_management_img_18_main_main_default = lv.style_t()
style_file_management_img_18_main_main_default.init()
style_file_management_img_18_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_18_main_main_default.set_img_recolor_opa(0)
style_file_management_img_18_main_main_default.set_img_opa(255)

# add style for file_management_img_18
file_management_img_18.add_style(style_file_management_img_18_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_21 = lv.img(file_management_cont_1)
file_management_img_21.set_pos(304,508)
file_management_img_21.set_size(96,96)
# create style style_file_management_img_21_main_main_default
style_file_management_img_21_main_main_default = lv.style_t()
style_file_management_img_21_main_main_default.init()
style_file_management_img_21_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_21_main_main_default.set_img_recolor_opa(0)
style_file_management_img_21_main_main_default.set_img_opa(255)

# add style for file_management_img_21
file_management_img_21.add_style(style_file_management_img_21_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_24 = lv.img(file_management_cont_1)
file_management_img_24.set_pos(436,615)
file_management_img_24.set_size(24,14)
file_management_img_24.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp44047850.png','rb') as f:
        file_management_img_24_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp44047850.png')
    sys.exit()

file_management_img_24_img = lv.img_dsc_t({
  'data_size': len(file_management_img_24_img_data),
  'header': {'always_zero': 0, 'w': 24, 'h': 14, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_24_img_data
})

file_management_img_24.set_src(file_management_img_24_img)
file_management_img_24.set_pivot(0,0)
file_management_img_24.set_angle(0)
# create style style_file_management_img_24_main_main_default
style_file_management_img_24_main_main_default = lv.style_t()
style_file_management_img_24_main_main_default.init()
style_file_management_img_24_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_24_main_main_default.set_img_recolor_opa(0)
style_file_management_img_24_main_main_default.set_img_opa(255)

# add style for file_management_img_24
file_management_img_24.add_style(style_file_management_img_24_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_25 = lv.img(file_management_cont_1)
file_management_img_25.set_pos(436,689)
file_management_img_25.set_size(24,14)
file_management_img_25.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-2033161493.png','rb') as f:
        file_management_img_25_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-2033161493.png')
    sys.exit()

file_management_img_25_img = lv.img_dsc_t({
  'data_size': len(file_management_img_25_img_data),
  'header': {'always_zero': 0, 'w': 24, 'h': 14, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_25_img_data
})

file_management_img_25.set_src(file_management_img_25_img)
file_management_img_25.set_pivot(0,0)
file_management_img_25.set_angle(0)
# create style style_file_management_img_25_main_main_default
style_file_management_img_25_main_main_default = lv.style_t()
style_file_management_img_25_main_main_default.init()
style_file_management_img_25_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_25_main_main_default.set_img_recolor_opa(0)
style_file_management_img_25_main_main_default.set_img_opa(255)

# add style for file_management_img_25
file_management_img_25.add_style(style_file_management_img_25_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_12 = lv.img(file_management_cont_1)
file_management_img_12.set_pos(80,295)
file_management_img_12.set_size(96,96)
# create style style_file_management_img_12_main_main_default
style_file_management_img_12_main_main_default = lv.style_t()
style_file_management_img_12_main_main_default.init()
style_file_management_img_12_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_12_main_main_default.set_img_recolor_opa(0)
style_file_management_img_12_main_main_default.set_img_opa(255)

# add style for file_management_img_12
file_management_img_12.add_style(style_file_management_img_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_7 = lv.img(file_management_cont_1)
file_management_img_7.set_pos(29,244)
file_management_img_7.set_size(18,18)
file_management_img_7.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png','rb') as f:
        file_management_img_7_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png')
    sys.exit()

file_management_img_7_img = lv.img_dsc_t({
  'data_size': len(file_management_img_7_img_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 18, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_7_img_data
})

file_management_img_7.set_src(file_management_img_7_img)
file_management_img_7.set_pivot(0,0)
file_management_img_7.set_angle(0)
# create style style_file_management_img_7_main_main_default
style_file_management_img_7_main_main_default = lv.style_t()
style_file_management_img_7_main_main_default.init()
style_file_management_img_7_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_7_main_main_default.set_img_recolor_opa(0)
style_file_management_img_7_main_main_default.set_img_opa(255)

# add style for file_management_img_7
file_management_img_7.add_style(style_file_management_img_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_13 = lv.img(file_management_cont_1)
file_management_img_13.set_pos(29,457)
file_management_img_13.set_size(18,18)
file_management_img_13.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png','rb') as f:
        file_management_img_13_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png')
    sys.exit()

file_management_img_13_img = lv.img_dsc_t({
  'data_size': len(file_management_img_13_img_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 18, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_13_img_data
})

file_management_img_13.set_src(file_management_img_13_img)
file_management_img_13.set_pivot(0,0)
file_management_img_13.set_angle(0)
# create style style_file_management_img_13_main_main_default
style_file_management_img_13_main_main_default = lv.style_t()
style_file_management_img_13_main_main_default.init()
style_file_management_img_13_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_13_main_main_default.set_img_recolor_opa(0)
style_file_management_img_13_main_main_default.set_img_opa(255)

# add style for file_management_img_13
file_management_img_13.add_style(style_file_management_img_13_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_19 = lv.img(file_management_cont_1)
file_management_img_19.set_pos(29,670)
file_management_img_19.set_size(18,18)
file_management_img_19.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png','rb') as f:
        file_management_img_19_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png')
    sys.exit()

file_management_img_19_img = lv.img_dsc_t({
  'data_size': len(file_management_img_19_img_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 18, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_19_img_data
})

file_management_img_19.set_src(file_management_img_19_img)
file_management_img_19.set_pivot(0,0)
file_management_img_19.set_angle(0)
# create style style_file_management_img_19_main_main_default
style_file_management_img_19_main_main_default = lv.style_t()
style_file_management_img_19_main_main_default.init()
style_file_management_img_19_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_19_main_main_default.set_img_recolor_opa(0)
style_file_management_img_19_main_main_default.set_img_opa(255)

# add style for file_management_img_19
file_management_img_19.add_style(style_file_management_img_19_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_22 = lv.img(file_management_cont_1)
file_management_img_22.set_pos(255,670)
file_management_img_22.set_size(18,18)
file_management_img_22.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png','rb') as f:
        file_management_img_22_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png')
    sys.exit()

file_management_img_22_img = lv.img_dsc_t({
  'data_size': len(file_management_img_22_img_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 18, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_22_img_data
})

file_management_img_22.set_src(file_management_img_22_img)
file_management_img_22.set_pivot(0,0)
file_management_img_22.set_angle(0)
# create style style_file_management_img_22_main_main_default
style_file_management_img_22_main_main_default = lv.style_t()
style_file_management_img_22_main_main_default.init()
style_file_management_img_22_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_22_main_main_default.set_img_recolor_opa(0)
style_file_management_img_22_main_main_default.set_img_opa(255)

# add style for file_management_img_22
file_management_img_22.add_style(style_file_management_img_22_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_16 = lv.img(file_management_cont_1)
file_management_img_16.set_pos(255,457)
file_management_img_16.set_size(18,18)
file_management_img_16.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png','rb') as f:
        file_management_img_16_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png')
    sys.exit()

file_management_img_16_img = lv.img_dsc_t({
  'data_size': len(file_management_img_16_img_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 18, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_16_img_data
})

file_management_img_16.set_src(file_management_img_16_img)
file_management_img_16.set_pivot(0,0)
file_management_img_16.set_angle(0)
# create style style_file_management_img_16_main_main_default
style_file_management_img_16_main_main_default = lv.style_t()
style_file_management_img_16_main_main_default.init()
style_file_management_img_16_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_16_main_main_default.set_img_recolor_opa(0)
style_file_management_img_16_main_main_default.set_img_opa(255)

# add style for file_management_img_16
file_management_img_16.add_style(style_file_management_img_16_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_10 = lv.img(file_management_cont_1)
file_management_img_10.set_pos(255,244)
file_management_img_10.set_size(18,18)
file_management_img_10.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png','rb') as f:
        file_management_img_10_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png')
    sys.exit()

file_management_img_10_img = lv.img_dsc_t({
  'data_size': len(file_management_img_10_img_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 18, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_10_img_data
})

file_management_img_10.set_src(file_management_img_10_img)
file_management_img_10.set_pivot(0,0)
file_management_img_10.set_angle(0)
# create style style_file_management_img_10_main_main_default
style_file_management_img_10_main_main_default = lv.style_t()
style_file_management_img_10_main_main_default.init()
style_file_management_img_10_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_10_main_main_default.set_img_recolor_opa(0)
style_file_management_img_10_main_main_default.set_img_opa(255)

# add style for file_management_img_10
file_management_img_10.add_style(style_file_management_img_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_8 = lv.img(file_management_cont_1)
file_management_img_8.set_pos(124,246)
file_management_img_8.set_size(16,16)
file_management_img_8.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png','rb') as f:
        file_management_img_8_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png')
    sys.exit()

file_management_img_8_img = lv.img_dsc_t({
  'data_size': len(file_management_img_8_img_data),
  'header': {'always_zero': 0, 'w': 16, 'h': 16, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_8_img_data
})

file_management_img_8.set_src(file_management_img_8_img)
file_management_img_8.set_pivot(0,0)
file_management_img_8.set_angle(0)
# create style style_file_management_img_8_main_main_default
style_file_management_img_8_main_main_default = lv.style_t()
style_file_management_img_8_main_main_default.init()
style_file_management_img_8_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_8_main_main_default.set_img_recolor_opa(0)
style_file_management_img_8_main_main_default.set_img_opa(255)

# add style for file_management_img_8
file_management_img_8.add_style(style_file_management_img_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_14 = lv.img(file_management_cont_1)
file_management_img_14.set_pos(124,459)
file_management_img_14.set_size(16,16)
file_management_img_14.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png','rb') as f:
        file_management_img_14_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png')
    sys.exit()

file_management_img_14_img = lv.img_dsc_t({
  'data_size': len(file_management_img_14_img_data),
  'header': {'always_zero': 0, 'w': 16, 'h': 16, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_14_img_data
})

file_management_img_14.set_src(file_management_img_14_img)
file_management_img_14.set_pivot(0,0)
file_management_img_14.set_angle(0)
# create style style_file_management_img_14_main_main_default
style_file_management_img_14_main_main_default = lv.style_t()
style_file_management_img_14_main_main_default.init()
style_file_management_img_14_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_14_main_main_default.set_img_recolor_opa(0)
style_file_management_img_14_main_main_default.set_img_opa(255)

# add style for file_management_img_14
file_management_img_14.add_style(style_file_management_img_14_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_20 = lv.img(file_management_cont_1)
file_management_img_20.set_pos(124,672)
file_management_img_20.set_size(16,16)
file_management_img_20.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png','rb') as f:
        file_management_img_20_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png')
    sys.exit()

file_management_img_20_img = lv.img_dsc_t({
  'data_size': len(file_management_img_20_img_data),
  'header': {'always_zero': 0, 'w': 16, 'h': 16, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_20_img_data
})

file_management_img_20.set_src(file_management_img_20_img)
file_management_img_20.set_pivot(0,0)
file_management_img_20.set_angle(0)
# create style style_file_management_img_20_main_main_default
style_file_management_img_20_main_main_default = lv.style_t()
style_file_management_img_20_main_main_default.init()
style_file_management_img_20_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_20_main_main_default.set_img_recolor_opa(0)
style_file_management_img_20_main_main_default.set_img_opa(255)

# add style for file_management_img_20
file_management_img_20.add_style(style_file_management_img_20_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_23 = lv.img(file_management_cont_1)
file_management_img_23.set_pos(350,672)
file_management_img_23.set_size(16,16)
file_management_img_23.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png','rb') as f:
        file_management_img_23_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png')
    sys.exit()

file_management_img_23_img = lv.img_dsc_t({
  'data_size': len(file_management_img_23_img_data),
  'header': {'always_zero': 0, 'w': 16, 'h': 16, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_23_img_data
})

file_management_img_23.set_src(file_management_img_23_img)
file_management_img_23.set_pivot(0,0)
file_management_img_23.set_angle(0)
# create style style_file_management_img_23_main_main_default
style_file_management_img_23_main_main_default = lv.style_t()
style_file_management_img_23_main_main_default.init()
style_file_management_img_23_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_23_main_main_default.set_img_recolor_opa(0)
style_file_management_img_23_main_main_default.set_img_opa(255)

# add style for file_management_img_23
file_management_img_23.add_style(style_file_management_img_23_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_17 = lv.img(file_management_cont_1)
file_management_img_17.set_pos(350,459)
file_management_img_17.set_size(16,16)
file_management_img_17.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png','rb') as f:
        file_management_img_17_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png')
    sys.exit()

file_management_img_17_img = lv.img_dsc_t({
  'data_size': len(file_management_img_17_img_data),
  'header': {'always_zero': 0, 'w': 16, 'h': 16, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_17_img_data
})

file_management_img_17.set_src(file_management_img_17_img)
file_management_img_17.set_pivot(0,0)
file_management_img_17.set_angle(0)
# create style style_file_management_img_17_main_main_default
style_file_management_img_17_main_main_default = lv.style_t()
style_file_management_img_17_main_main_default.init()
style_file_management_img_17_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_17_main_main_default.set_img_recolor_opa(0)
style_file_management_img_17_main_main_default.set_img_opa(255)

# add style for file_management_img_17
file_management_img_17.add_style(style_file_management_img_17_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_11 = lv.img(file_management_cont_1)
file_management_img_11.set_pos(350,246)
file_management_img_11.set_size(16,16)
file_management_img_11.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png','rb') as f:
        file_management_img_11_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png')
    sys.exit()

file_management_img_11_img = lv.img_dsc_t({
  'data_size': len(file_management_img_11_img_data),
  'header': {'always_zero': 0, 'w': 16, 'h': 16, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_11_img_data
})

file_management_img_11.set_src(file_management_img_11_img)
file_management_img_11.set_pivot(0,0)
file_management_img_11.set_angle(0)
# create style style_file_management_img_11_main_main_default
style_file_management_img_11_main_main_default = lv.style_t()
style_file_management_img_11_main_main_default.init()
style_file_management_img_11_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_11_main_main_default.set_img_recolor_opa(0)
style_file_management_img_11_main_main_default.set_img_opa(255)

# add style for file_management_img_11
file_management_img_11.add_style(style_file_management_img_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_1 = lv.img(file_management_cont_1)
file_management_img_1.set_pos(30,742)
file_management_img_1.set_size(48,48)
file_management_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png','rb') as f:
        file_management_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png')
    sys.exit()

file_management_img_1_img = lv.img_dsc_t({
  'data_size': len(file_management_img_1_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_1_img_data
})

file_management_img_1.set_src(file_management_img_1_img)
file_management_img_1.set_pivot(0,0)
file_management_img_1.set_angle(0)
# create style style_file_management_img_1_main_main_default
style_file_management_img_1_main_main_default = lv.style_t()
style_file_management_img_1_main_main_default.init()
style_file_management_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_1_main_main_default.set_img_recolor_opa(0)
style_file_management_img_1_main_main_default.set_img_opa(255)

# add style for file_management_img_1
file_management_img_1.add_style(style_file_management_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_2 = lv.img(file_management_cont_1)
file_management_img_2.set_pos(128,742)
file_management_img_2.set_size(48,48)
file_management_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png','rb') as f:
        file_management_img_2_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png')
    sys.exit()

file_management_img_2_img = lv.img_dsc_t({
  'data_size': len(file_management_img_2_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_2_img_data
})

file_management_img_2.set_src(file_management_img_2_img)
file_management_img_2.set_pivot(0,0)
file_management_img_2.set_angle(0)
# create style style_file_management_img_2_main_main_default
style_file_management_img_2_main_main_default = lv.style_t()
style_file_management_img_2_main_main_default.init()
style_file_management_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_2_main_main_default.set_img_recolor_opa(0)
style_file_management_img_2_main_main_default.set_img_opa(255)

# add style for file_management_img_2
file_management_img_2.add_style(style_file_management_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_3 = lv.img(file_management_cont_1)
file_management_img_3.set_pos(224,742)
file_management_img_3.set_size(48,48)
file_management_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png','rb') as f:
        file_management_img_3_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png')
    sys.exit()

file_management_img_3_img = lv.img_dsc_t({
  'data_size': len(file_management_img_3_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_3_img_data
})

file_management_img_3.set_src(file_management_img_3_img)
file_management_img_3.set_pivot(0,0)
file_management_img_3.set_angle(0)
# create style style_file_management_img_3_main_main_default
style_file_management_img_3_main_main_default = lv.style_t()
style_file_management_img_3_main_main_default.init()
style_file_management_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_3_main_main_default.set_img_recolor_opa(0)
style_file_management_img_3_main_main_default.set_img_opa(255)

# add style for file_management_img_3
file_management_img_3.add_style(style_file_management_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_4 = lv.img(file_management_cont_1)
file_management_img_4.set_pos(318,742)
file_management_img_4.set_size(48,48)
file_management_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png','rb') as f:
        file_management_img_4_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png')
    sys.exit()

file_management_img_4_img = lv.img_dsc_t({
  'data_size': len(file_management_img_4_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_4_img_data
})

file_management_img_4.set_src(file_management_img_4_img)
file_management_img_4.set_pivot(0,0)
file_management_img_4.set_angle(0)
# create style style_file_management_img_4_main_main_default
style_file_management_img_4_main_main_default = lv.style_t()
style_file_management_img_4_main_main_default.init()
style_file_management_img_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_4_main_main_default.set_img_recolor_opa(0)
style_file_management_img_4_main_main_default.set_img_opa(255)

# add style for file_management_img_4
file_management_img_4.add_style(style_file_management_img_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_management_img_5 = lv.img(file_management_cont_1)
file_management_img_5.set_pos(414,742)
file_management_img_5.set_size(48,48)
file_management_img_5.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png','rb') as f:
        file_management_img_5_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png')
    sys.exit()

file_management_img_5_img = lv.img_dsc_t({
  'data_size': len(file_management_img_5_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_management_img_5_img_data
})

file_management_img_5.set_src(file_management_img_5_img)
file_management_img_5.set_pivot(0,0)
file_management_img_5.set_angle(0)
# create style style_file_management_img_5_main_main_default
style_file_management_img_5_main_main_default = lv.style_t()
style_file_management_img_5_main_main_default.init()
style_file_management_img_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_management_img_5_main_main_default.set_img_recolor_opa(0)
style_file_management_img_5_main_main_default.set_img_opa(255)

# add style for file_management_img_5
file_management_img_5.add_style(style_file_management_img_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_file_management_cont_1_main_main_default
style_file_management_cont_1_main_main_default = lv.style_t()
style_file_management_cont_1_main_main_default.init()
style_file_management_cont_1_main_main_default.set_radius(0)
style_file_management_cont_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_file_management_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_file_management_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_management_cont_1_main_main_default.set_bg_opa(255)
style_file_management_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_file_management_cont_1_main_main_default.set_border_width(0)
style_file_management_cont_1_main_main_default.set_border_opa(255)
style_file_management_cont_1_main_main_default.set_pad_left(0)
style_file_management_cont_1_main_main_default.set_pad_right(0)
style_file_management_cont_1_main_main_default.set_pad_top(0)
style_file_management_cont_1_main_main_default.set_pad_bottom(0)

# add style for file_management_cont_1
file_management_cont_1.add_style(style_file_management_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd = lv.obj()
# create style style_file_managemen_sd_main_main_default
style_file_managemen_sd_main_main_default = lv.style_t()
style_file_managemen_sd_main_main_default.init()
style_file_managemen_sd_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_main_main_default.set_bg_opa(0)

# add style for file_managemen_sd
file_managemen_sd.add_style(style_file_managemen_sd_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_tabview_1 = lv.tabview(file_managemen_sd, lv.DIR.TOP, 47)
file_managemen_sd_tabview_1_tab_btns = file_managemen_sd_tabview_1.get_tab_btns()
# create style style_file_managemen_sd_tabview_1_extra_btnm_main_default
style_file_managemen_sd_tabview_1_extra_btnm_main_default = lv.style_t()
style_file_managemen_sd_tabview_1_extra_btnm_main_default.init()
style_file_managemen_sd_tabview_1_extra_btnm_main_default.set_bg_color(lv.color_make(0x23,0x24,0x26))
style_file_managemen_sd_tabview_1_extra_btnm_main_default.set_bg_grad_color(lv.color_make(0x23,0x24,0x26))
style_file_managemen_sd_tabview_1_extra_btnm_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_tabview_1_extra_btnm_main_default.set_bg_opa(255)
style_file_managemen_sd_tabview_1_extra_btnm_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_sd_tabview_1_extra_btnm_main_default.set_border_width(0)
style_file_managemen_sd_tabview_1_extra_btnm_main_default.set_border_opa(100)
style_file_managemen_sd_tabview_1_extra_btnm_main_default.set_pad_left(0)
style_file_managemen_sd_tabview_1_extra_btnm_main_default.set_pad_right(0)
style_file_managemen_sd_tabview_1_extra_btnm_main_default.set_pad_top(0)
style_file_managemen_sd_tabview_1_extra_btnm_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_tabview_1_tab_btns
file_managemen_sd_tabview_1_tab_btns.add_style(style_file_managemen_sd_tabview_1_extra_btnm_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_file_managemen_sd_tabview_1_extra_btnm_items_default
style_file_managemen_sd_tabview_1_extra_btnm_items_default = lv.style_t()
style_file_managemen_sd_tabview_1_extra_btnm_items_default.init()
style_file_managemen_sd_tabview_1_extra_btnm_items_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_file_managemen_sd_tabview_1_extra_btnm_items_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_file_managemen_sd_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_file_managemen_sd_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_16)

# add style for file_managemen_sd_tabview_1_tab_btns
file_managemen_sd_tabview_1_tab_btns.add_style(style_file_managemen_sd_tabview_1_extra_btnm_items_default, lv.PART.ITEMS|lv.STATE.DEFAULT)

# create style style_file_managemen_sd_tabview_1_extra_btnm_items_checked
style_file_managemen_sd_tabview_1_extra_btnm_items_checked = lv.style_t()
style_file_managemen_sd_tabview_1_extra_btnm_items_checked.init()
style_file_managemen_sd_tabview_1_extra_btnm_items_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_sd_tabview_1_extra_btnm_items_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_sd_tabview_1_extra_btnm_items_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_tabview_1_extra_btnm_items_checked.set_bg_opa(60)
style_file_managemen_sd_tabview_1_extra_btnm_items_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_sd_tabview_1_extra_btnm_items_checked.set_border_width(4)
style_file_managemen_sd_tabview_1_extra_btnm_items_checked.set_border_opa(255)
style_file_managemen_sd_tabview_1_extra_btnm_items_checked.set_border_side(lv.BORDER_SIDE.BOTTOM)
style_file_managemen_sd_tabview_1_extra_btnm_items_checked.set_text_color(lv.color_make(0x21,0x95,0xf6))
try:
    style_file_managemen_sd_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_file_managemen_sd_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_file_managemen_sd_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_16)

# add style for file_managemen_sd_tabview_1_tab_btns
file_managemen_sd_tabview_1_tab_btns.add_style(style_file_managemen_sd_tabview_1_extra_btnm_items_checked, lv.PART.ITEMS|lv.STATE.CHECKED)

file_managemen_sd_tabview_1_title1 = file_managemen_sd_tabview_1.add_tab("title1")
file_managemen_sd_tabview_1_title2 = file_managemen_sd_tabview_1.add_tab("title2")
file_managemen_sd_tabview_1_title3 = file_managemen_sd_tabview_1.add_tab("title3")
file_managemen_sd_tabview_1.set_pos(0,0)
file_managemen_sd_tabview_1.set_size(480,720)
# create style style_file_managemen_sd_tabview_1_main_main_default
style_file_managemen_sd_tabview_1_main_main_default = lv.style_t()
style_file_managemen_sd_tabview_1_main_main_default.init()
style_file_managemen_sd_tabview_1_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_file_managemen_sd_tabview_1_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_file_managemen_sd_tabview_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_tabview_1_main_main_default.set_bg_opa(255)
style_file_managemen_sd_tabview_1_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_tabview_1_main_main_default.set_border_width(0)
style_file_managemen_sd_tabview_1_main_main_default.set_border_opa(100)
style_file_managemen_sd_tabview_1_main_main_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_file_managemen_sd_tabview_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_tabview_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_tabview_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_tabview_1_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_tabview_1_main_main_default.set_text_line_space(16)

# add style for file_managemen_sd_tabview_1
file_managemen_sd_tabview_1.add_style(style_file_managemen_sd_tabview_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_cont_1 = lv.obj(file_managemen_sd)
file_managemen_sd_cont_1.set_pos(0,0)
file_managemen_sd_cont_1.set_size(480,800)
file_managemen_sd_label_1 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_1.set_pos(0,720)
file_managemen_sd_label_1.set_size(480,80)
# create style style_file_managemen_sd_label_1_main_main_default
style_file_managemen_sd_label_1_main_main_default = lv.style_t()
style_file_managemen_sd_label_1_main_main_default.init()
style_file_managemen_sd_label_1_main_main_default.set_radius(0)
style_file_managemen_sd_label_1_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_sd_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_sd_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_1_main_main_default.set_bg_opa(255)
style_file_managemen_sd_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_1_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_1_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_1_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_1_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_1_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_1
file_managemen_sd_label_1.add_style(style_file_managemen_sd_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_2 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_2.set_pos(20,72)
file_managemen_sd_label_2.set_size(215,203)
# create style style_file_managemen_sd_label_2_main_main_default
style_file_managemen_sd_label_2_main_main_default = lv.style_t()
style_file_managemen_sd_label_2_main_main_default.init()
style_file_managemen_sd_label_2_main_main_default.set_radius(8)
style_file_managemen_sd_label_2_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_2_main_main_default.set_bg_opa(255)
style_file_managemen_sd_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_2_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_2_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_2_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_2_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_2_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_2_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_2_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_2
file_managemen_sd_label_2.add_style(style_file_managemen_sd_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_6 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_6.set_pos(245,72)
file_managemen_sd_label_6.set_size(215,203)
# create style style_file_managemen_sd_label_6_main_main_default
style_file_managemen_sd_label_6_main_main_default = lv.style_t()
style_file_managemen_sd_label_6_main_main_default.init()
style_file_managemen_sd_label_6_main_main_default.set_radius(8)
style_file_managemen_sd_label_6_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_6_main_main_default.set_bg_opa(255)
style_file_managemen_sd_label_6_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_6_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_6_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_6_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_6_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_6_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_6_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_6_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_6
file_managemen_sd_label_6.add_style(style_file_managemen_sd_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_10 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_10.set_pos(20,285)
file_managemen_sd_label_10.set_size(215,203)
# create style style_file_managemen_sd_label_10_main_main_default
style_file_managemen_sd_label_10_main_main_default = lv.style_t()
style_file_managemen_sd_label_10_main_main_default.init()
style_file_managemen_sd_label_10_main_main_default.set_radius(8)
style_file_managemen_sd_label_10_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_10_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_10_main_main_default.set_bg_opa(255)
style_file_managemen_sd_label_10_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_10_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_10_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_10_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_10_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_10_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_10_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_10_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_10
file_managemen_sd_label_10.add_style(style_file_managemen_sd_label_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_11 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_11.set_pos(245,285)
file_managemen_sd_label_11.set_size(215,203)
# create style style_file_managemen_sd_label_11_main_main_default
style_file_managemen_sd_label_11_main_main_default = lv.style_t()
style_file_managemen_sd_label_11_main_main_default.init()
style_file_managemen_sd_label_11_main_main_default.set_radius(8)
style_file_managemen_sd_label_11_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_11_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_11_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_11_main_main_default.set_bg_opa(255)
style_file_managemen_sd_label_11_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_11_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_11_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_11_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_11_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_11_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_11_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_11_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_11_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_11
file_managemen_sd_label_11.add_style(style_file_managemen_sd_label_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_12 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_12.set_pos(20,498)
file_managemen_sd_label_12.set_size(215,203)
# create style style_file_managemen_sd_label_12_main_main_default
style_file_managemen_sd_label_12_main_main_default = lv.style_t()
style_file_managemen_sd_label_12_main_main_default.init()
style_file_managemen_sd_label_12_main_main_default.set_radius(8)
style_file_managemen_sd_label_12_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_12_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_12_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_12_main_main_default.set_bg_opa(255)
style_file_managemen_sd_label_12_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_12_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_12_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_12_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_12_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_12_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_12_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_12_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_12_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_12
file_managemen_sd_label_12.add_style(style_file_managemen_sd_label_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_13 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_13.set_pos(245,498)
file_managemen_sd_label_13.set_size(215,203)
# create style style_file_managemen_sd_label_13_main_main_default
style_file_managemen_sd_label_13_main_main_default = lv.style_t()
style_file_managemen_sd_label_13_main_main_default.init()
style_file_managemen_sd_label_13_main_main_default.set_radius(8)
style_file_managemen_sd_label_13_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_13_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_13_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_13_main_main_default.set_bg_opa(255)
style_file_managemen_sd_label_13_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_13_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_13_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_13_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_13_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_13_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_13_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_13_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_13_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_13
file_managemen_sd_label_13.add_style(style_file_managemen_sd_label_13_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_3 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_3.set_pos(30,190)
file_managemen_sd_label_3.set_size(199,42)
file_managemen_sd_label_3.set_text("test.gcode")
file_managemen_sd_label_3.set_long_mode(lv.label.LONG.WRAP)
file_managemen_sd_label_3.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_sd_label_3_main_main_default
style_file_managemen_sd_label_3_main_main_default = lv.style_t()
style_file_managemen_sd_label_3_main_main_default.init()
style_file_managemen_sd_label_3_main_main_default.set_radius(0)
style_file_managemen_sd_label_3_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_3_main_main_default.set_bg_opa(255)
style_file_managemen_sd_label_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_3_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_3_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_3_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_3_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_3_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_3
file_managemen_sd_label_3.add_style(style_file_managemen_sd_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_btn_1 = lv.btn(file_managemen_sd_cont_1)
file_managemen_sd_btn_1.set_pos(418,592)
file_managemen_sd_btn_1.set_size(60,60)
# create style style_file_managemen_sd_btn_1_main_main_default
style_file_managemen_sd_btn_1_main_main_default = lv.style_t()
style_file_managemen_sd_btn_1_main_main_default.init()
style_file_managemen_sd_btn_1_main_main_default.set_radius(30)
style_file_managemen_sd_btn_1_main_main_default.set_bg_color(lv.color_make(0x26,0x28,0x2a))
style_file_managemen_sd_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x26,0x28,0x2a))
style_file_managemen_sd_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_btn_1_main_main_default.set_bg_opa(227)
style_file_managemen_sd_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_sd_btn_1_main_main_default.set_shadow_opa(0)
style_file_managemen_sd_btn_1_main_main_default.set_border_color(lv.color_make(0x4d,0x4d,0x4d))
style_file_managemen_sd_btn_1_main_main_default.set_border_width(1)
style_file_managemen_sd_btn_1_main_main_default.set_border_opa(255)

# add style for file_managemen_sd_btn_1
file_managemen_sd_btn_1.add_style(style_file_managemen_sd_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_btn_2 = lv.btn(file_managemen_sd_cont_1)
file_managemen_sd_btn_2.set_pos(418,666)
file_managemen_sd_btn_2.set_size(60,60)
# create style style_file_managemen_sd_btn_2_main_main_default
style_file_managemen_sd_btn_2_main_main_default = lv.style_t()
style_file_managemen_sd_btn_2_main_main_default.init()
style_file_managemen_sd_btn_2_main_main_default.set_radius(30)
style_file_managemen_sd_btn_2_main_main_default.set_bg_color(lv.color_make(0x26,0x28,0x2a))
style_file_managemen_sd_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x26,0x28,0x2a))
style_file_managemen_sd_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_btn_2_main_main_default.set_bg_opa(227)
style_file_managemen_sd_btn_2_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_sd_btn_2_main_main_default.set_shadow_opa(0)
style_file_managemen_sd_btn_2_main_main_default.set_border_color(lv.color_make(0x4d,0x4d,0x4d))
style_file_managemen_sd_btn_2_main_main_default.set_border_width(1)
style_file_managemen_sd_btn_2_main_main_default.set_border_opa(255)

# add style for file_managemen_sd_btn_2
file_managemen_sd_btn_2.add_style(style_file_managemen_sd_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_14 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_14.set_pos(30,403)
file_managemen_sd_label_14.set_size(199,42)
file_managemen_sd_label_14.set_text("test.gcode")
file_managemen_sd_label_14.set_long_mode(lv.label.LONG.WRAP)
file_managemen_sd_label_14.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_sd_label_14_main_main_default
style_file_managemen_sd_label_14_main_main_default = lv.style_t()
style_file_managemen_sd_label_14_main_main_default.init()
style_file_managemen_sd_label_14_main_main_default.set_radius(0)
style_file_managemen_sd_label_14_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_14_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_14_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_14_main_main_default.set_bg_opa(255)
style_file_managemen_sd_label_14_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_14_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_14_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_14_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_14_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_14_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_14_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_14_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_14_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_14
file_managemen_sd_label_14.add_style(style_file_managemen_sd_label_14_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_17 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_17.set_pos(255,403)
file_managemen_sd_label_17.set_size(199,42)
file_managemen_sd_label_17.set_text("test.gcode")
file_managemen_sd_label_17.set_long_mode(lv.label.LONG.WRAP)
file_managemen_sd_label_17.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_sd_label_17_main_main_default
style_file_managemen_sd_label_17_main_main_default = lv.style_t()
style_file_managemen_sd_label_17_main_main_default.init()
style_file_managemen_sd_label_17_main_main_default.set_radius(0)
style_file_managemen_sd_label_17_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_17_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_17_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_17_main_main_default.set_bg_opa(255)
style_file_managemen_sd_label_17_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_17_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_17_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_17_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_17_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_17_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_17_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_17_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_17_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_17
file_managemen_sd_label_17.add_style(style_file_managemen_sd_label_17_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_20 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_20.set_pos(30,616)
file_managemen_sd_label_20.set_size(199,42)
file_managemen_sd_label_20.set_text("test.gcode")
file_managemen_sd_label_20.set_long_mode(lv.label.LONG.WRAP)
file_managemen_sd_label_20.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_sd_label_20_main_main_default
style_file_managemen_sd_label_20_main_main_default = lv.style_t()
style_file_managemen_sd_label_20_main_main_default.init()
style_file_managemen_sd_label_20_main_main_default.set_radius(0)
style_file_managemen_sd_label_20_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_20_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_20_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_20_main_main_default.set_bg_opa(255)
style_file_managemen_sd_label_20_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_20_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_20_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_20_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_20_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_20_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_20_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_20_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_20_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_20
file_managemen_sd_label_20.add_style(style_file_managemen_sd_label_20_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_23 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_23.set_pos(255,616)
file_managemen_sd_label_23.set_size(199,42)
file_managemen_sd_label_23.set_text("test.gcode")
file_managemen_sd_label_23.set_long_mode(lv.label.LONG.WRAP)
file_managemen_sd_label_23.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_sd_label_23_main_main_default
style_file_managemen_sd_label_23_main_main_default = lv.style_t()
style_file_managemen_sd_label_23_main_main_default.init()
style_file_managemen_sd_label_23_main_main_default.set_radius(0)
style_file_managemen_sd_label_23_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_23_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_23_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_23_main_main_default.set_bg_opa(0)
style_file_managemen_sd_label_23_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_23_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_23_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_23_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_23_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_23_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_23_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_23_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_23_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_23
file_managemen_sd_label_23.add_style(style_file_managemen_sd_label_23_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_7 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_7.set_pos(255,190)
file_managemen_sd_label_7.set_size(199,42)
file_managemen_sd_label_7.set_text("test.gcode")
file_managemen_sd_label_7.set_long_mode(lv.label.LONG.WRAP)
file_managemen_sd_label_7.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_sd_label_7_main_main_default
style_file_managemen_sd_label_7_main_main_default = lv.style_t()
style_file_managemen_sd_label_7_main_main_default.init()
style_file_managemen_sd_label_7_main_main_default.set_radius(0)
style_file_managemen_sd_label_7_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_7_main_main_default.set_bg_opa(255)
style_file_managemen_sd_label_7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_7_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_7_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_7_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_7_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_7_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_7_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_7_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_7
file_managemen_sd_label_7.add_style(style_file_managemen_sd_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_4 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_4.set_pos(49,240)
file_managemen_sd_label_4.set_size(57,24)
file_managemen_sd_label_4.set_text("test.gcode")
file_managemen_sd_label_4.set_long_mode(lv.label.LONG.WRAP)
file_managemen_sd_label_4.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_sd_label_4_main_main_default
style_file_managemen_sd_label_4_main_main_default = lv.style_t()
style_file_managemen_sd_label_4_main_main_default.init()
style_file_managemen_sd_label_4_main_main_default.set_radius(0)
style_file_managemen_sd_label_4_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_4_main_main_default.set_bg_opa(0)
style_file_managemen_sd_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_4_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_4_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_4_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_4_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_4_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_4
file_managemen_sd_label_4.add_style(style_file_managemen_sd_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_15 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_15.set_pos(49,452)
file_managemen_sd_label_15.set_size(57,24)
file_managemen_sd_label_15.set_text("test.gcode")
file_managemen_sd_label_15.set_long_mode(lv.label.LONG.WRAP)
file_managemen_sd_label_15.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_sd_label_15_main_main_default
style_file_managemen_sd_label_15_main_main_default = lv.style_t()
style_file_managemen_sd_label_15_main_main_default.init()
style_file_managemen_sd_label_15_main_main_default.set_radius(0)
style_file_managemen_sd_label_15_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_15_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_15_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_15_main_main_default.set_bg_opa(0)
style_file_managemen_sd_label_15_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_15_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_15_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_15_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_15_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_15_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_15_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_15_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_15_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_15
file_managemen_sd_label_15.add_style(style_file_managemen_sd_label_15_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_21 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_21.set_pos(49,665)
file_managemen_sd_label_21.set_size(57,24)
file_managemen_sd_label_21.set_text("test.gcode")
file_managemen_sd_label_21.set_long_mode(lv.label.LONG.WRAP)
file_managemen_sd_label_21.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_sd_label_21_main_main_default
style_file_managemen_sd_label_21_main_main_default = lv.style_t()
style_file_managemen_sd_label_21_main_main_default.init()
style_file_managemen_sd_label_21_main_main_default.set_radius(0)
style_file_managemen_sd_label_21_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_21_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_21_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_21_main_main_default.set_bg_opa(0)
style_file_managemen_sd_label_21_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_21_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_21_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_21_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_21_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_21_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_21_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_21_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_21_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_21
file_managemen_sd_label_21.add_style(style_file_managemen_sd_label_21_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_24 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_24.set_pos(275,665)
file_managemen_sd_label_24.set_size(57,24)
file_managemen_sd_label_24.set_text("test.gcode")
file_managemen_sd_label_24.set_long_mode(lv.label.LONG.WRAP)
file_managemen_sd_label_24.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_sd_label_24_main_main_default
style_file_managemen_sd_label_24_main_main_default = lv.style_t()
style_file_managemen_sd_label_24_main_main_default.init()
style_file_managemen_sd_label_24_main_main_default.set_radius(0)
style_file_managemen_sd_label_24_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_24_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_24_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_24_main_main_default.set_bg_opa(0)
style_file_managemen_sd_label_24_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_24_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_24_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_24_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_24_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_24_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_24_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_24_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_24_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_24
file_managemen_sd_label_24.add_style(style_file_managemen_sd_label_24_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_25 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_25.set_pos(369,665)
file_managemen_sd_label_25.set_size(57,24)
file_managemen_sd_label_25.set_text("test.gcode")
file_managemen_sd_label_25.set_long_mode(lv.label.LONG.WRAP)
file_managemen_sd_label_25.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_sd_label_25_main_main_default
style_file_managemen_sd_label_25_main_main_default = lv.style_t()
style_file_managemen_sd_label_25_main_main_default.init()
style_file_managemen_sd_label_25_main_main_default.set_radius(0)
style_file_managemen_sd_label_25_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_25_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_25_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_25_main_main_default.set_bg_opa(0)
style_file_managemen_sd_label_25_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_25_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_25_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_25_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_25_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_25_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_25_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_25_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_25_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_25
file_managemen_sd_label_25.add_style(style_file_managemen_sd_label_25_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_22 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_22.set_pos(143,665)
file_managemen_sd_label_22.set_size(57,24)
file_managemen_sd_label_22.set_text("test.gcode")
file_managemen_sd_label_22.set_long_mode(lv.label.LONG.WRAP)
file_managemen_sd_label_22.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_sd_label_22_main_main_default
style_file_managemen_sd_label_22_main_main_default = lv.style_t()
style_file_managemen_sd_label_22_main_main_default.init()
style_file_managemen_sd_label_22_main_main_default.set_radius(0)
style_file_managemen_sd_label_22_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_22_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_22_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_22_main_main_default.set_bg_opa(0)
style_file_managemen_sd_label_22_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_22_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_22_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_22_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_22_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_22_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_22_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_22_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_22_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_22
file_managemen_sd_label_22.add_style(style_file_managemen_sd_label_22_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_18 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_18.set_pos(275,452)
file_managemen_sd_label_18.set_size(57,24)
file_managemen_sd_label_18.set_text("test.gcode")
file_managemen_sd_label_18.set_long_mode(lv.label.LONG.WRAP)
file_managemen_sd_label_18.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_sd_label_18_main_main_default
style_file_managemen_sd_label_18_main_main_default = lv.style_t()
style_file_managemen_sd_label_18_main_main_default.init()
style_file_managemen_sd_label_18_main_main_default.set_radius(0)
style_file_managemen_sd_label_18_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_18_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_18_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_18_main_main_default.set_bg_opa(0)
style_file_managemen_sd_label_18_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_18_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_18_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_18_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_18_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_18_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_18_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_18_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_18_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_18
file_managemen_sd_label_18.add_style(style_file_managemen_sd_label_18_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_19 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_19.set_pos(369,452)
file_managemen_sd_label_19.set_size(57,24)
file_managemen_sd_label_19.set_text("test.gcode")
file_managemen_sd_label_19.set_long_mode(lv.label.LONG.WRAP)
file_managemen_sd_label_19.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_sd_label_19_main_main_default
style_file_managemen_sd_label_19_main_main_default = lv.style_t()
style_file_managemen_sd_label_19_main_main_default.init()
style_file_managemen_sd_label_19_main_main_default.set_radius(0)
style_file_managemen_sd_label_19_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_19_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_19_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_19_main_main_default.set_bg_opa(0)
style_file_managemen_sd_label_19_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_19_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_19_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_19_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_19_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_19_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_19_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_19_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_19_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_19
file_managemen_sd_label_19.add_style(style_file_managemen_sd_label_19_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_16 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_16.set_pos(143,452)
file_managemen_sd_label_16.set_size(57,24)
file_managemen_sd_label_16.set_text("test.gcode")
file_managemen_sd_label_16.set_long_mode(lv.label.LONG.WRAP)
file_managemen_sd_label_16.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_sd_label_16_main_main_default
style_file_managemen_sd_label_16_main_main_default = lv.style_t()
style_file_managemen_sd_label_16_main_main_default.init()
style_file_managemen_sd_label_16_main_main_default.set_radius(0)
style_file_managemen_sd_label_16_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_16_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_16_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_16_main_main_default.set_bg_opa(0)
style_file_managemen_sd_label_16_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_16_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_16_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_16_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_16_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_16_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_16_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_16_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_16_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_16
file_managemen_sd_label_16.add_style(style_file_managemen_sd_label_16_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_8 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_8.set_pos(275,240)
file_managemen_sd_label_8.set_size(57,24)
file_managemen_sd_label_8.set_text("test.gcode")
file_managemen_sd_label_8.set_long_mode(lv.label.LONG.WRAP)
file_managemen_sd_label_8.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_sd_label_8_main_main_default
style_file_managemen_sd_label_8_main_main_default = lv.style_t()
style_file_managemen_sd_label_8_main_main_default.init()
style_file_managemen_sd_label_8_main_main_default.set_radius(0)
style_file_managemen_sd_label_8_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_8_main_main_default.set_bg_opa(0)
style_file_managemen_sd_label_8_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_8_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_8_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_8_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_8_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_8_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_8_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_8_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_8
file_managemen_sd_label_8.add_style(style_file_managemen_sd_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_5 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_5.set_pos(143,240)
file_managemen_sd_label_5.set_size(57,24)
file_managemen_sd_label_5.set_text("test.gcode")
file_managemen_sd_label_5.set_long_mode(lv.label.LONG.WRAP)
file_managemen_sd_label_5.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_sd_label_5_main_main_default
style_file_managemen_sd_label_5_main_main_default = lv.style_t()
style_file_managemen_sd_label_5_main_main_default.init()
style_file_managemen_sd_label_5_main_main_default.set_radius(0)
style_file_managemen_sd_label_5_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_5_main_main_default.set_bg_opa(0)
style_file_managemen_sd_label_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_5_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_5_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_5_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_5_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_5_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_5_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_5_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_5
file_managemen_sd_label_5.add_style(style_file_managemen_sd_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_label_9 = lv.label(file_managemen_sd_cont_1)
file_managemen_sd_label_9.set_pos(369,240)
file_managemen_sd_label_9.set_size(57,24)
file_managemen_sd_label_9.set_text("test.gcode")
file_managemen_sd_label_9.set_long_mode(lv.label.LONG.WRAP)
file_managemen_sd_label_9.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_sd_label_9_main_main_default
style_file_managemen_sd_label_9_main_main_default = lv.style_t()
style_file_managemen_sd_label_9_main_main_default.init()
style_file_managemen_sd_label_9_main_main_default.set_radius(0)
style_file_managemen_sd_label_9_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_9_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_managemen_sd_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_label_9_main_main_default.set_bg_opa(0)
style_file_managemen_sd_label_9_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_sd_label_9_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_sd_label_9_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_sd_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_sd_label_9_main_main_default.set_text_letter_space(0)
style_file_managemen_sd_label_9_main_main_default.set_pad_left(0)
style_file_managemen_sd_label_9_main_main_default.set_pad_right(0)
style_file_managemen_sd_label_9_main_main_default.set_pad_top(0)
style_file_managemen_sd_label_9_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_label_9
file_managemen_sd_label_9.add_style(style_file_managemen_sd_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_6 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_6.set_pos(80,82)
file_managemen_sd_img_6.set_size(96,96)
# create style style_file_managemen_sd_img_6_main_main_default
style_file_managemen_sd_img_6_main_main_default = lv.style_t()
style_file_managemen_sd_img_6_main_main_default.init()
style_file_managemen_sd_img_6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_6_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_6_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_6
file_managemen_sd_img_6.add_style(style_file_managemen_sd_img_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_9 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_9.set_pos(304,82)
file_managemen_sd_img_9.set_size(96,96)
# create style style_file_managemen_sd_img_9_main_main_default
style_file_managemen_sd_img_9_main_main_default = lv.style_t()
style_file_managemen_sd_img_9_main_main_default.init()
style_file_managemen_sd_img_9_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_9_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_9_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_9
file_managemen_sd_img_9.add_style(style_file_managemen_sd_img_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_15 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_15.set_pos(304,295)
file_managemen_sd_img_15.set_size(96,96)
# create style style_file_managemen_sd_img_15_main_main_default
style_file_managemen_sd_img_15_main_main_default = lv.style_t()
style_file_managemen_sd_img_15_main_main_default.init()
style_file_managemen_sd_img_15_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_15_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_15_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_15
file_managemen_sd_img_15.add_style(style_file_managemen_sd_img_15_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_18 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_18.set_pos(80,508)
file_managemen_sd_img_18.set_size(96,96)
# create style style_file_managemen_sd_img_18_main_main_default
style_file_managemen_sd_img_18_main_main_default = lv.style_t()
style_file_managemen_sd_img_18_main_main_default.init()
style_file_managemen_sd_img_18_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_18_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_18_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_18
file_managemen_sd_img_18.add_style(style_file_managemen_sd_img_18_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_21 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_21.set_pos(304,508)
file_managemen_sd_img_21.set_size(96,96)
# create style style_file_managemen_sd_img_21_main_main_default
style_file_managemen_sd_img_21_main_main_default = lv.style_t()
style_file_managemen_sd_img_21_main_main_default.init()
style_file_managemen_sd_img_21_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_21_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_21_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_21
file_managemen_sd_img_21.add_style(style_file_managemen_sd_img_21_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_24 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_24.set_pos(436,615)
file_managemen_sd_img_24.set_size(24,14)
file_managemen_sd_img_24.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp44047850.png','rb') as f:
        file_managemen_sd_img_24_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp44047850.png')
    sys.exit()

file_managemen_sd_img_24_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_24_img_data),
  'header': {'always_zero': 0, 'w': 24, 'h': 14, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_24_img_data
})

file_managemen_sd_img_24.set_src(file_managemen_sd_img_24_img)
file_managemen_sd_img_24.set_pivot(0,0)
file_managemen_sd_img_24.set_angle(0)
# create style style_file_managemen_sd_img_24_main_main_default
style_file_managemen_sd_img_24_main_main_default = lv.style_t()
style_file_managemen_sd_img_24_main_main_default.init()
style_file_managemen_sd_img_24_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_24_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_24_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_24
file_managemen_sd_img_24.add_style(style_file_managemen_sd_img_24_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_25 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_25.set_pos(436,689)
file_managemen_sd_img_25.set_size(24,14)
file_managemen_sd_img_25.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-2033161493.png','rb') as f:
        file_managemen_sd_img_25_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-2033161493.png')
    sys.exit()

file_managemen_sd_img_25_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_25_img_data),
  'header': {'always_zero': 0, 'w': 24, 'h': 14, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_25_img_data
})

file_managemen_sd_img_25.set_src(file_managemen_sd_img_25_img)
file_managemen_sd_img_25.set_pivot(0,0)
file_managemen_sd_img_25.set_angle(0)
# create style style_file_managemen_sd_img_25_main_main_default
style_file_managemen_sd_img_25_main_main_default = lv.style_t()
style_file_managemen_sd_img_25_main_main_default.init()
style_file_managemen_sd_img_25_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_25_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_25_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_25
file_managemen_sd_img_25.add_style(style_file_managemen_sd_img_25_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_12 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_12.set_pos(80,295)
file_managemen_sd_img_12.set_size(96,96)
# create style style_file_managemen_sd_img_12_main_main_default
style_file_managemen_sd_img_12_main_main_default = lv.style_t()
style_file_managemen_sd_img_12_main_main_default.init()
style_file_managemen_sd_img_12_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_12_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_12_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_12
file_managemen_sd_img_12.add_style(style_file_managemen_sd_img_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_7 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_7.set_pos(29,244)
file_managemen_sd_img_7.set_size(18,18)
file_managemen_sd_img_7.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png','rb') as f:
        file_managemen_sd_img_7_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png')
    sys.exit()

file_managemen_sd_img_7_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_7_img_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 18, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_7_img_data
})

file_managemen_sd_img_7.set_src(file_managemen_sd_img_7_img)
file_managemen_sd_img_7.set_pivot(0,0)
file_managemen_sd_img_7.set_angle(0)
# create style style_file_managemen_sd_img_7_main_main_default
style_file_managemen_sd_img_7_main_main_default = lv.style_t()
style_file_managemen_sd_img_7_main_main_default.init()
style_file_managemen_sd_img_7_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_7_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_7_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_7
file_managemen_sd_img_7.add_style(style_file_managemen_sd_img_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_13 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_13.set_pos(29,457)
file_managemen_sd_img_13.set_size(18,18)
file_managemen_sd_img_13.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png','rb') as f:
        file_managemen_sd_img_13_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png')
    sys.exit()

file_managemen_sd_img_13_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_13_img_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 18, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_13_img_data
})

file_managemen_sd_img_13.set_src(file_managemen_sd_img_13_img)
file_managemen_sd_img_13.set_pivot(0,0)
file_managemen_sd_img_13.set_angle(0)
# create style style_file_managemen_sd_img_13_main_main_default
style_file_managemen_sd_img_13_main_main_default = lv.style_t()
style_file_managemen_sd_img_13_main_main_default.init()
style_file_managemen_sd_img_13_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_13_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_13_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_13
file_managemen_sd_img_13.add_style(style_file_managemen_sd_img_13_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_19 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_19.set_pos(29,670)
file_managemen_sd_img_19.set_size(18,18)
file_managemen_sd_img_19.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png','rb') as f:
        file_managemen_sd_img_19_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png')
    sys.exit()

file_managemen_sd_img_19_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_19_img_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 18, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_19_img_data
})

file_managemen_sd_img_19.set_src(file_managemen_sd_img_19_img)
file_managemen_sd_img_19.set_pivot(0,0)
file_managemen_sd_img_19.set_angle(0)
# create style style_file_managemen_sd_img_19_main_main_default
style_file_managemen_sd_img_19_main_main_default = lv.style_t()
style_file_managemen_sd_img_19_main_main_default.init()
style_file_managemen_sd_img_19_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_19_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_19_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_19
file_managemen_sd_img_19.add_style(style_file_managemen_sd_img_19_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_22 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_22.set_pos(255,670)
file_managemen_sd_img_22.set_size(18,18)
file_managemen_sd_img_22.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png','rb') as f:
        file_managemen_sd_img_22_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png')
    sys.exit()

file_managemen_sd_img_22_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_22_img_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 18, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_22_img_data
})

file_managemen_sd_img_22.set_src(file_managemen_sd_img_22_img)
file_managemen_sd_img_22.set_pivot(0,0)
file_managemen_sd_img_22.set_angle(0)
# create style style_file_managemen_sd_img_22_main_main_default
style_file_managemen_sd_img_22_main_main_default = lv.style_t()
style_file_managemen_sd_img_22_main_main_default.init()
style_file_managemen_sd_img_22_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_22_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_22_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_22
file_managemen_sd_img_22.add_style(style_file_managemen_sd_img_22_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_16 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_16.set_pos(255,457)
file_managemen_sd_img_16.set_size(18,18)
file_managemen_sd_img_16.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png','rb') as f:
        file_managemen_sd_img_16_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png')
    sys.exit()

file_managemen_sd_img_16_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_16_img_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 18, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_16_img_data
})

file_managemen_sd_img_16.set_src(file_managemen_sd_img_16_img)
file_managemen_sd_img_16.set_pivot(0,0)
file_managemen_sd_img_16.set_angle(0)
# create style style_file_managemen_sd_img_16_main_main_default
style_file_managemen_sd_img_16_main_main_default = lv.style_t()
style_file_managemen_sd_img_16_main_main_default.init()
style_file_managemen_sd_img_16_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_16_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_16_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_16
file_managemen_sd_img_16.add_style(style_file_managemen_sd_img_16_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_10 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_10.set_pos(255,244)
file_managemen_sd_img_10.set_size(18,18)
file_managemen_sd_img_10.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png','rb') as f:
        file_managemen_sd_img_10_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png')
    sys.exit()

file_managemen_sd_img_10_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_10_img_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 18, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_10_img_data
})

file_managemen_sd_img_10.set_src(file_managemen_sd_img_10_img)
file_managemen_sd_img_10.set_pivot(0,0)
file_managemen_sd_img_10.set_angle(0)
# create style style_file_managemen_sd_img_10_main_main_default
style_file_managemen_sd_img_10_main_main_default = lv.style_t()
style_file_managemen_sd_img_10_main_main_default.init()
style_file_managemen_sd_img_10_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_10_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_10_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_10
file_managemen_sd_img_10.add_style(style_file_managemen_sd_img_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_8 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_8.set_pos(124,246)
file_managemen_sd_img_8.set_size(16,16)
file_managemen_sd_img_8.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png','rb') as f:
        file_managemen_sd_img_8_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png')
    sys.exit()

file_managemen_sd_img_8_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_8_img_data),
  'header': {'always_zero': 0, 'w': 16, 'h': 16, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_8_img_data
})

file_managemen_sd_img_8.set_src(file_managemen_sd_img_8_img)
file_managemen_sd_img_8.set_pivot(0,0)
file_managemen_sd_img_8.set_angle(0)
# create style style_file_managemen_sd_img_8_main_main_default
style_file_managemen_sd_img_8_main_main_default = lv.style_t()
style_file_managemen_sd_img_8_main_main_default.init()
style_file_managemen_sd_img_8_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_8_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_8_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_8
file_managemen_sd_img_8.add_style(style_file_managemen_sd_img_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_14 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_14.set_pos(124,459)
file_managemen_sd_img_14.set_size(16,16)
file_managemen_sd_img_14.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png','rb') as f:
        file_managemen_sd_img_14_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png')
    sys.exit()

file_managemen_sd_img_14_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_14_img_data),
  'header': {'always_zero': 0, 'w': 16, 'h': 16, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_14_img_data
})

file_managemen_sd_img_14.set_src(file_managemen_sd_img_14_img)
file_managemen_sd_img_14.set_pivot(0,0)
file_managemen_sd_img_14.set_angle(0)
# create style style_file_managemen_sd_img_14_main_main_default
style_file_managemen_sd_img_14_main_main_default = lv.style_t()
style_file_managemen_sd_img_14_main_main_default.init()
style_file_managemen_sd_img_14_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_14_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_14_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_14
file_managemen_sd_img_14.add_style(style_file_managemen_sd_img_14_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_20 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_20.set_pos(124,672)
file_managemen_sd_img_20.set_size(16,16)
file_managemen_sd_img_20.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png','rb') as f:
        file_managemen_sd_img_20_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png')
    sys.exit()

file_managemen_sd_img_20_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_20_img_data),
  'header': {'always_zero': 0, 'w': 16, 'h': 16, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_20_img_data
})

file_managemen_sd_img_20.set_src(file_managemen_sd_img_20_img)
file_managemen_sd_img_20.set_pivot(0,0)
file_managemen_sd_img_20.set_angle(0)
# create style style_file_managemen_sd_img_20_main_main_default
style_file_managemen_sd_img_20_main_main_default = lv.style_t()
style_file_managemen_sd_img_20_main_main_default.init()
style_file_managemen_sd_img_20_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_20_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_20_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_20
file_managemen_sd_img_20.add_style(style_file_managemen_sd_img_20_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_23 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_23.set_pos(350,672)
file_managemen_sd_img_23.set_size(16,16)
file_managemen_sd_img_23.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png','rb') as f:
        file_managemen_sd_img_23_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png')
    sys.exit()

file_managemen_sd_img_23_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_23_img_data),
  'header': {'always_zero': 0, 'w': 16, 'h': 16, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_23_img_data
})

file_managemen_sd_img_23.set_src(file_managemen_sd_img_23_img)
file_managemen_sd_img_23.set_pivot(0,0)
file_managemen_sd_img_23.set_angle(0)
# create style style_file_managemen_sd_img_23_main_main_default
style_file_managemen_sd_img_23_main_main_default = lv.style_t()
style_file_managemen_sd_img_23_main_main_default.init()
style_file_managemen_sd_img_23_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_23_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_23_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_23
file_managemen_sd_img_23.add_style(style_file_managemen_sd_img_23_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_17 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_17.set_pos(350,459)
file_managemen_sd_img_17.set_size(16,16)
file_managemen_sd_img_17.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png','rb') as f:
        file_managemen_sd_img_17_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png')
    sys.exit()

file_managemen_sd_img_17_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_17_img_data),
  'header': {'always_zero': 0, 'w': 16, 'h': 16, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_17_img_data
})

file_managemen_sd_img_17.set_src(file_managemen_sd_img_17_img)
file_managemen_sd_img_17.set_pivot(0,0)
file_managemen_sd_img_17.set_angle(0)
# create style style_file_managemen_sd_img_17_main_main_default
style_file_managemen_sd_img_17_main_main_default = lv.style_t()
style_file_managemen_sd_img_17_main_main_default.init()
style_file_managemen_sd_img_17_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_17_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_17_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_17
file_managemen_sd_img_17.add_style(style_file_managemen_sd_img_17_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_11 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_11.set_pos(350,246)
file_managemen_sd_img_11.set_size(16,16)
file_managemen_sd_img_11.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png','rb') as f:
        file_managemen_sd_img_11_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png')
    sys.exit()

file_managemen_sd_img_11_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_11_img_data),
  'header': {'always_zero': 0, 'w': 16, 'h': 16, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_11_img_data
})

file_managemen_sd_img_11.set_src(file_managemen_sd_img_11_img)
file_managemen_sd_img_11.set_pivot(0,0)
file_managemen_sd_img_11.set_angle(0)
# create style style_file_managemen_sd_img_11_main_main_default
style_file_managemen_sd_img_11_main_main_default = lv.style_t()
style_file_managemen_sd_img_11_main_main_default.init()
style_file_managemen_sd_img_11_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_11_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_11_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_11
file_managemen_sd_img_11.add_style(style_file_managemen_sd_img_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_1 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_1.set_pos(30,742)
file_managemen_sd_img_1.set_size(48,48)
file_managemen_sd_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png','rb') as f:
        file_managemen_sd_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png')
    sys.exit()

file_managemen_sd_img_1_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_1_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_1_img_data
})

file_managemen_sd_img_1.set_src(file_managemen_sd_img_1_img)
file_managemen_sd_img_1.set_pivot(0,0)
file_managemen_sd_img_1.set_angle(0)
# create style style_file_managemen_sd_img_1_main_main_default
style_file_managemen_sd_img_1_main_main_default = lv.style_t()
style_file_managemen_sd_img_1_main_main_default.init()
style_file_managemen_sd_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_1_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_1_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_1
file_managemen_sd_img_1.add_style(style_file_managemen_sd_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_2 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_2.set_pos(128,742)
file_managemen_sd_img_2.set_size(48,48)
file_managemen_sd_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png','rb') as f:
        file_managemen_sd_img_2_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png')
    sys.exit()

file_managemen_sd_img_2_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_2_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_2_img_data
})

file_managemen_sd_img_2.set_src(file_managemen_sd_img_2_img)
file_managemen_sd_img_2.set_pivot(0,0)
file_managemen_sd_img_2.set_angle(0)
# create style style_file_managemen_sd_img_2_main_main_default
style_file_managemen_sd_img_2_main_main_default = lv.style_t()
style_file_managemen_sd_img_2_main_main_default.init()
style_file_managemen_sd_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_2_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_2_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_2
file_managemen_sd_img_2.add_style(style_file_managemen_sd_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_3 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_3.set_pos(224,742)
file_managemen_sd_img_3.set_size(48,48)
file_managemen_sd_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png','rb') as f:
        file_managemen_sd_img_3_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png')
    sys.exit()

file_managemen_sd_img_3_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_3_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_3_img_data
})

file_managemen_sd_img_3.set_src(file_managemen_sd_img_3_img)
file_managemen_sd_img_3.set_pivot(0,0)
file_managemen_sd_img_3.set_angle(0)
# create style style_file_managemen_sd_img_3_main_main_default
style_file_managemen_sd_img_3_main_main_default = lv.style_t()
style_file_managemen_sd_img_3_main_main_default.init()
style_file_managemen_sd_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_3_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_3_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_3
file_managemen_sd_img_3.add_style(style_file_managemen_sd_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_4 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_4.set_pos(318,742)
file_managemen_sd_img_4.set_size(48,48)
file_managemen_sd_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png','rb') as f:
        file_managemen_sd_img_4_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png')
    sys.exit()

file_managemen_sd_img_4_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_4_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_4_img_data
})

file_managemen_sd_img_4.set_src(file_managemen_sd_img_4_img)
file_managemen_sd_img_4.set_pivot(0,0)
file_managemen_sd_img_4.set_angle(0)
# create style style_file_managemen_sd_img_4_main_main_default
style_file_managemen_sd_img_4_main_main_default = lv.style_t()
style_file_managemen_sd_img_4_main_main_default.init()
style_file_managemen_sd_img_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_4_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_4_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_4
file_managemen_sd_img_4.add_style(style_file_managemen_sd_img_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_sd_img_5 = lv.img(file_managemen_sd_cont_1)
file_managemen_sd_img_5.set_pos(414,742)
file_managemen_sd_img_5.set_size(48,48)
file_managemen_sd_img_5.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png','rb') as f:
        file_managemen_sd_img_5_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png')
    sys.exit()

file_managemen_sd_img_5_img = lv.img_dsc_t({
  'data_size': len(file_managemen_sd_img_5_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_sd_img_5_img_data
})

file_managemen_sd_img_5.set_src(file_managemen_sd_img_5_img)
file_managemen_sd_img_5.set_pivot(0,0)
file_managemen_sd_img_5.set_angle(0)
# create style style_file_managemen_sd_img_5_main_main_default
style_file_managemen_sd_img_5_main_main_default = lv.style_t()
style_file_managemen_sd_img_5_main_main_default.init()
style_file_managemen_sd_img_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_sd_img_5_main_main_default.set_img_recolor_opa(0)
style_file_managemen_sd_img_5_main_main_default.set_img_opa(255)

# add style for file_managemen_sd_img_5
file_managemen_sd_img_5.add_style(style_file_managemen_sd_img_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_file_managemen_sd_cont_1_main_main_default
style_file_managemen_sd_cont_1_main_main_default = lv.style_t()
style_file_managemen_sd_cont_1_main_main_default.init()
style_file_managemen_sd_cont_1_main_main_default.set_radius(0)
style_file_managemen_sd_cont_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_file_managemen_sd_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_file_managemen_sd_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_sd_cont_1_main_main_default.set_bg_opa(255)
style_file_managemen_sd_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_sd_cont_1_main_main_default.set_border_width(0)
style_file_managemen_sd_cont_1_main_main_default.set_border_opa(255)
style_file_managemen_sd_cont_1_main_main_default.set_pad_left(0)
style_file_managemen_sd_cont_1_main_main_default.set_pad_right(0)
style_file_managemen_sd_cont_1_main_main_default.set_pad_top(0)
style_file_managemen_sd_cont_1_main_main_default.set_pad_bottom(0)

# add style for file_managemen_sd_cont_1
file_managemen_sd_cont_1.add_style(style_file_managemen_sd_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history = lv.obj()
# create style style_file_managemen_history_main_main_default
style_file_managemen_history_main_main_default = lv.style_t()
style_file_managemen_history_main_main_default.init()
style_file_managemen_history_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_file_managemen_history_main_main_default.set_bg_opa(0)

# add style for file_managemen_history
file_managemen_history.add_style(style_file_managemen_history_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_tabview_1 = lv.tabview(file_managemen_history, lv.DIR.TOP, 47)
file_managemen_history_tabview_1_tab_btns = file_managemen_history_tabview_1.get_tab_btns()
# create style style_file_managemen_history_tabview_1_extra_btnm_main_default
style_file_managemen_history_tabview_1_extra_btnm_main_default = lv.style_t()
style_file_managemen_history_tabview_1_extra_btnm_main_default.init()
style_file_managemen_history_tabview_1_extra_btnm_main_default.set_bg_color(lv.color_make(0x23,0x24,0x26))
style_file_managemen_history_tabview_1_extra_btnm_main_default.set_bg_grad_color(lv.color_make(0x23,0x24,0x26))
style_file_managemen_history_tabview_1_extra_btnm_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_tabview_1_extra_btnm_main_default.set_bg_opa(255)
style_file_managemen_history_tabview_1_extra_btnm_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_history_tabview_1_extra_btnm_main_default.set_border_width(0)
style_file_managemen_history_tabview_1_extra_btnm_main_default.set_border_opa(100)
style_file_managemen_history_tabview_1_extra_btnm_main_default.set_pad_left(0)
style_file_managemen_history_tabview_1_extra_btnm_main_default.set_pad_right(0)
style_file_managemen_history_tabview_1_extra_btnm_main_default.set_pad_top(0)
style_file_managemen_history_tabview_1_extra_btnm_main_default.set_pad_bottom(0)

# add style for file_managemen_history_tabview_1_tab_btns
file_managemen_history_tabview_1_tab_btns.add_style(style_file_managemen_history_tabview_1_extra_btnm_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_file_managemen_history_tabview_1_extra_btnm_items_default
style_file_managemen_history_tabview_1_extra_btnm_items_default = lv.style_t()
style_file_managemen_history_tabview_1_extra_btnm_items_default.init()
style_file_managemen_history_tabview_1_extra_btnm_items_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_file_managemen_history_tabview_1_extra_btnm_items_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_file_managemen_history_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_file_managemen_history_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_16)

# add style for file_managemen_history_tabview_1_tab_btns
file_managemen_history_tabview_1_tab_btns.add_style(style_file_managemen_history_tabview_1_extra_btnm_items_default, lv.PART.ITEMS|lv.STATE.DEFAULT)

# create style style_file_managemen_history_tabview_1_extra_btnm_items_checked
style_file_managemen_history_tabview_1_extra_btnm_items_checked = lv.style_t()
style_file_managemen_history_tabview_1_extra_btnm_items_checked.init()
style_file_managemen_history_tabview_1_extra_btnm_items_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_history_tabview_1_extra_btnm_items_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_history_tabview_1_extra_btnm_items_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_tabview_1_extra_btnm_items_checked.set_bg_opa(60)
style_file_managemen_history_tabview_1_extra_btnm_items_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_history_tabview_1_extra_btnm_items_checked.set_border_width(4)
style_file_managemen_history_tabview_1_extra_btnm_items_checked.set_border_opa(255)
style_file_managemen_history_tabview_1_extra_btnm_items_checked.set_border_side(lv.BORDER_SIDE.BOTTOM)
style_file_managemen_history_tabview_1_extra_btnm_items_checked.set_text_color(lv.color_make(0x21,0x95,0xf6))
try:
    style_file_managemen_history_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_file_managemen_history_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_file_managemen_history_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_16)

# add style for file_managemen_history_tabview_1_tab_btns
file_managemen_history_tabview_1_tab_btns.add_style(style_file_managemen_history_tabview_1_extra_btnm_items_checked, lv.PART.ITEMS|lv.STATE.CHECKED)

file_managemen_history_tabview_1_title1 = file_managemen_history_tabview_1.add_tab("title1")
file_managemen_history_tabview_1_title2 = file_managemen_history_tabview_1.add_tab("title2")
file_managemen_history_tabview_1_title3 = file_managemen_history_tabview_1.add_tab("title3")
file_managemen_history_tabview_1.set_pos(0,0)
file_managemen_history_tabview_1.set_size(480,720)
# create style style_file_managemen_history_tabview_1_main_main_default
style_file_managemen_history_tabview_1_main_main_default = lv.style_t()
style_file_managemen_history_tabview_1_main_main_default.init()
style_file_managemen_history_tabview_1_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_file_managemen_history_tabview_1_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_file_managemen_history_tabview_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_tabview_1_main_main_default.set_bg_opa(255)
style_file_managemen_history_tabview_1_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_file_managemen_history_tabview_1_main_main_default.set_border_width(0)
style_file_managemen_history_tabview_1_main_main_default.set_border_opa(100)
style_file_managemen_history_tabview_1_main_main_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_file_managemen_history_tabview_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_tabview_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_tabview_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_tabview_1_main_main_default.set_text_letter_space(0)
style_file_managemen_history_tabview_1_main_main_default.set_text_line_space(16)

# add style for file_managemen_history_tabview_1
file_managemen_history_tabview_1.add_style(style_file_managemen_history_tabview_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_cont_1 = lv.obj(file_managemen_history)
file_managemen_history_cont_1.set_pos(0,0)
file_managemen_history_cont_1.set_size(480,800)
file_managemen_history_label_1 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_1.set_pos(0,720)
file_managemen_history_label_1.set_size(480,80)
# create style style_file_managemen_history_label_1_main_main_default
style_file_managemen_history_label_1_main_main_default = lv.style_t()
style_file_managemen_history_label_1_main_main_default.init()
style_file_managemen_history_label_1_main_main_default.set_radius(0)
style_file_managemen_history_label_1_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_1_main_main_default.set_bg_opa(255)
style_file_managemen_history_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_1_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_1_main_main_default.set_pad_left(0)
style_file_managemen_history_label_1_main_main_default.set_pad_right(0)
style_file_managemen_history_label_1_main_main_default.set_pad_top(0)
style_file_managemen_history_label_1_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_1
file_managemen_history_label_1.add_style(style_file_managemen_history_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_2 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_2.set_pos(7,59)
file_managemen_history_label_2.set_size(460,647)
# create style style_file_managemen_history_label_2_main_main_default
style_file_managemen_history_label_2_main_main_default = lv.style_t()
style_file_managemen_history_label_2_main_main_default.init()
style_file_managemen_history_label_2_main_main_default.set_radius(0)
style_file_managemen_history_label_2_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_file_managemen_history_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_file_managemen_history_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_2_main_main_default.set_bg_opa(255)
style_file_managemen_history_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_2_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_2_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_2_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_2_main_main_default.set_pad_left(0)
style_file_managemen_history_label_2_main_main_default.set_pad_right(0)
style_file_managemen_history_label_2_main_main_default.set_pad_top(0)
style_file_managemen_history_label_2_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_2
file_managemen_history_label_2.add_style(style_file_managemen_history_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_3 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_3.set_pos(130,85)
file_managemen_history_label_3.set_size(207,24)
file_managemen_history_label_3.set_text("test.gcode")
file_managemen_history_label_3.set_long_mode(lv.label.LONG.WRAP)
file_managemen_history_label_3.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_history_label_3_main_main_default
style_file_managemen_history_label_3_main_main_default = lv.style_t()
style_file_managemen_history_label_3_main_main_default.init()
style_file_managemen_history_label_3_main_main_default.set_radius(0)
style_file_managemen_history_label_3_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_3_main_main_default.set_bg_opa(0)
style_file_managemen_history_label_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_3_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_3_main_main_default.set_pad_left(0)
style_file_managemen_history_label_3_main_main_default.set_pad_right(0)
style_file_managemen_history_label_3_main_main_default.set_pad_top(0)
style_file_managemen_history_label_3_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_3
file_managemen_history_label_3.add_style(style_file_managemen_history_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_11 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_11.set_pos(130,201)
file_managemen_history_label_11.set_size(207,24)
file_managemen_history_label_11.set_text("test.gcode")
file_managemen_history_label_11.set_long_mode(lv.label.LONG.WRAP)
file_managemen_history_label_11.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_history_label_11_main_main_default
style_file_managemen_history_label_11_main_main_default = lv.style_t()
style_file_managemen_history_label_11_main_main_default.init()
style_file_managemen_history_label_11_main_main_default.set_radius(0)
style_file_managemen_history_label_11_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_11_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_11_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_11_main_main_default.set_bg_opa(0)
style_file_managemen_history_label_11_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_11_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_11_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_11_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_11_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_11_main_main_default.set_pad_left(0)
style_file_managemen_history_label_11_main_main_default.set_pad_right(0)
style_file_managemen_history_label_11_main_main_default.set_pad_top(0)
style_file_managemen_history_label_11_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_11
file_managemen_history_label_11.add_style(style_file_managemen_history_label_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_12 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_12.set_pos(130,317)
file_managemen_history_label_12.set_size(207,24)
file_managemen_history_label_12.set_text("test.gcode")
file_managemen_history_label_12.set_long_mode(lv.label.LONG.WRAP)
file_managemen_history_label_12.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_history_label_12_main_main_default
style_file_managemen_history_label_12_main_main_default = lv.style_t()
style_file_managemen_history_label_12_main_main_default.init()
style_file_managemen_history_label_12_main_main_default.set_radius(0)
style_file_managemen_history_label_12_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_12_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_12_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_12_main_main_default.set_bg_opa(0)
style_file_managemen_history_label_12_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_12_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_12_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_12_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_12_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_12_main_main_default.set_pad_left(0)
style_file_managemen_history_label_12_main_main_default.set_pad_right(0)
style_file_managemen_history_label_12_main_main_default.set_pad_top(0)
style_file_managemen_history_label_12_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_12
file_managemen_history_label_12.add_style(style_file_managemen_history_label_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_13 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_13.set_pos(130,433)
file_managemen_history_label_13.set_size(207,24)
file_managemen_history_label_13.set_text("test.gcode")
file_managemen_history_label_13.set_long_mode(lv.label.LONG.WRAP)
file_managemen_history_label_13.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_history_label_13_main_main_default
style_file_managemen_history_label_13_main_main_default = lv.style_t()
style_file_managemen_history_label_13_main_main_default.init()
style_file_managemen_history_label_13_main_main_default.set_radius(0)
style_file_managemen_history_label_13_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_13_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_13_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_13_main_main_default.set_bg_opa(0)
style_file_managemen_history_label_13_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_13_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_13_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_13_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_13_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_13_main_main_default.set_pad_left(0)
style_file_managemen_history_label_13_main_main_default.set_pad_right(0)
style_file_managemen_history_label_13_main_main_default.set_pad_top(0)
style_file_managemen_history_label_13_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_13
file_managemen_history_label_13.add_style(style_file_managemen_history_label_13_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_14 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_14.set_pos(130,549)
file_managemen_history_label_14.set_size(207,24)
file_managemen_history_label_14.set_text("test.gcode")
file_managemen_history_label_14.set_long_mode(lv.label.LONG.WRAP)
file_managemen_history_label_14.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_history_label_14_main_main_default
style_file_managemen_history_label_14_main_main_default = lv.style_t()
style_file_managemen_history_label_14_main_main_default.init()
style_file_managemen_history_label_14_main_main_default.set_radius(0)
style_file_managemen_history_label_14_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_14_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_14_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_14_main_main_default.set_bg_opa(0)
style_file_managemen_history_label_14_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_14_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_14_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_14_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_14_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_14_main_main_default.set_pad_left(0)
style_file_managemen_history_label_14_main_main_default.set_pad_right(0)
style_file_managemen_history_label_14_main_main_default.set_pad_top(0)
style_file_managemen_history_label_14_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_14
file_managemen_history_label_14.add_style(style_file_managemen_history_label_14_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_4 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_4.set_pos(130,117)
file_managemen_history_label_4.set_size(183,24)
file_managemen_history_label_4.set_text("3月4日 11：50")
file_managemen_history_label_4.set_long_mode(lv.label.LONG.WRAP)
file_managemen_history_label_4.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_history_label_4_main_main_default
style_file_managemen_history_label_4_main_main_default = lv.style_t()
style_file_managemen_history_label_4_main_main_default.init()
style_file_managemen_history_label_4_main_main_default.set_radius(0)
style_file_managemen_history_label_4_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_4_main_main_default.set_bg_opa(0)
style_file_managemen_history_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_4_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_4_main_main_default.set_pad_left(0)
style_file_managemen_history_label_4_main_main_default.set_pad_right(0)
style_file_managemen_history_label_4_main_main_default.set_pad_top(0)
style_file_managemen_history_label_4_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_4
file_managemen_history_label_4.add_style(style_file_managemen_history_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_15 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_15.set_pos(130,233)
file_managemen_history_label_15.set_size(183,24)
file_managemen_history_label_15.set_text("3月4日 11：50")
file_managemen_history_label_15.set_long_mode(lv.label.LONG.WRAP)
file_managemen_history_label_15.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_history_label_15_main_main_default
style_file_managemen_history_label_15_main_main_default = lv.style_t()
style_file_managemen_history_label_15_main_main_default.init()
style_file_managemen_history_label_15_main_main_default.set_radius(0)
style_file_managemen_history_label_15_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_15_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_15_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_15_main_main_default.set_bg_opa(0)
style_file_managemen_history_label_15_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_15_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_15_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_15_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_15_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_15_main_main_default.set_pad_left(0)
style_file_managemen_history_label_15_main_main_default.set_pad_right(0)
style_file_managemen_history_label_15_main_main_default.set_pad_top(0)
style_file_managemen_history_label_15_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_15
file_managemen_history_label_15.add_style(style_file_managemen_history_label_15_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_16 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_16.set_pos(130,349)
file_managemen_history_label_16.set_size(183,24)
file_managemen_history_label_16.set_text("3月4日 11：50")
file_managemen_history_label_16.set_long_mode(lv.label.LONG.WRAP)
file_managemen_history_label_16.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_history_label_16_main_main_default
style_file_managemen_history_label_16_main_main_default = lv.style_t()
style_file_managemen_history_label_16_main_main_default.init()
style_file_managemen_history_label_16_main_main_default.set_radius(0)
style_file_managemen_history_label_16_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_16_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_16_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_16_main_main_default.set_bg_opa(0)
style_file_managemen_history_label_16_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_16_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_16_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_16_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_16_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_16_main_main_default.set_pad_left(0)
style_file_managemen_history_label_16_main_main_default.set_pad_right(0)
style_file_managemen_history_label_16_main_main_default.set_pad_top(0)
style_file_managemen_history_label_16_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_16
file_managemen_history_label_16.add_style(style_file_managemen_history_label_16_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_17 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_17.set_pos(130,465)
file_managemen_history_label_17.set_size(183,24)
file_managemen_history_label_17.set_text("3月4日 11：50")
file_managemen_history_label_17.set_long_mode(lv.label.LONG.WRAP)
file_managemen_history_label_17.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_history_label_17_main_main_default
style_file_managemen_history_label_17_main_main_default = lv.style_t()
style_file_managemen_history_label_17_main_main_default.init()
style_file_managemen_history_label_17_main_main_default.set_radius(0)
style_file_managemen_history_label_17_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_17_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_17_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_17_main_main_default.set_bg_opa(0)
style_file_managemen_history_label_17_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_17_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_17_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_17_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_17_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_17_main_main_default.set_pad_left(0)
style_file_managemen_history_label_17_main_main_default.set_pad_right(0)
style_file_managemen_history_label_17_main_main_default.set_pad_top(0)
style_file_managemen_history_label_17_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_17
file_managemen_history_label_17.add_style(style_file_managemen_history_label_17_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_18 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_18.set_pos(130,581)
file_managemen_history_label_18.set_size(183,24)
file_managemen_history_label_18.set_text("3月4日 11：50")
file_managemen_history_label_18.set_long_mode(lv.label.LONG.WRAP)
file_managemen_history_label_18.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_history_label_18_main_main_default
style_file_managemen_history_label_18_main_main_default = lv.style_t()
style_file_managemen_history_label_18_main_main_default.init()
style_file_managemen_history_label_18_main_main_default.set_radius(0)
style_file_managemen_history_label_18_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_18_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_18_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_18_main_main_default.set_bg_opa(0)
style_file_managemen_history_label_18_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_18_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_18_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_18_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_18_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_18_main_main_default.set_pad_left(0)
style_file_managemen_history_label_18_main_main_default.set_pad_right(0)
style_file_managemen_history_label_18_main_main_default.set_pad_top(0)
style_file_managemen_history_label_18_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_18
file_managemen_history_label_18.add_style(style_file_managemen_history_label_18_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_5 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_5.set_pos(130,149)
file_managemen_history_label_5.set_size(183,24)
file_managemen_history_label_5.set_text("11h25m")
file_managemen_history_label_5.set_long_mode(lv.label.LONG.WRAP)
file_managemen_history_label_5.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_history_label_5_main_main_default
style_file_managemen_history_label_5_main_main_default = lv.style_t()
style_file_managemen_history_label_5_main_main_default.init()
style_file_managemen_history_label_5_main_main_default.set_radius(0)
style_file_managemen_history_label_5_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_5_main_main_default.set_bg_opa(0)
style_file_managemen_history_label_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_5_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_5_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_5_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_5_main_main_default.set_pad_left(0)
style_file_managemen_history_label_5_main_main_default.set_pad_right(0)
style_file_managemen_history_label_5_main_main_default.set_pad_top(0)
style_file_managemen_history_label_5_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_5
file_managemen_history_label_5.add_style(style_file_managemen_history_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_19 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_19.set_pos(130,265)
file_managemen_history_label_19.set_size(183,24)
file_managemen_history_label_19.set_text("11h25m")
file_managemen_history_label_19.set_long_mode(lv.label.LONG.WRAP)
file_managemen_history_label_19.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_history_label_19_main_main_default
style_file_managemen_history_label_19_main_main_default = lv.style_t()
style_file_managemen_history_label_19_main_main_default.init()
style_file_managemen_history_label_19_main_main_default.set_radius(0)
style_file_managemen_history_label_19_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_19_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_19_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_19_main_main_default.set_bg_opa(0)
style_file_managemen_history_label_19_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_19_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_19_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_19_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_19_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_19_main_main_default.set_pad_left(0)
style_file_managemen_history_label_19_main_main_default.set_pad_right(0)
style_file_managemen_history_label_19_main_main_default.set_pad_top(0)
style_file_managemen_history_label_19_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_19
file_managemen_history_label_19.add_style(style_file_managemen_history_label_19_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_20 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_20.set_pos(130,381)
file_managemen_history_label_20.set_size(183,24)
file_managemen_history_label_20.set_text("11h25m")
file_managemen_history_label_20.set_long_mode(lv.label.LONG.WRAP)
file_managemen_history_label_20.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_history_label_20_main_main_default
style_file_managemen_history_label_20_main_main_default = lv.style_t()
style_file_managemen_history_label_20_main_main_default.init()
style_file_managemen_history_label_20_main_main_default.set_radius(0)
style_file_managemen_history_label_20_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_20_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_20_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_20_main_main_default.set_bg_opa(0)
style_file_managemen_history_label_20_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_20_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_20_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_20_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_20_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_20_main_main_default.set_pad_left(0)
style_file_managemen_history_label_20_main_main_default.set_pad_right(0)
style_file_managemen_history_label_20_main_main_default.set_pad_top(0)
style_file_managemen_history_label_20_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_20
file_managemen_history_label_20.add_style(style_file_managemen_history_label_20_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_21 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_21.set_pos(130,497)
file_managemen_history_label_21.set_size(183,24)
file_managemen_history_label_21.set_text("11h25m")
file_managemen_history_label_21.set_long_mode(lv.label.LONG.WRAP)
file_managemen_history_label_21.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_history_label_21_main_main_default
style_file_managemen_history_label_21_main_main_default = lv.style_t()
style_file_managemen_history_label_21_main_main_default.init()
style_file_managemen_history_label_21_main_main_default.set_radius(0)
style_file_managemen_history_label_21_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_21_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_21_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_21_main_main_default.set_bg_opa(0)
style_file_managemen_history_label_21_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_21_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_21_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_21_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_21_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_21_main_main_default.set_pad_left(0)
style_file_managemen_history_label_21_main_main_default.set_pad_right(0)
style_file_managemen_history_label_21_main_main_default.set_pad_top(0)
style_file_managemen_history_label_21_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_21
file_managemen_history_label_21.add_style(style_file_managemen_history_label_21_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_22 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_22.set_pos(130,613)
file_managemen_history_label_22.set_size(183,24)
file_managemen_history_label_22.set_text("11h25m")
file_managemen_history_label_22.set_long_mode(lv.label.LONG.WRAP)
file_managemen_history_label_22.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_managemen_history_label_22_main_main_default
style_file_managemen_history_label_22_main_main_default = lv.style_t()
style_file_managemen_history_label_22_main_main_default.init()
style_file_managemen_history_label_22_main_main_default.set_radius(0)
style_file_managemen_history_label_22_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_22_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_file_managemen_history_label_22_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_22_main_main_default.set_bg_opa(0)
style_file_managemen_history_label_22_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_22_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_22_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_22_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_22_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_22_main_main_default.set_pad_left(0)
style_file_managemen_history_label_22_main_main_default.set_pad_right(0)
style_file_managemen_history_label_22_main_main_default.set_pad_top(0)
style_file_managemen_history_label_22_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_22
file_managemen_history_label_22.add_style(style_file_managemen_history_label_22_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_6 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_6.set_pos(20,191)
file_managemen_history_label_6.set_size(440,1)
# create style style_file_managemen_history_label_6_main_main_default
style_file_managemen_history_label_6_main_main_default = lv.style_t()
style_file_managemen_history_label_6_main_main_default.init()
style_file_managemen_history_label_6_main_main_default.set_radius(0)
style_file_managemen_history_label_6_main_main_default.set_bg_color(lv.color_make(0x3a,0x3d,0x42))
style_file_managemen_history_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x3a,0x3d,0x42))
style_file_managemen_history_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_6_main_main_default.set_bg_opa(255)
style_file_managemen_history_label_6_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_6_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_6_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_6_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_6_main_main_default.set_pad_left(0)
style_file_managemen_history_label_6_main_main_default.set_pad_right(0)
style_file_managemen_history_label_6_main_main_default.set_pad_top(0)
style_file_managemen_history_label_6_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_6
file_managemen_history_label_6.add_style(style_file_managemen_history_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_7 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_7.set_pos(20,307)
file_managemen_history_label_7.set_size(440,1)
# create style style_file_managemen_history_label_7_main_main_default
style_file_managemen_history_label_7_main_main_default = lv.style_t()
style_file_managemen_history_label_7_main_main_default.init()
style_file_managemen_history_label_7_main_main_default.set_radius(0)
style_file_managemen_history_label_7_main_main_default.set_bg_color(lv.color_make(0x3a,0x3d,0x42))
style_file_managemen_history_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x3a,0x3d,0x42))
style_file_managemen_history_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_7_main_main_default.set_bg_opa(255)
style_file_managemen_history_label_7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_7_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_7_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_7_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_7_main_main_default.set_pad_left(0)
style_file_managemen_history_label_7_main_main_default.set_pad_right(0)
style_file_managemen_history_label_7_main_main_default.set_pad_top(0)
style_file_managemen_history_label_7_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_7
file_managemen_history_label_7.add_style(style_file_managemen_history_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_8 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_8.set_pos(20,423)
file_managemen_history_label_8.set_size(440,1)
# create style style_file_managemen_history_label_8_main_main_default
style_file_managemen_history_label_8_main_main_default = lv.style_t()
style_file_managemen_history_label_8_main_main_default.init()
style_file_managemen_history_label_8_main_main_default.set_radius(0)
style_file_managemen_history_label_8_main_main_default.set_bg_color(lv.color_make(0x3a,0x3d,0x42))
style_file_managemen_history_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x3a,0x3d,0x42))
style_file_managemen_history_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_8_main_main_default.set_bg_opa(255)
style_file_managemen_history_label_8_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_8_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_8_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_8_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_8_main_main_default.set_pad_left(0)
style_file_managemen_history_label_8_main_main_default.set_pad_right(0)
style_file_managemen_history_label_8_main_main_default.set_pad_top(0)
style_file_managemen_history_label_8_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_8
file_managemen_history_label_8.add_style(style_file_managemen_history_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_9 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_9.set_pos(20,539)
file_managemen_history_label_9.set_size(440,1)
# create style style_file_managemen_history_label_9_main_main_default
style_file_managemen_history_label_9_main_main_default = lv.style_t()
style_file_managemen_history_label_9_main_main_default.init()
style_file_managemen_history_label_9_main_main_default.set_radius(0)
style_file_managemen_history_label_9_main_main_default.set_bg_color(lv.color_make(0x3a,0x3d,0x42))
style_file_managemen_history_label_9_main_main_default.set_bg_grad_color(lv.color_make(0x3a,0x3d,0x42))
style_file_managemen_history_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_9_main_main_default.set_bg_opa(255)
style_file_managemen_history_label_9_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_9_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_9_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_9_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_9_main_main_default.set_pad_left(0)
style_file_managemen_history_label_9_main_main_default.set_pad_right(0)
style_file_managemen_history_label_9_main_main_default.set_pad_top(0)
style_file_managemen_history_label_9_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_9
file_managemen_history_label_9.add_style(style_file_managemen_history_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_label_10 = lv.label(file_managemen_history_cont_1)
file_managemen_history_label_10.set_pos(20,655)
file_managemen_history_label_10.set_size(440,1)
# create style style_file_managemen_history_label_10_main_main_default
style_file_managemen_history_label_10_main_main_default = lv.style_t()
style_file_managemen_history_label_10_main_main_default.init()
style_file_managemen_history_label_10_main_main_default.set_radius(0)
style_file_managemen_history_label_10_main_main_default.set_bg_color(lv.color_make(0x3a,0x3d,0x42))
style_file_managemen_history_label_10_main_main_default.set_bg_grad_color(lv.color_make(0x3a,0x3d,0x42))
style_file_managemen_history_label_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_label_10_main_main_default.set_bg_opa(255)
style_file_managemen_history_label_10_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_managemen_history_label_10_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_managemen_history_label_10_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_managemen_history_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_managemen_history_label_10_main_main_default.set_text_letter_space(0)
style_file_managemen_history_label_10_main_main_default.set_pad_left(0)
style_file_managemen_history_label_10_main_main_default.set_pad_right(0)
style_file_managemen_history_label_10_main_main_default.set_pad_top(0)
style_file_managemen_history_label_10_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_label_10
file_managemen_history_label_10.add_style(style_file_managemen_history_label_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_btn_1 = lv.btn(file_managemen_history_cont_1)
file_managemen_history_btn_1.set_pos(418,592)
file_managemen_history_btn_1.set_size(60,60)
# create style style_file_managemen_history_btn_1_main_main_default
style_file_managemen_history_btn_1_main_main_default = lv.style_t()
style_file_managemen_history_btn_1_main_main_default.init()
style_file_managemen_history_btn_1_main_main_default.set_radius(30)
style_file_managemen_history_btn_1_main_main_default.set_bg_color(lv.color_make(0x26,0x28,0x2a))
style_file_managemen_history_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x26,0x28,0x2a))
style_file_managemen_history_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_btn_1_main_main_default.set_bg_opa(227)
style_file_managemen_history_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_history_btn_1_main_main_default.set_shadow_opa(0)
style_file_managemen_history_btn_1_main_main_default.set_border_color(lv.color_make(0x4d,0x4d,0x4d))
style_file_managemen_history_btn_1_main_main_default.set_border_width(1)
style_file_managemen_history_btn_1_main_main_default.set_border_opa(255)

# add style for file_managemen_history_btn_1
file_managemen_history_btn_1.add_style(style_file_managemen_history_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_btn_2 = lv.btn(file_managemen_history_cont_1)
file_managemen_history_btn_2.set_pos(418,666)
file_managemen_history_btn_2.set_size(60,60)
# create style style_file_managemen_history_btn_2_main_main_default
style_file_managemen_history_btn_2_main_main_default = lv.style_t()
style_file_managemen_history_btn_2_main_main_default.init()
style_file_managemen_history_btn_2_main_main_default.set_radius(30)
style_file_managemen_history_btn_2_main_main_default.set_bg_color(lv.color_make(0x26,0x28,0x2a))
style_file_managemen_history_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x26,0x28,0x2a))
style_file_managemen_history_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_btn_2_main_main_default.set_bg_opa(227)
style_file_managemen_history_btn_2_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_history_btn_2_main_main_default.set_shadow_opa(0)
style_file_managemen_history_btn_2_main_main_default.set_border_color(lv.color_make(0x4d,0x4d,0x4d))
style_file_managemen_history_btn_2_main_main_default.set_border_width(1)
style_file_managemen_history_btn_2_main_main_default.set_border_opa(255)

# add style for file_managemen_history_btn_2
file_managemen_history_btn_2.add_style(style_file_managemen_history_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_btn_3 = lv.btn(file_managemen_history_cont_1)
file_managemen_history_btn_3.set_pos(366,117)
file_managemen_history_btn_3.set_size(97,32)
file_managemen_history_btn_3_label = lv.label(file_managemen_history_btn_3)
file_managemen_history_btn_3_label.set_text("再次打印")
file_managemen_history_btn_3.set_style_pad_all(0, lv.STATE.DEFAULT)
file_managemen_history_btn_3_label.align(lv.ALIGN.CENTER,0,0)
file_managemen_history_btn_3_label.set_style_text_color(lv.color_make(0x42,0xbd,0xd8), lv.STATE.DEFAULT)
try:
    file_managemen_history_btn_3_label.set_style_text_font(lv.font_simsun_24, lv.STATE.DEFAULT)
except AttributeError:
    try:
        file_managemen_history_btn_3_label.set_style_text_font(lv.font_montserrat_24, lv.STATE.DEFAULT)
    except AttributeError:
        file_managemen_history_btn_3_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_file_managemen_history_btn_3_main_main_default
style_file_managemen_history_btn_3_main_main_default = lv.style_t()
style_file_managemen_history_btn_3_main_main_default.init()
style_file_managemen_history_btn_3_main_main_default.set_radius(0)
style_file_managemen_history_btn_3_main_main_default.set_bg_color(lv.color_make(0x26,0x28,0x2a))
style_file_managemen_history_btn_3_main_main_default.set_bg_grad_color(lv.color_make(0x26,0x28,0x2a))
style_file_managemen_history_btn_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_btn_3_main_main_default.set_bg_opa(0)
style_file_managemen_history_btn_3_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_history_btn_3_main_main_default.set_shadow_opa(0)
style_file_managemen_history_btn_3_main_main_default.set_border_color(lv.color_make(0x4d,0x4d,0x4d))
style_file_managemen_history_btn_3_main_main_default.set_border_width(0)
style_file_managemen_history_btn_3_main_main_default.set_border_opa(255)

# add style for file_managemen_history_btn_3
file_managemen_history_btn_3.add_style(style_file_managemen_history_btn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_btn_4 = lv.btn(file_managemen_history_cont_1)
file_managemen_history_btn_4.set_pos(366,233)
file_managemen_history_btn_4.set_size(97,32)
file_managemen_history_btn_4_label = lv.label(file_managemen_history_btn_4)
file_managemen_history_btn_4_label.set_text("再次打印")
file_managemen_history_btn_4.set_style_pad_all(0, lv.STATE.DEFAULT)
file_managemen_history_btn_4_label.align(lv.ALIGN.CENTER,0,0)
file_managemen_history_btn_4_label.set_style_text_color(lv.color_make(0x42,0xbd,0xd8), lv.STATE.DEFAULT)
try:
    file_managemen_history_btn_4_label.set_style_text_font(lv.font_simsun_24, lv.STATE.DEFAULT)
except AttributeError:
    try:
        file_managemen_history_btn_4_label.set_style_text_font(lv.font_montserrat_24, lv.STATE.DEFAULT)
    except AttributeError:
        file_managemen_history_btn_4_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_file_managemen_history_btn_4_main_main_default
style_file_managemen_history_btn_4_main_main_default = lv.style_t()
style_file_managemen_history_btn_4_main_main_default.init()
style_file_managemen_history_btn_4_main_main_default.set_radius(0)
style_file_managemen_history_btn_4_main_main_default.set_bg_color(lv.color_make(0x26,0x28,0x2a))
style_file_managemen_history_btn_4_main_main_default.set_bg_grad_color(lv.color_make(0x26,0x28,0x2a))
style_file_managemen_history_btn_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_btn_4_main_main_default.set_bg_opa(0)
style_file_managemen_history_btn_4_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_history_btn_4_main_main_default.set_shadow_opa(0)
style_file_managemen_history_btn_4_main_main_default.set_border_color(lv.color_make(0x4d,0x4d,0x4d))
style_file_managemen_history_btn_4_main_main_default.set_border_width(0)
style_file_managemen_history_btn_4_main_main_default.set_border_opa(255)

# add style for file_managemen_history_btn_4
file_managemen_history_btn_4.add_style(style_file_managemen_history_btn_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_btn_5 = lv.btn(file_managemen_history_cont_1)
file_managemen_history_btn_5.set_pos(366,349)
file_managemen_history_btn_5.set_size(97,32)
file_managemen_history_btn_5_label = lv.label(file_managemen_history_btn_5)
file_managemen_history_btn_5_label.set_text("再次打印")
file_managemen_history_btn_5.set_style_pad_all(0, lv.STATE.DEFAULT)
file_managemen_history_btn_5_label.align(lv.ALIGN.CENTER,0,0)
file_managemen_history_btn_5_label.set_style_text_color(lv.color_make(0x42,0xbd,0xd8), lv.STATE.DEFAULT)
try:
    file_managemen_history_btn_5_label.set_style_text_font(lv.font_simsun_24, lv.STATE.DEFAULT)
except AttributeError:
    try:
        file_managemen_history_btn_5_label.set_style_text_font(lv.font_montserrat_24, lv.STATE.DEFAULT)
    except AttributeError:
        file_managemen_history_btn_5_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_file_managemen_history_btn_5_main_main_default
style_file_managemen_history_btn_5_main_main_default = lv.style_t()
style_file_managemen_history_btn_5_main_main_default.init()
style_file_managemen_history_btn_5_main_main_default.set_radius(0)
style_file_managemen_history_btn_5_main_main_default.set_bg_color(lv.color_make(0x26,0x28,0x2a))
style_file_managemen_history_btn_5_main_main_default.set_bg_grad_color(lv.color_make(0x26,0x28,0x2a))
style_file_managemen_history_btn_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_btn_5_main_main_default.set_bg_opa(0)
style_file_managemen_history_btn_5_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_history_btn_5_main_main_default.set_shadow_opa(0)
style_file_managemen_history_btn_5_main_main_default.set_border_color(lv.color_make(0x4d,0x4d,0x4d))
style_file_managemen_history_btn_5_main_main_default.set_border_width(0)
style_file_managemen_history_btn_5_main_main_default.set_border_opa(255)

# add style for file_managemen_history_btn_5
file_managemen_history_btn_5.add_style(style_file_managemen_history_btn_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_btn_6 = lv.btn(file_managemen_history_cont_1)
file_managemen_history_btn_6.set_pos(366,462)
file_managemen_history_btn_6.set_size(97,32)
file_managemen_history_btn_6_label = lv.label(file_managemen_history_btn_6)
file_managemen_history_btn_6_label.set_text("再次打印")
file_managemen_history_btn_6.set_style_pad_all(0, lv.STATE.DEFAULT)
file_managemen_history_btn_6_label.align(lv.ALIGN.CENTER,0,0)
file_managemen_history_btn_6_label.set_style_text_color(lv.color_make(0x42,0xbd,0xd8), lv.STATE.DEFAULT)
try:
    file_managemen_history_btn_6_label.set_style_text_font(lv.font_simsun_24, lv.STATE.DEFAULT)
except AttributeError:
    try:
        file_managemen_history_btn_6_label.set_style_text_font(lv.font_montserrat_24, lv.STATE.DEFAULT)
    except AttributeError:
        file_managemen_history_btn_6_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_file_managemen_history_btn_6_main_main_default
style_file_managemen_history_btn_6_main_main_default = lv.style_t()
style_file_managemen_history_btn_6_main_main_default.init()
style_file_managemen_history_btn_6_main_main_default.set_radius(0)
style_file_managemen_history_btn_6_main_main_default.set_bg_color(lv.color_make(0x26,0x28,0x2a))
style_file_managemen_history_btn_6_main_main_default.set_bg_grad_color(lv.color_make(0x26,0x28,0x2a))
style_file_managemen_history_btn_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_btn_6_main_main_default.set_bg_opa(0)
style_file_managemen_history_btn_6_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_history_btn_6_main_main_default.set_shadow_opa(0)
style_file_managemen_history_btn_6_main_main_default.set_border_color(lv.color_make(0x4d,0x4d,0x4d))
style_file_managemen_history_btn_6_main_main_default.set_border_width(0)
style_file_managemen_history_btn_6_main_main_default.set_border_opa(255)

# add style for file_managemen_history_btn_6
file_managemen_history_btn_6.add_style(style_file_managemen_history_btn_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_btn_7 = lv.btn(file_managemen_history_cont_1)
file_managemen_history_btn_7.set_pos(366,581)
file_managemen_history_btn_7.set_size(97,32)
file_managemen_history_btn_7_label = lv.label(file_managemen_history_btn_7)
file_managemen_history_btn_7_label.set_text("再次打印")
file_managemen_history_btn_7.set_style_pad_all(0, lv.STATE.DEFAULT)
file_managemen_history_btn_7_label.align(lv.ALIGN.CENTER,0,0)
file_managemen_history_btn_7_label.set_style_text_color(lv.color_make(0x42,0xbd,0xd8), lv.STATE.DEFAULT)
try:
    file_managemen_history_btn_7_label.set_style_text_font(lv.font_simsun_24, lv.STATE.DEFAULT)
except AttributeError:
    try:
        file_managemen_history_btn_7_label.set_style_text_font(lv.font_montserrat_24, lv.STATE.DEFAULT)
    except AttributeError:
        file_managemen_history_btn_7_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_file_managemen_history_btn_7_main_main_default
style_file_managemen_history_btn_7_main_main_default = lv.style_t()
style_file_managemen_history_btn_7_main_main_default.init()
style_file_managemen_history_btn_7_main_main_default.set_radius(0)
style_file_managemen_history_btn_7_main_main_default.set_bg_color(lv.color_make(0x26,0x28,0x2a))
style_file_managemen_history_btn_7_main_main_default.set_bg_grad_color(lv.color_make(0x26,0x28,0x2a))
style_file_managemen_history_btn_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_btn_7_main_main_default.set_bg_opa(0)
style_file_managemen_history_btn_7_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_history_btn_7_main_main_default.set_shadow_opa(0)
style_file_managemen_history_btn_7_main_main_default.set_border_color(lv.color_make(0x4d,0x4d,0x4d))
style_file_managemen_history_btn_7_main_main_default.set_border_width(0)
style_file_managemen_history_btn_7_main_main_default.set_border_opa(255)

# add style for file_managemen_history_btn_7
file_managemen_history_btn_7.add_style(style_file_managemen_history_btn_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_img_6 = lv.img(file_managemen_history_cont_1)
file_managemen_history_img_6.set_pos(436,615)
file_managemen_history_img_6.set_size(24,14)
file_managemen_history_img_6.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp44047850.png','rb') as f:
        file_managemen_history_img_6_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp44047850.png')
    sys.exit()

file_managemen_history_img_6_img = lv.img_dsc_t({
  'data_size': len(file_managemen_history_img_6_img_data),
  'header': {'always_zero': 0, 'w': 24, 'h': 14, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_history_img_6_img_data
})

file_managemen_history_img_6.set_src(file_managemen_history_img_6_img)
file_managemen_history_img_6.set_pivot(0,0)
file_managemen_history_img_6.set_angle(0)
# create style style_file_managemen_history_img_6_main_main_default
style_file_managemen_history_img_6_main_main_default = lv.style_t()
style_file_managemen_history_img_6_main_main_default.init()
style_file_managemen_history_img_6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_history_img_6_main_main_default.set_img_recolor_opa(0)
style_file_managemen_history_img_6_main_main_default.set_img_opa(255)

# add style for file_managemen_history_img_6
file_managemen_history_img_6.add_style(style_file_managemen_history_img_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_img_8 = lv.img(file_managemen_history_cont_1)
file_managemen_history_img_8.set_pos(20,85)
file_managemen_history_img_8.set_size(96,96)
file_managemen_history_img_8.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp464483330.png','rb') as f:
        file_managemen_history_img_8_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp464483330.png')
    sys.exit()

file_managemen_history_img_8_img = lv.img_dsc_t({
  'data_size': len(file_managemen_history_img_8_img_data),
  'header': {'always_zero': 0, 'w': 96, 'h': 96, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_history_img_8_img_data
})

file_managemen_history_img_8.set_src(file_managemen_history_img_8_img)
file_managemen_history_img_8.set_pivot(0,0)
file_managemen_history_img_8.set_angle(0)
# create style style_file_managemen_history_img_8_main_main_default
style_file_managemen_history_img_8_main_main_default = lv.style_t()
style_file_managemen_history_img_8_main_main_default.init()
style_file_managemen_history_img_8_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_history_img_8_main_main_default.set_img_recolor_opa(0)
style_file_managemen_history_img_8_main_main_default.set_img_opa(255)

# add style for file_managemen_history_img_8
file_managemen_history_img_8.add_style(style_file_managemen_history_img_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_img_9 = lv.img(file_managemen_history_cont_1)
file_managemen_history_img_9.set_pos(20,201)
file_managemen_history_img_9.set_size(96,96)
file_managemen_history_img_9.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp464483330.png','rb') as f:
        file_managemen_history_img_9_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp464483330.png')
    sys.exit()

file_managemen_history_img_9_img = lv.img_dsc_t({
  'data_size': len(file_managemen_history_img_9_img_data),
  'header': {'always_zero': 0, 'w': 96, 'h': 96, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_history_img_9_img_data
})

file_managemen_history_img_9.set_src(file_managemen_history_img_9_img)
file_managemen_history_img_9.set_pivot(0,0)
file_managemen_history_img_9.set_angle(0)
# create style style_file_managemen_history_img_9_main_main_default
style_file_managemen_history_img_9_main_main_default = lv.style_t()
style_file_managemen_history_img_9_main_main_default.init()
style_file_managemen_history_img_9_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_history_img_9_main_main_default.set_img_recolor_opa(0)
style_file_managemen_history_img_9_main_main_default.set_img_opa(255)

# add style for file_managemen_history_img_9
file_managemen_history_img_9.add_style(style_file_managemen_history_img_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_img_10 = lv.img(file_managemen_history_cont_1)
file_managemen_history_img_10.set_pos(19,317)
file_managemen_history_img_10.set_size(96,96)
file_managemen_history_img_10.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp464483330.png','rb') as f:
        file_managemen_history_img_10_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp464483330.png')
    sys.exit()

file_managemen_history_img_10_img = lv.img_dsc_t({
  'data_size': len(file_managemen_history_img_10_img_data),
  'header': {'always_zero': 0, 'w': 96, 'h': 96, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_history_img_10_img_data
})

file_managemen_history_img_10.set_src(file_managemen_history_img_10_img)
file_managemen_history_img_10.set_pivot(0,0)
file_managemen_history_img_10.set_angle(0)
# create style style_file_managemen_history_img_10_main_main_default
style_file_managemen_history_img_10_main_main_default = lv.style_t()
style_file_managemen_history_img_10_main_main_default.init()
style_file_managemen_history_img_10_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_history_img_10_main_main_default.set_img_recolor_opa(0)
style_file_managemen_history_img_10_main_main_default.set_img_opa(255)

# add style for file_managemen_history_img_10
file_managemen_history_img_10.add_style(style_file_managemen_history_img_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_img_11 = lv.img(file_managemen_history_cont_1)
file_managemen_history_img_11.set_pos(20,433)
file_managemen_history_img_11.set_size(96,96)
file_managemen_history_img_11.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp464483330.png','rb') as f:
        file_managemen_history_img_11_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp464483330.png')
    sys.exit()

file_managemen_history_img_11_img = lv.img_dsc_t({
  'data_size': len(file_managemen_history_img_11_img_data),
  'header': {'always_zero': 0, 'w': 96, 'h': 96, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_history_img_11_img_data
})

file_managemen_history_img_11.set_src(file_managemen_history_img_11_img)
file_managemen_history_img_11.set_pivot(0,0)
file_managemen_history_img_11.set_angle(0)
# create style style_file_managemen_history_img_11_main_main_default
style_file_managemen_history_img_11_main_main_default = lv.style_t()
style_file_managemen_history_img_11_main_main_default.init()
style_file_managemen_history_img_11_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_history_img_11_main_main_default.set_img_recolor_opa(0)
style_file_managemen_history_img_11_main_main_default.set_img_opa(255)

# add style for file_managemen_history_img_11
file_managemen_history_img_11.add_style(style_file_managemen_history_img_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_img_12 = lv.img(file_managemen_history_cont_1)
file_managemen_history_img_12.set_pos(23,549)
file_managemen_history_img_12.set_size(96,96)
file_managemen_history_img_12.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp464483330.png','rb') as f:
        file_managemen_history_img_12_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp464483330.png')
    sys.exit()

file_managemen_history_img_12_img = lv.img_dsc_t({
  'data_size': len(file_managemen_history_img_12_img_data),
  'header': {'always_zero': 0, 'w': 96, 'h': 96, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_history_img_12_img_data
})

file_managemen_history_img_12.set_src(file_managemen_history_img_12_img)
file_managemen_history_img_12.set_pivot(0,0)
file_managemen_history_img_12.set_angle(0)
# create style style_file_managemen_history_img_12_main_main_default
style_file_managemen_history_img_12_main_main_default = lv.style_t()
style_file_managemen_history_img_12_main_main_default.init()
style_file_managemen_history_img_12_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_history_img_12_main_main_default.set_img_recolor_opa(0)
style_file_managemen_history_img_12_main_main_default.set_img_opa(255)

# add style for file_managemen_history_img_12
file_managemen_history_img_12.add_style(style_file_managemen_history_img_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_img_7 = lv.img(file_managemen_history_cont_1)
file_managemen_history_img_7.set_pos(436,689)
file_managemen_history_img_7.set_size(24,14)
file_managemen_history_img_7.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-2033161493.png','rb') as f:
        file_managemen_history_img_7_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-2033161493.png')
    sys.exit()

file_managemen_history_img_7_img = lv.img_dsc_t({
  'data_size': len(file_managemen_history_img_7_img_data),
  'header': {'always_zero': 0, 'w': 24, 'h': 14, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_history_img_7_img_data
})

file_managemen_history_img_7.set_src(file_managemen_history_img_7_img)
file_managemen_history_img_7.set_pivot(0,0)
file_managemen_history_img_7.set_angle(0)
# create style style_file_managemen_history_img_7_main_main_default
style_file_managemen_history_img_7_main_main_default = lv.style_t()
style_file_managemen_history_img_7_main_main_default.init()
style_file_managemen_history_img_7_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_history_img_7_main_main_default.set_img_recolor_opa(0)
style_file_managemen_history_img_7_main_main_default.set_img_opa(255)

# add style for file_managemen_history_img_7
file_managemen_history_img_7.add_style(style_file_managemen_history_img_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_img_1 = lv.img(file_managemen_history_cont_1)
file_managemen_history_img_1.set_pos(30,742)
file_managemen_history_img_1.set_size(48,48)
file_managemen_history_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png','rb') as f:
        file_managemen_history_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png')
    sys.exit()

file_managemen_history_img_1_img = lv.img_dsc_t({
  'data_size': len(file_managemen_history_img_1_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_history_img_1_img_data
})

file_managemen_history_img_1.set_src(file_managemen_history_img_1_img)
file_managemen_history_img_1.set_pivot(0,0)
file_managemen_history_img_1.set_angle(0)
# create style style_file_managemen_history_img_1_main_main_default
style_file_managemen_history_img_1_main_main_default = lv.style_t()
style_file_managemen_history_img_1_main_main_default.init()
style_file_managemen_history_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_history_img_1_main_main_default.set_img_recolor_opa(0)
style_file_managemen_history_img_1_main_main_default.set_img_opa(255)

# add style for file_managemen_history_img_1
file_managemen_history_img_1.add_style(style_file_managemen_history_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_img_2 = lv.img(file_managemen_history_cont_1)
file_managemen_history_img_2.set_pos(128,742)
file_managemen_history_img_2.set_size(48,48)
file_managemen_history_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png','rb') as f:
        file_managemen_history_img_2_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png')
    sys.exit()

file_managemen_history_img_2_img = lv.img_dsc_t({
  'data_size': len(file_managemen_history_img_2_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_history_img_2_img_data
})

file_managemen_history_img_2.set_src(file_managemen_history_img_2_img)
file_managemen_history_img_2.set_pivot(0,0)
file_managemen_history_img_2.set_angle(0)
# create style style_file_managemen_history_img_2_main_main_default
style_file_managemen_history_img_2_main_main_default = lv.style_t()
style_file_managemen_history_img_2_main_main_default.init()
style_file_managemen_history_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_history_img_2_main_main_default.set_img_recolor_opa(0)
style_file_managemen_history_img_2_main_main_default.set_img_opa(255)

# add style for file_managemen_history_img_2
file_managemen_history_img_2.add_style(style_file_managemen_history_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_img_3 = lv.img(file_managemen_history_cont_1)
file_managemen_history_img_3.set_pos(224,742)
file_managemen_history_img_3.set_size(48,48)
file_managemen_history_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png','rb') as f:
        file_managemen_history_img_3_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png')
    sys.exit()

file_managemen_history_img_3_img = lv.img_dsc_t({
  'data_size': len(file_managemen_history_img_3_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_history_img_3_img_data
})

file_managemen_history_img_3.set_src(file_managemen_history_img_3_img)
file_managemen_history_img_3.set_pivot(0,0)
file_managemen_history_img_3.set_angle(0)
# create style style_file_managemen_history_img_3_main_main_default
style_file_managemen_history_img_3_main_main_default = lv.style_t()
style_file_managemen_history_img_3_main_main_default.init()
style_file_managemen_history_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_history_img_3_main_main_default.set_img_recolor_opa(0)
style_file_managemen_history_img_3_main_main_default.set_img_opa(255)

# add style for file_managemen_history_img_3
file_managemen_history_img_3.add_style(style_file_managemen_history_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_img_4 = lv.img(file_managemen_history_cont_1)
file_managemen_history_img_4.set_pos(318,742)
file_managemen_history_img_4.set_size(48,48)
file_managemen_history_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png','rb') as f:
        file_managemen_history_img_4_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png')
    sys.exit()

file_managemen_history_img_4_img = lv.img_dsc_t({
  'data_size': len(file_managemen_history_img_4_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_history_img_4_img_data
})

file_managemen_history_img_4.set_src(file_managemen_history_img_4_img)
file_managemen_history_img_4.set_pivot(0,0)
file_managemen_history_img_4.set_angle(0)
# create style style_file_managemen_history_img_4_main_main_default
style_file_managemen_history_img_4_main_main_default = lv.style_t()
style_file_managemen_history_img_4_main_main_default.init()
style_file_managemen_history_img_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_history_img_4_main_main_default.set_img_recolor_opa(0)
style_file_managemen_history_img_4_main_main_default.set_img_opa(255)

# add style for file_managemen_history_img_4
file_managemen_history_img_4.add_style(style_file_managemen_history_img_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_managemen_history_img_5 = lv.img(file_managemen_history_cont_1)
file_managemen_history_img_5.set_pos(414,742)
file_managemen_history_img_5.set_size(48,48)
file_managemen_history_img_5.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png','rb') as f:
        file_managemen_history_img_5_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png')
    sys.exit()

file_managemen_history_img_5_img = lv.img_dsc_t({
  'data_size': len(file_managemen_history_img_5_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_managemen_history_img_5_img_data
})

file_managemen_history_img_5.set_src(file_managemen_history_img_5_img)
file_managemen_history_img_5.set_pivot(0,0)
file_managemen_history_img_5.set_angle(0)
# create style style_file_managemen_history_img_5_main_main_default
style_file_managemen_history_img_5_main_main_default = lv.style_t()
style_file_managemen_history_img_5_main_main_default.init()
style_file_managemen_history_img_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_managemen_history_img_5_main_main_default.set_img_recolor_opa(0)
style_file_managemen_history_img_5_main_main_default.set_img_opa(255)

# add style for file_managemen_history_img_5
file_managemen_history_img_5.add_style(style_file_managemen_history_img_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_file_managemen_history_cont_1_main_main_default
style_file_managemen_history_cont_1_main_main_default = lv.style_t()
style_file_managemen_history_cont_1_main_main_default.init()
style_file_managemen_history_cont_1_main_main_default.set_radius(0)
style_file_managemen_history_cont_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_file_managemen_history_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_file_managemen_history_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_managemen_history_cont_1_main_main_default.set_bg_opa(255)
style_file_managemen_history_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_file_managemen_history_cont_1_main_main_default.set_border_width(0)
style_file_managemen_history_cont_1_main_main_default.set_border_opa(255)
style_file_managemen_history_cont_1_main_main_default.set_pad_left(0)
style_file_managemen_history_cont_1_main_main_default.set_pad_right(0)
style_file_managemen_history_cont_1_main_main_default.set_pad_top(0)
style_file_managemen_history_cont_1_main_main_default.set_pad_bottom(0)

# add style for file_managemen_history_cont_1
file_managemen_history_cont_1.add_style(style_file_managemen_history_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_information = lv.obj()
# create style style_file_information_main_main_default
style_file_information_main_main_default = lv.style_t()
style_file_information_main_main_default.init()
style_file_information_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_file_information_main_main_default.set_bg_opa(0)

# add style for file_information
file_information.add_style(style_file_information_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_information_cont_1 = lv.obj(file_information)
file_information_cont_1.set_pos(0,0)
file_information_cont_1.set_size(480,800)
file_information_label_1 = lv.label(file_information_cont_1)
file_information_label_1.set_pos(0,0)
file_information_label_1.set_size(480,53)
# create style style_file_information_label_1_main_main_default
style_file_information_label_1_main_main_default = lv.style_t()
style_file_information_label_1_main_main_default.init()
style_file_information_label_1_main_main_default.set_radius(0)
style_file_information_label_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_file_information_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_file_information_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_information_label_1_main_main_default.set_bg_opa(255)
style_file_information_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_information_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_information_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_information_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_information_label_1_main_main_default.set_text_letter_space(2)
style_file_information_label_1_main_main_default.set_pad_left(0)
style_file_information_label_1_main_main_default.set_pad_right(0)
style_file_information_label_1_main_main_default.set_pad_top(0)
style_file_information_label_1_main_main_default.set_pad_bottom(0)

# add style for file_information_label_1
file_information_label_1.add_style(style_file_information_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_information_label_3 = lv.label(file_information_cont_1)
file_information_label_3.set_pos(9,64)
file_information_label_3.set_size(460,727)
# create style style_file_information_label_3_main_main_default
style_file_information_label_3_main_main_default = lv.style_t()
style_file_information_label_3_main_main_default.init()
style_file_information_label_3_main_main_default.set_radius(0)
style_file_information_label_3_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_file_information_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_file_information_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_information_label_3_main_main_default.set_bg_opa(255)
style_file_information_label_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_information_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_information_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_information_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_information_label_3_main_main_default.set_text_letter_space(0)
style_file_information_label_3_main_main_default.set_pad_left(0)
style_file_information_label_3_main_main_default.set_pad_right(0)
style_file_information_label_3_main_main_default.set_pad_top(0)
style_file_information_label_3_main_main_default.set_pad_bottom(0)

# add style for file_information_label_3
file_information_label_3.add_style(style_file_information_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_information_btn_2 = lv.btn(file_information_cont_1)
file_information_btn_2.set_pos(27,700)
file_information_btn_2.set_size(426,65)
file_information_btn_2_label = lv.label(file_information_btn_2)
file_information_btn_2_label.set_text("打印")
file_information_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
file_information_btn_2_label.align(lv.ALIGN.CENTER,0,0)
file_information_btn_2_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    file_information_btn_2_label.set_style_text_font(lv.font_simsun_28, lv.STATE.DEFAULT)
except AttributeError:
    try:
        file_information_btn_2_label.set_style_text_font(lv.font_montserrat_28, lv.STATE.DEFAULT)
    except AttributeError:
        file_information_btn_2_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_file_information_btn_2_main_main_default
style_file_information_btn_2_main_main_default = lv.style_t()
style_file_information_btn_2_main_main_default.init()
style_file_information_btn_2_main_main_default.set_radius(5)
style_file_information_btn_2_main_main_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_file_information_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_file_information_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_information_btn_2_main_main_default.set_bg_opa(255)
style_file_information_btn_2_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_file_information_btn_2_main_main_default.set_shadow_opa(0)
style_file_information_btn_2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_file_information_btn_2_main_main_default.set_border_width(0)
style_file_information_btn_2_main_main_default.set_border_opa(255)

# add style for file_information_btn_2
file_information_btn_2.add_style(style_file_information_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_information_label_4 = lv.label(file_information_cont_1)
file_information_label_4.set_pos(26,76)
file_information_label_4.set_size(427,344)
# create style style_file_information_label_4_main_main_default
style_file_information_label_4_main_main_default = lv.style_t()
style_file_information_label_4_main_main_default.init()
style_file_information_label_4_main_main_default.set_radius(0)
style_file_information_label_4_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_information_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_file_information_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_information_label_4_main_main_default.set_bg_opa(255)
style_file_information_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_information_label_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_information_label_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_information_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_information_label_4_main_main_default.set_text_letter_space(0)
style_file_information_label_4_main_main_default.set_pad_left(0)
style_file_information_label_4_main_main_default.set_pad_right(0)
style_file_information_label_4_main_main_default.set_pad_top(0)
style_file_information_label_4_main_main_default.set_pad_bottom(0)

# add style for file_information_label_4
file_information_label_4.add_style(style_file_information_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_information_img_2 = lv.img(file_information_cont_1)
file_information_img_2.set_pos(90,93)
file_information_img_2.set_size(300,300)
# create style style_file_information_img_2_main_main_default
style_file_information_img_2_main_main_default = lv.style_t()
style_file_information_img_2_main_main_default.init()
style_file_information_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_information_img_2_main_main_default.set_img_recolor_opa(0)
style_file_information_img_2_main_main_default.set_img_opa(255)

# add style for file_information_img_2
file_information_img_2.add_style(style_file_information_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_information_img_3 = lv.img(file_information_cont_1)
file_information_img_3.set_pos(28,507)
file_information_img_3.set_size(18,18)
file_information_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png','rb') as f:
        file_information_img_3_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-464334966.png')
    sys.exit()

file_information_img_3_img = lv.img_dsc_t({
  'data_size': len(file_information_img_3_img_data),
  'header': {'always_zero': 0, 'w': 18, 'h': 18, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_information_img_3_img_data
})

file_information_img_3.set_src(file_information_img_3_img)
file_information_img_3.set_pivot(0,0)
file_information_img_3.set_angle(0)
# create style style_file_information_img_3_main_main_default
style_file_information_img_3_main_main_default = lv.style_t()
style_file_information_img_3_main_main_default.init()
style_file_information_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_information_img_3_main_main_default.set_img_recolor_opa(0)
style_file_information_img_3_main_main_default.set_img_opa(255)

# add style for file_information_img_3
file_information_img_3.add_style(style_file_information_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_information_img_4 = lv.img(file_information_cont_1)
file_information_img_4.set_pos(173,507)
file_information_img_4.set_size(16,16)
file_information_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png','rb') as f:
        file_information_img_4_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1221404579.png')
    sys.exit()

file_information_img_4_img = lv.img_dsc_t({
  'data_size': len(file_information_img_4_img_data),
  'header': {'always_zero': 0, 'w': 16, 'h': 16, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_information_img_4_img_data
})

file_information_img_4.set_src(file_information_img_4_img)
file_information_img_4.set_pivot(0,0)
file_information_img_4.set_angle(0)
# create style style_file_information_img_4_main_main_default
style_file_information_img_4_main_main_default = lv.style_t()
style_file_information_img_4_main_main_default.init()
style_file_information_img_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_information_img_4_main_main_default.set_img_recolor_opa(0)
style_file_information_img_4_main_main_default.set_img_opa(255)

# add style for file_information_img_4
file_information_img_4.add_style(style_file_information_img_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_information_btn_1 = lv.btn(file_information_cont_1)
file_information_btn_1.set_pos(0,0)
file_information_btn_1.set_size(85,50)
# create style style_file_information_btn_1_main_main_default
style_file_information_btn_1_main_main_default = lv.style_t()
style_file_information_btn_1_main_main_default.init()
style_file_information_btn_1_main_main_default.set_radius(0)
style_file_information_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_file_information_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_file_information_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_information_btn_1_main_main_default.set_bg_opa(0)
style_file_information_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_file_information_btn_1_main_main_default.set_shadow_opa(0)
style_file_information_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_file_information_btn_1_main_main_default.set_border_width(0)
style_file_information_btn_1_main_main_default.set_border_opa(255)

# add style for file_information_btn_1
file_information_btn_1.add_style(style_file_information_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_information_img_1 = lv.img(file_information_cont_1)
file_information_img_1.set_pos(21,17)
file_information_img_1.set_size(36,24)
file_information_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png','rb') as f:
        file_information_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png')
    sys.exit()

file_information_img_1_img = lv.img_dsc_t({
  'data_size': len(file_information_img_1_img_data),
  'header': {'always_zero': 0, 'w': 36, 'h': 24, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': file_information_img_1_img_data
})

file_information_img_1.set_src(file_information_img_1_img)
file_information_img_1.set_pivot(0,0)
file_information_img_1.set_angle(0)
# create style style_file_information_img_1_main_main_default
style_file_information_img_1_main_main_default = lv.style_t()
style_file_information_img_1_main_main_default.init()
style_file_information_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_file_information_img_1_main_main_default.set_img_recolor_opa(0)
style_file_information_img_1_main_main_default.set_img_opa(255)

# add style for file_information_img_1
file_information_img_1.add_style(style_file_information_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_information_label_2 = lv.label(file_information_cont_1)
file_information_label_2.set_pos(90,11)
file_information_label_2.set_size(300,32)
file_information_label_2.set_text("文件详情")
file_information_label_2.set_long_mode(lv.label.LONG.WRAP)
file_information_label_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_file_information_label_2_main_main_default
style_file_information_label_2_main_main_default = lv.style_t()
style_file_information_label_2_main_main_default.init()
style_file_information_label_2_main_main_default.set_radius(0)
style_file_information_label_2_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_file_information_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_file_information_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_information_label_2_main_main_default.set_bg_opa(0)
style_file_information_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_information_label_2_main_main_default.set_text_font(lv.font_simsun_32)
except AttributeError:
    try:
        style_file_information_label_2_main_main_default.set_text_font(lv.font_montserrat_32)
    except AttributeError:
        style_file_information_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_information_label_2_main_main_default.set_text_letter_space(2)
style_file_information_label_2_main_main_default.set_pad_left(0)
style_file_information_label_2_main_main_default.set_pad_right(0)
style_file_information_label_2_main_main_default.set_pad_top(0)
style_file_information_label_2_main_main_default.set_pad_bottom(0)

# add style for file_information_label_2
file_information_label_2.add_style(style_file_information_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_information_label_5 = lv.label(file_information_cont_1)
file_information_label_5.set_pos(29,434)
file_information_label_5.set_size(388,24)
file_information_label_5.set_text("test.gcode")
file_information_label_5.set_long_mode(lv.label.LONG.WRAP)
file_information_label_5.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_information_label_5_main_main_default
style_file_information_label_5_main_main_default = lv.style_t()
style_file_information_label_5_main_main_default.init()
style_file_information_label_5_main_main_default.set_radius(0)
style_file_information_label_5_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_file_information_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_file_information_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_information_label_5_main_main_default.set_bg_opa(0)
style_file_information_label_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_information_label_5_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_information_label_5_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_information_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_information_label_5_main_main_default.set_text_letter_space(2)
style_file_information_label_5_main_main_default.set_pad_left(0)
style_file_information_label_5_main_main_default.set_pad_right(0)
style_file_information_label_5_main_main_default.set_pad_top(0)
style_file_information_label_5_main_main_default.set_pad_bottom(0)

# add style for file_information_label_5
file_information_label_5.add_style(style_file_information_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_information_label_7 = lv.label(file_information_cont_1)
file_information_label_7.set_pos(49,504)
file_information_label_7.set_size(119,24)
file_information_label_7.set_text("202h35m")
file_information_label_7.set_long_mode(lv.label.LONG.WRAP)
file_information_label_7.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_information_label_7_main_main_default
style_file_information_label_7_main_main_default = lv.style_t()
style_file_information_label_7_main_main_default.init()
style_file_information_label_7_main_main_default.set_radius(0)
style_file_information_label_7_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_file_information_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_file_information_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_information_label_7_main_main_default.set_bg_opa(0)
style_file_information_label_7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_information_label_7_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_information_label_7_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_information_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_information_label_7_main_main_default.set_text_letter_space(2)
style_file_information_label_7_main_main_default.set_pad_left(0)
style_file_information_label_7_main_main_default.set_pad_right(0)
style_file_information_label_7_main_main_default.set_pad_top(0)
style_file_information_label_7_main_main_default.set_pad_bottom(0)

# add style for file_information_label_7
file_information_label_7.add_style(style_file_information_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_information_label_8 = lv.label(file_information_cont_1)
file_information_label_8.set_pos(196,504)
file_information_label_8.set_size(101,24)
file_information_label_8.set_text("166g")
file_information_label_8.set_long_mode(lv.label.LONG.WRAP)
file_information_label_8.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_file_information_label_8_main_main_default
style_file_information_label_8_main_main_default = lv.style_t()
style_file_information_label_8_main_main_default.init()
style_file_information_label_8_main_main_default.set_radius(0)
style_file_information_label_8_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_file_information_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_file_information_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_information_label_8_main_main_default.set_bg_opa(0)
style_file_information_label_8_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_information_label_8_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_information_label_8_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_information_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_information_label_8_main_main_default.set_text_letter_space(2)
style_file_information_label_8_main_main_default.set_pad_left(0)
style_file_information_label_8_main_main_default.set_pad_right(0)
style_file_information_label_8_main_main_default.set_pad_top(0)
style_file_information_label_8_main_main_default.set_pad_bottom(0)

# add style for file_information_label_8
file_information_label_8.add_style(style_file_information_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_information_label_9 = lv.label(file_information_cont_1)
file_information_label_9.set_pos(383,504)
file_information_label_9.set_size(72,24)
file_information_label_9.set_text("ABS")
file_information_label_9.set_long_mode(lv.label.LONG.WRAP)
file_information_label_9.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_file_information_label_9_main_main_default
style_file_information_label_9_main_main_default = lv.style_t()
style_file_information_label_9_main_main_default.init()
style_file_information_label_9_main_main_default.set_radius(0)
style_file_information_label_9_main_main_default.set_bg_color(lv.color_make(0xfa,0x5a,0x15))
style_file_information_label_9_main_main_default.set_bg_grad_color(lv.color_make(0xfa,0x5a,0x15))
style_file_information_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_information_label_9_main_main_default.set_bg_opa(255)
style_file_information_label_9_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_information_label_9_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_information_label_9_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_information_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_information_label_9_main_main_default.set_text_letter_space(2)
style_file_information_label_9_main_main_default.set_pad_left(0)
style_file_information_label_9_main_main_default.set_pad_right(0)
style_file_information_label_9_main_main_default.set_pad_top(0)
style_file_information_label_9_main_main_default.set_pad_bottom(0)

# add style for file_information_label_9
file_information_label_9.add_style(style_file_information_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_information_label_6 = lv.label(file_information_cont_1)
file_information_label_6.set_pos(27,485)
file_information_label_6.set_size(426,1)
# create style style_file_information_label_6_main_main_default
style_file_information_label_6_main_main_default = lv.style_t()
style_file_information_label_6_main_main_default.init()
style_file_information_label_6_main_main_default.set_radius(0)
style_file_information_label_6_main_main_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_file_information_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_file_information_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_information_label_6_main_main_default.set_bg_opa(255)
style_file_information_label_6_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_information_label_6_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_information_label_6_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_information_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_information_label_6_main_main_default.set_text_letter_space(0)
style_file_information_label_6_main_main_default.set_pad_left(0)
style_file_information_label_6_main_main_default.set_pad_right(0)
style_file_information_label_6_main_main_default.set_pad_top(0)
style_file_information_label_6_main_main_default.set_pad_bottom(0)

# add style for file_information_label_6
file_information_label_6.add_style(style_file_information_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_information_label_10 = lv.label(file_information_cont_1)
file_information_label_10.set_pos(27,663)
file_information_label_10.set_size(426,1)
# create style style_file_information_label_10_main_main_default
style_file_information_label_10_main_main_default = lv.style_t()
style_file_information_label_10_main_main_default.init()
style_file_information_label_10_main_main_default.set_radius(0)
style_file_information_label_10_main_main_default.set_bg_color(lv.color_make(0x3a,0x3d,0x42))
style_file_information_label_10_main_main_default.set_bg_grad_color(lv.color_make(0x3a,0x3d,0x42))
style_file_information_label_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_information_label_10_main_main_default.set_bg_opa(255)
style_file_information_label_10_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_information_label_10_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_information_label_10_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_information_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_information_label_10_main_main_default.set_text_letter_space(0)
style_file_information_label_10_main_main_default.set_pad_left(0)
style_file_information_label_10_main_main_default.set_pad_right(0)
style_file_information_label_10_main_main_default.set_pad_top(0)
style_file_information_label_10_main_main_default.set_pad_bottom(0)

# add style for file_information_label_10
file_information_label_10.add_style(style_file_information_label_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_file_information_cont_1_main_main_default
style_file_information_cont_1_main_main_default = lv.style_t()
style_file_information_cont_1_main_main_default.init()
style_file_information_cont_1_main_main_default.set_radius(0)
style_file_information_cont_1_main_main_default.set_bg_color(lv.color_make(0x23,0x24,0x26))
style_file_information_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x23,0x24,0x26))
style_file_information_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_information_cont_1_main_main_default.set_bg_opa(255)
style_file_information_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_file_information_cont_1_main_main_default.set_border_width(0)
style_file_information_cont_1_main_main_default.set_border_opa(255)
style_file_information_cont_1_main_main_default.set_pad_left(0)
style_file_information_cont_1_main_main_default.set_pad_right(0)
style_file_information_cont_1_main_main_default.set_pad_top(0)
style_file_information_cont_1_main_main_default.set_pad_bottom(0)

# add style for file_information_cont_1
file_information_cont_1.add_style(style_file_information_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

file_information_cb_1 = lv.checkbox(file_information)
file_information_cb_1.set_pos(30,619)
file_information_cb_1.set_text("自动调平")
# create style style_file_information_cb_1_main_main_default
style_file_information_cb_1_main_main_default = lv.style_t()
style_file_information_cb_1_main_main_default.init()
style_file_information_cb_1_main_main_default.set_radius(6)
style_file_information_cb_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_file_information_cb_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_file_information_cb_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_information_cb_1_main_main_default.set_bg_opa(0)
style_file_information_cb_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_file_information_cb_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_file_information_cb_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_file_information_cb_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_file_information_cb_1_main_main_default.set_text_letter_space(0)

# add style for file_information_cb_1
file_information_cb_1.add_style(style_file_information_cb_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_file_information_cb_1_main_indicator_default
style_file_information_cb_1_main_indicator_default = lv.style_t()
style_file_information_cb_1_main_indicator_default.init()
style_file_information_cb_1_main_indicator_default.set_radius(2)
style_file_information_cb_1_main_indicator_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_file_information_cb_1_main_indicator_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_file_information_cb_1_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_information_cb_1_main_indicator_default.set_bg_opa(255)
style_file_information_cb_1_main_indicator_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_file_information_cb_1_main_indicator_default.set_border_width(0)

# add style for file_information_cb_1
file_information_cb_1.add_style(style_file_information_cb_1_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_file_information_cb_1_main_indicator_checked
style_file_information_cb_1_main_indicator_checked = lv.style_t()
style_file_information_cb_1_main_indicator_checked.init()
style_file_information_cb_1_main_indicator_checked.set_radius(2)
style_file_information_cb_1_main_indicator_checked.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_file_information_cb_1_main_indicator_checked.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_file_information_cb_1_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_file_information_cb_1_main_indicator_checked.set_bg_opa(255)
style_file_information_cb_1_main_indicator_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_file_information_cb_1_main_indicator_checked.set_border_width(0)

# add style for file_information_cb_1
file_information_cb_1.add_style(style_file_information_cb_1_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

settings_systems = lv.obj()
# create style style_settings_systems_main_main_default
style_settings_systems_main_main_default = lv.style_t()
style_settings_systems_main_main_default.init()
style_settings_systems_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_systems_main_main_default.set_bg_opa(0)

# add style for settings_systems
settings_systems.add_style(style_settings_systems_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_tabview_1 = lv.tabview(settings_systems, lv.DIR.TOP, 50)
settings_systems_tabview_1_tab_btns = settings_systems_tabview_1.get_tab_btns()
# create style style_settings_systems_tabview_1_extra_btnm_main_default
style_settings_systems_tabview_1_extra_btnm_main_default = lv.style_t()
style_settings_systems_tabview_1_extra_btnm_main_default.init()
style_settings_systems_tabview_1_extra_btnm_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_systems_tabview_1_extra_btnm_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_systems_tabview_1_extra_btnm_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_tabview_1_extra_btnm_main_default.set_bg_opa(255)
style_settings_systems_tabview_1_extra_btnm_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_systems_tabview_1_extra_btnm_main_default.set_border_width(0)
style_settings_systems_tabview_1_extra_btnm_main_default.set_border_opa(100)
style_settings_systems_tabview_1_extra_btnm_main_default.set_pad_left(0)
style_settings_systems_tabview_1_extra_btnm_main_default.set_pad_right(0)
style_settings_systems_tabview_1_extra_btnm_main_default.set_pad_top(0)
style_settings_systems_tabview_1_extra_btnm_main_default.set_pad_bottom(0)

# add style for settings_systems_tabview_1_tab_btns
settings_systems_tabview_1_tab_btns.add_style(style_settings_systems_tabview_1_extra_btnm_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_systems_tabview_1_extra_btnm_items_default
style_settings_systems_tabview_1_extra_btnm_items_default = lv.style_t()
style_settings_systems_tabview_1_extra_btnm_items_default.init()
style_settings_systems_tabview_1_extra_btnm_items_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_settings_systems_tabview_1_extra_btnm_items_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_settings_systems_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_settings_systems_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_16)

# add style for settings_systems_tabview_1_tab_btns
settings_systems_tabview_1_tab_btns.add_style(style_settings_systems_tabview_1_extra_btnm_items_default, lv.PART.ITEMS|lv.STATE.DEFAULT)

# create style style_settings_systems_tabview_1_extra_btnm_items_checked
style_settings_systems_tabview_1_extra_btnm_items_checked = lv.style_t()
style_settings_systems_tabview_1_extra_btnm_items_checked.init()
style_settings_systems_tabview_1_extra_btnm_items_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_systems_tabview_1_extra_btnm_items_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_systems_tabview_1_extra_btnm_items_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_tabview_1_extra_btnm_items_checked.set_bg_opa(60)
style_settings_systems_tabview_1_extra_btnm_items_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_systems_tabview_1_extra_btnm_items_checked.set_border_width(4)
style_settings_systems_tabview_1_extra_btnm_items_checked.set_border_opa(255)
style_settings_systems_tabview_1_extra_btnm_items_checked.set_border_side(lv.BORDER_SIDE.BOTTOM)
style_settings_systems_tabview_1_extra_btnm_items_checked.set_text_color(lv.color_make(0x21,0x95,0xf6))
try:
    style_settings_systems_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_settings_systems_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_settings_systems_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_16)

# add style for settings_systems_tabview_1_tab_btns
settings_systems_tabview_1_tab_btns.add_style(style_settings_systems_tabview_1_extra_btnm_items_checked, lv.PART.ITEMS|lv.STATE.CHECKED)

settings_systems_tabview_1_title1 = settings_systems_tabview_1.add_tab("title1")
settings_systems_tabview_1_title2 = settings_systems_tabview_1.add_tab("title2")
settings_systems_tabview_1_title3 = settings_systems_tabview_1.add_tab("title3")
settings_systems_tabview_1_Title = settings_systems_tabview_1.add_tab("Title")
settings_systems_tabview_1.set_pos(0,0)
settings_systems_tabview_1.set_size(480,720)
# create style style_settings_systems_tabview_1_main_main_default
style_settings_systems_tabview_1_main_main_default = lv.style_t()
style_settings_systems_tabview_1_main_main_default.init()
style_settings_systems_tabview_1_main_main_default.set_bg_color(lv.color_make(0xea,0xef,0xf3))
style_settings_systems_tabview_1_main_main_default.set_bg_grad_color(lv.color_make(0xea,0xef,0xf3))
style_settings_systems_tabview_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_tabview_1_main_main_default.set_bg_opa(255)
style_settings_systems_tabview_1_main_main_default.set_border_color(lv.color_make(0xc0,0xc0,0xc0))
style_settings_systems_tabview_1_main_main_default.set_border_width(0)
style_settings_systems_tabview_1_main_main_default.set_border_opa(100)
style_settings_systems_tabview_1_main_main_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_settings_systems_tabview_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_settings_systems_tabview_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_settings_systems_tabview_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_tabview_1_main_main_default.set_text_letter_space(2)
style_settings_systems_tabview_1_main_main_default.set_text_line_space(16)

# add style for settings_systems_tabview_1
settings_systems_tabview_1.add_style(style_settings_systems_tabview_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_cont_1 = lv.obj(settings_systems)
settings_systems_cont_1.set_pos(0,0)
settings_systems_cont_1.set_size(480,800)
settings_systems_label_2 = lv.label(settings_systems_cont_1)
settings_systems_label_2.set_pos(7,61)
settings_systems_label_2.set_size(460,648)
# create style style_settings_systems_label_2_main_main_default
style_settings_systems_label_2_main_main_default = lv.style_t()
style_settings_systems_label_2_main_main_default.init()
style_settings_systems_label_2_main_main_default.set_radius(0)
style_settings_systems_label_2_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_systems_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_systems_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_label_2_main_main_default.set_bg_opa(255)
style_settings_systems_label_2_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_settings_systems_label_2_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_label_2_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_label_2_main_main_default.set_text_letter_space(0)
style_settings_systems_label_2_main_main_default.set_pad_left(0)
style_settings_systems_label_2_main_main_default.set_pad_right(0)
style_settings_systems_label_2_main_main_default.set_pad_top(0)
style_settings_systems_label_2_main_main_default.set_pad_bottom(0)

# add style for settings_systems_label_2
settings_systems_label_2.add_style(style_settings_systems_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_btn_1 = lv.btn(settings_systems_cont_1)
settings_systems_btn_1.set_pos(425,385)
settings_systems_btn_1.set_size(40,50)
# create style style_settings_systems_btn_1_main_main_default
style_settings_systems_btn_1_main_main_default = lv.style_t()
style_settings_systems_btn_1_main_main_default.init()
style_settings_systems_btn_1_main_main_default.set_radius(0)
style_settings_systems_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_systems_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_systems_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_btn_1_main_main_default.set_bg_opa(0)
style_settings_systems_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_settings_systems_btn_1_main_main_default.set_shadow_opa(0)
style_settings_systems_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_systems_btn_1_main_main_default.set_border_width(0)
style_settings_systems_btn_1_main_main_default.set_border_opa(255)

# add style for settings_systems_btn_1
settings_systems_btn_1.add_style(style_settings_systems_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_btn_2 = lv.btn(settings_systems_cont_1)
settings_systems_btn_2.set_pos(425,539)
settings_systems_btn_2.set_size(40,50)
# create style style_settings_systems_btn_2_main_main_default
style_settings_systems_btn_2_main_main_default = lv.style_t()
style_settings_systems_btn_2_main_main_default.init()
style_settings_systems_btn_2_main_main_default.set_radius(0)
style_settings_systems_btn_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_systems_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_systems_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_btn_2_main_main_default.set_bg_opa(0)
style_settings_systems_btn_2_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_settings_systems_btn_2_main_main_default.set_shadow_opa(0)
style_settings_systems_btn_2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_systems_btn_2_main_main_default.set_border_width(0)
style_settings_systems_btn_2_main_main_default.set_border_opa(255)

# add style for settings_systems_btn_2
settings_systems_btn_2.add_style(style_settings_systems_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_btn_3 = lv.btn(settings_systems_cont_1)
settings_systems_btn_3.set_pos(426,617)
settings_systems_btn_3.set_size(40,50)
# create style style_settings_systems_btn_3_main_main_default
style_settings_systems_btn_3_main_main_default = lv.style_t()
style_settings_systems_btn_3_main_main_default.init()
style_settings_systems_btn_3_main_main_default.set_radius(0)
style_settings_systems_btn_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_systems_btn_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_systems_btn_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_btn_3_main_main_default.set_bg_opa(0)
style_settings_systems_btn_3_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_settings_systems_btn_3_main_main_default.set_shadow_opa(0)
style_settings_systems_btn_3_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_systems_btn_3_main_main_default.set_border_width(0)
style_settings_systems_btn_3_main_main_default.set_border_opa(255)

# add style for settings_systems_btn_3
settings_systems_btn_3.add_style(style_settings_systems_btn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_img_6 = lv.img(settings_systems_cont_1)
settings_systems_img_6.set_pos(231,87)
settings_systems_img_6.set_size(38,38)
settings_systems_img_6.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-2131954534.png','rb') as f:
        settings_systems_img_6_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-2131954534.png')
    sys.exit()

settings_systems_img_6_img = lv.img_dsc_t({
  'data_size': len(settings_systems_img_6_img_data),
  'header': {'always_zero': 0, 'w': 38, 'h': 38, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_systems_img_6_img_data
})

settings_systems_img_6.set_src(settings_systems_img_6_img)
settings_systems_img_6.set_pivot(0,0)
settings_systems_img_6.set_angle(0)
# create style style_settings_systems_img_6_main_main_default
style_settings_systems_img_6_main_main_default = lv.style_t()
style_settings_systems_img_6_main_main_default.init()
style_settings_systems_img_6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_systems_img_6_main_main_default.set_img_recolor_opa(0)
style_settings_systems_img_6_main_main_default.set_img_opa(255)

# add style for settings_systems_img_6
settings_systems_img_6.add_style(style_settings_systems_img_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_img_8 = lv.img(settings_systems_cont_1)
settings_systems_img_8.set_pos(443,398)
settings_systems_img_8.set_size(14,28)
settings_systems_img_8.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png','rb') as f:
        settings_systems_img_8_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png')
    sys.exit()

settings_systems_img_8_img = lv.img_dsc_t({
  'data_size': len(settings_systems_img_8_img_data),
  'header': {'always_zero': 0, 'w': 14, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_systems_img_8_img_data
})

settings_systems_img_8.set_src(settings_systems_img_8_img)
settings_systems_img_8.set_pivot(0,0)
settings_systems_img_8.set_angle(0)
# create style style_settings_systems_img_8_main_main_default
style_settings_systems_img_8_main_main_default = lv.style_t()
style_settings_systems_img_8_main_main_default.init()
style_settings_systems_img_8_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_systems_img_8_main_main_default.set_img_recolor_opa(0)
style_settings_systems_img_8_main_main_default.set_img_opa(255)

# add style for settings_systems_img_8
settings_systems_img_8.add_style(style_settings_systems_img_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_img_9 = lv.img(settings_systems_cont_1)
settings_systems_img_9.set_pos(443,550)
settings_systems_img_9.set_size(14,28)
settings_systems_img_9.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png','rb') as f:
        settings_systems_img_9_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png')
    sys.exit()

settings_systems_img_9_img = lv.img_dsc_t({
  'data_size': len(settings_systems_img_9_img_data),
  'header': {'always_zero': 0, 'w': 14, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_systems_img_9_img_data
})

settings_systems_img_9.set_src(settings_systems_img_9_img)
settings_systems_img_9.set_pivot(0,0)
settings_systems_img_9.set_angle(0)
# create style style_settings_systems_img_9_main_main_default
style_settings_systems_img_9_main_main_default = lv.style_t()
style_settings_systems_img_9_main_main_default.init()
style_settings_systems_img_9_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_systems_img_9_main_main_default.set_img_recolor_opa(0)
style_settings_systems_img_9_main_main_default.set_img_opa(255)

# add style for settings_systems_img_9
settings_systems_img_9.add_style(style_settings_systems_img_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_img_10 = lv.img(settings_systems_cont_1)
settings_systems_img_10.set_pos(443,626)
settings_systems_img_10.set_size(14,28)
settings_systems_img_10.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png','rb') as f:
        settings_systems_img_10_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png')
    sys.exit()

settings_systems_img_10_img = lv.img_dsc_t({
  'data_size': len(settings_systems_img_10_img_data),
  'header': {'always_zero': 0, 'w': 14, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_systems_img_10_img_data
})

settings_systems_img_10.set_src(settings_systems_img_10_img)
settings_systems_img_10.set_pivot(0,0)
settings_systems_img_10.set_angle(0)
# create style style_settings_systems_img_10_main_main_default
style_settings_systems_img_10_main_main_default = lv.style_t()
style_settings_systems_img_10_main_main_default.init()
style_settings_systems_img_10_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_systems_img_10_main_main_default.set_img_recolor_opa(0)
style_settings_systems_img_10_main_main_default.set_img_opa(255)

# add style for settings_systems_img_10
settings_systems_img_10.add_style(style_settings_systems_img_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_img_7 = lv.img(settings_systems_cont_1)
settings_systems_img_7.set_pos(424,87)
settings_systems_img_7.set_size(38,38)
settings_systems_img_7.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-931143092.png','rb') as f:
        settings_systems_img_7_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-931143092.png')
    sys.exit()

settings_systems_img_7_img = lv.img_dsc_t({
  'data_size': len(settings_systems_img_7_img_data),
  'header': {'always_zero': 0, 'w': 38, 'h': 38, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_systems_img_7_img_data
})

settings_systems_img_7.set_src(settings_systems_img_7_img)
settings_systems_img_7.set_pivot(0,0)
settings_systems_img_7.set_angle(0)
# create style style_settings_systems_img_7_main_main_default
style_settings_systems_img_7_main_main_default = lv.style_t()
style_settings_systems_img_7_main_main_default.init()
style_settings_systems_img_7_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_systems_img_7_main_main_default.set_img_recolor_opa(0)
style_settings_systems_img_7_main_main_default.set_img_opa(255)

# add style for settings_systems_img_7
settings_systems_img_7.add_style(style_settings_systems_img_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_label_3 = lv.label(settings_systems_cont_1)
settings_systems_label_3.set_pos(25,88)
settings_systems_label_3.set_size(186,24)
settings_systems_label_3.set_text("屏幕亮度")
settings_systems_label_3.set_long_mode(lv.label.LONG.WRAP)
settings_systems_label_3.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_settings_systems_label_3_main_main_default
style_settings_systems_label_3_main_main_default = lv.style_t()
style_settings_systems_label_3_main_main_default.init()
style_settings_systems_label_3_main_main_default.set_radius(0)
style_settings_systems_label_3_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_systems_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_systems_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_label_3_main_main_default.set_bg_opa(0)
style_settings_systems_label_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_label_3_main_main_default.set_text_letter_space(0)
style_settings_systems_label_3_main_main_default.set_pad_left(0)
style_settings_systems_label_3_main_main_default.set_pad_right(0)
style_settings_systems_label_3_main_main_default.set_pad_top(0)
style_settings_systems_label_3_main_main_default.set_pad_bottom(0)

# add style for settings_systems_label_3
settings_systems_label_3.add_style(style_settings_systems_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_label_4 = lv.label(settings_systems_cont_1)
settings_systems_label_4.set_pos(25,164)
settings_systems_label_4.set_size(132,24)
settings_systems_label_4.set_text("息屏")
settings_systems_label_4.set_long_mode(lv.label.LONG.WRAP)
settings_systems_label_4.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_settings_systems_label_4_main_main_default
style_settings_systems_label_4_main_main_default = lv.style_t()
style_settings_systems_label_4_main_main_default.init()
style_settings_systems_label_4_main_main_default.set_radius(0)
style_settings_systems_label_4_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_systems_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_systems_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_label_4_main_main_default.set_bg_opa(0)
style_settings_systems_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_label_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_label_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_label_4_main_main_default.set_text_letter_space(0)
style_settings_systems_label_4_main_main_default.set_pad_left(0)
style_settings_systems_label_4_main_main_default.set_pad_right(0)
style_settings_systems_label_4_main_main_default.set_pad_top(0)
style_settings_systems_label_4_main_main_default.set_pad_bottom(0)

# add style for settings_systems_label_4
settings_systems_label_4.add_style(style_settings_systems_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_label_5 = lv.label(settings_systems_cont_1)
settings_systems_label_5.set_pos(25,240)
settings_systems_label_5.set_size(176,24)
settings_systems_label_5.set_text("语言选择")
settings_systems_label_5.set_long_mode(lv.label.LONG.WRAP)
settings_systems_label_5.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_settings_systems_label_5_main_main_default
style_settings_systems_label_5_main_main_default = lv.style_t()
style_settings_systems_label_5_main_main_default.init()
style_settings_systems_label_5_main_main_default.set_radius(0)
style_settings_systems_label_5_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_systems_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_systems_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_label_5_main_main_default.set_bg_opa(0)
style_settings_systems_label_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_label_5_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_label_5_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_label_5_main_main_default.set_text_letter_space(0)
style_settings_systems_label_5_main_main_default.set_pad_left(0)
style_settings_systems_label_5_main_main_default.set_pad_right(0)
style_settings_systems_label_5_main_main_default.set_pad_top(0)
style_settings_systems_label_5_main_main_default.set_pad_bottom(0)

# add style for settings_systems_label_5
settings_systems_label_5.add_style(style_settings_systems_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_label_6 = lv.label(settings_systems_cont_1)
settings_systems_label_6.set_pos(25,316)
settings_systems_label_6.set_size(176,24)
settings_systems_label_6.set_text("语言选择")
settings_systems_label_6.set_long_mode(lv.label.LONG.WRAP)
settings_systems_label_6.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_settings_systems_label_6_main_main_default
style_settings_systems_label_6_main_main_default = lv.style_t()
style_settings_systems_label_6_main_main_default.init()
style_settings_systems_label_6_main_main_default.set_radius(0)
style_settings_systems_label_6_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_systems_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_systems_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_label_6_main_main_default.set_bg_opa(0)
style_settings_systems_label_6_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_label_6_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_label_6_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_label_6_main_main_default.set_text_letter_space(0)
style_settings_systems_label_6_main_main_default.set_pad_left(0)
style_settings_systems_label_6_main_main_default.set_pad_right(0)
style_settings_systems_label_6_main_main_default.set_pad_top(0)
style_settings_systems_label_6_main_main_default.set_pad_bottom(0)

# add style for settings_systems_label_6
settings_systems_label_6.add_style(style_settings_systems_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_label_7 = lv.label(settings_systems_cont_1)
settings_systems_label_7.set_pos(25,392)
settings_systems_label_7.set_size(176,24)
settings_systems_label_7.set_text("按键音")
settings_systems_label_7.set_long_mode(lv.label.LONG.WRAP)
settings_systems_label_7.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_settings_systems_label_7_main_main_default
style_settings_systems_label_7_main_main_default = lv.style_t()
style_settings_systems_label_7_main_main_default.init()
style_settings_systems_label_7_main_main_default.set_radius(0)
style_settings_systems_label_7_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_systems_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_systems_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_label_7_main_main_default.set_bg_opa(0)
style_settings_systems_label_7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_label_7_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_label_7_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_label_7_main_main_default.set_text_letter_space(0)
style_settings_systems_label_7_main_main_default.set_pad_left(0)
style_settings_systems_label_7_main_main_default.set_pad_right(0)
style_settings_systems_label_7_main_main_default.set_pad_top(0)
style_settings_systems_label_7_main_main_default.set_pad_bottom(0)

# add style for settings_systems_label_7
settings_systems_label_7.add_style(style_settings_systems_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_label_8 = lv.label(settings_systems_cont_1)
settings_systems_label_8.set_pos(25,468)
settings_systems_label_8.set_size(176,24)
settings_systems_label_8.set_text("主题")
settings_systems_label_8.set_long_mode(lv.label.LONG.WRAP)
settings_systems_label_8.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_settings_systems_label_8_main_main_default
style_settings_systems_label_8_main_main_default = lv.style_t()
style_settings_systems_label_8_main_main_default.init()
style_settings_systems_label_8_main_main_default.set_radius(0)
style_settings_systems_label_8_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_systems_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_systems_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_label_8_main_main_default.set_bg_opa(0)
style_settings_systems_label_8_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_label_8_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_label_8_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_label_8_main_main_default.set_text_letter_space(0)
style_settings_systems_label_8_main_main_default.set_pad_left(0)
style_settings_systems_label_8_main_main_default.set_pad_right(0)
style_settings_systems_label_8_main_main_default.set_pad_top(0)
style_settings_systems_label_8_main_main_default.set_pad_bottom(0)

# add style for settings_systems_label_8
settings_systems_label_8.add_style(style_settings_systems_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_label_9 = lv.label(settings_systems_cont_1)
settings_systems_label_9.set_pos(25,544)
settings_systems_label_9.set_size(176,24)
settings_systems_label_9.set_text("设备绑定")
settings_systems_label_9.set_long_mode(lv.label.LONG.WRAP)
settings_systems_label_9.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_settings_systems_label_9_main_main_default
style_settings_systems_label_9_main_main_default = lv.style_t()
style_settings_systems_label_9_main_main_default.init()
style_settings_systems_label_9_main_main_default.set_radius(0)
style_settings_systems_label_9_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_systems_label_9_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_systems_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_label_9_main_main_default.set_bg_opa(0)
style_settings_systems_label_9_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_label_9_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_label_9_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_label_9_main_main_default.set_text_letter_space(0)
style_settings_systems_label_9_main_main_default.set_pad_left(0)
style_settings_systems_label_9_main_main_default.set_pad_right(0)
style_settings_systems_label_9_main_main_default.set_pad_top(0)
style_settings_systems_label_9_main_main_default.set_pad_bottom(0)

# add style for settings_systems_label_9
settings_systems_label_9.add_style(style_settings_systems_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_label_10 = lv.label(settings_systems_cont_1)
settings_systems_label_10.set_pos(25,620)
settings_systems_label_10.set_size(176,24)
settings_systems_label_10.set_text("导出日志")
settings_systems_label_10.set_long_mode(lv.label.LONG.WRAP)
settings_systems_label_10.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_settings_systems_label_10_main_main_default
style_settings_systems_label_10_main_main_default = lv.style_t()
style_settings_systems_label_10_main_main_default.init()
style_settings_systems_label_10_main_main_default.set_radius(0)
style_settings_systems_label_10_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_systems_label_10_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_systems_label_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_label_10_main_main_default.set_bg_opa(0)
style_settings_systems_label_10_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_label_10_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_label_10_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_label_10_main_main_default.set_text_letter_space(0)
style_settings_systems_label_10_main_main_default.set_pad_left(0)
style_settings_systems_label_10_main_main_default.set_pad_right(0)
style_settings_systems_label_10_main_main_default.set_pad_top(0)
style_settings_systems_label_10_main_main_default.set_pad_bottom(0)

# add style for settings_systems_label_10
settings_systems_label_10.add_style(style_settings_systems_label_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_label_1 = lv.label(settings_systems_cont_1)
settings_systems_label_1.set_pos(0,719)
settings_systems_label_1.set_size(480,80)
# create style style_settings_systems_label_1_main_main_default
style_settings_systems_label_1_main_main_default = lv.style_t()
style_settings_systems_label_1_main_main_default.init()
style_settings_systems_label_1_main_main_default.set_radius(0)
style_settings_systems_label_1_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_settings_systems_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_settings_systems_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_label_1_main_main_default.set_bg_opa(255)
style_settings_systems_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_label_1_main_main_default.set_text_letter_space(0)
style_settings_systems_label_1_main_main_default.set_pad_left(0)
style_settings_systems_label_1_main_main_default.set_pad_right(0)
style_settings_systems_label_1_main_main_default.set_pad_top(0)
style_settings_systems_label_1_main_main_default.set_pad_bottom(0)

# add style for settings_systems_label_1
settings_systems_label_1.add_style(style_settings_systems_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_img_1 = lv.img(settings_systems_cont_1)
settings_systems_img_1.set_pos(30,742)
settings_systems_img_1.set_size(48,48)
settings_systems_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png','rb') as f:
        settings_systems_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png')
    sys.exit()

settings_systems_img_1_img = lv.img_dsc_t({
  'data_size': len(settings_systems_img_1_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_systems_img_1_img_data
})

settings_systems_img_1.set_src(settings_systems_img_1_img)
settings_systems_img_1.set_pivot(0,0)
settings_systems_img_1.set_angle(0)
# create style style_settings_systems_img_1_main_main_default
style_settings_systems_img_1_main_main_default = lv.style_t()
style_settings_systems_img_1_main_main_default.init()
style_settings_systems_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_systems_img_1_main_main_default.set_img_recolor_opa(0)
style_settings_systems_img_1_main_main_default.set_img_opa(255)

# add style for settings_systems_img_1
settings_systems_img_1.add_style(style_settings_systems_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_img_2 = lv.img(settings_systems_cont_1)
settings_systems_img_2.set_pos(128,742)
settings_systems_img_2.set_size(48,48)
settings_systems_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png','rb') as f:
        settings_systems_img_2_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png')
    sys.exit()

settings_systems_img_2_img = lv.img_dsc_t({
  'data_size': len(settings_systems_img_2_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_systems_img_2_img_data
})

settings_systems_img_2.set_src(settings_systems_img_2_img)
settings_systems_img_2.set_pivot(0,0)
settings_systems_img_2.set_angle(0)
# create style style_settings_systems_img_2_main_main_default
style_settings_systems_img_2_main_main_default = lv.style_t()
style_settings_systems_img_2_main_main_default.init()
style_settings_systems_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_systems_img_2_main_main_default.set_img_recolor_opa(0)
style_settings_systems_img_2_main_main_default.set_img_opa(255)

# add style for settings_systems_img_2
settings_systems_img_2.add_style(style_settings_systems_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_img_3 = lv.img(settings_systems_cont_1)
settings_systems_img_3.set_pos(224,742)
settings_systems_img_3.set_size(48,48)
settings_systems_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png','rb') as f:
        settings_systems_img_3_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png')
    sys.exit()

settings_systems_img_3_img = lv.img_dsc_t({
  'data_size': len(settings_systems_img_3_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_systems_img_3_img_data
})

settings_systems_img_3.set_src(settings_systems_img_3_img)
settings_systems_img_3.set_pivot(0,0)
settings_systems_img_3.set_angle(0)
# create style style_settings_systems_img_3_main_main_default
style_settings_systems_img_3_main_main_default = lv.style_t()
style_settings_systems_img_3_main_main_default.init()
style_settings_systems_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_systems_img_3_main_main_default.set_img_recolor_opa(0)
style_settings_systems_img_3_main_main_default.set_img_opa(255)

# add style for settings_systems_img_3
settings_systems_img_3.add_style(style_settings_systems_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_img_4 = lv.img(settings_systems_cont_1)
settings_systems_img_4.set_pos(318,742)
settings_systems_img_4.set_size(48,48)
settings_systems_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png','rb') as f:
        settings_systems_img_4_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png')
    sys.exit()

settings_systems_img_4_img = lv.img_dsc_t({
  'data_size': len(settings_systems_img_4_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_systems_img_4_img_data
})

settings_systems_img_4.set_src(settings_systems_img_4_img)
settings_systems_img_4.set_pivot(0,0)
settings_systems_img_4.set_angle(0)
# create style style_settings_systems_img_4_main_main_default
style_settings_systems_img_4_main_main_default = lv.style_t()
style_settings_systems_img_4_main_main_default.init()
style_settings_systems_img_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_systems_img_4_main_main_default.set_img_recolor_opa(0)
style_settings_systems_img_4_main_main_default.set_img_opa(255)

# add style for settings_systems_img_4
settings_systems_img_4.add_style(style_settings_systems_img_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_img_5 = lv.img(settings_systems_cont_1)
settings_systems_img_5.set_pos(414,742)
settings_systems_img_5.set_size(48,48)
settings_systems_img_5.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png','rb') as f:
        settings_systems_img_5_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png')
    sys.exit()

settings_systems_img_5_img = lv.img_dsc_t({
  'data_size': len(settings_systems_img_5_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_systems_img_5_img_data
})

settings_systems_img_5.set_src(settings_systems_img_5_img)
settings_systems_img_5.set_pivot(0,0)
settings_systems_img_5.set_angle(0)
# create style style_settings_systems_img_5_main_main_default
style_settings_systems_img_5_main_main_default = lv.style_t()
style_settings_systems_img_5_main_main_default.init()
style_settings_systems_img_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_systems_img_5_main_main_default.set_img_recolor_opa(0)
style_settings_systems_img_5_main_main_default.set_img_opa(255)

# add style for settings_systems_img_5
settings_systems_img_5.add_style(style_settings_systems_img_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_systems_cont_1_main_main_default
style_settings_systems_cont_1_main_main_default = lv.style_t()
style_settings_systems_cont_1_main_main_default.init()
style_settings_systems_cont_1_main_main_default.set_radius(0)
style_settings_systems_cont_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_settings_systems_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_settings_systems_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_cont_1_main_main_default.set_bg_opa(255)
style_settings_systems_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_systems_cont_1_main_main_default.set_border_width(0)
style_settings_systems_cont_1_main_main_default.set_border_opa(255)
style_settings_systems_cont_1_main_main_default.set_pad_left(0)
style_settings_systems_cont_1_main_main_default.set_pad_right(0)
style_settings_systems_cont_1_main_main_default.set_pad_top(0)
style_settings_systems_cont_1_main_main_default.set_pad_bottom(0)

# add style for settings_systems_cont_1
settings_systems_cont_1.add_style(style_settings_systems_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_slider_1 = lv.slider(settings_systems)
settings_systems_slider_1.set_pos(275,102)
settings_systems_slider_1.set_size(142,8)
settings_systems_slider_1.set_range(0, 100)
settings_systems_slider_1.set_value(50, False)

# create style style_settings_systems_slider_1_main_main_default
style_settings_systems_slider_1_main_main_default = lv.style_t()
style_settings_systems_slider_1_main_main_default.init()
style_settings_systems_slider_1_main_main_default.set_radius(0)
style_settings_systems_slider_1_main_main_default.set_bg_color(lv.color_make(0x50,0x53,0x5a))
style_settings_systems_slider_1_main_main_default.set_bg_grad_color(lv.color_make(0x50,0x53,0x5a))
style_settings_systems_slider_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_slider_1_main_main_default.set_bg_opa(255)
style_settings_systems_slider_1_main_main_default.set_outline_color(lv.color_make(0x21,0x95,0xf6))
style_settings_systems_slider_1_main_main_default.set_outline_width(0)
style_settings_systems_slider_1_main_main_default.set_outline_opa(255)
style_settings_systems_slider_1_main_main_default.set_pad_left(0)
style_settings_systems_slider_1_main_main_default.set_pad_right(0)
style_settings_systems_slider_1_main_main_default.set_pad_top(0)
style_settings_systems_slider_1_main_main_default.set_pad_bottom(0)

# add style for settings_systems_slider_1
settings_systems_slider_1.add_style(style_settings_systems_slider_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_systems_slider_1_main_indicator_default
style_settings_systems_slider_1_main_indicator_default = lv.style_t()
style_settings_systems_slider_1_main_indicator_default.init()
style_settings_systems_slider_1_main_indicator_default.set_radius(0)
style_settings_systems_slider_1_main_indicator_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_settings_systems_slider_1_main_indicator_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_settings_systems_slider_1_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_slider_1_main_indicator_default.set_bg_opa(255)

# add style for settings_systems_slider_1
settings_systems_slider_1.add_style(style_settings_systems_slider_1_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_settings_systems_slider_1_main_knob_default
style_settings_systems_slider_1_main_knob_default = lv.style_t()
style_settings_systems_slider_1_main_knob_default.init()
style_settings_systems_slider_1_main_knob_default.set_radius(0)
style_settings_systems_slider_1_main_knob_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_systems_slider_1_main_knob_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_systems_slider_1_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_slider_1_main_knob_default.set_bg_opa(255)

# add style for settings_systems_slider_1
settings_systems_slider_1.add_style(style_settings_systems_slider_1_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

settings_systems_ddlist_1 = lv.dropdown(settings_systems)
settings_systems_ddlist_1.set_pos(216,159)
settings_systems_ddlist_1.set_width(242)
settings_systems_ddlist_1.set_options("3分钟\n5分钟\n15分钟\n不设置")
# create style style_settings_systems_ddlist_1_extra_list_selected_default
style_settings_systems_ddlist_1_extra_list_selected_default = lv.style_t()
style_settings_systems_ddlist_1_extra_list_selected_default.init()
style_settings_systems_ddlist_1_extra_list_selected_default.set_radius(0)
style_settings_systems_ddlist_1_extra_list_selected_default.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_settings_systems_ddlist_1_extra_list_selected_default.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_settings_systems_ddlist_1_extra_list_selected_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_ddlist_1_extra_list_selected_default.set_bg_opa(255)
style_settings_systems_ddlist_1_extra_list_selected_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_settings_systems_ddlist_1_extra_list_selected_default.set_border_width(0)
style_settings_systems_ddlist_1_extra_list_selected_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_ddlist_1_extra_list_selected_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_ddlist_1_extra_list_selected_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_ddlist_1_extra_list_selected_default.set_text_font(lv.font_montserrat_16)

def settings_systems_ddlist_1_event_cb(e):
    settings_systems_ddlist_1.get_list().add_style(style_settings_systems_ddlist_1_extra_list_selected_default, lv.PART.SELECTED|lv.STATE.DEFAULT)

settings_systems_ddlist_1.add_event_cb(settings_systems_ddlist_1_event_cb, lv.EVENT.READY, None)

# create style style_settings_systems_ddlist_1_extra_list_main_default
style_settings_systems_ddlist_1_extra_list_main_default = lv.style_t()
style_settings_systems_ddlist_1_extra_list_main_default.init()
style_settings_systems_ddlist_1_extra_list_main_default.set_radius(0)
style_settings_systems_ddlist_1_extra_list_main_default.set_bg_color(lv.color_make(0x3c,0x3e,0x42))
style_settings_systems_ddlist_1_extra_list_main_default.set_bg_grad_color(lv.color_make(0x3c,0x3e,0x42))
style_settings_systems_ddlist_1_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_ddlist_1_extra_list_main_default.set_bg_opa(255)
style_settings_systems_ddlist_1_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_settings_systems_ddlist_1_extra_list_main_default.set_border_width(0)
style_settings_systems_ddlist_1_extra_list_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_ddlist_1_extra_list_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_ddlist_1_extra_list_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_ddlist_1_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_ddlist_1_extra_list_main_default.set_max_height(120)

def settings_systems_ddlist_1_event_cb(e):
    settings_systems_ddlist_1.get_list().add_style(style_settings_systems_ddlist_1_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_ddlist_1.add_event_cb(settings_systems_ddlist_1_event_cb, lv.EVENT.READY, None)

# create style style_settings_systems_ddlist_1_extra_list_scrollbar_default
style_settings_systems_ddlist_1_extra_list_scrollbar_default = lv.style_t()
style_settings_systems_ddlist_1_extra_list_scrollbar_default.init()
style_settings_systems_ddlist_1_extra_list_scrollbar_default.set_radius(0)
style_settings_systems_ddlist_1_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_settings_systems_ddlist_1_extra_list_scrollbar_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_settings_systems_ddlist_1_extra_list_scrollbar_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_ddlist_1_extra_list_scrollbar_default.set_bg_opa(255)

def settings_systems_ddlist_1_event_cb(e):
    settings_systems_ddlist_1.get_list().add_style(style_settings_systems_ddlist_1_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

settings_systems_ddlist_1.add_event_cb(settings_systems_ddlist_1_event_cb, lv.EVENT.READY, None)

# create style style_settings_systems_ddlist_1_main_main_default
style_settings_systems_ddlist_1_main_main_default = lv.style_t()
style_settings_systems_ddlist_1_main_main_default.init()
style_settings_systems_ddlist_1_main_main_default.set_radius(0)
style_settings_systems_ddlist_1_main_main_default.set_bg_color(lv.color_make(0x28,0x29,0x2d))
style_settings_systems_ddlist_1_main_main_default.set_bg_grad_color(lv.color_make(0x28,0x29,0x2d))
style_settings_systems_ddlist_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_ddlist_1_main_main_default.set_bg_opa(255)
style_settings_systems_ddlist_1_main_main_default.set_border_color(lv.color_make(0x4a,0x4e,0x57))
style_settings_systems_ddlist_1_main_main_default.set_border_width(1)
style_settings_systems_ddlist_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_ddlist_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_ddlist_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_ddlist_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_ddlist_1_main_main_default.set_text_line_space(20)

# add style for settings_systems_ddlist_1
settings_systems_ddlist_1.add_style(style_settings_systems_ddlist_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_ddlist_2 = lv.dropdown(settings_systems)
settings_systems_ddlist_2.set_pos(216,234)
settings_systems_ddlist_2.set_width(242)
settings_systems_ddlist_2.set_options("中文")
# create style style_settings_systems_ddlist_2_extra_list_selected_default
style_settings_systems_ddlist_2_extra_list_selected_default = lv.style_t()
style_settings_systems_ddlist_2_extra_list_selected_default.init()
style_settings_systems_ddlist_2_extra_list_selected_default.set_radius(0)
style_settings_systems_ddlist_2_extra_list_selected_default.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_settings_systems_ddlist_2_extra_list_selected_default.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_settings_systems_ddlist_2_extra_list_selected_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_ddlist_2_extra_list_selected_default.set_bg_opa(255)
style_settings_systems_ddlist_2_extra_list_selected_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_settings_systems_ddlist_2_extra_list_selected_default.set_border_width(0)
style_settings_systems_ddlist_2_extra_list_selected_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_ddlist_2_extra_list_selected_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_ddlist_2_extra_list_selected_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_ddlist_2_extra_list_selected_default.set_text_font(lv.font_montserrat_16)

def settings_systems_ddlist_2_event_cb(e):
    settings_systems_ddlist_2.get_list().add_style(style_settings_systems_ddlist_2_extra_list_selected_default, lv.PART.SELECTED|lv.STATE.DEFAULT)

settings_systems_ddlist_2.add_event_cb(settings_systems_ddlist_2_event_cb, lv.EVENT.READY, None)

# create style style_settings_systems_ddlist_2_extra_list_main_default
style_settings_systems_ddlist_2_extra_list_main_default = lv.style_t()
style_settings_systems_ddlist_2_extra_list_main_default.init()
style_settings_systems_ddlist_2_extra_list_main_default.set_radius(0)
style_settings_systems_ddlist_2_extra_list_main_default.set_bg_color(lv.color_make(0x3c,0x3e,0x42))
style_settings_systems_ddlist_2_extra_list_main_default.set_bg_grad_color(lv.color_make(0x3c,0x3e,0x42))
style_settings_systems_ddlist_2_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_ddlist_2_extra_list_main_default.set_bg_opa(255)
style_settings_systems_ddlist_2_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_settings_systems_ddlist_2_extra_list_main_default.set_border_width(0)
style_settings_systems_ddlist_2_extra_list_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_ddlist_2_extra_list_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_ddlist_2_extra_list_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_ddlist_2_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_ddlist_2_extra_list_main_default.set_max_height(120)

def settings_systems_ddlist_2_event_cb(e):
    settings_systems_ddlist_2.get_list().add_style(style_settings_systems_ddlist_2_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_ddlist_2.add_event_cb(settings_systems_ddlist_2_event_cb, lv.EVENT.READY, None)

# create style style_settings_systems_ddlist_2_extra_list_scrollbar_default
style_settings_systems_ddlist_2_extra_list_scrollbar_default = lv.style_t()
style_settings_systems_ddlist_2_extra_list_scrollbar_default.init()
style_settings_systems_ddlist_2_extra_list_scrollbar_default.set_radius(0)
style_settings_systems_ddlist_2_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_settings_systems_ddlist_2_extra_list_scrollbar_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_settings_systems_ddlist_2_extra_list_scrollbar_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_ddlist_2_extra_list_scrollbar_default.set_bg_opa(255)

def settings_systems_ddlist_2_event_cb(e):
    settings_systems_ddlist_2.get_list().add_style(style_settings_systems_ddlist_2_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

settings_systems_ddlist_2.add_event_cb(settings_systems_ddlist_2_event_cb, lv.EVENT.READY, None)

# create style style_settings_systems_ddlist_2_main_main_default
style_settings_systems_ddlist_2_main_main_default = lv.style_t()
style_settings_systems_ddlist_2_main_main_default.init()
style_settings_systems_ddlist_2_main_main_default.set_radius(0)
style_settings_systems_ddlist_2_main_main_default.set_bg_color(lv.color_make(0x28,0x29,0x2d))
style_settings_systems_ddlist_2_main_main_default.set_bg_grad_color(lv.color_make(0x28,0x29,0x2d))
style_settings_systems_ddlist_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_ddlist_2_main_main_default.set_bg_opa(255)
style_settings_systems_ddlist_2_main_main_default.set_border_color(lv.color_make(0x4a,0x4e,0x57))
style_settings_systems_ddlist_2_main_main_default.set_border_width(1)
style_settings_systems_ddlist_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_ddlist_2_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_ddlist_2_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_ddlist_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_ddlist_2_main_main_default.set_text_line_space(20)

# add style for settings_systems_ddlist_2
settings_systems_ddlist_2.add_style(style_settings_systems_ddlist_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_ddlist_3 = lv.dropdown(settings_systems)
settings_systems_ddlist_3.set_pos(216,309)
settings_systems_ddlist_3.set_width(242)
settings_systems_ddlist_3.set_options("中国(大陆)")
# create style style_settings_systems_ddlist_3_extra_list_selected_default
style_settings_systems_ddlist_3_extra_list_selected_default = lv.style_t()
style_settings_systems_ddlist_3_extra_list_selected_default.init()
style_settings_systems_ddlist_3_extra_list_selected_default.set_radius(0)
style_settings_systems_ddlist_3_extra_list_selected_default.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_settings_systems_ddlist_3_extra_list_selected_default.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_settings_systems_ddlist_3_extra_list_selected_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_ddlist_3_extra_list_selected_default.set_bg_opa(255)
style_settings_systems_ddlist_3_extra_list_selected_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_settings_systems_ddlist_3_extra_list_selected_default.set_border_width(0)
style_settings_systems_ddlist_3_extra_list_selected_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_ddlist_3_extra_list_selected_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_ddlist_3_extra_list_selected_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_ddlist_3_extra_list_selected_default.set_text_font(lv.font_montserrat_16)

def settings_systems_ddlist_3_event_cb(e):
    settings_systems_ddlist_3.get_list().add_style(style_settings_systems_ddlist_3_extra_list_selected_default, lv.PART.SELECTED|lv.STATE.DEFAULT)

settings_systems_ddlist_3.add_event_cb(settings_systems_ddlist_3_event_cb, lv.EVENT.READY, None)

# create style style_settings_systems_ddlist_3_extra_list_main_default
style_settings_systems_ddlist_3_extra_list_main_default = lv.style_t()
style_settings_systems_ddlist_3_extra_list_main_default.init()
style_settings_systems_ddlist_3_extra_list_main_default.set_radius(0)
style_settings_systems_ddlist_3_extra_list_main_default.set_bg_color(lv.color_make(0x3c,0x3e,0x42))
style_settings_systems_ddlist_3_extra_list_main_default.set_bg_grad_color(lv.color_make(0x3c,0x3e,0x42))
style_settings_systems_ddlist_3_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_ddlist_3_extra_list_main_default.set_bg_opa(255)
style_settings_systems_ddlist_3_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_settings_systems_ddlist_3_extra_list_main_default.set_border_width(0)
style_settings_systems_ddlist_3_extra_list_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_ddlist_3_extra_list_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_ddlist_3_extra_list_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_ddlist_3_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_ddlist_3_extra_list_main_default.set_max_height(120)

def settings_systems_ddlist_3_event_cb(e):
    settings_systems_ddlist_3.get_list().add_style(style_settings_systems_ddlist_3_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_ddlist_3.add_event_cb(settings_systems_ddlist_3_event_cb, lv.EVENT.READY, None)

# create style style_settings_systems_ddlist_3_extra_list_scrollbar_default
style_settings_systems_ddlist_3_extra_list_scrollbar_default = lv.style_t()
style_settings_systems_ddlist_3_extra_list_scrollbar_default.init()
style_settings_systems_ddlist_3_extra_list_scrollbar_default.set_radius(0)
style_settings_systems_ddlist_3_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_settings_systems_ddlist_3_extra_list_scrollbar_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_settings_systems_ddlist_3_extra_list_scrollbar_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_ddlist_3_extra_list_scrollbar_default.set_bg_opa(255)

def settings_systems_ddlist_3_event_cb(e):
    settings_systems_ddlist_3.get_list().add_style(style_settings_systems_ddlist_3_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

settings_systems_ddlist_3.add_event_cb(settings_systems_ddlist_3_event_cb, lv.EVENT.READY, None)

# create style style_settings_systems_ddlist_3_main_main_default
style_settings_systems_ddlist_3_main_main_default = lv.style_t()
style_settings_systems_ddlist_3_main_main_default.init()
style_settings_systems_ddlist_3_main_main_default.set_radius(0)
style_settings_systems_ddlist_3_main_main_default.set_bg_color(lv.color_make(0x28,0x29,0x2d))
style_settings_systems_ddlist_3_main_main_default.set_bg_grad_color(lv.color_make(0x28,0x29,0x2d))
style_settings_systems_ddlist_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_ddlist_3_main_main_default.set_bg_opa(255)
style_settings_systems_ddlist_3_main_main_default.set_border_color(lv.color_make(0x4a,0x4e,0x57))
style_settings_systems_ddlist_3_main_main_default.set_border_width(1)
style_settings_systems_ddlist_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_ddlist_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_ddlist_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_ddlist_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_ddlist_3_main_main_default.set_text_line_space(20)

# add style for settings_systems_ddlist_3
settings_systems_ddlist_3.add_style(style_settings_systems_ddlist_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_ddlist_4 = lv.dropdown(settings_systems)
settings_systems_ddlist_4.set_pos(216,461)
settings_systems_ddlist_4.set_width(242)
settings_systems_ddlist_4.set_options("主题一")
# create style style_settings_systems_ddlist_4_extra_list_selected_default
style_settings_systems_ddlist_4_extra_list_selected_default = lv.style_t()
style_settings_systems_ddlist_4_extra_list_selected_default.init()
style_settings_systems_ddlist_4_extra_list_selected_default.set_radius(0)
style_settings_systems_ddlist_4_extra_list_selected_default.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_settings_systems_ddlist_4_extra_list_selected_default.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_settings_systems_ddlist_4_extra_list_selected_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_ddlist_4_extra_list_selected_default.set_bg_opa(255)
style_settings_systems_ddlist_4_extra_list_selected_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_settings_systems_ddlist_4_extra_list_selected_default.set_border_width(0)
style_settings_systems_ddlist_4_extra_list_selected_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_ddlist_4_extra_list_selected_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_ddlist_4_extra_list_selected_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_ddlist_4_extra_list_selected_default.set_text_font(lv.font_montserrat_16)

def settings_systems_ddlist_4_event_cb(e):
    settings_systems_ddlist_4.get_list().add_style(style_settings_systems_ddlist_4_extra_list_selected_default, lv.PART.SELECTED|lv.STATE.DEFAULT)

settings_systems_ddlist_4.add_event_cb(settings_systems_ddlist_4_event_cb, lv.EVENT.READY, None)

# create style style_settings_systems_ddlist_4_extra_list_main_default
style_settings_systems_ddlist_4_extra_list_main_default = lv.style_t()
style_settings_systems_ddlist_4_extra_list_main_default.init()
style_settings_systems_ddlist_4_extra_list_main_default.set_radius(0)
style_settings_systems_ddlist_4_extra_list_main_default.set_bg_color(lv.color_make(0x3c,0x3e,0x42))
style_settings_systems_ddlist_4_extra_list_main_default.set_bg_grad_color(lv.color_make(0x3c,0x3e,0x42))
style_settings_systems_ddlist_4_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_ddlist_4_extra_list_main_default.set_bg_opa(255)
style_settings_systems_ddlist_4_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_settings_systems_ddlist_4_extra_list_main_default.set_border_width(0)
style_settings_systems_ddlist_4_extra_list_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_ddlist_4_extra_list_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_ddlist_4_extra_list_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_ddlist_4_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_ddlist_4_extra_list_main_default.set_max_height(120)

def settings_systems_ddlist_4_event_cb(e):
    settings_systems_ddlist_4.get_list().add_style(style_settings_systems_ddlist_4_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_systems_ddlist_4.add_event_cb(settings_systems_ddlist_4_event_cb, lv.EVENT.READY, None)

# create style style_settings_systems_ddlist_4_extra_list_scrollbar_default
style_settings_systems_ddlist_4_extra_list_scrollbar_default = lv.style_t()
style_settings_systems_ddlist_4_extra_list_scrollbar_default.init()
style_settings_systems_ddlist_4_extra_list_scrollbar_default.set_radius(0)
style_settings_systems_ddlist_4_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_settings_systems_ddlist_4_extra_list_scrollbar_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_settings_systems_ddlist_4_extra_list_scrollbar_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_ddlist_4_extra_list_scrollbar_default.set_bg_opa(255)

def settings_systems_ddlist_4_event_cb(e):
    settings_systems_ddlist_4.get_list().add_style(style_settings_systems_ddlist_4_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

settings_systems_ddlist_4.add_event_cb(settings_systems_ddlist_4_event_cb, lv.EVENT.READY, None)

# create style style_settings_systems_ddlist_4_main_main_default
style_settings_systems_ddlist_4_main_main_default = lv.style_t()
style_settings_systems_ddlist_4_main_main_default.init()
style_settings_systems_ddlist_4_main_main_default.set_radius(0)
style_settings_systems_ddlist_4_main_main_default.set_bg_color(lv.color_make(0x28,0x29,0x2d))
style_settings_systems_ddlist_4_main_main_default.set_bg_grad_color(lv.color_make(0x28,0x29,0x2d))
style_settings_systems_ddlist_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_systems_ddlist_4_main_main_default.set_bg_opa(255)
style_settings_systems_ddlist_4_main_main_default.set_border_color(lv.color_make(0x4a,0x4e,0x57))
style_settings_systems_ddlist_4_main_main_default.set_border_width(1)
style_settings_systems_ddlist_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_systems_ddlist_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_systems_ddlist_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_systems_ddlist_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_systems_ddlist_4_main_main_default.set_text_line_space(20)

# add style for settings_systems_ddlist_4
settings_systems_ddlist_4.add_style(style_settings_systems_ddlist_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

keytone_setting = lv.obj()
# create style style_keytone_setting_main_main_default
style_keytone_setting_main_main_default = lv.style_t()
style_keytone_setting_main_main_default.init()
style_keytone_setting_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_keytone_setting_main_main_default.set_bg_opa(0)

# add style for keytone_setting
keytone_setting.add_style(style_keytone_setting_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

keytone_setting_cont_1 = lv.obj(keytone_setting)
keytone_setting_cont_1.set_pos(0,0)
keytone_setting_cont_1.set_size(480,800)
keytone_setting_label_3 = lv.label(keytone_setting_cont_1)
keytone_setting_label_3.set_pos(8,63)
keytone_setting_label_3.set_size(460,727)
# create style style_keytone_setting_label_3_main_main_default
style_keytone_setting_label_3_main_main_default = lv.style_t()
style_keytone_setting_label_3_main_main_default.init()
style_keytone_setting_label_3_main_main_default.set_radius(0)
style_keytone_setting_label_3_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_keytone_setting_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_keytone_setting_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_keytone_setting_label_3_main_main_default.set_bg_opa(255)
style_keytone_setting_label_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_keytone_setting_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_keytone_setting_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_keytone_setting_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_keytone_setting_label_3_main_main_default.set_text_letter_space(2)
style_keytone_setting_label_3_main_main_default.set_pad_left(0)
style_keytone_setting_label_3_main_main_default.set_pad_right(0)
style_keytone_setting_label_3_main_main_default.set_pad_top(0)
style_keytone_setting_label_3_main_main_default.set_pad_bottom(0)

# add style for keytone_setting_label_3
keytone_setting_label_3.add_style(style_keytone_setting_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

keytone_setting_ddlist_1 = lv.dropdown(keytone_setting_cont_1)
keytone_setting_ddlist_1.set_pos(216,279)
keytone_setting_ddlist_1.set_width(242)
keytone_setting_ddlist_1.set_options("科技\n灵动\n简短\n清脆")
# create style style_keytone_setting_ddlist_1_extra_list_selected_default
style_keytone_setting_ddlist_1_extra_list_selected_default = lv.style_t()
style_keytone_setting_ddlist_1_extra_list_selected_default.init()
style_keytone_setting_ddlist_1_extra_list_selected_default.set_radius(0)
style_keytone_setting_ddlist_1_extra_list_selected_default.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_keytone_setting_ddlist_1_extra_list_selected_default.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_keytone_setting_ddlist_1_extra_list_selected_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_keytone_setting_ddlist_1_extra_list_selected_default.set_bg_opa(255)
style_keytone_setting_ddlist_1_extra_list_selected_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_keytone_setting_ddlist_1_extra_list_selected_default.set_border_width(0)
style_keytone_setting_ddlist_1_extra_list_selected_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_keytone_setting_ddlist_1_extra_list_selected_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_keytone_setting_ddlist_1_extra_list_selected_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_keytone_setting_ddlist_1_extra_list_selected_default.set_text_font(lv.font_montserrat_16)

def keytone_setting_ddlist_1_event_cb(e):
    keytone_setting_ddlist_1.get_list().add_style(style_keytone_setting_ddlist_1_extra_list_selected_default, lv.PART.SELECTED|lv.STATE.DEFAULT)

keytone_setting_ddlist_1.add_event_cb(keytone_setting_ddlist_1_event_cb, lv.EVENT.READY, None)

# create style style_keytone_setting_ddlist_1_extra_list_main_default
style_keytone_setting_ddlist_1_extra_list_main_default = lv.style_t()
style_keytone_setting_ddlist_1_extra_list_main_default.init()
style_keytone_setting_ddlist_1_extra_list_main_default.set_radius(0)
style_keytone_setting_ddlist_1_extra_list_main_default.set_bg_color(lv.color_make(0x3c,0x3e,0x42))
style_keytone_setting_ddlist_1_extra_list_main_default.set_bg_grad_color(lv.color_make(0x3c,0x3e,0x42))
style_keytone_setting_ddlist_1_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_keytone_setting_ddlist_1_extra_list_main_default.set_bg_opa(255)
style_keytone_setting_ddlist_1_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_keytone_setting_ddlist_1_extra_list_main_default.set_border_width(0)
style_keytone_setting_ddlist_1_extra_list_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_keytone_setting_ddlist_1_extra_list_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_keytone_setting_ddlist_1_extra_list_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_keytone_setting_ddlist_1_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_keytone_setting_ddlist_1_extra_list_main_default.set_max_height(130)

def keytone_setting_ddlist_1_event_cb(e):
    keytone_setting_ddlist_1.get_list().add_style(style_keytone_setting_ddlist_1_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

keytone_setting_ddlist_1.add_event_cb(keytone_setting_ddlist_1_event_cb, lv.EVENT.READY, None)

# create style style_keytone_setting_ddlist_1_extra_list_scrollbar_default
style_keytone_setting_ddlist_1_extra_list_scrollbar_default = lv.style_t()
style_keytone_setting_ddlist_1_extra_list_scrollbar_default.init()
style_keytone_setting_ddlist_1_extra_list_scrollbar_default.set_radius(3)
style_keytone_setting_ddlist_1_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x00,0xff,0x00))
style_keytone_setting_ddlist_1_extra_list_scrollbar_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_keytone_setting_ddlist_1_extra_list_scrollbar_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_keytone_setting_ddlist_1_extra_list_scrollbar_default.set_bg_opa(0)

def keytone_setting_ddlist_1_event_cb(e):
    keytone_setting_ddlist_1.get_list().add_style(style_keytone_setting_ddlist_1_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

keytone_setting_ddlist_1.add_event_cb(keytone_setting_ddlist_1_event_cb, lv.EVENT.READY, None)

# create style style_keytone_setting_ddlist_1_main_main_default
style_keytone_setting_ddlist_1_main_main_default = lv.style_t()
style_keytone_setting_ddlist_1_main_main_default.init()
style_keytone_setting_ddlist_1_main_main_default.set_radius(0)
style_keytone_setting_ddlist_1_main_main_default.set_bg_color(lv.color_make(0x28,0x29,0x2d))
style_keytone_setting_ddlist_1_main_main_default.set_bg_grad_color(lv.color_make(0x28,0x29,0x2d))
style_keytone_setting_ddlist_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_keytone_setting_ddlist_1_main_main_default.set_bg_opa(255)
style_keytone_setting_ddlist_1_main_main_default.set_border_color(lv.color_make(0x4a,0x4e,0x57))
style_keytone_setting_ddlist_1_main_main_default.set_border_width(1)
style_keytone_setting_ddlist_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_keytone_setting_ddlist_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_keytone_setting_ddlist_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_keytone_setting_ddlist_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_keytone_setting_ddlist_1_main_main_default.set_text_line_space(20)

# add style for keytone_setting_ddlist_1
keytone_setting_ddlist_1.add_style(style_keytone_setting_ddlist_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

keytone_setting_label_4 = lv.label(keytone_setting_cont_1)
keytone_setting_label_4.set_pos(26,100)
keytone_setting_label_4.set_size(308,24)
keytone_setting_label_4.set_text("按键音开关")
keytone_setting_label_4.set_long_mode(lv.label.LONG.WRAP)
keytone_setting_label_4.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_keytone_setting_label_4_main_main_default
style_keytone_setting_label_4_main_main_default = lv.style_t()
style_keytone_setting_label_4_main_main_default.init()
style_keytone_setting_label_4_main_main_default.set_radius(0)
style_keytone_setting_label_4_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_keytone_setting_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_keytone_setting_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_keytone_setting_label_4_main_main_default.set_bg_opa(0)
style_keytone_setting_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_keytone_setting_label_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_keytone_setting_label_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_keytone_setting_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_keytone_setting_label_4_main_main_default.set_text_letter_space(1)
style_keytone_setting_label_4_main_main_default.set_pad_left(0)
style_keytone_setting_label_4_main_main_default.set_pad_right(0)
style_keytone_setting_label_4_main_main_default.set_pad_top(0)
style_keytone_setting_label_4_main_main_default.set_pad_bottom(0)

# add style for keytone_setting_label_4
keytone_setting_label_4.add_style(style_keytone_setting_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

keytone_setting_slider_1 = lv.slider(keytone_setting_cont_1)
keytone_setting_slider_1.set_pos(249,205)
keytone_setting_slider_1.set_size(160,8)
keytone_setting_slider_1.set_range(0, 100)
keytone_setting_slider_1.set_value(50, False)

# create style style_keytone_setting_slider_1_main_main_default
style_keytone_setting_slider_1_main_main_default = lv.style_t()
style_keytone_setting_slider_1_main_main_default.init()
style_keytone_setting_slider_1_main_main_default.set_radius(50)
style_keytone_setting_slider_1_main_main_default.set_bg_color(lv.color_make(0x50,0x53,0x5a))
style_keytone_setting_slider_1_main_main_default.set_bg_grad_color(lv.color_make(0x50,0x53,0x5a))
style_keytone_setting_slider_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_keytone_setting_slider_1_main_main_default.set_bg_opa(255)
style_keytone_setting_slider_1_main_main_default.set_outline_color(lv.color_make(0x21,0x95,0xf6))
style_keytone_setting_slider_1_main_main_default.set_outline_width(0)
style_keytone_setting_slider_1_main_main_default.set_outline_opa(255)
style_keytone_setting_slider_1_main_main_default.set_pad_left(0)
style_keytone_setting_slider_1_main_main_default.set_pad_right(0)
style_keytone_setting_slider_1_main_main_default.set_pad_top(0)
style_keytone_setting_slider_1_main_main_default.set_pad_bottom(0)

# add style for keytone_setting_slider_1
keytone_setting_slider_1.add_style(style_keytone_setting_slider_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_keytone_setting_slider_1_main_indicator_default
style_keytone_setting_slider_1_main_indicator_default = lv.style_t()
style_keytone_setting_slider_1_main_indicator_default.init()
style_keytone_setting_slider_1_main_indicator_default.set_radius(0)
style_keytone_setting_slider_1_main_indicator_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_keytone_setting_slider_1_main_indicator_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_keytone_setting_slider_1_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_keytone_setting_slider_1_main_indicator_default.set_bg_opa(255)

# add style for keytone_setting_slider_1
keytone_setting_slider_1.add_style(style_keytone_setting_slider_1_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_keytone_setting_slider_1_main_knob_default
style_keytone_setting_slider_1_main_knob_default = lv.style_t()
style_keytone_setting_slider_1_main_knob_default.init()
style_keytone_setting_slider_1_main_knob_default.set_radius(0)
style_keytone_setting_slider_1_main_knob_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_keytone_setting_slider_1_main_knob_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_keytone_setting_slider_1_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_keytone_setting_slider_1_main_knob_default.set_bg_opa(255)

# add style for keytone_setting_slider_1
keytone_setting_slider_1.add_style(style_keytone_setting_slider_1_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

keytone_setting_label_5 = lv.label(keytone_setting_cont_1)
keytone_setting_label_5.set_pos(26,193)
keytone_setting_label_5.set_size(181,24)
keytone_setting_label_5.set_text("音量")
keytone_setting_label_5.set_long_mode(lv.label.LONG.WRAP)
keytone_setting_label_5.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_keytone_setting_label_5_main_main_default
style_keytone_setting_label_5_main_main_default = lv.style_t()
style_keytone_setting_label_5_main_main_default.init()
style_keytone_setting_label_5_main_main_default.set_radius(0)
style_keytone_setting_label_5_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_keytone_setting_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_keytone_setting_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_keytone_setting_label_5_main_main_default.set_bg_opa(0)
style_keytone_setting_label_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_keytone_setting_label_5_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_keytone_setting_label_5_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_keytone_setting_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_keytone_setting_label_5_main_main_default.set_text_letter_space(1)
style_keytone_setting_label_5_main_main_default.set_pad_left(0)
style_keytone_setting_label_5_main_main_default.set_pad_right(0)
style_keytone_setting_label_5_main_main_default.set_pad_top(0)
style_keytone_setting_label_5_main_main_default.set_pad_bottom(0)

# add style for keytone_setting_label_5
keytone_setting_label_5.add_style(style_keytone_setting_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

keytone_setting_label_6 = lv.label(keytone_setting_cont_1)
keytone_setting_label_6.set_pos(26,288)
keytone_setting_label_6.set_size(181,24)
keytone_setting_label_6.set_text("音效设置")
keytone_setting_label_6.set_long_mode(lv.label.LONG.WRAP)
keytone_setting_label_6.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_keytone_setting_label_6_main_main_default
style_keytone_setting_label_6_main_main_default = lv.style_t()
style_keytone_setting_label_6_main_main_default.init()
style_keytone_setting_label_6_main_main_default.set_radius(0)
style_keytone_setting_label_6_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_keytone_setting_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_keytone_setting_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_keytone_setting_label_6_main_main_default.set_bg_opa(0)
style_keytone_setting_label_6_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_keytone_setting_label_6_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_keytone_setting_label_6_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_keytone_setting_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_keytone_setting_label_6_main_main_default.set_text_letter_space(1)
style_keytone_setting_label_6_main_main_default.set_pad_left(0)
style_keytone_setting_label_6_main_main_default.set_pad_right(0)
style_keytone_setting_label_6_main_main_default.set_pad_top(0)
style_keytone_setting_label_6_main_main_default.set_pad_bottom(0)

# add style for keytone_setting_label_6
keytone_setting_label_6.add_style(style_keytone_setting_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

keytone_setting_sw_1 = lv.switch(keytone_setting_cont_1)
keytone_setting_sw_1.set_pos(380,93)
keytone_setting_sw_1.set_size(74,36)
# create style style_keytone_setting_sw_1_main_main_default
style_keytone_setting_sw_1_main_main_default = lv.style_t()
style_keytone_setting_sw_1_main_main_default.init()
style_keytone_setting_sw_1_main_main_default.set_radius(100)
style_keytone_setting_sw_1_main_main_default.set_bg_color(lv.color_make(0xe6,0xe2,0xe6))
style_keytone_setting_sw_1_main_main_default.set_bg_grad_color(lv.color_make(0xe6,0xe2,0xe6))
style_keytone_setting_sw_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_keytone_setting_sw_1_main_main_default.set_bg_opa(255)

# add style for keytone_setting_sw_1
keytone_setting_sw_1.add_style(style_keytone_setting_sw_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_keytone_setting_sw_1_main_indicator_checked
style_keytone_setting_sw_1_main_indicator_checked = lv.style_t()
style_keytone_setting_sw_1_main_indicator_checked.init()
style_keytone_setting_sw_1_main_indicator_checked.set_radius(100)
style_keytone_setting_sw_1_main_indicator_checked.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_keytone_setting_sw_1_main_indicator_checked.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_keytone_setting_sw_1_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_keytone_setting_sw_1_main_indicator_checked.set_bg_opa(255)

# add style for keytone_setting_sw_1
keytone_setting_sw_1.add_style(style_keytone_setting_sw_1_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

# create style style_keytone_setting_sw_1_main_knob_default
style_keytone_setting_sw_1_main_knob_default = lv.style_t()
style_keytone_setting_sw_1_main_knob_default.init()
style_keytone_setting_sw_1_main_knob_default.set_radius(100)
style_keytone_setting_sw_1_main_knob_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_keytone_setting_sw_1_main_knob_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_keytone_setting_sw_1_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_keytone_setting_sw_1_main_knob_default.set_bg_opa(255)

# add style for keytone_setting_sw_1
keytone_setting_sw_1.add_style(style_keytone_setting_sw_1_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

keytone_setting_label_1 = lv.label(keytone_setting_cont_1)
keytone_setting_label_1.set_pos(0,0)
keytone_setting_label_1.set_size(480,53)
# create style style_keytone_setting_label_1_main_main_default
style_keytone_setting_label_1_main_main_default = lv.style_t()
style_keytone_setting_label_1_main_main_default.init()
style_keytone_setting_label_1_main_main_default.set_radius(0)
style_keytone_setting_label_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_keytone_setting_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_keytone_setting_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_keytone_setting_label_1_main_main_default.set_bg_opa(255)
style_keytone_setting_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_keytone_setting_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_keytone_setting_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_keytone_setting_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_keytone_setting_label_1_main_main_default.set_text_letter_space(2)
style_keytone_setting_label_1_main_main_default.set_pad_left(0)
style_keytone_setting_label_1_main_main_default.set_pad_right(0)
style_keytone_setting_label_1_main_main_default.set_pad_top(0)
style_keytone_setting_label_1_main_main_default.set_pad_bottom(0)

# add style for keytone_setting_label_1
keytone_setting_label_1.add_style(style_keytone_setting_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

keytone_setting_btn_1 = lv.btn(keytone_setting_cont_1)
keytone_setting_btn_1.set_pos(0,0)
keytone_setting_btn_1.set_size(85,50)
# create style style_keytone_setting_btn_1_main_main_default
style_keytone_setting_btn_1_main_main_default = lv.style_t()
style_keytone_setting_btn_1_main_main_default.init()
style_keytone_setting_btn_1_main_main_default.set_radius(0)
style_keytone_setting_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_keytone_setting_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_keytone_setting_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_keytone_setting_btn_1_main_main_default.set_bg_opa(0)
style_keytone_setting_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_keytone_setting_btn_1_main_main_default.set_shadow_opa(0)
style_keytone_setting_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_keytone_setting_btn_1_main_main_default.set_border_width(0)
style_keytone_setting_btn_1_main_main_default.set_border_opa(255)

# add style for keytone_setting_btn_1
keytone_setting_btn_1.add_style(style_keytone_setting_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

keytone_setting_img_1 = lv.img(keytone_setting_cont_1)
keytone_setting_img_1.set_pos(21,17)
keytone_setting_img_1.set_size(36,24)
keytone_setting_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png','rb') as f:
        keytone_setting_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png')
    sys.exit()

keytone_setting_img_1_img = lv.img_dsc_t({
  'data_size': len(keytone_setting_img_1_img_data),
  'header': {'always_zero': 0, 'w': 36, 'h': 24, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': keytone_setting_img_1_img_data
})

keytone_setting_img_1.set_src(keytone_setting_img_1_img)
keytone_setting_img_1.set_pivot(0,0)
keytone_setting_img_1.set_angle(0)
# create style style_keytone_setting_img_1_main_main_default
style_keytone_setting_img_1_main_main_default = lv.style_t()
style_keytone_setting_img_1_main_main_default.init()
style_keytone_setting_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_keytone_setting_img_1_main_main_default.set_img_recolor_opa(0)
style_keytone_setting_img_1_main_main_default.set_img_opa(255)

# add style for keytone_setting_img_1
keytone_setting_img_1.add_style(style_keytone_setting_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

keytone_setting_img_2 = lv.img(keytone_setting_cont_1)
keytone_setting_img_2.set_pos(216,192)
keytone_setting_img_2.set_size(38,38)
keytone_setting_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp377296655.png','rb') as f:
        keytone_setting_img_2_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp377296655.png')
    sys.exit()

keytone_setting_img_2_img = lv.img_dsc_t({
  'data_size': len(keytone_setting_img_2_img_data),
  'header': {'always_zero': 0, 'w': 38, 'h': 38, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': keytone_setting_img_2_img_data
})

keytone_setting_img_2.set_src(keytone_setting_img_2_img)
keytone_setting_img_2.set_pivot(0,0)
keytone_setting_img_2.set_angle(0)
# create style style_keytone_setting_img_2_main_main_default
style_keytone_setting_img_2_main_main_default = lv.style_t()
style_keytone_setting_img_2_main_main_default.init()
style_keytone_setting_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_keytone_setting_img_2_main_main_default.set_img_recolor_opa(0)
style_keytone_setting_img_2_main_main_default.set_img_opa(255)

# add style for keytone_setting_img_2
keytone_setting_img_2.add_style(style_keytone_setting_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

keytone_setting_img_3 = lv.img(keytone_setting_cont_1)
keytone_setting_img_3.set_pos(416,192)
keytone_setting_img_3.set_size(38,38)
keytone_setting_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1840461298.png','rb') as f:
        keytone_setting_img_3_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1840461298.png')
    sys.exit()

keytone_setting_img_3_img = lv.img_dsc_t({
  'data_size': len(keytone_setting_img_3_img_data),
  'header': {'always_zero': 0, 'w': 38, 'h': 38, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': keytone_setting_img_3_img_data
})

keytone_setting_img_3.set_src(keytone_setting_img_3_img)
keytone_setting_img_3.set_pivot(0,0)
keytone_setting_img_3.set_angle(0)
# create style style_keytone_setting_img_3_main_main_default
style_keytone_setting_img_3_main_main_default = lv.style_t()
style_keytone_setting_img_3_main_main_default.init()
style_keytone_setting_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_keytone_setting_img_3_main_main_default.set_img_recolor_opa(0)
style_keytone_setting_img_3_main_main_default.set_img_opa(255)

# add style for keytone_setting_img_3
keytone_setting_img_3.add_style(style_keytone_setting_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

keytone_setting_label_2 = lv.label(keytone_setting_cont_1)
keytone_setting_label_2.set_pos(90,11)
keytone_setting_label_2.set_size(300,32)
keytone_setting_label_2.set_text("按键音")
keytone_setting_label_2.set_long_mode(lv.label.LONG.WRAP)
keytone_setting_label_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_keytone_setting_label_2_main_main_default
style_keytone_setting_label_2_main_main_default = lv.style_t()
style_keytone_setting_label_2_main_main_default.init()
style_keytone_setting_label_2_main_main_default.set_radius(0)
style_keytone_setting_label_2_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_keytone_setting_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_keytone_setting_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_keytone_setting_label_2_main_main_default.set_bg_opa(0)
style_keytone_setting_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_keytone_setting_label_2_main_main_default.set_text_font(lv.font_simsun_32)
except AttributeError:
    try:
        style_keytone_setting_label_2_main_main_default.set_text_font(lv.font_montserrat_32)
    except AttributeError:
        style_keytone_setting_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_keytone_setting_label_2_main_main_default.set_text_letter_space(2)
style_keytone_setting_label_2_main_main_default.set_pad_left(0)
style_keytone_setting_label_2_main_main_default.set_pad_right(0)
style_keytone_setting_label_2_main_main_default.set_pad_top(0)
style_keytone_setting_label_2_main_main_default.set_pad_bottom(0)

# add style for keytone_setting_label_2
keytone_setting_label_2.add_style(style_keytone_setting_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_keytone_setting_cont_1_main_main_default
style_keytone_setting_cont_1_main_main_default = lv.style_t()
style_keytone_setting_cont_1_main_main_default.init()
style_keytone_setting_cont_1_main_main_default.set_radius(0)
style_keytone_setting_cont_1_main_main_default.set_bg_color(lv.color_make(0x23,0x24,0x26))
style_keytone_setting_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x23,0x24,0x26))
style_keytone_setting_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_keytone_setting_cont_1_main_main_default.set_bg_opa(255)
style_keytone_setting_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_keytone_setting_cont_1_main_main_default.set_border_width(0)
style_keytone_setting_cont_1_main_main_default.set_border_opa(255)
style_keytone_setting_cont_1_main_main_default.set_pad_left(0)
style_keytone_setting_cont_1_main_main_default.set_pad_right(0)
style_keytone_setting_cont_1_main_main_default.set_pad_top(0)
style_keytone_setting_cont_1_main_main_default.set_pad_bottom(0)

# add style for keytone_setting_cont_1
keytone_setting_cont_1.add_style(style_keytone_setting_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

device_binding = lv.obj()
# create style style_device_binding_main_main_default
style_device_binding_main_main_default = lv.style_t()
style_device_binding_main_main_default.init()
style_device_binding_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_device_binding_main_main_default.set_bg_opa(0)

# add style for device_binding
device_binding.add_style(style_device_binding_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

device_binding_cont_1 = lv.obj(device_binding)
device_binding_cont_1.set_pos(0,0)
device_binding_cont_1.set_size(480,800)
device_binding_label_3 = lv.label(device_binding_cont_1)
device_binding_label_3.set_pos(8,63)
device_binding_label_3.set_size(460,727)
# create style style_device_binding_label_3_main_main_default
style_device_binding_label_3_main_main_default = lv.style_t()
style_device_binding_label_3_main_main_default.init()
style_device_binding_label_3_main_main_default.set_radius(0)
style_device_binding_label_3_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_device_binding_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_device_binding_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_device_binding_label_3_main_main_default.set_bg_opa(255)
style_device_binding_label_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_device_binding_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_device_binding_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_device_binding_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_device_binding_label_3_main_main_default.set_text_letter_space(2)
style_device_binding_label_3_main_main_default.set_pad_left(0)
style_device_binding_label_3_main_main_default.set_pad_right(0)
style_device_binding_label_3_main_main_default.set_pad_top(0)
style_device_binding_label_3_main_main_default.set_pad_bottom(0)

# add style for device_binding_label_3
device_binding_label_3.add_style(style_device_binding_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

device_binding_label_4 = lv.label(device_binding_cont_1)
device_binding_label_4.set_pos(67,459)
device_binding_label_4.set_size(365,27)
device_binding_label_4.set_text("请使用创想云app扫码绑定设备")
device_binding_label_4.set_long_mode(lv.label.LONG.WRAP)
device_binding_label_4.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_device_binding_label_4_main_main_default
style_device_binding_label_4_main_main_default = lv.style_t()
style_device_binding_label_4_main_main_default.init()
style_device_binding_label_4_main_main_default.set_radius(0)
style_device_binding_label_4_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_device_binding_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_device_binding_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_device_binding_label_4_main_main_default.set_bg_opa(255)
style_device_binding_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_device_binding_label_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_device_binding_label_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_device_binding_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_device_binding_label_4_main_main_default.set_text_letter_space(2)
style_device_binding_label_4_main_main_default.set_pad_left(0)
style_device_binding_label_4_main_main_default.set_pad_right(0)
style_device_binding_label_4_main_main_default.set_pad_top(0)
style_device_binding_label_4_main_main_default.set_pad_bottom(0)

# add style for device_binding_label_4
device_binding_label_4.add_style(style_device_binding_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

device_binding_img_2 = lv.img(device_binding_cont_1)
device_binding_img_2.set_pos(136,231)
device_binding_img_2.set_size(208,208)
# create style style_device_binding_img_2_main_main_default
style_device_binding_img_2_main_main_default = lv.style_t()
style_device_binding_img_2_main_main_default.init()
style_device_binding_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_device_binding_img_2_main_main_default.set_img_recolor_opa(0)
style_device_binding_img_2_main_main_default.set_img_opa(255)

# add style for device_binding_img_2
device_binding_img_2.add_style(style_device_binding_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

device_binding_label_1 = lv.label(device_binding_cont_1)
device_binding_label_1.set_pos(0,0)
device_binding_label_1.set_size(480,53)
# create style style_device_binding_label_1_main_main_default
style_device_binding_label_1_main_main_default = lv.style_t()
style_device_binding_label_1_main_main_default.init()
style_device_binding_label_1_main_main_default.set_radius(0)
style_device_binding_label_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_device_binding_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_device_binding_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_device_binding_label_1_main_main_default.set_bg_opa(255)
style_device_binding_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_device_binding_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_device_binding_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_device_binding_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_device_binding_label_1_main_main_default.set_text_letter_space(2)
style_device_binding_label_1_main_main_default.set_pad_left(0)
style_device_binding_label_1_main_main_default.set_pad_right(0)
style_device_binding_label_1_main_main_default.set_pad_top(0)
style_device_binding_label_1_main_main_default.set_pad_bottom(0)

# add style for device_binding_label_1
device_binding_label_1.add_style(style_device_binding_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

device_binding_btn_1 = lv.btn(device_binding_cont_1)
device_binding_btn_1.set_pos(0,0)
device_binding_btn_1.set_size(85,50)
# create style style_device_binding_btn_1_main_main_default
style_device_binding_btn_1_main_main_default = lv.style_t()
style_device_binding_btn_1_main_main_default.init()
style_device_binding_btn_1_main_main_default.set_radius(0)
style_device_binding_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_device_binding_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_device_binding_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_device_binding_btn_1_main_main_default.set_bg_opa(0)
style_device_binding_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_device_binding_btn_1_main_main_default.set_shadow_opa(0)
style_device_binding_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_device_binding_btn_1_main_main_default.set_border_width(0)
style_device_binding_btn_1_main_main_default.set_border_opa(255)

# add style for device_binding_btn_1
device_binding_btn_1.add_style(style_device_binding_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

device_binding_img_1 = lv.img(device_binding_cont_1)
device_binding_img_1.set_pos(21,17)
device_binding_img_1.set_size(36,24)
device_binding_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png','rb') as f:
        device_binding_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png')
    sys.exit()

device_binding_img_1_img = lv.img_dsc_t({
  'data_size': len(device_binding_img_1_img_data),
  'header': {'always_zero': 0, 'w': 36, 'h': 24, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': device_binding_img_1_img_data
})

device_binding_img_1.set_src(device_binding_img_1_img)
device_binding_img_1.set_pivot(0,0)
device_binding_img_1.set_angle(0)
# create style style_device_binding_img_1_main_main_default
style_device_binding_img_1_main_main_default = lv.style_t()
style_device_binding_img_1_main_main_default.init()
style_device_binding_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_device_binding_img_1_main_main_default.set_img_recolor_opa(0)
style_device_binding_img_1_main_main_default.set_img_opa(255)

# add style for device_binding_img_1
device_binding_img_1.add_style(style_device_binding_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

device_binding_label_2 = lv.label(device_binding_cont_1)
device_binding_label_2.set_pos(90,11)
device_binding_label_2.set_size(300,32)
device_binding_label_2.set_text("设备绑定")
device_binding_label_2.set_long_mode(lv.label.LONG.WRAP)
device_binding_label_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_device_binding_label_2_main_main_default
style_device_binding_label_2_main_main_default = lv.style_t()
style_device_binding_label_2_main_main_default.init()
style_device_binding_label_2_main_main_default.set_radius(0)
style_device_binding_label_2_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_device_binding_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_device_binding_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_device_binding_label_2_main_main_default.set_bg_opa(0)
style_device_binding_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_device_binding_label_2_main_main_default.set_text_font(lv.font_simsun_32)
except AttributeError:
    try:
        style_device_binding_label_2_main_main_default.set_text_font(lv.font_montserrat_32)
    except AttributeError:
        style_device_binding_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_device_binding_label_2_main_main_default.set_text_letter_space(2)
style_device_binding_label_2_main_main_default.set_pad_left(0)
style_device_binding_label_2_main_main_default.set_pad_right(0)
style_device_binding_label_2_main_main_default.set_pad_top(0)
style_device_binding_label_2_main_main_default.set_pad_bottom(0)

# add style for device_binding_label_2
device_binding_label_2.add_style(style_device_binding_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_device_binding_cont_1_main_main_default
style_device_binding_cont_1_main_main_default = lv.style_t()
style_device_binding_cont_1_main_main_default.init()
style_device_binding_cont_1_main_main_default.set_radius(0)
style_device_binding_cont_1_main_main_default.set_bg_color(lv.color_make(0x23,0x24,0x26))
style_device_binding_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x23,0x24,0x26))
style_device_binding_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_device_binding_cont_1_main_main_default.set_bg_opa(255)
style_device_binding_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_device_binding_cont_1_main_main_default.set_border_width(0)
style_device_binding_cont_1_main_main_default.set_border_opa(255)
style_device_binding_cont_1_main_main_default.set_pad_left(0)
style_device_binding_cont_1_main_main_default.set_pad_right(0)
style_device_binding_cont_1_main_main_default.set_pad_top(0)
style_device_binding_cont_1_main_main_default.set_pad_bottom(0)

# add style for device_binding_cont_1
device_binding_cont_1.add_style(style_device_binding_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device = lv.obj()
# create style style_about_device_main_main_default
style_about_device_main_main_default = lv.style_t()
style_about_device_main_main_default.init()
style_about_device_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_about_device_main_main_default.set_bg_opa(0)

# add style for about_device
about_device.add_style(style_about_device_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_cont_1 = lv.obj(about_device)
about_device_cont_1.set_pos(0,0)
about_device_cont_1.set_size(480,800)
about_device_label_3 = lv.label(about_device_cont_1)
about_device_label_3.set_pos(9,58)
about_device_label_3.set_size(460,727)
# create style style_about_device_label_3_main_main_default
style_about_device_label_3_main_main_default = lv.style_t()
style_about_device_label_3_main_main_default.init()
style_about_device_label_3_main_main_default.set_radius(0)
style_about_device_label_3_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_about_device_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_about_device_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_label_3_main_main_default.set_bg_opa(255)
style_about_device_label_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_about_device_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_about_device_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_about_device_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_device_label_3_main_main_default.set_text_letter_space(2)
style_about_device_label_3_main_main_default.set_pad_left(0)
style_about_device_label_3_main_main_default.set_pad_right(0)
style_about_device_label_3_main_main_default.set_pad_top(0)
style_about_device_label_3_main_main_default.set_pad_bottom(0)

# add style for about_device_label_3
about_device_label_3.add_style(style_about_device_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_label_4 = lv.label(about_device_cont_1)
about_device_label_4.set_pos(26,76)
about_device_label_4.set_size(427,344)
# create style style_about_device_label_4_main_main_default
style_about_device_label_4_main_main_default = lv.style_t()
style_about_device_label_4_main_main_default.init()
style_about_device_label_4_main_main_default.set_radius(0)
style_about_device_label_4_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_label_4_main_main_default.set_bg_opa(255)
style_about_device_label_4_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_about_device_label_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_about_device_label_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_about_device_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_device_label_4_main_main_default.set_text_letter_space(2)
style_about_device_label_4_main_main_default.set_pad_left(0)
style_about_device_label_4_main_main_default.set_pad_right(0)
style_about_device_label_4_main_main_default.set_pad_top(0)
style_about_device_label_4_main_main_default.set_pad_bottom(0)

# add style for about_device_label_4
about_device_label_4.add_style(style_about_device_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_label_5 = lv.label(about_device_cont_1)
about_device_label_5.set_pos(90,340)
about_device_label_5.set_size(300,32)
about_device_label_5.set_text("CR-10 H1")
about_device_label_5.set_long_mode(lv.label.LONG.WRAP)
about_device_label_5.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_about_device_label_5_main_main_default
style_about_device_label_5_main_main_default = lv.style_t()
style_about_device_label_5_main_main_default.init()
style_about_device_label_5_main_main_default.set_radius(0)
style_about_device_label_5_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_label_5_main_main_default.set_bg_opa(0)
style_about_device_label_5_main_main_default.set_text_color(lv.color_make(0x42,0xbd,0xd8))
try:
    style_about_device_label_5_main_main_default.set_text_font(lv.font_simsun_28)
except AttributeError:
    try:
        style_about_device_label_5_main_main_default.set_text_font(lv.font_montserrat_28)
    except AttributeError:
        style_about_device_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_device_label_5_main_main_default.set_text_letter_space(0)
style_about_device_label_5_main_main_default.set_pad_left(0)
style_about_device_label_5_main_main_default.set_pad_right(0)
style_about_device_label_5_main_main_default.set_pad_top(0)
style_about_device_label_5_main_main_default.set_pad_bottom(0)

# add style for about_device_label_5
about_device_label_5.add_style(style_about_device_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_label_6 = lv.label(about_device_cont_1)
about_device_label_6.set_pos(90,370)
about_device_label_6.set_size(300,32)
about_device_label_6.set_text("200X200X200mm")
about_device_label_6.set_long_mode(lv.label.LONG.WRAP)
about_device_label_6.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_about_device_label_6_main_main_default
style_about_device_label_6_main_main_default = lv.style_t()
style_about_device_label_6_main_main_default.init()
style_about_device_label_6_main_main_default.set_radius(0)
style_about_device_label_6_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_label_6_main_main_default.set_bg_opa(0)
style_about_device_label_6_main_main_default.set_text_color(lv.color_make(0x6a,0x70,0x7d))
try:
    style_about_device_label_6_main_main_default.set_text_font(lv.font_simsun_28)
except AttributeError:
    try:
        style_about_device_label_6_main_main_default.set_text_font(lv.font_montserrat_28)
    except AttributeError:
        style_about_device_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_device_label_6_main_main_default.set_text_letter_space(0)
style_about_device_label_6_main_main_default.set_pad_left(0)
style_about_device_label_6_main_main_default.set_pad_right(0)
style_about_device_label_6_main_main_default.set_pad_top(0)
style_about_device_label_6_main_main_default.set_pad_bottom(0)

# add style for about_device_label_6
about_device_label_6.add_style(style_about_device_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_label_7 = lv.label(about_device_cont_1)
about_device_label_7.set_pos(21,440)
about_device_label_7.set_size(190,24)
about_device_label_7.set_text("设备名称")
about_device_label_7.set_long_mode(lv.label.LONG.WRAP)
about_device_label_7.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_about_device_label_7_main_main_default
style_about_device_label_7_main_main_default = lv.style_t()
style_about_device_label_7_main_main_default.init()
style_about_device_label_7_main_main_default.set_radius(0)
style_about_device_label_7_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_label_7_main_main_default.set_bg_opa(0)
style_about_device_label_7_main_main_default.set_text_color(lv.color_make(0x6a,0x70,0x7d))
try:
    style_about_device_label_7_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_about_device_label_7_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_about_device_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_device_label_7_main_main_default.set_text_letter_space(0)
style_about_device_label_7_main_main_default.set_pad_left(0)
style_about_device_label_7_main_main_default.set_pad_right(0)
style_about_device_label_7_main_main_default.set_pad_top(0)
style_about_device_label_7_main_main_default.set_pad_bottom(0)

# add style for about_device_label_7
about_device_label_7.add_style(style_about_device_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_label_8 = lv.label(about_device_cont_1)
about_device_label_8.set_pos(21,484)
about_device_label_8.set_size(190,24)
about_device_label_8.set_text("机器型号")
about_device_label_8.set_long_mode(lv.label.LONG.WRAP)
about_device_label_8.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_about_device_label_8_main_main_default
style_about_device_label_8_main_main_default = lv.style_t()
style_about_device_label_8_main_main_default.init()
style_about_device_label_8_main_main_default.set_radius(0)
style_about_device_label_8_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_label_8_main_main_default.set_bg_opa(0)
style_about_device_label_8_main_main_default.set_text_color(lv.color_make(0x6a,0x70,0x7d))
try:
    style_about_device_label_8_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_about_device_label_8_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_about_device_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_device_label_8_main_main_default.set_text_letter_space(0)
style_about_device_label_8_main_main_default.set_pad_left(0)
style_about_device_label_8_main_main_default.set_pad_right(0)
style_about_device_label_8_main_main_default.set_pad_top(0)
style_about_device_label_8_main_main_default.set_pad_bottom(0)

# add style for about_device_label_8
about_device_label_8.add_style(style_about_device_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_label_9 = lv.label(about_device_cont_1)
about_device_label_9.set_pos(21,528)
about_device_label_9.set_size(190,24)
about_device_label_9.set_text("固件版本")
about_device_label_9.set_long_mode(lv.label.LONG.WRAP)
about_device_label_9.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_about_device_label_9_main_main_default
style_about_device_label_9_main_main_default = lv.style_t()
style_about_device_label_9_main_main_default.init()
style_about_device_label_9_main_main_default.set_radius(0)
style_about_device_label_9_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_9_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_label_9_main_main_default.set_bg_opa(0)
style_about_device_label_9_main_main_default.set_text_color(lv.color_make(0x6a,0x70,0x7d))
try:
    style_about_device_label_9_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_about_device_label_9_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_about_device_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_device_label_9_main_main_default.set_text_letter_space(0)
style_about_device_label_9_main_main_default.set_pad_left(0)
style_about_device_label_9_main_main_default.set_pad_right(0)
style_about_device_label_9_main_main_default.set_pad_top(0)
style_about_device_label_9_main_main_default.set_pad_bottom(0)

# add style for about_device_label_9
about_device_label_9.add_style(style_about_device_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_label_10 = lv.label(about_device_cont_1)
about_device_label_10.set_pos(21,572)
about_device_label_10.set_size(190,24)
about_device_label_10.set_text("Mac地址")
about_device_label_10.set_long_mode(lv.label.LONG.WRAP)
about_device_label_10.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_about_device_label_10_main_main_default
style_about_device_label_10_main_main_default = lv.style_t()
style_about_device_label_10_main_main_default.init()
style_about_device_label_10_main_main_default.set_radius(0)
style_about_device_label_10_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_10_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_label_10_main_main_default.set_bg_opa(0)
style_about_device_label_10_main_main_default.set_text_color(lv.color_make(0x6a,0x70,0x7d))
try:
    style_about_device_label_10_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_about_device_label_10_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_about_device_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_device_label_10_main_main_default.set_text_letter_space(0)
style_about_device_label_10_main_main_default.set_pad_left(0)
style_about_device_label_10_main_main_default.set_pad_right(0)
style_about_device_label_10_main_main_default.set_pad_top(0)
style_about_device_label_10_main_main_default.set_pad_bottom(0)

# add style for about_device_label_10
about_device_label_10.add_style(style_about_device_label_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_label_11 = lv.label(about_device_cont_1)
about_device_label_11.set_pos(21,616)
about_device_label_11.set_size(190,24)
about_device_label_11.set_text("累计打印")
about_device_label_11.set_long_mode(lv.label.LONG.WRAP)
about_device_label_11.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_about_device_label_11_main_main_default
style_about_device_label_11_main_main_default = lv.style_t()
style_about_device_label_11_main_main_default.init()
style_about_device_label_11_main_main_default.set_radius(0)
style_about_device_label_11_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_11_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_11_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_label_11_main_main_default.set_bg_opa(0)
style_about_device_label_11_main_main_default.set_text_color(lv.color_make(0x6a,0x70,0x7d))
try:
    style_about_device_label_11_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_about_device_label_11_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_about_device_label_11_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_device_label_11_main_main_default.set_text_letter_space(0)
style_about_device_label_11_main_main_default.set_pad_left(0)
style_about_device_label_11_main_main_default.set_pad_right(0)
style_about_device_label_11_main_main_default.set_pad_top(0)
style_about_device_label_11_main_main_default.set_pad_bottom(0)

# add style for about_device_label_11
about_device_label_11.add_style(style_about_device_label_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_label_12 = lv.label(about_device_cont_1)
about_device_label_12.set_pos(21,660)
about_device_label_12.set_size(190,24)
about_device_label_12.set_text("存储空间")
about_device_label_12.set_long_mode(lv.label.LONG.WRAP)
about_device_label_12.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_about_device_label_12_main_main_default
style_about_device_label_12_main_main_default = lv.style_t()
style_about_device_label_12_main_main_default.init()
style_about_device_label_12_main_main_default.set_radius(0)
style_about_device_label_12_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_12_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_12_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_label_12_main_main_default.set_bg_opa(0)
style_about_device_label_12_main_main_default.set_text_color(lv.color_make(0x6a,0x70,0x7d))
try:
    style_about_device_label_12_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_about_device_label_12_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_about_device_label_12_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_device_label_12_main_main_default.set_text_letter_space(0)
style_about_device_label_12_main_main_default.set_pad_left(0)
style_about_device_label_12_main_main_default.set_pad_right(0)
style_about_device_label_12_main_main_default.set_pad_top(0)
style_about_device_label_12_main_main_default.set_pad_bottom(0)

# add style for about_device_label_12
about_device_label_12.add_style(style_about_device_label_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_label_13 = lv.label(about_device_cont_1)
about_device_label_13.set_pos(266,440)
about_device_label_13.set_size(190,24)
about_device_label_13.set_text("3D-001-08")
about_device_label_13.set_long_mode(lv.label.LONG.WRAP)
about_device_label_13.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_about_device_label_13_main_main_default
style_about_device_label_13_main_main_default = lv.style_t()
style_about_device_label_13_main_main_default.init()
style_about_device_label_13_main_main_default.set_radius(0)
style_about_device_label_13_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_13_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_13_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_label_13_main_main_default.set_bg_opa(0)
style_about_device_label_13_main_main_default.set_text_color(lv.color_make(0x83,0x86,0x8b))
try:
    style_about_device_label_13_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_about_device_label_13_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_about_device_label_13_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_device_label_13_main_main_default.set_text_letter_space(0)
style_about_device_label_13_main_main_default.set_pad_left(0)
style_about_device_label_13_main_main_default.set_pad_right(0)
style_about_device_label_13_main_main_default.set_pad_top(0)
style_about_device_label_13_main_main_default.set_pad_bottom(0)

# add style for about_device_label_13
about_device_label_13.add_style(style_about_device_label_13_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_label_14 = lv.label(about_device_cont_1)
about_device_label_14.set_pos(266,484)
about_device_label_14.set_size(190,24)
about_device_label_14.set_text("CR-10 H1")
about_device_label_14.set_long_mode(lv.label.LONG.WRAP)
about_device_label_14.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_about_device_label_14_main_main_default
style_about_device_label_14_main_main_default = lv.style_t()
style_about_device_label_14_main_main_default.init()
style_about_device_label_14_main_main_default.set_radius(0)
style_about_device_label_14_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_14_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_14_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_label_14_main_main_default.set_bg_opa(0)
style_about_device_label_14_main_main_default.set_text_color(lv.color_make(0x83,0x86,0x8b))
try:
    style_about_device_label_14_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_about_device_label_14_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_about_device_label_14_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_device_label_14_main_main_default.set_text_letter_space(0)
style_about_device_label_14_main_main_default.set_pad_left(0)
style_about_device_label_14_main_main_default.set_pad_right(0)
style_about_device_label_14_main_main_default.set_pad_top(0)
style_about_device_label_14_main_main_default.set_pad_bottom(0)

# add style for about_device_label_14
about_device_label_14.add_style(style_about_device_label_14_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_label_15 = lv.label(about_device_cont_1)
about_device_label_15.set_pos(266,528)
about_device_label_15.set_size(190,24)
about_device_label_15.set_text("V10.52.44")
about_device_label_15.set_long_mode(lv.label.LONG.WRAP)
about_device_label_15.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_about_device_label_15_main_main_default
style_about_device_label_15_main_main_default = lv.style_t()
style_about_device_label_15_main_main_default.init()
style_about_device_label_15_main_main_default.set_radius(0)
style_about_device_label_15_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_15_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_15_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_label_15_main_main_default.set_bg_opa(0)
style_about_device_label_15_main_main_default.set_text_color(lv.color_make(0x83,0x86,0x8b))
try:
    style_about_device_label_15_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_about_device_label_15_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_about_device_label_15_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_device_label_15_main_main_default.set_text_letter_space(0)
style_about_device_label_15_main_main_default.set_pad_left(0)
style_about_device_label_15_main_main_default.set_pad_right(0)
style_about_device_label_15_main_main_default.set_pad_top(0)
style_about_device_label_15_main_main_default.set_pad_bottom(0)

# add style for about_device_label_15
about_device_label_15.add_style(style_about_device_label_15_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_label_16 = lv.label(about_device_cont_1)
about_device_label_16.set_pos(266,572)
about_device_label_16.set_size(190,24)
about_device_label_16.set_text("48:71:76:4C:4A")
about_device_label_16.set_long_mode(lv.label.LONG.WRAP)
about_device_label_16.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_about_device_label_16_main_main_default
style_about_device_label_16_main_main_default = lv.style_t()
style_about_device_label_16_main_main_default.init()
style_about_device_label_16_main_main_default.set_radius(0)
style_about_device_label_16_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_16_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_16_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_label_16_main_main_default.set_bg_opa(0)
style_about_device_label_16_main_main_default.set_text_color(lv.color_make(0x83,0x86,0x8b))
try:
    style_about_device_label_16_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_about_device_label_16_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_about_device_label_16_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_device_label_16_main_main_default.set_text_letter_space(0)
style_about_device_label_16_main_main_default.set_pad_left(0)
style_about_device_label_16_main_main_default.set_pad_right(0)
style_about_device_label_16_main_main_default.set_pad_top(0)
style_about_device_label_16_main_main_default.set_pad_bottom(0)

# add style for about_device_label_16
about_device_label_16.add_style(style_about_device_label_16_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_label_17 = lv.label(about_device_cont_1)
about_device_label_17.set_pos(266,616)
about_device_label_17.set_size(190,24)
about_device_label_17.set_text("12d11h33m")
about_device_label_17.set_long_mode(lv.label.LONG.WRAP)
about_device_label_17.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_about_device_label_17_main_main_default
style_about_device_label_17_main_main_default = lv.style_t()
style_about_device_label_17_main_main_default.init()
style_about_device_label_17_main_main_default.set_radius(0)
style_about_device_label_17_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_17_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_17_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_label_17_main_main_default.set_bg_opa(0)
style_about_device_label_17_main_main_default.set_text_color(lv.color_make(0x83,0x86,0x8b))
try:
    style_about_device_label_17_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_about_device_label_17_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_about_device_label_17_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_device_label_17_main_main_default.set_text_letter_space(0)
style_about_device_label_17_main_main_default.set_pad_left(0)
style_about_device_label_17_main_main_default.set_pad_right(0)
style_about_device_label_17_main_main_default.set_pad_top(0)
style_about_device_label_17_main_main_default.set_pad_bottom(0)

# add style for about_device_label_17
about_device_label_17.add_style(style_about_device_label_17_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_label_18 = lv.label(about_device_cont_1)
about_device_label_18.set_pos(266,660)
about_device_label_18.set_size(190,24)
about_device_label_18.set_text("5.5GB/7.8GB")
about_device_label_18.set_long_mode(lv.label.LONG.WRAP)
about_device_label_18.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_about_device_label_18_main_main_default
style_about_device_label_18_main_main_default = lv.style_t()
style_about_device_label_18_main_main_default.init()
style_about_device_label_18_main_main_default.set_radius(0)
style_about_device_label_18_main_main_default.set_bg_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_18_main_main_default.set_bg_grad_color(lv.color_make(0x0d,0x0d,0x0d))
style_about_device_label_18_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_label_18_main_main_default.set_bg_opa(0)
style_about_device_label_18_main_main_default.set_text_color(lv.color_make(0x83,0x86,0x8b))
try:
    style_about_device_label_18_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_about_device_label_18_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_about_device_label_18_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_device_label_18_main_main_default.set_text_letter_space(0)
style_about_device_label_18_main_main_default.set_pad_left(0)
style_about_device_label_18_main_main_default.set_pad_right(0)
style_about_device_label_18_main_main_default.set_pad_top(0)
style_about_device_label_18_main_main_default.set_pad_bottom(0)

# add style for about_device_label_18
about_device_label_18.add_style(style_about_device_label_18_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_img_2 = lv.img(about_device_cont_1)
about_device_img_2.set_pos(129,89)
about_device_img_2.set_size(222,249)
about_device_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-436760867.png','rb') as f:
        about_device_img_2_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-436760867.png')
    sys.exit()

about_device_img_2_img = lv.img_dsc_t({
  'data_size': len(about_device_img_2_img_data),
  'header': {'always_zero': 0, 'w': 222, 'h': 249, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': about_device_img_2_img_data
})

about_device_img_2.set_src(about_device_img_2_img)
about_device_img_2.set_pivot(0,0)
about_device_img_2.set_angle(0)
# create style style_about_device_img_2_main_main_default
style_about_device_img_2_main_main_default = lv.style_t()
style_about_device_img_2_main_main_default.init()
style_about_device_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_about_device_img_2_main_main_default.set_img_recolor_opa(0)
style_about_device_img_2_main_main_default.set_img_opa(255)

# add style for about_device_img_2
about_device_img_2.add_style(style_about_device_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_label_1 = lv.label(about_device_cont_1)
about_device_label_1.set_pos(0,0)
about_device_label_1.set_size(480,53)
# create style style_about_device_label_1_main_main_default
style_about_device_label_1_main_main_default = lv.style_t()
style_about_device_label_1_main_main_default.init()
style_about_device_label_1_main_main_default.set_radius(0)
style_about_device_label_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_about_device_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_about_device_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_label_1_main_main_default.set_bg_opa(255)
style_about_device_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_about_device_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_about_device_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_about_device_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_device_label_1_main_main_default.set_text_letter_space(2)
style_about_device_label_1_main_main_default.set_pad_left(0)
style_about_device_label_1_main_main_default.set_pad_right(0)
style_about_device_label_1_main_main_default.set_pad_top(0)
style_about_device_label_1_main_main_default.set_pad_bottom(0)

# add style for about_device_label_1
about_device_label_1.add_style(style_about_device_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_btn_1 = lv.btn(about_device_cont_1)
about_device_btn_1.set_pos(0,0)
about_device_btn_1.set_size(85,50)
# create style style_about_device_btn_1_main_main_default
style_about_device_btn_1_main_main_default = lv.style_t()
style_about_device_btn_1_main_main_default.init()
style_about_device_btn_1_main_main_default.set_radius(0)
style_about_device_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_about_device_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_about_device_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_btn_1_main_main_default.set_bg_opa(0)
style_about_device_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_about_device_btn_1_main_main_default.set_shadow_opa(0)
style_about_device_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_about_device_btn_1_main_main_default.set_border_width(0)
style_about_device_btn_1_main_main_default.set_border_opa(255)

# add style for about_device_btn_1
about_device_btn_1.add_style(style_about_device_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_img_1 = lv.img(about_device_cont_1)
about_device_img_1.set_pos(21,17)
about_device_img_1.set_size(36,24)
about_device_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png','rb') as f:
        about_device_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png')
    sys.exit()

about_device_img_1_img = lv.img_dsc_t({
  'data_size': len(about_device_img_1_img_data),
  'header': {'always_zero': 0, 'w': 36, 'h': 24, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': about_device_img_1_img_data
})

about_device_img_1.set_src(about_device_img_1_img)
about_device_img_1.set_pivot(0,0)
about_device_img_1.set_angle(0)
# create style style_about_device_img_1_main_main_default
style_about_device_img_1_main_main_default = lv.style_t()
style_about_device_img_1_main_main_default.init()
style_about_device_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_about_device_img_1_main_main_default.set_img_recolor_opa(0)
style_about_device_img_1_main_main_default.set_img_opa(255)

# add style for about_device_img_1
about_device_img_1.add_style(style_about_device_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_device_label_2 = lv.label(about_device_cont_1)
about_device_label_2.set_pos(90,11)
about_device_label_2.set_size(300,32)
about_device_label_2.set_text("关于本机")
about_device_label_2.set_long_mode(lv.label.LONG.WRAP)
about_device_label_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_about_device_label_2_main_main_default
style_about_device_label_2_main_main_default = lv.style_t()
style_about_device_label_2_main_main_default.init()
style_about_device_label_2_main_main_default.set_radius(0)
style_about_device_label_2_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_about_device_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_about_device_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_label_2_main_main_default.set_bg_opa(0)
style_about_device_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_about_device_label_2_main_main_default.set_text_font(lv.font_simsun_32)
except AttributeError:
    try:
        style_about_device_label_2_main_main_default.set_text_font(lv.font_montserrat_32)
    except AttributeError:
        style_about_device_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_device_label_2_main_main_default.set_text_letter_space(2)
style_about_device_label_2_main_main_default.set_pad_left(0)
style_about_device_label_2_main_main_default.set_pad_right(0)
style_about_device_label_2_main_main_default.set_pad_top(0)
style_about_device_label_2_main_main_default.set_pad_bottom(0)

# add style for about_device_label_2
about_device_label_2.add_style(style_about_device_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_about_device_cont_1_main_main_default
style_about_device_cont_1_main_main_default = lv.style_t()
style_about_device_cont_1_main_main_default.init()
style_about_device_cont_1_main_main_default.set_radius(0)
style_about_device_cont_1_main_main_default.set_bg_color(lv.color_make(0x23,0x24,0x26))
style_about_device_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x23,0x24,0x26))
style_about_device_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_about_device_cont_1_main_main_default.set_bg_opa(255)
style_about_device_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_about_device_cont_1_main_main_default.set_border_width(0)
style_about_device_cont_1_main_main_default.set_border_opa(255)
style_about_device_cont_1_main_main_default.set_pad_left(0)
style_about_device_cont_1_main_main_default.set_pad_right(0)
style_about_device_cont_1_main_main_default.set_pad_top(0)
style_about_device_cont_1_main_main_default.set_pad_bottom(0)

# add style for about_device_cont_1
about_device_cont_1.add_style(style_about_device_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

export_log = lv.obj()
# create style style_export_log_main_main_default
style_export_log_main_main_default = lv.style_t()
style_export_log_main_main_default.init()
style_export_log_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_export_log_main_main_default.set_bg_opa(0)

# add style for export_log
export_log.add_style(style_export_log_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

export_log_cont_1 = lv.obj(export_log)
export_log_cont_1.set_pos(0,0)
export_log_cont_1.set_size(480,800)
export_log_label_3 = lv.label(export_log_cont_1)
export_log_label_3.set_pos(5,58)
export_log_label_3.set_size(460,727)
# create style style_export_log_label_3_main_main_default
style_export_log_label_3_main_main_default = lv.style_t()
style_export_log_label_3_main_main_default.init()
style_export_log_label_3_main_main_default.set_radius(0)
style_export_log_label_3_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_export_log_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_export_log_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_export_log_label_3_main_main_default.set_bg_opa(255)
style_export_log_label_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_export_log_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_export_log_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_export_log_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_export_log_label_3_main_main_default.set_text_letter_space(2)
style_export_log_label_3_main_main_default.set_pad_left(0)
style_export_log_label_3_main_main_default.set_pad_right(0)
style_export_log_label_3_main_main_default.set_pad_top(0)
style_export_log_label_3_main_main_default.set_pad_bottom(0)

# add style for export_log_label_3
export_log_label_3.add_style(style_export_log_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

export_log_btn_2 = lv.btn(export_log_cont_1)
export_log_btn_2.set_pos(27,700)
export_log_btn_2.set_size(426,65)
export_log_btn_2_label = lv.label(export_log_btn_2)
export_log_btn_2_label.set_text("导出")
export_log_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
export_log_btn_2_label.align(lv.ALIGN.CENTER,0,0)
export_log_btn_2_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    export_log_btn_2_label.set_style_text_font(lv.font_simsun_28, lv.STATE.DEFAULT)
except AttributeError:
    try:
        export_log_btn_2_label.set_style_text_font(lv.font_montserrat_28, lv.STATE.DEFAULT)
    except AttributeError:
        export_log_btn_2_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_export_log_btn_2_main_main_default
style_export_log_btn_2_main_main_default = lv.style_t()
style_export_log_btn_2_main_main_default.init()
style_export_log_btn_2_main_main_default.set_radius(8)
style_export_log_btn_2_main_main_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_export_log_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_export_log_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_export_log_btn_2_main_main_default.set_bg_opa(255)
style_export_log_btn_2_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_export_log_btn_2_main_main_default.set_shadow_opa(0)
style_export_log_btn_2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_export_log_btn_2_main_main_default.set_border_width(0)
style_export_log_btn_2_main_main_default.set_border_opa(255)

# add style for export_log_btn_2
export_log_btn_2.add_style(style_export_log_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

export_log_label_1 = lv.label(export_log_cont_1)
export_log_label_1.set_pos(0,0)
export_log_label_1.set_size(480,53)
# create style style_export_log_label_1_main_main_default
style_export_log_label_1_main_main_default = lv.style_t()
style_export_log_label_1_main_main_default.init()
style_export_log_label_1_main_main_default.set_radius(0)
style_export_log_label_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_export_log_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_export_log_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_export_log_label_1_main_main_default.set_bg_opa(255)
style_export_log_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_export_log_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_export_log_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_export_log_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_export_log_label_1_main_main_default.set_text_letter_space(2)
style_export_log_label_1_main_main_default.set_pad_left(0)
style_export_log_label_1_main_main_default.set_pad_right(0)
style_export_log_label_1_main_main_default.set_pad_top(0)
style_export_log_label_1_main_main_default.set_pad_bottom(0)

# add style for export_log_label_1
export_log_label_1.add_style(style_export_log_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

export_log_label_4 = lv.label(export_log_cont_1)
export_log_label_4.set_pos(39,86)
export_log_label_4.set_size(350,28)
export_log_label_4.set_text("文件路径.....")
export_log_label_4.set_long_mode(lv.label.LONG.WRAP)
export_log_label_4.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_export_log_label_4_main_main_default
style_export_log_label_4_main_main_default = lv.style_t()
style_export_log_label_4_main_main_default.init()
style_export_log_label_4_main_main_default.set_radius(0)
style_export_log_label_4_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_export_log_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_export_log_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_export_log_label_4_main_main_default.set_bg_opa(0)
style_export_log_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_export_log_label_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_export_log_label_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_export_log_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_export_log_label_4_main_main_default.set_text_letter_space(0)
style_export_log_label_4_main_main_default.set_pad_left(0)
style_export_log_label_4_main_main_default.set_pad_right(0)
style_export_log_label_4_main_main_default.set_pad_top(0)
style_export_log_label_4_main_main_default.set_pad_bottom(0)

# add style for export_log_label_4
export_log_label_4.add_style(style_export_log_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

export_log_btn_1 = lv.btn(export_log_cont_1)
export_log_btn_1.set_pos(0,0)
export_log_btn_1.set_size(85,50)
# create style style_export_log_btn_1_main_main_default
style_export_log_btn_1_main_main_default = lv.style_t()
style_export_log_btn_1_main_main_default.init()
style_export_log_btn_1_main_main_default.set_radius(0)
style_export_log_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_export_log_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_export_log_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_export_log_btn_1_main_main_default.set_bg_opa(0)
style_export_log_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_export_log_btn_1_main_main_default.set_shadow_opa(0)
style_export_log_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_export_log_btn_1_main_main_default.set_border_width(0)
style_export_log_btn_1_main_main_default.set_border_opa(255)

# add style for export_log_btn_1
export_log_btn_1.add_style(style_export_log_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

export_log_img_1 = lv.img(export_log_cont_1)
export_log_img_1.set_pos(21,17)
export_log_img_1.set_size(36,24)
export_log_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png','rb') as f:
        export_log_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png')
    sys.exit()

export_log_img_1_img = lv.img_dsc_t({
  'data_size': len(export_log_img_1_img_data),
  'header': {'always_zero': 0, 'w': 36, 'h': 24, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': export_log_img_1_img_data
})

export_log_img_1.set_src(export_log_img_1_img)
export_log_img_1.set_pivot(0,0)
export_log_img_1.set_angle(0)
# create style style_export_log_img_1_main_main_default
style_export_log_img_1_main_main_default = lv.style_t()
style_export_log_img_1_main_main_default.init()
style_export_log_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_export_log_img_1_main_main_default.set_img_recolor_opa(0)
style_export_log_img_1_main_main_default.set_img_opa(255)

# add style for export_log_img_1
export_log_img_1.add_style(style_export_log_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

export_log_label_2 = lv.label(export_log_cont_1)
export_log_label_2.set_pos(90,11)
export_log_label_2.set_size(300,32)
export_log_label_2.set_text("关于本机")
export_log_label_2.set_long_mode(lv.label.LONG.WRAP)
export_log_label_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_export_log_label_2_main_main_default
style_export_log_label_2_main_main_default = lv.style_t()
style_export_log_label_2_main_main_default.init()
style_export_log_label_2_main_main_default.set_radius(0)
style_export_log_label_2_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_export_log_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_export_log_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_export_log_label_2_main_main_default.set_bg_opa(0)
style_export_log_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_export_log_label_2_main_main_default.set_text_font(lv.font_simsun_32)
except AttributeError:
    try:
        style_export_log_label_2_main_main_default.set_text_font(lv.font_montserrat_32)
    except AttributeError:
        style_export_log_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_export_log_label_2_main_main_default.set_text_letter_space(2)
style_export_log_label_2_main_main_default.set_pad_left(0)
style_export_log_label_2_main_main_default.set_pad_right(0)
style_export_log_label_2_main_main_default.set_pad_top(0)
style_export_log_label_2_main_main_default.set_pad_bottom(0)

# add style for export_log_label_2
export_log_label_2.add_style(style_export_log_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_export_log_cont_1_main_main_default
style_export_log_cont_1_main_main_default = lv.style_t()
style_export_log_cont_1_main_main_default.init()
style_export_log_cont_1_main_main_default.set_radius(0)
style_export_log_cont_1_main_main_default.set_bg_color(lv.color_make(0x23,0x24,0x26))
style_export_log_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x23,0x24,0x26))
style_export_log_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_export_log_cont_1_main_main_default.set_bg_opa(255)
style_export_log_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_export_log_cont_1_main_main_default.set_border_width(0)
style_export_log_cont_1_main_main_default.set_border_opa(255)
style_export_log_cont_1_main_main_default.set_pad_left(0)
style_export_log_cont_1_main_main_default.set_pad_right(0)
style_export_log_cont_1_main_main_default.set_pad_top(0)
style_export_log_cont_1_main_main_default.set_pad_bottom(0)

# add style for export_log_cont_1
export_log_cont_1.add_style(style_export_log_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

resetdevide = lv.obj()
# create style style_resetdevide_main_main_default
style_resetdevide_main_main_default = lv.style_t()
style_resetdevide_main_main_default.init()
style_resetdevide_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_resetdevide_main_main_default.set_bg_opa(0)

# add style for resetdevide
resetdevide.add_style(style_resetdevide_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

resetdevide_cont_1 = lv.obj(resetdevide)
resetdevide_cont_1.set_pos(0,0)
resetdevide_cont_1.set_size(480,800)
resetdevide_label_3 = lv.label(resetdevide_cont_1)
resetdevide_label_3.set_pos(10,56)
resetdevide_label_3.set_size(460,727)
# create style style_resetdevide_label_3_main_main_default
style_resetdevide_label_3_main_main_default = lv.style_t()
style_resetdevide_label_3_main_main_default.init()
style_resetdevide_label_3_main_main_default.set_radius(0)
style_resetdevide_label_3_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_resetdevide_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_resetdevide_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_label_3_main_main_default.set_bg_opa(255)
style_resetdevide_label_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_resetdevide_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_resetdevide_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_resetdevide_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_resetdevide_label_3_main_main_default.set_text_letter_space(2)
style_resetdevide_label_3_main_main_default.set_pad_left(0)
style_resetdevide_label_3_main_main_default.set_pad_right(0)
style_resetdevide_label_3_main_main_default.set_pad_top(0)
style_resetdevide_label_3_main_main_default.set_pad_bottom(0)

# add style for resetdevide_label_3
resetdevide_label_3.add_style(style_resetdevide_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

resetdevide_cb_1 = lv.checkbox(resetdevide_cont_1)
resetdevide_cb_1.set_pos(36,147)
resetdevide_cb_1.set_text("日志")
# create style style_resetdevide_cb_1_main_main_default
style_resetdevide_cb_1_main_main_default = lv.style_t()
style_resetdevide_cb_1_main_main_default.init()
style_resetdevide_cb_1_main_main_default.set_radius(0)
style_resetdevide_cb_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_resetdevide_cb_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_resetdevide_cb_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_cb_1_main_main_default.set_bg_opa(0)
style_resetdevide_cb_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_resetdevide_cb_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_resetdevide_cb_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_resetdevide_cb_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_resetdevide_cb_1_main_main_default.set_text_letter_space(0)

# add style for resetdevide_cb_1
resetdevide_cb_1.add_style(style_resetdevide_cb_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_resetdevide_cb_1_main_indicator_default
style_resetdevide_cb_1_main_indicator_default = lv.style_t()
style_resetdevide_cb_1_main_indicator_default.init()
style_resetdevide_cb_1_main_indicator_default.set_radius(0)
style_resetdevide_cb_1_main_indicator_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_resetdevide_cb_1_main_indicator_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_resetdevide_cb_1_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_cb_1_main_indicator_default.set_bg_opa(0)
style_resetdevide_cb_1_main_indicator_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_resetdevide_cb_1_main_indicator_default.set_border_width(2)

# add style for resetdevide_cb_1
resetdevide_cb_1.add_style(style_resetdevide_cb_1_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_resetdevide_cb_1_main_indicator_checked
style_resetdevide_cb_1_main_indicator_checked = lv.style_t()
style_resetdevide_cb_1_main_indicator_checked.init()
style_resetdevide_cb_1_main_indicator_checked.set_radius(0)
style_resetdevide_cb_1_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_resetdevide_cb_1_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_resetdevide_cb_1_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_cb_1_main_indicator_checked.set_bg_opa(0)
style_resetdevide_cb_1_main_indicator_checked.set_border_color(lv.color_make(0xff,0xff,0xff))
style_resetdevide_cb_1_main_indicator_checked.set_border_width(2)

# add style for resetdevide_cb_1
resetdevide_cb_1.add_style(style_resetdevide_cb_1_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

resetdevide_cb_2 = lv.checkbox(resetdevide_cont_1)
resetdevide_cb_2.set_pos(36,207)
resetdevide_cb_2.set_text("延时摄影视频")
# create style style_resetdevide_cb_2_main_main_default
style_resetdevide_cb_2_main_main_default = lv.style_t()
style_resetdevide_cb_2_main_main_default.init()
style_resetdevide_cb_2_main_main_default.set_radius(0)
style_resetdevide_cb_2_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_resetdevide_cb_2_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_resetdevide_cb_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_cb_2_main_main_default.set_bg_opa(0)
style_resetdevide_cb_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_resetdevide_cb_2_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_resetdevide_cb_2_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_resetdevide_cb_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_resetdevide_cb_2_main_main_default.set_text_letter_space(0)

# add style for resetdevide_cb_2
resetdevide_cb_2.add_style(style_resetdevide_cb_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_resetdevide_cb_2_main_indicator_default
style_resetdevide_cb_2_main_indicator_default = lv.style_t()
style_resetdevide_cb_2_main_indicator_default.init()
style_resetdevide_cb_2_main_indicator_default.set_radius(0)
style_resetdevide_cb_2_main_indicator_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_resetdevide_cb_2_main_indicator_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_resetdevide_cb_2_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_cb_2_main_indicator_default.set_bg_opa(0)
style_resetdevide_cb_2_main_indicator_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_resetdevide_cb_2_main_indicator_default.set_border_width(2)

# add style for resetdevide_cb_2
resetdevide_cb_2.add_style(style_resetdevide_cb_2_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_resetdevide_cb_2_main_indicator_checked
style_resetdevide_cb_2_main_indicator_checked = lv.style_t()
style_resetdevide_cb_2_main_indicator_checked.init()
style_resetdevide_cb_2_main_indicator_checked.set_radius(0)
style_resetdevide_cb_2_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_resetdevide_cb_2_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_resetdevide_cb_2_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_cb_2_main_indicator_checked.set_bg_opa(0)
style_resetdevide_cb_2_main_indicator_checked.set_border_color(lv.color_make(0xff,0xff,0xff))
style_resetdevide_cb_2_main_indicator_checked.set_border_width(2)

# add style for resetdevide_cb_2
resetdevide_cb_2.add_style(style_resetdevide_cb_2_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

resetdevide_cb_3 = lv.checkbox(resetdevide_cont_1)
resetdevide_cb_3.set_pos(36,268)
resetdevide_cb_3.set_text("Gcode文件")
# create style style_resetdevide_cb_3_main_main_default
style_resetdevide_cb_3_main_main_default = lv.style_t()
style_resetdevide_cb_3_main_main_default.init()
style_resetdevide_cb_3_main_main_default.set_radius(0)
style_resetdevide_cb_3_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_resetdevide_cb_3_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_resetdevide_cb_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_cb_3_main_main_default.set_bg_opa(0)
style_resetdevide_cb_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_resetdevide_cb_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_resetdevide_cb_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_resetdevide_cb_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_resetdevide_cb_3_main_main_default.set_text_letter_space(0)

# add style for resetdevide_cb_3
resetdevide_cb_3.add_style(style_resetdevide_cb_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_resetdevide_cb_3_main_indicator_default
style_resetdevide_cb_3_main_indicator_default = lv.style_t()
style_resetdevide_cb_3_main_indicator_default.init()
style_resetdevide_cb_3_main_indicator_default.set_radius(0)
style_resetdevide_cb_3_main_indicator_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_resetdevide_cb_3_main_indicator_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_resetdevide_cb_3_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_cb_3_main_indicator_default.set_bg_opa(0)
style_resetdevide_cb_3_main_indicator_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_resetdevide_cb_3_main_indicator_default.set_border_width(2)

# add style for resetdevide_cb_3
resetdevide_cb_3.add_style(style_resetdevide_cb_3_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_resetdevide_cb_3_main_indicator_checked
style_resetdevide_cb_3_main_indicator_checked = lv.style_t()
style_resetdevide_cb_3_main_indicator_checked.init()
style_resetdevide_cb_3_main_indicator_checked.set_radius(0)
style_resetdevide_cb_3_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_resetdevide_cb_3_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_resetdevide_cb_3_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_cb_3_main_indicator_checked.set_bg_opa(0)
style_resetdevide_cb_3_main_indicator_checked.set_border_color(lv.color_make(0xff,0xff,0xff))
style_resetdevide_cb_3_main_indicator_checked.set_border_width(2)

# add style for resetdevide_cb_3
resetdevide_cb_3.add_style(style_resetdevide_cb_3_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

resetdevide_cb_4 = lv.checkbox(resetdevide_cont_1)
resetdevide_cb_4.set_pos(36,325)
resetdevide_cb_4.set_text("打印记录")
# create style style_resetdevide_cb_4_main_main_default
style_resetdevide_cb_4_main_main_default = lv.style_t()
style_resetdevide_cb_4_main_main_default.init()
style_resetdevide_cb_4_main_main_default.set_radius(0)
style_resetdevide_cb_4_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_resetdevide_cb_4_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_resetdevide_cb_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_cb_4_main_main_default.set_bg_opa(0)
style_resetdevide_cb_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_resetdevide_cb_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_resetdevide_cb_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_resetdevide_cb_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_resetdevide_cb_4_main_main_default.set_text_letter_space(0)

# add style for resetdevide_cb_4
resetdevide_cb_4.add_style(style_resetdevide_cb_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_resetdevide_cb_4_main_indicator_default
style_resetdevide_cb_4_main_indicator_default = lv.style_t()
style_resetdevide_cb_4_main_indicator_default.init()
style_resetdevide_cb_4_main_indicator_default.set_radius(0)
style_resetdevide_cb_4_main_indicator_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_resetdevide_cb_4_main_indicator_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_resetdevide_cb_4_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_cb_4_main_indicator_default.set_bg_opa(0)
style_resetdevide_cb_4_main_indicator_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_resetdevide_cb_4_main_indicator_default.set_border_width(2)

# add style for resetdevide_cb_4
resetdevide_cb_4.add_style(style_resetdevide_cb_4_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_resetdevide_cb_4_main_indicator_checked
style_resetdevide_cb_4_main_indicator_checked = lv.style_t()
style_resetdevide_cb_4_main_indicator_checked.init()
style_resetdevide_cb_4_main_indicator_checked.set_radius(0)
style_resetdevide_cb_4_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_resetdevide_cb_4_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_resetdevide_cb_4_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_cb_4_main_indicator_checked.set_bg_opa(0)
style_resetdevide_cb_4_main_indicator_checked.set_border_color(lv.color_make(0xff,0xff,0xff))
style_resetdevide_cb_4_main_indicator_checked.set_border_width(2)

# add style for resetdevide_cb_4
resetdevide_cb_4.add_style(style_resetdevide_cb_4_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

resetdevide_btn_2 = lv.btn(resetdevide_cont_1)
resetdevide_btn_2.set_pos(27,700)
resetdevide_btn_2.set_size(426,65)
resetdevide_btn_2_label = lv.label(resetdevide_btn_2)
resetdevide_btn_2_label.set_text("恢复")
resetdevide_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
resetdevide_btn_2_label.align(lv.ALIGN.CENTER,0,0)
resetdevide_btn_2_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    resetdevide_btn_2_label.set_style_text_font(lv.font_simsun_28, lv.STATE.DEFAULT)
except AttributeError:
    try:
        resetdevide_btn_2_label.set_style_text_font(lv.font_montserrat_28, lv.STATE.DEFAULT)
    except AttributeError:
        resetdevide_btn_2_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_resetdevide_btn_2_main_main_default
style_resetdevide_btn_2_main_main_default = lv.style_t()
style_resetdevide_btn_2_main_main_default.init()
style_resetdevide_btn_2_main_main_default.set_radius(8)
style_resetdevide_btn_2_main_main_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_resetdevide_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_resetdevide_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_btn_2_main_main_default.set_bg_opa(255)
style_resetdevide_btn_2_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_resetdevide_btn_2_main_main_default.set_shadow_opa(0)
style_resetdevide_btn_2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_resetdevide_btn_2_main_main_default.set_border_width(0)
style_resetdevide_btn_2_main_main_default.set_border_opa(255)

# add style for resetdevide_btn_2
resetdevide_btn_2.add_style(style_resetdevide_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

resetdevide_label_1 = lv.label(resetdevide_cont_1)
resetdevide_label_1.set_pos(0,0)
resetdevide_label_1.set_size(480,53)
# create style style_resetdevide_label_1_main_main_default
style_resetdevide_label_1_main_main_default = lv.style_t()
style_resetdevide_label_1_main_main_default.init()
style_resetdevide_label_1_main_main_default.set_radius(0)
style_resetdevide_label_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_resetdevide_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_resetdevide_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_label_1_main_main_default.set_bg_opa(255)
style_resetdevide_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_resetdevide_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_resetdevide_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_resetdevide_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_resetdevide_label_1_main_main_default.set_text_letter_space(2)
style_resetdevide_label_1_main_main_default.set_pad_left(0)
style_resetdevide_label_1_main_main_default.set_pad_right(0)
style_resetdevide_label_1_main_main_default.set_pad_top(0)
style_resetdevide_label_1_main_main_default.set_pad_bottom(0)

# add style for resetdevide_label_1
resetdevide_label_1.add_style(style_resetdevide_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

resetdevide_label_4 = lv.label(resetdevide_cont_1)
resetdevide_label_4.set_pos(36,80)
resetdevide_label_4.set_size(350,28)
resetdevide_label_4.set_text("清除选项")
resetdevide_label_4.set_long_mode(lv.label.LONG.WRAP)
resetdevide_label_4.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_resetdevide_label_4_main_main_default
style_resetdevide_label_4_main_main_default = lv.style_t()
style_resetdevide_label_4_main_main_default.init()
style_resetdevide_label_4_main_main_default.set_radius(0)
style_resetdevide_label_4_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_resetdevide_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_resetdevide_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_label_4_main_main_default.set_bg_opa(0)
style_resetdevide_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_resetdevide_label_4_main_main_default.set_text_font(lv.font_simsun_28)
except AttributeError:
    try:
        style_resetdevide_label_4_main_main_default.set_text_font(lv.font_montserrat_28)
    except AttributeError:
        style_resetdevide_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_resetdevide_label_4_main_main_default.set_text_letter_space(0)
style_resetdevide_label_4_main_main_default.set_pad_left(0)
style_resetdevide_label_4_main_main_default.set_pad_right(0)
style_resetdevide_label_4_main_main_default.set_pad_top(0)
style_resetdevide_label_4_main_main_default.set_pad_bottom(0)

# add style for resetdevide_label_4
resetdevide_label_4.add_style(style_resetdevide_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

resetdevide_btn_1 = lv.btn(resetdevide_cont_1)
resetdevide_btn_1.set_pos(0,0)
resetdevide_btn_1.set_size(85,50)
# create style style_resetdevide_btn_1_main_main_default
style_resetdevide_btn_1_main_main_default = lv.style_t()
style_resetdevide_btn_1_main_main_default.init()
style_resetdevide_btn_1_main_main_default.set_radius(0)
style_resetdevide_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_resetdevide_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_resetdevide_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_btn_1_main_main_default.set_bg_opa(0)
style_resetdevide_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_resetdevide_btn_1_main_main_default.set_shadow_opa(0)
style_resetdevide_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_resetdevide_btn_1_main_main_default.set_border_width(0)
style_resetdevide_btn_1_main_main_default.set_border_opa(255)

# add style for resetdevide_btn_1
resetdevide_btn_1.add_style(style_resetdevide_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

resetdevide_img_1 = lv.img(resetdevide_cont_1)
resetdevide_img_1.set_pos(21,17)
resetdevide_img_1.set_size(36,24)
resetdevide_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png','rb') as f:
        resetdevide_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png')
    sys.exit()

resetdevide_img_1_img = lv.img_dsc_t({
  'data_size': len(resetdevide_img_1_img_data),
  'header': {'always_zero': 0, 'w': 36, 'h': 24, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': resetdevide_img_1_img_data
})

resetdevide_img_1.set_src(resetdevide_img_1_img)
resetdevide_img_1.set_pivot(0,0)
resetdevide_img_1.set_angle(0)
# create style style_resetdevide_img_1_main_main_default
style_resetdevide_img_1_main_main_default = lv.style_t()
style_resetdevide_img_1_main_main_default.init()
style_resetdevide_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_resetdevide_img_1_main_main_default.set_img_recolor_opa(0)
style_resetdevide_img_1_main_main_default.set_img_opa(255)

# add style for resetdevide_img_1
resetdevide_img_1.add_style(style_resetdevide_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

resetdevide_label_2 = lv.label(resetdevide_cont_1)
resetdevide_label_2.set_pos(90,11)
resetdevide_label_2.set_size(300,32)
resetdevide_label_2.set_text("恢复出厂")
resetdevide_label_2.set_long_mode(lv.label.LONG.WRAP)
resetdevide_label_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_resetdevide_label_2_main_main_default
style_resetdevide_label_2_main_main_default = lv.style_t()
style_resetdevide_label_2_main_main_default.init()
style_resetdevide_label_2_main_main_default.set_radius(0)
style_resetdevide_label_2_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_resetdevide_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_resetdevide_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_label_2_main_main_default.set_bg_opa(0)
style_resetdevide_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_resetdevide_label_2_main_main_default.set_text_font(lv.font_simsun_32)
except AttributeError:
    try:
        style_resetdevide_label_2_main_main_default.set_text_font(lv.font_montserrat_32)
    except AttributeError:
        style_resetdevide_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_resetdevide_label_2_main_main_default.set_text_letter_space(2)
style_resetdevide_label_2_main_main_default.set_pad_left(0)
style_resetdevide_label_2_main_main_default.set_pad_right(0)
style_resetdevide_label_2_main_main_default.set_pad_top(0)
style_resetdevide_label_2_main_main_default.set_pad_bottom(0)

# add style for resetdevide_label_2
resetdevide_label_2.add_style(style_resetdevide_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_resetdevide_cont_1_main_main_default
style_resetdevide_cont_1_main_main_default = lv.style_t()
style_resetdevide_cont_1_main_main_default.init()
style_resetdevide_cont_1_main_main_default.set_radius(0)
style_resetdevide_cont_1_main_main_default.set_bg_color(lv.color_make(0x23,0x24,0x26))
style_resetdevide_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x23,0x24,0x26))
style_resetdevide_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_resetdevide_cont_1_main_main_default.set_bg_opa(255)
style_resetdevide_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_resetdevide_cont_1_main_main_default.set_border_width(0)
style_resetdevide_cont_1_main_main_default.set_border_opa(255)
style_resetdevide_cont_1_main_main_default.set_pad_left(0)
style_resetdevide_cont_1_main_main_default.set_pad_right(0)
style_resetdevide_cont_1_main_main_default.set_pad_top(0)
style_resetdevide_cont_1_main_main_default.set_pad_bottom(0)

# add style for resetdevide_cont_1
resetdevide_cont_1.add_style(style_resetdevide_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_network = lv.obj()
# create style style_settings_network_main_main_default
style_settings_network_main_main_default = lv.style_t()
style_settings_network_main_main_default.init()
style_settings_network_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_network_main_main_default.set_bg_opa(0)

# add style for settings_network
settings_network.add_style(style_settings_network_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_network_tabview_1 = lv.tabview(settings_network, lv.DIR.TOP, 50)
settings_network_tabview_1_tab_btns = settings_network_tabview_1.get_tab_btns()
# create style style_settings_network_tabview_1_extra_btnm_main_default
style_settings_network_tabview_1_extra_btnm_main_default = lv.style_t()
style_settings_network_tabview_1_extra_btnm_main_default.init()
style_settings_network_tabview_1_extra_btnm_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_network_tabview_1_extra_btnm_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_network_tabview_1_extra_btnm_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_network_tabview_1_extra_btnm_main_default.set_bg_opa(255)
style_settings_network_tabview_1_extra_btnm_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_network_tabview_1_extra_btnm_main_default.set_border_width(0)
style_settings_network_tabview_1_extra_btnm_main_default.set_border_opa(100)
style_settings_network_tabview_1_extra_btnm_main_default.set_pad_left(0)
style_settings_network_tabview_1_extra_btnm_main_default.set_pad_right(0)
style_settings_network_tabview_1_extra_btnm_main_default.set_pad_top(0)
style_settings_network_tabview_1_extra_btnm_main_default.set_pad_bottom(0)

# add style for settings_network_tabview_1_tab_btns
settings_network_tabview_1_tab_btns.add_style(style_settings_network_tabview_1_extra_btnm_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_network_tabview_1_extra_btnm_items_default
style_settings_network_tabview_1_extra_btnm_items_default = lv.style_t()
style_settings_network_tabview_1_extra_btnm_items_default.init()
style_settings_network_tabview_1_extra_btnm_items_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_settings_network_tabview_1_extra_btnm_items_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_settings_network_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_settings_network_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_16)

# add style for settings_network_tabview_1_tab_btns
settings_network_tabview_1_tab_btns.add_style(style_settings_network_tabview_1_extra_btnm_items_default, lv.PART.ITEMS|lv.STATE.DEFAULT)

# create style style_settings_network_tabview_1_extra_btnm_items_checked
style_settings_network_tabview_1_extra_btnm_items_checked = lv.style_t()
style_settings_network_tabview_1_extra_btnm_items_checked.init()
style_settings_network_tabview_1_extra_btnm_items_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_network_tabview_1_extra_btnm_items_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_network_tabview_1_extra_btnm_items_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_network_tabview_1_extra_btnm_items_checked.set_bg_opa(60)
style_settings_network_tabview_1_extra_btnm_items_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_network_tabview_1_extra_btnm_items_checked.set_border_width(4)
style_settings_network_tabview_1_extra_btnm_items_checked.set_border_opa(255)
style_settings_network_tabview_1_extra_btnm_items_checked.set_border_side(lv.BORDER_SIDE.BOTTOM)
style_settings_network_tabview_1_extra_btnm_items_checked.set_text_color(lv.color_make(0x21,0x95,0xf6))
try:
    style_settings_network_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_settings_network_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_settings_network_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_16)

# add style for settings_network_tabview_1_tab_btns
settings_network_tabview_1_tab_btns.add_style(style_settings_network_tabview_1_extra_btnm_items_checked, lv.PART.ITEMS|lv.STATE.CHECKED)

settings_network_tabview_1_title1 = settings_network_tabview_1.add_tab("title1")
settings_network_tabview_1_title2 = settings_network_tabview_1.add_tab("title2")
settings_network_tabview_1_title3 = settings_network_tabview_1.add_tab("title3")
settings_network_tabview_1_Title = settings_network_tabview_1.add_tab("Title")
settings_network_tabview_1.set_pos(0,0)
settings_network_tabview_1.set_size(480,720)
# create style style_settings_network_tabview_1_main_main_default
style_settings_network_tabview_1_main_main_default = lv.style_t()
style_settings_network_tabview_1_main_main_default.init()
style_settings_network_tabview_1_main_main_default.set_bg_color(lv.color_make(0xea,0xef,0xf3))
style_settings_network_tabview_1_main_main_default.set_bg_grad_color(lv.color_make(0xea,0xef,0xf3))
style_settings_network_tabview_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_network_tabview_1_main_main_default.set_bg_opa(255)
style_settings_network_tabview_1_main_main_default.set_border_color(lv.color_make(0xc0,0xc0,0xc0))
style_settings_network_tabview_1_main_main_default.set_border_width(0)
style_settings_network_tabview_1_main_main_default.set_border_opa(100)
style_settings_network_tabview_1_main_main_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_settings_network_tabview_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_settings_network_tabview_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_settings_network_tabview_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_network_tabview_1_main_main_default.set_text_letter_space(2)
style_settings_network_tabview_1_main_main_default.set_text_line_space(16)

# add style for settings_network_tabview_1
settings_network_tabview_1.add_style(style_settings_network_tabview_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_network_cont_1 = lv.obj(settings_network)
settings_network_cont_1.set_pos(0,0)
settings_network_cont_1.set_size(480,800)
settings_network_label_4 = lv.label(settings_network_cont_1)
settings_network_label_4.set_pos(7,61)
settings_network_label_4.set_size(460,648)
# create style style_settings_network_label_4_main_main_default
style_settings_network_label_4_main_main_default = lv.style_t()
style_settings_network_label_4_main_main_default.init()
style_settings_network_label_4_main_main_default.set_radius(0)
style_settings_network_label_4_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_network_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_network_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_network_label_4_main_main_default.set_bg_opa(255)
style_settings_network_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_network_label_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_network_label_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_network_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_network_label_4_main_main_default.set_text_letter_space(0)
style_settings_network_label_4_main_main_default.set_pad_left(0)
style_settings_network_label_4_main_main_default.set_pad_right(0)
style_settings_network_label_4_main_main_default.set_pad_top(0)
style_settings_network_label_4_main_main_default.set_pad_bottom(0)

# add style for settings_network_label_4
settings_network_label_4.add_style(style_settings_network_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_network_list_1 = lv.list(settings_network_cont_1)
settings_network_list_1.set_pos(25,154)
settings_network_list_1.set_size(430,500)
# create style style_settings_network_list_1_extra_btns_main_default
style_settings_network_list_1_extra_btns_main_default = lv.style_t()
style_settings_network_list_1_extra_btns_main_default.init()
style_settings_network_list_1_extra_btns_main_default.set_radius(3)
style_settings_network_list_1_extra_btns_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_network_list_1_extra_btns_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_network_list_1_extra_btns_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_network_list_1_extra_btns_main_default.set_bg_opa(255)
style_settings_network_list_1_extra_btns_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_settings_network_list_1_extra_btns_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_network_list_1_extra_btns_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_network_list_1_extra_btns_main_default.set_text_font(lv.font_montserrat_16)


settings_network_list_1_btn_0 = settings_network_list_1.add_btn(lv.SYMBOL.SAVE, "save")

# add style for settings_network_list_1_btn_0
settings_network_list_1_btn_0.add_style(style_settings_network_list_1_extra_btns_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_network_list_1_main_main_default
style_settings_network_list_1_main_main_default = lv.style_t()
style_settings_network_list_1_main_main_default.init()
style_settings_network_list_1_main_main_default.set_radius(3)
style_settings_network_list_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_network_list_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_network_list_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_network_list_1_main_main_default.set_bg_opa(0)
style_settings_network_list_1_main_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_settings_network_list_1_main_main_default.set_border_width(1)
style_settings_network_list_1_main_main_default.set_pad_left(5)
style_settings_network_list_1_main_main_default.set_pad_right(5)
style_settings_network_list_1_main_main_default.set_pad_top(5)

# add style for settings_network_list_1
settings_network_list_1.add_style(style_settings_network_list_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_network_list_1_main_scrollbar_default
style_settings_network_list_1_main_scrollbar_default = lv.style_t()
style_settings_network_list_1_main_scrollbar_default.init()
style_settings_network_list_1_main_scrollbar_default.set_radius(3)
style_settings_network_list_1_main_scrollbar_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_network_list_1_main_scrollbar_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_network_list_1_main_scrollbar_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_network_list_1_main_scrollbar_default.set_bg_opa(255)

# add style for settings_network_list_1
settings_network_list_1.add_style(style_settings_network_list_1_main_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

settings_network_img_6 = lv.img(settings_network_cont_1)
settings_network_img_6.set_pos(439,76)
settings_network_img_6.set_size(14,28)
settings_network_img_6.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png','rb') as f:
        settings_network_img_6_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png')
    sys.exit()

settings_network_img_6_img = lv.img_dsc_t({
  'data_size': len(settings_network_img_6_img_data),
  'header': {'always_zero': 0, 'w': 14, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_network_img_6_img_data
})

settings_network_img_6.set_src(settings_network_img_6_img)
settings_network_img_6.set_pivot(0,0)
settings_network_img_6.set_angle(0)
# create style style_settings_network_img_6_main_main_default
style_settings_network_img_6_main_main_default = lv.style_t()
style_settings_network_img_6_main_main_default.init()
style_settings_network_img_6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_network_img_6_main_main_default.set_img_recolor_opa(0)
style_settings_network_img_6_main_main_default.set_img_opa(255)

# add style for settings_network_img_6
settings_network_img_6.add_style(style_settings_network_img_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_network_label_3 = lv.label(settings_network_cont_1)
settings_network_label_3.set_pos(25,78)
settings_network_label_3.set_size(110,24)
settings_network_label_3.set_text("本地网络")
settings_network_label_3.set_long_mode(lv.label.LONG.WRAP)
settings_network_label_3.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_settings_network_label_3_main_main_default
style_settings_network_label_3_main_main_default = lv.style_t()
style_settings_network_label_3_main_main_default.init()
style_settings_network_label_3_main_main_default.set_radius(0)
style_settings_network_label_3_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_network_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_network_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_network_label_3_main_main_default.set_bg_opa(0)
style_settings_network_label_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_network_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_network_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_network_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_network_label_3_main_main_default.set_text_letter_space(0)
style_settings_network_label_3_main_main_default.set_pad_left(0)
style_settings_network_label_3_main_main_default.set_pad_right(0)
style_settings_network_label_3_main_main_default.set_pad_top(0)
style_settings_network_label_3_main_main_default.set_pad_bottom(0)

# add style for settings_network_label_3
settings_network_label_3.add_style(style_settings_network_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_network_label_5 = lv.label(settings_network_cont_1)
settings_network_label_5.set_pos(360,78)
settings_network_label_5.set_size(73,24)
settings_network_label_5.set_text("已连接")
settings_network_label_5.set_long_mode(lv.label.LONG.WRAP)
settings_network_label_5.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_settings_network_label_5_main_main_default
style_settings_network_label_5_main_main_default = lv.style_t()
style_settings_network_label_5_main_main_default.init()
style_settings_network_label_5_main_main_default.set_radius(0)
style_settings_network_label_5_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_network_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_network_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_network_label_5_main_main_default.set_bg_opa(0)
style_settings_network_label_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_network_label_5_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_network_label_5_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_network_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_network_label_5_main_main_default.set_text_letter_space(0)
style_settings_network_label_5_main_main_default.set_pad_left(0)
style_settings_network_label_5_main_main_default.set_pad_right(0)
style_settings_network_label_5_main_main_default.set_pad_top(0)
style_settings_network_label_5_main_main_default.set_pad_bottom(0)

# add style for settings_network_label_5
settings_network_label_5.add_style(style_settings_network_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_network_btn_1 = lv.btn(settings_network_cont_1)
settings_network_btn_1.set_pos(357,66)
settings_network_btn_1.set_size(100,50)
# create style style_settings_network_btn_1_main_main_default
style_settings_network_btn_1_main_main_default = lv.style_t()
style_settings_network_btn_1_main_main_default.init()
style_settings_network_btn_1_main_main_default.set_radius(0)
style_settings_network_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_network_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_network_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_network_btn_1_main_main_default.set_bg_opa(0)
style_settings_network_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_settings_network_btn_1_main_main_default.set_shadow_opa(0)
style_settings_network_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_network_btn_1_main_main_default.set_border_width(0)
style_settings_network_btn_1_main_main_default.set_border_opa(255)

# add style for settings_network_btn_1
settings_network_btn_1.add_style(style_settings_network_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_network_label_1 = lv.label(settings_network_cont_1)
settings_network_label_1.set_pos(0,719)
settings_network_label_1.set_size(480,80)
# create style style_settings_network_label_1_main_main_default
style_settings_network_label_1_main_main_default = lv.style_t()
style_settings_network_label_1_main_main_default.init()
style_settings_network_label_1_main_main_default.set_radius(0)
style_settings_network_label_1_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_settings_network_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_settings_network_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_network_label_1_main_main_default.set_bg_opa(255)
style_settings_network_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_network_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_network_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_network_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_network_label_1_main_main_default.set_text_letter_space(0)
style_settings_network_label_1_main_main_default.set_pad_left(0)
style_settings_network_label_1_main_main_default.set_pad_right(0)
style_settings_network_label_1_main_main_default.set_pad_top(0)
style_settings_network_label_1_main_main_default.set_pad_bottom(0)

# add style for settings_network_label_1
settings_network_label_1.add_style(style_settings_network_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_network_img_1 = lv.img(settings_network_cont_1)
settings_network_img_1.set_pos(30,742)
settings_network_img_1.set_size(48,48)
settings_network_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png','rb') as f:
        settings_network_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png')
    sys.exit()

settings_network_img_1_img = lv.img_dsc_t({
  'data_size': len(settings_network_img_1_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_network_img_1_img_data
})

settings_network_img_1.set_src(settings_network_img_1_img)
settings_network_img_1.set_pivot(0,0)
settings_network_img_1.set_angle(0)
# create style style_settings_network_img_1_main_main_default
style_settings_network_img_1_main_main_default = lv.style_t()
style_settings_network_img_1_main_main_default.init()
style_settings_network_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_network_img_1_main_main_default.set_img_recolor_opa(0)
style_settings_network_img_1_main_main_default.set_img_opa(255)

# add style for settings_network_img_1
settings_network_img_1.add_style(style_settings_network_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_network_img_2 = lv.img(settings_network_cont_1)
settings_network_img_2.set_pos(128,742)
settings_network_img_2.set_size(48,48)
settings_network_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png','rb') as f:
        settings_network_img_2_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png')
    sys.exit()

settings_network_img_2_img = lv.img_dsc_t({
  'data_size': len(settings_network_img_2_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_network_img_2_img_data
})

settings_network_img_2.set_src(settings_network_img_2_img)
settings_network_img_2.set_pivot(0,0)
settings_network_img_2.set_angle(0)
# create style style_settings_network_img_2_main_main_default
style_settings_network_img_2_main_main_default = lv.style_t()
style_settings_network_img_2_main_main_default.init()
style_settings_network_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_network_img_2_main_main_default.set_img_recolor_opa(0)
style_settings_network_img_2_main_main_default.set_img_opa(255)

# add style for settings_network_img_2
settings_network_img_2.add_style(style_settings_network_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_network_img_3 = lv.img(settings_network_cont_1)
settings_network_img_3.set_pos(224,742)
settings_network_img_3.set_size(48,48)
settings_network_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png','rb') as f:
        settings_network_img_3_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png')
    sys.exit()

settings_network_img_3_img = lv.img_dsc_t({
  'data_size': len(settings_network_img_3_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_network_img_3_img_data
})

settings_network_img_3.set_src(settings_network_img_3_img)
settings_network_img_3.set_pivot(0,0)
settings_network_img_3.set_angle(0)
# create style style_settings_network_img_3_main_main_default
style_settings_network_img_3_main_main_default = lv.style_t()
style_settings_network_img_3_main_main_default.init()
style_settings_network_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_network_img_3_main_main_default.set_img_recolor_opa(0)
style_settings_network_img_3_main_main_default.set_img_opa(255)

# add style for settings_network_img_3
settings_network_img_3.add_style(style_settings_network_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_network_img_4 = lv.img(settings_network_cont_1)
settings_network_img_4.set_pos(318,742)
settings_network_img_4.set_size(48,48)
settings_network_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png','rb') as f:
        settings_network_img_4_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png')
    sys.exit()

settings_network_img_4_img = lv.img_dsc_t({
  'data_size': len(settings_network_img_4_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_network_img_4_img_data
})

settings_network_img_4.set_src(settings_network_img_4_img)
settings_network_img_4.set_pivot(0,0)
settings_network_img_4.set_angle(0)
# create style style_settings_network_img_4_main_main_default
style_settings_network_img_4_main_main_default = lv.style_t()
style_settings_network_img_4_main_main_default.init()
style_settings_network_img_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_network_img_4_main_main_default.set_img_recolor_opa(0)
style_settings_network_img_4_main_main_default.set_img_opa(255)

# add style for settings_network_img_4
settings_network_img_4.add_style(style_settings_network_img_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_network_img_5 = lv.img(settings_network_cont_1)
settings_network_img_5.set_pos(414,742)
settings_network_img_5.set_size(48,48)
settings_network_img_5.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png','rb') as f:
        settings_network_img_5_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png')
    sys.exit()

settings_network_img_5_img = lv.img_dsc_t({
  'data_size': len(settings_network_img_5_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_network_img_5_img_data
})

settings_network_img_5.set_src(settings_network_img_5_img)
settings_network_img_5.set_pivot(0,0)
settings_network_img_5.set_angle(0)
# create style style_settings_network_img_5_main_main_default
style_settings_network_img_5_main_main_default = lv.style_t()
style_settings_network_img_5_main_main_default.init()
style_settings_network_img_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_network_img_5_main_main_default.set_img_recolor_opa(0)
style_settings_network_img_5_main_main_default.set_img_opa(255)

# add style for settings_network_img_5
settings_network_img_5.add_style(style_settings_network_img_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_network_cont_1_main_main_default
style_settings_network_cont_1_main_main_default = lv.style_t()
style_settings_network_cont_1_main_main_default.init()
style_settings_network_cont_1_main_main_default.set_radius(0)
style_settings_network_cont_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_settings_network_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_settings_network_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_network_cont_1_main_main_default.set_bg_opa(255)
style_settings_network_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_network_cont_1_main_main_default.set_border_width(0)
style_settings_network_cont_1_main_main_default.set_border_opa(255)
style_settings_network_cont_1_main_main_default.set_pad_left(0)
style_settings_network_cont_1_main_main_default.set_pad_right(0)
style_settings_network_cont_1_main_main_default.set_pad_top(0)
style_settings_network_cont_1_main_main_default.set_pad_bottom(0)

# add style for settings_network_cont_1
settings_network_cont_1.add_style(style_settings_network_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_selftest = lv.obj()
# create style style_settings_selftest_main_main_default
style_settings_selftest_main_main_default = lv.style_t()
style_settings_selftest_main_main_default.init()
style_settings_selftest_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_main_main_default.set_bg_opa(0)

# add style for settings_selftest
settings_selftest.add_style(style_settings_selftest_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_selftest_tabview_1 = lv.tabview(settings_selftest, lv.DIR.TOP, 50)
settings_selftest_tabview_1_tab_btns = settings_selftest_tabview_1.get_tab_btns()
# create style style_settings_selftest_tabview_1_extra_btnm_main_default
style_settings_selftest_tabview_1_extra_btnm_main_default = lv.style_t()
style_settings_selftest_tabview_1_extra_btnm_main_default.init()
style_settings_selftest_tabview_1_extra_btnm_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_tabview_1_extra_btnm_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_tabview_1_extra_btnm_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_tabview_1_extra_btnm_main_default.set_bg_opa(255)
style_settings_selftest_tabview_1_extra_btnm_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_tabview_1_extra_btnm_main_default.set_border_width(0)
style_settings_selftest_tabview_1_extra_btnm_main_default.set_border_opa(100)
style_settings_selftest_tabview_1_extra_btnm_main_default.set_pad_left(0)
style_settings_selftest_tabview_1_extra_btnm_main_default.set_pad_right(0)
style_settings_selftest_tabview_1_extra_btnm_main_default.set_pad_top(0)
style_settings_selftest_tabview_1_extra_btnm_main_default.set_pad_bottom(0)

# add style for settings_selftest_tabview_1_tab_btns
settings_selftest_tabview_1_tab_btns.add_style(style_settings_selftest_tabview_1_extra_btnm_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_selftest_tabview_1_extra_btnm_items_default
style_settings_selftest_tabview_1_extra_btnm_items_default = lv.style_t()
style_settings_selftest_tabview_1_extra_btnm_items_default.init()
style_settings_selftest_tabview_1_extra_btnm_items_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_settings_selftest_tabview_1_extra_btnm_items_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_settings_selftest_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_settings_selftest_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_16)

# add style for settings_selftest_tabview_1_tab_btns
settings_selftest_tabview_1_tab_btns.add_style(style_settings_selftest_tabview_1_extra_btnm_items_default, lv.PART.ITEMS|lv.STATE.DEFAULT)

# create style style_settings_selftest_tabview_1_extra_btnm_items_checked
style_settings_selftest_tabview_1_extra_btnm_items_checked = lv.style_t()
style_settings_selftest_tabview_1_extra_btnm_items_checked.init()
style_settings_selftest_tabview_1_extra_btnm_items_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_tabview_1_extra_btnm_items_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_tabview_1_extra_btnm_items_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_tabview_1_extra_btnm_items_checked.set_bg_opa(60)
style_settings_selftest_tabview_1_extra_btnm_items_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_tabview_1_extra_btnm_items_checked.set_border_width(4)
style_settings_selftest_tabview_1_extra_btnm_items_checked.set_border_opa(255)
style_settings_selftest_tabview_1_extra_btnm_items_checked.set_border_side(lv.BORDER_SIDE.BOTTOM)
style_settings_selftest_tabview_1_extra_btnm_items_checked.set_text_color(lv.color_make(0x21,0x95,0xf6))
try:
    style_settings_selftest_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_settings_selftest_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_settings_selftest_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_16)

# add style for settings_selftest_tabview_1_tab_btns
settings_selftest_tabview_1_tab_btns.add_style(style_settings_selftest_tabview_1_extra_btnm_items_checked, lv.PART.ITEMS|lv.STATE.CHECKED)

settings_selftest_tabview_1_title1 = settings_selftest_tabview_1.add_tab("title1")
settings_selftest_tabview_1_title2 = settings_selftest_tabview_1.add_tab("title2")
settings_selftest_tabview_1_title3 = settings_selftest_tabview_1.add_tab("title3")
settings_selftest_tabview_1_Title = settings_selftest_tabview_1.add_tab("Title")
settings_selftest_tabview_1.set_pos(0,0)
settings_selftest_tabview_1.set_size(480,720)
# create style style_settings_selftest_tabview_1_main_main_default
style_settings_selftest_tabview_1_main_main_default = lv.style_t()
style_settings_selftest_tabview_1_main_main_default.init()
style_settings_selftest_tabview_1_main_main_default.set_bg_color(lv.color_make(0xea,0xef,0xf3))
style_settings_selftest_tabview_1_main_main_default.set_bg_grad_color(lv.color_make(0xea,0xef,0xf3))
style_settings_selftest_tabview_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_tabview_1_main_main_default.set_bg_opa(255)
style_settings_selftest_tabview_1_main_main_default.set_border_color(lv.color_make(0xc0,0xc0,0xc0))
style_settings_selftest_tabview_1_main_main_default.set_border_width(0)
style_settings_selftest_tabview_1_main_main_default.set_border_opa(100)
style_settings_selftest_tabview_1_main_main_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_settings_selftest_tabview_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_settings_selftest_tabview_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_settings_selftest_tabview_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_selftest_tabview_1_main_main_default.set_text_letter_space(2)
style_settings_selftest_tabview_1_main_main_default.set_text_line_space(16)

# add style for settings_selftest_tabview_1
settings_selftest_tabview_1.add_style(style_settings_selftest_tabview_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_selftest_cont_1 = lv.obj(settings_selftest)
settings_selftest_cont_1.set_pos(0,0)
settings_selftest_cont_1.set_size(480,800)
settings_selftest_label_2 = lv.label(settings_selftest_cont_1)
settings_selftest_label_2.set_pos(10,53)
settings_selftest_label_2.set_size(460,648)
# create style style_settings_selftest_label_2_main_main_default
style_settings_selftest_label_2_main_main_default = lv.style_t()
style_settings_selftest_label_2_main_main_default.init()
style_settings_selftest_label_2_main_main_default.set_radius(0)
style_settings_selftest_label_2_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_selftest_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_selftest_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_label_2_main_main_default.set_bg_opa(255)
style_settings_selftest_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_selftest_label_2_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_selftest_label_2_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_selftest_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_selftest_label_2_main_main_default.set_text_letter_space(0)
style_settings_selftest_label_2_main_main_default.set_pad_left(0)
style_settings_selftest_label_2_main_main_default.set_pad_right(0)
style_settings_selftest_label_2_main_main_default.set_pad_top(0)
style_settings_selftest_label_2_main_main_default.set_pad_bottom(0)

# add style for settings_selftest_label_2
settings_selftest_label_2.add_style(style_settings_selftest_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_selftest_btn_2 = lv.btn(settings_selftest_cont_1)
settings_selftest_btn_2.set_pos(27,625)
settings_selftest_btn_2.set_size(426,65)
settings_selftest_btn_2_label = lv.label(settings_selftest_btn_2)
settings_selftest_btn_2_label.set_text("开始检测")
settings_selftest_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
settings_selftest_btn_2_label.align(lv.ALIGN.CENTER,0,0)
settings_selftest_btn_2_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    settings_selftest_btn_2_label.set_style_text_font(lv.font_simsun_28, lv.STATE.DEFAULT)
except AttributeError:
    try:
        settings_selftest_btn_2_label.set_style_text_font(lv.font_montserrat_28, lv.STATE.DEFAULT)
    except AttributeError:
        settings_selftest_btn_2_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_settings_selftest_btn_2_main_main_default
style_settings_selftest_btn_2_main_main_default = lv.style_t()
style_settings_selftest_btn_2_main_main_default.init()
style_settings_selftest_btn_2_main_main_default.set_radius(5)
style_settings_selftest_btn_2_main_main_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_settings_selftest_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_settings_selftest_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_btn_2_main_main_default.set_bg_opa(255)
style_settings_selftest_btn_2_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_btn_2_main_main_default.set_shadow_opa(0)
style_settings_selftest_btn_2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_btn_2_main_main_default.set_border_width(0)
style_settings_selftest_btn_2_main_main_default.set_border_opa(255)

# add style for settings_selftest_btn_2
settings_selftest_btn_2.add_style(style_settings_selftest_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_selftest_label_5 = lv.label(settings_selftest_cont_1)
settings_selftest_label_5.set_pos(24,559)
settings_selftest_label_5.set_size(432,1)
# create style style_settings_selftest_label_5_main_main_default
style_settings_selftest_label_5_main_main_default = lv.style_t()
style_settings_selftest_label_5_main_main_default.init()
style_settings_selftest_label_5_main_main_default.set_radius(0)
style_settings_selftest_label_5_main_main_default.set_bg_color(lv.color_make(0x3a,0x3d,0x42))
style_settings_selftest_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x3a,0x3d,0x42))
style_settings_selftest_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_label_5_main_main_default.set_bg_opa(255)
style_settings_selftest_label_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_selftest_label_5_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_selftest_label_5_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_selftest_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_selftest_label_5_main_main_default.set_text_letter_space(0)
style_settings_selftest_label_5_main_main_default.set_pad_left(0)
style_settings_selftest_label_5_main_main_default.set_pad_right(0)
style_settings_selftest_label_5_main_main_default.set_pad_top(0)
style_settings_selftest_label_5_main_main_default.set_pad_bottom(0)

# add style for settings_selftest_label_5
settings_selftest_label_5.add_style(style_settings_selftest_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_selftest_btn_1 = lv.btn(settings_selftest_cont_1)
settings_selftest_btn_1.set_pos(405,78)
settings_selftest_btn_1.set_size(55,33)
settings_selftest_btn_1_label = lv.label(settings_selftest_btn_1)
settings_selftest_btn_1_label.set_text("全选")
settings_selftest_btn_1.set_style_pad_all(0, lv.STATE.DEFAULT)
settings_selftest_btn_1_label.align(lv.ALIGN.CENTER,0,0)
settings_selftest_btn_1_label.set_style_text_color(lv.color_make(0x42,0xdb,0xd8), lv.STATE.DEFAULT)
try:
    settings_selftest_btn_1_label.set_style_text_font(lv.font_simsun_24, lv.STATE.DEFAULT)
except AttributeError:
    try:
        settings_selftest_btn_1_label.set_style_text_font(lv.font_montserrat_24, lv.STATE.DEFAULT)
    except AttributeError:
        settings_selftest_btn_1_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_settings_selftest_btn_1_main_main_default
style_settings_selftest_btn_1_main_main_default = lv.style_t()
style_settings_selftest_btn_1_main_main_default.init()
style_settings_selftest_btn_1_main_main_default.set_radius(0)
style_settings_selftest_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_btn_1_main_main_default.set_bg_opa(0)
style_settings_selftest_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_btn_1_main_main_default.set_shadow_opa(0)
style_settings_selftest_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_btn_1_main_main_default.set_border_width(0)
style_settings_selftest_btn_1_main_main_default.set_border_opa(255)

# add style for settings_selftest_btn_1
settings_selftest_btn_1.add_style(style_settings_selftest_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_selftest_label_6 = lv.label(settings_selftest_cont_1)
settings_selftest_label_6.set_pos(24,566)
settings_selftest_label_6.set_size(379,24)
settings_selftest_label_6.set_text("自检过程预计需要15分钟。")
settings_selftest_label_6.set_long_mode(lv.label.LONG.WRAP)
settings_selftest_label_6.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_settings_selftest_label_6_main_main_default
style_settings_selftest_label_6_main_main_default = lv.style_t()
style_settings_selftest_label_6_main_main_default.init()
style_settings_selftest_label_6_main_main_default.set_radius(0)
style_settings_selftest_label_6_main_main_default.set_bg_color(lv.color_make(0x3a,0x3d,0x42))
style_settings_selftest_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x3a,0x3d,0x42))
style_settings_selftest_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_label_6_main_main_default.set_bg_opa(0)
style_settings_selftest_label_6_main_main_default.set_text_color(lv.color_make(0x6a,0x70,0x7d))
try:
    style_settings_selftest_label_6_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_selftest_label_6_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_selftest_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_selftest_label_6_main_main_default.set_text_letter_space(0)
style_settings_selftest_label_6_main_main_default.set_pad_left(0)
style_settings_selftest_label_6_main_main_default.set_pad_right(0)
style_settings_selftest_label_6_main_main_default.set_pad_top(0)
style_settings_selftest_label_6_main_main_default.set_pad_bottom(0)

# add style for settings_selftest_label_6
settings_selftest_label_6.add_style(style_settings_selftest_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_selftest_cb_1 = lv.checkbox(settings_selftest_cont_1)
settings_selftest_cb_1.set_pos(26,154)
settings_selftest_cb_1.set_text("开启喉管散热风扇")
# create style style_settings_selftest_cb_1_main_main_default
style_settings_selftest_cb_1_main_main_default = lv.style_t()
style_settings_selftest_cb_1_main_main_default.init()
style_settings_selftest_cb_1_main_main_default.set_radius(0)
style_settings_selftest_cb_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_1_main_main_default.set_bg_opa(0)
style_settings_selftest_cb_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_selftest_cb_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_selftest_cb_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_selftest_cb_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_selftest_cb_1_main_main_default.set_text_letter_space(0)

# add style for settings_selftest_cb_1
settings_selftest_cb_1.add_style(style_settings_selftest_cb_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_selftest_cb_1_main_indicator_default
style_settings_selftest_cb_1_main_indicator_default = lv.style_t()
style_settings_selftest_cb_1_main_indicator_default.init()
style_settings_selftest_cb_1_main_indicator_default.set_radius(0)
style_settings_selftest_cb_1_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_1_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_1_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_1_main_indicator_default.set_bg_opa(0)
style_settings_selftest_cb_1_main_indicator_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_1_main_indicator_default.set_border_width(3)

# add style for settings_selftest_cb_1
settings_selftest_cb_1.add_style(style_settings_selftest_cb_1_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_settings_selftest_cb_1_main_indicator_checked
style_settings_selftest_cb_1_main_indicator_checked = lv.style_t()
style_settings_selftest_cb_1_main_indicator_checked.init()
style_settings_selftest_cb_1_main_indicator_checked.set_radius(0)
style_settings_selftest_cb_1_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cb_1_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cb_1_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_1_main_indicator_checked.set_bg_opa(0)
style_settings_selftest_cb_1_main_indicator_checked.set_border_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_1_main_indicator_checked.set_border_width(3)

# add style for settings_selftest_cb_1
settings_selftest_cb_1.add_style(style_settings_selftest_cb_1_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

settings_selftest_cb_3 = lv.checkbox(settings_selftest_cont_1)
settings_selftest_cb_3.set_pos(26,233)
settings_selftest_cb_3.set_text("开启模型冷却风扇")
# create style style_settings_selftest_cb_3_main_main_default
style_settings_selftest_cb_3_main_main_default = lv.style_t()
style_settings_selftest_cb_3_main_main_default.init()
style_settings_selftest_cb_3_main_main_default.set_radius(0)
style_settings_selftest_cb_3_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_3_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_3_main_main_default.set_bg_opa(0)
style_settings_selftest_cb_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_selftest_cb_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_selftest_cb_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_selftest_cb_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_selftest_cb_3_main_main_default.set_text_letter_space(0)

# add style for settings_selftest_cb_3
settings_selftest_cb_3.add_style(style_settings_selftest_cb_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_selftest_cb_3_main_indicator_default
style_settings_selftest_cb_3_main_indicator_default = lv.style_t()
style_settings_selftest_cb_3_main_indicator_default.init()
style_settings_selftest_cb_3_main_indicator_default.set_radius(0)
style_settings_selftest_cb_3_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_3_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_3_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_3_main_indicator_default.set_bg_opa(0)
style_settings_selftest_cb_3_main_indicator_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_3_main_indicator_default.set_border_width(3)

# add style for settings_selftest_cb_3
settings_selftest_cb_3.add_style(style_settings_selftest_cb_3_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_settings_selftest_cb_3_main_indicator_checked
style_settings_selftest_cb_3_main_indicator_checked = lv.style_t()
style_settings_selftest_cb_3_main_indicator_checked.init()
style_settings_selftest_cb_3_main_indicator_checked.set_radius(0)
style_settings_selftest_cb_3_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cb_3_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cb_3_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_3_main_indicator_checked.set_bg_opa(0)
style_settings_selftest_cb_3_main_indicator_checked.set_border_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_3_main_indicator_checked.set_border_width(3)

# add style for settings_selftest_cb_3
settings_selftest_cb_3.add_style(style_settings_selftest_cb_3_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

settings_selftest_cb_5 = lv.checkbox(settings_selftest_cont_1)
settings_selftest_cb_5.set_pos(26,310)
settings_selftest_cb_5.set_text("喷头PID校准")
# create style style_settings_selftest_cb_5_main_main_default
style_settings_selftest_cb_5_main_main_default = lv.style_t()
style_settings_selftest_cb_5_main_main_default.init()
style_settings_selftest_cb_5_main_main_default.set_radius(0)
style_settings_selftest_cb_5_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_5_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_5_main_main_default.set_bg_opa(0)
style_settings_selftest_cb_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_selftest_cb_5_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_selftest_cb_5_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_selftest_cb_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_selftest_cb_5_main_main_default.set_text_letter_space(0)

# add style for settings_selftest_cb_5
settings_selftest_cb_5.add_style(style_settings_selftest_cb_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_selftest_cb_5_main_indicator_default
style_settings_selftest_cb_5_main_indicator_default = lv.style_t()
style_settings_selftest_cb_5_main_indicator_default.init()
style_settings_selftest_cb_5_main_indicator_default.set_radius(0)
style_settings_selftest_cb_5_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_5_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_5_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_5_main_indicator_default.set_bg_opa(0)
style_settings_selftest_cb_5_main_indicator_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_5_main_indicator_default.set_border_width(3)

# add style for settings_selftest_cb_5
settings_selftest_cb_5.add_style(style_settings_selftest_cb_5_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_settings_selftest_cb_5_main_indicator_checked
style_settings_selftest_cb_5_main_indicator_checked = lv.style_t()
style_settings_selftest_cb_5_main_indicator_checked.init()
style_settings_selftest_cb_5_main_indicator_checked.set_radius(0)
style_settings_selftest_cb_5_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cb_5_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cb_5_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_5_main_indicator_checked.set_bg_opa(0)
style_settings_selftest_cb_5_main_indicator_checked.set_border_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_5_main_indicator_checked.set_border_width(3)

# add style for settings_selftest_cb_5
settings_selftest_cb_5.add_style(style_settings_selftest_cb_5_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

settings_selftest_cb_7 = lv.checkbox(settings_selftest_cont_1)
settings_selftest_cb_7.set_pos(26,391)
settings_selftest_cb_7.set_text("热床PID校准")
# create style style_settings_selftest_cb_7_main_main_default
style_settings_selftest_cb_7_main_main_default = lv.style_t()
style_settings_selftest_cb_7_main_main_default.init()
style_settings_selftest_cb_7_main_main_default.set_radius(0)
style_settings_selftest_cb_7_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_7_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_7_main_main_default.set_bg_opa(0)
style_settings_selftest_cb_7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_selftest_cb_7_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_selftest_cb_7_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_selftest_cb_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_selftest_cb_7_main_main_default.set_text_letter_space(0)

# add style for settings_selftest_cb_7
settings_selftest_cb_7.add_style(style_settings_selftest_cb_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_selftest_cb_7_main_indicator_default
style_settings_selftest_cb_7_main_indicator_default = lv.style_t()
style_settings_selftest_cb_7_main_indicator_default.init()
style_settings_selftest_cb_7_main_indicator_default.set_radius(0)
style_settings_selftest_cb_7_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_7_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_7_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_7_main_indicator_default.set_bg_opa(0)
style_settings_selftest_cb_7_main_indicator_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_7_main_indicator_default.set_border_width(3)

# add style for settings_selftest_cb_7
settings_selftest_cb_7.add_style(style_settings_selftest_cb_7_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_settings_selftest_cb_7_main_indicator_checked
style_settings_selftest_cb_7_main_indicator_checked = lv.style_t()
style_settings_selftest_cb_7_main_indicator_checked.init()
style_settings_selftest_cb_7_main_indicator_checked.set_radius(0)
style_settings_selftest_cb_7_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cb_7_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cb_7_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_7_main_indicator_checked.set_bg_opa(0)
style_settings_selftest_cb_7_main_indicator_checked.set_border_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_7_main_indicator_checked.set_border_width(3)

# add style for settings_selftest_cb_7
settings_selftest_cb_7.add_style(style_settings_selftest_cb_7_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

settings_selftest_cb_9 = lv.checkbox(settings_selftest_cont_1)
settings_selftest_cb_9.set_pos(26,470)
settings_selftest_cb_9.set_text("振动补偿")
# create style style_settings_selftest_cb_9_main_main_default
style_settings_selftest_cb_9_main_main_default = lv.style_t()
style_settings_selftest_cb_9_main_main_default.init()
style_settings_selftest_cb_9_main_main_default.set_radius(0)
style_settings_selftest_cb_9_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_9_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_9_main_main_default.set_bg_opa(0)
style_settings_selftest_cb_9_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_selftest_cb_9_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_selftest_cb_9_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_selftest_cb_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_selftest_cb_9_main_main_default.set_text_letter_space(0)

# add style for settings_selftest_cb_9
settings_selftest_cb_9.add_style(style_settings_selftest_cb_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_selftest_cb_9_main_indicator_default
style_settings_selftest_cb_9_main_indicator_default = lv.style_t()
style_settings_selftest_cb_9_main_indicator_default.init()
style_settings_selftest_cb_9_main_indicator_default.set_radius(0)
style_settings_selftest_cb_9_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_9_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_9_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_9_main_indicator_default.set_bg_opa(0)
style_settings_selftest_cb_9_main_indicator_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_9_main_indicator_default.set_border_width(3)

# add style for settings_selftest_cb_9
settings_selftest_cb_9.add_style(style_settings_selftest_cb_9_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_settings_selftest_cb_9_main_indicator_checked
style_settings_selftest_cb_9_main_indicator_checked = lv.style_t()
style_settings_selftest_cb_9_main_indicator_checked.init()
style_settings_selftest_cb_9_main_indicator_checked.set_radius(0)
style_settings_selftest_cb_9_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cb_9_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cb_9_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_9_main_indicator_checked.set_bg_opa(0)
style_settings_selftest_cb_9_main_indicator_checked.set_border_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_9_main_indicator_checked.set_border_width(3)

# add style for settings_selftest_cb_9
settings_selftest_cb_9.add_style(style_settings_selftest_cb_9_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

settings_selftest_cb_8 = lv.checkbox(settings_selftest_cont_1)
settings_selftest_cb_8.set_pos(275,391)
settings_selftest_cb_8.set_text("自动调平")
# create style style_settings_selftest_cb_8_main_main_default
style_settings_selftest_cb_8_main_main_default = lv.style_t()
style_settings_selftest_cb_8_main_main_default.init()
style_settings_selftest_cb_8_main_main_default.set_radius(0)
style_settings_selftest_cb_8_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_8_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_8_main_main_default.set_bg_opa(0)
style_settings_selftest_cb_8_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_selftest_cb_8_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_selftest_cb_8_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_selftest_cb_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_selftest_cb_8_main_main_default.set_text_letter_space(0)

# add style for settings_selftest_cb_8
settings_selftest_cb_8.add_style(style_settings_selftest_cb_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_selftest_cb_8_main_indicator_default
style_settings_selftest_cb_8_main_indicator_default = lv.style_t()
style_settings_selftest_cb_8_main_indicator_default.init()
style_settings_selftest_cb_8_main_indicator_default.set_radius(0)
style_settings_selftest_cb_8_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_8_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_8_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_8_main_indicator_default.set_bg_opa(0)
style_settings_selftest_cb_8_main_indicator_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_8_main_indicator_default.set_border_width(3)

# add style for settings_selftest_cb_8
settings_selftest_cb_8.add_style(style_settings_selftest_cb_8_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_settings_selftest_cb_8_main_indicator_checked
style_settings_selftest_cb_8_main_indicator_checked = lv.style_t()
style_settings_selftest_cb_8_main_indicator_checked.init()
style_settings_selftest_cb_8_main_indicator_checked.set_radius(0)
style_settings_selftest_cb_8_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cb_8_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cb_8_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_8_main_indicator_checked.set_bg_opa(0)
style_settings_selftest_cb_8_main_indicator_checked.set_border_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_8_main_indicator_checked.set_border_width(3)

# add style for settings_selftest_cb_8
settings_selftest_cb_8.add_style(style_settings_selftest_cb_8_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

settings_selftest_cb_6 = lv.checkbox(settings_selftest_cont_1)
settings_selftest_cb_6.set_pos(275,310)
settings_selftest_cb_6.set_text("断料检测")
# create style style_settings_selftest_cb_6_main_main_default
style_settings_selftest_cb_6_main_main_default = lv.style_t()
style_settings_selftest_cb_6_main_main_default.init()
style_settings_selftest_cb_6_main_main_default.set_radius(0)
style_settings_selftest_cb_6_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_6_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_6_main_main_default.set_bg_opa(0)
style_settings_selftest_cb_6_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_selftest_cb_6_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_selftest_cb_6_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_selftest_cb_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_selftest_cb_6_main_main_default.set_text_letter_space(0)

# add style for settings_selftest_cb_6
settings_selftest_cb_6.add_style(style_settings_selftest_cb_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_selftest_cb_6_main_indicator_default
style_settings_selftest_cb_6_main_indicator_default = lv.style_t()
style_settings_selftest_cb_6_main_indicator_default.init()
style_settings_selftest_cb_6_main_indicator_default.set_radius(0)
style_settings_selftest_cb_6_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_6_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_6_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_6_main_indicator_default.set_bg_opa(0)
style_settings_selftest_cb_6_main_indicator_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_6_main_indicator_default.set_border_width(3)

# add style for settings_selftest_cb_6
settings_selftest_cb_6.add_style(style_settings_selftest_cb_6_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_settings_selftest_cb_6_main_indicator_checked
style_settings_selftest_cb_6_main_indicator_checked = lv.style_t()
style_settings_selftest_cb_6_main_indicator_checked.init()
style_settings_selftest_cb_6_main_indicator_checked.set_radius(0)
style_settings_selftest_cb_6_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cb_6_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cb_6_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_6_main_indicator_checked.set_bg_opa(0)
style_settings_selftest_cb_6_main_indicator_checked.set_border_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_6_main_indicator_checked.set_border_width(3)

# add style for settings_selftest_cb_6
settings_selftest_cb_6.add_style(style_settings_selftest_cb_6_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

settings_selftest_cb_4 = lv.checkbox(settings_selftest_cont_1)
settings_selftest_cb_4.set_pos(275,233)
settings_selftest_cb_4.set_text("探头检测")
# create style style_settings_selftest_cb_4_main_main_default
style_settings_selftest_cb_4_main_main_default = lv.style_t()
style_settings_selftest_cb_4_main_main_default.init()
style_settings_selftest_cb_4_main_main_default.set_radius(0)
style_settings_selftest_cb_4_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_4_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_4_main_main_default.set_bg_opa(0)
style_settings_selftest_cb_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_selftest_cb_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_selftest_cb_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_selftest_cb_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_selftest_cb_4_main_main_default.set_text_letter_space(0)

# add style for settings_selftest_cb_4
settings_selftest_cb_4.add_style(style_settings_selftest_cb_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_selftest_cb_4_main_indicator_default
style_settings_selftest_cb_4_main_indicator_default = lv.style_t()
style_settings_selftest_cb_4_main_indicator_default.init()
style_settings_selftest_cb_4_main_indicator_default.set_radius(0)
style_settings_selftest_cb_4_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_4_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_4_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_4_main_indicator_default.set_bg_opa(0)
style_settings_selftest_cb_4_main_indicator_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_4_main_indicator_default.set_border_width(3)

# add style for settings_selftest_cb_4
settings_selftest_cb_4.add_style(style_settings_selftest_cb_4_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_settings_selftest_cb_4_main_indicator_checked
style_settings_selftest_cb_4_main_indicator_checked = lv.style_t()
style_settings_selftest_cb_4_main_indicator_checked.init()
style_settings_selftest_cb_4_main_indicator_checked.set_radius(0)
style_settings_selftest_cb_4_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cb_4_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cb_4_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_4_main_indicator_checked.set_bg_opa(0)
style_settings_selftest_cb_4_main_indicator_checked.set_border_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_4_main_indicator_checked.set_border_width(3)

# add style for settings_selftest_cb_4
settings_selftest_cb_4.add_style(style_settings_selftest_cb_4_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

settings_selftest_cb_2 = lv.checkbox(settings_selftest_cont_1)
settings_selftest_cb_2.set_pos(275,154)
settings_selftest_cb_2.set_text("归位检测")
# create style style_settings_selftest_cb_2_main_main_default
style_settings_selftest_cb_2_main_main_default = lv.style_t()
style_settings_selftest_cb_2_main_main_default.init()
style_settings_selftest_cb_2_main_main_default.set_radius(0)
style_settings_selftest_cb_2_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_2_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_2_main_main_default.set_bg_opa(0)
style_settings_selftest_cb_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_selftest_cb_2_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_selftest_cb_2_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_selftest_cb_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_selftest_cb_2_main_main_default.set_text_letter_space(0)

# add style for settings_selftest_cb_2
settings_selftest_cb_2.add_style(style_settings_selftest_cb_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_selftest_cb_2_main_indicator_default
style_settings_selftest_cb_2_main_indicator_default = lv.style_t()
style_settings_selftest_cb_2_main_indicator_default.init()
style_settings_selftest_cb_2_main_indicator_default.set_radius(0)
style_settings_selftest_cb_2_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_2_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_2_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_2_main_indicator_default.set_bg_opa(0)
style_settings_selftest_cb_2_main_indicator_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_2_main_indicator_default.set_border_width(3)

# add style for settings_selftest_cb_2
settings_selftest_cb_2.add_style(style_settings_selftest_cb_2_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

# create style style_settings_selftest_cb_2_main_indicator_checked
style_settings_selftest_cb_2_main_indicator_checked = lv.style_t()
style_settings_selftest_cb_2_main_indicator_checked.init()
style_settings_selftest_cb_2_main_indicator_checked.set_radius(0)
style_settings_selftest_cb_2_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cb_2_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cb_2_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cb_2_main_indicator_checked.set_bg_opa(0)
style_settings_selftest_cb_2_main_indicator_checked.set_border_color(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_cb_2_main_indicator_checked.set_border_width(3)

# add style for settings_selftest_cb_2
settings_selftest_cb_2.add_style(style_settings_selftest_cb_2_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

settings_selftest_label_3 = lv.label(settings_selftest_cont_1)
settings_selftest_label_3.set_pos(26,78)
settings_selftest_label_3.set_size(96,28)
settings_selftest_label_3.set_text("检测选项")
settings_selftest_label_3.set_long_mode(lv.label.LONG.WRAP)
settings_selftest_label_3.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_settings_selftest_label_3_main_main_default
style_settings_selftest_label_3_main_main_default = lv.style_t()
style_settings_selftest_label_3_main_main_default.init()
style_settings_selftest_label_3_main_main_default.set_radius(0)
style_settings_selftest_label_3_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_selftest_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_selftest_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_label_3_main_main_default.set_bg_opa(0)
style_settings_selftest_label_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_selftest_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_selftest_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_selftest_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_selftest_label_3_main_main_default.set_text_letter_space(0)
style_settings_selftest_label_3_main_main_default.set_pad_left(0)
style_settings_selftest_label_3_main_main_default.set_pad_right(0)
style_settings_selftest_label_3_main_main_default.set_pad_top(0)
style_settings_selftest_label_3_main_main_default.set_pad_bottom(0)

# add style for settings_selftest_label_3
settings_selftest_label_3.add_style(style_settings_selftest_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_selftest_label_4 = lv.label(settings_selftest_cont_1)
settings_selftest_label_4.set_pos(24,127)
settings_selftest_label_4.set_size(432,1)
# create style style_settings_selftest_label_4_main_main_default
style_settings_selftest_label_4_main_main_default = lv.style_t()
style_settings_selftest_label_4_main_main_default.init()
style_settings_selftest_label_4_main_main_default.set_radius(0)
style_settings_selftest_label_4_main_main_default.set_bg_color(lv.color_make(0x3a,0x3d,0x42))
style_settings_selftest_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x3a,0x3d,0x42))
style_settings_selftest_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_label_4_main_main_default.set_bg_opa(255)
style_settings_selftest_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_selftest_label_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_selftest_label_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_selftest_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_selftest_label_4_main_main_default.set_text_letter_space(0)
style_settings_selftest_label_4_main_main_default.set_pad_left(0)
style_settings_selftest_label_4_main_main_default.set_pad_right(0)
style_settings_selftest_label_4_main_main_default.set_pad_top(0)
style_settings_selftest_label_4_main_main_default.set_pad_bottom(0)

# add style for settings_selftest_label_4
settings_selftest_label_4.add_style(style_settings_selftest_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_selftest_label_1 = lv.label(settings_selftest_cont_1)
settings_selftest_label_1.set_pos(0,719)
settings_selftest_label_1.set_size(480,80)
# create style style_settings_selftest_label_1_main_main_default
style_settings_selftest_label_1_main_main_default = lv.style_t()
style_settings_selftest_label_1_main_main_default.init()
style_settings_selftest_label_1_main_main_default.set_radius(0)
style_settings_selftest_label_1_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_settings_selftest_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_settings_selftest_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_label_1_main_main_default.set_bg_opa(255)
style_settings_selftest_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_selftest_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_selftest_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_selftest_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_selftest_label_1_main_main_default.set_text_letter_space(0)
style_settings_selftest_label_1_main_main_default.set_pad_left(0)
style_settings_selftest_label_1_main_main_default.set_pad_right(0)
style_settings_selftest_label_1_main_main_default.set_pad_top(0)
style_settings_selftest_label_1_main_main_default.set_pad_bottom(0)

# add style for settings_selftest_label_1
settings_selftest_label_1.add_style(style_settings_selftest_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_selftest_img_1 = lv.img(settings_selftest_cont_1)
settings_selftest_img_1.set_pos(30,742)
settings_selftest_img_1.set_size(48,48)
settings_selftest_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png','rb') as f:
        settings_selftest_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png')
    sys.exit()

settings_selftest_img_1_img = lv.img_dsc_t({
  'data_size': len(settings_selftest_img_1_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_selftest_img_1_img_data
})

settings_selftest_img_1.set_src(settings_selftest_img_1_img)
settings_selftest_img_1.set_pivot(0,0)
settings_selftest_img_1.set_angle(0)
# create style style_settings_selftest_img_1_main_main_default
style_settings_selftest_img_1_main_main_default = lv.style_t()
style_settings_selftest_img_1_main_main_default.init()
style_settings_selftest_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_img_1_main_main_default.set_img_recolor_opa(0)
style_settings_selftest_img_1_main_main_default.set_img_opa(255)

# add style for settings_selftest_img_1
settings_selftest_img_1.add_style(style_settings_selftest_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_selftest_img_2 = lv.img(settings_selftest_cont_1)
settings_selftest_img_2.set_pos(128,742)
settings_selftest_img_2.set_size(48,48)
settings_selftest_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png','rb') as f:
        settings_selftest_img_2_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png')
    sys.exit()

settings_selftest_img_2_img = lv.img_dsc_t({
  'data_size': len(settings_selftest_img_2_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_selftest_img_2_img_data
})

settings_selftest_img_2.set_src(settings_selftest_img_2_img)
settings_selftest_img_2.set_pivot(0,0)
settings_selftest_img_2.set_angle(0)
# create style style_settings_selftest_img_2_main_main_default
style_settings_selftest_img_2_main_main_default = lv.style_t()
style_settings_selftest_img_2_main_main_default.init()
style_settings_selftest_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_img_2_main_main_default.set_img_recolor_opa(0)
style_settings_selftest_img_2_main_main_default.set_img_opa(255)

# add style for settings_selftest_img_2
settings_selftest_img_2.add_style(style_settings_selftest_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_selftest_img_3 = lv.img(settings_selftest_cont_1)
settings_selftest_img_3.set_pos(224,742)
settings_selftest_img_3.set_size(48,48)
settings_selftest_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png','rb') as f:
        settings_selftest_img_3_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png')
    sys.exit()

settings_selftest_img_3_img = lv.img_dsc_t({
  'data_size': len(settings_selftest_img_3_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_selftest_img_3_img_data
})

settings_selftest_img_3.set_src(settings_selftest_img_3_img)
settings_selftest_img_3.set_pivot(0,0)
settings_selftest_img_3.set_angle(0)
# create style style_settings_selftest_img_3_main_main_default
style_settings_selftest_img_3_main_main_default = lv.style_t()
style_settings_selftest_img_3_main_main_default.init()
style_settings_selftest_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_img_3_main_main_default.set_img_recolor_opa(0)
style_settings_selftest_img_3_main_main_default.set_img_opa(255)

# add style for settings_selftest_img_3
settings_selftest_img_3.add_style(style_settings_selftest_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_selftest_img_4 = lv.img(settings_selftest_cont_1)
settings_selftest_img_4.set_pos(318,742)
settings_selftest_img_4.set_size(48,48)
settings_selftest_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png','rb') as f:
        settings_selftest_img_4_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png')
    sys.exit()

settings_selftest_img_4_img = lv.img_dsc_t({
  'data_size': len(settings_selftest_img_4_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_selftest_img_4_img_data
})

settings_selftest_img_4.set_src(settings_selftest_img_4_img)
settings_selftest_img_4.set_pivot(0,0)
settings_selftest_img_4.set_angle(0)
# create style style_settings_selftest_img_4_main_main_default
style_settings_selftest_img_4_main_main_default = lv.style_t()
style_settings_selftest_img_4_main_main_default.init()
style_settings_selftest_img_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_img_4_main_main_default.set_img_recolor_opa(0)
style_settings_selftest_img_4_main_main_default.set_img_opa(255)

# add style for settings_selftest_img_4
settings_selftest_img_4.add_style(style_settings_selftest_img_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_selftest_img_5 = lv.img(settings_selftest_cont_1)
settings_selftest_img_5.set_pos(414,742)
settings_selftest_img_5.set_size(48,48)
settings_selftest_img_5.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png','rb') as f:
        settings_selftest_img_5_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png')
    sys.exit()

settings_selftest_img_5_img = lv.img_dsc_t({
  'data_size': len(settings_selftest_img_5_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_selftest_img_5_img_data
})

settings_selftest_img_5.set_src(settings_selftest_img_5_img)
settings_selftest_img_5.set_pivot(0,0)
settings_selftest_img_5.set_angle(0)
# create style style_settings_selftest_img_5_main_main_default
style_settings_selftest_img_5_main_main_default = lv.style_t()
style_settings_selftest_img_5_main_main_default.init()
style_settings_selftest_img_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_selftest_img_5_main_main_default.set_img_recolor_opa(0)
style_settings_selftest_img_5_main_main_default.set_img_opa(255)

# add style for settings_selftest_img_5
settings_selftest_img_5.add_style(style_settings_selftest_img_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_selftest_cont_1_main_main_default
style_settings_selftest_cont_1_main_main_default = lv.style_t()
style_settings_selftest_cont_1_main_main_default.init()
style_settings_selftest_cont_1_main_main_default.set_radius(0)
style_settings_selftest_cont_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_settings_selftest_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_settings_selftest_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_selftest_cont_1_main_main_default.set_bg_opa(255)
style_settings_selftest_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_selftest_cont_1_main_main_default.set_border_width(0)
style_settings_selftest_cont_1_main_main_default.set_border_opa(255)
style_settings_selftest_cont_1_main_main_default.set_pad_left(0)
style_settings_selftest_cont_1_main_main_default.set_pad_right(0)
style_settings_selftest_cont_1_main_main_default.set_pad_top(0)
style_settings_selftest_cont_1_main_main_default.set_pad_bottom(0)

# add style for settings_selftest_cont_1
settings_selftest_cont_1.add_style(style_settings_selftest_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

netwowork_information = lv.obj()
# create style style_netwowork_information_main_main_default
style_netwowork_information_main_main_default = lv.style_t()
style_netwowork_information_main_main_default.init()
style_netwowork_information_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_netwowork_information_main_main_default.set_bg_opa(0)

# add style for netwowork_information
netwowork_information.add_style(style_netwowork_information_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

netwowork_information_cont_1 = lv.obj(netwowork_information)
netwowork_information_cont_1.set_pos(0,0)
netwowork_information_cont_1.set_size(480,800)
netwowork_information_label_3 = lv.label(netwowork_information_cont_1)
netwowork_information_label_3.set_pos(10,63)
netwowork_information_label_3.set_size(460,727)
# create style style_netwowork_information_label_3_main_main_default
style_netwowork_information_label_3_main_main_default = lv.style_t()
style_netwowork_information_label_3_main_main_default.init()
style_netwowork_information_label_3_main_main_default.set_radius(0)
style_netwowork_information_label_3_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_netwowork_information_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_netwowork_information_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_netwowork_information_label_3_main_main_default.set_bg_opa(255)
style_netwowork_information_label_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_netwowork_information_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_netwowork_information_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_netwowork_information_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_netwowork_information_label_3_main_main_default.set_text_letter_space(2)
style_netwowork_information_label_3_main_main_default.set_pad_left(0)
style_netwowork_information_label_3_main_main_default.set_pad_right(0)
style_netwowork_information_label_3_main_main_default.set_pad_top(0)
style_netwowork_information_label_3_main_main_default.set_pad_bottom(0)

# add style for netwowork_information_label_3
netwowork_information_label_3.add_style(style_netwowork_information_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

netwowork_information_label_1 = lv.label(netwowork_information_cont_1)
netwowork_information_label_1.set_pos(0,0)
netwowork_information_label_1.set_size(480,53)
# create style style_netwowork_information_label_1_main_main_default
style_netwowork_information_label_1_main_main_default = lv.style_t()
style_netwowork_information_label_1_main_main_default.init()
style_netwowork_information_label_1_main_main_default.set_radius(0)
style_netwowork_information_label_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_netwowork_information_label_1_main_main_default.set_bg_opa(255)
style_netwowork_information_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_netwowork_information_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_netwowork_information_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_netwowork_information_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_netwowork_information_label_1_main_main_default.set_text_letter_space(2)
style_netwowork_information_label_1_main_main_default.set_pad_left(0)
style_netwowork_information_label_1_main_main_default.set_pad_right(0)
style_netwowork_information_label_1_main_main_default.set_pad_top(0)
style_netwowork_information_label_1_main_main_default.set_pad_bottom(0)

# add style for netwowork_information_label_1
netwowork_information_label_1.add_style(style_netwowork_information_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

netwowork_information_btn_1 = lv.btn(netwowork_information_cont_1)
netwowork_information_btn_1.set_pos(0,0)
netwowork_information_btn_1.set_size(85,50)
# create style style_netwowork_information_btn_1_main_main_default
style_netwowork_information_btn_1_main_main_default = lv.style_t()
style_netwowork_information_btn_1_main_main_default.init()
style_netwowork_information_btn_1_main_main_default.set_radius(0)
style_netwowork_information_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_netwowork_information_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_netwowork_information_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_netwowork_information_btn_1_main_main_default.set_bg_opa(0)
style_netwowork_information_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_netwowork_information_btn_1_main_main_default.set_shadow_opa(0)
style_netwowork_information_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_netwowork_information_btn_1_main_main_default.set_border_width(0)
style_netwowork_information_btn_1_main_main_default.set_border_opa(255)

# add style for netwowork_information_btn_1
netwowork_information_btn_1.add_style(style_netwowork_information_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

netwowork_information_img_1 = lv.img(netwowork_information_cont_1)
netwowork_information_img_1.set_pos(21,17)
netwowork_information_img_1.set_size(36,24)
netwowork_information_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png','rb') as f:
        netwowork_information_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png')
    sys.exit()

netwowork_information_img_1_img = lv.img_dsc_t({
  'data_size': len(netwowork_information_img_1_img_data),
  'header': {'always_zero': 0, 'w': 36, 'h': 24, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': netwowork_information_img_1_img_data
})

netwowork_information_img_1.set_src(netwowork_information_img_1_img)
netwowork_information_img_1.set_pivot(0,0)
netwowork_information_img_1.set_angle(0)
# create style style_netwowork_information_img_1_main_main_default
style_netwowork_information_img_1_main_main_default = lv.style_t()
style_netwowork_information_img_1_main_main_default.init()
style_netwowork_information_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_netwowork_information_img_1_main_main_default.set_img_recolor_opa(0)
style_netwowork_information_img_1_main_main_default.set_img_opa(255)

# add style for netwowork_information_img_1
netwowork_information_img_1.add_style(style_netwowork_information_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

netwowork_information_label_2 = lv.label(netwowork_information_cont_1)
netwowork_information_label_2.set_pos(90,11)
netwowork_information_label_2.set_size(300,32)
netwowork_information_label_2.set_text("本地网络")
netwowork_information_label_2.set_long_mode(lv.label.LONG.WRAP)
netwowork_information_label_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_netwowork_information_label_2_main_main_default
style_netwowork_information_label_2_main_main_default = lv.style_t()
style_netwowork_information_label_2_main_main_default.init()
style_netwowork_information_label_2_main_main_default.set_radius(0)
style_netwowork_information_label_2_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_netwowork_information_label_2_main_main_default.set_bg_opa(0)
style_netwowork_information_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_netwowork_information_label_2_main_main_default.set_text_font(lv.font_simsun_32)
except AttributeError:
    try:
        style_netwowork_information_label_2_main_main_default.set_text_font(lv.font_montserrat_32)
    except AttributeError:
        style_netwowork_information_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_netwowork_information_label_2_main_main_default.set_text_letter_space(2)
style_netwowork_information_label_2_main_main_default.set_pad_left(0)
style_netwowork_information_label_2_main_main_default.set_pad_right(0)
style_netwowork_information_label_2_main_main_default.set_pad_top(0)
style_netwowork_information_label_2_main_main_default.set_pad_bottom(0)

# add style for netwowork_information_label_2
netwowork_information_label_2.add_style(style_netwowork_information_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

netwowork_information_label_4 = lv.label(netwowork_information_cont_1)
netwowork_information_label_4.set_pos(30,80)
netwowork_information_label_4.set_size(178,24)
netwowork_information_label_4.set_text("IP地址:")
netwowork_information_label_4.set_long_mode(lv.label.LONG.WRAP)
netwowork_information_label_4.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_netwowork_information_label_4_main_main_default
style_netwowork_information_label_4_main_main_default = lv.style_t()
style_netwowork_information_label_4_main_main_default.init()
style_netwowork_information_label_4_main_main_default.set_radius(0)
style_netwowork_information_label_4_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_netwowork_information_label_4_main_main_default.set_bg_opa(0)
style_netwowork_information_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_netwowork_information_label_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_netwowork_information_label_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_netwowork_information_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_netwowork_information_label_4_main_main_default.set_text_letter_space(0)
style_netwowork_information_label_4_main_main_default.set_pad_left(0)
style_netwowork_information_label_4_main_main_default.set_pad_right(0)
style_netwowork_information_label_4_main_main_default.set_pad_top(0)
style_netwowork_information_label_4_main_main_default.set_pad_bottom(0)

# add style for netwowork_information_label_4
netwowork_information_label_4.add_style(style_netwowork_information_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

netwowork_information_label_8 = lv.label(netwowork_information_cont_1)
netwowork_information_label_8.set_pos(300,80)
netwowork_information_label_8.set_size(150,24)
netwowork_information_label_8.set_text("172.23.1.236")
netwowork_information_label_8.set_long_mode(lv.label.LONG.WRAP)
netwowork_information_label_8.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_netwowork_information_label_8_main_main_default
style_netwowork_information_label_8_main_main_default = lv.style_t()
style_netwowork_information_label_8_main_main_default.init()
style_netwowork_information_label_8_main_main_default.set_radius(0)
style_netwowork_information_label_8_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_netwowork_information_label_8_main_main_default.set_bg_opa(0)
style_netwowork_information_label_8_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_netwowork_information_label_8_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_netwowork_information_label_8_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_netwowork_information_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_netwowork_information_label_8_main_main_default.set_text_letter_space(0)
style_netwowork_information_label_8_main_main_default.set_pad_left(0)
style_netwowork_information_label_8_main_main_default.set_pad_right(0)
style_netwowork_information_label_8_main_main_default.set_pad_top(0)
style_netwowork_information_label_8_main_main_default.set_pad_bottom(0)

# add style for netwowork_information_label_8
netwowork_information_label_8.add_style(style_netwowork_information_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

netwowork_information_label_9 = lv.label(netwowork_information_cont_1)
netwowork_information_label_9.set_pos(300,130)
netwowork_information_label_9.set_size(150,24)
netwowork_information_label_9.set_text("172.23.1.1")
netwowork_information_label_9.set_long_mode(lv.label.LONG.WRAP)
netwowork_information_label_9.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_netwowork_information_label_9_main_main_default
style_netwowork_information_label_9_main_main_default = lv.style_t()
style_netwowork_information_label_9_main_main_default.init()
style_netwowork_information_label_9_main_main_default.set_radius(0)
style_netwowork_information_label_9_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_9_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_netwowork_information_label_9_main_main_default.set_bg_opa(0)
style_netwowork_information_label_9_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_netwowork_information_label_9_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_netwowork_information_label_9_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_netwowork_information_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_netwowork_information_label_9_main_main_default.set_text_letter_space(0)
style_netwowork_information_label_9_main_main_default.set_pad_left(0)
style_netwowork_information_label_9_main_main_default.set_pad_right(0)
style_netwowork_information_label_9_main_main_default.set_pad_top(0)
style_netwowork_information_label_9_main_main_default.set_pad_bottom(0)

# add style for netwowork_information_label_9
netwowork_information_label_9.add_style(style_netwowork_information_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

netwowork_information_label_10 = lv.label(netwowork_information_cont_1)
netwowork_information_label_10.set_pos(266,177)
netwowork_information_label_10.set_size(183,24)
netwowork_information_label_10.set_text("255.255.255.0")
netwowork_information_label_10.set_long_mode(lv.label.LONG.WRAP)
netwowork_information_label_10.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_netwowork_information_label_10_main_main_default
style_netwowork_information_label_10_main_main_default = lv.style_t()
style_netwowork_information_label_10_main_main_default.init()
style_netwowork_information_label_10_main_main_default.set_radius(0)
style_netwowork_information_label_10_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_10_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_netwowork_information_label_10_main_main_default.set_bg_opa(0)
style_netwowork_information_label_10_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_netwowork_information_label_10_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_netwowork_information_label_10_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_netwowork_information_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_netwowork_information_label_10_main_main_default.set_text_letter_space(0)
style_netwowork_information_label_10_main_main_default.set_pad_left(0)
style_netwowork_information_label_10_main_main_default.set_pad_right(0)
style_netwowork_information_label_10_main_main_default.set_pad_top(0)
style_netwowork_information_label_10_main_main_default.set_pad_bottom(0)

# add style for netwowork_information_label_10
netwowork_information_label_10.add_style(style_netwowork_information_label_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

netwowork_information_label_11 = lv.label(netwowork_information_cont_1)
netwowork_information_label_11.set_pos(300,224)
netwowork_information_label_11.set_size(150,24)
netwowork_information_label_11.set_text("172.23.88.89")
netwowork_information_label_11.set_long_mode(lv.label.LONG.WRAP)
netwowork_information_label_11.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_netwowork_information_label_11_main_main_default
style_netwowork_information_label_11_main_main_default = lv.style_t()
style_netwowork_information_label_11_main_main_default.init()
style_netwowork_information_label_11_main_main_default.set_radius(0)
style_netwowork_information_label_11_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_11_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_11_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_netwowork_information_label_11_main_main_default.set_bg_opa(0)
style_netwowork_information_label_11_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_netwowork_information_label_11_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_netwowork_information_label_11_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_netwowork_information_label_11_main_main_default.set_text_font(lv.font_montserrat_16)
style_netwowork_information_label_11_main_main_default.set_text_letter_space(0)
style_netwowork_information_label_11_main_main_default.set_pad_left(0)
style_netwowork_information_label_11_main_main_default.set_pad_right(0)
style_netwowork_information_label_11_main_main_default.set_pad_top(0)
style_netwowork_information_label_11_main_main_default.set_pad_bottom(0)

# add style for netwowork_information_label_11
netwowork_information_label_11.add_style(style_netwowork_information_label_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

netwowork_information_label_5 = lv.label(netwowork_information_cont_1)
netwowork_information_label_5.set_pos(30,130)
netwowork_information_label_5.set_size(196,24)
netwowork_information_label_5.set_text("网关:")
netwowork_information_label_5.set_long_mode(lv.label.LONG.WRAP)
netwowork_information_label_5.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_netwowork_information_label_5_main_main_default
style_netwowork_information_label_5_main_main_default = lv.style_t()
style_netwowork_information_label_5_main_main_default.init()
style_netwowork_information_label_5_main_main_default.set_radius(0)
style_netwowork_information_label_5_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_netwowork_information_label_5_main_main_default.set_bg_opa(0)
style_netwowork_information_label_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_netwowork_information_label_5_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_netwowork_information_label_5_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_netwowork_information_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_netwowork_information_label_5_main_main_default.set_text_letter_space(0)
style_netwowork_information_label_5_main_main_default.set_pad_left(0)
style_netwowork_information_label_5_main_main_default.set_pad_right(0)
style_netwowork_information_label_5_main_main_default.set_pad_top(0)
style_netwowork_information_label_5_main_main_default.set_pad_bottom(0)

# add style for netwowork_information_label_5
netwowork_information_label_5.add_style(style_netwowork_information_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

netwowork_information_label_6 = lv.label(netwowork_information_cont_1)
netwowork_information_label_6.set_pos(30,177)
netwowork_information_label_6.set_size(195,24)
netwowork_information_label_6.set_text("子网掩码:")
netwowork_information_label_6.set_long_mode(lv.label.LONG.WRAP)
netwowork_information_label_6.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_netwowork_information_label_6_main_main_default
style_netwowork_information_label_6_main_main_default = lv.style_t()
style_netwowork_information_label_6_main_main_default.init()
style_netwowork_information_label_6_main_main_default.set_radius(0)
style_netwowork_information_label_6_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_netwowork_information_label_6_main_main_default.set_bg_opa(0)
style_netwowork_information_label_6_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_netwowork_information_label_6_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_netwowork_information_label_6_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_netwowork_information_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_netwowork_information_label_6_main_main_default.set_text_letter_space(0)
style_netwowork_information_label_6_main_main_default.set_pad_left(0)
style_netwowork_information_label_6_main_main_default.set_pad_right(0)
style_netwowork_information_label_6_main_main_default.set_pad_top(0)
style_netwowork_information_label_6_main_main_default.set_pad_bottom(0)

# add style for netwowork_information_label_6
netwowork_information_label_6.add_style(style_netwowork_information_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

netwowork_information_label_7 = lv.label(netwowork_information_cont_1)
netwowork_information_label_7.set_pos(30,224)
netwowork_information_label_7.set_size(205,24)
netwowork_information_label_7.set_text("DNS服务器:")
netwowork_information_label_7.set_long_mode(lv.label.LONG.WRAP)
netwowork_information_label_7.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_netwowork_information_label_7_main_main_default
style_netwowork_information_label_7_main_main_default = lv.style_t()
style_netwowork_information_label_7_main_main_default.init()
style_netwowork_information_label_7_main_main_default.set_radius(0)
style_netwowork_information_label_7_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_netwowork_information_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_netwowork_information_label_7_main_main_default.set_bg_opa(0)
style_netwowork_information_label_7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_netwowork_information_label_7_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_netwowork_information_label_7_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_netwowork_information_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_netwowork_information_label_7_main_main_default.set_text_letter_space(0)
style_netwowork_information_label_7_main_main_default.set_pad_left(0)
style_netwowork_information_label_7_main_main_default.set_pad_right(0)
style_netwowork_information_label_7_main_main_default.set_pad_top(0)
style_netwowork_information_label_7_main_main_default.set_pad_bottom(0)

# add style for netwowork_information_label_7
netwowork_information_label_7.add_style(style_netwowork_information_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_netwowork_information_cont_1_main_main_default
style_netwowork_information_cont_1_main_main_default = lv.style_t()
style_netwowork_information_cont_1_main_main_default.init()
style_netwowork_information_cont_1_main_main_default.set_radius(0)
style_netwowork_information_cont_1_main_main_default.set_bg_color(lv.color_make(0x23,0x24,0x26))
style_netwowork_information_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x23,0x24,0x26))
style_netwowork_information_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_netwowork_information_cont_1_main_main_default.set_bg_opa(255)
style_netwowork_information_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_netwowork_information_cont_1_main_main_default.set_border_width(0)
style_netwowork_information_cont_1_main_main_default.set_border_opa(255)
style_netwowork_information_cont_1_main_main_default.set_pad_left(0)
style_netwowork_information_cont_1_main_main_default.set_pad_right(0)
style_netwowork_information_cont_1_main_main_default.set_pad_top(0)
style_netwowork_information_cont_1_main_main_default.set_pad_bottom(0)

# add style for netwowork_information_cont_1
netwowork_information_cont_1.add_style(style_netwowork_information_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera = lv.obj()
# create style style_settings_camera_main_main_default
style_settings_camera_main_main_default = lv.style_t()
style_settings_camera_main_main_default.init()
style_settings_camera_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_camera_main_main_default.set_bg_opa(0)

# add style for settings_camera
settings_camera.add_style(style_settings_camera_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_tabview_1 = lv.tabview(settings_camera, lv.DIR.TOP, 50)
settings_camera_tabview_1_tab_btns = settings_camera_tabview_1.get_tab_btns()
# create style style_settings_camera_tabview_1_extra_btnm_main_default
style_settings_camera_tabview_1_extra_btnm_main_default = lv.style_t()
style_settings_camera_tabview_1_extra_btnm_main_default.init()
style_settings_camera_tabview_1_extra_btnm_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_settings_camera_tabview_1_extra_btnm_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_settings_camera_tabview_1_extra_btnm_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_camera_tabview_1_extra_btnm_main_default.set_bg_opa(255)
style_settings_camera_tabview_1_extra_btnm_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_camera_tabview_1_extra_btnm_main_default.set_border_width(0)
style_settings_camera_tabview_1_extra_btnm_main_default.set_border_opa(100)
style_settings_camera_tabview_1_extra_btnm_main_default.set_pad_left(0)
style_settings_camera_tabview_1_extra_btnm_main_default.set_pad_right(0)
style_settings_camera_tabview_1_extra_btnm_main_default.set_pad_top(0)
style_settings_camera_tabview_1_extra_btnm_main_default.set_pad_bottom(0)

# add style for settings_camera_tabview_1_tab_btns
settings_camera_tabview_1_tab_btns.add_style(style_settings_camera_tabview_1_extra_btnm_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_camera_tabview_1_extra_btnm_items_default
style_settings_camera_tabview_1_extra_btnm_items_default = lv.style_t()
style_settings_camera_tabview_1_extra_btnm_items_default.init()
style_settings_camera_tabview_1_extra_btnm_items_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_settings_camera_tabview_1_extra_btnm_items_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_settings_camera_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_settings_camera_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_16)

# add style for settings_camera_tabview_1_tab_btns
settings_camera_tabview_1_tab_btns.add_style(style_settings_camera_tabview_1_extra_btnm_items_default, lv.PART.ITEMS|lv.STATE.DEFAULT)

# create style style_settings_camera_tabview_1_extra_btnm_items_checked
style_settings_camera_tabview_1_extra_btnm_items_checked = lv.style_t()
style_settings_camera_tabview_1_extra_btnm_items_checked.init()
style_settings_camera_tabview_1_extra_btnm_items_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_camera_tabview_1_extra_btnm_items_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_camera_tabview_1_extra_btnm_items_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_camera_tabview_1_extra_btnm_items_checked.set_bg_opa(60)
style_settings_camera_tabview_1_extra_btnm_items_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_camera_tabview_1_extra_btnm_items_checked.set_border_width(4)
style_settings_camera_tabview_1_extra_btnm_items_checked.set_border_opa(255)
style_settings_camera_tabview_1_extra_btnm_items_checked.set_border_side(lv.BORDER_SIDE.BOTTOM)
style_settings_camera_tabview_1_extra_btnm_items_checked.set_text_color(lv.color_make(0x21,0x95,0xf6))
try:
    style_settings_camera_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_settings_camera_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_settings_camera_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_16)

# add style for settings_camera_tabview_1_tab_btns
settings_camera_tabview_1_tab_btns.add_style(style_settings_camera_tabview_1_extra_btnm_items_checked, lv.PART.ITEMS|lv.STATE.CHECKED)

settings_camera_tabview_1_title1 = settings_camera_tabview_1.add_tab("title1")
settings_camera_tabview_1_title2 = settings_camera_tabview_1.add_tab("title2")
settings_camera_tabview_1_title3 = settings_camera_tabview_1.add_tab("title3")
settings_camera_tabview_1_Title = settings_camera_tabview_1.add_tab("Title")
settings_camera_tabview_1.set_pos(0,0)
settings_camera_tabview_1.set_size(480,720)
# create style style_settings_camera_tabview_1_main_main_default
style_settings_camera_tabview_1_main_main_default = lv.style_t()
style_settings_camera_tabview_1_main_main_default.init()
style_settings_camera_tabview_1_main_main_default.set_bg_color(lv.color_make(0xea,0xef,0xf3))
style_settings_camera_tabview_1_main_main_default.set_bg_grad_color(lv.color_make(0xea,0xef,0xf3))
style_settings_camera_tabview_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_camera_tabview_1_main_main_default.set_bg_opa(255)
style_settings_camera_tabview_1_main_main_default.set_border_color(lv.color_make(0xc0,0xc0,0xc0))
style_settings_camera_tabview_1_main_main_default.set_border_width(0)
style_settings_camera_tabview_1_main_main_default.set_border_opa(100)
style_settings_camera_tabview_1_main_main_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_settings_camera_tabview_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_settings_camera_tabview_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_settings_camera_tabview_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_camera_tabview_1_main_main_default.set_text_letter_space(2)
style_settings_camera_tabview_1_main_main_default.set_text_line_space(16)

# add style for settings_camera_tabview_1
settings_camera_tabview_1.add_style(style_settings_camera_tabview_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_cont_1 = lv.obj(settings_camera)
settings_camera_cont_1.set_pos(0,0)
settings_camera_cont_1.set_size(480,800)
settings_camera_label_2 = lv.label(settings_camera_cont_1)
settings_camera_label_2.set_pos(9,52)
settings_camera_label_2.set_size(460,648)
# create style style_settings_camera_label_2_main_main_default
style_settings_camera_label_2_main_main_default = lv.style_t()
style_settings_camera_label_2_main_main_default.init()
style_settings_camera_label_2_main_main_default.set_radius(0)
style_settings_camera_label_2_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_camera_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_camera_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_camera_label_2_main_main_default.set_bg_opa(255)
style_settings_camera_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_camera_label_2_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_camera_label_2_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_camera_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_camera_label_2_main_main_default.set_text_letter_space(0)
style_settings_camera_label_2_main_main_default.set_pad_left(0)
style_settings_camera_label_2_main_main_default.set_pad_right(0)
style_settings_camera_label_2_main_main_default.set_pad_top(0)
style_settings_camera_label_2_main_main_default.set_pad_bottom(0)

# add style for settings_camera_label_2
settings_camera_label_2.add_style(style_settings_camera_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_img_6 = lv.img(settings_camera_cont_1)
settings_camera_img_6.set_pos(24,76)
settings_camera_img_6.set_size(432,324)
# create style style_settings_camera_img_6_main_main_default
style_settings_camera_img_6_main_main_default = lv.style_t()
style_settings_camera_img_6_main_main_default.init()
style_settings_camera_img_6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_camera_img_6_main_main_default.set_img_recolor_opa(0)
style_settings_camera_img_6_main_main_default.set_img_opa(255)

# add style for settings_camera_img_6
settings_camera_img_6.add_style(style_settings_camera_img_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_btn_1 = lv.btn(settings_camera_cont_1)
settings_camera_btn_1.set_pos(409,420)
settings_camera_btn_1.set_size(50,50)
# create style style_settings_camera_btn_1_main_main_default
style_settings_camera_btn_1_main_main_default = lv.style_t()
style_settings_camera_btn_1_main_main_default.init()
style_settings_camera_btn_1_main_main_default.set_radius(0)
style_settings_camera_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_camera_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_camera_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_camera_btn_1_main_main_default.set_bg_opa(0)
style_settings_camera_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_settings_camera_btn_1_main_main_default.set_shadow_opa(0)
style_settings_camera_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_camera_btn_1_main_main_default.set_border_width(0)
style_settings_camera_btn_1_main_main_default.set_border_opa(255)

# add style for settings_camera_btn_1
settings_camera_btn_1.add_style(style_settings_camera_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_btn_2 = lv.btn(settings_camera_cont_1)
settings_camera_btn_2.set_pos(409,504)
settings_camera_btn_2.set_size(50,50)
# create style style_settings_camera_btn_2_main_main_default
style_settings_camera_btn_2_main_main_default = lv.style_t()
style_settings_camera_btn_2_main_main_default.init()
style_settings_camera_btn_2_main_main_default.set_radius(0)
style_settings_camera_btn_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_camera_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_camera_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_camera_btn_2_main_main_default.set_bg_opa(0)
style_settings_camera_btn_2_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_settings_camera_btn_2_main_main_default.set_shadow_opa(0)
style_settings_camera_btn_2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_camera_btn_2_main_main_default.set_border_width(0)
style_settings_camera_btn_2_main_main_default.set_border_opa(255)

# add style for settings_camera_btn_2
settings_camera_btn_2.add_style(style_settings_camera_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_btn_3 = lv.btn(settings_camera_cont_1)
settings_camera_btn_3.set_pos(409,585)
settings_camera_btn_3.set_size(50,50)
# create style style_settings_camera_btn_3_main_main_default
style_settings_camera_btn_3_main_main_default = lv.style_t()
style_settings_camera_btn_3_main_main_default.init()
style_settings_camera_btn_3_main_main_default.set_radius(0)
style_settings_camera_btn_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_settings_camera_btn_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_settings_camera_btn_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_camera_btn_3_main_main_default.set_bg_opa(0)
style_settings_camera_btn_3_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_settings_camera_btn_3_main_main_default.set_shadow_opa(0)
style_settings_camera_btn_3_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_camera_btn_3_main_main_default.set_border_width(0)
style_settings_camera_btn_3_main_main_default.set_border_opa(255)

# add style for settings_camera_btn_3
settings_camera_btn_3.add_style(style_settings_camera_btn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_label_3 = lv.label(settings_camera_cont_1)
settings_camera_label_3.set_pos(176,277)
settings_camera_label_3.set_size(159,33)
settings_camera_label_3.set_text("摄像头未启用")
settings_camera_label_3.set_long_mode(lv.label.LONG.WRAP)
settings_camera_label_3.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_settings_camera_label_3_main_main_default
style_settings_camera_label_3_main_main_default = lv.style_t()
style_settings_camera_label_3_main_main_default.init()
style_settings_camera_label_3_main_main_default.set_radius(0)
style_settings_camera_label_3_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_camera_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_camera_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_camera_label_3_main_main_default.set_bg_opa(0)
style_settings_camera_label_3_main_main_default.set_text_color(lv.color_make(0x6a,0x70,0x7d))
try:
    style_settings_camera_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_camera_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_camera_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_camera_label_3_main_main_default.set_text_letter_space(0)
style_settings_camera_label_3_main_main_default.set_pad_left(0)
style_settings_camera_label_3_main_main_default.set_pad_right(0)
style_settings_camera_label_3_main_main_default.set_pad_top(0)
style_settings_camera_label_3_main_main_default.set_pad_bottom(0)

# add style for settings_camera_label_3
settings_camera_label_3.add_style(style_settings_camera_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_label_4 = lv.label(settings_camera_cont_1)
settings_camera_label_4.set_pos(80,432)
settings_camera_label_4.set_size(263,24)
settings_camera_label_4.set_text("视频列表")
settings_camera_label_4.set_long_mode(lv.label.LONG.WRAP)
settings_camera_label_4.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_settings_camera_label_4_main_main_default
style_settings_camera_label_4_main_main_default = lv.style_t()
style_settings_camera_label_4_main_main_default.init()
style_settings_camera_label_4_main_main_default.set_radius(0)
style_settings_camera_label_4_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_camera_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_camera_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_camera_label_4_main_main_default.set_bg_opa(0)
style_settings_camera_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_camera_label_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_camera_label_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_camera_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_camera_label_4_main_main_default.set_text_letter_space(0)
style_settings_camera_label_4_main_main_default.set_pad_left(0)
style_settings_camera_label_4_main_main_default.set_pad_right(0)
style_settings_camera_label_4_main_main_default.set_pad_top(0)
style_settings_camera_label_4_main_main_default.set_pad_bottom(0)

# add style for settings_camera_label_4
settings_camera_label_4.add_style(style_settings_camera_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_label_5 = lv.label(settings_camera_cont_1)
settings_camera_label_5.set_pos(80,509)
settings_camera_label_5.set_size(260,24)
settings_camera_label_5.set_text("摄像头设置")
settings_camera_label_5.set_long_mode(lv.label.LONG.WRAP)
settings_camera_label_5.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_settings_camera_label_5_main_main_default
style_settings_camera_label_5_main_main_default = lv.style_t()
style_settings_camera_label_5_main_main_default.init()
style_settings_camera_label_5_main_main_default.set_radius(0)
style_settings_camera_label_5_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_camera_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_camera_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_camera_label_5_main_main_default.set_bg_opa(0)
style_settings_camera_label_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_camera_label_5_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_camera_label_5_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_camera_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_camera_label_5_main_main_default.set_text_letter_space(0)
style_settings_camera_label_5_main_main_default.set_pad_left(0)
style_settings_camera_label_5_main_main_default.set_pad_right(0)
style_settings_camera_label_5_main_main_default.set_pad_top(0)
style_settings_camera_label_5_main_main_default.set_pad_bottom(0)

# add style for settings_camera_label_5
settings_camera_label_5.add_style(style_settings_camera_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_label_6 = lv.label(settings_camera_cont_1)
settings_camera_label_6.set_pos(80,590)
settings_camera_label_6.set_size(260,24)
settings_camera_label_6.set_text("AI检测")
settings_camera_label_6.set_long_mode(lv.label.LONG.WRAP)
settings_camera_label_6.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_settings_camera_label_6_main_main_default
style_settings_camera_label_6_main_main_default = lv.style_t()
style_settings_camera_label_6_main_main_default.init()
style_settings_camera_label_6_main_main_default.set_radius(0)
style_settings_camera_label_6_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_camera_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_settings_camera_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_camera_label_6_main_main_default.set_bg_opa(0)
style_settings_camera_label_6_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_camera_label_6_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_camera_label_6_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_camera_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_camera_label_6_main_main_default.set_text_letter_space(0)
style_settings_camera_label_6_main_main_default.set_pad_left(0)
style_settings_camera_label_6_main_main_default.set_pad_right(0)
style_settings_camera_label_6_main_main_default.set_pad_top(0)
style_settings_camera_label_6_main_main_default.set_pad_bottom(0)

# add style for settings_camera_label_6
settings_camera_label_6.add_style(style_settings_camera_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_label_7 = lv.label(settings_camera_cont_1)
settings_camera_label_7.set_pos(27,481)
settings_camera_label_7.set_size(426,1)
# create style style_settings_camera_label_7_main_main_default
style_settings_camera_label_7_main_main_default = lv.style_t()
style_settings_camera_label_7_main_main_default.init()
style_settings_camera_label_7_main_main_default.set_radius(0)
style_settings_camera_label_7_main_main_default.set_bg_color(lv.color_make(0x3a,0x3d,0x42))
style_settings_camera_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x3a,0x3d,0x42))
style_settings_camera_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_camera_label_7_main_main_default.set_bg_opa(255)
style_settings_camera_label_7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_camera_label_7_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_camera_label_7_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_camera_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_camera_label_7_main_main_default.set_text_letter_space(0)
style_settings_camera_label_7_main_main_default.set_pad_left(0)
style_settings_camera_label_7_main_main_default.set_pad_right(0)
style_settings_camera_label_7_main_main_default.set_pad_top(0)
style_settings_camera_label_7_main_main_default.set_pad_bottom(0)

# add style for settings_camera_label_7
settings_camera_label_7.add_style(style_settings_camera_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_label_8 = lv.label(settings_camera_cont_1)
settings_camera_label_8.set_pos(27,562)
settings_camera_label_8.set_size(426,1)
# create style style_settings_camera_label_8_main_main_default
style_settings_camera_label_8_main_main_default = lv.style_t()
style_settings_camera_label_8_main_main_default.init()
style_settings_camera_label_8_main_main_default.set_radius(0)
style_settings_camera_label_8_main_main_default.set_bg_color(lv.color_make(0x3a,0x3d,0x42))
style_settings_camera_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x3a,0x3d,0x42))
style_settings_camera_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_camera_label_8_main_main_default.set_bg_opa(255)
style_settings_camera_label_8_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_camera_label_8_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_camera_label_8_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_camera_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_camera_label_8_main_main_default.set_text_letter_space(0)
style_settings_camera_label_8_main_main_default.set_pad_left(0)
style_settings_camera_label_8_main_main_default.set_pad_right(0)
style_settings_camera_label_8_main_main_default.set_pad_top(0)
style_settings_camera_label_8_main_main_default.set_pad_bottom(0)

# add style for settings_camera_label_8
settings_camera_label_8.add_style(style_settings_camera_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_label_9 = lv.label(settings_camera_cont_1)
settings_camera_label_9.set_pos(27,643)
settings_camera_label_9.set_size(426,1)
# create style style_settings_camera_label_9_main_main_default
style_settings_camera_label_9_main_main_default = lv.style_t()
style_settings_camera_label_9_main_main_default.init()
style_settings_camera_label_9_main_main_default.set_radius(0)
style_settings_camera_label_9_main_main_default.set_bg_color(lv.color_make(0x3a,0x3d,0x42))
style_settings_camera_label_9_main_main_default.set_bg_grad_color(lv.color_make(0x3a,0x3d,0x42))
style_settings_camera_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_camera_label_9_main_main_default.set_bg_opa(255)
style_settings_camera_label_9_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_camera_label_9_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_camera_label_9_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_camera_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_camera_label_9_main_main_default.set_text_letter_space(0)
style_settings_camera_label_9_main_main_default.set_pad_left(0)
style_settings_camera_label_9_main_main_default.set_pad_right(0)
style_settings_camera_label_9_main_main_default.set_pad_top(0)
style_settings_camera_label_9_main_main_default.set_pad_bottom(0)

# add style for settings_camera_label_9
settings_camera_label_9.add_style(style_settings_camera_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_img_7 = lv.img(settings_camera_cont_1)
settings_camera_img_7.set_pos(186,154)
settings_camera_img_7.set_size(109,109)
# create style style_settings_camera_img_7_main_main_default
style_settings_camera_img_7_main_main_default = lv.style_t()
style_settings_camera_img_7_main_main_default.init()
style_settings_camera_img_7_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_camera_img_7_main_main_default.set_img_recolor_opa(0)
style_settings_camera_img_7_main_main_default.set_img_opa(255)

# add style for settings_camera_img_7
settings_camera_img_7.add_style(style_settings_camera_img_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_img_8 = lv.img(settings_camera_cont_1)
settings_camera_img_8.set_pos(40,431)
settings_camera_img_8.set_size(30,24)
settings_camera_img_8.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1807104405.png','rb') as f:
        settings_camera_img_8_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1807104405.png')
    sys.exit()

settings_camera_img_8_img = lv.img_dsc_t({
  'data_size': len(settings_camera_img_8_img_data),
  'header': {'always_zero': 0, 'w': 30, 'h': 24, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_camera_img_8_img_data
})

settings_camera_img_8.set_src(settings_camera_img_8_img)
settings_camera_img_8.set_pivot(0,0)
settings_camera_img_8.set_angle(0)
# create style style_settings_camera_img_8_main_main_default
style_settings_camera_img_8_main_main_default = lv.style_t()
style_settings_camera_img_8_main_main_default.init()
style_settings_camera_img_8_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_camera_img_8_main_main_default.set_img_recolor_opa(0)
style_settings_camera_img_8_main_main_default.set_img_opa(255)

# add style for settings_camera_img_8
settings_camera_img_8.add_style(style_settings_camera_img_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_img_11 = lv.img(settings_camera_cont_1)
settings_camera_img_11.set_pos(430,431)
settings_camera_img_11.set_size(14,28)
settings_camera_img_11.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png','rb') as f:
        settings_camera_img_11_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png')
    sys.exit()

settings_camera_img_11_img = lv.img_dsc_t({
  'data_size': len(settings_camera_img_11_img_data),
  'header': {'always_zero': 0, 'w': 14, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_camera_img_11_img_data
})

settings_camera_img_11.set_src(settings_camera_img_11_img)
settings_camera_img_11.set_pivot(0,0)
settings_camera_img_11.set_angle(0)
# create style style_settings_camera_img_11_main_main_default
style_settings_camera_img_11_main_main_default = lv.style_t()
style_settings_camera_img_11_main_main_default.init()
style_settings_camera_img_11_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_camera_img_11_main_main_default.set_img_recolor_opa(0)
style_settings_camera_img_11_main_main_default.set_img_opa(255)

# add style for settings_camera_img_11
settings_camera_img_11.add_style(style_settings_camera_img_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_img_12 = lv.img(settings_camera_cont_1)
settings_camera_img_12.set_pos(430,513)
settings_camera_img_12.set_size(14,28)
settings_camera_img_12.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png','rb') as f:
        settings_camera_img_12_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png')
    sys.exit()

settings_camera_img_12_img = lv.img_dsc_t({
  'data_size': len(settings_camera_img_12_img_data),
  'header': {'always_zero': 0, 'w': 14, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_camera_img_12_img_data
})

settings_camera_img_12.set_src(settings_camera_img_12_img)
settings_camera_img_12.set_pivot(0,0)
settings_camera_img_12.set_angle(0)
# create style style_settings_camera_img_12_main_main_default
style_settings_camera_img_12_main_main_default = lv.style_t()
style_settings_camera_img_12_main_main_default.init()
style_settings_camera_img_12_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_camera_img_12_main_main_default.set_img_recolor_opa(0)
style_settings_camera_img_12_main_main_default.set_img_opa(255)

# add style for settings_camera_img_12
settings_camera_img_12.add_style(style_settings_camera_img_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_img_13 = lv.img(settings_camera_cont_1)
settings_camera_img_13.set_pos(430,593)
settings_camera_img_13.set_size(14,28)
settings_camera_img_13.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png','rb') as f:
        settings_camera_img_13_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png')
    sys.exit()

settings_camera_img_13_img = lv.img_dsc_t({
  'data_size': len(settings_camera_img_13_img_data),
  'header': {'always_zero': 0, 'w': 14, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_camera_img_13_img_data
})

settings_camera_img_13.set_src(settings_camera_img_13_img)
settings_camera_img_13.set_pivot(0,0)
settings_camera_img_13.set_angle(0)
# create style style_settings_camera_img_13_main_main_default
style_settings_camera_img_13_main_main_default = lv.style_t()
style_settings_camera_img_13_main_main_default.init()
style_settings_camera_img_13_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_camera_img_13_main_main_default.set_img_recolor_opa(0)
style_settings_camera_img_13_main_main_default.set_img_opa(255)

# add style for settings_camera_img_13
settings_camera_img_13.add_style(style_settings_camera_img_13_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_img_9 = lv.img(settings_camera_cont_1)
settings_camera_img_9.set_pos(40,509)
settings_camera_img_9.set_size(25,25)
settings_camera_img_9.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1400306841.png','rb') as f:
        settings_camera_img_9_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1400306841.png')
    sys.exit()

settings_camera_img_9_img = lv.img_dsc_t({
  'data_size': len(settings_camera_img_9_img_data),
  'header': {'always_zero': 0, 'w': 25, 'h': 25, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_camera_img_9_img_data
})

settings_camera_img_9.set_src(settings_camera_img_9_img)
settings_camera_img_9.set_pivot(0,0)
settings_camera_img_9.set_angle(0)
# create style style_settings_camera_img_9_main_main_default
style_settings_camera_img_9_main_main_default = lv.style_t()
style_settings_camera_img_9_main_main_default.init()
style_settings_camera_img_9_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_camera_img_9_main_main_default.set_img_recolor_opa(0)
style_settings_camera_img_9_main_main_default.set_img_opa(255)

# add style for settings_camera_img_9
settings_camera_img_9.add_style(style_settings_camera_img_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_img_10 = lv.img(settings_camera_cont_1)
settings_camera_img_10.set_pos(40,586)
settings_camera_img_10.set_size(32,32)
settings_camera_img_10.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1737858481.png','rb') as f:
        settings_camera_img_10_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1737858481.png')
    sys.exit()

settings_camera_img_10_img = lv.img_dsc_t({
  'data_size': len(settings_camera_img_10_img_data),
  'header': {'always_zero': 0, 'w': 32, 'h': 32, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_camera_img_10_img_data
})

settings_camera_img_10.set_src(settings_camera_img_10_img)
settings_camera_img_10.set_pivot(0,0)
settings_camera_img_10.set_angle(0)
# create style style_settings_camera_img_10_main_main_default
style_settings_camera_img_10_main_main_default = lv.style_t()
style_settings_camera_img_10_main_main_default.init()
style_settings_camera_img_10_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_camera_img_10_main_main_default.set_img_recolor_opa(0)
style_settings_camera_img_10_main_main_default.set_img_opa(255)

# add style for settings_camera_img_10
settings_camera_img_10.add_style(style_settings_camera_img_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_label_1 = lv.label(settings_camera_cont_1)
settings_camera_label_1.set_pos(0,719)
settings_camera_label_1.set_size(480,80)
# create style style_settings_camera_label_1_main_main_default
style_settings_camera_label_1_main_main_default = lv.style_t()
style_settings_camera_label_1_main_main_default.init()
style_settings_camera_label_1_main_main_default.set_radius(0)
style_settings_camera_label_1_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_settings_camera_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_settings_camera_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_camera_label_1_main_main_default.set_bg_opa(255)
style_settings_camera_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_settings_camera_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_settings_camera_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_settings_camera_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_settings_camera_label_1_main_main_default.set_text_letter_space(0)
style_settings_camera_label_1_main_main_default.set_pad_left(0)
style_settings_camera_label_1_main_main_default.set_pad_right(0)
style_settings_camera_label_1_main_main_default.set_pad_top(0)
style_settings_camera_label_1_main_main_default.set_pad_bottom(0)

# add style for settings_camera_label_1
settings_camera_label_1.add_style(style_settings_camera_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_img_1 = lv.img(settings_camera_cont_1)
settings_camera_img_1.set_pos(30,742)
settings_camera_img_1.set_size(48,48)
settings_camera_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png','rb') as f:
        settings_camera_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png')
    sys.exit()

settings_camera_img_1_img = lv.img_dsc_t({
  'data_size': len(settings_camera_img_1_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_camera_img_1_img_data
})

settings_camera_img_1.set_src(settings_camera_img_1_img)
settings_camera_img_1.set_pivot(0,0)
settings_camera_img_1.set_angle(0)
# create style style_settings_camera_img_1_main_main_default
style_settings_camera_img_1_main_main_default = lv.style_t()
style_settings_camera_img_1_main_main_default.init()
style_settings_camera_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_camera_img_1_main_main_default.set_img_recolor_opa(0)
style_settings_camera_img_1_main_main_default.set_img_opa(255)

# add style for settings_camera_img_1
settings_camera_img_1.add_style(style_settings_camera_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_img_2 = lv.img(settings_camera_cont_1)
settings_camera_img_2.set_pos(128,742)
settings_camera_img_2.set_size(48,48)
settings_camera_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png','rb') as f:
        settings_camera_img_2_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png')
    sys.exit()

settings_camera_img_2_img = lv.img_dsc_t({
  'data_size': len(settings_camera_img_2_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_camera_img_2_img_data
})

settings_camera_img_2.set_src(settings_camera_img_2_img)
settings_camera_img_2.set_pivot(0,0)
settings_camera_img_2.set_angle(0)
# create style style_settings_camera_img_2_main_main_default
style_settings_camera_img_2_main_main_default = lv.style_t()
style_settings_camera_img_2_main_main_default.init()
style_settings_camera_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_camera_img_2_main_main_default.set_img_recolor_opa(0)
style_settings_camera_img_2_main_main_default.set_img_opa(255)

# add style for settings_camera_img_2
settings_camera_img_2.add_style(style_settings_camera_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_img_3 = lv.img(settings_camera_cont_1)
settings_camera_img_3.set_pos(224,742)
settings_camera_img_3.set_size(48,48)
settings_camera_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png','rb') as f:
        settings_camera_img_3_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png')
    sys.exit()

settings_camera_img_3_img = lv.img_dsc_t({
  'data_size': len(settings_camera_img_3_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_camera_img_3_img_data
})

settings_camera_img_3.set_src(settings_camera_img_3_img)
settings_camera_img_3.set_pivot(0,0)
settings_camera_img_3.set_angle(0)
# create style style_settings_camera_img_3_main_main_default
style_settings_camera_img_3_main_main_default = lv.style_t()
style_settings_camera_img_3_main_main_default.init()
style_settings_camera_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_camera_img_3_main_main_default.set_img_recolor_opa(0)
style_settings_camera_img_3_main_main_default.set_img_opa(255)

# add style for settings_camera_img_3
settings_camera_img_3.add_style(style_settings_camera_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_img_4 = lv.img(settings_camera_cont_1)
settings_camera_img_4.set_pos(318,742)
settings_camera_img_4.set_size(48,48)
settings_camera_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png','rb') as f:
        settings_camera_img_4_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png')
    sys.exit()

settings_camera_img_4_img = lv.img_dsc_t({
  'data_size': len(settings_camera_img_4_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_camera_img_4_img_data
})

settings_camera_img_4.set_src(settings_camera_img_4_img)
settings_camera_img_4.set_pivot(0,0)
settings_camera_img_4.set_angle(0)
# create style style_settings_camera_img_4_main_main_default
style_settings_camera_img_4_main_main_default = lv.style_t()
style_settings_camera_img_4_main_main_default.init()
style_settings_camera_img_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_camera_img_4_main_main_default.set_img_recolor_opa(0)
style_settings_camera_img_4_main_main_default.set_img_opa(255)

# add style for settings_camera_img_4
settings_camera_img_4.add_style(style_settings_camera_img_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

settings_camera_img_5 = lv.img(settings_camera_cont_1)
settings_camera_img_5.set_pos(414,742)
settings_camera_img_5.set_size(48,48)
settings_camera_img_5.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png','rb') as f:
        settings_camera_img_5_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png')
    sys.exit()

settings_camera_img_5_img = lv.img_dsc_t({
  'data_size': len(settings_camera_img_5_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': settings_camera_img_5_img_data
})

settings_camera_img_5.set_src(settings_camera_img_5_img)
settings_camera_img_5.set_pivot(0,0)
settings_camera_img_5.set_angle(0)
# create style style_settings_camera_img_5_main_main_default
style_settings_camera_img_5_main_main_default = lv.style_t()
style_settings_camera_img_5_main_main_default.init()
style_settings_camera_img_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_settings_camera_img_5_main_main_default.set_img_recolor_opa(0)
style_settings_camera_img_5_main_main_default.set_img_opa(255)

# add style for settings_camera_img_5
settings_camera_img_5.add_style(style_settings_camera_img_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_settings_camera_cont_1_main_main_default
style_settings_camera_cont_1_main_main_default = lv.style_t()
style_settings_camera_cont_1_main_main_default.init()
style_settings_camera_cont_1_main_main_default.set_radius(0)
style_settings_camera_cont_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_settings_camera_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_settings_camera_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_settings_camera_cont_1_main_main_default.set_bg_opa(255)
style_settings_camera_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_settings_camera_cont_1_main_main_default.set_border_width(0)
style_settings_camera_cont_1_main_main_default.set_border_opa(255)
style_settings_camera_cont_1_main_main_default.set_pad_left(0)
style_settings_camera_cont_1_main_main_default.set_pad_right(0)
style_settings_camera_cont_1_main_main_default.set_pad_top(0)
style_settings_camera_cont_1_main_main_default.set_pad_bottom(0)

# add style for settings_camera_cont_1
settings_camera_cont_1.add_style(style_settings_camera_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

camera_seting = lv.obj()
# create style style_camera_seting_main_main_default
style_camera_seting_main_main_default = lv.style_t()
style_camera_seting_main_main_default.init()
style_camera_seting_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_camera_seting_main_main_default.set_bg_opa(0)

# add style for camera_seting
camera_seting.add_style(style_camera_seting_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

camera_seting_cont_1 = lv.obj(camera_seting)
camera_seting_cont_1.set_pos(0,0)
camera_seting_cont_1.set_size(480,800)
camera_seting_label_3 = lv.label(camera_seting_cont_1)
camera_seting_label_3.set_pos(9,63)
camera_seting_label_3.set_size(460,727)
# create style style_camera_seting_label_3_main_main_default
style_camera_seting_label_3_main_main_default = lv.style_t()
style_camera_seting_label_3_main_main_default.init()
style_camera_seting_label_3_main_main_default.set_radius(0)
style_camera_seting_label_3_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_camera_seting_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_camera_seting_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_label_3_main_main_default.set_bg_opa(255)
style_camera_seting_label_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_camera_seting_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_camera_seting_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_camera_seting_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_camera_seting_label_3_main_main_default.set_text_letter_space(0)
style_camera_seting_label_3_main_main_default.set_pad_left(0)
style_camera_seting_label_3_main_main_default.set_pad_right(0)
style_camera_seting_label_3_main_main_default.set_pad_top(0)
style_camera_seting_label_3_main_main_default.set_pad_bottom(0)

# add style for camera_seting_label_3
camera_seting_label_3.add_style(style_camera_seting_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

camera_seting_ddlist_1 = lv.dropdown(camera_seting_cont_1)
camera_seting_ddlist_1.set_pos(238,284)
camera_seting_ddlist_1.set_width(218)
camera_seting_ddlist_1.set_options("MP4-15\nMP4-25")
# create style style_camera_seting_ddlist_1_extra_list_selected_default
style_camera_seting_ddlist_1_extra_list_selected_default = lv.style_t()
style_camera_seting_ddlist_1_extra_list_selected_default.init()
style_camera_seting_ddlist_1_extra_list_selected_default.set_radius(0)
style_camera_seting_ddlist_1_extra_list_selected_default.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_camera_seting_ddlist_1_extra_list_selected_default.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_camera_seting_ddlist_1_extra_list_selected_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_ddlist_1_extra_list_selected_default.set_bg_opa(255)
style_camera_seting_ddlist_1_extra_list_selected_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_camera_seting_ddlist_1_extra_list_selected_default.set_border_width(0)
style_camera_seting_ddlist_1_extra_list_selected_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_camera_seting_ddlist_1_extra_list_selected_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_camera_seting_ddlist_1_extra_list_selected_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_camera_seting_ddlist_1_extra_list_selected_default.set_text_font(lv.font_montserrat_16)

def camera_seting_ddlist_1_event_cb(e):
    camera_seting_ddlist_1.get_list().add_style(style_camera_seting_ddlist_1_extra_list_selected_default, lv.PART.SELECTED|lv.STATE.DEFAULT)

camera_seting_ddlist_1.add_event_cb(camera_seting_ddlist_1_event_cb, lv.EVENT.READY, None)

# create style style_camera_seting_ddlist_1_extra_list_main_default
style_camera_seting_ddlist_1_extra_list_main_default = lv.style_t()
style_camera_seting_ddlist_1_extra_list_main_default.init()
style_camera_seting_ddlist_1_extra_list_main_default.set_radius(3)
style_camera_seting_ddlist_1_extra_list_main_default.set_bg_color(lv.color_make(0x3c,0x3e,0x42))
style_camera_seting_ddlist_1_extra_list_main_default.set_bg_grad_color(lv.color_make(0x3c,0x3e,0x42))
style_camera_seting_ddlist_1_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_ddlist_1_extra_list_main_default.set_bg_opa(255)
style_camera_seting_ddlist_1_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_camera_seting_ddlist_1_extra_list_main_default.set_border_width(0)
style_camera_seting_ddlist_1_extra_list_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_camera_seting_ddlist_1_extra_list_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_camera_seting_ddlist_1_extra_list_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_camera_seting_ddlist_1_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_camera_seting_ddlist_1_extra_list_main_default.set_max_height(90)

def camera_seting_ddlist_1_event_cb(e):
    camera_seting_ddlist_1.get_list().add_style(style_camera_seting_ddlist_1_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

camera_seting_ddlist_1.add_event_cb(camera_seting_ddlist_1_event_cb, lv.EVENT.READY, None)

# create style style_camera_seting_ddlist_1_extra_list_scrollbar_default
style_camera_seting_ddlist_1_extra_list_scrollbar_default = lv.style_t()
style_camera_seting_ddlist_1_extra_list_scrollbar_default.init()
style_camera_seting_ddlist_1_extra_list_scrollbar_default.set_radius(3)
style_camera_seting_ddlist_1_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x00,0xff,0x00))
style_camera_seting_ddlist_1_extra_list_scrollbar_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_camera_seting_ddlist_1_extra_list_scrollbar_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_ddlist_1_extra_list_scrollbar_default.set_bg_opa(255)

def camera_seting_ddlist_1_event_cb(e):
    camera_seting_ddlist_1.get_list().add_style(style_camera_seting_ddlist_1_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

camera_seting_ddlist_1.add_event_cb(camera_seting_ddlist_1_event_cb, lv.EVENT.READY, None)

# create style style_camera_seting_ddlist_1_main_main_default
style_camera_seting_ddlist_1_main_main_default = lv.style_t()
style_camera_seting_ddlist_1_main_main_default.init()
style_camera_seting_ddlist_1_main_main_default.set_radius(2)
style_camera_seting_ddlist_1_main_main_default.set_bg_color(lv.color_make(0x4f,0x52,0x55))
style_camera_seting_ddlist_1_main_main_default.set_bg_grad_color(lv.color_make(0x4f,0x52,0x55))
style_camera_seting_ddlist_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_ddlist_1_main_main_default.set_bg_opa(255)
style_camera_seting_ddlist_1_main_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_camera_seting_ddlist_1_main_main_default.set_border_width(0)
style_camera_seting_ddlist_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_camera_seting_ddlist_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_camera_seting_ddlist_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_camera_seting_ddlist_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_camera_seting_ddlist_1_main_main_default.set_text_line_space(20)

# add style for camera_seting_ddlist_1
camera_seting_ddlist_1.add_style(style_camera_seting_ddlist_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

camera_seting_sw_1 = lv.switch(camera_seting_cont_1)
camera_seting_sw_1.set_pos(380,90)
camera_seting_sw_1.set_size(74,36)
# create style style_camera_seting_sw_1_main_main_default
style_camera_seting_sw_1_main_main_default = lv.style_t()
style_camera_seting_sw_1_main_main_default.init()
style_camera_seting_sw_1_main_main_default.set_radius(100)
style_camera_seting_sw_1_main_main_default.set_bg_color(lv.color_make(0xe6,0xe2,0xe6))
style_camera_seting_sw_1_main_main_default.set_bg_grad_color(lv.color_make(0xe6,0xe2,0xe6))
style_camera_seting_sw_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_sw_1_main_main_default.set_bg_opa(255)

# add style for camera_seting_sw_1
camera_seting_sw_1.add_style(style_camera_seting_sw_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_camera_seting_sw_1_main_indicator_checked
style_camera_seting_sw_1_main_indicator_checked = lv.style_t()
style_camera_seting_sw_1_main_indicator_checked.init()
style_camera_seting_sw_1_main_indicator_checked.set_radius(100)
style_camera_seting_sw_1_main_indicator_checked.set_bg_color(lv.color_make(0x42,0xbd,0xd8))
style_camera_seting_sw_1_main_indicator_checked.set_bg_grad_color(lv.color_make(0x42,0xbd,0xd8))
style_camera_seting_sw_1_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_sw_1_main_indicator_checked.set_bg_opa(255)

# add style for camera_seting_sw_1
camera_seting_sw_1.add_style(style_camera_seting_sw_1_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

# create style style_camera_seting_sw_1_main_knob_default
style_camera_seting_sw_1_main_knob_default = lv.style_t()
style_camera_seting_sw_1_main_knob_default.init()
style_camera_seting_sw_1_main_knob_default.set_radius(100)
style_camera_seting_sw_1_main_knob_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_camera_seting_sw_1_main_knob_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_camera_seting_sw_1_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_sw_1_main_knob_default.set_bg_opa(255)

# add style for camera_seting_sw_1
camera_seting_sw_1.add_style(style_camera_seting_sw_1_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

camera_seting_label_1 = lv.label(camera_seting_cont_1)
camera_seting_label_1.set_pos(0,0)
camera_seting_label_1.set_size(480,53)
# create style style_camera_seting_label_1_main_main_default
style_camera_seting_label_1_main_main_default = lv.style_t()
style_camera_seting_label_1_main_main_default.init()
style_camera_seting_label_1_main_main_default.set_radius(0)
style_camera_seting_label_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_camera_seting_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_camera_seting_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_label_1_main_main_default.set_bg_opa(255)
style_camera_seting_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_camera_seting_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_camera_seting_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_camera_seting_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_camera_seting_label_1_main_main_default.set_text_letter_space(2)
style_camera_seting_label_1_main_main_default.set_pad_left(0)
style_camera_seting_label_1_main_main_default.set_pad_right(0)
style_camera_seting_label_1_main_main_default.set_pad_top(0)
style_camera_seting_label_1_main_main_default.set_pad_bottom(0)

# add style for camera_seting_label_1
camera_seting_label_1.add_style(style_camera_seting_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

camera_seting_ta_1 = lv.textarea(camera_seting_cont_1)
camera_seting_ta_1.set_pos(233,221)
camera_seting_ta_1.set_size(89,30)
camera_seting_ta_1.set_text("3")
try:
    camera_seting_cont_1_kb
except NameError:
    camera_seting_cont_1_kb = lv.keyboard(camera_seting_cont_1)

camera_seting_cont_1_kb.add_flag(lv.obj.FLAG.HIDDEN)
camera_seting_cont_1_kb.set_textarea(camera_seting_ta_1)
camera_seting_ta_1.add_event_cb(lambda e: ta_event_cb(e,camera_seting_cont_1_kb), lv.EVENT.ALL, None)
# create style style_camera_seting_ta_1_main_main_default
style_camera_seting_ta_1_main_main_default = lv.style_t()
style_camera_seting_ta_1_main_main_default.init()
style_camera_seting_ta_1_main_main_default.set_radius(0)
style_camera_seting_ta_1_main_main_default.set_bg_color(lv.color_make(0x83,0x86,0x8b))
style_camera_seting_ta_1_main_main_default.set_bg_grad_color(lv.color_make(0x83,0x86,0x8b))
style_camera_seting_ta_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_ta_1_main_main_default.set_bg_opa(255)
style_camera_seting_ta_1_main_main_default.set_border_color(lv.color_make(0xe6,0xe6,0xe6))
style_camera_seting_ta_1_main_main_default.set_border_width(0)
style_camera_seting_ta_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_camera_seting_ta_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_camera_seting_ta_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_camera_seting_ta_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_camera_seting_ta_1_main_main_default.set_text_letter_space(2)
style_camera_seting_ta_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_camera_seting_ta_1_main_main_default.set_pad_left(2)
style_camera_seting_ta_1_main_main_default.set_pad_right(2)
style_camera_seting_ta_1_main_main_default.set_pad_top(2)
style_camera_seting_ta_1_main_main_default.set_pad_bottom(2)

# add style for camera_seting_ta_1
camera_seting_ta_1.add_style(style_camera_seting_ta_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_camera_seting_ta_1_main_scrollbar_default
style_camera_seting_ta_1_main_scrollbar_default = lv.style_t()
style_camera_seting_ta_1_main_scrollbar_default.init()
style_camera_seting_ta_1_main_scrollbar_default.set_radius(0)
style_camera_seting_ta_1_main_scrollbar_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_camera_seting_ta_1_main_scrollbar_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_camera_seting_ta_1_main_scrollbar_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_ta_1_main_scrollbar_default.set_bg_opa(255)

# add style for camera_seting_ta_1
camera_seting_ta_1.add_style(style_camera_seting_ta_1_main_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

camera_seting_btn_1 = lv.btn(camera_seting_cont_1)
camera_seting_btn_1.set_pos(0,0)
camera_seting_btn_1.set_size(85,50)
# create style style_camera_seting_btn_1_main_main_default
style_camera_seting_btn_1_main_main_default = lv.style_t()
style_camera_seting_btn_1_main_main_default.init()
style_camera_seting_btn_1_main_main_default.set_radius(0)
style_camera_seting_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_camera_seting_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_camera_seting_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_btn_1_main_main_default.set_bg_opa(0)
style_camera_seting_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_camera_seting_btn_1_main_main_default.set_shadow_opa(0)
style_camera_seting_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_camera_seting_btn_1_main_main_default.set_border_width(0)
style_camera_seting_btn_1_main_main_default.set_border_opa(255)

# add style for camera_seting_btn_1
camera_seting_btn_1.add_style(style_camera_seting_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

camera_seting_img_1 = lv.img(camera_seting_cont_1)
camera_seting_img_1.set_pos(21,17)
camera_seting_img_1.set_size(36,24)
camera_seting_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png','rb') as f:
        camera_seting_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png')
    sys.exit()

camera_seting_img_1_img = lv.img_dsc_t({
  'data_size': len(camera_seting_img_1_img_data),
  'header': {'always_zero': 0, 'w': 36, 'h': 24, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': camera_seting_img_1_img_data
})

camera_seting_img_1.set_src(camera_seting_img_1_img)
camera_seting_img_1.set_pivot(0,0)
camera_seting_img_1.set_angle(0)
# create style style_camera_seting_img_1_main_main_default
style_camera_seting_img_1_main_main_default = lv.style_t()
style_camera_seting_img_1_main_main_default.init()
style_camera_seting_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_camera_seting_img_1_main_main_default.set_img_recolor_opa(0)
style_camera_seting_img_1_main_main_default.set_img_opa(255)

# add style for camera_seting_img_1
camera_seting_img_1.add_style(style_camera_seting_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

camera_seting_label_2 = lv.label(camera_seting_cont_1)
camera_seting_label_2.set_pos(90,11)
camera_seting_label_2.set_size(300,32)
camera_seting_label_2.set_text("摄像头设置")
camera_seting_label_2.set_long_mode(lv.label.LONG.WRAP)
camera_seting_label_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_camera_seting_label_2_main_main_default
style_camera_seting_label_2_main_main_default = lv.style_t()
style_camera_seting_label_2_main_main_default.init()
style_camera_seting_label_2_main_main_default.set_radius(0)
style_camera_seting_label_2_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_camera_seting_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_camera_seting_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_label_2_main_main_default.set_bg_opa(0)
style_camera_seting_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_camera_seting_label_2_main_main_default.set_text_font(lv.font_simsun_32)
except AttributeError:
    try:
        style_camera_seting_label_2_main_main_default.set_text_font(lv.font_montserrat_32)
    except AttributeError:
        style_camera_seting_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_camera_seting_label_2_main_main_default.set_text_letter_space(2)
style_camera_seting_label_2_main_main_default.set_pad_left(0)
style_camera_seting_label_2_main_main_default.set_pad_right(0)
style_camera_seting_label_2_main_main_default.set_pad_top(0)
style_camera_seting_label_2_main_main_default.set_pad_bottom(0)

# add style for camera_seting_label_2
camera_seting_label_2.add_style(style_camera_seting_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

camera_seting_label_4 = lv.label(camera_seting_cont_1)
camera_seting_label_4.set_pos(24,95)
camera_seting_label_4.set_size(178,24)
camera_seting_label_4.set_text("启用延时摄影")
camera_seting_label_4.set_long_mode(lv.label.LONG.WRAP)
camera_seting_label_4.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_camera_seting_label_4_main_main_default
style_camera_seting_label_4_main_main_default = lv.style_t()
style_camera_seting_label_4_main_main_default.init()
style_camera_seting_label_4_main_main_default.set_radius(0)
style_camera_seting_label_4_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_camera_seting_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_camera_seting_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_label_4_main_main_default.set_bg_opa(0)
style_camera_seting_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_camera_seting_label_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_camera_seting_label_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_camera_seting_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_camera_seting_label_4_main_main_default.set_text_letter_space(0)
style_camera_seting_label_4_main_main_default.set_pad_left(0)
style_camera_seting_label_4_main_main_default.set_pad_right(0)
style_camera_seting_label_4_main_main_default.set_pad_top(0)
style_camera_seting_label_4_main_main_default.set_pad_bottom(0)

# add style for camera_seting_label_4
camera_seting_label_4.add_style(style_camera_seting_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

camera_seting_label_9 = lv.label(camera_seting_cont_1)
camera_seting_label_9.set_pos(300,158)
camera_seting_label_9.set_size(150,24)
camera_seting_label_9.set_text("每层起始位置")
camera_seting_label_9.set_long_mode(lv.label.LONG.WRAP)
camera_seting_label_9.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_camera_seting_label_9_main_main_default
style_camera_seting_label_9_main_main_default = lv.style_t()
style_camera_seting_label_9_main_main_default.init()
style_camera_seting_label_9_main_main_default.set_radius(0)
style_camera_seting_label_9_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_camera_seting_label_9_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_camera_seting_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_label_9_main_main_default.set_bg_opa(0)
style_camera_seting_label_9_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_camera_seting_label_9_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_camera_seting_label_9_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_camera_seting_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_camera_seting_label_9_main_main_default.set_text_letter_space(0)
style_camera_seting_label_9_main_main_default.set_pad_left(0)
style_camera_seting_label_9_main_main_default.set_pad_right(0)
style_camera_seting_label_9_main_main_default.set_pad_top(0)
style_camera_seting_label_9_main_main_default.set_pad_bottom(0)

# add style for camera_seting_label_9
camera_seting_label_9.add_style(style_camera_seting_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

camera_seting_label_10 = lv.label(camera_seting_cont_1)
camera_seting_label_10.set_pos(321,224)
camera_seting_label_10.set_size(128,24)
camera_seting_label_10.set_text("层拍摄一次")
camera_seting_label_10.set_long_mode(lv.label.LONG.WRAP)
camera_seting_label_10.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_camera_seting_label_10_main_main_default
style_camera_seting_label_10_main_main_default = lv.style_t()
style_camera_seting_label_10_main_main_default.init()
style_camera_seting_label_10_main_main_default.set_radius(0)
style_camera_seting_label_10_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_camera_seting_label_10_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_camera_seting_label_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_label_10_main_main_default.set_bg_opa(0)
style_camera_seting_label_10_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_camera_seting_label_10_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_camera_seting_label_10_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_camera_seting_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_camera_seting_label_10_main_main_default.set_text_letter_space(0)
style_camera_seting_label_10_main_main_default.set_pad_left(0)
style_camera_seting_label_10_main_main_default.set_pad_right(0)
style_camera_seting_label_10_main_main_default.set_pad_top(0)
style_camera_seting_label_10_main_main_default.set_pad_bottom(0)

# add style for camera_seting_label_10
camera_seting_label_10.add_style(style_camera_seting_label_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

camera_seting_label_12 = lv.label(camera_seting_cont_1)
camera_seting_label_12.set_pos(196,224)
camera_seting_label_12.set_size(31,24)
camera_seting_label_12.set_text("每")
camera_seting_label_12.set_long_mode(lv.label.LONG.WRAP)
camera_seting_label_12.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_camera_seting_label_12_main_main_default
style_camera_seting_label_12_main_main_default = lv.style_t()
style_camera_seting_label_12_main_main_default.init()
style_camera_seting_label_12_main_main_default.set_radius(0)
style_camera_seting_label_12_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_camera_seting_label_12_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_camera_seting_label_12_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_label_12_main_main_default.set_bg_opa(0)
style_camera_seting_label_12_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_camera_seting_label_12_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_camera_seting_label_12_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_camera_seting_label_12_main_main_default.set_text_font(lv.font_montserrat_16)
style_camera_seting_label_12_main_main_default.set_text_letter_space(0)
style_camera_seting_label_12_main_main_default.set_pad_left(0)
style_camera_seting_label_12_main_main_default.set_pad_right(0)
style_camera_seting_label_12_main_main_default.set_pad_top(0)
style_camera_seting_label_12_main_main_default.set_pad_bottom(0)

# add style for camera_seting_label_12
camera_seting_label_12.add_style(style_camera_seting_label_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

camera_seting_label_5 = lv.label(camera_seting_cont_1)
camera_seting_label_5.set_pos(24,158)
camera_seting_label_5.set_size(196,24)
camera_seting_label_5.set_text("拍照位置")
camera_seting_label_5.set_long_mode(lv.label.LONG.WRAP)
camera_seting_label_5.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_camera_seting_label_5_main_main_default
style_camera_seting_label_5_main_main_default = lv.style_t()
style_camera_seting_label_5_main_main_default.init()
style_camera_seting_label_5_main_main_default.set_radius(0)
style_camera_seting_label_5_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_camera_seting_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_camera_seting_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_label_5_main_main_default.set_bg_opa(0)
style_camera_seting_label_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_camera_seting_label_5_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_camera_seting_label_5_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_camera_seting_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_camera_seting_label_5_main_main_default.set_text_letter_space(0)
style_camera_seting_label_5_main_main_default.set_pad_left(0)
style_camera_seting_label_5_main_main_default.set_pad_right(0)
style_camera_seting_label_5_main_main_default.set_pad_top(0)
style_camera_seting_label_5_main_main_default.set_pad_bottom(0)

# add style for camera_seting_label_5
camera_seting_label_5.add_style(style_camera_seting_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

camera_seting_label_6 = lv.label(camera_seting_cont_1)
camera_seting_label_6.set_pos(24,221)
camera_seting_label_6.set_size(175,24)
camera_seting_label_6.set_text("拍照频率")
camera_seting_label_6.set_long_mode(lv.label.LONG.WRAP)
camera_seting_label_6.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_camera_seting_label_6_main_main_default
style_camera_seting_label_6_main_main_default = lv.style_t()
style_camera_seting_label_6_main_main_default.init()
style_camera_seting_label_6_main_main_default.set_radius(0)
style_camera_seting_label_6_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_camera_seting_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_camera_seting_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_label_6_main_main_default.set_bg_opa(0)
style_camera_seting_label_6_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_camera_seting_label_6_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_camera_seting_label_6_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_camera_seting_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_camera_seting_label_6_main_main_default.set_text_letter_space(0)
style_camera_seting_label_6_main_main_default.set_pad_left(0)
style_camera_seting_label_6_main_main_default.set_pad_right(0)
style_camera_seting_label_6_main_main_default.set_pad_top(0)
style_camera_seting_label_6_main_main_default.set_pad_bottom(0)

# add style for camera_seting_label_6
camera_seting_label_6.add_style(style_camera_seting_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

camera_seting_label_7 = lv.label(camera_seting_cont_1)
camera_seting_label_7.set_pos(24,285)
camera_seting_label_7.set_size(205,24)
camera_seting_label_7.set_text("渲染方式")
camera_seting_label_7.set_long_mode(lv.label.LONG.WRAP)
camera_seting_label_7.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_camera_seting_label_7_main_main_default
style_camera_seting_label_7_main_main_default = lv.style_t()
style_camera_seting_label_7_main_main_default.init()
style_camera_seting_label_7_main_main_default.set_radius(0)
style_camera_seting_label_7_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_camera_seting_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_camera_seting_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_label_7_main_main_default.set_bg_opa(0)
style_camera_seting_label_7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_camera_seting_label_7_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_camera_seting_label_7_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_camera_seting_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_camera_seting_label_7_main_main_default.set_text_letter_space(0)
style_camera_seting_label_7_main_main_default.set_pad_left(0)
style_camera_seting_label_7_main_main_default.set_pad_right(0)
style_camera_seting_label_7_main_main_default.set_pad_top(0)
style_camera_seting_label_7_main_main_default.set_pad_bottom(0)

# add style for camera_seting_label_7
camera_seting_label_7.add_style(style_camera_seting_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_camera_seting_cont_1_main_main_default
style_camera_seting_cont_1_main_main_default = lv.style_t()
style_camera_seting_cont_1_main_main_default.init()
style_camera_seting_cont_1_main_main_default.set_radius(0)
style_camera_seting_cont_1_main_main_default.set_bg_color(lv.color_make(0x23,0x24,0x26))
style_camera_seting_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x23,0x24,0x26))
style_camera_seting_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_camera_seting_cont_1_main_main_default.set_bg_opa(255)
style_camera_seting_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_camera_seting_cont_1_main_main_default.set_border_width(0)
style_camera_seting_cont_1_main_main_default.set_border_opa(255)
style_camera_seting_cont_1_main_main_default.set_pad_left(0)
style_camera_seting_cont_1_main_main_default.set_pad_right(0)
style_camera_seting_cont_1_main_main_default.set_pad_top(0)
style_camera_seting_cont_1_main_main_default.set_pad_bottom(0)

# add style for camera_seting_cont_1
camera_seting_cont_1.add_style(style_camera_seting_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information = lv.obj()
# create style style_video_information_main_main_default
style_video_information_main_main_default = lv.style_t()
style_video_information_main_main_default.init()
style_video_information_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_video_information_main_main_default.set_bg_opa(0)

# add style for video_information
video_information.add_style(style_video_information_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_cont_1 = lv.obj(video_information)
video_information_cont_1.set_pos(0,0)
video_information_cont_1.set_size(480,800)
video_information_label_3 = lv.label(video_information_cont_1)
video_information_label_3.set_pos(10,63)
video_information_label_3.set_size(460,727)
# create style style_video_information_label_3_main_main_default
style_video_information_label_3_main_main_default = lv.style_t()
style_video_information_label_3_main_main_default.init()
style_video_information_label_3_main_main_default.set_radius(0)
style_video_information_label_3_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_video_information_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_video_information_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_label_3_main_main_default.set_bg_opa(255)
style_video_information_label_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_video_information_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_information_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_information_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_information_label_3_main_main_default.set_text_letter_space(2)
style_video_information_label_3_main_main_default.set_pad_left(0)
style_video_information_label_3_main_main_default.set_pad_right(0)
style_video_information_label_3_main_main_default.set_pad_top(0)
style_video_information_label_3_main_main_default.set_pad_bottom(0)

# add style for video_information_label_3
video_information_label_3.add_style(style_video_information_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_btn_2 = lv.btn(video_information_cont_1)
video_information_btn_2.set_pos(193,710)
video_information_btn_2.set_size(116,60)
video_information_btn_2_label = lv.label(video_information_btn_2)
video_information_btn_2_label.set_text("上传云")
video_information_btn_2.set_style_pad_all(0, lv.STATE.DEFAULT)
video_information_btn_2_label.align(lv.ALIGN.CENTER,0,0)
video_information_btn_2_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    video_information_btn_2_label.set_style_text_font(lv.font_simsun_24, lv.STATE.DEFAULT)
except AttributeError:
    try:
        video_information_btn_2_label.set_style_text_font(lv.font_montserrat_24, lv.STATE.DEFAULT)
    except AttributeError:
        video_information_btn_2_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_video_information_btn_2_main_main_default
style_video_information_btn_2_main_main_default = lv.style_t()
style_video_information_btn_2_main_main_default.init()
style_video_information_btn_2_main_main_default.set_radius(6)
style_video_information_btn_2_main_main_default.set_bg_color(lv.color_make(0x28,0x29,0x2d))
style_video_information_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x28,0x29,0x2d))
style_video_information_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_btn_2_main_main_default.set_bg_opa(255)
style_video_information_btn_2_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_video_information_btn_2_main_main_default.set_shadow_opa(0)
style_video_information_btn_2_main_main_default.set_border_color(lv.color_make(0x4a,0x4e,0x57))
style_video_information_btn_2_main_main_default.set_border_width(1)
style_video_information_btn_2_main_main_default.set_border_opa(255)

# add style for video_information_btn_2
video_information_btn_2.add_style(style_video_information_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_btn_3 = lv.btn(video_information_cont_1)
video_information_btn_3.set_pos(334,710)
video_information_btn_3.set_size(116,60)
video_information_btn_3_label = lv.label(video_information_btn_3)
video_information_btn_3_label.set_text("导出")
video_information_btn_3.set_style_pad_all(0, lv.STATE.DEFAULT)
video_information_btn_3_label.align(lv.ALIGN.CENTER,0,0)
video_information_btn_3_label.set_style_text_color(lv.color_make(0xff,0xff,0xff), lv.STATE.DEFAULT)
try:
    video_information_btn_3_label.set_style_text_font(lv.font_simsun_24, lv.STATE.DEFAULT)
except AttributeError:
    try:
        video_information_btn_3_label.set_style_text_font(lv.font_montserrat_24, lv.STATE.DEFAULT)
    except AttributeError:
        video_information_btn_3_label.set_style_text_font(lv.font_montserrat_16, lv.STATE.DEFAULT)
# create style style_video_information_btn_3_main_main_default
style_video_information_btn_3_main_main_default = lv.style_t()
style_video_information_btn_3_main_main_default.init()
style_video_information_btn_3_main_main_default.set_radius(6)
style_video_information_btn_3_main_main_default.set_bg_color(lv.color_make(0x28,0x29,0x2d))
style_video_information_btn_3_main_main_default.set_bg_grad_color(lv.color_make(0x28,0x29,0x2d))
style_video_information_btn_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_btn_3_main_main_default.set_bg_opa(255)
style_video_information_btn_3_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_video_information_btn_3_main_main_default.set_shadow_opa(0)
style_video_information_btn_3_main_main_default.set_border_color(lv.color_make(0x4a,0x4e,0x57))
style_video_information_btn_3_main_main_default.set_border_width(1)
style_video_information_btn_3_main_main_default.set_border_opa(255)

# add style for video_information_btn_3
video_information_btn_3.add_style(style_video_information_btn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_img_2 = lv.img(video_information_cont_1)
video_information_img_2.set_pos(30,83)
video_information_img_2.set_size(420,315)
# create style style_video_information_img_2_main_main_default
style_video_information_img_2_main_main_default = lv.style_t()
style_video_information_img_2_main_main_default.init()
style_video_information_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_video_information_img_2_main_main_default.set_img_recolor_opa(0)
style_video_information_img_2_main_main_default.set_img_opa(255)

# add style for video_information_img_2
video_information_img_2.add_style(style_video_information_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_label_1 = lv.label(video_information_cont_1)
video_information_label_1.set_pos(0,0)
video_information_label_1.set_size(480,53)
# create style style_video_information_label_1_main_main_default
style_video_information_label_1_main_main_default = lv.style_t()
style_video_information_label_1_main_main_default.init()
style_video_information_label_1_main_main_default.set_radius(0)
style_video_information_label_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_label_1_main_main_default.set_bg_opa(255)
style_video_information_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_information_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_information_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_information_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_information_label_1_main_main_default.set_text_letter_space(2)
style_video_information_label_1_main_main_default.set_pad_left(0)
style_video_information_label_1_main_main_default.set_pad_right(0)
style_video_information_label_1_main_main_default.set_pad_top(0)
style_video_information_label_1_main_main_default.set_pad_bottom(0)

# add style for video_information_label_1
video_information_label_1.add_style(style_video_information_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_btn_1 = lv.btn(video_information_cont_1)
video_information_btn_1.set_pos(0,0)
video_information_btn_1.set_size(85,50)
# create style style_video_information_btn_1_main_main_default
style_video_information_btn_1_main_main_default = lv.style_t()
style_video_information_btn_1_main_main_default.init()
style_video_information_btn_1_main_main_default.set_radius(0)
style_video_information_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_video_information_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_video_information_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_btn_1_main_main_default.set_bg_opa(0)
style_video_information_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_video_information_btn_1_main_main_default.set_shadow_opa(0)
style_video_information_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_video_information_btn_1_main_main_default.set_border_width(0)
style_video_information_btn_1_main_main_default.set_border_opa(255)

# add style for video_information_btn_1
video_information_btn_1.add_style(style_video_information_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_img_1 = lv.img(video_information_cont_1)
video_information_img_1.set_pos(21,17)
video_information_img_1.set_size(36,24)
video_information_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png','rb') as f:
        video_information_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png')
    sys.exit()

video_information_img_1_img = lv.img_dsc_t({
  'data_size': len(video_information_img_1_img_data),
  'header': {'always_zero': 0, 'w': 36, 'h': 24, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': video_information_img_1_img_data
})

video_information_img_1.set_src(video_information_img_1_img)
video_information_img_1.set_pivot(0,0)
video_information_img_1.set_angle(0)
# create style style_video_information_img_1_main_main_default
style_video_information_img_1_main_main_default = lv.style_t()
style_video_information_img_1_main_main_default.init()
style_video_information_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_video_information_img_1_main_main_default.set_img_recolor_opa(0)
style_video_information_img_1_main_main_default.set_img_opa(255)

# add style for video_information_img_1
video_information_img_1.add_style(style_video_information_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_label_2 = lv.label(video_information_cont_1)
video_information_label_2.set_pos(90,11)
video_information_label_2.set_size(300,32)
video_information_label_2.set_text("视频详情")
video_information_label_2.set_long_mode(lv.label.LONG.WRAP)
video_information_label_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_video_information_label_2_main_main_default
style_video_information_label_2_main_main_default = lv.style_t()
style_video_information_label_2_main_main_default.init()
style_video_information_label_2_main_main_default.set_radius(0)
style_video_information_label_2_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_label_2_main_main_default.set_bg_opa(0)
style_video_information_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_information_label_2_main_main_default.set_text_font(lv.font_simsun_32)
except AttributeError:
    try:
        style_video_information_label_2_main_main_default.set_text_font(lv.font_montserrat_32)
    except AttributeError:
        style_video_information_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_information_label_2_main_main_default.set_text_letter_space(2)
style_video_information_label_2_main_main_default.set_pad_left(0)
style_video_information_label_2_main_main_default.set_pad_right(0)
style_video_information_label_2_main_main_default.set_pad_top(0)
style_video_information_label_2_main_main_default.set_pad_bottom(0)

# add style for video_information_label_2
video_information_label_2.add_style(style_video_information_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_label_4 = lv.label(video_information_cont_1)
video_information_label_4.set_pos(30,420)
video_information_label_4.set_size(205,24)
video_information_label_4.set_text("文件名称:")
video_information_label_4.set_long_mode(lv.label.LONG.WRAP)
video_information_label_4.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_information_label_4_main_main_default
style_video_information_label_4_main_main_default = lv.style_t()
style_video_information_label_4_main_main_default.init()
style_video_information_label_4_main_main_default.set_radius(0)
style_video_information_label_4_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_label_4_main_main_default.set_bg_opa(0)
style_video_information_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_information_label_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_information_label_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_information_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_information_label_4_main_main_default.set_text_letter_space(0)
style_video_information_label_4_main_main_default.set_pad_left(0)
style_video_information_label_4_main_main_default.set_pad_right(0)
style_video_information_label_4_main_main_default.set_pad_top(0)
style_video_information_label_4_main_main_default.set_pad_bottom(0)

# add style for video_information_label_4
video_information_label_4.add_style(style_video_information_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_label_10 = lv.label(video_information_cont_1)
video_information_label_10.set_pos(260,420)
video_information_label_10.set_size(200,24)
video_information_label_10.set_text("Pawn.MP4")
video_information_label_10.set_long_mode(lv.label.LONG.WRAP)
video_information_label_10.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_video_information_label_10_main_main_default
style_video_information_label_10_main_main_default = lv.style_t()
style_video_information_label_10_main_main_default.init()
style_video_information_label_10_main_main_default.set_radius(0)
style_video_information_label_10_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_10_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_label_10_main_main_default.set_bg_opa(0)
style_video_information_label_10_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_information_label_10_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_information_label_10_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_information_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_information_label_10_main_main_default.set_text_letter_space(0)
style_video_information_label_10_main_main_default.set_pad_left(0)
style_video_information_label_10_main_main_default.set_pad_right(0)
style_video_information_label_10_main_main_default.set_pad_top(0)
style_video_information_label_10_main_main_default.set_pad_bottom(0)

# add style for video_information_label_10
video_information_label_10.add_style(style_video_information_label_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_label_11 = lv.label(video_information_cont_1)
video_information_label_11.set_pos(260,457)
video_information_label_11.set_size(200,24)
video_information_label_11.set_text("2022/01/23 12:12")
video_information_label_11.set_long_mode(lv.label.LONG.WRAP)
video_information_label_11.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_video_information_label_11_main_main_default
style_video_information_label_11_main_main_default = lv.style_t()
style_video_information_label_11_main_main_default.init()
style_video_information_label_11_main_main_default.set_radius(0)
style_video_information_label_11_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_11_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_11_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_label_11_main_main_default.set_bg_opa(0)
style_video_information_label_11_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_information_label_11_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_information_label_11_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_information_label_11_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_information_label_11_main_main_default.set_text_letter_space(0)
style_video_information_label_11_main_main_default.set_pad_left(0)
style_video_information_label_11_main_main_default.set_pad_right(0)
style_video_information_label_11_main_main_default.set_pad_top(0)
style_video_information_label_11_main_main_default.set_pad_bottom(0)

# add style for video_information_label_11
video_information_label_11.add_style(style_video_information_label_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_label_12 = lv.label(video_information_cont_1)
video_information_label_12.set_pos(260,494)
video_information_label_12.set_size(200,24)
video_information_label_12.set_text("03h23m")
video_information_label_12.set_long_mode(lv.label.LONG.WRAP)
video_information_label_12.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_video_information_label_12_main_main_default
style_video_information_label_12_main_main_default = lv.style_t()
style_video_information_label_12_main_main_default.init()
style_video_information_label_12_main_main_default.set_radius(0)
style_video_information_label_12_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_12_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_12_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_label_12_main_main_default.set_bg_opa(0)
style_video_information_label_12_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_information_label_12_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_information_label_12_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_information_label_12_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_information_label_12_main_main_default.set_text_letter_space(0)
style_video_information_label_12_main_main_default.set_pad_left(0)
style_video_information_label_12_main_main_default.set_pad_right(0)
style_video_information_label_12_main_main_default.set_pad_top(0)
style_video_information_label_12_main_main_default.set_pad_bottom(0)

# add style for video_information_label_12
video_information_label_12.add_style(style_video_information_label_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_label_13 = lv.label(video_information_cont_1)
video_information_label_13.set_pos(260,548)
video_information_label_13.set_size(200,24)
video_information_label_13.set_text("打印机起始点")
video_information_label_13.set_long_mode(lv.label.LONG.WRAP)
video_information_label_13.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_video_information_label_13_main_main_default
style_video_information_label_13_main_main_default = lv.style_t()
style_video_information_label_13_main_main_default.init()
style_video_information_label_13_main_main_default.set_radius(0)
style_video_information_label_13_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_13_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_13_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_label_13_main_main_default.set_bg_opa(0)
style_video_information_label_13_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_information_label_13_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_information_label_13_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_information_label_13_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_information_label_13_main_main_default.set_text_letter_space(0)
style_video_information_label_13_main_main_default.set_pad_left(0)
style_video_information_label_13_main_main_default.set_pad_right(0)
style_video_information_label_13_main_main_default.set_pad_top(0)
style_video_information_label_13_main_main_default.set_pad_bottom(0)

# add style for video_information_label_13
video_information_label_13.add_style(style_video_information_label_13_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_label_14 = lv.label(video_information_cont_1)
video_information_label_14.set_pos(260,586)
video_information_label_14.set_size(200,24)
video_information_label_14.set_text("每五层拍摄一次")
video_information_label_14.set_long_mode(lv.label.LONG.WRAP)
video_information_label_14.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_video_information_label_14_main_main_default
style_video_information_label_14_main_main_default = lv.style_t()
style_video_information_label_14_main_main_default.init()
style_video_information_label_14_main_main_default.set_radius(0)
style_video_information_label_14_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_14_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_14_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_label_14_main_main_default.set_bg_opa(0)
style_video_information_label_14_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_information_label_14_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_information_label_14_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_information_label_14_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_information_label_14_main_main_default.set_text_letter_space(0)
style_video_information_label_14_main_main_default.set_pad_left(0)
style_video_information_label_14_main_main_default.set_pad_right(0)
style_video_information_label_14_main_main_default.set_pad_top(0)
style_video_information_label_14_main_main_default.set_pad_bottom(0)

# add style for video_information_label_14
video_information_label_14.add_style(style_video_information_label_14_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_label_15 = lv.label(video_information_cont_1)
video_information_label_15.set_pos(260,624)
video_information_label_15.set_size(200,24)
video_information_label_15.set_text("30帧")
video_information_label_15.set_long_mode(lv.label.LONG.WRAP)
video_information_label_15.set_style_text_align(lv.TEXT_ALIGN.RIGHT, 0)
# create style style_video_information_label_15_main_main_default
style_video_information_label_15_main_main_default = lv.style_t()
style_video_information_label_15_main_main_default.init()
style_video_information_label_15_main_main_default.set_radius(0)
style_video_information_label_15_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_15_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_15_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_label_15_main_main_default.set_bg_opa(0)
style_video_information_label_15_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_information_label_15_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_information_label_15_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_information_label_15_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_information_label_15_main_main_default.set_text_letter_space(0)
style_video_information_label_15_main_main_default.set_pad_left(0)
style_video_information_label_15_main_main_default.set_pad_right(0)
style_video_information_label_15_main_main_default.set_pad_top(0)
style_video_information_label_15_main_main_default.set_pad_bottom(0)

# add style for video_information_label_15
video_information_label_15.add_style(style_video_information_label_15_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_label_5 = lv.label(video_information_cont_1)
video_information_label_5.set_pos(30,457)
video_information_label_5.set_size(205,24)
video_information_label_5.set_text("打印日期:")
video_information_label_5.set_long_mode(lv.label.LONG.WRAP)
video_information_label_5.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_information_label_5_main_main_default
style_video_information_label_5_main_main_default = lv.style_t()
style_video_information_label_5_main_main_default.init()
style_video_information_label_5_main_main_default.set_radius(0)
style_video_information_label_5_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_label_5_main_main_default.set_bg_opa(0)
style_video_information_label_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_information_label_5_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_information_label_5_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_information_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_information_label_5_main_main_default.set_text_letter_space(0)
style_video_information_label_5_main_main_default.set_pad_left(0)
style_video_information_label_5_main_main_default.set_pad_right(0)
style_video_information_label_5_main_main_default.set_pad_top(0)
style_video_information_label_5_main_main_default.set_pad_bottom(0)

# add style for video_information_label_5
video_information_label_5.add_style(style_video_information_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_label_6 = lv.label(video_information_cont_1)
video_information_label_6.set_pos(30,494)
video_information_label_6.set_size(205,24)
video_information_label_6.set_text("视频时长:")
video_information_label_6.set_long_mode(lv.label.LONG.WRAP)
video_information_label_6.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_information_label_6_main_main_default
style_video_information_label_6_main_main_default = lv.style_t()
style_video_information_label_6_main_main_default.init()
style_video_information_label_6_main_main_default.set_radius(0)
style_video_information_label_6_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_label_6_main_main_default.set_bg_opa(0)
style_video_information_label_6_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_information_label_6_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_information_label_6_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_information_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_information_label_6_main_main_default.set_text_letter_space(0)
style_video_information_label_6_main_main_default.set_pad_left(0)
style_video_information_label_6_main_main_default.set_pad_right(0)
style_video_information_label_6_main_main_default.set_pad_top(0)
style_video_information_label_6_main_main_default.set_pad_bottom(0)

# add style for video_information_label_6
video_information_label_6.add_style(style_video_information_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_label_7 = lv.label(video_information_cont_1)
video_information_label_7.set_pos(30,548)
video_information_label_7.set_size(205,24)
video_information_label_7.set_text("拍摄位置:")
video_information_label_7.set_long_mode(lv.label.LONG.WRAP)
video_information_label_7.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_information_label_7_main_main_default
style_video_information_label_7_main_main_default = lv.style_t()
style_video_information_label_7_main_main_default.init()
style_video_information_label_7_main_main_default.set_radius(0)
style_video_information_label_7_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_label_7_main_main_default.set_bg_opa(0)
style_video_information_label_7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_information_label_7_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_information_label_7_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_information_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_information_label_7_main_main_default.set_text_letter_space(0)
style_video_information_label_7_main_main_default.set_pad_left(0)
style_video_information_label_7_main_main_default.set_pad_right(0)
style_video_information_label_7_main_main_default.set_pad_top(0)
style_video_information_label_7_main_main_default.set_pad_bottom(0)

# add style for video_information_label_7
video_information_label_7.add_style(style_video_information_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_label_8 = lv.label(video_information_cont_1)
video_information_label_8.set_pos(30,586)
video_information_label_8.set_size(205,24)
video_information_label_8.set_text("拍摄频率:")
video_information_label_8.set_long_mode(lv.label.LONG.WRAP)
video_information_label_8.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_information_label_8_main_main_default
style_video_information_label_8_main_main_default = lv.style_t()
style_video_information_label_8_main_main_default.init()
style_video_information_label_8_main_main_default.set_radius(0)
style_video_information_label_8_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_label_8_main_main_default.set_bg_opa(0)
style_video_information_label_8_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_information_label_8_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_information_label_8_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_information_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_information_label_8_main_main_default.set_text_letter_space(0)
style_video_information_label_8_main_main_default.set_pad_left(0)
style_video_information_label_8_main_main_default.set_pad_right(0)
style_video_information_label_8_main_main_default.set_pad_top(0)
style_video_information_label_8_main_main_default.set_pad_bottom(0)

# add style for video_information_label_8
video_information_label_8.add_style(style_video_information_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_information_label_9 = lv.label(video_information_cont_1)
video_information_label_9.set_pos(30,624)
video_information_label_9.set_size(205,24)
video_information_label_9.set_text("渲染方式:")
video_information_label_9.set_long_mode(lv.label.LONG.WRAP)
video_information_label_9.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_information_label_9_main_main_default
style_video_information_label_9_main_main_default = lv.style_t()
style_video_information_label_9_main_main_default.init()
style_video_information_label_9_main_main_default.set_radius(0)
style_video_information_label_9_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_9_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_information_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_label_9_main_main_default.set_bg_opa(0)
style_video_information_label_9_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_information_label_9_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_information_label_9_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_information_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_information_label_9_main_main_default.set_text_letter_space(0)
style_video_information_label_9_main_main_default.set_pad_left(0)
style_video_information_label_9_main_main_default.set_pad_right(0)
style_video_information_label_9_main_main_default.set_pad_top(0)
style_video_information_label_9_main_main_default.set_pad_bottom(0)

# add style for video_information_label_9
video_information_label_9.add_style(style_video_information_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_video_information_cont_1_main_main_default
style_video_information_cont_1_main_main_default = lv.style_t()
style_video_information_cont_1_main_main_default.init()
style_video_information_cont_1_main_main_default.set_radius(0)
style_video_information_cont_1_main_main_default.set_bg_color(lv.color_make(0x23,0x24,0x26))
style_video_information_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x23,0x24,0x26))
style_video_information_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_information_cont_1_main_main_default.set_bg_opa(255)
style_video_information_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_video_information_cont_1_main_main_default.set_border_width(0)
style_video_information_cont_1_main_main_default.set_border_opa(255)
style_video_information_cont_1_main_main_default.set_pad_left(0)
style_video_information_cont_1_main_main_default.set_pad_right(0)
style_video_information_cont_1_main_main_default.set_pad_top(0)
style_video_information_cont_1_main_main_default.set_pad_bottom(0)

# add style for video_information_cont_1
video_information_cont_1.add_style(style_video_information_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list = lv.obj()
# create style style_video_list_main_main_default
style_video_list_main_main_default = lv.style_t()
style_video_list_main_main_default.init()
style_video_list_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_video_list_main_main_default.set_bg_opa(0)

# add style for video_list
video_list.add_style(style_video_list_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_cont_1 = lv.obj(video_list)
video_list_cont_1.set_pos(0,0)
video_list_cont_1.set_size(480,800)
video_list_label_3 = lv.label(video_list_cont_1)
video_list_label_3.set_pos(10,63)
video_list_label_3.set_size(460,727)
# create style style_video_list_label_3_main_main_default
style_video_list_label_3_main_main_default = lv.style_t()
style_video_list_label_3_main_main_default.init()
style_video_list_label_3_main_main_default.set_radius(0)
style_video_list_label_3_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_video_list_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_video_list_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_label_3_main_main_default.set_bg_opa(255)
style_video_list_label_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_video_list_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_list_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_list_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_list_label_3_main_main_default.set_text_letter_space(2)
style_video_list_label_3_main_main_default.set_pad_left(0)
style_video_list_label_3_main_main_default.set_pad_right(0)
style_video_list_label_3_main_main_default.set_pad_top(0)
style_video_list_label_3_main_main_default.set_pad_bottom(0)

# add style for video_list_label_3
video_list_label_3.add_style(style_video_list_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_btn_2 = lv.btn(video_list_cont_1)
video_list_btn_2.set_pos(418,645)
video_list_btn_2.set_size(60,60)
# create style style_video_list_btn_2_main_main_default
style_video_list_btn_2_main_main_default = lv.style_t()
style_video_list_btn_2_main_main_default.init()
style_video_list_btn_2_main_main_default.set_radius(30)
style_video_list_btn_2_main_main_default.set_bg_color(lv.color_make(0x28,0x29,0x2d))
style_video_list_btn_2_main_main_default.set_bg_grad_color(lv.color_make(0x28,0x29,0x2d))
style_video_list_btn_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_btn_2_main_main_default.set_bg_opa(255)
style_video_list_btn_2_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_video_list_btn_2_main_main_default.set_shadow_opa(0)
style_video_list_btn_2_main_main_default.set_border_color(lv.color_make(0x4a,0x4e,0x57))
style_video_list_btn_2_main_main_default.set_border_width(1)
style_video_list_btn_2_main_main_default.set_border_opa(255)

# add style for video_list_btn_2
video_list_btn_2.add_style(style_video_list_btn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_btn_3 = lv.btn(video_list_cont_1)
video_list_btn_3.set_pos(418,717)
video_list_btn_3.set_size(60,60)
# create style style_video_list_btn_3_main_main_default
style_video_list_btn_3_main_main_default = lv.style_t()
style_video_list_btn_3_main_main_default.init()
style_video_list_btn_3_main_main_default.set_radius(30)
style_video_list_btn_3_main_main_default.set_bg_color(lv.color_make(0x28,0x29,0x2d))
style_video_list_btn_3_main_main_default.set_bg_grad_color(lv.color_make(0x28,0x29,0x2d))
style_video_list_btn_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_btn_3_main_main_default.set_bg_opa(255)
style_video_list_btn_3_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_video_list_btn_3_main_main_default.set_shadow_opa(0)
style_video_list_btn_3_main_main_default.set_border_color(lv.color_make(0x4a,0x4e,0x57))
style_video_list_btn_3_main_main_default.set_border_width(1)
style_video_list_btn_3_main_main_default.set_border_opa(255)

# add style for video_list_btn_3
video_list_btn_3.add_style(style_video_list_btn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_img_2 = lv.img(video_list_cont_1)
video_list_img_2.set_pos(23,80)
video_list_img_2.set_size(96,96)
# create style style_video_list_img_2_main_main_default
style_video_list_img_2_main_main_default = lv.style_t()
style_video_list_img_2_main_main_default.init()
style_video_list_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_video_list_img_2_main_main_default.set_img_recolor_opa(0)
style_video_list_img_2_main_main_default.set_img_opa(255)

# add style for video_list_img_2
video_list_img_2.add_style(style_video_list_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_img_3 = lv.img(video_list_cont_1)
video_list_img_3.set_pos(28,196)
video_list_img_3.set_size(96,96)
# create style style_video_list_img_3_main_main_default
style_video_list_img_3_main_main_default = lv.style_t()
style_video_list_img_3_main_main_default.init()
style_video_list_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_video_list_img_3_main_main_default.set_img_recolor_opa(0)
style_video_list_img_3_main_main_default.set_img_opa(255)

# add style for video_list_img_3
video_list_img_3.add_style(style_video_list_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_img_4 = lv.img(video_list_cont_1)
video_list_img_4.set_pos(28,312)
video_list_img_4.set_size(96,96)
# create style style_video_list_img_4_main_main_default
style_video_list_img_4_main_main_default = lv.style_t()
style_video_list_img_4_main_main_default.init()
style_video_list_img_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_video_list_img_4_main_main_default.set_img_recolor_opa(0)
style_video_list_img_4_main_main_default.set_img_opa(255)

# add style for video_list_img_4
video_list_img_4.add_style(style_video_list_img_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_img_5 = lv.img(video_list_cont_1)
video_list_img_5.set_pos(28,428)
video_list_img_5.set_size(96,96)
# create style style_video_list_img_5_main_main_default
style_video_list_img_5_main_main_default = lv.style_t()
style_video_list_img_5_main_main_default.init()
style_video_list_img_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_video_list_img_5_main_main_default.set_img_recolor_opa(0)
style_video_list_img_5_main_main_default.set_img_opa(255)

# add style for video_list_img_5
video_list_img_5.add_style(style_video_list_img_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_img_6 = lv.img(video_list_cont_1)
video_list_img_6.set_pos(28,544)
video_list_img_6.set_size(96,96)
# create style style_video_list_img_6_main_main_default
style_video_list_img_6_main_main_default = lv.style_t()
style_video_list_img_6_main_main_default.init()
style_video_list_img_6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_video_list_img_6_main_main_default.set_img_recolor_opa(0)
style_video_list_img_6_main_main_default.set_img_opa(255)

# add style for video_list_img_6
video_list_img_6.add_style(style_video_list_img_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_img_7 = lv.img(video_list_cont_1)
video_list_img_7.set_pos(436,668)
video_list_img_7.set_size(24,14)
video_list_img_7.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp44047850.png','rb') as f:
        video_list_img_7_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp44047850.png')
    sys.exit()

video_list_img_7_img = lv.img_dsc_t({
  'data_size': len(video_list_img_7_img_data),
  'header': {'always_zero': 0, 'w': 24, 'h': 14, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': video_list_img_7_img_data
})

video_list_img_7.set_src(video_list_img_7_img)
video_list_img_7.set_pivot(0,0)
video_list_img_7.set_angle(0)
# create style style_video_list_img_7_main_main_default
style_video_list_img_7_main_main_default = lv.style_t()
style_video_list_img_7_main_main_default.init()
style_video_list_img_7_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_video_list_img_7_main_main_default.set_img_recolor_opa(0)
style_video_list_img_7_main_main_default.set_img_opa(255)

# add style for video_list_img_7
video_list_img_7.add_style(style_video_list_img_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_img_9 = lv.img(video_list_cont_1)
video_list_img_9.set_pos(433,114)
video_list_img_9.set_size(14,28)
video_list_img_9.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png','rb') as f:
        video_list_img_9_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png')
    sys.exit()

video_list_img_9_img = lv.img_dsc_t({
  'data_size': len(video_list_img_9_img_data),
  'header': {'always_zero': 0, 'w': 14, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': video_list_img_9_img_data
})

video_list_img_9.set_src(video_list_img_9_img)
video_list_img_9.set_pivot(0,0)
video_list_img_9.set_angle(0)
# create style style_video_list_img_9_main_main_default
style_video_list_img_9_main_main_default = lv.style_t()
style_video_list_img_9_main_main_default.init()
style_video_list_img_9_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_video_list_img_9_main_main_default.set_img_recolor_opa(0)
style_video_list_img_9_main_main_default.set_img_opa(255)

# add style for video_list_img_9
video_list_img_9.add_style(style_video_list_img_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_img_10 = lv.img(video_list_cont_1)
video_list_img_10.set_pos(433,230)
video_list_img_10.set_size(14,28)
video_list_img_10.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png','rb') as f:
        video_list_img_10_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png')
    sys.exit()

video_list_img_10_img = lv.img_dsc_t({
  'data_size': len(video_list_img_10_img_data),
  'header': {'always_zero': 0, 'w': 14, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': video_list_img_10_img_data
})

video_list_img_10.set_src(video_list_img_10_img)
video_list_img_10.set_pivot(0,0)
video_list_img_10.set_angle(0)
# create style style_video_list_img_10_main_main_default
style_video_list_img_10_main_main_default = lv.style_t()
style_video_list_img_10_main_main_default.init()
style_video_list_img_10_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_video_list_img_10_main_main_default.set_img_recolor_opa(0)
style_video_list_img_10_main_main_default.set_img_opa(255)

# add style for video_list_img_10
video_list_img_10.add_style(style_video_list_img_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_img_11 = lv.img(video_list_cont_1)
video_list_img_11.set_pos(433,346)
video_list_img_11.set_size(14,28)
video_list_img_11.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png','rb') as f:
        video_list_img_11_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png')
    sys.exit()

video_list_img_11_img = lv.img_dsc_t({
  'data_size': len(video_list_img_11_img_data),
  'header': {'always_zero': 0, 'w': 14, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': video_list_img_11_img_data
})

video_list_img_11.set_src(video_list_img_11_img)
video_list_img_11.set_pivot(0,0)
video_list_img_11.set_angle(0)
# create style style_video_list_img_11_main_main_default
style_video_list_img_11_main_main_default = lv.style_t()
style_video_list_img_11_main_main_default.init()
style_video_list_img_11_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_video_list_img_11_main_main_default.set_img_recolor_opa(0)
style_video_list_img_11_main_main_default.set_img_opa(255)

# add style for video_list_img_11
video_list_img_11.add_style(style_video_list_img_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_img_12 = lv.img(video_list_cont_1)
video_list_img_12.set_pos(433,462)
video_list_img_12.set_size(14,28)
video_list_img_12.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png','rb') as f:
        video_list_img_12_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png')
    sys.exit()

video_list_img_12_img = lv.img_dsc_t({
  'data_size': len(video_list_img_12_img_data),
  'header': {'always_zero': 0, 'w': 14, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': video_list_img_12_img_data
})

video_list_img_12.set_src(video_list_img_12_img)
video_list_img_12.set_pivot(0,0)
video_list_img_12.set_angle(0)
# create style style_video_list_img_12_main_main_default
style_video_list_img_12_main_main_default = lv.style_t()
style_video_list_img_12_main_main_default.init()
style_video_list_img_12_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_video_list_img_12_main_main_default.set_img_recolor_opa(0)
style_video_list_img_12_main_main_default.set_img_opa(255)

# add style for video_list_img_12
video_list_img_12.add_style(style_video_list_img_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_img_13 = lv.img(video_list_cont_1)
video_list_img_13.set_pos(433,576)
video_list_img_13.set_size(14,28)
video_list_img_13.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png','rb') as f:
        video_list_img_13_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-939421352.png')
    sys.exit()

video_list_img_13_img = lv.img_dsc_t({
  'data_size': len(video_list_img_13_img_data),
  'header': {'always_zero': 0, 'w': 14, 'h': 28, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': video_list_img_13_img_data
})

video_list_img_13.set_src(video_list_img_13_img)
video_list_img_13.set_pivot(0,0)
video_list_img_13.set_angle(0)
# create style style_video_list_img_13_main_main_default
style_video_list_img_13_main_main_default = lv.style_t()
style_video_list_img_13_main_main_default.init()
style_video_list_img_13_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_video_list_img_13_main_main_default.set_img_recolor_opa(0)
style_video_list_img_13_main_main_default.set_img_opa(255)

# add style for video_list_img_13
video_list_img_13.add_style(style_video_list_img_13_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_img_8 = lv.img(video_list_cont_1)
video_list_img_8.set_pos(436,740)
video_list_img_8.set_size(24,14)
video_list_img_8.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-2033161493.png','rb') as f:
        video_list_img_8_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-2033161493.png')
    sys.exit()

video_list_img_8_img = lv.img_dsc_t({
  'data_size': len(video_list_img_8_img_data),
  'header': {'always_zero': 0, 'w': 24, 'h': 14, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': video_list_img_8_img_data
})

video_list_img_8.set_src(video_list_img_8_img)
video_list_img_8.set_pivot(0,0)
video_list_img_8.set_angle(0)
# create style style_video_list_img_8_main_main_default
style_video_list_img_8_main_main_default = lv.style_t()
style_video_list_img_8_main_main_default.init()
style_video_list_img_8_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_video_list_img_8_main_main_default.set_img_recolor_opa(0)
style_video_list_img_8_main_main_default.set_img_opa(255)

# add style for video_list_img_8
video_list_img_8.add_style(style_video_list_img_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_label_1 = lv.label(video_list_cont_1)
video_list_label_1.set_pos(0,0)
video_list_label_1.set_size(480,53)
# create style style_video_list_label_1_main_main_default
style_video_list_label_1_main_main_default = lv.style_t()
style_video_list_label_1_main_main_default.init()
style_video_list_label_1_main_main_default.set_radius(0)
style_video_list_label_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_label_1_main_main_default.set_bg_opa(255)
style_video_list_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_list_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_list_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_list_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_list_label_1_main_main_default.set_text_letter_space(2)
style_video_list_label_1_main_main_default.set_pad_left(0)
style_video_list_label_1_main_main_default.set_pad_right(0)
style_video_list_label_1_main_main_default.set_pad_top(0)
style_video_list_label_1_main_main_default.set_pad_bottom(0)

# add style for video_list_label_1
video_list_label_1.add_style(style_video_list_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_btn_1 = lv.btn(video_list_cont_1)
video_list_btn_1.set_pos(0,0)
video_list_btn_1.set_size(85,50)
# create style style_video_list_btn_1_main_main_default
style_video_list_btn_1_main_main_default = lv.style_t()
style_video_list_btn_1_main_main_default.init()
style_video_list_btn_1_main_main_default.set_radius(0)
style_video_list_btn_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_video_list_btn_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_video_list_btn_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_btn_1_main_main_default.set_bg_opa(0)
style_video_list_btn_1_main_main_default.set_shadow_color(lv.color_make(0x21,0x95,0xf6))
style_video_list_btn_1_main_main_default.set_shadow_opa(0)
style_video_list_btn_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_video_list_btn_1_main_main_default.set_border_width(0)
style_video_list_btn_1_main_main_default.set_border_opa(255)

# add style for video_list_btn_1
video_list_btn_1.add_style(style_video_list_btn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_img_1 = lv.img(video_list_cont_1)
video_list_img_1.set_pos(20,16)
video_list_img_1.set_size(36,24)
video_list_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png','rb') as f:
        video_list_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-409622789.png')
    sys.exit()

video_list_img_1_img = lv.img_dsc_t({
  'data_size': len(video_list_img_1_img_data),
  'header': {'always_zero': 0, 'w': 36, 'h': 24, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': video_list_img_1_img_data
})

video_list_img_1.set_src(video_list_img_1_img)
video_list_img_1.set_pivot(0,0)
video_list_img_1.set_angle(0)
# create style style_video_list_img_1_main_main_default
style_video_list_img_1_main_main_default = lv.style_t()
style_video_list_img_1_main_main_default.init()
style_video_list_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_video_list_img_1_main_main_default.set_img_recolor_opa(0)
style_video_list_img_1_main_main_default.set_img_opa(255)

# add style for video_list_img_1
video_list_img_1.add_style(style_video_list_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_label_2 = lv.label(video_list_cont_1)
video_list_label_2.set_pos(90,11)
video_list_label_2.set_size(300,32)
video_list_label_2.set_text("视频列表")
video_list_label_2.set_long_mode(lv.label.LONG.WRAP)
video_list_label_2.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_video_list_label_2_main_main_default
style_video_list_label_2_main_main_default = lv.style_t()
style_video_list_label_2_main_main_default.init()
style_video_list_label_2_main_main_default.set_radius(0)
style_video_list_label_2_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_label_2_main_main_default.set_bg_opa(0)
style_video_list_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_list_label_2_main_main_default.set_text_font(lv.font_simsun_32)
except AttributeError:
    try:
        style_video_list_label_2_main_main_default.set_text_font(lv.font_montserrat_32)
    except AttributeError:
        style_video_list_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_list_label_2_main_main_default.set_text_letter_space(2)
style_video_list_label_2_main_main_default.set_pad_left(0)
style_video_list_label_2_main_main_default.set_pad_right(0)
style_video_list_label_2_main_main_default.set_pad_top(0)
style_video_list_label_2_main_main_default.set_pad_bottom(0)

# add style for video_list_label_2
video_list_label_2.add_style(style_video_list_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_label_4 = lv.label(video_list_cont_1)
video_list_label_4.set_pos(131,80)
video_list_label_4.set_size(260,24)
video_list_label_4.set_text("Pawn.MP4")
video_list_label_4.set_long_mode(lv.label.LONG.WRAP)
video_list_label_4.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_list_label_4_main_main_default
style_video_list_label_4_main_main_default = lv.style_t()
style_video_list_label_4_main_main_default.init()
style_video_list_label_4_main_main_default.set_radius(0)
style_video_list_label_4_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_label_4_main_main_default.set_bg_opa(0)
style_video_list_label_4_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_list_label_4_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_list_label_4_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_list_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_list_label_4_main_main_default.set_text_letter_space(0)
style_video_list_label_4_main_main_default.set_pad_left(0)
style_video_list_label_4_main_main_default.set_pad_right(0)
style_video_list_label_4_main_main_default.set_pad_top(0)
style_video_list_label_4_main_main_default.set_pad_bottom(0)

# add style for video_list_label_4
video_list_label_4.add_style(style_video_list_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_label_10 = lv.label(video_list_cont_1)
video_list_label_10.set_pos(131,312)
video_list_label_10.set_size(200,24)
video_list_label_10.set_text("Pawn.MP4")
video_list_label_10.set_long_mode(lv.label.LONG.WRAP)
video_list_label_10.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_list_label_10_main_main_default
style_video_list_label_10_main_main_default = lv.style_t()
style_video_list_label_10_main_main_default.init()
style_video_list_label_10_main_main_default.set_radius(0)
style_video_list_label_10_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_10_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_10_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_label_10_main_main_default.set_bg_opa(0)
style_video_list_label_10_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_list_label_10_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_list_label_10_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_list_label_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_list_label_10_main_main_default.set_text_letter_space(0)
style_video_list_label_10_main_main_default.set_pad_left(0)
style_video_list_label_10_main_main_default.set_pad_right(0)
style_video_list_label_10_main_main_default.set_pad_top(0)
style_video_list_label_10_main_main_default.set_pad_bottom(0)

# add style for video_list_label_10
video_list_label_10.add_style(style_video_list_label_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_label_11 = lv.label(video_list_cont_1)
video_list_label_11.set_pos(131,348)
video_list_label_11.set_size(253,24)
video_list_label_11.set_text("2022/01/23 12:12")
video_list_label_11.set_long_mode(lv.label.LONG.WRAP)
video_list_label_11.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_list_label_11_main_main_default
style_video_list_label_11_main_main_default = lv.style_t()
style_video_list_label_11_main_main_default.init()
style_video_list_label_11_main_main_default.set_radius(0)
style_video_list_label_11_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_11_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_11_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_label_11_main_main_default.set_bg_opa(0)
style_video_list_label_11_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_list_label_11_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_list_label_11_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_list_label_11_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_list_label_11_main_main_default.set_text_letter_space(0)
style_video_list_label_11_main_main_default.set_pad_left(0)
style_video_list_label_11_main_main_default.set_pad_right(0)
style_video_list_label_11_main_main_default.set_pad_top(0)
style_video_list_label_11_main_main_default.set_pad_bottom(0)

# add style for video_list_label_11
video_list_label_11.add_style(style_video_list_label_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_label_12 = lv.label(video_list_cont_1)
video_list_label_12.set_pos(131,384)
video_list_label_12.set_size(300,24)
video_list_label_12.set_text("打印日期:2022/03/07 10:33")
video_list_label_12.set_long_mode(lv.label.LONG.WRAP)
video_list_label_12.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_list_label_12_main_main_default
style_video_list_label_12_main_main_default = lv.style_t()
style_video_list_label_12_main_main_default.init()
style_video_list_label_12_main_main_default.set_radius(0)
style_video_list_label_12_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_12_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_12_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_label_12_main_main_default.set_bg_opa(0)
style_video_list_label_12_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_list_label_12_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_list_label_12_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_list_label_12_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_list_label_12_main_main_default.set_text_letter_space(0)
style_video_list_label_12_main_main_default.set_pad_left(0)
style_video_list_label_12_main_main_default.set_pad_right(0)
style_video_list_label_12_main_main_default.set_pad_top(0)
style_video_list_label_12_main_main_default.set_pad_bottom(0)

# add style for video_list_label_12
video_list_label_12.add_style(style_video_list_label_12_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_label_13 = lv.label(video_list_cont_1)
video_list_label_13.set_pos(131,428)
video_list_label_13.set_size(200,24)
video_list_label_13.set_text("测试文件.gcode")
video_list_label_13.set_long_mode(lv.label.LONG.WRAP)
video_list_label_13.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_list_label_13_main_main_default
style_video_list_label_13_main_main_default = lv.style_t()
style_video_list_label_13_main_main_default.init()
style_video_list_label_13_main_main_default.set_radius(0)
style_video_list_label_13_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_13_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_13_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_label_13_main_main_default.set_bg_opa(0)
style_video_list_label_13_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_list_label_13_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_list_label_13_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_list_label_13_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_list_label_13_main_main_default.set_text_letter_space(0)
style_video_list_label_13_main_main_default.set_pad_left(0)
style_video_list_label_13_main_main_default.set_pad_right(0)
style_video_list_label_13_main_main_default.set_pad_top(0)
style_video_list_label_13_main_main_default.set_pad_bottom(0)

# add style for video_list_label_13
video_list_label_13.add_style(style_video_list_label_13_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_label_14 = lv.label(video_list_cont_1)
video_list_label_14.set_pos(131,464)
video_list_label_14.set_size(261,24)
video_list_label_14.set_text("2022/01/23 12:12")
video_list_label_14.set_long_mode(lv.label.LONG.WRAP)
video_list_label_14.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_list_label_14_main_main_default
style_video_list_label_14_main_main_default = lv.style_t()
style_video_list_label_14_main_main_default.init()
style_video_list_label_14_main_main_default.set_radius(0)
style_video_list_label_14_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_14_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_14_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_label_14_main_main_default.set_bg_opa(0)
style_video_list_label_14_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_list_label_14_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_list_label_14_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_list_label_14_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_list_label_14_main_main_default.set_text_letter_space(0)
style_video_list_label_14_main_main_default.set_pad_left(0)
style_video_list_label_14_main_main_default.set_pad_right(0)
style_video_list_label_14_main_main_default.set_pad_top(0)
style_video_list_label_14_main_main_default.set_pad_bottom(0)

# add style for video_list_label_14
video_list_label_14.add_style(style_video_list_label_14_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_label_15 = lv.label(video_list_cont_1)
video_list_label_15.set_pos(131,496)
video_list_label_15.set_size(300,24)
video_list_label_15.set_text("打印日期:2022/03/07 10:33")
video_list_label_15.set_long_mode(lv.label.LONG.WRAP)
video_list_label_15.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_list_label_15_main_main_default
style_video_list_label_15_main_main_default = lv.style_t()
style_video_list_label_15_main_main_default.init()
style_video_list_label_15_main_main_default.set_radius(0)
style_video_list_label_15_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_15_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_15_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_label_15_main_main_default.set_bg_opa(0)
style_video_list_label_15_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_list_label_15_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_list_label_15_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_list_label_15_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_list_label_15_main_main_default.set_text_letter_space(0)
style_video_list_label_15_main_main_default.set_pad_left(0)
style_video_list_label_15_main_main_default.set_pad_right(0)
style_video_list_label_15_main_main_default.set_pad_top(0)
style_video_list_label_15_main_main_default.set_pad_bottom(0)

# add style for video_list_label_15
video_list_label_15.add_style(style_video_list_label_15_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_label_18 = lv.label(video_list_cont_1)
video_list_label_18.set_pos(131,612)
video_list_label_18.set_size(300,24)
video_list_label_18.set_text("打印日期:2022/03/07 10:33")
video_list_label_18.set_long_mode(lv.label.LONG.WRAP)
video_list_label_18.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_list_label_18_main_main_default
style_video_list_label_18_main_main_default = lv.style_t()
style_video_list_label_18_main_main_default.init()
style_video_list_label_18_main_main_default.set_radius(0)
style_video_list_label_18_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_18_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_18_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_label_18_main_main_default.set_bg_opa(0)
style_video_list_label_18_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_list_label_18_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_list_label_18_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_list_label_18_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_list_label_18_main_main_default.set_text_letter_space(0)
style_video_list_label_18_main_main_default.set_pad_left(0)
style_video_list_label_18_main_main_default.set_pad_right(0)
style_video_list_label_18_main_main_default.set_pad_top(0)
style_video_list_label_18_main_main_default.set_pad_bottom(0)

# add style for video_list_label_18
video_list_label_18.add_style(style_video_list_label_18_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_label_16 = lv.label(video_list_cont_1)
video_list_label_16.set_pos(131,544)
video_list_label_16.set_size(282,24)
video_list_label_16.set_text("测试文件.gcode")
video_list_label_16.set_long_mode(lv.label.LONG.WRAP)
video_list_label_16.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_list_label_16_main_main_default
style_video_list_label_16_main_main_default = lv.style_t()
style_video_list_label_16_main_main_default.init()
style_video_list_label_16_main_main_default.set_radius(0)
style_video_list_label_16_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_16_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_16_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_label_16_main_main_default.set_bg_opa(0)
style_video_list_label_16_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_list_label_16_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_list_label_16_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_list_label_16_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_list_label_16_main_main_default.set_text_letter_space(0)
style_video_list_label_16_main_main_default.set_pad_left(0)
style_video_list_label_16_main_main_default.set_pad_right(0)
style_video_list_label_16_main_main_default.set_pad_top(0)
style_video_list_label_16_main_main_default.set_pad_bottom(0)

# add style for video_list_label_16
video_list_label_16.add_style(style_video_list_label_16_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_label_17 = lv.label(video_list_cont_1)
video_list_label_17.set_pos(131,576)
video_list_label_17.set_size(282,24)
video_list_label_17.set_text("2022/01/23 12:12")
video_list_label_17.set_long_mode(lv.label.LONG.WRAP)
video_list_label_17.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_list_label_17_main_main_default
style_video_list_label_17_main_main_default = lv.style_t()
style_video_list_label_17_main_main_default.init()
style_video_list_label_17_main_main_default.set_radius(0)
style_video_list_label_17_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_17_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_17_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_label_17_main_main_default.set_bg_opa(0)
style_video_list_label_17_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_list_label_17_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_list_label_17_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_list_label_17_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_list_label_17_main_main_default.set_text_letter_space(0)
style_video_list_label_17_main_main_default.set_pad_left(0)
style_video_list_label_17_main_main_default.set_pad_right(0)
style_video_list_label_17_main_main_default.set_pad_top(0)
style_video_list_label_17_main_main_default.set_pad_bottom(0)

# add style for video_list_label_17
video_list_label_17.add_style(style_video_list_label_17_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_label_5 = lv.label(video_list_cont_1)
video_list_label_5.set_pos(131,116)
video_list_label_5.set_size(260,24)
video_list_label_5.set_text("实际打印时间:19h22m")
video_list_label_5.set_long_mode(lv.label.LONG.WRAP)
video_list_label_5.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_list_label_5_main_main_default
style_video_list_label_5_main_main_default = lv.style_t()
style_video_list_label_5_main_main_default.init()
style_video_list_label_5_main_main_default.set_radius(0)
style_video_list_label_5_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_label_5_main_main_default.set_bg_opa(0)
style_video_list_label_5_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_list_label_5_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_list_label_5_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_list_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_list_label_5_main_main_default.set_text_letter_space(0)
style_video_list_label_5_main_main_default.set_pad_left(0)
style_video_list_label_5_main_main_default.set_pad_right(0)
style_video_list_label_5_main_main_default.set_pad_top(0)
style_video_list_label_5_main_main_default.set_pad_bottom(0)

# add style for video_list_label_5
video_list_label_5.add_style(style_video_list_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_label_6 = lv.label(video_list_cont_1)
video_list_label_6.set_pos(130,152)
video_list_label_6.set_size(300,24)
video_list_label_6.set_text("打印日期:2022/03/07 10:33")
video_list_label_6.set_long_mode(lv.label.LONG.WRAP)
video_list_label_6.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_list_label_6_main_main_default
style_video_list_label_6_main_main_default = lv.style_t()
style_video_list_label_6_main_main_default.init()
style_video_list_label_6_main_main_default.set_radius(0)
style_video_list_label_6_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_6_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_6_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_label_6_main_main_default.set_bg_opa(0)
style_video_list_label_6_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_list_label_6_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_list_label_6_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_list_label_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_list_label_6_main_main_default.set_text_letter_space(0)
style_video_list_label_6_main_main_default.set_pad_left(0)
style_video_list_label_6_main_main_default.set_pad_right(0)
style_video_list_label_6_main_main_default.set_pad_top(0)
style_video_list_label_6_main_main_default.set_pad_bottom(0)

# add style for video_list_label_6
video_list_label_6.add_style(style_video_list_label_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_label_7 = lv.label(video_list_cont_1)
video_list_label_7.set_pos(131,196)
video_list_label_7.set_size(205,24)
video_list_label_7.set_text("Pawn.MP4")
video_list_label_7.set_long_mode(lv.label.LONG.WRAP)
video_list_label_7.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_list_label_7_main_main_default
style_video_list_label_7_main_main_default = lv.style_t()
style_video_list_label_7_main_main_default.init()
style_video_list_label_7_main_main_default.set_radius(0)
style_video_list_label_7_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_7_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_7_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_label_7_main_main_default.set_bg_opa(0)
style_video_list_label_7_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_list_label_7_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_list_label_7_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_list_label_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_list_label_7_main_main_default.set_text_letter_space(0)
style_video_list_label_7_main_main_default.set_pad_left(0)
style_video_list_label_7_main_main_default.set_pad_right(0)
style_video_list_label_7_main_main_default.set_pad_top(0)
style_video_list_label_7_main_main_default.set_pad_bottom(0)

# add style for video_list_label_7
video_list_label_7.add_style(style_video_list_label_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_label_8 = lv.label(video_list_cont_1)
video_list_label_8.set_pos(131,232)
video_list_label_8.set_size(260,24)
video_list_label_8.set_text("实际打印时间:19h22m")
video_list_label_8.set_long_mode(lv.label.LONG.WRAP)
video_list_label_8.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_list_label_8_main_main_default
style_video_list_label_8_main_main_default = lv.style_t()
style_video_list_label_8_main_main_default.init()
style_video_list_label_8_main_main_default.set_radius(0)
style_video_list_label_8_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_8_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_8_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_label_8_main_main_default.set_bg_opa(0)
style_video_list_label_8_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_list_label_8_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_list_label_8_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_list_label_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_list_label_8_main_main_default.set_text_letter_space(0)
style_video_list_label_8_main_main_default.set_pad_left(0)
style_video_list_label_8_main_main_default.set_pad_right(0)
style_video_list_label_8_main_main_default.set_pad_top(0)
style_video_list_label_8_main_main_default.set_pad_bottom(0)

# add style for video_list_label_8
video_list_label_8.add_style(style_video_list_label_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

video_list_label_9 = lv.label(video_list_cont_1)
video_list_label_9.set_pos(131,268)
video_list_label_9.set_size(300,24)
video_list_label_9.set_text("打印日期:2022/03/07 10:33")
video_list_label_9.set_long_mode(lv.label.LONG.WRAP)
video_list_label_9.set_style_text_align(lv.TEXT_ALIGN.LEFT, 0)
# create style style_video_list_label_9_main_main_default
style_video_list_label_9_main_main_default = lv.style_t()
style_video_list_label_9_main_main_default.init()
style_video_list_label_9_main_main_default.set_radius(0)
style_video_list_label_9_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_9_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_video_list_label_9_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_label_9_main_main_default.set_bg_opa(0)
style_video_list_label_9_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_video_list_label_9_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_video_list_label_9_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_video_list_label_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_video_list_label_9_main_main_default.set_text_letter_space(0)
style_video_list_label_9_main_main_default.set_pad_left(0)
style_video_list_label_9_main_main_default.set_pad_right(0)
style_video_list_label_9_main_main_default.set_pad_top(0)
style_video_list_label_9_main_main_default.set_pad_bottom(0)

# add style for video_list_label_9
video_list_label_9.add_style(style_video_list_label_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_video_list_cont_1_main_main_default
style_video_list_cont_1_main_main_default = lv.style_t()
style_video_list_cont_1_main_main_default.init()
style_video_list_cont_1_main_main_default.set_radius(0)
style_video_list_cont_1_main_main_default.set_bg_color(lv.color_make(0x23,0x24,0x26))
style_video_list_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x23,0x24,0x26))
style_video_list_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_video_list_cont_1_main_main_default.set_bg_opa(255)
style_video_list_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_video_list_cont_1_main_main_default.set_border_width(0)
style_video_list_cont_1_main_main_default.set_border_opa(255)
style_video_list_cont_1_main_main_default.set_pad_left(0)
style_video_list_cont_1_main_main_default.set_pad_right(0)
style_video_list_cont_1_main_main_default.set_pad_top(0)
style_video_list_cont_1_main_main_default.set_pad_bottom(0)

# add style for video_list_cont_1
video_list_cont_1.add_style(style_video_list_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

FAQ = lv.obj()
# create style style_faq_main_main_default
style_faq_main_main_default = lv.style_t()
style_faq_main_main_default.init()
style_faq_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_faq_main_main_default.set_bg_opa(0)

# add style for FAQ
FAQ.add_style(style_faq_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

FAQ_tabview_1 = lv.tabview(FAQ, lv.DIR.TOP, 50)
FAQ_tabview_1_tab_btns = FAQ_tabview_1.get_tab_btns()
# create style style_faq_tabview_1_extra_btnm_main_default
style_faq_tabview_1_extra_btnm_main_default = lv.style_t()
style_faq_tabview_1_extra_btnm_main_default.init()
style_faq_tabview_1_extra_btnm_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_faq_tabview_1_extra_btnm_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_faq_tabview_1_extra_btnm_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_faq_tabview_1_extra_btnm_main_default.set_bg_opa(255)
style_faq_tabview_1_extra_btnm_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_faq_tabview_1_extra_btnm_main_default.set_border_width(0)
style_faq_tabview_1_extra_btnm_main_default.set_border_opa(100)
style_faq_tabview_1_extra_btnm_main_default.set_pad_left(0)
style_faq_tabview_1_extra_btnm_main_default.set_pad_right(0)
style_faq_tabview_1_extra_btnm_main_default.set_pad_top(0)
style_faq_tabview_1_extra_btnm_main_default.set_pad_bottom(0)

# add style for FAQ_tabview_1_tab_btns
FAQ_tabview_1_tab_btns.add_style(style_faq_tabview_1_extra_btnm_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_faq_tabview_1_extra_btnm_items_default
style_faq_tabview_1_extra_btnm_items_default = lv.style_t()
style_faq_tabview_1_extra_btnm_items_default.init()
style_faq_tabview_1_extra_btnm_items_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_faq_tabview_1_extra_btnm_items_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_faq_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_faq_tabview_1_extra_btnm_items_default.set_text_font(lv.font_montserrat_16)

# add style for FAQ_tabview_1_tab_btns
FAQ_tabview_1_tab_btns.add_style(style_faq_tabview_1_extra_btnm_items_default, lv.PART.ITEMS|lv.STATE.DEFAULT)

# create style style_faq_tabview_1_extra_btnm_items_checked
style_faq_tabview_1_extra_btnm_items_checked = lv.style_t()
style_faq_tabview_1_extra_btnm_items_checked.init()
style_faq_tabview_1_extra_btnm_items_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_faq_tabview_1_extra_btnm_items_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_faq_tabview_1_extra_btnm_items_checked.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_faq_tabview_1_extra_btnm_items_checked.set_bg_opa(60)
style_faq_tabview_1_extra_btnm_items_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_faq_tabview_1_extra_btnm_items_checked.set_border_width(4)
style_faq_tabview_1_extra_btnm_items_checked.set_border_opa(255)
style_faq_tabview_1_extra_btnm_items_checked.set_border_side(lv.BORDER_SIDE.BOTTOM)
style_faq_tabview_1_extra_btnm_items_checked.set_text_color(lv.color_make(0x21,0x95,0xf6))
try:
    style_faq_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_faq_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_faq_tabview_1_extra_btnm_items_checked.set_text_font(lv.font_montserrat_16)

# add style for FAQ_tabview_1_tab_btns
FAQ_tabview_1_tab_btns.add_style(style_faq_tabview_1_extra_btnm_items_checked, lv.PART.ITEMS|lv.STATE.CHECKED)

FAQ_tabview_1_title1 = FAQ_tabview_1.add_tab("title1")
FAQ_tabview_1_title2 = FAQ_tabview_1.add_tab("title2")
FAQ_tabview_1_title3 = FAQ_tabview_1.add_tab("title3")
FAQ_tabview_1_Title = FAQ_tabview_1.add_tab("Title")
FAQ_tabview_1.set_pos(0,0)
FAQ_tabview_1.set_size(480,720)
# create style style_faq_tabview_1_main_main_default
style_faq_tabview_1_main_main_default = lv.style_t()
style_faq_tabview_1_main_main_default.init()
style_faq_tabview_1_main_main_default.set_bg_color(lv.color_make(0xea,0xef,0xf3))
style_faq_tabview_1_main_main_default.set_bg_grad_color(lv.color_make(0xea,0xef,0xf3))
style_faq_tabview_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_faq_tabview_1_main_main_default.set_bg_opa(255)
style_faq_tabview_1_main_main_default.set_border_color(lv.color_make(0xc0,0xc0,0xc0))
style_faq_tabview_1_main_main_default.set_border_width(0)
style_faq_tabview_1_main_main_default.set_border_opa(100)
style_faq_tabview_1_main_main_default.set_text_color(lv.color_make(0x4d,0x4d,0x4d))
try:
    style_faq_tabview_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_faq_tabview_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_faq_tabview_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_faq_tabview_1_main_main_default.set_text_letter_space(2)
style_faq_tabview_1_main_main_default.set_text_line_space(16)

# add style for FAQ_tabview_1
FAQ_tabview_1.add_style(style_faq_tabview_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

FAQ_cont_1 = lv.obj(FAQ)
FAQ_cont_1.set_pos(0,0)
FAQ_cont_1.set_size(480,800)
FAQ_label_2 = lv.label(FAQ_cont_1)
FAQ_label_2.set_pos(9,52)
FAQ_label_2.set_size(460,648)
# create style style_faq_label_2_main_main_default
style_faq_label_2_main_main_default = lv.style_t()
style_faq_label_2_main_main_default.init()
style_faq_label_2_main_main_default.set_radius(0)
style_faq_label_2_main_main_default.set_bg_color(lv.color_make(0x2d,0x2e,0x31))
style_faq_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x2d,0x2e,0x31))
style_faq_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_faq_label_2_main_main_default.set_bg_opa(255)
style_faq_label_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_faq_label_2_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_faq_label_2_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_faq_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_faq_label_2_main_main_default.set_text_letter_space(0)
style_faq_label_2_main_main_default.set_pad_left(0)
style_faq_label_2_main_main_default.set_pad_right(0)
style_faq_label_2_main_main_default.set_pad_top(0)
style_faq_label_2_main_main_default.set_pad_bottom(0)

# add style for FAQ_label_2
FAQ_label_2.add_style(style_faq_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

FAQ_img_6 = lv.img(FAQ_cont_1)
FAQ_img_6.set_pos(160,250)
FAQ_img_6.set_size(160,160)
# create style style_faq_img_6_main_main_default
style_faq_img_6_main_main_default = lv.style_t()
style_faq_img_6_main_main_default.init()
style_faq_img_6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_faq_img_6_main_main_default.set_img_recolor_opa(0)
style_faq_img_6_main_main_default.set_img_opa(255)

# add style for FAQ_img_6
FAQ_img_6.add_style(style_faq_img_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

FAQ_label_3 = lv.label(FAQ_cont_1)
FAQ_label_3.set_pos(86,416)
FAQ_label_3.set_size(300,32)
FAQ_label_3.set_text("扫码进行意见反馈")
FAQ_label_3.set_long_mode(lv.label.LONG.WRAP)
FAQ_label_3.set_style_text_align(lv.TEXT_ALIGN.CENTER, 0)
# create style style_faq_label_3_main_main_default
style_faq_label_3_main_main_default = lv.style_t()
style_faq_label_3_main_main_default.init()
style_faq_label_3_main_main_default.set_radius(0)
style_faq_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_faq_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_faq_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_faq_label_3_main_main_default.set_bg_opa(0)
style_faq_label_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_faq_label_3_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_faq_label_3_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_faq_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_faq_label_3_main_main_default.set_text_letter_space(2)
style_faq_label_3_main_main_default.set_pad_left(0)
style_faq_label_3_main_main_default.set_pad_right(0)
style_faq_label_3_main_main_default.set_pad_top(0)
style_faq_label_3_main_main_default.set_pad_bottom(0)

# add style for FAQ_label_3
FAQ_label_3.add_style(style_faq_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

FAQ_label_1 = lv.label(FAQ_cont_1)
FAQ_label_1.set_pos(0,719)
FAQ_label_1.set_size(480,80)
# create style style_faq_label_1_main_main_default
style_faq_label_1_main_main_default = lv.style_t()
style_faq_label_1_main_main_default.init()
style_faq_label_1_main_main_default.set_radius(0)
style_faq_label_1_main_main_default.set_bg_color(lv.color_make(0x0e,0x0e,0x0e))
style_faq_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x0e,0x0e,0x0e))
style_faq_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_faq_label_1_main_main_default.set_bg_opa(255)
style_faq_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_faq_label_1_main_main_default.set_text_font(lv.font_simsun_24)
except AttributeError:
    try:
        style_faq_label_1_main_main_default.set_text_font(lv.font_montserrat_24)
    except AttributeError:
        style_faq_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_faq_label_1_main_main_default.set_text_letter_space(0)
style_faq_label_1_main_main_default.set_pad_left(0)
style_faq_label_1_main_main_default.set_pad_right(0)
style_faq_label_1_main_main_default.set_pad_top(0)
style_faq_label_1_main_main_default.set_pad_bottom(0)

# add style for FAQ_label_1
FAQ_label_1.add_style(style_faq_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

FAQ_img_1 = lv.img(FAQ_cont_1)
FAQ_img_1.set_pos(30,742)
FAQ_img_1.set_size(48,48)
FAQ_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png','rb') as f:
        FAQ_img_1_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-150469354.png')
    sys.exit()

FAQ_img_1_img = lv.img_dsc_t({
  'data_size': len(FAQ_img_1_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': FAQ_img_1_img_data
})

FAQ_img_1.set_src(FAQ_img_1_img)
FAQ_img_1.set_pivot(0,0)
FAQ_img_1.set_angle(0)
# create style style_faq_img_1_main_main_default
style_faq_img_1_main_main_default = lv.style_t()
style_faq_img_1_main_main_default.init()
style_faq_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_faq_img_1_main_main_default.set_img_recolor_opa(0)
style_faq_img_1_main_main_default.set_img_opa(255)

# add style for FAQ_img_1
FAQ_img_1.add_style(style_faq_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

FAQ_img_2 = lv.img(FAQ_cont_1)
FAQ_img_2.set_pos(128,742)
FAQ_img_2.set_size(48,48)
FAQ_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png','rb') as f:
        FAQ_img_2_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-1935624352.png')
    sys.exit()

FAQ_img_2_img = lv.img_dsc_t({
  'data_size': len(FAQ_img_2_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': FAQ_img_2_img_data
})

FAQ_img_2.set_src(FAQ_img_2_img)
FAQ_img_2.set_pivot(0,0)
FAQ_img_2.set_angle(0)
# create style style_faq_img_2_main_main_default
style_faq_img_2_main_main_default = lv.style_t()
style_faq_img_2_main_main_default.init()
style_faq_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_faq_img_2_main_main_default.set_img_recolor_opa(0)
style_faq_img_2_main_main_default.set_img_opa(255)

# add style for FAQ_img_2
FAQ_img_2.add_style(style_faq_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

FAQ_img_3 = lv.img(FAQ_cont_1)
FAQ_img_3.set_pos(224,742)
FAQ_img_3.set_size(48,48)
FAQ_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png','rb') as f:
        FAQ_img_3_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp-78292720.png')
    sys.exit()

FAQ_img_3_img = lv.img_dsc_t({
  'data_size': len(FAQ_img_3_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': FAQ_img_3_img_data
})

FAQ_img_3.set_src(FAQ_img_3_img)
FAQ_img_3.set_pivot(0,0)
FAQ_img_3.set_angle(0)
# create style style_faq_img_3_main_main_default
style_faq_img_3_main_main_default = lv.style_t()
style_faq_img_3_main_main_default.init()
style_faq_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_faq_img_3_main_main_default.set_img_recolor_opa(0)
style_faq_img_3_main_main_default.set_img_opa(255)

# add style for FAQ_img_3
FAQ_img_3.add_style(style_faq_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

FAQ_img_4 = lv.img(FAQ_cont_1)
FAQ_img_4.set_pos(318,742)
FAQ_img_4.set_size(48,48)
FAQ_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png','rb') as f:
        FAQ_img_4_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1163456951.png')
    sys.exit()

FAQ_img_4_img = lv.img_dsc_t({
  'data_size': len(FAQ_img_4_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': FAQ_img_4_img_data
})

FAQ_img_4.set_src(FAQ_img_4_img)
FAQ_img_4.set_pivot(0,0)
FAQ_img_4.set_angle(0)
# create style style_faq_img_4_main_main_default
style_faq_img_4_main_main_default = lv.style_t()
style_faq_img_4_main_main_default.init()
style_faq_img_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_faq_img_4_main_main_default.set_img_recolor_opa(0)
style_faq_img_4_main_main_default.set_img_opa(255)

# add style for FAQ_img_4
FAQ_img_4.add_style(style_faq_img_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

FAQ_img_5 = lv.img(FAQ_cont_1)
FAQ_img_5.set_pos(414,742)
FAQ_img_5.set_size(48,48)
FAQ_img_5.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png','rb') as f:
        FAQ_img_5_img_data = f.read()
except:
    print('Could not open F:\\lisiqin_workspace\\4408\\guiguider_workspace\\CR10_H1_PRO\\CR_10_H1_800x800\\generated\\mPythonImages\\mp1032271055.png')
    sys.exit()

FAQ_img_5_img = lv.img_dsc_t({
  'data_size': len(FAQ_img_5_img_data),
  'header': {'always_zero': 0, 'w': 48, 'h': 48, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': FAQ_img_5_img_data
})

FAQ_img_5.set_src(FAQ_img_5_img)
FAQ_img_5.set_pivot(0,0)
FAQ_img_5.set_angle(0)
# create style style_faq_img_5_main_main_default
style_faq_img_5_main_main_default = lv.style_t()
style_faq_img_5_main_main_default.init()
style_faq_img_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_faq_img_5_main_main_default.set_img_recolor_opa(0)
style_faq_img_5_main_main_default.set_img_opa(255)

# add style for FAQ_img_5
FAQ_img_5.add_style(style_faq_img_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_faq_cont_1_main_main_default
style_faq_cont_1_main_main_default = lv.style_t()
style_faq_cont_1_main_main_default.init()
style_faq_cont_1_main_main_default.set_radius(0)
style_faq_cont_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_faq_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x00,0x00,0x00))
style_faq_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.VER)
style_faq_cont_1_main_main_default.set_bg_opa(255)
style_faq_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_faq_cont_1_main_main_default.set_border_width(0)
style_faq_cont_1_main_main_default.set_border_opa(255)
style_faq_cont_1_main_main_default.set_pad_left(0)
style_faq_cont_1_main_main_default.set_pad_right(0)
style_faq_cont_1_main_main_default.set_pad_top(0)
style_faq_cont_1_main_main_default.set_pad_bottom(0)

# add style for FAQ_cont_1
FAQ_cont_1.add_style(style_faq_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)






# content from custom.py

# Load the default screen
lv.scr_load(homepapage)

while SDL.check():
    time.sleep_ms(5)
