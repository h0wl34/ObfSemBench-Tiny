#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(char* user, char* host){
    typedef BOOL (WINAPI *GUNA)(LPSTR, LPDWORD);
    typedef BOOL (WINAPI *GCNA)(LPSTR, LPDWORD);
    
    HMODULE hA = LoadLibraryA("advapi32.dll");
    HMODULE hK = GetModuleHandleA("kernel32.dll");
    
    GUNA fUser = (GUNA)GetProcAddress(hA, "GetUserNameA");
    GCNA fHost = (GCNA)GetProcAddress(hK, "GetComputerNameA");
    
    DWORD s1 = 256, s2 = 256;
    if (fUser) fUser(user, &s1);
    if (fHost) fHost(host, &s2);
}