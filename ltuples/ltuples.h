#ifndef __L_TUPLES_H__
#define __L_TUPLES_H__

/**************************************************************************//**
 * @file     ltuples.h
 * @brief    Project L - Cross-platform tuples library (for Lena lang)
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

/* Get tuple error function */
extern ldt_error_t get_tuple_error(ldt tuple);

/* To tuple constructor */
extern ldt _to_tuple(ldt_type map[], size_t n, ...);

/* Free memory after usage */
extern void free_tuple(ldt* tuple);

/* Macros */
#ifdef __L_TUPLES_U_H__
#define to_tuple(map, ...) _to_tuple(map, LDT_N(__VA_ARGS__), __VA_ARGS__)
#else
#define to_tuple(map, n, ...) _to_tuple(map, n, __VA_ARGS__)
#endif

#endif // __L_TUPLES_H__