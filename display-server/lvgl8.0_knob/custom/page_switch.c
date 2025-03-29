/*
 * @Description: 
 * @Author: sunhui
 * @Date: 2023-06-12 03:45:17
 * @LastEditTime: 2023-10-17 23:08:10
 */
#include "lvgl.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "page_switch.h"
#include "CrlogDef.h"

//该页面切换框架以属性页为管理对象节点，每个属性页下包含不同的功能子页, 根据需求目前只支持包含属性页在内的3级页面的管理，超过三级页面需以自定义切换事件组加载页面对象
//目前主要管理5个属性页面： 主页面、控制页、打印文件页、设置页、服务帮助页




/**
 * 初始化页面管理器
 */
void init_page_manager(void)
{
    lv_obj_t *head = NULL;
    page_manager.head = NULL;
    page_manager.current_page = NULL;
   // page_manager.pre_page = NULL;
   // page_manager.pre_focus_obj = NULL;
    add_page(head, NULL, NULL);

    //
    pthread_mutex_init(&ScreenOffPopout.PopoutMutex, NULL);
    pthread_mutex_init(&MsgPopout.PopoutMutex, NULL);
    pthread_mutex_init(&ErrorPopout.PopoutMutex, NULL);
    pthread_mutex_init(&BtnDialogPopout.PopoutMutex, NULL);
}

/**
 * 添加页面到页面链表
 */
void add_page(lv_obj_t *page_obj, void (*change_group_objs)(uint8_t level), void (*load_page)(void))
{
    // 创建新的页面节点
    PageNode *new_node = (PageNode *)malloc(sizeof(PageNode));
    if (new_node == NULL) {
        CrLogI("Failed to allocate memory for new page node.\n");
        return;
    }

    if (page_obj == NULL)
        return;
  
    new_node->page_obj = page_obj;
    new_node->change_group_objs = change_group_objs;
    new_node->load_page = load_page;
    new_node->next = NULL;

    // 如果页面链表为空，则将新节点设置为链表头节点
    if (page_manager.head == NULL) {
        page_manager.head = new_node;
    } else {
        // 遍历页面链表，找到最后一个节点并将新节点添加到其后面
        PageNode *current = page_manager.head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}


/**
 * 初始化页面链表
 */
void init_pages(lv_obj_t *page_obj, void (*change_group_objs)(uint8_t level), void (*load_page)(void))
{
    // 添加页面到链表
    add_page(page_obj, change_group_objs, load_page);
}

/**
 * 根据页面对象查找对应的页面节点
 */
PageNode *find_page(lv_obj_t *page_obj)
{
    PageNode *current = page_manager.head;
    while (current != NULL) {
        if (current->page_obj == page_obj) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/**
 * @description: 弹框前聚焦对象记录, 目前涉及的有错误弹框以及熄屏后黑色面板弹框，以便消除弹框后可以聚焦到原对象
 * @return {*}
 */
void RecordObjBeforePopup(void)
{
    //printf("RecordObjBeforePopup\n");
    if(lv_group_get_obj_count(encoder_group))
    {
        if (page_manager.current_page)
        {
            //printf("page_manager.current_page\n");
            page_manager.current_page->focus_obj = lv_group_get_focused(encoder_group);
            //printf("page_manager.current_page->focus_obj:%p\n", page_manager.current_page->focus_obj);
            return;
        }
    }
    page_manager.current_page->focus_obj = NULL;
}

void ChangeFocusObjBeforePopup(lv_obj_t *focus_obj)
{
    page_manager.current_page->focus_obj = focus_obj;
}

/**
 * 切换页面
 */
void LoadPage(lv_obj_t *new_page_obj, uint8_t enter_group_level)
{
    PageNode *old_page_node = page_manager.current_page;
    // 检查目标页面对象是否为空
    if (new_page_obj == NULL) {
        CrLogI("Invalid page object.\n");
        return;
    }

    
    //检查当前页面是否已经是要切换的页面
    // if (page_manager.current_page == NULL) { //&& page_manager.current_page->page_obj == new_page_obj
    //     printf("Page is already active.\n");
    //     return;
    // }

    // 查找目标页面节点
    PageNode *new_page = find_page(new_page_obj);
    if (new_page == NULL) {
        CrLogI("Page not found.\n");
        return;
    }
    new_page->page_obj = new_page_obj;
    new_page->pre_nav_level = enter_group_level;
    new_page->pre_focus_obj= lv_group_get_focused(encoder_group);
    
    if (old_page_node != NULL) { //上电第一次页面重载 old_page_node 为NULL
        new_page->pre_page = old_page_node->page_obj; //上一页面对象
        // 执行页面重载操作
        // ...
    }
    
   
    // 执行页面切换操作
   // page_manager.page_obj = new_page_obj;
    if (old_page_node == NULL || old_page_node->page_obj != new_page_obj)  //进入新的页面
    {
        if (new_page->load_page)
            new_page->load_page();
        if (new_page->change_group_objs)
            new_page->change_group_objs(1); //新页面默认聚焦到当前页组的第一个对象
        page_manager.current_page = new_page; // 更新当前页面为新页面
    }
    else //未切换页面
    {
        
        new_page->change_group_objs(enter_group_level);
    }

}

/**
 * @description: 返回上一级页面，如果时isPopout是True，进入弹框也之前必须调用RecordObjBeforePopup接口，记录聚焦对象
 * @return {*}
 * @param {bool} isPopout
 */
void BackPrepage(bool isPopout)
{
    if (isPopout == false)
    {
          // 检查是否存在上一级页面
        if (page_manager.current_page->pre_page == NULL) {
            CrLogI("Invalid page object.");
            return;
        }
        
        // 查找目标页面节点
        PageNode *pre_page_node = find_page(page_manager.current_page->pre_page);
        if (pre_page_node == NULL) {
            CrLogI("Page not found.");
            return;
        }
        

        // 执行页面切换操作
        
        if (pre_page_node->page_obj != page_manager.current_page->page_obj)
        {
            pre_page_node->load_page();
            pre_page_node->change_group_objs(pre_page_node->pre_nav_level);
        }
        else //未切换页面
        {
            //pre_page_node->load_page();
            pre_page_node->change_group_objs(pre_page_node->pre_nav_level - 1); //同一属性页内最多3级，3级返回后进入2级事件组
            pre_page_node->pre_nav_level = pre_page_node->pre_nav_level - 1;
        }

        CrLogI("pre_page->pre_nav_level :%d", pre_page_node->pre_nav_level);
        
        // 恢复焦点对象
        if (pre_page_node->pre_focus_obj != NULL) {
            lv_group_focus_obj(page_manager.current_page->pre_focus_obj);
            //printf("page_manager.current_page->pre_focus_obj = %p\n", page_manager.current_page->pre_focus_obj);
        }
        // // 更新当前页面为新页面
        page_manager.current_page = pre_page_node;
        
    }
    else
    {
        if (page_manager.current_page)
        {
            page_manager.current_page->change_group_objs(page_manager.current_page->nav_level);
            // printf("page_manager.current_page :%p\n", page_manager.current_page); 
            // printf("page_manager.current_page->focus_obj :%p\n", page_manager.current_page->focus_obj);
            if(page_manager.current_page->focus_obj != NULL)
            {
                lv_group_focus_obj(page_manager.current_page->focus_obj);
            }
            // ErrorPopout.popout_focus_obj1 = NULL;
            // ErrorPopout.popout_focus_obj2 = NULL;
            // ErrorPopout.obj1_flag = false;
            // ErrorPopout.obj2_flag = false;
            // ErrorPopout.change_group_objs = NULL;
            CrLogI("BackPrepage");
        }  
    }
}

//初始化弹框管理者，每次创建弹框的时候调用
void InitPopoutManager(PopoutManager *Popout, lv_obj_t * Popout_obj, void (*change_group_objs_cb)(void))
{
    pthread_mutex_lock(&Popout->PopoutMutex);
    Popout->change_group_objs = change_group_objs_cb;
    Popout->popout_main_obj = Popout_obj;
    Popout->popout_focus_obj1 = NULL;
    Popout->popout_focus_obj2 = NULL;
    Popout->popout_focus_obj3 = NULL;
    Popout->obj1_flag = false;
    Popout->obj2_flag = false;
    Popout->obj3_flag = false;
    Popout->is_active = true;
    pthread_mutex_unlock(&Popout->PopoutMutex);
}

//反初始化弹框管理者，每次销毁弹框的时候调用
void DeinitPopoutManager(PopoutManager *Popout)
{
    pthread_mutex_lock(&Popout->PopoutMutex);
    Popout->change_group_objs = NULL;
    Popout->popout_main_obj = NULL;
    Popout->popout_focus_obj1 = NULL;
    Popout->popout_focus_obj2 = NULL;
    Popout->popout_focus_obj3 = NULL;
    Popout->obj1_flag = false;
    Popout->obj2_flag = false;
    Popout->obj3_flag = false;
    Popout->is_active = false;
    pthread_mutex_unlock(&Popout->PopoutMutex);
}

bool IsPopoutExist(PopoutManager *Popout)
{
    if (Popout->popout_main_obj && !lv_obj_has_flag(Popout->popout_main_obj, LV_OBJ_FLAG_HIDDEN))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//判断是否有弹框存在
bool IsThereAnyPopout()
{
    if (IsPopoutExist(&ScreenOffPopout))
    {
        return true;
    }
    if (IsPopoutExist(&MsgPopout))
    {
        return true;
    }
    if (IsPopoutExist(&ErrorPopout))
    {
        return true;
    }
    if (IsPopoutExist(&BtnDialogPopout))
    {
        return true;
    }
    return false;
}

void ManagePopoutFocus()
{
    if (IsPopoutExist(&ScreenOffPopout))
    {
        ScreenOffPopout.change_group_objs();
        return;
    }
    if (IsPopoutExist(&MsgPopout))
    {
        MsgPopout.change_group_objs();
        return;
    }
    if (IsPopoutExist(&ErrorPopout))
    {
        ErrorPopout.change_group_objs();
        return;
    }
    if (IsPopoutExist(&BtnDialogPopout))
    {
        //TODO:这里要优化线程同步问题
        if(BtnDialogPopout.change_group_objs)
            BtnDialogPopout.change_group_objs();
    }
}

//判断聚焦对象是不是在这个弹框上
bool IsFocusOnPopout(PopoutManager *Popout)
{
    lv_obj_t * focus_obj = lv_group_get_focused(encoder_group);
    if (focus_obj == NULL)
    {
        CrLogI("There is not focus obj!!!\n");
        CrLogI("messagebox_panel =  %p\n", Popout->popout_main_obj);
        return false;
    }
    if (focus_obj == Popout->popout_focus_obj1)
    {
        return true;
    }
    if (focus_obj == Popout->popout_focus_obj2)
    {
        return true;
    }
    if (focus_obj == Popout->popout_focus_obj3)
    {
        return true;
    }
    return false;
}

//判断是否聚焦异常：如果有高级别的弹框，聚集却不在上面
bool IsFocusAbnormal()
{
    if (IsPopoutExist(&ScreenOffPopout))
    {
        if (!IsFocusOnPopout(&ScreenOffPopout))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (IsPopoutExist(&MsgPopout))
    {
        if (!IsFocusOnPopout(&MsgPopout))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (IsPopoutExist(&ErrorPopout))
    {
        if (!IsFocusOnPopout(&ErrorPopout))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if (IsPopoutExist(&BtnDialogPopout))
    {
        if (!IsFocusOnPopout(&BtnDialogPopout))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
