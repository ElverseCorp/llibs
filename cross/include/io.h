#ifndef LLIBS_FRAMEWORK_IO_H_
#define LLIBS_FRAMEWORK_IO_H_

/**************************************************************************//**
 * @file     string.h
 * @brief    Project L - Llibs, cross-platform framework / string.h
 * @version  V0.2.0
 * @date     5. Jan 2024
 ******************************************************************************/

/* Llibs */
#include "llibs.h"

/* Standard functions */

/* Console */

/** 
 * @brief Prints a line in the UTF-8 encoding console 
 * 
 * The line should end '\0' for correct processing. 
 * 
 * @param[in] str string address 
*/
extern void cout(lc str[]);

/** 
 * @brief Prints len characters in the console in the coding UTF-8.
 * 
 * 
 * @param[in] str string address
 * @param[in] len number of symbols
*/
extern void coutn(lc str[], lsz len);

/** 
 * @brief Prints a line in the UTF-8 encoding console error stream
 * 
 * The line should end '\0' for correct processing. 
 * 
 * @param[in] str string address 
*/
extern void cerr(lc str[]);

/** 
 * @brief Prints len characters in the console error stream in the coding UTF-8.
 * 
 * 
 * @param[in] str string address
 * @param[in] len number of symbols
*/
extern void cerrn(lc str[], lsz len);

/** 
 * @brief Receive string in UTF-8 from console to the feet of sep
 * 
 * 
 * @param[in] dest destination address
 * @param[in] sep separator
*/
extern void cin(lc* dest, lc sep);

/** 
 * @brief Receive len symbols from console in UTF-8
 * 
 * 
 * @param[in] dest destination address
 * @param[in] sep separator
*/
extern void cinn(lc* dest, lsz len);


/* Files */

#endif // LLIBS_FRAMEWORK_IO_H_