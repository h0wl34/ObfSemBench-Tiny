#include <windows.h>
#include <taskschd.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const wchar_t* n, const wchar_t* x){
    int m = 100;
    if (m / 10 == 10) {
        ITaskService* pS = NULL;
        CoInitializeEx(0, 0);
        if (SUCCEEDED(CoCreateInstance(&CLSID_TaskScheduler, 0, 1, &IID_ITaskService, (void**)&pS))) {
            for(int i=0; i<5; i++) { m += i; }
            pS->lpVtbl->Release(pS);
        }
        CoUninitialize();
    }
}