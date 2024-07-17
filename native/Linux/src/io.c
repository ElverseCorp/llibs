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

const static lc* color_text_lookup[] = {
    [(int)(LC_COLOR_BLACK)] = X("\x1b[30m"), 
    [(int)(LC_COLOR_WHITE)] = X("\x1b[97m"),
    
    [(int)(LC_COLOR_RED)]           = X("\x1b[91m"), 
    [(int)(LC_COLOR_DARK_RED)]      = X("\x1b[31m"),
    [(int)(LC_COLOR_BLUE)]          = X("\x1b[94m"), 
    [(int)(LC_COLOR_DARK_BLUE)]     = X("\x1b[34m"),
    [(int)(LC_COLOR_GREEN)]         = X("\x1b[92m"), 
    [(int)(LC_COLOR_DARK_GREEN)]    = X("\x1b[32m"),

    [(int)(LC_COLOR_GRAY)]          = X("\x1b[90m"), 
    [(int)(LC_COLOR_DARK_GRAY)]     = X("\x1b[30m"),

    [(int)(LC_COLOR_MAGNETA)]       = X("\x1b[95m"), 
    [(int)(LC_COLOR_DARK_MAGNETA)]  = X("\x1b[35m"),

    [(int)(LC_COLOR_YELLOW)]        = X("\x1b[93m"), 
    [(int)(LC_COLOR_DARK_YELLOW)]   = X("\x1b[33m"),

    [(int)(LC_COLOR_CYAN)]      = X("\x1b[96m"), 
    [(int)(LC_COLOR_DARK_CYAN)] = X("\x1b[36m"),
};

const static lc* color_bg_lookup[] = {
    [(int)(LC_COLOR_BLACK)] = X("\x1b[40m"), 
    [(int)(LC_COLOR_WHITE)] = X("\x1b[107m"),
    
    [(int)(LC_COLOR_RED)]           = X("\x1b[101m"), 
    [(int)(LC_COLOR_DARK_RED)]      = X("\x1b[41m"),
    [(int)(LC_COLOR_BLUE)]          = X("\x1b[104m"), 
    [(int)(LC_COLOR_DARK_BLUE)]     = X("\x1b[44m"),
    [(int)(LC_COLOR_GREEN)]         = X("\x1b[102m"), 
    [(int)(LC_COLOR_DARK_GREEN)]    = X("\x1b[42m"),

    [(int)(LC_COLOR_GRAY)]          = X("\x1b[100m"), 
    [(int)(LC_COLOR_DARK_GRAY)]     = X("\x1b[40m"),

    [(int)(LC_COLOR_MAGNETA)]       = X("\x1b[105m"), 
    [(int)(LC_COLOR_DARK_MAGNETA)]  = X("\x1b[45m"),

    [(int)(LC_COLOR_YELLOW)]        = X("\x1b[103m"), 
    [(int)(LC_COLOR_DARK_YELLOW)]   = X("\x1b[43m"),

    [(int)(LC_COLOR_CYAN)]      = X("\x1b[106m"), 
    [(int)(LC_COLOR_DARK_CYAN)] = X("\x1b[46m"),
};

void lccol(lccolor text, lccolor bg) {
    lcout(color_bg_lookup[bg]);
    lcout(color_text_lookup[text]);
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
