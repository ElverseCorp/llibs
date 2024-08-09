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

/// @brief Error code of invalid malloc is the same with L_ERROR
#define L_ERROR_MALLOC L_ERROR

/** 
  * @brief Checks access to the allocated memory block.
  * 
  * The principle of operation is similar (void* == NULL)
  * 
  * @param[in] pointer data pointer.
  * @return returns L_ERROR or L_OK
  */
extern lerr lmemchk(void* pointer);

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
  * @param[in] size new size of memory 
  * @return returns the address of the allocated memory.
  */
extern void* lrealloc(void* mem, lsz size);

/**
 * @brief Copy a block of memory.
 *
 * This function copies a specified number of bytes from the source address to the destination address.
 * The behavior is undefined if the source and destination memory blocks overlap.
 *
 * @param[out] dest Pointer to the destination memory block where the data will be copied.
 * @param[in] src Pointer to the source memory block from which the data will be copied.
 * @param[in] size Number of bytes to copy.
 * @return Returns a pointer to the destination memory block.
 */
extern void* lmemcpy(void* restrict dest, void* restrict src, lsz size);

/**
 * @brief Compare two blocks of memory.
 *
 * This function compares a specified number of bytes from two memory blocks.
 * It returns an integer less than, equal to, or greater than zero if the first block is found,
 * respectively, to be less than, to match, or be greater than the second block.
 *
 * @param[in] data1 Pointer to the first memory block.
 * @param[in] data2 Pointer to the second memory block.
 * @param[in] size Number of bytes to compare.
 * @return Returns an integer indicating the relationship between the two blocks of memory.
 */
extern int lmemcmp(const void* data1, const void* data2, lsz size);

/**
 * @brief Move a block of memory.
 *
 * This function moves a specified number of bytes from the source address to the destination address.
 * Unlike `lmemcpy`, it handles overlapping memory blocks by ensuring that the original data is copied
 * before the destination is overwritten.
 *
 * @param[out] dest Pointer to the destination memory block where the data will be moved.
 * @param[in] src Pointer to the source memory block from which the data will be moved.
 * @param[in] size Number of bytes to move.
 * @return Returns a pointer to the destination memory block.
 */
extern void* lmemmove(void* dest, const void* src, lsz size);

#endif // LLIBS_FRAMEWORK_MEM_H_