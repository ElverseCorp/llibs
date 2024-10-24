#ifndef ELLIPSE_2_MEM_H_
#define ELLIPSE_2_MEM_H_

/**************************************************************************//**
 * @file     mem.h
 * @brief    Ellipse memory managment for C.
 * @version  V0.3.0
 * @date     30. Sep 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include "types.h"
#include "str.h"
#include "io.h"

/////////////////////////////////////////////
///////////// Types definition ////////////// 
///////////////////////////////////////////// 

/**
 * @brief    Structure for managing dynamic memory.
 *
 * This structure is used to represent and manage dynamically allocated memory 
 * in the Ellipse framework. It contains metadata about the memory block, including 
 * the pointer to the allocated memory, the total size allocated, and the amount 
 * of memory currently used.
 *
 * @var data
 *     Pointer to the allocated memory block.
 *
 * @var allocated
 *     The total size of the allocated memory in bytes.
 *
 * @var used
 *     The amount of memory currently used in bytes. This may be less than 
 *     or equal to the `allocated` size.
 */
typedef struct {
    void* data;      ///< Pointer to the allocated memory block.
    size_t allocated; ///< Total size of allocated memory in bytes.
    size_t used;      ///< Amount of memory currently used in bytes.
} memory_t;


/////////////////////////////////////////////
//////// Memory allocation functions //////// 
///////////////////////////////////////////// 

/**
 * @brief    Allocates memory for an array of elements.
 *
 * This function allocates memory for `num` elements of size `sizeof_element`. 
 * It returns a memory_t structure that contains a pointer to the allocated memory, 
 * the allocated size, and the used size (initially set to zero).
 *
 * @param[in] num             The number of elements to allocate.
 * @param[in] sizeof_element   The size of each element in bytes.
 * @return    A memory_t structure containing the allocated memory and metadata.
 *
 * @note     Use `freeing()` or `mem_free()` to free the memory when done.
 */
extern memory_t allocate(size_t num, size_t sizeof_element);

/**
 * @brief    Reallocates memory to adjust the size.
 *
 * This function reallocates the memory of a `memory_t` structure to hold `num` 
 * elements of size `sizeof_element`. The contents of the memory will be preserved, 
 * but if the memory is expanded, new space will be uninitialized.
 *
 * @param[in] data            The memory block to reallocate.
 * @param[in] num             The number of elements to allocate.
 * @param[in] sizeof_element   The size of each element in bytes.
 * @return    A memory_t structure with the reallocated memory.
 *
 * @note     The pointer `data->data` may change after this operation. Always 
 *           check the returned memory structure.
 */
extern memory_t reallocate(memory_t* data, size_t num, size_t sizeof_element);

/**
 * @brief    Forces reallocation, overwriting data if necessary.
 *
 * This function reallocates the memory to fit `num` elements, potentially 
 * overwriting any data if the memory is reduced or shifted. This may result 
 * in loss of data if the memory is resized to a smaller size.
 *
 * @param[in] data            The memory block to reallocate.
 * @param[in] num             The number of elements to allocate.
 * @param[in] sizeof_element   The size of each element in bytes.
 * @return    A memory_t structure with the reallocated memory.
 *
 * @warning  This function may overwrite data. Use with caution.
 */
extern memory_t reallocate_force(memory_t* data, size_t num, size_t sizeof_element);

/**
 * @brief    Frees the allocated memory.
 *
 * This function frees the memory block described by `data` and sets the 
 * memory metadata to zero.
 *
 * @param[in] data            The memory block to free.
 * @return    An error code of type `err_t`. Returns `OK` if on success, non-zero on error.
 */
extern err_t freeing(memory_t data);

/////////////////////////////////////////////
//////// Memory managment functions ///////// 
///////////////////////////////////////////// 

/**
 * @brief    Copies data from one memory block to another.
 *
 * This function copies the contents of `mem2` to `mem1`. The memory in `mem1` must 
 * be large enough to hold the contents of `mem2`.
 *
 * @param[in] dest            The destination memory block.
 * @param[in] src             The source memory block.
 * @return    An error code of type `err_t`. Returns `OK` if on success, non-zero on error.
 */
extern err_t mem_copy(memory_t* dest, memory_t src);

/**
 * @brief    Sets the memory block to a specific value.
 *
 * This function fills the memory block `mem1` with the specified byte value `data`.
 *
 * @param[in] mem            The memory block to be set.
 * @param[in] data            The byte value to set each element to.
 * @return    An error code of type `err_t`. Returns `OK` if on success, non-zero on error.
 */
extern err_t mem_set(memory_t* mem, u8_t data);

/**
 * @brief    Moves data from one memory block to another.
 *
 * This function moves the contents of `mem2` to `mem1`. The memory in `mem2` 
 * is assumed to be invalid after the move.
 *
 * @param[in] mem1            The destination memory block.
 * @param[in] mem2            The source memory block.
 * @return    An error code of type `err_t`. Returns `OK` if on success, non-zero on error.
 */
extern err_t mem_move(memory_t* mem1, memory_t* mem2);

/**
 * @brief    Compares two memory blocks.
 *
 * This function compares the contents of two memory blocks `mem1` and `mem2`. 
 * It returns `OK` if both memory blocks are identical, or a negative/positive value 
 * if they differ.
 *
 * @param[in] mem1            The first memory block.
 * @param[in] mem2            The second memory block.
 * @return    `OK` if memory blocks are equal, non-zero otherwise.
 */
extern ssize_t mem_compare(memory_t mem1, memory_t mem2);

/**
 * @brief    Reduces allocated memory to match the used size.
 *
 * This function strips excess memory from the allocated block, shrinking 
 * it to fit the currently used size. It can be used to minimize memory overhead.
 *
 * @param[in] mem             The memory block to optimize.
 * @return    An error code of type `err_t`. Returns `OK` if on success, non-zero on error.
 */
extern err_t mem_strip(memory_t* mem);

/////////////////////////////////////////////
////////// Global memory functions ////////// 
///////////////////////////////////////////// 

/**
 * @brief    Gets the total allocated memory size.
 *
 * This function returns the total amount of memory currently allocated by the program. 
 * It includes both used and unused (but allocated) memory, representing the complete 
 * size of all memory blocks that are managed by the Ellipse memory system.
 *
 * @return    The total allocated memory size in bytes.
 *
 * @note      This function provides an overview of the memory footprint of the program.
 */
extern size_t mem_global_all_resources_size(void);

/**
 * @brief    Gets the total used memory size.
 *
 * This function returns the total amount of memory currently in use by the program. 
 * It represents only the memory actively used for storing data and excludes any unused 
 * (but allocated) memory. It can be used to determine how efficiently allocated memory 
 * is being utilized.
 *
 * @return    The total used memory size in bytes.
 *
 * @note      This value is always less than or equal to the total allocated memory size.
 */
extern size_t mem_global_used_resources_size(void);

/**
 * @brief    Frees all globally allocated memory.
 *
 * This function frees all globally allocated memory used by the program. 
 * It should be called when the program is finished using memory to avoid leaks.
 *
 * @return    An error code of type `err_t`. Returns `OK` on success, non-zero on error.
 */
extern err_t mem_global_all_resources_free(void);

/**
 * UNFINISHED!!
 */
extern err_t mem_global_dump(void);  // TODO: file io

/////////////////////////////////////////////
///////// Generic memory allocation ///////// 
///////////////////////////////////////////// 

/**
 * @brief    Allocates and clears memory for an array.
 *
 * This function allocates memory for an array of `num` elements of size 
 * `sizeof_element` and initializes the memory to zero.
 *
 * @param[in] num             The number of elements to allocate.
 * @param[in] sizeof_element   The size of each element in bytes.
 * @return    A pointer to the allocated and cleared memory.
 */
extern void* calloc_generic(size_t num, size_t sizeof_element);

/**
 * @brief    Reallocates and clears additional memory for an array.
 *
 * This function reallocates the memory block `data` to hold `num` elements 
 * of size `sizeof_element`. New memory is initialized to zero.
 *
 * @param[in] data            The memory block to reallocate.
 * @param[in] num             The number of elements to allocate.
 * @param[in] sizeof_element   The size of each element in bytes.
 * @return    A pointer to the reallocated and cleared memory.
 */
extern void* recalloc_generic(void* data, size_t num, size_t sizeof_element);

/**
 * @brief    Frees memory allocated by calloc_generic or recalloc_generic.
 *
 * This function frees memory previously allocated by `calloc_generic` or `recalloc_generic`.
 *
 * @param[in] data            The pointer to the memory to free.
 */
extern void free_generic(void* data);

/////////////////////////////////////////////
///////////// Memory protection ///////////// 
///////////////////////////////////////////// 

/**
 * @brief    Memory access levels for setting memory protection.
 *
 * This enumeration defines different levels of access that can be applied to 
 * a memory block using the `mem_access` function. It includes full, 
 * read-only, write-only, and denied access modes.
 */
typedef enum {
    MEMORY_ACCESS_FULL          = 0b11,
    MEMORY_ACCESS_READ          = 0b10,
    MEMORY_ACCESS_WRITE         = 0b01,
    MEMORY_ACCESS_DENIED        = 0b00,
} memory_access_t;

/**
 * @brief    Sets memory access protection level for a memory block.
 *
 * This function modifies the protection level of a given memory block to 
 * one of the levels defined by `memory_access_t`. The function may fail if 
 * the underlying system call does not support the requested protection mode.
 *
 * @param[in] memory   The memory block whose access level is being changed.
 * @param[in] level    The access level to be set, defined by `memory_access_t`.
 *
 * @return    An error code of type `err_t`. Returns 0 on success, non-zero on failure.
 *
 * @note      This function is platform-dependent and relies on system-specific 
 *            memory protection mechanisms such as `mprotect` for POSIX systems 
 *            or `VirtualProtect` for Windows.
 *
 * @warning   Attempting to access memory after setting `MEMORY_ACCESS_DENIED` 
 *            will result in a segmentation fault or access violation.
 */
extern err_t mem_access(memory_t memory, memory_access_t level);

#endif // ELLIPSE_2_MEM_H_
