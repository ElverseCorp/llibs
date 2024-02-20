
/* Include libraries */
#include "lchar.defs.h"

/* Standard libraries */
#include <wchar.h>

#ifdef __L_CHAR_WINDOWS_H__ 

size_t llen(lnchar_t string[]) {
    return wcslen(string);
}

#else
#error "[lchar.c][Windows]: Invalid data type lnchar_t"
#endif