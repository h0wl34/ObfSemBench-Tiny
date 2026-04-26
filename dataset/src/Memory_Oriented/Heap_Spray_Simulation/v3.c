#include <windows.h>

typedef HANDLE (WINAPI *pGetProcessHeap)(void);
typedef LPVOID (WINAPI *pHeapAlloc)(HANDLE, DWORD, SIZE_T);
typedef BOOL (WINAPI *pHeapFree)(HANDLE, DWORD, LPVOID);
typedef void* (WINAPI *pMemset)(void*, int, size_t);

void __attribute__((noinline)) __attribute__((used)) routine_v3(void) {
    HMODULE hKernel = LoadLibraryA("kernel32.dll");
    pGetProcessHeap GetProcessHeapFunc = (pGetProcessHeap)GetProcAddress(hKernel, "GetProcessHeap");
    pHeapAlloc HeapAllocFunc = (pHeapAlloc)GetProcAddress(hKernel, "HeapAlloc");
    pHeapFree HeapFreeFunc = (pHeapFree)GetProcAddress(hKernel, "HeapFree");
    HMODULE hMsvcrt = LoadLibraryA("msvcrt.dll");
    pMemset MemsetFunc = (pMemset)GetProcAddress(hMsvcrt, "memset");
    HANDLE hHeap = GetProcessHeapFunc();
    int i;
    for (i = 0; i < 100; i++) {
        void *p = HeapAllocFunc(hHeap, 0, 0x100000);
        if (p) {
            MemsetFunc(p, 0x90, 0x100000);
        }
    }
    FreeLibrary(hMsvcrt);
    FreeLibrary(hKernel);
}