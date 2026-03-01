
#include <stdlib.h>
#include <llibs/memory.h>

static llen _active_ptrs = 0;

void* lalloc(llen num, lsize size_of_element) {
    if (!num || !size_of_element) return NULL;
    void* buff = calloc(num, size_of_element);
    if (buff)
        _active_ptrs++;
    return buff;
}

lerr lrealloc(void** ptr, llen num, lsize size_of_element) {
    if (!*ptr || !num || !size_of_element) return LERR_INVALID_ARG;
    void* buff = realloc(*ptr, num * size_of_element);
    if (!buff)
        return LERR_OUT_OF_MEMORY;
    (*ptr) = buff;
    return LERR_OK;
}

void lfree(void* ptr) {
    if (ptr) _active_ptrs--; 
    free(ptr);
}

llen lmem_allocated(void) {
    return _active_ptrs;
}

