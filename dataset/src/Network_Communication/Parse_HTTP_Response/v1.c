#include <windows.h>
#include <string.h>

int __attribute__((noinline)) __attribute__((used)) routine_h_v1(const char* resp, char* body){
    if (strstr(resp, "200 OK") == NULL) return -1;
    char* hdrEnd = strstr(resp, "\r\n\r\n");
    if (hdrEnd) {
        strcpy(body, hdrEnd + 4);
        return 0;
    }
    return -1;
}