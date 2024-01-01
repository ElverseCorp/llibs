#ifndef __L_DTYPES_H__
#define __L_DTYPES_H__

/**************************************************************************//**
 * @file     ldtypes.h
 * @brief    Project L - Cross-platform dynamic type library (for Lina/Lena/Lisa langs)
 * @version  V0.0.1
 * @date     01. Jan 2024
 ******************************************************************************/

/* EXPERIMENT */

/* Standard C libs */

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    void* data;
    size_t size;
} ld;

/* General */

void ld_free(ld var){
    free(var.data);
    var.size = 0;
}

/* Only for standard types: char, short, int, int64 */

ld _to_type(size_t var_size){
    void* buffer = malloc(var_size);
    if (buffer == NULL){ return (ld){NULL, 0}; }
    return (ld){buffer, var_size};
}

#define to_type(type) _to_type(sizeof(type))

#define ld_write(var, type, value) (*(type*)(var.data)) = value
#define ld_read(var, type) (*(type*)(var.data))
#define ld_read_pointer(var, type) (type*)(var.data)

/* Strings */

ld to_string(size_t len, bool clear){
    void* buffer = clear ? calloc(len, sizeof(char)) : malloc(len);
    if (buffer == NULL){ return (ld){NULL, 0}; }
    return (ld){buffer, len};
}

bool ld_write_string(ld *var, char str[]){
    size_t len = strlen(str);
    if (var->size < len) {
        void* buffer = realloc(var->data, len);
        if (buffer == NULL){
            return 0;
        }
        var->data = buffer;
    }
    memcpy(var->data, str, len);
    return 1;
}

bool ld_extend_string(ld *var, size_t len){
    void* buffer = realloc(var->data, len);
    if (buffer == NULL){
        return 0;
    }
    var->data = buffer;
    var->size = len;
    return 1;
}

bool ld_fill_string(ld *var, char filler){
    memset(var->data, filler, var->size);
    (*(char*)(var->data + var->size)) = '\0';
    return 1;
}

#define ld_read_string(var) ld_read(var, char)

#endif // __L_DTYPES_H__