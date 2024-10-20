#ifndef ELLIPSE_2_IO_HPP_
#define ELLIPSE_2_IO_HPP_

/**************************************************************************//**
 * @file     io.h
 * @brief    Project L - Ellipse, cross-platform framework. Input/Output header.
 * @version  V0.3.0
 * @date     30. Sep 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include <llibs.hpp>

namespace ll {

/*************************************************************
 * CONSOLE
 ************************************************************/

/// @brief Ellipse framework / Console namespace
namespace console {

// Minimal functions

/**
 * @brief Writes a specified number of bytes 
 * from text to the console.
 * 
 * If the `size_in_bytes` is negative, then the text is 
 * output up to the zero character `\0`.
 * 
 * @param[in] str string pointer. 
 * @param[in] size_in_bytes number of bytes to be written to the console.
 */ 
extern void write(ConstStr str, SSize size_in_bytes);

/**
 * @brief Reads a specified number of bytes
 * from the console, the buffer is not allocated automatically.
 * 
 * @param[out] buffer target buffer.
 * @param[out] size_in_bytes number of bytes to be read from the console.
 * @returns total size of bytes read from console.
 */ 
extern Size read(Char* buffer, SSize size_in_bytes);

// Console output


template<typename T>
extern void print(T var);
extern void print(ConstStr format, ...);

// Console input

template<typename T>
extern T scan(void);
extern UInt32 scan(ConstStr format, ...);

// Console errors

extern void print_error(ConstStr message); 

}


/*************************************************************
 * FILES
 ************************************************************/

/// @brief Ellipse framework / File namespace
namespace file {

typedef struct {
    ConstStr name;
    enum access {
        READ    = 0b001,
        WRITE   = 0b010,
        APPEND  = 0b100,
    };
} Conf;

typedef void* Handler;

extern Error open(Handler file, Conf conf);
extern void close(Handler file);

}

}
 
#endif // ELLIPSE_2_IO_HPP_