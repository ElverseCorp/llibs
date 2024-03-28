/* Include llibs.h header */ 
#include <llibs.h>
#include <stdlib.h>

void* lmalloc(lsz size) {
    return malloc(size);
}

void* lcalloc(lsz num, lsz size) {
    return calloc(num, size);
}

void* lrealloc(void* mem, lsz size) {
    return realloc(mem, size);
}