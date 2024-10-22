#ifndef ELLIPSE_2_H_
#define ELLIPSE_2_H_

/**************************************************************************//**
 * @file     llibs.h
 * @brief    Project L - Ellipse, cross-platform framework. Main header for C.
 * @version  V0.3.0
 * @date     30. Sep 2024
 * @author   Matvey Rybalkin
******************************************************************************/

/*
 * Llibs framework. (Ellipse)
 * Cross-platform framework with native adaptibility for each platform and OS.
 *
 * Author: Matvey Rybalkin
 * Contact: robotsvision.vx@gmail.com (github.com robotsvision/llibs)
 * Date: 5 Jan. 2024
 *
 * This file is part of Llibs framework. And this project is a part of Project L.
 *
 * Llibs is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * Llibs is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with Llibs. If not, see <http://www.gnu.org/licenses/>.
 */

#undef __cplusplus
#ifndef __cplusplus

#define ELLIPSE_VERSION 2.0
#define ELLIPSE_VERSION_CSTR "0.2.0"
#define ELLIPSE_LANGUAGE_C
#ifdef ELLIPSE_LANGUAGE_CPP
#   undef ELLIPSE_LANGUAGE_CPP
#endif
#define ELLIPSE_LANGUAGE_CSTR "C"


// Include every header file
#include <c/types.h>
#include <c/str.h>
#include <c/mem.h>
#include <c/time.h>
#include <c/bits.h>

#include <c/io.h>
#include <c/threads.h>
#include <c/locale.h>

// Math
#include <c/main.h>
#include <c/math/complex.h>

// Advanced
#include <c/structures/stack.h>
#include <c/structures/vector.h>

#else
#   error "[ELLIPSE] ERROR: This header file is designed for use in C files. HELP: Use llibs.hpp instead."
#endif
#endif // ELLIPSE_H_