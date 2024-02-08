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

/* Functions */

void* lmalloc(size_t size) {
    return malloc(size);
}

void* lcalloc(size_t num, size_t size) {
    return calloc(num, size);
}

void* lrealloc(void* mem, size_t size) {
    return realloc(mem, size);
}

void* lrecalloc(void* mem, size_t num, size_t size) {
    return _recalloc(mem, num, size);
}

#endif // __L_MEMORY_H__