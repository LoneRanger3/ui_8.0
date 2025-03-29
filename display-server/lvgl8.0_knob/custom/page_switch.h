/*
 * @Description: 
 * @Author: sunhui
 * @Date: 2023-06-13 03:06:40
 * @LastEditTime: 2023-08-29 23:29:13
 */
#ifndef PAGE_SWITCH_H
#define PAGE_SWITCH_H

#include "lvgl.h"
#include <pthread.h>

extern lv_indev_t * enc_indev;
extern lv_group_t * encoder_group;


/**
 * @description: 页面管理链表中记录的当前页变量对象只有在出现弹框时会使用到nav_level
 * @return {*}
 */
typedef struct PageNode_t {
    lv_obj_t *page_obj;      // 当前页面对象
    uint8_t  nav_level;      // 当前面导航等级,聚焦弹框
    lv_obj_t *focus_obj;     // 当前页面中焦点对象
    lv_obj_t *pre_page;      // 上一级页面对象
    uint8_t pre_nav_level;   // 上一页面导航等级
    lv_obj_t *pre_focus_obj; // 上一级页面中的焦点对象
    void (*change_group_objs)(uint8_t level);     // 创建页面回调函数
    void (*load_page)(void);     // 更新页面回调函数
    struct PageNode_t *next;          
} PageNode;

typedef struct PageManager_t {
    PageNode *head;       // 页面链表头指针
    PageNode *current_page;    // 记录当前页面节点
    bool objFreezzFlag; 
} PageManager;

PageManager page_manager;

typedef struct PopoutManager_t{
    lv_obj_t *popout_main_obj;        // 弹框对象
    lv_obj_t *popout_focus_obj1;      // 错误弹框对象
    lv_obj_t *popout_focus_obj2; 
    lv_obj_t *popout_focus_obj3; 
    bool obj1_flag;
    bool obj2_flag;
    bool obj3_flag;
    bool is_active;
    void (*change_group_objs)(void);
    pthread_mutex_t PopoutMutex;
} PopoutManager;

PopoutManager ScreenOffPopout;  //息屏弹框
PopoutManager MsgPopout;        //消息弹框，可以定时自动消失
PopoutManager ErrorPopout;      //错误弹框
PopoutManager BtnDialogPopout;  //按钮对话弹框

typedef enum {
    BtnDialogPopoutLevel = 0,
    ErrorPopoutLevel,
    MsgPopoutLevel,
    ScreenOffPopoutLevel,
}PopoutManagerLevel;




void init_page_manager(void);
void init_pages(lv_obj_t *page_obj, void (*change_group_objs)(uint8_t level), void (*load_page)(void));
void LoadPage(lv_obj_t *new_page_obj, uint8_t curgroup_level);
void BackPrepage(bool isPopout);
PageNode *find_page(lv_obj_t *page_obj);

void RecordObjBeforePopup(void);
void ChangeFocusObjBeforePopup(lv_obj_t *focus_obj);
void InitPopoutManager(PopoutManager *Popout, lv_obj_t * Popout_obj, void (*change_group_objs_cb)(void));
void DeinitPopoutManager(PopoutManager *Popout);
bool IsThereAnyPopout();
void ManagePopoutFocus();
bool IsFocusAbnormal();
// PopoutManager *FindMaxLevelPopoutManager();


#endif