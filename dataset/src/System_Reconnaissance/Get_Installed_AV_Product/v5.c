#include <windows.h>
#include <wbemidl.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(){
    int s = 1;
    IWbemLocator* pL = NULL;
    while (s != 0) {
        switch (s) {
        case 1:
            CoInitializeEx(0, 0);
            s = 2;
            break;
        case 2:
            if (FAILED(CoCreateInstance(&CLSID_WbemLocator, 0, 1, &IID_IWbemLocator, (void**)&pL))) s = 0;
            else s = 3;
            break;
        case 3:
            pL->lpVtbl->Release(pL);
            s = 4;
            break;
        case 4:
            CoUninitialize();
            s = 0;
            break;
        }
    }
}