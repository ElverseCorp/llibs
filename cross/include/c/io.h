#ifndef ELLIPSE_2_IO_H_
#define ELLIPSE_2_IO_H_

/**************************************************************************//**
 * @file     io.h
 * @brief    Project L - Ellipse, cross-platform framework. Input/Output header.
 * @version  V0.3.0
 * @date     30. Sep 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include "types.h"
#include "str.h"

/////////////////////////////////////////////
////////////// Type definition ////////////// 
///////////////////////////////////////////// 


typedef struct {
    void (write)(void*);
    void (read)(void*);
} iostream_t;


/////////////////////////////////////////////
/////////// Function declaration //////////// 
///////////////////////////////////////////// 

extern err_t out(iostream_t stream, void* data);
extern err_t in(iostream_t stream, void* data);

extern size_t print(cstr_t format, ...);
extern size_t error(cstr_t format, ...);
extern size_t scan(cstr_t format, ...);

#endif // ELLIPSE_2_IO_H_