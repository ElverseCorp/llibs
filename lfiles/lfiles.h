#ifndef __L_FILES_H__
#define __L_FILES_H__

/**************************************************************************//**
 * @file     lfiles.h
 * @brief    Project L - Cross-platform files library (for Lena lang)
 * @version  V0.0.3
 * @date     31. Dec 2023
 ******************************************************************************/

/* Standard libraries */
#include <stdlib.h>
#include <stdint.h>

/* Llibs */
#include "ltypes.h"

/* Platform */
#include "platforms/platform.h"

/* Standard functions */

extern lerrot_t llibs_open(lfile_t lchar_t name); 

extern lerrot_t llibs_open(lchar_t name); 

extern lerrot_t llibs_close(lchar_t name); 

#endif // __L_FILES_H__