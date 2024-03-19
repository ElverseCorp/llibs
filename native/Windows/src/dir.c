/* Include llibs.h header */
#include <llibs.h>
#include <windows.h>

/* Files */

lerr ldircreate(lc dirname[]) {
    return (lerr)!(CreateDirectoryA((char*)dirname, NULL) || GetLastError());
}