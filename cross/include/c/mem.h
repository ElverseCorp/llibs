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

typedef struct {
    void* data;
    size_t allocated;
    size_t used;
} memory_t;

/////////////////////////////////////////////
/////////// Function declaration //////////// 
///////////////////////////////////////////// 

// Safe functions

extern memory_t allocate(size_t num, size_t sizeof_element);
extern memory_t reallocate(memory_t* data, size_t num, size_t sizeof_element);
extern memory_t reallocate_force(memory_t* data, size_t num, size_t sizeof_element);

extern void mem_copy(memory_t* mem1, memory_t mem2);
extern void mem_set(memory_t* mem1, memory_t mem2);
extern void mem_move(memory_t* mem1, memory_t* mem2);
extern ssize_t mem_compare(memory_t mem1, memory_t mem2);

extern void mem_copy_force(memory_t* mem1, memory_t mem2);
extern void mem_move_force(memory_t* mem1, memory_t* mem2);

extern void mem_optimize(memory_t* mem);

extern void mem_free(memory_t* mem);

// Generic functions

extern void* g_calloc(size_t num, size_t sizeof_element);
extern void* g_recalloc(void* data, size_t num, size_t sizeof_element);
extern void g_free(void* data);



#endif // ELLIPSE_2_STR_H_
