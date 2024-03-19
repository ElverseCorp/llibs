/* Include llibs.h header */ 
#include <llibs.h>
#include <str.h>
#include <string.h>

lsz lslen(lc* str) {
    lsz len = 0;
    while (*str != '\0') {
        if ((*str & 0xC0) != 0x80) {
            ++len;
        }
        ++str;
    }
    return len;
}

lsz lssize(lc* str) {
    lsz size = 0;
    while (*str != '\0') {
        ++size; ++str;
    }
    return size;
}

lsz lssizen(lc* str, lsz n) {
    lsz size = 0;
    while (*str != '\0' && n) {
        if ((*str & 0xC0) != 0x80) {
            --n;
        }
        ++str; ++size;
    }

    while (*str != '\0') {
        if ((*str & 0xC0) != 0x80) {
            break;
        }
        ++str; ++size;
    }
    return size;
}

lbool lscmp(lc* str1, lc* str2) {
    return !(lbool)(memcmp(str1, str2, lssize(str1)));
}

lbool lscpy(lc* str1, const lc* str2) {
    return !(lbool)(memcpy(str1, str2, lssize(str1)));
}
