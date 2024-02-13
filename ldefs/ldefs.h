#ifndef __L_DEFS_H__
#define __L_DEFS_H__

/**************************************************************************//**
 * @file     ldefs.h
 * @brief    Project L - Cross-platform defs library (for Lena lang)
 * @version  V0.0.1
 * @date     10. Feb 2024
 ******************************************************************************/

/* Include platform selector */
#include "platforms/platform.h"

#ifdef __LDEFS_SPT__
#define LMAIN _LMAIN 
/* _LMAIN is defined in native library */

/* Appilication exit */

/* Standard libraries */
#include <stdint.h>

/* Type */
typedef uint8_t lexit_code_t;

enum lexit_codes {
    LENA_EXIT_SUCCESS = 0x00,
    LENA_EXIT_FAILURE = 0x01,
    // ... other codes (max = 0xFF/255)
};

extern void lexit(lexit_code_t code);

#else
#error "[llibs.h] -> [ldefs.h]: Application signature is undefined! Llibs doesn't support this platform!"
#endif

#endif // __L_DEFS_H__