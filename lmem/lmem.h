#ifndef __L_MEMORY_H__
#define __L_MEMORY_H__

/**************************************************************************//**
 * @file     lmem.h
 * @brief    Project L - For mem. allocation (from Lena language -> lena-i)
 * @version  V0.0.1
 * @date     6. Feb 2024
 ******************************************************************************/

/* Standard libraries */
#include <stdlib.h>

/* Platform */
#include "platforms/platform.h"

/* Functions */

#ifdef __LMEM_SPT__
extern void* lmalloc(size_t size);
extern void* lcalloc(size_t num, size_t size);
extern void* lrealloc(void* mem, size_t size);
extern void* lrecalloc(void* mem, size_t num, size_t size);
#else
#warning "[llibs.h] -> [lmem.h]: Platform doesn't support memory allocation!"
#endif

#endif // __L_MEMORY_H__