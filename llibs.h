#ifndef __L_LIBS_H__
#define __L_LIBS_H__

/**************************************************************************//**
 * @file     llibs.h
 * @brief    Project L - Llibs framework for Lena programming language
 * @version  V0.0.2
 * @date     5. Jan 2024
 ******************************************************************************/

/*
 * The llibs framework is part of Project L and is freely available and distributable under its terms.
 * For more details, visit: https://github.com/robotsvision/llibs
 *
 * This framework is utilized within the internal mechanisms of the Lena programming language with some modifications.
 * However, due to the specific nature of the language version, they are not compatible.
 *
 * Supported language versions: C11 and later; usage in C++ is also possible.
 */

#ifdef __cplusplus
extern "C" {
#endif

/* LDEFS */
#include "ldefs/ldefs.h"

/* LTYPES */
#include "ltypes/ltypes.h"

/* LDTYTPES */
#include "ldtypes/ldtypes.h"

/* LFILES */
#include "lfiles/lfiles.h"

/* LTUPLES */
#include "ltuples/ltuples.h"

#ifdef __cplusplus
}
#endif

#endif // __L_LIBS_H__