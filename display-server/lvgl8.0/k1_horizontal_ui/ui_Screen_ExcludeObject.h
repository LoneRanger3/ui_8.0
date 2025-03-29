#ifndef _EXCLUDEOBJECT_H
#define _EXCLUDEOBJECT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "ui.h"

#define CANVAS_WIDTH  300
#define CANVAS_HEIGHT  300
#define POINTSCOUNT  5

extern lv_obj_t * ui_ExcludeObject;

typedef enum
{
    NormalState = 1,
    CancelState = 2,
    PrintingState = 3,
    FocusState = 4,
}ObjectState;

typedef struct Exclueobject_t
{
    lv_point_t point[POINTSCOUNT];
    lv_point_t center;
    ObjectState state;
    int currentNumber;
    char singeObjectName[64];
}Exclueobject_t;

typedef struct{
    int ObjectCount;
    int CurrentObject;
}CurrentExclueObject_t;

void refreshExcludeObjectPage(char * data);
void ui_ExcludeObject_screen_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif