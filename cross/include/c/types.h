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

/**
 * @union any_t
 * @brief Union for storing various data types in a single variable.
 * @details This union allows for flexible storage of different types of data, including pointers, 
 * integers of various sizes, and floating-point numbers. It supports both signed and unsigned types, 
 * as well as maximum width integer and floating-point types.
 */
typedef union {
    /**
     * @brief Pointer to any type.
     * @details Allows the storage of a generic pointer, which can be cast to any other type as needed.
     */
    void* ptr;

    /**
     * @brief 8-bit signed integer.
     * @details Stores a signed 8-bit integer (i.e., `int8_t`).
     */
    i8_t i8;

    /**
     * @brief 8-bit unsigned integer.
     * @details Stores an unsigned 8-bit integer (i.e., `uint8_t`).
     */
    u8_t u8;

    /**
     * @brief 16-bit signed integer.
     * @details Stores a signed 16-bit integer (i.e., `int16_t`).
     */
    i16_t i16;

    /**
     * @brief 16-bit unsigned integer.
     * @details Stores an unsigned 16-bit integer (i.e., `uint16_t`).
     */
    u16_t u16;

    /**
     * @brief 32-bit signed integer.
     * @details Stores a signed 32-bit integer (i.e., `int32_t`).
     */
    i32_t i32;

    /**
     * @brief 32-bit unsigned integer.
     * @details Stores an unsigned 32-bit integer (i.e., `uint32_t`).
     */
    u32_t u32;

    /**
     * @brief 64-bit signed integer.
     * @details Stores a signed 64-bit integer (i.e., `int64_t`).
     */
    i64_t i64;

    /**
     * @brief 64-bit unsigned integer.
     * @details Stores an unsigned 64-bit integer (i.e., `uint64_t`).
     */
    u64_t u64;

#ifdef __SIZEOF_INT128__
    /**
     * @brief 128-bit signed integer.
     * @details Stores a signed 128-bit integer (i.e., `__int128_t`). (if supported by the system)
     */
    i128_t i128;

    /**
     * @brief 128-bit unsigned integer.
     * @details Stores an unsigned 128-bit integer (i.e., `unsigned __int128_t`). (if supported by the system)
     */
    u128_t u128;
#endif

    /**
     * @brief 32-bit floating-point number.
     * @details Stores a 32-bit floating-point value (i.e., `float`).
     */
    f32_t f32;

    /**
     * @brief 64-bit floating-point number.
     * @details Stores a 64-bit floating-point value (i.e., `double`).
     */
    f64_t f64;

#ifdef __SIZEOF_FLOAT128__
    /**
     * @brief 128-bit floating-point number.
     * @details Stores a 128-bit floating-point value (i.e., `__float128`). (if supported by the system)
     */
    f128_t f128;
#endif

    /**
     * @brief Maximum signed integer.
     * @details Stores the largest signed integer available (i.e., `intmax_t`), depending on the platform.
     */
    imax_t imax;

    /**
     * @brief Maximum unsigned integer.
     * @details Stores the largest unsigned integer available (i.e., `uintmax_t`), depending on the platform.
     */
    umax_t umax;

    /**
     * @brief Maximum floating point number.
     * @details Stores the largest floating-point number available, depending on the platform.
     */
    fmax_t fmax;
} any_t;

/////////////////////////////////////////////
///////////// Types enumerations //////////// 
/////////////////////////////////////////////

/**
 * @brief Enumeration of data types for Ellipse framework.
 * 
 * This enumeration lists different data types that can be used in the framework.
 * It supports integer types, floating-point types, and system-specific maximum types.
 */
typedef enum {
    TYPE_I8,        ///< Signed 8-bit integer `i8_t`
    TYPE_U8,        ///< Unsigned 8-bit integer `ui8_t`
    TYPE_I16,       ///< Signed 16-bit integer `i16_t`
    TYPE_U16,       ///< Unsigned 16-bit integer `u16_t`
    TYPE_I32,       ///< Signed 32-bit integer `i32_t`
    TYPE_U32,       ///< Unsigned 32-bit integer `u32_t`
    TYPE_I64,       ///< Signed 64-bit integer `i64_t`
    TYPE_U64,       ///< Unsigned 64-bit integer `u64_t`
    TYPE_IMAX,      ///< Maximum signed integer type available on the system `imax_t`
    TYPE_UMAX,      ///< Maximum unsigned integer type available on the system `umax_t`
    TYPE_FMAX,      ///< Maximum floating point type available on the system `fmax_t`

#ifdef __SIZEOF_INT128__
    TYPE_I128,      ///< Signed 128-bit integer `i128_t` (if supported by the system)
    TYPE_U128,      ///< Unsigned 128-bit integer `u128_t` (if supported by the system)
#endif

#ifdef __SIZEOF_FLOAT128__
    TYPE_F128,      ///< Floating point 128-bit `f128_t` (if supported by the system)
#endif
} type_t;

/**
 * @brief Enumeration of generic value types.
 * 
 * This enumeration defines different value categories used during tokenization
 * and processing of data.
 */
typedef enum {
    VALUE_TYPE_INTEGER,   ///< Represents an integer value (signed or unsigned)
    VALUE_TYPE_DECIMAL,   ///< Represents a decimal value (floating-point)
    VALUE_TYPE_CHARACTER, ///< Represents a single character
    VALUE_TYPE_STRING,    ///< Represents a string (sequence of characters)
} value_type_t;

/////////////////////////////////////////////
///////////// Error definitions ///////////// 
/////////////////////////////////////////////

/**
 * @enum err_t
 * @brief Error codes for various operations.
 * @details Includes general, memory-related, I/O, network, validation, and hardware errors.
 */
typedef enum {
    ERR_OK = 0,                      ///< Operation completed successfully.
    ERR_GENERAL = 1,                 ///< General error.

    // Memory Errors
    ERR_MEM_GENERAL = 100,           ///< General memory error.
    ERR_MEM_OUT_OF_MEMORY = 101,     ///< Out of memory (heap or stack exhausted).
    ERR_MEM_NULL_POINTER = 102,      ///< Null pointer dereference.
    ERR_MEM_LEAK = 103,              ///< Memory leak detected.
    ERR_MEM_CORRUPTION = 104,        ///< Memory corruption detected.
    ERR_MEM_SEGMENTATION_FAULT = 105,///< Invalid memory access (segmentation fault).

    // I/O Errors
    ERR_IO_GENERAL = 200,            ///< General I/O error.
    ERR_IO_FILE_NOT_FOUND = 201,     ///< File not found.
    ERR_IO_FILE_PERMISSION = 202,    ///< File access permission denied.
    ERR_IO_FILE_READ = 203,          ///< File read error.
    ERR_IO_FILE_WRITE = 204,         ///< File write error.
    ERR_IO_TIMEOUT = 205,            ///< I/O operation timed out.
    ERR_IO_DISK_FULL = 206,          ///< No space left on device.
    ERR_IO_PATH_TOO_LONG = 207,      ///< File path too long.
    ERR_IO_FILE_EXISTS = 208,        ///< File already exists.

    // Network Errors
    ERR_NET_GENERAL = 300,           ///< General network error.
    ERR_NET_CONNECTION_FAILED = 301, ///< Network connection failed.
    ERR_NET_CONNECTION_LOST = 302,   ///< Network connection lost.
    ERR_NET_TIMEOUT = 303,           ///< Network connection timed out.
    ERR_NET_INVALID_ADDRESS = 304,   ///< Invalid network address.
    ERR_NET_DNS_RESOLUTION = 305,    ///< DNS resolution failed.
    ERR_NET_PROTOCOL = 306,          ///< Protocol error.
    ERR_NET_SSL = 307,               ///< SSL/TLS error.

    // Argument and Data Errors
    ERR_ARG_INVALID = 400,           ///< Invalid function argument.
    ERR_ARG_OUT_OF_BOUNDS = 401,     ///< Index or pointer out of bounds.
    ERR_ARG_INVALID_DATA = 402,      ///< Invalid data format.
    ERR_ARG_DATA_OVERFLOW = 403,     ///< Data overflow (buffer too small).
    ERR_ARG_DATA_UNDERFLOW = 404,    ///< Data underflow (buffer is already empty).
    ERR_ARG_TYPE_MISMATCH = 405,     ///< Type mismatch error.
    ERR_ARG_ENCODING = 406,          ///< Encoding error.

    // State and Logic Errors
    ERR_STATE_UNINITIALIZED = 500,   ///< Uninitialized variable or state.
    ERR_STATE_MISMATCH = 501,        ///< Invalid state or state mismatch.
    ERR_STATE_LOGIC_FAILURE = 502,   ///< General logical failure.
    ERR_STATE_NOT_IMPLEMENTED = 503, ///< Functionality not implemented.
    ERR_STATE_UNSUPPORTED = 504,     ///< Operation not supported.
    ERR_STATE_INTERNAL = 505,        ///< Internal error.

    // Parsing and Syntax Errors
    ERR_PARSE_SYNTAX = 600,          ///< Syntax error.
    ERR_PARSE_FAILURE = 601,         ///< Parsing failure.
    ERR_PARSE_UNEXPECTED_TOKEN = 602,///< Unexpected token encountered during parsing.
    ERR_PARSE_LEXER = 603,           ///< Lexical analysis error.
    ERR_PARSE_TOKENIZATION = 604,    ///< Tokenization error.
    ERR_PARSE_SEMANTIC = 605,        ///< Semantic analysis error.
    ERR_PARSE_UNEXPECTED_EOF = 606,  ///< Unexpected end of file/input.

    // Hardware and Device Errors
    ERR_HW_GENERAL = 700,            ///< General hardware error.
    ERR_HW_DEVICE_FAILURE = 701,     ///< Hardware device failure.
    ERR_HW_DEVICE_BUSY = 702,        ///< Hardware device is busy.
    ERR_HW_DEVICE_NOT_FOUND = 703,   ///< Hardware device not found.
    ERR_HW_DEVICE_NOT_READY = 704,   ///< Device not ready.
    ERR_HW_DEVICE_TIMEOUT = 705,     ///< Device operation timed out.
    ERR_HW_DEVICE_UNSUPPORTED = 706, ///< Device not supported.

    // Security and Authentication Errors
    ERR_SEC_AUTH = 800,              ///< Authentication failure.
    ERR_SEC_ACCESS_DENIED = 801,     ///< Access denied.
    ERR_SEC_ENCRYPTION = 802,        ///< Encryption or decryption failure.
    ERR_SEC_GENERAL = 803,           ///< General security error.
    ERR_SEC_PRIVILEGE = 804,         ///< Insufficient privileges.

    // Threading and Concurrency Errors
    ERR_THREAD_GENERAL = 900,        ///< General threading error.
    ERR_THREAD_MUTEX = 901,          ///< Mutex acquisition or release failure.
    ERR_THREAD_DEADLOCK = 902,       ///< Deadlock detected.
    ERR_THREAD_TIMEOUT = 903,        ///< Threading operation timed out.
    ERR_THREAD_CREATION = 904,       ///< Failed to create a new thread.
    ERR_THREAD_JOIN = 905,           ///< Failed to join a thread.
    ERR_THREAD_INTERRUPTED = 906,    ///< Thread was interrupted.
    ERR_THREAD_MUTEX_INIT = 907,     ///< Mutex initialization failed.
    ERR_THREAD_MUTEX_LOCK = 908,     ///< Failed to acquire mutex lock.
    ERR_THREAD_MUTEX_UNLOCK = 909,   ///< Failed to release mutex lock.
    ERR_THREAD_CONDITION_WAIT = 910, ///< Condition variable wait failed.
    ERR_THREAD_CONDITION_SIGNAL = 911, ///< Condition variable signal failed.

    // Time and Timer Errors
    ERR_TIME_CLOCK = 1000,           ///< Clock error.
    ERR_TIME_TIMER = 1001,           ///< Timer error.
    ERR_TIME_OPERATION_TIMEOUT = 1002, ///< Operation timed out.

    // Configuration Errors
    ERR_CONFIG_GENERAL = 1003,       ///< Configuration error.
    ERR_CONFIG_INVALID = 1004,       ///< Invalid configuration.

    // Resource Errors
    ERR_RESOURCE_LIMIT = 1005,       ///< Resource limit exceeded.
    ERR_RESOURCE_BUSY = 1006,        ///< Resource is busy.

    // Signal and Exception Errors
    ERR_SIGNAL_GENERAL = 1007,       ///< Signal received.
    ERR_EXCEPTION = 1008,            ///< Exception occurred.

    // Module and Plugin Errors
    ERR_MODULE_LOAD = 1009,          ///< Failed to load module.
    ERR_MODULE_UNLOAD = 1010,        ///< Failed to unload module.
    ERR_MODULE_INIT = 1011,          ///< Module initialization failed.

    // Server Errors
    ERR_SERVER_START = 1012,         ///< Failed to start server.
    ERR_SERVER_STOP = 1013,          ///< Failed to stop server.
    ERR_SERVER_OVERLOAD = 1014,      ///< Server is overloaded.

    // Database Errors
    ERR_DB_GENERAL = 1100,           ///< General database error.
    ERR_DB_CONNECTION = 1101,        ///< Database connection failed.
    ERR_DB_QUERY = 1102,             ///< Database query failed.
    ERR_DB_TRANSACTION = 1103,       ///< Database transaction failed.

    // Serialization and Deserialization Errors
    ERR_SERIALIZATION = 1200,        ///< Serialization error.
    ERR_DESERIALIZATION = 1201,      ///< Deserialization error.

    // Compression and Decompression Errors
    ERR_COMPRESSION = 1300,          ///< Compression error.
    ERR_DECOMPRESSION = 1301,        ///< Decompression error.

    // Internationalization Errors
    ERR_LOCALE_GENERAL = 1400,       ///< Locale error.
    ERR_ENCODING_CONVERSION = 1401,  ///< Encoding conversion error.

    // Machine Learning and AI Errors (if applicable)
    ERR_ML_MODEL_LOAD = 1500,        ///< Failed to load model.
    ERR_ML_INFERENCE = 1501,         ///< Inference error.
    ERR_ML_DATA_PREPROCESSING = 1502,///< Data preprocessing error.

    // User Interface Errors
    ERR_UI_RENDER = 1600,            ///< UI rendering error.
    ERR_UI_EVENT = 1601,             ///< UI event handling error.

    // API Errors
    ERR_API_GENERAL = 1700,          ///< General API error.
    ERR_API_LIMIT = 1701,            ///< API rate limit exceeded.
    ERR_API_RESPONSE = 1702,         ///< Invalid API response.

    // Cryptography Errors
    ERR_CRYPTO_GENERAL = 1800,       ///< General cryptography error.
    ERR_CRYPTO_KEY_GENERATION = 1801,///< Key generation error.
    ERR_CRYPTO_SIGNATURE = 1802,     ///< Digital signature error.

    // File System Errors
    ERR_FS_GENERAL = 1900,           ///< General filesystem error.
    ERR_FS_DIRECTORY_NOT_FOUND = 1901,///< Directory not found.
    ERR_FS_READ_ONLY = 1902,         ///< Filesystem is read-only.

    // General Purpose Errors
    ERR_UNKNOWN = 2000,              ///< Unknown error.
    ERR_NOT_FOUND = 2001,            ///< Requested item not found.
    ERR_ALREADY_EXISTS = 2002,       ///< Item already exists.
    ERR_NOT_AVAILABLE = 2003,        ///< Item not available.
    ERR_READ_ONLY = 2004,            ///< Data is read-only.
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

/**
 * @def SWAP(a, b, type)
 * @brief Swaps the values of two variables of the same type.
 *
 * This macro swaps the values of two variables `a` and `b`, both of which 
 * must be of the same type. It uses a temporary variable to hold the value 
 * of `a` while assigning `b` to `a`, and then assigns the value stored in the 
 * temporary variable to `b`. This is useful for in-place swapping without 
 * creating deep copies or additional memory allocations.
 *
 * @param[in, out] a First variable, passed by reference, to be swapped with `b`.
 * @param[in, out] b Second variable, passed by reference, to be swapped with `a`.
 * @param[in] type The type of the variables `a` and `b`. This ensures that the 
 *        macro is type-safe and works only when both variables are of the same type.
 *
 * @warning Both `a` and `b` must be valid pointers of the same type. 
 * Using this macro with different types, or with invalid pointers, 
 * can lead to undefined behavior.
 *
 * Potential Pitfalls:
 * - Ensure that both `a` and `b` are valid pointers.
 * - Ensure that `a` and `b` point to objects of the same type.
 * - Do not use this macro for complex types that require special handling (like structs with dynamic memory).
 * - Be cautious with const-qualified pointers, as the macro attempts to modify values, which is illegal for const-qualified objects.
 */
#define SWAP(a, b, type)    type temp = a; \
                            *a = b;        \
                            *b = temp;
                            
#endif // ELLIPSE_2_TYPES_H_
