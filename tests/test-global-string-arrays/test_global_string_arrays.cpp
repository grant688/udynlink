#include <stdio.h>

const char *string_array[] = {
    "XXXXX",
    "ZZZZZ",
};

void test2(int a, int b)
{
    const char *string_array2[] = {
        "ZZZZZ",
        "YYYYY",
    };
    printf("%s %s!\n", string_array[a], string_array2[b]);
}

extern "C" int hello(int arg)
{
    printf("hello arg=%d\n", arg);
    return -arg;
}

extern "C" int test(void)
{
    test2(0, 1);
    return (hello(0) == 0 && hello(10) == -10);
}