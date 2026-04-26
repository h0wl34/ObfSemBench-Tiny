#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(){
    typedef HMODULE(WINAPI* ll)(LPCSTR);
    HMODULE k = GetModuleHandleA("kernel32.dll");
    ll _ll = (ll)GetProcAddress(k, "LoadLibraryA");
    char n[8];
    n[0] = 'u'; n[1] = 's'; n[2] = 'e'; n[3] = 'r'; n[4] = '3'; n[5] = '2'; n[6] = 0;
    _ll(n);
}