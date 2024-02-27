#ifndef LLIBS_FRAMEWORK_H_
#define LLIBS_FRAMEWORK_H_

/**************************************************************************//**
 * @file     llibs.h
 * @brief    Project L - Llibs, cross-platform framework
 * @version  V0.2.0
 * @date     5. Jan 2024
 * @author   Matvey Rybalkin
******************************************************************************/

/* Check C standard */
#if __STDC_VERSION__  >= 201112L

/* Include standard libraries */
#include "defs.h"
#include "types.h"
#include "string.h"
#include "thread.h"
#include "mem.h"
#include "io.h"
#include "main.h"

/* Include external submodules */

#include "../../external/external.h"

#else /* ERROR (__STDC_VERSION__ >= 201112L) */
#error [llibs.h]: Requires at least version C 2011 (__STDC_VERSION__ >= 201112L)
#endif
#endif // LLIBS_FRAMEWORK_H_