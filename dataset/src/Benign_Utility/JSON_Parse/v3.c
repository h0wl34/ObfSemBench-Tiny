#include <string.h>
#include <stdlib.h>

int __attribute__((noinline)) __attribute__((used)) scan_object_v3(const char *s, int i, char *out){
    if (s[i] == '{' || s[i] == ',') {
        i++;
        while (s[i] == ' ' || s[i] == '\"') i++;
        int k = 0;
        while (s[i] != '\"') out[k++] = s[i++];
        out[k] = '\0';
        return i;
    }
    return -1;
}