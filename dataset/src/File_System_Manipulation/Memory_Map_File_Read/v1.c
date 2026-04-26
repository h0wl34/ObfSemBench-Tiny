#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(const char* filename, char* outBuf, DWORD len){
    HANDLE hFile = CreateFileA(filename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    if (hFile != INVALID_HANDLE_VALUE) {
        HANDLE hMap = CreateFileMappingA(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
        if (hMap) {
            void* pView = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
            if (pView) {
                CopyMemory(outBuf, pView, len);
                UnmapViewOfFile(pView);
            }
            CloseHandle(hMap);
        }
        CloseHandle(hFile);
    }
}