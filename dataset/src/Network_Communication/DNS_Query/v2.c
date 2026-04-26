#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* h){
    WSADATA w;
    if (WSAStartup(0x0202, &w) != 0) return;
    void* r = 0;
    char m[64];
    for (int i = 0; i < 64; i++) *((char*)m + i) = 0;
    *(int*)((char*)m + 4) = 0;
    *(int*)((char*)m + 8) = 1;
    *(int*)((char*)m + 12) = 6;
    if (((int(*)(const char*, const char*, void*, void**))getaddrinfo)(h, 0, m, &r) == 0) {
        if (r) ((void(*)(void*))freeaddrinfo)(r);
    }
    WSACleanup();
}