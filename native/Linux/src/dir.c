/* Include llibs.h header */
#include <llibs.h>
#include <sys/stat.h>
#include <sys/types.h>

/* Files */

lerr ldirmk(const lc dirname[]) {
    return (lerr)!(mkdir(dirname, 0755) == 0);
}

lerr ldirrm(const lc dirname[]) {
    return (lerr)!(rmdir(dirname) == 0);
}