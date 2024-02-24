#ifndef LLIBS_FRAMEWORK_STRING_H_
#define LLIBS_FRAMEWORK_STRING_H_

/**************************************************************************//**
 * @file     string.h
 * @brief    Project L - Llibs, cross-platform framework / string.h
 * @version  V0.2.0
 * @date     5. Jan 2024
 ******************************************************************************/

/* Standard functions */

extern lbool lscmp(lc* str1, lc* str2);
extern lbool lscpy(lc* dest, const lc* src);
extern lbool lsset(lc* dest, lc data);
extern lbool lscat(lc* dest, const lc* src);

#endif // LLIBS_FRAMEWORK_STRING_H_