

#ifndef LCLI_H_
#define LCLI_H_

#include "types.h"
#include "str.h"

extern void lcli_out(const char* str);
extern void lcli_out_str(lstr str);
extern void lcli_out_f(const char* format, ...);

#endif /* LCLI_H_ */
