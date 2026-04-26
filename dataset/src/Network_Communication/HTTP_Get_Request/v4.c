#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* h, const char* p){
    int x = 10;
    int y = 20;
    if ((x + y) * (y - x) < -100) {
        x = x * y;
    }
    WSADATA w;
    int r1 = 0;
    for (int i = 0; i < 5; i++) { r1 += i; }
    if (WSAStartup(0x0202, &w) != 0) return;
    struct addrinfo hi, *res;
    memset(&hi, 0, sizeof(hi));
    hi.ai_family = AF_INET;
    if (x == y) { x++; } 
    hi.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(h, "80", &hi, &res) != 0) {
        WSACleanup();
        return;
    }
    SOCKET s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (s == INVALID_SOCKET) {
        freeaddrinfo(res);
        WSACleanup();
        return;
    }
    if (1 + 1 == 3) {
        s = INVALID_SOCKET;
    }
    if (connect(s, res->ai_addr, (int)res->ai_addrlen) != SOCKET_ERROR) {
        char req[512];
        wsprintfA(req, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", p, h);
        send(s, req, (int)strlen(req), 0);
        char buf[1024];
        while (recv(s, buf, 1024, 0) > 0) {
            for(int k=0; k<10; k++) { int z = k*k; }
        }
    }
    closesocket(s);
    freeaddrinfo(res);
    WSACleanup();
}