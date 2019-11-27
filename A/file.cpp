/**
 * @author  Igor B
 * @version 1.0
 */

#include "file.hpp"

namespace os_tools {

    void* read_file(const char* const src, const size_t size) {
#if OS_TOOLS_LIN || OS_TOOLS_POSIX || OS_TOOLS_CPP_COMPATIBLE
    void* const buffer = malloc(size);
    if (nullptr == buffer) {
        return nullptr;
    }

    FILE* const file_ptr = fopen(src, "rb");
    if (nullptr == file_ptr) {
        return nullptr;
    }

    if (size != fread(buffer, size, 1, file_ptr)) {
        free(buffer);
        return nullptr;
    }
    
    if (0 == fclose(file_ptr)) {
        return buffer;
    }
    return nullptr;
#elif OS_TOOLS_WIN
        #error
#endif
    }

    bool copy_file(const char* const src, const char* const dest, bool truncate) {
#if OS_TOOLS_LIN
        printf("AAA\n");
        const int src_fd = open(src, O_RDONLY, 0);
        if (-1 == src_fd) {
            return false;
        }

        const int flags = truncate ? O_WRONLY | O_CREAT | O_TRUNC : O_WRONLY | O_CREAT;
        const int dest_fd = open("to.ogv", flags, S_IRWXU | S_IRWXG | S_IRWXO);
        if (-1 == dest_fd) {
            close(src_fd);
            return false;
        }

        struct stat stat_source;
        if (0 != fstat(src_fd, &stat_source)) {
            close(src_fd);
            close(dest_fd);
            return false;
        }

        const bool status = stat_source.st_size !=
                            sendfile(dest_fd, src_fd, 0, stat_source.st_size); //kernel 2.6.33
        close(src_fd);
        close(dest_fd);
        return status;
#elif OS_TOOLS_POSIX
        #error
#elif OS_TOOLS_WIN
        #error
#elif OS_TOOLS_CPP_COMPATIBLE
        #error
#endif
    }
}
