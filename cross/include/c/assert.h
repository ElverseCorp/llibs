#ifndef ELLIPSE_2_ASSERT_H_
#define ELLIPSE_2_ASSERT_H_

/**************************************************************************//**
 * @file     assert.h
 * @brief    Ellipse asserts for C.
 * @version  V0.3.0
 * @date     30. Sep 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include <c/types.h>
#include "str.h"

/////////////////////////////////////////////
//////////// Macros definition ////////////// 
///////////////////////////////////////////// 


/////////////////////////////////////////////
/////////// Function declaration //////////// 
///////////////////////////////////////////// 

void assert(bool condition, cstr_t message);


#endif // ELLIPSE_2_ASSERT_H_
