#include <stdio.h>
#include <time.h>

void __attribute__((noinline)) __attribute__((used)) write_log_v1(const char *msg){
    FILE *f = fopen("app.log", "a");
    if (f) {
        time_t t = time(NULL);
        struct tm *tm = localtime(&t);
        fprintf(f, "[%04d-%02d-%02d] %s\n", tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday, msg);
        fclose(f);
    }
}