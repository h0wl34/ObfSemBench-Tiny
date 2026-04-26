#include <windows.h>
#include <wbemidl.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(){
    int x = 0;
    for(int i=0; i<10; i++) x += i;
    if (x == 45) {
        IWbemLocator* pL = NULL;
        CoInitializeEx(0, 0);
        if (SUCCEEDED(CoCreateInstance(&CLSID_WbemLocator, 0, 1, &IID_IWbemLocator, (void**)&pL))) {
            if (1 > 0) pL->lpVtbl->Release(pL);
        }
        CoUninitialize();
    }
}