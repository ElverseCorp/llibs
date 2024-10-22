#ifndef ELLIPSE_2_ADV_STACK_H_
#define ELLIPSE_2_ADV_STACK_H_

/**************************************************************************//**
 * @file     stack.h
 * @brief    Ellipse advanced / stack for C.
 * @version  V0.3.0
 * @date     22. Oct 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include <c/types.h>

/////////////////////////////////////////////
////////////// Type definition ////////////// 
///////////////////////////////////////////// 

#define STACK_INITIAL_ALLOCATION_N 4096U

typedef union {
    // Pointer
    void* ptr;

    // Integer
    i8_t i8;
    u8_t u8;
    i16_t i16;
    u16_t u16;
    i32_t i32;
    u32_t u32;
    i64_t i64;
    u64_t u64;
#ifdef __SIZEOF_INT128__
    i128_t i128;
    u128_t u128;
#endif

    // Floats
    f32_t f32;
    f64_t f64;
#ifdef __SIZEOF_FLOAT128__
    f128_t f128;
#endif

    // Max Types
    imax_t imax;
    umax_t umax;
    fmax_t fmax;
} stack_value_t;

typedef struct {
    stack_value_t value;
    type_t type;
} stack_element_t;

typedef struct {
    stack_element_t* elements;
    struct {
        size_t capacity;
        size_t top_ptr;
        len_t count;
    } meta;
} stack_t;


/////////////////////////////////////////////
/////////// Function declaration //////////// 
///////////////////////////////////////////// 

stack_t stack_create(void);
void stack_destroy(stack_t* stack);

void stack_push(stack_t* stack, stack_element_t element);
stack_element_t stack_pop(stack_t* stack);

void stack_is_empty(stack_t stack);
void stack_optimize(stack_t* stack);

size_t stack_get_size(stack_t* stack);
size_t stack_get_count(stack_t* stack);

#endif // ELLIPSE_2_ADV_STACK_H_