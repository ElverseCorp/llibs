#ifndef __L_DTYPES_X64_H__
#define __L_DTYPES_X64_H__

/**************************************************************************//**
 * @file     ldtypes_x64.h
 * @brief    Project L - Cross-platform dynamic type library (for Lina/Lena/Lisa langs)
 * @version  V0.0.1
 * @date     10. Jan 2024
 ******************************************************************************/

/* EXPERIMENT */

#ifndef __L_TYPES_H__
#error [ldtypes_x64.h]: ltypes.h was not included.
#else

/* Standard C libs */

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef int64_t lx64;

typedef struct {
    void* data;
    size_t size;
    size_t len;
} ld64;

ld64 to_str64(size_t len) {
    /* x64 cast */
    size_t size = (sizeof(lchar_t) * len) + (sizeof(lx64) - ((sizeof(lchar_t) * len) % 8));
    lchar_t* buffer = malloc(size);
    if (buffer == NULL) {
        return (ld64){NULL, 0};
    }
    return (ld64){buffer, size, len};
}

#include <stdio.h>

void str64cpy(ld64 dest, const lchar_t* src, size_t len) {
    len /= sizeof(lx64);
    size_t shift = 0;
    printf("%d", len);
    for (uint64_t i = 0; i < len; ++i) {
        (*(lx64*)(dest.data + shift)) = (*(lx64*)(src + shift));
        shift += sizeof(lx64);
    }
}


#endif // __L_TYPES_H__
#endif // __L_DTYPES_X64_H__