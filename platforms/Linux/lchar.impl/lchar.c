
/* Include libraries */
#include "lchar.defs.h"

/* Standard libraries */
#include <string.h>

#ifdef __L_CHAR_LINUX_H__

size_t llen(lnchar_t string[]) {
    return strlen(string);
}

#else
#error "[lchar.c][Linux]: Invalid data type lnchar_t"
#endif