#include <c/str.h>
#include <c/types.h>

/**
 * @brief To find the length of a
 * standard string, where each 
 * character cannot occupy more 
 * than one byte. (ASCII or similar)
 * 
 * @param[in] string constant string pointer.
 * @return number of symbols. (bytes)
 * @warning Use `s_utf8_len()` for UTF-8 encoded 
 * strings!
 */
len_t slen(cstr_t string[static 1]) {
    len_t length = 0;
    while ((*string) != '\0') {
        ++length; 
        ++string;
    }
    return length;
}

/**
 * @brief To find the length of a 
 * string in UTF-8 encoding.
 * 
 * @param[in] string UTF-8 constant string pointer.
 * @return number of symbols.
 */
len_t s_utf8_len(cstr_utf8_t string) {
    len_t length = 0;
    while ((*string) != '\0') {
        if (((*string) & 0xC0) != 0x80)
            ++length;
        ++string;
    }
    return length;
}

// unsafe 
static bool _is_ascii_utf8(void* data) {

}

static bool _is_utf16le(void* data) {

}

static bool _is_utf16be(void* data) {

}

static bool _is_utf32le(void* data) {

}

static bool _is_utf32be(void* data) {

}

xstr_encode_t xstr_get_encode(void* data) {
    if (data == NULL) {
        return XSTR_ENCODE_UNKNOWN;
    }
    if ()
}

xstr_t xstr_create(void* data, xstr_encode_t encode, bool is_mutable) {
    if (data == NULL) {

    }
}

len_t xstr_is_mutable(xstr_t string) {
    return (bool)(string.meta.is_mutable);
}

len_t xstr_len(xstr_t string) {
    if (string.content.data == NULL) {
        return 0;
    }
    return string.content.length;
}

len_t xstr_size(xstr_t string) {
    if (string.content.data == NULL) {
        return 0;
    }
    return string.content.size;
}
