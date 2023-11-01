#include <stdio.h>

extern "C" int hello(int arg) {
    printf("Hello World! arg=%d\n", arg);
    return -arg;
}

extern "C" int test(void) {
    return (hello(0) == 0 && hello(10) == -10);
}
