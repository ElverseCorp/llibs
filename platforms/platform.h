#ifndef __L_PLATFORM_SELECTOR_H__
#define __L_PLATFORM_SELECTOR_H__

/**************************************************************************//**
 * @file     platform.h
 * @brief    Project L - Cross-platform platforms library
 * @version  V0.0.1
 * @date     13. Feb 2023
 ******************************************************************************/

/**
 * __L_WINDOWS__ and other macroses were created specific for Llibs framework.
 * Read official documentation for more information.
*/

/* Select current platform */
#if defined(__L_WINDOWS__)
#include "Windows/lwindows.h"
#elif defined(__L_LINUX__)
#include "Linux/llinux.h"
#elif defined(__L_LOTUS__)
#include "Lotus/llotus.h"
#endif // defined(__L_RAPIRA__) 

#endif // __L_PLATFORM_SELECTOR_H__