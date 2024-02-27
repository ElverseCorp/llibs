#ifndef LLIBS_FRAMEWORK_THREAD_H_
#define LLIBS_FRAMEWORK_THREAD_H_

/**************************************************************************//**
 * @file     string.h
 * @brief    Project L - Llibs, cross-platform framework / string.h
 * @version  V0.2.0
 * @date     5. Jan 2024
 * @author   Matvey Rybalkin
******************************************************************************/

/* Must be included in llibs.h */

/* Standard types */

/** 
 * @brief Native data type for callback function
 */
typedef struct lthread_func lthread_func;

/** 
 * @brief Native structure for thread data
 */
typedef struct lthread lthread;

/* Standard functions */

/** 
 * @brief Creates new thread, based on callback function
 * 
 * @param[out] thread thread data pointer
 * @param[in] func callback function pointer
 * @return Error status (OK/ERROR)
*/
extern lerr lthread_new(lthread* thread, lthread_func* func);

/** 
 * @brief Join thread, wait for the end
 * 
 * @param[out] thread thread data pointer
*/
extern void lthread_join(lthread* thread);

#endif // LLIBS_FRAMEWORK_THREAD_H_