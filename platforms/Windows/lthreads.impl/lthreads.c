
/* Include libraries */
#include "lthreads.defs.h"

lthread_t lthread_create(LPTHREAD_START_ROUTINE func){
    lthread_t thread = {NULL, 0};
    thread.hThread = CreateThread(NULL, 0, (func), NULL, 0, &thread.IdThread);
    return thread;
}

/* lthread get error */

lthread_error_t lthread_get_error(lthread_t thread){
    uint8_t result = 0;
    result = ((bool)(thread.IdThread) << 1) |((bool)(thread.hThread) << 0);
    return (lthread_error_t)(result);
}

/* lthread join */

void lthread_join(lthread_t* thread, lthread_wait_t wait_ms){
    WaitForSingleObject(thread->hThread, wait_ms);
    CloseHandle(thread->hThread);
    thread->IdThread = 0;
}