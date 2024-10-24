#ifndef ELLIPSE_2_ADV_STACK_H_
#define ELLIPSE_2_ADV_STACK_H_

/**************************************************************************//**
 * @file     stack.h
 * @brief    Ellipse advanced / stack for C.
 * @version  V0.3.0
 * @date     22. Oct 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include <c/types.h>

/////////////////////////////////////////////
////////////// Type definition ////////////// 
///////////////////////////////////////////// 

#ifndef STACK_INITIAL_ALLOCATION
#   define STACK_INITIAL_ALLOCATION 4096U
#endif

typedef any_t stack_value_t;

typedef struct {
    stack_value_t value;
    type_t type;
} stack_element_t;

typedef struct {
    stack_element_t* elements;
    struct {
        size_t capacity_ptr;
        size_t top_ptr;
        len_t count;
    } meta;
} stack_t;


/////////////////////////////////////////////
/////////// Function declaration //////////// 
///////////////////////////////////////////// 

/**
 * @brief    Creates a new stack with an initial allocation.
 *
 * This function initializes a new stack structure with an initial allocation size
 * defined by `STACK_INITIAL_ALLOCATION_N`. It allocates memory for the stack elements 
 * and sets initial metadata for capacity and top pointer.
 *
 * @return   A newly created stack structure, ready for use.
 *
 * @note     The created stack must be destroyed using `stack_destroy()` to free
 *           allocated memory and avoid memory leaks.
 */
stack_t stack_create(void);

/**
 * @brief    Destroys a stack and frees allocated memory.
 *
 * This function properly cleans up and deallocates the memory used by the stack.
 * It should be called when the stack is no longer needed to prevent memory leaks.
 *
 * @param[in] stack Pointer to the stack to be destroyed.
 *
 * @note     After calling this function, the stack pointer should not be used
 *           unless it is reinitialized.
 */
void stack_destroy(stack_t* stack);

/**
 * @brief    Pushes an element onto the stack.
 *
 * This function adds a new element to the top of the stack. If the stack is full,
 * it will automatically call `stack_expand()` to allocate additional space.
 *
 * @param[in] stack   Pointer to the stack.
 * @param[in] element The element to be pushed onto the stack.
 *
 * @note     Ensure that the stack is initialized before using this function.
 */
void stack_push(stack_t* stack, stack_element_t element);

/**
 * @brief    Pops an element from the stack.
 *
 * This function removes and returns the top element from the stack. If the stack is
 * empty, behavior is undefined, so it's advised to check with `stack_is_empty()`
 * before calling this function.
 *
 * @param[in] stack Pointer to the stack.
 * @return    The element popped from the top of the stack.
 *
 * @warning  Popping from an empty stack results in undefined behavior.
 */
stack_element_t stack_pop(stack_t* stack);

/**
 * @brief    Checks if the stack is empty.
 *
 * This function returns `true` if the stack contains no elements and `false`
 * otherwise.
 *
 * @param[in] stack The stack to be checked.
 * @return    `true` if the stack is empty, `false` otherwise.
 */
bool stack_is_empty(stack_t stack);

/**
 * @brief    Strips excess memory allocated to the stack.
 *
 * This function reduces the allocated memory of the stack to fit the current
 * number of elements, potentially freeing unused memory.
 *
 * @param[in] stack Pointer to the stack to be stripped.
 *
 * @note     This function is useful for minimizing memory usage after a large 
 *           number of elements have been removed from the stack.
 */
void stack_strip(stack_t* stack);

/**
 * @brief    Expands the stack's memory capacity.
 *
 * This function increases the capacity of the stack by reallocating memory. 
 * It is called automatically when pushing an element onto a full stack, but 
 * can also be called explicitly to pre-allocate space for future elements.
 *
 * @param[in] stack Pointer to the stack that needs to be expanded.
 *
 * @warning  Ensure there is enough system memory to allocate the new capacity.
 */
void stack_expand(stack_t* stack);

/**
 * @brief    Returns the total size of the stack (capacity).
 *
 * This function returns the total memory capacity of the stack, including both 
 * used and unused elements.
 *
 * @param[in] stack Stack structure.
 * @return    The total size of the stack in terms of element capacity.
 */
size_t stack_get_size(stack_t stack);

/**
 * @brief    Returns the number of elements in the stack.
 *
 * This function returns the number of elements currently stored in the stack.
 *
 * @param[in] stack Stack structure.
 * @return    The number of elements in the stack.
 */
size_t stack_get_count(stack_t stack);


#endif // ELLIPSE_2_ADV_STACK_H_