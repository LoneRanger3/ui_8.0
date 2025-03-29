/******************************************************************************
 * qLibc
 *
 * Copyright (c) 2010-2015 Seungyoung Kim.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

/**
 * @file qqueue.c Doubly Linked-list implementation.
 *
 * qqueue container is a doubly Linked-List implementation.
 * qqueue provides uniformly named methods to add, get, pop and remove an
 * element at the beginning and end of the list. These operations allow qqueue
 * to be used as a stack, queue, or double-ended queue.
 *
 * @code
 *  [Conceptional Data Structure Diagram]
 *
 *  last~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+
 *                                                          |
 *          +-----------+  doubly  +-----------+  doubly  +-|---------+
 *  first~~~|~>   0   <~|~~~~~~~~~~|~>   1   <~|~~~~~~~~~~|~>   N     |
 *          +-----|-----+  linked  +-----|-----+  linked  +-----|-----+
 *                |                      |                      |
 *          +-----v---------------+      |                +-----v-----+
 *          | DATA A              |      |                | DATA N    |
 *          +---------------------+      |                +-----------+
 *                 +---------------------v------------------+
 *                 | DATA B                                 |
 *                 +----------------------------------------+
 * @endcode
 *
 * @code
 *  // create a list.
 *  qqueue_t *list = qqueue(qqueue_THREADSAFE);
 *
 *  // insert elements
 *  list->addlast(list, "e1", sizeof("e1"));
 *  list->addlast(list, "e2", sizeof("e2"));
 *  list->addlast(list, "e3", sizeof("e3"));
 *
 *  // get
 *  char *e1 = (char*)list->getfirst(list, NULL, true));    // malloced
 *  char *e3  = (char*)list->getat(list, -1, NULL, false)); // no malloc
 *  (...omit...)
 *  free(e1);
 *
 *  // pop (get and remove)
 *  char *e2 = (char*)list->popat(list, 1, NULL)); // get malloced copy
 *  (...omit...)
 *  free(e2);
 *
 *  // debug output
 *  list->debug(list, stdout, true);
 *
 *  // traversal
 *  qqueue_obj_t obj;
 *  memset((void*)&obj, 0, sizeof(obj)); // must be cleared before call
 *  list->lock(list);
 *  while (list->getnext(list, &obj, false) == true) {
 *    printf("DATA=%s, SIZE=%zu\n", (char*)obj.data, obj.size);
 *  }
 *  list->unlock(list);
 *
 *  // free object
 *  list->free(list);
 * @endcode
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include "qqueue.h"

#ifndef _DOXYGEN_SKIP

static void *get_at(qqueue_t *list, int index, uint32_t *size, bool newmem, bool remove);
static qqueue_obj_t *get_obj(qqueue_t *list, int index);
static bool remove_obj(qqueue_t *list, qqueue_obj_t *obj);

#endif

/**
 * Create new qqueue_t linked-list container
 *
 * @param options   combination of initialization options.
 *
 * @return a pointer of malloced qqueue_t container, otherwise returns NULL.
 * @retval errno will be set in error condition.
 *  -ENOMEM : Memory allocation failure.
 *
 * @code
 *  qqueue_t *list = qqueue(0);
 * @endcode
 *
 * @note
 *   Available options:
 *   - qqueue_THREADSAFE - make it thread-safe.
 */
qqueue_t *qqueue(int options) {
    qqueue_t *list = (qqueue_t *) calloc(1, sizeof(qqueue_t));
    if (list == NULL) {
        errno = ENOMEM;
        return NULL;
    }

    // handle options.
    if (options & QUEUE_THREADSAFE) {
        Q_MUTEX_NEW(list->qmutex, true);
        if (list->qmutex == NULL) {
            errno = ENOMEM;
            free_s(list);
            return NULL;
        }
    }

    return list;
}

/**
 * qqueue->setsize(): Limit maximum number of elements allowed in this list.
 *
 * @param list  qqueue_t container pointer.
 * @param max   maximum number of elements. 0 means no limit.
 *
 * @return previous maximum number.
 *
 * @note
 *  The default maximum number of elements is unlimited.
 */
uint32_t qqueue_setsize(qqueue_t *list, uint32_t max) {
    qqueue_lock(list);
    uint32_t old = list->max;
    list->max = max;
    qqueue_unlock(list);
    return old;
}


/**
 * qqueue->addlast(): Appends a element to the end of this list.
 *
 * @param list  qqueue_t container pointer.
 * @param data  a pointer which points data memory.
 * @param size  size of the data.
 *
 * @return true if successful, otherwise returns false.
 * @retval errno will be set in error condition.
 *  - ENOBUFS : List full. Only happens when this list has set to have limited
 *              number of elements.
 *  - EINVAL  : Invalid argument.
 *  - ENOMEM  : Memory allocation failure.
 */
bool qqueue_addlast(qqueue_t *list, const void *data, uint32_t size) {
    return qqueue_addat(list, -1, data, size);
}

/**
 * qqueue->addat(): Inserts a element at the specified position in this
 * list.
 *
 * @param list   qqueue_t container pointer.
 * @param index  index at which the specified element is to be inserted.
 * @param data   a pointer which points data memory.
 * @param size   size of the data.
 *
 * @return true if successful, otherwise returns false.
 * @retval errno will be set in error condition.
 *  - ENOBUFS : List full. Only happens when this list has set to have limited
 *              number of elements.
 *  - ERANGE  : Index out of range.
 *  - EINVAL  : Invalid argument.
 *  - ENOMEM  : Memory allocation failure.
 *
 * @code
 *                     first           last      new
 *  Linked-list        [ A ]<=>[ B ]<=>[ C ]?==?[   ]
 *  (positive index)     0       1       2        3
 *  (negative index)    -3      -2      -1
 * @endcode
 *
 * @code
 *  qqueue_t *list = qqueue();
 *  list->addat(list, 0, &obj, sizeof(obj));  // same as addfirst().
 *  list->addat(list, -1, &obj, sizeof(obj)); // same as addlast().
 * @endcode
 *
 * @note
 *  Index starts from 0.
 */
bool qqueue_addat(qqueue_t *list, int index, const void *data, uint32_t size) {
    // check arguments
    if (data == NULL || size <= 0) {
        // LOG_PRINTF(LOG_ERROR , "%s" , "the data is NULL.");
        errno = EINVAL;
        return false;
    }

    qqueue_lock(list);

    // check maximum number of allowed elements if set
    if (list->max > 0 && list->num >= list->max) {
        // LOG_PRINTF(LOG_ERROR , "%s" , "the list is full...");
        errno = ENOBUFS;
        qqueue_unlock(list);
        return false;
    }

    // adjust index
    if (index < 0)
        index = (list->num + index) + 1;  // -1 is same as addlast()
    if (index < 0 || index > list->num) {
        // out of bound
        // LOG_PRINTF(LOG_ERROR , "the index out of bound...");
        qqueue_unlock(list);
        errno = ERANGE;
        return false;
    }

    // duplicate object
    void *dup_data = malloc(size);
    if (dup_data == NULL) {
        // LOG_PRINTF(LOG_ERROR , "malloc %d failed, errno = %d , msg = %s", size , errno, strerror(errno));
        qqueue_unlock(list);
        errno = ENOMEM;
        return false;
    }
    memcpy(dup_data, data, size);

    // make new object list
    qqueue_obj_t *obj = (qqueue_obj_t *) malloc(sizeof(qqueue_obj_t));
    if (obj == NULL) {
        // LOG_PRINTF(LOG_ERROR , "malloc size %ld failed, errno = %d , msg = %s", sizeof(qqueue_obj_t) , errno, strerror(errno));
        free_s(dup_data);
        qqueue_unlock(list);
        errno = ENOMEM;
        return false;
    }
    obj->data = dup_data;
    obj->size = size;
    obj->prev = NULL;
    obj->next = NULL;

    // make link
    if (index == 0) {
        // add at first
        obj->next = list->first;
        if (obj->next != NULL)
            obj->next->prev = obj;
        list->first = obj;
        if (list->last == NULL)
            list->last = obj;
    } else if (index == list->num) {
        // add after last
        obj->prev = list->last;
        if (obj->prev != NULL)
            obj->prev->next = obj;
        list->last = obj;
        if (list->first == NULL)
            list->first = obj;
    } else {
        // add at the middle of list
        // LOG_PRINTF(LOG_DEBUG , "add at the middle of list , list->first = %p , list->last = %p" , list->first , list->last);
        qqueue_obj_t *tgt = get_obj(list, index);
        if (tgt == NULL) {
            // should not be happened.
            // LOG_PRINTF(LOG_ERROR , "should not be happened!");
            free_s(dup_data);
            free_s(obj);
            qqueue_unlock(list);
            errno = EAGAIN;
            return false;
        }

        // insert obj
        tgt->prev->next = obj;
        obj->prev = tgt->prev;
        obj->next = tgt;
        tgt->prev = obj;
    }

    list->datasum += size;
    list->num++;

    qqueue_unlock(list);

    return true;
}

/**
 * qqueue->popfirst(): Returns and remove the first element in this list.
 *
 * @param list  qqueue_t container pointer.
 * @param size  if size is not NULL, element size will be stored.
 *
 * @return a pointer of malloced element, otherwise returns NULL.
 * @retval errno will be set in error condition.
 *  -ENOENT : List is empty.
 *  -ENOMEM : Memory allocation failure.
 */
void *qqueue_popfirst(qqueue_t *list, uint32_t *size) {
    return qqueue_popat(list, 0, size);
}


/**
 * qqueue->popat(): Returns and remove the element at the specified
 * position in this list.
 *
 * @param list   qqueue_t container pointer.
 * @param index  index at which the specified element is to be inserted
 * @param size   if size is not NULL, element size will be stored.
 *
 * @return a pointer of malloced element, otherwise returns NULL.
 * @retval errno will be set in error condition.
 *  -ERANGE : Index out of range.
 *  -ENOMEM : Memory allocation failure.
 *
 * @code
 *                     first           last
 *  Linked-list        [ A ]<=>[ B ]<=>[ C ]
 *  (positive index)     0       1       2
 *  (negative index)    -3      -2      -1
 * @endcode
 *
 * @note
 *  Negative index can be used for addressing a element from the end in this
 *  stack. For example, index -1 is same as poplast() and index 0 is same as
 *  popfirst();
 */
void *qqueue_popat(qqueue_t *list, int index, uint32_t *size) {
    return get_at(list, index, size, true, true);
}

/**
 * qqueue->removefirst(): Removes the first element in this list.
 *
 * @param list  qqueue_t container pointer.
 *
 * @return a number of removed objects.
 * @retval errno will be set in error condition.
 *  -ENOENT : List is empty.
 */
bool qqueue_removefirst(qqueue_t *list) {
    return qqueue_removeat(list, 0);
}

/**
 * qqueue->removeat(): Removes the element at the specified position in
 * this list.
 *
 * @param list   qqueue_t container pointer.
 * @param index  index at which the specified element is to be removed.
 *
 * @return a number of removed objects.
 * @retval errno will be set in error condition.
 *  -ERANGE : Index out of range.
 */
bool qqueue_removeat(qqueue_t *list, int index) {
    qqueue_lock(list);

    // get object pointer
    qqueue_obj_t *obj = get_obj(list, index);
    if (obj == NULL) {
        qqueue_unlock(list);
        return false;
    }

    bool ret = remove_obj(list, obj);

    qqueue_unlock(list);

    return ret;
}

/**
 * qqueue->size(): Returns the number of elements in this list.
 *
 * @param list  qqueue_t container pointer.
 *
 * @return the number of elements in this list.
 */
uint32_t qqueue_size(qqueue_t *list) {
    return list->num;
}

/**
 * qqueue->size(): Returns the sum of total element size.
 *
 * @param list  qqueue_t container pointer.
 *
 * @return the sum of total element size.
 */
uint32_t qqueue_datasize(qqueue_t *list) {
    return list->datasum;
}

/**
 * qqueue->clear(): Removes all of the elements from this list.
 *
 * @param list  qqueue_t container pointer.
 */
void qqueue_clear(qqueue_t *list) {
    qqueue_lock(list);
    qqueue_obj_t *obj;
    for (obj = list->first; obj;) {
        qqueue_obj_t *next = obj->next;
        free_s(obj->data);
        free_s(obj);
        obj = next;
    }

    list->num = 0;
    list->datasum = 0;
    list->first = NULL;
    list->last = NULL;
    qqueue_unlock(list);
}

/**
 * qqueue->lock(): Enters critical section.
 *
 * @param list  qqueue_t container pointer.
 *
 * @note
 *  From user side, normally locking operation is only needed when traverse all
 *  elements using qqueue->getnext().
 */
void qqueue_lock(qqueue_t *list) {
    Q_MUTEX_ENTER(list->qmutex);
}

/**
 * qqueue->unlock(): Leaves critical section.
 *
 * @param list  qqueue_t container pointer.
 */
void qqueue_unlock(qqueue_t *list) {
    Q_MUTEX_LEAVE(list->qmutex);
}

/**
 * qqueue->free(): Free qqueue_t.
 *
 * @param list  qqueue_t container pointer.
 */
void qqueue_free(qqueue_t *list) {
    qqueue_clear(list);
    Q_MUTEX_DESTROY(list->qmutex);

    free_s(list);
}

#ifndef _DOXYGEN_SKIP

//参数newmem的作用，在函数中定义一个obj指针，通过newmem来判断是否申请新的空间来存储queue中的obj到指针中
//参数remove的作用，在函数中删除找到的queue中的结点obj
static void *get_at(qqueue_t *list, int index, uint32_t *size, bool newmem,
bool remove) {
    qqueue_lock(list);

    // get object pointer
    qqueue_obj_t *obj = get_obj(list, index);
    if (obj == NULL) {
        qqueue_unlock(list);
        // return false;
        return NULL;
    }

    // copy data
    void *data;
    if (newmem == true) {
        data = malloc(obj->size);
        if (data == NULL) {
            // LOG_PRINTF(LOG_ERROR , "malloc %d failed, errno = %d , msg = %s", obj->size , errno, strerror(errno));
            // if(remove_obj(list , obj) == false)
            //     LOG_PRINTF(LOG_ERROR , "remove_obj failed!");
            qqueue_unlock(list);
            errno = ENOMEM;
            return false;
        }
        memcpy(data, obj->data, obj->size);
    } else {
        data = obj->data;
    }
    if (size != NULL)
        *size = obj->size;

    // remove if necessary
    if (remove == true) {
        if(remove_obj(list, obj) == false) 
        {
            // LOG_PRINTF(LOG_ERROR , "%s" , "remove_obj failed!");
            if(newmem == true)
                free_s(data);
            data = NULL;
        }
    }

    qqueue_unlock(list);

    return data;
}

static qqueue_obj_t *get_obj(qqueue_t *list, int index) {
    // index adjustment
    if (index < 0)
        index = list->num + index;
    if (index >= list->num) {
        errno = ERANGE;
        return NULL;
    }

    // detect faster scan direction
    bool backward;
    qqueue_obj_t *obj;
    int listidx;
    if (index < list->num / 2) {
        backward = false;
        obj = list->first;
        listidx = 0;
    } else {
        backward = true;
        obj = list->last;
        listidx = list->num - 1;
    }

    // find object
    while (obj != NULL) {
        if (listidx == index)
            return obj;

        if (backward == false) {
            obj = obj->next;
            listidx++;
        } else {
            obj = obj->prev;
            listidx--;
        }
    }

    // never reach here
    errno = ENOENT;
    return NULL;
}

static bool remove_obj(qqueue_t *list, qqueue_obj_t *obj) {
    if (obj == NULL)
        return false;

    // chain prev and next elements
    if (obj->prev == NULL)
        list->first = obj->next;
    else
        obj->prev->next = obj->next;
    if (obj->next == NULL)
        list->last = obj->prev;
    else
        obj->next->prev = obj->prev;

    // adjust counter
    list->datasum -= obj->size;
    list->num--;

    // release obj
    free_s(obj->data);
    free_s(obj);

    return true;
}

void free_s(void *ptr)
{
    if(ptr != NULL)
    {
        free(ptr);
        ptr = NULL;
    }
}
#endif /* _DOXYGEN_SKIP */

