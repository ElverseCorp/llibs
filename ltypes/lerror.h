#ifndef __L_TYPES_ERROR_H__
#define __L_TYPES_ERROR_H__

/**************************************************************************//**
 * @file     lerror.h
 * @brief    Project L - For error handling (from Lena language -> lena-i)
 * @version  V0.0.2
 * @date     6. Feb 2024
 ******************************************************************************/

/* Standard libraries */
#include <stdint.h>

/* Type */
typedef uint8_t lerror_t;

enum lerror_codes_t{
    LLIBS_OK    = 0x00,
    LLIBS_ERROR = 0x01,
    // ... other codes (max = 0xFF/255)
};

#endif // __L_TYPES_ERROR_H__