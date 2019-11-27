#include "main.h"

int main(int argc, char *argv[]) {
#if IS_INDEX_DEFINED
    if (1 >= argc || 0 == memcmp(argv[1], "-h", 2)) {
        printf("It is cp\nUsing: cp <src> <dest>\nExample: ./cd ./A/file.hpp /tmp/A.hpp");
        return 0;
    }
    else if (3 != argc || !os_tools::copy_file(argv[1], argv[2])) {
        printf("error\n");
        return 666;
    }
    return 0;
#else
    #error // include C/index.h
#endif
}