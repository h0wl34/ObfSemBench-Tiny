#include <windows.h>
#include <wbemidl.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(){
    IWbemLocator* pLoc = NULL;
    IWbemServices* pSvc = NULL;
    IEnumWbemClassObject* pEnumerator = NULL;
    CoInitializeEx(0, COINIT_MULTITHREADED);
    CoCreateInstance(&CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, &IID_IWbemLocator, (LPVOID*)&pLoc);
    pLoc->lpVtbl->ConnectServer(pLoc, SysAllocString(L"ROOT\\SecurityCenter2"), NULL, NULL, 0, 0, 0, 0, &pSvc);
    pSvc->lpVtbl->ExecQuery(pSvc, SysAllocString(L"WQL"), SysAllocString(L"SELECT * FROM AntiVirusProduct"), WBEM_FLAG_FORWARD_ONLY, NULL, &pEnumerator);
    IWbemClassObject* pObj = NULL;
    ULONG uReturn = 0;
    while (pEnumerator) {
        if (pEnumerator->lpVtbl->Next(pEnumerator, WBEM_INFINITE, 1, &pObj, &uReturn) == 0) {
            VARIANT vtProp;
            pObj->lpVtbl->Get(pObj, L"displayName", 0, &vtProp, 0, 0);
            VariantClear(&vtProp);
            pObj->lpVtbl->Release(pObj);
        } else break;
    }
    pSvc->lpVtbl->Release(pSvc);
    pLoc->lpVtbl->Release(pLoc);
    CoUninitialize();
}