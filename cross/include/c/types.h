#ifndef ELLIPSE_2_TYPES_H_
#define ELLIPSE_2_TYPES_H_

/**************************************************************************//**
 * @file     types.h
 * @brief    Ellipse types for C/C++.
 * @version  V0.3.0
 * @date     30. Sep 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#ifndef __cplusplus
/// @brief A null pointer means there is no data at the current pointer.
#   define NULL (void*)(0)
#   include <stdbool.h>
#endif

/////////////////////////////////////////////
///////////// Types definition ////////////// 
///////////////////////////////////////////// 

/// @brief Signed 8-bit type.
typedef signed char         i8_t;
/// @brief Unsigned 8-bit type.
typedef unsigned char       u8_t;
/// @brief Signed 16-bit type.
typedef signed short        i16_t;
/// @brief Unsigned 16-bit type.
typedef unsigned short      u16_t;
/// @brief Signed 32-bit type.
typedef signed int          i32_t;
/// @brief Unsigned 32-bit type.
typedef unsigned int        u32_t;
/// @brief Signed 64-bit type.
typedef signed long long    i64_t;
/// @brief Unsigned 64-bit type.
typedef unsigned long long  u64_t;

#ifdef __SIZEOF_INT128__
/// @brief Signed 128-bit type.
typedef __int128_t  i128_t;
/// @brief Unsigned 128-bit type.
typedef __uint128_t u128_t;
#endif 

/// @brief Floating point 32-bit type.
typedef float       f32_t;
/// @brief Floating point 64-bit type.
typedef double      f64_t;
/// @brief Floating point 128-bit type.
typedef long double f128_t;

/// @brief Character 8-bit type. (ASCII)
typedef i8_t    char_t;
/// @brief Unsigned character 8-bit type.
typedef u8_t    uchar_t;

/// @brief Character 8-bit type. (ASCII)
typedef i8_t    char8_t;
/// @brief Character 16-bit type. (UTF-16 or wchar_t)
typedef u16_t   char16_t;
/// @brief Character 16-bit type. (UTF-16 or wchar_t)
typedef u16_t   wchar_t;
/// @brief Character 16-bit type. (UTF-32)
typedef u32_t   char32_t;

/// @brief Size data type. Specifies the size of something, usually in bytes.
typedef unsigned long size_t;
/// @brief Size signed data type. Specifies the size of something, usually in bytes.
typedef signed long ssize_t;
/// @brief Size data type. Specifies the size of something, usually in bytes.
typedef unsigned long usize_t;

typedef size_t len_t;

typedef enum {
    LL_OK,
    LL_ERROR,
} err_t;

/////////////////////////////////////////////
////////////////// Aliases ////////////////// 
///////////////////////////////////////////// 

#define RANGE(i, n) for(ssize_t i = 0; i < (n); ++i)
#define IN_RANGE(i, min, max) (bool)((i) >= (min) && (i) <= (max))

#endif // ELLIPSE_2_TYPES_H_
