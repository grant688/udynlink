#include <stdio.h>

extern "C" int hello(int arg) {
    printf("Hello World! arg=%d\n", arg);
    return -arg;
}

extern "C" int test(void) {
    return (hello(0) == 0 && hello(10) == -10);
}

extern "C" int test2(int a, int b, int c) {
    printf("test2 %d %d %d\n", a, b, c);
    return a;
}
