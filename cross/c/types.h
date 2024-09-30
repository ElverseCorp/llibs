#ifndef ELLIPSE_2_TYPES_H_
#define ELLIPSE_2_TYPES_H_

/**************************************************************************//**
 * @file     types.h
 * @brief    Ellipse types for C/C++.
 * @version  V0.3.0
 * @date     30. Sep 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include <stdbool.h>

// Basic types
typedef signed char         _ELLIPSE_MAKE_NAME(Int8);
typedef signed short        _ELLIPSE_MAKE_NAME(Int16);
typedef signed int          _ELLIPSE_MAKE_NAME(Int32);
typedef signed long long    _ELLIPSE_MAKE_NAME(Int64);

typedef unsigned char       _ELLIPSE_MAKE_NAME(UInt8);
typedef unsigned short      _ELLIPSE_MAKE_NAME(UInt16);
typedef unsigned int        _ELLIPSE_MAKE_NAME(UInt32);
typedef unsigned long long  _ELLIPSE_MAKE_NAME(UInt64);

typedef float       _ELLIPSE_MAKE_NAME(Float32);
typedef double      _ELLIPSE_MAKE_NAME(Float64);
typedef long double _ELLIPSE_MAKE_NAME(Float128);

// String types

typedef bool _ELLIPSE_MAKE_NAME(Bool);
typedef char _ELLIPSE_MAKE_NAME(Char);
typedef const char* _ELLIPSE_MAKE_NAME(ConstStr);

#if __SIZEOF_POINTER__ == 8
    typedef _ELLIPSE_MAKE_NAME(UInt64) _ELLIPSE_MAKE_NAME(Size);
    typedef _ELLIPSE_MAKE_NAME(UInt64) _ELLIPSE_MAKE_NAME(USize);
    typedef _ELLIPSE_MAKE_NAME(Int64) _ELLIPSE_MAKE_NAME(SSize);
#elif __SIZEOF_POINTER__ == 4
    typedef _ELLIPSE_MAKE_NAME(UInt32) _ELLIPSE_MAKE_NAME(Size);
    typedef _ELLIPSE_MAKE_NAME(UInt64) _ELLIPSE_MAKE_NAME(USize);
    typedef _ELLIPSE_MAKE_NAME(Int32) _ELLIPSE_MAKE_NAME(SSize);
#else
#   error "[ELLIPSE] ERROR: Platform not defined, address size could not be determined. (aka size_t)"
#endif

typedef _ELLIPSE_MAKE_NAME(USize) _ELLIPSE_MAKE_NAME(Len);

typedef enum {
    _ELLIPSE_MAKE_MACROS(OK),
    _ELLIPSE_MAKE_MACROS(ERROR),
}_ELLIPSE_MAKE_NAME(Error);

#endif // ELLIPSE_2_TYPES_H_