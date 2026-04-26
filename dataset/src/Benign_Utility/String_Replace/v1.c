#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void __attribute__((noinline)) __attribute__((used)) modify_str_v1(char *s, const char *old_w, const char *new_w){
    char buffer[1024];
    char *p;
    if (!(p = strstr(s, old_w))) return;
    strncpy(buffer, s, p - s);
    buffer[p - s] = '\0';
    sprintf(buffer + (p - s), "%s%s", new_w, p + strlen(old_w));
    strcpy(s, buffer);
}