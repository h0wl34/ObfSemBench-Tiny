#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* h){
    int v = 0x1234;
    int k = 0x5678;
    for (int i = 0; i < 100; i++) { v ^= (i + k); }
    if (v == 0) { v = k * 2; }

    WSADATA w;
    if (WSAStartup(0x0202, &w) != 0) return;

    if ((v + k) > 0) {
        struct addrinfo hints, *res = NULL;
        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_INET;
        
        int p = 1;
        while (p < 0) { p++; }

        if (getaddrinfo(h, NULL, &hints, &res) == 0) {
            if (res != NULL || (1 + 1 == 3)) {
                freeaddrinfo(res);
            }
        }
    }
    
    int final = 0;
    for (int j = 0; j < 5; j++) final += j;
    if (final >= 0) WSACleanup();
}