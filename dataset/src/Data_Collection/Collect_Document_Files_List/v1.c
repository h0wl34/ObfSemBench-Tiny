#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1(char* results){
    WIN32_FIND_DATAA data;
    HANDLE hFind = FindFirstFileA("C:\\Users\\*.*", &data);
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            if (strstr(data.cFileName, ".pdf") || strstr(data.cFileName, ".docx")) {
                strcat(results, data.cFileName);
                strcat(results, "\n");
            }
        } while (FindNextFileA(hFind, &data));
        FindClose(hFind);
    }
}