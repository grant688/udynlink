#include <stdio.h>

extern "C" void aaaa() {
}

typedef void (*fp)();

static fp cccc[] ={
    &aaaa,
    &aaaa,
};

extern "C" int test(void) {
    for(auto n : cccc)
    {
        printf("0x%x\n", n);
        if(n != &aaaa)
            return false;
    }
    return true;
}
