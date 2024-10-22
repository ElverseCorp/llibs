#ifndef ELLIPSE_2_STR_H_
#define ELLIPSE_2_STR_H_

/**************************************************************************//**
 * @file     types.h
 * @brief    Ellipse strings for C/C++.
 * @version  V0.3.0
 * @date     30. Sep 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include "types.h"

/////////////////////////////////////////////
///////////// Types definition ////////////// 
/////////////////////////////////////////////

/**
 * @typedef cstr_t
 * @brief Alias for constant pointer to char_t (C-string).
 * @details Used for passing constant strings to functions, ensuring immutability.
 */
typedef const char_t* cstr_t;

/**
 * @typedef str_t
 * @brief Alias for pointer to char_t (mutable string).
 * @details Used for passing mutable strings, allowing modification.
 */
typedef char_t* str_t;

/**
 * @typedef cstr_utf8_t
 * @brief Alias for constant pointer to UTF-8 encoded data (immutable).
 * @details Used to represent constant UTF-8 encoded strings.
 */
typedef const u8_t* cstr_utf8_t;

/**
 * @typedef str_utf8_t
 * @brief Alias for pointer to UTF-8 encoded data (mutable).
 * @details Used to represent UTF-8 encoded strings that can be modified.
 */
typedef u8_t* str_utf8_t;

/**
 * @enum xstr_encode_t
 * @brief Enumeration of supported string encoding formats.
 * @details Used to specify the encoding of the string content within the xstr_t structure.
 */
typedef enum {

    XSTR_ENCODE_ASCII,    /**< ASCII encoding. */
    XSTR_ENCODE_UTF8,     /**< UTF-8 encoding. */
    XSTR_ENCODE_UTF16LE,  /**< UTF-16 Little Endian encoding. */
    XSTR_ENCODE_UTF16BE,  /**< UTF-16 Big Endian encoding. */
    XSTR_ENCODE_UTF32LE,  /**< UTF-32 Little Endian encoding. */
    XSTR_ENCODE_UTF32BE,  /**< UTF-32 Big Endian encoding. */

    XSTR_ENCODE_UNKNOWN,  /**< Unknown or unsupported encoding. */
} xstr_encode_t;

/**
 * @struct xstr_t
 * @brief Extended string structure to manage various encodings and metadata.
 * @details This structure allows for flexible management of string encodings, length, and associated functions.
 */
typedef struct {

    /**
     * @struct meta
     * @brief Metadata about the string.
     * @details Stores the encoding type and whether the string is mutable.
     */
    struct {
        xstr_encode_t encode; /**< Encoding format of the string (e.g., UTF-8, ASCII). */
        bool is_mutable;      /**< Indicates if the string is mutable. */
    } meta;

    /**
     * @struct content
     * @brief The actual content of the string.
     * @details Stores the pointer to the string data, its length in characters, and its size in bytes.
     */
    struct {
        void* data;   /**< Pointer to the string data (encoding-specific). */
        len_t length; /**< Length of the string in characters. */
        size_t size;  /**< Size of the string in bytes. */
    } content;

    /**
     * @struct functions
     * @brief Function pointers to operations on the string.
     * @details Contains function pointers for common string operations (length, size, decoding).
     */
    struct {
        len_t (*str_len)(void*);             /**< Private function to calculate the length of the string in characters. */
        size_t (*str_size)(void*);           /**< Private function to calculate the size of the string in bytes. */
        void* (*str_decode)(void*, size_t*); /**< Private function to decode the string data. */
    } functions;
    
} xstr_t;

/////////////////////////////////////////////
/////////// Function declaration //////////// 
/////////////////////////////////////////////

/**
 * @brief Get the length of an ASCII string.
 * @param[in] string The C-string to measure.
 * @return The length of the string in characters.
 */
extern len_t str_len(cstr_t string[static 1]);

/**
 * @brief Compare two ASCII strings lexicographically.
 * @param[in] string1 First string for comparison.
 * @param[in] string2 Second string for comparison.
 * @return A negative value if string1 is less than string2, 
 *         zero if they are equal, and a positive value if string1 is greater.
 */
extern ssize_t str_compare(cstr_t string1[static 1], cstr_t string2[static 1]);

/**
 * @brief Concatenate two ASCII strings.
 * @param[out] dest The destination string to append to.
 * @param[in] src The source string to append.
 */
extern void str_concatenate(str_t dest, cstr_t src[static 1]);

/**
 * @brief Copy one ASCII string to another.
 * @param[out] dest The destination string buffer.
 * @param[in] src The source string to copy.
 */
extern void str_copy(str_t dest, cstr_t src[static 1]);

/**
 * @brief Move one ASCII string to another.
 * @param[out] dest The destination string.
 * @param[in,out] src The source string, which may be invalidated.
 */
extern void str_move(str_t dest, str_t src);

/**
 * @brief Find the first occurrence of a character in an ASCII string.
 * @param[in] string The C-string to search in.
 * @param[in] character The character to search for.
 * @return The index of the first occurrence of the character, or -1 if not found.
 */
extern len_t str_find(cstr_t string[static 1], char_t character);

/**
 * @brief Find a substring within an ASCII string.
 * @param[in] string The string to search within.
 * @param[in] substring The substring to search for.
 * @return The index of the first occurrence of the substring, or -1 if not found.
 */
extern len_t str_substr(cstr_t string[static 1], cstr_t substring[static 1]);

// UTF-8

/**
 * @brief Decode a UTF-8 encoded string.
 * @param[in] string The UTF-8 string to decode.
 * @param[out] pointer A pointer to the decoded data.
 * @return Pointer to the decoded string.
 */
extern str_utf8_t str_utf8_decode(str_utf8_t string[static 1], size_t* pointer);

/**
 * @brief Get the length of a UTF-8 string in characters.
 * @param[in] string The UTF-8 string to measure.
 * @return The length of the string in characters.
 */
extern len_t str_utf8_len(cstr_utf8_t string[static 1]);

/**
 * @brief Get the size of a UTF-8 string in bytes.
 * @param[in] string The UTF-8 string to measure.
 * @return The size of the string in bytes.
 */
extern size_t str_utf8_size(cstr_utf8_t string[static 1]);

/**
 * @brief Get the size of a UTF-8 string for a specific number of characters.
 * @param[in] string The UTF-8 string to measure.
 * @param[in] n The number of characters to consider.
 * @return The size of the string in bytes for the specified number of characters.
 */
extern size_t str_utf8_size_n(cstr_utf8_t string[static 1], len_t n);

/**
 * @brief Compare two UTF-8 encoded strings lexicographically.
 * @param[in] string1 First UTF-8 string for comparison.
 * @param[in] string2 Second UTF-8 string for comparison.
 * @return A negative value if string1 is less than string2, 
 *         zero if they are equal, and a positive value if string1 is greater.
 */
extern ssize_t str_utf8_compare(cstr_utf8_t string1[static 1], cstr_utf8_t string2[static 1]);

/**
 * @brief Concatenate two UTF-8 strings.
 * @param[out] dest The destination UTF-8 string.
 * @param[in] src The source UTF-8 string.
 * @return Pointer to the destination string.
 */
extern str_utf8_t* str_utf8_concatenate(str_utf8_t dest, cstr_utf8_t src[static 1]);

/**
 * @brief Copy one UTF-8 string to another.
 * @param[out] dest The destination UTF-8 string.
 * @param[in] src The source UTF-8 string to copy.
 */
extern void str_utf8_copy(str_utf8_t dest, cstr_utf8_t src[static 1]);

/**
 * @brief Move one UTF-8 string to another.
 * @param[out] dest The destination UTF-8 string.
 * @param[in,out] src The source UTF-8 string, which may be invalidated.
 */
extern void str_utf8_move(str_utf8_t dest, str_utf8_t src);

/**
 * @brief Find the first occurrence of a character in a UTF-8 string.
 * @param[in] string The UTF-8 string to search.
 * @param[in] character The character to search for.
 * @return The index of the first occurrence of the character, or -1 if not found.
 */
extern len_t str_utf8_find(cstr_utf8_t string[static 1], char_t character);

/**
 * @brief Find a substring within a UTF-8 string.
 * @param[in] string The UTF-8 string to search.
 * @param[in] substring The substring to search for.
 * @return The index of the first occurrence of the substring, or -1 if not found.
 */
extern len_t str_utf8_substr(cstr_utf8_t string[static 1], cstr_utf8_t substring[static 1]);


// XSTR

/**
 * @def XSTR_INITIAL_ALLOCATION
 * @brief Initial allocation size for dynamic extended string management.
 */
#define XSTR_INITIAL_ALLOCATION 4096UL

/**
 * @brief Create an extended string (xstr_t) with specific encoding and mutability.
 * @param[in] data Pointer to the initial string data.
 * @param[in] encode Encoding format (e.g., UTF-8, ASCII).
 * @param[in] is_mutable Indicates if the string is mutable.
 * @return An initialized xstr_t structure.
 */
extern xstr_t xstr_create(void* data, xstr_encode_t encode, bool is_mutable);

/**
 * @brief Delete an extended string and free associated memory.
 * @param[in,out] string Pointer to the extended string to delete.
 */
extern void xstr_delete(xstr_t* string);

/**
 * @brief Check if the extended string is mutable.
 * @param[in] string The extended string to check.
 * @return true if the string is mutable, false otherwise.
 */
extern bool xstr_is_mutable(xstr_t string);

/**
 * @brief Get the length of an extended string in characters.
 * @param[in] string The extended string to measure.
 * @return The length of the string in characters.
 */
extern len_t xstr_len(xstr_t string);

/**
 * @brief Get the size of an extended string in bytes.
 * @param[in] string The extended string to measure.
 * @return The size of the string in bytes.
 */
extern len_t xstr_size(xstr_t string);

/**
 * @brief Insert a substring into an extended string at a specified position.
 * @param[in,out] dest The destination string to modify.
 * @param[in] n The position to insert the substring.
 * @param[in] src The source substring to insert.
 * @return Error code indicating success or failure.
 */
extern err_t xstr_insert(xstr_t* dest, len_t n, xstr_t src);

/**
 * @brief Append one extended string to another.
 * @param[in,out] dest The destination string.
 * @param[in] src The source string to append.
 * @return The length of the resulting string.
 */
extern len_t xstr_append(xstr_t* dest, xstr_t* src);

/**
 * @brief Concatenate raw data into an extended string.
 * @param[in,out] dest The destination extended string.
 * @param[in] data The raw data to concatenate.
 * @param[in] encode The encoding of the raw data.
 * @return The length of the resulting string.
 */
extern len_t xstr_concatenate(xstr_t* dest, void* data, xstr_encode_t encode);

/**
 * @brief Assign new data to an extended string.
 * @param[in,out] dest The destination extended string.
 * @param[in] data The new data to assign.
 * @param[in] encode The encoding of the new data.
 * @return The length of the resulting string.
 */
extern len_t xstr_assign(xstr_t* dest, void* data, xstr_encode_t encode);

/**
 * @brief Find data within an extended string.
 * @param[in] string The extended string to search.
 * @param[in] data The data to search for.
 * @return The index of the first occurrence, or -1 if not found.
 */
extern len_t xstr_find(xstr_t string, void* data);

/**
 * @brief Find a substring within an extended string.
 * @param[in] string The extended string to search.
 * @param[in] substring The substring to search for.
 * @return The index of the first occurrence, or -1 if not found.
 */
extern len_t xstr_substring(xstr_t string, xstr_t substring);

/**
 * @brief Compare two extended strings lexicographically.
 * @param[in] string1 The first extended string.
 * @param[in] string2 The second extended string.
 * @return A negative value if string1 is less than string2, 
 *         zero if they are equal, and a positive value if string1 is greater.
 */
extern ssize_t xstr_compare(xstr_t string1, xstr_t string2);

/**
 * @brief Optimize an extended string by minimizing memory usage.
 * @param[in] string The extended string to optimize.
 * @return The length of the optimized string.
 */
extern len_t xstr_optimize(xstr_t string);

/**
 * @brief Get the encoding of a raw data string.
 * @param[in] data The raw data to analyze.
 * @return The encoding type (e.g., UTF-8, ASCII).
 */
extern xstr_encode_t xstr_get_encode(void* data);

#endif // ELLIPSE_2_STR_H_
