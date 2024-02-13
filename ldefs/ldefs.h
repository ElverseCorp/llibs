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
#else
#error "[llibs.h] -> [ldefs.h]: Application signature is undefined! Llibs doesn't support this platform!"
#endif

#endif // __L_DEFS_H__