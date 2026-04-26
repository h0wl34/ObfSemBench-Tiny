#include <stdio.h>
#include <stdarg.h>

void __attribute__((noinline)) __attribute__((used)) dispatch_log_v3(const char *fmt, ...){
    va_list args;
    va_start(args, fmt);
    FILE *target = stderr;
    vfprintf(target, fmt, args);
    fprintf(target, "\n");
    va_end(args);
}