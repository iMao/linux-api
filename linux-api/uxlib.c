#include "uxlib.h"

void show_GLIBC_version()
{
    printf("GNU C library version: %s \n", gnu_get_libc_version());
    printf("GNU C library release: %s \n", gnu_get_libc_release());
}
