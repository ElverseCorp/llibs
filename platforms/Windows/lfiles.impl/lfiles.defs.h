#ifndef __L_FILES_WINDOWS_DEFS_H__
#define __L_FILES_WINDOWS_DEFS_H__

/**************************************************************************//**
 * @file     lfiles.defs.h
 * @brief    Project L - Native Windows files definitions library for Llibs framework
 * @version  V0.0.1
 * @date     13. Feb 2023
 ******************************************************************************/

#include <windows.h>

typedef struct {
    HANDLE fileHandle;
    HANDLE mapHandle;
    LPCVOID mapView;
    int64_t size;
} lfile_t;

typedef uint8_t lfile_status_t;

enum lfile_status{
    LFILE_SUCCESS               = 0,
    LFILE_OPEN_FAILURE          = 1,
    LFILE_MAP_HANDLE_FAILURE    = 2,
    LFILE_MAP_VIEW_FAILURE      = 3,
    LFILE_SIZE_FAILURE          = 4
};

#endif // __L_FILES_WINDOWS_DEFS_H__