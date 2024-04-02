/* Include llibs.h header */
#include <llibs.h>
#include <stdio.h>

/* Console */

lerr lcio_init(void) {
    // POSIX doesn't need initialization
    return L_OK;
}


void lcout(const lc str[]) {
    fwrite(str, sizeof(lc), lssize(str), stdout);
}


void lcoutn(const lc str[], lsz len) {
    fwrite(str, sizeof(lc), lssizen(str, len), stdout);
}


void lcerr(const lc str[]) {
    fwrite(str, sizeof(lc), lssize(str), stderr);
}


void lcerrn(const lc str[], lsz len) {
    fwrite(str, sizeof(lc), lssizen(str, len), stderr);
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
    fread(dest, sizeof(lc), lssizen(dest, len), stdin);
}


/* Files */

struct lfile {
    lc* data;   // data pointer
    li64 len;   // number of symbols
};

/* Not finished functions */

lerr lfopen(lc filename[], lfile* file) {
    return L_OK;
}

lerr lfget(lfile* file) {
    return L_OK;
}


lerr lfclose(lfile* file) {
    return L_OK;
}
