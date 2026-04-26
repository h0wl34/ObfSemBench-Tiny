#include <windows.h>
#include <wbemidl.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(){
    void* l = NULL; void* s = NULL; void* e = NULL;
    CoInitializeEx(0, 0);
    GUID cl = { 0x4590f811, 0x1d3a, 0x11d0, { 0x89, 0x1f, 0x00, 0xaa, 0x00, 0x4b, 0x2e, 0x24 } };
    GUID it = { 0xdc12a687, 0x737f, 0x11cf, { 0x88, 0x4d, 0x00, 0xaa, 0x00, 0x4b, 0x2e, 0x24 } };
    CoCreateInstance(&cl, 0, 1, &it, &l);

    ((HRESULT (__stdcall *)(IWbemLocator*, BSTR, BSTR, BSTR, BSTR, LONG, BSTR, IWbemContext*, IWbemServices**))
        (*(void***)l)[3])((IWbemLocator*)l, SysAllocString(L"ROOT\\SecurityCenter2"), 0, 0, 0, 0, 0, 0, (IWbemServices**)&s);

    ((HRESULT (__stdcall *)(IWbemServices*, BSTR, BSTR, LONG, IWbemContext*, IEnumWbemClassObject**))
        (*(void***)s)[20])((IWbemServices*)s, SysAllocString(L"WQL"), SysAllocString(L"SELECT * FROM AntiVirusProduct"), 48, 0, (IEnumWbemClassObject**)&e);

    IWbemClassObject* o = NULL; ULONG r = 0;

    ((HRESULT (__stdcall *)(IEnumWbemClassObject*, LONG, ULONG, IWbemClassObject**, ULONG*))
        (*(void***)e)[4])((IEnumWbemClassObject*)e, -1, 1, &o, &r);
}