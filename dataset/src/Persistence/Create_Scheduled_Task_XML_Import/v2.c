#include <windows.h>
#include <taskschd.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const wchar_t* n, const wchar_t* x){
    void* s = NULL;
    void* f = NULL;
    void* r = NULL;
    CoInitializeEx(0, 0);
    GUID c = { 0x0f87369f, 0xa4bb, 0x452a, { 0x8c, 0x27, 0x38, 0x30, 0x19, 0x24, 0x3f, 0x7a } };
    GUID i = { 0x2faba4c7, 0x4da9, 0x4013, { 0x96, 0x97, 0x20, 0xcc, 0x3f, 0xd4, 0x0f, 0x85 } };
    CoCreateInstance(&c, 0, 1, &i, &s);
    VARIANT v; v.vt = 0;

    ((ITaskService*)s)->lpVtbl->Connect((ITaskService*)s, v, v, v, v);
    ((ITaskService*)s)->lpVtbl->GetFolder((ITaskService*)s, L"\\", (ITaskFolder**)&f);
    ((ITaskFolder*)f)->lpVtbl->RegisterTask(
        (ITaskFolder*)f,
        (BSTR)n,
        (BSTR)x,
        6,
        v,
        v,
        0,
        v,
        (IRegisteredTask**)&r
    );
}