#ifndef __L_TYPES_ERROR_H__
#define __L_TYPES_ERROR_H__

/**************************************************************************//**
 * @file     lerror.h
 * @brief    Project L - For error handling (from Lena language -> lena-i)
 * @version  V0.0.1
 * @date     6. Feb 2024
 ******************************************************************************/

/* Standard libraries */
#include <stdint.h>

/* Type */
typedef uint8_t lerror_t;

typedef enum {
    LLIBS_OK = 1,
    LLIBS_ERROR = 0,
    // ... other codes
} lerror_codes_t;

#endif // __L_TYPES_ERROR_H__