#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(const wchar_t* n, const wchar_t* x){
    HMODULE hOle = LoadLibraryA("ole32.dll");
    typedef HRESULT(WINAPI* fCCI)(REFCLSID, LPUNKNOWN, DWORD, REFIID, LPVOID*);
    fCCI _CCI = (fCCI)GetProcAddress(hOle, "CoCreateInstance");
    IUnknown* pSvc = NULL;
    GUID clsid = { 0x0f87369f, 0xa4bb, 0x452a, { 0x8c, 0x27, 0x38, 0x30, 0x19, 0x24, 0x3f, 0x7a } };
    GUID iid = { 0x2faba4c7, 0x4da9, 0x4013, { 0x96, 0x97, 0x20, 0xcc, 0x3f, 0xd4, 0x0f, 0x85 } };
    CoInitializeEx(0, 0);
    _CCI(&clsid, NULL, 1, &iid, (LPVOID*)&pSvc);
}