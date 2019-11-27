/**
 * @author  Igor B
 * @version 1.0
 */

#pragma once
#ifndef OS_TOOLS_FILE_H
#define OS_TOOLS_FILE_H

#include <cstdio>

#if OS_TOOLS_LIN
    #include <iostream>
    #include <sys/sendfile.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <ctime>
#elif OS_TOOLS_POSIX // Mac-way
    #include <iostream>
    #include <fcntl.h>
    #include <unistd.h>
    #include <ctime>
#elif OS_TOOLS_WIN
    #error
#elif OS_TOOLS_CPP_COMPATIBLE
    #include <iostream>
    #include <ctime>
#endif



namespace os_tools {

    /*
     * Read <size> bytes and get ptr to buf
     * \param src   path
     * \param size  size of file
     * \return ptr to buf or nullptr
     */
    void* read_file(const char* const src, const size_t size);

    /*
     * Simple copy of file.
     * \param src   path
     * \param dest  path
     * \return true if successful, else - false(read errno/GetLastError())
     */
    bool copy_file(const char* const src, const char* const dest, bool truncate = false);
}

#endif // OS_TOOLS_FILE_H
