#ifndef LLIBS_H_
#define LLIBS_H_

#if __STDC_VERSION__  < 201112L
#error "[llibs.h]: Requires at least version C 2011 (__STDC_VERSION__ >= 201112L)"
#else

#include "llibs/types.h"
#include "llibs/errors.h"
#include "llibs/memory.h"
#include "llibs/str.h"
#include "llibs/main.h"

#endif // __STDC_VERSION__  >= 201112L
#endif // LLIBS_H_
