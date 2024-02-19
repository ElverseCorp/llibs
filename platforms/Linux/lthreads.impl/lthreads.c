
/* Include libraries */
#include "lthreads.defs.h"

/* Funcrions prototypes */
/* You must use -lpthread as argument for correct compilation */

extern int pthread_tryjoin_np(pthread_t thread, void **retval);

extern int pthread_timedjoin_np(pthread_t thread, void **retval, const struct timespec *abstime);


/* lthread create */

lthread_t lthread_create(void *(*func)(void *)){
    lthread_t result = {0, 0};
    result.errThread = pthread_create(&result.pThread, NULL, func, NULL);
    return result;
}

/* lthread get error */

// enum lthread_error_t is defined above

lthread_error_t lthread_get_error(lthread_t thread){
    return (lthread_error_t)(thread.errThread);
}

/* lthread join */

void lthread_join(lthread_t* thread, lthread_wait_t wait_ms){
    if (wait_ms != LTHREAD_WAIT_INFINITE){
        struct timespec timeout = {0, (wait_ms * 1000)};
        pthread_timedjoin_np(thread->pThread, NULL, &timeout);
    } else {
        pthread_join(thread->pThread, NULL);
    }
}