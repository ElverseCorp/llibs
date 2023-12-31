#ifndef __L_FILES_H__
#define __L_FILES_H__

/**************************************************************************//**
 * @file     lfiles.h
 * @brief    Project L - Cross-platform files library (for Lina/Lena/Lisa langs)
 * @version  V0.0.1
 * @date     31. Dec 2023
 ******************************************************************************/

#ifdef _WIN32

#include <windows.h>

HANDLE lena_GetFileHandle(char filename[]) {
    return CreateFileA(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
}

HANDLE lena_GetMapHandle(HANDLE fileHandle) {
    return CreateFileMapping(fileHandle, NULL, PAGE_READONLY, 0, 0, NULL);
}

LPCVOID lena_GetMapView(HANDLE mapHandle) {
    return MapViewOfFile(mapHandle, FILE_MAP_READ, 0, 0, 0);
}

LONGLONG lena_GetFileSize(HANDLE fileHandle) {
    LARGE_INTEGER fileSize;
    if (!GetFileSizeEx(fileHandle, &fileSize)) {
        return -1;
    }
    return fileSize.QuadPart;
}

typedef struct {
    HANDLE fileHandle;
    HANDLE mapHandle;
    LPCVOID mapView;
    int64_t fileSize;
} lena_file_t;

typedef uint8_t lena_file_status_t;

enum lena_file_status{
    LENA_FILE_SUCCESS               = 0,
    LENA_FILE_OPEN_FAILURE          = 1,
    LENA_FILE_MAP_HANDLE_FAILURE    = 2,
    LENA_FILE_MAP_VIEW_FAILURE      = 3,
    LENA_FILE_SIZE_FAILURE          = 4
};

lena_file_status_t lena_OpenFile(lena_file_t *lena_file, char filename[]){
    lena_file->fileHandle = lena_GetFileHandle(filename);
    if (lena_file->fileHandle == NULL) { 
        CloseHandle(lena_file->fileHandle);
        return LENA_FILE_OPEN_FAILURE; 
    }
    lena_file->mapHandle = lena_GetMapHandle(lena_file->fileHandle);
    if (lena_file->mapHandle == NULL) {
        CloseHandle(lena_file->mapHandle);
        CloseHandle(lena_file->fileHandle);
        return LENA_FILE_MAP_HANDLE_FAILURE;
    };
    lena_file->mapView = lena_GetMapView(lena_file->mapHandle);
    if (lena_file->mapView == NULL) {
        UnmapViewOfFile(lena_file->mapView);
        CloseHandle(lena_file->mapHandle);
        CloseHandle(lena_file->fileHandle);
        return LENA_FILE_MAP_VIEW_FAILURE;
    };
    lena_file->fileSize = lena_GetFileSize(lena_file->fileHandle);
    if (lena_file->fileSize == -1) {
        UnmapViewOfFile(lena_file->mapView);
        CloseHandle(lena_file->mapHandle);
        CloseHandle(lena_file->fileHandle);
        return LENA_FILE_SIZE_FAILURE; 
    };
    return LENA_FILE_SUCCESS;
}

char* lena_GetFilePointer(lena_file_t lena_file){
    return (char *)(lena_file.mapView);
}

void lena_DeleteFile(lena_file_t lena_file){
    UnmapViewOfFile(lena_file.mapView);
    CloseHandle(lena_file.mapHandle);
    CloseHandle(lena_file.fileHandle);
}

#else       /* LINUX / UNIX */

#include <stdio.h>

FILE* lena_GetfileHandle(char filename[]){
    return fopen(filename, "rb");
}

long lena_GetFileSize(FILE *file){
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}

char* lena_GetFileData(int64_t fileSize){
    return malloc(fileSize);
}

typedef struct {
    FILE *fileHandle;
    int64_t fileSize;
    char *filePointer;
} lena_file_t;

typedef uint8_t lena_file_status_t;

enum lena_file_status{
    LENA_FILE_SUCCESS               = 0,
    LENA_FILE_OPEN_FAILURE          = 1,
    LENA_FILE_MEMORY_ALLOC_FAILURE  = 2,
};

lena_file_status_t lena_OpenFile(lena_file_t *lena_file, char filename[]){
    lena_file->fileHandle = lena_GetfileHandle(filename);
    if (lena_file->fileHandle == NULL){
        return LENA_FILE_OPEN_FAILURE;
    }
    lena_file->fileSize = lena_GetFileSize(lena_file->fileHandle);
    lena_file->filePointer = lena_GetFileData(lena_file->fileSize);
    if (lena_file->filePointer == NULL){
        fclose(lena_file->fileHandle);
        return LENA_FILE_MEMORY_ALLOC_FAILURE;
    }
    fread(lena_file->filePointer, 1, lena_file->fileSize, lena_file->fileHandle);
    return LENA_FILE_SUCCESS;
}


char* lena_GetFilePointer(lena_file_t lena_file){
    return (lena_file.filePointer);
}

void lena_DeleteFile(lena_file_t lena_file){
    fclose(lena_file.fileHandle);
    free(lena_file.filePointer);
}

#endif

#endif // __L_FILES_H__