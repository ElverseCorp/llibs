/* Include llibs.h header */
#include <llibs.h>
#include <windows.h>

/* Files */

lerr ldirmk(const lc dirname[]) {
    return (lerr)!(CreateDirectoryA((char*)dirname, NULL) || GetLastError());
}

lerr ldirrm(const lc dirname[]) {
    return (lerr)!(RemoveDirectoryA((char*)dirname) || GetLastError());
}