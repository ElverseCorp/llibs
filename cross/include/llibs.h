#ifndef LLIBS_FRAMEWORK_H_
#define LLIBS_FRAMEWORK_H_

/**************************************************************************//**
 * @file     llibs.h
 * @brief    Project L - Llibs, cross-platform framework
 * @version  V0.2.0
 * @date     5. Jan 2024
 * @author   Matvey Rybalkin
******************************************************************************/

/*
 * Llibs framework.
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


/* Check C standard */
#if __STDC_VERSION__  >= 201112L

/* Include standard libraries */
#include "defs.h"
#include "types.h"
#include "string.h"
#include "thread.h"
#include "mem.h"
#include "io.h"
#include "file.h"
#include "main.h"

extern lerr llibs_init(void); 

/* Include external submodules */

#include "../../external/external.h"

#else /* ERROR (__STDC_VERSION__ >= 201112L) */
#error [llibs.h]: Requires at least version C 2011 (__STDC_VERSION__ >= 201112L)
#endif
#endif // LLIBS_FRAMEWORK_H_