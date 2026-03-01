

#ifndef LMAIN_H_
#define LMAIN_H_

#include "types.h"
#include "str.h"

typedef enum {
	LEXIT_SUCCESS,
	LEXIT_FAILURE
} lexit;

extern lexit lmain(li32 argc, lstr* argv);

#endif // LMAIN_H_
