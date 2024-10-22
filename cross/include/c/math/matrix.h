#ifndef ELLIPSE_2_MATH_MATRIX_H_
#define ELLIPSE_2_MATH_MATRIX_H_

/**************************************************************************//**
 * @file     matrix.h
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
    len_t n;
    len_t m;
    fmax_t* data;
} matrix_64_t;

#ifdef __SIZEOF_FLOAT128__

typedef struct {
    len_t n;
    len_t m;
    f128_t* data;
} matrix_t;

#endif

typedef struct {
    len_t n;
    len_t m;
    fmax_t* data;
} matrix_t;

void matrix_mul(matrix_t* matrix1, matrix_t matrix2);
void matrix_sum(matrix_t* matrix1, matrix_t matrix2);
void matrix_trpos(matrix_t* matrix);

fmax_t matrix_det(matrix_t matrix);


#endif // ELLIPSE_2_MATH_MATRIX_H_