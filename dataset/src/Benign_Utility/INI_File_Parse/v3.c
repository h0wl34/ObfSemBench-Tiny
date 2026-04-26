#include <stdlib.h>
#include <string.h>

typedef struct {
    char k[32];
    char v[32];
} entry;
int __attribute__((noinline)) __attribute__((used)) parse_cfg_c(char *raw, entry *items, int max){
    int count = 0;
    char *token = strtok(raw, "\n\r");
    while (token && count < max) {
        if (token[0] != '[' && strchr(token, '=')) {
            char *d = strchr(token, '=');
            *d = '\0';
            strncpy(items[count].k, token, 31);
            strncpy(items[count].v, d + 1, 31);
            count++;
        }
        token = strtok(NULL, "\n\r");
    }
    return count;
}