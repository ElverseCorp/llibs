#ifndef ELLIPSE_2_BITS_H_
#define ELLIPSE_2_BITS_H_

/**************************************************************************//**
 * @file     bits.h
 * @brief    Ellipse bits operation for C.
 * @version  V0.3.0
 * @date     22. Oct 2024
 * @author   Matvey Rybalkin
 ******************************************************************************/

#include <c/types.h>

/////////////////////////////////////////////
////////////// Type definition ////////////// 
///////////////////////////////////////////// 

/**
 * @typedef bitfield8_t
 * @brief 8-bit bitfield type alias.
 */
typedef u8_t    bitfield8_t;

/**
 * @typedef bitfield16_t
 * @brief 16-bit bitfield type alias.
 */
typedef u16_t   bitfield16_t;

/**
 * @typedef bitfield32_t
 * @brief 32-bit bitfield type alias.
 */
typedef u32_t   bitfield32_t;

/**
 * @typedef bitfield64_t
 * @brief 64-bit bitfield type alias.
 */
typedef u64_t   bitfield64_t;

#ifdef __SIZEOF_INT128__
/**
 * @typedef bitfield128_t
 * @brief 128-bit bitfield type alias, if supported.
 */
typedef u128_t  bitfield128_t;
#endif

/////////////////////////////////////////////
///////////// Macros definition ///////////// 
///////////////////////////////////////////// 

// Bits

/**
 * @def BIT_SET(var, pos)
 * @brief Sets the bit at the specified position to 1.
 * @param[in, out] var The variable in which the bit will be set.
 * @param[in] pos The bit position to set (0-based).
 */
#define BIT_SET(var, pos) var |= (1 << pos)

/**
 * @def BIT_CLEAR(var, pos)
 * @brief Clears the bit at the specified position (sets it to 0).
 * @param[in, out] var The variable in which the bit will be cleared.
 * @param[in] pos The bit position to clear (0-based).
 */
#define BIT_CLEAR(var, pos) var &= ~(1 << pos)

/**
 * @def BIT_TOGGLE(var, pos)
 * @brief Toggles the bit at the specified position (flips its value).
 * @param[in, out] var The variable in which the bit will be toggled.
 * @param[in] pos The bit position to toggle (0-based).
 */
#define BIT_TOGGLE(var, pos) var ^= (1 << pos)

/**
 * @def BIT_CHECK(var, pos)
 * @brief Checks the value of the bit at the specified position.
 * @param[in] var The variable in which the bit is checked.
 * @param[in] pos The bit position to check (0-based).
 * @return `true` if the bit is set to 1, `false` otherwise.
 */
#define BIT_CHECK(var, pos) (!!(var & (1 << pos)))

/**
 * @def BIT_WRITE(var, pos, value)
 * @brief Writes a bit value (0 or 1) to the specified position.
 * @param[in, out] var The variable in which the bit will be written.
 * @param[in] pos The bit position to modify (0-based).
 * @param[in] value The bit value to write (0 or 1).
 */
#define BIT_WRITE(var, pos, value) var = (var & ~(1 << pos)) | ((value & 1) << pos)

/**
 * @def BIT_READ(var, pos)
 * @brief Reads the bit value at the specified position.
 * @param[in] var The variable from which the bit is read.
 * @param[in] pos The bit position to read (0-based).
 * @return `true` if the bit is set to 1, `false` otherwise.
 */
#define BIT_READ(var, pos) BIT_CHECK(var, pos)

// Bytes

/**
 * @def BYTE_WRITE(var, pos, value)
 * @brief Writes a byte value to the specified byte position in the variable.
 * @param[in, out] var The variable in which the byte will be written.
 * @param[in] pos The byte position to modify (0-based).
 * @param[in] value The byte value to write.
 */
#define BYTE_WRITE(var, pos, value) var = (var & ~(0xFF << (pos * 8))) | ((u8_t)(value) << (pos * 8))

/**
 * @def BYTE_READ(var, pos)
 * @brief Reads the byte value at the specified byte position in the variable.
 * @param[in] var The variable from which the byte is read.
 * @param[in] pos The byte position to read (0-based).
 * @return The byte value at the specified position.
 */
#define BYTE_READ(var, pos) ((var >> (pos * 8)) & 0xFF)

// Halfs

/**
 * @def HALF_HIGH_MASK(_sizeof)
 * @brief Generates a mask for the upper half of the variable based on its size.
 * @param[in] _sizeof Size of the variable in bytes.
 * @return The mask for the upper half of the variable.
 */
#define HALF_HIGH_MASK(_sizeof) (((1ULL << ((_sizeof * 4))) - 1) << (_sizeof * 4))

/**
 * @def HALF_HIGH_GET(var, _sizeof)
 * @brief Retrieves the upper half of the variable.
 * @param[in] var The variable from which the upper half is extracted.
 * @param[in] _sizeof Size of the variable in bytes.
 * @return The value of the upper half.
 */
#define HALF_HIGH_GET(var, _sizeof) (var & HALF_HIGH_MASK(_sizeof))

/**
 * @def HALF_HIGH_SET(var, new_value, _sizeof)
 * @brief Sets the upper half of the variable to the specified value.
 * @param[in, out] var The variable in which the upper half will be set.
 * @param[in] new_value The new value for the upper half.
 * @param[in] _sizeof Size of the variable in bytes.
 */
#define HALF_HIGH_SET(var, new_value, _sizeof) \
    ((var & ((1ULL << (_sizeof * 4)) - 1)) | ((umax_t)(new_value) << (_sizeof * 4)))

/**
 * @def HALF_HIGH_TOGGLE(var, _sizeof)
 * @brief Toggles all bits in the upper half of the variable.
 * @param[in, out] var The variable in which the upper half will be toggled.
 * @param[in] _sizeof Size of the variable in bytes.
 */
#define HALF_HIGH_TOGGLE(var, _sizeof) \
    var ^= ((1ULL << ((_sizeof * 4))) - 1) << (_sizeof * 4)

/**
 * @def HALF_LOW_MASK(_sizeof)
 * @brief Generates a mask for the lower half of the variable based on its size.
 * @param[in] _sizeof Size of the variable in bytes.
 * @return The mask for the lower half of the variable.
 */
#define HALF_LOW_MASK(_sizeof) ((1ULL << (_sizeof * 4)) - 1)

/**
 * @def HALF_LOW_GET(var, _sizeof)
 * @brief Retrieves the lower half of the variable.
 * @param[in] var The variable from which the lower half is extracted.
 * @param[in] _sizeof Size of the variable in bytes.
 * @return The value of the lower half.
 */
#define HALF_LOW_GET(var, _sizeof) (var & HALF_LOW_MASK(_sizeof))

/**
 * @def HALF_LOW_SET(var, new_value, _sizeof)
 * @brief Sets the lower half of the variable to the specified value.
 * @param[in, out] var The variable in which the lower half will be set.
 * @param[in] new_value The new value for the lower half.
 * @param[in] _sizeof Size of the variable in bytes.
 */
#define HALF_LOW_SET(var, new_value, _sizeof) \
    ((var & ~((1ULL << (_sizeof * 4)) - 1)) | ((umax_t)(new_value) & ((1ULL << (_sizeof * 4)) - 1)))

/**
 * @def HALF_LOW_TOGGLE(var, _sizeof)
 * @brief Toggles all bits in the lower half of the variable.
 * @param[in, out] var The variable in which the lower half will be toggled.
 * @param[in] _sizeof Size of the variable in bytes.
 */
#define HALF_LOW_TOGGLE(var, _sizeof) \
    var ^= (1ULL << ((_sizeof * 4))) - 1

#endif // ELLIPSE_2_BITS_H_
