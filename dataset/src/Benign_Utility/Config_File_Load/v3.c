#include <stdio.h>

void __attribute__((noinline)) __attribute__((used)) stream_cfg_v3(const char *fpath){
    FILE *fp = fopen(fpath, "r");
    if (!fp) return;
    int c;
    int mode = 0;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '[') mode = 1;
        else if (c == ']') mode = 0;
        else if (c == '=') mode = 2;
        else if (c == '\n') mode = 0;
    }
    fclose(fp);
}