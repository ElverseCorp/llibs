#ifndef __L_THREADS_DEFS_WINDOWS_H__
#define __L_THREADS_DEFS_WINDOWS_H__

/**************************************************************************//**
 * @file     lthread.defs.h
 * @brief    Project L - Native Windows threads definitions library for Llibs framework
 * @version  V0.0.1
 * @date     19. Feb 2023
 ******************************************************************************/

#define __LTHREADS_SPT__

/* Standard libraires */
#include <stdint.h>
#include <stdbool.h>

#include <windows.h>

typedef struct {
    HANDLE hThread;
    DWORD IdThread;
} lthread_t;

typedef DWORD lthread_func_t;
#define LENA_API WINAPI
#define LTHREAD_ARGS        LPVOID lpParam
#define LTHREAD_CALLBACK    0

typedef enum {
    LTHREAD_SUCCESS                 = 0b00000011,
    /* NEXT LINES OF CODE ARE NOT CROSS-PLATFORM */
    LTHREAD_ERROR_INVALID_POINTER   = 0b00000001,
    LTHREAD_ERROR_INVALID_ID        = 0b00000010,
} lthread_error_t;

#define LTHREAD_WAIT_INFINITE (DWORD)(INFINITE)
typedef DWORD lthread_wait_t;

#endif // __L_THREADS_DEFS_WINDOWS_H__