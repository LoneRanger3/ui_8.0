#ifndef QQUEUE_H
#define QQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>

#ifdef  __cplusplus
extern "C" {
#endif

enum {
    QUEUE_THREADSAFE = 0x01,
};

#include <unistd.h>
#include <pthread.h>

typedef struct qmutex_s qmutex_t;    /*!< qlibc pthread mutex type*/

struct qmutex_s {
    pthread_mutex_t mutex;  /*!< pthread mutex */
    pthread_t owner;        /*!< mutex owner thread id */
    int count;              /*!< recursive lock counter */
};

#define DEBUG(fmt,arg...)         do{\
                                        printf("<<-DEBUG->> [%u] " fmt "\n",__LINE__, ##arg);\
                                    }while(0)

#define Q_MUTEX_NEW(m,r) do {                                           \
        qmutex_t *x = (qmutex_t *)calloc(1, sizeof(qmutex_t));          \
        pthread_mutexattr_t _mutexattr;                                 \
        pthread_mutexattr_init(&_mutexattr);                            \
        if(r == true) {                                                 \
            pthread_mutexattr_settype(&_mutexattr, PTHREAD_MUTEX_RECURSIVE); \
        }                                                               \
        int _ret = pthread_mutex_init(&(x->mutex), &_mutexattr);        \
        pthread_mutexattr_destroy(&_mutexattr);                         \
        if(_ret == 0) {                                                 \
            m = x;                                                      \
        } else {                                                        \
            DEBUG("Q_MUTEX: can't initialize mutex. [%d]", _ret);       \
            free(x);                                                    \
            m = NULL;                                                   \
        }                                                               \
    } while(0)

#define Q_MUTEX_LEAVE(m) do {                                           \
        if(m == NULL) break;                                            \
        qmutex_t *x = (qmutex_t *)m;                                    \
        if(!pthread_equal(x->owner, pthread_self())) {                  \
            DEBUG("Q_MUTEX: unlock - owner mismatch.");                 \
        }                                                               \
        if((x->count--) < 0) x->count = 0;                              \
        pthread_mutex_unlock(&(x->mutex));                              \
    } while(0)

#define MAX_MUTEX_LOCK_WAIT (15000)
#define Q_MUTEX_ENTER(m) do {                                           \
        if(m == NULL) break;                                            \
        qmutex_t *x = (qmutex_t *)m;                                    \
        while(true) {                                                   \
            int _ret, i;                                                \
            for(i = 0; (_ret = pthread_mutex_trylock(&(x->mutex))) != 0 \
                        && i < MAX_MUTEX_LOCK_WAIT; i++) {              \
                if(i == 0) {                                            \
                    DEBUG("Q_MUTEX: mutex is already locked - retrying"); \
                }                                                       \
                usleep(1);                                              \
            }                                                           \
            if(_ret == 0) break;                                        \
            DEBUG("Q_MUTEX: can't get lock - force to unlock. [%d]",    \
                  _ret);                                                \
            Q_MUTEX_LEAVE(x);                                           \
        }                                                               \
        x->count++;                                                     \
        x->owner = pthread_self();                                      \
    } while(0)

#define Q_MUTEX_DESTROY(m) do {                                         \
        if(m == NULL) break;                                            \
        qmutex_t *x = (qmutex_t *)m;                                    \
        if(x->count != 0) DEBUG("Q_MUTEX: mutex counter is not 0.");    \
        int _ret;                                                       \
        while((_ret = pthread_mutex_destroy(&(x->mutex))) != 0) {       \
            DEBUG("Q_MUTEX: force to unlock mutex. [%d]", _ret);        \
            Q_MUTEX_LEAVE(x);                                           \
        }                                                               \
        free(x);                                                        \
    } while(0)

typedef struct qqueue_s qqueue_t;
typedef struct qqueue_obj_s qqueue_obj_t;

struct qqueue_obj_s {
    void *data;          /*!< data */
    uint32_t size;         /*!< data size */

    qqueue_obj_t *prev;   /*!< previous link */
    qqueue_obj_t *next;   /*!< next link */
};

struct qqueue_s {

    /* private variables - do not access directly */
    void *qmutex;     /*!< initialized when qqueue_OPT_THREADSAFE is given */
    uint32_t num;           /*!< number of elements */
    uint32_t max;           /*!< maximum number of elements. 0 means no limit */
    uint32_t datasum;       /*!< total sum of data size, does not include name size */

    qqueue_obj_t *first;   /*!< first object pointer */
    qqueue_obj_t *last;    /*!< last object pointer */
};
qqueue_t *qqueue(int options);
bool qqueue_removeat(qqueue_t *list, int index);
bool qqueue_addat(qqueue_t *list, int index, const void *data, uint32_t size);
void *qqueue_popat(qqueue_t *list, int index, uint32_t *size);
bool qqueue_addlast(qqueue_t *list, const void *data, uint32_t size);
void *qqueue_popfirst(qqueue_t *list, uint32_t *size);
uint32_t qqueue_setsize(qqueue_t *list, uint32_t max);
void qqueue_free(qqueue_t *list);

void qqueue_lock(qqueue_t *list);
void qqueue_unlock(qqueue_t *list);

void free_s(void *ptr);

#ifdef  __cplusplus
}
#endif  /* end of __cplusplus */

#endif
