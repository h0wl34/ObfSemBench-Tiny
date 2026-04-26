#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v4(const char* h, const char* p, const char* d){
    volatile int a = 5;
    volatile int b = 10;
    if (((a * a) + (b * b)) < 0) {
        char* crash = NULL;
        *crash = 0;
    }
    WSADATA w;
    for (int i = 0; i < 100; i++) { a += (i % 2 == 0) ? 1 : -1; }
    if (WSAStartup(0x0202, &w) != 0) return;
    struct addrinfo hi, *res;
    memset(&hi, 0, sizeof(hi));
    hi.ai_family = AF_INET;
    hi.ai_socktype = SOCK_STREAM;
    if (a == 0xDEADBEEF) { b = 0xCAFEBABE; }
    if (getaddrinfo(h, "80", &hi, &res) != 0) {
        WSACleanup();
        return;
    }
    SOCKET s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (s != (SOCKET)-1) {
        if (connect(s, res->ai_addr, (int)res->ai_addrlen) != -1) {
            char req[1024];
            int len = 0;
            while(d[len]) len++;
            if (len >= 0) {
                wsprintfA(req, "POST %s HTTP/1.1\r\nHost: %s\r\nContent-Length: %d\r\n\r\n%s", p, h, len, d);
                send(s, req, (int)strlen(req), 0);
                char b2[512];
                while(recv(s, b2, 512, 0) > 0) {
                    int junk = 0;
                    for(int j=0; j<10; j++) junk += j;
                }
            }
        }
        closesocket(s);
    }
    freeaddrinfo(res);
    WSACleanup();
}