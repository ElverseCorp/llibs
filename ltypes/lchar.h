#ifndef __L_CHAR_H__
#define __L_CHAR_H__

/**************************************************************************//**
 * @file     lchar.h
 * @brief    Project L - Cross-platform chars library (for Lena lang)
 * @version  V0.2.0
 * @date     4. Jan 2024
 ******************************************************************************/

/* Standard libraries */
#include <stdint.h>


/* Types for different UTF */
typedef uint32_t lchar32_t;
typedef uint16_t lchar16_t;
typedef uint8_t  lchar8_t;

/* Native type */

/* For Windows */
#ifdef _WIN32
#include <wchar.h>
typedef wchar_t lnchar_t;
#else /* LINUX */
typedef char16_t lnchar_t;
#endif

#endif // __L_CHAR_H__