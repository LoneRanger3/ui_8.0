/*
 * @Description : Crlog重定义
 * @Author      : Yufeng Zhang
 * @Date: 2022-03-02 12:10:36
 * @LastEditTime: 2022-12-03 18:00:54
 */

#define ENABLE_USE_CRLOG     1 // 使能Crlog


#if ENABLE_USE_CRLOG
    #include "CrLog.h"
#else
    #include <string.h>
    #define CrLogD(xx, arg...)       printf(xx, ##arg); printf("\n")
    #define CrLogI(xx, arg...)       printf(xx, ##arg); printf("\n")
    #define CrLogW(xx, arg...)       printf(xx, ##arg); printf("\n")
    #define CrLogE(xx, arg...)       printf(xx, ##arg); printf("\n")
    #define CrLogOpen(a, b, c, d)
    #define CrLogRecreate()
#endif

