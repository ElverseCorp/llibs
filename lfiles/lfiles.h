#ifndef __L_FILES_H__
#define __L_FILES_H__

/**************************************************************************//**
 * @file     lfiles.h
 * @brief    Project L - Cross-platform files library (for Lena lang)
 * @version  V0.0.3
 * @date     31. Dec 2023
 ******************************************************************************/

/* Standard libraries */
#include <stdlib.h>
#include <stdint.h>

/* Llibs */
#include "ltypes.h"

/* For Windows */
#ifdef _WIN32

#include <windows.h>

#ifdef UNICODE
#include <wchar.h>
HANDLE llibs_GetFileHandle(lchar_t filename[]) {
    return CreateFileW(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
}
#else 
HANDLE llibs_GetFileHandle(lchar_t filename[]) {
    return CreateFileA(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
}
#endif

HANDLE llibs_GetMapHandle(HANDLE fileHandle) {
    return CreateFileMapping(fileHandle, NULL, PAGE_READONLY, 0, 0, NULL);
}

LPCVOID llibs_GetMapView(HANDLE mapHandle) {
    return MapViewOfFile(mapHandle, FILE_MAP_READ, 0, 0, 0);
}

LONGLONG llibs_GetFileSize(HANDLE fileHandle) {
    LARGE_INTEGER size;
    if (!GetFileSizeEx(fileHandle, &size)) {
        return -1;
    }
    return size.QuadPart;
}

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

lfile_status_t lfopen(lfile_t* lfile, lchar_t* filename){
    lfile->fileHandle = llibs_GetFileHandle(filename);
    if (lfile->fileHandle == NULL) { 
        CloseHandle(lfile->fileHandle);
        return LFILE_OPEN_FAILURE; 
    }
    lfile->mapHandle = llibs_GetMapHandle(lfile->fileHandle);
    if (lfile->mapHandle == NULL) {
        CloseHandle(lfile->mapHandle);
        CloseHandle(lfile->fileHandle);
        return LFILE_MAP_HANDLE_FAILURE;
    };
    lfile->mapView = llibs_GetMapView(lfile->mapHandle);
    if (lfile->mapView == NULL) {
        UnmapViewOfFile(lfile->mapView);
        CloseHandle(lfile->mapHandle);
        CloseHandle(lfile->fileHandle);
        return LFILE_MAP_VIEW_FAILURE;
    };
    lfile->size = llibs_GetFileSize(lfile->fileHandle);
    if (lfile->size == -1) {
        UnmapViewOfFile(lfile->mapView);
        CloseHandle(lfile->mapHandle);
        CloseHandle(lfile->fileHandle);
        return LFILE_SIZE_FAILURE; 
    };
    return LFILE_SUCCESS;
}

lchar_t* lfget_pointer(lfile_t* lfile){
    return (lchar_t *)(lfile->mapView);
}

void lfclose(lfile_t* lfile){
    UnmapViewOfFile(lfile->mapView);
    CloseHandle(lfile->mapHandle);
    CloseHandle(lfile->fileHandle);
    lfile->size = 0;
}

#else       /* LINUX / UNIX */

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

lfile_status_t lfopen(lfile_t* lfile, lchar_t* filename) {
    int file_descriptor;
    size_t size;
    struct stat file_stat;
    char* buffer = NULL;

    file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor < 0) {
        return LFILE_OPEN_FAILURE;
    }

    if (fstat(file_descriptor, &file_stat) < 0) {
        close(file_descriptor);
        return LFILE_SIZE_FAILURE;
    }

    size = file_stat.st_size;
    buffer = (lchar_t*)malloc(size);
    if (buffer == NULL) {
        close(file_descriptor);
        return LFILE_MEMORY_FAILURE;
    }

    if (read(file_descriptor, buffer, size) < 0) {
        free(buffer);
        close(file_descriptor);
        return LFILE_READING_FAILURE;
    }

    close(file_descriptor);

    lfile->data = buffer;
    lfile->size = size;

    return LFILE_SUCCESS;
}

lchar_t* lfget_pointer(lfile_t* lfile){
    return (lchar_t *)(lfile->data);
}

void lfclose(lfile_t* lfile) {
    free(lfile->data);
    lfile->size = 0;
}

#endif // Linux
#endif // lchar_t is defined
#endif // __L_FILES_H__