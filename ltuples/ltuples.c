
/* Tuples */
#include "ltuples.h"

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
ldt_error_t get_tuple_error(ldt tuple) {
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