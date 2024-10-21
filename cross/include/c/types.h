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
/// @brief A null pointer definition for C.
/// @details This definition is included only when the code is compiled as C,
/// since C++ already includes the `nullptr` equivalent.
/// @note For C++, `nullptr` is used instead.
#   define NULL (void*)(0)

/// @brief Boolean type for C.
/// @details This header is included for boolean type support in C. In C++,
/// `bool` is already a built-in type.
#   include <stdbool.h>
#endif

/////////////////////////////////////////////
///////////// Types definition ////////////// 
/////////////////////////////////////////////

/**
 * @typedef i8_t
 * @brief Signed 8-bit integer.
 */
typedef signed char         i8_t;
/**
 * @typedef u8_t
 * @brief Unsigned 8-bit integer.
 */
typedef unsigned char       u8_t;
/**
 * @typedef i16_t
 * @brief Signed 16-bit integer.
 */
typedef signed short        i16_t;
/**
 * @typedef u16_t
 * @brief Unsigned 16-bit integer.
 */
typedef unsigned short      u16_t;
/**
 * @typedef i32_t
 * @brief Signed 32-bit integer.
 */
typedef signed int          i32_t;
/**
 * @typedef u32_t
 * @brief Unsigned 32-bit integer.
 */
typedef unsigned int        u32_t;
/**
 * @typedef i64_t
 * @brief Signed 64-bit integer.
 */
typedef signed long long    i64_t;
/**
 * @typedef u64_t
 * @brief Unsigned 64-bit integer.
 */
typedef unsigned long long  u64_t;

#ifdef __SIZEOF_INT128__
/**
 * @typedef i128_t
 * @brief Signed 128-bit integer (if supported by the platform).
 */
typedef __int128_t  i128_t;
/**
 * @typedef u128_t
 * @brief Unsigned 128-bit integer (if supported by the platform).
 */
typedef __uint128_t u128_t;
/**
 * @typedef imax_t
 * @brief Maximum-sized signed integer, equivalent to 128-bit if supported.
 */
typedef i128_t      imax_t;
/**
 * @typedef umax_t
 * @brief Maximum-sized unsigned integer, equivalent to 128-bit if supported.
 */
typedef u128_t      umax_t;
#else
/**
 * @typedef imax_t
 * @brief Maximum-sized signed integer, equivalent to 64-bit if 128-bit is not supported.
 */
typedef i64_t       imax_t;
/**
 * @typedef umax_t
 * @brief Maximum-sized unsigned integer, equivalent to 64-bit if 128-bit is not supported.
 */
typedef u64_t       umax_t;
#endif

/**
 * @typedef f32_t
 * @brief 32-bit floating-point type.
 */
typedef float       f32_t;
/**
 * @typedef f64_t
 * @brief 64-bit floating-point type (double precision).
 */
typedef double      f64_t;

#ifdef __SIZEOF_FLOAT128__
/**
 * @typedef f128_t
 * @brief 128-bit floating-point type (if supported by the platform).
 */
typedef __float128  f128_t;
/**
 * @typedef fmax_t
 * @brief Maximum-sized floating-point type, equivalent to 128-bit if supported.
 */
typedef f128_t      fmax_t;
#else
/**
 * @typedef fmax_t
 * @brief Maximum-sized floating-point type, equivalent to long double (usually 64-bit or more).
 */
typedef long double fmax_t;
#endif

/**
 * @def SIZEOF_FMAX
 * @brief Defines the size of the largest available floating-point type.
 */
#define SIZEOF_FMAX sizeof(fmax_t)

/**
 * @typedef char_t
 * @brief 8-bit signed character type (ASCII).
 */
typedef i8_t    char_t;
/**
 * @typedef uchar_t
 * @brief 8-bit unsigned character type.
 */
typedef u8_t    uchar_t;

/**
 * @typedef char8_t
 * @brief Alias for 8-bit character (ASCII).
 */
typedef i8_t    char8_t;
/**
 * @typedef char16_t
 * @brief 16-bit character type (UTF-16 or `wchar_t`).
 */
typedef u16_t   char16_t;

#ifndef __cplusplus
/**
 * @typedef wchar_t
 * @brief Wide character type for C (16-bit).
 * @details In C++, this type is already defined.
 */
typedef u16_t   wchar_t;
#endif

/**
 * @typedef char32_t
 * @brief 32-bit character type (UTF-32).
 */
typedef u32_t   char32_t;

#ifndef size_t
/**
 * @typedef size_t
 * @brief Data type for representing sizes of objects (usually in bytes).
 */
typedef unsigned long size_t;
#endif

#ifndef ssize_t
/**
 * @typedef ssize_t
 * @brief Signed data type for representing sizes of objects (usually in bytes).
 */
typedef signed long ssize_t;
#endif

/**
 * @typedef len_t
 * @brief Data type for representing quantities or lengths (not in bytes).
 * @warning Don't confuse with `size_t`.
 */
typedef size_t len_t;

/////////////////////////////////////////////
///////////// Error definitions ///////////// 
/////////////////////////////////////////////

/**
 * @enum err_t
 * @brief Error codes for various operations.
 * @details Includes general, memory-related, I/O, network, validation, and hardware errors.
 */
typedef enum {
    OK = 0,                      ///< Operation completed successfully.
    ERROR = 1,                   ///< General error.
    ERROR_MEMORY = 100,          ///< Memory allocation failure.
    ERROR_OUT_OF_MEMORY = 101,   ///< Out of memory (heap or stack exhausted).
    ERROR_NULL_POINTER = 102,    ///< Null pointer dereference.
    ERROR_IO = 200,              ///< General I/O error.
    ERROR_FILE_NOT_FOUND = 201,  ///< File not found.
    ERROR_FILE_PERMISSION = 202, ///< File access permission denied.
    ERROR_FILE_READ = 203,       ///< File read error.
    ERROR_FILE_WRITE = 204,      ///< File write error.
    ERROR_IO_TIMEOUT = 205,      ///< I/O operation timed out.
    ERROR_NETWORK = 300,             ///< General network error.
    ERROR_CONNECTION_FAILED = 301,   ///< Network connection failed.
    ERROR_CONNECTION_LOST = 302,     ///< Network connection lost.
    ERROR_CONNECTION_TIMEOUT = 303,  ///< Network connection timed out.
    ERROR_INVALID_ADDRESS = 304,     ///< Invalid network address.
    ERROR_INVALID_ARGUMENT = 400,    ///< Invalid function argument.
    ERROR_OUT_OF_BOUNDS = 401,       ///< Index or pointer out of bounds.
    ERROR_INVALID_DATA = 402,        ///< Invalid data format.
    ERROR_DATA_OVERFLOW = 403,       ///< Data overflow (buffer too small).
    ERROR_UNINITIALIZED = 500,       ///< Uninitialized variable or state.
    ERROR_STATE_MISMATCH = 501,      ///< Invalid state or state mismatch.
    ERROR_LOGIC_FAILURE = 502,       ///< General logical failure.
    ERROR_SYNTAX = 600,              ///< Syntax error.
    ERROR_PARSING = 601,             ///< Parsing failure.
    ERROR_UNEXPECTED_TOKEN = 602,    ///< Unexpected token encountered during parsing.
    ERROR_HARDWARE = 700,            ///< General hardware error.
    ERROR_DEVICE_FAILURE = 701,      ///< Hardware device failure.
    ERROR_DEVICE_BUSY = 702,         ///< Hardware device is busy.
    ERROR_DEVICE_NOT_FOUND = 703,    ///< Hardware device not found.
    ERROR_AUTHENTICATION = 800,      ///< Authentication failure.
    ERROR_ACCESS_DENIED = 801,       ///< Access denied.
    ERROR_ENCRYPTION = 802,          ///< Encryption or decryption failure.
    ERROR_THREAD_FAILURE = 900,      ///< General threading error.
    ERROR_MUTEX_FAILURE = 901,       ///< Mutex acquisition or release failure.
    ERROR_DEADLOCK = 902,            ///< Deadlock detected.
    ERROR_TIMEOUT = 903              ///< Operation timed out.
} err_t;

/////////////////////////////////////////////
////////////////// Aliases //////////////////
/////////////////////////////////////////////

/**
 * @def RANGE(i, n)
 * @brief Alias for a for loop with an index variable `i`.
 * @details Equivalent to `for (ssize_t i = 0; i < n; ++i)`.
 * @param[in] i Iterator variable.
 * @param[in] n Loop count limit.
 */
#define RANGE(i, n) for(ssize_t i = 0; i < (n); ++i)

/**
 * @def IN_RANGE(i, min, max)
 * @brief Checks if a value is within a specified range.
 * @details Equivalent to `(i >= min && i <= max)`.
 * @param[in] i The value to check.
 * @param[in] min Lower bound of the range.
 * @param[in] max Upper bound of the range.
 */
#define IN_RANGE(i, min, max) ((i) >= (min) && (i) <= (max))

#endif // ELLIPSE_2_TYPES_H_
