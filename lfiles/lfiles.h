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
#include "../ltypes/ltypes.h"

/* Platform */
#include "platforms/platform.h"

/* Standard functions */

#ifdef __LFILES_SPT__

extern lerror_t lopen(lfile_t* file, lchar_t* name); 
extern lerror_t lclose(lfile_t* file); 

#else // If lfiles lib isn't supported
#warning "[llibs.h] -> [lfiles.h]: Functions aren't supported! Check your platform."
#endif 

/* To get data pointer use (lfile_t) file.data */

#endif // __L_FILES_H__