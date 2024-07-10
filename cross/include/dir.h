#ifndef LLIBS_FRAMEWORK_DIR_H_
#define LLIBS_FRAMEWORK_DIR_H_

/**************************************************************************//**
 * @file     file.h
 * @brief    Project L - Llibs, cross-platform framework / file.h
 * @version  V0.1.0
 * @date     17. Mar 2024
 * @author   Matvey Rybalkin
******************************************************************************/

/* Must be included in llibs.h */

/** 
 * @brief Create directory based on the path.
 * 
 * @param[in] dirname name of directory in UTF-8 encode
*/
extern lerr ldirmk(const lc dirname[]);

/** 
 * @brief Remove directory based on the path.
 * 
 * @param[in] dirname name of directory in UTF-8 encode
*/
extern lerr ldirrm(const lc dirname[]);

#endif // LLIBS_FRAMEWORK_DIR_H_