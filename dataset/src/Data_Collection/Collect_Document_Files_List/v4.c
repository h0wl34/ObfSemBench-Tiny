#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(char* res){
    WIN32_FIND_DATAA data;
    int a = 5, b = 10;
    if (a + b == 15) {
        HANDLE h = FindFirstFileA("C:\\Users\\*.*", &data);
        if (h != INVALID_HANDLE_VALUE) {
            do {
                volatile int z = 0;
                for(int i=0; i<10; i++) z += i;
                if (strstr(data.cFileName, ".docx")) {
                    if (z >= 0) {
                        strcat(res, data.cFileName);
                    }
                }
            } while (FindNextFileA(h, &data));
            FindClose(h);
        }
    }
}