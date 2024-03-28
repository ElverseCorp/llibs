#ifndef LLIBS_FRAMEWORK_MEM_H_
#define LLIBS_FRAMEWORK_MEM_H_

/**************************************************************************//**
 * @file     mem.h
 * @brief    Project L - Llibs, cross-platform framework / mem.h
 * @version  V0.2.0
 * @date     5. Jan 2024
 * @author   Matvey Rybalkin
******************************************************************************/

/* Must be included in llibs.h */

/* Standard functions */

/** 
  * @brief Dynamically allocate a certain amount of memory bytes.
  * 
  * The principle of operation is similar to malloc() 
  * 
  * @param[in] size size in bytes. 
  * @return returns the address of the allocated memory.
  */
extern void* lmalloc(lsz size);

/** 
  * @brief Dynamically allocate and clear a certain amount of memory bytes.
  * 
  * The principle of operation is similar to calloc() 
  * 
  * @param[in] num number of elements.
  * @param[in] size size of every element. 
  * @return returns the address of the allocated memory.
  */
extern void* lcalloc(lsz num, lsz size);

/** 
  * @brief Dynamically reallocate a certain amount of memory bytes.
  * 
  * The principle of operation is similar to calloc() 
  * 
  * @param[in] mem current memory address
  * @param[in] size size of every element. 
  * @return returns the address of the allocated memory.
  */
extern void* lrealloc(void* mem, lsz size);

#endif // LLIBS_FRAMEWORK_MEM_H_