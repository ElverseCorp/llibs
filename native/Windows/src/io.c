/* Include llibs.h header */
#include <llibs.h>
#include <stdio.h>
#include <windows.h>

/* Console */

/* Static variables */

static HANDLE   hcout   = NULL,
                hcin    = NULL,
                hcerr    = NULL;

lerr lcio_init(void) {
    hcout = GetStdHandle(STD_OUTPUT_HANDLE);
    hcin = GetStdHandle(STD_INPUT_HANDLE);
    hcerr = GetStdHandle(STD_ERROR_HANDLE);
    
    if (hcout == INVALID_HANDLE_VALUE
    || hcin == INVALID_HANDLE_VALUE
    || hcerr == INVALID_HANDLE_VALUE) {
        return L_ERROR;
    }

    return L_OK;
}


void lcout(lc str[]) {
    WriteConsoleA(hcout, str, lssize(str), NULL, NULL);
}


void lcoutn(lc str[], lsz len) {
    WriteConsoleA(hcout, str, lssizen(str, len), NULL, NULL);
}


void lcerr(lc str[]) {
    WriteConsoleW(hcerr, str, lslen(str), NULL, NULL);
}


void lcerrn(lc str[], lsz len) {
    WriteConsoleW(hcerr, str, lssizen(str, len), NULL, NULL);
}

void lcin(lc* dest, lc sep) {
    lc sym;
    do {
        fread(&sym, sizeof(lc), 1, stdin); 
        (*dest) = sym;
        ++dest;
    } while (sym != sep);
}


void lcinn(lc* dest, lsz len) {
    ReadConsoleW(hcin, dest, len, NULL, NULL);
}


/* Files */

struct lfile {
    lc* data;   // data pointer
    li64 len;   // number of symbols
};

lerr lfopen(lc filename[], lfile* file) {

}

lerr lfget(lfile* file) {

}


lerr lfclose(lfile* file) {
    
}
