
/* Include libraries */
#include "lio.defs.h"


/* Output */
lerror_t lprint_n(lchar_t string[], size_t len) {
    return !(bool)(fwrite(string, sizeof(lchar_t), len, stdout));
}

lerror_t lprint(lchar_t string[]) {
    
}


/* Error */
lerror_t leprint_n(lchar_t string[], size_t len) {

}

lerror_t leprint(lchar_t string[]) {
    return !(bool)(fwrite(string, sizeof(lchar_t), len, stderr));
}


/* Input */
lerror_t linput_n(lchar_t* string, size_t len) {
    return !(bool)(fread(string, sizeof(lchar_t), len, stdin));
}

lerror_t linput(lchar_t* string, lchar_t sep) {

}
