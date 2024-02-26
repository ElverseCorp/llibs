#ifndef LLIBS_FRAMEWORK_IO_H_
#define LLIBS_FRAMEWORK_IO_H_

/**************************************************************************//**
 * @file     string.h
 * @brief    Project L - Llibs, cross-platform framework / string.h
 * @version  V0.2.0
 * @date     5. Jan 2024
 * @author   Matvey Rybalkin
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
extern void lcout(lc str[]);

/** 
 * @brief Prints len characters in the console in the coding UTF-8.
 * 
 * 
 * @param[in] str string address
 * @param[in] len number of symbols
*/
extern void lcoutn(lc str[], lsz len);

/** 
 * @brief Prints a line in the UTF-8 encoding console error stream
 * 
 * The line should end '\0' for correct processing. 
 * 
 * @param[in] str string address 
*/
extern void lcerr(lc str[]);

/** 
 * @brief Prints len characters in the console error stream in the coding UTF-8.
 * 
 * 
 * @param[in] str string address
 * @param[in] len number of symbols
*/
extern void lcerrn(lc str[], lsz len);

/** 
 * @brief Receive string in UTF-8 from console to the feet of sep
 * 
 * 
 * @param[in] dest destination address
 * @param[in] sep separator
*/
extern void lcin(lc* dest, lc sep);

/** 
 * @brief Receive len symbols from console in UTF-8
 * 
 * 
 * @param[in] dest destination address
 * @param[in] sep separator
*/
extern void lcinn(lc* dest, lsz len);


/* Files */

/** 
 * @brief Native structure for file data
 */
typedef struct lfile lfile;

/** 
 * @brief Opens a file by name and stores its data in file
 * 
 * 
 * @param[in] filename name of file in UTF-8 encode
 * @param[out] file file structure pointer
*/
extern lerr lfopen(lc filename[], lfile* file);

/** 
 * @brief Gets the pointer to file data
 *
 * @param[in] file file structure pointer
*/
extern lerr lfget(lfile* file);

/** 
 * @brief Closes file and clear file structure
 *
 * @param[out] file file structure pointer
*/
extern lerr lfclose(lfile* file);

#endif // LLIBS_FRAMEWORK_IO_H_