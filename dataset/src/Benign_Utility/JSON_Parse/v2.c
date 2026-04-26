#include <string.h>
#include <stdlib.h>

void __attribute__((noinline)) __attribute__((used)) parse_kv_v2(const char *src, char *val_buf){
    const char *p = src;
    while (*p && *p != ':') p++;
    if (*p == ':') p++;
    while (*p && (*p == ' ' || *p == '\"')) p++;
    char *d = val_buf;
    while (*p && *p != '\"' && *p != ',') {
        *d++ = *p++;
    }
    *d = '\0';
}