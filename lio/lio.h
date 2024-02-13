#ifndef __L_INPUT_OUTPUT_H__
#define __L_INPUT_OUTPUT_H__

/**************************************************************************//**
 * @file     lio.h
 * @brief    Project L - Cross-platform i/o library (for Lena lang)
 * @version  V0.0.1
 * @date     11. Feb 2023
 ******************************************************************************/

/* Libraries */
#include "../ltypes/ltypes.h"

/* Include platform selector */
#include "platforms/platform.h"

#ifdef __LIO_SPT__

/* Output */
extern lerror_t lprint_n(lchar_t string[], size_t len);
extern lerror_t lprint(lchar_t string[]);

/* Error */
extern lerror_t leprint_n(lchar_t string[], size_t len);
extern lerror_t leprint(lchar_t string[]);

/* Input */
extern lerror_t linput_n(lchar_t string[], size_t len);
extern lerror_t linput(lchar_t string[], lchar_t sep);

#else
#warning "[llibs.h] -> [lio.h]: Platform doesn't support standard input/output!"
#endif

#endif // __L_INPUT_OUTPUT_H__