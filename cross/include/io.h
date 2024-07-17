#ifndef LLIBS_FRAMEWORK_IO_H_
#define LLIBS_FRAMEWORK_IO_H_

/**************************************************************************//**
 * @file     string.h
 * @brief    Project L - Llibs, cross-platform framework / string.h
 * @version  V0.2.0
 * @date     5. Jan 2024
 * @author   Matvey Rybalkin
******************************************************************************/

/* Must be included in llibs.h */

/* Standard functions */

/* Console */

/** 
 * @brief Initializes console input/output
 * 
 * This function was created for specific platform like Windows
 * 
 * @return status L_OK or L_ERROR
*/
extern lerr lcio_init(void);

/** 
 * @brief Prints a line in the UTF-8 encoding console 
 * 
 * The line should end '\0' for correct processing. 
 * 
 * @param[in] str string address 
*/
extern void lcout(const lc str[]);

/** 
 * @brief Prints len characters in the console in the coding UTF-8.
 * 
 * 
 * @param[in] str string address
 * @param[in] len number of symbols
*/
extern void lcoutn(const lc str[], lsz len);

/** 
 * @brief Prints a line in the UTF-8 encoding console error stream
 * 
 * The line should end '\0' for correct processing. 
 * 
 * @param[in] str string address 
*/
extern void lcerr(const lc str[]);

/** 
 * @brief Prints len characters in the console error stream in the coding UTF-8.
 * 
 * 
 * @param[in] str string address
 * @param[in] len number of symbols
*/
extern void lcerrn(const lc str[], lsz len);

/** 
 * @brief Receive string in UTF-8 from console to the feet of sep
 * 
 * 
 * @param[in] dest destination address
 * @param[in] sep separator
*/
extern void lcin(lc* dest, const lc sep);

/** 
 * @brief Receive len symbols from console in UTF-8
 * 
 * 
 * @param[in] dest destination address
 * @param[in] sep separator
*/
extern void lcinn(lc* dest, lsz len);

/** 
 * @brief Color type.
*/
typedef enum {
    LC_COLOR_BLACK          = 0,
    LC_COLOR_WHITE          = 1,
    LC_COLOR_RED            = 2,
    LC_COLOR_DARK_RED       = 3,
    LC_COLOR_GREEN          = 4,
    LC_COLOR_DARK_GREEN     = 5,
    LC_COLOR_BLUE           = 6,
    LC_COLOR_DARK_BLUE      = 7,
    LC_COLOR_GRAY           = 8,
    LC_COLOR_DARK_GRAY      = 9,
    LC_COLOR_MAGNETA        = 10,
    LC_COLOR_DARK_MAGNETA   = 11,
    LC_COLOR_YELLOW         = 12,
    LC_COLOR_DARK_YELLOW    = 13,
    LC_COLOR_CYAN           = 14,
    LC_COLOR_DARK_CYAN      = 15,
} lccolor;

/** 
 * @brief Change console color.
 * 
 * @param[in] text text color
 * @param[in] bg background color
*/
extern void lccol(lccolor text, lccolor bg);


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
extern lerr lfopen(const lc filename[], lfile* file);

/** 
 * @brief Gets the pointer to file data
 *
 * @param[in] pointer target pointer
 * @param[in] file file structure pointer
*/
extern lerr lfget(lc* pointer, lfile* file);

/** 
 * @brief Closes file and clear file structure
 *
 * @param[out] file file structure pointer
*/
extern lerr lfclose(lfile* file);

/** 
 * @brief Creates file and stores its data in file
 * 
 * 
 * @param[in] filename name of file in UTF-8 encode
 * @param[out] file file structure pointer
*/
// extern lerr lfcreate(const lc filename[], lfile* file);

#endif // LLIBS_FRAMEWORK_IO_H_