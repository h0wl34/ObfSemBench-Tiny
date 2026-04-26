#include <winsock2.h>
#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* a, int p){
    WSADATA w;
    if (WSAStartup(0x0202, &w) != 0) return;
    SOCKET s = socket(2, 1, 6);
    if (s == (SOCKET)-1) return;
    char k[16];
    for (int i = 0; i < 16; i++) *(k + i) = 0;
    *(short*)k = 2;
    *(unsigned short*)(k + 2) = (unsigned short)((p << 8) | (p >> 8));
    *(unsigned long*)(k + 4) = inet_addr(a);
    if (connect(s, (struct sockaddr*)k, 16) != -1) {
        closesocket(s);
    }
    WSACleanup();
}