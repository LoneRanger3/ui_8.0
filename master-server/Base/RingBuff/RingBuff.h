/*
 * @Description : RingBuff.h
 * @Author      : Yufeng Zhang
 * @Date: 2021-12-29 14:23:52
 * @LastEditTime: 2023-02-22 20:19:11
 */
#ifndef __RING_BUFF_H__
#define __RING_BUFF_H__

#ifdef  __cplusplus  
extern "C" {  
#endif

typedef struct {  
    char cmd[100];   
}Ring_t; 

typedef struct {  
    unsigned int head;   
    unsigned int tail;
    unsigned int size;
    Ring_t *array;   
}RingBuff_t;    

#define RingBuffEmpty(q)   (q->head == q->tail)
#define RingBuffFull(q)    (((q->tail + 1) % q->size) == q->head)

int GetRingBuffSize(RingBuff_t *ringqp);
int RingBuffInit(RingBuff_t *ringqp, Ring_t *array_ptr, unsigned int size);
int RingBuffPush(RingBuff_t *ringqp, Ring_t data);
int RingBuffPoll(RingBuff_t *ringqp, Ring_t * val);

#ifdef  __cplusplus  
}  
#endif  /* end of __cplusplus */  

#endif