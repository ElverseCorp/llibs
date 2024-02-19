
/* Include libraries */
#include "lfiles.defs.h"

static HANDLE llibs_GetFileHandle(lchar_t filename[]) {
    return CreateFile(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
} /* I'm not sure about this argument lchar_t filename[] */

static HANDLE llibs_GetMapHandle(HANDLE fileHandle) {
    return CreateFileMapping(fileHandle, NULL, PAGE_READONLY, 0, 0, NULL);
}

static LPCVOID llibs_GetMapView(HANDLE mapHandle) {
    return MapViewOfFile(mapHandle, FILE_MAP_READ, 0, 0, 0);
}

static LONGLONG llibs_GetFileSize(HANDLE fileHandle) {
    LARGE_INTEGER size;
    if (!GetFileSizeEx(fileHandle, &size)) {
        return -1;
    }
    return size.QuadPart;
}

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