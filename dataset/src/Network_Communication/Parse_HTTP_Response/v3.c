#include <windows.h>

typedef char* (WINAPI *pStrStrA)(const char*, const char*);
void __attribute__((noinline)) __attribute__((used)) routine_h_v3(const char* input, char* output){
    HMODULE h = LoadLibraryA("shlwapi.dll");
    pStrStrA _strstr = (pStrStrA)GetProcAddress(h, "StrStrA");
    
    char* loc = _strstr(input, "\r\n\r\n");
    if (loc) {
        int i = 0;
        loc += 4;
        while (loc[i]) {
            output[i] = loc[i];
            i++;
        }
        output[i] = 0;
    }
}