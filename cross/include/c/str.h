#ifndef ELLIPSE_2_STR_H_
#define ELLIPSE_2_STR_H_

/**************************************************************************//**
 * @file     types.h
 * @brief    Ellipse strings for C/C++.
 * @version  V0.3.0
 * @date     30. Sep 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include "types.h"

/////////////////////////////////////////////
///////////// Types definition ////////////// 
///////////////////////////////////////////// 

typedef const char_t* cstr_t;
typedef char_t* str_t;

typedef const u8_t* cstr_utf8_t;
typedef u8_t* str_utf8_t;

typedef enum {

    XSTR_ENCODE_ASCII,
    XSTR_ENCODE_UTF8,
    XSTR_ENCODE_UTF16LE,
    XSTR_ENCODE_UTF16BE,
    XSTR_ENCODE_UTF32LE,
    XSTR_ENCODE_UTF32BE,

    XSTR_ENCODE_UNKNOWN,
} xstr_encode_t;

typedef struct {

    struct {
        xstr_encode_t encode;
        bool is_mutable;
    } meta;

    struct {
        void* data;
        len_t length;
        size_t size;
    } content;

    struct {
        len_t (*str_len)(void*);
        size_t (*str_size)(void*);
        void* (*str_decode)(void*, size_t*);
    } functions;
    
} xstr_t;


/////////////////////////////////////////////
/////////// Function declaration //////////// 
///////////////////////////////////////////// 

// ASCII

extern len_t str_len(cstr_t string[static 1]);
extern ssize_t str_compare(cstr_t string1[static 1], cstr_t string2[static 1]);
extern str_t* str_concatenate(str_t dest, cstr_t src[static 1]);
extern void str_copy(str_t dest, cstr_t string1[static 1]);
extern void str_move(str_t dest, str_t src);
extern len_t str_find(cstr_t string[static 1], char_t character);
extern len_t str_substr(cstr_t string[static 1], cstr_t substring[static 1]);

// UTF-8

extern str_utf8_t str_utf8_decode(str_utf8_t string[static 1], size_t* pointer);

extern len_t str_utf8_len(cstr_t string[static 1]);
extern size_t str_utf8_size(cstr_t string[static 1]);
extern size_t str_utf8_size_n(cstr_t string[static 1], len_t n);

extern ssize_t str_utf8_compare(cstr_t string1[static 1], cstr_t string2[static 1]);
extern str_t* str_utf8_concatenate(str_t dest, cstr_t src[static 1]);
extern void str_utf8_copy(str_t dest, cstr_t string1[static 1]);
extern void str_utf8_move(str_t dest, str_t src);
extern len_t str_utf8_find(cstr_t string[static 1], char_t character);
extern len_t str_utf8_substr(cstr_t string[static 1], cstr_t substring[static 1])


// XSTR

#define XSTR_INITIAL_ALLOCATION 4096UL

extern xstr_t xstr_create(void* data, xstr_encode_t encode, bool is_mutable);
extern void xstr_delete(xstr_t* string);

extern bool xstr_is_mutable(xstr_t string);

extern len_t xstr_len(xstr_t string);
extern len_t xstr_size(xstr_t string);

extern len_t xstr_insert(xstr_t* dest, len_t n, xstr_t src);
extern len_t xstr_append(xstr_t* dest, xstr_t* src);
extern len_t xstr_concatinate(xstr_t* dest, void* data, xstr_encode_t encode);
extern len_t xstr_assign(xstr_t* dest, void* data, xstr_encode_t encode);
extern len_t xstr_find(xstr_t string, void* data);
extern len_t xstr_substring(xstr_t string, xstr_t substring);
extern ssize_t xstr_compare(xstr_t string1, xstr_t string2)

extern len_t xstr_optimize(xstr_t string);
extern xstr_encode_t xstr_get_encode(void* data);

#endif // ELLIPSE_2_STR_H_
