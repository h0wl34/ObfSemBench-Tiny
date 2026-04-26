#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void __attribute__((noinline)) __attribute__((used)) load_cfg_v1(const char *path, char *key, char *val){
    FILE *f = fopen(path, "r");
    if (!f) return;
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        if (strstr(line, key)) {
            char *eq = strchr(line, '=');
            if (eq) {
                strcpy(val, eq + 1);
                val[strcspn(val, "\r\n")] = 0;
                break;
            }
        }
    }
    fclose(f);
}