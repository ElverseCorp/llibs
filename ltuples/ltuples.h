#ifndef __L_TUPLES_H__
#define __L_TUPLES_H__

/**************************************************************************//**
 * @file     ltuples.h
 * @brief    Project L - Cross-platform tuples library (for Lina/Lena/Lisa langs)
 * @version  V0.0.1
 * @date     4. Jan 2024
 ******************************************************************************/

/* EXPERIMENT */

/* Standard C libs */

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>

/* Tuples */
#include "ltuples_util.h"

typedef uint8_t ldt_type;
typedef const uint8_t ldt_type_size;

typedef enum {
    TYPE_CHAR   = 0,
    TYPE_I8     = 1,
    TYPE_U8     = 2,
    TYPE_I16    = 3,
    TYPE_U16    = 4,
    TYPE_I32    = 5,
    TYPE_U32    = 6,
    TYPE_I64    = 7,
    TYPE_U64    = 8,
    TYPE_F      = 9,
    TYPE_D      = 10,
    TYPE_LD     = 11,

    // TYPE_C_POINTER = 12,    // char* str;
} ldt_types;

ldt_type_size ldt_type_sizes[] = {
    sizeof(char),
    sizeof(int8_t),
    sizeof(uint8_t),
    sizeof(int16_t),
    sizeof(uint16_t),
    sizeof(int32_t),
    sizeof(uint32_t),
    sizeof(int64_t),
    sizeof(uint64_t),
    sizeof(float),
    sizeof(double),
    sizeof(long double)
};

#define LDT_MAP(...) (ldt_type[]){ __VA_ARGS__ }
#define LDT_VAL(...)  __VA_ARGS__ 

typedef struct {
    void* data;     // data pointer
    size_t size;    // data size (in bytes)
    ldt_type* map;  // data map (array of int)
    size_t num;     // number of elements
} ldt;

/** Error codes:
 * data | map = NULL | NULL -> NOT DEFINED
 * data | map = NULL | !NULL -> ARG ERROR
 * data | map = !NULL | NULL -> DATA ERROR
 * data | map = !NULL | !NULL -> SUCCESS
*/

typedef enum {
    LDT_SUCCESS             = 0b00000011,
    LDT_ERROR_NOT_DEFINED   = 0b00000000,
    LDT_ERROR_ARG           = 0b00000001,
    LDT_ERROR_DATA          = 0b00000010,  
} ldt_error_t;

/**
  * Gets the error code for the ldt structure.
  *
  * @param tuple The ldt structure for which to get the error code.
  *
  * @return The error code represented as ldt_error_t.
  * Returns LDT_SUCCESS (0b00000011) if there are no errors.
  * Returns LDT_ERROR_NOT_DEFINED (0b00000000) if the structure is not defined (both data and map are NULL).
  * Returns LDT_ERROR_ARG (0b00000001) if the error is related to the arguments (the data field is NULL).
  * Returns LDT_ERROR_DATA (0b00000010) if the error is data related (the map field is NULL).
  */
ldt_error_t get_tuple_error(ldt tuple){
    uint8_t er_code = 0b00000000;
    er_code |= (((bool)(tuple.data) << 0) | ((bool)(tuple.map) << 1));
    return (ldt_error_t)(er_code);
}

ldt _to_tuple(ldt_type map[], size_t n, ...){
    if (map == NULL) { return (ldt){NULL, 0, (ldt_type *)(void*)(1), 0};
        // -> DATA ERROR
    }
    size_t size = 0; // size in bytes
    for (size_t i = 0; i < n; ++i) { size += (uint8_t)(map[i]); }
    if(size == 0) { return (ldt){(void*)(1), 0, NULL, 0};
        // -> ARG ERROR
    }
    void* data = malloc(size);
    if (data == NULL) { return (ldt){NULL, 0, (ldt_type *)(void*)(1), 0};
        // -> DATA ERROR
    }

    size_t shift = 0;
    va_list args;
    va_start(args, n);
    for (size_t i = 0; i < n; ++i) {
        if (map[i] < TYPE_U32){
            (*(int *)(data + shift)) = va_arg(args, int);
            shift += (size_t)(ldt_type_sizes[map[i]]);
        } else {
            switch(map[i]){
            case TYPE_U32:
                (*(uint32_t *)(data + shift)) = va_arg(args, uint32_t);
                shift += (size_t)(ldt_type_sizes[map[i]]);
                break;
            case TYPE_I64:
                (*(int64_t *)(data + shift)) = va_arg(args, int64_t);
                shift += (size_t)(ldt_type_sizes[map[i]]);
                break;
            case TYPE_U64:
                (*(uint64_t *)(data + shift)) = va_arg(args, uint64_t);
                shift += (size_t)(ldt_type_sizes[map[i]]);
                break;
            case TYPE_F:
            case TYPE_D:
                (*(double *)(data + shift)) = va_arg(args, double);
                shift += (size_t)(ldt_type_sizes[map[i]]);
                break;
            case TYPE_LD:
                (*(long double *)(data + shift)) = va_arg(args, long double);
                shift += (size_t)(ldt_type_sizes[map[i]]);
                break;
            }
        }
    }
    va_end(args);

    return (ldt){data, size, map, n};
}

/* Redefinition */
#ifdef __L_TUPLES_U_H__
#define to_tuple(map, ...) _to_tuple(map, LDT_N(__VA_ARGS__), __VA_ARGS__)
#else
#define to_tuple(map, n, ...) _to_tuple(map, n, __VA_ARGS__)
#endif

/**
 * LDT_N(__VA_ARGS__) defined in ltuples_util.h
*/

void free_tuple(ldt* tuple){
    if (tuple != NULL){
        if (tuple->data != NULL) { free(tuple->data); }
        if (tuple->map != NULL) { free(tuple->map); }
        tuple->size = tuple->num = 0;
    }
}


/* Other functions */

/*
ldt_error_t push_tuple(ldt* tuple, int n, ...){
    if (tuple->data != NULL && tuple->map != NULL) {
        
    } else {
        return get_tuple_error(*tuple);
    }
}

void* pop_tuple(ldt* tuple, int n, ...){
    if (tuple->data != NULL && tuple->map != NULL) {
        
    } else {
        return get_tuple_error(*tuple);
    }
}
*/

#endif // __L_TUPLES_H__