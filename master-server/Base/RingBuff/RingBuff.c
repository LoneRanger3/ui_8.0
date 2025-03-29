/*
 * @Description : 
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-29 14:23:52
 * @LastEditTime: 2023-02-22 20:18:14
 */

#include <string.h>
#include "RingBuff.h"

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {RingBuff_t *} ringqp
 * @param {Ring_t *} array_ptr
 * @param {unsigned} size
 */
int RingBuffInit(RingBuff_t *ringqp, Ring_t *array_ptr, unsigned int size)
{
    ringqp->array = array_ptr;
    ringqp->size = size;
    ringqp->head = 0;
    ringqp->tail = 0;
    return 0;
}

/**
 * @description: 
 * @return {*}
 * @param {RingBuff_t} *ringqp
 */
int GetRingBuffSize(RingBuff_t *ringqp)
{
    if (ringqp->tail > ringqp->head)
        return (ringqp->size - ringqp->tail + ringqp->head - 1);
    else
        return (ringqp->head - ringqp->tail - 1);
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {RingBuff_t *} ringqp
 * @param {Ring_t} data
 */
int RingBuffPush(RingBuff_t *ringqp, Ring_t data)
{
    if(RingBuffFull(ringqp))
        return -1;

    memset(&ringqp->array[ringqp->tail], 0, sizeof(Ring_t));
    ringqp->array[ringqp->tail] = data;
    ringqp->tail = (ringqp->tail + 1) % ringqp->size ;
    return 0;
}

/**
 * @description: 
 * @param  {*}
 * @return {*}
 * @param {RingBuff_t} *ringqp
 * @param {Ring_t *} val
 */
int RingBuffPoll(RingBuff_t *ringqp, Ring_t * val)
{
    if(RingBuffEmpty(ringqp))
        return -1;

    *val = ringqp->array[ringqp->head];
    ringqp->head = (ringqp->head + 1) % ringqp->size ;
    return 0;
}
