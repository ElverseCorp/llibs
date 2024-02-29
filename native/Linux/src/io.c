/* Include llibs.h header */
#include <llibs.h>
#include <stdio.h>

/* Console */

lerr lcio_init(void) {
    // POSIX doesn't need initialization
    return L_OK;
}


void lcout(lc str[]) {
    fwrite(str, sizeof(lc), lssize(str), stdout);
}


void lcoutn(lc str[], lsz len) {
    fwrite(str, sizeof(lc), lssizen(str, len), stdout);
}


void lcerr(lc str[]) {
    fwrite(str, sizeof(lc), lssize(str), stderr);
}


void lcerrn(lc str[], lsz len) {
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

lerr lfopen(lc filename[], lfile* file) {

}

lerr lfget(lfile* file) {

}


lerr lfclose(lfile* file) {
    
}
