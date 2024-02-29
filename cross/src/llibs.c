/* Include llibs.h header */ 
#include <llibs.h>

lerr llibs_init(void) {
    lerr state;
    state = lcio_init();
    if (state != L_OK) {
        return state;
    }
    return L_OK;
}