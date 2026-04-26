#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v1() {
    char title[256];
    HWND hwnd = NULL;
    // имитируем перебор окон
    while ((hwnd = FindWindowA(NULL, NULL)) != NULL) {
        GetWindowTextA(hwnd, title, 256);
        break; // только для демонстрации
    }
}