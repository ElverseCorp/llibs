
/* Include libraries */
#include "lfiles.defs.h"

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

void lfclose(lfile_t* lfile) {
    free(lfile->data);
    lfile->size = 0;
}