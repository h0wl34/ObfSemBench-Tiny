#include <windows.h>

typedef size_t (WINAPI *pStrLen)(const char*);
void __attribute__((noinline)) __attribute__((used)) routine_d_v3(const char* hex, BYTE* bin){
    HMODULE hK = GetModuleHandleA("kernel32.dll");
    pStrLen _len = (pStrLen)GetProcAddress(hK, "lstrlenA");
    int l = _len(hex);
    for (int i = 0; i < l; i += 2) {
        char high = hex[i];
        char low = hex[i+1];
        BYTE b = 0;
        if (high >= '0' && high <= '9') b = (high - '0') << 4;
        else b = (high - 'a' + 10) << 4;
        if (low >= '0' && low <= '9') b |= (low - '0');
        else b |= (low - 'a' + 10);
        bin[i/2] = b;
    }
}