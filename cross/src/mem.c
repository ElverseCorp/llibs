/* Include llibs.h header */ 
#include <llibs.h>
/* for Allocation */
#include <stdlib.h>
/* for Memory managment */
#include <string.h>

/* General */

lerr lmemchk(void* pointer) {
    return (lerr)(pointer == NULL);
}

/* Allocation */

void* lmalloc(lsz size) {
    return malloc(size);
}

void* lcalloc(lsz num, lsz size) {
    return calloc(num, size);
}

void* lrealloc(void* mem, lsz size) {
    return realloc(mem, size);
}

/* Memory managment */

void* lmemcpy(void* restrict dest, void* restrict src, lsz size){
    return memcpy(dest, src, size);
}

int lmemcmp(const void* data1, const void* data2, lsz size){
    return memcmp(data1, data2, size);
}

void* lmemmove(void* dest, const void* src, lsz size){
    return memmove(dest, src, size);
}