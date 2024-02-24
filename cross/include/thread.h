#ifndef LLIBS_FRAMEWORK_THREAD_H_
#define LLIBS_FRAMEWORK_THREAD_H_

/**************************************************************************//**
 * @file     string.h
 * @brief    Project L - Llibs, cross-platform framework / string.h
 * @version  V0.2.0
 * @date     5. Jan 2024
 ******************************************************************************/

/* Llibs */
#include "llibs.h"

/* Standard functions */
extern lbool lthread_new(lc* str1, lc* str2);
extern lbool lthread_join(lc* dest, const lc* src);

#endif // LLIBS_FRAMEWORK_THREAD_H_