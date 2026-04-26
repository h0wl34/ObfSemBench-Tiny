#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

void __attribute__((noinline)) __attribute__((used)) routine_v2(const char* h, const char* p){
    WSADATA w;
    if (*(int*)((char*)&w + 0) = 0, WSAStartup(0x0202, &w) != 0) return;
    struct addrinfo* r = 0, i, * k;
    char b[1024], * q = b;
    for (int j = 0; j < sizeof(i); *(char*)((char*)&i + j++) = 0);
    *((int*)&i + 1) = 2;
    *((int*)&i + 2) = 1;
    *((int*)&i + 3) = 6;
    if (getaddrinfo(h, "80", &i, &r) != 0) { WSACleanup(); return; }
    SOCKET s = socket(r->ai_family, r->ai_socktype, r->ai_protocol);
    if (s == (SOCKET)-1) { freeaddrinfo(r); WSACleanup(); return; }
    if (connect(s, r->ai_addr, (int)r->ai_addrlen) == -1) { closesocket(s); freeaddrinfo(r); WSACleanup(); return; }
    const char* m1 = "GET ";
    const char* m2 = " HTTP/1.1\r\nHost: ";
    const char* m3 = "\r\nConnection: close\r\n\r\n";
    while (*m1) *q++ = *m1++;
    while (*p) *q++ = *p++;
    while (*m2) *q++ = *m2++;
    while (*h) *q++ = *h++;
    while (*m3) *q++ = *m3++;
    *q = 0;
    send(s, b, (int)(q - b), 0);
    while (recv(s, b, 1024, 0) > 0);
    closesocket(s);
    freeaddrinfo(r);
    WSACleanup();
}