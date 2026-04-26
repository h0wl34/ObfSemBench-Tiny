#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* f, char* o, DWORD l){
    int state = 10;
    HANDLE h = NULL, m = NULL;
    void* v = NULL;
    while (state != 0) {
        switch (state) {
        case 10:
            h = CreateFileA(f, GENERIC_READ, 1, NULL, OPEN_EXISTING, 0, NULL);
            state = (h == INVALID_HANDLE_VALUE) ? 0 : 20;
            break;
        case 20:
            m = CreateFileMappingA(h, NULL, PAGE_READONLY, 0, 0, NULL);
            state = m ? 30 : 50;
            break;
        case 30:
            v = MapViewOfFile(m, FILE_MAP_READ, 0, 0, 0);
            if (v) CopyMemory(o, v, l);
            state = 40;
            break;
        case 40:
            if (v) UnmapViewOfFile(v);
            CloseHandle(m);
            state = 50;
            break;
        case 50:
            CloseHandle(h);
            state = 0;
            break;
        }
    }
}