#include <windows.h>
#include <wbemidl.h>

void __attribute__((noinline)) __attribute__((used)) routine_v3(const char* name){
    HMODULE hOle = LoadLibraryA("ole32.dll");
    HMODULE hAut = LoadLibraryA("oleaut32.dll");
    typedef HRESULT(WINAPI* fCI)(LPVOID, DWORD);
    typedef HRESULT(WINAPI* fCCI)(REFCLSID, LPUNKNOWN, DWORD, REFIID, LPVOID*);
    typedef BSTR(WINAPI* fSAS)(const OLECHAR*);
    fCI _CI = (fCI)GetProcAddress(hOle, "CoInitializeEx");
    fCCI _CCI = (fCCI)GetProcAddress(hOle, "CoCreateInstance");
    fSAS _SAS = (fSAS)GetProcAddress(hAut, "SysAllocString");
    _CI(NULL, 0);
    IUnknown* pLoc = NULL;
    _CCI(&CLSID_WbemLocator, NULL, 1, &IID_IWbemLocator, (LPVOID*)&pLoc);
}