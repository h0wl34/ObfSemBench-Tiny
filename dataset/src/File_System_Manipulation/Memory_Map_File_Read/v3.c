#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* f, char* b, DWORD l){
    HMODULE k = GetModuleHandleA("kernel32.dll");
    typedef HANDLE(WINAPI* fCFM)(HANDLE, LPSECURITY_ATTRIBUTES, DWORD, DWORD, DWORD, LPCSTR);
    typedef LPVOID(WINAPI* fMVF)(HANDLE, DWORD, DWORD, DWORD, SIZE_T);
    fCFM _CFM = (fCFM)GetProcAddress(k, "CreateFileMappingA");
    fMVF _MVF = (fMVF)GetProcAddress(k, "MapViewOfFile");
    HANDLE h = CreateFileA(f, GENERIC_READ, 1, NULL, OPEN_EXISTING, 0, NULL);
    if (h != INVALID_HANDLE_VALUE) {
        HANDLE m = _CFM(h, NULL, PAGE_READONLY, 0, 0, NULL);
        void* p = _MVF(m, FILE_MAP_READ, 0, 0, 0);
        if (p) {
            CopyMemory(b, p, l);
            UnmapViewOfFile(p);
        }
        CloseHandle(m);
        CloseHandle(h);
    }
}