#include <stdio.h>
#include <string.h>

void __attribute__((noinline)) __attribute__((used)) commit_log_v2(int level, const char *content){
    static char buf[4096];
    size_t len = snprintf(buf, sizeof(buf), "LVL:%d | %s\n", level, content);
    FILE *fp = fopen("sys.log", "ab");
    if (fp) {
        fwrite(buf, 1, len, fp);
        fclose(fp);
    }
}