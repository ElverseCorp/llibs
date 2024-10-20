#include <stdlib.h>

#ifdef NULL
#   undef NULL
#endif

#include <mem.h>



memory_t allocate(size_t num, size_t sizeof_element){
    memory_t memory;
    memory.data = calloc(num, sizeof_element);
    memory.used = 0;

    if (memory.data == NULL) {
        memory.allocated = 0;
        return memory;
    } 
    memory.allocated = num * sizeof_element;
    return memory;
}

memory_t reallocate(memory_t* data, size_t num, size_t sizeof_element){
#ifdef _recalloc

#endif
}

memory_t reallocate_force(memory_t* data, size_t num, size_t sizeof_element){

}

void mem_copy(memory_t* mem1, memory_t mem2){

}
void mem_move(memory_t* mem1, memory_t* mem2){

}
ssize_t mem_compare(memory_t mem1, memory_t mem2){

}

void mem_copy_force(memory_t* mem1, memory_t mem2){

}
void mem_move_force(memory_t* mem1, memory_t* mem2){

}

void mem_optimize(memory_t* mem){

}

void mem_free(memory_t* mem) {

// Generic

void* g_calloc(size_t num, size_t sizeof_element){

}
void* g_recalloc(void* data, size_t num, size_t sizeof_element){

}
void g_free(void* data){

}
