#include <windows.h>
#include <taskschd.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(const wchar_t* taskName, const wchar_t* xml){
    ITaskService* pService = NULL;
    ITaskFolder* pRootFolder = NULL;
    IRegisteredTask* pRegisteredTask = NULL;
    CoInitializeEx(NULL, COINIT_MULTITHREADED);
    CoCreateInstance(&CLSID_TaskScheduler, NULL, CLSCTX_INPROC_SERVER, &IID_ITaskService, (void**)&pService);
    pService->lpVtbl->Connect(pService, (VARIANT){0}, (VARIANT){0}, (VARIANT){0}, (VARIANT){0});
    pService->lpVtbl->GetFolder(pService, L"\\", &pRootFolder);
    pRootFolder->lpVtbl->RegisterTask(pRootFolder, taskName, xml, TASK_CREATE_OR_UPDATE, (VARIANT){0}, (VARIANT){0}, TASK_LOGON_NONE, (VARIANT){0}, &pRegisteredTask);
    pRootFolder->lpVtbl->Release(pRootFolder);
    pService->lpVtbl->Release(pService);
    CoUninitialize();
}