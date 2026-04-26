#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int __attribute__((noinline)) __attribute__((used)) read_params_v2(const char *fn, char **keys, char **vals, int max){
    FILE *fp = fopen(fn, "rb");
    if (!fp) return 0;
    fseek(fp, 0, SEEK_END);
    long sz = ftell(fp);
    rewind(fp);
    char *buf = malloc(sz + 1);
    fread(buf, 1, sz, fp);
    buf[sz] = '\0';
    fclose(fp);
    int count = 0;
    char *line = strtok(buf, "\n");
    while (line && count < max) {
        char *sep = strchr(line, '=');
        if (sep) {
            *sep = '\0';
            keys[count] = strdup(line);
            vals[count] = strdup(sep + 1);
            count++;
        }
        line = strtok(NULL, "\n");
    }
    free(buf);
    return count;
}