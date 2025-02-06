#include "udynlink.h"
#include "test_multiple_relocs_module_data.h"
#include "test_utils.h"
#include <stdio.h>

int test_qemu(void) {
    const char *exported_syms[] = {"test", NULL};
    const char *extern_syms[] = {"printf", NULL};
    udynlink_module_t mod;
    int res = 0;

    for (int i = (int)_UDYNLINK_LOAD_MODE_FIRST; i <= (int)_UDYNLINK_LOAD_MODE_LAST; i ++) {
        if (udynlink_load_module(&mod, test_multiple_relocs_module_data, NULL, 0, (udynlink_load_mode_t)i))
            return 0;

        udynlink_cpp_init(&mod);
        
        CHECK_RAM_SIZE(&mod, 0);
        if (!check_exported_symbols(&mod, exported_syms))
            goto exit;
        if (!check_extern_symbols(&mod, extern_syms))
            goto exit;
        if (!run_test_func(&mod))
            goto exit;

        udynlink_unload_module(&mod);
    }
    res = 1;
exit:
    udynlink_unload_module(&mod);
    return res;
}
