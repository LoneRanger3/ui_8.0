/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2022-06-06 22:16:45
 * @LastEditTime: 2022-06-09 16:28:33
 */

#ifndef __CXY_QR_CODE_H__
#define __CXY_QR_CODE_H__

#include <png.h>
#include <qrencode.h>

#define INCHES_PER_METER        (100.0 / 2.54)
#define MICRO_QR_CODE           0  // 是否为微型编码
#define EIGHTBIT_QR_CODE        0  // 数据是否是字符串
#define QR_CODE_VERSION         0  // 符号的版本。如果为 0，则库选择最小值
#define CASE_SENSITIVE          1  // 区分大小写（1）或不区分（0）
#define NUMBER_PIXELS           72 // 像素点
#define IMAGE_MARGINS           1  // 图像边距
#define IMAGE_WIDTH_PIXEL       280 // 图像宽度像素点

class CxyQrCode
{
    public:
        CxyQrCode();
        ~CxyQrCode();
        int GenerateQrCode(char *fileName, char *value, int len);

    private:
        QRcode *QrEncode(const unsigned char *intext, int length);
        int WritePNG(QRcode *qrcode, const char *outfile, int multiple);

    private:
        unsigned int        m_fountGroundColor[4];
        unsigned int        m_backgGroundColor[4];
};

#endif