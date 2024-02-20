#ifndef __L_CHAR_H__
#define __L_CHAR_H__

/**************************************************************************//**
 * @file     lchar.h
 * @brief    Project L - Cross-platform chars library (for Lena lang)
 * @version  V0.2.0
 * @date     4. Jan 2024
 ******************************************************************************/

/* Standard libraries */
#include <stdlib.h>
#include <stdlib.h>
#include <stdint.h>

/* Types for different UTF */
typedef uint32_t lchar32_t;
typedef uint16_t lchar16_t;
typedef uint8_t  lchar8_t;

/* General type */
typedef lchar8_t lchar_t;

/* --- Native type --- */

/* Include platform selector */
#include "platforms/platform.h"

export size_t llen(lnchar_t string[]);

#endif // __L_CHAR_H__