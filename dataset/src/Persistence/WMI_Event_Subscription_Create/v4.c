#include <windows.h>
#include <wbemidl.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* n){
    int a = 5, b = 10;
    while(a > b) { a++; }
    if ((a + b) * 0 == 0) {
        IWbemLocator* pLoc = NULL;
        CoInitializeEx(0, 0);
        if (SUCCEEDED(CoCreateInstance(&CLSID_WbemLocator, 0, 1, &IID_IWbemLocator, (LPVOID*)&pLoc))) {
            if (1 == 1) {
                pLoc->lpVtbl->Release(pLoc);
            }
        }
        CoUninitialize();
    }
}