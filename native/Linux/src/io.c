/* Include llibs.h header */
#include <llibs.h>
#include <stdio.h>

/* Console */

void lcout(lc str[]) {
    fwrite(str, sizeof(lc), lssize(str), stdout);
}


void lcoutn(lc str[], lsz len) {
    fwrite(str, sizeof(lc), lssizen(str, len), stdout);
}


void lcerr(lc str[]) {

}


void lcerrn(lc str[], lsz len) {

}

void lcin(lc* dest, lc sep) {

}


void lcinn(lc* dest, lsz len) {

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
