#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <malloc.h>

#include "global/list/list.h"
#include "Base/MasterMsgBase.h"
#include "gcode_point.h"

#define MAX_LEN 1024

typedef struct Point_attr{
    float x;
    float y;
    float z;
    float e;
    float f;
    float g;
    char key;
    double value;
    char type;
}PointAttr;

typedef struct list_attr{
    PointAttr data;
    struct list_head node;
}ListAttr;


float model_max_x = 0;
float model_max_y = 0;
float model_min_x = 0;
float model_min_y = 0;


int list_size(struct list_head* head)
{
    ListAttr *pos;
    int len = 0;

    if(!head)
        return -1;

    list_for_each_entry(pos, head, node) {
        len++;
    }

    return len;
}

ListAttr* list_new_node(void)
{
    ListAttr* list = (ListAttr*)malloc(sizeof(ListAttr));
    if (list == NULL) {
        CrLogW("Unable to allocate memory\n");
        return NULL;
    }
    bzero(list, sizeof(ListAttr));

    list->node.next = NULL;
    list->node.prev = NULL;

    return list;
}

void list_clear(struct list_head* head)
{
    ListAttr *pos, *next;

    if(head == NULL)  
        return;  

    list_for_each_entry_safe(pos, next, head, node) {
        list_del(&pos->node);
        free(pos);
    }
}

void print_list(struct list_head* head)
{
    ListAttr *pos;

    if(head == NULL)
        return;

    CrLogI("print_list\n");

    list_for_each_entry(pos, head, node)
    {
        CrLogI("x=%f, y=%f, z=%f e=%f f=%f\n",
            pos->data.x, pos->data.y, pos->data.z,
            pos->data.e, pos->data.f);
    }
}


ListAttr* cmdToPoint(char* cmd, PointAttr* prev)
{
    ListAttr *p = list_new_node();
    if(p == NULL){
        return NULL;
    }
    bzero(p, sizeof(ListAttr));
    memcpy(&p->data, prev, sizeof(PointAttr));
    bool hasExtruded = false;

    // 以“ ”分割字符（可以用strtok）
    char* token = strtok(cmd, " ");
    while(token)
    {
        if (strlen(token) > 0)
        {
            // 获取key-value，x\y\z\e\f\g
            char key = tolower(*token);
            double value = atof(token + 1);
          
            if(key == ';')
                break;
            // 有e轴，表示有挤出动作
            if (key == 'e' && value > 0)
                hasExtruded = true;
            if (key == 'g') {
                token = strtok(NULL, " ");
                continue;
            }

            if(key == 'e'){
                // CrLogI("e=%f",value);
                p->data.e = value;
            } else if(key == 'x'){
                p->data.x = value;
            } else if(key == 'y'){
                p->data.y = value;
            } else if(key == 'z'){
                p->data.z = value;
            } else if(key == 'f'){
                p->data.f = value;
            } else if(key == 'g'){
                p->data.g = value;
            }
        }
        token = strtok(NULL, " ");
    };

    // 标识挤出打印，还是喷嘴平移
    if(hasExtruded){
        p->data.type = 1;
    }else{
        p->data.type = 0;
    }
    
    //printf("type=%d \n",p->data.type);

    return p;
}

// 移动指令，判断单行指令是否是G0、G1开头
bool isMoveCmd(char* cmd)
{
    if(strncmp(cmd, "G0", 2) == 0 || strncmp(cmd, "G1", 2) == 0)
        return true;
    else
        return false;
    
}


static int GeneratePointCloud(struct list_head* points_list, int size, float segmentLen, struct list_head* pointcloud_list)
{
    ListAttr *pos, *next;

    ListAttr* point1 = list_entry(points_list, ListAttr, node);
    double max_x = point1->data.x;
    double min_x = point1->data.x;
    ListAttr* point2 = list_entry(point1->node.next, ListAttr, node);
    double max_y = point2->data.y;
    double min_y = point2->data.y;
                
    struct list_head *head = points_list;

    CrLogI("size=%d\n", size);

    list_for_each_entry_safe(pos, next, head, node)
    {
        max_x = max_x > pos->data.x ? max_x : pos->data.x;
        min_x = min_x < pos->data.x ? min_x : pos->data.x;
        max_y = max_y > pos->data.y ? max_y : pos->data.y;
        min_y = min_y < pos->data.y ? min_y : pos->data.y;
        //printf("x=%f, y=%f, z=%f e=%f f=%f\n",pos->data.x,pos->data.y,pos->data.z,pos->data.e,pos->data.f);
        // type == 1: 打印机有挤出在打印
        // type == 0: 打印机没有挤出在平移
                    
        if (pos->data.type == 1)
        {
            //printf("type=%d\n",pos->data.type);
            ListAttr* v = list_entry(pos->node.prev, ListAttr, node);;
            if(&v->node == head) {
                continue;
            }
            float ta = sqrt(pow(pos->data.x - v->data.x, 2) + pow(pos->data.y - v->data.y, 2));  // 总长度
            float len = segmentLen;      // 预分段长度
            int paragraphs = ceil(ta/len);   // 分段数
            // CrLogI("paragraphs=%d",paragraphs);
            // 起点坐标
            ListAttr* p1 = list_new_node();
            if (p1 == NULL ) {
                CrLogW("Unable to allocate memory\n");
                return -1;
            }
            p1->data.x = v->data.x;
            p1->data.y = v->data.y;
            p1->data.z = v->data.z;
            list_add_tail(&p1->node, pointcloud_list);

            // 分段坐标
            for (int m = 1; m < paragraphs; m++) {
                float x = v->data.x + m * (pos->data.x - v->data.x) / paragraphs;
                float y = v->data.y + m * (pos->data.y - v->data.y) / paragraphs;
                ListAttr* vp = list_new_node();
                vp->data.x = x;
                vp->data.y = y;
                vp->data.z =  v->data.z;
                list_add_tail(&vp->node, pointcloud_list);
            }

            // 终点坐标
            ListAttr* p2 = list_new_node();
            p2->data.x = pos->data.x;
            p2->data.y = pos->data.y;
            p2->data.z = pos->data.z;
            list_add_tail(&p2->node, pointcloud_list);
        }
    }

    return 0;
}


struct list_head* loadfile(char* filepath, float segmentLen){

    if(!filepath)
        return NULL;

    // 打开文件
    FILE *fp = fopen(filepath,"r");
    if(!fp){
        CrLogW("open file: %s fail\n", filepath);
        return NULL;
    }

    PointAttr previous ={0};
    bool isReading = false;

    struct list_head *points_list = (struct list_head *)malloc(sizeof(struct list_head));
    struct list_head *pointcloud_list = (struct list_head *)malloc(sizeof(struct list_head));

    INIT_LIST_HEAD(points_list);
    INIT_LIST_HEAD(pointcloud_list);

    float lastLayerHight = 0;
    char str[MAX_LEN]={0};
    // G0/G1：Linear Movement，G0---start
    // F：Print head movement speed
    // E：Wire speed
    while (fgets(str, MAX_LEN ,fp))
    {
        char cmd[MAX_LEN] = {0};
        memcpy(cmd, str, MAX_LEN);
        //printf("str=%s\n",str);

        if (isMoveCmd(cmd) && isReading)
        {  
            //printf("isMoveCmd\n");
            // 获取顶点数据
            ListAttr* point = cmdToPoint(str, &previous);
            if(point == NULL) {
                fclose(fp);
                return NULL;
            }

            // 找到有E轴移动，判断是否取完一层
            bool isNewLayer = point->data.z > lastLayerHight;
            if(point->data.type && isNewLayer)
            {
                // 过滤掉无效的层数据
                int size = list_size(points_list);
                CrLogI("size = %d, point->data.z = %f lastLayerHight = %f\n", size, point->data.z, lastLayerHight);
               
                // 判断是否是有效层数
                if (size < 20 || lastLayerHight <= 0.0001)
                {
                    lastLayerHight = point->data.z;
                    list_clear(points_list);

                    memcpy(&previous,  &point->data, sizeof(PointAttr));
                    list_add_tail(&point->node, points_list);
                    continue;
                }
                CrLogI("isNewLayer\n");
                free(point);
                
                // 有效的层数据
                GeneratePointCloud(points_list, size, segmentLen, pointcloud_list);
                list_clear(points_list);
                break;
            }

            // 保存前一个点信息
            memcpy(&previous, &point->data,  sizeof(PointAttr));
            // 保存单个顶点信息到容器
            list_add_tail(&point->node, points_list);

        } else if (strncmp(cmd, "M104", 4) == 0 && !isReading) {
            // M104命令-加热喷嘴
            // 进入读取顶点阶段
            CrLogI("M104\n");
            isReading = true;
        } else if (strncmp(cmd, "G92", 3) == 0 && isReading) {
            // G92命令-设置当前位置
            // tips: 常在每一层的开始或在启动或撤回命令之前执行此操作
            CrLogI("G92\n");
            // list_clear(points);
        } else if (strncmp(cmd, ";End", 4) == 0) {
            // 判断是否为单层模型
            bool isNewLayer = previous.z < 0.5;
            int size = list_size(points_list);
            CrLogI("previous.z = %f size = %d\n", previous.z, size);

            // 判断是否是有效层数
            if (isNewLayer || size > 20) {
                CrLogI("isNewLayer\n");
                // 有效的层数据
                GeneratePointCloud(points_list, size, segmentLen, pointcloud_list);
            }
            
            // 清空资源
            list_clear(points_list);
            CrLogI("END\n");
            // 文件读取结束
            break;
        }
    }
    if(fp)
        fclose(fp);

    list_clear(points_list);
    free(points_list);

    //print_list(pointcloud_list);
    int list_count = list_size(pointcloud_list);
    CrLogI("list_count=%d\n",list_count);

    return pointcloud_list;
}

double max(double a,double b)
{
    return a>b?a:b;
}
double min(double a,double b)
{
    return a<b?a:b;
}

void getLayerRange(float* points,int len)
{
    float max_x=points[0];
    float max_y=points[1];
    float min_x=points[0];
    float min_y=points[1];
    for (int i = 0; i < len; i++)
    {      
        max_x = max(max_x, points[3*i+0]);
        min_x = min(min_x, points[3*i+0]);
        max_y = max(max_y, points[3*i+1]);
        min_y = min(min_y, points[3*i+1]);
    }
    CrLogI("max_x=%f\n",max_x);
    CrLogI("min_x=%f\n",min_x);
    CrLogI("max_y=%f\n",max_y);
    CrLogI("min_y=%f\n",min_y);

    model_max_x = max_x;
    model_max_y = max_y;
    model_min_x = min_x;
    model_min_y = min_y;
}

int GetGcodeModelSize(float *max_x, float *max_y, float *min_x, float *min_y)
{
    *max_x = model_max_x;
    *max_y = model_max_y;
    *min_x = model_min_x;
    *min_y = model_min_y;
    return 0;
}

bool IsPointCloudRestored(void)
{
    if (model_max_x < 0.0001 || model_max_y < 0.0001 || model_min_x < 0.0001 || model_min_y < 0.0001) return false;
    else return true;
}

int GetGcodePointCloudFromFile(char *gcodeFile, float segmentLen)
{
    ListAttr *pos, *next;
    int i = 0;

    CrLogI("start!!!\n");
    CrLogI("segmentLen = %f\n", segmentLen);
    model_max_x = 0;
    model_max_y = 0;
    model_min_x = 0;
    model_min_y = 0;

    struct list_head *points = loadfile(gcodeFile, segmentLen);
    if(points != NULL) {
        struct list_head* head = points;
        int num = list_size(points) - 1;   // remove list head?
        if(num<=0){
            CrLogI("points less than 0\n");
            return -1;
        }
        // 保存gcode还原点云数据
        json_object *gcodePointObj = json_object_new_array();

        float p[num * 3];
        CrLogI("points num=%d\n", num);

        list_for_each_entry_safe(pos, next, head->next, node) {
            json_object *point = json_object_new_array();
            json_object_array_add(point, json_object_new_int(pos->data.x * 1000));
            json_object_array_add(point, json_object_new_int(pos->data.y * 1000));
            json_object_array_add(point, json_object_new_int(pos->data.z * 1000));
            json_object_array_add(gcodePointObj, point);

            p[3*i+0] = pos->data.x;
            p[3*i+1] = pos->data.y;
            p[3*i+2] = pos->data.z;
            i++;
        }

        // 获取图层范围
        CrLogI("get layer range");
        getLayerRange(p,num);
        list_clear(points);
        free(points);

        // 保存到文件
        json_object_to_file_ext(GetTempGcodeReductionPoint(), gcodePointObj, JSON_C_TO_STRING_PRETTY);
        json_object_put(gcodePointObj);
        malloc_trim(0); // 强制释放内存给系统
    }
    
    return 0;
}


// int main()
// {
//     printf("start!!!\n");
//     ListAttr* points = loadfile("/home/feng/gcode_files/x3.gcode");
//     if(points!=NULL){
//         ListAttr* tmp=points;
//         unsigned int num=0;
//         if(tmp->next)
//             tmp=tmp->next;
//         while(tmp->next){
//             num++;
//             tmp=tmp->next;
//         }
//         float p[num*3];
//         printf("num=%d\n",num);
//         tmp=points;
//         tmp=tmp->next;
//         for(int i=0;i<num;i++){

//             p[3*i+0]=tmp->data.x;
//             p[3*i+1]=tmp->data.y;
//             p[3*i+2]=tmp->data.z;
//             tmp=tmp->next;
//         }
//         getLayerRange(p,num);
//         list_clear(points);
//         free(points);
//     }
    
//     return 0;
// }
