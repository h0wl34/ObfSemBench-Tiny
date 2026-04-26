#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(const char* target_exe, const char* debugger_path){
    char path[256];
    wsprintfA(path, "Software\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\%s", target_exe);
    HKEY hKey;
    if (RegCreateKeyExA(HKEY_LOCAL_MACHINE, path, 0, NULL, 0, KEY_SET_VALUE, NULL, &hKey, NULL) == ERROR_SUCCESS) {
        RegSetValueExA(hKey, "Debugger", 0, REG_SZ, (const BYTE*)debugger_path, lstrlenA(debugger_path));
        RegCloseKey(hKey);
    }
}   