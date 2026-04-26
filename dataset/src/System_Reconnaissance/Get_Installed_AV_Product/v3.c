#include <windows.h>
#include <wbemidl.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(){
    HMODULE hOle = LoadLibraryA("ole32.dll");
    typedef HRESULT(WINAPI* fCI)(LPVOID, DWORD);
    typedef HRESULT(WINAPI* fCCI)(REFCLSID, LPUNKNOWN, DWORD, REFIID, LPVOID*);
    fCI _CI = (fCI)GetProcAddress(hOle, "CoInitializeEx");
    fCCI _CCI = (fCCI)GetProcAddress(hOle, "CoCreateInstance");
    _CI(0, 0);
    IUnknown* pLoc = NULL;
    _CCI(&CLSID_WbemLocator, NULL, 1, &IID_IWbemLocator, (LPVOID*)&pLoc);
}