# Llibs framework

## Basic information

* Based on C17 language
* Cross-platform
* Used as part of Project L in Lena and Light
* High-efficient and Native adaptability

*(Llibs - pronounced Ellipse)*

## Parts of Llibs

1) `lio` - like stdio library, supports `cio` and `fio` (*Console and Files*)
2) `lthreads` - supports cross-platform
3) `ldefs` - definitions
4) `ltypes` - types
5) `lmem` - memory allocation
6) `ltuples` - dynamic tuples, implemenation for C
7) `ldtypes` - dynamic data types, implementation for C

*And private part of the llibs:*
8) platforms folder for implementations.

## Examples

## Hello World

``` c
#include <llibs.h>

LMAIN(LARGC, LARGV) {
    lprint(l("Hello World!"));
    lexit(LLIBS_EXIT_SUCCESS);
}
```
