/*
 * @Description : 二维码生成
 * @Author      : Yufeng Zhang
 * @Date: 2022-06-06 22:16:45
 * @LastEditTime: 2023-02-06 12:14:45
 */
#include "Base/AppMsgBase.h"
#include "CxyQrCode.h"

/**
 * @description: 
 * @return {*}
 */
CxyQrCode::CxyQrCode()
{
    m_fountGroundColor[0] = 0;
    m_fountGroundColor[1] = 0;
    m_fountGroundColor[2] = 0;
    m_fountGroundColor[3] = 255;

    m_backgGroundColor[0] = 255;
    m_backgGroundColor[1] = 255;
    m_backgGroundColor[2] = 255;
    m_backgGroundColor[3] = 255;
}

/**
 * @description: 
 * @return {*}
 */
CxyQrCode::~CxyQrCode() {}

/**
 * @description: 
 * @return {*}
 * @param {unsigned char} *intext
 * @param {int} length
 */
QRcode *CxyQrCode::QrEncode(const unsigned char *intext, int length)
{
	QRcode *code = NULL;
	if(MICRO_QR_CODE)
    {
		if(EIGHTBIT_QR_CODE) {
			code = QRcode_encodeDataMQR(length, intext, QR_CODE_VERSION, QR_ECLEVEL_L);
		} else {
			code = QRcode_encodeStringMQR((char *)intext, QR_CODE_VERSION, QR_ECLEVEL_L, QR_MODE_8, CASE_SENSITIVE);
		}
	}
    else
    {
		if(EIGHTBIT_QR_CODE) {
			code = QRcode_encodeData(length, intext, QR_CODE_VERSION, QR_ECLEVEL_L);
		} else {
			code = QRcode_encodeString((char *)intext, QR_CODE_VERSION, QR_ECLEVEL_L, QR_MODE_8, CASE_SENSITIVE);
		}
	}
	return code;
}

/**
 * @description: 
 * @return {*}
 * @param {QRcode} *qrcode
 * @param {char} *outfile
 */
int CxyQrCode::WritePNG(QRcode *qrcode, const char *outfile, int multiple)
{
    FILE *fp;
	png_structp png_ptr;
	png_infop info_ptr;
	png_colorp palette;
	png_byte alpha_values[2];

	int realwidth = (qrcode->width + IMAGE_MARGINS * 2) * multiple;
	unsigned char *row = (unsigned char *)malloc((realwidth + 7) / 8);
	if(row == NULL) {
		CrLogE("Failed to allocate memory.\n");
		return -1;
	}

    // 打开二维码保存文件
    fp = fopen(outfile, "wb");
    if(fp == NULL) {
        CrLogE("Failed to create file: %s\n", outfile);
        return -1;
    }

	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if(png_ptr == NULL) {
		CrLogE("Failed to initialize PNG writer.\n");
		return -1;
	}

	info_ptr = png_create_info_struct(png_ptr);
	if(info_ptr == NULL) {
		CrLogE("Failed to initialize PNG write.\n");
		return -1;
	}

	if(setjmp(png_jmpbuf(png_ptr))) {
		png_destroy_write_struct(&png_ptr, &info_ptr);
		CrLogE("Failed to write PNG image.\n");
		return -1;
	}

	palette = (png_colorp) malloc(sizeof(png_color) * 2);
	if(palette == NULL) {
		CrLogE("Failed to allocate memory.\n");
		return -1;
	}
    
	palette[0].red   = m_fountGroundColor[0];
	palette[0].green = m_fountGroundColor[1];
	palette[0].blue  = m_fountGroundColor[2];
	palette[1].red   = m_backgGroundColor[0];
	palette[1].green = m_backgGroundColor[1];
	palette[1].blue  = m_backgGroundColor[2];
	alpha_values[0] = m_fountGroundColor[3];
	alpha_values[1] = m_backgGroundColor[3];
	png_set_PLTE(png_ptr, info_ptr, palette, 2);
	png_set_tRNS(png_ptr, info_ptr, alpha_values, 2, NULL);

	png_init_io(png_ptr, fp);
	png_set_IHDR(   png_ptr, info_ptr,
			        realwidth, realwidth,
			        1,
			        PNG_COLOR_TYPE_PALETTE,
			        PNG_INTERLACE_NONE,
			        PNG_COMPRESSION_TYPE_DEFAULT,
			        PNG_FILTER_TYPE_DEFAULT);
	png_set_pHYs(   png_ptr, info_ptr,
			        NUMBER_PIXELS * INCHES_PER_METER,
			        NUMBER_PIXELS * INCHES_PER_METER,
			        PNG_RESOLUTION_METER);
	png_write_info(png_ptr, info_ptr);

	// 图像上边距
	memset(row, 0xff, (realwidth + 7) / 8);
	for(int y = 0; y < IMAGE_MARGINS * multiple; y++) {
		png_write_row(png_ptr, row);
	}

	// 二维码数据
	unsigned char *p = qrcode->data;
	for(int y = 0; y < qrcode->width; y++) {
		int bit = 7;
		memset(row, 0xff, (realwidth + 7) / 8);
		unsigned char *q = row;
		q += IMAGE_MARGINS * multiple / 8;
		bit = 7 - (IMAGE_MARGINS * multiple % 8);
		for(int x = 0; x < qrcode->width; x++) {
			for(int xx = 0; xx < multiple; xx++) {
				*q ^= (*p & 1) << bit;
				bit--;
				if(bit < 0) {
					q++;
					bit = 7;
				}
			}
			p++;
		}
		for(int yy = 0; yy < multiple; yy++) {
			png_write_row(png_ptr, row);
		}
	}

	// 图像下边距
	memset(row, 0xff, (realwidth + 7) / 8);
	for(int y = 0; y < IMAGE_MARGINS * multiple; y++) {
		png_write_row(png_ptr, row);
	}

	png_write_end(png_ptr, info_ptr);
	png_destroy_write_struct(&png_ptr, &info_ptr);

	fclose(fp);
	free(row);
	free(palette);

	return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {char} *fileName
 * @param {char} *value
 * @param {int} len
 */
int CxyQrCode::GenerateQrCode(char *fileName, char *value, int len)
{
    // 生成二维码数据
	QRcode *qrcode = QrEncode((const unsigned char*)value, len);
    if (qrcode == NULL) return -1;

    // 计算二维码放大倍数
    int multiple = IMAGE_WIDTH_PIXEL / (qrcode->width + IMAGE_MARGINS * 2);
    CrLogI("qrcode multiple = %d", multiple);

    // 生成PNG文件
    int res = WritePNG(qrcode, fileName, multiple > 0 ? multiple : 1);

    // 释放内存
    if (qrcode->data) {
        free(qrcode->data);
    }
    free(qrcode);
    
    if (res == 0) return 0;
    else return -1;
}

