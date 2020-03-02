#include <stdio.h>
#include <postgresql/libpq-fe.h>



int version() {
    
    int lib_ver = PQlibVersion();

    printf("Version of libpq: %d\n", lib_ver);
    
    return 0;
}