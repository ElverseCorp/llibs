#include <llibs.h>
#include <windows.h>

/* ----------- Converter ----------- */

/* Macro */
#define wchar_get_len(wstr)\
WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL)

#define wchar_to_lc(wstr, lstr, len)\
WideCharToMultiByte(CP_UTF8, 0, wstr, -1, lstr, len, NULL, NULL)

lc* convert_wchar_to_utf8(const wchar_t* wstr) {
    li32 utf8_len = wchar_get_len(wstr);
    if (utf8_len == 0) {
        return NULL; // Invalid string
    }
    lc* utf8_str = malloc(utf8_len);
    if (utf8_str == NULL) {
        return NULL; // Memory allocation error
    }
    if (!wchar_to_lc(wstr, (char*)utf8_str, utf8_len)) {
        free(utf8_str);
        return NULL; // Convertation error
    }
    return (lc*)(utf8_str);
}


int wmain(int argc, wchar_t* argv[]) {
    lc** argv_utf8 = malloc(argc * sizeof(lc*));
    if (argv_utf8 == NULL) {
        return EXIT_FAILURE;
    }
    range(i, 0, argc) {
        argv_utf8[i] = convert_wchar_to_utf8(argv[i]);
    }
    lm state = lmain(argc, argv_utf8);
    free(argv_utf8);
    return state;
}