#ifndef LSTR_H_
#define LSTR_H_

#include "types.h"
#include "errors.h"

typedef struct {
    char* ptr;
    llen length;
} lstr;

extern lstr lstr_create(llen basic_length, lcstr initial_str, lerr* error_status);
extern lerr lstr_destroy(lstr* string);

extern lerr lstr_cstr_set(lstr* string, lcstr new_string);
extern lcstr lstr_cstr_get(lstr string);

extern lerr lstr_append(lstr* string, llen new_length);
extern lerr lstr_shrink(lstr* string, llen new_length);


#endif // LSTR_H_
