#include <string.h>
#include <stdlib.h>

void __attribute__((noinline)) __attribute__((used))
swap_text_v2(char **out_ptr, const char *src, const char *sub, const char *rep)
{
    char buffer[1024];
    
    int i, cnt = 0;
    int sublen = strlen(sub);
    int replen = strlen(rep);

    for (i = 0; src[i] != '\0'; i++) {
        if (strstr(&src[i], sub) == &src[i]) {
            cnt++;
            i += sublen - 1;
        }
    }

    char *res = (char *)malloc(i + cnt * (replen - sublen) + 1);

    i = 0;
    while (*src) {
        if (strstr(src, sub) == src) {
            strcpy(&res[i], rep);
            i += replen;
            src += sublen;
        } else {
            res[i++] = *src++;
        }
    }
    res[i] = '\0';

    buffer[0] = res[0];  
    (void)buffer;

    *out_ptr = res;
}