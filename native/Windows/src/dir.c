/* Include llibs.h header */
#include <llibs.h>
#include <windows.h>

/* Files */

lerr ldirmk(lc dirname[]) {
    return (lerr)!(CreateDirectoryA((char*)dirname, NULL) || GetLastError());
}

lerr ldirrm(lc dirname[]) {
    return (lerr)!(RemoveDirectoryA((char*)dirname) || GetLastError());
}