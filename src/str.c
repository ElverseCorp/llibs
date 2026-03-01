
#include <stdlib.h>
#include <string.h>
#include <llibs/str.h>
#include <llibs/errors.h>
#include <llibs/memory.h>


lstr lstr_create(llen capacity, lcstr initial_str, lerr* error_status){
    if (!capacity) {
        (*error_status) = LERR_INVALID_ARG;
        return (lstr){.length = 0, .ptr = NULL};
    }
    
    char* buff = lalloc(capacity, sizeof(char));
    if (!buff) {
        (*error_status) = LERR_OUT_OF_MEMORY;
        return (lstr){.length = 0, .ptr = NULL};
    }

    llen final_len = 0;
    if (initial_str) {
        final_len = strlen(initial_str);
        if (final_len >= capacity) {
            final_len = capacity - 1;
        }
        memcpy(buff, initial_str, final_len);
    }
    buff[final_len] = '\0';

    (*error_status) = LERR_OK;
    return (lstr){.length = final_len, .ptr = buff};

}

lerr lstr_destroy(lstr* string){
    if (!string) return LERR_INVALID_ARG;
    string->length = 0;
    lfree(string->ptr);
    string->ptr = NULL;
    return LERR_OK;
}

lerr lstr_append(lstr* string, llen new_length){
    if (!string || !string->ptr || !new_length) return LERR_INVALID_ARG;
    if (new_length <= string->length) return LERR_OK;
    if (LREALLOC(string->ptr, new_length+1, 1) != LERR_OK)
        return LERR_OUT_OF_MEMORY;
    string->length = new_length;
    return LERR_OK;
}

lerr lstr_shrink(lstr* string, llen new_length){
    if (!string || !string->ptr || !new_length) return LERR_INVALID_ARG;
    if (new_length > string->length) return LERR_OK;
    if (LREALLOC(string->ptr, new_length+1, 1) != LERR_OK)
        return LERR_OUT_OF_MEMORY;
    string->length = new_length;
    return LERR_OK;
}

lerr lstr_cstr_set(lstr* string, lcstr new_string){
    if (!string || !string->ptr || !new_string) return LERR_INVALID_ARG;
    llen new_str_len = strlen(new_string);
    if (new_str_len > string->length) {
        if (LREALLOC(string->ptr, new_str_len+1, 1) != LERR_OK)
            return LERR_OUT_OF_MEMORY;
    }
    memcpy(string->ptr, new_string, new_str_len + 1);
    string->length = new_str_len;
    return LERR_OK;
}

inline lcstr lstr_cstr_get(lstr string){
    return (lcstr)string.ptr;
}
