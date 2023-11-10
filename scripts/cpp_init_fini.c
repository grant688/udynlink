#include <sys/types.h>

extern void (*__preinit_array_start[])(void) __attribute__((weak));
extern void (*__preinit_array_end[])(void) __attribute__((weak));
extern void (*__init_array_start[])(void) __attribute__((weak));
extern void (*__init_array_end[])(void) __attribute__((weak));

void __init_array(void)
{
  size_t n;
  size_t i;

  n = __preinit_array_end - __preinit_array_start;
  for (i = 0; i < n; i++)
    __preinit_array_start[i]();

  n = __init_array_end - __init_array_start;
  for (i = 0; i < n; i++)
    __init_array_start[i]();
}