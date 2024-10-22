#ifndef ELLIPSE_2_MATH_SPACE_H_
#define ELLIPSE_2_MATH_SPACE_H_

/**************************************************************************//**
 * @file     math.h
 * @brief    Ellipse mathematic for C.
 * @version  V0.3.0
 * @date     22. Oct 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include <c/types.h>

/////////////////////////////////////////////
///////////// Types definition //////////////
/////////////////////////////////////////////

typedef struct {
    f64_t x;
    f64_t y;
} point2d_64_t;

typedef struct {
    f64_t x;
    f64_t y;
    f64_t z;
} point3d_64_t;

#ifdef __SIZEOF_FLOAT128__

typedef struct {
    f128_t x;
    f128_t y;
} point2d_128_t;

typedef struct {
    f128_t x;
    f128_t y;
    f128_t z;
} point3d_128_t;

#endif

typedef struct {
    fmax_t x;
    fmax_t y;
} point2d_t;

typedef struct {
    fmax_t x;
    fmax_t y;
    fmax_t z;
} point3d_t;

typedef point2d_64_t vector2d_64_t;
typedef point3d_64_t vector2d_64_t;

#ifdef __SIZEOF_FLOAT128__
typedef point2d_t vector2d_128_t;
typedef point3d_t vector3d_128_t;
#endif
typedef point2d_t vector2d_t;
typedef point3d_t vector3d_t;

#endif // ELLIPSE_2_MATH_SPACE_H_