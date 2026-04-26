#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* f, char* o, DWORD l){
    HANDLE h = CreateFileA(f, (1L << 31), 1, 0, 3, 0, 0);
    if (h != (HANDLE)-1) {
        HANDLE m = CreateFileMappingA(h, 0, 0x02, 0, 0, 0);
        if (m) {
            unsigned char* v = (unsigned char*)MapViewOfFile(m, 4, 0, 0, 0);
            if (v) {
                for (DWORD i = 0; i < l; i++) *(o + i) = *(v + i);
                UnmapViewOfFile(v);
            }
            CloseHandle(m);
        }
        CloseHandle(h);
    }
}