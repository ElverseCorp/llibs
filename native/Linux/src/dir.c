/* Include llibs.h header */
#include <llibs.h>
#include <sys/stat.h>
#include <sys/types.h>

/* Files */

lerr ldircreate(lc dirname[]) {
    return (lerr)(mkdir("new_directory", 0777) == -1);
}