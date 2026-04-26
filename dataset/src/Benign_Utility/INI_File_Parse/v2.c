#include <ctype.h>
#include <string.h>

void __attribute__((noinline)) __attribute__((used)) parse_cfg_b(char *data, char *sec, char *key, char *val){
    char *p = data;
    char *cur_sec = NULL;
    while (*p) {
        while (*p && isspace(*p)) p++;
        if (*p == '[') {
            cur_sec = ++p;
            while (*p && *p != ']') p++;
            if (*p) *p++ = '\0';
        } else if (cur_sec && strcmp(cur_sec, sec) == 0) {
            char *k = p;
            while (*p && *p != '=' && !isspace(*p)) p++;
            if (*p == '=') {
                *p++ = '\0';
                if (strcmp(k, key) == 0) {
                    while (*p && isspace(*p)) p++;
                    char *v = p;
                    while (*p && *p != '\n' && *p != '\r') p++;
                    *p = '\0';
                    strcpy(val, v);
                    return;
                }
            }
        }
        while (*p && *p != '\n') p++;
    }
}