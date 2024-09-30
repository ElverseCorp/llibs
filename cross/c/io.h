#ifndef ELLIPSE_2_IO_H_
#define ELLIPSE_2_IO_H_

/**************************************************************************//**
 * @file     io.h
 * @brief    Project L - Ellipse, cross-platform framework. Input/Output header.
 * @version  V0.3.0
 * @date     30. Sep 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include <llibs.h>

/*************************************************************
 * CONSOLE
 ************************************************************/

// Minimal functions

extern void ll_ConsoleWrite(ll_ConstStr str, ll_Len num_of_symbols);
extern void ll_ConsoleRead(ll_Char* buffer, ll_Len num_of_symbols);

// Console output

extern ll_Len ll_PrintInt(ll_Int64 number);
extern ll_Len ll_PrintUInt(ll_UInt64 number);
extern ll_Len ll_PrintFloat(ll_Float128 number, ll_Len num_of_frac_chars);
extern ll_Len ll_PrintChar(ll_Char character);

extern ll_Len ll_Print(ll_ConstStr format, ...);
 
// Console input

extern ll_UInt32 ll_Scan(ll_ConstStr format, ...);

// Console errors

extern void ll_PrintError(ll_ConstStr message); 

/*************************************************************
 * FILES
 ************************************************************/

typedef struct {
    ll_ConstStr name;
    enum access {
        FILE_READ    = 0b001,
        FILE_WRITE   = 0b010,
        FILE_APPEND  = 0b100,
    };
} ll_FileConf;

typedef void* ll_Handler;

extern ll_Error open(ll_Handler file, ll_FileConf conf);
extern void close(ll_Handler file);

#endif // ELLIPSE_2_IO_H_