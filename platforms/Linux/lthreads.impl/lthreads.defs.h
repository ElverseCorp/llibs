#ifndef __L_THREADS_DEFS_LINUX_H__
#define __L_THREADS_DEFS_LINUX_H__

/**************************************************************************//**
 * @file     lthread.defs.h
 * @brief    Project L - Native Linux threads definitions library for Llibs framework
 * @version  V0.0.1
 * @date     19. Feb 2023
 ******************************************************************************/

#define __LTHREADS_SPT__

/* Standard libraires */
#include <stdint.h>
#include <stdbool.h>

#define _GNU_SOURCE
#include <pthread.h>
#include <features.h>
#include <sys/time.h>

typedef enum {
    LTHREAD_SUCCESS = 0,
    /* NEXT LINES OF CODE ARE NOT CROSS-PLATFORM */
    /** LTHREAD_ERROR_N
     *  -> N is error code;
     * 
    */
} lthread_error_t;

typedef struct {
    pthread_t pThread;
    int32_t errThread;
} lthread_t;

typedef void* lthread_func_t;
#define LENA_API
#define LTHREAD_ARGS        void* arg
#define LTHREAD_CALLBACK    NULL

#define LTHREAD_WAIT_INFINITE 0
typedef uint32_t lthread_wait_t;



#endif // __L_THREADS_DEFS_LINUX_H__