/* Include llibs.h header */ 
#include <llibs.h>

lsz lslen(lc* str) {
    lc* str_ptr = str;
    lsz len = 0;
    while (*str_ptr != '\0') {
        if ((*str_ptr & 0xC0) != 0x80) {
            ++len;
        }
        ++str_ptr;
    }
    return len;
}
