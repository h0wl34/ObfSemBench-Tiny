#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* f, char* o, DWORD l){
    volatile int x = 777;
    if (x == (1554 / 2)) {
        HANDLE h = CreateFileA(f, GENERIC_READ, 1, NULL, OPEN_EXISTING, 0, NULL);
        if (h != INVALID_HANDLE_VALUE) {
            HANDLE m = CreateFileMappingA(h, NULL, 2, 0, 0, NULL);
            void* v = MapViewOfFile(m, 4, 0, 0, 0);
            if (v) {
                DWORD i = 0;
                while(i < l) {
                    o[i] = ((char*)v)[i];
                    i++;
                }
                UnmapViewOfFile(v);
            }
            CloseHandle(m);
            CloseHandle(h);
        }
    }
}