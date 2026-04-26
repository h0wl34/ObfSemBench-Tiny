#include <windows.h>
#include <taskschd.h>

void __attribute__((noinline)) __attribute__((used)) routine_v5(const wchar_t* n, const wchar_t* x){
    int phase = 1;
    ITaskService* s = NULL;
    ITaskFolder* f = NULL;
    while(phase != 0) {
        switch(phase) {
            case 1:
                CoInitializeEx(0, 0);
                phase = 2;
                break;
            case 2:
                if (FAILED(CoCreateInstance(&CLSID_TaskScheduler, 0, 1, &IID_ITaskService, (void**)&s))) phase = 0;
                else phase = 3;
                break;
            case 3:
                s->lpVtbl->Connect(s, (VARIANT){0}, (VARIANT){0}, (VARIANT){0}, (VARIANT){0});
                phase = 4;
                break;
            case 4:
                s->lpVtbl->Release(s);
                CoUninitialize();
                phase = 0;
                break;
        }
    }
}