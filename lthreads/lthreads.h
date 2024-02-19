#ifndef __L_DEFS_H__
#define __L_DEFS_H__

/**************************************************************************//**
 * @file     lthreads.h
 * @brief    Project L - Cross-platform threads library (for Lena lang)
 * @version  V0.0.1
 * @date     10. Feb 2024
 ******************************************************************************/

/* Include platform selector */
#include "platforms/platform.h"

#ifdef __LTHREADS_SPT__

extern lthread_t lthread_create(lthread_func_ptr_t func);
extern lthread_error_t lthread_get_error(lthread_t* thread);
extern void lthread_join(lthread_t* thread, lthread_wait_t wait_ms);

#else
#error "[llibs.h] -> [lthreads.h]: Current platform doesn't support thread functions!"
#endif

#endif // __L_DEFS_H__