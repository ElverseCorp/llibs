#ifndef ELLIPSE_2_LOGS_H_
#define ELLIPSE_2_LOGS_H_

/**************************************************************************//**
 * @file     logs.h
 * @brief    Ellipse asserts for C.
 * @version  V0.3.0
 * @date     30. Sep 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include <c/types.h>
#include <c/str.h>

/////////////////////////////////////////////
//////////// Macros definition ////////////// 
///////////////////////////////////////////// 


/////////////////////////////////////////////
/////////// Function declaration //////////// 
///////////////////////////////////////////// 

void log(bool condition, cstr_t message);


#endif // ELLIPSE_2_LOGS_H_
