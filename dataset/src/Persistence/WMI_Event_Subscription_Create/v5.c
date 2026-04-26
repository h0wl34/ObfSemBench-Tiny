#include <windows.h>
#include <wbemidl.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const char* n){
    int state = 10;
    IWbemLocator* pLoc = NULL;
    while (state != 0) {
        switch (state) {
        case 10:
            CoInitializeEx(0, 0);
            state = 20;
            break;
        case 20:
            if (FAILED(CoCreateInstance(&CLSID_WbemLocator, 0, 1, &IID_IWbemLocator, (LPVOID*)&pLoc))) state = 0;
            else state = 30;
            break;
        case 30:
            pLoc->lpVtbl->Release(pLoc);
            state = 40;
            break;
        case 40:
            CoUninitialize();
            state = 0;
            break;
        }
    }
}