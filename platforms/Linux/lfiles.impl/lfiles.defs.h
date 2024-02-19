#ifndef __L_FILES_LINUX_DEFS_H__
#define __L_FILES_LINUX_DEFS_H__

/**************************************************************************//**
 * @file     lfiles.defs.h
 * @brief    Project L - Native Linux files definitions library for Llibs framework
 * @version  V0.0.1
 * @date     13. Feb 2023
 ******************************************************************************/


#include <fcntl.h>
#include <unistd.h> 
#include <sys/stat.h>
#include <stdlib.h>

typedef struct {
    lchar_t* data;  // data pointer
    int64_t size;   // size in bytes
} lfile_t;


enum lfile_status{
    LFILE_SUCCESS               = 0,
    LFILE_OPEN_FAILURE          = 1,
    LFILE_MEMORY_FAILURE        = 2,
    LFILE_READING_FAILURE       = 3,
    LFILE_SIZE_FAILURE          = 4
};

typedef uint8_t lfile_status_t;

#endif // __L_FILES_LINUX_DEFS_H__